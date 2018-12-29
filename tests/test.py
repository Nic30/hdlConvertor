import sys
from os import path
from pprint import pprint
import unittest

BASE_DIR = path.join(path.dirname(__file__), "..")
sys.path.insert(1, path.join(BASE_DIR, "dist"))

import hdlConvertor


def dumpFile(fname, language):
    f = path.join(BASE_DIR, "tests/", fname)
    res = hdlConvertor.parse(f, language, debug=True)
    return f, res


class BasicTC(unittest.TestCase):
    def test_vhld_dump_mux(self):
        f, res = dumpFile("mux.vhd", "vhdl")
        str(res)

    def test_vhdl_package_array_const(self):
        f, res = dumpFile("package_array_const.vhd", "vhdl")
        str(res)

    def test_vhdl_package_component(self):
        f, res = dumpFile("package_component.vhd", "vhdl")
        str(res)

    def test_vhdl_package_constants(self):
        f, res = dumpFile("package_constants.vhd", "vhdl")
        str(res)

    def test_verilog_uart(self):
        f, res = dumpFile("uart.v", "verilog")
        str(res)

#    def test_system_verilog_mem_base_object(self):
#        f, res = dumpFile("mem_base_object.sv",  "systemVerilog")
#        str(res)


if __name__ == "__main__":
    suite = unittest.TestSuite()
    # suite.addTest(BasicTC('test_read'))
    suite.addTest(unittest.makeSuite(BasicTC))

    runner = unittest.TextTestRunner(verbosity=3)
    runner.run(suite)
