from itertools import islice
from utils.antlr4.query import Antlr4SyntCmp
from sortedcontainers.sorteddict import SortedDict
from utils.antlr4.grammar import Antlr4Rule, rule_by_name
from typing import List


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

