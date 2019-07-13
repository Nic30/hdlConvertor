from hdlConvertor.toHdlUtils import Indent, AutoIndentingStream, iter_with_last_flag, is_str
from hdlConvertor.hdlAst import HdlName, HdlDirection, HdlBuildinFn, HdlIntValue, \
    HdlCall, HdlAll, HdlStmWait, HdlStmProcess, HdlStmIf, HdlStmAssign, \
    HdlStmCase, HdlComponentInst, HdlVariableDef, iHdlStatement, HdlModuleDec, \
    HdlModuleDef, HdlStmFor, HdlStmForIn, HdlStmWhile, HdlTypeAuto

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
        l = p.is_latched
        if l:
            w("reg ")

        t = p.type
        is_array = self.print_type_first_part(t)
        if is_array:
            raise NotImplementedError(t)

        w(p.name)

    def print_module_header(self, e):
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

    def print_expr(self, expr):
        """
        :type expr: iHdlExpr
        """
        w = self.out.write
        if isinstance(expr, HdlName):
            w(expr)
            return
        elif is_str(expr):
            w('"%s"' % expr)
            return
        elif isinstance(expr, HdlIntValue):
            if expr.bits is None:
                w(str(expr.val))
            else:
                if expr.base is None:
                    f = "{0}'h{1:x}"
                else:
                    b = expr.base
                    if b == 2:
                        base_char = 'b'
                    elif b == 8:
                        base_char = 'O'
                    elif b == 10:
                        base_char = 'd'
                    elif b == 16:
                        base_char = 'h'
                    else:
                        raise NotImplementedError(b)
                    f = "{0}'" + base_char + "{1}"
                w(f.format(expr.bits, expr.val))
            return
        elif isinstance(expr, HdlName):
            w(expr.val)
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
                op_cnt = len(o.ops)
                if op_cnt == 1:
                    w("(")
                    w(symbol)
                    pe(o.ops[0])
                    w(")")
                elif op_cnt == 2:
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
                w("posedge ")
                pe(o.ops[0])
                return
            elif op == HdlBuildinFn.FALLING:
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
                w("(")
                pe(o.ops[0])
                w(") ? (")
                o0, o1 = o.ops[1:]
                pe(o0)
                w(") : (")
                pe(o1)
                w(")")
                return
            elif op == HdlBuildinFn.CALL:
                pe(o.ops[0])
                w("(")
                for is_last, o_n in iter_with_last_flag(o.ops[1:]):
                    pe(o_n)
                    if not is_last:
                        w(", ")
                w(")")
                return
            else:
                raise NotImplementedError(op)
        elif expr is HdlAll:
            w("*")
            return
        elif expr is HdlTypeAuto:
            return

        raise NotImplementedError(expr)

    def print_type_first_part(self, t):
        """
        :type t: iHdlExpr
        :return: True if the type has also the array dimension part
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
        """
        :type t: iHdlExpr
        """
        w = self.out.write
        if isinstance(t, HdlCall) and t.fn == HdlBuildinFn.INDEX:
            self.print_type_array_part(t.ops[0])
            w("[")
            self.print_expr(t.ops[1])
            w("]")

    def print_variable(self, var):
        """
        :type var: HdlVariableDef
        """
        self.print_doc(var)
        name = var.name
        t = var.type
        l = var.is_latched
        w = self.out.write
        if l:
            w("reg ")
        else:
            w("wire ")
        is_array = self.print_type_first_part(t)
        if t != WIRE:
            w(" ")
        w(name)
        if is_array:
            w(" ")
            self.print_type_array_part(t)

    def print_process(self, proc, is_top=False):
        """
        :type proc: HdlStmProcess
        """
        sens = proc.sensitivity
        body = proc.body
        w = self.out.write
        skip_first = False
        if sens is None:
            if len(body) and isinstance(body[0], HdlStmWait):
                skip_first = True
                wait = body[0]
                if is_top:
                    w("always ")
                w("#")
                assert len(wait.val) == 1
                self.print_expr(wait.val[0])
            else:
                assert is_top
                w("initial")
        else:
            if is_top:
                w("always ")
            w("@(")
            for last, item in iter_with_last_flag(sens):
                self.print_expr(item)
                if not last:
                    w(", ")
            w(")")

        if skip_first:
            _body = body[1:]
        else:
            _body = body

        # to prevent useless newline for empty always/time waits
        if _body:
            return self.print_block(_body, True)
        else:
            return True

    def print_block(self, stms, space_before):
        """
        :type stms: List[iHdlStatement]
        :type space_before: bool
        :return: True if requires ;\n after end
        """
        w = self.out.write
        stm_cnt = len(stms)
        if stm_cnt == 0:
            w("\n")
            return True
        elif stm_cnt == 1:
            w("\n")
            with Indent(self.out):
                return self.print_statement(stms[0])

        if space_before:
            w(" ")
        w("begin\n")
        with Indent(self.out):
            for s in stms:
                need_semi = self.print_statement(s)
                if need_semi:
                    w(";\n")
                else:
                    w("\n")
        w("end")
        return False

    def print_if(self, stm):
        """
        :type stm: HdlStmIf
        """
        w = self.out.write
        c = stm.cond
        ifTrue = stm.if_true
        ifFalse = stm.if_false

        w("if (")
        self.print_expr(c)
        w(")")
        need_semi = self.print_block(ifTrue, True)

        for cond, stms in stm.elifs:
            if need_semi:
                w(";\n")
            else:
                w(" ")
            w("else if (")
            self.print_expr(cond)
            w(")")
            need_semi = self.print_block(stms, True)

        if ifFalse is not None:
            if need_semi:
                w(";\n")
            else:
                w(" ")
            w("else")
            need_semi = self.print_block(ifFalse, True)
        if need_semi:
            w(";")

    def print_assignment(self, a, is_top=False):
        """
        :type a: HdlStmAssign
        :return: True if requires ;\n after end
        """
        s = a.src
        d = a.dst
        w = self.out.write
        if is_top:
            w("assign ")
            self.print_expr(d)
            w(" = ")
        else:
            self.print_expr(d)
            if a.is_blocking:
                w(" = ")
            else:
                w(" <= ")

        if a.time_delay is not None:
            w("#")
            self.print_expr(a.time_delay)
            w(" ")
        if a.event_delay is not None:
            w("@")
            if len(a.event_delay) > 1:
                w("(")
            for is_last, e in iter_with_last_flag(a.event_delay):
                self.print_expr(e)
                if not is_last:
                    w(", ")
            if len(a.event_delay) > 1:
                w(")")
            w(" ")

        self.print_expr(s)
        return True

    def print_case(self, cstm):
        """
        :type cstm: HdlStmCase

        :return: True if requires ;\n after end
        """
        w = self.out.write
        w("case(")
        self.print_expr(cstm.switch_on)
        w(")\n")
        with Indent(self.out):
            cases = cstm.cases
            for k, stms in cases:
                self.print_expr(k)
                w(":")
                need_semi = self.print_block(stms, True)
                if need_semi:
                    w(";\n")
                else:
                    w("\n")
            defal = cstm.default
            if defal is not None:
                w("default:")
                need_semi = self.print_block(defal, True)
                if need_semi:
                    w(";\n")
                else:
                    w("\n")
        w("endcase")
        return False

    def print_wait(self, o):
        """
        :type o: HdlStmWait

        :return: True if requires ;\n after end
        """
        self.print_doc(o)
        w = self.out.write
        w("#")
        assert len(o.val) == 1
        self.print_expr(o.val[0]);
        return True

    def print_for(self, o):
        """
        :type o: HdlStmFor

        :return: True if requires ;\n after end
        """
        w = self.out.write
        w("for (")
        for is_last, stm in iter_with_last_flag(o.init):
            self.print_statement(stm)
            if not is_last:
                w(", ")
        w("; ")
        self.print_expr(o.cond)
        w("; ")
        for is_last, stm in iter_with_last_flag(o.step):
            self.print_statement(stm)
            if not is_last:
                w(", ")
        w(")")
        return self.print_block(o.body, True)

    def print_for_in(self, o):
        """
        :type o: HdlStmForIn
        :return: True if requires ;\n after end
        """
        raise NotImplementedError()

    def print_while(self, o):
        """
        :type o: HdlStmWhile
        :return: True if requires ;\n after end
        """
        w = self.out.write
        w("while (")
        self.print_expr(o.cond)
        w(") ")
        return self.print_block(o.body, True)

    def print_statement(self, stm, is_top=False):
        """
        :type o: iHdlStatement
        :return: True if requires ;\n after end
        """
        # statement can be also expressin
        if isinstance(stm, iHdlStatement):
            self.print_doc(stm)

        if isinstance(stm, HdlStmProcess):
            return self.print_process(stm, is_top=is_top)
        elif isinstance(stm, HdlStmIf):
            return self.print_if(stm)
        elif isinstance(stm, HdlStmAssign):
            return self.print_assignment(stm, is_top=is_top)
        elif isinstance(stm, HdlStmCase):
            return self.print_case(stm)
        elif isinstance(stm, HdlStmWait):
            return self.print_wait(stm)
        elif isinstance(stm, HdlStmFor):
            return self.print_for(stm)
        elif isinstance(stm, HdlStmForIn):
            return self.print_for_int(stm)
        elif isinstance(stm, HdlStmWhile):
            return self.print_while(stm)
        else:
            self.print_expr(stm)
            return True

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
        assert c.module_name
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
                    w(";\n\n")
                elif isinstance(o, iHdlStatement):
                    need_semi = self.print_statement(o, is_top=True)
                    if need_semi:
                        w(";\n")
                    else:
                        w("\n\n")
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
    filenames = [os.path.join(TEST_DIR, "arbiter_tb.v")]
    #AES = os.path.join(BASE_DIR, "..", "aes")
    #files = [
    #    # "aes_cipher_top.v",
    #    # "aes_key_expand_128.v",
    #    # "aes_inv_cipher_top.v",  "aes_rcon.v",
    #    "test_bench_top.v",
    #    # "aes_inv_sbox.v",        "aes_sbox.v",
    #]
    #
    #filenames = [os.path.join(AES, f) for f in files]
    d = c.parse(filenames, Language.VERILOG, [], False, True)
    tv = ToVerilog(sys.stdout)
    tv.print_context(d)
