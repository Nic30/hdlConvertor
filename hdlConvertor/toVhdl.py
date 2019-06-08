from hdlConvertor.toHdlUtils import Indent, AutoIndentingStream, iter_with_last_flag
from hdlConvertor.hdlAst import *


class ToVhdl():
    """
    Convert hdlObject AST back to VHDL-1993
    """
    INDENT_STEP = "    "
    DIR2V = {
        HdlDirection.IN: "IN",
        HdlDirection.OUT: "OUT",
        HdlDirection.INOUT: "INOUT",
    }

    GENERIC_BIN_OPS = {
        HdlBuildinFn.AND: "AND",
        HdlBuildinFn.LOG_AND: "AND",
        HdlBuildinFn.OR: "OR",
        HdlBuildinFn.LOG_OR: "OR",
        HdlBuildinFn.SUB: "-",
        HdlBuildinFn.ADD: "+",
        HdlBuildinFn.MUL: "*",
        HdlBuildinFn.DIV: "/",
        HdlBuildinFn.MOD: "MOD",
        HdlBuildinFn.NAND: "NAND",
        HdlBuildinFn.NOR: "NOR",
        HdlBuildinFn.XOR: "XOR",
        HdlBuildinFn.XNOR: "XNOR",
        HdlBuildinFn.EQ: '=',
        HdlBuildinFn.NEQ: "/=",
        HdlBuildinFn.LT: "<",
        HdlBuildinFn.LE: "<=",
        HdlBuildinFn.GT: ">",
        HdlBuildinFn.GE: ">=",
        HdlBuildinFn.SLL: "SLL",
        HdlBuildinFn.SRL: "SRL",
        HdlBuildinFn.TO: "TO",
        HdlBuildinFn.DOWNTO: "DOWNTO",
    }

    def __init__(self, out_stream):
        self.out = AutoIndentingStream(out_stream, self.INDENT_STEP)
        self.used_libraries = set()

    def print_doc(self, obj):
        doc = obj.doc
        if doc is not None:
            doc = doc.split("\n")
            w = self.out.write
            for last, d in iter_with_last_flag(doc):
                if last and d == "":
                    break
                w("--")
                w(d)
                w("\n")

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
            self.print_expr(v)

    def print_module_header(self, e):
        self.print_doc(e)
        w = self.out.write
        w("ENTITY ")
        w(e.name)
        w(" IS\n")
        gs = e.params
        if gs:
            with Indent(self.out):
                w("GENERIC(\n")
                with Indent(self.out):
                    for last, g in iter_with_last_flag(gs):
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
                    for last, p in iter_with_last_flag(ps):
                        self.print_generic_or_port_declr(p)
                        if last:
                            w("\n")
                        else:
                            w(",\n")
                w(");\n")
        w("END ENTITY;\n")

    def print_expr(self, expr):
        w = self.out.write
        if isinstance(expr, HdlName):
            w(expr)
            return
        elif isinstance(expr, str):
            w('"%s"' % expr)
            return
        elif isinstance(expr, HdlIntValue):
            v = expr.val
            bits = expr.bits
            if bits is None:
                w(str(v))
            elif bits % 8 == 0:
                f = '"{0:0%dX}"' % (bits % 8)
                w(f % v)
            else:
                f = '"{0:0%db}"' % (bits)
                w(f % v)

            return
        elif isinstance(expr, HdlName):
            w(v)
            return
        elif isinstance(expr, HdlAll):
            w("*")
            return
        elif isinstance(expr, HdlCall):
            pe = self.print_expr

            o = expr
            op = expr.fn
            symbol = self.GENERIC_BIN_OPS.get(op, None)
            if symbol is not None:
                w("(")
                pe(o.ops[0])
                w(" ")
                w(symbol)
                w(" ")
                pe(o.ops[1])
                w(")")
                return
            elif op == HdlBuildinFn.NOT:
                w("!")
                pe(o.ops[0])
                return
            elif op == HdlBuildinFn.NEG:
                w("~")
                pe(o.ops[0])
                return
            elif op == HdlBuildinFn.RISING:
                w("RISIG_EDGE(")
                pe(o.ops[0])
                w(")")
                return
            elif op == HdlBuildinFn.FALLING:
                w("FALLING_EDGE(")
                pe(o.ops[0])
                w(")")
                return
            elif op == HdlBuildinFn.NEG:
                w("~")
                pe(o.ops[0])
                return
            elif op == HdlBuildinFn.CONCAT:
                w("{")
                pe(o.ops[0])
                w(", ")
                pe(o.ops[1])
                w("}")
                return
            elif op == HdlBuildinFn.INDEX:
                pe(o.ops[0])
                w("(")
                pe(o.ops[1])
                w(")")
                return
            elif op == HdlBuildinFn.DOT:
                pe(o.ops[0])
                w(".")
                pe(o.ops[1])
                return
            elif op == HdlBuildinFn.TERNARY:
                pe(o.ops[0])
                w(" ? ")
                o0, o1 = o.ops[1:]
                pe(o0)
                w(" : ")
                pe(o1)
                return
            else:
                raise NotImplementedError(op)
        elif expr is HdlAll:
            w("ALL")
            return

        raise NotImplementedError(expr)

    def print_type(self, t):
        """
        """
        self.print_expr(t)

    def print_variable(self, var):
        self.print_doc(var)
        name = var.name
        t = var.type
        l = var.latched
        w = self.out.write
        if l:
            w("reg ")
        else:
            w("wire ")
        is_array = self.print_type_first_part(t)
        w(name)
        if is_array:
            w(" ")
            self.print_type_array_part(t)

    def print_process(self, proc):
        sens = proc.sensitivity
        body = proc.body
        w = self.out.write

        w("PROCESS(")
        for last, item in iter_with_last_flag(sens):
            self.print_expr(item)
            if not last:
                w(", ")
        w(")\n")
        w("BEGIN\n")
        with Indent(self.out):
            for stm in body:
                self.print_statement(stm)

        w("END PROCESS;\n")

    def print_block(self, stms):
        """
        :return: True if statements are wrapped in begin-end block
        """
        w = self.out.write
        if len(stms) != 1:
            w(" BEGIN\n")
        else:
            w("\n")

        with Indent(self.out):
            for s in stms:
                self.print_statement(s)

        if len(stms) != 1:
            w("END")
            return True
        return False

    def print_if(self, stm):
        w = self.out.write
        c = stm.cond
        ifTrue = stm.if_true
        ifFalse = stm.if_false

        w("IF ")
        self.print_expr(c)
        w(" ")
        need_space = self.print_block(ifTrue)

        for cond, stms in stm.elifs:
            if need_space:
                w(" ")
            w("ELSE IF ")
            self.print_expr(cond)
            w(" ")
            need_space = self.print_block(stms)

        if ifFalse is not None:
            if need_space:
                w(" ")
            w("ELSE")
            self.print_block(ifFalse)
        if need_space:
            w("\n")

    def print_assignment(self, a):
        s = a.src
        d = a.dst
        w = self.out.write
        self.print_expr(d)
        w(" <= ")
        self.print_expr(s)
        w(";\n")

    def print_case(self, cstm):
        w = self.out.write
        w("CASE ")
        self.print_expr(cstm.switch_on)
        w(" IS\n")
        with Indent(self.out):
            cases = cstm.cases
            for k, stms in cases:
                w("WHEN ")
                self.print_expr(k)
                w(" => ")
                is_block = self.print_block(stms)
                if is_block:
                    w("\n")
            defal = cstm.default
            if defal is not None:
                is_block = w("WHEN OTHERS => ")
                self.print_block(defal)
                if is_block:
                    w("\n")
        w("END CASE;\n")

    def print_statement(self, stm):
        self.print_doc(stm)
        if isinstance(stm, HdlProcessStm):
            self.print_process(stm)
        elif isinstance(stm, HdlIfStm):
            self.print_if(stm)
        elif isinstance(stm, HdlAssignStm):
            self.print_assignment(stm)
        elif isinstance(stm, HdlCaseStm):
            self.print_case(stm)
        else:
            raise NotImplementedError(stm)

    def print_map_item(self, item):
        if isinstance(item, HdlCall) and item.fn == HdlBuildinFn.MAP_ASSOCIATION:
            w = self.out.write
            # k, v pair
            k, v = item.ops
            w(".")
            self.print_expr(k)
            w("(")
            self.print_expr(v)
            w(")")
        else:
            self.print_expr(item)

    def print_map(self, map_):
        w = self.out.write
        with Indent(self.out):
            for last, m in iter_with_last_flag(map_):
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
        self.print_expr(c.module_name)
        w(" ")
        self.print_expr(c.name)
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
        w(";")

    def print_module_body(self, a):
        """
        :type a: HdlModuleDef
        """
        w = self.out.write
        w("ARCHITECTURE ")
        w(a.name)
        w(" OF ")
        w(a.module_name)
        w(" IS\n")
        w("BEGIN\n")
        with Indent(self.out):
            for o in a.objs:
                if isinstance(o, HdlVariableDef):
                    self.print_variable(o)
                    w(";\n")
                elif isinstance(o, HdlComponentInst):
                    self.print_component_instance(o)
                    w("\n")
                elif isinstance(o, iHdlStatement):
                    self.print_statement(o)
                else:
                    raise NotImplementedError()

        self.out.write("END ARCHITECTURE\n")

    def print_library(self, o):
        w = self.out.write
        w("LIBRARY ")
        self.print_expr(o)
        w(";\n")

    def print_hdl_import(self, o):
        """
        :type o: HdlImport
        """
        self.print_doc(o)
        w = self.out.write
        lib_name = o.path[0]
        if lib_name not in self.used_libraries:
            self.print_library(lib_name)

        w("USE ")
        for last, p in iter_with_last_flag(o.path):
            self.print_expr(p)
            if not last:
                w(".")
        w(";\n")

    def print_context(self, context):
        """
        :type context: HdlContext
        """

        w = self.out.write
        for o in context.objs:
            if isinstance(o, HdlModuleDec):
                w("\n")
                self.print_module_header(o)
                w("\n")
            elif isinstance(o, HdlModuleDef):
                self.print_module_body(o)
            elif isinstance(o, HdlImport):
                self.print_hdl_import(o)
            else:
                raise NotImplementedError(o)


if __name__ == "__main__":
    import os
    import sys
    BASE_DIR = os.path.join(os.path.dirname(__file__), "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'vhdl')
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    c = HdlConvertor()
    filenames = [os.path.join(TEST_DIR, "mux.vhd")]
    d = c.parse(filenames, Language.VHDL, [], False, False)
    tv = ToVhdl(sys.stdout)
    tv.print_context(d)
