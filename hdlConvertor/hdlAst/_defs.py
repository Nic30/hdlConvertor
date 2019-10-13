from typing import List, Union, Optional

from hdlConvertor.hdlAst._bases import iHdlObj, iHdlObjInModule, \
                                       iHdlObjWithName
from hdlConvertor.hdlAst._expr import iHdlExpr


class HdlVariableDef(iHdlObjWithName, iHdlObjInModule):
    """
    Definition of port/param/type etc in HDL

    :ivar name: name of newly defined object
    :ivar type: type of the defined variable (or type etc.)
    :ivar value: initialisation of variable (typedef etc.)
    :ivar is_const: flag if true the value is constants
    :ivar is_latched: flag if true the object corresponds to VHDL variable/Verilog reg
    :ivar is_static: flag if true static (same meaning as in C/C++)
    :ivar is_static: flag if true the variable stores virtual type
        (corresponds to System Verilog virtual parameter)
    :ivar direction: direction if the variable is port
    """
    __slots__ = ["name", "type", "value", "is_latched", "is_const", "is_static",
                 "is_virtual", "direction"]

    def __init__(self):
        iHdlObjWithName.__init__(self)
        iHdlObjInModule.__init__(self)
        self.type = None  # type: HdlType
        self.value = None  # iHdlExpr
        self.is_const = False  # type: bool
        self.is_latched = False  # type: bool
        self.is_static = False  # type: bool
        self.is_virtual = False  # type: bool
        self.direction = None  # type: HdlDirection


class HdlFunctionDef(iHdlObjWithName, iHdlObjInModule):
    """
    HDL Function definition or declaration

    :note: Verilog:
        * task automatic corresponds to is_static=False, is_task=True
        * task corresponds to is_static=True, is_task=True
        * task/function in module is static by default, if in class it is automatic by default

    """
    __slots__ = [
        "is_declaration_only",
        "is_operator",
        "is_static",
        "is_task",
        "is_virtual",
        "return_t", "params", "body"]

    def __init__(self):
        iHdlObjWithName.__init__(self)
        iHdlObjInModule.__init__(self)
        self.is_declaration_only = True  # type:bool
        self.is_operator = False  # type: bool
        self.is_static = False  # type: bool
        self.is_task = False  # type: bool
        self.is_virtual = False  # type: bool
        self.return_t = None  # type: Optional[iHdlExpr]
        self.params = []  # type: List[HdlVariableDef]
        self.body = []  # type: List[Union[HdlVariableDef, iHdlStatement, iHdlExpr]]

