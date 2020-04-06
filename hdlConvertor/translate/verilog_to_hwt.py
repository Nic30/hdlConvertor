from hdlConvertor.translate._verilog_to_basic_hdl_sim_model\
    .wrap_module_statements_to_processes import wrap_module_statements_to_processes
from hdlConvertor.translate.common.discover_declarations import DiscoverDeclarations
from hdlConvertor.translate.vhdl_to_verilog import link_module_dec_def
from hdlConvertor.translate.common.name_scope import NameScope
from hdlConvertor.translate.common.resolve_names import ResolveNames
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model\
    .verilog_operands_to_basic_hdl_sim_model import BasicHdlSimModelTranslateVerilogOperands
from hdlConvertor.translate._verilog_to_vhdl.inject_process_sens_to_statements import InjectProcessSensToStatements
from hdlConvertor.translate._verilog_to_hwt.verilog_types_to_hwt import VerilogTypesToHwt


def verilog_to_hwt(context):
    """
    :type context: HdlContext
    """
    link_module_dec_def(context)
    name_scope = NameScope.make_top(False)

    DiscoverDeclarations(name_scope).visit_HdlContext(context)
    ResolveNames(name_scope).visit_HdlContext(context)
    #wrap_module_statements_to_processes(context)
    InjectProcessSensToStatements().visit_HdlContext(context)
    BasicHdlSimModelTranslateVerilogOperands().visit_HdlContext(context)
    VerilogTypesToHwt().visit_HdlContext(context)

    return context, name_scope
