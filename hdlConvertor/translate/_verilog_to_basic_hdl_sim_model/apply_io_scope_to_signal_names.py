from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor
from hdlConvertor.hdlAst._expr import HdlName, HdlIntValue, HdlCall,\
    HdlBuiltinFn
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.utils import hdl_getattr,\
    hdl_name_prefix
from hdlConvertor.py_ver_compatibility import is_str


def add_io_prefix(o):
    s = HdlName("self")
    s = hdl_getattr(s, "io")
    return hdl_name_prefix(s, o)


class ApplyIoScopeToSignalNames(HdlAstVisitor):
    """
    Change every signal_name to self.io.signal_name
    in every statement expression.
    And for signal which are beeing read add .val.

    :ivar ~._stm_dst: flag which tells if currently processing destination of HdlStmAssig
    """

    def __init__(self):
        super(ApplyIoScopeToSignalNames, self).__init__()
        self._stm_dst = False

    def visit_HdlVariableDef(self, var):
        """
        :type var: HdlVariableDef
        """
        pass

    def visit_port(self, o):
        pass

    def visit_param(self, o):
        pass

    def visit_HdlComponentInst(self, o):
        pass

    def visit_HdlCall(self, o):
        """
        :type o: HdlCall
        :return: iHdlExpr
        """
        if o.fn == HdlBuiltinFn.DOT:
            # update only left most name
            o.ops[0] = self.visit_iHdlExpr(o.ops[0])
            if not self._stm_dst:
                return hdl_getattr(o, "val")
        else:
            o.ops = [self.visit_iHdlExpr(op) for op in o.ops]

        return o

    def visit_iHdlExpr(self, o):
        """
        :type o: iHdlExpr
        :return: iHdlExpr
        """
        if isinstance(o, HdlName):
            o = add_io_prefix(o)
            if not self._stm_dst:
                return hdl_getattr(o, "val")
            return o
        elif o is None or isinstance(o, HdlIntValue) or is_str(o):
            return o
        elif isinstance(o, list):
            return [self.visit_iHdlExpr(_o) for _o in o]
        elif isinstance(o, HdlCall):
            return self.visit_HdlCall(o)
        else:
            raise NotImplementedError(
                "Do not know how to convert %s" % (o))

    def visit_HdlStmAssign(self, o):
        """
        :type o: HdlStmAssign
        """
        assert o.event_delay is None, o
        assert o.time_delay is None, o

        _stm_dst = self._stm_dst
        self._stm_dst = True
        try:
            o.dst = self.visit_iHdlExpr(o.dst)
        finally:
            self._stm_dst = _stm_dst

        o.src = self.visit_iHdlExpr(o.src)

    def visit_HdlStmIf(self, o):
        """
        :type o: HdlStmIf
        """
        o.cond = self.visit_iHdlExpr(o.cond)
        if o.if_true is not None:
            self.visit_iHdlStatement(o.if_true)
        o.elifs = [
            (self.visit_iHdlExpr(c), stm)
            for (c, stm) in o.elifs
        ]
        for _, stm in o.elifs:
            self.visit_iHdlStatement(stm)
        if o.if_false is not None:
            self.visit_iHdlStatement(o.if_false)
