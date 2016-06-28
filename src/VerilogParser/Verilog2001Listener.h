
// Generated from Verilog2001.g4 by ANTLR 4.5.3

#pragma once


#include "antlr4-runtime.h"
#include "Verilog2001Parser.h"


namespace verilog {

/**
 * This interface defines an abstract listener for a parse tree produced by Verilog2001Parser.
 */
class Verilog2001Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterConfig_declaration(Verilog2001Parser::Config_declarationContext *ctx) = 0;
  virtual void exitConfig_declaration(Verilog2001Parser::Config_declarationContext *ctx) = 0;

  virtual void enterDesign_statement(Verilog2001Parser::Design_statementContext *ctx) = 0;
  virtual void exitDesign_statement(Verilog2001Parser::Design_statementContext *ctx) = 0;

  virtual void enterConfig_rule_statement(Verilog2001Parser::Config_rule_statementContext *ctx) = 0;
  virtual void exitConfig_rule_statement(Verilog2001Parser::Config_rule_statementContext *ctx) = 0;

  virtual void enterDefault_clause(Verilog2001Parser::Default_clauseContext *ctx) = 0;
  virtual void exitDefault_clause(Verilog2001Parser::Default_clauseContext *ctx) = 0;

  virtual void enterInst_clause(Verilog2001Parser::Inst_clauseContext *ctx) = 0;
  virtual void exitInst_clause(Verilog2001Parser::Inst_clauseContext *ctx) = 0;

  virtual void enterInst_name(Verilog2001Parser::Inst_nameContext *ctx) = 0;
  virtual void exitInst_name(Verilog2001Parser::Inst_nameContext *ctx) = 0;

  virtual void enterLiblist_clause(Verilog2001Parser::Liblist_clauseContext *ctx) = 0;
  virtual void exitLiblist_clause(Verilog2001Parser::Liblist_clauseContext *ctx) = 0;

  virtual void enterCell_clause(Verilog2001Parser::Cell_clauseContext *ctx) = 0;
  virtual void exitCell_clause(Verilog2001Parser::Cell_clauseContext *ctx) = 0;

  virtual void enterUse_clause(Verilog2001Parser::Use_clauseContext *ctx) = 0;
  virtual void exitUse_clause(Verilog2001Parser::Use_clauseContext *ctx) = 0;

  virtual void enterSource_text(Verilog2001Parser::Source_textContext *ctx) = 0;
  virtual void exitSource_text(Verilog2001Parser::Source_textContext *ctx) = 0;

  virtual void enterDescription(Verilog2001Parser::DescriptionContext *ctx) = 0;
  virtual void exitDescription(Verilog2001Parser::DescriptionContext *ctx) = 0;

  virtual void enterModule_declaration(Verilog2001Parser::Module_declarationContext *ctx) = 0;
  virtual void exitModule_declaration(Verilog2001Parser::Module_declarationContext *ctx) = 0;

  virtual void enterModule_keyword(Verilog2001Parser::Module_keywordContext *ctx) = 0;
  virtual void exitModule_keyword(Verilog2001Parser::Module_keywordContext *ctx) = 0;

  virtual void enterModule_parameter_port_list(Verilog2001Parser::Module_parameter_port_listContext *ctx) = 0;
  virtual void exitModule_parameter_port_list(Verilog2001Parser::Module_parameter_port_listContext *ctx) = 0;

  virtual void enterList_of_ports(Verilog2001Parser::List_of_portsContext *ctx) = 0;
  virtual void exitList_of_ports(Verilog2001Parser::List_of_portsContext *ctx) = 0;

  virtual void enterList_of_port_declarations(Verilog2001Parser::List_of_port_declarationsContext *ctx) = 0;
  virtual void exitList_of_port_declarations(Verilog2001Parser::List_of_port_declarationsContext *ctx) = 0;

  virtual void enterPort(Verilog2001Parser::PortContext *ctx) = 0;
  virtual void exitPort(Verilog2001Parser::PortContext *ctx) = 0;

  virtual void enterPort_expression(Verilog2001Parser::Port_expressionContext *ctx) = 0;
  virtual void exitPort_expression(Verilog2001Parser::Port_expressionContext *ctx) = 0;

  virtual void enterPort_reference(Verilog2001Parser::Port_referenceContext *ctx) = 0;
  virtual void exitPort_reference(Verilog2001Parser::Port_referenceContext *ctx) = 0;

  virtual void enterPort_declaration(Verilog2001Parser::Port_declarationContext *ctx) = 0;
  virtual void exitPort_declaration(Verilog2001Parser::Port_declarationContext *ctx) = 0;

  virtual void enterModule_item(Verilog2001Parser::Module_itemContext *ctx) = 0;
  virtual void exitModule_item(Verilog2001Parser::Module_itemContext *ctx) = 0;

  virtual void enterModule_or_generate_item(Verilog2001Parser::Module_or_generate_itemContext *ctx) = 0;
  virtual void exitModule_or_generate_item(Verilog2001Parser::Module_or_generate_itemContext *ctx) = 0;

  virtual void enterNon_port_module_item(Verilog2001Parser::Non_port_module_itemContext *ctx) = 0;
  virtual void exitNon_port_module_item(Verilog2001Parser::Non_port_module_itemContext *ctx) = 0;

  virtual void enterModule_or_generate_item_declaration(Verilog2001Parser::Module_or_generate_item_declarationContext *ctx) = 0;
  virtual void exitModule_or_generate_item_declaration(Verilog2001Parser::Module_or_generate_item_declarationContext *ctx) = 0;

  virtual void enterParameter_override(Verilog2001Parser::Parameter_overrideContext *ctx) = 0;
  virtual void exitParameter_override(Verilog2001Parser::Parameter_overrideContext *ctx) = 0;

  virtual void enterLocal_parameter_declaration(Verilog2001Parser::Local_parameter_declarationContext *ctx) = 0;
  virtual void exitLocal_parameter_declaration(Verilog2001Parser::Local_parameter_declarationContext *ctx) = 0;

  virtual void enterParameter_declaration(Verilog2001Parser::Parameter_declarationContext *ctx) = 0;
  virtual void exitParameter_declaration(Verilog2001Parser::Parameter_declarationContext *ctx) = 0;

  virtual void enterParameter_declaration_(Verilog2001Parser::Parameter_declaration_Context *ctx) = 0;
  virtual void exitParameter_declaration_(Verilog2001Parser::Parameter_declaration_Context *ctx) = 0;

  virtual void enterSpecparam_declaration(Verilog2001Parser::Specparam_declarationContext *ctx) = 0;
  virtual void exitSpecparam_declaration(Verilog2001Parser::Specparam_declarationContext *ctx) = 0;

  virtual void enterInout_declaration(Verilog2001Parser::Inout_declarationContext *ctx) = 0;
  virtual void exitInout_declaration(Verilog2001Parser::Inout_declarationContext *ctx) = 0;

  virtual void enterInput_declaration(Verilog2001Parser::Input_declarationContext *ctx) = 0;
  virtual void exitInput_declaration(Verilog2001Parser::Input_declarationContext *ctx) = 0;

  virtual void enterOutput_declaration(Verilog2001Parser::Output_declarationContext *ctx) = 0;
  virtual void exitOutput_declaration(Verilog2001Parser::Output_declarationContext *ctx) = 0;

  virtual void enterEvent_declaration(Verilog2001Parser::Event_declarationContext *ctx) = 0;
  virtual void exitEvent_declaration(Verilog2001Parser::Event_declarationContext *ctx) = 0;

  virtual void enterGenvar_declaration(Verilog2001Parser::Genvar_declarationContext *ctx) = 0;
  virtual void exitGenvar_declaration(Verilog2001Parser::Genvar_declarationContext *ctx) = 0;

  virtual void enterInteger_declaration(Verilog2001Parser::Integer_declarationContext *ctx) = 0;
  virtual void exitInteger_declaration(Verilog2001Parser::Integer_declarationContext *ctx) = 0;

  virtual void enterTime_declaration(Verilog2001Parser::Time_declarationContext *ctx) = 0;
  virtual void exitTime_declaration(Verilog2001Parser::Time_declarationContext *ctx) = 0;

  virtual void enterReal_declaration(Verilog2001Parser::Real_declarationContext *ctx) = 0;
  virtual void exitReal_declaration(Verilog2001Parser::Real_declarationContext *ctx) = 0;

  virtual void enterRealtime_declaration(Verilog2001Parser::Realtime_declarationContext *ctx) = 0;
  virtual void exitRealtime_declaration(Verilog2001Parser::Realtime_declarationContext *ctx) = 0;

  virtual void enterReg_declaration(Verilog2001Parser::Reg_declarationContext *ctx) = 0;
  virtual void exitReg_declaration(Verilog2001Parser::Reg_declarationContext *ctx) = 0;

  virtual void enterNet_declaration(Verilog2001Parser::Net_declarationContext *ctx) = 0;
  virtual void exitNet_declaration(Verilog2001Parser::Net_declarationContext *ctx) = 0;

  virtual void enterNet_type(Verilog2001Parser::Net_typeContext *ctx) = 0;
  virtual void exitNet_type(Verilog2001Parser::Net_typeContext *ctx) = 0;

  virtual void enterOutput_variable_type(Verilog2001Parser::Output_variable_typeContext *ctx) = 0;
  virtual void exitOutput_variable_type(Verilog2001Parser::Output_variable_typeContext *ctx) = 0;

  virtual void enterReal_type(Verilog2001Parser::Real_typeContext *ctx) = 0;
  virtual void exitReal_type(Verilog2001Parser::Real_typeContext *ctx) = 0;

  virtual void enterVariable_type(Verilog2001Parser::Variable_typeContext *ctx) = 0;
  virtual void exitVariable_type(Verilog2001Parser::Variable_typeContext *ctx) = 0;

  virtual void enterDrive_strength(Verilog2001Parser::Drive_strengthContext *ctx) = 0;
  virtual void exitDrive_strength(Verilog2001Parser::Drive_strengthContext *ctx) = 0;

  virtual void enterStrength0(Verilog2001Parser::Strength0Context *ctx) = 0;
  virtual void exitStrength0(Verilog2001Parser::Strength0Context *ctx) = 0;

  virtual void enterStrength1(Verilog2001Parser::Strength1Context *ctx) = 0;
  virtual void exitStrength1(Verilog2001Parser::Strength1Context *ctx) = 0;

  virtual void enterCharge_strength(Verilog2001Parser::Charge_strengthContext *ctx) = 0;
  virtual void exitCharge_strength(Verilog2001Parser::Charge_strengthContext *ctx) = 0;

  virtual void enterDelay3(Verilog2001Parser::Delay3Context *ctx) = 0;
  virtual void exitDelay3(Verilog2001Parser::Delay3Context *ctx) = 0;

  virtual void enterDelay2(Verilog2001Parser::Delay2Context *ctx) = 0;
  virtual void exitDelay2(Verilog2001Parser::Delay2Context *ctx) = 0;

  virtual void enterDelay_value(Verilog2001Parser::Delay_valueContext *ctx) = 0;
  virtual void exitDelay_value(Verilog2001Parser::Delay_valueContext *ctx) = 0;

  virtual void enterList_of_event_identifiers(Verilog2001Parser::List_of_event_identifiersContext *ctx) = 0;
  virtual void exitList_of_event_identifiers(Verilog2001Parser::List_of_event_identifiersContext *ctx) = 0;

  virtual void enterList_of_net_identifiers(Verilog2001Parser::List_of_net_identifiersContext *ctx) = 0;
  virtual void exitList_of_net_identifiers(Verilog2001Parser::List_of_net_identifiersContext *ctx) = 0;

  virtual void enterList_of_genvar_identifiers(Verilog2001Parser::List_of_genvar_identifiersContext *ctx) = 0;
  virtual void exitList_of_genvar_identifiers(Verilog2001Parser::List_of_genvar_identifiersContext *ctx) = 0;

  virtual void enterList_of_port_identifiers(Verilog2001Parser::List_of_port_identifiersContext *ctx) = 0;
  virtual void exitList_of_port_identifiers(Verilog2001Parser::List_of_port_identifiersContext *ctx) = 0;

  virtual void enterList_of_net_decl_assignments(Verilog2001Parser::List_of_net_decl_assignmentsContext *ctx) = 0;
  virtual void exitList_of_net_decl_assignments(Verilog2001Parser::List_of_net_decl_assignmentsContext *ctx) = 0;

  virtual void enterList_of_param_assignments(Verilog2001Parser::List_of_param_assignmentsContext *ctx) = 0;
  virtual void exitList_of_param_assignments(Verilog2001Parser::List_of_param_assignmentsContext *ctx) = 0;

  virtual void enterList_of_specparam_assignments(Verilog2001Parser::List_of_specparam_assignmentsContext *ctx) = 0;
  virtual void exitList_of_specparam_assignments(Verilog2001Parser::List_of_specparam_assignmentsContext *ctx) = 0;

  virtual void enterList_of_real_identifiers(Verilog2001Parser::List_of_real_identifiersContext *ctx) = 0;
  virtual void exitList_of_real_identifiers(Verilog2001Parser::List_of_real_identifiersContext *ctx) = 0;

  virtual void enterList_of_variable_identifiers(Verilog2001Parser::List_of_variable_identifiersContext *ctx) = 0;
  virtual void exitList_of_variable_identifiers(Verilog2001Parser::List_of_variable_identifiersContext *ctx) = 0;

  virtual void enterList_of_variable_port_identifiers(Verilog2001Parser::List_of_variable_port_identifiersContext *ctx) = 0;
  virtual void exitList_of_variable_port_identifiers(Verilog2001Parser::List_of_variable_port_identifiersContext *ctx) = 0;

  virtual void enterNet_decl_assignment(Verilog2001Parser::Net_decl_assignmentContext *ctx) = 0;
  virtual void exitNet_decl_assignment(Verilog2001Parser::Net_decl_assignmentContext *ctx) = 0;

  virtual void enterParam_assignment(Verilog2001Parser::Param_assignmentContext *ctx) = 0;
  virtual void exitParam_assignment(Verilog2001Parser::Param_assignmentContext *ctx) = 0;

  virtual void enterSpecparam_assignment(Verilog2001Parser::Specparam_assignmentContext *ctx) = 0;
  virtual void exitSpecparam_assignment(Verilog2001Parser::Specparam_assignmentContext *ctx) = 0;

  virtual void enterPulse_control_specparam(Verilog2001Parser::Pulse_control_specparamContext *ctx) = 0;
  virtual void exitPulse_control_specparam(Verilog2001Parser::Pulse_control_specparamContext *ctx) = 0;

  virtual void enterError_limit_value(Verilog2001Parser::Error_limit_valueContext *ctx) = 0;
  virtual void exitError_limit_value(Verilog2001Parser::Error_limit_valueContext *ctx) = 0;

  virtual void enterReject_limit_value(Verilog2001Parser::Reject_limit_valueContext *ctx) = 0;
  virtual void exitReject_limit_value(Verilog2001Parser::Reject_limit_valueContext *ctx) = 0;

  virtual void enterLimit_value(Verilog2001Parser::Limit_valueContext *ctx) = 0;
  virtual void exitLimit_value(Verilog2001Parser::Limit_valueContext *ctx) = 0;

  virtual void enterDimension(Verilog2001Parser::DimensionContext *ctx) = 0;
  virtual void exitDimension(Verilog2001Parser::DimensionContext *ctx) = 0;

  virtual void enterRange(Verilog2001Parser::RangeContext *ctx) = 0;
  virtual void exitRange(Verilog2001Parser::RangeContext *ctx) = 0;

  virtual void enterFunction_declaration(Verilog2001Parser::Function_declarationContext *ctx) = 0;
  virtual void exitFunction_declaration(Verilog2001Parser::Function_declarationContext *ctx) = 0;

  virtual void enterFunction_item_declaration(Verilog2001Parser::Function_item_declarationContext *ctx) = 0;
  virtual void exitFunction_item_declaration(Verilog2001Parser::Function_item_declarationContext *ctx) = 0;

  virtual void enterFunction_port_list(Verilog2001Parser::Function_port_listContext *ctx) = 0;
  virtual void exitFunction_port_list(Verilog2001Parser::Function_port_listContext *ctx) = 0;

  virtual void enterFunction_port(Verilog2001Parser::Function_portContext *ctx) = 0;
  virtual void exitFunction_port(Verilog2001Parser::Function_portContext *ctx) = 0;

  virtual void enterRange_or_type(Verilog2001Parser::Range_or_typeContext *ctx) = 0;
  virtual void exitRange_or_type(Verilog2001Parser::Range_or_typeContext *ctx) = 0;

  virtual void enterTask_declaration(Verilog2001Parser::Task_declarationContext *ctx) = 0;
  virtual void exitTask_declaration(Verilog2001Parser::Task_declarationContext *ctx) = 0;

  virtual void enterTask_item_declaration(Verilog2001Parser::Task_item_declarationContext *ctx) = 0;
  virtual void exitTask_item_declaration(Verilog2001Parser::Task_item_declarationContext *ctx) = 0;

  virtual void enterTask_port_list(Verilog2001Parser::Task_port_listContext *ctx) = 0;
  virtual void exitTask_port_list(Verilog2001Parser::Task_port_listContext *ctx) = 0;

  virtual void enterTask_port_item(Verilog2001Parser::Task_port_itemContext *ctx) = 0;
  virtual void exitTask_port_item(Verilog2001Parser::Task_port_itemContext *ctx) = 0;

  virtual void enterTf_decl_header(Verilog2001Parser::Tf_decl_headerContext *ctx) = 0;
  virtual void exitTf_decl_header(Verilog2001Parser::Tf_decl_headerContext *ctx) = 0;

  virtual void enterTf_declaration(Verilog2001Parser::Tf_declarationContext *ctx) = 0;
  virtual void exitTf_declaration(Verilog2001Parser::Tf_declarationContext *ctx) = 0;

  virtual void enterTask_port_type(Verilog2001Parser::Task_port_typeContext *ctx) = 0;
  virtual void exitTask_port_type(Verilog2001Parser::Task_port_typeContext *ctx) = 0;

  virtual void enterBlock_item_declaration(Verilog2001Parser::Block_item_declarationContext *ctx) = 0;
  virtual void exitBlock_item_declaration(Verilog2001Parser::Block_item_declarationContext *ctx) = 0;

  virtual void enterBlock_reg_declaration(Verilog2001Parser::Block_reg_declarationContext *ctx) = 0;
  virtual void exitBlock_reg_declaration(Verilog2001Parser::Block_reg_declarationContext *ctx) = 0;

  virtual void enterList_of_block_variable_identifiers(Verilog2001Parser::List_of_block_variable_identifiersContext *ctx) = 0;
  virtual void exitList_of_block_variable_identifiers(Verilog2001Parser::List_of_block_variable_identifiersContext *ctx) = 0;

  virtual void enterBlock_variable_type(Verilog2001Parser::Block_variable_typeContext *ctx) = 0;
  virtual void exitBlock_variable_type(Verilog2001Parser::Block_variable_typeContext *ctx) = 0;

  virtual void enterGate_instantiation(Verilog2001Parser::Gate_instantiationContext *ctx) = 0;
  virtual void exitGate_instantiation(Verilog2001Parser::Gate_instantiationContext *ctx) = 0;

  virtual void enterCmos_switch_instance(Verilog2001Parser::Cmos_switch_instanceContext *ctx) = 0;
  virtual void exitCmos_switch_instance(Verilog2001Parser::Cmos_switch_instanceContext *ctx) = 0;

  virtual void enterEnable_gate_instance(Verilog2001Parser::Enable_gate_instanceContext *ctx) = 0;
  virtual void exitEnable_gate_instance(Verilog2001Parser::Enable_gate_instanceContext *ctx) = 0;

  virtual void enterMos_switch_instance(Verilog2001Parser::Mos_switch_instanceContext *ctx) = 0;
  virtual void exitMos_switch_instance(Verilog2001Parser::Mos_switch_instanceContext *ctx) = 0;

  virtual void enterN_input_gate_instance(Verilog2001Parser::N_input_gate_instanceContext *ctx) = 0;
  virtual void exitN_input_gate_instance(Verilog2001Parser::N_input_gate_instanceContext *ctx) = 0;

  virtual void enterN_output_gate_instance(Verilog2001Parser::N_output_gate_instanceContext *ctx) = 0;
  virtual void exitN_output_gate_instance(Verilog2001Parser::N_output_gate_instanceContext *ctx) = 0;

  virtual void enterPass_switch_instance(Verilog2001Parser::Pass_switch_instanceContext *ctx) = 0;
  virtual void exitPass_switch_instance(Verilog2001Parser::Pass_switch_instanceContext *ctx) = 0;

  virtual void enterPass_enable_switch_instance(Verilog2001Parser::Pass_enable_switch_instanceContext *ctx) = 0;
  virtual void exitPass_enable_switch_instance(Verilog2001Parser::Pass_enable_switch_instanceContext *ctx) = 0;

  virtual void enterPull_gate_instance(Verilog2001Parser::Pull_gate_instanceContext *ctx) = 0;
  virtual void exitPull_gate_instance(Verilog2001Parser::Pull_gate_instanceContext *ctx) = 0;

  virtual void enterName_of_gate_instance(Verilog2001Parser::Name_of_gate_instanceContext *ctx) = 0;
  virtual void exitName_of_gate_instance(Verilog2001Parser::Name_of_gate_instanceContext *ctx) = 0;

  virtual void enterPulldown_strength(Verilog2001Parser::Pulldown_strengthContext *ctx) = 0;
  virtual void exitPulldown_strength(Verilog2001Parser::Pulldown_strengthContext *ctx) = 0;

  virtual void enterPullup_strength(Verilog2001Parser::Pullup_strengthContext *ctx) = 0;
  virtual void exitPullup_strength(Verilog2001Parser::Pullup_strengthContext *ctx) = 0;

  virtual void enterEnable_terminal(Verilog2001Parser::Enable_terminalContext *ctx) = 0;
  virtual void exitEnable_terminal(Verilog2001Parser::Enable_terminalContext *ctx) = 0;

  virtual void enterNcontrol_terminal(Verilog2001Parser::Ncontrol_terminalContext *ctx) = 0;
  virtual void exitNcontrol_terminal(Verilog2001Parser::Ncontrol_terminalContext *ctx) = 0;

  virtual void enterPcontrol_terminal(Verilog2001Parser::Pcontrol_terminalContext *ctx) = 0;
  virtual void exitPcontrol_terminal(Verilog2001Parser::Pcontrol_terminalContext *ctx) = 0;

  virtual void enterInput_terminal(Verilog2001Parser::Input_terminalContext *ctx) = 0;
  virtual void exitInput_terminal(Verilog2001Parser::Input_terminalContext *ctx) = 0;

  virtual void enterInout_terminal(Verilog2001Parser::Inout_terminalContext *ctx) = 0;
  virtual void exitInout_terminal(Verilog2001Parser::Inout_terminalContext *ctx) = 0;

  virtual void enterOutput_terminal(Verilog2001Parser::Output_terminalContext *ctx) = 0;
  virtual void exitOutput_terminal(Verilog2001Parser::Output_terminalContext *ctx) = 0;

  virtual void enterCmos_switchtype(Verilog2001Parser::Cmos_switchtypeContext *ctx) = 0;
  virtual void exitCmos_switchtype(Verilog2001Parser::Cmos_switchtypeContext *ctx) = 0;

  virtual void enterEnable_gatetype(Verilog2001Parser::Enable_gatetypeContext *ctx) = 0;
  virtual void exitEnable_gatetype(Verilog2001Parser::Enable_gatetypeContext *ctx) = 0;

  virtual void enterMos_switchtype(Verilog2001Parser::Mos_switchtypeContext *ctx) = 0;
  virtual void exitMos_switchtype(Verilog2001Parser::Mos_switchtypeContext *ctx) = 0;

  virtual void enterN_input_gatetype(Verilog2001Parser::N_input_gatetypeContext *ctx) = 0;
  virtual void exitN_input_gatetype(Verilog2001Parser::N_input_gatetypeContext *ctx) = 0;

  virtual void enterN_output_gatetype(Verilog2001Parser::N_output_gatetypeContext *ctx) = 0;
  virtual void exitN_output_gatetype(Verilog2001Parser::N_output_gatetypeContext *ctx) = 0;

  virtual void enterPass_en_switchtype(Verilog2001Parser::Pass_en_switchtypeContext *ctx) = 0;
  virtual void exitPass_en_switchtype(Verilog2001Parser::Pass_en_switchtypeContext *ctx) = 0;

  virtual void enterPass_switchtype(Verilog2001Parser::Pass_switchtypeContext *ctx) = 0;
  virtual void exitPass_switchtype(Verilog2001Parser::Pass_switchtypeContext *ctx) = 0;

  virtual void enterModule_instantiation(Verilog2001Parser::Module_instantiationContext *ctx) = 0;
  virtual void exitModule_instantiation(Verilog2001Parser::Module_instantiationContext *ctx) = 0;

  virtual void enterParameter_value_assignment(Verilog2001Parser::Parameter_value_assignmentContext *ctx) = 0;
  virtual void exitParameter_value_assignment(Verilog2001Parser::Parameter_value_assignmentContext *ctx) = 0;

  virtual void enterList_of_parameter_assignments(Verilog2001Parser::List_of_parameter_assignmentsContext *ctx) = 0;
  virtual void exitList_of_parameter_assignments(Verilog2001Parser::List_of_parameter_assignmentsContext *ctx) = 0;

  virtual void enterOrdered_parameter_assignment(Verilog2001Parser::Ordered_parameter_assignmentContext *ctx) = 0;
  virtual void exitOrdered_parameter_assignment(Verilog2001Parser::Ordered_parameter_assignmentContext *ctx) = 0;

  virtual void enterNamed_parameter_assignment(Verilog2001Parser::Named_parameter_assignmentContext *ctx) = 0;
  virtual void exitNamed_parameter_assignment(Verilog2001Parser::Named_parameter_assignmentContext *ctx) = 0;

  virtual void enterModule_instance(Verilog2001Parser::Module_instanceContext *ctx) = 0;
  virtual void exitModule_instance(Verilog2001Parser::Module_instanceContext *ctx) = 0;

  virtual void enterName_of_instance(Verilog2001Parser::Name_of_instanceContext *ctx) = 0;
  virtual void exitName_of_instance(Verilog2001Parser::Name_of_instanceContext *ctx) = 0;

  virtual void enterList_of_port_connections(Verilog2001Parser::List_of_port_connectionsContext *ctx) = 0;
  virtual void exitList_of_port_connections(Verilog2001Parser::List_of_port_connectionsContext *ctx) = 0;

  virtual void enterOrdered_port_connection(Verilog2001Parser::Ordered_port_connectionContext *ctx) = 0;
  virtual void exitOrdered_port_connection(Verilog2001Parser::Ordered_port_connectionContext *ctx) = 0;

  virtual void enterNamed_port_connection(Verilog2001Parser::Named_port_connectionContext *ctx) = 0;
  virtual void exitNamed_port_connection(Verilog2001Parser::Named_port_connectionContext *ctx) = 0;

  virtual void enterGenerated_instantiation(Verilog2001Parser::Generated_instantiationContext *ctx) = 0;
  virtual void exitGenerated_instantiation(Verilog2001Parser::Generated_instantiationContext *ctx) = 0;

  virtual void enterGenerate_item_or_null(Verilog2001Parser::Generate_item_or_nullContext *ctx) = 0;
  virtual void exitGenerate_item_or_null(Verilog2001Parser::Generate_item_or_nullContext *ctx) = 0;

  virtual void enterGenerate_item(Verilog2001Parser::Generate_itemContext *ctx) = 0;
  virtual void exitGenerate_item(Verilog2001Parser::Generate_itemContext *ctx) = 0;

  virtual void enterGenerate_conditional_statement(Verilog2001Parser::Generate_conditional_statementContext *ctx) = 0;
  virtual void exitGenerate_conditional_statement(Verilog2001Parser::Generate_conditional_statementContext *ctx) = 0;

  virtual void enterGenerate_case_statement(Verilog2001Parser::Generate_case_statementContext *ctx) = 0;
  virtual void exitGenerate_case_statement(Verilog2001Parser::Generate_case_statementContext *ctx) = 0;

  virtual void enterGenvar_case_item(Verilog2001Parser::Genvar_case_itemContext *ctx) = 0;
  virtual void exitGenvar_case_item(Verilog2001Parser::Genvar_case_itemContext *ctx) = 0;

  virtual void enterGenerate_loop_statement(Verilog2001Parser::Generate_loop_statementContext *ctx) = 0;
  virtual void exitGenerate_loop_statement(Verilog2001Parser::Generate_loop_statementContext *ctx) = 0;

  virtual void enterGenvar_assignment(Verilog2001Parser::Genvar_assignmentContext *ctx) = 0;
  virtual void exitGenvar_assignment(Verilog2001Parser::Genvar_assignmentContext *ctx) = 0;

  virtual void enterGenerate_block(Verilog2001Parser::Generate_blockContext *ctx) = 0;
  virtual void exitGenerate_block(Verilog2001Parser::Generate_blockContext *ctx) = 0;

  virtual void enterContinuous_assign(Verilog2001Parser::Continuous_assignContext *ctx) = 0;
  virtual void exitContinuous_assign(Verilog2001Parser::Continuous_assignContext *ctx) = 0;

  virtual void enterList_of_net_assignments(Verilog2001Parser::List_of_net_assignmentsContext *ctx) = 0;
  virtual void exitList_of_net_assignments(Verilog2001Parser::List_of_net_assignmentsContext *ctx) = 0;

  virtual void enterNet_assignment(Verilog2001Parser::Net_assignmentContext *ctx) = 0;
  virtual void exitNet_assignment(Verilog2001Parser::Net_assignmentContext *ctx) = 0;

  virtual void enterInitial_construct(Verilog2001Parser::Initial_constructContext *ctx) = 0;
  virtual void exitInitial_construct(Verilog2001Parser::Initial_constructContext *ctx) = 0;

  virtual void enterAlways_construct(Verilog2001Parser::Always_constructContext *ctx) = 0;
  virtual void exitAlways_construct(Verilog2001Parser::Always_constructContext *ctx) = 0;

  virtual void enterBlocking_assignment(Verilog2001Parser::Blocking_assignmentContext *ctx) = 0;
  virtual void exitBlocking_assignment(Verilog2001Parser::Blocking_assignmentContext *ctx) = 0;

  virtual void enterNonblocking_assignment(Verilog2001Parser::Nonblocking_assignmentContext *ctx) = 0;
  virtual void exitNonblocking_assignment(Verilog2001Parser::Nonblocking_assignmentContext *ctx) = 0;

  virtual void enterProcedural_continuous_assignments(Verilog2001Parser::Procedural_continuous_assignmentsContext *ctx) = 0;
  virtual void exitProcedural_continuous_assignments(Verilog2001Parser::Procedural_continuous_assignmentsContext *ctx) = 0;

  virtual void enterFunction_blocking_assignment(Verilog2001Parser::Function_blocking_assignmentContext *ctx) = 0;
  virtual void exitFunction_blocking_assignment(Verilog2001Parser::Function_blocking_assignmentContext *ctx) = 0;

  virtual void enterFunction_statement_or_null(Verilog2001Parser::Function_statement_or_nullContext *ctx) = 0;
  virtual void exitFunction_statement_or_null(Verilog2001Parser::Function_statement_or_nullContext *ctx) = 0;

  virtual void enterFunction_seq_block(Verilog2001Parser::Function_seq_blockContext *ctx) = 0;
  virtual void exitFunction_seq_block(Verilog2001Parser::Function_seq_blockContext *ctx) = 0;

  virtual void enterVariable_assignment(Verilog2001Parser::Variable_assignmentContext *ctx) = 0;
  virtual void exitVariable_assignment(Verilog2001Parser::Variable_assignmentContext *ctx) = 0;

  virtual void enterPar_block(Verilog2001Parser::Par_blockContext *ctx) = 0;
  virtual void exitPar_block(Verilog2001Parser::Par_blockContext *ctx) = 0;

  virtual void enterSeq_block(Verilog2001Parser::Seq_blockContext *ctx) = 0;
  virtual void exitSeq_block(Verilog2001Parser::Seq_blockContext *ctx) = 0;

  virtual void enterStatement(Verilog2001Parser::StatementContext *ctx) = 0;
  virtual void exitStatement(Verilog2001Parser::StatementContext *ctx) = 0;

  virtual void enterStatement_or_null(Verilog2001Parser::Statement_or_nullContext *ctx) = 0;
  virtual void exitStatement_or_null(Verilog2001Parser::Statement_or_nullContext *ctx) = 0;

  virtual void enterFunction_statement(Verilog2001Parser::Function_statementContext *ctx) = 0;
  virtual void exitFunction_statement(Verilog2001Parser::Function_statementContext *ctx) = 0;

  virtual void enterDelay_or_event_control(Verilog2001Parser::Delay_or_event_controlContext *ctx) = 0;
  virtual void exitDelay_or_event_control(Verilog2001Parser::Delay_or_event_controlContext *ctx) = 0;

  virtual void enterDelay_control(Verilog2001Parser::Delay_controlContext *ctx) = 0;
  virtual void exitDelay_control(Verilog2001Parser::Delay_controlContext *ctx) = 0;

  virtual void enterDisable_statement(Verilog2001Parser::Disable_statementContext *ctx) = 0;
  virtual void exitDisable_statement(Verilog2001Parser::Disable_statementContext *ctx) = 0;

  virtual void enterEvent_control(Verilog2001Parser::Event_controlContext *ctx) = 0;
  virtual void exitEvent_control(Verilog2001Parser::Event_controlContext *ctx) = 0;

  virtual void enterEvent_trigger(Verilog2001Parser::Event_triggerContext *ctx) = 0;
  virtual void exitEvent_trigger(Verilog2001Parser::Event_triggerContext *ctx) = 0;

  virtual void enterEvent_expression(Verilog2001Parser::Event_expressionContext *ctx) = 0;
  virtual void exitEvent_expression(Verilog2001Parser::Event_expressionContext *ctx) = 0;

  virtual void enterEvent_primary(Verilog2001Parser::Event_primaryContext *ctx) = 0;
  virtual void exitEvent_primary(Verilog2001Parser::Event_primaryContext *ctx) = 0;

  virtual void enterProcedural_timing_control_statement(Verilog2001Parser::Procedural_timing_control_statementContext *ctx) = 0;
  virtual void exitProcedural_timing_control_statement(Verilog2001Parser::Procedural_timing_control_statementContext *ctx) = 0;

  virtual void enterWait_statement(Verilog2001Parser::Wait_statementContext *ctx) = 0;
  virtual void exitWait_statement(Verilog2001Parser::Wait_statementContext *ctx) = 0;

  virtual void enterConditional_statement(Verilog2001Parser::Conditional_statementContext *ctx) = 0;
  virtual void exitConditional_statement(Verilog2001Parser::Conditional_statementContext *ctx) = 0;

  virtual void enterIf_else_if_statement(Verilog2001Parser::If_else_if_statementContext *ctx) = 0;
  virtual void exitIf_else_if_statement(Verilog2001Parser::If_else_if_statementContext *ctx) = 0;

  virtual void enterFunction_conditional_statement(Verilog2001Parser::Function_conditional_statementContext *ctx) = 0;
  virtual void exitFunction_conditional_statement(Verilog2001Parser::Function_conditional_statementContext *ctx) = 0;

  virtual void enterFunction_if_else_if_statement(Verilog2001Parser::Function_if_else_if_statementContext *ctx) = 0;
  virtual void exitFunction_if_else_if_statement(Verilog2001Parser::Function_if_else_if_statementContext *ctx) = 0;

  virtual void enterCase_statement(Verilog2001Parser::Case_statementContext *ctx) = 0;
  virtual void exitCase_statement(Verilog2001Parser::Case_statementContext *ctx) = 0;

  virtual void enterCase_item(Verilog2001Parser::Case_itemContext *ctx) = 0;
  virtual void exitCase_item(Verilog2001Parser::Case_itemContext *ctx) = 0;

  virtual void enterFunction_case_statement(Verilog2001Parser::Function_case_statementContext *ctx) = 0;
  virtual void exitFunction_case_statement(Verilog2001Parser::Function_case_statementContext *ctx) = 0;

  virtual void enterFunction_case_item(Verilog2001Parser::Function_case_itemContext *ctx) = 0;
  virtual void exitFunction_case_item(Verilog2001Parser::Function_case_itemContext *ctx) = 0;

  virtual void enterFunction_loop_statement(Verilog2001Parser::Function_loop_statementContext *ctx) = 0;
  virtual void exitFunction_loop_statement(Verilog2001Parser::Function_loop_statementContext *ctx) = 0;

  virtual void enterLoop_statement(Verilog2001Parser::Loop_statementContext *ctx) = 0;
  virtual void exitLoop_statement(Verilog2001Parser::Loop_statementContext *ctx) = 0;

  virtual void enterSystem_task_enable(Verilog2001Parser::System_task_enableContext *ctx) = 0;
  virtual void exitSystem_task_enable(Verilog2001Parser::System_task_enableContext *ctx) = 0;

  virtual void enterTask_enable(Verilog2001Parser::Task_enableContext *ctx) = 0;
  virtual void exitTask_enable(Verilog2001Parser::Task_enableContext *ctx) = 0;

  virtual void enterSpecify_block(Verilog2001Parser::Specify_blockContext *ctx) = 0;
  virtual void exitSpecify_block(Verilog2001Parser::Specify_blockContext *ctx) = 0;

  virtual void enterSpecify_item(Verilog2001Parser::Specify_itemContext *ctx) = 0;
  virtual void exitSpecify_item(Verilog2001Parser::Specify_itemContext *ctx) = 0;

  virtual void enterPulsestyle_declaration(Verilog2001Parser::Pulsestyle_declarationContext *ctx) = 0;
  virtual void exitPulsestyle_declaration(Verilog2001Parser::Pulsestyle_declarationContext *ctx) = 0;

  virtual void enterShowcancelled_declaration(Verilog2001Parser::Showcancelled_declarationContext *ctx) = 0;
  virtual void exitShowcancelled_declaration(Verilog2001Parser::Showcancelled_declarationContext *ctx) = 0;

  virtual void enterPath_declaration(Verilog2001Parser::Path_declarationContext *ctx) = 0;
  virtual void exitPath_declaration(Verilog2001Parser::Path_declarationContext *ctx) = 0;

  virtual void enterSimple_path_declaration(Verilog2001Parser::Simple_path_declarationContext *ctx) = 0;
  virtual void exitSimple_path_declaration(Verilog2001Parser::Simple_path_declarationContext *ctx) = 0;

  virtual void enterParallel_path_description(Verilog2001Parser::Parallel_path_descriptionContext *ctx) = 0;
  virtual void exitParallel_path_description(Verilog2001Parser::Parallel_path_descriptionContext *ctx) = 0;

  virtual void enterFull_path_description(Verilog2001Parser::Full_path_descriptionContext *ctx) = 0;
  virtual void exitFull_path_description(Verilog2001Parser::Full_path_descriptionContext *ctx) = 0;

  virtual void enterList_of_path_inputs(Verilog2001Parser::List_of_path_inputsContext *ctx) = 0;
  virtual void exitList_of_path_inputs(Verilog2001Parser::List_of_path_inputsContext *ctx) = 0;

  virtual void enterList_of_path_outputs(Verilog2001Parser::List_of_path_outputsContext *ctx) = 0;
  virtual void exitList_of_path_outputs(Verilog2001Parser::List_of_path_outputsContext *ctx) = 0;

  virtual void enterSpecify_input_terminal_descriptor(Verilog2001Parser::Specify_input_terminal_descriptorContext *ctx) = 0;
  virtual void exitSpecify_input_terminal_descriptor(Verilog2001Parser::Specify_input_terminal_descriptorContext *ctx) = 0;

  virtual void enterSpecify_output_terminal_descriptor(Verilog2001Parser::Specify_output_terminal_descriptorContext *ctx) = 0;
  virtual void exitSpecify_output_terminal_descriptor(Verilog2001Parser::Specify_output_terminal_descriptorContext *ctx) = 0;

  virtual void enterInput_identifier(Verilog2001Parser::Input_identifierContext *ctx) = 0;
  virtual void exitInput_identifier(Verilog2001Parser::Input_identifierContext *ctx) = 0;

  virtual void enterOutput_identifier(Verilog2001Parser::Output_identifierContext *ctx) = 0;
  virtual void exitOutput_identifier(Verilog2001Parser::Output_identifierContext *ctx) = 0;

  virtual void enterPath_delay_value(Verilog2001Parser::Path_delay_valueContext *ctx) = 0;
  virtual void exitPath_delay_value(Verilog2001Parser::Path_delay_valueContext *ctx) = 0;

  virtual void enterList_of_path_delay_expressions(Verilog2001Parser::List_of_path_delay_expressionsContext *ctx) = 0;
  virtual void exitList_of_path_delay_expressions(Verilog2001Parser::List_of_path_delay_expressionsContext *ctx) = 0;

  virtual void enterT_path_delay_expression(Verilog2001Parser::T_path_delay_expressionContext *ctx) = 0;
  virtual void exitT_path_delay_expression(Verilog2001Parser::T_path_delay_expressionContext *ctx) = 0;

  virtual void enterTrise_path_delay_expression(Verilog2001Parser::Trise_path_delay_expressionContext *ctx) = 0;
  virtual void exitTrise_path_delay_expression(Verilog2001Parser::Trise_path_delay_expressionContext *ctx) = 0;

  virtual void enterTfall_path_delay_expression(Verilog2001Parser::Tfall_path_delay_expressionContext *ctx) = 0;
  virtual void exitTfall_path_delay_expression(Verilog2001Parser::Tfall_path_delay_expressionContext *ctx) = 0;

  virtual void enterTz_path_delay_expression(Verilog2001Parser::Tz_path_delay_expressionContext *ctx) = 0;
  virtual void exitTz_path_delay_expression(Verilog2001Parser::Tz_path_delay_expressionContext *ctx) = 0;

  virtual void enterT01_path_delay_expression(Verilog2001Parser::T01_path_delay_expressionContext *ctx) = 0;
  virtual void exitT01_path_delay_expression(Verilog2001Parser::T01_path_delay_expressionContext *ctx) = 0;

  virtual void enterT10_path_delay_expression(Verilog2001Parser::T10_path_delay_expressionContext *ctx) = 0;
  virtual void exitT10_path_delay_expression(Verilog2001Parser::T10_path_delay_expressionContext *ctx) = 0;

  virtual void enterT0z_path_delay_expression(Verilog2001Parser::T0z_path_delay_expressionContext *ctx) = 0;
  virtual void exitT0z_path_delay_expression(Verilog2001Parser::T0z_path_delay_expressionContext *ctx) = 0;

  virtual void enterTz1_path_delay_expression(Verilog2001Parser::Tz1_path_delay_expressionContext *ctx) = 0;
  virtual void exitTz1_path_delay_expression(Verilog2001Parser::Tz1_path_delay_expressionContext *ctx) = 0;

  virtual void enterT1z_path_delay_expression(Verilog2001Parser::T1z_path_delay_expressionContext *ctx) = 0;
  virtual void exitT1z_path_delay_expression(Verilog2001Parser::T1z_path_delay_expressionContext *ctx) = 0;

  virtual void enterTz0_path_delay_expression(Verilog2001Parser::Tz0_path_delay_expressionContext *ctx) = 0;
  virtual void exitTz0_path_delay_expression(Verilog2001Parser::Tz0_path_delay_expressionContext *ctx) = 0;

  virtual void enterT0x_path_delay_expression(Verilog2001Parser::T0x_path_delay_expressionContext *ctx) = 0;
  virtual void exitT0x_path_delay_expression(Verilog2001Parser::T0x_path_delay_expressionContext *ctx) = 0;

  virtual void enterTx1_path_delay_expression(Verilog2001Parser::Tx1_path_delay_expressionContext *ctx) = 0;
  virtual void exitTx1_path_delay_expression(Verilog2001Parser::Tx1_path_delay_expressionContext *ctx) = 0;

  virtual void enterT1x_path_delay_expression(Verilog2001Parser::T1x_path_delay_expressionContext *ctx) = 0;
  virtual void exitT1x_path_delay_expression(Verilog2001Parser::T1x_path_delay_expressionContext *ctx) = 0;

  virtual void enterTx0_path_delay_expression(Verilog2001Parser::Tx0_path_delay_expressionContext *ctx) = 0;
  virtual void exitTx0_path_delay_expression(Verilog2001Parser::Tx0_path_delay_expressionContext *ctx) = 0;

  virtual void enterTxz_path_delay_expression(Verilog2001Parser::Txz_path_delay_expressionContext *ctx) = 0;
  virtual void exitTxz_path_delay_expression(Verilog2001Parser::Txz_path_delay_expressionContext *ctx) = 0;

  virtual void enterTzx_path_delay_expression(Verilog2001Parser::Tzx_path_delay_expressionContext *ctx) = 0;
  virtual void exitTzx_path_delay_expression(Verilog2001Parser::Tzx_path_delay_expressionContext *ctx) = 0;

  virtual void enterPath_delay_expression(Verilog2001Parser::Path_delay_expressionContext *ctx) = 0;
  virtual void exitPath_delay_expression(Verilog2001Parser::Path_delay_expressionContext *ctx) = 0;

  virtual void enterEdge_sensitive_path_declaration(Verilog2001Parser::Edge_sensitive_path_declarationContext *ctx) = 0;
  virtual void exitEdge_sensitive_path_declaration(Verilog2001Parser::Edge_sensitive_path_declarationContext *ctx) = 0;

  virtual void enterParallel_edge_sensitive_path_description(Verilog2001Parser::Parallel_edge_sensitive_path_descriptionContext *ctx) = 0;
  virtual void exitParallel_edge_sensitive_path_description(Verilog2001Parser::Parallel_edge_sensitive_path_descriptionContext *ctx) = 0;

  virtual void enterFull_edge_sensitive_path_description(Verilog2001Parser::Full_edge_sensitive_path_descriptionContext *ctx) = 0;
  virtual void exitFull_edge_sensitive_path_description(Verilog2001Parser::Full_edge_sensitive_path_descriptionContext *ctx) = 0;

  virtual void enterData_source_expression(Verilog2001Parser::Data_source_expressionContext *ctx) = 0;
  virtual void exitData_source_expression(Verilog2001Parser::Data_source_expressionContext *ctx) = 0;

  virtual void enterEdge_identifier(Verilog2001Parser::Edge_identifierContext *ctx) = 0;
  virtual void exitEdge_identifier(Verilog2001Parser::Edge_identifierContext *ctx) = 0;

  virtual void enterState_dependent_path_declaration(Verilog2001Parser::State_dependent_path_declarationContext *ctx) = 0;
  virtual void exitState_dependent_path_declaration(Verilog2001Parser::State_dependent_path_declarationContext *ctx) = 0;

  virtual void enterPolarity_operator(Verilog2001Parser::Polarity_operatorContext *ctx) = 0;
  virtual void exitPolarity_operator(Verilog2001Parser::Polarity_operatorContext *ctx) = 0;

  virtual void enterChecktime_condition(Verilog2001Parser::Checktime_conditionContext *ctx) = 0;
  virtual void exitChecktime_condition(Verilog2001Parser::Checktime_conditionContext *ctx) = 0;

  virtual void enterDelayed_data(Verilog2001Parser::Delayed_dataContext *ctx) = 0;
  virtual void exitDelayed_data(Verilog2001Parser::Delayed_dataContext *ctx) = 0;

  virtual void enterDelayed_reference(Verilog2001Parser::Delayed_referenceContext *ctx) = 0;
  virtual void exitDelayed_reference(Verilog2001Parser::Delayed_referenceContext *ctx) = 0;

  virtual void enterEnd_edge_offset(Verilog2001Parser::End_edge_offsetContext *ctx) = 0;
  virtual void exitEnd_edge_offset(Verilog2001Parser::End_edge_offsetContext *ctx) = 0;

  virtual void enterEvent_based_flag(Verilog2001Parser::Event_based_flagContext *ctx) = 0;
  virtual void exitEvent_based_flag(Verilog2001Parser::Event_based_flagContext *ctx) = 0;

  virtual void enterNotify_reg(Verilog2001Parser::Notify_regContext *ctx) = 0;
  virtual void exitNotify_reg(Verilog2001Parser::Notify_regContext *ctx) = 0;

  virtual void enterRemain_active_flag(Verilog2001Parser::Remain_active_flagContext *ctx) = 0;
  virtual void exitRemain_active_flag(Verilog2001Parser::Remain_active_flagContext *ctx) = 0;

  virtual void enterStamptime_condition(Verilog2001Parser::Stamptime_conditionContext *ctx) = 0;
  virtual void exitStamptime_condition(Verilog2001Parser::Stamptime_conditionContext *ctx) = 0;

  virtual void enterStart_edge_offset(Verilog2001Parser::Start_edge_offsetContext *ctx) = 0;
  virtual void exitStart_edge_offset(Verilog2001Parser::Start_edge_offsetContext *ctx) = 0;

  virtual void enterThreshold(Verilog2001Parser::ThresholdContext *ctx) = 0;
  virtual void exitThreshold(Verilog2001Parser::ThresholdContext *ctx) = 0;

  virtual void enterTiming_check_limit(Verilog2001Parser::Timing_check_limitContext *ctx) = 0;
  virtual void exitTiming_check_limit(Verilog2001Parser::Timing_check_limitContext *ctx) = 0;

  virtual void enterConcatenation(Verilog2001Parser::ConcatenationContext *ctx) = 0;
  virtual void exitConcatenation(Verilog2001Parser::ConcatenationContext *ctx) = 0;

  virtual void enterConstant_concatenation(Verilog2001Parser::Constant_concatenationContext *ctx) = 0;
  virtual void exitConstant_concatenation(Verilog2001Parser::Constant_concatenationContext *ctx) = 0;

  virtual void enterConstant_multiple_concatenation(Verilog2001Parser::Constant_multiple_concatenationContext *ctx) = 0;
  virtual void exitConstant_multiple_concatenation(Verilog2001Parser::Constant_multiple_concatenationContext *ctx) = 0;

  virtual void enterModule_path_concatenation(Verilog2001Parser::Module_path_concatenationContext *ctx) = 0;
  virtual void exitModule_path_concatenation(Verilog2001Parser::Module_path_concatenationContext *ctx) = 0;

  virtual void enterModule_path_multiple_concatenation(Verilog2001Parser::Module_path_multiple_concatenationContext *ctx) = 0;
  virtual void exitModule_path_multiple_concatenation(Verilog2001Parser::Module_path_multiple_concatenationContext *ctx) = 0;

  virtual void enterMultiple_concatenation(Verilog2001Parser::Multiple_concatenationContext *ctx) = 0;
  virtual void exitMultiple_concatenation(Verilog2001Parser::Multiple_concatenationContext *ctx) = 0;

  virtual void enterNet_concatenation(Verilog2001Parser::Net_concatenationContext *ctx) = 0;
  virtual void exitNet_concatenation(Verilog2001Parser::Net_concatenationContext *ctx) = 0;

  virtual void enterNet_concatenation_value(Verilog2001Parser::Net_concatenation_valueContext *ctx) = 0;
  virtual void exitNet_concatenation_value(Verilog2001Parser::Net_concatenation_valueContext *ctx) = 0;

  virtual void enterVariable_concatenation(Verilog2001Parser::Variable_concatenationContext *ctx) = 0;
  virtual void exitVariable_concatenation(Verilog2001Parser::Variable_concatenationContext *ctx) = 0;

  virtual void enterVariable_concatenation_value(Verilog2001Parser::Variable_concatenation_valueContext *ctx) = 0;
  virtual void exitVariable_concatenation_value(Verilog2001Parser::Variable_concatenation_valueContext *ctx) = 0;

  virtual void enterConstant_function_call(Verilog2001Parser::Constant_function_callContext *ctx) = 0;
  virtual void exitConstant_function_call(Verilog2001Parser::Constant_function_callContext *ctx) = 0;

  virtual void enterFunction_call(Verilog2001Parser::Function_callContext *ctx) = 0;
  virtual void exitFunction_call(Verilog2001Parser::Function_callContext *ctx) = 0;

  virtual void enterSystem_function_call(Verilog2001Parser::System_function_callContext *ctx) = 0;
  virtual void exitSystem_function_call(Verilog2001Parser::System_function_callContext *ctx) = 0;

  virtual void enterGenvar_function_call(Verilog2001Parser::Genvar_function_callContext *ctx) = 0;
  virtual void exitGenvar_function_call(Verilog2001Parser::Genvar_function_callContext *ctx) = 0;

  virtual void enterBase_expression(Verilog2001Parser::Base_expressionContext *ctx) = 0;
  virtual void exitBase_expression(Verilog2001Parser::Base_expressionContext *ctx) = 0;

  virtual void enterConstant_base_expression(Verilog2001Parser::Constant_base_expressionContext *ctx) = 0;
  virtual void exitConstant_base_expression(Verilog2001Parser::Constant_base_expressionContext *ctx) = 0;

  virtual void enterConstant_expression(Verilog2001Parser::Constant_expressionContext *ctx) = 0;
  virtual void exitConstant_expression(Verilog2001Parser::Constant_expressionContext *ctx) = 0;

  virtual void enterConstant_mintypmax_expression(Verilog2001Parser::Constant_mintypmax_expressionContext *ctx) = 0;
  virtual void exitConstant_mintypmax_expression(Verilog2001Parser::Constant_mintypmax_expressionContext *ctx) = 0;

  virtual void enterConstant_range_expression(Verilog2001Parser::Constant_range_expressionContext *ctx) = 0;
  virtual void exitConstant_range_expression(Verilog2001Parser::Constant_range_expressionContext *ctx) = 0;

  virtual void enterDimension_constant_expression(Verilog2001Parser::Dimension_constant_expressionContext *ctx) = 0;
  virtual void exitDimension_constant_expression(Verilog2001Parser::Dimension_constant_expressionContext *ctx) = 0;

  virtual void enterExpression(Verilog2001Parser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(Verilog2001Parser::ExpressionContext *ctx) = 0;

  virtual void enterTerm(Verilog2001Parser::TermContext *ctx) = 0;
  virtual void exitTerm(Verilog2001Parser::TermContext *ctx) = 0;

  virtual void enterLsb_constant_expression(Verilog2001Parser::Lsb_constant_expressionContext *ctx) = 0;
  virtual void exitLsb_constant_expression(Verilog2001Parser::Lsb_constant_expressionContext *ctx) = 0;

  virtual void enterMintypmax_expression(Verilog2001Parser::Mintypmax_expressionContext *ctx) = 0;
  virtual void exitMintypmax_expression(Verilog2001Parser::Mintypmax_expressionContext *ctx) = 0;

  virtual void enterModule_path_conditional_expression(Verilog2001Parser::Module_path_conditional_expressionContext *ctx) = 0;
  virtual void exitModule_path_conditional_expression(Verilog2001Parser::Module_path_conditional_expressionContext *ctx) = 0;

  virtual void enterModule_path_expression(Verilog2001Parser::Module_path_expressionContext *ctx) = 0;
  virtual void exitModule_path_expression(Verilog2001Parser::Module_path_expressionContext *ctx) = 0;

  virtual void enterModule_path_mintypmax_expression(Verilog2001Parser::Module_path_mintypmax_expressionContext *ctx) = 0;
  virtual void exitModule_path_mintypmax_expression(Verilog2001Parser::Module_path_mintypmax_expressionContext *ctx) = 0;

  virtual void enterMsb_constant_expression(Verilog2001Parser::Msb_constant_expressionContext *ctx) = 0;
  virtual void exitMsb_constant_expression(Verilog2001Parser::Msb_constant_expressionContext *ctx) = 0;

  virtual void enterRange_expression(Verilog2001Parser::Range_expressionContext *ctx) = 0;
  virtual void exitRange_expression(Verilog2001Parser::Range_expressionContext *ctx) = 0;

  virtual void enterWidth_constant_expression(Verilog2001Parser::Width_constant_expressionContext *ctx) = 0;
  virtual void exitWidth_constant_expression(Verilog2001Parser::Width_constant_expressionContext *ctx) = 0;

  virtual void enterConstant_primary(Verilog2001Parser::Constant_primaryContext *ctx) = 0;
  virtual void exitConstant_primary(Verilog2001Parser::Constant_primaryContext *ctx) = 0;

  virtual void enterModule_path_primary(Verilog2001Parser::Module_path_primaryContext *ctx) = 0;
  virtual void exitModule_path_primary(Verilog2001Parser::Module_path_primaryContext *ctx) = 0;

  virtual void enterPrimary(Verilog2001Parser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(Verilog2001Parser::PrimaryContext *ctx) = 0;

  virtual void enterNet_lvalue(Verilog2001Parser::Net_lvalueContext *ctx) = 0;
  virtual void exitNet_lvalue(Verilog2001Parser::Net_lvalueContext *ctx) = 0;

  virtual void enterVariable_lvalue(Verilog2001Parser::Variable_lvalueContext *ctx) = 0;
  virtual void exitVariable_lvalue(Verilog2001Parser::Variable_lvalueContext *ctx) = 0;

  virtual void enterUnary_operator(Verilog2001Parser::Unary_operatorContext *ctx) = 0;
  virtual void exitUnary_operator(Verilog2001Parser::Unary_operatorContext *ctx) = 0;

  virtual void enterBinary_operator(Verilog2001Parser::Binary_operatorContext *ctx) = 0;
  virtual void exitBinary_operator(Verilog2001Parser::Binary_operatorContext *ctx) = 0;

  virtual void enterUnary_module_path_operator(Verilog2001Parser::Unary_module_path_operatorContext *ctx) = 0;
  virtual void exitUnary_module_path_operator(Verilog2001Parser::Unary_module_path_operatorContext *ctx) = 0;

  virtual void enterBinary_module_path_operator(Verilog2001Parser::Binary_module_path_operatorContext *ctx) = 0;
  virtual void exitBinary_module_path_operator(Verilog2001Parser::Binary_module_path_operatorContext *ctx) = 0;

  virtual void enterNumber(Verilog2001Parser::NumberContext *ctx) = 0;
  virtual void exitNumber(Verilog2001Parser::NumberContext *ctx) = 0;

  virtual void enterDefault_nettype_spec(Verilog2001Parser::Default_nettype_specContext *ctx) = 0;
  virtual void exitDefault_nettype_spec(Verilog2001Parser::Default_nettype_specContext *ctx) = 0;

  virtual void enterTiming_spec(Verilog2001Parser::Timing_specContext *ctx) = 0;
  virtual void exitTiming_spec(Verilog2001Parser::Timing_specContext *ctx) = 0;

  virtual void enterAttribute_instance(Verilog2001Parser::Attribute_instanceContext *ctx) = 0;
  virtual void exitAttribute_instance(Verilog2001Parser::Attribute_instanceContext *ctx) = 0;

  virtual void enterAttr_spec(Verilog2001Parser::Attr_specContext *ctx) = 0;
  virtual void exitAttr_spec(Verilog2001Parser::Attr_specContext *ctx) = 0;

  virtual void enterAttr_name(Verilog2001Parser::Attr_nameContext *ctx) = 0;
  virtual void exitAttr_name(Verilog2001Parser::Attr_nameContext *ctx) = 0;

  virtual void enterArrayed_identifier(Verilog2001Parser::Arrayed_identifierContext *ctx) = 0;
  virtual void exitArrayed_identifier(Verilog2001Parser::Arrayed_identifierContext *ctx) = 0;

  virtual void enterBlock_identifier(Verilog2001Parser::Block_identifierContext *ctx) = 0;
  virtual void exitBlock_identifier(Verilog2001Parser::Block_identifierContext *ctx) = 0;

  virtual void enterCell_identifier(Verilog2001Parser::Cell_identifierContext *ctx) = 0;
  virtual void exitCell_identifier(Verilog2001Parser::Cell_identifierContext *ctx) = 0;

  virtual void enterConfig_identifier(Verilog2001Parser::Config_identifierContext *ctx) = 0;
  virtual void exitConfig_identifier(Verilog2001Parser::Config_identifierContext *ctx) = 0;

  virtual void enterEscaped_arrayed_identifier(Verilog2001Parser::Escaped_arrayed_identifierContext *ctx) = 0;
  virtual void exitEscaped_arrayed_identifier(Verilog2001Parser::Escaped_arrayed_identifierContext *ctx) = 0;

  virtual void enterEscaped_hierarchical_identifier(Verilog2001Parser::Escaped_hierarchical_identifierContext *ctx) = 0;
  virtual void exitEscaped_hierarchical_identifier(Verilog2001Parser::Escaped_hierarchical_identifierContext *ctx) = 0;

  virtual void enterEvent_identifier(Verilog2001Parser::Event_identifierContext *ctx) = 0;
  virtual void exitEvent_identifier(Verilog2001Parser::Event_identifierContext *ctx) = 0;

  virtual void enterFunction_identifier(Verilog2001Parser::Function_identifierContext *ctx) = 0;
  virtual void exitFunction_identifier(Verilog2001Parser::Function_identifierContext *ctx) = 0;

  virtual void enterGate_instance_identifier(Verilog2001Parser::Gate_instance_identifierContext *ctx) = 0;
  virtual void exitGate_instance_identifier(Verilog2001Parser::Gate_instance_identifierContext *ctx) = 0;

  virtual void enterGenerate_block_identifier(Verilog2001Parser::Generate_block_identifierContext *ctx) = 0;
  virtual void exitGenerate_block_identifier(Verilog2001Parser::Generate_block_identifierContext *ctx) = 0;

  virtual void enterGenvar_function_identifier(Verilog2001Parser::Genvar_function_identifierContext *ctx) = 0;
  virtual void exitGenvar_function_identifier(Verilog2001Parser::Genvar_function_identifierContext *ctx) = 0;

  virtual void enterGenvar_identifier(Verilog2001Parser::Genvar_identifierContext *ctx) = 0;
  virtual void exitGenvar_identifier(Verilog2001Parser::Genvar_identifierContext *ctx) = 0;

  virtual void enterHierarchical_block_identifier(Verilog2001Parser::Hierarchical_block_identifierContext *ctx) = 0;
  virtual void exitHierarchical_block_identifier(Verilog2001Parser::Hierarchical_block_identifierContext *ctx) = 0;

  virtual void enterHierarchical_event_identifier(Verilog2001Parser::Hierarchical_event_identifierContext *ctx) = 0;
  virtual void exitHierarchical_event_identifier(Verilog2001Parser::Hierarchical_event_identifierContext *ctx) = 0;

  virtual void enterHierarchical_function_identifier(Verilog2001Parser::Hierarchical_function_identifierContext *ctx) = 0;
  virtual void exitHierarchical_function_identifier(Verilog2001Parser::Hierarchical_function_identifierContext *ctx) = 0;

  virtual void enterHierarchical_identifier(Verilog2001Parser::Hierarchical_identifierContext *ctx) = 0;
  virtual void exitHierarchical_identifier(Verilog2001Parser::Hierarchical_identifierContext *ctx) = 0;

  virtual void enterHierarchical_net_identifier(Verilog2001Parser::Hierarchical_net_identifierContext *ctx) = 0;
  virtual void exitHierarchical_net_identifier(Verilog2001Parser::Hierarchical_net_identifierContext *ctx) = 0;

  virtual void enterHierarchical_variable_identifier(Verilog2001Parser::Hierarchical_variable_identifierContext *ctx) = 0;
  virtual void exitHierarchical_variable_identifier(Verilog2001Parser::Hierarchical_variable_identifierContext *ctx) = 0;

  virtual void enterHierarchical_task_identifier(Verilog2001Parser::Hierarchical_task_identifierContext *ctx) = 0;
  virtual void exitHierarchical_task_identifier(Verilog2001Parser::Hierarchical_task_identifierContext *ctx) = 0;

  virtual void enterIdentifier(Verilog2001Parser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(Verilog2001Parser::IdentifierContext *ctx) = 0;

  virtual void enterInout_port_identifier(Verilog2001Parser::Inout_port_identifierContext *ctx) = 0;
  virtual void exitInout_port_identifier(Verilog2001Parser::Inout_port_identifierContext *ctx) = 0;

  virtual void enterInput_port_identifier(Verilog2001Parser::Input_port_identifierContext *ctx) = 0;
  virtual void exitInput_port_identifier(Verilog2001Parser::Input_port_identifierContext *ctx) = 0;

  virtual void enterInstance_identifier(Verilog2001Parser::Instance_identifierContext *ctx) = 0;
  virtual void exitInstance_identifier(Verilog2001Parser::Instance_identifierContext *ctx) = 0;

  virtual void enterLibrary_identifier(Verilog2001Parser::Library_identifierContext *ctx) = 0;
  virtual void exitLibrary_identifier(Verilog2001Parser::Library_identifierContext *ctx) = 0;

  virtual void enterMemory_identifier(Verilog2001Parser::Memory_identifierContext *ctx) = 0;
  virtual void exitMemory_identifier(Verilog2001Parser::Memory_identifierContext *ctx) = 0;

  virtual void enterModule_identifier(Verilog2001Parser::Module_identifierContext *ctx) = 0;
  virtual void exitModule_identifier(Verilog2001Parser::Module_identifierContext *ctx) = 0;

  virtual void enterModule_instance_identifier(Verilog2001Parser::Module_instance_identifierContext *ctx) = 0;
  virtual void exitModule_instance_identifier(Verilog2001Parser::Module_instance_identifierContext *ctx) = 0;

  virtual void enterNet_identifier(Verilog2001Parser::Net_identifierContext *ctx) = 0;
  virtual void exitNet_identifier(Verilog2001Parser::Net_identifierContext *ctx) = 0;

  virtual void enterOutput_port_identifier(Verilog2001Parser::Output_port_identifierContext *ctx) = 0;
  virtual void exitOutput_port_identifier(Verilog2001Parser::Output_port_identifierContext *ctx) = 0;

  virtual void enterParameter_identifier(Verilog2001Parser::Parameter_identifierContext *ctx) = 0;
  virtual void exitParameter_identifier(Verilog2001Parser::Parameter_identifierContext *ctx) = 0;

  virtual void enterPort_identifier(Verilog2001Parser::Port_identifierContext *ctx) = 0;
  virtual void exitPort_identifier(Verilog2001Parser::Port_identifierContext *ctx) = 0;

  virtual void enterReal_identifier(Verilog2001Parser::Real_identifierContext *ctx) = 0;
  virtual void exitReal_identifier(Verilog2001Parser::Real_identifierContext *ctx) = 0;

  virtual void enterSimple_arrayed_identifier(Verilog2001Parser::Simple_arrayed_identifierContext *ctx) = 0;
  virtual void exitSimple_arrayed_identifier(Verilog2001Parser::Simple_arrayed_identifierContext *ctx) = 0;

  virtual void enterSimple_hierarchical_identifier(Verilog2001Parser::Simple_hierarchical_identifierContext *ctx) = 0;
  virtual void exitSimple_hierarchical_identifier(Verilog2001Parser::Simple_hierarchical_identifierContext *ctx) = 0;

  virtual void enterSpecparam_identifier(Verilog2001Parser::Specparam_identifierContext *ctx) = 0;
  virtual void exitSpecparam_identifier(Verilog2001Parser::Specparam_identifierContext *ctx) = 0;

  virtual void enterSystem_function_identifier(Verilog2001Parser::System_function_identifierContext *ctx) = 0;
  virtual void exitSystem_function_identifier(Verilog2001Parser::System_function_identifierContext *ctx) = 0;

  virtual void enterSystem_task_identifier(Verilog2001Parser::System_task_identifierContext *ctx) = 0;
  virtual void exitSystem_task_identifier(Verilog2001Parser::System_task_identifierContext *ctx) = 0;

  virtual void enterTask_identifier(Verilog2001Parser::Task_identifierContext *ctx) = 0;
  virtual void exitTask_identifier(Verilog2001Parser::Task_identifierContext *ctx) = 0;

  virtual void enterTerminal_identifier(Verilog2001Parser::Terminal_identifierContext *ctx) = 0;
  virtual void exitTerminal_identifier(Verilog2001Parser::Terminal_identifierContext *ctx) = 0;

  virtual void enterText_macro_identifier(Verilog2001Parser::Text_macro_identifierContext *ctx) = 0;
  virtual void exitText_macro_identifier(Verilog2001Parser::Text_macro_identifierContext *ctx) = 0;

  virtual void enterTopmodule_identifier(Verilog2001Parser::Topmodule_identifierContext *ctx) = 0;
  virtual void exitTopmodule_identifier(Verilog2001Parser::Topmodule_identifierContext *ctx) = 0;

  virtual void enterUdp_identifier(Verilog2001Parser::Udp_identifierContext *ctx) = 0;
  virtual void exitUdp_identifier(Verilog2001Parser::Udp_identifierContext *ctx) = 0;

  virtual void enterUdp_instance_identifier(Verilog2001Parser::Udp_instance_identifierContext *ctx) = 0;
  virtual void exitUdp_instance_identifier(Verilog2001Parser::Udp_instance_identifierContext *ctx) = 0;

  virtual void enterVariable_identifier(Verilog2001Parser::Variable_identifierContext *ctx) = 0;
  virtual void exitVariable_identifier(Verilog2001Parser::Variable_identifierContext *ctx) = 0;

  virtual void enterSimple_hierarchical_branch(Verilog2001Parser::Simple_hierarchical_branchContext *ctx) = 0;
  virtual void exitSimple_hierarchical_branch(Verilog2001Parser::Simple_hierarchical_branchContext *ctx) = 0;

  virtual void enterEscaped_hierarchical_branch(Verilog2001Parser::Escaped_hierarchical_branchContext *ctx) = 0;
  virtual void exitEscaped_hierarchical_branch(Verilog2001Parser::Escaped_hierarchical_branchContext *ctx) = 0;


};

}  // namespace verilog
