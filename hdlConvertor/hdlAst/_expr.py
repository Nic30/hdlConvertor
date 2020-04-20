from enum import Enum
from typing import Optional, Union, List

from hdlConvertor.hdlAst._bases import iHdlObj
from hdlConvertor.py_ver_compatibility import is_str


class HdlDirection(Enum):
    """
    Direction of the interface
    """
    (
        IN,
        OUT,
        INOUT,
        BUFFER,
        LINKAGE,
        INTERNAL,
        UNKNOWN
    ) = range(7)


class HdlName(object):
    """
    String which is id in HDL

    :type ~.val: str
    :ivar ~.obj: an object which corresponds to this name
        (has to be explicitly discovered and is not available imediately
        after parsing)
    """

    def __init__(self, val, obj=None):
        assert is_str(val, str), val
        self.val = val
        self.obj = obj

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.val == other.val

    def __lt__(self, other):
        if not isinstance(other, HdlName):
            return False
        return self.val < other.val

    def __hash__(self):
        return hash(self.val)

    def __str__(self):
        return self.val

    def __repr__(self):
        return "<%s %s>" % (self.__class__.__name__, self.val)


class HdlAll(object):
    """
    Constant which corresponds to VHDL "all" keyword
    or "*" in Verilog sensitivity list
    """
    __slots__ = []

    def __init__(self):
        raise ValueError("This class (%r) is not supposed to be instantiated "
                         "and should be used as a constant instead"
                         % self.__class__)


class HdlOthers(object):
    """
    Constant which corresponds to VHDL "others" keyword
    """
    __slots__ = []

    def __init__(self):
        raise ValueError("This class (%r) is not supposed to be instantiated"
                         % self.__class__)


class HdlTypeType(object):
    """
    Type which means that the object is type of type
    """
    __slots__ = []

    def __init__(self):
        raise ValueError("This class (%r) is not supposed to be instantiated"
                         % self.__class__)


class HdlTypeAuto(object):
    """
    Type which means that the type is automatically resolved
    from the type of the value
    """
    __slots__ = []

    def __init__(self):
        raise ValueError("This class (%r) is not supposed to be instantiated"
                         % self.__class__)


class HdlBuiltinFn(Enum):
    """
    The build in functions and operators in HDL languages.
    (Python equivalent of c++ hdlConvertor::hdlObjects::HdlOperatorType)
    """
    (
        RANGE,  # range used in VHDL type specifications
        RANGE_REVERSE,  # reverse range used in VHDL type specifications
        ACROSS,
        THROUGH,
        REFERENCE,
        TOLERANCE,
        TYPE_OF,  # SV type operator
        INDEX,  # array index
        DOWNTO,  # downto for the slice specification
        TO,  # to for the slice specification
        MINUS_UNARY,
        PLUS_UNARY,
        OR_UNARY,  # SV or reduction (|a)
        AND_UNARY,  # SV and reduction (&a)
        NAND_UNARY,  # SV nand reduction (~&a)
        NOR_UNARY,  # SV nor reduction (~|a)
        XOR_UNARY,  # SV xor reduction (^a)
        XNOR_UNARY,  # SV and reduction (~^a) or (^~a)
        SUB,
        ADD,
        DIV,
        MUL,
        MOD,  # modulo
        REM,  # reminder
        CONCAT,  # concatenation of signals
        REPL_CONCAT,  # replicative concatenation {<N>, <item>}
                 # duplicates and concatenates the item N times
        POW,  # power of
        ABS,  # absolute value
        NEG_LOG,  # logical negation "not" in vhdl
        NEG,  # bitwise negation
        AND_LOG,  # "and" in vhdl
        OR_LOG,  # "or" in vhdl
        AND,  # & in vhdl
        OR,  # | in vhdl
        NAND,
        NOR,
        XOR,
        XNOR,
        EQ,  # ==
        NEQ,  # ~
        LT,  # <
        LE,   # <=
        GT,  # >
        GE,  # >=
        SLL,  # shift left logical
        SRL,  # shift right logical
        SLA,  # shift left arithmetical
        SRA,  # shift right arithmetical
        ROL,  # rotate left
        ROR,  # rotate right
        TERNARY,
        DOT,  # accessing of property
        DOUBLE_COLON,  # SV accessing class/package static property/type
        APOSTROPHE,  # vhdl attribute access
        CALL,  # call of HDL function
        PARAMETRIZATION,  # specification of template arguments
        ARROW,  # arrow operator used in vhdl type descriptions
        RISING,  # rising edge/posedge event operator
        FALLING,  # falling edge/negedge event operator
        MAP_ASSOCIATION,
        # VHDL-2008 matching ops (the X values are ignored while match)
        EQ_MATCH,
        NEQ_MATCH,
        LT_MATCH,
        LE_MATCH,
        GT_MATCH,
        GE_MATCH,
        INCR_PRE,
        DECR_PRE,
        INCR_POST,
        DECR_POST,
        ASSIGN,
        PLUS_ASSIGN,  # +=
        MINUS_ASSIGN,  # -=
        MUL_ASSIGN,  # *=
        DIV_ASSIGN,  # /=
        MOD_ASSIGN,  # %=
        AND_ASSIGN,  # &=
        OR_ASSIGN,  # |=
        XOR_ASSIGN,  # ^=
        SHIFT_LEFT_ASSIGN,  # <<=
        SHIFT_RIGHT_ASSIGN,  # >>=
        ARITH_SHIFT_LEFT_ASSIGN,  # <<<=
        ARITH_SHIFT_RIGHT_ASSIGN,  # >>>=
    ) = range(83)
    # note that in verilog bitewise operators can have only one argument


class HdlCall(iHdlObj):
    """
    Container for call of the HDL function in HDL code
    """
    __slots__ = ["fn", "ops"]

    def __init__(self, fn, ops):
        """
        :type fn: Union[HdlBuiltinFn, iHdlExpr]
        :type ops: List[iHdlExpr]
        """
        self.fn = fn
        self.ops = ops

    def __lt__(self, other):
        if isinstance(other, HdlName):
            return True
        else:
            return (self.fn.value, self.ops) < (other.fn.value, other.ops)

    def __eq__(self, other):
        if not isinstance(other, HdlCall):
            return False
        else:
            return self.fn == other.fn and self.ops == other.ops


class HdlIntValue(iHdlObj):
    """
    Object for representation of int value in in HDL
    (= also for the bitstrings)

    :ivar ~.val: int value or bitstring string
    :ivar ~.bits: number of bits if specified
    :ivar ~.base: base for bitstring
    """
    __slots__ = ["val", "bits", "base"]

    def __init__(self, val, bits, base):
        self.val = val  # type: Union[int, str]
        self.bits = bits  # type: Optional[int]
        self.base = base  # type: Optional[Union[2, 8, 10, 16, 256]]

    def __int__(self):
        return int(self.val)

    def __bool__(self):
        return bool(self.val)

    def __hash__(self):
        return hash((self.val, self.bits, self.base))

    def __lt__(self, other):
        return (self.val, self.bits, self.base) < (other.val, other.bits, other.base)

    def __nonzero__(self):
        return self.__bool__()

    def __eq__(self, other):
        if isinstance(other, HdlIntValue):
            return (self.val == other.val
                    and self.bits == other.bits
                    and self.base == other.base)
        else:
            try:
                return self.val == other
            except Exception:
                return False
            except ValueError:
                return False


# None is equivalent of HDL null
iHdlExpr = Union[HdlName, HdlIntValue, float, str,
                 None, List["iHdlExpr"], HdlAll, HdlCall]
