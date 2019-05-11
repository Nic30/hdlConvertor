from ._hdlConvertor import Language as __Language
from enum import Enum

class Language(Enum):
    VHDL_2002 = "vhdl2002"
    VHDL_2008 = "vhdl2008"
    VHDL = __Language.VDHL # default vhdl version
    
    VERILOG_2001 = "verilog2001"
    VERILOG = __Language.VERILOG # default verilog version
    
    SYSTEM_VERILOG_2012 = "sv2012"
    SYSTEM_VERILOG = __Language.SYSTEM_VERILOG # default verilog version
