from enum import Enum


# [TODO] use full names of standard like 1800_2012
#   because there are modifications and extensions which differs
#   in first number but they have same second number
#   (e.g. 1800-2017 vs 1802-2017)
class Language(Enum):
    VHDL_2002 = "vhdl2002"
    VHDL_2008 = "vhdl2008"
    VHDL = "vhdl"  # default vhdl version

    VERILOG_2001 = "verilog2001"
    VERILOG_2005 = "verilog2005"
    VERILOG = "verilog"  # default verilog version

    SYSTEM_VERILOG_2012 = "sv2012"
    SYSTEM_VERILOG_2017 = "sv2017"
    SYSTEM_VERILOG = "systemVerilog"  # default verilog version
