from utils.antlr4.grammar import Antlr4Sequence, Antlr4Option, iter_non_visuals
from utils.antlr4._utils import replace_item_by_sequence


def reduce_optionality(rules):
    """
    (a? b?)? -> a? b?
    (a?)? -> a?
    """

    def match_replace_fn(o):
        if isinstance(o, Antlr4Option):
            if isinstance(o.body, Antlr4Sequence):
                items = []
                for c in o.body:
                    if isinstance(c, Antlr4Sequence):
                        c = list(iter_non_visuals(c))
                        if len(c) != 1:
                            return
                        c = c[0]

                    if not isinstance(c, Antlr4Option):
                        return
                    items.append(c)

                return Antlr4Sequence([*items, ])
            elif isinstance(o.body, Antlr4Option):
                return o.body

    for r in rules:
        replace_item_by_sequence(r, match_replace_fn)

