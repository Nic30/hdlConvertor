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
    return f, res


def parseAndPrint(printNow=True):
    if not printNow:
        data = []
    for fname in vhdl_files:
        d = dumpFile(fname, "vhdl")
        if printNow:
            f, res = d
            print(f)
            pprint(res)
        else:
            data.append(d)

    for fname in verilog_files:
        d = dumpFile(fname,  "verilog")
        if printNow:
            f, res = d
            print(f)
            pprint(res)
        else:
            data.append(d)

    if not printNow:
        for f, res in data:
            print(f)
            pprint(res)


if __name__ == "__main__":
    for i in range(3):
        parseAndPrint(printNow=not (i % 2))

    # for fname in system_verilog_files:
    #    dumpFile(fname,  "system_verilog")
