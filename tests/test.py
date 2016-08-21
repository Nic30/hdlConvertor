import sys
from os import path
from  pprint import pprint

BASE_DIR = path.join(path.dirname(__file__), "..")
sys.path.insert(1, path.join(BASE_DIR, "build/lib.linux-x86_64-3.5")) 

import hdlConvertor

f = path.join(BASE_DIR, "tests/mux.vhd")
res = hdlConvertor.parse(f, "vhdl", debug=True)
pprint(res)

f = path.join(BASE_DIR, "tests/uart.v")
res = hdlConvertor.parse(f, "verilog", debug=True)
pprint(res)

f = path.join(BASE_DIR, "tests/mem_base_object.sv")
res = hdlConvertor.parse(f, "system_verilog", debug=True)
pprint(res)
