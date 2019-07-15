#!/usr/bin/env python

import pdfminer3
from pdfminer3.pdfinterp import PDFResourceManager
from pdfminer3.pdfinterp import PDFPageInterpreter
from pdfminer3.layout import LAParams
from pdfminer3.converter import PDFPageAggregator
import re
from typing import List, Set
from utils.antlr4grammar import ANTLR4Rule, ANTLR4Symbol, ANTLR4Sequence, \
    ANTLR4VisualNewline, ANTLR4Selection, ANTLR4VisualIndent, ANTLR4Option, \
    ANTLR4Iteration
from utils.pdf_parsing import createPDFDoc
from pdfminer3.pdfpage import PDFPage
import sys
from itertools import islice

PAGE_OFFSET = 0

def parse_sv_pdf():
    file_name = 'sv2017.pdf'
    document = createPDFDoc(file_name)
    pages = PDFPage.create_pages(document)
    vp = SvSpecParser(sys.stdout)
    # if True:
    for page in islice(pages, PAGE_OFFSET + 1136, PAGE_OFFSET + 1181 + 2):
    # for page in islice(pages, PAGE_OFFSET + 23, PAGE_OFFSET + 25):
        # page = next(islice(pages, PAGE_OFFSET + 6, None))
        vp.parse_page(page)


class SvSpecParser():
    FONT_TRANSLATION = {#"HEFBHG+TimesNewRomanPS-ItalicMT": "it",
                        #"HEFBAE+TimesNewRomanPS-BoldMT": "b",
                        'BVXWSQ+CourierNew,Bold': 'b',
                        'BHDFJL+TimesNewRomanPSMT': None,
                        None:None}
    #FOOTER_STR = "Copyright © 2018 IEEE. All rights reserved."
    FOOTER_STR = "Authorized licensed use limited to:"
    #HEADER_STR = "IEEE Standard for SystemVerilog—Unified Hardware Design, Specification, and Verification Language"
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
                            #if text.startswith("list_of_port_declarations"):
                            #    print("----------")
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
                                        and c.matrix[-1] - o._objs[0].matrix[-1] > 3.0):
                                        #sys.stderr.write(c.get_text())
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
                                    #if text.startswith("list_of_port_declarations") and c.get_text() == "s":
                                    #    print("----------")

                                    self.ofile.write(c.get_text())
            # if it's a container, recurse
            elif isinstance(obj, pdfminer3.layout.LTFigure):
                self.parse_obj(obj._objs)
            else:
                pass

if __name__ == "__main__":
    parse_sv_pdf()
