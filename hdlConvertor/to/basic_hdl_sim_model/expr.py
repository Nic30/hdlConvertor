from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, \
    HdlCall
from hdlConvertor.to.common import ToHdlCommon
from hdlConvertor.to.hdlUtils import is_str, iter_with_last


class ToBasicHdlSimModelExpr(ToHdlCommon):
    OP_PRECEDENCE = {
        # TO/DOWNTO becomes a call to slice
        # HdlBuiltinFn.DOWNTO: 1,
        # HdlBuiltinFn.TO: 1,

        # note that HdlExpressions in BasicHdlSimModel
        # do not use == but ._eq()
        HdlBuiltinFn.EQ: 11,
        HdlBuiltinFn.NEQ: 11,
        HdlBuiltinFn.GT: 11,
        HdlBuiltinFn.LT: 11,
        HdlBuiltinFn.GE: 11,
        HdlBuiltinFn.LE: 11,

        HdlBuiltinFn.OR: 10,
        HdlBuiltinFn.XOR: 9,
        HdlBuiltinFn.AND: 8,

        HdlBuiltinFn.ADD: 7,
        HdlBuiltinFn.SUB: 7,

        HdlBuiltinFn.DIV: 6,
        HdlBuiltinFn.MUL: 6,
        HdlBuiltinFn.MOD: 6,

        HdlBuiltinFn.NEG_LOG: 5,
        HdlBuiltinFn.NEG: 5,
        HdlBuiltinFn.MINUS_UNARY: 5,
        HdlBuiltinFn.POW: 4,

        HdlBuiltinFn.DOT: 1,
        HdlBuiltinFn.RISING: 1,
        HdlBuiltinFn.FALLING: 1,

        HdlBuiltinFn.INDEX: 1,

        # concat/ternary become a call to _concat, _ternary__val function
        # HdlBuiltinFn.CONCAT: 2,
        # HdlBuiltinFn.TERNARY: 2,
        # rising/faling as ._onRisingEdge(), ._onFallingEdge()
        HdlBuiltinFn.CALL: 1,
        # parametrization values are parameters of component class
        # constructor
        HdlBuiltinFn.PARAMETRIZATION: 1,
    }
    _unaryEventOps = {
        HdlBuiltinFn.RISING: "._onRisingEdge()",
        HdlBuiltinFn.FALLING: "._onFallingEdge()",
    }
    GENERIC_UNARY_OPS = {
        HdlBuiltinFn.NEG_LOG: "~",
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
                if b == 2:
                    f = "0b{0:b}"
                elif b == 8:
                    f = "0o{0:o}"
                elif b == 16:
                    f = "0x{0:x}"
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
        elif isinstance(o, list):
            with_nl = len(o) > 3
            w("(")
            for is_last, elem in iter_with_last(o):
                self.visit_iHdlExpr(elem)
                if not is_last:
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

        raise NotImplementedError(o)

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
