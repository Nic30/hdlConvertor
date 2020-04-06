from hdlConvertor.hdlAst import HdlCall
from hdlConvertor.hdlAst._expr import HdlBuiltinFn, HdlName, HdlIntValue
from hdlConvertor.to.hdlUtils import AutoIndentingStream, iter_with_last, is_str
from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor


class ToHdlCommon(HdlAstVisitor):
    INDENT_STEP = "    "
    GENERIC_UNARY_OPS = {
        HdlBuiltinFn.MINUS_UNARY: "-",
    }
    GENERIC_BIN_OPS = {
        HdlBuiltinFn.ADD: " + ",
        HdlBuiltinFn.SUB: " - ",
        HdlBuiltinFn.MUL: " * ",

        HdlBuiltinFn.LT: " < ",
        HdlBuiltinFn.LE: " <= ",
        HdlBuiltinFn.GT: " > ",
        HdlBuiltinFn.GE: " >= ",

        HdlBuiltinFn.DOT: ".",
    }

    def __init__(self, out_stream):
        super(ToHdlCommon, self).__init__()
        self.out = AutoIndentingStream(out_stream, self.INDENT_STEP)

    def visit_doc(self, obj, line_comment_prefix):
        """
        Format doc as line comments

        :type line_comment_prefix: str
        """
        doc = obj.doc
        if doc is not None:
            doc = doc.split("\n")
            w = self.out.write
            for last, d in iter_with_last(doc):
                if last and d == "":
                    break
                w(line_comment_prefix)
                w(d)
                w("\n")

    def _precedence_of_expr(self, o):
        """
        :type o: iHdlExpr
        """
        # not id or value
        if not isinstance(o, HdlCall):
            return -1

        return self.OP_PRECEDENCE[o.fn]

    def visit_HdlCall(self, op):
        """
        :type op: HdlCall
        """
        o = op.fn
        w = self.out.write
        argc = len(op.ops)
        if argc == 1:
            op_str = self.GENERIC_UNARY_OPS.get(o, None)
            if op_str is not None:
                w(op_str)
                self._visit_operand(op.ops[0], 0, op, False, False)
                return
        if argc == 2:
            op_str = self.GENERIC_BIN_OPS.get(o, None)
            if op_str is not None:
                return self._visit_bin_op(op, op_str)
        if o == HdlBuiltinFn.INDEX:
            return self._visit_operator_index(op)
        elif o == HdlBuiltinFn.CALL or o == HdlBuiltinFn.PARAMETRIZATION:
            return self.visit_operator_call(op)
        else:
            raise NotImplementedError(
                "Do not know how to convert %s argc:%d" % (o, argc))

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
        elif isinstance(o, HdlCall):
            self.visit_HdlCall(o)
            return
        else:
            raise NotImplementedError(
                "Do not know how to convert %s" % (o))

    def _visit_operand(self, operand, i,
                       parent,
                       expr_requires_parenthesis,
                       cancel_parenthesis):
        """
        :type operand: iHdlExpr
        :type i: int
        :type parent: HdlCall
        :type expr_requires_parenthesis: bool
        :type cancel_parenthesis: bool
        """
        use_parenthesis = False
        if not cancel_parenthesis:
            # resolve if the parenthesis are required
            precedence_my = self._precedence_of_expr(operand)
            if precedence_my >= 0:  # if this is an expression
                if expr_requires_parenthesis:
                    use_parenthesis = True
                else:
                    precedence_parent = self.OP_PRECEDENCE[parent.fn]
                    right = None
                    left = None
                    argc = len(parent.ops)
                    assert argc, parent
                    if argc == 1:
                        pass
                    else:
                        if i == 0:
                            right = parent.ops[1]
                        else:
                            left = parent.ops[i - 1]

                    if left is not None:  # "operand" is right
                        # same precedence -> parenthesis on right if it is expression
                        # a + (b + c)
                        # a + b + c = (a + b) + c
                        # right with lower precedence -> parenthesis for right not required
                        # a + b * c = a + (b * c)
                        # right with higher precedence -> parenthesis for right
                        # a * (b + c)
                        if precedence_my >= precedence_parent:
                            use_parenthesis = True
                    if right is not None:
                        # "operand" is left
                        if precedence_my == precedence_parent:
                            if self._precedence_of_expr(right) == precedence_my:
                                # right and left with same precedence -> parenthesis on both sides
                                # (a + b) + (c + d)
                                use_parenthesis = True
                        elif precedence_my > precedence_parent:
                            # left with higher precedence -> parenthesis for left
                            # (a + b) * c
                            # a + b + c + d = (a + b) + c + d = ((a + b) + c) +
                            # d
                            use_parenthesis = True

        w = self.out.write
        if use_parenthesis:
            w("(")
        self.visit_iHdlExpr(operand)
        if use_parenthesis:
            w(")")

    def _visit_bin_op(self, operator, op_str,
                      expr_requires_parenthesis=False,
                      cancel_parenthesis=False):
        """
        :type operator: HdlCall
        :type op_str: str
        """
        op0, op1 = operator.ops
        self._visit_operand(op0, 0, operator, expr_requires_parenthesis,
                            cancel_parenthesis)
        self.out.write(op_str)
        self._visit_operand(op1, 1, operator, expr_requires_parenthesis,
                            cancel_parenthesis)

    def _visit_operator_index(self, operator):
        """
        :type operator: HdlCall
        """
        op0, op1 = operator.ops
        self._visit_operand(op0, 0, operator, True, False)
        w = self.out.write
        w("[")
        self._visit_operand(op1, 1, operator, False, True)
        w("]")

    def visit_operator_call(self, o):
        """
        :type operator: HdlCall
        """
        self._visit_operand(o.ops[0], 0, o, False, False)
        w = self.out.write
        w("(")
        for is_last, (o_i, _o) in iter_with_last(enumerate(o.ops[1:])):
            self._visit_operand(_o, o_i, o, False, True)
            if not is_last:
                w(", ")
        w(")")

    def visit_HdlFunctionDef(self, o):
        """
        :type o: HdlFunctionDef
        """
        raise TypeError("does not support HdlFunctionDef", self, o)

    def visit_HdlStmProcess(self, o):
        """
        :type proc: HdlStmProcess
        """
        raise TypeError("does not support HdlStmProcess", self, o)

    def visit_HdlStmBlock(self, o):
        """
        :type o: HdlStmBlock
        """
        raise TypeError("does not support HdlStmBlock", self, o)

    def visit_HdlStmIf(self, o):
        """
        :type o: HdlStmIf
        """
        raise TypeError("does not support HdlStmIf", self, o)

    def visit_HdlStmCase(self, o):
        """
        :type o: HdlStmCase
        """
        raise TypeError("does not support HdlStmCase", self, o)

    def visit_HdlStmWait(self, o):
        """
        :type o: HdlStmWait
        """
        raise TypeError("does not support HdlStmWait", self, o)

    def visit_HdlStmFor(self, o):
        """
        :type o: HdlStmFor
        """
        raise TypeError("does not support HdlStmFor", self, o)

    def visit_HdlStmForIn(self, o):
        """
        :type o: HdlStmForIn
        """
        raise TypeError("does not support HdlStmForIn", self, o)

    def visit_HdlStmWhile(self, o):
        """
        :type o: HdlStmWhile
        """
        raise TypeError("does not support HdlStmWhile", self, o)

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        """
        raise TypeError("does not support HdlStmAssign", self, o)

    def visit_HdlStmRepeat(self, o):
        """
        :type o: HdlStmRepeat
        """
        raise TypeError("does not support HdlStmRepeat", self, o)

    def visit_HdlStmReturn(self, o):
        """
        :type o: HdlStmReturn
        """
        raise TypeError("does not support HdlStmReturn", self, o)

    def visit_HdlStmContinue(self, o):
        """
        :type o: HdlStmContinue
        """
        raise TypeError("does not support HdlStmContinue", self, o)

    def visit_HdlStmBreak(self, o):
        """
        :type o: HdlStmBreak
        """
        raise TypeError("does not support HdlStmBreak", self, o)
