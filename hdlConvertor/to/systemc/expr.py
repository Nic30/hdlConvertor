from hdlConvertor.hdlAst import HdlOpType, HdlValueId, HdlValueInt, \
    HdlOp
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
        HdlOpType.DOUBLE_COLON: (1, L),

        HdlOpType.INCR_POST: (2, L),
        HdlOpType.DECR_POST: (2, L),
        HdlOpType.TYPE_OF: (2, L),
        HdlOpType.CALL: (2, L),
        HdlOpType.INDEX: (3, L),
        HdlOpType.DOT: (2, L),
        HdlOpType.ARROW: (2, L),
        HdlOpType.PARAMETRIZATION: (2, L),


        HdlOpType.INCR_PRE: (3, L),
        HdlOpType.DECR_PRE: (3, L),
        HdlOpType.MINUS_UNARY: (3, L),
        HdlOpType.NEG_LOG: (3, L),
        HdlOpType.NEG: (3, L),
        HdlOpType.REFERENCE: (3, L),

        HdlOpType.DIV: (5, L),
        HdlOpType.MUL: (5, L),
        HdlOpType.MOD: (5, L),

        HdlOpType.ADD: (6, L),
        HdlOpType.SUB: (6, L),

        HdlOpType.SLL: (7, L),
        HdlOpType.SRL: (7, L),

        HdlOpType.GT:  (9, L),
        HdlOpType.LT:  (9, L),
        HdlOpType.GE:  (9, L),
        HdlOpType.LE:  (9, L),

        HdlOpType.NEQ: (10, L),
        HdlOpType.EQ: (10, L),

        HdlOpType.AND: (11, L),
        HdlOpType.XOR: (12, L),
        HdlOpType.OR: (13, L),

        HdlOpType.AND_LOG: (14, L),
        HdlOpType.OR_LOG: (15, L),

        HdlOpType.TERNARY: (16, R),
    }
    OP_PRECEDENCE.update({
        k: (16, R) for k in ASSIGN_OPERATORS
    })

    GENERIC_UNARY_OPS = {
        HdlOpType.NEG_LOG: "!",
        HdlOpType.NEG: "~",
        HdlOpType.MINUS_UNARY: "-",
    }

    GENERIC_BIN_OPS = {
        HdlOpType.DOUBLE_COLON: "::",
        HdlOpType.AND: " & ",
        HdlOpType.OR: " | ",
        HdlOpType.XOR: " ^ ",

        HdlOpType.EQ: ' == ',
        HdlOpType.NEQ: " != ",

        HdlOpType.MUL: " * ",
        HdlOpType.DIV: " / ",
        HdlOpType.POW: " ** ",
        HdlOpType.MOD: " % ",

        HdlOpType.SLL: " << ",
        HdlOpType.SRL: " >> ",
    }
    GENERIC_BIN_OPS.update(ToHdlCommon.GENERIC_BIN_OPS)
    GENERIC_BIN_OPS.update(ASSIGN_OPERATORS_SYMBOLS_C)

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
        if isinstance(o, HdlValueId):
            w(o.val)
        elif is_str(o):
            w('"%s"' % o)
        elif isinstance(o, HdlValueInt):
            self.visit_HdlValueInt(o)
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
        elif isinstance(o, HdlOp):
            self.visit_HdlOp(o)
        elif o is None:
            w("nullptr")
        else:
            raise NotImplementedError(o.__class__, o)
        return True

    def visit_HdlOp(self, op):
        """
        :type o: HdlOp
        """

        w = self.out.write
        o = op.fn
        if o == HdlOpType.RISING:
            self._visit_operand(op.ops[0], 0, op, False, False)
            w(".pos()")
        elif o == HdlOpType.FALLING:
            self._visit_operand(op.ops[0], 0, op, False, False)
            w(".neg()")
        elif o == HdlOpType.PARAMETRIZATION:
            self._visit_operand(op.ops[0], 0, op, False, False)
            w("<")
            for last, _o in iter_with_last(op.ops[1:]):
                self.visit_iHdlExpr(_o)
                if not last:
                    w(", ")
            w(">")
        else:
            ToHdlCommon.visit_HdlOp(self, op)
        return True
