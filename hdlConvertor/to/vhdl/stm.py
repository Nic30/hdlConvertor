from hdlConvertor.hdlAst._bases import iHdlStatement
from hdlConvertor.hdlAst._defs import HdlIdDef
from hdlConvertor.hdlAst._expr import HdlOp, HdlOpType
from hdlConvertor.hdlAst._statements import HdlStmBlock
from hdlConvertor.to.hdlUtils import iter_with_last, Indent, UnIndent
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

    def visit_HdlStmProcess(self, o):
        """
        :type proc: HdlStmProcess
        """
        self.visit_doc(o)
        sens = o.sensitivity
        w = self.out.write
        if o.labels:
            w(o.labels[0])
            w(": ")
        w("PROCESS")
        if sens:
            w("(")
            for last, item in iter_with_last(sens):
                self.visit_iHdlExpr(item)
                if not last:
                    w(", ")
            w(")")
        w("\n")
        self.visit_HdlStmBlock(o.body, force_space_before=False, force_begin_end=True)
        w(" PROCESS;\n")

    def _write_begin(self, begin_end, must_have_begin_end, force_space_before):
        w = self.out.write
        if begin_end and must_have_begin_end:
            if force_space_before:
                w(" BEGIN\n")
            else:
                w("BEGIN\n")
        else:
            w("\n")

    def visit_HdlStmBlock(self, stms, force_space_before=True, begin_end=True, force_begin_end=False):
        """
        :type stms: Union[List[iHdlStatement], iHdlStatement, iHdlExpr]
        :return: True if statements are wrapped in begin-end block
        """
        w = self.out.write
        if isinstance(stms, HdlStmBlock):
            self.visit_doc(stms)
            must_have_begin_end = True
            stms = stms.body
        elif isinstance(stms, list):
            must_have_begin_end = len(stms) != 1
        else:
            must_have_begin_end = False
            stms = [stms, ]
        must_have_begin_end |= force_begin_end

        non_declarative_seen = False
        with Indent(self.out):
            for s in stms:
                if isinstance(s, iHdlStatement):
                    if not non_declarative_seen:
                        non_declarative_seen = True
                        with UnIndent(self.out):
                            self._write_begin(begin_end, must_have_begin_end, force_space_before)
                    self.visit_iHdlStatement(s)
                elif isinstance(s, HdlIdDef):
                    self.visit_HdlIdDef(s)
                else:
                    if not non_declarative_seen:
                        non_declarative_seen = True
                        with UnIndent(self.out):
                            self._write_begin(begin_end, must_have_begin_end, force_space_before)
                    self.visit_iHdlExpr(s)
                    w(";\n")

        if not non_declarative_seen:
            self._write_begin(begin_end, must_have_begin_end, force_space_before)

        if begin_end and must_have_begin_end:
            w("END")
            return True

        return False

    def visit_HdlStmIf(self, o):
        """
        :type o: HdlStmIf
        """
        self.visit_doc(o)
        w = self.out.write

        w("IF ")
        self.visit_iHdlExpr(o.cond)
        w(" THEN")
        need_space = self.visit_HdlStmBlock(o.if_true, begin_end=False)

        for cond, stms in o.elifs:
            if need_space:
                w(" ")
            w("ELSIF ")
            self.visit_iHdlExpr(cond)
            w(" THEN")
            need_space = self.visit_HdlStmBlock(stms, begin_end=False)

        ifFalse = o.if_false
        if ifFalse is not None:
            if need_space:
                w(" ")
            w("ELSE")
            self.visit_HdlStmBlock(ifFalse, begin_end=False)
        if need_space:
            w("\n")
        w("END IF;\n")

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        """
        w = self.out.write
        if o.time_delay is not None:
            raise NotImplementedError()
        if o.event_delay is not None:
            raise NotImplementedError()

        self.visit_iHdlExpr(o.dst)
        if o.is_blocking:
            w(" := ")
        else:
            w(" <= ")
        with Indent(self.out):
            self.visit_iHdlExpr(o.src)
        w(";\n")

    def visit_HdlStmCase(self, o):
        """
        :type o: HdlStmCase
        """
        self.visit_doc(o)
        w = self.out.write
        w("CASE ")
        self.visit_iHdlExpr(o.switch_on)
        w(" IS\n")
        with Indent(self.out):
            cases = o.cases
            for k, stms in cases:
                w("WHEN ")
                self.visit_iHdlExpr(k)
                w(" =>")
                is_block = self.visit_HdlStmBlock(stms, begin_end=False)
                if is_block:
                    w("\n")
            defal = o.default
            if defal is not None:
                is_block = w("WHEN OTHERS =>")
                self.visit_HdlStmBlock(defal, begin_end=False)
                if is_block:
                    w("\n")
        w("END CASE;\n")

    def visit_HdlStmReturn(self, o):
        """
        :type o: HdlStmReturn
        """
        self.visit_doc(o)
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
        self.visit_doc(o)
        self.out.write("CONTINUE")

    def visit_HdlStmBreak(self, o):
        """
        :type o: HdlStmBreak
        """
        self.visit_doc(o)
        self.out.write("BREAK")

    def visit_HdlStmFor(self, o):
        """
        :type o: HdlStmFor
        """
        self.visit_doc(o)
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
        self.visit_doc(o)
        w = self.out.write
        w("WAIT")
        for e in o.val:
            if isinstance(e, HdlOp) and e.fn == HdlOpType.MUL:
                # wait for time
                w(" FOR ")
                self.visit_iHdlExpr(e.ops[0])
                w(" ")
                self.visit_iHdlExpr(e.ops[1])
            # elif :
            #  wait until
            else:
                # wait on event
                w(" ON ")
                self.visit_iHdlExpr(e)

        w(";\n")
