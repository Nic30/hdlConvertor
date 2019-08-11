from antlr4.tree.Tree import TerminalNode
from typing import Union, List

from antlr4grammar import BaseGrammarConvertor, Antlr4Selection, Antlr4Sequence, \
    Antlr4Symbol, Antlr4Iteration, Antlr4Option, Antlr4Rule, Antlr4Indent, \
    Antlr4Newline
from proto_ast_loader import load_ast_file
from proto_grammar.proto_grammarParser import proto_grammarParser

Proto_ruleContext = proto_grammarParser.Proto_ruleContext
ElementContext = proto_grammarParser.ElementContext
Element_blockContext = proto_grammarParser.Element_blockContext
Element_selectionContext = proto_grammarParser.Element_selectionContext
Element_sequenceContext = proto_grammarParser.Element_sequenceContext
Element_iterationContext = proto_grammarParser.Element_iterationContext
Element_optionalContext = proto_grammarParser.Element_optionalContext
Element_textContext = proto_grammarParser.Element_textContext


class SvRule2Antlr4Rule(BaseGrammarConvertor):

    SPEC_SYMB = {
        ";": "SEMI",
        "(": "LPAREN",
        ")": "RPAREN",
        "[": "LSQUARE_BR",
        "]": "RSQUARE_BR",
        '{': "LBRACE",
        '}': "RBRACE",

        "'": "APOSTROPHE",
        '"': "DBLQUOTE",
        "<<": "SHIFT_LEFT",
        ">>": "SHIFT_RIGHT",
        "<<<": "ARITH_SHIFT_LEFT",
        ">>>": "ARITH_SHIFT_RIGHT",
        "$": "DOLAR",
        "_": "UNDERSCORE",
        "%": "MOD",
        "!": "NOT",
        "~": "NEG",
        "~&": "NAND",
        "~|": "NOR",
        "^": "XOR",
        "~^": "NXOR",
        "^~": "XORN",
        # "@": "AT",
        # "#": "HASHTAG",
        ",": "COMMA",
        ".": "DOT",
        "?": "QUESTIONMARK",
        ":": "COLON",
        "::": "DOUBLE_COLON",
        "==": "EQ",
        "!=": "NEQ",
        "===": "CASE_EQ",
        "!==": "CASE_NEQ",
        '==?': "WILDCARD_EQ",
        '!=?': "WILDCARD_NEQ",

        "=": "ASSIGN",
        "<": "LT",
        ">": "GT",
        ">=": "GE",
        "<=": "LE",
        "+=": "PLUS_EQ",
        "-=": "MINUS_EQ",
        "*=": "MUL_EQ",
        "/=": "DIV_EQ",
        "%=": "MOD_EQ",
        "&=": "AND_EQ",
        "|=": "OR_EQ",
        '^=': "XOR_EQ",
        "<<=": "SHIFT_LEFT_EQ",
        ">>=": "SHIFT_RIGHT_EQ",
        "<<<=": "ARITH_SHIFT_LEFT_EQ",
        ">>>=": "ARITH_SHIFT_RIGHT_EQ",

        "+": "PLUS",
        "-": "MINUS",
        "&": "AMPERSAND",
        "&&": "LOG_AND",
        "|": "BAR",
        "||": "LOG_OR",
        "\\": "BACKSLASH",
        "*": "MUL",
        "/": "DIV",
        "**": "DOUBLESTAR",
        "\\": "BACKSLASH",
        "<->": "BI_DIR_ARROW",
        "->": "ARROW",
        "->>": "DOUBLE_RIGHT_ARROW",
        "++": "INCR",
        "--": "DECR",

        ':=': "DIST_WEIGHT_ASSIGN",
        ':/': "DIST_WEIGHT_ASSIGN_DIV",

        '|->': "OVERLAPPING_IMPL",
        '|=>': "NONOVERLAPPING_IMPL",
        '=>': "IMPLIES",  # or path parralel
        '*>': "PATH_FULL",
        '#-#': "HASH_MINUS_HASH",
        '#=#': "HASH_EQ_HASH",
        "@": "AT",
        "@@": "DOUBLE_AT",
        "#": "HASH",
        "##": "DOUBLE_HASH",
        "&&&": "TRIPLE_AND",
    }
    INDENT = "      "

    def parse_element(self, ctx: ElementContext) -> Union[Antlr4Selection, Antlr4Sequence]:
        """
        element:
            element_sequence
            | element_selection
        ;
        """
        seq = ctx.element_sequence()
        if seq is not None:
            return self.parse_element_sequence(seq)
        else:
            sel = ctx.element_selection()
            return self.parse_element_selection(sel)

    def parse_element_block(self, ctx: Element_blockContext) -> \
            Union[Antlr4Symbol, Antlr4Iteration, Antlr4Option]:
        """
        element_block:
              element_text
            | element_iteration
            | element_optional
        ;
        """
        t = ctx.element_text()
        if t is not None:
            return self.parse_element_text(t)
        it = ctx.element_iteration()
        if it is not None:
            return self.parse_element_iteration(it)
        else:
            opt = ctx.element_optional()
            return self.parse_element_optional(opt)

    def parse_element_optional(self, ctx: Element_optionalContext) -> Antlr4Option:
        """
        element_optional: '[' element ']';
        """
        body = self.parse_element(ctx.element())
        return Antlr4Option(body)

    def parse_element_iteration(self, ctx: Element_iterationContext) -> Antlr4Iteration:
        """
        element_iteration: '{' element '}';
        """
        body = self.parse_element(ctx.element())
        return Antlr4Iteration(body)

    def parse_element_text(self, ctx: Element_textContext) -> Antlr4Symbol:
        """
        element_text: NAME | TERMINAL;
        """
        n = ctx.NAME()
        if n is not None:
            return Antlr4Symbol(n.getText(), False)
        else:
            n = ctx.TERMINAL().getText()
            n = n[len("<b>"):-len("</b>")]
            return Antlr4Symbol(n, True)

    def parse_element_sequence(self, ctx: Element_sequenceContext) -> Antlr4Sequence:
        """
        element_sequence: element_block (WS element_block)*;
        """
        body = []
        for c in ctx.children:
            if isinstance(c, Element_blockContext):
                res = self.parse_element_block(c)
                body.append(res)
            else:
                res = self.parse_ws(c)
                body.extend(res)
        return Antlr4Sequence(body)

    def parse_element_selection(self, ctx: Element_selectionContext) -> Antlr4Selection:
        """
        element_selection: element_sequence ('|' element_sequence)+;
        """
        body = []
        for c in ctx.element_sequence():
            body.append(self.parse_element_sequence(c))

        return Antlr4Selection(body)

    def parse_rule(self, rule: Proto_ruleContext):
        name = rule.NAME().getText()
        body = self.parse_element(rule.element())
        return Antlr4Rule(name, body)

    def parse_ws(self, n: TerminalNode) -> List[Union[Antlr4Indent, Antlr4Newline]]:
        objs = []
        actual_indent = 0
        for c in n.getText():
            if c == "\n":
                if actual_indent // len("    ") != 0:
                    i = Antlr4Indent(actual_indent // len("    "))
                    objs.append(i)
                    actual_indent = 0
                objs.append(Antlr4Newline())
            else:
                actual_indent += 1
        if actual_indent // len("    ") > 0:
            i = Antlr4Indent(actual_indent // len("    "))
            objs.append(i)

        return objs

    def convert(self, buff):
        ast = load_ast_file(buff)
        for rule in ast.children:
            if isinstance(rule, TerminalNode) and rule.getText() == '<EOF>':
                break
            r = self.parse_rule(rule)
            assert len(r.body) > 0
            self.rules.append(r)
