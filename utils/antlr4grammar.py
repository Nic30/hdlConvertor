from typing import List, Optional


class iAntlr4GramElem():

    def walk(self, fn):
        fn(self)

    def __repr__(self):
        return self.toAntlr4()


class Antlr4Rule(iAntlr4GramElem):
    """
    Containers of ANTLR4 rule
    """

    def __init__(self, name, body: iAntlr4GramElem, is_fragment: bool=False,
                 lexer_mode=None,
                 lexer_actions=None):
        self.name = name
        assert isinstance(body, iAntlr4GramElem), body
        self.body = body
        self.lexer_mode = lexer_mode
        self.is_fragment = is_fragment
        if lexer_actions is None:
            lexer_actions = []
        self.lexer_actions = lexer_actions
        if lexer_mode or self.lexer_actions:
            assert self.is_lexer_rule()

    def is_lexer_rule(self):
        return self.is_fragment or self.name == self.name.upper()

    def walk(self, fn):
        fn(self)
        self.body.walk(fn)

    def toAntlr4(self, actual_lexer_node=None):
        body = self.body.toAntlr4()
        if body and not body[0].isspace():
            body = " " + body
        if actual_lexer_node != self.lexer_mode:
            lm = self.lexer_mode
            if lm is None:
                lm = "DEFAULT_MODE"
            mode = "\nmode %s;\n" % (lm)
        else:
            mode = ""

        if self.lexer_mode is not None:
            mode += Antlr4Indent.INDENT

        if self.lexer_actions:
            body += " -> %s" % (",".join(self.lexer_actions))

        if self.is_fragment:
            f = "%sfragment %s:%s;"
        else:
            f = "%s%s:%s;"
        return f % (mode, self.name, body)


class Antlr4LexerAction():

    @staticmethod
    def mode(name):
        return "mode(%s)" % name

    @staticmethod
    def type(name):
        return "type(%s)" % name

    @staticmethod
    def skip():
        return "skip"

    @staticmethod
    def popMode():
        return "popMode"

    @staticmethod
    def pushMode(name):
        return "pushMode(%s)" % name

    @staticmethod
    def channel(name):
        return "channel(%s)" % name


class Antlr4Indent(iAntlr4GramElem):
    INDENT = "    "

    def __init__(self, indent_cnt: int):
        self.indent_cnt = indent_cnt

    def __eq__(self, other):
        return isinstance(other, Antlr4Indent)

    def toAntlr4(self):
        return "".join(self.INDENT for _ in range(self.indent_cnt))


class Antlr4Newline(iAntlr4GramElem):

    def toAntlr4(self):
        return "\n"

    def __eq__(self, other):
        return isinstance(other, Antlr4Newline)

    def __ne__(self, other):
        return not (self == other)


class Antlr4Sequence(list, iAntlr4GramElem):

    def walk(self, fn):
        fn(self)
        for i in self:
            i.walk(fn)

    def __eq__(self, other):
        return isinstance(other, Antlr4Sequence) and list.__eq__(self, other)

    def toAntlr4(self):
        buff = []
        for i in self:
            if isinstance(i, Antlr4Selection):
                buff.append("( %s )" % i.toAntlr4())
            else:
                buff.append(i.toAntlr4())
        return " ".join(buff)


class Antlr4Iteration(iAntlr4GramElem):

    def __init__(self, body: iAntlr4GramElem, positive: bool=False):
        assert isinstance(body, iAntlr4GramElem)
        self.body = body
        self.positive = positive

    def __eq__(self, other):
        return (isinstance(other, Antlr4Iteration)
                and self.positive == other.positive
                and self.body == other.body)

    def walk(self, fn):
        fn(self)
        self.body.walk(fn)

    def toAntlr4(self):
        body = self.body.toAntlr4()
        if self.positive:
            return "( %s )+" % body
        else:
            return "( %s )*" % body


class Antlr4Option(iAntlr4GramElem):

    def __init__(self, body: iAntlr4GramElem):
        assert isinstance(body, iAntlr4GramElem)
        self.body = body

    def walk(self, fn):
        fn(self)
        self.body.walk(fn)

    def __eq__(self, other):
        return isinstance(other, Antlr4Option) and self.body == other.body

    def toAntlr4(self):
        return "( %s )?" % (self.body.toAntlr4())


class Antlr4Selection(list, iAntlr4GramElem):

    def walk(self, fn):
        fn(self)
        for i in self:
            i.walk(fn)

    def toAntlr4(self):
        items = [i.toAntlr4() for i in self]
        return " | ".join(items)


class Antlr4Symbol(iAntlr4GramElem):

    def __init__(self, symbol: str, is_terminal: bool, is_regex: bool=False):
        self.symbol = symbol
        self.is_terminal = is_terminal
        self.is_regex = is_regex

    def is_lexer_nonterminal(self):
        return not self.is_terminal and self.symbol == self.symbol.upper()

    def __eq__(self, other):
        return (isinstance(other, Antlr4Symbol)
                and self.symbol == other.symbol
                and self.is_terminal == other.is_terminal
                and self.is_regex == other.is_regex)

    def __hash__(self):
        return hash((self.symbol, self.is_terminal, self.is_regex))

    def _escaped(self):
        tr = str.maketrans({
                    "'":  "\\'",
                    "\n": "\\n",
                    "\r": "\\r",
                    "\t": "\\t",
                    "\\": "\\\\",
                    '\v': '\u000b',
                    '\f': '\\f',
                    '\a': '\u0007', # bell
                })
        return self.symbol.translate(tr)
    def toAntlr4(self):
        if self.is_terminal:
            if self.is_regex:
                return self.symbol
            else:
                return "'%s'" % self._escaped()
        else:
            return self.symbol


def generate_renamer(renames, set_to_non_terminal=False):

    def apply_rename(obj):
        if isinstance(obj, Antlr4Rule):
            n = renames.get(obj.name, None)
            if n is not None:
                obj.name = n
        elif isinstance(obj, Antlr4Symbol):
            n = renames.get(obj.symbol, None)
            if n is not None:
                obj.symbol = n
                if set_to_non_terminal:
                    obj.is_terminal = False

    return apply_rename


def get_used_non_terminals(rules: List[Antlr4Rule]):
    nts: Set[str] = set()

    def collect_non_terminals(obj):
        if isinstance(obj, Antlr4Symbol) and not obj.is_terminal:
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
            if isinstance(obj, Antlr4Newline):
                Cntr.nls += 1

        r.walk(count_nl)
        if Cntr.nls == 1:
            if isinstance(r.body, Antlr4Sequence):
                assert isinstance(r.body[-1], Antlr4Newline)
                r.body.pop()
            elif isinstance(r.body, Antlr4Selection):
                assert isinstance(r.body[-1][-1], Antlr4Newline)
                r.body[-1].pop()
            else:
                raise NotImplementedError(r.body)


def get_defined_non_terminals(rules: List[Antlr4Rule]):
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
        return Antlr4Option(self.parse_rule_block(body))

    def parse_iteration(self, body):
        return Antlr4Iteration(self.parse_rule_block(body))

    def parse_symbol(self, symbol_token):
        if symbol_token.startswith("<b>"):
            if not symbol_token.endswith("</b>"):
                raise AssertionError(symbol_token)
            symbol_token = symbol_token[len("<b>"):-len("</b>")]
            symbol_token = symbol_token.upper()
        is_t = self.is_terminal(symbol_token)
        return Antlr4Symbol(symbol_token, is_t)

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
                    objs = [Antlr4Sequence(objs), ]
                    is_selection = True
                # push new selection option
                objs.append(Antlr4Sequence())
                continue
            elif o == "[":
                _o = self.parse_option(block)
            elif o == "{":
                _o = self.parse_iteration(block)
            elif o == "]" or o == "}":
                break
            elif isinstance(o, (Antlr4Indent, Antlr4Newline)):
                _o = o
            else:
                _o = self.parse_symbol(o)

            if is_selection:
                objs[-1].append(_o)
            else:
                objs.append(_o)

        if is_selection:
            return Antlr4Selection(objs)
        else:
            return Antlr4Sequence(objs)

    def parse_rule_tokens(self, tokens) -> Antlr4Rule:
        tokens = iter(tokens)
        name = next(tokens)
        t = next(tokens)
        if t != "::=":
            raise AssertionError(t)
        body = self.parse_rule_block(tokens)
        return Antlr4Rule(name, body)

    def extract_indent(self, s):
        indent_cnt = (len(s) - len(s.lstrip())) // len(self.INDENT)
        if indent_cnt == 0:
            return None
        return Antlr4Indent(indent_cnt)

    def parse_rule(self, rule_buff):
        tokens = []
        for part in rule_buff:
            ind = self.extract_indent(part)
            if ind:
                tokens.append(ind)

            part = self.RE_GRAM_OP.sub(" \g<1> ", part)
            p = [_p for _p in part.split(" ") if _p]
            for _p in p:
                _p = _p.strip()
                if _p:
                    tokens.append(_p)
            if part.endswith("\n"):
                tokens.append(Antlr4Newline())
        assert tokens
        return self.parse_rule_tokens(tokens)

    def convert(self, lines):
        raise NotImplementedError("Implement in your convertor implementation")


def rule_by_name(rules: List[Antlr4Rule], name: str) -> Optional[Antlr4Rule]:
    for r in rules:
        if r.name == name:
            return r
