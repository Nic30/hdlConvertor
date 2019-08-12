#!/usr/bin/env python3

"""
"main" for scripts which extract, fixes and optimizes the grammar from pdf with 1800-2017 standard
"""

from antlr4grammar import Antlr4Rule, Antlr4Symbol, Antlr4Sequence, \
    Antlr4Selection, Antlr4Option, generate_renamer, \
    iAntlr4GramElem, rule_by_name, Antlr4LexerAction, Antlr4Iteration
from svRule2Antlr4Rule import SvRule2Antlr4Rule
from antlr4_utils import rm_redunt_whitespaces_on_end, collect_simple_rules, \
    remove_simple_rule, rm_option_on_rule_usage, extract_option_as_rule, \
    replace_item_by_sequence, inline_rule, _inline_rule
from copy import deepcopy
from optionality_optimiser import reduce_optionality
from sv_rules_defined_in_text import add_string_literal_rules, \
    add_file_path_literal_rules
from sv_lr_rm import left_recurse_remove
import os
from sv.keywords import IEEE1800_2017_KEYWORDS
from svStd_pdf_parsing import parse_sv_pdf


def replace_rule(rule_name, replace_rule_name, names_to_replace, parser):
    parser.rules = [p for p in parser.rules if p.name != rule_name]
    names_to_replace[rule_name] = replace_rule_name


def mark_regex(obj: iAntlr4GramElem):
    if isinstance(obj, Antlr4Symbol) and obj.symbol in [
            '[a-zA-Z_]', '[a-zA-Z0-9_$]', '[a-zA-Z0-9_]']:
        obj.is_regex = True


def collect_keywords(rules):
    keywords = set()

    def _collect_keywords(obj):
        if isinstance(obj, Antlr4Symbol) and obj.is_terminal:
            s = obj.symbol
            keywords.add(s)

    for r in rules:
        if not r.is_lexer_rule():
            r.walk(_collect_keywords)
    return keywords


def extract_keywords_to_specific_rule(p: SvRule2Antlr4Rule):
    keywords = collect_keywords(p.rules)

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
    return keywords


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

    for t_name in sorted(tokens.union(shared_tokens)):
        t_rule = rule_by_name(rules, t_name)
        if t_name in shared_tokens:
            # copy the rule
            # translate mode specific token to a original token
            actions = deepcopy(t_rule.lexer_actions)
            if not Antlr4LexerAction.skip() in actions:
                actions.append(Antlr4LexerAction.type(t_name))
            mode_specific_t_rule = Antlr4Rule(
                mode_name + "_" + t_name, deepcopy(t_rule.body),
                lexer_mode=mode_name,
                lexer_actions=actions
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


def rm_option_from_eps_rules(p):
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


def remove_useless_and_normalize_names(p):
    renames = {}
    for k, v in SvRule2Antlr4Rule.SPEC_SYMB.items():
        renames[k] = v
    # rm_newline_from_simple_rules(p.rules)
    # nts = get_used_non_terminals(p.rules)
    # def_nts = get_defined_non_terminals(p.rules)

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
        "level_symbol",
        "output_symbol",
        "edge_symbol",

        "file_path_spec",
    ]
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

    to_remove = {
       "comment",
       "one_line_comment",
       "block_comment",
       "comment_text",
       "white_space",
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

    for k, v in SvRule2Antlr4Rule.SPEC_SYMB.items():
        body = Antlr4Symbol(k, True)
        r = Antlr4Rule(v, body)
        if k == '"':
            r.is_fragment = True
        p.rules.append(r)

    # because C_IDENTIFIER is just normal identifier without $ and can match identifiers
    identifier = rule_by_name(p.rules, "identifier")
    identifier.body.insert(0, Antlr4Symbol("C_IDENTIFIER", False))

    kws = collect_keywords(p.rules)
    for kw in kws:
        if kw not in IEEE1800_2017_KEYWORDS and kw != "1step" and "$" not in kw:
            identifier.body.append(Antlr4Symbol("KW_" + kw.upper(), False))


COMMENT_AND_WS_TOKENS = {"ONE_LINE_COMMENT", "BLOCK_COMMENT", "WHITE_SPACE"}


def fix_lexer_for_table_def(p):
    # because OUTPUT_SYMBOL is a special case of LEVEL_SYMBOL
    OUTPUT_SYMBOL = Antlr4Symbol("OUTPUT_SYMBOL", False)

    def OUTPUT_SYMBOL_to_LEVEL_SYMBOL(o):
        if o == OUTPUT_SYMBOL:
            o.symbol = "LEVEL_SYMBOL"

    for r in p.rules:
        r.body.walk(OUTPUT_SYMBOL_to_LEVEL_SYMBOL)
    p.rules.remove(rule_by_name(p.rules, "OUTPUT_SYMBOL"))
    table_tokens = get_all_used_lexer_tokens(p.rules, "combinational_body")
    table_tokens2 = get_all_used_lexer_tokens(p.rules, "sequential_entry")
    table_tokens = table_tokens.union(table_tokens2)

    # [TODO] += comments, whitespaces
    table_tokens.remove("KW_TABLE")
    table_shared_tokens = {'SEMI', 'RPAREN', 'COLON', 'LPAREN', 'MINUS',
                           *COMMENT_AND_WS_TOKENS}
    wrap_in_lexer_mode(p.rules, "TABLE_MODE", {"KW_TABLE", }, {"KW_ENDTABLE", },
                       table_tokens, table_shared_tokens)


def fix_lexer_for_library_def(p):
    library_identifier_tokens = get_all_used_lexer_tokens(p.rules, "identifier")
    wrap_in_lexer_mode(p.rules, "LIBRARY_IDENTIFIER_MODE", {"KW_LIBRARY", },
                       # all possible identifiers can appear and all of the ending this mode
                       library_identifier_tokens,
                       library_identifier_tokens,
                       library_identifier_tokens.union(COMMENT_AND_WS_TOKENS))
    library_path_tokens = (get_all_used_lexer_tokens(p.rules, "library_declaration") 
                           -library_identifier_tokens 
                           -{"KW_LIBRARY", })
    wrap_in_lexer_mode(p.rules, "INCLUDE_MODE",
                       # starts after library id
                       {"KW_INCLUDE"},
                       {"SEMI"},
                       {"FILE_PATH_SPEC", "SEMI"},
                       {"SEMI", *COMMENT_AND_WS_TOKENS})

    wrap_in_lexer_mode(p.rules, "LIBRARY_PATH_MODE",
                       # starts after library id
                       {"LIBRARY_IDENTIFIER_MODE_" + t for t in library_identifier_tokens},
                       {"SEMI"},
                       library_path_tokens,
                       {"MINUS", "SEMI", "COMMA", "FILE_PATH_SPEC", *COMMENT_AND_WS_TOKENS})


def add_comments_and_ws(rules):
    # ONE_LINE_COMMENT: '//' .*? '\\r'? '\\n' -> channel(HIDDEN);
    olc = Antlr4Rule("ONE_LINE_COMMENT", Antlr4Sequence([
            Antlr4Symbol("//", True),
            Antlr4Symbol(".*?", True, is_regex=True),
            Antlr4Option(Antlr4Symbol("\r", True)),
            Antlr4Symbol("\n", True),
        ]),
        lexer_actions=[Antlr4LexerAction.channel("HIDDEN")])
    rules.append(olc)
    # BLOCK_COMMENT: '/*' .*? '*/' -> channel (HIDDEN);
    bc = Antlr4Rule("BLOCK_COMMENT", Antlr4Sequence([
            Antlr4Symbol("/*", True),
            Antlr4Symbol(".*?", True, is_regex=True),
            Antlr4Symbol("*/", True),
        ]),
        lexer_actions=[Antlr4LexerAction.channel("HIDDEN")])
    rules.append(bc)
    # WHITE_SPACE: [ \\t\\n\\r] + -> skip;
    ws = Antlr4Rule("WHITE_SPACE", Antlr4Sequence([
            Antlr4Symbol("[ \\t\\n\\r] +", True, is_regex=True),
        ]),
        lexer_actions=[Antlr4LexerAction.skip()])
    rules.append(ws)


def rm_ambiguity(rules):
    rule = rule_by_name(rules, "variable_decl_assignment")
    to_repl = Antlr4Option(Antlr4Sequence([
        Antlr4Symbol("ASSIGN", False),
        Antlr4Symbol("class_new", False)
    ]))

    def match_replace_fn(o):
        if o == to_repl:
            return o.body

    replace_item_by_sequence(rule, match_replace_fn)


def rm_semi_from_cross_body_item(rules):
    """
    Because SEMI is already part of cross_body_item
    """
    rule = rule_by_name(rules, "cross_body")
    semi = Antlr4Symbol("SEMI", False)

    def match_replace_fn(o):
        if o == semi:
            return Antlr4Sequence([])

    replace_item_by_sequence(rule.body[0], match_replace_fn)


def add_interface_class_declaration(rules):
    """
    Because interface_class_definition is not used anywhere
    (is missing in specified rules)
    """
    intf = Antlr4Symbol("interface_class_declaration", False)
    cls = Antlr4Symbol("class_declaration", False)

    def match_replace_fn(o):
        if o == cls:
            return Antlr4Selection([o, deepcopy(intf)])

    for rule in rules:
        replace_item_by_sequence(rule, match_replace_fn)


def fix_priority_of__class_scope__package_scope(rules):
    orig = Antlr4Selection([Antlr4Symbol("class_scope", False),
                            Antlr4Symbol("package_scope", False)])
    repl = Antlr4Selection([Antlr4Symbol("package_scope", False),
                            Antlr4Symbol("class_scope", False)])

    def match_replace_fn(o):
        if o == orig:
            return deepcopy(repl)

    for rule in rules:
        replace_item_by_sequence(rule, match_replace_fn)


def fix_class_scope(rules):
    """
    Because otherwise class_type consume last id after ::
    and it is not possible to recover
    """
    r = rule_by_name(rules, "class_scope")
    _inline_rule([r, ], rule_by_name(rules, "class_type"))


def fix_call(rules):
    # inline_rule(rules, "ps_identifier")
    r = rule_by_name(rules, "subroutine_call")
    r.body.insert(0, Antlr4Sequence([
        Antlr4Option(Antlr4Symbol("class_qualifier", False)),
        Antlr4Symbol("method_call_body", False)
        ]))


def fix_implicit_data_type(rules):
    r = rule_by_name(rules, "implicit_data_type")
    # : (signing)? (packed_dimension)*
    # ->
    # : signing (packed_dimension)*
    # | (packed_dimension)+
    # ;
    r.body = Antlr4Selection([
        Antlr4Sequence([Antlr4Symbol("signing", False), Antlr4Iteration(Antlr4Symbol("packed_dimension", False))]),
        Antlr4Iteration(Antlr4Symbol("packed_dimension", False), positive=True)
    ])


def fix_SYSTEM_TF_IDENTIFIER(rules):
    kws = collect_keywords(rules)
    SYSTEM_TF_IDENTIFIER = Antlr4Symbol("SYSTEM_TF_IDENTIFIER", False)
    any_system_tf_identifier = Antlr4Symbol("any_system_tf_identifier", False)

    def match_replace_fn(o):
        if o == SYSTEM_TF_IDENTIFIER:
            return deepcopy(any_system_tf_identifier)

    for rule in rules:
        replace_item_by_sequence(rule, match_replace_fn)

    rules.append(Antlr4Rule("any_system_tf_identifier", Antlr4Selection([
        SYSTEM_TF_IDENTIFIER,
        *[Antlr4Symbol(kw.replace("$", "KW_DOLAR_").upper(), False)
          for kw in kws if kw.startswith("$")]
        ])))


def proto_grammar_to_g4():
    p = SvRule2Antlr4Rule()
    with open("sv2017.g4_proto") as f:
        p.convert(f)

    for r in p.rules:
        r.walk(mark_regex)

    remove_useless_and_normalize_names(p)
    fix_SYSTEM_TF_IDENTIFIER(p.rules)
    extract_keywords_to_specific_rule(p)
    add_string_literal_rules(p)
    add_file_path_literal_rules(p)
    add_comments_and_ws(p.rules)
    rm_option_from_eps_rules(p)
    p.rules = left_recurse_remove(p.rules)
    extract_option_as_rule(p.rules, "real_number", [1, ], "REAL_NUMBER_WITH_EXP")
    extract_option_as_rule(p.rules, "decimal_number", [1, ], "DECIMAL_NUMBER_WITH_BASE")
    extract_option_as_rule(p.rules, "decimal_number", [2, ], "DECIMAL_TRISTATE_NUMBER_WITH_BASE")

    fix_lexer_for_table_def(p)
    fix_lexer_for_library_def(p)
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
    rm_ambiguity(p.rules)
    rm_semi_from_cross_body_item(p.rules)
    add_interface_class_declaration(p.rules)
    fix_priority_of__class_scope__package_scope(p.rules)
    fix_class_scope(p.rules)
    # fix_implicit_data_type(p.rules)
    fix_call(p.rules)
    p.rules.sort(key=lambda x: ("" if x.lexer_mode is None else x.lexer_mode,
                                not x.name.startswith("KW_"),
                                x.name == x.name.upper(),
                                x.is_fragment))
    root = os.path.join("..", "grammars")
    # root = ""
    with open(os.path.join(root, "sv2017Parser.g4"), "w") as f:
        # f.write("\n// ---------- PARSER ----------\n\n")
        f.write("parser grammar sv2017Parser;\noptions { tokenVocab=sv2017Lexer; }\n\n")
        for r in p.rules:
            # print(r)
            if not r.is_lexer_rule():
                f.write(r.toAntlr4())
                f.write("\n")
                assert r.lexer_mode is None
                assert len(r.lexer_actions) == 0

    with open(os.path.join(root, "sv2017Lexer.g4"), "w") as f:
        # f.write("// ---------- LEXER ----------\n\n")
        f.write("lexer grammar sv2017Lexer;\n\n")

        lexer_mode = None
        for r in p.rules:
            # print(r)
            if r.is_lexer_rule():
                f.write(r.toAntlr4(actual_lexer_node=lexer_mode))
                f.write("\n")
                lexer_mode = r.lexer_mode


if __name__ == "__main__":
    # parse_sv_pdf()
    proto_grammar_to_g4()
