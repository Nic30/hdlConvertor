

class _Antlr4GrammarElem():

    def walk(self, fn):
        fn(self)

    def __repr__(self):
        return self.toAntlr4()


class ANTLR4Rule(_Antlr4GrammarElem):
    """
    Containers of ANTLR4 rule
    """

    def walk(self, fn):
        fn(self)
        self.body.walk(fn)

    def __init__(self, name, body: list):
        self.name = name
        self.body = body
        self.is_fragment = False

    def toAntlr4(self):
        body = self.body.toAntlr4()
        if body and not body[0].isspace():
            body = " " + body

        if self.is_fragment:
            f = "fragment %s:%s;"
        else:
            f = "%s:%s;"
        return f % (self.name, body)


class ANTLR4VisualIndent(_Antlr4GrammarElem):

    def __init__(self, indent_cnt: int):
        self.indent_cnt = indent_cnt

    def toAntlr4(self):
        return "".join("    " for _ in range(self.indent_cnt))


class ANTLR4VisualNewline(_Antlr4GrammarElem):

    def toAntlr4(self):
        return "\n"

    def __eq__(self, other):
        return isinstance(other, ANTLR4VisualNewline)

    def __ne__(self, other):
        return not (self == other)


class ANTLR4Sequence(list, _Antlr4GrammarElem):

    def walk(self, fn):
        fn(self)
        for i in self:
            i.walk(fn)

    def __eq__(self, other):
        return isinstance(other, ANTLR4Sequence) and list.__eq__(self, other)

    def toAntlr4(self):
        return " ".join(i.toAntlr4() for i in self)


class ANTLR4Iteration(_Antlr4GrammarElem):

    def __init__(self, body):
        self.body = body

    def walk(self, fn):
        fn(self)
        for i in self.body:
            i.walk(fn)

    def toAntlr4(self):
        body = " ".join([b.toAntlr4() for b in self.body])
        return "( %s )*" % body


class ANTLR4Option(_Antlr4GrammarElem):

    def __init__(self, body: 'Sequence'):
        self.body = body

    def walk(self, fn):
        fn(self)
        for i in self.body:
            i.walk(fn)

    def __eq__(self, other):
        return isinstance(other, ANTLR4Option) and self.body == other.body

    def toAntlr4(self):
        body = " ".join([b.toAntlr4() for b in self.body])
        return "( %s )?" % body


class ANTLR4Selection(list, _Antlr4GrammarElem):

    def walk(self, fn):
        fn(self)
        for i in self:
            i.walk(fn)

    def toAntlr4(self):
        items = [ i.toAntlr4() for i in self]
        return " | ".join(items)


class ANTLR4Symbol(_Antlr4GrammarElem):

    def __init__(self, symbol:str, is_terminal: bool):
        self.symbol = symbol
        self.is_terminal = is_terminal

    def __eq__(self, other):
        return (isinstance(other, ANTLR4Symbol)
                and self.symbol == other.symbol
                and self.is_terminal == other.is_terminal)

    def __hash__(self):
        return hash((self.symbol, self.is_terminal))

    def toAntlr4(self):
        return self.symbol
