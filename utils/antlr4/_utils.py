from itertools import islice

from utils.antlr4.grammar import iAntlr4GramElem, Antlr4Option, Antlr4Symbol, \
    Antlr4Iteration, Antlr4Sequence, Antlr4Selection, Antlr4Rule, rule_by_name
from typing import List, Tuple
from copy import deepcopy


def rm_option_on_rule_usage(rules, rule_name):
    """
    (rule_name)? -> rule_name
    """

    def match_replace_fn(o: iAntlr4GramElem):
        if isinstance(o, Antlr4Option):
            items = o.body
            if isinstance(items, Antlr4Sequence) and len(items) == 1:
                s = items[0]
            else:
                s = items

            if isinstance(s, Antlr4Symbol) and s.symbol == rule_name:
                    return Antlr4Sequence([s, ])

    for r in rules:
        replace_item_by_sequence(r.body, match_replace_fn)


def replace_item_by_sequence_in_sequence(arr, match_replace_fn, do_inline_fn):
    """
    :param match_replace_fn: the function which takes element as an input
        and optionaly returns the element which should replace this item
    :param do_inline_fn: the function which specifies if current replacement
        should just replace the element of if it should be inlined in to parent element
        (e.g. inlining a | b in  (a | b) | c  leads to  a | b | c)
    """
    i = 0
    while True:
        m = None
        # look for something to replace
        _i = 0
        for _i, e in enumerate(islice(arr, i, None)):
            m = match_replace_fn(e)
            if m is None:
                replace_item_by_sequence(e, match_replace_fn)
            elif not do_inline_fn(m):
                arr[i + _i] = m
                m = None
            else:
                break
        i += _i
        if m is None:
            # nothing to replce
            break
        else:
            # perform actual replacement
            replace_with_something = False
            for i2, e in enumerate(m):
                if i2 == 0:
                    replace_with_something = True
                    arr[i] = e
                else:
                    arr.insert(i + i2, e)
            i += len(m)
            if not replace_with_something:
                del arr[i]


def replace_item_by_sequence(elem, match_replace_fn):
    """
    If the match_replace_fn returns None no action is performed,
    if the match_replace_fn returns something iterable the original item is replaced
    by content of this collection
    """
    if isinstance(elem, Antlr4Symbol):
        # replacing in the parent
        pass
    elif isinstance(elem, (Antlr4Iteration, Antlr4Option)):
        m = match_replace_fn(elem.body)
        if m is None:
            replace_item_by_sequence(elem.body, match_replace_fn)
        else:
            assert isinstance(m, iAntlr4GramElem)
            elem.body = m
    elif isinstance(elem, Antlr4Sequence):

        def do_inline_fn(elem):
            return isinstance(elem, Antlr4Sequence)

        replace_item_by_sequence_in_sequence(elem, match_replace_fn, do_inline_fn)
    elif isinstance(elem, Antlr4Selection):

        def do_inline_fn(elem):
            return isinstance(elem, Antlr4Selection)

        replace_item_by_sequence_in_sequence(elem, match_replace_fn, do_inline_fn)
    elif isinstance(elem, Antlr4Rule):
        m = match_replace_fn(elem.body)
        if m is None:
            replace_item_by_sequence(elem.body, match_replace_fn)
        else:
            assert isinstance(m, iAntlr4GramElem)
            elem.body = m
    else:
        raise TypeError(elem.__class__)


def remove_simple_rule(name, p):
    r = rule_by_name(p.rules, name)
    assert r is not None, name
    body = r.body 
    assert len(body) == 1, r
    assert isinstance(body[0], Antlr4Symbol)
    inline_rule(p.rules, name)


def get_simple_rules(rules):
    for r in rules:
        body = r.body
        if len(body) == 1 and isinstance(body[0], Antlr4Symbol):
            yield r

def collect_simple_rules(rules: List[Antlr4Rule], symbol_name: str):
    for r in rules:
        if len(r.body) == 1:
            b = r.body[0]
            if isinstance(b, Antlr4Symbol) and b.symbol == symbol_name:
                yield r

def _extract_option_as_rule(r, rules, options_i: List[Tuple[int, iAntlr4GramElem]], new_rule_name):
    assert isinstance(r.body, Antlr4Selection)

    new_body = Antlr4Selection([])
    consumed = set()
    for i, ev in options_i:
        assert r.body[i].eq_relaxed(ev), (r.body[i], ev)
        new_body.append(r.body[i])
        consumed.add(i)

    body = [Antlr4Symbol(new_rule_name, False), ]
    for i, x in enumerate(r.body):
        if i not in consumed:
            body.append(x)

    if len(body) == 1:
        r.body = body[0]
    else:
        r.body = Antlr4Selection(body)

    if len(new_body) == 1:
        new_body = new_body[0]

    new_r = Antlr4Rule(new_rule_name, new_body)
    rules.insert(rules.index(r), new_r)
    return new_r

def extract_option_as_rule(rules, rule_name, options_i: List[Tuple[int, iAntlr4GramElem]], new_rule_name):
    r = rule_by_name(rules, rule_name)
    return _extract_option_as_rule(r, rules, options_i, new_rule_name)

def _replace_symbol_in_rule(rule, symbol_name, symbol_name_replace,
                           only_first=False):

    class FirstFound(Exception):
        pass

    def renamer(obj):
        if isinstance(obj, Antlr4Symbol) and obj.symbol == symbol_name:
            obj.symbol = symbol_name_replace
            if only_first:
                raise FirstFound()

    try:
        rule.walk(renamer)
    except FirstFound:
        pass


def replace_symbol_in_rule(rules, rule_name, symbol_name, symbol_name_replace,
                           only_first=False):
    rule = rule_by_name(rules, rule_name)
    _replace_symbol_in_rule(rule, symbol_name, symbol_name_replace,
                            only_first=only_first)
    

def inline_rule(rules, rule_name):
    rule = rule_by_name(rules, rule_name)
    _inline_rule(rules, rule)
    rules.remove(rule)


def _inline_rule(rules, rule):
    replacement = rule.body

    def match_replace_fn(o):
        if isinstance(o, Antlr4Symbol) and o.symbol == rule.name:
            return deepcopy(replacement)

    for r in rules:
        replace_item_by_sequence(r, match_replace_fn)

