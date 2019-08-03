from antlr4grammar import Antlr4Rule, iAntlr4GramElem, Antlr4Selection, \
    Antlr4Sequence, Antlr4Indent, Antlr4Newline, Antlr4Symbol, \
    Antlr4Option
from typing import List
from antlr4_utils import iter_non_visuals, index_non_visual, len_without_visuals, \
    replace_item_by_sequence


def _optimise_selections(elm: iAntlr4GramElem):
    """
    Reduce selection options which differ only in single item
    to a sequence with selection of different items.

    Example:
    a:
        b c d
      | b e d;

    to a: b (c | e) d;

    :note: ignores visuals
    :note: similar sequences have to be directly after each other
        because if they were not the priority of choices would
        be changed
    """
    if isinstance(elm, Antlr4Sequence):
        modified = False
        for e in elm:
            modified = modified or _optimise_selections(e)
        return modified
    elif isinstance(elm, Antlr4Selection):
        # List[Tuple[index of different item,
        #            List[Tuple[index in choices, selection options to replace]]]]
        to_reduce = []
        # tuple (index in choices, value)
        similar_choices = []
        diff_in = None
        for c_i, choice in enumerate(elm):
            if not similar_choices:
                if isinstance(choice, Antlr4Sequence) and len_without_visuals(choice) > 1:
                    similar_choices.append((c_i, choice))
                continue
            else:
                _, prev = similar_choices[0]
                compatible = True
                if (isinstance(prev, Antlr4Sequence)
                        and isinstance(choice, Antlr4Sequence)
                        and len_without_visuals(prev) == len_without_visuals(choice)):
                    # check if differs in a single item
                    for i, (prev_item, current_item) in enumerate(
                            zip(iter_non_visuals(prev), iter_non_visuals(choice))):
                        if prev_item != current_item:
                            if diff_in == i or diff_in is None:
                                diff_in = i
                            else:
                                compatible = False
                                break
                    if compatible:
                        similar_choices.append((c_i, choice))
                else:
                    compatible = False

                if not compatible:
                    if len(similar_choices) > 1:
                        to_reduce.append((diff_in, similar_choices))
                    # reset search
                    if isinstance(choice, Antlr4Sequence) and len_without_visuals(choice) > 1:
                        similar_choices = [(c_i, choice)]
                    else:
                        similar_choices = []
                    diff_in = None

        if len(similar_choices) > 1:
            to_reduce.append((diff_in, similar_choices))

        offset = 0
        for diff_in, _choices in to_reduce:
            choices = [c[1] for c in _choices]
            start_i = _choices[0][0] + offset
            assert len(_choices) > 1
            try:
                assert elm[start_i] is choices[0]
            except AssertionError:
                raise
            diff_item_substitution = Antlr4Selection([
                index_non_visual(c, diff_in) for c in choices
                ])
            part_to_exclude = index_non_visual(choices[0], diff_in)
            new_choice = Antlr4Sequence([
                (e if e is not part_to_exclude else diff_item_substitution)
                for e in choices[0]
            ])
            elm[start_i] = new_choice
            del elm[start_i + 1: start_i + len(choices)]

            offset -= len(choices) - 1
        return len(to_reduce)
    return False


def char_options_to_regex(r: Antlr4Rule):
    """
    '0' | '1' -> [01]
    """

    def rm_single_item_sequences(o):
        if isinstance(o, Antlr4Sequence) and len(o) == 1:
            return o

    replace_item_by_sequence(r, rm_single_item_sequences)

    def match_replace_fn(o):
        if isinstance(o, Antlr4Selection):
            char_symb_to_replace = []
            for c in o:
                if isinstance(c, Antlr4Symbol) and c.is_terminal and len(c.symbol) == 1:
                    char_symb_to_replace.append(c)
            if len(char_symb_to_replace) > 1:
                # build an regex out of them
                # and replace them by the regex
                for c in char_symb_to_replace:
                    o.remove(c)

                re_str = "[%s]" % ("".join([c.symbol for c in char_symb_to_replace]))
                re = Antlr4Symbol(re_str, True, is_regex=True)
                if len(list(iter_non_visuals(o))):
                    o.append(re)
                else:
                    return Antlr4Sequence([re, ])

    replace_item_by_sequence(r, match_replace_fn)


def is_prefix_of_elem(prefix: iAntlr4GramElem, elem: iAntlr4GramElem):
    """
    Chekc if the prefix in prefix of the element

    :returns: tuple (is_prefix, suffix)
    """
    if not isinstance(prefix, Antlr4Sequence):
        prefix = Antlr4Sequence([prefix, ])
    if not isinstance(elem, Antlr4Sequence):
        elem = Antlr4Sequence([elem, ])

    pr_list = list(iter_non_visuals(prefix))
    el_list = list(iter_non_visuals(elem))
    if len(pr_list) > len(el_list):
        return (False, None)

    last_pr = None
    for el, pr in zip(el_list, pr_list):
        if not (el == pr):
            return (False, None)
        last_pr = pr

    return (True, elem[elem.index(last_pr) + 1:])


def extract_optional_suffix(r):
    """
    a | a b -> a b?
    """
    modified = False

    def match_replace_fn(o):
        if isinstance(o, Antlr4Selection):
            potential_prefix = None
            potential_prefix_i = None

            to_remove = []
            for i, c in enumerate(o):
                if potential_prefix is None:
                    potential_prefix = c
                    potential_prefix_i = i
                else:
                    # check if the potential_prefix is really a prefix of this rule
                    is_prefix, suffix = is_prefix_of_elem(potential_prefix, c)
                    if is_prefix:
                        # put suffix as a optional to a prefix
                        if list(iter_non_visuals(suffix)):
                            if not isinstance(potential_prefix, Antlr4Sequence):
                                assert o[potential_prefix_i] is potential_prefix
                                potential_prefix = Antlr4Sequence([potential_prefix, ])
                                o[potential_prefix_i] = potential_prefix

                            if len(suffix) == 1:
                                suffix = suffix[0]
                            else:
                                suffix = Antlr4Sequence(suffix)

                            potential_prefix.append(Antlr4Option(suffix))
                        to_remove.append(c)
                        potential_prefix = None
                        potential_prefix_i = None
                        modified = True
                    else:
                        potential_prefix = c
                        potential_prefix_i = i

            for c in to_remove:
                o.remove(c)

            if len(o) == 1:
                return Antlr4Sequence([o[0], ])

    replace_item_by_sequence(r, match_replace_fn)
    return modified


def reduce_selection_from_optional(rule: Antlr4Rule):
    """
    a? | b? -> (a | b)?
    """
    modified = False

    def match_replace_fn(o):
        if isinstance(o, Antlr4Selection):
            non_optional_items = []
            for c in o:
                if isinstance(c, Antlr4Sequence):
                    c = list(iter_non_visuals(c))
                    if len(c) != 1:
                        return
                    c = c[0]

                if not isinstance(c, Antlr4Option):
                    return
                non_optional_items.append(c.body)

            o.clear()
            o.extend(non_optional_items)
            modified = True
            return Antlr4Sequence([Antlr4Option(o), ])

    replace_item_by_sequence(rule, match_replace_fn)
    return modified


def optimise_selections(rules: List[Antlr4Rule]):
    for r in rules:
        modified = True
        while modified:
            modified = _optimise_selections(r.body)
            modified |= extract_optional_suffix(r)
            modified |= reduce_selection_from_optional(r)

        if r.is_lexer_rule():
            char_options_to_regex(r)
        # if modified:
        #     print(r.name)
    return rules

