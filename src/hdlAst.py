from enum import Enum
from typing import Dict, Union, Tuple, Optional

"""
This module contains the containers for Hardware Description Language Abstract Syntax Tree (HDL AST)

(System) Verilog/VHDL can be converted by this format and back using this library
Main container is HdlContext which can store all other objects.

:note: this module is using PEP484 type hints, and the typehints are in comments
    to sustain Python 2.7 compatibility
:attention: this module is just simple format of HDL and does not performs all check,
    e.g. you can use a string as a type of the port, but such a module can not be synthetised
"""


class HdlDirection(Enum):
    IN = "IN"
    INOUT = "INOUT"
    OUT = "OUT"


class NameId(int):
    """
    Reference to name string in name table
    """


class HdlAll():
    """
    Constant which corresponds to VHDL "all" keyword or "*" in verilog sensitivitylist
    """


class HdlTypeType():
    """
    Type which means that the object is type of type
    """


HdlTypeInt = int
HdlTypeStr = str
HdlTypeFloat = float
HdlTypeEnum = Enum


# arrays are described as HdlCall(HdlBuildinFn.INDEX, (type, array size))
# [TODO] HdlTypeStruct/Union
class HdlTypeBits():

    def __init__(self, MSB, lsb=0, signed=False):
        self.msb = msb
        self.lsb = lsb
        self.signed = signed

    def __hash__(self):
        return hash((self.msb, self.lsb, self.signed))

    def __eq__(self, other):
        return isinstance(other, HdlTypeBits) and (
            self.msb == other.msb
            and self.lsb == other.lsb
            and self.signed == other.signed)


class HdlTypeAuto():
    """
    Type which means that the type is automatically resolved from the type of the value
    """


class iHdlObj():
    """
    Object with direct represenation in HDL

    :ivar doc: doc from the HDL related probably to this object
    """

    def __init__(self):
        self.doc: str = ""


iHdlExpr = Union[NameId, int, float, string, None, List["iHdlExpr"], HdlAll, "HdlCall"]


class HdlBuildinFn(Enum):
    (INDEX,  # array index
    SLICE,  # (start, stop, step) for "downto" operator step = -1 for "to" operator step = 1
    SUB,  # can also be unary minus
    ADD,  # can also be unary plus
    DIV,
    MUL,
    MOD,  # modulo operator
    REM,  # remainder operator
    CONCAT,  # concatenation of signals
    REPL_CONCAT,  # replicative concatenation {<N>, <item>} duplicates and concatenates the item N times
    POW,  # bin operator power of
    ABS,  # absolute value
    NOT,  # logical negation
    NEG,  # bitwise negation
    LOG_AND,
    LOG_OR,
    AND,
    OR,
    NAND,
    NOR,
    XOR,
    XNOR,
    EQ,  # ==
    NEQ,  # ~
    LOWERTHAN,  # <
    LE,  # <=
    GREATERTHAN,  # >
    GE,  # >=
    SLL,  # shift left logical
    SRL,  # shift right logical
    SLA,  # shift left arithmetical
    SRA,  # shift right arithmetical
    ROL,  # rotate left
    ROR,  # rotate right
    TERNARY,
    DOT,
    CALL,
    ARROW,  # arrow operator used in vhdl type descriptions
    RISING,  # rising edge/posedge event operator
    FALLING,  # falling edge/negedge event operator
    MAP_ASSOCIATION,) = range(41)
    # note that in verilog bitewise operators can have only one argument


class HdlCall():

    def __init__(self):
        self.fn = None  # type: Union[HdlBuildinFn, iHdlExpr]
        self.ops = []  # type: List[iHdlExpr]


class iHdlObjWithName(iHdlObj):
    """
    :ivar name: reference to name of the object
    """

    def __init__(self):
        super(iHdlObjWithName, self).__init__()
        self.name = None  # type: NameId


class iInModuleHdlObj():
    """
    Object which can apear in the module body
    """


class HdlImport(iHdlObj):
    """
    The import statements used in VHDL

    :note: note that this does not corresponds to include as include is processed by preprocessor
    :ivar path: the list of namemes which are in the import
    :ivar wildcard: flag if true all objects from specified namespace should be imported
    """

    def __init__(self):
        self.path = []  # type: List[str]
        self.wildcard = False  # type: bool


class HdlVariableDef(iHdlObj, iInModuleHdlObj):

    def __init__(self):
        iHdlObj.__init__(self)
        iInModuleHdlObj.__init__(self)
        self.type = None  # type: HdlType
        self.value = None  # iHdlExpr
        self.latched = False  # type: bool


class HdlPortDef(HdlVariableDef):

    def __init__(self):
        super(HdlPortDef, self).__init__()
        self.dir = None  # type: HdlDirection


class HdlNamespace(iHdlObjWithName):
    """
    Corresponds to VHDL package/package body or System Verilog namespace
    """

    def __init__(self):
        super(HdlNamespace, self).__init__()
        self.objs = []  # type: List[iHdlObj]


class HdlModuleDec(HdlNamespace):
    """
    HDL Module declaration

    Corresponds to VHDL entity and the first first part of the module with the ports and parameters
    """

    def __init__(self):
        super(HdlModuleDec, self).__init__()
        self.params = []  # type: List[HdlVariableDef]
        self.ports = []  # type: List[HdlPortDef]


class HdlModuleDef(iHdlObjWithName):
    """
    :ivar name: name of the architecture in VHDL or name of module in Verilog
    :ivar module_name: the name of entity in VHDL or same as name in Verilog
    """

    def __init__(self):
        super(HdlModuleDef, self).__init__()
        self.module_name = None  # type: NameId
        self.objs = []  # type: List[Union[iHdlObj, iInModuleHdlObj]]


class HdlComponentInst(iHdlObjWithName, iInModuleHdlObj):
    """
    HDL Component insance

    :ivar name: name of this component instance in this module
    :ivar module_name: HdlId or iHdlExpr made from HdlIds and dot operators
    :ivar param_map: same as port_map just port parameters of the component
    :ivar port_map: the list of iHdlExpr with map operator for map assignment or any other iHdlExpr for positional mapping
    """

    def __init__(self):
        iHdlObjWithName.__init__(self)
        iInModuleHdlObj.__init__(self)
        self.module_name = None  # type: iHdlExpr
        self.param_map = []  # type: List[iHdlExpr]
        self.port_map = []  # type: List[iHdlExpr]


class iHdlStatement(iHdlObj, iInModuleHdlObj):

    def __init__(self):
        iHdlObj.__init__(self)
        iInModuleHdlObj.__init__(self)


class HdlStatementBlock(iHdlStatement, list):
    """
    Block of statements in HDL
    List[Union[iHdlExpr, iHdlStatement, HdlVariableDef, iHdlTypeDef]]
    """

    def __init__(self):
        super(HdlStatementBlock, self).__init__()


class HdlAssignStm(iHdlStatement):
    """
    HDL assignment (blocking/non blocking is resolved from type of the variable)
    """

    def __init__(self):
        super(HdlAssignStm, self).__init__(iHdlStatement)
        self.src = None  # type: iHdlExpr
        self.dst = None  # type: iHdlExpr


class HdlIfStm(iHdlStatement):
    """
    HDL if statement
    """

    def __init__(self):
        super(HdlIfStm, self).__init__()
        self.cond = None  # type: iHdlExpr
        self.if_true = HdlStatementBlock()  # type: HdlStatementBlock
        self.elifs = []  # type: List[Tuple[iHdlExpr, HdlStatementBlock]]
        self.if_false = None  # type: Optional[HdlStatementBlock]


class HdlProcessStm(HdlStatementBlock, iHdlObjWithName):

    def __init__(self):
        HdlStatementBlock.__init__(self)
        iHdlObjWithName.__init__(self)
        self.sensitivity = None  # type: Optional[iHdlExpr]


class HdlCaseStm(iHdlStatement):
    """
    HDL case statement
    """

    def __init__(self):
        super(iHdlStatement, self).__init__()
        self.swith_on = None  # type: iHdlExpr
        self.cases = []  # type: List[Tuple[iHdlExpr, HdlStatementBlock]]
        self.default = None  # type: Optional[Tuple[iHdlExpr, HdlStatementBlock]]


class HdlReturnStm(iHdlStatement):
    """
    HDL return statement
    """

    def __init__(self):
        super(iHdlStatement, self).__init__()
        self.val = None  # type: iHdlExpr


class HdlContext():
    """
    The container of the objects specified in HDL files

    :ivar names: the dictionary mapping the name id to it's string
    :ivar objs: the list of the object from the HDL files
    """

    def __init__(self):
        self.names = {}  # type: Dict[int, str]
        self.objs = []  # type: List[iHdlObj]
