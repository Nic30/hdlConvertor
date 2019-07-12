from enum import Enum
from typing import Dict, Union, Tuple, Optional, List

"""
This module contains the containers
for Hardware Description Language Abstract Syntax Tree (HDL AST)

(System) Verilog/VHDL can be converted by this format and back using this library
Main container is HdlContext which can store all other objects.

:note: this module is using PEP484 type hints, and the type hints are in comments
    to sustain Python 2.7 compatibility
:attention: this module is just simple format of HDL and does not performs all check,
    e.g. you can use a string as a type of the port,
    but such a module generally can not be synthetised to a hardware

:attention: classes in his module are used from C++
"""


class CodePosition(object):
    __slots__ = ["startLine", "stopLine", "startColumn", "stopColumn"]

    def __init__(self, startLine, stopLine, startColumn, stopColumn):
        self.startLine = startLine  # type: int
        self.stopLine = stopLine  # type: int
        self.startColumn = startColumn  # type: int
        self.stopColumn = stopColumn  # type: int


class HdlDirection(Enum):
    (IN,
    OUT,
    INOUT,
    BUFFER,
    LINKAGE,
    INTERNAL,
    UNKNOWN) = range(7)


class HdlName(str):
    """
    Reference to name string in name table
    """
    __slots__ = []


class HdlAll(object):
    """
    Constant which corresponds to VHDL "all" keyword
    or "*" in Verilog sensitivity list
    """
    __slots__ = []


class HdlOthers(object):
    """
    Constant which corresponds to VHDL "others" keyword
    """
    __slots__ = []


class HdlTypeType(object):
    """
    Type which means that the object is type of type
    """
    __slots__ = []


HdlTypeInt = int
HdlTypeStr = str
# Verilog real
HdlTypeFloat = float
HdlTypeEnum = Enum


# arrays are described as HdlCall(HdlBuildinFn.INDEX, (type, array size))
# [TODO] HdlTypeStruct/Union
class HdlTypeBits(object):
    """
    The type which represents bit or bit vector in HDL (std_logic/_vector
    in VHDL [0:8] in Verilog)

    :note: you should let lsb=0, it is there only for legacy issues
    """
    __slots__ = ["msb", "lsb", "signed"]

    def __init__(self, msb, lsb=0, signed=False):
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


class HdlTypeAuto(object):
    """
    Type which means that the type is automatically resolved
    from the type of the value
    """
    __slots__ = []


class iHdlObj(object):
    """
    Object with direct representation in HDL

    :ivar doc: doc from the HDL related probably to this object
    """
    __slots__ = ["doc"]

    def __init__(self):
        self.doc = ""  # type: str


class HdlIntValue(object):
    """
    Object for representation of int value in in HDL (= also for the bitstrings)

    :ivar val: int value or bitstring string
    :ivar bits: number of bits if specified
    :ivar base: base for bitstring
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

    def __nonzero__(self):
        return self.__bool__()


# None is equivalent of HDL null
iHdlExpr = Union[HdlName, HdlIntValue, float, str,
                 None, List["iHdlExpr"], HdlAll, "HdlCall"]


class HdlBuildinFn(Enum):
    """
    The build in functions and operators in HDL languages
    """
    (
    RANGE,  # range used in VHDL type specifications
    REVERSE_RANGE,
    ACROSS,
    THROUGH,
    REFERENCE,
    TOLERANCE,
    INDEX,  # array index
    DOWNTO,  # downto for the slice specification
    TO,  # to for the slice specification
    SUB,  # can also be unary minus
    ADD,  # can also be unary plus
    DIV,
    MUL,
    MOD,
    REM,
    CONCAT,  # concatenation of signals
    REPL_CONCAT,  # replicative concatenation {<N>, <item>} duplicates and concatenates the item N times
    POW,  # bin operator power of
    ABS,  # absolute value
    NOT,
    NEG,  # negation
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
    LT,  # <
    LE,  # <=
    GT,  # >
    GE,  # >=
    SLL,  # shift left logical
    SRL,  # shift right logical
    SLA,  # shift left arithmetical
    SRA,  # shift right arithmetical
    ROL,  # rotate left
    ROR,  # rotate right
    TERNARY,
    DOT,
    APOSTROPHE,  # vhdl attribute access
    CALL,
    ARROW,  # arrow operator used in vhdl type descriptions
    RISING,  # rising edge/posedge event operator
    FALLING,  # falling edge/negedge event operator
    MAP_ASSOCIATION,
    MATCH_EQ,  # VHDL-2008 matching ops (the X values are ignored while match)
    MATCH_NEQ,
    MATCH_LT,
    MATCH_LE,
    MATCH_GT,
    MATCH_GE,
    ) = range(55)
    # note that in verilog bitewise operators can have only one argument


class HdlCall(object):
    """
    Container for call of the HDL function in HDL code
    """
    __slots__ = ["fn", "ops"]

    def __init__(self):
        self.fn = None  # type: Union[HdlBuildinFn, iHdlExpr]
        self.ops = []  # type: List[iHdlExpr]


class iHdlObjWithName(iHdlObj):
    """
    :ivar name: reference to name of the object
    """
    __slots__ = ["name"]

    def __init__(self):
        super(iHdlObjWithName, self).__init__()
        self.name = None  # type: HdlName


class iInModuleHdlObj(object):
    """
    Object which can appear in the module body
    """
    __slots__ = []


class HdlVariableDef(iHdlObj, iInModuleHdlObj):
    """
    Definition of port/param/type etc in HDL

    :ivar name: name of newly defined object
    :ivar type: type of the defined variable (or type etc.)
    :ivar value: initialisation of variable (typedef etc.)
    :ivar is_latched: flag if true the object corresponds to VHDL variable/Verilog reg
    :ivar is_const: flag if true the value is constants
    :ivar direction: direction if the variable is port
    """
    __slots__ = ["name", "type", "value", "is_latched", "is_const", "direction"]

    def __init__(self):
        iHdlObj.__init__(self)
        iInModuleHdlObj.__init__(self)
        self.name = None  # type HdlName
        self.type = None  # type: HdlType
        self.value = None  # iHdlExpr
        self.is_latched = False  # type: bool
        self.is_const = False  # type: bool
        self.direction = None  # type: HdlDirection


class HdlNamespace(iHdlObjWithName):
    """
    Corresponds to VHDL package/package body or System Verilog namespace
    """
    __slots__ = ["objs", "declaration_only"]

    def __init__(self):
        super(HdlNamespace, self).__init__()
        self.declaration_only = False  # type: bool
        self.objs = []  # type: List[iHdlObj]


class HdlModuleDec(HdlNamespace):
    """
    HDL Module declaration
    (ports, params header of module in Verilog/ VHDL Entity)

    Corresponds to VHDL entity and the first first part of the module with the ports and parameters
    """
    __slots__ = ["params", "ports", "objs"]

    def __init__(self):
        super(HdlModuleDec, self).__init__()
        self.params = []  # type: List[HdlVariableDef]
        self.ports = []  # type: List[HdlVariableDef]


class HdlModuleDef(iHdlObjWithName):
    """
    HDL module definition (body of module in Verilog/vhdl architecture)

    :ivar name: name of the architecture in VHDL or name of module in Verilog
    :ivar module_name: the name of entity in VHDL or same as name in Verilog
    """
    __slots__ = ["module_name", "objs"]

    def __init__(self):
        super(HdlModuleDef, self).__init__()
        self.module_name = None  # type: HdlName
        self.objs = []  # type: List[Union[iHdlObj, iInModuleHdlObj]]


class HdlComponentInst(iHdlObjWithName, iInModuleHdlObj):
    """
    HDL Component insance

    :ivar name: name of this component instance in this module
    :ivar module_name: HdlId or iHdlExpr made from HdlIds and dot operators
    :ivar param_map: same as port_map just port parameters of the component
    :ivar port_map: the list of iHdlExpr with map operator for map assignment
                    or any other iHdlExpr for positional mapping
    """
    __slots__ = ["module_name", "param_map", "port_map"]

    def __init__(self):
        iHdlObjWithName.__init__(self)
        iInModuleHdlObj.__init__(self)
        self.module_name = None  # type: iHdlExpr
        self.param_map = []  # type: List[iHdlExpr]
        self.port_map = []  # type: List[iHdlExpr]


class HdlFunction(iHdlObjWithName, iInModuleHdlObj):
    """
    HDL Function definition or declaration
    """
    __slots__ = ["is_operator", "return_t", "params", "body"]

    def __init__(self):
        self.is_operator = False  # type: bool
        self.return_t = None  # type: Optional[iHdlExpr]
        self.params = []  # type: List[HdlVariableDef]
        self.body = []  # type: List[Union[HdlVariableDef, iHdlStatement]]


class iHdlStatement(iHdlObj, iInModuleHdlObj):
    """
    :ivar labels: list of labels, the first label is for this statement
        the others are for it's branches
    :ivar in_preproc: if True the statement is VHDL generate
            or other different of type of statement which should be evaluated
            compile time (note that this correspond s to VHDL generate statements
            and not to Verilog preprocessor ifdefs as they are processed before
            Verilog code parsing and are not present in code read by parser
            in the first place)
    """
    __slots__ = ["labels", "in_prepoc"]

    def __init__(self):
        iHdlObj.__init__(self)
        iInModuleHdlObj.__init__(self)
        self.labels = []  # type: List[HdlName]
        self.in_prepoc = False  # type: bool


class HdlImport(iHdlStatement):
    """
    The import statements used in VHDL

    :note: note that this does not corresponds to include as include
            is processed by preprocessor
    :ivar path: the list of names which are in the import
    """
    __slots__ = ["path", ]

    def __init__(self):
        super(HdlImport, self).__init__()
        self.path = []  # type: List[str]


class HdlStmBlock(iHdlStatement):
    """
    Block of statements in HDL
    List[Union[iHdlExpr, iHdlStatement, HdlVariableDef, iHdlTypeDef]]
    """
    __slots__ = ["body"]

    def __init__(self):
        super(HdlStmBlock, self).__init__()
        self.body = []  # type: List[iHdlObj]


class HdlStmAssign(iHdlStatement):
    """
    HDL assignment statement

    :ivar src: the source
    :ivar dst: the destination
    :ivar is_blocking: flag if true assignment should be evaluated immediately
        else the assignment is evaluated after end of the current event
    :ivar
    """
    __slots__ = ["src", "dst", 'is_blocking', 'delay']

    def __init__(self, src, dst):
        super(HdlStmAssign, self).__init__()
        self.src = src  # type: iHdlExpr
        self.dst = dst  # type: iHdlExpr
        self.is_blocking = False


class HdlStmAssignControlled(HdlStmAssign):
    """
    Assignment with some sort of delay specification
    if statement is blocking the current statement waits until the condition is met
    and then continues. If the assignment is not blocking the code continues and this statement
    is executed asynchronously after condition is met.

    This is generally not synthetisable to hardware and is used in simulations.

    :ivar time_delay: delay which waits for a specified time
    :ivar event_delay: delay which waits for a specified event

    """

    def __init__(self, src, dst, time_delay, event_delay):
        super(HdlStmAssignControlled, self).__init__(src, dst)
        self.time_delay = time_delay  # type Optional[iHdlExpr]
        self.event_delay = event_delay  # type Optional[List[iHdlExpr]]


class HdlStmIf(iHdlStatement):
    """
    HDL if statement

    :ivar cond: condition in if statement
    :ivar if_true: block of statements which is in if true branch
    :ivar elifs: type: List[Tuple[iHdlExpr, List[iHdlStatement]]]
                  = list of (condition, statement list)
    """
    __slots__ = ["cond", "if_true", "elifs", "if_false"]

    def __init__(self):
        super(HdlStmIf, self).__init__()
        self.cond = None  # type: iHdlExpr
        self.if_true = []  # type: List[iHdlStatement]
        self.elifs = []  # type: List[Tuple[iHdlExpr, List[iHdlStatement]]]
        self.if_false = None  # type: Optional[List[iHdlStatement]]


class HdlStmProcess(iHdlStatement):
    """
    HDL process statement
    the container of statements with the sensitivity specified

    :ivar sensitivity: optional list of expressions which specifies
        the trigger signals of the evaluation of the process
    :note: sensitivity = None means that the process is executed immediately
        sensitivity = [] means the process is never executed
    :note: Verilog always #time construct is translated to process without sensitivity and
        wait #time as a first statement in body.
    """
    __slots__ = ["sensitivity", "body"]

    def __init__(self):
        super(HdlStmProcess, self).__init__()
        self.sensitivity = None  # type: Optional[iHdlExpr]
        self.body = []  # type: Tuple[iHdlExpr, List[iHdlStatement]]


class HdlStmCase(iHdlStatement):
    """
    HDL case statement
    """
    __slots__ = ["switch_on", "cases", "default"]

    def __init__(self):
        super(HdlStmCase, self).__init__()
        self.switch_on = None  # type: iHdlExpr
        self.cases = []  # type: List[Tuple[iHdlExpr, List[iHdlStatement]]]
        self.default = None  # type: Optional[List[iHdlStatement]]


class HdlStmFor(iHdlStatement):
    """
    HDL for statement

    for (init, cond, step)
        body
    """
    __slots__ = ["init", "cond", "step", "body"]

    def __init__(self):
        super(HdlStmFor, self).__init__()
        self.init = []  # type: List[iHdlStatement]
        self.cond = None  # type: iHdlExpr
        self.step = []  # type: List[iHdlStatement]
        self.body = []  # type: List[iHdlStatement]


class HdlStmForIn(iHdlStatement):
    """
    HDL for in statement

    for var in collection:
        body
    """
    __slots__ = ["var", "collection", "body"]

    def __init__(self):
        super(HdlStmForIn, self).__init__()
        self.var = []  # type: List[iHdlStatement]
        self.collection = None  # type: iHdlExpr
        self.body = []  # type: List[iHdlStatement]


class HdlStmWhile(iHdlStatement):
    """
    HDL while statement

    while cond:
        body
    """
    __slots__ = ["cond", "body"]

    def __init__(self):
        super(HdlStmWhile, self).__init__()
        self.cond = None  # type: iHdlExpr
        self.body = []  # type: Tuple[iHdlExpr, List[iHdlStatement]]


class HdlStmReturn(iHdlStatement):
    """
    HDL return statement
    """
    __slots__ = ["val"]

    def __init__(self):
        super(HdlStmReturn, self).__init__()
        self.val = None  # type: iHdlExpr


class HdlStmWait(iHdlStatement):
    """
    HDL wait statement

    This is generally not synthetisable to hardware and is used in simulations.
    """
    __slots__ = ["val"]

    def __init__(self):
        super(HdlStmWait, self).__init__()
        self.val = []  # type: List[iHdlExpr]


class HdlStmBreak(iHdlStatement):
    """
    HDL break statement
    """
    __slots__ = []


class HdlStmContinue(iHdlStatement):
    """
    HDL continue statement
    """
    __slots__ = []


class HdlContext(object):
    """
    The container of the objects specified in HDL files

    :ivar objs: the list of the object from the HDL files
    """

    def __init__(self):
        self.objs = []  # type: List[iHdlObj]
