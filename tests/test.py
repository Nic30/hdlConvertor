from os import path
import unittest

try:
    # python2
    from StringIO import StringIO
except ImportError:
    # python3
    from io import StringIO

try:
    from tests.test_constants import *
except ImportError:
    from test_constants import *

from hdlConvertor import HdlConvertor, ParseException
from hdlConvertor.language import Language
from hdlConvertor.hdlAst import HdlModuleDec, HdlModuleDef, HdlDirection
from hdlConvertor.toVerilog import ToVerilog


VHDL = Language.VHDL
VERILOG = Language.VERILOG
SV = Language.SYSTEM_VERILOG


def parseFile(fname, language):
    _language = language
    if language == SV:
        _language = VERILOG
    inc_dir = path.join(TEST_DIR, _language.value)
    f = path.join(BASE_DIR, "tests", _language.value, fname)
    c = HdlConvertor()
    res = c.parse([f, ], language, [inc_dir], debug=True)
    return f, res



class BasicTC(unittest.TestCase):
    def parseWithRef(self, fname, language):
        _, res = parseFile(fname, language)
        buff = StringIO()
        ser = ToVerilog(buff)
        ser.print_context(res)
        _language = language
        if language == SV:
            _language = VERILOG

        ref_file =  path.join(BASE_DIR, "tests", _language.value,
                              "expected", fname)
        res_str = buff.getvalue()
        # with open(ref_file, "w") as f:
        #     f.write(res_str)

        with open(ref_file) as f:
            ref = f.read()

        self.assertEqual(ref, res_str)

    def check_obj_names(self, context, obj_cls, names):
        filtered = [ o.name for o in context.objs if isinstance(o, obj_cls)]
        self.assertSequenceEqual(names, filtered)

    def find_obj_by_name(self, context, obj_cls, name):
        for o in context.objs:
            if isinstance(o, obj_cls) and o.name == name:
                return o

    def test_vhld_dump_mux(self):
        f, res = parseFile("mux.vhd", VHDL)
        str(res)

    def test_vhdl_package_array_const(self):
        f, res = parseFile("package_array_const.vhd", VHDL)
        str(res)

    def test_vhdl_package_component(self):
        f, res = parseFile("package_component.vhd", VHDL)
        str(res)

    def test_vhdl_package_constants(self):
        f, res = parseFile("package_constants.vhd", VHDL)
        str(res)

    def test_vhdl_fourbit_adder(self):
        f, res = parseFile("fourbit_adder.vhd", VHDL)
        str(res)

    def test_vhdl_mux2i(self):
        f, res = parseFile("mux2i.vhd", VHDL)
        str(res)

    def test_verilog_uart(self):
        self.parseWithRef("uart.v", VERILOG)

    def test_verilog_adder_implicit(self):
        f, res = parseFile("adder_implicit.v", VERILOG)
        str(res)

    def test_verilog_arbiter(self):
        f, res = parseFile("arbiter.v", VERILOG)
        str(res)
        a = self.find_obj_by_name(res, HdlModuleDec, "arbiter")
        self.assertEqual(len(a.params), 0)
        self.assertEqual(len(a.ports), 10)
        ports = {
            "clk" : HdlDirection.IN,
            "rst" : HdlDirection.IN,
            "req3": HdlDirection.IN,
            "req2": HdlDirection.IN,
            "req1": HdlDirection.IN,
            "req0": HdlDirection.IN,
            "gnt3": HdlDirection.OUT,
            "gnt2": HdlDirection.OUT,
            "gnt1": HdlDirection.OUT,
            "gnt0": HdlDirection.OUT,
        }

        _ports = { p.name: p.direction for p in a.ports }
        self.assertDictEqual(_ports, ports)

    def test_verilog_include(self):
        f, res = parseFile("include.v", VERILOG)
        str(res)
        self.check_obj_names(res, HdlModuleDec, ["arbiter", "uart"])

    def test_verilog_define(self):
        f, res = parseFile("define.v", VERILOG)
        str(res)

    def test_verilog_fifo_rx(self):
        f, res = parseFile("fifo_rx.v", VERILOG)
        f = self.find_obj_by_name(res, HdlModuleDec, "fifo_rx")
        self.assertEqual(len(f.params), 2)
        self.assertEqual(len(f.ports), 11)
        str(res)

    def test_multiple_files_at_once(self):
        language = VERILOG
        f = [path.join(TEST_DIR, language.value, f)
             for f in ["fifo_rx.v", "define.v", "arbiter.v", "uart.v"]]
        inc_dir = path.join(TEST_DIR, language.value)
        c = HdlConvertor()
        res = c.parse(f, language, [inc_dir], debug=True)
        e = [ o for o in res.objs if isinstance(o, HdlModuleDef)]
        self.assertSetEqual(set(_e.module_name for _e in e),
                            {'fifo_rx', 'test', 'arbiter', 'uart'})
        str(res)

    def test_verilog_macro(self):
        f, res = parseFile("macro.v", VERILOG)
        str(res)

    def test_directive_verilogpp(self):
        f, res = parseFile("directive_verilogpp.v", VERILOG)
        str(res)

    def test_system_verilog_mem_base_object(self):
        f, res = parseFile("mem_base_object.sv", SV)
        str(res)

    def test_vhdl_malformed(self):
        with self.assertRaises(ParseException):
            f, res = parseFile("malformed.vhdl", VHDL)


if __name__ == "__main__":
    suite = unittest.TestSuite()
    # suite.addTest(BasicTC('test_read'))
    suite.addTest(unittest.makeSuite(BasicTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
