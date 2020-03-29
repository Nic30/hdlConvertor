from itertools import chain

from hdlConvertor.hdlAst._defs import HdlVariableDef
from hdlConvertor.hdlAst._expr import HdlTypeAuto
from hdlConvertor.hdlAst._structural import HdlModuleDec
from hdlConvertor.to.basic_hdl_sim_model.utils import BitsT
from hdlConvertor.to.verilog.utils import collect_array_dims, get_wire_t_params


class VerilogTypesToBasicHdlSimModel():
    """
    Translate Verilog HDL types to BasicHdlSimModel HDL types
    """

    def context(self, context):
        """
        :type context: HdlContext
        """
        for o in context.objs:
            if isinstance(o, HdlModuleDec):
                self.module_dec(o)

    def module_dec(self, m: HdlModuleDec):
        for p in chain(m.params, m.ports):
            # :type p: HdlVariableDef
            self.variable_def(p)

        for o in m.body.objs:
            if isinstance(o, HdlVariableDef):
                self.variable_def(o)

    def variable_def(self, v: HdlVariableDef):
        v.type = self.type(v.type)

    def type(self, t):
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
