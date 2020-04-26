from enum import Enum


# [TODO] use full names of standard like 1800_2012
#   because there are modifications and extensions which differs
#   in first number but they have same second number
#   (e.g. 1800-2017 vs 1802-2017)
class Language(Enum):
    VHDL_2002 = "vhdl2002"
    VHDL_2008 = "vhdl2008"
    VHDL = VHDL_2008  # default vhdl version

    VERILOG_1995 = "verilog1995"  # ieee1364_1995
    VERILOG_2001 = "verilog2001"  # ieee1364_2001
    VERILOG_2001_NOCONFIG = "verilog2001_noconfig"  # ieee1364_2001-noconfig
    VERILOG_2005 = "verilog2005"  # ieee1364_2001
    VERILOG = VERILOG_2001  # default verilog version

    SYSTEM_VERILOG_2005 = "sv2005"  # ieee1800_2005
    SYSTEM_VERILOG_2009 = "sv2009"  # ieee1800_2009
    SYSTEM_VERILOG_2012 = "sv2012"  # ieee1800_2012
    SYSTEM_VERILOG_2017 = "sv2017"  # ieee1800_2017
    SYSTEM_VERILOG = SYSTEM_VERILOG_2017  # default verilog version

    # json produced by hdlConvertor.to.json.ToJson
    HDLCONVERTOR_JSON = "hdlConvertor_JSON"

    def is_vhdl(self):
        return self in [Language.VHDL_2002,
                        Language.VHDL_2008]

    def is_verilog(self):
        return self in (
            Language.VERILOG_1995,
            Language.VERILOG_2001,
            Language.VERILOG_2001_NOCONFIG,
            Language.VERILOG_2005
        )

    def is_system_verilog(self):
        return self in (
            Language.SYSTEM_VERILOG_2005,
            Language.SYSTEM_VERILOG_2009,
            Language.SYSTEM_VERILOG_2012,
            Language.SYSTEM_VERILOG_2017
        )
