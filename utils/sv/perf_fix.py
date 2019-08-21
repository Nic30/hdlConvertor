from utils.antlr4.grammar import rule_by_name, Antlr4Symbol, Antlr4Option, \
    Antlr4Sequence, Antlr4Rule, Antlr4Iteration, Antlr4Selection
from utils.antlr4._utils import replace_item_by_sequence, rm_option_on_rule_usage, \
    inline_rule, _replace_symbol_in_rule
from utils.antlr4.simple_parser import Antlr4parser
from typing import List
from utils.antlr4.query import Antlr4Query, Antlr4SyntCmp, find_dependet_on
from sortedcontainers.sorteddict import SortedDict
from itertools import islice


def rm_ambiguity(rules):
    rule = rule_by_name(rules, "variable_decl_assignment")
    to_repl = Antlr4parser().from_str("( ASSIGN class_new )?")

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

    # fix optinality on datatypes

    r = rule_by_name(p.rules, "implicit_data_type")
    # : (signing)? (packed_dimension)*
    # ->
    # : signing (packed_dimension)*
    # | (packed_dimension)+
    # ;
    r.body = Antlr4parser().from_str("signing ( packed_dimension )* | ( packed_dimension )+")
    
    _inline_rules(p.rules, ["variable_port_header", "net_port_header", "interface_port_header"])
    # make data_type_or_implicit optional 
    for r in p.rules:
        to_optional = [
            "port",
            "function_data_type_or_implicit",
            "var_data_type",
            "property_formal_type",
            "let_formal_type",
            "net_port_type"]
        if r.name not in ["sequence_formal_type",
                          "let_formal_type", ]:
            to_optional.append("data_type_or_implicit")
        if r.name not in ["data_type_or_implicit", "function_data_type_or_implicit"]:
            to_optional.append("implicit_data_type")
        if r.name != "property_formal_type":
            to_optional.append("sequence_formal_type")

        def match_replace_fn(o):
            if isinstance(o, Antlr4Symbol) and o.symbol in to_optional:
                return Antlr4Option(o)

        replace_item_by_sequence(r, match_replace_fn)
        
        if r.name == "net_port_type":
            # net_port_type:
            #       ( net_type )? data_type_or_implicit 
            #       | identifier 
            #       | KW_INTERCONNECT implicit_data_type;
            r.body[1] = Antlr4parser().from_str("data_type_or_implicit")
            r.body[0] = Antlr4parser().from_str("net_type ( data_type_or_implicit )?")
        
    port = rule_by_name(p.rules, "port")
    #      ( port_expression )? 
    #  | DOT identifier LPAREN ( port_expression )? RPAREN;
    port.body[0] = Antlr4Symbol("port_expression", False)
    # var_data_type: data_type | KW_VAR data_type_or_implicit;
    # var_data_type = rule_by_name(p.rules, "var_data_type")
    # var_data_type.body = Antlr4parser().from_str("KW_VAR ( data_type_or_implicit )? | data_type_or_implicit")


def _optimize_ps_parameter_identifier(rules):
    ps_parameter_identifier = rule_by_name(rules, "ps_parameter_identifier")
    #  ( ( package_scope | class_scope )? | ( 
    #      identifier ( LSQUARE_BR constant_expression RSQUARE_BR )? DOT )* 
    #  ) identifier 
    ps_parameter_identifier.body = Antlr4parser().from_str("""
        package_or_class_scoped_id
        ( DOT identifier ( LSQUARE_BR constant_expression RSQUARE_BR )? )*
    """)


def _optimize_ps_type_identifier(rules):
    ps_type_identifier = rule_by_name(rules, "ps_parameter_identifier")
    # ps_type_identifier: ( KW_LOCAL DOUBLE_COLON | package_scope | class_scope )? identifier;
    ps_type_identifier.body = Antlr4parser().from_str("""
        ( KW_LOCAL DOUBLE_COLON )? package_or_class_scoped_id
    """)


def optimize_primary(rules):
    primary_no_cast_no_call = rule_by_name(rules, "primary_no_cast_no_call")

    def assert_eq(index, s):
        elm = Antlr4parser().from_str(s)
        assert (primary_no_cast_no_call.body[index].eq_relaxed(elm)
            ), primary_no_cast_no_call.body[index]

    assert_eq(5, "package_or_class_scoped_hier_id_with_const_select select")
    assert_eq(8, "let_expression")
    primary_no_cast_no_call.body[5] = Antlr4parser().from_str("""
        package_or_class_scoped_hier_id_with_const_select select ( LPAREN let_list_of_arguments RPAREN )?
    """)
    del primary_no_cast_no_call.body[8]

    constant_primary_no_cast_no_call = rule_by_name(rules, "constant_primary_no_cast_no_call")

    def assert_eq_c(index, s):
        elm = Antlr4parser().from_str(s)
        assert (constant_primary_no_cast_no_call.body[index].eq_relaxed(elm)
            ), constant_primary_no_cast_no_call.body[index]

    assert_eq_c(3, "ps_parameter_identifier constant_select")
    assert_eq_c(4, """identifier ( LSQUARE_BR constant_range_expression RSQUARE_BR 
              | constant_select 
              )?""")
    assert_eq_c(5, "package_or_class_scoped_id")
    assert_eq_c(7, "let_expression")
    constant_primary_no_cast_no_call.body[3] = Antlr4parser().from_str("""
        package_or_class_scoped_hier_id_with_const_select ( LPAREN let_list_of_arguments RPAREN )?
    """)
    offset = 0
    for i in [4, 5, 7]:
        del constant_primary_no_cast_no_call.body[offset + i]
        offset -= 1


def optimize_class_scope(rules):
    p = Antlr4parser()
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
                        del match[id(o)]
                        if (v is to_replace0
                             or v is to_replace1
                             or (isinstance(v, Antlr4Symbol) and v.symbol == "identifier")):
                            return Antlr4Symbol(package_or_class_scoped_id.name, False)
                        else:
                            return Antlr4Sequence([])

            replace_item_by_sequence(r, apply_to_replace0_and_1)
            for _m in m:
                # assert that all matching items were replaced
                assert not _m
        #    print(r.toAntlr4())
        #    print(m)
        # else:
        #     if "package_scope | class_scope" in r.toAntlr4() or "class_scope | package_scope" in r.toAntlr4():
        #         print("not found " + r.toAntlr4())
    
    # class_qualifier:
    #   ( KW_LOCAL DOUBLE_COLON )? ( implicit_class_handle DOT 
    #                            | class_scope 
    #                            )?;
    # class_scope:
    #     ps_identifier ( parameter_value_assignment )? 
    #     ( DOUBLE_COLON identifier 
    #       ( parameter_value_assignment )?
    #     )* DOUBLE_COLON;
    # implicit_class_handle:
    #     KW_THIS ( DOT KW_SUPER )? 
    #      | KW_SUPER 
    # ;
    # package_scope:
    #  ( KW_DOLAR_UNIT 
    #    | identifier 
    #  ) DOUBLE_COLON;
    # hierarchical_identifier: ( KW_DOLAR_ROOT DOT )? ( identifier constant_bit_select DOT )* identifier;
    to_replace2 = p.from_str("( class_qualifier | package_scope )? hierarchical_identifier")
    package_or_class_scoped_hier_id_with_const_select = Antlr4Rule("package_or_class_scoped_hier_id_with_const_select", p.from_str("""
        ( KW_LOCAL DOUBLE_COLON )?
        ( 
          KW_DOLAR_ROOT
          | implicit_class_handle
          | ( 
              ( 
                  KW_DOLAR_UNIT  
                | identifier ( parameter_value_assignment )? 
              )
              ( DOUBLE_COLON identifier ( parameter_value_assignment )? )*
           )
        )
        ( constant_bit_select )* ( DOT identifier ( constant_bit_select )* )*
    """))
    rules.append(package_or_class_scoped_hier_id_with_const_select)
    primary_no_cast_no_call = rule_by_name(rules, "primary_no_cast_no_call")
    m = Antlr4Query(to_replace2).match(primary_no_cast_no_call.body)

    def apply_to_replace2(o):
        for match in m:
            v = match.get(id(o), None)
            if v is not None:
                if (v is to_replace2
                     or (isinstance(v, Antlr4Symbol) and v.symbol == "hierarchical_identifier")):
                    return Antlr4Symbol(package_or_class_scoped_hier_id_with_const_select.name, False)
                else:
                    return Antlr4Sequence([])

    replace_item_by_sequence(primary_no_cast_no_call, apply_to_replace2)
    
    _optimize_ps_type_identifier(rules)
    _optimize_ps_parameter_identifier(rules)
    rules.remove(rule_by_name(rules, "class_qualifier"))


def move_iteration_up_in_parse_tree(rules, rule_name):
    r = rule_by_name(rules, rule_name)
    
    # remove ()* from the rule body
    if isinstance(r.body, Antlr4Sequence):
        assert len(r.body) == 1, r.body
        r.body = r.body[0]
    assert isinstance(r.body, Antlr4Iteration) and not r.body.positive
    r.body = r.body.body
    
    # wrap rule appearence in ()*
    r_symb = Antlr4Symbol(rule_name, False)

    def match_replace_fn(o):
        if o == r_symb:
            return Antlr4Iteration(o, positive=False)

    for r in rules:
        replace_item_by_sequence(r.body, match_replace_fn)


def simplify_select_rule(rules, rule_name):
    """
    ( ( KW0 a0 ( a1 )* )* KW0 a0 )? ( a1 )* ...
    ->
    ( KW0 a0 | a1 )* ...
    """
    r = rule_by_name(rules, rule_name)
    g0 = r.body[0]
    g1 = r.body[1]
    first_part = Antlr4Iteration(Antlr4Selection([Antlr4Sequence(g0.body[-2:]), g1.body]), positive=False)
    if len(r.body) > 2:
        if len(r.body) > 3:
            rest = r.body[2:]
        else:
            rest = [r.body[2], ]

        new_body = Antlr4Sequence([
            first_part,
            *rest
        ])
    else:
        new_body = first_part

    r.body = new_body

    
def optimize_select(rules):
    """
    bit_select: ( LSQUARE_BR expression RSQUARE_BR )*; // used only there
    select:
          ( ( DOT identifier bit_select )* DOT identifier )? bit_select
          ( LSQUARE_BR part_select_range RSQUARE_BR )?;
    nonrange_select:
          ( ( DOT identifier bit_select )* DOT identifier )? bit_select;
    constant_bit_select: ( LSQUARE_BR constant_expression RSQUARE_BR )*;
    constant_select:
          ( ( DOT identifier constant_bit_select )* DOT identifier )? constant_bit_select 
          ( LSQUARE_BR constant_part_select_range RSQUARE_BR )?;
    """
    move_iteration_up_in_parse_tree(rules, "bit_select")
    move_iteration_up_in_parse_tree(rules, "constant_bit_select")
    simplify_select_rule(rules, "select")
    simplify_select_rule(rules, "nonrange_select")
    simplify_select_rule(rules, "constant_select")
    

def replace_same_rules(rules, rules_to_replace: List[str], replacement:str):
    r = None
    for name in rules_to_replace:
        _r = rule_by_name(rules, name)
        if r is None:
            r = _r
        else:
            assert r.body == _r.body or r.body.toAntlr4() == _r.body.toAntlr4(), (r, _r)
        rules.remove(_r)
    
    for rule in rules:
        for symbol_name in rules_to_replace:
            _replace_symbol_in_rule(rule, symbol_name, replacement, False)


def replace_and_rename_same(rules: List[Antlr4Rule],
                       rules_to_replace: List[str],
                       name_of_new_rule:str):
    r = None
    for name in rules_to_replace:
        _r = rule_by_name(rules, name)
        if r is None:
            r = _r
        else:
            assert r.body == _r.body or r.body.toAntlr4() == _r.body.toAntlr4(), (r, _r)
            rules.remove(_r)

    for rule in rules:
        assert r.name != name_of_new_rule, name_of_new_rule 
    r.name = name_of_new_rule

    for rule in rules:
        for symbol_name in rules_to_replace:
            _replace_symbol_in_rule(rule, symbol_name, name_of_new_rule, False)


def inline_unique_variant_of_rules(rules):
    replace_same_rules(rules, [
        "list_of_genvar_identifiers",
        "list_of_udp_port_identifiers"
    ], "identifier_list")
    
    replace_same_rules(rules, ["delayed_data"], "delayed_reference")
    _inline_rules(rules, [
        "cross_item",
        "dynamic_array_variable_identifier",
    ])
    _inline_rules(rules, [
        "bind_target_scope",
    ])
    replace_same_rules(rules, ["function_statement_or_null"], "statement_or_null")
    replace_and_rename_same(rules, ["list_of_cross_items", "udp_port_list"], "identifier_list_2plus")
    replace_same_rules(rules, ["checker_generate_item"], "program_generate_item")
    replace_same_rules(rules, ["for_step_assignment"], "sequence_match_item")

    
def _inline_rules(rules, rule_names_to_inline):
    for rule_name in rule_names_to_inline:
        inline_rule(rules, rule_name)


def detect_duplicit_rules(_rules: List[Antlr4Rule]):
    """
    Detect the rules which are exactly same
    """
    rules = [r for r in _rules if not r.is_lexer_rule()]
    eq_classes = SortedDict()
    for r in rules:
        eq_classes[r.name] = set([r.name, ])

    nonrange_select = rule_by_name(rules, "nonrange_select")
    select = rule_by_name(rules, "select")
    assert not(nonrange_select.body == select.body)
    assert not(select.body == nonrange_select.body)

    for r0 in rules:
        for r1 in rules:
            if r0 is r1:
                continue
            g = eq_classes[r0.name]
            if r1.name not in g and r0.body == r1.body:
                g.update(eq_classes[r1.name])
                eq_classes[r1.name] = g

    print("duplicit rules")
    seen = set()
    for r_name, c in eq_classes.items():
        if len(c) > 1 and r_name not in seen:
            print("%s: {%s}" % (r_name, ", ".join(sorted(c))))
            seen.update(c)


def detect_syntacticaly_same_rules(rules):
    """
    Detect the rules which have same structure but may have different symbol names used
    """
    r_list = [r for r in rules if not r.is_lexer_rule()]
    groups = {r.name: set([r.name, ]) for r in r_list}
    for i, r0 in enumerate(r_list):
        for r1 in islice(r_list, i + 1, None):
            if Antlr4SyntCmp().eq(r0.body, r1.body, can_rename=lambda x: not x.is_lexer_nonterminal()):
                r0_cls = groups[r0.name]
                r1_cls = groups[r1.name]
                if r0_cls is not r1_cls:
                    r0_cls.update(r1_cls)
                    groups[r1.name] = r0_cls
                    r0_cls.add(r1.name)
    
    print("---- structuraly same rules---")
    seen = set([
        # ignored
        'rs_prod', 'specify_item'
        ])
    for k, same in sorted(groups.items(), key=lambda x: x[0]):
        if k not in seen:
            seen.update(same)
            if len(same) > 1:
                print(k, sorted(list(same)))

    # d = find_dependet_on(rules, "stream_concatenation")
    # print(sorted(list(d)))


def other_performance_fixes(rules):
    # concurrent_assertion_statement items
    concurrent_assertion_statement_options = [
        "assert_property_statement",
        "assume_property_statement",
        "cover_property_statement",
        "cover_sequence_statement",
        "restrict_property_statement",
     ]
    for rn in concurrent_assertion_statement_options:
        inline_rule(rules, rn)

    def starts_with_token(o):
        if isinstance(o, Antlr4Symbol):
            return o.is_lexer_nonterminal()
        elif isinstance(o, Antlr4Sequence):
            return starts_with_token(o[0])
        elif isinstance(o, Antlr4Selection):
            for c in o:
                if not starts_with_token(c):
                    return False
            assert len(o)
            return True
        elif isinstance(o, (Antlr4Iteration, Antlr4Option)):
            return False
        else:
            raise TypeError()

    def sort_simple_first(o):
        if isinstance(o, Antlr4Selection):
            o.sort(key=lambda x: int(not starts_with_token(x)))

    for r in rules:
        r.body.walk(sort_simple_first)

    optimize_primary(rules)
    # detect_duplicit_rules(rules)
    detect_syntacticaly_same_rules(rules)


def add_eof(rules):
    source_text = rule_by_name(rules, "source_text")
    source_text.body.append(Antlr4Symbol("EOF", False))
    
