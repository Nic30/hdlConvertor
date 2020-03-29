from hdlConvertor.translate.vhdl_to_verilog import link_module_dec_def
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.wrap_module_statements_to_processes import wrap_module_statements_to_processes
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.add_unique_labels_to_all_processes import AddUniqueLabelsToAllProcesses
from hdlConvertor.translate._verilog_to_basic_hdl_sim_model.verilog_types_to_basic_hdl_sim_model import VerilogTypesToBasicHdlSimModel


def verilog_to_basic_hdl_sim_model(context):
    """
    :type context: HdlContext
    """
    link_module_dec_def(context)
    wrap_module_statements_to_processes(context)
    AddUniqueLabelsToAllProcesses().context(context)
    VerilogTypesToBasicHdlSimModel().context(context)
    return context
