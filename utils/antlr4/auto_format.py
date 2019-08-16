from utils.antlr4._utils import replace_item_by_sequence
from utils.antlr4.grammar import Antlr4Indent, Antlr4Newline, Antlr4Sequence, \
    iAntlr4GramElem, Antlr4Option, Antlr4Selection, Antlr4Iteration, \
    Antlr4Symbol, Antlr4Rule
from math import ceil


def remove_any_visuals(rules):

    def match_replace_fn(o):
        if isinstance(o, (Antlr4Indent, Antlr4Newline)):
            return Antlr4Sequence([])

    for r in rules:
        replace_item_by_sequence(r.body, match_replace_fn)


class Antlr4Formater():

    def __init__(self, line_len=100):
        self.line_len = line_len

    def _auto_format(self, e: iAntlr4GramElem, x, indent) -> int:
        if isinstance(e, Antlr4Selection):
            item_indent = ceil(x / len(Antlr4Indent.INDENT)) + 1
            x = item_indent * len(Antlr4Indent.INDENT)
            # item_indent = indent + 1
            # assert item_indent >= indent
            for ci, c in enumerate(e):
                if not isinstance(c, Antlr4Sequence):
                    c = Antlr4Sequence([c, ])
                    e[ci] = c
                self._auto_format(c, item_indent, indent)
                if ci != len(e):
                    c.extend([Antlr4Newline(), Antlr4Indent(item_indent)])
        elif isinstance(e, Antlr4Sequence):
            line_breaks = []
            for i, o in enumerate(e):
                x = self._auto_format(o, x, indent) + 1
                if x >= self.line_len:
                    line_breaks.append(i)
                    x = indent * len(Antlr4Indent.INDENT)
            offset = 0
            for i in line_breaks:
                e.insert(offset + i, Antlr4Newline())
                e.insert(offset + i + 1, Antlr4Indent(indent))
                offset += 2
        elif isinstance(e, (Antlr4Option, Antlr4Iteration)):
            return self._auto_format(e.body, x, indent) + 5
        elif isinstance(e, Antlr4Symbol):
            return x + len(e.symbol)
        elif isinstance(e, Antlr4Rule):
            if isinstance(e.body, Antlr4Symbol):
                return self._auto_format(e.body, len(e.name) + 2, 1) 
            else:
                if not isinstance(e.body, Antlr4Sequence):
                    e.body = Antlr4Sequence([e.body, ])
                x = self._auto_format(e.body, 0, 1)
                e.body.insert(0, Antlr4Newline())
        else:
            raise TypeError(repr(e.__class__))
        
        return x

    
def auto_format(rules):
    f = Antlr4Formater()
    for r in rules:
        f._auto_format(r, 0, 0)
        
