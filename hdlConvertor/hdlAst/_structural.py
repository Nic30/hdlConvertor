from typing import List, Union

from hdlConvertor.hdlAst._bases import iHdlObjWithName, iHdlObjInModule, iHdlObj
from hdlConvertor.hdlAst._defs import HdlVariableDef


try:
    # python2
    from StringIO import StringIO
except ImportError:
    # python3
    from io import StringIO


class HdlLibrary(iHdlObjWithName):
    """
    The library clause in VHDL
    """
    __slots__ = []

    def __init__(self, name):
        super(HdlLibrary, self).__init__()
        self.name = name


class HdlNamespace(iHdlObjWithName):
    """
    Corresponds to VHDL package/package body or SystemVerilog namespace
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

    :ivar ~.name: name of the architecture in VHDL or name of module in Verilog
    :ivar ~.module_name: the name of entity in VHDL or same as name in Verilog
    :ivar ~.dec: module header for verilog
    """
    __slots__ = ["dec", "module_name", "objs"]

    def __init__(self):
        super(HdlModuleDef, self).__init__()
        self.dec = None  # type: Optional[HdlModuleDec]
        self.module_name = None  # type: HdlName
        self.objs = []  # type: List[Union[iHdlObj, iHdlObjInModule]]


class HdlComponentInst(iHdlObjWithName, iHdlObjInModule):
    """
    HDL Component instance

    :ivar ~.name: name of this component instance in this module
    :ivar ~.module_name: iHdlExpr made from HdlNames and dot operators (optionally)
    :attention: module has to be find explicitly and is not present in default
        AST after parsing
    :ivar ~.param_map: same as port_map just port parameters of the component
    :ivar ~.port_map: the list of iHdlExpr with map operator for map assignment
                    or any other iHdlExpr for positional mapping
    """
    __slots__ = ["module_name", "module", "param_map", "port_map"]

    def __init__(self):
        iHdlObjWithName.__init__(self)
        iHdlObjInModule.__init__(self)
        self.module_name = None  # type: iHdlExpr
        self.param_map = []  # type: List[iHdlExpr]
        self.port_map = []  # type: List[iHdlExpr]


class HdlContext(object):
    """
    The container of the objects specified in HDL files

    :ivar ~.objs: the list of the object from the HDL files
    :ivar ~.name_scope: A NameScope instance build from objs
    """

    def __init__(self):
        self.objs = []  # type: List[iHdlObj]
        self.name_scope = None

    def __repr__(self):
        from hdlConvertor.to.json import ToJson
        from pprint import pprint
        to = ToJson()
        d = getattr(to, "visit_" + self.__class__.__name__)(self)
        s = StringIO()
        pprint(d, stream=s, depth=3)
        return s.getvalue() 