#!/usr/bin/env python3

"""
"main" for scripts which extract, fixes and optimizes the grammar from pdf with 1800-2017 standard
"""

import os

from utils.antlr4._utils import collect_simple_rules, \
    remove_simple_rule, extract_option_as_rule
from utils.antlr4.auto_format import remove_any_visuals, auto_format
from utils.antlr4.generic_optimiser import Antlr4GenericOptimizer
from utils.antlr4.grammar import Antlr4Rule, Antlr4Symbol, Antlr4Sequence, \
    Antlr4Selection, generate_renamer, \
    rule_by_name
from utils.antlr4.simple_parser import Antlr4parser
from utils.sv._utils import mark_regex, extract_keywords_to_specific_rule, \
    replace_rule, collect_keywords, pretify_regex
from utils.sv.keywords import IEEE1800_2017_KEYWORDS
from utils.sv.lr_rm import left_recurse_remove
from utils.sv.pdf_parsing import parse_sv_pdf
from utils.sv.perf_fix import rm_option_from_eps_rules, rm_ambiguity, \
    optimize_class_scope, add_eof, inline_unique_variant_of_rules, \
    optimize_select, other_performance_fixes
from utils.sv.rule2Antlr4Rule import SvRule2Antlr4Rule
from utils.sv.rules_defined_in_text import add_string_literal_rules, \
    add_comments_and_ws
from utils.sv.syntax_fix import fix_SYSTEM_TF_IDENTIFIER, \
    fix_lexer_for_table_def, \
    rm_semi_from_cross_body_item, add_interface_class_declaration, fix_class_scope, \
    fix_randomize_call, fix_dpi_import_export
from utils.sv.version_dependent_grammar import std_version_specific_keywords, \
    print_lexer_extra_for_std_version_specific_keywords


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
                Antlr4Symbol("package_scope", False),
                Antlr4Symbol("identifier", False)
            ]),
            # can be only identifier
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
       
        # libary rules
        "library_text",
        "library_description",
        "library_declaration",
        "include_statement",
        "file_path_spec",
        "file_path_spec",
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
        "let_identifier",
        "type_identifier",

        # covergroup_expression
        "with_covergroup_expression",
        "set_covergroup_expression",
        "integer_covergroup_expression",
        "cross_set_expression",

        "data_event",
        "reference_event",
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


def better_names_for_single_purpose_rules(rules):
    renames = {"ps_or_hierarchical_array_identifier": "foreach_ps_or_hierarchical_array_identifier"}
    rnm = generate_renamer(renames, False)
    for r in rules:
        r.walk(rnm)


def lexer_friendly_numbers(p):

    def par(s):
        return Antlr4parser().from_str(s)

    extract_option_as_rule(p.rules, "real_number",
                           [(1, par("UNSIGNED_NUMBER ( DOT UNSIGNED_NUMBER )? EXP ( SIGN )? UNSIGNED_NUMBER")), ],
                           "REAL_NUMBER_WITH_EXP")
    extract_option_as_rule(p.rules, "decimal_number",
                           [(1, par("( SIZE )? DECIMAL_BASE UNSIGNED_NUMBER")), ],
                           "DECIMAL_NUMBER_WITH_BASE")
    extract_option_as_rule(p.rules, "decimal_number",
                           [(2, par("( SIZE )? DECIMAL_BASE X_DIGIT ( UNDERSCORE )*")), ],
                           "DECIMAL_INVALID_NUMBER_WITH_BASE")
    extract_option_as_rule(p.rules, "decimal_number",
                           [(3, par("( SIZE )? DECIMAL_BASE Z_DIGIT ( UNDERSCORE )*")), ],
                           "DECIMAL_TRISTATE_NUMBER_WITH_BASE")


UTILS_ROOT = os.path.join(os.path.dirname(__file__), "..")


def proto_grammar_to_g4():
    # [NOTE] dissable this if you need java compatible parser/lexer
    CONFIGURABLE_STD_VERSION = True
    
    p = SvRule2Antlr4Rule()
    with open(os.path.join(UTILS_ROOT, "sv2017.g4_proto")) as f:
        p.convert(f)

    for r in p.rules:
        r.walk(mark_regex)
    remove_any_visuals(p.rules)
    remove_useless_and_normalize_names(p)
    lexer_friendly_numbers(p)
    fix_SYSTEM_TF_IDENTIFIER(p.rules)
    extract_keywords_to_specific_rule(p)
    add_string_literal_rules(p)
    # add_file_path_literal_rules(p)
    add_comments_and_ws(p.rules)
    rm_option_from_eps_rules(p)
    Antlr4GenericOptimizer().optimize(p.rules)
    inline_unique_variant_of_rules(p.rules)
    Antlr4GenericOptimizer().optimize(p.rules)
    pretify_regex(p.rules)
    p.rules = left_recurse_remove(p.rules)

    fix_lexer_for_table_def(p)
    # fix_lexer_for_library_def(p)
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
    rm_ambiguity(p.rules)
    rm_semi_from_cross_body_item(p.rules)
    add_interface_class_declaration(p.rules)
    fix_class_scope(p.rules)
    optimize_select(p.rules)
    # fix_cross_body_item(p.rules)
    fix_randomize_call(p.rules)
    fix_dpi_import_export(p.rules)
    better_names_for_single_purpose_rules(p.rules)
    optimize_class_scope(p.rules)
    other_performance_fixes(p.rules)
    add_eof(p.rules)
    Antlr4GenericOptimizer().optimize(p.rules)
    if CONFIGURABLE_STD_VERSION:
        std_version_specific_keywords(p.rules)
    
    auto_format(p.rules)
    p.rules.sort(key=lambda x: ("" if x.lexer_mode is None else x.lexer_mode,
                                not x.name.startswith("KW_"),
                                x.name == x.name.upper(),
                                x.is_fragment))
    root = os.path.join(UTILS_ROOT, "..", "grammars")
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
        if CONFIGURABLE_STD_VERSION:
            print_lexer_extra_for_std_version_specific_keywords(f)

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
