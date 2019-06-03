import sys
from os import path
from pprint import pprint
import unittest

try:
    from .use_build_version import BASE_DIR, TEST_DIR
except ImportError:
    from use_build_version import BASE_DIR, TEST_DIR

from hdlConvertor import HdlConvertor, ParseException
from hdlConvertor.language import Language
from hdlConvertor.hdlAst import HdlModuleDec, HdlModuleDef, HdlDirection


VHDL = Language.VHDL
VERILOG = Language.VERILOG
SV = Language.SYSTEM_VERILOG


def dumpFile(fname, language):
    _language = language
    if language == SV:
        _language = VERILOG
    inc_dir = path.join(TEST_DIR, _language.value)
    f = path.join(BASE_DIR, "tests", _language.value, fname)
    c = HdlConvertor()
    res = c.parse([f, ], language, [inc_dir], debug=True)
    return f, res


class BasicTC(unittest.TestCase):

    def check_obj_names(self, context, obj_cls, names):
        filtered = [ o.name for o in context.objs if isinstance(o, obj_cls)]
        self.assertSequenceEqual(names, filtered)

    def find_obj_by_name(self, context, obj_cls, name):
        for o in context.objs:
            if isinstance(o, obj_cls) and o.name == name:
                return o

    def test_vhld_dump_mux(self):
        f, res = dumpFile("mux.vhd", VHDL)
        str(res)

    def test_vhdl_package_array_const(self):
        f, res = dumpFile("package_array_const.vhd", VHDL)
        str(res)

    def test_vhdl_package_component(self):
        f, res = dumpFile("package_component.vhd", VHDL)
        str(res)

    def test_vhdl_package_constants(self):
        f, res = dumpFile("package_constants.vhd", VHDL)
        str(res)

    def test_vhdl_fourbit_adder(self):
        f, res = dumpFile("fourbit_adder.vhd", VHDL)
        str(res)

    def test_vhdl_mux2i(self):
        f, res = dumpFile("mux2i.vhd", VHDL)
        str(res)

    def test_verilog_uart(self):
        f, res = dumpFile("uart.v", VERILOG)
        str(res)

    def test_verilog_adder_implicit(self):
        f, res = dumpFile("adder_implicit.v", VERILOG)
        str(res)

    def test_verilog_arbiter(self):
        f, res = dumpFile("arbiter.v", VERILOG)
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
        f, res = dumpFile("include.v", VERILOG)
        str(res)
        self.check_obj_names(res, HdlModuleDec, ["arbiter", "uart"])

    def test_verilog_define(self):
        f, res = dumpFile("define.v", VERILOG)
        str(res)

    def test_verilog_fifo_rx(self):
        f, res = dumpFile("fifo_rx.v", VERILOG)
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
        f, res = dumpFile("macro.v", VERILOG)
        str(res)

    def test_directive_verilogpp(self):
        f, res = dumpFile("directive_verilogpp.v", VERILOG)
        str(res)

    def test_system_verilog_mem_base_object(self):
        f, res = dumpFile("mem_base_object.sv", SV)
        str(res)

    def test_vhdl_malformed(self):
        with self.assertRaises(ParseException):
            f, res = dumpFile("malformed.vhdl", VHDL)


if __name__ == "__main__":
    suite = unittest.TestSuite()
    # suite.addTest(BasicTC('test_read'))
    suite.addTest(unittest.makeSuite(BasicTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
