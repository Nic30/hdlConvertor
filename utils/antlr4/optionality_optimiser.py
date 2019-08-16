from utils.antlr4.grammar import Antlr4Sequence, Antlr4Option


def _option_reduce_option(o: Antlr4Option):
    """
    (a? b?)? -> a? b?
    (a?)? -> a?
    """
    assert isinstance(o, Antlr4Option)
    if isinstance(o.body, Antlr4Sequence):
        items = []
        for c in o.body:
            if isinstance(c, Antlr4Sequence):
                if len(c) != 1:
                    return o, False
                c = c[0]
    
            if not isinstance(c, Antlr4Option):
                return o, False
            items.append(c)
    
        return Antlr4Sequence([*items, ]), True
    elif isinstance(o.body, Antlr4Option):
        return o.body, True
    return o, False
