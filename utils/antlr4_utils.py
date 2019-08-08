from itertools import islice

from antlr4grammar import iAntlr4GramElem, Antlr4Option, Antlr4Symbol, \
    Antlr4Indent, Antlr4Newline, Antlr4Iteration, Antlr4Sequence, \
    Antlr4Selection, Antlr4Rule, rule_by_name
from typing import List
from copy import deepcopy


def rm_option_on_rule_usage(rules, rule_name):
    """
    (rule_name)? -> rule_name
    """

    def match_replace_fn(o: iAntlr4GramElem):
        if isinstance(o, Antlr4Option):
            items = list(iter_non_visuals(o.body))
            if len(items) == 1:
                s = items[0]
                if isinstance(s, Antlr4Symbol) and s.symbol == rule_name:
                    return Antlr4Sequence([s, ])

    for r in rules:
        replace_item_by_sequence(r.body, match_replace_fn)


def replace_item_by_sequence_in_sequence(arr, match_replace_fn):
    i = 0
    while True:
        m = None
        # look for something to replace
        for _i, e in enumerate(islice(arr, i, None)):
            m = match_replace_fn(e)
            if m is None:
                replace_item_by_sequence(e, match_replace_fn)
            elif not isinstance(m, Antlr4Sequence):
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

            if not replace_with_something:
                    del arr[i]


def replace_item_by_sequence(elem, match_replace_fn):
    """
    If the match_replace_fn returns None no action is performed,
    if the match_replace_fn returns something iterable the original item is replaced
    by content of this collection
    """
    if isinstance(elem, (Antlr4Symbol, Antlr4Indent, Antlr4Newline)):
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
        replace_item_by_sequence_in_sequence(elem, match_replace_fn)
    elif isinstance(elem, Antlr4Selection):
        for i, c in enumerate(elem):
            m = match_replace_fn(c)
            if m is None:
                replace_item_by_sequence(c, match_replace_fn)
            else:
                assert isinstance(m, iAntlr4GramElem)
                elem[i] = m
    elif isinstance(elem, Antlr4Rule):
        m = match_replace_fn(elem.body)
        if m is None:
            replace_item_by_sequence(elem.body, match_replace_fn)
        else:
            assert isinstance(m, iAntlr4GramElem)
            elem.body = m
    else:
        raise TypeError(elem)


def remove_simple_rule(name, p):
    r = rule_by_name(p.rules, name)
    assert r is not None, name
    assert len(r.body) == 1, r
    assert isinstance(r.body[0], Antlr4Symbol)
    inline_rule(p.rules, name)


def get_simple_rules(rules):
    for r in rules:
        body = list(iter_non_visuals(r.body))
        if len(body) == 1 and isinstance(body[0], Antlr4Symbol):
            yield r


def rm_redunt_whitespaces_on_end(rule: Antlr4Rule):
    s = rule.body
    while True:
        if isinstance(s, (Antlr4Selection, Antlr4Sequence)):
            _s = s[-1]
            if isinstance(_s, (Antlr4Newline, Antlr4Indent)):
                s.pop()
                continue
            elif isinstance(_s, (Antlr4Selection, Antlr4Sequence)):
                s = _s
                continue
        break


def collect_simple_rules(rules: List[Antlr4Rule], symbol_name: str):
    for r in rules:
        if len(r.body) == 1:
            b = r.body[0]
            if isinstance(b, Antlr4Symbol) and b.symbol == symbol_name:
                yield r


def iter_non_visuals(s: Antlr4Sequence):
    if isinstance(s, (Antlr4Indent, Antlr4Newline)):
        return
    if isinstance(s, iAntlr4GramElem):
        if not isinstance(s, Antlr4Sequence):
            yield s
            return

    for e in s:
        if not isinstance(e, (Antlr4Indent, Antlr4Newline)):
            yield e


def index_non_visual(s: Antlr4Selection, index: int):
    for e in iter_non_visuals(s):
        if index == 0:
            return e
        else:
            index -= 1

    raise IndexError()


def len_without_visuals(s: Antlr4Sequence):
    i = 0
    for e in s:
        if not isinstance(e, (Antlr4Indent, Antlr4Newline)):
            i += 1
    return i


def extract_option_as_rule(rules, rule_name, option_i, new_rule_name):
    r = rule_by_name(rules, rule_name)
    assert isinstance(r.body, Antlr4Selection)
    new_r = Antlr4Rule(new_rule_name, r.body[option_i])
    r.body[option_i] = Antlr4Sequence([
        Antlr4Symbol(new_rule_name, False),
        Antlr4Newline(),
        Antlr4Indent(1)
    ])
    rules.insert(rules.index(r), new_r)
    return new_r


def replace_symbol_in_rule(rules, rule_name, symbol_name, symbol_name_replace,
                           only_first=False):
    r = rule_by_name(rules, rule_name)

    class FirstFound(Exception):
        pass

    def renamer(obj):
        if isinstance(obj, Antlr4Symbol) and obj.symbol == symbol_name:
            obj.symbol = symbol_name_replace
            if only_first:
                raise FirstFound()

    try:
        r.walk(renamer)
    except FirstFound:
        pass

def inline_rule(rules, rule_name):
    rule = rule_by_name(rules, rule_name)
    replacement = rule.body

    def match_replace_fn(o):
        if isinstance(o, Antlr4Symbol) and o.symbol == rule_name:
            return deepcopy(replacement)

    for r in rules:
        replace_item_by_sequence(r, match_replace_fn)

    rules.remove(rule)
