import sys
from os import path
from pprint import pprint
import unittest

BASE_DIR = path.join(path.dirname(__file__), "..")
sys.path.insert(1, path.join(BASE_DIR, "build/lib.linux-x86_64-%d.%d"
                             % (sys.version_info.major, sys.version_info.minor)))

import hdlConvertor


def dumpFile(fname, language):
    f = path.join(BASE_DIR, "tests/", fname)
    res = hdlConvertor.parse(f, language, debug=True)
    return f, res


class BasicTC(unittest.TestCase):
    def test_vhld_dump_mux(self):
        f, res = dumpFile("mux.vhd", "vhdl")
        str(res)

    def test_vhdl_package_example(self):
        f, res = dumpFile("package_example.vhd", "vhdl")
        str(res)

    def test_vhdl_stcu_integr_pkg(self):
        f, res = dumpFile("stcu_integr_pkg.vhd", "vhdl")
        str(res)

    def test_verilog_uart(self):
        f, res = dumpFile("uart.v", "verilog")
        str(res)

    def test_system_verilog_mem_base_object(self):
        f, res = dumpFile("mem_base_object.sv",  "system_verilog")
        str(res)


if __name__ == "__main__":
    for i in range(3):
        parseAndPrint(printNow=not (i % 2))

    # for fname in system_verilog_files:
    #    dumpFile(fname,  "system_verilog")
