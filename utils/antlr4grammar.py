from typing import List


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

    def is_lexer_nonterminal(self):
        return not self.is_terminal and self.symbol == self.symbol.upper()

    def __eq__(self, other):
        return (isinstance(other, ANTLR4Symbol)
                and self.symbol == other.symbol
                and self.is_terminal == other.is_terminal)

    def __hash__(self):
        return hash((self.symbol, self.is_terminal))

    def toAntlr4(self):
        if self.is_terminal:
            return "'%s'" % self.symbol.translate(str.maketrans({"'":  "\'",
                                                                 "\n": "\\n",
                                                                 "\t": "\\t"
                                                                 }))
        else:
            return self.symbol


def generate_renamer(renames, set_to_non_terminal=False):

    def apply_rename(obj):
        if isinstance(obj, ANTLR4Rule):
            n = renames.get(obj.name, None)
            if n is not None:
                obj.name = n
        elif isinstance(obj, ANTLR4Symbol):
            n = renames.get(obj.symbol , None)
            if n is not None:
                obj.symbol = n
                if set_to_non_terminal:
                    obj.is_terminal = False

    return apply_rename


def get_used_non_terminals(rules: List[ANTLR4Rule]):
    nts: Set[str] = set()

    def collect_non_terminals(obj):
        if isinstance(obj, ANTLR4Symbol) and not obj.is_terminal:
            nts.add(obj.symbol)

    for r in rules:
        r.walk(collect_non_terminals)

    return nts


def rm_newline_from_simple_rules(rules):
    """
    Rule is simple if contains one newline at the end
    """
    for r in rules:

        class Cntr():
            nls = 0

        def count_nl(obj):
            if isinstance(obj, ANTLR4VisualNewline):
                Cntr.nls += 1

        r.walk(count_nl)
        if Cntr.nls == 1:
            if isinstance(r.body, ANTLR4Sequence):
                assert isinstance(r.body[-1], ANTLR4VisualNewline)
                r.body.pop()
            elif isinstance(r.body, ANTLR4Selection):
                assert isinstance(r.body[-1][-1], ANTLR4VisualNewline)
                r.body[-1].pop()
            else:
                raise NotImplementedError(r.body)


def get_defined_non_terminals(rules: List[ANTLR4Rule]):
    nts: Set[str] = set()
    for r in rules:
        nts.add(r.name)
    return nts


class BaseGrammarConvertor():
    def __init__(self):
        self.rules = []

    @staticmethod
    def is_terminal(t):
        return t.isupper() or t[0] == "'"

    def parse_option(self, body):
        return ANTLR4Option(self.parse_rule_block(body))

    def parse_iteration(self, body):
        return ANTLR4Iteration(self.parse_rule_block(body))

    def parse_symbol(self, symbol_token):
        if symbol_token.startswith("<b>"):
            if not symbol_token.endswith("</b>"):
                raise AssertionError(symbol_token)
            symbol_token = symbol_token[len("<b>"):-len("</b>")]
            symbol_token = symbol_token.upper()
        is_t = self.is_terminal(symbol_token)
        return ANTLR4Symbol(symbol_token, is_t)

    def parse_rule_block(self, block) -> list:
        objs = []
        is_selection = False
        while True:
            try:
                o = next(block)
            except StopIteration:
                break
            if o == "|":
                if not is_selection:
                    # convert all items in current sequence to option in selection
                    objs = [ANTLR4Sequence(objs), ]
                    is_selection = True
                # push new selection option
                objs.append(ANTLR4Sequence())
                continue
            elif o == "[":
                _o = self.parse_option(block)
            elif o == "{":
                _o = self.parse_iteration(block)
            elif o == "]" or o == "}":
                break
            elif isinstance(o, (ANTLR4VisualIndent, ANTLR4VisualNewline)):
                _o = o
            else:
                _o = self.parse_symbol(o)

            if is_selection:
                objs[-1].append(_o)
            else:
                objs.append(_o)

        if is_selection:
            return ANTLR4Selection(objs)
        else:
            return ANTLR4Sequence(objs)

    def parse_rule_tokens(self, tokens) -> ANTLR4Rule:
        tokens = iter(tokens)
        name = next(tokens)
        t = next(tokens)
        if t != "::=":
            raise AssertionError(t)
        body = self.parse_rule_block(tokens)
        return ANTLR4Rule(name, body)

    def extract_indent(self, s):
        indent_cnt = (len(s) - len(s.lstrip())) // len(self.INDENT)
        if indent_cnt == 0:
            return None
        return ANTLR4VisualIndent(indent_cnt)

    def parse_rule(self, rule_buff):
        tokens = []
        for part in rule_buff:
            ind = self.extract_indent(part)
            if ind:
                tokens.append(ind)

            part = self.RE_GRAM_OP.sub(" \g<1> ", part)
            p = [ _p for _p in part.split(" ") if _p]
            for _p in p:
                _p = _p.strip()
                if _p:
                    tokens.append(_p)
            if part.endswith("\n"):
                tokens.append(ANTLR4VisualNewline())
        assert tokens
        return self.parse_rule_tokens(tokens)

    def convert(self, lines):
        raise NotImplementedError("Implement in your convertor implementation")
