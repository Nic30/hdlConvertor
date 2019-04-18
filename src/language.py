
from enum import Enum

class Language(Enum):
    VHDL_2002 = "vhdl2002"
    VHDL_2008 = "vhdl2008"
    VHDL = VHDL_2002 # default vhdl version
    
    VERILOG_2001 = "verilog2001"
    VERILOG = VERILOG_2001 # default verilog version
    
    SYSTEM_VERILOG_2012 = "sv2012"
    SYSTEM_VERILOG = SYSTEM_VERILOG_2012 # default verilog version
