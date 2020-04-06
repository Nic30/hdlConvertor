from hdlConvertor.to.basic_hdl_sim_model.expr import ToBasicHdlSimModelExpr
from copy import copy
from hdlConvertor.hdlAst._expr import HdlBuiltinFn


class ToHwtExpr(ToBasicHdlSimModelExpr):
    GENERIC_BIN_OPS = copy(ToBasicHdlSimModelExpr.GENERIC_BIN_OPS)
    GENERIC_BIN_OPS.update({
        HdlBuiltinFn.DOWNTO: " : ",
    })