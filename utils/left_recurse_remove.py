from sortedcontainers.sortedset import SortedSet
from typing import Set, Dict, List

from antlr4grammar import iAntlr4GramElem, Antlr4Sequence, Antlr4Symbol, \
    Antlr4Iteration, Antlr4Selection, Antlr4Option, Antlr4Indent, \
    Antlr4Newline, rule_by_name, Antlr4Rule
from selection_optimiser import iter_non_visuals
from copy import deepcopy
from antlr4_utils import replace_item_by_sequence


def transitive_closure(graph: Dict[object, Set[object]], reflexive=False):
    """
    Calculate the transitive closure of a directed graph,
    optionally the reflexive transitive closure.
    The algorithm is a slight modification of the "Marking Algorithm" of
    Ioannidis & Ramakrishnan (1998) "Efficient Transitive Closure Algorithms".
    :param graph: the initial graph, represented as a dictionary of sets
    :type graph: dict(set)
    :param reflexive: if set, also make the closure reflexive
    :type reflexive: bool
    :rtype: dict(set)
    """
    if reflexive:
        base_set = lambda k: set([k])
    else:
        base_set = lambda k: set()
    # The graph U_i in the article:
    agenda_graph = dict((k, graph[k].copy()) for k in graph)
    # The graph M_i in the article:
    closure_graph = dict((k, base_set(k)) for k in graph)
    for i in graph:
        agenda = agenda_graph[i]
        closure = closure_graph[i]
        while agenda:
            j = agenda.pop()
            closure.add(j)
            closure |= closure_graph.setdefault(j, base_set(j))
            agenda |= agenda_graph.get(j, base_set(j))
            agenda -= closure
    return closure_graph


def _direct_left_corner(elem: iAntlr4GramElem, dlc: SortedSet,
                        allow_eps_in_sel=False):
    """
    Collect all possible symbols which can appear on the beggining
    """
    if isinstance(elem, Antlr4Symbol):
        dlc.add(elem.symbol)
        return False
    elif isinstance(elem, Antlr4Iteration):
        _direct_left_corner(
            elem.body, dlc, allow_eps_in_sel=allow_eps_in_sel)
        return not elem.positive
    elif isinstance(elem, Antlr4Sequence):
        for e in elem:
            if not _direct_left_corner(
                    e, dlc, allow_eps_in_sel=allow_eps_in_sel):
                break
        return True
    elif isinstance(elem, Antlr4Selection):
        for e in elem:
            can_be_eps = _direct_left_corner(
                    e, dlc, allow_eps_in_sel=allow_eps_in_sel)
            if not allow_eps_in_sel:
                assert not can_be_eps, elem
    elif isinstance(elem, Antlr4Option):
        _direct_left_corner(
            elem.body, dlc, allow_eps_in_sel=allow_eps_in_sel)
        return True
    elif isinstance(elem, (Antlr4Indent, Antlr4Newline)):
        return True
    else:
        raise TypeError(elem)


def direct_left_corner(rule, allow_eps_in_sel=False):
    """
    direct left corner:
       The Symbol X is a direct left corner of a nonterminal A,
       if there is an A-production with X as the left-most symbol on the right-hand side.
       We define the left-corner relation to be the reflexive transitive closure
       of the direct-left-corner relation and we define theproper-left-corner relation
       to be the transitive closure ofthe direct-left-corner relation.

       (A nonterminal is left re-cursive if it is a proper left corner of itself.)

       (A nonterminal is directly left recursive if it is a direct left corner of itself
        and a nonterminal is indirectly left recursiveif it is left recursive,
        but not directly left recursive.)
       :note: | in rules is not taken in account
    """
    dlc = SortedSet()
    can_be_eps = _direct_left_corner(
        rule.body, dlc, allow_eps_in_sel=allow_eps_in_sel)
    if not allow_eps_in_sel:
        assert not can_be_eps, rule
    return dlc


def get_terminals(rules):
    terminals = SortedSet()

    def collect_terminals(obj: iAntlr4GramElem):
        if isinstance(obj, Antlr4Symbol) and obj.is_terminal:
            terminals.add(obj.symbol)

    for r in rules:
        r.walk(collect_terminals)

    return terminals


def proper_left_corners(rules):
    terminals = get_terminals(rules)
    dependencies = {}
    for r in rules:
        deps = set([x for x in direct_left_corner(r, allow_eps_in_sel=True)
                    if x not in terminals])
        dependencies[r.name] = deps

    dependencies = transitive_closure(dependencies)
    # proper left corners
    PLCs = {r.name: (r, dependencies[r.name])
            for r in rules}

    return PLCs


def left_recurse_print(rules):
    PLCs = proper_left_corners(rules)
    # tuple of sorted members of circle
    circles = set()
    for name, (_, plcs) in sorted(PLCs.items(), key=lambda x: len(x[1][1])):
        if name in plcs:
            k = tuple(sorted([n for n in plcs if n in PLCs and n in PLCs[n][1]]))
            circles.add(k)
            # print(name, len(plcs))

    for c in sorted(circles, key=len):
        print(c)


def iterate_everything_except_first(rules, rule_name):
    r = rule_by_name(rules, rule_name)
    if isinstance(r.body, Antlr4Sequence):
        _iterate_everything_except_first_and_replace_first(
            r.body, next(iter_non_visuals(r.body)))
    else:
        raise NotImplementedError()


def _iterate_everything_except_first_and_replace_first(seq, repl):
    rest = list(iter_non_visuals(seq))[1:]
    if len(rest) == 1:
        rest = rest[0]
    else:
        rest = Antlr4Sequence(rest)
    rest_iterated = Antlr4Iteration(rest)
    seq.clear()
    seq.append(repl)
    seq.append(rest_iterated)
    seq.append(Antlr4Newline())
    seq.append(Antlr4Indent(1))


def direct_left_recurse_rm(rules, rule_name):
    r = rule_by_name(rules, rule_name)

    if isinstance(r.body, Antlr4Selection):
        choices = r.body
    elif isinstance(r.body, Antlr4Sequence):
        choices = [r.body, ]
    else:
        raise NotImplementedError()

    # find choices which starts with this rule non terminal
    lr_choices = []
    for c in choices:
        if isinstance(c, Antlr4Sequence):
            first = next(iter_non_visuals(c))
            if isinstance(first, Antlr4Symbol) and first.symbol == rule_name:
                lr_choices.append(c)
        else:
            raise NotImplementedError()

    # remove choices which are causing left recursion
    assert len(lr_choices) >= 1, rule_name
    for lr_choice in lr_choices:
        choices.remove(lr_choice)

    if len(choices) == 0:
        raise NotImplementedError()
    elif len(choices) == 1:
        r.body = choices[0]

    # renaame this rule to rule_item
    r_base_name = r.name + "_item"
    for _r in rules:
        assert r.name != r_base_name, r_base_name
    r.name = r_base_name

    # create new rule which will implement removed choices and also expands to rule_item
    choices_new = Antlr4Selection([])
    for lr_choice in lr_choices:
        first = next(iter_non_visuals(lr_choice))
        assert isinstance(first, Antlr4Symbol) and first.symbol == rule_name
        repl = Antlr4Symbol(r_base_name, False)
        _iterate_everything_except_first_and_replace_first(lr_choice, repl)

        if not choices_new:
            lr_choice.insert(0, Antlr4Newline())
            lr_choice.insert(1, Antlr4Indent(1))
        choices_new.append(lr_choice)

    body_new = choices_new[0] if len(choices_new) == 1 else choices_new
    r_new = Antlr4Rule(rule_name, body_new)
    rules.insert(rules.index(r), r_new)


def inline_rule(rules, rule_name):
    rule = rule_by_name(rules, rule_name)
    replacement = rule.body

    def match_replace_fn(o):
        if isinstance(o, Antlr4Symbol) and o.symbol == rule_name:
            return deepcopy(replacement)

    for r in rules:
        replace_item_by_sequence(r, match_replace_fn)

    rules.remove(rule)


def split_rule(rules, rule_name, symbols_to_extract: List[str], subrule_name: str):
    """
    Let only options which are starting with symbols from symbols_to_extract.
    Put the rest to a subrule.
    """
    r = rule_by_name(rules, rule_name)

    assert isinstance(r.body, Antlr4Selection), r

    sub_options = Antlr4Selection([])
    for o in r.body:
        start_symbols = set()
        _direct_left_corner(o, start_symbols, allow_eps_in_sel=True)
        if not start_symbols.intersection(symbols_to_extract):
            sub_options.append(o)
    r.body = Antlr4Selection([o for o in r.body if not (o in sub_options)])
    r.body.insert(0, Antlr4Symbol(subrule_name, False))
    if len(r.body) == 1:
        r.body = r.body[0]

    assert len(sub_options) > 0
    if len(sub_options) == 1:
        sub_options = sub_options[0]
    else:
        sub_options = Antlr4Selection(sub_options)

    sub_r = Antlr4Rule(subrule_name, sub_options)
    rules.insert(rules.index(r), sub_r)
    return sub_r

