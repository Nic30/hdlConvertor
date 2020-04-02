from hdlConvertor.hdlAst._bases import iHdlStatement
from hdlConvertor.hdlAst._expr import HdlCall, HdlBuiltinFn
from hdlConvertor.hdlAst._statements import HdlStmBlock
from hdlConvertor.to.hdlUtils import iter_with_last, Indent
from hdlConvertor.to.vhdl.expr import ToVhdl2008Expr


class ToVhdl2008Stm(ToVhdl2008Expr):

    def visit_assert(self, args):
        """
        :type args: List[iHdlExpr]
        """
        w = self.out.write
        w("ASSERT ")
        for is_last, (prefix, a) in iter_with_last(
                zip(("", "REPORT ", "SEVERITY "), args)):
            w(prefix)
            self.visit_iHdlExpr(a)
            if not is_last:
                w(" ")

    def visit_report(self, args):
        """
        :type args: List[iHdlExpr]
        """
        w = self.out.write
        w("REPORT ")
        for is_last, (prefix, a) in iter_with_last(
                zip(("", "SEVERITY "), args)):
            w(prefix)
            self.visit_iHdlExpr(a)
            if not is_last:
                w(" ")

    def visit_HdlStmProcess(self, proc):
        """
        :type proc: HdlStmProcess
        """
        sens = proc.sensitivity
        body = proc.body
        w = self.out.write

        w("PROCESS")
        if sens:
            w("(")
            for last, item in iter_with_last(sens):
                self.visit_iHdlExpr(item)
                if not last:
                    w(", ")
            w(")")
        w("\n")
        self.visit_HdlStmBlock(body, force_space_before=False)
        w(" PROCESS;\n")

    def visit_HdlStmBlock(self, stms, force_space_before=True):
        """
        :type stms: Union[List[iHdlStatement], iHdlStatement, iHdlExpr]
        :return: True if statements are wrapped in begin-end block
        """
        w = self.out.write
        if isinstance(stms, HdlStmBlock):
            must_have_begin_end = True
            stms = stms.body
        elif isinstance(stms, list):
            must_have_begin_end = len(stms) != 1
        else:
            must_have_begin_end = False
            stms = [stms, ]

        if must_have_begin_end:
            if force_space_before:
                w(" BEGIN\n")
            else:
                w("BEGIN\n")
        else:
            w("\n")

        with Indent(self.out):
            for s in stms:
                if isinstance(s, iHdlStatement):
                    self.visit_iHdlStatement(s)
                else:
                    self.visit_iHdlExpr(s)
                    w(";\n")

        if must_have_begin_end:
            w("END")
            return True

        return False

    def visit_HdlStmIf(self, stm):
        """
        :type stm: HdlStmIf
        """
        w = self.out.write
        c = stm.cond
        ifTrue = stm.if_true
        ifFalse = stm.if_false

        w("IF ")
        self.visit_iHdlExpr(c)
        w(" THEN ")
        need_space = self.visit_HdlStmBlock(ifTrue)

        for cond, stms in stm.elifs:
            if need_space:
                w(" ")
            w("ELSIF ")
            self.visit_iHdlExpr(cond)
            w(" THEN ")
            need_space = self.visit_HdlStmBlock(stms)

        if ifFalse is not None:
            if need_space:
                w(" ")
            w("ELSE")
            self.visit_HdlStmBlock(ifFalse)
        if need_space:
            w("\n")
        w("END IF;\n")

    def visit_HdlStmAssign(self, a):
        """
        :type a: HdlStmAssign
        """
        s = a.src
        d = a.dst
        w = self.out.write
        if a.time_delay is not None:
            raise NotImplementedError()
        if a.event_delay is not None:
            raise NotImplementedError()

        self.visit_iHdlExpr(d)
        w(" <= ")
        self.visit_iHdlExpr(s)
        w(";\n")

    def visit_HdlStmCase(self, cstm):
        """
        :type cstm: HdlStmCase
        """
        w = self.out.write
        w("CASE ")
        self.visit_iHdlExpr(cstm.switch_on)
        w(" IS\n")
        with Indent(self.out):
            cases = cstm.cases
            for k, stms in cases:
                w("WHEN ")
                self.visit_iHdlExpr(k)
                w(" => ")
                is_block = self.visit_HdlStmBlock(stms)
                if is_block:
                    w("\n")
            defal = cstm.default
            if defal is not None:
                is_block = w("WHEN OTHERS => ")
                self.visit_HdlStmBlock(defal)
                if is_block:
                    w("\n")
        w("END CASE;\n")

    def visit_HdlStmReturn(self, o):
        """
        :type o: HdlStmReturn
        """
        w = self.out.write
        w("RETURN")
        if o.val is not None:
            w(" ")
            self.visit_iHdlExpr(o.val)
        w(";\n")

    def visit_HdlStmContinue(self, o):
        """
        :type o: HdlStmContinue
        """
        w = self.out.write
        w("CONTINUE")

    def visit_HdlStmBreak(self, o):
        """
        :type o: HdlStmBreak
        """
        w = self.out.write
        w("BREAK")

    def visit_HdlStmFor(self, o):
        """
        :type o: HdlStmFor
        """
        w = self.out.write
        w("FOR ")
        self.visit_iHdlExpr(o.params[0])
        w(" IN ")
        self.visit_iHdlExpr(o.params[1])
        w(" LOOP\n")
        with Indent(self.out):
            for b in o.body:
                self.visit_iHdlStatement(b)
        w("END FOR;\n")

    def visit_HdlStmWait(self, o):
        """
        :type o: HdlStmWait
        """
        w = self.out.write
        w("WAIT")
        for e in o.val:
            if isinstance(e, HdlCall) and e.fn == HdlBuiltinFn.MUL:
                w(" FOR ")
                self.visit_iHdlExpr(e.ops[0])
                w(" ")
                self.visit_iHdlExpr(e.ops[1])
            else:
                w(" ON ")
                self.visit_iHdlExpr(e)
        w(";\n")
