import sys
from os import path
from  pprint import pprint

BASE_DIR = path.join(path.dirname(__file__), "..")
sys.path.append(path.join(BASE_DIR, "build/lib.linux-x86_64-3.5")) 

import hdlConvertor
f = path.join(BASE_DIR, "tests/uart.v")
print(f)
res =  hdlConvertor.parse(f, "verilog", debug=True)

pprint(res)
