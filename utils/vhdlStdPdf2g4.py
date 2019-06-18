#!/usr/bin/env python

import pdfminer3
from pdfminer3.pdfparser import PDFParser
from pdfminer3.pdfdocument import PDFDocument
from pdfminer3.pdfpage import PDFPage
from pdfminer3.pdfinterp import PDFResourceManager
from pdfminer3.pdfinterp import PDFPageInterpreter
from pdfminer3.layout import LAParams
from pdfminer3.converter import PDFPageAggregator
from itertools import islice
import re
import sys
from pprint import pprint
from typing import List, Set
from enum import Enum

PAGE_OFFSET = 13  # VHDL 2008


def createPDFDoc(fpath):
    fp = open(fpath, 'rb')
    parser = PDFParser(fp)
    document = PDFDocument(parser, password='')
    # Check if the document allows text extraction. If not, abort.
    if not document.is_extractable:
        raise "Not extractable"
    else:
        return document


class VhdlSpecParser():
    FONT_TRANSLATION = {"HEFBHG+TimesNewRomanPS-ItalicMT": "it",
                        "HEFBAE+TimesNewRomanPS-BoldMT": "b",
                        "HEFBBF+TimesNewRomanPSMT": None,
                        None:None}
    FOOTER_STR = 'Copyright © 2009 IEEE. All rights reserved.'

    def __init__(self, ofile):
        rsrcmgr = PDFResourceManager()
        laparams = LAParams()
        self.device = PDFPageAggregator(rsrcmgr, laparams=laparams)
        self.interpreter = PDFPageInterpreter(rsrcmgr, self.device)
        self.last_font = None
        self.in_rule = False
        self.font_print_pending = False
        self.header_footer_skipping = False
        self.ofile = ofile

    def parse_page(self, page):
        self.interpreter.process_page(page)
        layout = self.device.get_result()
        self.parse_obj(layout._objs)

    def parse_obj(self, objs):
        font_translation = self.FONT_TRANSLATION

        for obj in objs:
            if isinstance(obj, pdfminer3.layout.LTTextBox):
                for o in obj._objs:
                    if isinstance(o, pdfminer3.layout.LTTextLine):
                        if self.header_footer_skipping:
                            text = o.get_text()
                            if text.startswith("Std 1076-"):
                                self.header_footer_skipping = False
                            continue

                        text = o.get_text()
                        if text.startswith(self.FOOTER_STR):
                            self.header_footer_skipping = True
                            continue

                        # print(text)
                        is_rule_header = "::=" in text
                        if is_rule_header or self.in_rule:
                            self.in_rule = True
                            if not is_rule_header:
                                if text and not text.startswith(" "):
                                    self.in_rule = False
                                    continue

                            if text.strip():
                                for c in  o._objs:
                                    if isinstance(c, pdfminer3.layout.LTChar) and self.last_font != c.fontname:
                                        # this character has different font need to propagate it to output
                                        self.font_print_pending = True

                                    if c.get_text().isspace() and font_translation[self.last_font] is not None:
                                        # print the font enclosing string directly after this word (ignore whitespaces behind)
                                        self.font_print_pending = True
                                        self.ofile.write("</%s>" % f)
                                        self.last_font = None

                                    if self.font_print_pending and not (c.get_text().isspace()):
                                        self.font_print_pending = False
                                        f = font_translation[self.last_font]
                                        if f:
                                            self.ofile.write("</%s>" % f)

                                        f = font_translation[c.fontname]
                                        if f:
                                            self.ofile.write("<%s>" % f)

                                        self.last_font = c.fontname
                                    self.ofile.write(c.get_text())
            # if it's a container, recurse
            elif isinstance(obj, pdfminer3.layout.LTFigure):
                parse_obj(obj._objs)
            else:
                pass


class _Antlr4GrammarElem():

    def walk(self, fn):
        fn(self)

    def __repr__(self):
        return self.toAntlr4()


class ANTLR4_rule(_Antlr4GrammarElem):
    """
    Containers of ANTLR4 rule
    """

    class VisualIndent(_Antlr4GrammarElem):

        def __init__(self, indent_cnt: int):
            self.indent_cnt = indent_cnt

        def toAntlr4(self):
            return "".join("    " for _ in range(self.indent_cnt))

    class VisualNewline(_Antlr4GrammarElem):

        def toAntlr4(self):
            return "\n"

        def __eq__(self, other):
            return isinstance(other, ANTLR4_rule.VisualNewline)

        def __ne__(self, other):
            return not (self == other)

    class Sequence(list, _Antlr4GrammarElem):

        def walk(self, fn):
            fn(self)
            for i in self:
                i.walk(fn)

        def __eq__(self, other):
            return isinstance(other, ANTLR4_rule.Sequence) and list.__eq__(self, other)

        def toAntlr4(self):
            return " ".join(i.toAntlr4() for i in self)

    class Iteration(_Antlr4GrammarElem):

        def __init__(self, body):
            self.body = body

        def walk(self, fn):
            fn(self)
            for i in self.body:
                i.walk(fn)

        def toAntlr4(self):
            body = " ".join([b.toAntlr4() for b in self.body])
            return "( %s )*" % body

    class Option(_Antlr4GrammarElem):

        def __init__(self, body: 'Sequence'):
            self.body = body

        def walk(self, fn):
            fn(self)
            for i in self.body:
                i.walk(fn)

        def __eq__(self, other):
            return isinstance(other, ANTLR4_rule.Option) and self.body == other.body

        def toAntlr4(self):
            body = " ".join([b.toAntlr4() for b in self.body])
            return "( %s )?" % body

    class Selection(list, _Antlr4GrammarElem):

        def walk(self, fn):
            fn(self)
            for i in self:
                i.walk(fn)

        def toAntlr4(self):
            items = [ i.toAntlr4() for i in self]
            return " | ".join(items)

    class Symbol(_Antlr4GrammarElem):

        def __init__(self, symbol:str, is_terminal: bool):
            self.symbol = symbol
            self.is_terminal = is_terminal

        def __eq__(self, other):
            return (isinstance(other, ANTLR4_rule.Symbol)
                    and self.symbol == other.symbol
                    and self.is_terminal == other.is_terminal)

        def __hash__(self):
            return hash((self.symbol, self.is_terminal))

        def toAntlr4(self):
            return self.symbol

    def walk(self, fn):
        fn(self)
        self.body.walk(fn)

    def __init__(self, name, body: list):
        self.name = name
        self.body = body

    def toAntlr4(self):
        body = self.body.toAntlr4()
        if body and not body[0].isspace():
            body = " " + body
        return "%s:%s;" % (self.name, body)


class VhdlRule2Antlr4Rule():
    # to remove prefix marked by <it>
    RE_TAILING_UNDERSCORE = re.compile("</it>_")
    # to add an extra space if there is not
    RE_GRAM_OP = re.compile("(\{|\}|\[|\]|\|)")

    ASSIGN        : '=='  ;
    LBRACKET      : '['   ;
    RBRACKET      : ']'   ;
    MINUS = "–"  # note it is not regular - char
    SPEC_SYMB = {";" : "SEMI",
                 "(" : "LPAREN",
                 ")" : "RPAREN",
                 "'" : "APOSTROPHE",
                 '"' : "DBLQUOTE",
                 "<<" : "SHIFT_LEFT",
                 ">>" : "SHIFT_RIGHT",
                 "@": "AT",
                 "#": "HASHTAG",
                 ",": "COMMA",
                 ".": "DOT",
                 "?": "QUESTIONMARK",
                 ":": "COLON",
                 "=": "EQ",
                 "/=": "NEQ",
                 "<": "LT",
                 ">" : "GT",
                 ">=": "GE",
                 "?=": "MATCH_EQ",
                 "?/=": "MATCH_NEQ",
                 "?<": "MATCH_LT",
                 "?<=": "MATCH_LE" ,
                 "?>": "MATCH_GT",
                 "?>=": "MATCH_GE" ,  # relational_operator
                 "+": "PLUS",
                 "-": "MINUS",
                 "&": "AMPERSAND",  # adding_operator
                 "|": "BAR",
                 "\\": "BACKSLASH",
                 "*": "MUL",
                 "/": "DIV",  # multiplying_operator
                 "**": "DOUBLESTAR",  # miscellaneous_operator
                 "<=": "CONASGN",  # concurrent_simple_signal_assignment
                 "\\": "BACKSLASH",  # extended_identifier
                 "`": "GRAVE_ACCENT",  # tool_directive
                 "^": "UP",  # relative_pathname
                 ":=": "VARASGN",  # simple_variable_assignment
                 "<>": "BOX",  # constrained_array_definition
                 "=>": "ARROW",  # association_element
                 "??": "COND_OP",  # condition_operator
                 }
    INDENT = "      "
    RE_IT_PREFIX = re.compile("<it>[a-zA-Z0-9_]+</it>_?")

    def __init__(self):
        self.rules = []

    @staticmethod
    def is_terminal(t):
        return t.isupper() or t[0] == "'"

    def parse_option(self, body):
        return ANTLR4_rule.Option(self.parse_rule_block(body))

    def parse_iteration(self, body):
        return ANTLR4_rule.Iteration(self.parse_rule_block(body))

    def parse_symbol(self, symbol_token):
        if symbol_token.startswith("<b>"):
            assert symbol_token.endswith("</b>")
            symbol_token = symbol_token[len("<b>"):-len("</b>")]
            symbol_token = symbol_token.upper()
        is_t = self.is_terminal(symbol_token)
        return ANTLR4_rule.Symbol(symbol_token, is_t)

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
                    objs = [ANTLR4_rule.Sequence(objs), ]
                    is_selection = True
                # push new selection option
                objs.append(ANTLR4_rule.Sequence())
                continue
            elif o == "[":
                _o = self.parse_option(block)
            elif o == "{":
                _o = self.parse_iteration(block)
            elif o == "]" or o == "}":
                break
            elif isinstance(o, (ANTLR4_rule.VisualIndent, ANTLR4_rule.VisualNewline)):
                _o = o
            else:
                _o = self.parse_symbol(o)

            if is_selection:
                objs[-1].append(_o)
            else:
                objs.append(_o)

        if is_selection:
            return ANTLR4_rule.Selection(objs)
        else:
            return ANTLR4_rule.Sequence(objs)

    def parse_rule_tokens(self, tokens) -> ANTLR4_rule:
        tokens = iter(tokens)
        name = next(tokens)
        assert next(tokens) == "::="
        body = self.parse_rule_block(tokens)
        return ANTLR4_rule(name, body)

    def extract_indent(self, s):
        indent_cnt = (len(s) - len(s.lstrip())) // len(self.INDENT)
        if indent_cnt == 0:
            return None
        return ANTLR4_rule.VisualIndent(indent_cnt)

    def parse_rule(self, rule_buff):
        tokens = []
        for part in rule_buff:
            ind = self.extract_indent(part)
            if ind:
                tokens.append(ind)

            part = self.RE_GRAM_OP.sub(" \g<1> ", part)
            part = self.RE_IT_PREFIX.sub("", part)
            p = [ _p for _p in part.split(" ") if _p]
            for _p in p:
                _p = _p.strip()
                if _p == self.MINUS:
                    _p = "-"
                if _p:
                    tokens.append(_p)
            if part.endswith("\n"):
                tokens.append(ANTLR4_rule.VisualNewline())
        assert tokens
        return self.parse_rule_tokens(tokens)

    def convert(self, lines):
        fix_pid = re.compile("package instantiation_declaration")
        fix_sn = re.compile("simple name")
        rule_buff = []
        for l in lines:
            l = fix_pid.sub("package_instantiation_declaration", l)
            l = fix_sn.sub("simple_name", l)

            if not l[0].isspace():
                if rule_buff:
                    r = self.parse_rule(rule_buff)
                    self.rules.append(r)
                rule_buff = [l, ]
            else:
                rule_buff.append(l)

        if rule_buff:
            r = self.parse_rule(rule_buff)
            self.rules.append(r)


def get_defined_non_terminals(rules: List[ANTLR4_rule]):
    nts: Set[str] = set()
    for r in rules:
        nts.add(r.name)
    return nts


def get_used_non_terminals(rules: List[ANTLR4_rule]):
    nts: Set[str] = set()

    def collect_non_terminals(obj):
        if isinstance(obj, ANTLR4_rule.Symbol) and not obj.is_terminal:
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
            if isinstance(obj, ANTLR4_rule.VisualNewline):
                Cntr.nls += 1

        r.walk(count_nl)
        if Cntr.nls == 1:
            if isinstance(r.body, ANTLR4_rule.Sequence):
                assert isinstance(r.body[-1], ANTLR4_rule.VisualNewline)
                r.body.pop()
            elif isinstance(r.body, ANTLR4_rule.Selection):
                assert isinstance(r.body[-1][-1], ANTLR4_rule.VisualNewline)
                r.body[-1].pop()
            else:
                raise NotImplementedError(r.body)

def left_recursion_remove(rules):
    # A → Aα / β
    # to
    # A → βA’
    # A’ → αA’ / ∈
    # is replaced manually in vhdl_base.g4
    replaced_rules = {
        "name",
        #"prefix",
        "selected_name",
        #"suffix",
        "indexed_name",
        "slice_name",
        #"attribute_name",
    }
    return [r for r in rules if r.name not in replaced_rules]


# {x} - zero or more times -> (x)*
# [x] - optional -> (x)?
# <HEFBHG+TimesNewRomanPS-ItalicMT>prefix<HEFBBF+TimesNewRomanPSMT>_name - rule equivalent to rule name
# <HEFBAE+TimesNewRomanPS-BoldMT>keyword_literal<HEFBBF+TimesNewRomanPSMT>
if __name__ == "__main__":
    # file_name = 'VHDL-2008.pdf'
    # document = createPDFDoc(file_name)
    # pages = PDFPage.create_pages(document)
    # vp = VhdlSpecParser(sys.stdout)
    # # if True:
    # for page in islice(pages, PAGE_OFFSET + 6, PAGE_OFFSET + 239 + 2):
    # # for page in islice(pages, PAGE_OFFSET + 23, PAGE_OFFSET + 25):
    #     # page = next(islice(pages, PAGE_OFFSET + 6, None))
    #    vp.parse_page(page)

    renames = { k: k.upper() for k in [
        "base_specifier", "lower_case_letter", "upper_case_letter",
        'special_character', 'other_special_character', 'digit',
        'format_effector', 'space_character', 'underline']}
    renames["mode"] = "signal_mode"
    renames["E"] = "E_SIGN"
    renames["NULL"] = "NULL_SYM"
    for k, v in VhdlRule2Antlr4Rule.SPEC_SYMB.items():
        renames[k] = v

    def apply_rename(obj):
        if isinstance(obj, ANTLR4_rule):
            n = renames.get(obj.name, None)
            if n is not None:
                obj.name = n
        elif isinstance(obj, ANTLR4_rule.Symbol):
            n = renames.get(obj.symbol , None)
            if n is not None:
                obj.symbol = n

    IGNORED = [
        ANTLR4_rule.Symbol(s, False)
        for s in [
            "Property_Declaration",
            "Sequence_Declaration",
            "Clock_Declaration",
            "PSL_Directive",
            "Verification_Unit",
    ]]
    with open("vhdl2008.g4_proto") as f:
        p = VhdlRule2Antlr4Rule()
        p.convert(f)
        rm_newline_from_simple_rules(p.rules)
        nts = get_used_non_terminals(p.rules)
        def_nts = get_defined_non_terminals(p.rules)

        keywords = set()

        def collect_keywords(obj):
            if isinstance(obj, ANTLR4_rule.Symbol):
                s = obj.symbol
                if (s.isupper() and s not in VhdlRule2Antlr4Rule.SPEC_SYMB.values()
                        and s not in renames.values()
                        and s not in ["B", "D", "E", "O", "X"]):
                    keywords.add(obj.symbol)

        p.rules = left_recursion_remove(p.rules)
        for r in p.rules:
            r.walk(apply_rename)
            r.walk(collect_keywords)
            s = r.body

            while True:
                if isinstance(s, (ANTLR4_rule.Selection, ANTLR4_rule.Sequence)):
                    _s = s[-1]
                    if isinstance(_s, ANTLR4_rule.Sequence):
                        all_to_remove = True
                        for s2 in _s:
                            if (s2 not in IGNORED
                                    and s2 != ANTLR4_rule.VisualNewline()
                                    and not isinstance(s2, ANTLR4_rule.VisualIndent)):
                                all_to_remove = False
                        if _s and all_to_remove:
                            s.pop()
                            continue
                break
            if r.name == "signature":
                # rm ()? as it is in ()? every where it is used
                a, b = r.body[0].body
                a = a.body
                b = b.body
                # ( ( type_mark ( COMMA type_mark )* )? ( RETURN type_mark )? )?
                r.body = ANTLR4_rule.Selection([
                    ANTLR4_rule.Sequence([a, ANTLR4_rule.VisualNewline(), ANTLR4_rule.VisualIndent(1)]),
                    ANTLR4_rule.Sequence([a, b, ANTLR4_rule.VisualNewline(), ANTLR4_rule.VisualIndent(1)]),
                    ANTLR4_rule.Sequence([b, ANTLR4_rule.VisualNewline()]),
                ])

    HEADER = """/*
 * Grammar extracted from the VHDL 1993, 2002, 2008, 2018 standard and then merged together
 * (the standard is selected by parser propery)
 */

grammar vhdl;
"""
    with open("vhdl.g4", "w") as f:
        f.write("\n\n")
        f.write(HEADER)
        for kw in keywords:
            r = ANTLR4_rule(kw, ANTLR4_rule.Sequence([
                    ANTLR4_rule.Symbol(k, True) for k in kw
                ]))
            f.write(r.toAntlr4())
            f.write("\n")

        for k, v in VhdlRule2Antlr4Rule.SPEC_SYMB.items():
            if k == "'":
                k = "'\\''"
            elif k == "\\":
                k = "'\\\\'"
            else:
                k = "'%s'" % k
            r = ANTLR4_rule(v, ANTLR4_rule.Symbol(k, True))
            f.write(r.toAntlr4())
            f.write("\n")

        with open("vhdl_base.g4") as b:
            f.write(b.read())
        for r in p.rules:
            f.write(r.toAntlr4())
            f.write("\n")
    # pprint(nts - def_nts)

