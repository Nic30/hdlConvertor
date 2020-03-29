from hdlConvertor.hdlAst._expr import HdlBuiltinFn, HdlName, HdlIntValue,\
    HdlAll, HdlCall, HdlOthers
from hdlConvertor.to.common import ToHdlCommon
from hdlConvertor.to.hdlUtils import is_str, iter_with_last, Indent


class ToVhdl2008Expr(ToHdlCommon):
    GENERIC_BIN_OPS = {
        HdlBuiltinFn.AND: "AND",
        HdlBuiltinFn.LOG_AND: "AND",
        HdlBuiltinFn.OR: "OR",
        HdlBuiltinFn.LOG_OR: "OR",
        HdlBuiltinFn.SUB: "-",
        HdlBuiltinFn.ADD: "+",
        HdlBuiltinFn.MUL: "*",
        HdlBuiltinFn.DIV: "/",
        HdlBuiltinFn.MOD: "MOD",
        HdlBuiltinFn.NAND: "NAND",
        HdlBuiltinFn.NOR: "NOR",
        HdlBuiltinFn.XOR: "XOR",
        HdlBuiltinFn.XNOR: "XNOR",
        HdlBuiltinFn.EQ: '=',
        HdlBuiltinFn.NEQ: "/=",
        HdlBuiltinFn.LT: "<",
        HdlBuiltinFn.LE: "<=",
        HdlBuiltinFn.GT: ">",
        HdlBuiltinFn.GE: ">=",
        HdlBuiltinFn.SLL: "SLL",
        HdlBuiltinFn.SRL: "SRL",
        HdlBuiltinFn.TO: "TO",
        HdlBuiltinFn.DOWNTO: "DOWNTO",
        HdlBuiltinFn.ARROW: "=>",
        HdlBuiltinFn.MAP_ASSOCIATION: "=>",
        HdlBuiltinFn.RANGE: "RANGE",
    }
    NUM_BASES = {
        2: "B",
        8: "O",
        16: "X",
        256: "",
    }

    def print_iHdlExpr(self, expr):
        w = self.out.write
        if isinstance(expr, HdlName):
            w(expr)
            return
        elif is_str(expr):
            w('"%s"' % expr)
            return
        elif isinstance(expr, HdlIntValue):
            v = expr.val
            bits = expr.bits
            if is_str(v):
                w('%s"%s"' % (self.NUM_BASES[expr.base], v))
                return
            if bits is None:
                if expr.base is not None:
                    if expr.base == 256:
                        w("'%s'" % str(v))
                        return
                    b = self.bases[expr.base]
                    w('%s"%"' % (b, v))
                w(str(v))
                return

            elif bits % 8 == 0:
                f = 'X"{0:0%dx}"' % (bits / 8)
            else:
                f = '"{0:0%db}"' % (bits)
            w(f.format(v))

            return
        elif isinstance(expr, HdlAll):
            w("*")
            return
        elif isinstance(expr, HdlCall):
            pe = self.print_iHdlExpr
            fn = expr.ops[0]
            if fn == HdlName("assert"):
                self.print_assert(expr.ops[1:])
                return
            elif fn == HdlName("report"):
                self.print_report(expr.ops[1:])
                return

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
            elif op == HdlBuiltinFn.NOT:
                w("!")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.NEG:
                w("~")
                pe(o.ops[0])
                return
            elif op == HdlBuiltinFn.RISING:
                w("RISIG_EDGE(")
                pe(o.ops[0])
                w(")")
                return
            elif op == HdlBuiltinFn.FALLING:
                w("FALLING_EDGE(")
                pe(o.ops[0])
                w(")")
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
            elif op == HdlBuiltinFn.INDEX or op == HdlBuiltinFn.CALL:
                pe(o.ops[0])
                w("(")
                for isLast, a in iter_with_last(o.ops[1:]):
                    pe(a)
                    if not isLast:
                        w(", ")
                w(")")
                return
            elif op == HdlBuiltinFn.DOT:
                pe(o.ops[0])
                w(".")
                pe(o.ops[1])
                return
            elif op == HdlBuiltinFn.TERNARY:
                pe(o.ops[0])
                w(" ? ")
                o0, o1 = o.ops[1:]
                pe(o0)
                w(" : ")
                pe(o1)
                return
            elif op == HdlBuiltinFn.APOSTROPHE:
                pe(o.ops[0])
                w("'")
                args = o.ops[1]
                if isinstance(args, list):
                    # aggregate
                    w("(")
                    for isLast, a in iter_with_last(args):
                        pe(a)
                        if not isLast:
                            w(", ")
                    w(")")
                else:
                    # normal attribute
                    pe(args)
                return
            else:
                raise NotImplementedError(op)
        elif expr is HdlAll:
            w("ALL")
            return
        elif isinstance(expr, list):
            w("(\n")
            with Indent(self.out):
                for is_last, elem in iter_with_last(expr):
                    self.print_iHdlExpr(elem)
                    if not is_last:
                        w(",\n")
            w(")")
            return
        elif expr is HdlAll:
            w("ALL")
            return
        elif expr is HdlOthers:
            w("OTHERS")
            return
        raise NotImplementedError(expr)
