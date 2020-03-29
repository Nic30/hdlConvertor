from hdlConvertor.hdlAst import HdlImport, HdlModuleDec, HdlModuleDef,\
    HdlNamespace, HdlVariableDef, HdlFunctionDef, HdlStmProcess, HdlStmIf,\
    HdlStmAssign, HdlStmCase, HdlStmWait, HdlStmReturn, HdlStmFor, \
    iHdlStatement, HdlStmForIn, HdlStmWhile, HdlStmBlock
from hdlConvertor.to.hdlUtils import AutoIndentingStream, iter_with_last


class ToHdlCommon():
    INDENT_STEP = "    "

    def __init__(self, out_stream):
        self.out = AutoIndentingStream(out_stream, self.INDENT_STEP)

    def print_doc(self, obj, line_comment_prefix):
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

    def print_main_obj(self, o):
        w = self.out.write
        if isinstance(o, HdlModuleDec):
            w("\n")
            self.print_HdlModuleDec(o)
            w("\n")
        elif isinstance(o, HdlModuleDef):
            self.print_HdlModuleDef(o)
        elif isinstance(o, HdlNamespace):
            self.print_HdlNamespace(o)
        elif isinstance(o, HdlVariableDef):
            self.print_HdlVariableDef(o)
        elif isinstance(o, HdlFunctionDef):
            self.print_HdlFunctionDef(o)
        else:
            raise NotImplementedError(o)

    def print_HdlContext(self, context):
        """
        :type context: HdlContext
        """
        for o in context.objs:
            if isinstance(o, HdlImport):
                self.print_HdlImport(o)
            else:
                self.print_main_obj(o)

    def print_iHdlStatement(self, stm, is_top=False):
        """
        :type o: iHdlStatement
        :return: True if requires ;\n after end
        """
        # statement can be also expressin
        if isinstance(stm, iHdlStatement):
            self.print_doc(stm)

        if isinstance(stm, HdlStmProcess):
            return self.print_HdlStmProcess(stm, is_top=is_top)
        elif isinstance(stm, HdlStmIf):
            return self.print_HdlStmIf(stm)
        elif isinstance(stm, HdlStmAssign):
            return self.print_HdlStmAssign(stm, is_top=is_top)
        elif isinstance(stm, HdlStmCase):
            return self.print_HdlStmCase(stm)
        elif isinstance(stm, HdlStmWait):
            return self.print_HdlStmWait(stm)
        elif isinstance(stm, HdlStmReturn):
            self.print_return(stm)
        elif isinstance(stm, HdlStmFor):
            return self.print_HdlStmFor(stm)
        elif isinstance(stm, HdlStmForIn):
            return self.print_HdlStmForInt(stm)
        elif isinstance(stm, HdlStmWhile):
            return self.print_HdlStmWhile(stm)
        elif isinstance(stm, HdlStmBlock):
            return self.print_HdlStmBlock(stm)
        else:
            self.print_iHdlExpr(stm)
            return True

    def print_HdlFunctionDef_def(self, o):
        """
        :type o: HdlFunctionDef
        """
        raise TypeError("does not support HdlFunctionDef", self, o)

    def print_HdlStmCase(self, o):
        """
        :type o: HdlStmCase

        :return: True if requires ;\n after end
        """
        raise TypeError("does not support HdlStmCase", self, o)

    def print_HdlStmWait(self, o):
        """
        :type o: HdlStmWait
        """
        raise TypeError("does not support HdlStmWait", self, o)

    def print_HdlStmFor(self, o):
        """
        :type o: HdlStmFor
        """
        raise TypeError("does not support HdlStmFor", self, o)

    def print_HdlStmForIn(self, o):
        """
        :type o: HdlStmForIn
        """
        raise TypeError("does not support HdlStmForIn", self, o)

    def print_HdlStmWhile(self, o):
        """
        :type o: HdlStmWhile
        :return: True if requires ;\n after end
        """
        raise TypeError("does not support HdlStmWhile", self, o)
