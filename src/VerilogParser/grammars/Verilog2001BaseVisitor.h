
// Generated from grammars/Verilog2001.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "Verilog2001Visitor.h"


namespace verilog {

/**
 * This class provides an empty implementation of Verilog2001Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  Verilog2001BaseVisitor : public Verilog2001Visitor {
public:

  virtual antlrcpp::Any visitConfig_declaration(Verilog2001Parser::Config_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesign_statement(Verilog2001Parser::Design_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfig_rule_statement(Verilog2001Parser::Config_rule_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefault_clause(Verilog2001Parser::Default_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInst_clause(Verilog2001Parser::Inst_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInst_name(Verilog2001Parser::Inst_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiblist_clause(Verilog2001Parser::Liblist_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCell_clause(Verilog2001Parser::Cell_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUse_clause(Verilog2001Parser::Use_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSource_text(Verilog2001Parser::Source_textContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDescription(Verilog2001Parser::DescriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_declaration(Verilog2001Parser::Module_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_keyword(Verilog2001Parser::Module_keywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_parameter_port_list(Verilog2001Parser::Module_parameter_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_ports(Verilog2001Parser::List_of_portsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_port_declarations(Verilog2001Parser::List_of_port_declarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort(Verilog2001Parser::PortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_expression(Verilog2001Parser::Port_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_reference(Verilog2001Parser::Port_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_declaration(Verilog2001Parser::Port_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_item(Verilog2001Parser::Module_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_or_generate_item(Verilog2001Parser::Module_or_generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNon_port_module_item(Verilog2001Parser::Non_port_module_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_or_generate_item_declaration(Verilog2001Parser::Module_or_generate_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_override(Verilog2001Parser::Parameter_overrideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocal_parameter_declaration(Verilog2001Parser::Local_parameter_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_declaration(Verilog2001Parser::Parameter_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_declaration_(Verilog2001Parser::Parameter_declaration_Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecparam_declaration(Verilog2001Parser::Specparam_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInout_declaration(Verilog2001Parser::Inout_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInput_declaration(Verilog2001Parser::Input_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_declaration(Verilog2001Parser::Output_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_declaration(Verilog2001Parser::Event_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_declaration(Verilog2001Parser::Genvar_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_declaration(Verilog2001Parser::Integer_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTime_declaration(Verilog2001Parser::Time_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReal_declaration(Verilog2001Parser::Real_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRealtime_declaration(Verilog2001Parser::Realtime_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReg_declaration(Verilog2001Parser::Reg_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_declaration(Verilog2001Parser::Net_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_type(Verilog2001Parser::Net_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_variable_type(Verilog2001Parser::Output_variable_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReal_type(Verilog2001Parser::Real_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_type(Verilog2001Parser::Variable_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDrive_strength(Verilog2001Parser::Drive_strengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrength0(Verilog2001Parser::Strength0Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrength1(Verilog2001Parser::Strength1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharge_strength(Verilog2001Parser::Charge_strengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay3(Verilog2001Parser::Delay3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay2(Verilog2001Parser::Delay2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay_value(Verilog2001Parser::Delay_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_event_identifiers(Verilog2001Parser::List_of_event_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_net_identifiers(Verilog2001Parser::List_of_net_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_genvar_identifiers(Verilog2001Parser::List_of_genvar_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_port_identifiers(Verilog2001Parser::List_of_port_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_net_decl_assignments(Verilog2001Parser::List_of_net_decl_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_param_assignments(Verilog2001Parser::List_of_param_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_specparam_assignments(Verilog2001Parser::List_of_specparam_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_real_identifiers(Verilog2001Parser::List_of_real_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_variable_identifiers(Verilog2001Parser::List_of_variable_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_variable_port_identifiers(Verilog2001Parser::List_of_variable_port_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_decl_assignment(Verilog2001Parser::Net_decl_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_assignment(Verilog2001Parser::Param_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecparam_assignment(Verilog2001Parser::Specparam_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPulse_control_specparam(Verilog2001Parser::Pulse_control_specparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitError_limit_value(Verilog2001Parser::Error_limit_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReject_limit_value(Verilog2001Parser::Reject_limit_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLimit_value(Verilog2001Parser::Limit_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDimension(Verilog2001Parser::DimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange(Verilog2001Parser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_declaration(Verilog2001Parser::Function_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_item_declaration(Verilog2001Parser::Function_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_port_list(Verilog2001Parser::Function_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_port(Verilog2001Parser::Function_portContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange_or_type(Verilog2001Parser::Range_or_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_declaration(Verilog2001Parser::Task_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_item_declaration(Verilog2001Parser::Task_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_port_list(Verilog2001Parser::Task_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_port_item(Verilog2001Parser::Task_port_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_decl_header(Verilog2001Parser::Tf_decl_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_declaration(Verilog2001Parser::Tf_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_port_type(Verilog2001Parser::Task_port_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_item_declaration(Verilog2001Parser::Block_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_reg_declaration(Verilog2001Parser::Block_reg_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_block_variable_identifiers(Verilog2001Parser::List_of_block_variable_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_variable_type(Verilog2001Parser::Block_variable_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGate_instantiation(Verilog2001Parser::Gate_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCmos_switch_instance(Verilog2001Parser::Cmos_switch_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnable_gate_instance(Verilog2001Parser::Enable_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMos_switch_instance(Verilog2001Parser::Mos_switch_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitN_input_gate_instance(Verilog2001Parser::N_input_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitN_output_gate_instance(Verilog2001Parser::N_output_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_switch_instance(Verilog2001Parser::Pass_switch_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_enable_switch_instance(Verilog2001Parser::Pass_enable_switch_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPull_gate_instance(Verilog2001Parser::Pull_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName_of_gate_instance(Verilog2001Parser::Name_of_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPulldown_strength(Verilog2001Parser::Pulldown_strengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPullup_strength(Verilog2001Parser::Pullup_strengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnable_terminal(Verilog2001Parser::Enable_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNcontrol_terminal(Verilog2001Parser::Ncontrol_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPcontrol_terminal(Verilog2001Parser::Pcontrol_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInput_terminal(Verilog2001Parser::Input_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInout_terminal(Verilog2001Parser::Inout_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_terminal(Verilog2001Parser::Output_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCmos_switchtype(Verilog2001Parser::Cmos_switchtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnable_gatetype(Verilog2001Parser::Enable_gatetypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMos_switchtype(Verilog2001Parser::Mos_switchtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitN_input_gatetype(Verilog2001Parser::N_input_gatetypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitN_output_gatetype(Verilog2001Parser::N_output_gatetypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_en_switchtype(Verilog2001Parser::Pass_en_switchtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_switchtype(Verilog2001Parser::Pass_switchtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_instantiation(Verilog2001Parser::Module_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_value_assignment(Verilog2001Parser::Parameter_value_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_parameter_assignments(Verilog2001Parser::List_of_parameter_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrdered_parameter_assignment(Verilog2001Parser::Ordered_parameter_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_parameter_assignment(Verilog2001Parser::Named_parameter_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_instance(Verilog2001Parser::Module_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName_of_instance(Verilog2001Parser::Name_of_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_port_connections(Verilog2001Parser::List_of_port_connectionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrdered_port_connection(Verilog2001Parser::Ordered_port_connectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_port_connection(Verilog2001Parser::Named_port_connectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerated_instantiation(Verilog2001Parser::Generated_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_item_or_null(Verilog2001Parser::Generate_item_or_nullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_item(Verilog2001Parser::Generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_conditional_statement(Verilog2001Parser::Generate_conditional_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_case_statement(Verilog2001Parser::Generate_case_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_case_item(Verilog2001Parser::Genvar_case_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_loop_statement(Verilog2001Parser::Generate_loop_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_assignment(Verilog2001Parser::Genvar_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_block(Verilog2001Parser::Generate_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinuous_assign(Verilog2001Parser::Continuous_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_net_assignments(Verilog2001Parser::List_of_net_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_assignment(Verilog2001Parser::Net_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitial_construct(Verilog2001Parser::Initial_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlways_construct(Verilog2001Parser::Always_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlocking_assignment(Verilog2001Parser::Blocking_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonblocking_assignment(Verilog2001Parser::Nonblocking_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedural_continuous_assignments(Verilog2001Parser::Procedural_continuous_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_blocking_assignment(Verilog2001Parser::Function_blocking_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_statement_or_null(Verilog2001Parser::Function_statement_or_nullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_seq_block(Verilog2001Parser::Function_seq_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_assignment(Verilog2001Parser::Variable_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPar_block(Verilog2001Parser::Par_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSeq_block(Verilog2001Parser::Seq_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(Verilog2001Parser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_or_null(Verilog2001Parser::Statement_or_nullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_statement(Verilog2001Parser::Function_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay_or_event_control(Verilog2001Parser::Delay_or_event_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay_control(Verilog2001Parser::Delay_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDisable_statement(Verilog2001Parser::Disable_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_control(Verilog2001Parser::Event_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_trigger(Verilog2001Parser::Event_triggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_expression(Verilog2001Parser::Event_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_primary(Verilog2001Parser::Event_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedural_timing_control_statement(Verilog2001Parser::Procedural_timing_control_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWait_statement(Verilog2001Parser::Wait_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_statement(Verilog2001Parser::Conditional_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_else_if_statement(Verilog2001Parser::If_else_if_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_conditional_statement(Verilog2001Parser::Function_conditional_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_if_else_if_statement(Verilog2001Parser::Function_if_else_if_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_statement(Verilog2001Parser::Case_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_item(Verilog2001Parser::Case_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_case_statement(Verilog2001Parser::Function_case_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_case_item(Verilog2001Parser::Function_case_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_loop_statement(Verilog2001Parser::Function_loop_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop_statement(Verilog2001Parser::Loop_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSystem_task_enable(Verilog2001Parser::System_task_enableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_enable(Verilog2001Parser::Task_enableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_block(Verilog2001Parser::Specify_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_item(Verilog2001Parser::Specify_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPulsestyle_declaration(Verilog2001Parser::Pulsestyle_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowcancelled_declaration(Verilog2001Parser::Showcancelled_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPath_declaration(Verilog2001Parser::Path_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_path_declaration(Verilog2001Parser::Simple_path_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParallel_path_description(Verilog2001Parser::Parallel_path_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFull_path_description(Verilog2001Parser::Full_path_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_path_inputs(Verilog2001Parser::List_of_path_inputsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_path_outputs(Verilog2001Parser::List_of_path_outputsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_input_terminal_descriptor(Verilog2001Parser::Specify_input_terminal_descriptorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_output_terminal_descriptor(Verilog2001Parser::Specify_output_terminal_descriptorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInput_identifier(Verilog2001Parser::Input_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_identifier(Verilog2001Parser::Output_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPath_delay_value(Verilog2001Parser::Path_delay_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_path_delay_expressions(Verilog2001Parser::List_of_path_delay_expressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT_path_delay_expression(Verilog2001Parser::T_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrise_path_delay_expression(Verilog2001Parser::Trise_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTfall_path_delay_expression(Verilog2001Parser::Tfall_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTz_path_delay_expression(Verilog2001Parser::Tz_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT01_path_delay_expression(Verilog2001Parser::T01_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT10_path_delay_expression(Verilog2001Parser::T10_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT0z_path_delay_expression(Verilog2001Parser::T0z_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTz1_path_delay_expression(Verilog2001Parser::Tz1_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT1z_path_delay_expression(Verilog2001Parser::T1z_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTz0_path_delay_expression(Verilog2001Parser::Tz0_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT0x_path_delay_expression(Verilog2001Parser::T0x_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTx1_path_delay_expression(Verilog2001Parser::Tx1_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT1x_path_delay_expression(Verilog2001Parser::T1x_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTx0_path_delay_expression(Verilog2001Parser::Tx0_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTxz_path_delay_expression(Verilog2001Parser::Txz_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTzx_path_delay_expression(Verilog2001Parser::Tzx_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPath_delay_expression(Verilog2001Parser::Path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_sensitive_path_declaration(Verilog2001Parser::Edge_sensitive_path_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParallel_edge_sensitive_path_description(Verilog2001Parser::Parallel_edge_sensitive_path_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFull_edge_sensitive_path_description(Verilog2001Parser::Full_edge_sensitive_path_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData_source_expression(Verilog2001Parser::Data_source_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_identifier(Verilog2001Parser::Edge_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitState_dependent_path_declaration(Verilog2001Parser::State_dependent_path_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPolarity_operator(Verilog2001Parser::Polarity_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecktime_condition(Verilog2001Parser::Checktime_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelayed_data(Verilog2001Parser::Delayed_dataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelayed_reference(Verilog2001Parser::Delayed_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnd_edge_offset(Verilog2001Parser::End_edge_offsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_based_flag(Verilog2001Parser::Event_based_flagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotify_reg(Verilog2001Parser::Notify_regContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRemain_active_flag(Verilog2001Parser::Remain_active_flagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStamptime_condition(Verilog2001Parser::Stamptime_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart_edge_offset(Verilog2001Parser::Start_edge_offsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThreshold(Verilog2001Parser::ThresholdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTiming_check_limit(Verilog2001Parser::Timing_check_limitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcatenation(Verilog2001Parser::ConcatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_concatenation(Verilog2001Parser::Constant_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_multiple_concatenation(Verilog2001Parser::Constant_multiple_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_concatenation(Verilog2001Parser::Module_path_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_multiple_concatenation(Verilog2001Parser::Module_path_multiple_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiple_concatenation(Verilog2001Parser::Multiple_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_concatenation(Verilog2001Parser::Net_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_concatenation_value(Verilog2001Parser::Net_concatenation_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_concatenation(Verilog2001Parser::Variable_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_concatenation_value(Verilog2001Parser::Variable_concatenation_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_function_call(Verilog2001Parser::Constant_function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_call(Verilog2001Parser::Function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSystem_function_call(Verilog2001Parser::System_function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_function_call(Verilog2001Parser::Genvar_function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBase_expression(Verilog2001Parser::Base_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_base_expression(Verilog2001Parser::Constant_base_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_expression(Verilog2001Parser::Constant_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_mintypmax_expression(Verilog2001Parser::Constant_mintypmax_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_range_expression(Verilog2001Parser::Constant_range_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDimension_constant_expression(Verilog2001Parser::Dimension_constant_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(Verilog2001Parser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(Verilog2001Parser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLsb_constant_expression(Verilog2001Parser::Lsb_constant_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMintypmax_expression(Verilog2001Parser::Mintypmax_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_conditional_expression(Verilog2001Parser::Module_path_conditional_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_expression(Verilog2001Parser::Module_path_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_mintypmax_expression(Verilog2001Parser::Module_path_mintypmax_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMsb_constant_expression(Verilog2001Parser::Msb_constant_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange_expression(Verilog2001Parser::Range_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWidth_constant_expression(Verilog2001Parser::Width_constant_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_primary(Verilog2001Parser::Constant_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_primary(Verilog2001Parser::Module_path_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary(Verilog2001Parser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_lvalue(Verilog2001Parser::Net_lvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_lvalue(Verilog2001Parser::Variable_lvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(Verilog2001Parser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_operator(Verilog2001Parser::Binary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_module_path_operator(Verilog2001Parser::Unary_module_path_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_module_path_operator(Verilog2001Parser::Binary_module_path_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(Verilog2001Parser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefault_nettype_spec(Verilog2001Parser::Default_nettype_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTiming_spec(Verilog2001Parser::Timing_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_instance(Verilog2001Parser::Attribute_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttr_spec(Verilog2001Parser::Attr_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttr_name(Verilog2001Parser::Attr_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrayed_identifier(Verilog2001Parser::Arrayed_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_identifier(Verilog2001Parser::Block_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCell_identifier(Verilog2001Parser::Cell_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfig_identifier(Verilog2001Parser::Config_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEscaped_arrayed_identifier(Verilog2001Parser::Escaped_arrayed_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEscaped_hierarchical_identifier(Verilog2001Parser::Escaped_hierarchical_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_identifier(Verilog2001Parser::Event_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_identifier(Verilog2001Parser::Function_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGate_instance_identifier(Verilog2001Parser::Gate_instance_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_block_identifier(Verilog2001Parser::Generate_block_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_function_identifier(Verilog2001Parser::Genvar_function_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_identifier(Verilog2001Parser::Genvar_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_block_identifier(Verilog2001Parser::Hierarchical_block_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_event_identifier(Verilog2001Parser::Hierarchical_event_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_function_identifier(Verilog2001Parser::Hierarchical_function_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_identifier(Verilog2001Parser::Hierarchical_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_net_identifier(Verilog2001Parser::Hierarchical_net_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_variable_identifier(Verilog2001Parser::Hierarchical_variable_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_task_identifier(Verilog2001Parser::Hierarchical_task_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(Verilog2001Parser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInout_port_identifier(Verilog2001Parser::Inout_port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInput_port_identifier(Verilog2001Parser::Input_port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_identifier(Verilog2001Parser::Instance_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibrary_identifier(Verilog2001Parser::Library_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemory_identifier(Verilog2001Parser::Memory_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_identifier(Verilog2001Parser::Module_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_instance_identifier(Verilog2001Parser::Module_instance_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_identifier(Verilog2001Parser::Net_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_port_identifier(Verilog2001Parser::Output_port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_identifier(Verilog2001Parser::Parameter_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_identifier(Verilog2001Parser::Port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReal_identifier(Verilog2001Parser::Real_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_arrayed_identifier(Verilog2001Parser::Simple_arrayed_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_hierarchical_identifier(Verilog2001Parser::Simple_hierarchical_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecparam_identifier(Verilog2001Parser::Specparam_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSystem_function_identifier(Verilog2001Parser::System_function_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSystem_task_identifier(Verilog2001Parser::System_task_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_identifier(Verilog2001Parser::Task_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerminal_identifier(Verilog2001Parser::Terminal_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitText_macro_identifier(Verilog2001Parser::Text_macro_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTopmodule_identifier(Verilog2001Parser::Topmodule_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_identifier(Verilog2001Parser::Udp_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_instance_identifier(Verilog2001Parser::Udp_instance_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_identifier(Verilog2001Parser::Variable_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_hierarchical_branch(Verilog2001Parser::Simple_hierarchical_branchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEscaped_hierarchical_branch(Verilog2001Parser::Escaped_hierarchical_branchContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace verilog
