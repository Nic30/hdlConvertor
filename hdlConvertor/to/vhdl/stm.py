from hdlConvertor.hdlAst._bases import iHdlStatement
from hdlConvertor.hdlAst._expr import HdlCall, HdlBuiltinFn
from hdlConvertor.hdlAst._statements import HdlStmBlock
from hdlConvertor.to.hdlUtils import iter_with_last, Indent
from hdlConvertor.to.vhdl.expr import ToVhdl2008Expr


class ToVhdl2008Stm(ToVhdl2008Expr):

    def print_assert(self, args):
        """
        :type args: List[iHdlExpr]
        """
        w = self.out.write
        w("ASSERT ")
        for is_last, (prefix, a) in iter_with_last(
                zip(("", "REPORT ", "SEVERITY "), args)):
            w(prefix)
            self.print_iHdlExpr(a)
            if not is_last:
                w(" ")

    def print_report(self, args):
        """
        :type args: List[iHdlExpr]
        """
        w = self.out.write
        w("REPORT ")
        for is_last, (prefix, a) in iter_with_last(
                zip(("", "SEVERITY "), args)):
            w(prefix)
            self.print_iHdlExpr(a)
            if not is_last:
                w(" ")

    def print_HdlStmProcess(self, proc):
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
                self.print_iHdlExpr(item)
                if not last:
                    w(", ")
            w(")")
        w("\n")
        self.print_HdlStmBlock(body, force_space_before=False)
        w(" PROCESS;\n")

    def print_HdlStmBlock(self, stms, force_space_before=True):
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
                    self.print_iHdlStatement(s)
                else:
                    self.print_iHdlExpr(s)
                    w(";\n")

        if must_have_begin_end:
            w("END")
            return True

        return False

    def print_HdlStmIf(self, stm):
        """
        :type stm: HdlStmIf
        """
        w = self.out.write
        c = stm.cond
        ifTrue = stm.if_true
        ifFalse = stm.if_false

        w("IF ")
        self.print_iHdlExpr(c)
        w(" THEN ")
        need_space = self.print_HdlStmBlock(ifTrue)

        for cond, stms in stm.elifs:
            if need_space:
                w(" ")
            w("ELSIF ")
            self.print_iHdlExpr(cond)
            w(" THEN ")
            need_space = self.print_HdlStmBlock(stms)

        if ifFalse is not None:
            if need_space:
                w(" ")
            w("ELSE")
            self.print_HdlStmBlock(ifFalse)
        if need_space:
            w("\n")
        w("END IF;\n")

    def print_HdlStmAssign(self, a):
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

        self.print_iHdlExpr(d)
        w(" <= ")
        self.print_iHdlExpr(s)
        w(";\n")

    def print_HdlStmCase(self, cstm):
        """
        :type cstm: HdlStmCase
        """
        w = self.out.write
        w("CASE ")
        self.print_iHdlExpr(cstm.switch_on)
        w(" IS\n")
        with Indent(self.out):
            cases = cstm.cases
            for k, stms in cases:
                w("WHEN ")
                self.print_iHdlExpr(k)
                w(" => ")
                is_block = self.print_HdlStmBlock(stms)
                if is_block:
                    w("\n")
            defal = cstm.default
            if defal is not None:
                is_block = w("WHEN OTHERS => ")
                self.print_HdlStmBlock(defal)
                if is_block:
                    w("\n")
        w("END CASE;\n")

    def print_return(self, o):
        """
        :type o: HdlStmReturn
        """
        w = self.out.write
        w("RETURN")
        if o.val is not None:
            w(" ")
            self.print_iHdlExpr(o.val)
        w(";\n")

    def print_HdlStmFor(self, o):
        """
        :type o: HdlStmFor
        """
        w = self.out.write
        w("FOR ")
        self.print_iHdlExpr(o.params[0])
        w(" IN ")
        self.print_iHdlExpr(o.params[1])
        w(" LOOP\n")
        with Indent(self.out):
            for b in o.body:
                self.print_iHdlStatement(b)
        w("END FOR;\n")

    def print_HdlStmWait(self, o):
        """
        :type o: HdlStmWait
        """
        w = self.out.write
        w("WAIT")
        for e in o.val:
            if isinstance(e, HdlCall) and e.fn == HdlBuiltinFn.MUL:
                w(" FOR ")
                self.print_iHdlExpr(e.ops[0])
                w(" ")
                self.print_iHdlExpr(e.ops[1])
            else:
                w(" ON ")
                self.print_iHdlExpr(e)
        w(";\n")
