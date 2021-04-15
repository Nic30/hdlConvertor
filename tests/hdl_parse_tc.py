from os import path
import os
import unittest

from hdlConvertor import HdlConvertor
from hdlConvertorAst.hdlAst._structural import HdlModuleDec, HdlModuleDef
from hdlConvertorAst.language import Language
from hdlConvertorAst.to.hwt import ToHwt
from hdlConvertorAst.to.verilog.verilog2005 import ToVerilog2005
from hdlConvertorAst.to.vhdl.vhdl2008 import ToVhdl2008
from hdlConvertorAst.to.json import ToJson


try:
    # python2
    from StringIO import StringIO
    from io import open
except ImportError:
    # python3
    from io import StringIO


TEST_DIR = os.path.abspath(os.path.dirname(__file__))

VHDL = Language.VHDL
VERILOG = Language.VERILOG
SV = Language.SYSTEM_VERILOG

LANG_SUFFIX = {
    VHDL: ".vhd",
    VERILOG: ".v",
    SV: ".sv",
    Language.HDLCONVERTOR_JSON: ".json",
    Language.HWT: ".py",
}


def get_language_path(lang_dir, language):
    if lang_dir is None:
        if language.is_system_verilog():
            lang_dir = os.path.join("sv_test", "others")
        elif language.is_verilog():
            lang_dir = "verilog"
        elif language.is_vhdl():
            lang_dir = "vhdl"
        elif language == Language.HDLCONVERTOR_JSON:
            lang_dir = "json"
        else:
            raise ValueError(language)
    return lang_dir


def get_to_hdl_cls(language):
    if language == VERILOG or language == SV:
        return ToVerilog2005
    elif language == VHDL:
        return ToVhdl2008
    elif language == Language.HWT:
        return ToHwt
    else:
        raise NotImplementedError(language)


def parseFile(fname, language, input_dir=None):
    input_dir = get_language_path(input_dir, language)
    inc_dir = path.join(TEST_DIR, input_dir)
    f = path.join(TEST_DIR, input_dir, fname)
    c = HdlConvertor()
    res = c.parse([f, ], language, [inc_dir], debug=True)
    return f, res


def _default_to_hdl(context, language, buff):
    to_hdl_cls = get_to_hdl_cls(language)
    ser = to_hdl_cls(buff)
    ser.visit_HdlContext(context)


class HdlParseTC(unittest.TestCase):
    """
    A base class for HDL parser tests
    """

    def parseWithRef(self, fname, language, input_dir=None, output_dir=None,
                     ref_fname=None, to_hdl=_default_to_hdl):
        """
        Parse file and compare it with a reference file.

        :param fname: name of a file to parse
        :type fname: str
        :type language: Language
        :param ref_fname: name of reference file in the case it is not the same
            (relative to "expected/" )
        :param input_dir: path relative to a test directory where test input file is stored
        :param output_dir: path relative to a test directory where $output_dir/expected/$fname is a reference
            file with expected test output (suffix of file may change depending on output format)
        :param transform: a function which can be used to modify a HdlContext
            pefore transformation to a target language
        """

        if ref_fname is None:
            ref_fname = fname

        input_dir = get_language_path(input_dir, language)
        _f, res = parseFile(fname, language, input_dir=input_dir)
        # check if repr works
        repr(res)

        buff = StringIO()
        # import sys
        # buff = sys.stdout

        # serialize a HDL code to a buff
        to_hdl(res, language, buff)
        if output_dir is None:
            output_dir = path.dirname(_f)
        else:
            output_dir = path.join(TEST_DIR, output_dir)

        ref_file = path.join(output_dir, "expected", ref_fname)
        res_str = buff.getvalue()
        # if fname == "aes.v":
        #     with open(ref_file, "w") as f:
        #         f.write(res_str)

        # check also that the content is serializable as json and that the repr works
        tj = ToJson()
        tj.visit_HdlContext(res)
        repr(res)

        with open(ref_file, encoding="utf-8") as f:
            ref = f.read()

        self.assertEqual(ref, res_str)
        return _f, res

    def check_obj_names(self, context, obj_cls, names):
        if obj_cls == HdlModuleDec:
            filtered = []
            for o in context.objs:
                if isinstance(o, HdlModuleDef) and o.dec is not None:
                    filtered.append(o.dec.name)
        else:
            filtered = [o.name for o in context.objs if isinstance(o, obj_cls)]
        self.assertSequenceEqual(names, filtered)

    def find_obj_by_name(self, context, obj_cls, name):
        if obj_cls == HdlModuleDec:
            for o in context.objs:
                if (isinstance(o, HdlModuleDec) and o.name == name) or\
                        (isinstance(o, HdlModuleDef) and o.dec.name == name):
                    return o.dec

        for o in context.objs:
            if isinstance(o, obj_cls) and o.name == name:
                return o
