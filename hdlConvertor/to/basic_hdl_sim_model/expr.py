from hdlConvertor.hdlAst import HdlOpType, HdlValueId, HdlValueInt, \
    HdlOp
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon, ASSOCIATIVITY
from hdlConvertor.to.hdlUtils import iter_with_last, Indent


L = ASSOCIATIVITY.L_TO_R
R = ASSOCIATIVITY.R_TO_L


class ToBasicHdlSimModelExpr(ToHdlCommon):
    OP_PRECEDENCE = {
        # TO/DOWNTO becomes a call to slice
        # HdlOpType.DOWNTO: 1,
        # HdlOpType.TO: 1,

        # note that HdlExpressions in BasicHdlSimModel
        # do not use == but ._eq()
        HdlOpType.EQ: (11, L),
        HdlOpType.NEQ: (11, L),
        HdlOpType.GT:  (11, L),
        HdlOpType.LT:  (11, L),
        HdlOpType.GE:  (11, L),
        HdlOpType.LE:  (11, L),

        HdlOpType.OR: (10, L),
        HdlOpType.XOR: (9, L),
        HdlOpType.AND: (8, L),

        HdlOpType.ADD: (7, L),
        HdlOpType.SUB: (7, L),

        HdlOpType.DIV: (6, L),
        HdlOpType.MUL: (6, L),
        HdlOpType.MOD: (6, L),

        HdlOpType.NEG_LOG: (5, L),
        HdlOpType.NEG: (5, L),
        HdlOpType.MINUS_UNARY: (5, L),
        HdlOpType.POW: (4, R),

        HdlOpType.INDEX: (1, L),

        HdlOpType.RISING: (1, L),
        HdlOpType.FALLING: (1, L),

        # concat/ternary become a call to _concat, _ternary__val function
        # HdlOpType.CONCAT: 2,
        # HdlOpType.TERNARY: 2,
        # rising/faling as ._onRisingEdge(), ._onFallingEdge()
        HdlOpType.CALL: (1, L),
        # parametrization values are parameters of component class
        # constructor
        HdlOpType.PARAMETRIZATION: (1, L),

        HdlOpType.DOT: (1, L),
    }
    _unaryEventOps = {
        HdlOpType.RISING: "._onRisingEdge()",
        HdlOpType.FALLING: "._onFallingEdge()",
    }
    GENERIC_UNARY_OPS = {
        HdlOpType.NEG_LOG: "not ",
        HdlOpType.NEG: "~",
        HdlOpType.MINUS_UNARY: "-",
    }

    GENERIC_BIN_OPS = {
        HdlOpType.AND: " & ",
        HdlOpType.OR: " | ",
        HdlOpType.XOR: " ^ ",

        HdlOpType.EQ: ' == ',
        HdlOpType.NEQ: " != ",

        HdlOpType.MUL: " * ",
        HdlOpType.DIV: " // ",
        HdlOpType.POW: " ** ",
        HdlOpType.MOD: " % ",

        HdlOpType.SLL: " << ",
        HdlOpType.SRL: " >> ",
    }
    GENERIC_BIN_OPS.update(ToHdlCommon.GENERIC_BIN_OPS)

    def visit_HdlValueInt(self, o):
        """
        :type o: HdlValueInt
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
        if isinstance(o, HdlValueId):
            w(o.val)
            return
        elif is_str(o):
            w('"%s"' % o)
            return
        elif isinstance(o, HdlValueInt):
            self.visit_HdlValueInt(o)
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
        elif isinstance(o, HdlOp):
            self.visit_HdlOp(o)
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

    def visit_HdlOp(self, o):
        """
        :type op: HdlOp
        """
        ops = o.ops
        op = o.fn
        w = self.out.write

        op_str = self._unaryEventOps.get(op, None)
        if op_str is not None:
            op0 = ops[0]
            w(op0.val)
            w(op_str)
        elif op == HdlOpType.MAP_ASSOCIATION:
            # kwargs, [todo]: dict constructor
            self._visit_operand(o.ops[0], 0, o, False, False)
            w("=")
            self._visit_operand(o.ops[1], 1, o, False, False)
        else:
            return super(ToBasicHdlSimModelExpr, self).visit_HdlOp(o)
