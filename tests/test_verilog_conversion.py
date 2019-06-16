from os import path
import unittest

from hdlConvertor import HdlConvertor
from hdlConvertor.hdlAst import HdlModuleDec, HdlModuleDef, HdlDirection
from hdlConvertor.language import Language

try:
    from tests.basic_tc import TEST_DIR, BasicTC, parseFile
except ImportError:
    from basic_tc import TEST_DIR, BasicTC, parseFile

VERILOG = Language.VERILOG
SV = Language.SYSTEM_VERILOG


class VerilogConversionTC(BasicTC):

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


if __name__ == "__main__":
    suite = unittest.TestSuite()
    # suite.addTest(BasicTC('test_read'))
    suite.addTest(unittest.makeSuite(VerilogConversionTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
