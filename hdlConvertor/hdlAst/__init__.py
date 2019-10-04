"""
This package contains the containers
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

from hdlConvertor.hdlAst._bases import (iHdlObj, iHdlObjInModule,
    iHdlObjWithName, iHdlStatement)
from hdlConvertor.hdlAst._defs import HdlFunctionDef, HdlVariableDef
from hdlConvertor.hdlAst._expr import (HdlAll, HdlBuiltinFn, HdlCall,
    HdlDirection, HdlIntValue, HdlName, HdlOthers, HdlTypeAuto, HdlTypeType,
    iHdlExpr)
from hdlConvertor.hdlAst._statements import (HdlImport, HdlStmAssign,
    HdlStmBlock, HdlStmBreak, HdlStmCase, HdlStmContinue, HdlStmFor,
    HdlStmForIn, HdlStmIf, HdlStmProcess, HdlStmReturn, HdlStmWait,
    HdlStmWhile)
from hdlConvertor.hdlAst._structural import (HdlComponentInst, HdlContext,
    HdlModuleDec, HdlModuleDef, HdlNamespace)
from hdlConvertor.hdlAst._typeDefs import HdlClassDef, HdlEnumDef, HdlTypeBitsDef
from hdlConvertor.hdlAst.utils import CodePosition
