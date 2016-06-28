import sys
from  pprint import pprint
sys.path.append("build/lib.linux-x86_64-3.5") 

import hdlConvertor
f = "../../samples/iLvl/vhdl/dualportRAM.vhd"
res =  hdlConvertor.parse(f, "vhdl", debug=True)

pprint(res)