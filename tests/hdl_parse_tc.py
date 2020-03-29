from os import path
import os
import unittest

try:
    # python2
    from StringIO import StringIO
    from io import open
except ImportError:
    # python3
    from io import StringIO

from hdlConvertor import HdlConvertor
from hdlConvertor.language import Language
from hdlConvertor.to.verilog.verilog2005 import ToVerilog2005
from hdlConvertor.to.vhdl.vhdl2008 import ToVhdl2008


TEST_DIR = os.path.abspath(os.path.dirname(__file__))

VHDL = Language.VHDL
VERILOG = Language.VERILOG
SV = Language.SYSTEM_VERILOG


def get_language_path(lang_dir, language):
    if lang_dir is None:
        if language.is_system_verilog():
            lang_dir = os.path.join("sv_test", "others")
        elif language.is_verilog():
            lang_dir = "verilog"
        elif language.is_vhdl():
            lang_dir = "vhdl"
        else:
            raise ValueError(language)
    return lang_dir


def get_to_hdl_cls(language):
    if language == VERILOG or language == SV:
        return ToVerilog2005
    elif language == VHDL:
        return ToVhdl2008
    else:
        raise NotImplementedError(language)


def parseFile(fname, language, lang_dir=None):
    lang_dir = get_language_path(lang_dir, language)
    inc_dir = path.join(TEST_DIR, lang_dir)
    f = path.join(TEST_DIR, lang_dir, fname)
    c = HdlConvertor()
    res = c.parse([f, ], language, [inc_dir], debug=True)
    return f, res


def _default_to_hdl(context, language, buff):
    to_hdl_cls = get_to_hdl_cls(language)
    ser = to_hdl_cls(buff)
    ser.print_HdlContext(context)


class HdlParseTC(unittest.TestCase):
    """
    A base class for HDL parser tests
    """

    def parseWithRef(self, fname, language, lang_dir=None,
                     ref_fname=None, to_hdl=_default_to_hdl):
        """
        Parse file and compare it with a reference file.

        :param fname: name of a file to parse
        :type fname: str
        :type language: Language
        :param ref_fname: name of reference file in the case it is not the same
            (relative to "expected/" )
        :param lang_dir: path relative to a test directory where test file is stored
        :param transform: a function which can be used to modify a HdlContext
            pefore transformation to a target language
        """

        if ref_fname is None:
            ref_fname = fname

        lang_dir = get_language_path(lang_dir, language)
        _, res = parseFile(fname, language, lang_dir=lang_dir)

        buff = StringIO()
        # import sys
        # buff = sys.stdout

        # serialize a HDL code to a buff
        to_hdl(res, language, buff)

        ref_file = path.join(TEST_DIR, lang_dir,
                             "expected", ref_fname)
        res_str = buff.getvalue()
        # if fname == "aes.v":
        #     with open(ref_file, "w") as f:
        #         f.write(res_str)

        with open(ref_file, encoding="utf-8") as f:
            ref = f.read()

        self.assertEqual(ref, res_str)

    def check_obj_names(self, context, obj_cls, names):
        filtered = [o.name for o in context.objs if isinstance(o, obj_cls)]
        self.assertSequenceEqual(names, filtered)

    def find_obj_by_name(self, context, obj_cls, name):
        for o in context.objs:
            if isinstance(o, obj_cls) and o.name == name:
                return o
