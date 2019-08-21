
from copy import deepcopy
from itertools import islice

from utils.antlr4._utils import replace_item_by_sequence
from utils.antlr4.grammar import Antlr4Rule, Antlr4Selection, \
    Antlr4Sequence, Antlr4Symbol, Antlr4Option, Antlr4Iteration
from utils.antlr4.sequence_optimiser import _is_optional, \
    _sequence_expand_optionality


def char_options_to_regex(r: Antlr4Rule):
    """
    '0' | '1' -> [01]
    """

    def match_replace_fn(o):
        if isinstance(o, Antlr4Selection):
            char_symb_to_replace = []
            for orig_c in o:
                c = orig_c
                if isinstance(c, Antlr4Sequence):
                    if len(c) > 1:
                        continue
                    else:
                        c = c[0]
                if isinstance(c, Antlr4Symbol) and c.is_terminal and len(c.symbol) == 1:
                    char_symb_to_replace.append((orig_c, c))
            if len(char_symb_to_replace) > 1:
                # build an regex out of them
                # and replace them by the regex
                for c, _ in char_symb_to_replace:
                    o.remove(c)

                re_str = "[%s]" % ("".join([c._escaped() for _, c in char_symb_to_replace]))
                re = Antlr4Symbol(re_str, True, is_regex=True)
                if len(o):
                    o.append(re)
                else:
                    return Antlr4Sequence([re, ])

    replace_item_by_sequence(r, match_replace_fn)


def _selection_reduce_optional(o: Antlr4Selection):
    """
    a? | b? -> (a | b)?
    """
    assert isinstance(o, Antlr4Selection)
    non_optional_items = []
    for c in o:
        if isinstance(c, Antlr4Sequence):
            if len(c) != 1:
                return o, False
            c = c[0]

        if not isinstance(c, Antlr4Option):
            return o, False
        non_optional_items.append(c.body)

    o.clear()
    o.extend(non_optional_items)
    return Antlr4Sequence([Antlr4Option(o), ]), True


def _selection_empty_option_to_optional(sel: Antlr4Selection):
    """"
    a | | c -> ( a | c )?
    """
    eo = Antlr4Sequence([])
    new_opts = [o for o in sel if o != eo]
    if len(new_opts) != len(sel):
        if len(new_opts) == 1:
            new_sel = new_opts[0]
        else:
            new_sel = Antlr4Selection(new_opts)
        return Antlr4Option(new_sel), True
    else:
        return sel, False
    
    
def _selection_options_to_sequnces(sel: Antlr4Selection):
    """
    Convert options in selection to a Antlr4Sequence 
    """
    for i, o in enumerate(sel):
        if not isinstance(o, Antlr4Sequence):
            sel[i] = Antlr4Sequence([o, ])


def _selection_share_suffix(sel: Antlr4Selection):
    """
    a c | b c | x0 y | x1 y-> (a | b) c | (x0 | x1) y

    :note: this is only single step which extracts only one item
    """
    return _selection_share_common(sel, -1)


def _selection_share_prefix(sel: Antlr4Selection):
    """
    a b | a c | x y0 | x y1 -> a (b | c) | x (y0 | y1)

    :note: this is only single step which extracts only one item
    """
    return _selection_share_common(sel, 0)


def _selection_share_common(sel: Antlr4Selection, start_index):
    assert start_index == 0 or start_index == -1
    assert isinstance(sel, Antlr4Selection), sel.__class__
    # find options which starting with the same element
    with_item = { i: set([i, ]) for i in range(len(sel))}
    for i0, p_opt in enumerate(sel):
        for i1, opt in enumerate(islice(sel, i0 + 1, None)):
            if p_opt and opt and p_opt[start_index] == opt[start_index]:
                prefix_cls = with_item[i0]
                prefix_cls.update(with_item[i0 + i1 + 1])
                with_item[i0 + i1 + 1] = prefix_cls
    resolved = set()
    new_options = []
    changed = False
    for i, _prefix_eq_cls in sorted(with_item.items()):
        if i in resolved:
            continue
        if len(_prefix_eq_cls) == 1:
            # keep option as it is
            new_opt = sel[i]
        else:
            changed = True
            # extraction of shared prefix
            eq_cls = list(sorted(_prefix_eq_cls))
            extracted_item = sel[i][start_index]
            if start_index == 0:
                new_opt = Antlr4Sequence([extracted_item,
                    Antlr4Selection([
                        Antlr4Sequence(sel[i0][1:])
                        for i0 in eq_cls
                    ])
                ])
            else:
                assert start_index == -1
                new_opt = Antlr4Sequence([
                    Antlr4Selection([
                        Antlr4Sequence(sel[i0][:-1])
                        for i0 in eq_cls
                    ]),
                    extracted_item
                ])
            resolved.update(eq_cls)
        new_options.append(new_opt)
    if len(new_options) == 1:
        return new_options[0], changed
    else:
        sel.clear()
        sel.extend(new_options)
        return sel, changed


def _selection_only_unique(sel: Antlr4Selection):
    assert isinstance(sel, Antlr4Selection)
    new_opts = []
    for o in sel:
        if o in new_opts:
            continue
        else:
            new_opts.append(o)
    if len(new_opts) != len(sel):
        if len(new_opts) == 1:
            return new_opts[0], True
        else:
            return Antlr4Selection(new_opts), True
    return sel, False

        
def _selection_propagate_optionality(sel: Antlr4Selection):
    assert isinstance(sel, Antlr4Selection)
    non_optional_choices = []
    entirely_optional = False
    for c in sel:
        is_optional = True
        for o in c:
            if _is_optional(o):
                continue
            else:
                is_optional = False
                break

        if is_optional:
            entirely_optional = True
            nocs = _sequence_expand_optionality(c)
            # the eps is represented by ptionality on while selection later
            non_optional_choices.extend([n for n in nocs
                                         if not isinstance(o, (Antlr4Sequence, Antlr4Selection))
                                            or len(n) > 0])
        else:
            non_optional_choices.append(c)

    if entirely_optional:
        return Antlr4Option(Antlr4Selection(non_optional_choices)), True
    else:
        return sel, False
