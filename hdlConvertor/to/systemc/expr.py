from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, \
    HdlCall
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon, ASSOCIATIVITY
from hdlConvertor.to.basic_hdl_sim_model.expr import ToBasicHdlSimModelExpr
from hdlConvertor.to.hdlUtils import iter_with_last


L = ASSOCIATIVITY.L_TO_R
R = ASSOCIATIVITY.R_TO_L


class ToSystemcExpr(ToHdlCommon):
    OP_PRECEDENCE = {
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
    GENERIC_UNARY_OPS = {
        HdlBuiltinFn.NEG_LOG: "!",
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
        HdlBuiltinFn.DIV: " / ",
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
        return ToBasicHdlSimModelExpr.visit_HdlIntValue(self, o)

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        """
        w = self.out.write
        if isinstance(o, HdlName):
            w(o.val)
        elif is_str(o):
            w('"%s"' % o)
        elif isinstance(o, HdlIntValue):
            self.visit_HdlIntValue(o)
        elif isinstance(o, (list, tuple)):
            with_nl = len(o) > 3
            if isinstance(o, list):
                begin = "{"
                end = "}"
            else:
                begin = "("
                end = ")"

            w(begin)
            for elem in o:
                self.visit_iHdlExpr(elem)
                if with_nl:
                    w(", \n")
                else:
                    w(", ")
            w(end)
        elif isinstance(o, HdlCall):
            self.visit_HdlCall(o)
        elif o is None:
            w("nullptr")
        else:
            raise NotImplementedError(o.__class__, o)
        return True

    def visit_HdlCall(self, op):
        """
        :type o: HdlCall
        """

        w = self.out.write
        o = op.fn
        if o == HdlBuiltinFn.RISING:
            self._visit_operand(op.ops[0], 0, op, False, False)
            w(".pos()")
        elif o == HdlBuiltinFn.FALLING:
            self._visit_operand(op.ops[0], 0, op, False, False)
            w(".neg()")
        elif o == HdlBuiltinFn.PARAMETRIZATION:
            self._visit_operand(op.ops[0], 0, op, False, False)
            w("<")
            for last, _o in iter_with_last(op.ops[1:]):
                self.visit_iHdlExpr(_o)
                if not last:
                    w(", ")
            w(">")
        else:
            ToHdlCommon.visit_HdlCall(self, op)
        return True
