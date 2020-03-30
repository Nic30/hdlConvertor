"""
Use declarations collected from resolve_names
and use them to associate HdlNames to a HdlObjects.
"""
from itertools import chain

from hdlConvertor.hdlAst import HdlCall, HdlBuiltinFn, HdlName, HdlAll,\
    HdlIntValue, HdlVariableDef, HdlStmAssign, HdlModuleDec, HdlModuleDef,\
    HdlComponentInst
from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor
from hdlConvertor.translate.common.discover_declarations import WithNameScope
from hdlConvertor.hdlAst._bases import iHdlStatement


class ResolveNames(HdlAstVisitor):

    def __init__(self, name_scope):
        """
        :type name_scope: NameScope
        """
        self.name_scope = name_scope

    def visit_HdlVariableDef(self, o):
        """
        :type o: HdlVariableDef
        """
        self.name_scope.register_name(o.name, o)

    def visit_HdlModuleDec(self, o):
        """
        :type o: HdlModuleDec
        """
        with WithNameScope(self, self.name_scope.level_push(o.name)):
            for p in chain(o.params, o.ports):
                self.visit_HdlVariableDef(p)

            for o2 in o.objs:
                raise NotImplementedError(o2)

        if o.body is not None:
            self.visit_HdlModuleDef(o.body)

    def visit_HdlModuleDef(self, o):
        """
        :type o: HdlModuleDef
        """
        with WithNameScope(self, self.name_scope.get_child(o.module_name)):
            self.visit(o.objs)

    def visit_port_param_map(self, mod_name_scope, pmap):
        """
        :type pmap: List[HdlCall]
        """
        for pm in pmap:
            assert isinstance(pm, HdlCall) and\
                pm.fn == HdlBuiltinFn.MAP_ASSOCIATION, pm
            mod_port, connected_sig = pm.ops
            assert isinstance(mod_port, HdlName), mod_port
            _, mod_port.obj = mod_name_scope.get_object_and_scope_by_name(
                mod_port)
            assert isinstance(connected_sig, HdlName), connected_sig
            _, connected_sig.obj = self.name_scope.get_object_and_scope_by_name(
                mod_port)

    def visit_HdlComponentInst(self, o):
        """
        :type o: HdlComponentInst
        """
        if o.name is not None:
            o.name.obj = o
        ns = self.name_scope
        mod_name_scope, mod_def = ns.get_object_and_scope_by_name(
            o.module_name)
        mod_name_scope = mod_name_scope.get_child(o.module_name)
        o.module_name.obj = mod_def
        self.visit_port_param_map(ns, mod_name_scope, o.param_map)
        self.visit_port_param_map(ns, mod_name_scope, o.port_map)

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        """
        if isinstance(o, HdlCall):
            for o2 in o.ops:
                self.visit_iHdlExpr(o2)
        elif isinstance(o, HdlName):
            _, o.obj = self.name_scope.get_object_and_scope_by_name(o)
        elif o is None or o is HdlAll or isinstance(
                o,  (HdlIntValue, float, str)):
            pass
        else:
            assert isinstance(o, list), o
            for o2 in o:
                self.visit_iHdlExpr(o2)

    def _visit(self, o):
        if isinstance(o, HdlVariableDef):
            self.visit_HdlVariableDef(o)
        elif isinstance(o, HdlModuleDec):
            self.visit_HdlModuleDec(o)
        elif isinstance(o, HdlModuleDef):
            self.visit_HdlModuleDef(o)
        elif isinstance(o, iHdlStatement):
            self.visit_iHdlStatement(o)
        elif isinstance(o, HdlComponentInst):
            self.visit_HdlComponentInst(o)
        else:
            raise NotImplementedError(o)

    def visit(self, objs):
        for o in objs:
            self._visit(o)
