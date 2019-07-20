#!/usr/bin/env python

from typing import List, Set, Union

from antlr4grammar import ANTLR4Rule, ANTLR4Symbol, ANTLR4Sequence, \
    ANTLR4VisualNewline, ANTLR4Selection, ANTLR4VisualIndent, ANTLR4Option, \
    ANTLR4Iteration, generate_renamer, rm_newline_from_simple_rules, \
    get_used_non_terminals, get_defined_non_terminals, BaseGrammarConvertor, \
    _Antlr4GrammarElem
from proto_ast_loader import load_ast_file
from proto_grammar.proto_grammarParser import proto_grammarParser
from antlr4.tree.Tree import TerminalNode
from pprint import pprint
from svStd_pdf_parsing import parse_sv_pdf

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
        ";" : "SEMI",
        "(" : "LPAREN",
        ")" : "RPAREN",
        "[": "LSQUARE_BR",
        "]": "RSQUARE_BR",
        '{': "LBRACE",
        '}': "RBRACE",

        "'" : "APOSTROPHE",
        '"' : "DBLQUOTE",
        "<<" : "SHIFT_LEFT",
        ">>" : "SHIFT_RIGHT",
        "<<<" : "ARITH_SHIFT_LEFT",
        ">>>" : "ARITH_SHIFT_RIGHT",
        "$": "DOLAR",
        "+:": "PLUS_COLON",
        "-:": "MINUS_COLON",
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
        '==?':"WILDCARD_EQ",
        '!=?':"WILDCARD_NEQ",

        "=": "ASSIGN",
        "<": "LT",
        ">" : "GT",
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
        "<->": "DOUBLE_ARROW",
        "->": "ARROW",
        "++": "INCR",
        "--": "DECR",

        ':=': "DIST_WEIGHT_ASSIGN",
        ':/': "DIST_WEIGHT_ASSIGN_DIV",

        '|->': "OVERLAPPING_IMPL",
        '|=>': "NONOVERLAPPING_IMPL",
        '#-#': "HASH_MINUS_HASH",
        '#=#': "HASH_EQ_HASH",
        "@": "AT",
        "@@": "DOUBLE_AT",
        "#": "HASH",
        "##": "DOUBLE_HASH",
        "&&&": "TRIPLE_END",
    }
    INDENT = "      "

    def parse_element(self, ctx: ElementContext) -> Union[ANTLR4Selection, ANTLR4Sequence]:
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
            Union[ANTLR4Symbol, ANTLR4Iteration, ANTLR4Option]:
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

    def parse_element_optional(self, ctx: Element_optionalContext) -> ANTLR4Option:
        """
        element_optional: '[' element ']';
        """
        body = self.parse_element(ctx.element())
        return ANTLR4Option(body)

    def parse_element_iteration(self, ctx: Element_iterationContext) -> ANTLR4Iteration:
        """
        element_iteration: '{' element '}';
        """
        body = self.parse_element(ctx.element())
        return ANTLR4Iteration(body)

    def parse_element_text(self, ctx: Element_textContext) -> ANTLR4Symbol:
        """
        element_text: NAME | TERMINAL;
        """
        n = ctx.NAME()
        if n is not None:
            return ANTLR4Symbol(n.getText(), False)
        else:
            n = ctx.TERMINAL().getText()
            n = n[len("<b>"):-len("</b>")]
            return ANTLR4Symbol(n, True)

    def parse_element_sequence(self, ctx: Element_sequenceContext) -> ANTLR4Sequence:
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
        return ANTLR4Sequence(body)

    def parse_element_selection(self, ctx: Element_selectionContext) -> ANTLR4Selection:
        """
        element_selection: element_sequence ('|' element_sequence)+;
        """
        body = []
        for c in ctx.element_sequence():
            body.append(self.parse_element_sequence(c))

        return ANTLR4Selection(body)

    def parse_rule(self, rule: Proto_ruleContext):
        name = rule.NAME().getText()
        body = self.parse_element(rule.element())
        return ANTLR4Rule(name, body)

    def parse_ws(self, n: TerminalNode) -> List[Union[ANTLR4VisualIndent, ANTLR4VisualNewline]]:
        objs = []
        actual_indent = 0
        for c in n.getText():
            if c == "\n":
                if actual_indent // len("    ") != 0:
                    i = ANTLR4VisualIndent(actual_indent // len("    "))
                    objs.append(i)
                    actual_indent = 0
                objs.append(ANTLR4VisualNewline())
            else:
                actual_indent += 1
        if actual_indent // len("    ") > 0:
            i = ANTLR4VisualIndent(actual_indent // len("    "))
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


def rm_redunt_whitespaces_on_end(rule: ANTLR4Rule):
    s = rule.body
    while True:
        if isinstance(s, (ANTLR4Selection, ANTLR4Sequence)):
            _s = s[-1]
            if isinstance(_s, (ANTLR4VisualNewline, ANTLR4VisualIndent)):
                s.pop()
                continue
            elif isinstance(_s, (ANTLR4Selection, ANTLR4Sequence)):
                s = _s
                continue
        break


def collect_simple_rules(rules: List[ANTLR4Rule], symbol_name: str):
    for r in rules:
        if len(r.body) == 1:
            b = r.body[0]
            if isinstance(b, ANTLR4Symbol) and b.symbol == symbol_name:
                yield r


def proto_grammar_to_g4():
    renames = {}
    # renames["E"] = "E_SIGN"
    # renames["NULL"] = "NULL_SYM"
    for k, v in SvRule2Antlr4Rule.SPEC_SYMB.items():
        renames[k] = v

    p = SvRule2Antlr4Rule()
    with open("sv2017.g4_proto") as f:
        p.convert(f)
    # rm_newline_from_simple_rules(p.rules)
    # nts = get_used_non_terminals(p.rules)
    # def_nts = get_defined_non_terminals(p.rules)

    to_remove = {
       "comment",
       "one_line_comment",
       "block_comment",
       "comment_text",
    }
    # overspecified
    # finish_number 0 - 2
    # scalar_constant 1b number
    # init_val 1b value
    # edge_descriptor 2 tristate digits
    # dpi_spec_string  two concrete strings

    to_lexer = [
        "c_identifier",
        "unsigned_number",
        "simple_identifier",
        "system_tf_identifier",
        #"real_number",
        "unsigned_number",
        "string_literal",
        "binary_number",
        "octal_number",
        "hex_number",
        "octal_number",
        "hex_number",
        #"decimal_number",
        "fixed_point_number",
        "escaped_identifier",
    ]
    for tl in to_lexer:
        renames[tl] = tl.upper()

    # to add
    # Any_ASCII_Characters
    # space, tab, newline, eof
    # any_printable_ASCII_character_except_white_space

    fragments = {
        "binary_value",
        "octal_value",
        "hex_value",
        "decimal_base",
        "binary_base",
        "octal_base",
        "hex_base",
        "non_zero_unsigned_number",
        "size",
        "sign",
        "output_symbol",
        "level_symbol",
        "edge_symbol",
        "non_zero_decimal_digit",
        "decimal_digit",
        "binary_digit",
        "octal_digit",
        "hex_digit",
        "x_digit",
        "z_digit",
        "unbased_unsized_literal",
        "exp",
        'white_space',
        'zero_or_one',
        'z_or_x',
    }
    for fr in fragments:
        for r in p.rules:
            if r.name in fragments:
                r.is_fragment = True
        renames[fr] = fr.upper()

    for r in p.rules:
        rm_redunt_whitespaces_on_end(r)

    identifier_rule_equivalents = {
        r.name for r in collect_simple_rules(p.rules, "identifier")
    }
    hierarchical_identifier_rule_equivalents = {
        r.name for r in collect_simple_rules(p.rules, "hierarchical_identifier")
    }

    to_remove.update(identifier_rule_equivalents)
    to_remove.update(hierarchical_identifier_rule_equivalents)
    p.rules = [r for r in p.rules if r.name not in to_remove ]

    for idname in identifier_rule_equivalents:
        renames[idname] = "identifier"

    for idname in hierarchical_identifier_rule_equivalents:
        renames[idname] = "hierarchical_identifier"

    apply_rename = generate_renamer(renames, True)
    for r in p.rules:
        r.walk(apply_rename)

    # because C_IDENTIFIER is just normal identifier without $ and can match identifiers
    for r in p.rules:
        if r.name == "identifier":
            r.body.insert(0, ANTLR4Symbol("C_IDENTIFIER", False))

    p.rules.sort(key=lambda x: (x.name == x.name.upper(), x.is_fragment))

    with open("sv2017.g4", "w") as f:
        f.write("grammar sv2017;\n\n")
        for r in p.rules:
            #print(r)
            f.write(r.toAntlr4())
            f.write("\n")


if __name__ == "__main__":
    parse_sv_pdf()
    proto_grammar_to_g4()
