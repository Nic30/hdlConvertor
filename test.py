import sys
from  pprint import pprint
sys.path.append("build/lib.linux-x86_64-3.5") 

import hdlConvertor
f = "uart.v"
res =  hdlConvertor.parse(f, "verilog", debug=True)

pprint(res)
