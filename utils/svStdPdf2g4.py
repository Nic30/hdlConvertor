#!/usr/bin/env python

import pdfminer3
from pdfminer3.pdfinterp import PDFResourceManager
from pdfminer3.pdfinterp import PDFPageInterpreter
from pdfminer3.layout import LAParams
from pdfminer3.converter import PDFPageAggregator
import re
from typing import List, Set
from antlr4grammar import ANTLR4Rule, ANTLR4Symbol, ANTLR4Sequence, \
    ANTLR4VisualNewline, ANTLR4Selection, ANTLR4VisualIndent, ANTLR4Option, \
    ANTLR4Iteration, generate_renamer, rm_newline_from_simple_rules, \
    get_used_non_terminals, get_defined_non_terminals, BaseGrammarConvertor
from pdf_parsing import createPDFDoc
from pdfminer3.pdfpage import PDFPage
import sys
from itertools import islice

PAGE_OFFSET = 0


def parse_sv_pdf():
    file_name = 'sv2017.pdf'
    document = createPDFDoc(file_name)
    pages = PDFPage.create_pages(document)
    out_file_name = "sv2017.g4_proto"
    with open(out_file_name, "w") as f:
        # f = sys.stdout
        vp = SvSpecParser(f)
        for page in islice(pages, PAGE_OFFSET + 1136, PAGE_OFFSET + 1181 + 2):
        # for page in islice(pages, PAGE_OFFSET + 23, PAGE_OFFSET + 25):
            # page = next(islice(pages, PAGE_OFFSET + 6, None))
            vp.parse_page(page)

    # post processing
    RE_GRAM_OP = re.compile("((?<!<b>)([\+#\*]*)[\{\}\[\]|\|]+([\+#\*]*)(?!</b>))")
    FIX_COMA_AS_TERMINAL = [
        "strength0 , strength1",
        "strength1 , strength0",
        "strength0 , <b>highz1</b>",
        "strength1 , <b>highz0</b>",
        "<b>highz0</b> , strength",
        "<b>highz1</b> , strength",
    ]
    with open(out_file_name) as f:
        lines = f.readlines()

    with open(out_file_name, "w") as f:
        for line in lines:
            line = re.sub("::=", " ::= ", line)
            if line == ('    | <b>PATHPULSE$</b>'
                    'specify_input_terminal_descriptor<b>$'
                    '</b>specify_output_terminal_descriptor \n'):
                line = re.sub("</b>", "</b> ", line)
            else:
                for to_fix in FIX_COMA_AS_TERMINAL:
                    if to_fix in line:
                        line = line.replace(",", "<b>,</b>")
                        break

            line = RE_GRAM_OP.sub(" \g<1> ", line)
            line = line.replace("–", "-")
            f.write(line)

class SvSpecParser():
    FONT_TRANSLATION = {  # "HEFBHG+TimesNewRomanPS-ItalicMT": "it",
                        # "HEFBAE+TimesNewRomanPS-BoldMT": "b",
                        'BVXWSQ+CourierNew,Bold': 'b',
                        'BHDFJL+TimesNewRomanPSMT': None,
                        None:None}
    # FOOTER_STR = "Copyright © 2018 IEEE. All rights reserved."
    FOOTER_STR = "Authorized licensed use limited to:"
    # HEADER_STR = "IEEE Standard for SystemVerilog—Unified Hardware Design, Specification, and Verification Language"
    HEADER_STR = "IEEE Std 1800-2017"

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

        f = None
        for obj in objs:
            if isinstance(obj, pdfminer3.layout.LTTextBox):
                for o in obj._objs:
                    if isinstance(o, pdfminer3.layout.LTTextLine):
                        if self.header_footer_skipping:
                            text = o.get_text()
                            if text.startswith(self.HEADER_STR):
                                self.header_footer_skipping = False
                            continue

                        text = o.get_text()
                        # print(text)
                        if text.startswith(self.FOOTER_STR):
                            self.header_footer_skipping = True
                            continue

                        is_rule_header = "::=" in text
                        if is_rule_header or self.in_rule:
                            # if text.startswith("module_ansi_header"):
                            #     print("----------")
                            self.in_rule = True
                            if not is_rule_header:
                                if text and o.x0 < 95:
                                    self.in_rule = False
                                    continue
                                self.ofile.write("    ")

                            if text.strip():
                                for c in  o._objs:
                                    is_char = isinstance(c, pdfminer3.layout.LTChar)
                                    if (isinstance(c, pdfminer3.layout.LTChar)
                                        and c.matrix[-1] - o._objs[0].matrix[-1] > 3.5):
                                        # sys.stderr.write(c.get_text())
                                        # skipping hrefs, which are upper indexes
                                        continue
                                    if is_char and self.last_font != c.fontname:
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
                                    # if text.startswith("list_of_port_declarations") and c.get_text() == "s":
                                    #    print("----------")

                                    self.ofile.write(c.get_text())
            # if it's a container, recurse
            elif isinstance(obj, pdfminer3.layout.LTFigure):
                self.parse_obj(obj._objs)
            else:
                pass


class SvRule2Antlr4Rule(BaseGrammarConvertor):

    SPEC_SYMB = {";" : "SEMI",
                 "(" : "LPAREN",
                 ")" : "RPAREN",
                 "'" : "APOSTROPHE",
                 '"' : "DBLQUOTE",
                 "<<" : "SHIFT_LEFT",
                 ">>" : "SHIFT_RIGHT",
                 # "@": "AT",
                 # "#": "HASHTAG",
                 ",": "COMMA",
                 ".": "DOT",
                 "?": "QUESTIONMARK",
                 ":": "COLON",
                 "=": "EQ",
                 # "/=": "NEQ",
                 "<": "LT",
                 ">" : "GT",
                 ">=": "GE",
                 "<=": "LE",
                 # "?=": "MATCH_EQ",
                 # "?/=": "MATCH_NEQ",
                 # "?<": "MATCH_LT",
                 # "?<=": "MATCH_LE" ,
                 # "?>": "MATCH_GT",
                 # "?>=": "MATCH_GE" ,  # relational_operator
                 "+": "PLUS",
                 "-": "MINUS",
                 "&": "AMPERSAND",  # adding_operator
                 "|": "BAR",
                 "\\": "BACKSLASH",
                 "*": "MUL",
                 "/": "DIV",  # multiplying_operator
                 "**": "DOUBLESTAR",  # miscellaneous_operator
                 "\\": "BACKSLASH",  # extended_identifier
                 # "`": "GRAVE_ACCENT",  # tool_directive
                 # "^": "UP",  # relative_pathname
                 # ":=": "VARASGN",  # simple_variable_assignment
                 # "<>": "BOX",  # constrained_array_definition
                 # "=>": "ARROW",  # association_element
                 # "??": "COND_OP",  # condition_operator
                 }
    INDENT = "      "

    def parse_rule(self, rule_buff):
        tokens = []
        for part in rule_buff:
            ind = self.extract_indent(part)
            if ind:
                tokens.append(ind)

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
        rule_buff = []
        for l in lines:
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


def main():
    renames = {}
    renames["E"] = "E_SIGN"
    renames["NULL"] = "NULL_SYM"
    for k, v in SvRule2Antlr4Rule.SPEC_SYMB.items():
        renames[k] = v

    p = SvRule2Antlr4Rule()
    with open("sv2017.g4_proto") as f:
        p.convert(f)
    rm_newline_from_simple_rules(p.rules)
    # nts = get_used_non_terminals(p.rules)
    # def_nts = get_defined_non_terminals(p.rules)

    apply_rename = generate_renamer(renames)
    for r in p.rules:
        r.walk(apply_rename)
        s = r.body

        while True:
            if isinstance(s, (ANTLR4Selection, ANTLR4Sequence)):
                _s = s[-1]
                if isinstance(_s, ANTLR4Sequence):
                    all_to_remove = True
                    # for s2 in _s:
                    #    if (s2 not in IGNORED
                    #            and s2 != ANTLR4VisualNewline()
                    #            and not isinstance(s2, ANTLR4VisualIndent)):
                    #        all_to_remove = False
                    if _s and all_to_remove:
                        s.pop()
                        continue
            break


if __name__ == "__main__":
    parse_sv_pdf()
    #main()
