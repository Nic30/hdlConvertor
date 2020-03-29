from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, HdlAll,\
    HdlCall, HdlTypeAuto
from hdlConvertor.to.common import ToHdlCommon
from hdlConvertor.to.hdlUtils import is_str, iter_with_last


class ToBasicHdlSimModelExpr(ToHdlCommon):
    GENERIC_BIN_OPS = {
        HdlBuiltinFn.AND: "&",
        # HdlBuiltinFn.LOG_AND: "&&",
        HdlBuiltinFn.OR: "|",
        # HdlBuiltinFn.LOG_OR: "||",
        HdlBuiltinFn.SUB: "-",
        HdlBuiltinFn.ADD: "+",
        HdlBuiltinFn.MUL: "*",
        HdlBuiltinFn.DIV: "//",
        # HdlBuiltinFn.MOD: "%",
        # HdlBuiltinFn.NAND: "~&",
        # HdlBuiltinFn.NOR: "~|",
        HdlBuiltinFn.XOR: "^",
        # HdlBuiltinFn.XNOR: "~^",
        # HdlBuiltinFn.EQ: '==',
        HdlBuiltinFn.NEQ: "!=",
        HdlBuiltinFn.LT: "<",
        HdlBuiltinFn.LE: "<=",
        HdlBuiltinFn.GT: ">",
        HdlBuiltinFn.GE: ">=",
        HdlBuiltinFn.SLL: "<<",
        HdlBuiltinFn.SRL: ">>",
    }

    def print_iHdlExpr(self, expr):
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
        elif isinstance(expr, HdlCall):
            pe = self.print_iHdlExpr

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
            elif op == HdlBuiltinFn.NEG:
                w("~")
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
                for is_last, o_n in iter_with_last(o.ops[1:]):
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
