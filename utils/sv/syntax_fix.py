from copy import deepcopy

from utils.antlr4.grammar import Antlr4Selection, Antlr4Rule, Antlr4Symbol, \
    rule_by_name, Antlr4Sequence, Antlr4Option, Antlr4Iteration, \
    generate_renamer
from utils.antlr4._utils import replace_item_by_sequence, _inline_rule, \
    _replace_symbol_in_rule
from utils.sv._utils import get_all_used_lexer_tokens, wrap_in_lexer_mode,\
    collect_keywords

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

# def fix_cross_body_item(rules):
#     """
#     There is an extra ';' after bins_selection_or_option
#     but the ';' is already in bins_selection_or_option rule
#     """
#     r = rule_by_name(rules, "cross_body_item")
#     semi = Antlr4Symbol("SEMI", False)
# 
#     def match_replace_fn(o):
#         if o == semi:
#             return Antlr4Sequence([])
# 
#     replace_item_by_sequence(r.body, match_replace_fn)


def fix_randomize_call(rules):
    # randomize_call:
    #   KW_RANDOMIZE ( attribute_instance )*
    #   ( LPAREN ( variable_identifier_list | KW_NULL )? RPAREN )?
    #   ( KW_WITH ( LPAREN ( identifier_list )? RPAREN )? constraint_block )?;
    
    rnm = generate_renamer({"variable_identifier_list": "randomize_arg_list"}, False)
    for r in rules:
        r.walk(rnm)
        if r.name == "randomize_arg_list":
            randomize_arg_list = r
    _replace_symbol_in_rule(randomize_arg_list, "identifier", "hierarchical_identifier")


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


def fix_dpi_import_export(rules):
    C_IDENTIFIER = Antlr4Symbol("C_IDENTIFIER", False)

    def match_replace_fn(o):
        if o == C_IDENTIFIER:
            return Antlr4Selection([C_IDENTIFIER, Antlr4Symbol("ESCAPED_IDENTIFIER", False)])

    r = rule_by_name(rules, "dpi_import_export")
    replace_item_by_sequence(r.body, match_replace_fn)
