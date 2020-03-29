from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.\
    add_unique_labels_to_all_processes import AddUniqueLabelsToAllProcesses
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.\
    verilog_types_to_basic_hdl_sim_model import VerilogTypesToBasicHdlSimModel
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.\
    wrap_module_statements_to_processes import wrap_module_statements_to_processes
from hdlConvertor.translate.common.discover_declarations import discover_declarations
from hdlConvertor.translate.vhdl_to_verilog import link_module_dec_def
from hdlConvertor.translate.common.name_scope import NameScope
from hdlConvertor.translate.common.resolve_names import resolve_names
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.discover_stm_outputs import discover_stm_outputs_context


def verilog_to_basic_hdl_sim_model(context):
    """
    :type context: HdlContext
    """
    link_module_dec_def(context)
    name_scope = NameScope.make_top(False)
    discover_declarations(name_scope, context.objs)
    resolve_names(name_scope, context.objs)
    wrap_module_statements_to_processes(context)
    VerilogTypesToBasicHdlSimModel().context(context)
    stm_outputs = discover_stm_outputs_context(context)
    AddUniqueLabelsToAllProcesses(name_scope, stm_outputs).context(context)

    return context, stm_outputs, name_scope
