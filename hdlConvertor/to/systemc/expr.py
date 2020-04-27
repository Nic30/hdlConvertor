from hdlConvertor.hdlAst import HdlBuiltinFn, HdlName, HdlIntValue, \
    HdlCall
from hdlConvertor.py_ver_compatibility import is_str
from hdlConvertor.to.common import ToHdlCommon, ASSOCIATIVITY,\
    ASSIGN_OPERATORS_SYMBOLS_C
from hdlConvertor.to.basic_hdl_sim_model.expr import ToBasicHdlSimModelExpr
from hdlConvertor.to.hdlUtils import iter_with_last
from hdlConvertor.to.verilog.expr import ASSIGN_OPERATORS


L = ASSOCIATIVITY.L_TO_R
R = ASSOCIATIVITY.R_TO_L


class ToSystemcExpr(ToHdlCommon):
    # https://en.cppreference.com/w/cpp/language/operator_precedence
    OP_PRECEDENCE = {
        HdlBuiltinFn.DOUBLE_COLON: (1, L),

        HdlBuiltinFn.INCR_POST: (2, L),
        HdlBuiltinFn.DECR_POST: (2, L),
        HdlBuiltinFn.TYPE_OF: (2, L),
        HdlBuiltinFn.CALL: (2, L),
        HdlBuiltinFn.INDEX: (3, L),
        HdlBuiltinFn.DOT: (2, L),
        HdlBuiltinFn.ARROW: (2, L),
        HdlBuiltinFn.PARAMETRIZATION: (2, L),


        HdlBuiltinFn.INCR_PRE: (3, L),
        HdlBuiltinFn.DECR_PRE: (3, L),
        HdlBuiltinFn.MINUS_UNARY: (3, L),
        HdlBuiltinFn.NEG_LOG: (3, L),
        HdlBuiltinFn.NEG: (3, L),
        HdlBuiltinFn.REFERENCE: (3, L),

        HdlBuiltinFn.DIV: (5, L),
        HdlBuiltinFn.MUL: (5, L),
        HdlBuiltinFn.MOD: (5, L),

        HdlBuiltinFn.ADD: (6, L),
        HdlBuiltinFn.SUB: (6, L),

        HdlBuiltinFn.SLL: (7, L),
        HdlBuiltinFn.SRL: (7, L),

        HdlBuiltinFn.GT:  (9, L),
        HdlBuiltinFn.LT:  (9, L),
        HdlBuiltinFn.GE:  (9, L),
        HdlBuiltinFn.LE:  (9, L),

        HdlBuiltinFn.NEQ: (10, L),
        HdlBuiltinFn.EQ: (10, L),

        HdlBuiltinFn.AND: (11, L),
        HdlBuiltinFn.XOR: (12, L),
        HdlBuiltinFn.OR: (13, L),

        HdlBuiltinFn.AND_LOG: (14, L),
        HdlBuiltinFn.OR_LOG: (15, L),

        HdlBuiltinFn.TERNARY: (16, R),
    }
    OP_PRECEDENCE.update({
        k: (16, R) for k in ASSIGN_OPERATORS
    })

    GENERIC_UNARY_OPS = {
        HdlBuiltinFn.NEG_LOG: "!",
        HdlBuiltinFn.NEG: "~",
        HdlBuiltinFn.MINUS_UNARY: "-",
    }

    GENERIC_BIN_OPS = {
        HdlBuiltinFn.DOUBLE_COLON: "::",
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
    GENERIC_BIN_OPS.update(ASSIGN_OPERATORS_SYMBOLS_C)

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
                    w(f.format(o.val))
                else:
                    if b == 2:
                        f = '"0b{0}"'
                    elif b == 8:
                        f = '"0o{0}"'
                    elif b == 16:
                        f = '"0x{0}"'
                    else:
                        raise NotImplementedError(b)

                    w(f.format(o.val.upper()))

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
