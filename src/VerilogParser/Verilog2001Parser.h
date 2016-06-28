
// Generated from Verilog2001.g4 by ANTLR 4.5.3

#pragma once


#include "antlr4-runtime.h"


using namespace antlr4;

namespace verilog {

template <typename T>
class Verilog2001Visitor;

class Verilog2001Parser : public Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, T__51 = 52, T__52 = 53, T__53 = 54, T__54 = 55, T__55 = 56, 
    T__56 = 57, T__57 = 58, T__58 = 59, T__59 = 60, T__60 = 61, T__61 = 62, 
    T__62 = 63, T__63 = 64, T__64 = 65, T__65 = 66, T__66 = 67, T__67 = 68, 
    T__68 = 69, T__69 = 70, T__70 = 71, T__71 = 72, T__72 = 73, T__73 = 74, 
    T__74 = 75, T__75 = 76, T__76 = 77, T__77 = 78, T__78 = 79, T__79 = 80, 
    T__80 = 81, T__81 = 82, T__82 = 83, T__83 = 84, T__84 = 85, T__85 = 86, 
    T__86 = 87, T__87 = 88, T__88 = 89, T__89 = 90, T__90 = 91, T__91 = 92, 
    T__92 = 93, T__93 = 94, T__94 = 95, T__95 = 96, T__96 = 97, T__97 = 98, 
    T__98 = 99, T__99 = 100, T__100 = 101, T__101 = 102, T__102 = 103, T__103 = 104, 
    T__104 = 105, T__105 = 106, T__106 = 107, T__107 = 108, T__108 = 109, 
    T__109 = 110, T__110 = 111, T__111 = 112, T__112 = 113, T__113 = 114, 
    T__114 = 115, T__115 = 116, T__116 = 117, T__117 = 118, T__118 = 119, 
    T__119 = 120, T__120 = 121, T__121 = 122, T__122 = 123, T__123 = 124, 
    T__124 = 125, T__125 = 126, T__126 = 127, T__127 = 128, T__128 = 129, 
    T__129 = 130, T__130 = 131, T__131 = 132, T__132 = 133, T__133 = 134, 
    T__134 = 135, T__135 = 136, T__136 = 137, T__137 = 138, T__138 = 139, 
    T__139 = 140, T__140 = 141, T__141 = 142, T__142 = 143, T__143 = 144, 
    T__144 = 145, T__145 = 146, T__146 = 147, T__147 = 148, T__148 = 149, 
    T__149 = 150, T__150 = 151, T__151 = 152, T__152 = 153, T__153 = 154, 
    T__154 = 155, T__155 = 156, T__156 = 157, T__157 = 158, T__158 = 159, 
    T__159 = 160, T__160 = 161, T__161 = 162, T__162 = 163, T__163 = 164, 
    T__164 = 165, T__165 = 166, T__166 = 167, Real_number = 168, Decimal_number = 169, 
    Binary_number = 170, Octal_number = 171, Hex_number = 172, String = 173, 
    One_line_comment = 174, Block_comment = 175, Escaped_identifier = 176, 
    Simple_identifier = 177, Dollar_Identifier = 178, Time_Identifier = 179, 
    White_space = 180
  };

  enum {
    RuleConfig_declaration = 0, RuleDesign_statement = 1, RuleConfig_rule_statement = 2, 
    RuleDefault_clause = 3, RuleInst_clause = 4, RuleInst_name = 5, RuleLiblist_clause = 6, 
    RuleCell_clause = 7, RuleUse_clause = 8, RuleSource_text = 9, RuleDescription = 10, 
    RuleModule_declaration = 11, RuleModule_keyword = 12, RuleModule_parameter_port_list = 13, 
    RuleList_of_ports = 14, RuleList_of_port_declarations = 15, RulePort = 16, 
    RulePort_expression = 17, RulePort_reference = 18, RulePort_declaration = 19, 
    RuleModule_item = 20, RuleModule_or_generate_item = 21, RuleNon_port_module_item = 22, 
    RuleModule_or_generate_item_declaration = 23, RuleParameter_override = 24, 
    RuleLocal_parameter_declaration = 25, RuleParameter_declaration = 26, 
    RuleParameter_declaration_ = 27, RuleSpecparam_declaration = 28, RuleInout_declaration = 29, 
    RuleInput_declaration = 30, RuleOutput_declaration = 31, RuleEvent_declaration = 32, 
    RuleGenvar_declaration = 33, RuleInteger_declaration = 34, RuleTime_declaration = 35, 
    RuleReal_declaration = 36, RuleRealtime_declaration = 37, RuleReg_declaration = 38, 
    RuleNet_declaration = 39, RuleNet_type = 40, RuleOutput_variable_type = 41, 
    RuleReal_type = 42, RuleVariable_type = 43, RuleDrive_strength = 44, 
    RuleStrength0 = 45, RuleStrength1 = 46, RuleCharge_strength = 47, RuleDelay3 = 48, 
    RuleDelay2 = 49, RuleDelay_value = 50, RuleList_of_event_identifiers = 51, 
    RuleList_of_net_identifiers = 52, RuleList_of_genvar_identifiers = 53, 
    RuleList_of_port_identifiers = 54, RuleList_of_net_decl_assignments = 55, 
    RuleList_of_param_assignments = 56, RuleList_of_specparam_assignments = 57, 
    RuleList_of_real_identifiers = 58, RuleList_of_variable_identifiers = 59, 
    RuleList_of_variable_port_identifiers = 60, RuleNet_decl_assignment = 61, 
    RuleParam_assignment = 62, RuleSpecparam_assignment = 63, RulePulse_control_specparam = 64, 
    RuleError_limit_value = 65, RuleReject_limit_value = 66, RuleLimit_value = 67, 
    RuleDimension = 68, RuleRange = 69, RuleFunction_declaration = 70, RuleFunction_item_declaration = 71, 
    RuleFunction_port_list = 72, RuleFunction_port = 73, RuleRange_or_type = 74, 
    RuleTask_declaration = 75, RuleTask_item_declaration = 76, RuleTask_port_list = 77, 
    RuleTask_port_item = 78, RuleTf_decl_header = 79, RuleTf_declaration = 80, 
    RuleTask_port_type = 81, RuleBlock_item_declaration = 82, RuleBlock_reg_declaration = 83, 
    RuleList_of_block_variable_identifiers = 84, RuleBlock_variable_type = 85, 
    RuleGate_instantiation = 86, RuleCmos_switch_instance = 87, RuleEnable_gate_instance = 88, 
    RuleMos_switch_instance = 89, RuleN_input_gate_instance = 90, RuleN_output_gate_instance = 91, 
    RulePass_switch_instance = 92, RulePass_enable_switch_instance = 93, 
    RulePull_gate_instance = 94, RuleName_of_gate_instance = 95, RulePulldown_strength = 96, 
    RulePullup_strength = 97, RuleEnable_terminal = 98, RuleNcontrol_terminal = 99, 
    RulePcontrol_terminal = 100, RuleInput_terminal = 101, RuleInout_terminal = 102, 
    RuleOutput_terminal = 103, RuleCmos_switchtype = 104, RuleEnable_gatetype = 105, 
    RuleMos_switchtype = 106, RuleN_input_gatetype = 107, RuleN_output_gatetype = 108, 
    RulePass_en_switchtype = 109, RulePass_switchtype = 110, RuleModule_instantiation = 111, 
    RuleParameter_value_assignment = 112, RuleList_of_parameter_assignments = 113, 
    RuleOrdered_parameter_assignment = 114, RuleNamed_parameter_assignment = 115, 
    RuleModule_instance = 116, RuleName_of_instance = 117, RuleList_of_port_connections = 118, 
    RuleOrdered_port_connection = 119, RuleNamed_port_connection = 120, 
    RuleGenerated_instantiation = 121, RuleGenerate_item_or_null = 122, 
    RuleGenerate_item = 123, RuleGenerate_conditional_statement = 124, RuleGenerate_case_statement = 125, 
    RuleGenvar_case_item = 126, RuleGenerate_loop_statement = 127, RuleGenvar_assignment = 128, 
    RuleGenerate_block = 129, RuleContinuous_assign = 130, RuleList_of_net_assignments = 131, 
    RuleNet_assignment = 132, RuleInitial_construct = 133, RuleAlways_construct = 134, 
    RuleBlocking_assignment = 135, RuleNonblocking_assignment = 136, RuleProcedural_continuous_assignments = 137, 
    RuleFunction_blocking_assignment = 138, RuleFunction_statement_or_null = 139, 
    RuleFunction_seq_block = 140, RuleVariable_assignment = 141, RulePar_block = 142, 
    RuleSeq_block = 143, RuleStatement = 144, RuleStatement_or_null = 145, 
    RuleFunction_statement = 146, RuleDelay_or_event_control = 147, RuleDelay_control = 148, 
    RuleDisable_statement = 149, RuleEvent_control = 150, RuleEvent_trigger = 151, 
    RuleEvent_expression = 152, RuleEvent_primary = 153, RuleProcedural_timing_control_statement = 154, 
    RuleWait_statement = 155, RuleConditional_statement = 156, RuleIf_else_if_statement = 157, 
    RuleFunction_conditional_statement = 158, RuleFunction_if_else_if_statement = 159, 
    RuleCase_statement = 160, RuleCase_item = 161, RuleFunction_case_statement = 162, 
    RuleFunction_case_item = 163, RuleFunction_loop_statement = 164, RuleLoop_statement = 165, 
    RuleSystem_task_enable = 166, RuleTask_enable = 167, RuleSpecify_block = 168, 
    RuleSpecify_item = 169, RulePulsestyle_declaration = 170, RuleShowcancelled_declaration = 171, 
    RulePath_declaration = 172, RuleSimple_path_declaration = 173, RuleParallel_path_description = 174, 
    RuleFull_path_description = 175, RuleList_of_path_inputs = 176, RuleList_of_path_outputs = 177, 
    RuleSpecify_input_terminal_descriptor = 178, RuleSpecify_output_terminal_descriptor = 179, 
    RuleInput_identifier = 180, RuleOutput_identifier = 181, RulePath_delay_value = 182, 
    RuleList_of_path_delay_expressions = 183, RuleT_path_delay_expression = 184, 
    RuleTrise_path_delay_expression = 185, RuleTfall_path_delay_expression = 186, 
    RuleTz_path_delay_expression = 187, RuleT01_path_delay_expression = 188, 
    RuleT10_path_delay_expression = 189, RuleT0z_path_delay_expression = 190, 
    RuleTz1_path_delay_expression = 191, RuleT1z_path_delay_expression = 192, 
    RuleTz0_path_delay_expression = 193, RuleT0x_path_delay_expression = 194, 
    RuleTx1_path_delay_expression = 195, RuleT1x_path_delay_expression = 196, 
    RuleTx0_path_delay_expression = 197, RuleTxz_path_delay_expression = 198, 
    RuleTzx_path_delay_expression = 199, RulePath_delay_expression = 200, 
    RuleEdge_sensitive_path_declaration = 201, RuleParallel_edge_sensitive_path_description = 202, 
    RuleFull_edge_sensitive_path_description = 203, RuleData_source_expression = 204, 
    RuleEdge_identifier = 205, RuleState_dependent_path_declaration = 206, 
    RulePolarity_operator = 207, RuleChecktime_condition = 208, RuleDelayed_data = 209, 
    RuleDelayed_reference = 210, RuleEnd_edge_offset = 211, RuleEvent_based_flag = 212, 
    RuleNotify_reg = 213, RuleRemain_active_flag = 214, RuleStamptime_condition = 215, 
    RuleStart_edge_offset = 216, RuleThreshold = 217, RuleTiming_check_limit = 218, 
    RuleConcatenation = 219, RuleConstant_concatenation = 220, RuleConstant_multiple_concatenation = 221, 
    RuleModule_path_concatenation = 222, RuleModule_path_multiple_concatenation = 223, 
    RuleMultiple_concatenation = 224, RuleNet_concatenation = 225, RuleNet_concatenation_value = 226, 
    RuleVariable_concatenation = 227, RuleVariable_concatenation_value = 228, 
    RuleConstant_function_call = 229, RuleFunction_call = 230, RuleSystem_function_call = 231, 
    RuleGenvar_function_call = 232, RuleBase_expression = 233, RuleConstant_base_expression = 234, 
    RuleConstant_expression = 235, RuleConstant_mintypmax_expression = 236, 
    RuleConstant_range_expression = 237, RuleDimension_constant_expression = 238, 
    RuleExpression = 239, RuleTerm = 240, RuleLsb_constant_expression = 241, 
    RuleMintypmax_expression = 242, RuleModule_path_conditional_expression = 243, 
    RuleModule_path_expression = 244, RuleModule_path_mintypmax_expression = 245, 
    RuleMsb_constant_expression = 246, RuleRange_expression = 247, RuleWidth_constant_expression = 248, 
    RuleConstant_primary = 249, RuleModule_path_primary = 250, RulePrimary = 251, 
    RuleNet_lvalue = 252, RuleVariable_lvalue = 253, RuleUnary_operator = 254, 
    RuleBinary_operator = 255, RuleUnary_module_path_operator = 256, RuleBinary_module_path_operator = 257, 
    RuleNumber = 258, RuleDefault_nettype_spec = 259, RuleTiming_spec = 260, 
    RuleAttribute_instance = 261, RuleAttr_spec = 262, RuleAttr_name = 263, 
    RuleArrayed_identifier = 264, RuleBlock_identifier = 265, RuleCell_identifier = 266, 
    RuleConfig_identifier = 267, RuleEscaped_arrayed_identifier = 268, RuleEscaped_hierarchical_identifier = 269, 
    RuleEvent_identifier = 270, RuleFunction_identifier = 271, RuleGate_instance_identifier = 272, 
    RuleGenerate_block_identifier = 273, RuleGenvar_function_identifier = 274, 
    RuleGenvar_identifier = 275, RuleHierarchical_block_identifier = 276, 
    RuleHierarchical_event_identifier = 277, RuleHierarchical_function_identifier = 278, 
    RuleHierarchical_identifier = 279, RuleHierarchical_net_identifier = 280, 
    RuleHierarchical_variable_identifier = 281, RuleHierarchical_task_identifier = 282, 
    RuleIdentifier = 283, RuleInout_port_identifier = 284, RuleInput_port_identifier = 285, 
    RuleInstance_identifier = 286, RuleLibrary_identifier = 287, RuleMemory_identifier = 288, 
    RuleModule_identifier = 289, RuleModule_instance_identifier = 290, RuleNet_identifier = 291, 
    RuleOutput_port_identifier = 292, RuleParameter_identifier = 293, RulePort_identifier = 294, 
    RuleReal_identifier = 295, RuleSimple_arrayed_identifier = 296, RuleSimple_hierarchical_identifier = 297, 
    RuleSpecparam_identifier = 298, RuleSystem_function_identifier = 299, 
    RuleSystem_task_identifier = 300, RuleTask_identifier = 301, RuleTerminal_identifier = 302, 
    RuleText_macro_identifier = 303, RuleTopmodule_identifier = 304, RuleUdp_identifier = 305, 
    RuleUdp_instance_identifier = 306, RuleVariable_identifier = 307, RuleSimple_hierarchical_branch = 308, 
    RuleEscaped_hierarchical_branch = 309
  };

  Verilog2001Parser(TokenStream *input);
  ~Verilog2001Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual dfa::Vocabulary& getVocabulary() const override;


  class Config_declarationContext;
  class Design_statementContext;
  class Config_rule_statementContext;
  class Default_clauseContext;
  class Inst_clauseContext;
  class Inst_nameContext;
  class Liblist_clauseContext;
  class Cell_clauseContext;
  class Use_clauseContext;
  class Source_textContext;
  class DescriptionContext;
  class Module_declarationContext;
  class Module_keywordContext;
  class Module_parameter_port_listContext;
  class List_of_portsContext;
  class List_of_port_declarationsContext;
  class PortContext;
  class Port_expressionContext;
  class Port_referenceContext;
  class Port_declarationContext;
  class Module_itemContext;
  class Module_or_generate_itemContext;
  class Non_port_module_itemContext;
  class Module_or_generate_item_declarationContext;
  class Parameter_overrideContext;
  class Local_parameter_declarationContext;
  class Parameter_declarationContext;
  class Parameter_declaration_Context;
  class Specparam_declarationContext;
  class Inout_declarationContext;
  class Input_declarationContext;
  class Output_declarationContext;
  class Event_declarationContext;
  class Genvar_declarationContext;
  class Integer_declarationContext;
  class Time_declarationContext;
  class Real_declarationContext;
  class Realtime_declarationContext;
  class Reg_declarationContext;
  class Net_declarationContext;
  class Net_typeContext;
  class Output_variable_typeContext;
  class Real_typeContext;
  class Variable_typeContext;
  class Drive_strengthContext;
  class Strength0Context;
  class Strength1Context;
  class Charge_strengthContext;
  class Delay3Context;
  class Delay2Context;
  class Delay_valueContext;
  class List_of_event_identifiersContext;
  class List_of_net_identifiersContext;
  class List_of_genvar_identifiersContext;
  class List_of_port_identifiersContext;
  class List_of_net_decl_assignmentsContext;
  class List_of_param_assignmentsContext;
  class List_of_specparam_assignmentsContext;
  class List_of_real_identifiersContext;
  class List_of_variable_identifiersContext;
  class List_of_variable_port_identifiersContext;
  class Net_decl_assignmentContext;
  class Param_assignmentContext;
  class Specparam_assignmentContext;
  class Pulse_control_specparamContext;
  class Error_limit_valueContext;
  class Reject_limit_valueContext;
  class Limit_valueContext;
  class DimensionContext;
  class RangeContext;
  class Function_declarationContext;
  class Function_item_declarationContext;
  class Function_port_listContext;
  class Function_portContext;
  class Range_or_typeContext;
  class Task_declarationContext;
  class Task_item_declarationContext;
  class Task_port_listContext;
  class Task_port_itemContext;
  class Tf_decl_headerContext;
  class Tf_declarationContext;
  class Task_port_typeContext;
  class Block_item_declarationContext;
  class Block_reg_declarationContext;
  class List_of_block_variable_identifiersContext;
  class Block_variable_typeContext;
  class Gate_instantiationContext;
  class Cmos_switch_instanceContext;
  class Enable_gate_instanceContext;
  class Mos_switch_instanceContext;
  class N_input_gate_instanceContext;
  class N_output_gate_instanceContext;
  class Pass_switch_instanceContext;
  class Pass_enable_switch_instanceContext;
  class Pull_gate_instanceContext;
  class Name_of_gate_instanceContext;
  class Pulldown_strengthContext;
  class Pullup_strengthContext;
  class Enable_terminalContext;
  class Ncontrol_terminalContext;
  class Pcontrol_terminalContext;
  class Input_terminalContext;
  class Inout_terminalContext;
  class Output_terminalContext;
  class Cmos_switchtypeContext;
  class Enable_gatetypeContext;
  class Mos_switchtypeContext;
  class N_input_gatetypeContext;
  class N_output_gatetypeContext;
  class Pass_en_switchtypeContext;
  class Pass_switchtypeContext;
  class Module_instantiationContext;
  class Parameter_value_assignmentContext;
  class List_of_parameter_assignmentsContext;
  class Ordered_parameter_assignmentContext;
  class Named_parameter_assignmentContext;
  class Module_instanceContext;
  class Name_of_instanceContext;
  class List_of_port_connectionsContext;
  class Ordered_port_connectionContext;
  class Named_port_connectionContext;
  class Generated_instantiationContext;
  class Generate_item_or_nullContext;
  class Generate_itemContext;
  class Generate_conditional_statementContext;
  class Generate_case_statementContext;
  class Genvar_case_itemContext;
  class Generate_loop_statementContext;
  class Genvar_assignmentContext;
  class Generate_blockContext;
  class Continuous_assignContext;
  class List_of_net_assignmentsContext;
  class Net_assignmentContext;
  class Initial_constructContext;
  class Always_constructContext;
  class Blocking_assignmentContext;
  class Nonblocking_assignmentContext;
  class Procedural_continuous_assignmentsContext;
  class Function_blocking_assignmentContext;
  class Function_statement_or_nullContext;
  class Function_seq_blockContext;
  class Variable_assignmentContext;
  class Par_blockContext;
  class Seq_blockContext;
  class StatementContext;
  class Statement_or_nullContext;
  class Function_statementContext;
  class Delay_or_event_controlContext;
  class Delay_controlContext;
  class Disable_statementContext;
  class Event_controlContext;
  class Event_triggerContext;
  class Event_expressionContext;
  class Event_primaryContext;
  class Procedural_timing_control_statementContext;
  class Wait_statementContext;
  class Conditional_statementContext;
  class If_else_if_statementContext;
  class Function_conditional_statementContext;
  class Function_if_else_if_statementContext;
  class Case_statementContext;
  class Case_itemContext;
  class Function_case_statementContext;
  class Function_case_itemContext;
  class Function_loop_statementContext;
  class Loop_statementContext;
  class System_task_enableContext;
  class Task_enableContext;
  class Specify_blockContext;
  class Specify_itemContext;
  class Pulsestyle_declarationContext;
  class Showcancelled_declarationContext;
  class Path_declarationContext;
  class Simple_path_declarationContext;
  class Parallel_path_descriptionContext;
  class Full_path_descriptionContext;
  class List_of_path_inputsContext;
  class List_of_path_outputsContext;
  class Specify_input_terminal_descriptorContext;
  class Specify_output_terminal_descriptorContext;
  class Input_identifierContext;
  class Output_identifierContext;
  class Path_delay_valueContext;
  class List_of_path_delay_expressionsContext;
  class T_path_delay_expressionContext;
  class Trise_path_delay_expressionContext;
  class Tfall_path_delay_expressionContext;
  class Tz_path_delay_expressionContext;
  class T01_path_delay_expressionContext;
  class T10_path_delay_expressionContext;
  class T0z_path_delay_expressionContext;
  class Tz1_path_delay_expressionContext;
  class T1z_path_delay_expressionContext;
  class Tz0_path_delay_expressionContext;
  class T0x_path_delay_expressionContext;
  class Tx1_path_delay_expressionContext;
  class T1x_path_delay_expressionContext;
  class Tx0_path_delay_expressionContext;
  class Txz_path_delay_expressionContext;
  class Tzx_path_delay_expressionContext;
  class Path_delay_expressionContext;
  class Edge_sensitive_path_declarationContext;
  class Parallel_edge_sensitive_path_descriptionContext;
  class Full_edge_sensitive_path_descriptionContext;
  class Data_source_expressionContext;
  class Edge_identifierContext;
  class State_dependent_path_declarationContext;
  class Polarity_operatorContext;
  class Checktime_conditionContext;
  class Delayed_dataContext;
  class Delayed_referenceContext;
  class End_edge_offsetContext;
  class Event_based_flagContext;
  class Notify_regContext;
  class Remain_active_flagContext;
  class Stamptime_conditionContext;
  class Start_edge_offsetContext;
  class ThresholdContext;
  class Timing_check_limitContext;
  class ConcatenationContext;
  class Constant_concatenationContext;
  class Constant_multiple_concatenationContext;
  class Module_path_concatenationContext;
  class Module_path_multiple_concatenationContext;
  class Multiple_concatenationContext;
  class Net_concatenationContext;
  class Net_concatenation_valueContext;
  class Variable_concatenationContext;
  class Variable_concatenation_valueContext;
  class Constant_function_callContext;
  class Function_callContext;
  class System_function_callContext;
  class Genvar_function_callContext;
  class Base_expressionContext;
  class Constant_base_expressionContext;
  class Constant_expressionContext;
  class Constant_mintypmax_expressionContext;
  class Constant_range_expressionContext;
  class Dimension_constant_expressionContext;
  class ExpressionContext;
  class TermContext;
  class Lsb_constant_expressionContext;
  class Mintypmax_expressionContext;
  class Module_path_conditional_expressionContext;
  class Module_path_expressionContext;
  class Module_path_mintypmax_expressionContext;
  class Msb_constant_expressionContext;
  class Range_expressionContext;
  class Width_constant_expressionContext;
  class Constant_primaryContext;
  class Module_path_primaryContext;
  class PrimaryContext;
  class Net_lvalueContext;
  class Variable_lvalueContext;
  class Unary_operatorContext;
  class Binary_operatorContext;
  class Unary_module_path_operatorContext;
  class Binary_module_path_operatorContext;
  class NumberContext;
  class Default_nettype_specContext;
  class Timing_specContext;
  class Attribute_instanceContext;
  class Attr_specContext;
  class Attr_nameContext;
  class Arrayed_identifierContext;
  class Block_identifierContext;
  class Cell_identifierContext;
  class Config_identifierContext;
  class Escaped_arrayed_identifierContext;
  class Escaped_hierarchical_identifierContext;
  class Event_identifierContext;
  class Function_identifierContext;
  class Gate_instance_identifierContext;
  class Generate_block_identifierContext;
  class Genvar_function_identifierContext;
  class Genvar_identifierContext;
  class Hierarchical_block_identifierContext;
  class Hierarchical_event_identifierContext;
  class Hierarchical_function_identifierContext;
  class Hierarchical_identifierContext;
  class Hierarchical_net_identifierContext;
  class Hierarchical_variable_identifierContext;
  class Hierarchical_task_identifierContext;
  class IdentifierContext;
  class Inout_port_identifierContext;
  class Input_port_identifierContext;
  class Instance_identifierContext;
  class Library_identifierContext;
  class Memory_identifierContext;
  class Module_identifierContext;
  class Module_instance_identifierContext;
  class Net_identifierContext;
  class Output_port_identifierContext;
  class Parameter_identifierContext;
  class Port_identifierContext;
  class Real_identifierContext;
  class Simple_arrayed_identifierContext;
  class Simple_hierarchical_identifierContext;
  class Specparam_identifierContext;
  class System_function_identifierContext;
  class System_task_identifierContext;
  class Task_identifierContext;
  class Terminal_identifierContext;
  class Text_macro_identifierContext;
  class Topmodule_identifierContext;
  class Udp_identifierContext;
  class Udp_instance_identifierContext;
  class Variable_identifierContext;
  class Simple_hierarchical_branchContext;
  class Escaped_hierarchical_branchContext; 

  class Config_declarationContext : public ParserRuleContext {
  public:
    Config_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Config_identifierContext> config_identifier();
    Ref<Design_statementContext> design_statement();
    std::vector<Ref<Config_rule_statementContext>> config_rule_statement();
    Ref<Config_rule_statementContext> config_rule_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConfig_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Config_declarationContext> config_declaration();

  class Design_statementContext : public ParserRuleContext {
  public:
    Design_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Cell_identifierContext>> cell_identifier();
    Ref<Cell_identifierContext> cell_identifier(int i);
    std::vector<Ref<Library_identifierContext>> library_identifier();
    Ref<Library_identifierContext> library_identifier(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDesign_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Design_statementContext> design_statement();

  class Config_rule_statementContext : public ParserRuleContext {
  public:
    Config_rule_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Default_clauseContext> default_clause();
    Ref<Liblist_clauseContext> liblist_clause();
    Ref<Inst_clauseContext> inst_clause();
    Ref<Use_clauseContext> use_clause();
    Ref<Cell_clauseContext> cell_clause();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConfig_rule_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Config_rule_statementContext> config_rule_statement();

  class Default_clauseContext : public ParserRuleContext {
  public:
    Default_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDefault_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Default_clauseContext> default_clause();

  class Inst_clauseContext : public ParserRuleContext {
  public:
    Inst_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Inst_nameContext> inst_name();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInst_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Inst_clauseContext> inst_clause();

  class Inst_nameContext : public ParserRuleContext {
  public:
    Inst_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Topmodule_identifierContext> topmodule_identifier();
    std::vector<Ref<Instance_identifierContext>> instance_identifier();
    Ref<Instance_identifierContext> instance_identifier(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInst_name(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Inst_nameContext> inst_name();

  class Liblist_clauseContext : public ParserRuleContext {
  public:
    Liblist_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Library_identifierContext>> library_identifier();
    Ref<Library_identifierContext> library_identifier(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitLiblist_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Liblist_clauseContext> liblist_clause();

  class Cell_clauseContext : public ParserRuleContext {
  public:
    Cell_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cell_identifierContext> cell_identifier();
    Ref<Library_identifierContext> library_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitCell_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Cell_clauseContext> cell_clause();

  class Use_clauseContext : public ParserRuleContext {
  public:
    Use_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cell_identifierContext> cell_identifier();
    Ref<Library_identifierContext> library_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitUse_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Use_clauseContext> use_clause();

  class Source_textContext : public ParserRuleContext {
  public:
    Source_textContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> EOF();
    Ref<Timing_specContext> timing_spec();
    std::vector<Ref<Default_nettype_specContext>> default_nettype_spec();
    Ref<Default_nettype_specContext> default_nettype_spec(int i);
    std::vector<Ref<DescriptionContext>> description();
    Ref<DescriptionContext> description(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSource_text(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Source_textContext> source_text();

  class DescriptionContext : public ParserRuleContext {
  public:
    DescriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_declarationContext> module_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDescription(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<DescriptionContext> description();

  class Module_declarationContext : public ParserRuleContext {
  public:
    Module_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_keywordContext> module_keyword();
    Ref<Module_identifierContext> module_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Module_parameter_port_listContext> module_parameter_port_list();
    Ref<List_of_portsContext> list_of_ports();
    std::vector<Ref<Module_itemContext>> module_item();
    Ref<Module_itemContext> module_item(int i);
    Ref<List_of_port_declarationsContext> list_of_port_declarations();
    std::vector<Ref<Non_port_module_itemContext>> non_port_module_item();
    Ref<Non_port_module_itemContext> non_port_module_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_declarationContext> module_declaration();

  class Module_keywordContext : public ParserRuleContext {
  public:
    Module_keywordContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_keyword(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_keywordContext> module_keyword();

  class Module_parameter_port_listContext : public ParserRuleContext {
  public:
    Module_parameter_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Parameter_declaration_Context>> parameter_declaration_();
    Ref<Parameter_declaration_Context> parameter_declaration_(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_parameter_port_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_parameter_port_listContext> module_parameter_port_list();

  class List_of_portsContext : public ParserRuleContext {
  public:
    List_of_portsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<PortContext>> port();
    Ref<PortContext> port(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_ports(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_portsContext> list_of_ports();

  class List_of_port_declarationsContext : public ParserRuleContext {
  public:
    List_of_port_declarationsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_declarationContext>> port_declaration();
    Ref<Port_declarationContext> port_declaration(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_port_declarations(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_port_declarationsContext> list_of_port_declarations();

  class PortContext : public ParserRuleContext {
  public:
    PortContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_expressionContext> port_expression();
    Ref<Port_identifierContext> port_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPort(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<PortContext> port();

  class Port_expressionContext : public ParserRuleContext {
  public:
    Port_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_referenceContext>> port_reference();
    Ref<Port_referenceContext> port_reference(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPort_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Port_expressionContext> port_expression();

  class Port_referenceContext : public ParserRuleContext {
  public:
    Port_referenceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_identifierContext> port_identifier();
    Ref<Constant_expressionContext> constant_expression();
    Ref<Range_expressionContext> range_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPort_reference(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Port_referenceContext> port_reference();

  class Port_declarationContext : public ParserRuleContext {
  public:
    Port_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Inout_declarationContext> inout_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Input_declarationContext> input_declaration();
    Ref<Output_declarationContext> output_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPort_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Port_declarationContext> port_declaration();

  class Module_itemContext : public ParserRuleContext {
  public:
    Module_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_or_generate_itemContext> module_or_generate_item();
    Ref<Port_declarationContext> port_declaration();
    Ref<Generated_instantiationContext> generated_instantiation();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Local_parameter_declarationContext> local_parameter_declaration();
    Ref<Parameter_declarationContext> parameter_declaration();
    Ref<Specify_blockContext> specify_block();
    Ref<Specparam_declarationContext> specparam_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_itemContext> module_item();

  class Module_or_generate_itemContext : public ParserRuleContext {
  public:
    Module_or_generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_or_generate_item_declarationContext> module_or_generate_item_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Parameter_overrideContext> parameter_override();
    Ref<Continuous_assignContext> continuous_assign();
    Ref<Gate_instantiationContext> gate_instantiation();
    Ref<Module_instantiationContext> module_instantiation();
    Ref<Initial_constructContext> initial_construct();
    Ref<Always_constructContext> always_construct();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_or_generate_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_or_generate_itemContext> module_or_generate_item();

  class Non_port_module_itemContext : public ParserRuleContext {
  public:
    Non_port_module_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Generated_instantiationContext> generated_instantiation();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Local_parameter_declarationContext> local_parameter_declaration();
    Ref<Module_or_generate_itemContext> module_or_generate_item();
    Ref<Parameter_declarationContext> parameter_declaration();
    Ref<Specify_blockContext> specify_block();
    Ref<Specparam_declarationContext> specparam_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNon_port_module_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Non_port_module_itemContext> non_port_module_item();

  class Module_or_generate_item_declarationContext : public ParserRuleContext {
  public:
    Module_or_generate_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_declarationContext> net_declaration();
    Ref<Reg_declarationContext> reg_declaration();
    Ref<Integer_declarationContext> integer_declaration();
    Ref<Real_declarationContext> real_declaration();
    Ref<Time_declarationContext> time_declaration();
    Ref<Realtime_declarationContext> realtime_declaration();
    Ref<Event_declarationContext> event_declaration();
    Ref<Genvar_declarationContext> genvar_declaration();
    Ref<Task_declarationContext> task_declaration();
    Ref<Function_declarationContext> function_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_or_generate_item_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_or_generate_item_declarationContext> module_or_generate_item_declaration();

  class Parameter_overrideContext : public ParserRuleContext {
  public:
    Parameter_overrideContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_param_assignmentsContext> list_of_param_assignments();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitParameter_override(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Parameter_overrideContext> parameter_override();

  class Local_parameter_declarationContext : public ParserRuleContext {
  public:
    Local_parameter_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_param_assignmentsContext> list_of_param_assignments();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitLocal_parameter_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Local_parameter_declarationContext> local_parameter_declaration();

  class Parameter_declarationContext : public ParserRuleContext {
  public:
    Parameter_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parameter_declaration_Context> parameter_declaration_();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitParameter_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Parameter_declarationContext> parameter_declaration();

  class Parameter_declaration_Context : public ParserRuleContext {
  public:
    Parameter_declaration_Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_param_assignmentsContext> list_of_param_assignments();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitParameter_declaration_(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Parameter_declaration_Context> parameter_declaration_();

  class Specparam_declarationContext : public ParserRuleContext {
  public:
    Specparam_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_specparam_assignmentsContext> list_of_specparam_assignments();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSpecparam_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Specparam_declarationContext> specparam_declaration();

  class Inout_declarationContext : public ParserRuleContext {
  public:
    Inout_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_port_identifiersContext> list_of_port_identifiers();
    Ref<Net_typeContext> net_type();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInout_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Inout_declarationContext> inout_declaration();

  class Input_declarationContext : public ParserRuleContext {
  public:
    Input_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_port_identifiersContext> list_of_port_identifiers();
    Ref<Net_typeContext> net_type();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInput_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Input_declarationContext> input_declaration();

  class Output_declarationContext : public ParserRuleContext {
  public:
    Output_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_port_identifiersContext> list_of_port_identifiers();
    Ref<Net_typeContext> net_type();
    Ref<RangeContext> range();
    Ref<List_of_variable_port_identifiersContext> list_of_variable_port_identifiers();
    Ref<Output_variable_typeContext> output_variable_type();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitOutput_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Output_declarationContext> output_declaration();

  class Event_declarationContext : public ParserRuleContext {
  public:
    Event_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_event_identifiersContext> list_of_event_identifiers();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEvent_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Event_declarationContext> event_declaration();

  class Genvar_declarationContext : public ParserRuleContext {
  public:
    Genvar_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_genvar_identifiersContext> list_of_genvar_identifiers();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenvar_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Genvar_declarationContext> genvar_declaration();

  class Integer_declarationContext : public ParserRuleContext {
  public:
    Integer_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_variable_identifiersContext> list_of_variable_identifiers();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInteger_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Integer_declarationContext> integer_declaration();

  class Time_declarationContext : public ParserRuleContext {
  public:
    Time_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_variable_identifiersContext> list_of_variable_identifiers();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTime_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Time_declarationContext> time_declaration();

  class Real_declarationContext : public ParserRuleContext {
  public:
    Real_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_real_identifiersContext> list_of_real_identifiers();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitReal_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Real_declarationContext> real_declaration();

  class Realtime_declarationContext : public ParserRuleContext {
  public:
    Realtime_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_real_identifiersContext> list_of_real_identifiers();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitRealtime_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Realtime_declarationContext> realtime_declaration();

  class Reg_declarationContext : public ParserRuleContext {
  public:
    Reg_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_variable_identifiersContext> list_of_variable_identifiers();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitReg_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Reg_declarationContext> reg_declaration();

  class Net_declarationContext : public ParserRuleContext {
  public:
    Net_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_typeContext> net_type();
    Ref<List_of_net_identifiersContext> list_of_net_identifiers();
    Ref<Delay3Context> delay3();
    Ref<List_of_net_decl_assignmentsContext> list_of_net_decl_assignments();
    Ref<Drive_strengthContext> drive_strength();
    Ref<Charge_strengthContext> charge_strength();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNet_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Net_declarationContext> net_declaration();

  class Net_typeContext : public ParserRuleContext {
  public:
    Net_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNet_type(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Net_typeContext> net_type();

  class Output_variable_typeContext : public ParserRuleContext {
  public:
    Output_variable_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitOutput_variable_type(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Output_variable_typeContext> output_variable_type();

  class Real_typeContext : public ParserRuleContext {
  public:
    Real_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Real_identifierContext> real_identifier();
    Ref<Constant_expressionContext> constant_expression();
    std::vector<Ref<DimensionContext>> dimension();
    Ref<DimensionContext> dimension(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitReal_type(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Real_typeContext> real_type();

  class Variable_typeContext : public ParserRuleContext {
  public:
    Variable_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();
    Ref<Constant_expressionContext> constant_expression();
    std::vector<Ref<DimensionContext>> dimension();
    Ref<DimensionContext> dimension(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitVariable_type(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Variable_typeContext> variable_type();

  class Drive_strengthContext : public ParserRuleContext {
  public:
    Drive_strengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Strength0Context> strength0();
    Ref<Strength1Context> strength1();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDrive_strength(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Drive_strengthContext> drive_strength();

  class Strength0Context : public ParserRuleContext {
  public:
    Strength0Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitStrength0(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Strength0Context> strength0();

  class Strength1Context : public ParserRuleContext {
  public:
    Strength1Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitStrength1(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Strength1Context> strength1();

  class Charge_strengthContext : public ParserRuleContext {
  public:
    Charge_strengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitCharge_strength(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Charge_strengthContext> charge_strength();

  class Delay3Context : public ParserRuleContext {
  public:
    Delay3Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Delay_valueContext>> delay_value();
    Ref<Delay_valueContext> delay_value(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDelay3(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Delay3Context> delay3();

  class Delay2Context : public ParserRuleContext {
  public:
    Delay2Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Delay_valueContext>> delay_value();
    Ref<Delay_valueContext> delay_value(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDelay2(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Delay2Context> delay2();

  class Delay_valueContext : public ParserRuleContext {
  public:
    Delay_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Decimal_number();
    Ref<Parameter_identifierContext> parameter_identifier();
    Ref<Specparam_identifierContext> specparam_identifier();
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDelay_value(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Delay_valueContext> delay_value();

  class List_of_event_identifiersContext : public ParserRuleContext {
  public:
    List_of_event_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Event_identifierContext>> event_identifier();
    Ref<Event_identifierContext> event_identifier(int i);
    std::vector<Ref<DimensionContext>> dimension();
    Ref<DimensionContext> dimension(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_event_identifiers(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_event_identifiersContext> list_of_event_identifiers();

  class List_of_net_identifiersContext : public ParserRuleContext {
  public:
    List_of_net_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Net_identifierContext>> net_identifier();
    Ref<Net_identifierContext> net_identifier(int i);
    std::vector<Ref<DimensionContext>> dimension();
    Ref<DimensionContext> dimension(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_net_identifiers(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_net_identifiersContext> list_of_net_identifiers();

  class List_of_genvar_identifiersContext : public ParserRuleContext {
  public:
    List_of_genvar_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Genvar_identifierContext>> genvar_identifier();
    Ref<Genvar_identifierContext> genvar_identifier(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_genvar_identifiers(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_genvar_identifiersContext> list_of_genvar_identifiers();

  class List_of_port_identifiersContext : public ParserRuleContext {
  public:
    List_of_port_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_identifierContext>> port_identifier();
    Ref<Port_identifierContext> port_identifier(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_port_identifiers(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_port_identifiersContext> list_of_port_identifiers();

  class List_of_net_decl_assignmentsContext : public ParserRuleContext {
  public:
    List_of_net_decl_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Net_decl_assignmentContext>> net_decl_assignment();
    Ref<Net_decl_assignmentContext> net_decl_assignment(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_net_decl_assignments(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_net_decl_assignmentsContext> list_of_net_decl_assignments();

  class List_of_param_assignmentsContext : public ParserRuleContext {
  public:
    List_of_param_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Param_assignmentContext>> param_assignment();
    Ref<Param_assignmentContext> param_assignment(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_param_assignments(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_param_assignmentsContext> list_of_param_assignments();

  class List_of_specparam_assignmentsContext : public ParserRuleContext {
  public:
    List_of_specparam_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Specparam_assignmentContext>> specparam_assignment();
    Ref<Specparam_assignmentContext> specparam_assignment(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_specparam_assignments(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_specparam_assignmentsContext> list_of_specparam_assignments();

  class List_of_real_identifiersContext : public ParserRuleContext {
  public:
    List_of_real_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Real_typeContext>> real_type();
    Ref<Real_typeContext> real_type(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_real_identifiers(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_real_identifiersContext> list_of_real_identifiers();

  class List_of_variable_identifiersContext : public ParserRuleContext {
  public:
    List_of_variable_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Variable_typeContext>> variable_type();
    Ref<Variable_typeContext> variable_type(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_variable_identifiers(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_variable_identifiersContext> list_of_variable_identifiers();

  class List_of_variable_port_identifiersContext : public ParserRuleContext {
  public:
    List_of_variable_port_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_identifierContext>> port_identifier();
    Ref<Port_identifierContext> port_identifier(int i);
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_variable_port_identifiers(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_variable_port_identifiersContext> list_of_variable_port_identifiers();

  class Net_decl_assignmentContext : public ParserRuleContext {
  public:
    Net_decl_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_identifierContext> net_identifier();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNet_decl_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Net_decl_assignmentContext> net_decl_assignment();

  class Param_assignmentContext : public ParserRuleContext {
  public:
    Param_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parameter_identifierContext> parameter_identifier();
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitParam_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Param_assignmentContext> param_assignment();

  class Specparam_assignmentContext : public ParserRuleContext {
  public:
    Specparam_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Specparam_identifierContext> specparam_identifier();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();
    Ref<Pulse_control_specparamContext> pulse_control_specparam();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSpecparam_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Specparam_assignmentContext> specparam_assignment();

  class Pulse_control_specparamContext : public ParserRuleContext {
  public:
    Pulse_control_specparamContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reject_limit_valueContext> reject_limit_value();
    Ref<Error_limit_valueContext> error_limit_value();
    Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor();
    Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPulse_control_specparam(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pulse_control_specparamContext> pulse_control_specparam();

  class Error_limit_valueContext : public ParserRuleContext {
  public:
    Error_limit_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Limit_valueContext> limit_value();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitError_limit_value(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Error_limit_valueContext> error_limit_value();

  class Reject_limit_valueContext : public ParserRuleContext {
  public:
    Reject_limit_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Limit_valueContext> limit_value();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitReject_limit_value(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Reject_limit_valueContext> reject_limit_value();

  class Limit_valueContext : public ParserRuleContext {
  public:
    Limit_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitLimit_value(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Limit_valueContext> limit_value();

  class DimensionContext : public ParserRuleContext {
  public:
    DimensionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Dimension_constant_expressionContext>> dimension_constant_expression();
    Ref<Dimension_constant_expressionContext> dimension_constant_expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDimension(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<DimensionContext> dimension();

  class RangeContext : public ParserRuleContext {
  public:
    RangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Msb_constant_expressionContext> msb_constant_expression();
    Ref<Lsb_constant_expressionContext> lsb_constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitRange(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<RangeContext> range();

  class Function_declarationContext : public ParserRuleContext {
  public:
    Function_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_identifierContext> function_identifier();
    Ref<Range_or_typeContext> range_or_type();
    std::vector<Ref<Function_item_declarationContext>> function_item_declaration();
    Ref<Function_item_declarationContext> function_item_declaration(int i);
    Ref<Function_statementContext> function_statement();
    Ref<Function_port_listContext> function_port_list();
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_declarationContext> function_declaration();

  class Function_item_declarationContext : public ParserRuleContext {
  public:
    Function_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_item_declarationContext> block_item_declaration();
    Ref<Tf_declarationContext> tf_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_item_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_item_declarationContext> function_item_declaration();

  class Function_port_listContext : public ParserRuleContext {
  public:
    Function_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Function_portContext>> function_port();
    Ref<Function_portContext> function_port(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_port_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_port_listContext> function_port_list();

  class Function_portContext : public ParserRuleContext {
  public:
    Function_portContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Tf_declarationContext> tf_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_port(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_portContext> function_port();

  class Range_or_typeContext : public ParserRuleContext {
  public:
    Range_or_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitRange_or_type(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Range_or_typeContext> range_or_type();

  class Task_declarationContext : public ParserRuleContext {
  public:
    Task_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Task_identifierContext> task_identifier();
    Ref<StatementContext> statement();
    std::vector<Ref<Task_item_declarationContext>> task_item_declaration();
    Ref<Task_item_declarationContext> task_item_declaration(int i);
    Ref<Task_port_listContext> task_port_list();
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTask_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Task_declarationContext> task_declaration();

  class Task_item_declarationContext : public ParserRuleContext {
  public:
    Task_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_item_declarationContext> block_item_declaration();
    Ref<Tf_declarationContext> tf_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTask_item_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Task_item_declarationContext> task_item_declaration();

  class Task_port_listContext : public ParserRuleContext {
  public:
    Task_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Task_port_itemContext>> task_port_item();
    Ref<Task_port_itemContext> task_port_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTask_port_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Task_port_listContext> task_port_list();

  class Task_port_itemContext : public ParserRuleContext {
  public:
    Task_port_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Tf_declarationContext> tf_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTask_port_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Task_port_itemContext> task_port_item();

  class Tf_decl_headerContext : public ParserRuleContext {
  public:
    Tf_decl_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_typeContext> net_type();
    Ref<RangeContext> range();
    Ref<Task_port_typeContext> task_port_type();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTf_decl_header(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tf_decl_headerContext> tf_decl_header();

  class Tf_declarationContext : public ParserRuleContext {
  public:
    Tf_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Tf_decl_headerContext> tf_decl_header();
    Ref<List_of_port_identifiersContext> list_of_port_identifiers();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTf_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tf_declarationContext> tf_declaration();

  class Task_port_typeContext : public ParserRuleContext {
  public:
    Task_port_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTask_port_type(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Task_port_typeContext> task_port_type();

  class Block_item_declarationContext : public ParserRuleContext {
  public:
    Block_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_reg_declarationContext> block_reg_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Event_declarationContext> event_declaration();
    Ref<Integer_declarationContext> integer_declaration();
    Ref<Local_parameter_declarationContext> local_parameter_declaration();
    Ref<Parameter_declarationContext> parameter_declaration();
    Ref<Real_declarationContext> real_declaration();
    Ref<Realtime_declarationContext> realtime_declaration();
    Ref<Time_declarationContext> time_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitBlock_item_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_item_declarationContext> block_item_declaration();

  class Block_reg_declarationContext : public ParserRuleContext {
  public:
    Block_reg_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_block_variable_identifiersContext> list_of_block_variable_identifiers();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitBlock_reg_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_reg_declarationContext> block_reg_declaration();

  class List_of_block_variable_identifiersContext : public ParserRuleContext {
  public:
    List_of_block_variable_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Block_variable_typeContext>> block_variable_type();
    Ref<Block_variable_typeContext> block_variable_type(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_block_variable_identifiers(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_block_variable_identifiersContext> list_of_block_variable_identifiers();

  class Block_variable_typeContext : public ParserRuleContext {
  public:
    Block_variable_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();
    std::vector<Ref<DimensionContext>> dimension();
    Ref<DimensionContext> dimension(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitBlock_variable_type(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_variable_typeContext> block_variable_type();

  class Gate_instantiationContext : public ParserRuleContext {
  public:
    Gate_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cmos_switchtypeContext> cmos_switchtype();
    std::vector<Ref<Cmos_switch_instanceContext>> cmos_switch_instance();
    Ref<Cmos_switch_instanceContext> cmos_switch_instance(int i);
    Ref<Delay3Context> delay3();
    Ref<Mos_switchtypeContext> mos_switchtype();
    std::vector<Ref<Mos_switch_instanceContext>> mos_switch_instance();
    Ref<Mos_switch_instanceContext> mos_switch_instance(int i);
    Ref<Pass_switchtypeContext> pass_switchtype();
    std::vector<Ref<Pass_switch_instanceContext>> pass_switch_instance();
    Ref<Pass_switch_instanceContext> pass_switch_instance(int i);
    std::vector<Ref<Pull_gate_instanceContext>> pull_gate_instance();
    Ref<Pull_gate_instanceContext> pull_gate_instance(int i);
    Ref<Pulldown_strengthContext> pulldown_strength();
    Ref<Pullup_strengthContext> pullup_strength();
    Ref<Enable_gatetypeContext> enable_gatetype();
    std::vector<Ref<Enable_gate_instanceContext>> enable_gate_instance();
    Ref<Enable_gate_instanceContext> enable_gate_instance(int i);
    Ref<Drive_strengthContext> drive_strength();
    Ref<N_input_gatetypeContext> n_input_gatetype();
    std::vector<Ref<N_input_gate_instanceContext>> n_input_gate_instance();
    Ref<N_input_gate_instanceContext> n_input_gate_instance(int i);
    Ref<Delay2Context> delay2();
    Ref<N_output_gatetypeContext> n_output_gatetype();
    std::vector<Ref<N_output_gate_instanceContext>> n_output_gate_instance();
    Ref<N_output_gate_instanceContext> n_output_gate_instance(int i);
    Ref<Pass_en_switchtypeContext> pass_en_switchtype();
    std::vector<Ref<Pass_enable_switch_instanceContext>> pass_enable_switch_instance();
    Ref<Pass_enable_switch_instanceContext> pass_enable_switch_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGate_instantiation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Gate_instantiationContext> gate_instantiation();

  class Cmos_switch_instanceContext : public ParserRuleContext {
  public:
    Cmos_switch_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    Ref<Input_terminalContext> input_terminal();
    Ref<Ncontrol_terminalContext> ncontrol_terminal();
    Ref<Pcontrol_terminalContext> pcontrol_terminal();
    Ref<Name_of_gate_instanceContext> name_of_gate_instance();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitCmos_switch_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Cmos_switch_instanceContext> cmos_switch_instance();

  class Enable_gate_instanceContext : public ParserRuleContext {
  public:
    Enable_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    Ref<Input_terminalContext> input_terminal();
    Ref<Enable_terminalContext> enable_terminal();
    Ref<Name_of_gate_instanceContext> name_of_gate_instance();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEnable_gate_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Enable_gate_instanceContext> enable_gate_instance();

  class Mos_switch_instanceContext : public ParserRuleContext {
  public:
    Mos_switch_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    Ref<Input_terminalContext> input_terminal();
    Ref<Enable_terminalContext> enable_terminal();
    Ref<Name_of_gate_instanceContext> name_of_gate_instance();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitMos_switch_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Mos_switch_instanceContext> mos_switch_instance();

  class N_input_gate_instanceContext : public ParserRuleContext {
  public:
    N_input_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    std::vector<Ref<Input_terminalContext>> input_terminal();
    Ref<Input_terminalContext> input_terminal(int i);
    Ref<Name_of_gate_instanceContext> name_of_gate_instance();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitN_input_gate_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<N_input_gate_instanceContext> n_input_gate_instance();

  class N_output_gate_instanceContext : public ParserRuleContext {
  public:
    N_output_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Output_terminalContext>> output_terminal();
    Ref<Output_terminalContext> output_terminal(int i);
    Ref<Input_terminalContext> input_terminal();
    Ref<Name_of_gate_instanceContext> name_of_gate_instance();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitN_output_gate_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<N_output_gate_instanceContext> n_output_gate_instance();

  class Pass_switch_instanceContext : public ParserRuleContext {
  public:
    Pass_switch_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Inout_terminalContext>> inout_terminal();
    Ref<Inout_terminalContext> inout_terminal(int i);
    Ref<Name_of_gate_instanceContext> name_of_gate_instance();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPass_switch_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pass_switch_instanceContext> pass_switch_instance();

  class Pass_enable_switch_instanceContext : public ParserRuleContext {
  public:
    Pass_enable_switch_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Inout_terminalContext>> inout_terminal();
    Ref<Inout_terminalContext> inout_terminal(int i);
    Ref<Enable_terminalContext> enable_terminal();
    Ref<Name_of_gate_instanceContext> name_of_gate_instance();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPass_enable_switch_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pass_enable_switch_instanceContext> pass_enable_switch_instance();

  class Pull_gate_instanceContext : public ParserRuleContext {
  public:
    Pull_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    Ref<Name_of_gate_instanceContext> name_of_gate_instance();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPull_gate_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pull_gate_instanceContext> pull_gate_instance();

  class Name_of_gate_instanceContext : public ParserRuleContext {
  public:
    Name_of_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Gate_instance_identifierContext> gate_instance_identifier();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitName_of_gate_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Name_of_gate_instanceContext> name_of_gate_instance();

  class Pulldown_strengthContext : public ParserRuleContext {
  public:
    Pulldown_strengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Strength0Context> strength0();
    Ref<Strength1Context> strength1();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPulldown_strength(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pulldown_strengthContext> pulldown_strength();

  class Pullup_strengthContext : public ParserRuleContext {
  public:
    Pullup_strengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Strength0Context> strength0();
    Ref<Strength1Context> strength1();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPullup_strength(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pullup_strengthContext> pullup_strength();

  class Enable_terminalContext : public ParserRuleContext {
  public:
    Enable_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEnable_terminal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Enable_terminalContext> enable_terminal();

  class Ncontrol_terminalContext : public ParserRuleContext {
  public:
    Ncontrol_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNcontrol_terminal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Ncontrol_terminalContext> ncontrol_terminal();

  class Pcontrol_terminalContext : public ParserRuleContext {
  public:
    Pcontrol_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPcontrol_terminal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pcontrol_terminalContext> pcontrol_terminal();

  class Input_terminalContext : public ParserRuleContext {
  public:
    Input_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInput_terminal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Input_terminalContext> input_terminal();

  class Inout_terminalContext : public ParserRuleContext {
  public:
    Inout_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_lvalueContext> net_lvalue();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInout_terminal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Inout_terminalContext> inout_terminal();

  class Output_terminalContext : public ParserRuleContext {
  public:
    Output_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_lvalueContext> net_lvalue();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitOutput_terminal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Output_terminalContext> output_terminal();

  class Cmos_switchtypeContext : public ParserRuleContext {
  public:
    Cmos_switchtypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitCmos_switchtype(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Cmos_switchtypeContext> cmos_switchtype();

  class Enable_gatetypeContext : public ParserRuleContext {
  public:
    Enable_gatetypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEnable_gatetype(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Enable_gatetypeContext> enable_gatetype();

  class Mos_switchtypeContext : public ParserRuleContext {
  public:
    Mos_switchtypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitMos_switchtype(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Mos_switchtypeContext> mos_switchtype();

  class N_input_gatetypeContext : public ParserRuleContext {
  public:
    N_input_gatetypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitN_input_gatetype(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<N_input_gatetypeContext> n_input_gatetype();

  class N_output_gatetypeContext : public ParserRuleContext {
  public:
    N_output_gatetypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitN_output_gatetype(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<N_output_gatetypeContext> n_output_gatetype();

  class Pass_en_switchtypeContext : public ParserRuleContext {
  public:
    Pass_en_switchtypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPass_en_switchtype(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pass_en_switchtypeContext> pass_en_switchtype();

  class Pass_switchtypeContext : public ParserRuleContext {
  public:
    Pass_switchtypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPass_switchtype(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pass_switchtypeContext> pass_switchtype();

  class Module_instantiationContext : public ParserRuleContext {
  public:
    Module_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_identifierContext> module_identifier();
    std::vector<Ref<Module_instanceContext>> module_instance();
    Ref<Module_instanceContext> module_instance(int i);
    Ref<Parameter_value_assignmentContext> parameter_value_assignment();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_instantiation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_instantiationContext> module_instantiation();

  class Parameter_value_assignmentContext : public ParserRuleContext {
  public:
    Parameter_value_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_parameter_assignmentsContext> list_of_parameter_assignments();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitParameter_value_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Parameter_value_assignmentContext> parameter_value_assignment();

  class List_of_parameter_assignmentsContext : public ParserRuleContext {
  public:
    List_of_parameter_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Ordered_parameter_assignmentContext>> ordered_parameter_assignment();
    Ref<Ordered_parameter_assignmentContext> ordered_parameter_assignment(int i);
    std::vector<Ref<Named_parameter_assignmentContext>> named_parameter_assignment();
    Ref<Named_parameter_assignmentContext> named_parameter_assignment(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_parameter_assignments(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_parameter_assignmentsContext> list_of_parameter_assignments();

  class Ordered_parameter_assignmentContext : public ParserRuleContext {
  public:
    Ordered_parameter_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitOrdered_parameter_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Ordered_parameter_assignmentContext> ordered_parameter_assignment();

  class Named_parameter_assignmentContext : public ParserRuleContext {
  public:
    Named_parameter_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parameter_identifierContext> parameter_identifier();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNamed_parameter_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Named_parameter_assignmentContext> named_parameter_assignment();

  class Module_instanceContext : public ParserRuleContext {
  public:
    Module_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Name_of_instanceContext> name_of_instance();
    Ref<List_of_port_connectionsContext> list_of_port_connections();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_instanceContext> module_instance();

  class Name_of_instanceContext : public ParserRuleContext {
  public:
    Name_of_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_instance_identifierContext> module_instance_identifier();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitName_of_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Name_of_instanceContext> name_of_instance();

  class List_of_port_connectionsContext : public ParserRuleContext {
  public:
    List_of_port_connectionsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Ordered_port_connectionContext>> ordered_port_connection();
    Ref<Ordered_port_connectionContext> ordered_port_connection(int i);
    std::vector<Ref<Named_port_connectionContext>> named_port_connection();
    Ref<Named_port_connectionContext> named_port_connection(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_port_connections(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_port_connectionsContext> list_of_port_connections();

  class Ordered_port_connectionContext : public ParserRuleContext {
  public:
    Ordered_port_connectionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitOrdered_port_connection(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Ordered_port_connectionContext> ordered_port_connection();

  class Named_port_connectionContext : public ParserRuleContext {
  public:
    Named_port_connectionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_identifierContext> port_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNamed_port_connection(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Named_port_connectionContext> named_port_connection();

  class Generated_instantiationContext : public ParserRuleContext {
  public:
    Generated_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Generate_itemContext>> generate_item();
    Ref<Generate_itemContext> generate_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenerated_instantiation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generated_instantiationContext> generated_instantiation();

  class Generate_item_or_nullContext : public ParserRuleContext {
  public:
    Generate_item_or_nullContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Generate_itemContext> generate_item();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenerate_item_or_null(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generate_item_or_nullContext> generate_item_or_null();

  class Generate_itemContext : public ParserRuleContext {
  public:
    Generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Generate_conditional_statementContext> generate_conditional_statement();
    Ref<Generate_case_statementContext> generate_case_statement();
    Ref<Generate_loop_statementContext> generate_loop_statement();
    Ref<Generate_blockContext> generate_block();
    Ref<Module_or_generate_itemContext> module_or_generate_item();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenerate_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generate_itemContext> generate_item();

  class Generate_conditional_statementContext : public ParserRuleContext {
  public:
    Generate_conditional_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    std::vector<Ref<Generate_item_or_nullContext>> generate_item_or_null();
    Ref<Generate_item_or_nullContext> generate_item_or_null(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenerate_conditional_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generate_conditional_statementContext> generate_conditional_statement();

  class Generate_case_statementContext : public ParserRuleContext {
  public:
    Generate_case_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    std::vector<Ref<Genvar_case_itemContext>> genvar_case_item();
    Ref<Genvar_case_itemContext> genvar_case_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenerate_case_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generate_case_statementContext> generate_case_statement();

  class Genvar_case_itemContext : public ParserRuleContext {
  public:
    Genvar_case_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);
    Ref<Generate_item_or_nullContext> generate_item_or_null();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenvar_case_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Genvar_case_itemContext> genvar_case_item();

  class Generate_loop_statementContext : public ParserRuleContext {
  public:
    Generate_loop_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Genvar_assignmentContext>> genvar_assignment();
    Ref<Genvar_assignmentContext> genvar_assignment(int i);
    Ref<Constant_expressionContext> constant_expression();
    Ref<Generate_blockContext> generate_block();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenerate_loop_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generate_loop_statementContext> generate_loop_statement();

  class Genvar_assignmentContext : public ParserRuleContext {
  public:
    Genvar_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Genvar_identifierContext> genvar_identifier();
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenvar_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Genvar_assignmentContext> genvar_assignment();

  class Generate_blockContext : public ParserRuleContext {
  public:
    Generate_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Generate_block_identifierContext> generate_block_identifier();
    std::vector<Ref<Generate_itemContext>> generate_item();
    Ref<Generate_itemContext> generate_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenerate_block(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generate_blockContext> generate_block();

  class Continuous_assignContext : public ParserRuleContext {
  public:
    Continuous_assignContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_net_assignmentsContext> list_of_net_assignments();
    Ref<Drive_strengthContext> drive_strength();
    Ref<Delay3Context> delay3();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitContinuous_assign(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Continuous_assignContext> continuous_assign();

  class List_of_net_assignmentsContext : public ParserRuleContext {
  public:
    List_of_net_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Net_assignmentContext>> net_assignment();
    Ref<Net_assignmentContext> net_assignment(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_net_assignments(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_net_assignmentsContext> list_of_net_assignments();

  class Net_assignmentContext : public ParserRuleContext {
  public:
    Net_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_lvalueContext> net_lvalue();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNet_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Net_assignmentContext> net_assignment();

  class Initial_constructContext : public ParserRuleContext {
  public:
    Initial_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<StatementContext> statement();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInitial_construct(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Initial_constructContext> initial_construct();

  class Always_constructContext : public ParserRuleContext {
  public:
    Always_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<StatementContext> statement();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitAlways_construct(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Always_constructContext> always_construct();

  class Blocking_assignmentContext : public ParserRuleContext {
  public:
    Blocking_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<ExpressionContext> expression();
    Ref<Delay_or_event_controlContext> delay_or_event_control();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitBlocking_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Blocking_assignmentContext> blocking_assignment();

  class Nonblocking_assignmentContext : public ParserRuleContext {
  public:
    Nonblocking_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<ExpressionContext> expression();
    Ref<Delay_or_event_controlContext> delay_or_event_control();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNonblocking_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Nonblocking_assignmentContext> nonblocking_assignment();

  class Procedural_continuous_assignmentsContext : public ParserRuleContext {
  public:
    Procedural_continuous_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_assignmentContext> variable_assignment();
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<Net_assignmentContext> net_assignment();
    Ref<Net_lvalueContext> net_lvalue();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitProcedural_continuous_assignments(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Procedural_continuous_assignmentsContext> procedural_continuous_assignments();

  class Function_blocking_assignmentContext : public ParserRuleContext {
  public:
    Function_blocking_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_blocking_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_blocking_assignmentContext> function_blocking_assignment();

  class Function_statement_or_nullContext : public ParserRuleContext {
  public:
    Function_statement_or_nullContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_statementContext> function_statement();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_statement_or_null(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_statement_or_nullContext> function_statement_or_null();

  class Function_seq_blockContext : public ParserRuleContext {
  public:
    Function_seq_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_identifierContext> block_identifier();
    std::vector<Ref<Function_statementContext>> function_statement();
    Ref<Function_statementContext> function_statement(int i);
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_seq_block(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_seq_blockContext> function_seq_block();

  class Variable_assignmentContext : public ParserRuleContext {
  public:
    Variable_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitVariable_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Variable_assignmentContext> variable_assignment();

  class Par_blockContext : public ParserRuleContext {
  public:
    Par_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_identifierContext> block_identifier();
    std::vector<Ref<StatementContext>> statement();
    Ref<StatementContext> statement(int i);
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPar_block(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Par_blockContext> par_block();

  class Seq_blockContext : public ParserRuleContext {
  public:
    Seq_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_identifierContext> block_identifier();
    std::vector<Ref<StatementContext>> statement();
    Ref<StatementContext> statement(int i);
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSeq_block(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Seq_blockContext> seq_block();

  class StatementContext : public ParserRuleContext {
  public:
    StatementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Blocking_assignmentContext> blocking_assignment();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Case_statementContext> case_statement();
    Ref<Conditional_statementContext> conditional_statement();
    Ref<Disable_statementContext> disable_statement();
    Ref<Event_triggerContext> event_trigger();
    Ref<Loop_statementContext> loop_statement();
    Ref<Nonblocking_assignmentContext> nonblocking_assignment();
    Ref<Par_blockContext> par_block();
    Ref<Procedural_continuous_assignmentsContext> procedural_continuous_assignments();
    Ref<Procedural_timing_control_statementContext> procedural_timing_control_statement();
    Ref<Seq_blockContext> seq_block();
    Ref<System_task_enableContext> system_task_enable();
    Ref<Task_enableContext> task_enable();
    Ref<Wait_statementContext> wait_statement();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitStatement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<StatementContext> statement();

  class Statement_or_nullContext : public ParserRuleContext {
  public:
    Statement_or_nullContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<StatementContext> statement();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitStatement_or_null(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Statement_or_nullContext> statement_or_null();

  class Function_statementContext : public ParserRuleContext {
  public:
    Function_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_blocking_assignmentContext> function_blocking_assignment();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Function_case_statementContext> function_case_statement();
    Ref<Function_conditional_statementContext> function_conditional_statement();
    Ref<Function_loop_statementContext> function_loop_statement();
    Ref<Function_seq_blockContext> function_seq_block();
    Ref<Disable_statementContext> disable_statement();
    Ref<System_task_enableContext> system_task_enable();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_statementContext> function_statement();

  class Delay_or_event_controlContext : public ParserRuleContext {
  public:
    Delay_or_event_controlContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Delay_controlContext> delay_control();
    Ref<Event_controlContext> event_control();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDelay_or_event_control(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Delay_or_event_controlContext> delay_or_event_control();

  class Delay_controlContext : public ParserRuleContext {
  public:
    Delay_controlContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Delay_valueContext> delay_value();
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDelay_control(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Delay_controlContext> delay_control();

  class Disable_statementContext : public ParserRuleContext {
  public:
    Disable_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_task_identifierContext> hierarchical_task_identifier();
    Ref<Hierarchical_block_identifierContext> hierarchical_block_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDisable_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Disable_statementContext> disable_statement();

  class Event_controlContext : public ParserRuleContext {
  public:
    Event_controlContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Event_identifierContext> event_identifier();
    Ref<Event_expressionContext> event_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEvent_control(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Event_controlContext> event_control();

  class Event_triggerContext : public ParserRuleContext {
  public:
    Event_triggerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_event_identifierContext> hierarchical_event_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEvent_trigger(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Event_triggerContext> event_trigger();

  class Event_expressionContext : public ParserRuleContext {
  public:
    Event_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Event_primaryContext>> event_primary();
    Ref<Event_primaryContext> event_primary(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEvent_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Event_expressionContext> event_expression();

  class Event_primaryContext : public ParserRuleContext {
  public:
    Event_primaryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEvent_primary(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Event_primaryContext> event_primary();

  class Procedural_timing_control_statementContext : public ParserRuleContext {
  public:
    Procedural_timing_control_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Delay_or_event_controlContext> delay_or_event_control();
    Ref<Statement_or_nullContext> statement_or_null();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitProcedural_timing_control_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Procedural_timing_control_statementContext> procedural_timing_control_statement();

  class Wait_statementContext : public ParserRuleContext {
  public:
    Wait_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Statement_or_nullContext> statement_or_null();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitWait_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Wait_statementContext> wait_statement();

  class Conditional_statementContext : public ParserRuleContext {
  public:
    Conditional_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    std::vector<Ref<Statement_or_nullContext>> statement_or_null();
    Ref<Statement_or_nullContext> statement_or_null(int i);
    Ref<If_else_if_statementContext> if_else_if_statement();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConditional_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Conditional_statementContext> conditional_statement();

  class If_else_if_statementContext : public ParserRuleContext {
  public:
    If_else_if_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    std::vector<Ref<Statement_or_nullContext>> statement_or_null();
    Ref<Statement_or_nullContext> statement_or_null(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitIf_else_if_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<If_else_if_statementContext> if_else_if_statement();

  class Function_conditional_statementContext : public ParserRuleContext {
  public:
    Function_conditional_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    std::vector<Ref<Function_statement_or_nullContext>> function_statement_or_null();
    Ref<Function_statement_or_nullContext> function_statement_or_null(int i);
    Ref<Function_if_else_if_statementContext> function_if_else_if_statement();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_conditional_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_conditional_statementContext> function_conditional_statement();

  class Function_if_else_if_statementContext : public ParserRuleContext {
  public:
    Function_if_else_if_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    std::vector<Ref<Function_statement_or_nullContext>> function_statement_or_null();
    Ref<Function_statement_or_nullContext> function_statement_or_null(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_if_else_if_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_if_else_if_statementContext> function_if_else_if_statement();

  class Case_statementContext : public ParserRuleContext {
  public:
    Case_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    std::vector<Ref<Case_itemContext>> case_item();
    Ref<Case_itemContext> case_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitCase_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Case_statementContext> case_statement();

  class Case_itemContext : public ParserRuleContext {
  public:
    Case_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Statement_or_nullContext> statement_or_null();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitCase_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Case_itemContext> case_item();

  class Function_case_statementContext : public ParserRuleContext {
  public:
    Function_case_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    std::vector<Ref<Function_case_itemContext>> function_case_item();
    Ref<Function_case_itemContext> function_case_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_case_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_case_statementContext> function_case_statement();

  class Function_case_itemContext : public ParserRuleContext {
  public:
    Function_case_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Function_statement_or_nullContext> function_statement_or_null();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_case_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_case_itemContext> function_case_item();

  class Function_loop_statementContext : public ParserRuleContext {
  public:
    Function_loop_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_statementContext> function_statement();
    Ref<ExpressionContext> expression();
    std::vector<Ref<Variable_assignmentContext>> variable_assignment();
    Ref<Variable_assignmentContext> variable_assignment(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_loop_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_loop_statementContext> function_loop_statement();

  class Loop_statementContext : public ParserRuleContext {
  public:
    Loop_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<StatementContext> statement();
    Ref<ExpressionContext> expression();
    std::vector<Ref<Variable_assignmentContext>> variable_assignment();
    Ref<Variable_assignmentContext> variable_assignment(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitLoop_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Loop_statementContext> loop_statement();

  class System_task_enableContext : public ParserRuleContext {
  public:
    System_task_enableContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<System_task_identifierContext> system_task_identifier();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSystem_task_enable(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<System_task_enableContext> system_task_enable();

  class Task_enableContext : public ParserRuleContext {
  public:
    Task_enableContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_task_identifierContext> hierarchical_task_identifier();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTask_enable(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Task_enableContext> task_enable();

  class Specify_blockContext : public ParserRuleContext {
  public:
    Specify_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Specify_itemContext>> specify_item();
    Ref<Specify_itemContext> specify_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSpecify_block(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Specify_blockContext> specify_block();

  class Specify_itemContext : public ParserRuleContext {
  public:
    Specify_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Specparam_declarationContext> specparam_declaration();
    Ref<Pulsestyle_declarationContext> pulsestyle_declaration();
    Ref<Showcancelled_declarationContext> showcancelled_declaration();
    Ref<Path_declarationContext> path_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSpecify_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Specify_itemContext> specify_item();

  class Pulsestyle_declarationContext : public ParserRuleContext {
  public:
    Pulsestyle_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_outputsContext> list_of_path_outputs();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPulsestyle_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Pulsestyle_declarationContext> pulsestyle_declaration();

  class Showcancelled_declarationContext : public ParserRuleContext {
  public:
    Showcancelled_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_outputsContext> list_of_path_outputs();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitShowcancelled_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Showcancelled_declarationContext> showcancelled_declaration();

  class Path_declarationContext : public ParserRuleContext {
  public:
    Path_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_path_declarationContext> simple_path_declaration();
    Ref<Edge_sensitive_path_declarationContext> edge_sensitive_path_declaration();
    Ref<State_dependent_path_declarationContext> state_dependent_path_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPath_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Path_declarationContext> path_declaration();

  class Simple_path_declarationContext : public ParserRuleContext {
  public:
    Simple_path_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parallel_path_descriptionContext> parallel_path_description();
    Ref<Path_delay_valueContext> path_delay_value();
    Ref<Full_path_descriptionContext> full_path_description();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSimple_path_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simple_path_declarationContext> simple_path_declaration();

  class Parallel_path_descriptionContext : public ParserRuleContext {
  public:
    Parallel_path_descriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor();
    Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor();
    Ref<Polarity_operatorContext> polarity_operator();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitParallel_path_description(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Parallel_path_descriptionContext> parallel_path_description();

  class Full_path_descriptionContext : public ParserRuleContext {
  public:
    Full_path_descriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_inputsContext> list_of_path_inputs();
    Ref<List_of_path_outputsContext> list_of_path_outputs();
    Ref<Polarity_operatorContext> polarity_operator();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFull_path_description(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Full_path_descriptionContext> full_path_description();

  class List_of_path_inputsContext : public ParserRuleContext {
  public:
    List_of_path_inputsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Specify_input_terminal_descriptorContext>> specify_input_terminal_descriptor();
    Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_path_inputs(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_path_inputsContext> list_of_path_inputs();

  class List_of_path_outputsContext : public ParserRuleContext {
  public:
    List_of_path_outputsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Specify_output_terminal_descriptorContext>> specify_output_terminal_descriptor();
    Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_path_outputs(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_path_outputsContext> list_of_path_outputs();

  class Specify_input_terminal_descriptorContext : public ParserRuleContext {
  public:
    Specify_input_terminal_descriptorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Input_identifierContext> input_identifier();
    Ref<Constant_expressionContext> constant_expression();
    Ref<Range_expressionContext> range_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSpecify_input_terminal_descriptor(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor();

  class Specify_output_terminal_descriptorContext : public ParserRuleContext {
  public:
    Specify_output_terminal_descriptorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_identifierContext> output_identifier();
    Ref<Constant_expressionContext> constant_expression();
    Ref<Range_expressionContext> range_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSpecify_output_terminal_descriptor(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor();

  class Input_identifierContext : public ParserRuleContext {
  public:
    Input_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Input_port_identifierContext> input_port_identifier();
    Ref<Inout_port_identifierContext> inout_port_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInput_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Input_identifierContext> input_identifier();

  class Output_identifierContext : public ParserRuleContext {
  public:
    Output_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_port_identifierContext> output_port_identifier();
    Ref<Inout_port_identifierContext> inout_port_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitOutput_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Output_identifierContext> output_identifier();

  class Path_delay_valueContext : public ParserRuleContext {
  public:
    Path_delay_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_delay_expressionsContext> list_of_path_delay_expressions();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPath_delay_value(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Path_delay_valueContext> path_delay_value();

  class List_of_path_delay_expressionsContext : public ParserRuleContext {
  public:
    List_of_path_delay_expressionsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<T_path_delay_expressionContext> t_path_delay_expression();
    Ref<Trise_path_delay_expressionContext> trise_path_delay_expression();
    Ref<Tfall_path_delay_expressionContext> tfall_path_delay_expression();
    Ref<Tz_path_delay_expressionContext> tz_path_delay_expression();
    Ref<T01_path_delay_expressionContext> t01_path_delay_expression();
    Ref<T10_path_delay_expressionContext> t10_path_delay_expression();
    Ref<T0z_path_delay_expressionContext> t0z_path_delay_expression();
    Ref<Tz1_path_delay_expressionContext> tz1_path_delay_expression();
    Ref<T1z_path_delay_expressionContext> t1z_path_delay_expression();
    Ref<Tz0_path_delay_expressionContext> tz0_path_delay_expression();
    Ref<T0x_path_delay_expressionContext> t0x_path_delay_expression();
    Ref<Tx1_path_delay_expressionContext> tx1_path_delay_expression();
    Ref<T1x_path_delay_expressionContext> t1x_path_delay_expression();
    Ref<Tx0_path_delay_expressionContext> tx0_path_delay_expression();
    Ref<Txz_path_delay_expressionContext> txz_path_delay_expression();
    Ref<Tzx_path_delay_expressionContext> tzx_path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitList_of_path_delay_expressions(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<List_of_path_delay_expressionsContext> list_of_path_delay_expressions();

  class T_path_delay_expressionContext : public ParserRuleContext {
  public:
    T_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitT_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<T_path_delay_expressionContext> t_path_delay_expression();

  class Trise_path_delay_expressionContext : public ParserRuleContext {
  public:
    Trise_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTrise_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Trise_path_delay_expressionContext> trise_path_delay_expression();

  class Tfall_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tfall_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTfall_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tfall_path_delay_expressionContext> tfall_path_delay_expression();

  class Tz_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tz_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTz_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tz_path_delay_expressionContext> tz_path_delay_expression();

  class T01_path_delay_expressionContext : public ParserRuleContext {
  public:
    T01_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitT01_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<T01_path_delay_expressionContext> t01_path_delay_expression();

  class T10_path_delay_expressionContext : public ParserRuleContext {
  public:
    T10_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitT10_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<T10_path_delay_expressionContext> t10_path_delay_expression();

  class T0z_path_delay_expressionContext : public ParserRuleContext {
  public:
    T0z_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitT0z_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<T0z_path_delay_expressionContext> t0z_path_delay_expression();

  class Tz1_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tz1_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTz1_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tz1_path_delay_expressionContext> tz1_path_delay_expression();

  class T1z_path_delay_expressionContext : public ParserRuleContext {
  public:
    T1z_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitT1z_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<T1z_path_delay_expressionContext> t1z_path_delay_expression();

  class Tz0_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tz0_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTz0_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tz0_path_delay_expressionContext> tz0_path_delay_expression();

  class T0x_path_delay_expressionContext : public ParserRuleContext {
  public:
    T0x_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitT0x_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<T0x_path_delay_expressionContext> t0x_path_delay_expression();

  class Tx1_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tx1_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTx1_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tx1_path_delay_expressionContext> tx1_path_delay_expression();

  class T1x_path_delay_expressionContext : public ParserRuleContext {
  public:
    T1x_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitT1x_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<T1x_path_delay_expressionContext> t1x_path_delay_expression();

  class Tx0_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tx0_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTx0_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tx0_path_delay_expressionContext> tx0_path_delay_expression();

  class Txz_path_delay_expressionContext : public ParserRuleContext {
  public:
    Txz_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTxz_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Txz_path_delay_expressionContext> txz_path_delay_expression();

  class Tzx_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tzx_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTzx_path_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tzx_path_delay_expressionContext> tzx_path_delay_expression();

  class Path_delay_expressionContext : public ParserRuleContext {
  public:
    Path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPath_delay_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Path_delay_expressionContext> path_delay_expression();

  class Edge_sensitive_path_declarationContext : public ParserRuleContext {
  public:
    Edge_sensitive_path_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parallel_edge_sensitive_path_descriptionContext> parallel_edge_sensitive_path_description();
    Ref<Path_delay_valueContext> path_delay_value();
    Ref<Full_edge_sensitive_path_descriptionContext> full_edge_sensitive_path_description();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEdge_sensitive_path_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Edge_sensitive_path_declarationContext> edge_sensitive_path_declaration();

  class Parallel_edge_sensitive_path_descriptionContext : public ParserRuleContext {
  public:
    Parallel_edge_sensitive_path_descriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor();
    Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor();
    Ref<Data_source_expressionContext> data_source_expression();
    Ref<Edge_identifierContext> edge_identifier();
    Ref<Polarity_operatorContext> polarity_operator();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitParallel_edge_sensitive_path_description(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Parallel_edge_sensitive_path_descriptionContext> parallel_edge_sensitive_path_description();

  class Full_edge_sensitive_path_descriptionContext : public ParserRuleContext {
  public:
    Full_edge_sensitive_path_descriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_inputsContext> list_of_path_inputs();
    Ref<List_of_path_outputsContext> list_of_path_outputs();
    Ref<Data_source_expressionContext> data_source_expression();
    Ref<Edge_identifierContext> edge_identifier();
    Ref<Polarity_operatorContext> polarity_operator();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFull_edge_sensitive_path_description(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Full_edge_sensitive_path_descriptionContext> full_edge_sensitive_path_description();

  class Data_source_expressionContext : public ParserRuleContext {
  public:
    Data_source_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitData_source_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Data_source_expressionContext> data_source_expression();

  class Edge_identifierContext : public ParserRuleContext {
  public:
    Edge_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEdge_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Edge_identifierContext> edge_identifier();

  class State_dependent_path_declarationContext : public ParserRuleContext {
  public:
    State_dependent_path_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_path_expressionContext> module_path_expression();
    Ref<Simple_path_declarationContext> simple_path_declaration();
    Ref<Edge_sensitive_path_declarationContext> edge_sensitive_path_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitState_dependent_path_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<State_dependent_path_declarationContext> state_dependent_path_declaration();

  class Polarity_operatorContext : public ParserRuleContext {
  public:
    Polarity_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPolarity_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Polarity_operatorContext> polarity_operator();

  class Checktime_conditionContext : public ParserRuleContext {
  public:
    Checktime_conditionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitChecktime_condition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Checktime_conditionContext> checktime_condition();

  class Delayed_dataContext : public ParserRuleContext {
  public:
    Delayed_dataContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Terminal_identifierContext> terminal_identifier();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDelayed_data(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Delayed_dataContext> delayed_data();

  class Delayed_referenceContext : public ParserRuleContext {
  public:
    Delayed_referenceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Terminal_identifierContext> terminal_identifier();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDelayed_reference(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Delayed_referenceContext> delayed_reference();

  class End_edge_offsetContext : public ParserRuleContext {
  public:
    End_edge_offsetContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEnd_edge_offset(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<End_edge_offsetContext> end_edge_offset();

  class Event_based_flagContext : public ParserRuleContext {
  public:
    Event_based_flagContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEvent_based_flag(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Event_based_flagContext> event_based_flag();

  class Notify_regContext : public ParserRuleContext {
  public:
    Notify_regContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNotify_reg(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Notify_regContext> notify_reg();

  class Remain_active_flagContext : public ParserRuleContext {
  public:
    Remain_active_flagContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitRemain_active_flag(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Remain_active_flagContext> remain_active_flag();

  class Stamptime_conditionContext : public ParserRuleContext {
  public:
    Stamptime_conditionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitStamptime_condition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Stamptime_conditionContext> stamptime_condition();

  class Start_edge_offsetContext : public ParserRuleContext {
  public:
    Start_edge_offsetContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitStart_edge_offset(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Start_edge_offsetContext> start_edge_offset();

  class ThresholdContext : public ParserRuleContext {
  public:
    ThresholdContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitThreshold(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<ThresholdContext> threshold();

  class Timing_check_limitContext : public ParserRuleContext {
  public:
    Timing_check_limitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTiming_check_limit(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Timing_check_limitContext> timing_check_limit();

  class ConcatenationContext : public ParserRuleContext {
  public:
    ConcatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConcatenation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<ConcatenationContext> concatenation();

  class Constant_concatenationContext : public ParserRuleContext {
  public:
    Constant_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConstant_concatenation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_concatenationContext> constant_concatenation();

  class Constant_multiple_concatenationContext : public ParserRuleContext {
  public:
    Constant_multiple_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<Constant_concatenationContext> constant_concatenation();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConstant_multiple_concatenation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_multiple_concatenationContext> constant_multiple_concatenation();

  class Module_path_concatenationContext : public ParserRuleContext {
  public:
    Module_path_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Module_path_expressionContext>> module_path_expression();
    Ref<Module_path_expressionContext> module_path_expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_path_concatenation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_path_concatenationContext> module_path_concatenation();

  class Module_path_multiple_concatenationContext : public ParserRuleContext {
  public:
    Module_path_multiple_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<Module_path_concatenationContext> module_path_concatenation();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_path_multiple_concatenation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_path_multiple_concatenationContext> module_path_multiple_concatenation();

  class Multiple_concatenationContext : public ParserRuleContext {
  public:
    Multiple_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<ConcatenationContext> concatenation();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitMultiple_concatenation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Multiple_concatenationContext> multiple_concatenation();

  class Net_concatenationContext : public ParserRuleContext {
  public:
    Net_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Net_concatenation_valueContext>> net_concatenation_value();
    Ref<Net_concatenation_valueContext> net_concatenation_value(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNet_concatenation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Net_concatenationContext> net_concatenation();

  class Net_concatenation_valueContext : public ParserRuleContext {
  public:
    Net_concatenation_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_net_identifierContext> hierarchical_net_identifier();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Range_expressionContext> range_expression();
    Ref<Net_concatenationContext> net_concatenation();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNet_concatenation_value(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Net_concatenation_valueContext> net_concatenation_value();

  class Variable_concatenationContext : public ParserRuleContext {
  public:
    Variable_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Variable_concatenation_valueContext>> variable_concatenation_value();
    Ref<Variable_concatenation_valueContext> variable_concatenation_value(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitVariable_concatenation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Variable_concatenationContext> variable_concatenation();

  class Variable_concatenation_valueContext : public ParserRuleContext {
  public:
    Variable_concatenation_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_variable_identifierContext> hierarchical_variable_identifier();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Range_expressionContext> range_expression();
    Ref<Variable_concatenationContext> variable_concatenation();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitVariable_concatenation_value(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Variable_concatenation_valueContext> variable_concatenation_value();

  class Constant_function_callContext : public ParserRuleContext {
  public:
    Constant_function_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_identifierContext> function_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConstant_function_call(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_function_callContext> constant_function_call();

  class Function_callContext : public ParserRuleContext {
  public:
    Function_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_function_identifierContext> hierarchical_function_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_call(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_callContext> function_call();

  class System_function_callContext : public ParserRuleContext {
  public:
    System_function_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<System_function_identifierContext> system_function_identifier();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSystem_function_call(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<System_function_callContext> system_function_call();

  class Genvar_function_callContext : public ParserRuleContext {
  public:
    Genvar_function_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Genvar_function_identifierContext> genvar_function_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenvar_function_call(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Genvar_function_callContext> genvar_function_call();

  class Base_expressionContext : public ParserRuleContext {
  public:
    Base_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitBase_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Base_expressionContext> base_expression();

  class Constant_base_expressionContext : public ParserRuleContext {
  public:
    Constant_base_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConstant_base_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_base_expressionContext> constant_base_expression();

  class Constant_expressionContext : public ParserRuleContext {
  public:
    Constant_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConstant_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_expressionContext> constant_expression();

  class Constant_mintypmax_expressionContext : public ParserRuleContext {
  public:
    Constant_mintypmax_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConstant_mintypmax_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

  class Constant_range_expressionContext : public ParserRuleContext {
  public:
    Constant_range_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<Msb_constant_expressionContext> msb_constant_expression();
    Ref<Lsb_constant_expressionContext> lsb_constant_expression();
    Ref<Constant_base_expressionContext> constant_base_expression();
    Ref<Width_constant_expressionContext> width_constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConstant_range_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_range_expressionContext> constant_range_expression();

  class Dimension_constant_expressionContext : public ParserRuleContext {
  public:
    Dimension_constant_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDimension_constant_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Dimension_constant_expressionContext> dimension_constant_expression();

  class ExpressionContext : public ParserRuleContext {
  public:
    ExpressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<TermContext>> term();
    Ref<TermContext> term(int i);
    std::vector<Ref<Binary_operatorContext>> binary_operator();
    Ref<Binary_operatorContext> binary_operator(int i);
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitExpression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<ExpressionContext> expression();

  class TermContext : public ParserRuleContext {
  public:
    TermContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Unary_operatorContext> unary_operator();
    Ref<PrimaryContext> primary();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<tree::TerminalNode> String();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTerm(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<TermContext> term();

  class Lsb_constant_expressionContext : public ParserRuleContext {
  public:
    Lsb_constant_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitLsb_constant_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Lsb_constant_expressionContext> lsb_constant_expression();

  class Mintypmax_expressionContext : public ParserRuleContext {
  public:
    Mintypmax_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitMintypmax_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Mintypmax_expressionContext> mintypmax_expression();

  class Module_path_conditional_expressionContext : public ParserRuleContext {
  public:
    Module_path_conditional_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Module_path_expressionContext>> module_path_expression();
    Ref<Module_path_expressionContext> module_path_expression(int i);
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_path_conditional_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_path_conditional_expressionContext> module_path_conditional_expression();

  class Module_path_expressionContext : public ParserRuleContext {
  public:
    Module_path_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_path_primaryContext> module_path_primary();
    Ref<Unary_module_path_operatorContext> unary_module_path_operator();
    std::vector<Ref<Binary_module_path_operatorContext>> binary_module_path_operator();
    Ref<Binary_module_path_operatorContext> binary_module_path_operator(int i);
    std::vector<Ref<Module_path_expressionContext>> module_path_expression();
    Ref<Module_path_expressionContext> module_path_expression(int i);
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_path_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_path_expressionContext> module_path_expression();

  class Module_path_mintypmax_expressionContext : public ParserRuleContext {
  public:
    Module_path_mintypmax_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Module_path_expressionContext>> module_path_expression();
    Ref<Module_path_expressionContext> module_path_expression(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_path_mintypmax_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_path_mintypmax_expressionContext> module_path_mintypmax_expression();

  class Msb_constant_expressionContext : public ParserRuleContext {
  public:
    Msb_constant_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitMsb_constant_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Msb_constant_expressionContext> msb_constant_expression();

  class Range_expressionContext : public ParserRuleContext {
  public:
    Range_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Msb_constant_expressionContext> msb_constant_expression();
    Ref<Lsb_constant_expressionContext> lsb_constant_expression();
    Ref<Base_expressionContext> base_expression();
    Ref<Width_constant_expressionContext> width_constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitRange_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Range_expressionContext> range_expression();

  class Width_constant_expressionContext : public ParserRuleContext {
  public:
    Width_constant_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitWidth_constant_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Width_constant_expressionContext> width_constant_expression();

  class Constant_primaryContext : public ParserRuleContext {
  public:
    Constant_primaryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_concatenationContext> constant_concatenation();
    Ref<Constant_function_callContext> constant_function_call();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();
    Ref<Constant_multiple_concatenationContext> constant_multiple_concatenation();
    Ref<Genvar_identifierContext> genvar_identifier();
    Ref<NumberContext> number();
    Ref<Parameter_identifierContext> parameter_identifier();
    Ref<Specparam_identifierContext> specparam_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConstant_primary(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_primaryContext> constant_primary();

  class Module_path_primaryContext : public ParserRuleContext {
  public:
    Module_path_primaryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NumberContext> number();
    Ref<IdentifierContext> identifier();
    Ref<Module_path_concatenationContext> module_path_concatenation();
    Ref<Module_path_multiple_concatenationContext> module_path_multiple_concatenation();
    Ref<Function_callContext> function_call();
    Ref<System_function_callContext> system_function_call();
    Ref<Constant_function_callContext> constant_function_call();
    Ref<Module_path_mintypmax_expressionContext> module_path_mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_path_primary(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_path_primaryContext> module_path_primary();

  class PrimaryContext : public ParserRuleContext {
  public:
    PrimaryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NumberContext> number();
    Ref<Hierarchical_identifierContext> hierarchical_identifier();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Range_expressionContext> range_expression();
    Ref<ConcatenationContext> concatenation();
    Ref<Multiple_concatenationContext> multiple_concatenation();
    Ref<Function_callContext> function_call();
    Ref<System_function_callContext> system_function_call();
    Ref<Constant_function_callContext> constant_function_call();
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPrimary(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<PrimaryContext> primary();

  class Net_lvalueContext : public ParserRuleContext {
  public:
    Net_lvalueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_net_identifierContext> hierarchical_net_identifier();
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);
    Ref<Constant_range_expressionContext> constant_range_expression();
    Ref<Net_concatenationContext> net_concatenation();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNet_lvalue(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Net_lvalueContext> net_lvalue();

  class Variable_lvalueContext : public ParserRuleContext {
  public:
    Variable_lvalueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_variable_identifierContext> hierarchical_variable_identifier();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Range_expressionContext> range_expression();
    Ref<Variable_concatenationContext> variable_concatenation();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitVariable_lvalue(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Variable_lvalueContext> variable_lvalue();

  class Unary_operatorContext : public ParserRuleContext {
  public:
    Unary_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitUnary_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Unary_operatorContext> unary_operator();

  class Binary_operatorContext : public ParserRuleContext {
  public:
    Binary_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitBinary_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Binary_operatorContext> binary_operator();

  class Unary_module_path_operatorContext : public ParserRuleContext {
  public:
    Unary_module_path_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitUnary_module_path_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Unary_module_path_operatorContext> unary_module_path_operator();

  class Binary_module_path_operatorContext : public ParserRuleContext {
  public:
    Binary_module_path_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitBinary_module_path_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Binary_module_path_operatorContext> binary_module_path_operator();

  class NumberContext : public ParserRuleContext {
  public:
    NumberContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Decimal_number();
    Ref<tree::TerminalNode> Octal_number();
    Ref<tree::TerminalNode> Binary_number();
    Ref<tree::TerminalNode> Hex_number();
    Ref<tree::TerminalNode> Real_number();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNumber(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<NumberContext> number();

  class Default_nettype_specContext : public ParserRuleContext {
  public:
    Default_nettype_specContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitDefault_nettype_spec(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Default_nettype_specContext> default_nettype_spec();

  class Timing_specContext : public ParserRuleContext {
  public:
    Timing_specContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> Time_Identifier();
    Ref<tree::TerminalNode> Time_Identifier(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTiming_spec(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Timing_specContext> timing_spec();

  class Attribute_instanceContext : public ParserRuleContext {
  public:
    Attribute_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Attr_specContext>> attr_spec();
    Ref<Attr_specContext> attr_spec(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitAttribute_instance(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Attribute_instanceContext> attribute_instance();

  class Attr_specContext : public ParserRuleContext {
  public:
    Attr_specContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Attr_nameContext> attr_name();
    Ref<Constant_expressionContext> constant_expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitAttr_spec(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Attr_specContext> attr_spec();

  class Attr_nameContext : public ParserRuleContext {
  public:
    Attr_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitAttr_name(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Attr_nameContext> attr_name();

  class Arrayed_identifierContext : public ParserRuleContext {
  public:
    Arrayed_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_arrayed_identifierContext> simple_arrayed_identifier();
    Ref<Escaped_arrayed_identifierContext> escaped_arrayed_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitArrayed_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Arrayed_identifierContext> arrayed_identifier();

  class Block_identifierContext : public ParserRuleContext {
  public:
    Block_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitBlock_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_identifierContext> block_identifier();

  class Cell_identifierContext : public ParserRuleContext {
  public:
    Cell_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitCell_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Cell_identifierContext> cell_identifier();

  class Config_identifierContext : public ParserRuleContext {
  public:
    Config_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitConfig_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Config_identifierContext> config_identifier();

  class Escaped_arrayed_identifierContext : public ParserRuleContext {
  public:
    Escaped_arrayed_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Escaped_identifier();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEscaped_arrayed_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Escaped_arrayed_identifierContext> escaped_arrayed_identifier();

  class Escaped_hierarchical_identifierContext : public ParserRuleContext {
  public:
    Escaped_hierarchical_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Escaped_hierarchical_branchContext>> escaped_hierarchical_branch();
    Ref<Escaped_hierarchical_branchContext> escaped_hierarchical_branch(int i);
    std::vector<Ref<Simple_hierarchical_branchContext>> simple_hierarchical_branch();
    Ref<Simple_hierarchical_branchContext> simple_hierarchical_branch(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEscaped_hierarchical_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Escaped_hierarchical_identifierContext> escaped_hierarchical_identifier();

  class Event_identifierContext : public ParserRuleContext {
  public:
    Event_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEvent_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Event_identifierContext> event_identifier();

  class Function_identifierContext : public ParserRuleContext {
  public:
    Function_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitFunction_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_identifierContext> function_identifier();

  class Gate_instance_identifierContext : public ParserRuleContext {
  public:
    Gate_instance_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Arrayed_identifierContext> arrayed_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGate_instance_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Gate_instance_identifierContext> gate_instance_identifier();

  class Generate_block_identifierContext : public ParserRuleContext {
  public:
    Generate_block_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenerate_block_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generate_block_identifierContext> generate_block_identifier();

  class Genvar_function_identifierContext : public ParserRuleContext {
  public:
    Genvar_function_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenvar_function_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Genvar_function_identifierContext> genvar_function_identifier();

  class Genvar_identifierContext : public ParserRuleContext {
  public:
    Genvar_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitGenvar_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Genvar_identifierContext> genvar_identifier();

  class Hierarchical_block_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_block_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitHierarchical_block_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Hierarchical_block_identifierContext> hierarchical_block_identifier();

  class Hierarchical_event_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_event_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitHierarchical_event_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Hierarchical_event_identifierContext> hierarchical_event_identifier();

  class Hierarchical_function_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_function_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitHierarchical_function_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Hierarchical_function_identifierContext> hierarchical_function_identifier();

  class Hierarchical_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_hierarchical_identifierContext> simple_hierarchical_identifier();
    Ref<Escaped_hierarchical_identifierContext> escaped_hierarchical_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitHierarchical_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Hierarchical_identifierContext> hierarchical_identifier();

  class Hierarchical_net_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_net_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitHierarchical_net_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Hierarchical_net_identifierContext> hierarchical_net_identifier();

  class Hierarchical_variable_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_variable_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitHierarchical_variable_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Hierarchical_variable_identifierContext> hierarchical_variable_identifier();

  class Hierarchical_task_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_task_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitHierarchical_task_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Hierarchical_task_identifierContext> hierarchical_task_identifier();

  class IdentifierContext : public ParserRuleContext {
  public:
    IdentifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Simple_identifier();
    Ref<tree::TerminalNode> Escaped_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitIdentifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<IdentifierContext> identifier();

  class Inout_port_identifierContext : public ParserRuleContext {
  public:
    Inout_port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInout_port_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Inout_port_identifierContext> inout_port_identifier();

  class Input_port_identifierContext : public ParserRuleContext {
  public:
    Input_port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInput_port_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Input_port_identifierContext> input_port_identifier();

  class Instance_identifierContext : public ParserRuleContext {
  public:
    Instance_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitInstance_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Instance_identifierContext> instance_identifier();

  class Library_identifierContext : public ParserRuleContext {
  public:
    Library_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitLibrary_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Library_identifierContext> library_identifier();

  class Memory_identifierContext : public ParserRuleContext {
  public:
    Memory_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitMemory_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Memory_identifierContext> memory_identifier();

  class Module_identifierContext : public ParserRuleContext {
  public:
    Module_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_identifierContext> module_identifier();

  class Module_instance_identifierContext : public ParserRuleContext {
  public:
    Module_instance_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Arrayed_identifierContext> arrayed_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitModule_instance_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Module_instance_identifierContext> module_instance_identifier();

  class Net_identifierContext : public ParserRuleContext {
  public:
    Net_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitNet_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Net_identifierContext> net_identifier();

  class Output_port_identifierContext : public ParserRuleContext {
  public:
    Output_port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitOutput_port_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Output_port_identifierContext> output_port_identifier();

  class Parameter_identifierContext : public ParserRuleContext {
  public:
    Parameter_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitParameter_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Parameter_identifierContext> parameter_identifier();

  class Port_identifierContext : public ParserRuleContext {
  public:
    Port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitPort_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Port_identifierContext> port_identifier();

  class Real_identifierContext : public ParserRuleContext {
  public:
    Real_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitReal_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Real_identifierContext> real_identifier();

  class Simple_arrayed_identifierContext : public ParserRuleContext {
  public:
    Simple_arrayed_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Simple_identifier();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSimple_arrayed_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simple_arrayed_identifierContext> simple_arrayed_identifier();

  class Simple_hierarchical_identifierContext : public ParserRuleContext {
  public:
    Simple_hierarchical_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_hierarchical_branchContext> simple_hierarchical_branch();
    Ref<tree::TerminalNode> Escaped_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSimple_hierarchical_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simple_hierarchical_identifierContext> simple_hierarchical_identifier();

  class Specparam_identifierContext : public ParserRuleContext {
  public:
    Specparam_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSpecparam_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Specparam_identifierContext> specparam_identifier();

  class System_function_identifierContext : public ParserRuleContext {
  public:
    System_function_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Dollar_Identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSystem_function_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<System_function_identifierContext> system_function_identifier();

  class System_task_identifierContext : public ParserRuleContext {
  public:
    System_task_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Dollar_Identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSystem_task_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<System_task_identifierContext> system_task_identifier();

  class Task_identifierContext : public ParserRuleContext {
  public:
    Task_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTask_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Task_identifierContext> task_identifier();

  class Terminal_identifierContext : public ParserRuleContext {
  public:
    Terminal_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTerminal_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Terminal_identifierContext> terminal_identifier();

  class Text_macro_identifierContext : public ParserRuleContext {
  public:
    Text_macro_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Simple_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitText_macro_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Text_macro_identifierContext> text_macro_identifier();

  class Topmodule_identifierContext : public ParserRuleContext {
  public:
    Topmodule_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitTopmodule_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Topmodule_identifierContext> topmodule_identifier();

  class Udp_identifierContext : public ParserRuleContext {
  public:
    Udp_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitUdp_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Udp_identifierContext> udp_identifier();

  class Udp_instance_identifierContext : public ParserRuleContext {
  public:
    Udp_instance_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Arrayed_identifierContext> arrayed_identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitUdp_instance_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Udp_instance_identifierContext> udp_instance_identifier();

  class Variable_identifierContext : public ParserRuleContext {
  public:
    Variable_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitVariable_identifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Variable_identifierContext> variable_identifier();

  class Simple_hierarchical_branchContext : public ParserRuleContext {
  public:
    Simple_hierarchical_branchContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> Simple_identifier();
    Ref<tree::TerminalNode> Simple_identifier(int i);
    std::vector<Ref<tree::TerminalNode>> Decimal_number();
    Ref<tree::TerminalNode> Decimal_number(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitSimple_hierarchical_branch(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simple_hierarchical_branchContext> simple_hierarchical_branch();

  class Escaped_hierarchical_branchContext : public ParserRuleContext {
  public:
    Escaped_hierarchical_branchContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> Escaped_identifier();
    Ref<tree::TerminalNode> Escaped_identifier(int i);
    std::vector<Ref<tree::TerminalNode>> Decimal_number();
    Ref<tree::TerminalNode> Decimal_number(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<Verilog2001Visitor<T>*>(visitor) != nullptr)
        return ((Verilog2001Visitor<T> *)visitor)->visitEscaped_hierarchical_branch(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Escaped_hierarchical_branchContext> escaped_hierarchical_branch();


private:
  static std::vector<dfa::DFA> _decisionToDFA;
  static atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static dfa::Vocabulary _vocabulary;
  static atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace verilog
