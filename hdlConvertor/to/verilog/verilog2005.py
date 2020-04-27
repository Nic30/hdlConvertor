from hdlConvertor.hdlAst import HdlDirection, HdlBuiltinFn,\
    HdlCall, HdlComponentInst, HdlVariableDef, iHdlStatement,\
    HdlTypeAuto
from hdlConvertor.hdlAst._defs import HdlFunctionDef
from hdlConvertor.to.hdlUtils import Indent, iter_with_last
from hdlConvertor.to.verilog.stm import ToVerilog2005Stm


class ToVerilog2005(ToVerilog2005Stm):
    """
    Convert HdlConverotr hdlObject AST back to Verilog 2002
    """
    DIR2V = {
        HdlDirection.IN: "input",
        HdlDirection.OUT: "output",
        HdlDirection.INOUT: "inout",
    }

    def visit_doc(self, obj):
        return super(ToVerilog2005, self).visit_doc(obj, "//")

    def visit_direction(self, d):
        """
        :type d: HdlDirection
        """
        vd = self.DIR2V[d]
        self.out.write(vd)

    def visit_generic_declr(self, g):
        """
        :type g: HdlVariableDef
        """
        self.visit_doc(g)
        w = self.out.write
        w("parameter ")
        if g.type is HdlTypeAuto:
            is_array = False
        else:
            is_array = self.visit_type_first_part(g.type)
            w(" ")
        w(g.name)
        if is_array:
            self.visit_type_array_part(g.type)
        v = g.value
        if v is not None:
            w(" = ")
            self.visit_iHdlExpr(v)

    def visit_port_declr(self, p):
        """
        :type p: HdlVariableDef
        """
        w = self.out.write
        self.visit_doc(p)
        self.visit_direction(p.direction)
        w(" ")

        t = p.type
        if t is HdlTypeAuto:
            is_array = False
        else:
            is_array = self.visit_type_first_part(t)
            w(" ")

        w(p.name)
        if is_array:
            self.visit_type_array_part(t)

    def visit_HdlVariableDef(self, var):
        """
        :type var: HdlVariableDef
        """
        self.visit_doc(var)
        name = var.name
        t = var.type
        w = self.out.write
        if var.is_const:
            w("localparam ")
            assert var.value is not None, var.name

        if t is HdlTypeAuto:
            is_array = False
        else:
            is_array = self.visit_type_first_part(t)
            w(" ")
        w(name)
        if is_array:
            self.visit_type_array_part(t)

        if var.value is not None:
            w(" = ")
            self.visit_iHdlExpr(var.value)

    def visit_map_item(self, item):
        if isinstance(item, HdlCall)\
                and item.fn == HdlBuiltinFn.MAP_ASSOCIATION:
            w = self.out.write
            # k, v pair
            k, v = item.ops
            w(".")
            self.visit_iHdlExpr(k)
            w("(")
            self.visit_iHdlExpr(v)
            w(")")
        else:
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

    def visit_HdlComponentInst(self, c):
        """
        :type c: HdlComponentInst
        """
        self.visit_doc(c)
        w = self.out.write
        assert c.module_name
        self.visit_iHdlExpr(c.module_name)
        gms = c.param_map
        if gms:
            w(" #(\n")
            self.visit_map(gms)
            w(")")
        w(" ")
        w(c.name.val)
        pms = c.port_map
        if pms:
            w(" (\n")
            self.visit_map(pms)
            w(")")

    def visit_HdlFunctionDef(self, o):
        """
        :type o: HdlFunctionDef
        """
        self.visit_doc(o)
        w = self.out.write
        if o.is_task:
            w("task ")
        else:
            w("function ")
        if not o.is_static:
            w("automatic ")

        if not o.is_task:
            self.visit_type_first_part(o.return_t)
            self.visit_type_array_part(o.return_t)

        if o.is_virtual or o.is_operator:
            raise NotImplementedError(o)
        w(" ")
        w(o.name)
        ps = o.params
        if ps:
            w(" (\n")
            with Indent(self.out):
                for last, p in iter_with_last(ps):
                    self.visit_port_declr(p)
                    if last:
                        w("\n")
                    else:
                        w(",\n")
            w(")")
        w(";\n")
        with Indent(self.out):
            for s in o.body:
                if isinstance(s, HdlVariableDef):
                    self.visit_HdlVariableDef(s)
                    w(";\n")
                elif isinstance(s, iHdlStatement):
                    need_semi = self.visit_iHdlStatement(s)
                    if need_semi:
                        w(";\n")
                    else:
                        w("\n")
                else:
                    self.visit_iHdlExpr(s)
                    w(";\n")

        if o.is_task:
            w("endtask")
        else:
            w("endfunction")

    def visit_HdlModuleDec(self, e):
        raise ValueError(self, "does not support a module headers without body")

    def visit_HdlModuleDef(self, a):
        """
        :type a: HdlModuleDef
        """
        e = a.dec
        assert e is not None, a
        self.visit_doc(e)
        w = self.out.write
        w("module ")
        w(e.name)
        gs = e.params
        if gs:
            w(" #(\n")
            with Indent(self.out):
                for last, g in iter_with_last(gs):
                    self.visit_generic_declr(g)
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
                    self.visit_port_declr(p)
                    if last:
                        w("\n")
                    else:
                        w(",\n")
            w(")")
        w(";\n")

        w = self.out.write
        with Indent(self.out):
            for o in a.objs:
                if isinstance(o, HdlVariableDef):
                    self.visit_HdlVariableDef(o)
                    w(";\n")
                elif isinstance(o, HdlComponentInst):
                    self.visit_HdlComponentInst(o)
                    w(";\n\n")
                elif isinstance(o, iHdlStatement):
                    need_semi = self.visit_iHdlStatement(o)
                    if need_semi:
                        w(";\n")
                    else:
                        w("\n\n")
                elif isinstance(o, HdlFunctionDef):
                    self.visit_HdlFunctionDef(o)
                    w("\n\n")
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
    tv = ToVerilog2005(sys.stdout)
    tv.visit_HdlContext(d)
