from hdlConvertor.to.systemc.expr import ToSystemcExpr
from hdlConvertor.to.verilog.stm import ToVerilog2005Stm
from hdlConvertor.to.hdlUtils import Indent
from hdlConvertor.hdlAst._statements import HdlStmBlock


class ToSystemcStm(ToSystemcExpr):
    BLOCK_BEGIN_KW = "{"
    BLOCK_END_KW = "}"

    def visit_iHdlStatement_in_statement(self, stm):
        return ToVerilog2005Stm.visit_iHdlStatement_in_statement(self, stm)

    def visit_HdlStmBlock(self, o):
        return ToVerilog2005Stm.visit_HdlStmBlock(self, o)

    def visit_HdlStmIf(self, o):
        return ToVerilog2005Stm.visit_HdlStmIf(self, o)

    def visit_HdlStmProcess(self, o):
        """
        :type o: HdlStmProcess
        """
        w = self.out.write
        self.visit_doc(o)
        w("void ")
        w(o.labels[0])
        if isinstance(o.body, HdlStmBlock):
            w("() ")
            self.visit_HdlStmBlock(o)
            w("\n")
        else:
            w("() {\n")
            with Indent(self.out):
                req_semi = self.visit_iHdlStatement(o.body)
                if req_semi:
                    w(";\n")
            w("}\n")

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        :return: True if requires ;\n after end
        """
        self.visit_doc(o)
        w = self.out.write
        self.visit_iHdlExpr(o.dst)
        w(" = ")
        self.visit_iHdlExpr(o.src)
        return True
