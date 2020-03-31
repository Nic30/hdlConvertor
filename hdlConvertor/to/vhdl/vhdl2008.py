from hdlConvertor.hdlAst import HdlDirection, iHdlStatement, \
    HdlVariableDef, HdlModuleDec, HdlFunctionDef, HdlComponentInst
from hdlConvertor.to.hdlUtils import Indent, iter_with_last, UnIndent
from hdlConvertor.to.vhdl.stm import ToVhdl2008Stm


class ToVhdl2008(ToVhdl2008Stm):
    """
    Convert hdlObject AST back to VHDL
    """
    DIR2V = {
        HdlDirection.IN: "IN",
        HdlDirection.OUT: "OUT",
        HdlDirection.INOUT: "INOUT",
    }

    def visit_doc(self, obj):
        return super(ToVhdl2008, self).visit_doc(obj, "--")

    def visit_direction(self, d):
        vd = self.DIR2V[d]
        self.out.write(vd)

    def visit_generic_or_port_declr(self, o):
        """
        :type p: HdlVariableDef
        """
        self.visit_doc(o)
        w = self.out.write
        w(o.name)
        w(" : ")
        d = o.direction
        if d != HdlDirection.INTERNAL:
            self.visit_direction(d)
            w(" ")
        self.visit_type(o.type)
        v = o.value
        if v:
            w(" := ")
            self.visit_iHdlExpr(v)

    def visit_HdlModuleDec(self, e, vhdl_obj_name="ENTITY"):
        """
        :param e: Entity
        :type e: HdlModuleDec
        """
        self.visit_doc(e)
        w = self.out.write
        w(vhdl_obj_name)
        w(" ")
        w(e.name)
        w(" IS\n")
        gs = e.params
        if gs:
            with Indent(self.out):
                w("GENERIC(\n")
                with Indent(self.out):
                    for last, g in iter_with_last(gs):
                        self.visit_generic_or_port_declr(g)
                        if last:
                            w("\n")
                        else:
                            w(",\n")

                w(");\n")
        ps = e.ports
        if ps:
            with Indent(self.out):
                w("PORT(\n")
                with Indent(self.out):
                    for last, p in iter_with_last(ps):
                        self.visit_generic_or_port_declr(p)
                        if last:
                            w("\n")
                        else:
                            w(",\n")
                w(");\n")
        w("END ")
        w(vhdl_obj_name)
        w(";\n")

    def visit_component(self, o):
        """
        :type o: HdlModuleDec
        """
        self.visit_HdlModuleDec(o, vhdl_obj_name="COMPONENT")

    def visit_type(self, t):
        """
        :type t: iHdlExpr
        """
        self.visit_iHdlExpr(t)

    def visit_HdlVariableDef(self, var, end=";\n"):
        """
        :type var: HdlVariableDef
        """
        self.visit_doc(var)
        name = var.name
        t = var.type
        latch = var.is_latched
        c = var.is_const
        w = self.out.write
        if c:
            w("CONSTANT ")
        elif latch:
            w("VARIABLE ")
        else:
            w("SIGNAL ")
        w(name)
        w(" : ")
        self.visit_type(t)
        v = var.value
        if v is not None:
            w(" := ")
            self.visit_iHdlExpr(v)
        w(end)

    def visit_map_item(self, item):
        self.visit_iHdlExpr(item)

    def visit_map(self, map_):
        w = self.out.write
        with Indent(self.out):
            for last, m in iter_with_last(map_):
                self.visit_map_item(m)
                if last:
                    w("\n")
                else:
                    w(",\n")

    def visit_component_instance(self, c):
        """
        :type c: HdlComponentInst
        """
        self.visit_doc(c)
        w = self.out.write
        self.visit_iHdlExpr(c.name)
        w(": ")
        self.visit_iHdlExpr(c.module_name)
        gms = c.param_map
        if gms:
            w(" GENERIC MAP(\n")
            self.visit_map(gms)
            w(")")

        pms = c.port_map
        if pms:
            w(" PORT MAP(\n")
            self.visit_map(pms)
            w(")")
        w(";")

    def visit_body_items(self, objs):
        w = self.out.write
        in_def_section = True
        with Indent(self.out):
            for o in objs:
                if isinstance(o, HdlVariableDef):
                    assert in_def_section, o
                    self.visit_HdlVariableDef(o)
                    continue
                elif isinstance(o, HdlModuleDec):
                    assert in_def_section, o
                    self.visit_component(o)
                    continue
                elif isinstance(o, HdlFunctionDef):
                    assert in_def_section, o
                    self.visit_HdlFunctionDef(o)
                    continue

                if in_def_section:
                    with UnIndent(self.out):
                        w("BEGIN\n")
                    in_def_section = False

                if isinstance(o, HdlComponentInst):
                    self.visit_component_instance(o)
                    w("\n")
                elif isinstance(o, iHdlStatement):
                    self.visit_iHdlStatement(o)
                else:
                    raise NotImplementedError(o)
        if in_def_section:
            w("BEGIN\n")

    def visit_HdlModuleDef(self, a):
        """
        :type a: HdlModuleDef
        """
        w = self.out.write
        w("ARCHITECTURE ")
        w(a.name)
        w(" OF ")
        w(a.module_name)
        w(" IS\n")
        self.visit_body_items(a.objs)
        self.out.write("END ARCHITECTURE;\n")

    def visit_HdlFunctionDef(self, o):
        """
        :type o: HdlFunctionDef
        """
        w = self.out.write
        self.visit_doc(o)
        is_procedure = o.return_t is None
        if is_procedure:
            w("PROCEDURE ")
        else:
            w("FUNCTION ")

        w(o.name)

        w(" (")
        with Indent(self.out):
            for is_last, par in iter_with_last(o.params):
                self.visit_HdlVariableDef(par, end="")
                if not is_last:
                    w(",\n")
        w(")")
        if not is_procedure:
            w(" RETURN ")
            self.visit_type(o.return_t)
        if o.is_declaration_only:
            w(";\n")
        else:
            w("\n")
            w("IS\n")
            self.visit_body_items(o.body)
            w("END FUNCTION;\n")

    def visit_HdlLibrary(self, o):
        """
        :type o: HdlLibrary
        """
        w = self.out.write
        w("LIBRARY ")
        w(o.name)
        w(";\n")

    def visit_HdlImport(self, o):
        """
        :type o: HdlImport
        """
        self.visit_doc(o)
        w = self.out.write
        w("USE ")
        for last, p in iter_with_last(o.path):
            self.visit_iHdlExpr(p)
            if not last:
                w(".")
        w(";\n")

    def visit_HdlNamespace(self, o):
        """
        :type o: HdlNamespace
        """
        self.visit_doc(o)
        w = self.out.write
        # if o.declaration_only:
        w("PACKAGE ")
        w(o.name)
        w(" IS\n")
        with Indent(self.out):
            for _o in o.objs:
                self.visit_main_obj(_o)

        w("END PACKAGE;\n")


if __name__ == "__main__":
    import os
    import sys
    BASE_DIR = os.path.join(os.path.dirname(__file__), "..", "..", "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'vhdl')
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    c = HdlConvertor()
    filenames = [os.path.join(TEST_DIR, "package_constants.vhd")]
    d = c.parse(filenames, Language.VHDL, [], False, True)
    tv = ToVhdl2008(sys.stdout)
    tv.visit_HdlContext(d)
