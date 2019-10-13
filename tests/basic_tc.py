from os import path
import unittest
import os
try:
    # python2
    from StringIO import StringIO
    from io import open
except ImportError:
    # python3
    from io import StringIO

from hdlConvertor.language import Language
from hdlConvertor import HdlConvertor
from hdlConvertor.toVerilog import ToVerilog
from hdlConvertor.toVhdl import ToVhdl

TEST_DIR = os.path.abspath(os.path.dirname(__file__))

VHDL = Language.VHDL
VERILOG = Language.VERILOG
SV = Language.SYSTEM_VERILOG


def parseFile(fname, language):
    if language.is_system_verilog():
        lang_dir = os.path.join("sv_test", "others")
    elif language.is_verilog():
        lang_dir = "verilog"
    elif language.is_vhdl():
        lang_dir = "vhdl"
    else:
        raise ValueError(language)
    inc_dir = path.join(TEST_DIR, lang_dir)
    f = path.join(TEST_DIR, lang_dir, fname)
    c = HdlConvertor()
    res = c.parse([f, ], language, [inc_dir], debug=True)
    return f, res


class BasicTC(unittest.TestCase):

    def parseWithRef(self, fname, language):
        _, res = parseFile(fname, language)
        buff = StringIO()
        # import sys
        # buff = sys.stdout
        if language == VERILOG or language == SV:
            ser = ToVerilog(buff)
        elif language == VHDL:
            ser = ToVhdl(buff)
        else:
            raise NotImplementedError(language)

        ser.print_context(res)
        if language.is_verilog() or language.is_system_verilog():
            lang_dir = "verilog"
        elif language.is_vhdl():
            lang_dir = "vhdl"
        else:
            raise ValueError(language)
        ref_file = path.join(TEST_DIR, lang_dir,
                             "expected", fname)
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
