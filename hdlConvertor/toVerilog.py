from hdlConvertor.toHdlUtils import Indent, AutoIndentingStream, iter_with_last_flag
from hdlConvertor.hdlAst import *

WIRE = HdlName('wire')


class ToVerilog():
    """
    Convert hdlObject AST back to Verilog 2002
    """
    INDENT_STEP = "    "
    DIR2V = {
        HdlDirection.IN: "input",
        HdlDirection.OUT: "output",
        HdlDirection.INOUT: "inout",
    }

    GENERIC_BIN_OPS = {
        HdlBuildinFn.AND: "&",
        HdlBuildinFn.LOG_AND: "&&",
        HdlBuildinFn.OR: "|",
        HdlBuildinFn.LOG_OR: "||",
        HdlBuildinFn.SUB: "-",
        HdlBuildinFn.ADD: "+",
        HdlBuildinFn.MUL: "*",
        HdlBuildinFn.DIV: "/",
        HdlBuildinFn.MOD: "%",
        HdlBuildinFn.NAND: "~&",
        HdlBuildinFn.NOR: "~|",
        HdlBuildinFn.XOR: "^",
        HdlBuildinFn.XNOR: "~^",
        HdlBuildinFn.EQ: '==',
        HdlBuildinFn.NEQ: "!=",
        HdlBuildinFn.LT: "<",
        HdlBuildinFn.LE: "<=",
        HdlBuildinFn.GT: ">",
        HdlBuildinFn.GE: ">=",
        HdlBuildinFn.SLL: "<<",
        HdlBuildinFn.SRL: ">>",
    }

    def __init__(self, out_stream):
        self.out = AutoIndentingStream(out_stream, self.INDENT_STEP)

    def print_doc(self, obj):
        doc = obj.doc
        if doc is not None:
            doc = doc.split("\n")
            w = self.out.write
            for last, d in iter_with_last_flag(doc):
                if last and d == "":
                    break
                w("//")
                w(d)
                w("\n")

    def print_direction(self, d):
        vd = self.DIR2V[d]
        self.out.write(vd)

    def print_generic_declr(self, g):
        self.print_doc(g)
        w = self.out.write
        w("parameter ")
        is_array = self.print_type_first_part(g.type)
        w(" ")
        w(g.name)
        v = g.value
        if v:
            w(" = ")
            self.print_expr(v)

    def print_port_declr(self, p):
        """
        :type p: HdlVariableDef
        """
        w = self.out.write
        self.print_doc(p)
        self.print_direction(p.direction)
        w(" ")
        l = p.latched
        if l:
            w("reg ")

        t = p.type
        is_array = self.print_type_first_part(t)
        if is_array:
            raise NotImplementedError(t)

        w(p.name)

    def print_module_header(self, e):
        self.print_doc(e)
        w = self.out.write
        w("module ")
        w(e.name)
        gs = e.params
        if gs:
            w(" #(\n")
            with Indent(self.out):
                for last, g in iter_with_last_flag(gs):
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
                for last, p in iter_with_last_flag(ps):
                    self.print_port_declr(p)
                    if last:
                        w("\n")
                    else:
                        w(",\n")
            w(")")
        w(";\n")

    def print_expr(self, expr, sensitivity=False):
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
            else:
                w(str(bits))
                w("'h")
                w("%x" % v)
            return
        elif isinstance(expr, HdlName):
            w(v)
            return
        elif isinstance(expr, HdlAll):
            w("*")
            return
        elif isinstance(expr, HdlCall):
            def pe(e):
                return self.print_expr(e, sensitivity=sensitivity)

            o = expr
            op = expr.fn
            symbol = self.GENERIC_BIN_OPS.get(op, None)
            if symbol is not None:
                if sensitivity and op == HdlBuildinFn.OR:
                    symbol = "or"
                w("(")
                pe(o.ops[0])
                w(" ")
                w(symbol)
                w(" ")
                pe(o.ops[1])
                w(")")
                return
            if op == HdlBuildinFn.DOWNTO:
                pe(o.ops[0])
                w(":")
                pe(o.ops[1])
                return
            elif op == HdlBuildinFn.TO:
                pe(o.ops[1])
                w(":")
                pe(o.ops[0])
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
                assert sensitivity
                w("posedge ")
                pe(o.ops[0])
                return
            elif op == HdlBuildinFn.FALLING:
                assert sensitivity
                w("negedge ")
                pe(o.ops[0])
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
                w("[")
                pe(o.ops[1])
                w("]")
                return
            elif op == HdlBuildinFn.REPL_CONCAT:
                w("{(")
                pe(o.ops[0])
                w("){")
                pe(o.ops[1])
                w("}}")
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
            w("*")
            return

        raise NotImplementedError(expr)

    def print_type_first_part(self, t):
        """
        :return: True if the type has also the array dimmension part
        """
        w = self.out.write
        if t != WIRE:
            op = t if isinstance(t, HdlCall) else None
            if op is None:
                self.print_expr(t)
                return False

            if op and op.fn == HdlBuildinFn.CALL and op.ops[0] == WIRE:
                # 1D vector
                w("[")
                ops = op.ops[1:]
                size_expr = ops[0]
                is_signed = bool(ops[1])
                if is_signed:
                    raise NotImplementedError(op)
                self.print_expr(size_expr)
                w("] ")
            else:
                o = op.fn
                if o == HdlBuildinFn.INDEX:
                    self.print_type_first_part(op.ops[0])
                    return True
                raise NotImplementedError(op)

        return False

    def print_type_array_part(self, t):
        w = self.out.write
        if isinstance(t, HdlCall) and t.fn == HdlBuildinFn.INDEX:
            self.print_type_array_part(t.ops[0])
            w("[")
            self.print_expr(t.ops[1])
            w("]")

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

        w("always @ (")
        for last, item in iter_with_last_flag(sens):
            self.print_expr(item, sensitivity=True)
            if not last:
                w(", ")
        w(") begin\n")
        with Indent(self.out):
            for stm in body:
                self.print_statement(stm)

        w("end\n")

    def print_block(self, stms):
        """
        :return: True if statements are wrapped in begin-end block
        """
        w = self.out.write
        if len(stms) != 1:
            w(" begin\n")
        else:
            w("\n")

        with Indent(self.out):
            for s in stms:
                self.print_statement(s)

        if len(stms) != 1:
            w("end")
            return True
        return False

    def print_if(self, stm):
        w = self.out.write
        c = stm.cond
        ifTrue = stm.if_true
        ifFalse = stm.if_false

        w("if (")
        self.print_expr(c)
        w(")")
        need_space = self.print_block(ifTrue)

        for cond, stms in stm.elifs:
            if need_space:
                w(" ")
            w("else if (")
            self.print_expr(cond)
            w(")")
            need_space = self.print_block(stms)

        if ifFalse is not None:
            if need_space:
                w(" ")
            w("else")
            self.print_block(ifFalse)
        if need_space:
            w("\n")

    def print_assignment(self, a, is_top=False):
        s = a.src
        d = a.dst
        w = self.out.write
        if is_top:
            w("assign ")
            self.print_expr(d)
            w(" = ")
            self.print_expr(s)
        else:
            self.print_expr(d)
            w(" <= ")
            self.print_expr(s)
        w(";\n")

    def print_case(self, cstm):
        w = self.out.write
        w("case(")
        self.print_expr(cstm.switch_on)
        w(")\n")
        with Indent(self.out):
            cases = cstm.cases
            for k, stms in cases:
                self.print_expr(k)
                w(":")
                is_block = self.print_block(stms)
                if is_block:
                    w("\n")
            defal = cstm.default
            if defal is not None:
                is_block = w("default:")
                self.print_block(defal)
                if is_block:
                    w("\n")
        w("endcase\n")

    def print_statement(self, stm, is_top=False):
        self.print_doc(stm)
        if isinstance(stm, HdlProcessStm):
            self.print_process(stm)
        elif isinstance(stm, HdlIfStm):
            self.print_if(stm)
        elif isinstance(stm, HdlAssignStm):
            self.print_assignment(stm, is_top=is_top)
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
        with Indent(self.out):
            for o in a.objs:
                if isinstance(o, HdlVariableDef):
                    self.print_variable(o)
                    w(";\n")
                elif isinstance(o, HdlComponentInst):
                    self.print_component_instance(o)
                    w("\n")
                elif isinstance(o, iHdlStatement):
                    self.print_statement(o, is_top=True)
                else:
                    raise NotImplementedError(o)

        self.out.write("endmodule\n")

    def print_context(self, context):
        """
        :type context: HdlContext
        """
        last = None
        for o in context.objs:
            if isinstance(o, HdlModuleDec):
                self.print_module_header(o)
            elif isinstance(o, HdlModuleDef):
                assert isinstance(last, HdlModuleDec) \
                        and o.module_name == last.name, (last, o)
                self.print_module_body(o)
            else:
                raise NotImplementedError(o)

            last = o


if __name__ == "__main__":
    import os
    import sys
    BASE_DIR = os.path.join(os.path.dirname(__file__), "..")
    TEST_DIR = os.path.join(BASE_DIR, 'tests', 'verilog')
    from hdlConvertor.language import Language
    from hdlConvertor import HdlConvertor
    c = HdlConvertor()
    # filenames = [os.path.join(TEST_DIR, "sram.v")]
    filenames = [os.path.join(TEST_DIR, "fifo_rx.v")]
    d = c.parse(filenames, Language.VERILOG, [], False, False)
    tv = ToVerilog(sys.stdout)
    tv.print_context(d)
