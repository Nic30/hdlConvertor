from hdlConvertor.hdlAst._structural import HdlModuleDec, HdlModuleDef,\
    HdlComponentInst
from itertools import chain
from hdlConvertor.hdlAst._defs import HdlVariableDef
from hdlConvertor.hdlAst._bases import iHdlStatement
from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor


class WithNameScope():

    def __init__(self, discover_declarations, name_scope):
        """
        :type discover_declarations: DiscoverDeclarations
        :type name_scope: NameScope
        """
        self.discover_declarations = discover_declarations
        self.name_scope = name_scope

    def __enter__(self):
        self.original_name_scope = self.discover_declarations.name_scope
        self.discover_declarations.name_scope = self.name_scope

    def __exit__(self, type, value, traceback):
        self.discover_declarations.name_scope = self.original_name_scope


class DiscoverDeclarations(HdlAstVisitor):

    def __init__(self, name_scope):
        """
        :type name_scope: NameScope
        """
        super(DiscoverDeclarations, self).__init__()
        self.name_scope = name_scope

    def visit_HdlVariableDef(self, o):
        """
        :type name_scope: NameScope
        :type o: HdlVariableDef
        """
        self.name_scope.register_name(o.name, o)

    def visit_HdlModuleDec(self, o):
        """
        :type name_scope: NameScope
        :type o: HdlModuleDec
        """
        ns = self.name_scope
        ns.register_name(o.name, o)
        with WithNameScope(self, ns.level_push(o.name)):
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
            self.discover_declarations(o.objs)

    def visit_HdlComponentInst(self, o):
        """
        :type o: HdlComponentInst
        """
        if o.name is not None:
            self.name_scope.register_name(o.name, o)
        # name_scope = name_scope.get_object_by_name(o.module_name)

    def _discover_declarations(self, o):
        if isinstance(o, HdlVariableDef):
            self.visit_HdlVariableDef(o)
        elif isinstance(o, HdlModuleDec):
            self.visit_HdlModuleDec(o)
        elif isinstance(o, HdlModuleDef):
            self.visit_HdlModuleDef(o)
        elif isinstance(o, iHdlStatement):
            pass
        elif isinstance(o, HdlComponentInst):
            self.visit_HdlComponentInst(o)
        else:
            raise NotImplementedError(o)

    def discover_declarations(self, objs):
        for o in objs:
            self._discover_declarations(o)
