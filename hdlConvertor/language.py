from enum import Enum


# [TODO] use full names of standard like 1800_2012
#   because there are modifications and extensions which differs
#   in first number but they have same second number
#   (e.g. 1800-2017 vs 1802-2017)
class Language(Enum):
    VHDL_2002 = "vhdl2002"
    VHDL_2008 = "vhdl2008"
    VHDL = VHDL_2008  # default vhdl version

    VERILOG_2001 = "verilog2001"
    VERILOG_2005 = "verilog2005"
    VERILOG = VERILOG_2001  # default verilog version

    SYSTEM_VERILOG_2012 = "sv2012"
    SYSTEM_VERILOG_2017 = "sv2017"
    SYSTEM_VERILOG = SYSTEM_VERILOG_2017  # default verilog version

    def is_vhdl(self):
        return self in [Language.VHDL_2002,
                        Language.VHDL_2008]

    def is_verilog(self):
        return self in [Language.VERILOG_2001,
                        Language.VERILOG_2005]

    def is_system_verilog(self):
        return self in [Language.SYSTEM_VERILOG_2012,
                        Language.SYSTEM_VERILOG_2017]
