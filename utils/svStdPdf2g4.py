#!/usr/bin/env python

from antlr4grammar import Antlr4Rule, Antlr4Symbol, Antlr4Sequence, \
    Antlr4Selection, Antlr4Option, Antlr4Iteration, generate_renamer, \
    iAntlr4GramElem, rule_by_name, Antlr4LexerAction
from left_recurse_remove import direct_left_recurse_rm, inline_rule, split_rule, \
    iterate_everything_except_first, left_recurse_print
from selection_optimiser import optimise_selections
from svRule2Antlr4Rule import SvRule2Antlr4Rule
from antlr4_utils import rm_redunt_whitespaces_on_end, collect_simple_rules, \
    remove_simple_rule, rm_option_on_rule_usage, iter_non_visuals, \
    extract_option_as_rule, replace_symbol_in_rule
from copy import deepcopy
from optionality_optimiser import reduce_optionality


def add_string_literal_rules(p):
    string_char = Antlr4Rule("ANY_ASCII_CHARACTERS", Antlr4Selection([
        Antlr4Symbol('~["\\\\r\\n]', True, True),
        Antlr4Symbol('\\\\n', True),
        Antlr4Symbol('\\\\r\\n', True),
        Antlr4Symbol('\\t', True),
        Antlr4Symbol('\\\\', True),
        Antlr4Symbol('\\"', True),
        Antlr4Symbol('\\v', True),
        Antlr4Symbol('\\f', True),
        Antlr4Symbol('\\a', True),
        Antlr4Symbol("'\\\\' [0-9] [0-9]? [0-9]?", True, True),
        Antlr4Symbol("'\\\\' 'x' [0-9A-Fa-f] [0-9A-Fa-f]?", True, True),
        ]), is_fragment=True)
    p.rules.append(string_char)

    any_printable_ASCII_character_except_white_space = Antlr4Rule(
        "ANY_PRINTABLE_ASCII_CHARACTER_EXCEPT_WHITE_SPACE",
        Antlr4Symbol("'\\u0021'..'\\u007E'", True, True),
        is_fragment=True)
    p.rules.append(any_printable_ASCII_character_except_white_space)


def add_file_path_literal_rules(p):
    FILE_PATH_SPEC_CHAR = Antlr4Rule(
        "FILE_PATH_SPEC_CHAR",
        Antlr4Symbol(
            "[^ !$`&()+] | ( '\\\\' [ !$`&*()+] )",
            True, True),
        is_fragment=True)
    p.rules.append(FILE_PATH_SPEC_CHAR)

    file_spec_path = Antlr4Rule(
        "FILE_PATH_SPEC",
        Antlr4Iteration(Antlr4Sequence([
                Antlr4Symbol("FILE_PATH_SPEC_CHAR", False),
                Antlr4Option(Antlr4Sequence([
                    Antlr4Symbol('SEMI', False),
                    Antlr4Symbol("FILE_PATH_SPEC_CHAR", False),
                ])),
            ]),
            positive=True
        )
    )
    p.rules.append(file_spec_path)


def replace_rule(rule_name, replace_rule_name, names_to_replace, parser):
    parser.rules = [p for p in parser.rules if p.name != rule_name]
    names_to_replace[rule_name] = replace_rule_name


def mark_regex(obj: iAntlr4GramElem):
    if isinstance(obj, Antlr4Symbol) and obj.symbol in [
            '[a-zA-Z_]', '[a-zA-Z0-9_$]', '[a-zA-Z0-9_]']:
        obj.is_regex = True


def subroutine_call_rm_lr(rules):
    r = rule_by_name(rules, "subroutine_call")
    assert isinstance(r.body, Antlr4Selection)
    c = r.body[2]
    _body = list(iter_non_visuals(c))
    assert _body[-1].symbol == "method_call_body", _body[-1].symbol
    start: Antlr4Selection = _body[0]
    start.clear()
    start.extend([
        Antlr4Symbol("primary_no_cast_no_call", False),
        Antlr4Symbol("cast", False),
        Antlr4Symbol("implicit_class_handle", False)
    ])


def left_recurse_remove(rules):
    """
    Removing Left Recursion from Context-Free Grammars
    https://www.microsoft.com/en-us/research/wp-content/uploads/2000/04/naacl2k-proc-rev.pdf

    http://web.science.mq.edu.au/~mjohnson/papers/johnson-left-corner.pdf

    :note: supports the '|',?,* in rules
    """
    # :note: higher priority = sooner in parse tree

    rules = optimise_selections(rules)
    direct_left_recurse_rm(rules, 'block_event_expression')
    direct_left_recurse_rm(rules, 'event_expression')
    direct_left_recurse_rm(rules, 'constant_expression')
    # method_call_root - only in method_call
    # method_call      - only in subroutine_call
    inline_rule(rules, "method_call")
    inline_rule(rules, "method_call_root")
    split_rule(rules, "primary",
               ["cast", "subroutine_call"],
               "primary_no_cast_no_call")
    split_rule(rules, "constant_primary",
               ["constant_cast", "subroutine_call"],
               "constant_primary_no_cast_no_call")

    # inline_rule(rules, "cast")
    # inline_rule(rules, "constant_cast")
    iterate_everything_except_first(
       rules, "cast")
    iterate_everything_except_first(
       rules, "constant_cast")
    # [TODO] check if really all combinations of cast/call are possible
    replace_symbol_in_rule(
        rules, "casting_type",
        "constant_primary",
        "constant_primary_no_cast_no_call")
    subroutine_call_rm_lr(rules)

    inline_rule(rules, "module_path_conditional_expression")
    direct_left_recurse_rm(rules, 'module_path_expression')

    # inline_rule(rules, "inside_expression")
    inline_rule(rules, "expression_or_cond_pattern")
    inline_rule(rules, "cond_pattern")
    # inline_rule(rules, "conditional_expression")
    rules = optimise_selections(rules)

    # solve expression - conditional_expression left recurse
    # copy cond_predicate

    split_rule(rules, "expression",
               ["inside_expression"],
               "expression_no_inside")
    replace_symbol_in_rule(
        rules, "inside_expression",
        "expression",
        "expression_no_inside")
    iterate_everything_except_first(
       rules, "inside_expression")

    # cond_predicate starting with expression_no_conditional instead of expression
    # expression_no_conditional
    split_rule(rules, "expression_no_inside",
               ["conditional_expression"],
               "expression_no_conditional")
    cond_predicate = rule_by_name(rules, "cond_predicate")
    cond_expr_predicate = deepcopy(cond_predicate)
    cond_expr_predicate.name = "cond_expr_predicate"
    rules.insert(rules.index(cond_predicate), cond_expr_predicate)
    replace_symbol_in_rule(
        rules, "cond_expr_predicate",
        "expression",
        "expression_no_conditional", only_first=True)
    replace_symbol_in_rule(
        rules, "conditional_expression",
        "cond_predicate",
        "cond_expr_predicate", only_first=True)
    iterate_everything_except_first(
       rules, "conditional_expression")
    # extract bin op
    extract_option_as_rule(rules, "expression_no_conditional", 4, "expression_bin_op")
    split_rule(rules, "expression_no_conditional",
               ["expression_bin_op"],
               "expression_no_bin_op")
    replace_symbol_in_rule(
        rules, "expression_bin_op",
        "expression",
        "expression_no_bin_op", only_first=True)
    iterate_everything_except_first(
       rules, "expression_bin_op")
    left_recurse_print(rules)

    return rules


def extract_keywords_to_specific_rule(p: SvRule2Antlr4Rule):
    keywords = set()

    def collect_keywords(obj):
        if isinstance(obj, Antlr4Symbol) and obj.is_terminal:
            s = obj.symbol
            keywords.add(s)

    for r in p.rules:
        if not r.is_lexer_rule():
            r.walk(collect_keywords)

    def get_kw_name(k):
        return "KW_" + k.replace("$", "DOLAR_").upper()

    def renamer(obj: iAntlr4GramElem):
        if isinstance(obj, Antlr4Symbol) and obj.is_terminal\
                and obj.symbol in keywords:
            obj.is_terminal = False
            obj.symbol = get_kw_name(obj.symbol)

    for r in p.rules:
        if not r.is_lexer_rule():
            r.walk(renamer)

    for k in sorted(keywords):
        kw_name = get_kw_name(k)
        kw_rule = Antlr4Rule(kw_name, Antlr4Symbol(k, True))
        p.rules.append(kw_rule)
        # if not re.match("^[A-Za-z0-9_]*$", k):
        #    print(k)


def get_all_used_lexer_tokens(rules, rule_name):
    tokens = set()
    seen = set()
    used_parser_rules = {rule_name, }

    def walk(obj: iAntlr4GramElem):
        if isinstance(obj, Antlr4Symbol) and not obj.symbol in seen:
            if obj.is_lexer_nonterminal():
                tokens.add(obj.symbol)
            elif not obj.is_terminal:
                used_parser_rules.add(obj.symbol)

    while used_parser_rules:
        r_name = used_parser_rules.pop()
        r = rule_by_name(rules, r_name)
        seen.add(r.name)
        r.walk(walk)

    return tokens


def wrap_in_lexer_mode(rules, mode_name, enter_tokens, exit_tokens, tokens, shared_tokens):
    for enter_token in enter_tokens:
        enter_rule = rule_by_name(rules, enter_token)
        enter_rule.lexer_actions.append(Antlr4LexerAction.pushMode(mode_name))

    for t_name in sorted(tokens):
        t_rule = rule_by_name(rules, t_name)
        if t_name in shared_tokens:
            # copy the rule
            # translate mode specific token to a original token
            mode_specific_t_rule = Antlr4Rule(
                mode_name + "_" + t_name, deepcopy(t_rule.body),
                lexer_mode=mode_name,
                lexer_actions=[Antlr4LexerAction.type(t_name), ]
            )
            rules.append(mode_specific_t_rule)
            t_rule = mode_specific_t_rule

        t_rule.lexer_mode = mode_name
        if t_name in sorted(exit_tokens):
            t_rule.lexer_actions.append(Antlr4LexerAction.popMode())


def pretify_regex(rules):

    def _pretify_regex(o):
        if isinstance(o, Antlr4Symbol) and o.is_regex:
            for orig, repl in [
                    ("0123456789", "0-9"),
                    ("01234567", "0-7"),
                    ("123456789", "1-9"),
                    ("abcdef", "a-f"),
                    ("ABCDEF", "A-F"),
                    ]:
                o.symbol = o.symbol.replace(orig, repl)

    for r in rules:
        if r.is_lexer_rule():
            r.walk(_pretify_regex)


def proto_grammar_to_g4():
    renames = {}
    for k, v in SvRule2Antlr4Rule.SPEC_SYMB.items():
        renames[k] = v

    p = SvRule2Antlr4Rule()
    with open("sv2017.g4_proto") as f:
        p.convert(f)
    # rm_newline_from_simple_rules(p.rules)
    # nts = get_used_non_terminals(p.rules)
    # def_nts = get_defined_non_terminals(p.rules)

    to_remove = {
       "comment",
       "one_line_comment",
       "block_comment",
       "comment_text",
    }
    # overspecified
    # finish_number 0 - 2
    replace_rule("finish_number", "UNSIGNED_NUMBER", renames, p)

    # scalar_constant 1b number
    replace_rule("scalar_constant", "integral_number", renames, p)

    # init_val 1b value
    replace_rule("init_val", "integral_number", renames, p)

    # edge_descriptor 2 tristate digits 
    # edge_descriptor: '01' | '10' | Z_OR_X ZERO_OR_ONE | ZERO_OR_ONE Z_OR_X;
    # dpi_spec_string  two concrete strings
    replace_rule("dpi_spec_string", "STRING_LITERAL", renames, p)

    # #0 -> # UNSIGNED_NUMBER
    primitive_delay = Antlr4Rule("primitive_delay", Antlr4Sequence([
        Antlr4Symbol("HASH", False),
        Antlr4Symbol("UNSIGNED_NUMBER", False),
        ]))
    p.rules.append(primitive_delay)
    replace_rule("#0", "primitive_delay", renames, p)

    # all same
    ps_identifier_rules = [
        "ps_class_identifier",
        "ps_covergroup_identifier",
        "ps_checker_identifier",
    ]
    for name in ps_identifier_rules:
        replace_rule(name, "ps_identifier", renames, p)

    ps_or_hierarchical_id_rules = [
        "ps_or_hierarchical_net_identifier",
        "ps_or_hierarchical_property_identifier",
        "ps_or_hierarchical_sequence_identifier",
        "ps_or_hierarchical_tf_identifier",
    ]

    ps_or_hierarchical_identifier = Antlr4Rule(
        "ps_or_hierarchical_identifier",
        Antlr4Selection([
            Antlr4Sequence([
                Antlr4Option(Antlr4Symbol("package_scope", False)),
                Antlr4Symbol("identifier", False)
            ]),
            Antlr4Symbol("hierarchical_identifier", False),
            ])
    )
    p.rules.append(ps_or_hierarchical_identifier)
    for name in ps_or_hierarchical_id_rules:
        replace_rule(name, "ps_or_hierarchical_identifier", renames, p)

    to_lexer = [
        "c_identifier",
        "unsigned_number",
        "simple_identifier",
        "system_tf_identifier",
        "unsigned_number",
        "string_literal",
        "binary_number",
        "octal_number",
        "hex_number",
        "octal_number",
        "hex_number",
        "fixed_point_number",
        "escaped_identifier",
        "unbased_unsized_literal",
        "time_literal",

        # because it is very hard to switch mode to parse
        # edge_descriptor and it is easy to just parse coma separated list of 2 chars
        "edge_control_specifier",
        # [TODO] lock in 'table'-'endtable' lexer mode (all following:)
        "level_symbol",
        "output_symbol",
        "edge_symbol",

        # [TODO] lock in 'library'-';' lexer mode
        "file_path_spec",
    ]
    # [TODO] extract second part of real_number (with EXP) as a lexer rule
    for tl in to_lexer:
        renames[tl] = tl.upper()

    fragments = {
        "binary_value",
        "octal_value",
        "hex_value",
        "decimal_base",
        "binary_base",
        "octal_base",
        "hex_base",
        "non_zero_unsigned_number",
        "size",
        "sign",
        "edge_descriptor",
        "non_zero_decimal_digit",
        "decimal_digit",
        "binary_digit",
        "octal_digit",
        "hex_digit",
        "x_digit",
        "z_digit",
        "exp",
        'white_space',
        'zero_or_one',
        'z_or_x',
        'Any_ASCII_Characters',
        "any_printable_ASCII_character_except_white_space",
        "time_unit"
    }

    for r in p.rules:
        if r.name.startswith("$"):
            renames[r.name] = r.name.replace("$", "dolar_")
        for fr in fragments:
            if r.name in fragments:
                r.is_fragment = True
                renames[fr] = fr.upper()

    for r in p.rules:
        rm_redunt_whitespaces_on_end(r)

    identifier_rule_equivalents = {
        r.name for r in collect_simple_rules(p.rules, "identifier")
    }
    hierarchical_identifier_rule_equivalents = {
        r.name for r in collect_simple_rules(p.rules, "hierarchical_identifier")
    }

    to_remove.update(identifier_rule_equivalents)
    to_remove.update(hierarchical_identifier_rule_equivalents)
    simple_rules_to_remove = [
        "default_clause",  # default kw
        "variable_port_type",
        "limit_value",  # used only in more specific limit values
        "dpi_function_proto",  # used only in dpi block so we already know
        "dpi_task_proto",  # used only in dpi block so we already know
        "property_lvar_port_direction",  # used only in property so we already know
        # "consecutive_repetition",  # useless
        "trans_item",
        "ordered_parameter_assignment",
        "function_statement",
        "case_expression",
        "case_item_expression",
        "open_value_range",  # used only in open_range_list so we already know
        "constant_assignment_pattern_expression",  # parser do not see the difference between const/non const
        "clockvar",  # used only in clockvar_expression
        "path_delay_expression",  # used only in more specific rules
        "constant_function_call",  # parser do not see the difference between const/non const
        "function_subroutine_call",
        "constant_let_expression",  # parser do not see the difference between const/non const
        "attr_name",  # used only in attr_spec
        "array_identifier",  # never used
        "checker_identifier",  # used only in rule with same name
        "class_identifier",
        "class_variable_identifier",
        "clocking_identifier",
        "config_identifier",
        "const_identifier",
        "constraint_identifier",
        "covergroup_identifier",
        "covergroup_variable_identifier",
        "cover_point_identifier",
        "cross_identifier",
        "enum_identifier",
        "formal_identifier",
        "function_identifier",
        "generate_block_identifier",
        "genvar_identifier",
        "hierarchical_array_identifier",
        "hierarchical_block_identifier",
        "hierarchical_event_identifier",
        "hierarchical_net_identifier",
        "hierarchical_parameter_identifier",
        "hierarchical_property_identifier",
        "hierarchical_sequence_identifier",
        "hierarchical_task_identifier",
        "hierarchical_tf_identifier",
        "hierarchical_variable_identifier",
        "index_variable_identifier",
        "interface_identifier",
        "interface_instance_identifier",
        # "inout_port_identifier",
        # "input_port_identifier",
        "instance_identifier",
        "member_identifier",
        "method_identifier",
        "modport_identifier",
        "module_identifier",
        "net_identifier",
        # "output_port_identifier"
        "package_identifier",
        "parameter_identifier",
        "port_identifier",
        "production_identifier",
        "program_identifier",
        "property_identifier",
        "sequence_identifier",
        "signal_identifier",
        "specparam_identifier",
        "task_identifier",
        "tf_identifier",
        "terminal_identifier",
        "topmodule_identifier",
        "udp_identifier",
        "variable_identifier",
    ]
    for sr in simple_rules_to_remove:
        remove_simple_rule(sr, p)
    p.rules = [r for r in p.rules if r.name not in to_remove]

    for idname in identifier_rule_equivalents:
        renames[idname] = "identifier"

    for idname in hierarchical_identifier_rule_equivalents:
        renames[idname] = "hierarchical_identifier"

    apply_rename = generate_renamer(renames, True)
    for r in p.rules:
        r.walk(apply_rename)
        r.walk(mark_regex)

    extract_keywords_to_specific_rule(p)

    # because C_IDENTIFIER is just normal identifier without $ and can match identifiers
    for r in p.rules:
        if r.name == "identifier":
            r.body.insert(0, Antlr4Symbol("C_IDENTIFIER", False))

    add_string_literal_rules(p)
    add_file_path_literal_rules(p)
    already_eps_rules = [
        "tf_port_list",
        "data_type_or_implicit",
        "list_of_arguments",
        "let_list_of_arguments",
        "list_of_port_connections",
        "list_of_checker_port_connections",
        "sequence_list_of_arguments",
        "property_list_of_arguments",
    ]
    # because it already can be eps
    for r in already_eps_rules:
        rm_option_on_rule_usage(p.rules, r)
    p.rules = [r for r in p.rules if r.name != "WHITE_SPACE"]
    p.rules = left_recurse_remove(p.rules)
    extract_option_as_rule(p.rules, "real_number", 1, "REAL_NUMBER_WITH_EXP")
    extract_option_as_rule(p.rules, "decimal_number", 1, "DECIMAL_NUMBER_WITH_BASE")
    extract_option_as_rule(p.rules, "decimal_number", 2, "DECIMAL_TRISTATE_NUMBER_WITH_BASE")

    for k, v in SvRule2Antlr4Rule.SPEC_SYMB.items():
        body = Antlr4Symbol(k, True)
        r = Antlr4Rule(v, body)
        p.rules.append(r)

    table_tokens = get_all_used_lexer_tokens(p.rules, "combinational_body")
    table_tokens2 = get_all_used_lexer_tokens(p.rules, "sequential_entry")
    table_tokens = table_tokens.union(table_tokens2)
    # [TODO] += comments, whitespaces
    table_tokens.remove("KW_TABLE")
    table_shared_tokens = {'SEMI', 'RPAREN', 'COLON', 'LPAREN', 'MINUS'}
    wrap_in_lexer_mode(p.rules, "TABLE_MODE", {"KW_TABLE", }, {"KW_ENDTABLE", },
                       table_tokens, table_shared_tokens)

    library_identifier_tokens = get_all_used_lexer_tokens(p.rules, "identifier")
    wrap_in_lexer_mode(p.rules, "LIBRARY_IDENTIFIER_MODE", {"KW_LIBRARY", },
                       # all possible identifiers can appear and all of the ending this mode
                       library_identifier_tokens,
                       library_identifier_tokens,
                       library_identifier_tokens)
    library_path_tokens = (get_all_used_lexer_tokens(p.rules, "library_declaration") 
                           -library_identifier_tokens 
                           -{"KW_LIBRARY", })
    wrap_in_lexer_mode(p.rules, "INCLUDE_MODE",
                       # starts after library id
                       {"KW_INCLUDE"},
                       {"SEMI"},
                       {"FILE_PATH_SPEC", "SEMI"},
                       {"SEMI"})

    wrap_in_lexer_mode(p.rules, "LIBRARY_PATH_MODE",
                       # starts after library id
                       {"LIBRARY_IDENTIFIER_MODE_" + t for t in library_identifier_tokens},
                       {"SEMI"},
                       library_path_tokens,
                       {"MINUS", "SEMI", "COMMA", "FILE_PATH_SPEC"})

    # inline_to_fragments = [
    #     "X_DIGIT",
    #     "Z_DIGIT",
    # ]
    # for n in inline_to_fragments:
    #     inline_rule(p.rules, n)
    # def inline_questionmark(o: iAntlr4GramElem):
    #    if isinstance(o, Antlr4Symbol) and o.symbol == "QUESTIONMARK":
    #        o.is_terminal = True
    #        o.symbol = "?"
    #
    # for r in p.rules:
    #    if r.is_fragment
    reduce_optionality(p.rules)
    pretify_regex(p.rules)
    p.rules.sort(key=lambda x: ("" if x.lexer_mode is None else x.lexer_mode,
                                not x.name.startswith("KW_"),
                                x.name == x.name.upper(),
                                x.is_fragment))

    with open("sv2017Parser.g4", "w") as f:
        # f.write("\n// ---------- PARSER ----------\n\n")
        f.write("parser grammar sv2017Parser;\noptions { tokenVocab=sv2017Lexer; }\n\n")
        for r in p.rules:
            # print(r)
            if not r.is_lexer_rule():
                f.write(r.toAntlr4())
                f.write("\n")
                assert r.lexer_mode is None
                assert len(r.lexer_actions) == 0

    with open("sv2017Lexer.g4", "w") as f:
        # f.write("// ---------- LEXER ----------\n\n")
        f.write("lexer grammar sv2017Lexer;\n\n")

        lexer_mode = None
        for r in p.rules:
            # print(r)
            if r.is_lexer_rule():
                f.write(r.toAntlr4(actual_lexer_node=lexer_mode))
                f.write("\n")
                lexer_mode = r.lexer_mode
        f.write("""

mode DEFAULT_MODE;
ONE_LINE_COMMENT: '//' .*? '\\r'? '\\n' -> channel (HIDDEN);
BLOCK_COMMENT: '/*' .*? '*/' -> channel (HIDDEN);
WHITE_SPACE: [ \\t\\n\\r] + -> skip;
""")

if __name__ == "__main__":
    # parse_sv_pdf()
    proto_grammar_to_g4()
