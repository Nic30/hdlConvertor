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
        super(ResolveNames, self).__init__()
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

    def visit_HdlModuleDef(self, o):
        """
        :type o: HdlModuleDef
        """
        if o.dec is not None:
            self.visit_HdlModuleDec(o.dec)

        with WithNameScope(self, self.name_scope.get_child(o.module_name.val)):
            for o2 in o.objs:
                self.visit_iHdlObj(o2)

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
                mod_port.val)
            assert isinstance(connected_sig, HdlName), connected_sig
            _, connected_sig.obj = self.name_scope.get_object_and_scope_by_name(
                mod_port.val)

    def visit_HdlComponentInst(self, o):
        """
        :type o: HdlComponentInst
        """
        if o.name is not None:
            o.name.obj = o
        ns = self.name_scope
        mod_name_scope, mod_def = ns.get_object_and_scope_by_name(
            o.module_name.val)
        mod_name_scope = mod_name_scope.get_child(o.module_name.val)
        o.module_name.obj = mod_def
        self.visit_port_param_map(mod_name_scope, o.param_map)
        self.visit_port_param_map(mod_name_scope, o.port_map)

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        """
        if isinstance(o, HdlCall):
            for o2 in o.ops:
                self.visit_iHdlExpr(o2)
        elif isinstance(o, HdlName):
            _, o.obj = self.name_scope.get_object_and_scope_by_name(o.val)
        elif o is None or o is HdlAll or isinstance(
                o,  (HdlIntValue, float, str)):
            pass
        else:
            assert isinstance(o, list), o
            for o2 in o:
                self.visit_iHdlExpr(o2)
