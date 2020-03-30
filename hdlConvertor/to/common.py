from hdlConvertor.hdlAst import HdlModuleDec, HdlCall
from hdlConvertor.to.hdlUtils import AutoIndentingStream, iter_with_last, is_str
from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor
from hdlConvertor.hdlAst._expr import HdlBuiltinFn, HdlName, HdlIntValue


class ToHdlCommon(HdlAstVisitor):
    INDENT_STEP = "    "
    GENERIC_UNARY_OPS = {}
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
        self.out = AutoIndentingStream(out_stream, self.INDENT_STEP)

    def visit_doc(self, obj, line_comment_prefix):
        """
        Format doc as line comments
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

    def visit_main_obj(self, o):
        if isinstance(o, HdlModuleDec):
            w = self.out.write
            w("\n")
            self.visit_HdlModuleDec(o)
            w("\n")
        else:
            super(ToHdlCommon, self).visit_main_obj(o)

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
        ops = op.ops
        o = op.fn
        w = self.out.write

        op_str = self.GENERIC_UNARY_OPS.get(o, None)
        if op_str is not None:
            w(op_str)
            self._visit_operand(ops[0], 0, op, False, False)
            return

        op_str = self.GENERIC_BIN_OPS.get(o, None)
        if op_str is not None:
            # [todo] unary +/-
            return self._visit_bin_op(op, op_str)
        elif o == HdlBuiltinFn.INDEX:
            return self._visit_operator_index(op)
        elif o == HdlBuiltinFn.CALL:
            return self.visit_operator_call(op)
        else:
            raise NotImplementedError(
                "Do not know how to convert %s" % (o))

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        """
        w = self.out.write
        if isinstance(o, HdlName):
            w(o)
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

    def _visit_operand(self, operand, i: int,
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
                    if argc == 1:
                        pass
                    elif argc == 2:
                        if i == 0:
                            right = parent.ops[1]
                        else:
                            assert i == 1, i
                            left = parent.ops[0]
                    else:
                        raise NotImplementedError(parent)

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
                    else:
                        # "operand" is left
                        if precedence_my == precedence_parent:
                            if self._precedence_of_expr(right) == precedence_my:
                                # right and left with same precedence -> parenthesis on both sides
                                # (a + b) + (c + d)
                                use_parenthesis = True
                        elif precedence_my > precedence_parent:
                            # left with higher precedence -> parenthesis for left
                            # (a + b) * c
                            # a + b + c + d = (a + b) + c + d = ((a + b) + c) + d
                            use_parenthesis = True

        w = self.out.write
        if use_parenthesis:
            w("(")
        self.visit_iHdlExpr(operand)
        if use_parenthesis:
            w(")")

    def _visit_bin_op(self, operator, op_str: str,
                      expr_requires_parenthesis=False,
                      cancel_parenthesis=False):
        """
        :type operator: HdlCall
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
        self._visit_operand(o.ops[0], 0, o, True, False)
        w = self.out.write
        w("(")
        for is_last, (o_i, _o) in iter_with_last(enumerate(o.ops[1:])):
            self._visit_operand(_o, o_i, o, False, True)
            if not is_last:
                w(", ")
        w(")")

    def visit_HdlFunctionDef_def(self, o):
        """
        :type o: HdlFunctionDef
        """
        raise TypeError("does not support HdlFunctionDef", self, o)

    def visit_HdlStmProcess(self, o, is_top=False):
        """
        :type proc: HdlStmProcess
        """
        raise TypeError("does not support HdlStmProcess", self, o)

    def visit_HdlStmCase(self, o, is_top=False):
        """
        :type o: HdlStmCase

        :return: True if requires ;\n after end
        """
        raise TypeError("does not support HdlStmCase", self, o)

    def visit_HdlStmWait(self, o, is_top=False):
        """
        :type o: HdlStmWait
        """
        raise TypeError("does not support HdlStmWait", self, o)

    def visit_HdlStmFor(self, o, is_top=False):
        """
        :type o: HdlStmFor
        """
        raise TypeError("does not support HdlStmFor", self, o)

    def visit_HdlStmForIn(self, o, is_top=False):
        """
        :type o: HdlStmForIn
        """
        raise TypeError("does not support HdlStmForIn", self, o)

    def visit_HdlStmWhile(self, o, is_top=False):
        """
        :type o: HdlStmWhile
        """
        raise TypeError("does not support HdlStmWhile", self, o)

    def visit_HdlStmAssign(self, o, is_top=False):
        """
        :type o: HdlStmAssign
        """
        raise TypeError("does not support HdlStmAssign", self, o)

