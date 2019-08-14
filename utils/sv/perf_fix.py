from utils.antlr4.grammar import rule_by_name, Antlr4Symbol, Antlr4Option, \
    Antlr4Sequence, iAntlr4GramElem, iter_non_visuals, Antlr4Selection, \
    Antlr4Iteration, Antlr4Rule
from utils.antlr4._utils import replace_item_by_sequence, rm_option_on_rule_usage
from utils.antlr4.simple_parser import Antrl4parser
from copy import copy
from typing import Dict, List
from itertools import islice
from utils.antlr4.query import Antlr4Query


def rm_ambiguity(rules):
    rule = rule_by_name(rules, "variable_decl_assignment")
    to_repl = Antrl4parser().from_str("( ASSIGN class_new )?")

    def match_replace_fn(o):
        if o == to_repl:
            return o.body

    replace_item_by_sequence(rule, match_replace_fn)


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

                    
def optimize_class_scope(rules):
    p = Antrl4parser()
    to_replace0 = p.from_str("( package_scope | class_scope )? identifier")
    to_replace1 = p.from_str("( class_scope | package_scope )? identifier")
    package_or_class_scoped_id = Antlr4Rule("package_or_class_scoped_id", p.from_str(
        """( identifier ( parameter_value_assignment )? | KW_DOLAR_UNIT )
           ( DOUBLE_COLON identifier ( parameter_value_assignment )? )*"""))
    rules.append(package_or_class_scoped_id)

    def match_replace_fn_reduce_1_item_sequence(o):
        if isinstance(o, Antlr4Sequence) and len(o) == 1:
            return o[0]


    q0 = Antlr4Query(to_replace0)
    q1 = Antlr4Query(to_replace1)
    for r in rules:
        replace_item_by_sequence(r, match_replace_fn_reduce_1_item_sequence)
        # if r.name == "net_type_declaration":
        #     print(r.toAntlr4())
        m = q0.match(r.body)
        if not m:
            m = q1.match(r.body)
        if m:
            def apply_to_replace0_and_1(o):
                for match in m:
                    v = match.get(id(o), None)
                    if v is not None:
                        if (v is to_replace0
                             or v is to_replace0
                             or (isinstance(v, Antlr4Symbol) and v.symbol == "identifier")):
                            return Antlr4Symbol(package_or_class_scoped_id.name, False)
                        else:
                            return Antlr4Sequence([])
            replace_item_by_sequence(r, apply_to_replace0_and_1)
        
            print(r.toAntlr4())
            print(m)
        else:
            if "package_scope | class_scope" in r.toAntlr4() or "class_scope | package_scope" in r.toAntlr4():
                print("not found " + r.toAntlr4())
        
