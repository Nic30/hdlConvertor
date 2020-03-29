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

    def print_doc(self, obj):
        return super(ToVhdl2008, self).print_doc(obj, "--")

    def print_direction(self, d):
        vd = self.DIR2V[d]
        self.out.write(vd)

    def print_generic_or_port_declr(self, o):
        """
        :type p: HdlVariableDef
        """
        self.print_doc(o)
        w = self.out.write
        w(o.name)
        w(" : ")
        d = o.direction
        if d != HdlDirection.INTERNAL:
            self.print_direction(d)
            w(" ")
        self.print_type(o.type)
        v = o.value
        if v:
            w(" := ")
            self.print_iHdlExpr(v)

    def print_HdlModuleDec(self, e, vhdl_obj_name="ENTITY"):
        """
        :param e: Entity
        :type e: HdlModuleDec
        """
        self.print_doc(e)
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
                        self.print_generic_or_port_declr(g)
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
                        self.print_generic_or_port_declr(p)
                        if last:
                            w("\n")
                        else:
                            w(",\n")
                w(");\n")
        w("END ")
        w(vhdl_obj_name)
        w(";\n")

    def print_component(self, o):
        """
        :type o: HdlModuleDec
        """
        self.print_HdlModuleDec(o, vhdl_obj_name="COMPONENT")

    def print_type(self, t):
        """
        :type t: iHdlExpr
        """
        self.print_iHdlExpr(t)

    def print_HdlVariableDef(self, var, end=";\n"):
        """
        :type var: HdlVariableDef
        """
        self.print_doc(var)
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
        self.print_type(t)
        v = var.value
        if v is not None:
            w(" := ")
            self.print_iHdlExpr(v)
        w(end)

    def print_map_item(self, item):
        self.print_iHdlExpr(item)

    def print_map(self, map_):
        w = self.out.write
        with Indent(self.out):
            for last, m in iter_with_last(map_):
                self.print_map_item(m)
                if last:
                    w("\n")
                else:
                    w(",\n")

    def print_component_instance(self, c):
        """
        :type c: HdlComponentInst
        """
        self.print_doc(c)
        w = self.out.write
        self.print_iHdlExpr(c.name)
        w(": ")
        self.print_iHdlExpr(c.module_name)
        gms = c.param_map
        if gms:
            w(" GENERIC MAP(\n")
            self.print_map(gms)
            w(")")

        pms = c.port_map
        if pms:
            w(" PORT MAP(\n")
            self.print_map(pms)
            w(")")
        w(";")

    def print_body_items(self, objs):
        w = self.out.write
        in_def_section = True
        with Indent(self.out):
            for o in objs:
                if isinstance(o, HdlVariableDef):
                    assert in_def_section, o
                    self.print_HdlVariableDef(o)
                    continue
                elif isinstance(o, HdlModuleDec):
                    assert in_def_section, o
                    self.print_component(o)
                    continue
                elif isinstance(o, HdlFunctionDef):
                    assert in_def_section, o
                    self.print_HdlFunctionDef(o)
                    continue

                if in_def_section:
                    with UnIndent(self.out):
                        w("BEGIN\n")
                    in_def_section = False

                if isinstance(o, HdlComponentInst):
                    self.print_component_instance(o)
                    w("\n")
                elif isinstance(o, iHdlStatement):
                    self.print_iHdlStatement(o)
                else:
                    raise NotImplementedError(o)
        if in_def_section:
            w("BEGIN\n")

    def print_HdlModuleDef(self, a):
        """
        :type a: HdlModuleDef
        """
        w = self.out.write
        w("ARCHITECTURE ")
        w(a.name)
        w(" OF ")
        w(a.module_name)
        w(" IS\n")
        self.print_body_items(a.objs)
        self.out.write("END ARCHITECTURE;\n")

    def print_HdlFunctionDef(self, o):
        """
        :type o: HdlFunctionDef
        """
        w = self.out.write
        self.print_doc(o)
        is_procedure = o.return_t is None
        if is_procedure:
            w("PROCEDURE ")
        else:
            w("FUNCTION ")

        w(o.name)

        w(" (")
        with Indent(self.out):
            for is_last, par in iter_with_last(o.params):
                self.print_HdlVariableDef(par, end="")
                if not is_last:
                    w(",\n")
        w(")")
        if not is_procedure:
            w(" RETURN ")
            self.print_type(o.return_t)
        if o.is_declaration_only:
            w(";\n")
        else:
            w("\n")
            w("IS\n")
            self.print_body_items(o.body)
            w("END FUNCTION;\n")

    def print_library(self, o):
        w = self.out.write
        w("LIBRARY ")
        self.print_iHdlExpr(o)
        w(";\n")

    def print_HdlImport(self, o):
        """
        :type o: HdlImport
        """
        self.print_doc(o)
        w = self.out.write
        w("USE ")
        for last, p in iter_with_last(o.path):
            self.print_iHdlExpr(p)
            if not last:
                w(".")
        w(";\n")

    def print_HdlNamespace(self, o):
        """
        :type o: HdlNamespace
        """
        self.print_doc(o)
        w = self.out.write
        # if o.declaration_only:
        w("PACKAGE ")
        w(o.name)
        w(" IS\n")
        with Indent(self.out):
            for _o in o.objs:
                self.print_main_obj(_o)

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
    tv.print_HdlContext(d)
