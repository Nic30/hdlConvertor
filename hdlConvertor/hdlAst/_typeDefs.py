from enum import Enum
from typing import Dict, Union, Tuple, List
from hdlConvertor.hdlAst._bases import iHdlObjWithName

HdlTypeInt = int
HdlTypeStr = str
# Verilog real
HdlTypeFloat = float
HdlTypeEnum = Enum


# arrays are described as HdlCall(HdlBuiltinFn.INDEX, (type, array size))
class HdlTypeBitsDef(iHdlObjWithName):
    """
    The type which represents bit or bit vector in HDL (std_logic/_vector
    in VHDL, [0:8] in Verilog )

    :ivar states: 2 means that each bit can be 0 or 1
        4 - (0, 1, X, Z) (e.g. Verilog wire)
        9 - (0, 1, X, Z, U, W, L, H, -) (e.g. VHDL std_logic)
            'U': uninitialized. This signal hasn't been set yet.
            'X': unknown. Impossible to determine this value/result.
            '0': logic 0
            '1': logic 1
            'Z': High Impedance
            'W': Weak signal, can't tell if it should be 0 or 1.
            'L': Weak signal that should probably go to 0
            'H': Weak signal that should probably go to 1
            '-': Don't care.
    :note: in new you should let lsb=0, it is there only for legacy issues
    """
    STD_LOGIC_STATES = 9
    WIRE_STATES = 4
    __slots__ = ["name", "msb", "lsb", "signed", "is_bigendian", "states"]

    def __init__(self, msb, lsb=0, signed=False):
        super(HdlTypeBitsDef, self).__init__()
        self.msb = msb  # type: int
        self.lsb = lsb  # type: int
        self.signed = signed  # type: bool
        self.is_bigendian = False  # type: bool
        self.states = 2

    def width(self):
        if self.msb >= self.lsb:
            return self.msb - self.lsb
        else:
            return self.lsb - self.msb

    def __hash__(self):
        return hash((self.msb, self.lsb, self.signed, self.is_bigendian))

    def __eq__(self, other):
        return isinstance(other, HdlTypeBitsDef) and (
            self.msb == other.msb
            and self.lsb == other.lsb
            and self.signed == other.signed
            and self.is_bigendian == other.is_bigendian)


class HdlClassDef(iHdlObjWithName):
    """
    Definition of SystemVerilog class/struct/interface or VHDL record

    :note: name may be None

    """
    __slots__ = ["name", "parents", "is_virtual", "is_static",
                 "is_struct", "is_union", "is_interface",
                 "private", "public", "protected"]

    def __init__(self):
        super(HdlClassDef, self).__init__()
        self.parents = []  # type: List[iHdlExpr]
        self.is_virtual = False  # type: bool
        self.is_static = False  # type: bool
        self.is_struct = False  # type: bool
        self.is_union = False  # type: bool
        self.private = []  # type: List[iHdlObj]
        self.public = []  # type: List[iHdlObj]
        self.protected = []  # type: List[iHdlObj]


class HdlEnumDef(iHdlObjWithName):
    """
    Definition of VHDL Enumeration Type or SystemVerilog enum

    :note: name may be None
    """
    __slots__ = ["name", "values"]

    def __init__(self):
        super(HdlEnumDef, self).__init__()
        self.values = []  # type: List[Union[str, Tuple[str, int]]]
