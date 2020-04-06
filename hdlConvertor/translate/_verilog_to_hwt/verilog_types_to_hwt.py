from hdlConvertor.hdlAst._expr import HdlTypeAuto
from hdlConvertor.to.hwt.utils import BitsT
from hdlConvertor.to.verilog.utils import collect_array_dims, get_wire_t_params
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.verilog_types_to_basic_hdl_sim_model import VerilogTypesToBasicHdlSimModel


class VerilogTypesToHwt(VerilogTypesToBasicHdlSimModel):
    """
    Translate Verilog HDL types to HWT HDL types
    """

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
