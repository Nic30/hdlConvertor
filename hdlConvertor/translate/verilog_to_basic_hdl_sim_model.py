from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.\
    add_unique_labels_to_all_processes import AddUniqueLabelsToAllProcesses
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model\
    .verilog_types_to_basic_hdl_sim_model import VerilogTypesToBasicHdlSimModel
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model\
    .wrap_module_statements_to_processes import wrap_module_statements_to_processes
from hdlConvertor.translate.common.discover_declarations import DiscoverDeclarations
from hdlConvertor.translate.vhdl_to_verilog import link_module_dec_def
from hdlConvertor.translate.common.name_scope import NameScope
from hdlConvertor.translate.common.resolve_names import ResolveNames
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model\
    .discover_stm_outputs import discover_stm_outputs_context
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model\
    .verilog_operands_to_basic_hdl_sim_model import BasicHdlSimModelTranslateVerilogOperands


def verilog_to_basic_hdl_sim_model(context):
    """
    :type context: HdlContext
    """
    link_module_dec_def(context)
    name_scope = NameScope.make_top(False)
    DiscoverDeclarations(name_scope).visit_HdlContext(context)
    ResolveNames(name_scope).visit_HdlContext(context)
    wrap_module_statements_to_processes(context)
    BasicHdlSimModelTranslateVerilogOperands().visit_HdlContext(context)
    VerilogTypesToBasicHdlSimModel().visit_HdlContext(context)
    stm_outputs = discover_stm_outputs_context(context)
    AddUniqueLabelsToAllProcesses(name_scope, stm_outputs).context(context)

    return context, stm_outputs, name_scope
