from itertools import chain

from hdlConvertor.hdlAst._defs import HdlVariableDef
from hdlConvertor.hdlAst._expr import HdlTypeAuto
from hdlConvertor.hdlAst._structural import HdlModuleDec
from hdlConvertor.to.basic_hdl_sim_model.utils import BitsT
from hdlConvertor.to.verilog.utils import collect_array_dims, get_wire_t_params
from hdlConvertor.to.hdl_ast_visitor import HdlAstVisitor


class VerilogTypesToBasicHdlSimModel(HdlAstVisitor):
    """
    Translate Verilog HDL types to BasicHdlSimModel HDL types
    """
    def visit_HdlVariableDef(self, o):
        """
        :type o: HdlVariableDef
        """
        o.type = self.visit_type(o.type)
        if o.value is not None:
            self.visit_iHdlExr(o.value)

    def visit_type(self, t):
        """
        :type t: iHdlExpr
        """
        t, array_dims = collect_array_dims(t)
        wire_params = get_wire_t_params(t)
        if wire_params is None:
            if t == HdlTypeAuto:
                t = BitsT(1)
        else:
            base_t, width, is_signed, _ = wire_params
            if width is None:
                width = 1
            t = BitsT(width, is_signed)
        for i in array_dims:
            t = apply_index(t, i)
        return t
