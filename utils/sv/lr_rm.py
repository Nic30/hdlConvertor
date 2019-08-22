from copy import deepcopy

from utils.antlr4._utils import inline_rule, replace_symbol_in_rule, extract_option_as_rule, \
    _inline_rule
from utils.antlr4.grammar import Antlr4Symbol, Antlr4Selection, rule_by_name, \
    Antlr4Sequence, Antlr4Iteration, Antlr4Rule, iAntlr4GramElem, Antlr4Option
from utils.antlr4.left_recurse_remove import direct_left_recurse_rm, split_rule, \
    iterate_everything_except_first
from utils.sv.rule2Antlr4Rule import SvRule2Antlr4Rule
from utils.sv.precedence import get_bin_op_precedence
from utils.antlr4.simple_parser import Antlr4parser
from utils.antlr4.generic_optimiser import Antlr4GenericOptimizer



def get_operator_precedence_groups():
    symbol_names = deepcopy(SvRule2Antlr4Rule.SPEC_SYMB)
    symbol_names.update({
        "inside": "KW_INSIDE",
        "dist": "KW_DIST",
        "?:": "QUESTIONMARK",
    })
    return get_bin_op_precedence(symbol_names)


def solve_left_recurse_and_op_precedence_for_expression(rules):
    # split_rule(rules, "expression",
    #            ["inside_expression"],
    #            "expression_no_inside")
    # replace_symbol_in_rule(
    #     rules, "inside_expression",
    #     "expression",
    #     "expression_no_inside")
    # iterate_everything_except_first(
    #    rules, "inside_expression")
    #
    # # cond_predicate starting with expression_no_conditional instead of expression
    # # expression_no_conditional
    # split_rule(rules, "expression_no_inside",
    #            ["conditional_expression"],
    #            "expression_no_conditional")

    # expression only from rules for highest precedence ops etc.

    # expression:
    # ( unary_operator ( attribute_instance )* )? primary 
    #  | inc_or_dec_expression 
    #  | LPAREN operator_assignment RPAREN 
    #  | expression binary_operator ( attribute_instance )* expression 
    #  | conditional_expression 
    #  | expression KW_INSIDE LBRACE open_range_list RBRACE 
    #  | tagged_union_expression 
    # ;
    p = Antlr4parser()
    expression_0 = extract_option_as_rule(
            rules, "expression", [
                (0, p.from_str("( unary_operator ( attribute_instance )* )? primary")),
                (1, p.from_str("inc_or_dec_expression")),
                (2, p.from_str("LPAREN operator_assignment RPAREN")),
                (6, p.from_str("tagged_union_expression")),
            ], "expression_0",
    )
    # expression:
    #   | expression binary_operator ( attribute_instance )* expression 
    #   | conditional_expression 
    #   | expression KW_INSIDE LBRACE open_range_list RBRACE;

    def handle_conditional_fn(bin_op_choices, current_expr_rule):
        # rm left recursion from cond_predicate/conditional_expression
        cond_predicate = rule_by_name(rules, "cond_predicate")
        conditional_expression = rule_by_name(rules, "conditional_expression")
        rules.remove(conditional_expression)
        _inline_rule([conditional_expression, ], cond_predicate)
 
        bin_op_choices.append(
            Antlr4Sequence(conditional_expression.body[1:])
        )

    def handle_inside_fn(bin_op_choices, current_expr_rule):
        # expression (KW_INSIDE LBRACE open_range_list RBRACE)*;
        bin_op_choice = Antlr4parser().from_str("KW_INSIDE LBRACE open_range_list RBRACE")
        bin_op_choices.append(bin_op_choice)

    rules.remove(rule_by_name(rules, "expression"))
    current_expr_rule = expression_0
    op_group = get_operator_precedence_groups()
    for i, prec_group in enumerate(op_group):
        is_last = i == len(op_group) - 1
        if is_last:
            new_rule_name = "expression"
        else:
            new_rule_name = "expression_%d" % (i + 1)
        current_expr_rule = extract_bin_ops(
            rules, current_expr_rule, prec_group, new_rule_name,
            handle_conditional_fn, handle_inside_fn)

    # split_rule(rules, "expression",
    #           ["conditional_expression"],
    #           "expression_no_conditional")

    # extract bin op
    # extract_option_as_rule(rules, "expression_no_conditional", [4,], "expression_bin_op")
    # split_rule(rules, "expression_no_conditional",
    #           ["expression_bin_op"],
    #           "expression_no_bin_op")
    # replace_symbol_in_rule(
    #    rules, "expression_bin_op",
    #    "expression",
    #    "expression_no_bin_op", only_first=True)
    # iterate_everything_except_first(
    #   rules, "expression_bin_op")
    # left_recurse_print(rules)


def solve_left_recurse_and_op_precedence_for_constant_expression(rules):
    # constant_expression:
    #       (unary_operator ( attribute_instance )*)? constant_primary 
    #       | constant_expression binary_operator ( attribute_instance )* constant_expression 
    #       | constant_expression QUESTIONMARK ( attribute_instance )* constant_expression COLON constant_expression;

    c_expression_0 = extract_option_as_rule(
            rules, "constant_expression",
            [(0, Antlr4parser().from_str("( unary_operator ( attribute_instance )* )? constant_primary"))],
            "constant_expression_0")
    # constant_expression_0:
    #       ( unary_operator ( attribute_instance )* )? constant_primary 

    def handle_conditional_fn(bin_op_choices, current_expr_rule):
        bin_op_choices.append(
            Antlr4parser().from_str(
            "QUESTIONMARK ( attribute_instance )* constant_expression COLON constant_expression")    
        )

    def handle_inside_fn(bin_op_choices, current_expr_rule):
        pass

    rules.remove(rule_by_name(rules, "constant_expression"))
    current_expr_rule = c_expression_0
    op_group = get_operator_precedence_groups()
    for i, prec_group in enumerate(op_group):
        is_last = i == len(op_group) - 1
        if is_last:
            new_rule_name = "constant_expression"
        else:
            new_rule_name = "constant_expression_%d" % (i + 1)
        current_expr_rule = extract_bin_ops(
            rules, current_expr_rule, prec_group, new_rule_name,
            handle_conditional_fn, handle_inside_fn)


def extract_bin_ops(rules, current_expr_rule, ops_to_extrat, new_rule_name,
                    handle_conditional_fn, handle_inside_fn):
    # find option with binary op rule
    # expr = rule_by_name(rules, "expression")
    ops_no_special = [o for o in ops_to_extrat
                      if o not in ["KW_INSIDE", "KW_DIST", "QUESTIONMARK", ]]

    bin_op_choices = []
    if len(ops_no_special) > 0:
        if len(ops_no_special) == 1:
            op = Antlr4Symbol(ops_no_special[0], False)
        else:
            op = Antlr4Selection([Antlr4Symbol(o, False) for o in ops_no_special])

        # expression (binary_operator ( attribute_instance )* expression)*
        bin_op_choice = Antlr4Sequence([
            op,
            Antlr4Iteration(Antlr4Symbol("attribute_instance", False)),
            Antlr4Symbol(current_expr_rule.name, False)
        ])
        bin_op_choices.append(bin_op_choice)

    if "KW_INSIDE" in ops_to_extrat:
        handle_inside_fn(bin_op_choices, current_expr_rule)

    if "KW_DIST" in ops_to_extrat:
        # handled differently, only allowed on specified places
        pass

    if "QUESTIONMARK" in ops_to_extrat:
        handle_conditional_fn(bin_op_choices, current_expr_rule)

    for c in bin_op_choices:
        assert isinstance(c, iAntlr4GramElem), c
    # create a new rule which contains rule for extracted binary operators
    if len(bin_op_choices) > 1:
        new_body = Antlr4Selection(bin_op_choices)
    else:
        new_body = bin_op_choices[0]
    new_body = Antlr4Sequence([
        Antlr4Symbol(current_expr_rule.name, False),
        Antlr4Iteration(new_body)
    ])
    new_r = Antlr4Rule(new_rule_name, new_body)
    rules.insert(rules.index(current_expr_rule), new_r)

    return new_r


def fix_subroutine_call(rules):
    r = rule_by_name(rules, "subroutine_call")
    r.body.insert(0, Antlr4Sequence([
        Antlr4Option(Antlr4Symbol("class_qualifier", False)),
        Antlr4Symbol("method_call_body", False)
        ]))

def optimise_subroutine_call(rules):
    r = rule_by_name(rules, "subroutine_call")
    Antlr4GenericOptimizer().optimize([r, ])
    c0 = Antlr4parser().from_str("""
    ( class_qualifier | ( primary | implicit_class_handle ) DOT )?
    ( 
        identifier ( attribute_instance )* ( LPAREN list_of_arguments RPAREN )? 
        |  array_method_name ( attribute_instance )* ( LPAREN list_of_arguments RPAREN )?
            ( KW_WITH LPAREN expression RPAREN )? 
        | randomize_call 
    )

    """)
    assert r.body[0].eq_relaxed(c0), r.body[0]
    subroutine_call_args = Antlr4Rule("subroutine_call_args", Antlr4parser().from_str("""
        ( attribute_instance )* ( LPAREN list_of_arguments RPAREN )? 
        ( KW_WITH LPAREN expression RPAREN )?
    """))
    rules.insert(rules.index(r), subroutine_call_args)
    new_c0 = Antlr4parser().from_str("""
    ( primary_no_cast_no_call
      | cast 
    )
    subroutine_call_args
    ( 
       DOT ( array_method_name | randomize_call | primary_no_cast_no_call | cast )
       subroutine_call_args
    )*
    """)
    r.body[0] = new_c0
    primary = rule_by_name(rules, "primary")
    assert primary.body[0].eq_relaxed(Antlr4Symbol("primary_no_cast_no_call", False))
    del primary.body[0]

    c2 =  Antlr4parser().from_str("""
        any_system_tf_identifier ( LPAREN ( list_of_arguments 
                                      | data_type ( COMMA expression )? 
                                      | expression ( COMMA ( expression )? )* ( COMMA 
                                      ( clocking_event )? )? 
                                      ) RPAREN )? 
    """)
    assert r.body[2].eq_relaxed(c2)
    r.body[2] = Antlr4parser().from_str("""
        any_system_tf_identifier ( LPAREN (
                                     ( data_type )? list_of_arguments 
                                     ( COMMA clocking_event )? 
                                 ) RPAREN )? 
    """)
    
    c1 = Antlr4parser().from_str("""
        ps_or_hierarchical_identifier ( attribute_instance )* ( LPAREN list_of_arguments RPAREN )?
    """)
    assert r.body[1].eq_relaxed(c1), r.body[1]
    del r.body[1]

    
    

def left_recurse_remove(rules):
    """
    Removing Left Recursion from Context-Free Grammars
    https://www.microsoft.com/en-us/research/wp-content/uploads/2000/04/naacl2k-proc-rev.pdf

    http://web.science.mq.edu.au/~mjohnson/papers/johnson-left-corner.pdf

    :note: supports the '|',?,* in rules
    """
    # :note: higher priority = sooner in parse tree

    direct_left_recurse_rm(rules, 'block_event_expression')
    direct_left_recurse_rm(rules, 'event_expression')
    # direct_left_recurse_rm(rules, 'constant_expression')
    solve_left_recurse_and_op_precedence_for_constant_expression(rules)
    # method_call_root - only in method_call
    # method_call      - only in subroutine_call
    split_rule(rules, "primary",
               ["cast", "subroutine_call"],
               "primary_no_cast_no_call")

    inline_rule(rules, "method_call")
    fix_subroutine_call(rules)
    inline_rule(rules, "method_call_body")
    inline_rule(rules, "method_call_root")
    inline_rule(rules, "built_in_method_call")
    inline_rule(rules, "array_manipulation_call")
    inline_rule(rules, "tf_call")
    inline_rule(rules, "system_tf_call")
    optimise_subroutine_call(rules)

    split_rule(rules, "constant_primary",
               ["constant_cast", "subroutine_call"],
               "constant_primary_no_cast_no_call")

    # inline_rule(rules, "cast")
    # inline_rule(rules, "constant_cast")
    # iterate_everything_except_first(
    #   rules, "cast")
    # iterate_everything_except_first(
    #   rules, "constant_cast")
    # [TODO] check if really all combinations of cast/call are possible
    replace_symbol_in_rule(
        rules, "casting_type",
        "constant_primary",
        "constant_primary_no_cast_no_call")

    # solve expression - conditional_expression left recurse
    # copy cond_predicate

    inline_rule(rules, "inside_expression")

    inline_rule(rules, "module_path_conditional_expression")
    direct_left_recurse_rm(rules, 'module_path_expression')

    # inline_rule(rules, "inside_expression")
    inline_rule(rules, "expression_or_cond_pattern")
    inline_rule(rules, "cond_pattern")
    # inline_rule(rules, "conditional_expression")
    Antlr4GenericOptimizer().optimize([rule_by_name(rules, "cond_predicate")])

    solve_left_recurse_and_op_precedence_for_expression(rules)
    binary_operator = rule_by_name(rules, "binary_operator")
    rules.remove(binary_operator)

    direct_left_recurse_rm(rules, "sequence_expr")
    direct_left_recurse_rm(rules, "property_expr")
    
    return rules
