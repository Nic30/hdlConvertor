#!/usr/bin/env python

from itertools import islice
import pdfminer
from pdfminer.converter import PDFPageAggregator
from pdfminer.layout import LAParams, LTFigure, LTChar, LTTextLine, LTTextBox
from pdfminer.pdfinterp import PDFPageInterpreter
from pdfminer.pdfinterp import PDFResourceManager
from pdfminer.pdfpage import PDFPage
import re
import sys
from typing import List, Set

from antlr4grammar import Antlr4Rule, Antlr4Symbol, Antlr4Sequence, \
    Antlr4Newline, Antlr4Selection, Antlr4Indent, Antlr4Option, \
    Antlr4Iteration, generate_renamer, BaseGrammarConvertor, \
    rm_newline_from_simple_rules, get_used_non_terminals, \
    get_defined_non_terminals
from pdf_parsing import createPDFDoc


PAGE_OFFSET = 13  # VHDL 2008


def parse_vhdl_pdf():
    file_name = 'VHDL-2008.pdf'
    document = createPDFDoc(file_name)
    pages = PDFPage.create_pages(document)
    vp = VhdlSpecParser(sys.stdout)
    # if True:
    for page in islice(pages, PAGE_OFFSET + 6, PAGE_OFFSET + 239 + 2):
    # for page in islice(pages, PAGE_OFFSET + 23, PAGE_OFFSET + 25):
        # page = next(islice(pages, PAGE_OFFSET + 6, None))
        vp.parse_page(page)


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
        self.first_rule = True

    def parse_page(self, page):
        self.interpreter.process_page(page)
        layout = self.device.get_result()
        self.parse_obj(layout._objs)

    def parse_obj(self, objs):
        font_translation = self.FONT_TRANSLATION
        f = None
        for obj in objs:
            if isinstance(obj, LTTextBox):
                for o in obj._objs:
                    if isinstance(o, LTTextLine):
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
                        if is_rule_header:
                            if not self.first_rule:
                                self.ofile.write("</br>" % f)
                            else:
                                self.first_rule = False

                        if is_rule_header or self.in_rule:
                            self.in_rule = True
                            if not is_rule_header:
                                if text and not text.startswith(" "):
                                    self.in_rule = False
                                    continue

                            if text.strip():
                                for c in  o._objs:
                                    if isinstance(c, LTChar) and self.last_font != c.fontname:
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
            elif isinstance(obj, LTFigure):
                self.parse_obj(obj._objs)
            else:
                pass


class VhdlRule2Antlr4Rule(BaseGrammarConvertor):
    # to remove prefix marked by <it>
    RE_TAILING_UNDERSCORE = re.compile("</it>_")
    # to add an extra space if there is not
    RE_GRAM_OP = re.compile("(\{|\}|\[|\]|\|)")

    ASSIGN: '=='
    LBRACKET: '['
    RBRACKET: ']'
    MINUS = "–"  # note it is not regular - char
    SPEC_SYMB = {
        ";": "SEMI",
        "(": "LPAREN",
        ")": "RPAREN",
        "'": "APOSTROPHE",
        '"': "DBLQUOTE",
        "<<": "SHIFT_LEFT",
        ">>": "SHIFT_RIGHT",
        "@": "AT",
        "#": "HASHTAG",
        ",": "COMMA",
        ".": "DOT",
        "?": "QUESTIONMARK",
        ":": "COLON",
        "=": "EQ",
        "/=": "NEQ",
        "<": "LT",
        ">": "GT",
        ">=": "GE",
        "?=": "MATCH_EQ",
        "?/=": "MATCH_NEQ",
        "?<": "MATCH_LT",
        "?<=": "MATCH_LE",
        "?>": "MATCH_GT",
        "?>=": "MATCH_GE",  # relational_operator
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
                tokens.append(Antlr4Newline())
        assert tokens
        return self.parse_rule_tokens(tokens)

    @staticmethod
    def is_terminal(t):
        return t.isupper() or t[0] == "'"

    def convert(self, lines):
        fix_pid = re.compile("package instantiation_declaration")
        fix_sn = re.compile("simple name")
        rule_buff = []
        for line in lines:
            line = fix_pid.sub("package_instantiation_declaration", line)
            line = fix_sn.sub("simple_name", line)

            if not line[0].isspace():
                if rule_buff:
                    r = self.parse_rule(rule_buff)
                    self.rules.append(r)
                rule_buff = [line, ]
            else:
                rule_buff.append(line)

        if rule_buff:
            r = self.parse_rule(rule_buff)
            self.rules.append(r)


def left_recursion_remove(rules):
    # A → Aα / β
    # to
    # A → βA’
    # A’ → αA’ / ∈
    # is replaced manually in vhdl_base.g4
    replaced_rules = {
        "name",
        # "prefix",
        "selected_name",
        # "suffix",
        "indexed_name",
        "slice_name",
        # "attribute_name",
    }
    return [r for r in rules if r.name not in replaced_rules]


# {x} - zero or more times -> (x)*
# [x] - optional -> (x)?
# <HEFBHG+TimesNewRomanPS-ItalicMT>prefix<HEFBBF+TimesNewRomanPSMT>_name - rule equivalent to rule name
# <HEFBAE+TimesNewRomanPS-BoldMT>keyword_literal<HEFBBF+TimesNewRomanPSMT>
if __name__ == "__main__":
    renames = {k: k.upper() for k in [
        "base_specifier", "lower_case_letter", "upper_case_letter",
        'special_character', 'other_special_character', 'digit',
        'format_effector', 'space_character', 'underline']}
    renames["mode"] = "signal_mode"
    renames["E"] = "E_SIGN"
    renames["NULL"] = "NULL_SYM"
    for k, v in VhdlRule2Antlr4Rule.SPEC_SYMB.items():
        renames[k] = v

    IGNORED = [
        Antlr4Symbol(s, False)
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
            if isinstance(obj, Antlr4Symbol):
                s = obj.symbol
                if (s.isupper() and s not in VhdlRule2Antlr4Rule.SPEC_SYMB.values()
                        and s not in renames.values()
                        and s not in ["B", "D", "E", "O", "X"]):
                    keywords.add(obj.symbol)

        p.rules = left_recursion_remove(p.rules)
        apply_rename = generate_renamer(renames)
        for r in p.rules:
            r.walk(apply_rename)
            r.walk(collect_keywords)
            s = r.body

            while True:
                if isinstance(s, (Antlr4Selection, Antlr4Sequence)):
                    _s = s[-1]
                    if isinstance(_s, Antlr4Sequence):
                        all_to_remove = True
                        for s2 in _s:
                            if (s2 not in IGNORED
                                    and s2 != Antlr4Newline()
                                    and not isinstance(s2, Antlr4Indent)):
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
                r.body = Antlr4Selection([
                    Antlr4Sequence([a, Antlr4Newline(), Antlr4Indent(1)]),
                    Antlr4Sequence([a, b, Antlr4Newline(), Antlr4Indent(1)]),
                    Antlr4Sequence([b, Antlr4Newline()]),
                ])

    HEADER = """/*
 * Grammar extracted from the VHDL 1993, 2002, 2008, 2018 standard and then merged together
 * (the standard is selected by parser property)
 */

grammar vhdl;
"""
    with open("vhdl.g4", "w") as f:
        f.write("\n\n")
        f.write(HEADER)
        for kw in keywords:
            r = Antlr4Rule(kw, Antlr4Sequence([
                    Antlr4Symbol(k, True) for k in kw
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
            r = Antlr4Rule(v, Antlr4Symbol(k, True))
            f.write(r.toAntlr4())
            f.write("\n")

        with open("vhdl_base.g4") as b:
            f.write(b.read())
        for r in p.rules:
            f.write(r.toAntlr4())
            f.write("\n")
    # pprint(nts - def_nts)

