from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, \
    HdlCall
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon, ASSOCIATIVITY
from hdlConvertor.to.hdlUtils import iter_with_last, Indent


L = ASSOCIATIVITY.L_TO_R
R = ASSOCIATIVITY.R_TO_L


class ToBasicHdlSimModelExpr(ToHdlCommon):
    OP_PRECEDENCE = {
        # TO/DOWNTO becomes a call to slice
        # HdlBuiltinFn.DOWNTO: 1,
        # HdlBuiltinFn.TO: 1,

        # note that HdlExpressions in BasicHdlSimModel
        # do not use == but ._eq()
        HdlBuiltinFn.EQ: (11, L),
        HdlBuiltinFn.NEQ: (11, L),
        HdlBuiltinFn.GT:  (11, L),
        HdlBuiltinFn.LT:  (11, L),
        HdlBuiltinFn.GE:  (11, L),
        HdlBuiltinFn.LE:  (11, L),

        HdlBuiltinFn.OR: (10, L),
        HdlBuiltinFn.XOR: (9, L),
        HdlBuiltinFn.AND: (8, L),

        HdlBuiltinFn.ADD: (7, L),
        HdlBuiltinFn.SUB: (7, L),

        HdlBuiltinFn.DIV: (6, L),
        HdlBuiltinFn.MUL: (6, L),
        HdlBuiltinFn.MOD: (6, L),

        HdlBuiltinFn.NEG_LOG: (5, L),
        HdlBuiltinFn.NEG: (5, L),
        HdlBuiltinFn.MINUS_UNARY: (5, L),
        HdlBuiltinFn.POW: (4, R),

        HdlBuiltinFn.INDEX: (3, L),

        HdlBuiltinFn.RISING: (2, L),
        HdlBuiltinFn.FALLING: (2, L),

        # concat/ternary become a call to _concat, _ternary__val function
        # HdlBuiltinFn.CONCAT: 2,
        # HdlBuiltinFn.TERNARY: 2,
        # rising/faling as ._onRisingEdge(), ._onFallingEdge()
        HdlBuiltinFn.CALL: (2, L),
        # parametrization values are parameters of component class
        # constructor
        HdlBuiltinFn.PARAMETRIZATION: (2, L),

        HdlBuiltinFn.DOT: (1, L),
    }
    _unaryEventOps = {
        HdlBuiltinFn.RISING: "._onRisingEdge()",
        HdlBuiltinFn.FALLING: "._onFallingEdge()",
    }
    GENERIC_UNARY_OPS = {
        HdlBuiltinFn.NEG_LOG: "not ",
        HdlBuiltinFn.NEG: "~",
        HdlBuiltinFn.MINUS_UNARY: "-",
    }

    GENERIC_BIN_OPS = {
        HdlBuiltinFn.AND: " & ",
        HdlBuiltinFn.OR: " | ",
        HdlBuiltinFn.XOR: " ^ ",

        HdlBuiltinFn.EQ: ' == ',
        HdlBuiltinFn.NEQ: " != ",

        HdlBuiltinFn.MUL: " * ",
        HdlBuiltinFn.DIV: " // ",
        HdlBuiltinFn.POW: " ** ",
        HdlBuiltinFn.MOD: " % ",

        HdlBuiltinFn.SLL: " << ",
        HdlBuiltinFn.SRL: " >> ",
    }
    GENERIC_BIN_OPS.update(ToHdlCommon.GENERIC_BIN_OPS)

    def visit_HdlIntValue(self, o):
        """
        :type o: HdlIntValue
        """
        w = self.out.write
        if o.bits is None:
            w(str(o.val))
        else:
            if o.base is None:
                w(str(o.val))
            else:
                b = o.base
                if isinstance(o.val, int):
                    if b == 2:
                        f = "0b{0:b}"
                    elif b == 8:
                        f = "0o{0:o}"
                    elif b == 16:
                        f = "0x{0:x}"
                    else:
                        raise NotImplementedError(b)
                else:
                    if b == 2:
                        f = "0b{0}"
                    elif b == 8:
                        f = "0o{0}"
                    elif b == 16:
                        f = "0x{0}"
                    else:
                        raise NotImplementedError(b)

                w(f.format(o.val))

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        """
        w = self.out.write
        if isinstance(o, HdlName):
            w(o.val)
            return
        elif is_str(o):
            w('"%s"' % o)
            return
        elif isinstance(o, HdlIntValue):
            self.visit_HdlIntValue(o)
            return
        elif isinstance(o, (list, tuple)):
            with_nl = len(o) > 3
            w("(")
            for elem in o:
                self.visit_iHdlExpr(elem)
                if with_nl:
                    w(", \n")
                else:
                    w(", ")
            w(")")
            return
        elif isinstance(o, HdlCall):
            self.visit_HdlCall(o)
            return
        elif o is None:
            w("None")
            return
        elif isinstance(o, dict):
            w("{")
            with Indent(self.out):
                for last, (k, v) in iter_with_last(sorted(o.items(), key=lambda x: x[0])):
                    self.visit_iHdlExpr(k)
                    w(": ")
                    self.visit_iHdlExpr(v)
                    if not last:
                        w(",\n")
                    else:
                        w("\n")
            w("}")
            return
        raise NotImplementedError(o.__class__, o)

    def visit_HdlCall(self, o):
        """
        :type op: HdlCall
        """
        ops = o.ops
        op = o.fn
        w = self.out.write

        op_str = self._unaryEventOps.get(op, None)
        if op_str is not None:
            op0 = ops[0]
            w(op0.val)
            w(op_str)
        elif op == HdlBuiltinFn.MAP_ASSOCIATION:
            # kwargs, [todo]: dict constructor
            self._visit_operand(o.ops[0], 0, o, False, False)
            w("=")
            self._visit_operand(o.ops[1], 1, o, False, False)
        else:
            return super(ToBasicHdlSimModelExpr, self).visit_HdlCall(o)
