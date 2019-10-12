from os import path
import unittest

from hdlConvertor import HdlConvertor
from hdlConvertor.hdlAst import HdlModuleDec, HdlModuleDef, HdlDirection
from hdlConvertor.language import Language

from tests.basic_tc import TEST_DIR, BasicTC, parseFile

VERILOG = Language.VERILOG
SV = Language.SYSTEM_VERILOG


class VerilogConversionTC(BasicTC):

    def test_adder_implicit(self):
        self.parseWithRef("adder_implicit.v", VERILOG)

    def test_aes(self):
        self.parseWithRef("aes.v", VERILOG)

    def test_aFifo(self):
        self.parseWithRef("aFifo.v", VERILOG)

    # not implemented repeat construct
    # def test_arbiter_tb(self):
    #    self.parseWithRef("arbiter_tb.v", VERILOG)

    def test_arbiter(self):
        f, res = parseFile("arbiter.v", VERILOG)
        str(res)
        a = self.find_obj_by_name(res, HdlModuleDec, "arbiter")
        self.assertEqual(len(a.params), 0)
        self.assertEqual(len(a.ports), 10)
        ports = {
            "clk": HdlDirection.IN,
            "rst": HdlDirection.IN,
            "req3": HdlDirection.IN,
            "req2": HdlDirection.IN,
            "req1": HdlDirection.IN,
            "req0": HdlDirection.IN,
            "gnt3": HdlDirection.OUT,
            "gnt2": HdlDirection.OUT,
            "gnt1": HdlDirection.OUT,
            "gnt0": HdlDirection.OUT,
        }

        _ports = {p.name: p.direction for p in a.ports}
        self.assertDictEqual(_ports, ports)

    def test_cam(self):
        self.parseWithRef("cam.v", VERILOG)

    def test_decoder_using_case(self):
        self.parseWithRef("decoder_using_case.v", VERILOG)

    def test_define(self):
        self.parseWithRef("define.v", VERILOG)

    def test_directive_verilogpp(self):
        self.parseWithRef("directive_verilogpp.v", VERILOG)

    def test_dff_async_reset(self):
        self.parseWithRef("dff_async_reset.v", VERILOG)

    def test_dlatch_reset(self):
        self.parseWithRef("dlatch_reset.v", VERILOG)

    def test_fifo_rx(self):
        f, res = parseFile("fifo_rx.v", VERILOG)
        f = self.find_obj_by_name(res, HdlModuleDec, "fifo_rx")
        self.assertEqual(len(f.params), 2)
        self.assertEqual(len(f.ports), 11)
        str(res)

    def test_include(self):
        f, res = parseFile("include.v", VERILOG)
        str(res)
        self.check_obj_names(res, HdlModuleDec, ["arbiter", "uart"])

    def test_lfsr_updown_tb(self):
        self.parseWithRef("lfsr_updown_tb.v", VERILOG)

    def test_macro(self):
        self.parseWithRef("macro.v", VERILOG)

    def test_parity_using_function2(self):
        self.parseWithRef("parity_using_function2.v", VERILOG)

    def test_pri_encoder_using_assign(self):
        self.parseWithRef("pri_encoder_using_assign.v", VERILOG)

    def test_pri_encoder_using_if(self):
        self.parseWithRef("pri_encoder_using_if.v", VERILOG)

    def test_ram_sp_ar_sw(self):
        self.parseWithRef("ram_sp_ar_sw.v", VERILOG)

    def test_ram_sp_sr_sw(self):
        self.parseWithRef("ram_sp_sr_sw.v", VERILOG)

    def test_rom_using_file(self):
        self.parseWithRef("rom_using_file.v", VERILOG)

    def test_uart(self):
        self.parseWithRef("uart.v", VERILOG)

    def test_multiple_files_at_once(self):
        language = VERILOG
        f = [path.join(TEST_DIR, "verilog", f)
             for f in ["fifo_rx.v", "define.v", "arbiter.v", "uart.v"]]
        inc_dir = path.join(TEST_DIR, "verilog")
        c = HdlConvertor()
        res = c.parse(f, language, [inc_dir], debug=True)
        e = [o for o in res.objs if isinstance(o, HdlModuleDef)]
        self.assertSetEqual(set(_e.module_name for _e in e),
                            {'fifo_rx', 'test', 'arbiter', 'uart'})
        str(res)

    def test_system_verilog_mem_base_object(self):
        f, res = parseFile("mem_base_object.sv", SV)
        str(res)

    def test_crc_functions(self):
        f, res = parseFile("crc_functions.sv", SV)
        str(res)

    def test_operator_type(self):
        self.parseWithRef("operator_type.sv", SV)


if __name__ == "__main__":
    suite = unittest.TestSuite()
    suite.addTest(VerilogConversionTC('test_operator_type'))
    # suite.addTest(unittest.makeSuite(VerilogConversionTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
