from copy import copy

from hdlConvertor.toHdlUtils import Indent, AutoIndentingStream,\
    iter_with_last_flag, is_str
from hdlConvertor.hdlAst import HdlName, HdlDirection, HdlBuiltinFn,\
    HdlIntValue, HdlCall, HdlAll, HdlStmWait, HdlStmProcess, HdlStmIf,\
    HdlStmAssign, HdlStmCase, HdlComponentInst, HdlVariableDef, iHdlStatement,\
    HdlModuleDec, HdlModuleDef, HdlStmFor, HdlStmForIn, HdlStmWhile,\
    HdlTypeAuto, HdlStmBlock
from hdlConvertor.hdlAst._defs import HdlFunctionDef

PRIMITIVE_TYPES = {HdlName("reg"), HdlName("wire")}


def collect_array_dims(t):
    array_dim = []
    prev_t = t
    while isinstance(t, HdlCall) and t.fn == HdlBuiltinFn.INDEX:
        array_dim.append(t.ops[1])
        prev_t = t
        t = t.ops[0]
    if array_dim:
        if (isinstance(t, HdlName) and t in PRIMITIVE_TYPES) \
            or (isinstance(t, HdlCall)
                and t.fn == HdlBuiltinFn.PARAMETRIZATION
                and t.ops[0] in PRIMITIVE_TYPES):
            # this dimensions is actually size of the vector
            array_dim.pop()
            t = prev_t
        array_dim.reverse()
    return t, array_dim


def get_wire_t_params(t):

    t, array_dim = collect_array_dims(t)

    if t == HdlName('wire') or t == HdlName('reg'):
        return t, None, False, array_dim

    if isinstance(t, HdlCall) and t.fn == HdlBuiltinFn.INDEX:
        width = t.ops[1]
        t = t.ops[0]

    is_signed = False
    if not isinstance(t, HdlName) or t not in PRIMITIVE_TYPES:
        if not isinstance(t, HdlCall) or t.fn != HdlBuiltinFn.PARAMETRIZATION:
            return None

        if t.ops[0] != HdlName('wire') and t.ops != HdlName('reg'):
            return None

        _, is_signed = t.ops
        t = t.ops[0]

    is_signed = bool(is_signed)

    if width == 1:
        width = None

    return t, width, is_signed, array_dim


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
        HdlBuiltinFn.AND: "&",
        HdlBuiltinFn.LOG_AND: "&&",
        HdlBuiltinFn.OR: "|",
        HdlBuiltinFn.LOG_OR: "||",
        HdlBuiltinFn.SUB: "-",
        HdlBuiltinFn.ADD: "+",
        HdlBuiltinFn.MUL: "*",
        HdlBuiltinFn.DIV: "/",
        HdlBuiltinFn.MOD: "%",
        HdlBuiltinFn.NAND: "~&",
        HdlBuiltinFn.NOR: "~|",
        HdlBuiltinFn.XOR: "^",
        HdlBuiltinFn.XNOR: "~^",
        HdlBuiltinFn.EQ: '==',
        HdlBuiltinFn.NEQ: "!=",
        HdlBuiltinFn.LT: "<",
        HdlBuiltinFn.LE: "<=",
        HdlBuiltinFn.GT: ">",
        HdlBuiltinFn.GE: ">=",
        HdlBuiltinFn.SLL: "<<",
        HdlBuiltinFn.SRL: ">>",
    }
    ASSIGN_OPS = {
        HdlBuiltinFn.ASSIGN: '=',
        HdlBuiltinFn.PLUS_ASSIGN: '+=',
        HdlBuiltinFn.MINUS_ASSIGN: '-=',
        HdlBuiltinFn.MUL_ASSIGN: '*=',
        HdlBuiltinFn.DIV_ASSIGN: '/=',
        HdlBuiltinFn.MOD_ASSIGN: '%=',
        HdlBuiltinFn.AND_ASSIGN: '&=',
        HdlBuiltinFn.OR_ASSIGN: '|=',
        HdlBuiltinFn.XOR_ASSIGN: '^=',
        HdlBuiltinFn.SHIFT_LEFT_ASSIGN: '<<=',
        HdlBuiltinFn.SHIFT_RIGHT_ASSIGN: '>>=',
        HdlBuiltinFn.ARITH_SHIFT_LEFT_ASSIGN: '<<<=',
        HdlBuiltinFn.ARITH_SHIFT_RIGHT_ASSIGN: '>>>=',
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
        if g.type is not HdlTypeAuto:
            w(" ")
        w(g.name)
        v = g.value
        if is_array:
            self.print_type_array_part(g.type)
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

        t = p.type
        is_array = self.print_type_first_part(t)
        w(" ")

        w(p.name)
        if is_array:
            self.print_type_array_part(t)

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
            symbol = self.ASSIGN_OPS.get(op, None)
            if symbol is not None:
                pe(o.ops[0])
                w(" ")
                w(symbol)
                w(" ")
                pe(o.ops[1])
                return
            if op == HdlBuiltinFn.DOWNTO:
                pe(o.ops[0])
                w(":")
                pe(o.ops[1])
                return
            elif op == HdlBuiltinFn.TO:
                pe(o.ops[1])
                w(":")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.NOT:
                w("!")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.NEG:
                w("~")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.RISING:
                w("posedge ")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.FALLING:
                w("negedge ")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.NEG:
                w("~")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.CONCAT:
                w("{")
                pe(o.ops[0])
                w(", ")
                pe(o.ops[1])
                w("}")
                return
            elif op == HdlBuiltinFn.INDEX:
                pe(o.ops[0])
                w("[")
                pe(o.ops[1])
                w("]")
                return
            elif op == HdlBuiltinFn.REPL_CONCAT:
                w("{(")
                pe(o.ops[0])
                w("){")
                pe(o.ops[1])
                w("}}")
                return
            elif op == HdlBuiltinFn.TERNARY:
                w("(")
                pe(o.ops[0])
                w(") ? (")
                o0, o1 = o.ops[1:]
                pe(o0)
                w(") : (")
                pe(o1)
                w(")")
                return
            elif op == HdlBuiltinFn.CALL:
                pe(o.ops[0])
                w("(")
                for is_last, o_n in iter_with_last_flag(o.ops[1:]):
                    pe(o_n)
                    if not is_last:
                        w(", ")
                w(")")
                return
            elif op == HdlBuiltinFn.TYPE_OF:
                w("type(")
                pe(o.ops[0])
                w(")")
                return
            else:
                raise NotImplementedError(op)
        elif expr is HdlAll:
            w("*")
            return
        elif expr is HdlTypeAuto:
            return
        elif expr is None:
            w("null")
            return

        raise NotImplementedError(expr)

    def print_type_first_part(self, t):
        """
        :type t: iHdlExpr
        :return: True if the type has also the array dimension part
        """
        w = self.out.write
        t, array_dims = collect_array_dims(t)
        wire_params = get_wire_t_params(t)
        if wire_params is None:
            if t != HdlTypeAuto:
                if isinstance(t, HdlCall) and t.fn == HdlBuiltinFn.TYPE_OF:
                    w("var ")
                self.print_expr(t)
        else:
            base_t, width, is_signed, _ = wire_params
            w(base_t)
            if width is not None:
                # 1D vector
                w("[")
                if is_signed:
                    raise NotImplementedError(t)
                self.print_expr(width)
                w("]")
        return len(array_dims) > 0

    def print_type_array_part(self, t):
        """
        :type t: iHdlExpr
        """
        w = self.out.write
        _, array_dim = collect_array_dims(t)
        for ad in array_dim:
            w("[")
            self.print_expr(ad)
            w("]")

    def print_variable(self, var):
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

    def print_process(self, proc, is_top=False):
        """
        :type proc: HdlStmProcess
        """
        sens = proc.sensitivity
        body = proc.body
        w = self.out.write
        skip_body = False
        if sens is None:
            if isinstance(body, HdlStmWait):
                skip_body = True
                wait = body
            elif (isinstance(body, HdlStmBlock)
                    and body.body
                    and isinstance(body.body[0], HdlStmWait)):
                wait = body.body[0]
                body = copy(body)
                body.body = body.body[1:]
            else:
                wait = None

            if wait is not None:
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

        # to prevent useless newline for empty always/time waits
        if skip_body:
            return True
        else:
            return self.print_statement_in_statement(body)

    def print_statement_in_statement(self, stm):
        """
        Print statement which is body of other statement
        e.g. body of process, branch of if-then-else or case of case stememnt
        """
        w = self.out.write
        if isinstance(stm, HdlStmBlock):
            if len(stm.body) == 1:
                stm = stm.body[0]
            else:
                w(" ")
                return self.print_block(stm)

        w("\n")
        with Indent(self.out):
            return self.print_statement(stm)

    def print_block(self, stm):
        """
        :type stm: HdlStmBlock
        """
        w = self.out.write

        w("begin\n")
        with Indent(self.out):
            for s in stm.body:
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
        need_semi = self.print_statement_in_statement(ifTrue)

        for cond, stms in stm.elifs:
            if need_semi:
                w(";\n")
            else:
                w(" ")
            w("else if (")
            self.print_expr(cond)
            w(")")
            need_semi = self.print_statement_in_statement(stms)

        if ifFalse is not None:
            if need_semi:
                w(";\n")
            else:
                w(" ")
            w("else")
            need_semi = self.print_statement_in_statement(ifFalse)
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
                need_semi = self.print_statement_in_statement(stms)
                if need_semi:
                    w(";\n")
                else:
                    w("\n")
            defal = cstm.default
            if defal is not None:
                w("default:")
                need_semi = self.print_statement_in_statement(defal)
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
        self.print_expr(o.val[0])
        return True

    def print_for(self, o):
        """
        :type o: HdlStmFor

        :return: True if requires ;\n after end
        """
        w = self.out.write
        w("for (")
        if isinstance(o.init, HdlStmBlock):
            init_stms = o.init.body
        else:
            init_stms = [o.init, ]

        for is_last, stm in iter_with_last_flag(init_stms):
            self.print_statement(stm)
            if not is_last:
                w(", ")
        w("; ")
        self.print_expr(o.cond)
        w("; ")
        if isinstance(o.init, HdlStmBlock):
            step_stms = o.step.body
        else:
            step_stms = [o.step, ]

        for is_last, stm in iter_with_last_flag(step_stms):
            self.print_statement(stm)
            if not is_last:
                w(", ")
        w(")")
        return self.print_statement_in_statement(o.body)

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
        elif isinstance(stm, HdlStmBlock):
            return self.print_block(stm)
        else:
            self.print_expr(stm)
            return True

    def print_map_item(self, item):
        if isinstance(item, HdlCall)\
                and item.fn == HdlBuiltinFn.MAP_ASSOCIATION:
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

    def print_function_def(self, o):
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
                for last, p in iter_with_last_flag(ps):
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
                    self.print_variable(s)
                    w(";\n")
                elif isinstance(s, iHdlStatement):
                    need_semi = self.print_statement(s)
                    if need_semi:
                        w(";\n")
                    else:
                        w("\n")
                else:
                    self.print_expr(s)
                    w(";\n")

        if o.is_task:
            w("endtask")
        else:
            w("endfunction")

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
                elif isinstance(o, HdlFunctionDef):
                    self.print_function_def(o)
                    w("\n")
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
    tv = ToVerilog(sys.stdout)
    tv.print_context(d)
