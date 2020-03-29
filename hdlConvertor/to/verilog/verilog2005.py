from hdlConvertor.hdlAst import HdlDirection, HdlBuiltinFn,\
    HdlCall, HdlComponentInst, HdlVariableDef, iHdlStatement,\
    HdlTypeAuto
from hdlConvertor.hdlAst._defs import HdlFunctionDef
from hdlConvertor.to.hdlUtils import Indent, iter_with_last
from hdlConvertor.to.verilog.stm import ToVerilog2001Stm


class ToVerilog2005(ToVerilog2001Stm):
    """
    Convert HdlConverotr hdlObject AST back to Verilog 2002
    """
    DIR2V = {
        HdlDirection.IN: "input",
        HdlDirection.OUT: "output",
        HdlDirection.INOUT: "inout",
    }

    def print_doc(self, obj):
        return super(ToVerilog2001, self).print_doc(obj, "//")

    def print_direction(self, d):
        """
        :type d: HdlDirection
        """
        vd = self.DIR2V[d]
        self.out.write(vd)

    def print_generic_declr(self, g):
        """
        :type g: HdlVariableDef
        """
        self.print_doc(g)
        w = self.out.write
        w("parameter ")
        is_array = self.print_type_first_part(g.type)
        if g.type is not HdlTypeAuto:
            w(" ")
        w(g.name)
        v = g.value
        if is_array:
            self.print_type_array_part(g.type)
        if v:
            w(" = ")
            self.print_iHdlExpr(v)

    def print_port_declr(self, p):
        """
        :type p: HdlVariableDef
        """
        w = self.out.write
        self.print_doc(p)
        self.print_direction(p.direction)
        w(" ")

        t = p.type
        is_array = self.print_type_first_part(t)
        w(" ")

        w(p.name)
        if is_array:
            self.print_type_array_part(t)

    def print_HdlModuleDec(self, e):
        """
        :type e: HdlModuleDef
        """
        self.print_doc(e)
        w = self.out.write
        w("module ")
        w(e.name)
        gs = e.params
        if gs:
            w(" #(\n")
            with Indent(self.out):
                for last, g in iter_with_last(gs):
                    self.print_generic_declr(g)
                    if last:
                        w("\n")
                    else:
                        w(",\n")

            w(")")
        ps = e.ports
        if ps:
            w(" (\n")
            with Indent(self.out):
                for last, p in iter_with_last(ps):
                    self.print_port_declr(p)
                    if last:
                        w("\n")
                    else:
                        w(",\n")
            w(")")
        w(";\n")

    def print_HdlVariableDef(self, var):
        """
        :type var: HdlVariableDef
        """
        self.print_doc(var)
        name = var.name
        t = var.type
        w = self.out.write
        if var.is_const:
            w("localparam ")
        is_array = self.print_type_first_part(t)
        w(" ")
        w(name)
        if is_array:
            self.print_type_array_part(t)

    def print_map_item(self, item):
        if isinstance(item, HdlCall)\
                and item.fn == HdlBuiltinFn.MAP_ASSOCIATION:
            w = self.out.write
            # k, v pair
            k, v = item.ops
            w(".")
            self.print_iHdlExpr(k)
            w("(")
            self.print_iHdlExpr(v)
            w(")")
        else:
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
        assert c.module_name
        self.print_iHdlExpr(c.module_name)
        w(" ")
        self.print_iHdlExpr(c.name)
        gms = c.param_map
        if gms:
            w(" #(\n")
            self.print_map(gms)
            w(")")

        pms = c.port_map
        if pms:
            w(" (\n")
            self.print_map(pms)
            w(")")

    def print_HdlFunctionDef_def(self, o):
        """
        :type o: HdlFunctionDef
        """
        self.print_doc(o)
        w = self.out.write
        if o.is_task:
            w("task ")
        else:
            w("function ")
        if not o.is_static:
            w("automatic ")

        if not o.is_task:
            self.print_type_first_part(o.return_t)
            self.print_type_array_part(o.return_t)

        if o.is_virtual or o.is_operator:
            raise NotImplementedError(o)
        w(" ")
        w(o.name)
        ps = o.params
        if ps:
            w(" (\n")
            with Indent(self.out):
                for last, p in iter_with_last(ps):
                    self.print_port_declr(p)
                    if last:
                        w("\n")
                    else:
                        w(",\n")
            w(")")
        w(";\n")
        with Indent(self.out):
            for s in o.body:
                if isinstance(s, HdlVariableDef):
                    self.print_HdlVariableDef(s)
                    w(";\n")
                elif isinstance(s, iHdlStatement):
                    need_semi = self.print_iHdlStatement(s)
                    if need_semi:
                        w(";\n")
                    else:
                        w("\n")
                else:
                    self.print_iHdlExpr(s)
                    w(";\n")

        if o.is_task:
            w("endtask")
        else:
            w("endfunction")

    def print_HdlModuleDef(self, a):
        """
        :type a: HdlModuleDef
        """
        w = self.out.write
        with Indent(self.out):
            for o in a.objs:
                if isinstance(o, HdlVariableDef):
                    self.print_HdlVariableDef(o)
                    w(";\n")
                elif isinstance(o, HdlComponentInst):
                    self.print_component_instance(o)
                    w(";\n\n")
                elif isinstance(o, iHdlStatement):
                    need_semi = self.print_iHdlStatement(o, is_top=True)
                    if need_semi:
                        w(";\n")
                    else:
                        w("\n\n")
                elif isinstance(o, HdlFunctionDef):
                    self.print_HdlFunctionDef_def(o)
                    w("\n")
                else:
                    raise NotImplementedError(o)

        self.out.write("endmodule\n")


if __name__ == "__main__":
    import os
    import sys
    BASE_DIR = os.path.join(os.path.dirname(__file__), "..", "..", "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'verilog')
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    c = HdlConvertor()
    filenames = [os.path.join(TEST_DIR, "arbiter_tb.v")]
    # AES = os.path.join(BASE_DIR, "..", "aes")
    # files = [
    #    # "aes_cipher_top.v",
    #    # "aes_key_expand_128.v",
    #    # "aes_inv_cipher_top.v",  "aes_rcon.v",
    #    "test_bench_top.v",
    #    # "aes_inv_sbox.v",        "aes_sbox.v",
    # ]
    #
    # filenames = [os.path.join(AES, f) for f in files]
    d = c.parse(filenames, Language.VERILOG, [], False, True)
    tv = ToVerilog2001(sys.stdout)
    tv.print_HdlContext(d)
