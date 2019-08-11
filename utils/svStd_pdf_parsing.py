from pdfminer.layout import LTChar, LAParams, LTTextBox, LTTextLine, LTFigure
from pdfminer.pdfinterp import PDFResourceManager, PDFPageInterpreter
from pdfminer.converter import PDFPageAggregator
from pdf_parsing import createPDFDoc
from pdfminer.pdfpage import PDFPage


def parse_sv_pdf():
    file_name = 'sv2017-formal-syntax.pdf'
    document = createPDFDoc(file_name)
    pages = PDFPage.create_pages(document)
    out_file_name = "sv2017.g4_proto"
    with open(out_file_name, "w") as f:
        # f = sys.stdout
        vp = SvSpecParser(f)
        for page in pages:
        # for page in islice(pages, PAGE_OFFSET + 1136, PAGE_OFFSET + 1181 + 2):
        # for page in islice(pages, PAGE_OFFSET + 23, PAGE_OFFSET + 25):
            # page = next(islice(pages, PAGE_OFFSET + 6, None))
            vp.parse_page(page)
        f.write("\n</br>\n")
    # post processing
    # RE_GRAM_OP = re.compile("((?<!<b>)([\+#\*]*)[\{\}\[\]|\|]+([\+#\*]*)(?!</b>))")
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
            if line == ('    | <b>PATHPULSE$</b>'
                    'specify_input_terminal_descriptor<b>$'
                    '</b>specify_output_terminal_descriptor \n'):
                line = line.replace("</b>", "</b> ")
            else:
                for to_fix in FIX_COMA_AS_TERMINAL:
                    if to_fix in line:
                        line = line.replace(",", "<b>,</b>")
                        break

            replaces = [
                ('<b>[*</b>', '<b>[</b> <b>*</b>'),
                ('<b>[-></b>', '<b>[</b> <b>-></b>'),
                ('<b>[=</b>', '<b>[</b> <b>=</b>'),
                ('<b>[*]</b>', '<b>[</b> <b>*</b> <b>]</b>'),
                ('<b>[+]</b>', '<b>[</b> <b>+</b> <b>]</b>'),
                ('<b>##[+]</b>', '<b>##</b> <b>[</b> <b>+</b> <b>]</b>'),
                ('<b>##[*]</b>', '<b>##</b> <b>[</b> <b>*</b> <b>]</b>'),
                ('<b>@@(</b>', '<b>@@</b> <b>(</b>'),
                ('<b>.*</b>', '<b>.</b> <b>*</b>'),
                ('<b>@*</b>', '<b>@</b> <b>*</b>'),
                ('<b>(*)</b>', '<b>(</b> <b>*</b> <b>)</b>'),
                ('<b>(*</b>', '<b>(</b> <b>*</b>'),
                ('<b>*)</b>', '<b>*</b> <b>)</b>'),
                ("<b>'{</b>", "<b>'</b> <b>{</b>"),
                ("[ <b>a</b>-<b>zA</b>-<b>Z_</b> ]", " <b>[a-zA-Z_]</b> "),
                ("[ <b>a</b>-<b>zA</b>-<b>Z0</b>-<b>9_$</b> ]", " <b>[a-zA-Z0-9_$]</b> "),
                ("[ <b>a</b>-<b>zA</b>-<b>Z0</b>-<b>9_</b> ]", " <b>[a-zA-Z0-9_]</b> "),
                ("<b>*::*</b>", "<b>*</b> <b>::</b> <b>*</b>"),
                ("::=", " ::= "),
                ("–", "-"),
                ("\\n", "<b>\\n</b>"),
                ("<b>$</b>", " <b>$</b>"),
                ("<b>s_always</b> <b>[</b> constant_range] property_expr",
                 "<b>s_always</b> <b>[</b> constant_range <b>]</b> property_expr"),
                ("option.</b>member", "option.</b> member"),
                ("</b>case", "</b> case"),
                ("identifier<b>.</b>port", "identifier <b>.</b> port"),
                ("    class_qualifier :=", "</br>\nclass_qualifier ::="),
                ("</b>[<b>", "</b> [ <b>"),
                ("</b>|<b>", "</b> | <b>"),
                ("</b>]<b>", "</b> ] <b>"),
                ("</b>z_or_x", "</b> z_or_x"),
                ("<b>$</b>[ <b>a</b>", "<b>$</b> [ <b>a</b>"),
                (" ]{ [ ", " ] { [ "),
                ("hierarchical_identifier<b>.</b>", "hierarchical_identifier <b>.</b>"),
                ("<b>if</b> ( expression_or_dist )", "<b>if</b> <b>(</b> expression_or_dist <b>)</b>"),
                ("<b>case</b> ( expression_or_dist )", "<b>case</b> <b>(</b> expression_or_dist <b>)</b>"),
                ("<b>#(</b>", "<b>#</b> <b>(</b>"),
                ("<b>)matches</b>", "<b>)</b> <b>matches</b>"),
                ("<b>[-></b>", "<b>[</b> <b>-></b>"),
                ("constant _expression", "constant_expression"),
                ("function_declaraton", "function_declaration"),
                ("<b>);</b>", "<b>)</b> <b>;</b>"),
                ("option.</b>", "option</b> <b>.</b>"),
                ("<b>-incdir</b>", "<b>-</b> <b>incdir</b>"),
                ("<b>+:</b>", "<b>+</b> <b>:</b>"),
                ("<b>-:</b>", "<b>-</b> <b>:</b>"),
            ]
            for elm, repl in replaces:
                line = line.replace(elm, repl)
            f.write(line)


class SvSpecParser():
    FONT_TRANSLATION = {  # "HEFBHG+TimesNewRomanPS-ItalicMT": "it",
                        # "HEFBAE+TimesNewRomanPS-BoldMT": "b",
                        'BVXWSQ+CourierNew,Bold': 'b',
                        'BHDFJL+TimesNewRomanPSMT': None,
                        'WTCCEL+TimesNewRoman,Italic': None,
                        None: None}

    def __init__(self, ofile):
        rsrcmgr = PDFResourceManager()
        laparams = LAParams()
        self.device = PDFPageAggregator(rsrcmgr, laparams=laparams)
        self.interpreter = PDFPageInterpreter(rsrcmgr, self.device)
        self.last_font = None
        self.in_rule = False
        self.font_print_pending = False
        self.ofile = ofile
        self.first_rule = True

    def parse_page(self, page):
        self.interpreter.process_page(page)
        layout = self.device.get_result()
        self.parse_obj(layout._objs)

    def collect_lines(self, o):
            if isinstance(o, LTTextBox):
                lines = [_o for _o in o._objs if isinstance(_o, LTTextLine)]
                yield from lines
            elif isinstance(o, LTFigure):
                yield from self.collect_lines(o._objs)

            return

    def parse_obj(self, objs):
        font_translation = self.FONT_TRANSLATION

        f = None
        tmp_lines = []
        for o in objs:
            tmp_lines.extend(self.collect_lines(o))

        tmp_lines.sort(key=lambda o: o.y0, reverse=True)
        tmp_lines = tmp_lines[2:-3]  # cut off header and footer

        for o in tmp_lines:
            text = o.get_text()
            # print(text)

            is_rule_header = "::=" in text
            if is_rule_header or self.in_rule:
                if is_rule_header:
                    if not self.first_rule:
                        self.ofile.write("\n</br>\n")
                    else:
                        self.first_rule = False

                # if is_rule_header and text.startswith("unary_module_path_operator"):
                #     print("----------")
                self.in_rule = True
                if not is_rule_header:
                    if text and o.x0 < 85:
                        self.in_rule = False
                        continue
                    self.ofile.write("    ")

                if text.strip():
                    for c in  o._objs:
                        is_char = isinstance(c, LTChar)
                        if is_char:
                            if c.fontname == 'BHDEOM+Arial-BoldMT':
                                self.in_rule = False
                                # title
                                break
                        if (is_char and c.matrix[-1] - o._objs[0].matrix[-1] > 3.5):
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
