"""
Utils to implement version of (System)Verlog language standard to a grammar
"""
from utils.antlr4.grammar import Antlr4Symbol, Antlr4Sequence
from utils.sv.keywords import IEEE1364_1995_KEYWORDS, IEEE1364_2001_KEYWORDS, \
    IEEE1364_2001_NOCONFIG_KEYWORDS, IEEE1364_2005_KEYWORDS, \
    IEEE1800_2005_KEYWORDS, IEEE1800_2009_KEYWORDS, IEEE1800_2012_KEYWORDS, \
    IEEE1800_2017_KEYWORDS


def print_lexer_extra_for_std_version_specific_keywords(f):
    f.write("@lexer::header {\n#include <hdlConvertor/language.h>\n}\n")
    f.write("@lexer::members {\n    hdlConvertor::Language language_version;\n}\n")


def add_predicate(r, std):
    r.body = Antlr4Sequence([Antlr4Symbol("{language_version >= hdlConvertor::Language::%s}?" % std, True, is_regex=True), r.body])


def std_version_specific_keywords(rules):
    stds = [
        ("VERILOG1995", set(IEEE1364_1995_KEYWORDS)),
        ("VERILOG2001", set(IEEE1364_2001_KEYWORDS)),
        ("VERILOG2001_NOCONFIG", set(IEEE1364_2001_NOCONFIG_KEYWORDS)),
        ("VERILOG2005", set(IEEE1364_2005_KEYWORDS)),
        ("SV2005", set(IEEE1800_2005_KEYWORDS)),
        ("SV2009", set(IEEE1800_2009_KEYWORDS)),
        ("SV2012", set(IEEE1800_2012_KEYWORDS)),
        ("SV2017", set(IEEE1800_2017_KEYWORDS)),
    ]
    lexer_rules = [r for r in rules if r.is_lexer_rule()]
    for r in lexer_rules:
        b = r.body
        if isinstance(b, Antlr4Symbol) and b.is_terminal:
            for std, kws in stds:
                if b.symbol in kws:
                    if std != "VERILOG1995":
                        add_predicate(r, std)
                    break
