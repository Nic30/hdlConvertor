from copy import deepcopy

from antlr4_utils import inline_rule, replace_symbol_in_rule, iter_non_visuals, \
    extract_option_as_rule
from antlr4grammar import Antlr4Symbol, Antlr4Selection, rule_by_name, \
    Antlr4Newline, Antlr4Indent, Antlr4Sequence, Antlr4Iteration, Antlr4Rule
from left_recurse_remove import direct_left_recurse_rm, split_rule, \
    iterate_everything_except_first
from selection_optimiser import optimise_selections
from svRule2Antlr4Rule import SvRule2Antlr4Rule
from sv_precedence_fix import get_bin_op_precedence


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
    #   primary 
    #   | unary_operator ( attribute_instance )* primary 
    #   | inc_or_dec_expression 
    #   | LPAREN operator_assignment RPAREN 
    #   | expression binary_operator ( attribute_instance )* expression 
    #   | conditional_expression 
    #   | expression KW_INSIDE LBRACE open_range_list RBRACE 
    #   | tagged_union_expression;
    expression_0 = extract_option_as_rule(
            rules, "expression", [0, 1, 2, 3, 7], "expression_0")
    # expression:
    #   | expression binary_operator ( attribute_instance )* expression 
    #   | conditional_expression 
    #   | expression KW_INSIDE LBRACE open_range_list RBRACE;

    def handle_conditional_fn(bin_op_choices, current_expr_rule):
        # rm left recursion from cond_predicate/conditional_expression
        replace_symbol_in_rule(
           rules, "conditional_expression",
           "cond_predicate",
           "cond_expr_predicate", only_first=True)
        iterate_everything_except_first(
           rules, "conditional_expression")
        # create new cond_predicate (cond_expr_predicate) whout left recursion
        cond_predicate = rule_by_name(rules, "cond_predicate")
        cond_expr_predicate = deepcopy(cond_predicate)
        cond_expr_predicate.name = "cond_expr_predicate"
        rules.insert(rules.index(cond_predicate), cond_expr_predicate)
        replace_symbol_in_rule(
            rules, "cond_expr_predicate",
            "expression",
            current_expr_rule.name, only_first=True)

        bin_op_choices.extend([
            Antlr4Symbol(current_expr_rule.name, False),
            Antlr4Symbol("conditional_expression", False)
        ])

    def handle_inside_fn(bin_op_choices, current_expr_rule):
        bin_op_choices[-1].extend([Antlr4Newline(), Antlr4Indent(1)])
        # expression (KW_INSIDE LBRACE open_range_list RBRACE)*;
        bin_op_choice = Antlr4Sequence([
            Antlr4Symbol(current_expr_rule.name, False),
            Antlr4Iteration(Antlr4Sequence([
                Antlr4Symbol("KW_INSIDE", False),
                Antlr4Symbol("LBRACE", False),
                Antlr4Symbol("open_range_list", False),
                Antlr4Symbol("RBRACE", False),
            ]))
        ])
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
            "expression", handle_conditional_fn, handle_inside_fn)

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
    #       constant_primary 
    #       | unary_operator ( attribute_instance )* constant_primary 
    #       | constant_expression binary_operator ( attribute_instance )* constant_expression 
    #       | constant_expression QUESTIONMARK ( attribute_instance )* constant_expression COLON constant_expression;

    c_expression_0 = extract_option_as_rule(
            rules, "constant_expression", [0, 1], "constant_expression_0")
    # constant_expression_0:
    #       constant_primary 
    #       | unary_operator ( attribute_instance )* constant_primary 

    def handle_conditional_fn(bin_op_choices, current_expr_rule):
        bin_op_choices.extend([
            Antlr4Symbol(current_expr_rule.name, False),
            Antlr4Iteration(Antlr4Sequence([
                Antlr4Symbol("QUESTIONMARK", False),
                Antlr4Iteration(Antlr4Symbol("attribute_instance", False)),
                Antlr4Symbol("constant_expression", False),
                Antlr4Symbol("COLON", False),
                Antlr4Symbol("constant_expression", False),
            ]))
        ])

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
            "constant_expression", handle_conditional_fn, handle_inside_fn)


def extract_bin_ops(rules, current_expr_rule, ops_to_extrat, new_rule_name,
                    top_rule_name, handle_conditional_fn, handle_inside_fn):
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
            Antlr4Symbol(current_expr_rule.name, False),
            Antlr4Iteration(Antlr4Sequence([
                op,
                Antlr4Iteration(Antlr4Symbol("attribute_instance", False)),
                Antlr4Symbol(top_rule_name, False)
                ]))
        ])
        bin_op_choices.append(bin_op_choice)

    if "KW_INSIDE" in ops_to_extrat:
        handle_inside_fn(bin_op_choices, current_expr_rule)

    if "KW_DIST" in ops_to_extrat:
        # handled differently, only allowed on specified places
        pass

    if "QUESTIONMARK" in ops_to_extrat:
        handle_conditional_fn(bin_op_choices, current_expr_rule)

    # create a new rule which contains rule for extracted binary operators
    if len(bin_op_choices) > 1:
        new_body = Antlr4Selection(bin_op_choices)
    else:
        new_body = bin_op_choices[0]

    new_r = Antlr4Rule(new_rule_name, new_body)
    rules.insert(rules.index(current_expr_rule), new_r)

    return new_r


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
    # direct_left_recurse_rm(rules, 'constant_expression')
    solve_left_recurse_and_op_precedence_for_constant_expression(rules)
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
    #iterate_everything_except_first(
    #   rules, "cast")
    #iterate_everything_except_first(
    #   rules, "constant_cast")
    # [TODO] check if really all combinations of cast/call are possible
    replace_symbol_in_rule(
        rules, "casting_type",
        "constant_primary",
        "constant_primary_no_cast_no_call")

    # solve expression - conditional_expression left recurse
    # copy cond_predicate

    inline_rule(rules, "inside_expression")
    subroutine_call_rm_lr(rules)

    inline_rule(rules, "module_path_conditional_expression")
    direct_left_recurse_rm(rules, 'module_path_expression')

    # inline_rule(rules, "inside_expression")
    inline_rule(rules, "expression_or_cond_pattern")
    inline_rule(rules, "cond_pattern")
    # inline_rule(rules, "conditional_expression")
    rules = optimise_selections(rules)

    solve_left_recurse_and_op_precedence_for_expression(rules)
    binary_operator = rule_by_name(rules, "binary_operator")
    rules.remove(binary_operator)

    return rules
