import sys
from os import path
from pprint import pprint

BASE_DIR = path.join(path.dirname(__file__), "..")
sys.path.insert(1, path.join(BASE_DIR, "build/lib.linux-x86_64-%d.%d"
                             % (sys.version_info.major, sys.version_info.minor)))

import hdlConvertor

vhdl_files = ["mux.vhd",
              "package_example.vhd",
              "stcu_integr_pkg.vhd"]
verilog_files = ["uart.v"]
system_verilog_files = ["mem_base_object.sv"]


def dumpFile(fname, language):
    f = path.join(BASE_DIR, "tests/", fname)
    res = hdlConvertor.parse(f, language, debug=True)
    print(f)
    pprint(res)


if __name__ == "__main__":
    for fname in vhdl_files:
        dumpFile(fname, "vhdl")

    for fname in verilog_files:
        dumpFile(fname,  "verilog")

    # for fname in system_verilog_files:
    #    dumpFile(fname,  "system_verilog")
