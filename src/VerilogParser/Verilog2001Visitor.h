
// Generated from Verilog2001.g4 by ANTLR 4.5.3

#pragma once


#include "antlr4-runtime.h"
#include "Verilog2001Parser.h"


namespace verilog {

/**
 * This template class defines an abstract visitor for a parse tree
 * produced by Verilog2001Parser.
 *
 * @param <T> The return type of the visit operation. Use void for
 * operations with no return type.
 */
template <typename T>
class Verilog2001Visitor : public antlr4::tree::ParseTreeVisitor<T> {
public:

  /**
   * Visit parse trees produced by Verilog2001Parser.
   */
    virtual T* visitConfig_declaration(Verilog2001Parser::Config_declarationContext *context) = 0;

    virtual T* visitDesign_statement(Verilog2001Parser::Design_statementContext *context) = 0;

    virtual T* visitConfig_rule_statement(Verilog2001Parser::Config_rule_statementContext *context) = 0;

    virtual T* visitDefault_clause(Verilog2001Parser::Default_clauseContext *context) = 0;

    virtual T* visitInst_clause(Verilog2001Parser::Inst_clauseContext *context) = 0;

    virtual T* visitInst_name(Verilog2001Parser::Inst_nameContext *context) = 0;

    virtual T* visitLiblist_clause(Verilog2001Parser::Liblist_clauseContext *context) = 0;

    virtual T* visitCell_clause(Verilog2001Parser::Cell_clauseContext *context) = 0;

    virtual T* visitUse_clause(Verilog2001Parser::Use_clauseContext *context) = 0;

    virtual T* visitSource_text(Verilog2001Parser::Source_textContext *context) = 0;

    virtual T* visitDescription(Verilog2001Parser::DescriptionContext *context) = 0;

    virtual T* visitModule_declaration(Verilog2001Parser::Module_declarationContext *context) = 0;

    virtual T* visitModule_keyword(Verilog2001Parser::Module_keywordContext *context) = 0;

    virtual T* visitModule_parameter_port_list(Verilog2001Parser::Module_parameter_port_listContext *context) = 0;

    virtual T* visitList_of_ports(Verilog2001Parser::List_of_portsContext *context) = 0;

    virtual T* visitList_of_port_declarations(Verilog2001Parser::List_of_port_declarationsContext *context) = 0;

    virtual T* visitPort(Verilog2001Parser::PortContext *context) = 0;

    virtual T* visitPort_expression(Verilog2001Parser::Port_expressionContext *context) = 0;

    virtual T* visitPort_reference(Verilog2001Parser::Port_referenceContext *context) = 0;

    virtual T* visitPort_declaration(Verilog2001Parser::Port_declarationContext *context) = 0;

    virtual T* visitModule_item(Verilog2001Parser::Module_itemContext *context) = 0;

    virtual T* visitModule_or_generate_item(Verilog2001Parser::Module_or_generate_itemContext *context) = 0;

    virtual T* visitNon_port_module_item(Verilog2001Parser::Non_port_module_itemContext *context) = 0;

    virtual T* visitModule_or_generate_item_declaration(Verilog2001Parser::Module_or_generate_item_declarationContext *context) = 0;

    virtual T* visitParameter_override(Verilog2001Parser::Parameter_overrideContext *context) = 0;

    virtual T* visitLocal_parameter_declaration(Verilog2001Parser::Local_parameter_declarationContext *context) = 0;

    virtual T* visitParameter_declaration(Verilog2001Parser::Parameter_declarationContext *context) = 0;

    virtual T* visitParameter_declaration_(Verilog2001Parser::Parameter_declaration_Context *context) = 0;

    virtual T* visitSpecparam_declaration(Verilog2001Parser::Specparam_declarationContext *context) = 0;

    virtual T* visitInout_declaration(Verilog2001Parser::Inout_declarationContext *context) = 0;

    virtual T* visitInput_declaration(Verilog2001Parser::Input_declarationContext *context) = 0;

    virtual T* visitOutput_declaration(Verilog2001Parser::Output_declarationContext *context) = 0;

    virtual T* visitEvent_declaration(Verilog2001Parser::Event_declarationContext *context) = 0;

    virtual T* visitGenvar_declaration(Verilog2001Parser::Genvar_declarationContext *context) = 0;

    virtual T* visitInteger_declaration(Verilog2001Parser::Integer_declarationContext *context) = 0;

    virtual T* visitTime_declaration(Verilog2001Parser::Time_declarationContext *context) = 0;

    virtual T* visitReal_declaration(Verilog2001Parser::Real_declarationContext *context) = 0;

    virtual T* visitRealtime_declaration(Verilog2001Parser::Realtime_declarationContext *context) = 0;

    virtual T* visitReg_declaration(Verilog2001Parser::Reg_declarationContext *context) = 0;

    virtual T* visitNet_declaration(Verilog2001Parser::Net_declarationContext *context) = 0;

    virtual T* visitNet_type(Verilog2001Parser::Net_typeContext *context) = 0;

    virtual T* visitOutput_variable_type(Verilog2001Parser::Output_variable_typeContext *context) = 0;

    virtual T* visitReal_type(Verilog2001Parser::Real_typeContext *context) = 0;

    virtual T* visitVariable_type(Verilog2001Parser::Variable_typeContext *context) = 0;

    virtual T* visitDrive_strength(Verilog2001Parser::Drive_strengthContext *context) = 0;

    virtual T* visitStrength0(Verilog2001Parser::Strength0Context *context) = 0;

    virtual T* visitStrength1(Verilog2001Parser::Strength1Context *context) = 0;

    virtual T* visitCharge_strength(Verilog2001Parser::Charge_strengthContext *context) = 0;

    virtual T* visitDelay3(Verilog2001Parser::Delay3Context *context) = 0;

    virtual T* visitDelay2(Verilog2001Parser::Delay2Context *context) = 0;

    virtual T* visitDelay_value(Verilog2001Parser::Delay_valueContext *context) = 0;

    virtual T* visitList_of_event_identifiers(Verilog2001Parser::List_of_event_identifiersContext *context) = 0;

    virtual T* visitList_of_net_identifiers(Verilog2001Parser::List_of_net_identifiersContext *context) = 0;

    virtual T* visitList_of_genvar_identifiers(Verilog2001Parser::List_of_genvar_identifiersContext *context) = 0;

    virtual T* visitList_of_port_identifiers(Verilog2001Parser::List_of_port_identifiersContext *context) = 0;

    virtual T* visitList_of_net_decl_assignments(Verilog2001Parser::List_of_net_decl_assignmentsContext *context) = 0;

    virtual T* visitList_of_param_assignments(Verilog2001Parser::List_of_param_assignmentsContext *context) = 0;

    virtual T* visitList_of_specparam_assignments(Verilog2001Parser::List_of_specparam_assignmentsContext *context) = 0;

    virtual T* visitList_of_real_identifiers(Verilog2001Parser::List_of_real_identifiersContext *context) = 0;

    virtual T* visitList_of_variable_identifiers(Verilog2001Parser::List_of_variable_identifiersContext *context) = 0;

    virtual T* visitList_of_variable_port_identifiers(Verilog2001Parser::List_of_variable_port_identifiersContext *context) = 0;

    virtual T* visitNet_decl_assignment(Verilog2001Parser::Net_decl_assignmentContext *context) = 0;

    virtual T* visitParam_assignment(Verilog2001Parser::Param_assignmentContext *context) = 0;

    virtual T* visitSpecparam_assignment(Verilog2001Parser::Specparam_assignmentContext *context) = 0;

    virtual T* visitPulse_control_specparam(Verilog2001Parser::Pulse_control_specparamContext *context) = 0;

    virtual T* visitError_limit_value(Verilog2001Parser::Error_limit_valueContext *context) = 0;

    virtual T* visitReject_limit_value(Verilog2001Parser::Reject_limit_valueContext *context) = 0;

    virtual T* visitLimit_value(Verilog2001Parser::Limit_valueContext *context) = 0;

    virtual T* visitDimension(Verilog2001Parser::DimensionContext *context) = 0;

    virtual T* visitRange(Verilog2001Parser::RangeContext *context) = 0;

    virtual T* visitFunction_declaration(Verilog2001Parser::Function_declarationContext *context) = 0;

    virtual T* visitFunction_item_declaration(Verilog2001Parser::Function_item_declarationContext *context) = 0;

    virtual T* visitFunction_port_list(Verilog2001Parser::Function_port_listContext *context) = 0;

    virtual T* visitFunction_port(Verilog2001Parser::Function_portContext *context) = 0;

    virtual T* visitRange_or_type(Verilog2001Parser::Range_or_typeContext *context) = 0;

    virtual T* visitTask_declaration(Verilog2001Parser::Task_declarationContext *context) = 0;

    virtual T* visitTask_item_declaration(Verilog2001Parser::Task_item_declarationContext *context) = 0;

    virtual T* visitTask_port_list(Verilog2001Parser::Task_port_listContext *context) = 0;

    virtual T* visitTask_port_item(Verilog2001Parser::Task_port_itemContext *context) = 0;

    virtual T* visitTf_decl_header(Verilog2001Parser::Tf_decl_headerContext *context) = 0;

    virtual T* visitTf_declaration(Verilog2001Parser::Tf_declarationContext *context) = 0;

    virtual T* visitTask_port_type(Verilog2001Parser::Task_port_typeContext *context) = 0;

    virtual T* visitBlock_item_declaration(Verilog2001Parser::Block_item_declarationContext *context) = 0;

    virtual T* visitBlock_reg_declaration(Verilog2001Parser::Block_reg_declarationContext *context) = 0;

    virtual T* visitList_of_block_variable_identifiers(Verilog2001Parser::List_of_block_variable_identifiersContext *context) = 0;

    virtual T* visitBlock_variable_type(Verilog2001Parser::Block_variable_typeContext *context) = 0;

    virtual T* visitGate_instantiation(Verilog2001Parser::Gate_instantiationContext *context) = 0;

    virtual T* visitCmos_switch_instance(Verilog2001Parser::Cmos_switch_instanceContext *context) = 0;

    virtual T* visitEnable_gate_instance(Verilog2001Parser::Enable_gate_instanceContext *context) = 0;

    virtual T* visitMos_switch_instance(Verilog2001Parser::Mos_switch_instanceContext *context) = 0;

    virtual T* visitN_input_gate_instance(Verilog2001Parser::N_input_gate_instanceContext *context) = 0;

    virtual T* visitN_output_gate_instance(Verilog2001Parser::N_output_gate_instanceContext *context) = 0;

    virtual T* visitPass_switch_instance(Verilog2001Parser::Pass_switch_instanceContext *context) = 0;

    virtual T* visitPass_enable_switch_instance(Verilog2001Parser::Pass_enable_switch_instanceContext *context) = 0;

    virtual T* visitPull_gate_instance(Verilog2001Parser::Pull_gate_instanceContext *context) = 0;

    virtual T* visitName_of_gate_instance(Verilog2001Parser::Name_of_gate_instanceContext *context) = 0;

    virtual T* visitPulldown_strength(Verilog2001Parser::Pulldown_strengthContext *context) = 0;

    virtual T* visitPullup_strength(Verilog2001Parser::Pullup_strengthContext *context) = 0;

    virtual T* visitEnable_terminal(Verilog2001Parser::Enable_terminalContext *context) = 0;

    virtual T* visitNcontrol_terminal(Verilog2001Parser::Ncontrol_terminalContext *context) = 0;

    virtual T* visitPcontrol_terminal(Verilog2001Parser::Pcontrol_terminalContext *context) = 0;

    virtual T* visitInput_terminal(Verilog2001Parser::Input_terminalContext *context) = 0;

    virtual T* visitInout_terminal(Verilog2001Parser::Inout_terminalContext *context) = 0;

    virtual T* visitOutput_terminal(Verilog2001Parser::Output_terminalContext *context) = 0;

    virtual T* visitCmos_switchtype(Verilog2001Parser::Cmos_switchtypeContext *context) = 0;

    virtual T* visitEnable_gatetype(Verilog2001Parser::Enable_gatetypeContext *context) = 0;

    virtual T* visitMos_switchtype(Verilog2001Parser::Mos_switchtypeContext *context) = 0;

    virtual T* visitN_input_gatetype(Verilog2001Parser::N_input_gatetypeContext *context) = 0;

    virtual T* visitN_output_gatetype(Verilog2001Parser::N_output_gatetypeContext *context) = 0;

    virtual T* visitPass_en_switchtype(Verilog2001Parser::Pass_en_switchtypeContext *context) = 0;

    virtual T* visitPass_switchtype(Verilog2001Parser::Pass_switchtypeContext *context) = 0;

    virtual T* visitModule_instantiation(Verilog2001Parser::Module_instantiationContext *context) = 0;

    virtual T* visitParameter_value_assignment(Verilog2001Parser::Parameter_value_assignmentContext *context) = 0;

    virtual T* visitList_of_parameter_assignments(Verilog2001Parser::List_of_parameter_assignmentsContext *context) = 0;

    virtual T* visitOrdered_parameter_assignment(Verilog2001Parser::Ordered_parameter_assignmentContext *context) = 0;

    virtual T* visitNamed_parameter_assignment(Verilog2001Parser::Named_parameter_assignmentContext *context) = 0;

    virtual T* visitModule_instance(Verilog2001Parser::Module_instanceContext *context) = 0;

    virtual T* visitName_of_instance(Verilog2001Parser::Name_of_instanceContext *context) = 0;

    virtual T* visitList_of_port_connections(Verilog2001Parser::List_of_port_connectionsContext *context) = 0;

    virtual T* visitOrdered_port_connection(Verilog2001Parser::Ordered_port_connectionContext *context) = 0;

    virtual T* visitNamed_port_connection(Verilog2001Parser::Named_port_connectionContext *context) = 0;

    virtual T* visitGenerated_instantiation(Verilog2001Parser::Generated_instantiationContext *context) = 0;

    virtual T* visitGenerate_item_or_null(Verilog2001Parser::Generate_item_or_nullContext *context) = 0;

    virtual T* visitGenerate_item(Verilog2001Parser::Generate_itemContext *context) = 0;

    virtual T* visitGenerate_conditional_statement(Verilog2001Parser::Generate_conditional_statementContext *context) = 0;

    virtual T* visitGenerate_case_statement(Verilog2001Parser::Generate_case_statementContext *context) = 0;

    virtual T* visitGenvar_case_item(Verilog2001Parser::Genvar_case_itemContext *context) = 0;

    virtual T* visitGenerate_loop_statement(Verilog2001Parser::Generate_loop_statementContext *context) = 0;

    virtual T* visitGenvar_assignment(Verilog2001Parser::Genvar_assignmentContext *context) = 0;

    virtual T* visitGenerate_block(Verilog2001Parser::Generate_blockContext *context) = 0;

    virtual T* visitContinuous_assign(Verilog2001Parser::Continuous_assignContext *context) = 0;

    virtual T* visitList_of_net_assignments(Verilog2001Parser::List_of_net_assignmentsContext *context) = 0;

    virtual T* visitNet_assignment(Verilog2001Parser::Net_assignmentContext *context) = 0;

    virtual T* visitInitial_construct(Verilog2001Parser::Initial_constructContext *context) = 0;

    virtual T* visitAlways_construct(Verilog2001Parser::Always_constructContext *context) = 0;

    virtual T* visitBlocking_assignment(Verilog2001Parser::Blocking_assignmentContext *context) = 0;

    virtual T* visitNonblocking_assignment(Verilog2001Parser::Nonblocking_assignmentContext *context) = 0;

    virtual T* visitProcedural_continuous_assignments(Verilog2001Parser::Procedural_continuous_assignmentsContext *context) = 0;

    virtual T* visitFunction_blocking_assignment(Verilog2001Parser::Function_blocking_assignmentContext *context) = 0;

    virtual T* visitFunction_statement_or_null(Verilog2001Parser::Function_statement_or_nullContext *context) = 0;

    virtual T* visitFunction_seq_block(Verilog2001Parser::Function_seq_blockContext *context) = 0;

    virtual T* visitVariable_assignment(Verilog2001Parser::Variable_assignmentContext *context) = 0;

    virtual T* visitPar_block(Verilog2001Parser::Par_blockContext *context) = 0;

    virtual T* visitSeq_block(Verilog2001Parser::Seq_blockContext *context) = 0;

    virtual T* visitStatement(Verilog2001Parser::StatementContext *context) = 0;

    virtual T* visitStatement_or_null(Verilog2001Parser::Statement_or_nullContext *context) = 0;

    virtual T* visitFunction_statement(Verilog2001Parser::Function_statementContext *context) = 0;

    virtual T* visitDelay_or_event_control(Verilog2001Parser::Delay_or_event_controlContext *context) = 0;

    virtual T* visitDelay_control(Verilog2001Parser::Delay_controlContext *context) = 0;

    virtual T* visitDisable_statement(Verilog2001Parser::Disable_statementContext *context) = 0;

    virtual T* visitEvent_control(Verilog2001Parser::Event_controlContext *context) = 0;

    virtual T* visitEvent_trigger(Verilog2001Parser::Event_triggerContext *context) = 0;

    virtual T* visitEvent_expression(Verilog2001Parser::Event_expressionContext *context) = 0;

    virtual T* visitEvent_primary(Verilog2001Parser::Event_primaryContext *context) = 0;

    virtual T* visitProcedural_timing_control_statement(Verilog2001Parser::Procedural_timing_control_statementContext *context) = 0;

    virtual T* visitWait_statement(Verilog2001Parser::Wait_statementContext *context) = 0;

    virtual T* visitConditional_statement(Verilog2001Parser::Conditional_statementContext *context) = 0;

    virtual T* visitIf_else_if_statement(Verilog2001Parser::If_else_if_statementContext *context) = 0;

    virtual T* visitFunction_conditional_statement(Verilog2001Parser::Function_conditional_statementContext *context) = 0;

    virtual T* visitFunction_if_else_if_statement(Verilog2001Parser::Function_if_else_if_statementContext *context) = 0;

    virtual T* visitCase_statement(Verilog2001Parser::Case_statementContext *context) = 0;

    virtual T* visitCase_item(Verilog2001Parser::Case_itemContext *context) = 0;

    virtual T* visitFunction_case_statement(Verilog2001Parser::Function_case_statementContext *context) = 0;

    virtual T* visitFunction_case_item(Verilog2001Parser::Function_case_itemContext *context) = 0;

    virtual T* visitFunction_loop_statement(Verilog2001Parser::Function_loop_statementContext *context) = 0;

    virtual T* visitLoop_statement(Verilog2001Parser::Loop_statementContext *context) = 0;

    virtual T* visitSystem_task_enable(Verilog2001Parser::System_task_enableContext *context) = 0;

    virtual T* visitTask_enable(Verilog2001Parser::Task_enableContext *context) = 0;

    virtual T* visitSpecify_block(Verilog2001Parser::Specify_blockContext *context) = 0;

    virtual T* visitSpecify_item(Verilog2001Parser::Specify_itemContext *context) = 0;

    virtual T* visitPulsestyle_declaration(Verilog2001Parser::Pulsestyle_declarationContext *context) = 0;

    virtual T* visitShowcancelled_declaration(Verilog2001Parser::Showcancelled_declarationContext *context) = 0;

    virtual T* visitPath_declaration(Verilog2001Parser::Path_declarationContext *context) = 0;

    virtual T* visitSimple_path_declaration(Verilog2001Parser::Simple_path_declarationContext *context) = 0;

    virtual T* visitParallel_path_description(Verilog2001Parser::Parallel_path_descriptionContext *context) = 0;

    virtual T* visitFull_path_description(Verilog2001Parser::Full_path_descriptionContext *context) = 0;

    virtual T* visitList_of_path_inputs(Verilog2001Parser::List_of_path_inputsContext *context) = 0;

    virtual T* visitList_of_path_outputs(Verilog2001Parser::List_of_path_outputsContext *context) = 0;

    virtual T* visitSpecify_input_terminal_descriptor(Verilog2001Parser::Specify_input_terminal_descriptorContext *context) = 0;

    virtual T* visitSpecify_output_terminal_descriptor(Verilog2001Parser::Specify_output_terminal_descriptorContext *context) = 0;

    virtual T* visitInput_identifier(Verilog2001Parser::Input_identifierContext *context) = 0;

    virtual T* visitOutput_identifier(Verilog2001Parser::Output_identifierContext *context) = 0;

    virtual T* visitPath_delay_value(Verilog2001Parser::Path_delay_valueContext *context) = 0;

    virtual T* visitList_of_path_delay_expressions(Verilog2001Parser::List_of_path_delay_expressionsContext *context) = 0;

    virtual T* visitT_path_delay_expression(Verilog2001Parser::T_path_delay_expressionContext *context) = 0;

    virtual T* visitTrise_path_delay_expression(Verilog2001Parser::Trise_path_delay_expressionContext *context) = 0;

    virtual T* visitTfall_path_delay_expression(Verilog2001Parser::Tfall_path_delay_expressionContext *context) = 0;

    virtual T* visitTz_path_delay_expression(Verilog2001Parser::Tz_path_delay_expressionContext *context) = 0;

    virtual T* visitT01_path_delay_expression(Verilog2001Parser::T01_path_delay_expressionContext *context) = 0;

    virtual T* visitT10_path_delay_expression(Verilog2001Parser::T10_path_delay_expressionContext *context) = 0;

    virtual T* visitT0z_path_delay_expression(Verilog2001Parser::T0z_path_delay_expressionContext *context) = 0;

    virtual T* visitTz1_path_delay_expression(Verilog2001Parser::Tz1_path_delay_expressionContext *context) = 0;

    virtual T* visitT1z_path_delay_expression(Verilog2001Parser::T1z_path_delay_expressionContext *context) = 0;

    virtual T* visitTz0_path_delay_expression(Verilog2001Parser::Tz0_path_delay_expressionContext *context) = 0;

    virtual T* visitT0x_path_delay_expression(Verilog2001Parser::T0x_path_delay_expressionContext *context) = 0;

    virtual T* visitTx1_path_delay_expression(Verilog2001Parser::Tx1_path_delay_expressionContext *context) = 0;

    virtual T* visitT1x_path_delay_expression(Verilog2001Parser::T1x_path_delay_expressionContext *context) = 0;

    virtual T* visitTx0_path_delay_expression(Verilog2001Parser::Tx0_path_delay_expressionContext *context) = 0;

    virtual T* visitTxz_path_delay_expression(Verilog2001Parser::Txz_path_delay_expressionContext *context) = 0;

    virtual T* visitTzx_path_delay_expression(Verilog2001Parser::Tzx_path_delay_expressionContext *context) = 0;

    virtual T* visitPath_delay_expression(Verilog2001Parser::Path_delay_expressionContext *context) = 0;

    virtual T* visitEdge_sensitive_path_declaration(Verilog2001Parser::Edge_sensitive_path_declarationContext *context) = 0;

    virtual T* visitParallel_edge_sensitive_path_description(Verilog2001Parser::Parallel_edge_sensitive_path_descriptionContext *context) = 0;

    virtual T* visitFull_edge_sensitive_path_description(Verilog2001Parser::Full_edge_sensitive_path_descriptionContext *context) = 0;

    virtual T* visitData_source_expression(Verilog2001Parser::Data_source_expressionContext *context) = 0;

    virtual T* visitEdge_identifier(Verilog2001Parser::Edge_identifierContext *context) = 0;

    virtual T* visitState_dependent_path_declaration(Verilog2001Parser::State_dependent_path_declarationContext *context) = 0;

    virtual T* visitPolarity_operator(Verilog2001Parser::Polarity_operatorContext *context) = 0;

    virtual T* visitChecktime_condition(Verilog2001Parser::Checktime_conditionContext *context) = 0;

    virtual T* visitDelayed_data(Verilog2001Parser::Delayed_dataContext *context) = 0;

    virtual T* visitDelayed_reference(Verilog2001Parser::Delayed_referenceContext *context) = 0;

    virtual T* visitEnd_edge_offset(Verilog2001Parser::End_edge_offsetContext *context) = 0;

    virtual T* visitEvent_based_flag(Verilog2001Parser::Event_based_flagContext *context) = 0;

    virtual T* visitNotify_reg(Verilog2001Parser::Notify_regContext *context) = 0;

    virtual T* visitRemain_active_flag(Verilog2001Parser::Remain_active_flagContext *context) = 0;

    virtual T* visitStamptime_condition(Verilog2001Parser::Stamptime_conditionContext *context) = 0;

    virtual T* visitStart_edge_offset(Verilog2001Parser::Start_edge_offsetContext *context) = 0;

    virtual T* visitThreshold(Verilog2001Parser::ThresholdContext *context) = 0;

    virtual T* visitTiming_check_limit(Verilog2001Parser::Timing_check_limitContext *context) = 0;

    virtual T* visitConcatenation(Verilog2001Parser::ConcatenationContext *context) = 0;

    virtual T* visitConstant_concatenation(Verilog2001Parser::Constant_concatenationContext *context) = 0;

    virtual T* visitConstant_multiple_concatenation(Verilog2001Parser::Constant_multiple_concatenationContext *context) = 0;

    virtual T* visitModule_path_concatenation(Verilog2001Parser::Module_path_concatenationContext *context) = 0;

    virtual T* visitModule_path_multiple_concatenation(Verilog2001Parser::Module_path_multiple_concatenationContext *context) = 0;

    virtual T* visitMultiple_concatenation(Verilog2001Parser::Multiple_concatenationContext *context) = 0;

    virtual T* visitNet_concatenation(Verilog2001Parser::Net_concatenationContext *context) = 0;

    virtual T* visitNet_concatenation_value(Verilog2001Parser::Net_concatenation_valueContext *context) = 0;

    virtual T* visitVariable_concatenation(Verilog2001Parser::Variable_concatenationContext *context) = 0;

    virtual T* visitVariable_concatenation_value(Verilog2001Parser::Variable_concatenation_valueContext *context) = 0;

    virtual T* visitConstant_function_call(Verilog2001Parser::Constant_function_callContext *context) = 0;

    virtual T* visitFunction_call(Verilog2001Parser::Function_callContext *context) = 0;

    virtual T* visitSystem_function_call(Verilog2001Parser::System_function_callContext *context) = 0;

    virtual T* visitGenvar_function_call(Verilog2001Parser::Genvar_function_callContext *context) = 0;

    virtual T* visitBase_expression(Verilog2001Parser::Base_expressionContext *context) = 0;

    virtual T* visitConstant_base_expression(Verilog2001Parser::Constant_base_expressionContext *context) = 0;

    virtual T* visitConstant_expression(Verilog2001Parser::Constant_expressionContext *context) = 0;

    virtual T* visitConstant_mintypmax_expression(Verilog2001Parser::Constant_mintypmax_expressionContext *context) = 0;

    virtual T* visitConstant_range_expression(Verilog2001Parser::Constant_range_expressionContext *context) = 0;

    virtual T* visitDimension_constant_expression(Verilog2001Parser::Dimension_constant_expressionContext *context) = 0;

    virtual T* visitExpression(Verilog2001Parser::ExpressionContext *context) = 0;

    virtual T* visitTerm(Verilog2001Parser::TermContext *context) = 0;

    virtual T* visitLsb_constant_expression(Verilog2001Parser::Lsb_constant_expressionContext *context) = 0;

    virtual T* visitMintypmax_expression(Verilog2001Parser::Mintypmax_expressionContext *context) = 0;

    virtual T* visitModule_path_conditional_expression(Verilog2001Parser::Module_path_conditional_expressionContext *context) = 0;

    virtual T* visitModule_path_expression(Verilog2001Parser::Module_path_expressionContext *context) = 0;

    virtual T* visitModule_path_mintypmax_expression(Verilog2001Parser::Module_path_mintypmax_expressionContext *context) = 0;

    virtual T* visitMsb_constant_expression(Verilog2001Parser::Msb_constant_expressionContext *context) = 0;

    virtual T* visitRange_expression(Verilog2001Parser::Range_expressionContext *context) = 0;

    virtual T* visitWidth_constant_expression(Verilog2001Parser::Width_constant_expressionContext *context) = 0;

    virtual T* visitConstant_primary(Verilog2001Parser::Constant_primaryContext *context) = 0;

    virtual T* visitModule_path_primary(Verilog2001Parser::Module_path_primaryContext *context) = 0;

    virtual T* visitPrimary(Verilog2001Parser::PrimaryContext *context) = 0;

    virtual T* visitNet_lvalue(Verilog2001Parser::Net_lvalueContext *context) = 0;

    virtual T* visitVariable_lvalue(Verilog2001Parser::Variable_lvalueContext *context) = 0;

    virtual T* visitUnary_operator(Verilog2001Parser::Unary_operatorContext *context) = 0;

    virtual T* visitBinary_operator(Verilog2001Parser::Binary_operatorContext *context) = 0;

    virtual T* visitUnary_module_path_operator(Verilog2001Parser::Unary_module_path_operatorContext *context) = 0;

    virtual T* visitBinary_module_path_operator(Verilog2001Parser::Binary_module_path_operatorContext *context) = 0;

    virtual T* visitNumber(Verilog2001Parser::NumberContext *context) = 0;

    virtual T* visitDefault_nettype_spec(Verilog2001Parser::Default_nettype_specContext *context) = 0;

    virtual T* visitTiming_spec(Verilog2001Parser::Timing_specContext *context) = 0;

    virtual T* visitAttribute_instance(Verilog2001Parser::Attribute_instanceContext *context) = 0;

    virtual T* visitAttr_spec(Verilog2001Parser::Attr_specContext *context) = 0;

    virtual T* visitAttr_name(Verilog2001Parser::Attr_nameContext *context) = 0;

    virtual T* visitArrayed_identifier(Verilog2001Parser::Arrayed_identifierContext *context) = 0;

    virtual T* visitBlock_identifier(Verilog2001Parser::Block_identifierContext *context) = 0;

    virtual T* visitCell_identifier(Verilog2001Parser::Cell_identifierContext *context) = 0;

    virtual T* visitConfig_identifier(Verilog2001Parser::Config_identifierContext *context) = 0;

    virtual T* visitEscaped_arrayed_identifier(Verilog2001Parser::Escaped_arrayed_identifierContext *context) = 0;

    virtual T* visitEscaped_hierarchical_identifier(Verilog2001Parser::Escaped_hierarchical_identifierContext *context) = 0;

    virtual T* visitEvent_identifier(Verilog2001Parser::Event_identifierContext *context) = 0;

    virtual T* visitFunction_identifier(Verilog2001Parser::Function_identifierContext *context) = 0;

    virtual T* visitGate_instance_identifier(Verilog2001Parser::Gate_instance_identifierContext *context) = 0;

    virtual T* visitGenerate_block_identifier(Verilog2001Parser::Generate_block_identifierContext *context) = 0;

    virtual T* visitGenvar_function_identifier(Verilog2001Parser::Genvar_function_identifierContext *context) = 0;

    virtual T* visitGenvar_identifier(Verilog2001Parser::Genvar_identifierContext *context) = 0;

    virtual T* visitHierarchical_block_identifier(Verilog2001Parser::Hierarchical_block_identifierContext *context) = 0;

    virtual T* visitHierarchical_event_identifier(Verilog2001Parser::Hierarchical_event_identifierContext *context) = 0;

    virtual T* visitHierarchical_function_identifier(Verilog2001Parser::Hierarchical_function_identifierContext *context) = 0;

    virtual T* visitHierarchical_identifier(Verilog2001Parser::Hierarchical_identifierContext *context) = 0;

    virtual T* visitHierarchical_net_identifier(Verilog2001Parser::Hierarchical_net_identifierContext *context) = 0;

    virtual T* visitHierarchical_variable_identifier(Verilog2001Parser::Hierarchical_variable_identifierContext *context) = 0;

    virtual T* visitHierarchical_task_identifier(Verilog2001Parser::Hierarchical_task_identifierContext *context) = 0;

    virtual T* visitIdentifier(Verilog2001Parser::IdentifierContext *context) = 0;

    virtual T* visitInout_port_identifier(Verilog2001Parser::Inout_port_identifierContext *context) = 0;

    virtual T* visitInput_port_identifier(Verilog2001Parser::Input_port_identifierContext *context) = 0;

    virtual T* visitInstance_identifier(Verilog2001Parser::Instance_identifierContext *context) = 0;

    virtual T* visitLibrary_identifier(Verilog2001Parser::Library_identifierContext *context) = 0;

    virtual T* visitMemory_identifier(Verilog2001Parser::Memory_identifierContext *context) = 0;

    virtual T* visitModule_identifier(Verilog2001Parser::Module_identifierContext *context) = 0;

    virtual T* visitModule_instance_identifier(Verilog2001Parser::Module_instance_identifierContext *context) = 0;

    virtual T* visitNet_identifier(Verilog2001Parser::Net_identifierContext *context) = 0;

    virtual T* visitOutput_port_identifier(Verilog2001Parser::Output_port_identifierContext *context) = 0;

    virtual T* visitParameter_identifier(Verilog2001Parser::Parameter_identifierContext *context) = 0;

    virtual T* visitPort_identifier(Verilog2001Parser::Port_identifierContext *context) = 0;

    virtual T* visitReal_identifier(Verilog2001Parser::Real_identifierContext *context) = 0;

    virtual T* visitSimple_arrayed_identifier(Verilog2001Parser::Simple_arrayed_identifierContext *context) = 0;

    virtual T* visitSimple_hierarchical_identifier(Verilog2001Parser::Simple_hierarchical_identifierContext *context) = 0;

    virtual T* visitSpecparam_identifier(Verilog2001Parser::Specparam_identifierContext *context) = 0;

    virtual T* visitSystem_function_identifier(Verilog2001Parser::System_function_identifierContext *context) = 0;

    virtual T* visitSystem_task_identifier(Verilog2001Parser::System_task_identifierContext *context) = 0;

    virtual T* visitTask_identifier(Verilog2001Parser::Task_identifierContext *context) = 0;

    virtual T* visitTerminal_identifier(Verilog2001Parser::Terminal_identifierContext *context) = 0;

    virtual T* visitText_macro_identifier(Verilog2001Parser::Text_macro_identifierContext *context) = 0;

    virtual T* visitTopmodule_identifier(Verilog2001Parser::Topmodule_identifierContext *context) = 0;

    virtual T* visitUdp_identifier(Verilog2001Parser::Udp_identifierContext *context) = 0;

    virtual T* visitUdp_instance_identifier(Verilog2001Parser::Udp_instance_identifierContext *context) = 0;

    virtual T* visitVariable_identifier(Verilog2001Parser::Variable_identifierContext *context) = 0;

    virtual T* visitSimple_hierarchical_branch(Verilog2001Parser::Simple_hierarchical_branchContext *context) = 0;

    virtual T* visitEscaped_hierarchical_branch(Verilog2001Parser::Escaped_hierarchical_branchContext *context) = 0;


};

}  // namespace verilog
