
// Generated from sv2012.g4 by ANTLR 4.5.3

#pragma once


#include "antlr4-runtime.h"


using namespace antlr4;

namespace sv {


class sv2012Parser : public Parser {
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
    T__164 = 165, T__165 = 166, T__166 = 167, T__167 = 168, T__168 = 169, 
    T__169 = 170, T__170 = 171, T__171 = 172, T__172 = 173, T__173 = 174, 
    T__174 = 175, T__175 = 176, T__176 = 177, T__177 = 178, T__178 = 179, 
    T__179 = 180, T__180 = 181, T__181 = 182, T__182 = 183, T__183 = 184, 
    T__184 = 185, T__185 = 186, T__186 = 187, T__187 = 188, T__188 = 189, 
    T__189 = 190, T__190 = 191, T__191 = 192, T__192 = 193, T__193 = 194, 
    T__194 = 195, T__195 = 196, T__196 = 197, T__197 = 198, T__198 = 199, 
    T__199 = 200, T__200 = 201, T__201 = 202, T__202 = 203, T__203 = 204, 
    T__204 = 205, T__205 = 206, T__206 = 207, T__207 = 208, T__208 = 209, 
    T__209 = 210, T__210 = 211, T__211 = 212, T__212 = 213, T__213 = 214, 
    T__214 = 215, T__215 = 216, T__216 = 217, T__217 = 218, T__218 = 219, 
    T__219 = 220, T__220 = 221, T__221 = 222, T__222 = 223, T__223 = 224, 
    T__224 = 225, T__225 = 226, T__226 = 227, T__227 = 228, T__228 = 229, 
    T__229 = 230, T__230 = 231, T__231 = 232, T__232 = 233, T__233 = 234, 
    T__234 = 235, T__235 = 236, T__236 = 237, T__237 = 238, T__238 = 239, 
    T__239 = 240, T__240 = 241, T__241 = 242, T__242 = 243, T__243 = 244, 
    T__244 = 245, T__245 = 246, T__246 = 247, T__247 = 248, T__248 = 249, 
    T__249 = 250, T__250 = 251, T__251 = 252, T__252 = 253, T__253 = 254, 
    T__254 = 255, T__255 = 256, T__256 = 257, T__257 = 258, T__258 = 259, 
    T__259 = 260, T__260 = 261, T__261 = 262, T__262 = 263, T__263 = 264, 
    T__264 = 265, T__265 = 266, T__266 = 267, T__267 = 268, T__268 = 269, 
    T__269 = 270, T__270 = 271, T__271 = 272, T__272 = 273, T__273 = 274, 
    T__274 = 275, T__275 = 276, T__276 = 277, T__277 = 278, T__278 = 279, 
    T__279 = 280, T__280 = 281, T__281 = 282, T__282 = 283, T__283 = 284, 
    T__284 = 285, T__285 = 286, T__286 = 287, T__287 = 288, T__288 = 289, 
    T__289 = 290, T__290 = 291, T__291 = 292, T__292 = 293, T__293 = 294, 
    T__294 = 295, T__295 = 296, T__296 = 297, T__297 = 298, T__298 = 299, 
    T__299 = 300, T__300 = 301, T__301 = 302, T__302 = 303, T__303 = 304, 
    T__304 = 305, T__305 = 306, T__306 = 307, T__307 = 308, T__308 = 309, 
    T__309 = 310, T__310 = 311, File_path_spec = 312, Integral_number = 313, 
    Decimal_number = 314, Real_number = 315, Fixed_point_number = 316, Unsigned_number = 317, 
    Unbased_unsized_literal = 318, String_literal = 319, One_line_comment = 320, 
    Block_comment = 321, Escaped_identifier = 322, Simple_identifier = 323, 
    System_tf_identifier = 324, White_space = 325
  };

  enum {
    RuleLibrary_text = 0, RuleLibrary_description = 1, RuleLibrary_declaration = 2, 
    RuleInclude_statement = 3, RuleSource_text = 4, RuleDescription = 5, 
    RuleModule_nonansi_header = 6, RuleModule_ansi_header = 7, RuleModule_declaration = 8, 
    RuleModule_keyword = 9, RuleInterface_declaration = 10, RuleInterface_nonansi_header = 11, 
    RuleInterface_ansi_header = 12, RuleProgram_declaration = 13, RuleProgram_nonansi_header = 14, 
    RuleProgram_ansi_header = 15, RuleChecker_declaration = 16, RuleClass_declaration = 17, 
    RuleInterface_class_type = 18, RuleInterface_class_declaration = 19, 
    RuleInterface_class_item = 20, RuleInterface_class_method = 21, RulePackage_declaration = 22, 
    RuleTimeunits_declaration = 23, RuleParameter_port_list = 24, RuleParameter_port_declaration = 25, 
    RuleList_of_ports = 26, RuleList_of_port_declarations = 27, RulePort_declaration = 28, 
    RulePort = 29, RulePort_expression = 30, RulePort_reference = 31, RulePort_direction = 32, 
    RuleNet_port_header = 33, RuleVariable_port_header = 34, RuleInterface_port_header = 35, 
    RuleAnsi_port_declaration = 36, RuleElaboration_system_task = 37, RuleFinish_number = 38, 
    RuleModule_common_item = 39, RuleModule_item = 40, RuleModule_or_generate_item = 41, 
    RuleModule_or_generate_item_declaration = 42, RuleNon_port_module_item = 43, 
    RuleParameter_override = 44, RuleBind_directive = 45, RuleBind_target_scope = 46, 
    RuleBind_target_instance = 47, RuleBind_target_instance_list = 48, RuleBind_instantiation = 49, 
    RuleConfig_declaration = 50, RuleDesign_statement = 51, RuleConfig_rule_statement = 52, 
    RuleDefault_clause = 53, RuleInst_clause = 54, RuleInst_name = 55, RuleCell_clause = 56, 
    RuleLiblist_clause = 57, RuleUse_clause = 58, RuleInterface_or_generate_item = 59, 
    RuleExtern_tf_declaration = 60, RuleInterface_item = 61, RuleNon_port_interface_item = 62, 
    RuleProgram_item = 63, RuleNon_port_program_item = 64, RuleProgram_generate_item = 65, 
    RuleChecker_port_list = 66, RuleChecker_port_item = 67, RuleChecker_port_direction = 68, 
    RuleChecker_or_generate_item = 69, RuleChecker_or_generate_item_declaration = 70, 
    RuleChecker_generate_item = 71, RuleClass_item = 72, RuleClass_property = 73, 
    RuleClass_method = 74, RuleClass_constructor_prototype = 75, RuleClass_constraint = 76, 
    RuleClass_item_qualifier = 77, RuleProperty_qualifier = 78, RuleRandom_qualifier = 79, 
    RuleMethod_qualifier = 80, RuleMethod_prototype = 81, RuleClass_constructor_declaration = 82, 
    RuleConstraint_declaration = 83, RuleConstraint_block = 84, RuleConstraint_block_item = 85, 
    RuleSolve_before_list = 86, RuleConstraint_primary = 87, RuleConstraint_expression = 88, 
    RuleUniqueness_constraint = 89, RuleConstraint_set = 90, RuleDist_list = 91, 
    RuleDist_item = 92, RuleDist_weight = 93, RuleConstraint_prototype = 94, 
    RuleConstraint_prototype_qualifier = 95, RuleExtern_constraint_declaration = 96, 
    RuleIdentifier_list = 97, RulePackage_item = 98, RulePackage_or_generate_item_declaration = 99, 
    RuleAnonymous_program = 100, RuleAnonymous_program_item = 101, RuleLocal_parameter_declaration = 102, 
    RuleParameter_declaration = 103, RuleSpecparam_declaration = 104, RuleInout_declaration = 105, 
    RuleInput_declaration = 106, RuleOutput_declaration = 107, RuleInterface_port_declaration = 108, 
    RuleRef_declaration = 109, RuleData_declaration = 110, RulePackage_import_declaration = 111, 
    RulePackage_import_item = 112, RulePackage_export_declaration = 113, 
    RuleGenvar_declaration = 114, RuleNet_declaration = 115, RuleType_declaration = 116, 
    RuleNet_type_declaration = 117, RuleLifetime = 118, RuleCasting_type_reduced = 119, 
    RuleCasting_type = 120, RuleData_type = 121, RuleData_type_or_implicit = 122, 
    RuleImplicit_data_type = 123, RuleEnum_base_type = 124, RuleEnum_name_declaration = 125, 
    RuleClass_scope = 126, RuleClass_type = 127, RuleInteger_type = 128, 
    RuleInteger_atom_type = 129, RuleInteger_vector_type = 130, RuleNon_integer_type = 131, 
    RuleNet_type = 132, RuleNet_port_type = 133, RuleVariable_port_type = 134, 
    RuleVar_data_type = 135, RuleSigning = 136, RuleSimple_type = 137, RuleStruct_union_member = 138, 
    RuleData_type_or_void = 139, RuleStruct_union = 140, RuleType_reference = 141, 
    RuleDrive_strength = 142, RuleStrength0 = 143, RuleStrength1 = 144, 
    RuleCharge_strength = 145, RuleDelay3 = 146, RuleDelay2 = 147, RuleDelay_value = 148, 
    RuleList_of_defparam_assignments = 149, RuleList_of_genvar_identifiers = 150, 
    RuleList_of_interface_identifiers = 151, RuleList_of_net_decl_assignments = 152, 
    RuleList_of_param_assignments = 153, RuleList_of_port_identifiers = 154, 
    RuleList_of_udp_port_identifiers = 155, RuleList_of_specparam_assignments = 156, 
    RuleList_of_tf_variable_identifiers = 157, RuleList_of_type_assignments = 158, 
    RuleList_of_variable_decl_assignments = 159, RuleList_of_variable_identifiers = 160, 
    RuleList_of_variable_port_identifiers = 161, RuleDefparam_assignment = 162, 
    RuleNet_decl_assignment = 163, RuleParam_assignment = 164, RuleSpecparam_assignment = 165, 
    RuleType_assignment = 166, RulePulse_control_specparam = 167, RuleError_limit_value = 168, 
    RuleReject_limit_value = 169, RuleLimit_value = 170, RuleVariable_decl_assignment = 171, 
    RuleClass_new = 172, RuleDynamic_array_new = 173, RuleUnpacked_dimension = 174, 
    RulePacked_dimension = 175, RuleAssociative_dimension = 176, RuleVariable_dimension = 177, 
    RuleQueue_dimension = 178, RuleUnsized_dimension = 179, RuleFunction_data_type_or_implicit = 180, 
    RuleFunction_declaration = 181, RuleFunction_body_declaration = 182, 
    RuleFunction_prototype = 183, RuleDpi_import_export = 184, RuleDpi_spec_string = 185, 
    RuleDpi_function_import_property = 186, RuleDpi_task_import_property = 187, 
    RuleDpi_function_proto = 188, RuleDpi_task_proto = 189, RuleTask_declaration = 190, 
    RuleTask_body_declaration = 191, RuleTf_item_declaration = 192, RuleTf_port_list = 193, 
    RuleTf_port_item = 194, RuleTf_port_direction = 195, RuleTf_port_declaration = 196, 
    RuleTask_prototype = 197, RuleBlock_item_declaration = 198, RuleOverload_declaration = 199, 
    RuleOverload_operator = 200, RuleOverload_proto_formals = 201, RuleModport_declaration = 202, 
    RuleModport_item = 203, RuleModport_ports_declaration = 204, RuleModport_clocking_declaration = 205, 
    RuleModport_simple_ports_declaration = 206, RuleModport_simple_port = 207, 
    RuleModport_tf_ports_declaration = 208, RuleModport_tf_port = 209, RuleImport_export = 210, 
    RuleConcurrent_assertion_item = 211, RuleConcurrent_assertion_statement = 212, 
    RuleAssert_property_statement = 213, RuleAssume_property_statement = 214, 
    RuleCover_property_statement = 215, RuleExpect_property_statement = 216, 
    RuleCover_sequence_statement = 217, RuleRestrict_property_statement = 218, 
    RuleProperty_instance = 219, RuleProperty_list_of_arguments = 220, RuleProperty_actual_arg = 221, 
    RuleAssertion_item_declaration = 222, RuleProperty_declaration = 223, 
    RuleProperty_port_list = 224, RuleProperty_port_item = 225, RuleProperty_lvar_port_direction = 226, 
    RuleProperty_formal_type = 227, RuleProperty_spec = 228, RuleProperty_expr = 229, 
    RuleProperty_case_item = 230, RuleSequence_declaration = 231, RuleSequence_port_list = 232, 
    RuleSequence_port_item = 233, RuleSequence_lvar_port_direction = 234, 
    RuleSequence_formal_type = 235, RuleSequence_expr = 236, RuleCycle_delay_range = 237, 
    RuleSequence_method_call = 238, RuleSequence_match_item = 239, RuleSequence_instance = 240, 
    RuleSequence_list_of_arguments = 241, RuleSequence_actual_arg = 242, 
    RuleBoolean_abbrev = 243, RuleSequence_abbrev = 244, RuleConsecutive_repetition = 245, 
    RuleNon_consecutive_repetition = 246, RuleGoto_repetition = 247, RuleConst_or_range_expression = 248, 
    RuleCycle_delay_const_range_expression = 249, RuleExpression_or_dist = 250, 
    RuleAssertion_variable_declaration = 251, RuleLet_declaration = 252, 
    RuleLet_identifier = 253, RuleLet_port_list = 254, RuleLet_port_item = 255, 
    RuleLet_formal_type = 256, RuleLet_expression = 257, RuleLet_list_of_arguments = 258, 
    RuleLet_actual_arg = 259, RuleCovergroup_declaration = 260, RuleCoverage_spec_or_option = 261, 
    RuleCoverage_option = 262, RuleCoverage_spec = 263, RuleCoverage_event = 264, 
    RuleBlock_event_expression = 265, RuleHierarchical_btf_identifier = 266, 
    RuleCover_point = 267, RuleBins_or_empty = 268, RuleBins_or_options = 269, 
    RuleBins_keyword = 270, RuleTrans_list = 271, RuleTrans_set = 272, RuleTrans_range_list = 273, 
    RuleTrans_item = 274, RuleRepeat_range = 275, RuleCover_cross = 276, 
    RuleList_of_cross_items = 277, RuleCross_item = 278, RuleCross_body = 279, 
    RuleCross_body_item = 280, RuleBins_selection_or_option = 281, RuleBins_selection = 282, 
    RuleSelect_expression = 283, RuleSelect_condition = 284, RuleBins_expression = 285, 
    RuleCovergroup_range_list = 286, RuleCovergroup_value_range = 287, RuleWith_covergroup_expression = 288, 
    RuleSet_covergroup_expression = 289, RuleInteger_covergroup_expression = 290, 
    RuleCross_set_expression = 291, RuleCovergroup_expression = 292, RuleGate_instantiation = 293, 
    RuleCmos_switch_instance = 294, RuleEnable_gate_instance = 295, RuleMos_switch_instance = 296, 
    RuleN_input_gate_instance = 297, RuleN_output_gate_instance = 298, RulePass_switch_instance = 299, 
    RulePass_enable_switch_instance = 300, RulePull_gate_instance = 301, 
    RulePulldown_strength = 302, RulePullup_strength = 303, RuleEnable_terminal = 304, 
    RuleInout_terminal = 305, RuleInput_terminal = 306, RuleNcontrol_terminal = 307, 
    RuleOutput_terminal = 308, RulePcontrol_terminal = 309, RuleCmos_switchtype = 310, 
    RuleEnable_gatetype = 311, RuleMos_switchtype = 312, RuleN_input_gatetype = 313, 
    RuleN_output_gatetype = 314, RulePass_en_switchtype = 315, RulePass_switchtype = 316, 
    RuleModule_instantiation = 317, RuleParameter_value_assignment = 318, 
    RuleList_of_parameter_assignments = 319, RuleOrdered_parameter_assignment = 320, 
    RuleNamed_parameter_assignment = 321, RuleHierarchical_instance = 322, 
    RuleName_of_instance = 323, RuleList_of_port_connections = 324, RuleOrdered_port_connection = 325, 
    RuleNamed_port_connection = 326, RuleInterface_instantiation = 327, 
    RuleProgram_instantiation = 328, RuleChecker_instantiation = 329, RuleList_of_checker_port_connections = 330, 
    RuleOrdered_checker_port_connection = 331, RuleNamed_checker_port_connection = 332, 
    RuleGenerate_region = 333, RuleLoop_generate_construct = 334, RuleGenvar_initialization = 335, 
    RuleGenvar_iteration = 336, RuleConditional_generate_construct = 337, 
    RuleIf_generate_construct = 338, RuleCase_generate_construct = 339, 
    RuleCase_generate_item = 340, RuleGenerate_block = 341, RuleGenerate_item = 342, 
    RuleUdp_nonansi_declaration = 343, RuleUdp_ansi_declaration = 344, RuleUdp_declaration = 345, 
    RuleUdp_port_list = 346, RuleUdp_declaration_port_list = 347, RuleUdp_port_declaration = 348, 
    RuleUdp_output_declaration = 349, RuleUdp_input_declaration = 350, RuleUdp_reg_declaration = 351, 
    RuleUdp_body = 352, RuleCombinational_body = 353, RuleCombinational_entry = 354, 
    RuleSequential_body = 355, RuleUdp_initial_statement = 356, RuleInit_val = 357, 
    RuleSequential_entry = 358, RuleSeq_input_list = 359, RuleLevel_input_list = 360, 
    RuleEdge_input_list = 361, RuleEdge_indicator = 362, RuleCurrent_state = 363, 
    RuleNext_state = 364, RuleOutput_symbol = 365, RuleLevel_symbol = 366, 
    RuleEdge_symbol = 367, RuleUdp_instantiation = 368, RuleUdp_instance = 369, 
    RuleContinuous_assign = 370, RuleList_of_net_assignments = 371, RuleList_of_variable_assignments = 372, 
    RuleNet_alias = 373, RuleNet_assignment = 374, RuleInitial_construct = 375, 
    RuleAlways_construct = 376, RuleAlways_keyword = 377, RuleFinal_construct = 378, 
    RuleBlocking_assignment = 379, RuleOperator_assignment = 380, RuleAssignment_operator = 381, 
    RuleNonblocking_assignment = 382, RuleProcedural_continuous_assignment = 383, 
    RuleVariable_assignment = 384, RuleAction_block = 385, RuleSeq_block = 386, 
    RulePar_block = 387, RuleJoin_keyword = 388, RuleStatement_or_null = 389, 
    RuleStatement = 390, RuleStatement_item = 391, RuleFunction_statement = 392, 
    RuleFunction_statement_or_null = 393, RuleVariable_identifier_list = 394, 
    RuleProcedural_timing_control_statement = 395, RuleDelay_or_event_control = 396, 
    RuleDelay_control = 397, RuleEvent_control = 398, RuleEvent_expression = 399, 
    RuleProcedural_timing_control = 400, RuleJump_statement = 401, RuleWait_statement = 402, 
    RuleEvent_trigger = 403, RuleDisable_statement = 404, RuleConditional_statement = 405, 
    RuleUnique_priority = 406, RuleCond_predicate = 407, RuleExpression_or_cond_pattern = 408, 
    RuleCond_pattern = 409, RuleCase_statement = 410, RuleCase_keyword = 411, 
    RuleCase_expression = 412, RuleCase_item = 413, RuleCase_pattern_item = 414, 
    RuleCase_inside_item = 415, RuleCase_item_expression = 416, RuleRandcase_statement = 417, 
    RuleRandcase_item = 418, RuleOpen_range_list = 419, RuleOpen_value_range = 420, 
    RulePattern = 421, RuleAssignment_pattern = 422, RuleStructure_pattern_key = 423, 
    RuleArray_pattern_key = 424, RuleAssignment_pattern_key = 425, RuleAssignment_pattern_expression = 426, 
    RuleAssignment_pattern_expression_type = 427, RuleConstant_assignment_pattern_expression = 428, 
    RuleAssignment_pattern_net_lvalue = 429, RuleAssignment_pattern_variable_lvalue = 430, 
    RuleLoop_statement = 431, RuleFor_initialization = 432, RuleFor_variable_declaration = 433, 
    RuleFor_step = 434, RuleFor_step_assignment = 435, RuleLoop_variables = 436, 
    RuleSubroutine_call_statement = 437, RuleAssertion_item = 438, RuleDeferred_immediate_assertion_item = 439, 
    RuleProcedural_assertion_statement = 440, RuleImmediate_assertion_statement = 441, 
    RuleSimple_immediate_assertion_statement = 442, RuleSimple_immediate_assert_statement = 443, 
    RuleSimple_immediate_assume_statement = 444, RuleSimple_immediate_cover_statement = 445, 
    RuleDeferred_immediate_assertion_statement = 446, RuleDeferred_immediate_assert_statement = 447, 
    RuleDeferred_immediate_assume_statement = 448, RuleDeferred_immediate_cover_statement = 449, 
    RuleClocking_declaration = 450, RuleClocking_event = 451, RuleClocking_item = 452, 
    RuleDefault_skew = 453, RuleClocking_direction = 454, RuleList_of_clocking_decl_assign = 455, 
    RuleClocking_decl_assign = 456, RuleClocking_skew = 457, RuleClocking_drive = 458, 
    RuleCycle_delay = 459, RuleClockvar = 460, RuleClockvar_expression = 461, 
    RuleRandsequence_statement = 462, RuleProduction = 463, RuleRs_rule = 464, 
    RuleRs_production_list = 465, RuleWeight_specification = 466, RuleRs_code_block = 467, 
    RuleRs_prod = 468, RuleProduction_item = 469, RuleRs_if_else = 470, 
    RuleRs_repeat = 471, RuleRs_case = 472, RuleRs_case_item = 473, RuleSpecify_block = 474, 
    RuleSpecify_item = 475, RulePulsestyle_declaration = 476, RuleShowcancelled_declaration = 477, 
    RulePath_declaration = 478, RuleSimple_path_declaration = 479, RuleParallel_path_description = 480, 
    RuleFull_path_description = 481, RuleList_of_path_inputs = 482, RuleList_of_path_outputs = 483, 
    RuleSpecify_input_terminal_descriptor = 484, RuleSpecify_output_terminal_descriptor = 485, 
    RuleInput_identifier = 486, RuleOutput_identifier = 487, RulePath_delay_value = 488, 
    RuleList_of_path_delay_expressions = 489, RuleT_path_delay_expression = 490, 
    RuleTrise_path_delay_expression = 491, RuleTfall_path_delay_expression = 492, 
    RuleTz_path_delay_expression = 493, RuleT01_path_delay_expression = 494, 
    RuleT10_path_delay_expression = 495, RuleT0z_path_delay_expression = 496, 
    RuleTz1_path_delay_expression = 497, RuleT1z_path_delay_expression = 498, 
    RuleTz0_path_delay_expression = 499, RuleT0x_path_delay_expression = 500, 
    RuleTx1_path_delay_expression = 501, RuleT1x_path_delay_expression = 502, 
    RuleTx0_path_delay_expression = 503, RuleTxz_path_delay_expression = 504, 
    RuleTzx_path_delay_expression = 505, RulePath_delay_expression = 506, 
    RuleEdge_sensitive_path_declaration = 507, RuleParallel_edge_sensitive_path_description = 508, 
    RuleFull_edge_sensitive_path_description = 509, RuleData_source_expression = 510, 
    RuleEdge_identifier = 511, RuleState_dependent_path_declaration = 512, 
    RulePolarity_operator = 513, RuleSystem_timing_check = 514, RuleSetup_timing_check = 515, 
    RuleHold_timing_check = 516, RuleSetuphold_timing_check = 517, RuleRecovery_timing_check = 518, 
    RuleRemoval_timing_check = 519, RuleRecrem_timing_check = 520, RuleSkew_timing_check = 521, 
    RuleTimeskew_timing_check = 522, RuleFullskew_timing_check = 523, RulePeriod_timing_check = 524, 
    RuleWidth_timing_check = 525, RuleNochange_timing_check = 526, RuleTimecheck_condition = 527, 
    RuleControlled_reference_event = 528, RuleData_event = 529, RuleDelayed_data = 530, 
    RuleDelayed_reference = 531, RuleEnd_edge_offset = 532, RuleEvent_based_flag = 533, 
    RuleNotifier = 534, RuleReference_event = 535, RuleRemain_active_flag = 536, 
    RuleTimestamp_condition = 537, RuleStart_edge_offset = 538, RuleThreshold = 539, 
    RuleTiming_check_limit = 540, RuleTiming_check_event = 541, RuleControlled_timing_check_event = 542, 
    RuleTiming_check_event_control = 543, RuleSpecify_terminal_descriptor = 544, 
    RuleEdge_control_specifier = 545, RuleEdge_descriptor = 546, RuleTiming_check_condition = 547, 
    RuleScalar_timing_check_condition = 548, RuleScalar_constant = 549, 
    RuleConcatenation = 550, RuleConstant_concatenation = 551, RuleConstant_multiple_concatenation = 552, 
    RuleModule_path_concatenation = 553, RuleModule_path_multiple_concatenation = 554, 
    RuleMultiple_concatenation = 555, RuleStreaming_concatenation = 556, 
    RuleStream_operator = 557, RuleSlice_size = 558, RuleStream_concatenation = 559, 
    RuleStream_expression = 560, RuleArray_range_expression = 561, RuleEmpty_queue = 562, 
    RuleConstant_function_call = 563, RuleTf_call = 564, RuleSystem_tf_call = 565, 
    RuleFunction_subroutine_call = 566, RuleSubroutine_call = 567, RuleMethod_call = 568, 
    RuleMethod_call_root = 569, RuleList_of_arguments = 570, RuleMethod_call_body = 571, 
    RuleBuilt_in_method_call = 572, RuleArray_manipulation_call = 573, RuleRandomize_call = 574, 
    RuleArray_method_name = 575, RuleInc_or_dec_expression = 576, RuleConditional_expression = 577, 
    RuleConstant_expression = 578, RuleConstant_mintypmax_expression = 579, 
    RuleConstant_param_expression = 580, RuleParam_expression = 581, RuleConstant_range_expression = 582, 
    RuleConstant_part_select_range = 583, RuleConstant_range = 584, RuleConstant_indexed_range = 585, 
    RuleExpression_cond_or_inside = 586, RuleExpression = 587, RuleTagged_union_expression = 588, 
    RuleInside_expression = 589, RuleValue_range = 590, RuleMintypmax_expression = 591, 
    RuleModule_path_conditional_expression = 592, RuleModule_path_expression = 593, 
    RuleModule_path_mintypmax_expression = 594, RulePart_select_range = 595, 
    RuleIndexed_range = 596, RuleGenvar_expression = 597, RuleConstant_primary = 598, 
    RuleModule_path_primary = 599, RulePrimary = 600, RuleClass_qualifier = 601, 
    RuleRange_expression = 602, RulePrimary_literal = 603, RuleTime_literal = 604, 
    RuleTime_unit = 605, RuleImplicit_class_handle = 606, RuleBit_select = 607, 
    RuleSelect = 608, RuleNonrange_select = 609, RuleConstant_bit_select = 610, 
    RuleConstant_select = 611, RuleConstant_cast = 612, RuleConstant_let_expression = 613, 
    RuleCast = 614, RuleNet_lvalue = 615, RuleVariable_lvalue = 616, RuleNonrange_variable_lvalue = 617, 
    RuleUnary_operator = 618, RuleBinary_operator = 619, RuleInc_or_dec_operator = 620, 
    RuleUnary_module_path_operator = 621, RuleBinary_module_path_operator = 622, 
    RuleNumber = 623, RuleAttribute_instance = 624, RuleAttr_spec = 625, 
    RuleAttr_name = 626, RuleArray_identifier = 627, RuleBlock_identifier = 628, 
    RuleBin_identifier = 629, RuleC_identifier = 630, RuleCell_identifier = 631, 
    RuleChecker_identifier = 632, RuleClass_identifier = 633, RuleClass_variable_identifier = 634, 
    RuleClocking_identifier = 635, RuleConfig_identifier = 636, RuleConst_identifier = 637, 
    RuleConstraint_identifier = 638, RuleCovergroup_identifier = 639, RuleCovergroup_variable_identifier = 640, 
    RuleCover_point_identifier = 641, RuleCross_identifier = 642, RuleDynamic_array_variable_identifier = 643, 
    RuleEnum_identifier = 644, RuleFormal_identifier = 645, RuleFormal_port_identifier = 646, 
    RuleFunction_identifier = 647, RuleGenerate_block_identifier = 648, 
    RuleGenvar_identifier = 649, RuleHierarchical_array_identifier = 650, 
    RuleHierarchical_block_identifier = 651, RuleHierarchical_event_identifier = 652, 
    RuleHierarchical_identifier = 653, RuleHierarchical_net_identifier = 654, 
    RuleHierarchical_parameter_identifier = 655, RuleHierarchical_property_identifier = 656, 
    RuleHierarchical_sequence_identifier = 657, RuleHierarchical_task_identifier = 658, 
    RuleHierarchical_tf_identifier = 659, RuleHierarchical_variable_identifier = 660, 
    RuleIdentifier = 661, RuleIndex_variable_identifier = 662, RuleInterface_identifier = 663, 
    RuleInterface_instance_identifier = 664, RuleInout_port_identifier = 665, 
    RuleInput_port_identifier = 666, RuleInstance_identifier = 667, RuleLibrary_identifier = 668, 
    RuleMember_identifier = 669, RuleMethod_identifier = 670, RuleModport_identifier = 671, 
    RuleModule_identifier = 672, RuleNet_identifier = 673, RuleNet_type_identifier = 674, 
    RuleOutput_port_identifier = 675, RulePackage_identifier = 676, RulePackage_scope = 677, 
    RuleParameter_identifier = 678, RulePort_identifier = 679, RuleProduction_identifier = 680, 
    RuleProgram_identifier = 681, RuleProperty_identifier = 682, RulePs_class_identifier = 683, 
    RulePs_covergroup_identifier = 684, RulePs_checker_identifier = 685, 
    RulePs_identifier = 686, RulePs_or_hierarchical_array_identifier = 687, 
    RulePs_or_hierarchical_net_identifier = 688, RulePs_or_hierarchical_property_identifier = 689, 
    RulePs_or_hierarchical_sequence_identifier = 690, RulePs_or_hierarchical_tf_identifier = 691, 
    RulePs_parameter_identifier = 692, RulePs_type_identifier = 693, RuleSequence_identifier = 694, 
    RuleSignal_identifier = 695, RuleSpecparam_identifier = 696, RuleTask_identifier = 697, 
    RuleTf_identifier = 698, RuleTerminal_identifier = 699, RuleTopmodule_identifier = 700, 
    RuleType_identifier = 701, RuleUdp_identifier = 702, RuleVariable_identifier = 703
  };

  sv2012Parser(TokenStream *input);
  ~sv2012Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual dfa::Vocabulary& getVocabulary() const override;


  class Library_textContext;
  class Library_descriptionContext;
  class Library_declarationContext;
  class Include_statementContext;
  class Source_textContext;
  class DescriptionContext;
  class Module_nonansi_headerContext;
  class Module_ansi_headerContext;
  class Module_declarationContext;
  class Module_keywordContext;
  class Interface_declarationContext;
  class Interface_nonansi_headerContext;
  class Interface_ansi_headerContext;
  class Program_declarationContext;
  class Program_nonansi_headerContext;
  class Program_ansi_headerContext;
  class Checker_declarationContext;
  class Class_declarationContext;
  class Interface_class_typeContext;
  class Interface_class_declarationContext;
  class Interface_class_itemContext;
  class Interface_class_methodContext;
  class Package_declarationContext;
  class Timeunits_declarationContext;
  class Parameter_port_listContext;
  class Parameter_port_declarationContext;
  class List_of_portsContext;
  class List_of_port_declarationsContext;
  class Port_declarationContext;
  class PortContext;
  class Port_expressionContext;
  class Port_referenceContext;
  class Port_directionContext;
  class Net_port_headerContext;
  class Variable_port_headerContext;
  class Interface_port_headerContext;
  class Ansi_port_declarationContext;
  class Elaboration_system_taskContext;
  class Finish_numberContext;
  class Module_common_itemContext;
  class Module_itemContext;
  class Module_or_generate_itemContext;
  class Module_or_generate_item_declarationContext;
  class Non_port_module_itemContext;
  class Parameter_overrideContext;
  class Bind_directiveContext;
  class Bind_target_scopeContext;
  class Bind_target_instanceContext;
  class Bind_target_instance_listContext;
  class Bind_instantiationContext;
  class Config_declarationContext;
  class Design_statementContext;
  class Config_rule_statementContext;
  class Default_clauseContext;
  class Inst_clauseContext;
  class Inst_nameContext;
  class Cell_clauseContext;
  class Liblist_clauseContext;
  class Use_clauseContext;
  class Interface_or_generate_itemContext;
  class Extern_tf_declarationContext;
  class Interface_itemContext;
  class Non_port_interface_itemContext;
  class Program_itemContext;
  class Non_port_program_itemContext;
  class Program_generate_itemContext;
  class Checker_port_listContext;
  class Checker_port_itemContext;
  class Checker_port_directionContext;
  class Checker_or_generate_itemContext;
  class Checker_or_generate_item_declarationContext;
  class Checker_generate_itemContext;
  class Class_itemContext;
  class Class_propertyContext;
  class Class_methodContext;
  class Class_constructor_prototypeContext;
  class Class_constraintContext;
  class Class_item_qualifierContext;
  class Property_qualifierContext;
  class Random_qualifierContext;
  class Method_qualifierContext;
  class Method_prototypeContext;
  class Class_constructor_declarationContext;
  class Constraint_declarationContext;
  class Constraint_blockContext;
  class Constraint_block_itemContext;
  class Solve_before_listContext;
  class Constraint_primaryContext;
  class Constraint_expressionContext;
  class Uniqueness_constraintContext;
  class Constraint_setContext;
  class Dist_listContext;
  class Dist_itemContext;
  class Dist_weightContext;
  class Constraint_prototypeContext;
  class Constraint_prototype_qualifierContext;
  class Extern_constraint_declarationContext;
  class Identifier_listContext;
  class Package_itemContext;
  class Package_or_generate_item_declarationContext;
  class Anonymous_programContext;
  class Anonymous_program_itemContext;
  class Local_parameter_declarationContext;
  class Parameter_declarationContext;
  class Specparam_declarationContext;
  class Inout_declarationContext;
  class Input_declarationContext;
  class Output_declarationContext;
  class Interface_port_declarationContext;
  class Ref_declarationContext;
  class Data_declarationContext;
  class Package_import_declarationContext;
  class Package_import_itemContext;
  class Package_export_declarationContext;
  class Genvar_declarationContext;
  class Net_declarationContext;
  class Type_declarationContext;
  class Net_type_declarationContext;
  class LifetimeContext;
  class Casting_type_reducedContext;
  class Casting_typeContext;
  class Data_typeContext;
  class Data_type_or_implicitContext;
  class Implicit_data_typeContext;
  class Enum_base_typeContext;
  class Enum_name_declarationContext;
  class Class_scopeContext;
  class Class_typeContext;
  class Integer_typeContext;
  class Integer_atom_typeContext;
  class Integer_vector_typeContext;
  class Non_integer_typeContext;
  class Net_typeContext;
  class Net_port_typeContext;
  class Variable_port_typeContext;
  class Var_data_typeContext;
  class SigningContext;
  class Simple_typeContext;
  class Struct_union_memberContext;
  class Data_type_or_voidContext;
  class Struct_unionContext;
  class Type_referenceContext;
  class Drive_strengthContext;
  class Strength0Context;
  class Strength1Context;
  class Charge_strengthContext;
  class Delay3Context;
  class Delay2Context;
  class Delay_valueContext;
  class List_of_defparam_assignmentsContext;
  class List_of_genvar_identifiersContext;
  class List_of_interface_identifiersContext;
  class List_of_net_decl_assignmentsContext;
  class List_of_param_assignmentsContext;
  class List_of_port_identifiersContext;
  class List_of_udp_port_identifiersContext;
  class List_of_specparam_assignmentsContext;
  class List_of_tf_variable_identifiersContext;
  class List_of_type_assignmentsContext;
  class List_of_variable_decl_assignmentsContext;
  class List_of_variable_identifiersContext;
  class List_of_variable_port_identifiersContext;
  class Defparam_assignmentContext;
  class Net_decl_assignmentContext;
  class Param_assignmentContext;
  class Specparam_assignmentContext;
  class Type_assignmentContext;
  class Pulse_control_specparamContext;
  class Error_limit_valueContext;
  class Reject_limit_valueContext;
  class Limit_valueContext;
  class Variable_decl_assignmentContext;
  class Class_newContext;
  class Dynamic_array_newContext;
  class Unpacked_dimensionContext;
  class Packed_dimensionContext;
  class Associative_dimensionContext;
  class Variable_dimensionContext;
  class Queue_dimensionContext;
  class Unsized_dimensionContext;
  class Function_data_type_or_implicitContext;
  class Function_declarationContext;
  class Function_body_declarationContext;
  class Function_prototypeContext;
  class Dpi_import_exportContext;
  class Dpi_spec_stringContext;
  class Dpi_function_import_propertyContext;
  class Dpi_task_import_propertyContext;
  class Dpi_function_protoContext;
  class Dpi_task_protoContext;
  class Task_declarationContext;
  class Task_body_declarationContext;
  class Tf_item_declarationContext;
  class Tf_port_listContext;
  class Tf_port_itemContext;
  class Tf_port_directionContext;
  class Tf_port_declarationContext;
  class Task_prototypeContext;
  class Block_item_declarationContext;
  class Overload_declarationContext;
  class Overload_operatorContext;
  class Overload_proto_formalsContext;
  class Modport_declarationContext;
  class Modport_itemContext;
  class Modport_ports_declarationContext;
  class Modport_clocking_declarationContext;
  class Modport_simple_ports_declarationContext;
  class Modport_simple_portContext;
  class Modport_tf_ports_declarationContext;
  class Modport_tf_portContext;
  class Import_exportContext;
  class Concurrent_assertion_itemContext;
  class Concurrent_assertion_statementContext;
  class Assert_property_statementContext;
  class Assume_property_statementContext;
  class Cover_property_statementContext;
  class Expect_property_statementContext;
  class Cover_sequence_statementContext;
  class Restrict_property_statementContext;
  class Property_instanceContext;
  class Property_list_of_argumentsContext;
  class Property_actual_argContext;
  class Assertion_item_declarationContext;
  class Property_declarationContext;
  class Property_port_listContext;
  class Property_port_itemContext;
  class Property_lvar_port_directionContext;
  class Property_formal_typeContext;
  class Property_specContext;
  class Property_exprContext;
  class Property_case_itemContext;
  class Sequence_declarationContext;
  class Sequence_port_listContext;
  class Sequence_port_itemContext;
  class Sequence_lvar_port_directionContext;
  class Sequence_formal_typeContext;
  class Sequence_exprContext;
  class Cycle_delay_rangeContext;
  class Sequence_method_callContext;
  class Sequence_match_itemContext;
  class Sequence_instanceContext;
  class Sequence_list_of_argumentsContext;
  class Sequence_actual_argContext;
  class Boolean_abbrevContext;
  class Sequence_abbrevContext;
  class Consecutive_repetitionContext;
  class Non_consecutive_repetitionContext;
  class Goto_repetitionContext;
  class Const_or_range_expressionContext;
  class Cycle_delay_const_range_expressionContext;
  class Expression_or_distContext;
  class Assertion_variable_declarationContext;
  class Let_declarationContext;
  class Let_identifierContext;
  class Let_port_listContext;
  class Let_port_itemContext;
  class Let_formal_typeContext;
  class Let_expressionContext;
  class Let_list_of_argumentsContext;
  class Let_actual_argContext;
  class Covergroup_declarationContext;
  class Coverage_spec_or_optionContext;
  class Coverage_optionContext;
  class Coverage_specContext;
  class Coverage_eventContext;
  class Block_event_expressionContext;
  class Hierarchical_btf_identifierContext;
  class Cover_pointContext;
  class Bins_or_emptyContext;
  class Bins_or_optionsContext;
  class Bins_keywordContext;
  class Trans_listContext;
  class Trans_setContext;
  class Trans_range_listContext;
  class Trans_itemContext;
  class Repeat_rangeContext;
  class Cover_crossContext;
  class List_of_cross_itemsContext;
  class Cross_itemContext;
  class Cross_bodyContext;
  class Cross_body_itemContext;
  class Bins_selection_or_optionContext;
  class Bins_selectionContext;
  class Select_expressionContext;
  class Select_conditionContext;
  class Bins_expressionContext;
  class Covergroup_range_listContext;
  class Covergroup_value_rangeContext;
  class With_covergroup_expressionContext;
  class Set_covergroup_expressionContext;
  class Integer_covergroup_expressionContext;
  class Cross_set_expressionContext;
  class Covergroup_expressionContext;
  class Gate_instantiationContext;
  class Cmos_switch_instanceContext;
  class Enable_gate_instanceContext;
  class Mos_switch_instanceContext;
  class N_input_gate_instanceContext;
  class N_output_gate_instanceContext;
  class Pass_switch_instanceContext;
  class Pass_enable_switch_instanceContext;
  class Pull_gate_instanceContext;
  class Pulldown_strengthContext;
  class Pullup_strengthContext;
  class Enable_terminalContext;
  class Inout_terminalContext;
  class Input_terminalContext;
  class Ncontrol_terminalContext;
  class Output_terminalContext;
  class Pcontrol_terminalContext;
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
  class Hierarchical_instanceContext;
  class Name_of_instanceContext;
  class List_of_port_connectionsContext;
  class Ordered_port_connectionContext;
  class Named_port_connectionContext;
  class Interface_instantiationContext;
  class Program_instantiationContext;
  class Checker_instantiationContext;
  class List_of_checker_port_connectionsContext;
  class Ordered_checker_port_connectionContext;
  class Named_checker_port_connectionContext;
  class Generate_regionContext;
  class Loop_generate_constructContext;
  class Genvar_initializationContext;
  class Genvar_iterationContext;
  class Conditional_generate_constructContext;
  class If_generate_constructContext;
  class Case_generate_constructContext;
  class Case_generate_itemContext;
  class Generate_blockContext;
  class Generate_itemContext;
  class Udp_nonansi_declarationContext;
  class Udp_ansi_declarationContext;
  class Udp_declarationContext;
  class Udp_port_listContext;
  class Udp_declaration_port_listContext;
  class Udp_port_declarationContext;
  class Udp_output_declarationContext;
  class Udp_input_declarationContext;
  class Udp_reg_declarationContext;
  class Udp_bodyContext;
  class Combinational_bodyContext;
  class Combinational_entryContext;
  class Sequential_bodyContext;
  class Udp_initial_statementContext;
  class Init_valContext;
  class Sequential_entryContext;
  class Seq_input_listContext;
  class Level_input_listContext;
  class Edge_input_listContext;
  class Edge_indicatorContext;
  class Current_stateContext;
  class Next_stateContext;
  class Output_symbolContext;
  class Level_symbolContext;
  class Edge_symbolContext;
  class Udp_instantiationContext;
  class Udp_instanceContext;
  class Continuous_assignContext;
  class List_of_net_assignmentsContext;
  class List_of_variable_assignmentsContext;
  class Net_aliasContext;
  class Net_assignmentContext;
  class Initial_constructContext;
  class Always_constructContext;
  class Always_keywordContext;
  class Final_constructContext;
  class Blocking_assignmentContext;
  class Operator_assignmentContext;
  class Assignment_operatorContext;
  class Nonblocking_assignmentContext;
  class Procedural_continuous_assignmentContext;
  class Variable_assignmentContext;
  class Action_blockContext;
  class Seq_blockContext;
  class Par_blockContext;
  class Join_keywordContext;
  class Statement_or_nullContext;
  class StatementContext;
  class Statement_itemContext;
  class Function_statementContext;
  class Function_statement_or_nullContext;
  class Variable_identifier_listContext;
  class Procedural_timing_control_statementContext;
  class Delay_or_event_controlContext;
  class Delay_controlContext;
  class Event_controlContext;
  class Event_expressionContext;
  class Procedural_timing_controlContext;
  class Jump_statementContext;
  class Wait_statementContext;
  class Event_triggerContext;
  class Disable_statementContext;
  class Conditional_statementContext;
  class Unique_priorityContext;
  class Cond_predicateContext;
  class Expression_or_cond_patternContext;
  class Cond_patternContext;
  class Case_statementContext;
  class Case_keywordContext;
  class Case_expressionContext;
  class Case_itemContext;
  class Case_pattern_itemContext;
  class Case_inside_itemContext;
  class Case_item_expressionContext;
  class Randcase_statementContext;
  class Randcase_itemContext;
  class Open_range_listContext;
  class Open_value_rangeContext;
  class PatternContext;
  class Assignment_patternContext;
  class Structure_pattern_keyContext;
  class Array_pattern_keyContext;
  class Assignment_pattern_keyContext;
  class Assignment_pattern_expressionContext;
  class Assignment_pattern_expression_typeContext;
  class Constant_assignment_pattern_expressionContext;
  class Assignment_pattern_net_lvalueContext;
  class Assignment_pattern_variable_lvalueContext;
  class Loop_statementContext;
  class For_initializationContext;
  class For_variable_declarationContext;
  class For_stepContext;
  class For_step_assignmentContext;
  class Loop_variablesContext;
  class Subroutine_call_statementContext;
  class Assertion_itemContext;
  class Deferred_immediate_assertion_itemContext;
  class Procedural_assertion_statementContext;
  class Immediate_assertion_statementContext;
  class Simple_immediate_assertion_statementContext;
  class Simple_immediate_assert_statementContext;
  class Simple_immediate_assume_statementContext;
  class Simple_immediate_cover_statementContext;
  class Deferred_immediate_assertion_statementContext;
  class Deferred_immediate_assert_statementContext;
  class Deferred_immediate_assume_statementContext;
  class Deferred_immediate_cover_statementContext;
  class Clocking_declarationContext;
  class Clocking_eventContext;
  class Clocking_itemContext;
  class Default_skewContext;
  class Clocking_directionContext;
  class List_of_clocking_decl_assignContext;
  class Clocking_decl_assignContext;
  class Clocking_skewContext;
  class Clocking_driveContext;
  class Cycle_delayContext;
  class ClockvarContext;
  class Clockvar_expressionContext;
  class Randsequence_statementContext;
  class ProductionContext;
  class Rs_ruleContext;
  class Rs_production_listContext;
  class Weight_specificationContext;
  class Rs_code_blockContext;
  class Rs_prodContext;
  class Production_itemContext;
  class Rs_if_elseContext;
  class Rs_repeatContext;
  class Rs_caseContext;
  class Rs_case_itemContext;
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
  class System_timing_checkContext;
  class Setup_timing_checkContext;
  class Hold_timing_checkContext;
  class Setuphold_timing_checkContext;
  class Recovery_timing_checkContext;
  class Removal_timing_checkContext;
  class Recrem_timing_checkContext;
  class Skew_timing_checkContext;
  class Timeskew_timing_checkContext;
  class Fullskew_timing_checkContext;
  class Period_timing_checkContext;
  class Width_timing_checkContext;
  class Nochange_timing_checkContext;
  class Timecheck_conditionContext;
  class Controlled_reference_eventContext;
  class Data_eventContext;
  class Delayed_dataContext;
  class Delayed_referenceContext;
  class End_edge_offsetContext;
  class Event_based_flagContext;
  class NotifierContext;
  class Reference_eventContext;
  class Remain_active_flagContext;
  class Timestamp_conditionContext;
  class Start_edge_offsetContext;
  class ThresholdContext;
  class Timing_check_limitContext;
  class Timing_check_eventContext;
  class Controlled_timing_check_eventContext;
  class Timing_check_event_controlContext;
  class Specify_terminal_descriptorContext;
  class Edge_control_specifierContext;
  class Edge_descriptorContext;
  class Timing_check_conditionContext;
  class Scalar_timing_check_conditionContext;
  class Scalar_constantContext;
  class ConcatenationContext;
  class Constant_concatenationContext;
  class Constant_multiple_concatenationContext;
  class Module_path_concatenationContext;
  class Module_path_multiple_concatenationContext;
  class Multiple_concatenationContext;
  class Streaming_concatenationContext;
  class Stream_operatorContext;
  class Slice_sizeContext;
  class Stream_concatenationContext;
  class Stream_expressionContext;
  class Array_range_expressionContext;
  class Empty_queueContext;
  class Constant_function_callContext;
  class Tf_callContext;
  class System_tf_callContext;
  class Function_subroutine_callContext;
  class Subroutine_callContext;
  class Method_callContext;
  class Method_call_rootContext;
  class List_of_argumentsContext;
  class Method_call_bodyContext;
  class Built_in_method_callContext;
  class Array_manipulation_callContext;
  class Randomize_callContext;
  class Array_method_nameContext;
  class Inc_or_dec_expressionContext;
  class Conditional_expressionContext;
  class Constant_expressionContext;
  class Constant_mintypmax_expressionContext;
  class Constant_param_expressionContext;
  class Param_expressionContext;
  class Constant_range_expressionContext;
  class Constant_part_select_rangeContext;
  class Constant_rangeContext;
  class Constant_indexed_rangeContext;
  class Expression_cond_or_insideContext;
  class ExpressionContext;
  class Tagged_union_expressionContext;
  class Inside_expressionContext;
  class Value_rangeContext;
  class Mintypmax_expressionContext;
  class Module_path_conditional_expressionContext;
  class Module_path_expressionContext;
  class Module_path_mintypmax_expressionContext;
  class Part_select_rangeContext;
  class Indexed_rangeContext;
  class Genvar_expressionContext;
  class Constant_primaryContext;
  class Module_path_primaryContext;
  class PrimaryContext;
  class Class_qualifierContext;
  class Range_expressionContext;
  class Primary_literalContext;
  class Time_literalContext;
  class Time_unitContext;
  class Implicit_class_handleContext;
  class Bit_selectContext;
  class SelectContext;
  class Nonrange_selectContext;
  class Constant_bit_selectContext;
  class Constant_selectContext;
  class Constant_castContext;
  class Constant_let_expressionContext;
  class CastContext;
  class Net_lvalueContext;
  class Variable_lvalueContext;
  class Nonrange_variable_lvalueContext;
  class Unary_operatorContext;
  class Binary_operatorContext;
  class Inc_or_dec_operatorContext;
  class Unary_module_path_operatorContext;
  class Binary_module_path_operatorContext;
  class NumberContext;
  class Attribute_instanceContext;
  class Attr_specContext;
  class Attr_nameContext;
  class Array_identifierContext;
  class Block_identifierContext;
  class Bin_identifierContext;
  class C_identifierContext;
  class Cell_identifierContext;
  class Checker_identifierContext;
  class Class_identifierContext;
  class Class_variable_identifierContext;
  class Clocking_identifierContext;
  class Config_identifierContext;
  class Const_identifierContext;
  class Constraint_identifierContext;
  class Covergroup_identifierContext;
  class Covergroup_variable_identifierContext;
  class Cover_point_identifierContext;
  class Cross_identifierContext;
  class Dynamic_array_variable_identifierContext;
  class Enum_identifierContext;
  class Formal_identifierContext;
  class Formal_port_identifierContext;
  class Function_identifierContext;
  class Generate_block_identifierContext;
  class Genvar_identifierContext;
  class Hierarchical_array_identifierContext;
  class Hierarchical_block_identifierContext;
  class Hierarchical_event_identifierContext;
  class Hierarchical_identifierContext;
  class Hierarchical_net_identifierContext;
  class Hierarchical_parameter_identifierContext;
  class Hierarchical_property_identifierContext;
  class Hierarchical_sequence_identifierContext;
  class Hierarchical_task_identifierContext;
  class Hierarchical_tf_identifierContext;
  class Hierarchical_variable_identifierContext;
  class IdentifierContext;
  class Index_variable_identifierContext;
  class Interface_identifierContext;
  class Interface_instance_identifierContext;
  class Inout_port_identifierContext;
  class Input_port_identifierContext;
  class Instance_identifierContext;
  class Library_identifierContext;
  class Member_identifierContext;
  class Method_identifierContext;
  class Modport_identifierContext;
  class Module_identifierContext;
  class Net_identifierContext;
  class Net_type_identifierContext;
  class Output_port_identifierContext;
  class Package_identifierContext;
  class Package_scopeContext;
  class Parameter_identifierContext;
  class Port_identifierContext;
  class Production_identifierContext;
  class Program_identifierContext;
  class Property_identifierContext;
  class Ps_class_identifierContext;
  class Ps_covergroup_identifierContext;
  class Ps_checker_identifierContext;
  class Ps_identifierContext;
  class Ps_or_hierarchical_array_identifierContext;
  class Ps_or_hierarchical_net_identifierContext;
  class Ps_or_hierarchical_property_identifierContext;
  class Ps_or_hierarchical_sequence_identifierContext;
  class Ps_or_hierarchical_tf_identifierContext;
  class Ps_parameter_identifierContext;
  class Ps_type_identifierContext;
  class Sequence_identifierContext;
  class Signal_identifierContext;
  class Specparam_identifierContext;
  class Task_identifierContext;
  class Tf_identifierContext;
  class Terminal_identifierContext;
  class Topmodule_identifierContext;
  class Type_identifierContext;
  class Udp_identifierContext;
  class Variable_identifierContext; 

  class Library_textContext : public ParserRuleContext {
  public:
    Library_textContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Library_descriptionContext>> library_description();
    Ref<Library_descriptionContext> library_description(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Library_textContext> library_text();

  class Library_descriptionContext : public ParserRuleContext {
  public:
    Library_descriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Library_declarationContext> library_declaration();
    Ref<Include_statementContext> include_statement();
    Ref<Config_declarationContext> config_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Library_descriptionContext> library_description();

  class Library_declarationContext : public ParserRuleContext {
  public:
    Library_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Library_identifierContext> library_identifier();
    std::vector<Ref<tree::TerminalNode>> File_path_spec();
    Ref<tree::TerminalNode> File_path_spec(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Library_declarationContext> library_declaration();

  class Include_statementContext : public ParserRuleContext {
  public:
    Include_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> File_path_spec();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Include_statementContext> include_statement();

  class Source_textContext : public ParserRuleContext {
  public:
    Source_textContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> EOF();
    Ref<Timeunits_declarationContext> timeunits_declaration();
    std::vector<Ref<DescriptionContext>> description();
    Ref<DescriptionContext> description(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Source_textContext> source_text();

  class DescriptionContext : public ParserRuleContext {
  public:
    DescriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_declarationContext> module_declaration();
    Ref<Udp_declarationContext> udp_declaration();
    Ref<Interface_declarationContext> interface_declaration();
    Ref<Program_declarationContext> program_declaration();
    Ref<Package_declarationContext> package_declaration();
    Ref<Package_itemContext> package_item();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Bind_directiveContext> bind_directive();
    Ref<Config_declarationContext> config_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<DescriptionContext> description();

  class Module_nonansi_headerContext : public ParserRuleContext {
  public:
    Module_nonansi_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_keywordContext> module_keyword();
    Ref<Module_identifierContext> module_identifier();
    Ref<List_of_portsContext> list_of_ports();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<LifetimeContext> lifetime();
    std::vector<Ref<Package_import_declarationContext>> package_import_declaration();
    Ref<Package_import_declarationContext> package_import_declaration(int i);
    Ref<Parameter_port_listContext> parameter_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_nonansi_headerContext> module_nonansi_header();

  class Module_ansi_headerContext : public ParserRuleContext {
  public:
    Module_ansi_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_keywordContext> module_keyword();
    Ref<Module_identifierContext> module_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<LifetimeContext> lifetime();
    std::vector<Ref<Package_import_declarationContext>> package_import_declaration();
    Ref<Package_import_declarationContext> package_import_declaration(int i);
    Ref<Parameter_port_listContext> parameter_port_list();
    Ref<List_of_port_declarationsContext> list_of_port_declarations();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_ansi_headerContext> module_ansi_header();

  class Module_declarationContext : public ParserRuleContext {
  public:
    Module_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_nonansi_headerContext> module_nonansi_header();
    Ref<Timeunits_declarationContext> timeunits_declaration();
    std::vector<Ref<Module_itemContext>> module_item();
    Ref<Module_itemContext> module_item(int i);
    std::vector<Ref<Module_identifierContext>> module_identifier();
    Ref<Module_identifierContext> module_identifier(int i);
    Ref<Module_ansi_headerContext> module_ansi_header();
    std::vector<Ref<Non_port_module_itemContext>> non_port_module_item();
    Ref<Non_port_module_itemContext> non_port_module_item(int i);
    Ref<Module_keywordContext> module_keyword();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<LifetimeContext> lifetime();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_declarationContext> module_declaration();

  class Module_keywordContext : public ParserRuleContext {
  public:
    Module_keywordContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_keywordContext> module_keyword();

  class Interface_declarationContext : public ParserRuleContext {
  public:
    Interface_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_nonansi_headerContext> interface_nonansi_header();
    Ref<Timeunits_declarationContext> timeunits_declaration();
    std::vector<Ref<Interface_itemContext>> interface_item();
    Ref<Interface_itemContext> interface_item(int i);
    std::vector<Ref<Interface_identifierContext>> interface_identifier();
    Ref<Interface_identifierContext> interface_identifier(int i);
    Ref<Interface_ansi_headerContext> interface_ansi_header();
    std::vector<Ref<Non_port_interface_itemContext>> non_port_interface_item();
    Ref<Non_port_interface_itemContext> non_port_interface_item(int i);
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_declarationContext> interface_declaration();

  class Interface_nonansi_headerContext : public ParserRuleContext {
  public:
    Interface_nonansi_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_identifierContext> interface_identifier();
    Ref<List_of_portsContext> list_of_ports();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<LifetimeContext> lifetime();
    std::vector<Ref<Package_import_declarationContext>> package_import_declaration();
    Ref<Package_import_declarationContext> package_import_declaration(int i);
    Ref<Parameter_port_listContext> parameter_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_nonansi_headerContext> interface_nonansi_header();

  class Interface_ansi_headerContext : public ParserRuleContext {
  public:
    Interface_ansi_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_identifierContext> interface_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<LifetimeContext> lifetime();
    std::vector<Ref<Package_import_declarationContext>> package_import_declaration();
    Ref<Package_import_declarationContext> package_import_declaration(int i);
    Ref<Parameter_port_listContext> parameter_port_list();
    Ref<List_of_port_declarationsContext> list_of_port_declarations();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_ansi_headerContext> interface_ansi_header();

  class Program_declarationContext : public ParserRuleContext {
  public:
    Program_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Program_nonansi_headerContext> program_nonansi_header();
    Ref<Timeunits_declarationContext> timeunits_declaration();
    std::vector<Ref<Program_itemContext>> program_item();
    Ref<Program_itemContext> program_item(int i);
    std::vector<Ref<Program_identifierContext>> program_identifier();
    Ref<Program_identifierContext> program_identifier(int i);
    Ref<Program_ansi_headerContext> program_ansi_header();
    std::vector<Ref<Non_port_program_itemContext>> non_port_program_item();
    Ref<Non_port_program_itemContext> non_port_program_item(int i);
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Program_declarationContext> program_declaration();

  class Program_nonansi_headerContext : public ParserRuleContext {
  public:
    Program_nonansi_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Program_identifierContext> program_identifier();
    Ref<List_of_portsContext> list_of_ports();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<LifetimeContext> lifetime();
    std::vector<Ref<Package_import_declarationContext>> package_import_declaration();
    Ref<Package_import_declarationContext> package_import_declaration(int i);
    Ref<Parameter_port_listContext> parameter_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Program_nonansi_headerContext> program_nonansi_header();

  class Program_ansi_headerContext : public ParserRuleContext {
  public:
    Program_ansi_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Program_identifierContext> program_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<LifetimeContext> lifetime();
    std::vector<Ref<Package_import_declarationContext>> package_import_declaration();
    Ref<Package_import_declarationContext> package_import_declaration(int i);
    Ref<Parameter_port_listContext> parameter_port_list();
    Ref<List_of_port_declarationsContext> list_of_port_declarations();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Program_ansi_headerContext> program_ansi_header();

  class Checker_declarationContext : public ParserRuleContext {
  public:
    Checker_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Checker_identifierContext>> checker_identifier();
    Ref<Checker_identifierContext> checker_identifier(int i);
    std::vector<Ref<Checker_or_generate_itemContext>> checker_or_generate_item();
    Ref<Checker_or_generate_itemContext> checker_or_generate_item(int i);
    Ref<Checker_port_listContext> checker_port_list();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_declarationContext> checker_declaration();

  class Class_declarationContext : public ParserRuleContext {
  public:
    Class_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Class_identifierContext>> class_identifier();
    Ref<Class_identifierContext> class_identifier(int i);
    Ref<LifetimeContext> lifetime();
    Ref<Parameter_port_listContext> parameter_port_list();
    Ref<Class_typeContext> class_type();
    std::vector<Ref<Interface_class_typeContext>> interface_class_type();
    Ref<Interface_class_typeContext> interface_class_type(int i);
    std::vector<Ref<Class_itemContext>> class_item();
    Ref<Class_itemContext> class_item(int i);
    Ref<List_of_argumentsContext> list_of_arguments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_declarationContext> class_declaration();

  class Interface_class_typeContext : public ParserRuleContext {
  public:
    Interface_class_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_class_identifierContext> ps_class_identifier();
    Ref<Parameter_value_assignmentContext> parameter_value_assignment();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_class_typeContext> interface_class_type();

  class Interface_class_declarationContext : public ParserRuleContext {
  public:
    Interface_class_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Class_identifierContext>> class_identifier();
    Ref<Class_identifierContext> class_identifier(int i);
    Ref<Parameter_port_listContext> parameter_port_list();
    std::vector<Ref<Interface_class_typeContext>> interface_class_type();
    Ref<Interface_class_typeContext> interface_class_type(int i);
    std::vector<Ref<Interface_class_itemContext>> interface_class_item();
    Ref<Interface_class_itemContext> interface_class_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_class_declarationContext> interface_class_declaration();

  class Interface_class_itemContext : public ParserRuleContext {
  public:
    Interface_class_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Type_declarationContext> type_declaration();
    Ref<Interface_class_methodContext> interface_class_method();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Local_parameter_declarationContext> local_parameter_declaration();
    Ref<Parameter_declarationContext> parameter_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_class_itemContext> interface_class_item();

  class Interface_class_methodContext : public ParserRuleContext {
  public:
    Interface_class_methodContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Method_prototypeContext> method_prototype();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_class_methodContext> interface_class_method();

  class Package_declarationContext : public ParserRuleContext {
  public:
    Package_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Package_identifierContext>> package_identifier();
    Ref<Package_identifierContext> package_identifier(int i);
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<LifetimeContext> lifetime();
    Ref<Timeunits_declarationContext> timeunits_declaration();
    std::vector<Ref<Package_itemContext>> package_item();
    Ref<Package_itemContext> package_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Package_declarationContext> package_declaration();

  class Timeunits_declarationContext : public ParserRuleContext {
  public:
    Timeunits_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Time_literalContext>> time_literal();
    Ref<Time_literalContext> time_literal(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Timeunits_declarationContext> timeunits_declaration();

  class Parameter_port_listContext : public ParserRuleContext {
  public:
    Parameter_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_param_assignmentsContext> list_of_param_assignments();
    std::vector<Ref<Parameter_port_declarationContext>> parameter_port_declaration();
    Ref<Parameter_port_declarationContext> parameter_port_declaration(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Parameter_port_listContext> parameter_port_list();

  class Parameter_port_declarationContext : public ParserRuleContext {
  public:
    Parameter_port_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parameter_declarationContext> parameter_declaration();
    Ref<Local_parameter_declarationContext> local_parameter_declaration();
    Ref<Data_typeContext> data_type();
    Ref<List_of_param_assignmentsContext> list_of_param_assignments();
    Ref<List_of_type_assignmentsContext> list_of_type_assignments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Parameter_port_declarationContext> parameter_port_declaration();

  class List_of_portsContext : public ParserRuleContext {
  public:
    List_of_portsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<PortContext>> port();
    Ref<PortContext> port(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_portsContext> list_of_ports();

  class List_of_port_declarationsContext : public ParserRuleContext {
  public:
    List_of_port_declarationsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Ansi_port_declarationContext>> ansi_port_declaration();
    Ref<Ansi_port_declarationContext> ansi_port_declaration(int i);
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_port_declarationsContext> list_of_port_declarations();

  class Port_declarationContext : public ParserRuleContext {
  public:
    Port_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Inout_declarationContext> inout_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Input_declarationContext> input_declaration();
    Ref<Output_declarationContext> output_declaration();
    Ref<Ref_declarationContext> ref_declaration();
    Ref<Interface_port_declarationContext> interface_port_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Port_declarationContext> port_declaration();

  class PortContext : public ParserRuleContext {
  public:
    PortContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_expressionContext> port_expression();
    Ref<Port_identifierContext> port_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<PortContext> port();

  class Port_expressionContext : public ParserRuleContext {
  public:
    Port_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_referenceContext>> port_reference();
    Ref<Port_referenceContext> port_reference(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Port_expressionContext> port_expression();

  class Port_referenceContext : public ParserRuleContext {
  public:
    Port_referenceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_identifierContext> port_identifier();
    Ref<Constant_selectContext> constant_select();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Port_referenceContext> port_reference();

  class Port_directionContext : public ParserRuleContext {
  public:
    Port_directionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Port_directionContext> port_direction();

  class Net_port_headerContext : public ParserRuleContext {
  public:
    Net_port_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_port_typeContext> net_port_type();
    Ref<Port_directionContext> port_direction();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_port_headerContext> net_port_header();

  class Variable_port_headerContext : public ParserRuleContext {
  public:
    Variable_port_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_port_typeContext> variable_port_type();
    Ref<Port_directionContext> port_direction();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Variable_port_headerContext> variable_port_header();

  class Interface_port_headerContext : public ParserRuleContext {
  public:
    Interface_port_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_identifierContext> interface_identifier();
    Ref<Modport_identifierContext> modport_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_port_headerContext> interface_port_header();

  class Ansi_port_declarationContext : public ParserRuleContext {
  public:
    Ansi_port_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_identifierContext> port_identifier();
    Ref<Net_port_headerContext> net_port_header();
    Ref<Interface_port_headerContext> interface_port_header();
    std::vector<Ref<Unpacked_dimensionContext>> unpacked_dimension();
    Ref<Unpacked_dimensionContext> unpacked_dimension(int i);
    Ref<Constant_expressionContext> constant_expression();
    Ref<Variable_port_headerContext> variable_port_header();
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    Ref<Port_directionContext> port_direction();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ansi_port_declarationContext> ansi_port_declaration();

  class Elaboration_system_taskContext : public ParserRuleContext {
  public:
    Elaboration_system_taskContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Finish_numberContext> finish_number();
    Ref<List_of_argumentsContext> list_of_arguments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Elaboration_system_taskContext> elaboration_system_task();

  class Finish_numberContext : public ParserRuleContext {
  public:
    Finish_numberContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Unsigned_number();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Finish_numberContext> finish_number();

  class Module_common_itemContext : public ParserRuleContext {
  public:
    Module_common_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_or_generate_item_declarationContext> module_or_generate_item_declaration();
    Ref<Interface_instantiationContext> interface_instantiation();
    Ref<Program_instantiationContext> program_instantiation();
    Ref<Assertion_itemContext> assertion_item();
    Ref<Bind_directiveContext> bind_directive();
    Ref<Continuous_assignContext> continuous_assign();
    Ref<Net_aliasContext> net_alias();
    Ref<Initial_constructContext> initial_construct();
    Ref<Final_constructContext> final_construct();
    Ref<Always_constructContext> always_construct();
    Ref<Loop_generate_constructContext> loop_generate_construct();
    Ref<Conditional_generate_constructContext> conditional_generate_construct();
    Ref<Elaboration_system_taskContext> elaboration_system_task();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_common_itemContext> module_common_item();

  class Module_itemContext : public ParserRuleContext {
  public:
    Module_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_declarationContext> port_declaration();
    Ref<Non_port_module_itemContext> non_port_module_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_itemContext> module_item();

  class Module_or_generate_itemContext : public ParserRuleContext {
  public:
    Module_or_generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parameter_overrideContext> parameter_override();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Gate_instantiationContext> gate_instantiation();
    Ref<Udp_instantiationContext> udp_instantiation();
    Ref<Module_instantiationContext> module_instantiation();
    Ref<Module_common_itemContext> module_common_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_or_generate_itemContext> module_or_generate_item();

  class Module_or_generate_item_declarationContext : public ParserRuleContext {
  public:
    Module_or_generate_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Package_or_generate_item_declarationContext> package_or_generate_item_declaration();
    Ref<Genvar_declarationContext> genvar_declaration();
    Ref<Clocking_declarationContext> clocking_declaration();
    Ref<Clocking_identifierContext> clocking_identifier();
    Ref<Expression_or_distContext> expression_or_dist();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_or_generate_item_declarationContext> module_or_generate_item_declaration();

  class Non_port_module_itemContext : public ParserRuleContext {
  public:
    Non_port_module_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Generate_regionContext> generate_region();
    Ref<Module_or_generate_itemContext> module_or_generate_item();
    Ref<Specify_blockContext> specify_block();
    Ref<Specparam_declarationContext> specparam_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Program_declarationContext> program_declaration();
    Ref<Module_declarationContext> module_declaration();
    Ref<Interface_declarationContext> interface_declaration();
    Ref<Timeunits_declarationContext> timeunits_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Non_port_module_itemContext> non_port_module_item();

  class Parameter_overrideContext : public ParserRuleContext {
  public:
    Parameter_overrideContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_defparam_assignmentsContext> list_of_defparam_assignments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Parameter_overrideContext> parameter_override();

  class Bind_directiveContext : public ParserRuleContext {
  public:
    Bind_directiveContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Bind_target_scopeContext> bind_target_scope();
    Ref<Bind_instantiationContext> bind_instantiation();
    Ref<Bind_target_instance_listContext> bind_target_instance_list();
    Ref<Bind_target_instanceContext> bind_target_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bind_directiveContext> bind_directive();

  class Bind_target_scopeContext : public ParserRuleContext {
  public:
    Bind_target_scopeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_identifierContext> module_identifier();
    Ref<Interface_identifierContext> interface_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bind_target_scopeContext> bind_target_scope();

  class Bind_target_instanceContext : public ParserRuleContext {
  public:
    Bind_target_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();
    Ref<Constant_bit_selectContext> constant_bit_select();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bind_target_instanceContext> bind_target_instance();

  class Bind_target_instance_listContext : public ParserRuleContext {
  public:
    Bind_target_instance_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Bind_target_instanceContext>> bind_target_instance();
    Ref<Bind_target_instanceContext> bind_target_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bind_target_instance_listContext> bind_target_instance_list();

  class Bind_instantiationContext : public ParserRuleContext {
  public:
    Bind_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Program_instantiationContext> program_instantiation();
    Ref<Module_instantiationContext> module_instantiation();
    Ref<Interface_instantiationContext> interface_instantiation();
    Ref<Checker_instantiationContext> checker_instantiation();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bind_instantiationContext> bind_instantiation();

  class Config_declarationContext : public ParserRuleContext {
  public:
    Config_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Config_identifierContext>> config_identifier();
    Ref<Config_identifierContext> config_identifier(int i);
    Ref<Design_statementContext> design_statement();
    std::vector<Ref<Local_parameter_declarationContext>> local_parameter_declaration();
    Ref<Local_parameter_declarationContext> local_parameter_declaration(int i);
    std::vector<Ref<Config_rule_statementContext>> config_rule_statement();
    Ref<Config_rule_statementContext> config_rule_statement(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Config_rule_statementContext> config_rule_statement();

  class Default_clauseContext : public ParserRuleContext {
  public:
    Default_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Default_clauseContext> default_clause();

  class Inst_clauseContext : public ParserRuleContext {
  public:
    Inst_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Inst_nameContext> inst_name();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Inst_clauseContext> inst_clause();

  class Inst_nameContext : public ParserRuleContext {
  public:
    Inst_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Topmodule_identifierContext> topmodule_identifier();
    std::vector<Ref<Instance_identifierContext>> instance_identifier();
    Ref<Instance_identifierContext> instance_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Inst_nameContext> inst_name();

  class Cell_clauseContext : public ParserRuleContext {
  public:
    Cell_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cell_identifierContext> cell_identifier();
    Ref<Library_identifierContext> library_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cell_clauseContext> cell_clause();

  class Liblist_clauseContext : public ParserRuleContext {
  public:
    Liblist_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Library_identifierContext>> library_identifier();
    Ref<Library_identifierContext> library_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Liblist_clauseContext> liblist_clause();

  class Use_clauseContext : public ParserRuleContext {
  public:
    Use_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cell_identifierContext> cell_identifier();
    Ref<Library_identifierContext> library_identifier();
    std::vector<Ref<Named_parameter_assignmentContext>> named_parameter_assignment();
    Ref<Named_parameter_assignmentContext> named_parameter_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Use_clauseContext> use_clause();

  class Interface_or_generate_itemContext : public ParserRuleContext {
  public:
    Interface_or_generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_common_itemContext> module_common_item();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Modport_declarationContext> modport_declaration();
    Ref<Extern_tf_declarationContext> extern_tf_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_or_generate_itemContext> interface_or_generate_item();

  class Extern_tf_declarationContext : public ParserRuleContext {
  public:
    Extern_tf_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Method_prototypeContext> method_prototype();
    Ref<Task_prototypeContext> task_prototype();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Extern_tf_declarationContext> extern_tf_declaration();

  class Interface_itemContext : public ParserRuleContext {
  public:
    Interface_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_declarationContext> port_declaration();
    Ref<Non_port_interface_itemContext> non_port_interface_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_itemContext> interface_item();

  class Non_port_interface_itemContext : public ParserRuleContext {
  public:
    Non_port_interface_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Generate_regionContext> generate_region();
    Ref<Interface_or_generate_itemContext> interface_or_generate_item();
    Ref<Program_declarationContext> program_declaration();
    Ref<Interface_declarationContext> interface_declaration();
    Ref<Timeunits_declarationContext> timeunits_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Non_port_interface_itemContext> non_port_interface_item();

  class Program_itemContext : public ParserRuleContext {
  public:
    Program_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_declarationContext> port_declaration();
    Ref<Non_port_program_itemContext> non_port_program_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Program_itemContext> program_item();

  class Non_port_program_itemContext : public ParserRuleContext {
  public:
    Non_port_program_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Continuous_assignContext> continuous_assign();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Module_or_generate_item_declarationContext> module_or_generate_item_declaration();
    Ref<Initial_constructContext> initial_construct();
    Ref<Final_constructContext> final_construct();
    Ref<Concurrent_assertion_itemContext> concurrent_assertion_item();
    Ref<Timeunits_declarationContext> timeunits_declaration();
    Ref<Program_generate_itemContext> program_generate_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Non_port_program_itemContext> non_port_program_item();

  class Program_generate_itemContext : public ParserRuleContext {
  public:
    Program_generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Loop_generate_constructContext> loop_generate_construct();
    Ref<Conditional_generate_constructContext> conditional_generate_construct();
    Ref<Generate_regionContext> generate_region();
    Ref<Elaboration_system_taskContext> elaboration_system_task();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Program_generate_itemContext> program_generate_item();

  class Checker_port_listContext : public ParserRuleContext {
  public:
    Checker_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Checker_port_itemContext>> checker_port_item();
    Ref<Checker_port_itemContext> checker_port_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_port_listContext> checker_port_list();

  class Checker_port_itemContext : public ParserRuleContext {
  public:
    Checker_port_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_formal_typeContext> property_formal_type();
    Ref<Formal_port_identifierContext> formal_port_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Checker_port_directionContext> checker_port_direction();
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    Ref<Property_actual_argContext> property_actual_arg();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_port_itemContext> checker_port_item();

  class Checker_port_directionContext : public ParserRuleContext {
  public:
    Checker_port_directionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_port_directionContext> checker_port_direction();

  class Checker_or_generate_itemContext : public ParserRuleContext {
  public:
    Checker_or_generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Checker_or_generate_item_declarationContext> checker_or_generate_item_declaration();
    Ref<Initial_constructContext> initial_construct();
    Ref<Always_constructContext> always_construct();
    Ref<Final_constructContext> final_construct();
    Ref<Assertion_itemContext> assertion_item();
    Ref<Continuous_assignContext> continuous_assign();
    Ref<Checker_generate_itemContext> checker_generate_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_or_generate_itemContext> checker_or_generate_item();

  class Checker_or_generate_item_declarationContext : public ParserRuleContext {
  public:
    Checker_or_generate_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_declarationContext> data_declaration();
    Ref<Function_declarationContext> function_declaration();
    Ref<Checker_declarationContext> checker_declaration();
    Ref<Assertion_item_declarationContext> assertion_item_declaration();
    Ref<Covergroup_declarationContext> covergroup_declaration();
    Ref<Overload_declarationContext> overload_declaration();
    Ref<Genvar_declarationContext> genvar_declaration();
    Ref<Clocking_declarationContext> clocking_declaration();
    Ref<Clocking_identifierContext> clocking_identifier();
    Ref<Expression_or_distContext> expression_or_dist();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_or_generate_item_declarationContext> checker_or_generate_item_declaration();

  class Checker_generate_itemContext : public ParserRuleContext {
  public:
    Checker_generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Loop_generate_constructContext> loop_generate_construct();
    Ref<Conditional_generate_constructContext> conditional_generate_construct();
    Ref<Generate_regionContext> generate_region();
    Ref<Elaboration_system_taskContext> elaboration_system_task();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_generate_itemContext> checker_generate_item();

  class Class_itemContext : public ParserRuleContext {
  public:
    Class_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Class_propertyContext> class_property();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Class_methodContext> class_method();
    Ref<Class_constraintContext> class_constraint();
    Ref<Class_declarationContext> class_declaration();
    Ref<Covergroup_declarationContext> covergroup_declaration();
    Ref<Local_parameter_declarationContext> local_parameter_declaration();
    Ref<Parameter_declarationContext> parameter_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_itemContext> class_item();

  class Class_propertyContext : public ParserRuleContext {
  public:
    Class_propertyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_declarationContext> data_declaration();
    std::vector<Ref<Property_qualifierContext>> property_qualifier();
    Ref<Property_qualifierContext> property_qualifier(int i);
    Ref<Data_typeContext> data_type();
    Ref<Const_identifierContext> const_identifier();
    std::vector<Ref<Class_item_qualifierContext>> class_item_qualifier();
    Ref<Class_item_qualifierContext> class_item_qualifier(int i);
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_propertyContext> class_property();

  class Class_methodContext : public ParserRuleContext {
  public:
    Class_methodContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Task_declarationContext> task_declaration();
    std::vector<Ref<Method_qualifierContext>> method_qualifier();
    Ref<Method_qualifierContext> method_qualifier(int i);
    Ref<Function_declarationContext> function_declaration();
    Ref<Method_prototypeContext> method_prototype();
    std::vector<Ref<Class_item_qualifierContext>> class_item_qualifier();
    Ref<Class_item_qualifierContext> class_item_qualifier(int i);
    Ref<Class_constructor_declarationContext> class_constructor_declaration();
    Ref<Class_constructor_prototypeContext> class_constructor_prototype();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_methodContext> class_method();

  class Class_constructor_prototypeContext : public ParserRuleContext {
  public:
    Class_constructor_prototypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Tf_port_listContext> tf_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_constructor_prototypeContext> class_constructor_prototype();

  class Class_constraintContext : public ParserRuleContext {
  public:
    Class_constraintContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constraint_prototypeContext> constraint_prototype();
    Ref<Constraint_declarationContext> constraint_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_constraintContext> class_constraint();

  class Class_item_qualifierContext : public ParserRuleContext {
  public:
    Class_item_qualifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_item_qualifierContext> class_item_qualifier();

  class Property_qualifierContext : public ParserRuleContext {
  public:
    Property_qualifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Random_qualifierContext> random_qualifier();
    Ref<Class_item_qualifierContext> class_item_qualifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_qualifierContext> property_qualifier();

  class Random_qualifierContext : public ParserRuleContext {
  public:
    Random_qualifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Random_qualifierContext> random_qualifier();

  class Method_qualifierContext : public ParserRuleContext {
  public:
    Method_qualifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Class_item_qualifierContext> class_item_qualifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Method_qualifierContext> method_qualifier();

  class Method_prototypeContext : public ParserRuleContext {
  public:
    Method_prototypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Task_prototypeContext> task_prototype();
    Ref<Function_prototypeContext> function_prototype();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Method_prototypeContext> method_prototype();

  class Class_constructor_declarationContext : public ParserRuleContext {
  public:
    Class_constructor_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Class_scopeContext> class_scope();
    Ref<Tf_port_listContext> tf_port_list();
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);
    std::vector<Ref<Function_statement_or_nullContext>> function_statement_or_null();
    Ref<Function_statement_or_nullContext> function_statement_or_null(int i);
    Ref<List_of_argumentsContext> list_of_arguments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_constructor_declarationContext> class_constructor_declaration();

  class Constraint_declarationContext : public ParserRuleContext {
  public:
    Constraint_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constraint_identifierContext> constraint_identifier();
    Ref<Constraint_blockContext> constraint_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_declarationContext> constraint_declaration();

  class Constraint_blockContext : public ParserRuleContext {
  public:
    Constraint_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constraint_block_itemContext>> constraint_block_item();
    Ref<Constraint_block_itemContext> constraint_block_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_blockContext> constraint_block();

  class Constraint_block_itemContext : public ParserRuleContext {
  public:
    Constraint_block_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Solve_before_listContext>> solve_before_list();
    Ref<Solve_before_listContext> solve_before_list(int i);
    Ref<Constraint_expressionContext> constraint_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_block_itemContext> constraint_block_item();

  class Solve_before_listContext : public ParserRuleContext {
  public:
    Solve_before_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constraint_primaryContext>> constraint_primary();
    Ref<Constraint_primaryContext> constraint_primary(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Solve_before_listContext> solve_before_list();

  class Constraint_primaryContext : public ParserRuleContext {
  public:
    Constraint_primaryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();
    Ref<SelectContext> select();
    Ref<Implicit_class_handleContext> implicit_class_handle();
    Ref<Class_scopeContext> class_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_primaryContext> constraint_primary();

  class Constraint_expressionContext : public ParserRuleContext {
  public:
    Constraint_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Expression_or_distContext> expression_or_dist();
    Ref<Uniqueness_constraintContext> uniqueness_constraint();
    Ref<ExpressionContext> expression();
    std::vector<Ref<Constraint_setContext>> constraint_set();
    Ref<Constraint_setContext> constraint_set(int i);
    Ref<Ps_or_hierarchical_array_identifierContext> ps_or_hierarchical_array_identifier();
    Ref<Loop_variablesContext> loop_variables();
    Ref<Constraint_primaryContext> constraint_primary();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_expressionContext> constraint_expression();

  class Uniqueness_constraintContext : public ParserRuleContext {
  public:
    Uniqueness_constraintContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Open_range_listContext> open_range_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Uniqueness_constraintContext> uniqueness_constraint();

  class Constraint_setContext : public ParserRuleContext {
  public:
    Constraint_setContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constraint_expressionContext>> constraint_expression();
    Ref<Constraint_expressionContext> constraint_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_setContext> constraint_set();

  class Dist_listContext : public ParserRuleContext {
  public:
    Dist_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Dist_itemContext>> dist_item();
    Ref<Dist_itemContext> dist_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dist_listContext> dist_list();

  class Dist_itemContext : public ParserRuleContext {
  public:
    Dist_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Value_rangeContext> value_range();
    Ref<Dist_weightContext> dist_weight();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dist_itemContext> dist_item();

  class Dist_weightContext : public ParserRuleContext {
  public:
    Dist_weightContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dist_weightContext> dist_weight();

  class Constraint_prototypeContext : public ParserRuleContext {
  public:
    Constraint_prototypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constraint_identifierContext> constraint_identifier();
    Ref<Constraint_prototype_qualifierContext> constraint_prototype_qualifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_prototypeContext> constraint_prototype();

  class Constraint_prototype_qualifierContext : public ParserRuleContext {
  public:
    Constraint_prototype_qualifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_prototype_qualifierContext> constraint_prototype_qualifier();

  class Extern_constraint_declarationContext : public ParserRuleContext {
  public:
    Extern_constraint_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Class_scopeContext> class_scope();
    Ref<Constraint_identifierContext> constraint_identifier();
    Ref<Constraint_blockContext> constraint_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Extern_constraint_declarationContext> extern_constraint_declaration();

  class Identifier_listContext : public ParserRuleContext {
  public:
    Identifier_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Identifier_listContext> identifier_list();

  class Package_itemContext : public ParserRuleContext {
  public:
    Package_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Package_or_generate_item_declarationContext> package_or_generate_item_declaration();
    Ref<Anonymous_programContext> anonymous_program();
    Ref<Package_export_declarationContext> package_export_declaration();
    Ref<Timeunits_declarationContext> timeunits_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Package_itemContext> package_item();

  class Package_or_generate_item_declarationContext : public ParserRuleContext {
  public:
    Package_or_generate_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_declarationContext> net_declaration();
    Ref<Data_declarationContext> data_declaration();
    Ref<Task_declarationContext> task_declaration();
    Ref<Function_declarationContext> function_declaration();
    Ref<Checker_declarationContext> checker_declaration();
    Ref<Dpi_import_exportContext> dpi_import_export();
    Ref<Extern_constraint_declarationContext> extern_constraint_declaration();
    Ref<Class_declarationContext> class_declaration();
    Ref<Class_constructor_declarationContext> class_constructor_declaration();
    Ref<Local_parameter_declarationContext> local_parameter_declaration();
    Ref<Parameter_declarationContext> parameter_declaration();
    Ref<Covergroup_declarationContext> covergroup_declaration();
    Ref<Overload_declarationContext> overload_declaration();
    Ref<Assertion_item_declarationContext> assertion_item_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Package_or_generate_item_declarationContext> package_or_generate_item_declaration();

  class Anonymous_programContext : public ParserRuleContext {
  public:
    Anonymous_programContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Anonymous_program_itemContext>> anonymous_program_item();
    Ref<Anonymous_program_itemContext> anonymous_program_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Anonymous_programContext> anonymous_program();

  class Anonymous_program_itemContext : public ParserRuleContext {
  public:
    Anonymous_program_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Task_declarationContext> task_declaration();
    Ref<Function_declarationContext> function_declaration();
    Ref<Class_declarationContext> class_declaration();
    Ref<Covergroup_declarationContext> covergroup_declaration();
    Ref<Class_constructor_declarationContext> class_constructor_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Anonymous_program_itemContext> anonymous_program_item();

  class Local_parameter_declarationContext : public ParserRuleContext {
  public:
    Local_parameter_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_implicitContext> data_type_or_implicit();
    Ref<List_of_param_assignmentsContext> list_of_param_assignments();
    Ref<List_of_type_assignmentsContext> list_of_type_assignments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Local_parameter_declarationContext> local_parameter_declaration();

  class Parameter_declarationContext : public ParserRuleContext {
  public:
    Parameter_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_implicitContext> data_type_or_implicit();
    Ref<List_of_param_assignmentsContext> list_of_param_assignments();
    Ref<List_of_type_assignmentsContext> list_of_type_assignments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Parameter_declarationContext> parameter_declaration();

  class Specparam_declarationContext : public ParserRuleContext {
  public:
    Specparam_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_specparam_assignmentsContext> list_of_specparam_assignments();
    Ref<Packed_dimensionContext> packed_dimension();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Specparam_declarationContext> specparam_declaration();

  class Inout_declarationContext : public ParserRuleContext {
  public:
    Inout_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_port_typeContext> net_port_type();
    Ref<List_of_port_identifiersContext> list_of_port_identifiers();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Inout_declarationContext> inout_declaration();

  class Input_declarationContext : public ParserRuleContext {
  public:
    Input_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_port_typeContext> net_port_type();
    Ref<List_of_port_identifiersContext> list_of_port_identifiers();
    Ref<Variable_port_typeContext> variable_port_type();
    Ref<List_of_variable_identifiersContext> list_of_variable_identifiers();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Input_declarationContext> input_declaration();

  class Output_declarationContext : public ParserRuleContext {
  public:
    Output_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_port_typeContext> net_port_type();
    Ref<List_of_port_identifiersContext> list_of_port_identifiers();
    Ref<Variable_port_typeContext> variable_port_type();
    Ref<List_of_variable_port_identifiersContext> list_of_variable_port_identifiers();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Output_declarationContext> output_declaration();

  class Interface_port_declarationContext : public ParserRuleContext {
  public:
    Interface_port_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_identifierContext> interface_identifier();
    Ref<List_of_interface_identifiersContext> list_of_interface_identifiers();
    Ref<Modport_identifierContext> modport_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_port_declarationContext> interface_port_declaration();

  class Ref_declarationContext : public ParserRuleContext {
  public:
    Ref_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_port_typeContext> variable_port_type();
    Ref<List_of_variable_identifiersContext> list_of_variable_identifiers();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ref_declarationContext> ref_declaration();

  class Data_declarationContext : public ParserRuleContext {
  public:
    Data_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_implicitContext> data_type_or_implicit();
    Ref<List_of_variable_decl_assignmentsContext> list_of_variable_decl_assignments();
    Ref<LifetimeContext> lifetime();
    Ref<Type_declarationContext> type_declaration();
    Ref<Package_import_declarationContext> package_import_declaration();
    Ref<Net_type_declarationContext> net_type_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Data_declarationContext> data_declaration();

  class Package_import_declarationContext : public ParserRuleContext {
  public:
    Package_import_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Package_import_itemContext>> package_import_item();
    Ref<Package_import_itemContext> package_import_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Package_import_declarationContext> package_import_declaration();

  class Package_import_itemContext : public ParserRuleContext {
  public:
    Package_import_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Package_identifierContext> package_identifier();
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Package_import_itemContext> package_import_item();

  class Package_export_declarationContext : public ParserRuleContext {
  public:
    Package_export_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Package_import_itemContext>> package_import_item();
    Ref<Package_import_itemContext> package_import_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Package_export_declarationContext> package_export_declaration();

  class Genvar_declarationContext : public ParserRuleContext {
  public:
    Genvar_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_genvar_identifiersContext> list_of_genvar_identifiers();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Genvar_declarationContext> genvar_declaration();

  class Net_declarationContext : public ParserRuleContext {
  public:
    Net_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_typeContext> net_type();
    Ref<Data_type_or_implicitContext> data_type_or_implicit();
    Ref<List_of_net_decl_assignmentsContext> list_of_net_decl_assignments();
    Ref<Drive_strengthContext> drive_strength();
    Ref<Charge_strengthContext> charge_strength();
    Ref<Delay3Context> delay3();
    Ref<Net_type_identifierContext> net_type_identifier();
    Ref<Delay_controlContext> delay_control();
    Ref<Implicit_data_typeContext> implicit_data_type();
    std::vector<Ref<Net_identifierContext>> net_identifier();
    Ref<Net_identifierContext> net_identifier(int i);
    Ref<Delay_valueContext> delay_value();
    std::vector<Ref<Unpacked_dimensionContext>> unpacked_dimension();
    Ref<Unpacked_dimensionContext> unpacked_dimension(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_declarationContext> net_declaration();

  class Type_declarationContext : public ParserRuleContext {
  public:
    Type_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_typeContext> data_type();
    std::vector<Ref<Type_identifierContext>> type_identifier();
    Ref<Type_identifierContext> type_identifier(int i);
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    Ref<Interface_instance_identifierContext> interface_instance_identifier();
    Ref<Constant_bit_selectContext> constant_bit_select();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Type_declarationContext> type_declaration();

  class Net_type_declarationContext : public ParserRuleContext {
  public:
    Net_type_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_typeContext> data_type();
    std::vector<Ref<Net_type_identifierContext>> net_type_identifier();
    Ref<Net_type_identifierContext> net_type_identifier(int i);
    Ref<Tf_identifierContext> tf_identifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Class_scopeContext> class_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_type_declarationContext> net_type_declaration();

  class LifetimeContext : public ParserRuleContext {
  public:
    LifetimeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<LifetimeContext> lifetime();

  class Casting_type_reducedContext : public ParserRuleContext {
  public:
    Casting_type_reducedContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_typeContext> simple_type();
    Ref<SigningContext> signing();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Casting_type_reducedContext> casting_type_reduced();

  class Casting_typeContext : public ParserRuleContext {
  public:
    Casting_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_typeContext> simple_type();
    Ref<Constant_primaryContext> constant_primary();
    Ref<SigningContext> signing();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Casting_typeContext> casting_type();

  class Data_typeContext : public ParserRuleContext {
  public:
    Data_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Integer_vector_typeContext> integer_vector_type();
    Ref<SigningContext> signing();
    std::vector<Ref<Packed_dimensionContext>> packed_dimension();
    Ref<Packed_dimensionContext> packed_dimension(int i);
    Ref<Integer_atom_typeContext> integer_atom_type();
    Ref<Non_integer_typeContext> non_integer_type();
    Ref<Struct_unionContext> struct_union();
    std::vector<Ref<Struct_union_memberContext>> struct_union_member();
    Ref<Struct_union_memberContext> struct_union_member(int i);
    std::vector<Ref<Enum_name_declarationContext>> enum_name_declaration();
    Ref<Enum_name_declarationContext> enum_name_declaration(int i);
    Ref<Enum_base_typeContext> enum_base_type();
    Ref<Interface_identifierContext> interface_identifier();
    Ref<Parameter_value_assignmentContext> parameter_value_assignment();
    Ref<Modport_identifierContext> modport_identifier();
    Ref<Type_identifierContext> type_identifier();
    Ref<Class_scopeContext> class_scope();
    Ref<Package_scopeContext> package_scope();
    Ref<Class_typeContext> class_type();
    Ref<Ps_covergroup_identifierContext> ps_covergroup_identifier();
    Ref<Type_referenceContext> type_reference();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Data_typeContext> data_type();

  class Data_type_or_implicitContext : public ParserRuleContext {
  public:
    Data_type_or_implicitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_typeContext> data_type();
    Ref<Implicit_data_typeContext> implicit_data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Data_type_or_implicitContext> data_type_or_implicit();

  class Implicit_data_typeContext : public ParserRuleContext {
  public:
    Implicit_data_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<SigningContext> signing();
    std::vector<Ref<Packed_dimensionContext>> packed_dimension();
    Ref<Packed_dimensionContext> packed_dimension(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Implicit_data_typeContext> implicit_data_type();

  class Enum_base_typeContext : public ParserRuleContext {
  public:
    Enum_base_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Integer_atom_typeContext> integer_atom_type();
    Ref<SigningContext> signing();
    Ref<Integer_vector_typeContext> integer_vector_type();
    Ref<Packed_dimensionContext> packed_dimension();
    Ref<Type_identifierContext> type_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Enum_base_typeContext> enum_base_type();

  class Enum_name_declarationContext : public ParserRuleContext {
  public:
    Enum_name_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Enum_identifierContext> enum_identifier();
    std::vector<Ref<tree::TerminalNode>> Integral_number();
    Ref<tree::TerminalNode> Integral_number(int i);
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Enum_name_declarationContext> enum_name_declaration();

  class Class_scopeContext : public ParserRuleContext {
  public:
    Class_scopeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Class_typeContext> class_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_scopeContext> class_scope();

  class Class_typeContext : public ParserRuleContext {
  public:
    Class_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_class_identifierContext> ps_class_identifier();
    std::vector<Ref<Parameter_value_assignmentContext>> parameter_value_assignment();
    Ref<Parameter_value_assignmentContext> parameter_value_assignment(int i);
    std::vector<Ref<Class_identifierContext>> class_identifier();
    Ref<Class_identifierContext> class_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_typeContext> class_type();

  class Integer_typeContext : public ParserRuleContext {
  public:
    Integer_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Integer_vector_typeContext> integer_vector_type();
    Ref<Integer_atom_typeContext> integer_atom_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Integer_typeContext> integer_type();

  class Integer_atom_typeContext : public ParserRuleContext {
  public:
    Integer_atom_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Integer_atom_typeContext> integer_atom_type();

  class Integer_vector_typeContext : public ParserRuleContext {
  public:
    Integer_vector_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Integer_vector_typeContext> integer_vector_type();

  class Non_integer_typeContext : public ParserRuleContext {
  public:
    Non_integer_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Non_integer_typeContext> non_integer_type();

  class Net_typeContext : public ParserRuleContext {
  public:
    Net_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_typeContext> net_type();

  class Net_port_typeContext : public ParserRuleContext {
  public:
    Net_port_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_implicitContext> data_type_or_implicit();
    Ref<Net_typeContext> net_type();
    Ref<Net_type_identifierContext> net_type_identifier();
    Ref<Implicit_data_typeContext> implicit_data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_port_typeContext> net_port_type();

  class Variable_port_typeContext : public ParserRuleContext {
  public:
    Variable_port_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Var_data_typeContext> var_data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Variable_port_typeContext> variable_port_type();

  class Var_data_typeContext : public ParserRuleContext {
  public:
    Var_data_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_typeContext> data_type();
    Ref<Data_type_or_implicitContext> data_type_or_implicit();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Var_data_typeContext> var_data_type();

  class SigningContext : public ParserRuleContext {
  public:
    SigningContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<SigningContext> signing();

  class Simple_typeContext : public ParserRuleContext {
  public:
    Simple_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Integer_typeContext> integer_type();
    Ref<Non_integer_typeContext> non_integer_type();
    Ref<Ps_type_identifierContext> ps_type_identifier();
    Ref<Ps_parameter_identifierContext> ps_parameter_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Simple_typeContext> simple_type();

  class Struct_union_memberContext : public ParserRuleContext {
  public:
    Struct_union_memberContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_voidContext> data_type_or_void();
    Ref<List_of_variable_decl_assignmentsContext> list_of_variable_decl_assignments();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Random_qualifierContext> random_qualifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Struct_union_memberContext> struct_union_member();

  class Data_type_or_voidContext : public ParserRuleContext {
  public:
    Data_type_or_voidContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_typeContext> data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Data_type_or_voidContext> data_type_or_void();

  class Struct_unionContext : public ParserRuleContext {
  public:
    Struct_unionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Struct_unionContext> struct_union();

  class Type_referenceContext : public ParserRuleContext {
  public:
    Type_referenceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Data_typeContext> data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Type_referenceContext> type_reference();

  class Drive_strengthContext : public ParserRuleContext {
  public:
    Drive_strengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Strength0Context> strength0();
    Ref<Strength1Context> strength1();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Drive_strengthContext> drive_strength();

  class Strength0Context : public ParserRuleContext {
  public:
    Strength0Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Strength0Context> strength0();

  class Strength1Context : public ParserRuleContext {
  public:
    Strength1Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Strength1Context> strength1();

  class Charge_strengthContext : public ParserRuleContext {
  public:
    Charge_strengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Charge_strengthContext> charge_strength();

  class Delay3Context : public ParserRuleContext {
  public:
    Delay3Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Delay_valueContext> delay_value();
    std::vector<Ref<Mintypmax_expressionContext>> mintypmax_expression();
    Ref<Mintypmax_expressionContext> mintypmax_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Delay3Context> delay3();

  class Delay2Context : public ParserRuleContext {
  public:
    Delay2Context(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Delay_valueContext> delay_value();
    std::vector<Ref<Mintypmax_expressionContext>> mintypmax_expression();
    Ref<Mintypmax_expressionContext> mintypmax_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Delay2Context> delay2();

  class Delay_valueContext : public ParserRuleContext {
  public:
    Delay_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Unsigned_number();
    Ref<tree::TerminalNode> Real_number();
    Ref<Ps_identifierContext> ps_identifier();
    Ref<Time_literalContext> time_literal();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Delay_valueContext> delay_value();

  class List_of_defparam_assignmentsContext : public ParserRuleContext {
  public:
    List_of_defparam_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Defparam_assignmentContext>> defparam_assignment();
    Ref<Defparam_assignmentContext> defparam_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_defparam_assignmentsContext> list_of_defparam_assignments();

  class List_of_genvar_identifiersContext : public ParserRuleContext {
  public:
    List_of_genvar_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Genvar_identifierContext>> genvar_identifier();
    Ref<Genvar_identifierContext> genvar_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_genvar_identifiersContext> list_of_genvar_identifiers();

  class List_of_interface_identifiersContext : public ParserRuleContext {
  public:
    List_of_interface_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Interface_identifierContext>> interface_identifier();
    Ref<Interface_identifierContext> interface_identifier(int i);
    std::vector<Ref<Unpacked_dimensionContext>> unpacked_dimension();
    Ref<Unpacked_dimensionContext> unpacked_dimension(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_interface_identifiersContext> list_of_interface_identifiers();

  class List_of_net_decl_assignmentsContext : public ParserRuleContext {
  public:
    List_of_net_decl_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Net_decl_assignmentContext>> net_decl_assignment();
    Ref<Net_decl_assignmentContext> net_decl_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_net_decl_assignmentsContext> list_of_net_decl_assignments();

  class List_of_param_assignmentsContext : public ParserRuleContext {
  public:
    List_of_param_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Param_assignmentContext>> param_assignment();
    Ref<Param_assignmentContext> param_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_param_assignmentsContext> list_of_param_assignments();

  class List_of_port_identifiersContext : public ParserRuleContext {
  public:
    List_of_port_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_identifierContext>> port_identifier();
    Ref<Port_identifierContext> port_identifier(int i);
    std::vector<Ref<Unpacked_dimensionContext>> unpacked_dimension();
    Ref<Unpacked_dimensionContext> unpacked_dimension(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_port_identifiersContext> list_of_port_identifiers();

  class List_of_udp_port_identifiersContext : public ParserRuleContext {
  public:
    List_of_udp_port_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_identifierContext>> port_identifier();
    Ref<Port_identifierContext> port_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_udp_port_identifiersContext> list_of_udp_port_identifiers();

  class List_of_specparam_assignmentsContext : public ParserRuleContext {
  public:
    List_of_specparam_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Specparam_assignmentContext>> specparam_assignment();
    Ref<Specparam_assignmentContext> specparam_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_specparam_assignmentsContext> list_of_specparam_assignments();

  class List_of_tf_variable_identifiersContext : public ParserRuleContext {
  public:
    List_of_tf_variable_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_identifierContext>> port_identifier();
    Ref<Port_identifierContext> port_identifier(int i);
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_tf_variable_identifiersContext> list_of_tf_variable_identifiers();

  class List_of_type_assignmentsContext : public ParserRuleContext {
  public:
    List_of_type_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Type_assignmentContext>> type_assignment();
    Ref<Type_assignmentContext> type_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_type_assignmentsContext> list_of_type_assignments();

  class List_of_variable_decl_assignmentsContext : public ParserRuleContext {
  public:
    List_of_variable_decl_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Variable_decl_assignmentContext>> variable_decl_assignment();
    Ref<Variable_decl_assignmentContext> variable_decl_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_variable_decl_assignmentsContext> list_of_variable_decl_assignments();

  class List_of_variable_identifiersContext : public ParserRuleContext {
  public:
    List_of_variable_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Variable_identifierContext>> variable_identifier();
    Ref<Variable_identifierContext> variable_identifier(int i);
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_variable_identifiersContext> list_of_variable_identifiers();

  class List_of_variable_port_identifiersContext : public ParserRuleContext {
  public:
    List_of_variable_port_identifiersContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Port_identifierContext>> port_identifier();
    Ref<Port_identifierContext> port_identifier(int i);
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_variable_port_identifiersContext> list_of_variable_port_identifiers();

  class Defparam_assignmentContext : public ParserRuleContext {
  public:
    Defparam_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_parameter_identifierContext> hierarchical_parameter_identifier();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Defparam_assignmentContext> defparam_assignment();

  class Net_decl_assignmentContext : public ParserRuleContext {
  public:
    Net_decl_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_identifierContext> net_identifier();
    std::vector<Ref<Unpacked_dimensionContext>> unpacked_dimension();
    Ref<Unpacked_dimensionContext> unpacked_dimension(int i);
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_decl_assignmentContext> net_decl_assignment();

  class Param_assignmentContext : public ParserRuleContext {
  public:
    Param_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parameter_identifierContext> parameter_identifier();
    std::vector<Ref<Unpacked_dimensionContext>> unpacked_dimension();
    Ref<Unpacked_dimensionContext> unpacked_dimension(int i);
    Ref<Constant_param_expressionContext> constant_param_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Param_assignmentContext> param_assignment();

  class Specparam_assignmentContext : public ParserRuleContext {
  public:
    Specparam_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Specparam_identifierContext> specparam_identifier();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();
    Ref<Pulse_control_specparamContext> pulse_control_specparam();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Specparam_assignmentContext> specparam_assignment();

  class Type_assignmentContext : public ParserRuleContext {
  public:
    Type_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Type_identifierContext> type_identifier();
    Ref<Data_typeContext> data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Type_assignmentContext> type_assignment();

  class Pulse_control_specparamContext : public ParserRuleContext {
  public:
    Pulse_control_specparamContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reject_limit_valueContext> reject_limit_value();
    Ref<Error_limit_valueContext> error_limit_value();
    Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor();
    Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pulse_control_specparamContext> pulse_control_specparam();

  class Error_limit_valueContext : public ParserRuleContext {
  public:
    Error_limit_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Limit_valueContext> limit_value();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Error_limit_valueContext> error_limit_value();

  class Reject_limit_valueContext : public ParserRuleContext {
  public:
    Reject_limit_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Limit_valueContext> limit_value();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Reject_limit_valueContext> reject_limit_value();

  class Limit_valueContext : public ParserRuleContext {
  public:
    Limit_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Limit_valueContext> limit_value();

  class Variable_decl_assignmentContext : public ParserRuleContext {
  public:
    Variable_decl_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    Ref<ExpressionContext> expression();
    Ref<Dynamic_array_variable_identifierContext> dynamic_array_variable_identifier();
    Ref<Unsized_dimensionContext> unsized_dimension();
    Ref<Dynamic_array_newContext> dynamic_array_new();
    Ref<Class_variable_identifierContext> class_variable_identifier();
    Ref<Class_newContext> class_new();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Variable_decl_assignmentContext> variable_decl_assignment();

  class Class_newContext : public ParserRuleContext {
  public:
    Class_newContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Class_scopeContext> class_scope();
    Ref<List_of_argumentsContext> list_of_arguments();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_newContext> class_new();

  class Dynamic_array_newContext : public ParserRuleContext {
  public:
    Dynamic_array_newContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dynamic_array_newContext> dynamic_array_new();

  class Unpacked_dimensionContext : public ParserRuleContext {
  public:
    Unpacked_dimensionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_rangeContext> constant_range();
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Unpacked_dimensionContext> unpacked_dimension();

  class Packed_dimensionContext : public ParserRuleContext {
  public:
    Packed_dimensionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_rangeContext> constant_range();
    Ref<Unsized_dimensionContext> unsized_dimension();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Packed_dimensionContext> packed_dimension();

  class Associative_dimensionContext : public ParserRuleContext {
  public:
    Associative_dimensionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_typeContext> data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Associative_dimensionContext> associative_dimension();

  class Variable_dimensionContext : public ParserRuleContext {
  public:
    Variable_dimensionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Unsized_dimensionContext> unsized_dimension();
    Ref<Unpacked_dimensionContext> unpacked_dimension();
    Ref<Associative_dimensionContext> associative_dimension();
    Ref<Queue_dimensionContext> queue_dimension();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Variable_dimensionContext> variable_dimension();

  class Queue_dimensionContext : public ParserRuleContext {
  public:
    Queue_dimensionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Queue_dimensionContext> queue_dimension();

  class Unsized_dimensionContext : public ParserRuleContext {
  public:
    Unsized_dimensionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Unsized_dimensionContext> unsized_dimension();

  class Function_data_type_or_implicitContext : public ParserRuleContext {
  public:
    Function_data_type_or_implicitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_voidContext> data_type_or_void();
    Ref<Implicit_data_typeContext> implicit_data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Function_data_type_or_implicitContext> function_data_type_or_implicit();

  class Function_declarationContext : public ParserRuleContext {
  public:
    Function_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_body_declarationContext> function_body_declaration();
    Ref<LifetimeContext> lifetime();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Function_declarationContext> function_declaration();

  class Function_body_declarationContext : public ParserRuleContext {
  public:
    Function_body_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_data_type_or_implicitContext> function_data_type_or_implicit();
    std::vector<Ref<Function_identifierContext>> function_identifier();
    Ref<Function_identifierContext> function_identifier(int i);
    Ref<Interface_identifierContext> interface_identifier();
    Ref<Class_scopeContext> class_scope();
    std::vector<Ref<Tf_item_declarationContext>> tf_item_declaration();
    Ref<Tf_item_declarationContext> tf_item_declaration(int i);
    std::vector<Ref<Function_statement_or_nullContext>> function_statement_or_null();
    Ref<Function_statement_or_nullContext> function_statement_or_null(int i);
    Ref<Tf_port_listContext> tf_port_list();
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Function_body_declarationContext> function_body_declaration();

  class Function_prototypeContext : public ParserRuleContext {
  public:
    Function_prototypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_voidContext> data_type_or_void();
    Ref<Function_identifierContext> function_identifier();
    Ref<Tf_port_listContext> tf_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Function_prototypeContext> function_prototype();

  class Dpi_import_exportContext : public ParserRuleContext {
  public:
    Dpi_import_exportContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Dpi_spec_stringContext> dpi_spec_string();
    Ref<Dpi_function_protoContext> dpi_function_proto();
    Ref<Dpi_function_import_propertyContext> dpi_function_import_property();
    Ref<C_identifierContext> c_identifier();
    Ref<Dpi_task_protoContext> dpi_task_proto();
    Ref<Dpi_task_import_propertyContext> dpi_task_import_property();
    Ref<Function_identifierContext> function_identifier();
    Ref<Task_identifierContext> task_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dpi_import_exportContext> dpi_import_export();

  class Dpi_spec_stringContext : public ParserRuleContext {
  public:
    Dpi_spec_stringContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dpi_spec_stringContext> dpi_spec_string();

  class Dpi_function_import_propertyContext : public ParserRuleContext {
  public:
    Dpi_function_import_propertyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dpi_function_import_propertyContext> dpi_function_import_property();

  class Dpi_task_import_propertyContext : public ParserRuleContext {
  public:
    Dpi_task_import_propertyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dpi_task_import_propertyContext> dpi_task_import_property();

  class Dpi_function_protoContext : public ParserRuleContext {
  public:
    Dpi_function_protoContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_prototypeContext> function_prototype();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dpi_function_protoContext> dpi_function_proto();

  class Dpi_task_protoContext : public ParserRuleContext {
  public:
    Dpi_task_protoContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Task_prototypeContext> task_prototype();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dpi_task_protoContext> dpi_task_proto();

  class Task_declarationContext : public ParserRuleContext {
  public:
    Task_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Task_body_declarationContext> task_body_declaration();
    Ref<LifetimeContext> lifetime();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Task_declarationContext> task_declaration();

  class Task_body_declarationContext : public ParserRuleContext {
  public:
    Task_body_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Task_identifierContext>> task_identifier();
    Ref<Task_identifierContext> task_identifier(int i);
    Ref<Interface_identifierContext> interface_identifier();
    Ref<Class_scopeContext> class_scope();
    std::vector<Ref<Tf_item_declarationContext>> tf_item_declaration();
    Ref<Tf_item_declarationContext> tf_item_declaration(int i);
    std::vector<Ref<Statement_or_nullContext>> statement_or_null();
    Ref<Statement_or_nullContext> statement_or_null(int i);
    Ref<Tf_port_listContext> tf_port_list();
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Task_body_declarationContext> task_body_declaration();

  class Tf_item_declarationContext : public ParserRuleContext {
  public:
    Tf_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_item_declarationContext> block_item_declaration();
    Ref<Tf_port_declarationContext> tf_port_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tf_item_declarationContext> tf_item_declaration();

  class Tf_port_listContext : public ParserRuleContext {
  public:
    Tf_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Tf_port_itemContext>> tf_port_item();
    Ref<Tf_port_itemContext> tf_port_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tf_port_listContext> tf_port_list();

  class Tf_port_itemContext : public ParserRuleContext {
  public:
    Tf_port_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_implicitContext> data_type_or_implicit();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Tf_port_directionContext> tf_port_direction();
    Ref<Port_identifierContext> port_identifier();
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tf_port_itemContext> tf_port_item();

  class Tf_port_directionContext : public ParserRuleContext {
  public:
    Tf_port_directionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_directionContext> port_direction();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tf_port_directionContext> tf_port_direction();

  class Tf_port_declarationContext : public ParserRuleContext {
  public:
    Tf_port_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Tf_port_directionContext> tf_port_direction();
    Ref<Data_type_or_implicitContext> data_type_or_implicit();
    Ref<List_of_tf_variable_identifiersContext> list_of_tf_variable_identifiers();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tf_port_declarationContext> tf_port_declaration();

  class Task_prototypeContext : public ParserRuleContext {
  public:
    Task_prototypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Task_identifierContext> task_identifier();
    Ref<Tf_port_listContext> tf_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Task_prototypeContext> task_prototype();

  class Block_item_declarationContext : public ParserRuleContext {
  public:
    Block_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_declarationContext> data_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Local_parameter_declarationContext> local_parameter_declaration();
    Ref<Parameter_declarationContext> parameter_declaration();
    Ref<Overload_declarationContext> overload_declaration();
    Ref<Let_declarationContext> let_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Block_item_declarationContext> block_item_declaration();

  class Overload_declarationContext : public ParserRuleContext {
  public:
    Overload_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Overload_operatorContext> overload_operator();
    Ref<Data_typeContext> data_type();
    Ref<Function_identifierContext> function_identifier();
    Ref<Overload_proto_formalsContext> overload_proto_formals();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Overload_declarationContext> overload_declaration();

  class Overload_operatorContext : public ParserRuleContext {
  public:
    Overload_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Overload_operatorContext> overload_operator();

  class Overload_proto_formalsContext : public ParserRuleContext {
  public:
    Overload_proto_formalsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Data_typeContext>> data_type();
    Ref<Data_typeContext> data_type(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Overload_proto_formalsContext> overload_proto_formals();

  class Modport_declarationContext : public ParserRuleContext {
  public:
    Modport_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Modport_itemContext>> modport_item();
    Ref<Modport_itemContext> modport_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_declarationContext> modport_declaration();

  class Modport_itemContext : public ParserRuleContext {
  public:
    Modport_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Modport_identifierContext> modport_identifier();
    std::vector<Ref<Modport_ports_declarationContext>> modport_ports_declaration();
    Ref<Modport_ports_declarationContext> modport_ports_declaration(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_itemContext> modport_item();

  class Modport_ports_declarationContext : public ParserRuleContext {
  public:
    Modport_ports_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Modport_simple_ports_declarationContext> modport_simple_ports_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Modport_tf_ports_declarationContext> modport_tf_ports_declaration();
    Ref<Modport_clocking_declarationContext> modport_clocking_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_ports_declarationContext> modport_ports_declaration();

  class Modport_clocking_declarationContext : public ParserRuleContext {
  public:
    Modport_clocking_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Clocking_identifierContext> clocking_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_clocking_declarationContext> modport_clocking_declaration();

  class Modport_simple_ports_declarationContext : public ParserRuleContext {
  public:
    Modport_simple_ports_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_directionContext> port_direction();
    std::vector<Ref<Modport_simple_portContext>> modport_simple_port();
    Ref<Modport_simple_portContext> modport_simple_port(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_simple_ports_declarationContext> modport_simple_ports_declaration();

  class Modport_simple_portContext : public ParserRuleContext {
  public:
    Modport_simple_portContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_identifierContext> port_identifier();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_simple_portContext> modport_simple_port();

  class Modport_tf_ports_declarationContext : public ParserRuleContext {
  public:
    Modport_tf_ports_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Import_exportContext> import_export();
    std::vector<Ref<Modport_tf_portContext>> modport_tf_port();
    Ref<Modport_tf_portContext> modport_tf_port(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_tf_ports_declarationContext> modport_tf_ports_declaration();

  class Modport_tf_portContext : public ParserRuleContext {
  public:
    Modport_tf_portContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Method_prototypeContext> method_prototype();
    Ref<Tf_identifierContext> tf_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_tf_portContext> modport_tf_port();

  class Import_exportContext : public ParserRuleContext {
  public:
    Import_exportContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Import_exportContext> import_export();

  class Concurrent_assertion_itemContext : public ParserRuleContext {
  public:
    Concurrent_assertion_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Concurrent_assertion_statementContext> concurrent_assertion_statement();
    Ref<Block_identifierContext> block_identifier();
    Ref<Checker_instantiationContext> checker_instantiation();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Concurrent_assertion_itemContext> concurrent_assertion_item();

  class Concurrent_assertion_statementContext : public ParserRuleContext {
  public:
    Concurrent_assertion_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Assert_property_statementContext> assert_property_statement();
    Ref<Assume_property_statementContext> assume_property_statement();
    Ref<Cover_property_statementContext> cover_property_statement();
    Ref<Cover_sequence_statementContext> cover_sequence_statement();
    Ref<Restrict_property_statementContext> restrict_property_statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Concurrent_assertion_statementContext> concurrent_assertion_statement();

  class Assert_property_statementContext : public ParserRuleContext {
  public:
    Assert_property_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_specContext> property_spec();
    Ref<Action_blockContext> action_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assert_property_statementContext> assert_property_statement();

  class Assume_property_statementContext : public ParserRuleContext {
  public:
    Assume_property_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_specContext> property_spec();
    Ref<Action_blockContext> action_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assume_property_statementContext> assume_property_statement();

  class Cover_property_statementContext : public ParserRuleContext {
  public:
    Cover_property_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_specContext> property_spec();
    Ref<Statement_or_nullContext> statement_or_null();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cover_property_statementContext> cover_property_statement();

  class Expect_property_statementContext : public ParserRuleContext {
  public:
    Expect_property_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_specContext> property_spec();
    Ref<Action_blockContext> action_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Expect_property_statementContext> expect_property_statement();

  class Cover_sequence_statementContext : public ParserRuleContext {
  public:
    Cover_sequence_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Sequence_exprContext> sequence_expr();
    Ref<Statement_or_nullContext> statement_or_null();
    Ref<Clocking_eventContext> clocking_event();
    Ref<Expression_or_distContext> expression_or_dist();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cover_sequence_statementContext> cover_sequence_statement();

  class Restrict_property_statementContext : public ParserRuleContext {
  public:
    Restrict_property_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_specContext> property_spec();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Restrict_property_statementContext> restrict_property_statement();

  class Property_instanceContext : public ParserRuleContext {
  public:
    Property_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_or_hierarchical_property_identifierContext> ps_or_hierarchical_property_identifier();
    Ref<Property_list_of_argumentsContext> property_list_of_arguments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_instanceContext> property_instance();

  class Property_list_of_argumentsContext : public ParserRuleContext {
  public:
    Property_list_of_argumentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Property_actual_argContext>> property_actual_arg();
    Ref<Property_actual_argContext> property_actual_arg(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_list_of_argumentsContext> property_list_of_arguments();

  class Property_actual_argContext : public ParserRuleContext {
  public:
    Property_actual_argContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_exprContext> property_expr();
    Ref<Sequence_actual_argContext> sequence_actual_arg();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_actual_argContext> property_actual_arg();

  class Assertion_item_declarationContext : public ParserRuleContext {
  public:
    Assertion_item_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_declarationContext> property_declaration();
    Ref<Sequence_declarationContext> sequence_declaration();
    Ref<Let_declarationContext> let_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assertion_item_declarationContext> assertion_item_declaration();

  class Property_declarationContext : public ParserRuleContext {
  public:
    Property_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Property_identifierContext>> property_identifier();
    Ref<Property_identifierContext> property_identifier(int i);
    Ref<Property_specContext> property_spec();
    std::vector<Ref<Assertion_variable_declarationContext>> assertion_variable_declaration();
    Ref<Assertion_variable_declarationContext> assertion_variable_declaration(int i);
    Ref<Property_port_listContext> property_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_declarationContext> property_declaration();

  class Property_port_listContext : public ParserRuleContext {
  public:
    Property_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Property_port_itemContext>> property_port_item();
    Ref<Property_port_itemContext> property_port_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_port_listContext> property_port_list();

  class Property_port_itemContext : public ParserRuleContext {
  public:
    Property_port_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_formal_typeContext> property_formal_type();
    Ref<Formal_port_identifierContext> formal_port_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    Ref<Property_actual_argContext> property_actual_arg();
    Ref<Property_lvar_port_directionContext> property_lvar_port_direction();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_port_itemContext> property_port_item();

  class Property_lvar_port_directionContext : public ParserRuleContext {
  public:
    Property_lvar_port_directionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_lvar_port_directionContext> property_lvar_port_direction();

  class Property_formal_typeContext : public ParserRuleContext {
  public:
    Property_formal_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Sequence_formal_typeContext> sequence_formal_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_formal_typeContext> property_formal_type();

  class Property_specContext : public ParserRuleContext {
  public:
    Property_specContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_exprContext> property_expr();
    Ref<Clocking_eventContext> clocking_event();
    Ref<Expression_or_distContext> expression_or_dist();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_specContext> property_spec();

  class Property_exprContext : public ParserRuleContext {
  public:
    Property_exprContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Sequence_exprContext> sequence_expr();
    std::vector<Ref<Property_exprContext>> property_expr();
    Ref<Property_exprContext> property_expr(int i);
    Ref<Expression_or_distContext> expression_or_dist();
    std::vector<Ref<Property_case_itemContext>> property_case_item();
    Ref<Property_case_itemContext> property_case_item(int i);
    Ref<Constant_expressionContext> constant_expression();
    Ref<Cycle_delay_const_range_expressionContext> cycle_delay_const_range_expression();
    Ref<Constant_rangeContext> constant_range();
    Ref<Property_instanceContext> property_instance();
    Ref<Clocking_eventContext> clocking_event();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_exprContext> property_expr();
  Ref<Property_exprContext> property_expr(int precedence);
  class Property_case_itemContext : public ParserRuleContext {
  public:
    Property_case_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Expression_or_distContext>> expression_or_dist();
    Ref<Expression_or_distContext> expression_or_dist(int i);
    Ref<Property_exprContext> property_expr();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_case_itemContext> property_case_item();

  class Sequence_declarationContext : public ParserRuleContext {
  public:
    Sequence_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Sequence_identifierContext>> sequence_identifier();
    Ref<Sequence_identifierContext> sequence_identifier(int i);
    Ref<Sequence_exprContext> sequence_expr();
    std::vector<Ref<Assertion_variable_declarationContext>> assertion_variable_declaration();
    Ref<Assertion_variable_declarationContext> assertion_variable_declaration(int i);
    Ref<Sequence_port_listContext> sequence_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_declarationContext> sequence_declaration();

  class Sequence_port_listContext : public ParserRuleContext {
  public:
    Sequence_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Sequence_port_itemContext>> sequence_port_item();
    Ref<Sequence_port_itemContext> sequence_port_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_port_listContext> sequence_port_list();

  class Sequence_port_itemContext : public ParserRuleContext {
  public:
    Sequence_port_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Sequence_formal_typeContext> sequence_formal_type();
    Ref<Formal_port_identifierContext> formal_port_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    Ref<Sequence_actual_argContext> sequence_actual_arg();
    Ref<Sequence_lvar_port_directionContext> sequence_lvar_port_direction();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_port_itemContext> sequence_port_item();

  class Sequence_lvar_port_directionContext : public ParserRuleContext {
  public:
    Sequence_lvar_port_directionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_lvar_port_directionContext> sequence_lvar_port_direction();

  class Sequence_formal_typeContext : public ParserRuleContext {
  public:
    Sequence_formal_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_implicitContext> data_type_or_implicit();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_formal_typeContext> sequence_formal_type();

  class Sequence_exprContext : public ParserRuleContext {
  public:
    Sequence_exprContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Cycle_delay_rangeContext>> cycle_delay_range();
    Ref<Cycle_delay_rangeContext> cycle_delay_range(int i);
    std::vector<Ref<Sequence_exprContext>> sequence_expr();
    Ref<Sequence_exprContext> sequence_expr(int i);
    Ref<Expression_or_distContext> expression_or_dist();
    Ref<Boolean_abbrevContext> boolean_abbrev();
    Ref<Sequence_instanceContext> sequence_instance();
    Ref<Sequence_abbrevContext> sequence_abbrev();
    std::vector<Ref<Sequence_match_itemContext>> sequence_match_item();
    Ref<Sequence_match_itemContext> sequence_match_item(int i);
    Ref<Clocking_eventContext> clocking_event();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_exprContext> sequence_expr();
  Ref<Sequence_exprContext> sequence_expr(int precedence);
  class Cycle_delay_rangeContext : public ParserRuleContext {
  public:
    Cycle_delay_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_primaryContext> constant_primary();
    Ref<Cycle_delay_const_range_expressionContext> cycle_delay_const_range_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cycle_delay_rangeContext> cycle_delay_range();

  class Sequence_method_callContext : public ParserRuleContext {
  public:
    Sequence_method_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Sequence_instanceContext> sequence_instance();
    Ref<Method_identifierContext> method_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_method_callContext> sequence_method_call();

  class Sequence_match_itemContext : public ParserRuleContext {
  public:
    Sequence_match_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Operator_assignmentContext> operator_assignment();
    Ref<Inc_or_dec_expressionContext> inc_or_dec_expression();
    Ref<Subroutine_callContext> subroutine_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_match_itemContext> sequence_match_item();

  class Sequence_instanceContext : public ParserRuleContext {
  public:
    Sequence_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_or_hierarchical_sequence_identifierContext> ps_or_hierarchical_sequence_identifier();
    Ref<Sequence_list_of_argumentsContext> sequence_list_of_arguments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_instanceContext> sequence_instance();

  class Sequence_list_of_argumentsContext : public ParserRuleContext {
  public:
    Sequence_list_of_argumentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Sequence_actual_argContext>> sequence_actual_arg();
    Ref<Sequence_actual_argContext> sequence_actual_arg(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_list_of_argumentsContext> sequence_list_of_arguments();

  class Sequence_actual_argContext : public ParserRuleContext {
  public:
    Sequence_actual_argContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Event_expressionContext> event_expression();
    Ref<Sequence_exprContext> sequence_expr();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_actual_argContext> sequence_actual_arg();

  class Boolean_abbrevContext : public ParserRuleContext {
  public:
    Boolean_abbrevContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Consecutive_repetitionContext> consecutive_repetition();
    Ref<Non_consecutive_repetitionContext> non_consecutive_repetition();
    Ref<Goto_repetitionContext> goto_repetition();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Boolean_abbrevContext> boolean_abbrev();

  class Sequence_abbrevContext : public ParserRuleContext {
  public:
    Sequence_abbrevContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Consecutive_repetitionContext> consecutive_repetition();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_abbrevContext> sequence_abbrev();

  class Consecutive_repetitionContext : public ParserRuleContext {
  public:
    Consecutive_repetitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Const_or_range_expressionContext> const_or_range_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Consecutive_repetitionContext> consecutive_repetition();

  class Non_consecutive_repetitionContext : public ParserRuleContext {
  public:
    Non_consecutive_repetitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Const_or_range_expressionContext> const_or_range_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Non_consecutive_repetitionContext> non_consecutive_repetition();

  class Goto_repetitionContext : public ParserRuleContext {
  public:
    Goto_repetitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Const_or_range_expressionContext> const_or_range_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Goto_repetitionContext> goto_repetition();

  class Const_or_range_expressionContext : public ParserRuleContext {
  public:
    Const_or_range_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<Cycle_delay_const_range_expressionContext> cycle_delay_const_range_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Const_or_range_expressionContext> const_or_range_expression();

  class Cycle_delay_const_range_expressionContext : public ParserRuleContext {
  public:
    Cycle_delay_const_range_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cycle_delay_const_range_expressionContext> cycle_delay_const_range_expression();

  class Expression_or_distContext : public ParserRuleContext {
  public:
    Expression_or_distContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Dist_listContext> dist_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Expression_or_distContext> expression_or_dist();

  class Assertion_variable_declarationContext : public ParserRuleContext {
  public:
    Assertion_variable_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Var_data_typeContext> var_data_type();
    Ref<List_of_variable_decl_assignmentsContext> list_of_variable_decl_assignments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assertion_variable_declarationContext> assertion_variable_declaration();

  class Let_declarationContext : public ParserRuleContext {
  public:
    Let_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Let_identifierContext> let_identifier();
    Ref<ExpressionContext> expression();
    Ref<Let_port_listContext> let_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Let_declarationContext> let_declaration();

  class Let_identifierContext : public ParserRuleContext {
  public:
    Let_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Let_identifierContext> let_identifier();

  class Let_port_listContext : public ParserRuleContext {
  public:
    Let_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Let_port_itemContext>> let_port_item();
    Ref<Let_port_itemContext> let_port_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Let_port_listContext> let_port_list();

  class Let_port_itemContext : public ParserRuleContext {
  public:
    Let_port_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Let_formal_typeContext> let_formal_type();
    Ref<Formal_port_identifierContext> formal_port_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    std::vector<Ref<Variable_dimensionContext>> variable_dimension();
    Ref<Variable_dimensionContext> variable_dimension(int i);
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Let_port_itemContext> let_port_item();

  class Let_formal_typeContext : public ParserRuleContext {
  public:
    Let_formal_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_type_or_implicitContext> data_type_or_implicit();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Let_formal_typeContext> let_formal_type();

  class Let_expressionContext : public ParserRuleContext {
  public:
    Let_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Let_identifierContext> let_identifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Let_list_of_argumentsContext> let_list_of_arguments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Let_expressionContext> let_expression();

  class Let_list_of_argumentsContext : public ParserRuleContext {
  public:
    Let_list_of_argumentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Let_actual_argContext>> let_actual_arg();
    Ref<Let_actual_argContext> let_actual_arg(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Let_list_of_argumentsContext> let_list_of_arguments();

  class Let_actual_argContext : public ParserRuleContext {
  public:
    Let_actual_argContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Let_actual_argContext> let_actual_arg();

  class Covergroup_declarationContext : public ParserRuleContext {
  public:
    Covergroup_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Covergroup_identifierContext>> covergroup_identifier();
    Ref<Covergroup_identifierContext> covergroup_identifier(int i);
    Ref<Tf_port_listContext> tf_port_list();
    Ref<Coverage_eventContext> coverage_event();
    std::vector<Ref<Coverage_spec_or_optionContext>> coverage_spec_or_option();
    Ref<Coverage_spec_or_optionContext> coverage_spec_or_option(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Covergroup_declarationContext> covergroup_declaration();

  class Coverage_spec_or_optionContext : public ParserRuleContext {
  public:
    Coverage_spec_or_optionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Coverage_specContext> coverage_spec();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Coverage_optionContext> coverage_option();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Coverage_spec_or_optionContext> coverage_spec_or_option();

  class Coverage_optionContext : public ParserRuleContext {
  public:
    Coverage_optionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Member_identifierContext> member_identifier();
    Ref<ExpressionContext> expression();
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Coverage_optionContext> coverage_option();

  class Coverage_specContext : public ParserRuleContext {
  public:
    Coverage_specContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cover_pointContext> cover_point();
    Ref<Cover_crossContext> cover_cross();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Coverage_specContext> coverage_spec();

  class Coverage_eventContext : public ParserRuleContext {
  public:
    Coverage_eventContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Clocking_eventContext> clocking_event();
    Ref<Tf_port_listContext> tf_port_list();
    Ref<Block_event_expressionContext> block_event_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Coverage_eventContext> coverage_event();

  class Block_event_expressionContext : public ParserRuleContext {
  public:
    Block_event_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_btf_identifierContext> hierarchical_btf_identifier();
    std::vector<Ref<Block_event_expressionContext>> block_event_expression();
    Ref<Block_event_expressionContext> block_event_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Block_event_expressionContext> block_event_expression();
  Ref<Block_event_expressionContext> block_event_expression(int precedence);
  class Hierarchical_btf_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_btf_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_tf_identifierContext> hierarchical_tf_identifier();
    Ref<Hierarchical_block_identifierContext> hierarchical_block_identifier();
    Ref<Method_identifierContext> method_identifier();
    Ref<Hierarchical_identifierContext> hierarchical_identifier();
    Ref<Class_scopeContext> class_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_btf_identifierContext> hierarchical_btf_identifier();

  class Cover_pointContext : public ParserRuleContext {
  public:
    Cover_pointContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Bins_or_emptyContext> bins_or_empty();
    Ref<Data_type_or_implicitContext> data_type_or_implicit();
    Ref<Cover_point_identifierContext> cover_point_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cover_pointContext> cover_point();

  class Bins_or_emptyContext : public ParserRuleContext {
  public:
    Bins_or_emptyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    std::vector<Ref<Bins_or_optionsContext>> bins_or_options();
    Ref<Bins_or_optionsContext> bins_or_options(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bins_or_emptyContext> bins_or_empty();

  class Bins_or_optionsContext : public ParserRuleContext {
  public:
    Bins_or_optionsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Coverage_optionContext> coverage_option();
    Ref<Bins_keywordContext> bins_keyword();
    Ref<Bin_identifierContext> bin_identifier();
    Ref<Covergroup_range_listContext> covergroup_range_list();
    Ref<With_covergroup_expressionContext> with_covergroup_expression();
    Ref<ExpressionContext> expression();
    Ref<Covergroup_expressionContext> covergroup_expression();
    Ref<Cover_point_identifierContext> cover_point_identifier();
    Ref<Set_covergroup_expressionContext> set_covergroup_expression();
    Ref<Trans_listContext> trans_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bins_or_optionsContext> bins_or_options();

  class Bins_keywordContext : public ParserRuleContext {
  public:
    Bins_keywordContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bins_keywordContext> bins_keyword();

  class Trans_listContext : public ParserRuleContext {
  public:
    Trans_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Trans_setContext>> trans_set();
    Ref<Trans_setContext> trans_set(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Trans_listContext> trans_list();

  class Trans_setContext : public ParserRuleContext {
  public:
    Trans_setContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Trans_range_listContext>> trans_range_list();
    Ref<Trans_range_listContext> trans_range_list(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Trans_setContext> trans_set();

  class Trans_range_listContext : public ParserRuleContext {
  public:
    Trans_range_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Trans_itemContext> trans_item();
    Ref<Repeat_rangeContext> repeat_range();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Trans_range_listContext> trans_range_list();

  class Trans_itemContext : public ParserRuleContext {
  public:
    Trans_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Covergroup_range_listContext> covergroup_range_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Trans_itemContext> trans_item();

  class Repeat_rangeContext : public ParserRuleContext {
  public:
    Repeat_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Covergroup_expressionContext>> covergroup_expression();
    Ref<Covergroup_expressionContext> covergroup_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Repeat_rangeContext> repeat_range();

  class Cover_crossContext : public ParserRuleContext {
  public:
    Cover_crossContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_cross_itemsContext> list_of_cross_items();
    Ref<Cross_bodyContext> cross_body();
    Ref<Cross_identifierContext> cross_identifier();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cover_crossContext> cover_cross();

  class List_of_cross_itemsContext : public ParserRuleContext {
  public:
    List_of_cross_itemsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Cross_itemContext>> cross_item();
    Ref<Cross_itemContext> cross_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_cross_itemsContext> list_of_cross_items();

  class Cross_itemContext : public ParserRuleContext {
  public:
    Cross_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cover_point_identifierContext> cover_point_identifier();
    Ref<Variable_identifierContext> variable_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cross_itemContext> cross_item();

  class Cross_bodyContext : public ParserRuleContext {
  public:
    Cross_bodyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Cross_body_itemContext>> cross_body_item();
    Ref<Cross_body_itemContext> cross_body_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cross_bodyContext> cross_body();

  class Cross_body_itemContext : public ParserRuleContext {
  public:
    Cross_body_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_declarationContext> function_declaration();
    Ref<Bins_selection_or_optionContext> bins_selection_or_option();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cross_body_itemContext> cross_body_item();

  class Bins_selection_or_optionContext : public ParserRuleContext {
  public:
    Bins_selection_or_optionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Coverage_optionContext> coverage_option();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Bins_selectionContext> bins_selection();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bins_selection_or_optionContext> bins_selection_or_option();

  class Bins_selectionContext : public ParserRuleContext {
  public:
    Bins_selectionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Bins_keywordContext> bins_keyword();
    Ref<Bin_identifierContext> bin_identifier();
    Ref<Select_expressionContext> select_expression();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bins_selectionContext> bins_selection();

  class Select_expressionContext : public ParserRuleContext {
  public:
    Select_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Select_conditionContext> select_condition();
    std::vector<Ref<Select_expressionContext>> select_expression();
    Ref<Select_expressionContext> select_expression(int i);
    Ref<Cross_identifierContext> cross_identifier();
    Ref<Cross_set_expressionContext> cross_set_expression();
    Ref<Integer_covergroup_expressionContext> integer_covergroup_expression();
    Ref<With_covergroup_expressionContext> with_covergroup_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Select_expressionContext> select_expression();
  Ref<Select_expressionContext> select_expression(int precedence);
  class Select_conditionContext : public ParserRuleContext {
  public:
    Select_conditionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Bins_expressionContext> bins_expression();
    Ref<Covergroup_range_listContext> covergroup_range_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Select_conditionContext> select_condition();

  class Bins_expressionContext : public ParserRuleContext {
  public:
    Bins_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();
    Ref<Cover_point_identifierContext> cover_point_identifier();
    Ref<Bin_identifierContext> bin_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bins_expressionContext> bins_expression();

  class Covergroup_range_listContext : public ParserRuleContext {
  public:
    Covergroup_range_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Covergroup_value_rangeContext>> covergroup_value_range();
    Ref<Covergroup_value_rangeContext> covergroup_value_range(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Covergroup_range_listContext> covergroup_range_list();

  class Covergroup_value_rangeContext : public ParserRuleContext {
  public:
    Covergroup_value_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Covergroup_expressionContext>> covergroup_expression();
    Ref<Covergroup_expressionContext> covergroup_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Covergroup_value_rangeContext> covergroup_value_range();

  class With_covergroup_expressionContext : public ParserRuleContext {
  public:
    With_covergroup_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Covergroup_expressionContext> covergroup_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<With_covergroup_expressionContext> with_covergroup_expression();

  class Set_covergroup_expressionContext : public ParserRuleContext {
  public:
    Set_covergroup_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Covergroup_expressionContext> covergroup_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Set_covergroup_expressionContext> set_covergroup_expression();

  class Integer_covergroup_expressionContext : public ParserRuleContext {
  public:
    Integer_covergroup_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Covergroup_expressionContext> covergroup_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Integer_covergroup_expressionContext> integer_covergroup_expression();

  class Cross_set_expressionContext : public ParserRuleContext {
  public:
    Cross_set_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Covergroup_expressionContext> covergroup_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cross_set_expressionContext> cross_set_expression();

  class Covergroup_expressionContext : public ParserRuleContext {
  public:
    Covergroup_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Covergroup_expressionContext> covergroup_expression();

  class Gate_instantiationContext : public ParserRuleContext {
  public:
    Gate_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cmos_switchtypeContext> cmos_switchtype();
    std::vector<Ref<Cmos_switch_instanceContext>> cmos_switch_instance();
    Ref<Cmos_switch_instanceContext> cmos_switch_instance(int i);
    Ref<Delay3Context> delay3();
    Ref<Enable_gatetypeContext> enable_gatetype();
    std::vector<Ref<Enable_gate_instanceContext>> enable_gate_instance();
    Ref<Enable_gate_instanceContext> enable_gate_instance(int i);
    Ref<Drive_strengthContext> drive_strength();
    Ref<Mos_switchtypeContext> mos_switchtype();
    std::vector<Ref<Mos_switch_instanceContext>> mos_switch_instance();
    Ref<Mos_switch_instanceContext> mos_switch_instance(int i);
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
    Ref<Pass_switchtypeContext> pass_switchtype();
    std::vector<Ref<Pass_switch_instanceContext>> pass_switch_instance();
    Ref<Pass_switch_instanceContext> pass_switch_instance(int i);
    std::vector<Ref<Pull_gate_instanceContext>> pull_gate_instance();
    Ref<Pull_gate_instanceContext> pull_gate_instance(int i);
    Ref<Pulldown_strengthContext> pulldown_strength();
    Ref<Pullup_strengthContext> pullup_strength();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cmos_switch_instanceContext> cmos_switch_instance();

  class Enable_gate_instanceContext : public ParserRuleContext {
  public:
    Enable_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    Ref<Input_terminalContext> input_terminal();
    Ref<Enable_terminalContext> enable_terminal();
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Enable_gate_instanceContext> enable_gate_instance();

  class Mos_switch_instanceContext : public ParserRuleContext {
  public:
    Mos_switch_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    Ref<Input_terminalContext> input_terminal();
    Ref<Enable_terminalContext> enable_terminal();
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Mos_switch_instanceContext> mos_switch_instance();

  class N_input_gate_instanceContext : public ParserRuleContext {
  public:
    N_input_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    std::vector<Ref<Input_terminalContext>> input_terminal();
    Ref<Input_terminalContext> input_terminal(int i);
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<N_input_gate_instanceContext> n_input_gate_instance();

  class N_output_gate_instanceContext : public ParserRuleContext {
  public:
    N_output_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Output_terminalContext>> output_terminal();
    Ref<Output_terminalContext> output_terminal(int i);
    Ref<Input_terminalContext> input_terminal();
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<N_output_gate_instanceContext> n_output_gate_instance();

  class Pass_switch_instanceContext : public ParserRuleContext {
  public:
    Pass_switch_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Inout_terminalContext>> inout_terminal();
    Ref<Inout_terminalContext> inout_terminal(int i);
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pass_switch_instanceContext> pass_switch_instance();

  class Pass_enable_switch_instanceContext : public ParserRuleContext {
  public:
    Pass_enable_switch_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Inout_terminalContext>> inout_terminal();
    Ref<Inout_terminalContext> inout_terminal(int i);
    Ref<Enable_terminalContext> enable_terminal();
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pass_enable_switch_instanceContext> pass_enable_switch_instance();

  class Pull_gate_instanceContext : public ParserRuleContext {
  public:
    Pull_gate_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pull_gate_instanceContext> pull_gate_instance();

  class Pulldown_strengthContext : public ParserRuleContext {
  public:
    Pulldown_strengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Strength0Context> strength0();
    Ref<Strength1Context> strength1();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pulldown_strengthContext> pulldown_strength();

  class Pullup_strengthContext : public ParserRuleContext {
  public:
    Pullup_strengthContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Strength0Context> strength0();
    Ref<Strength1Context> strength1();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pullup_strengthContext> pullup_strength();

  class Enable_terminalContext : public ParserRuleContext {
  public:
    Enable_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Enable_terminalContext> enable_terminal();

  class Inout_terminalContext : public ParserRuleContext {
  public:
    Inout_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_lvalueContext> net_lvalue();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Inout_terminalContext> inout_terminal();

  class Input_terminalContext : public ParserRuleContext {
  public:
    Input_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Input_terminalContext> input_terminal();

  class Ncontrol_terminalContext : public ParserRuleContext {
  public:
    Ncontrol_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ncontrol_terminalContext> ncontrol_terminal();

  class Output_terminalContext : public ParserRuleContext {
  public:
    Output_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_lvalueContext> net_lvalue();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Output_terminalContext> output_terminal();

  class Pcontrol_terminalContext : public ParserRuleContext {
  public:
    Pcontrol_terminalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pcontrol_terminalContext> pcontrol_terminal();

  class Cmos_switchtypeContext : public ParserRuleContext {
  public:
    Cmos_switchtypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cmos_switchtypeContext> cmos_switchtype();

  class Enable_gatetypeContext : public ParserRuleContext {
  public:
    Enable_gatetypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Enable_gatetypeContext> enable_gatetype();

  class Mos_switchtypeContext : public ParserRuleContext {
  public:
    Mos_switchtypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Mos_switchtypeContext> mos_switchtype();

  class N_input_gatetypeContext : public ParserRuleContext {
  public:
    N_input_gatetypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<N_input_gatetypeContext> n_input_gatetype();

  class N_output_gatetypeContext : public ParserRuleContext {
  public:
    N_output_gatetypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<N_output_gatetypeContext> n_output_gatetype();

  class Pass_en_switchtypeContext : public ParserRuleContext {
  public:
    Pass_en_switchtypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pass_en_switchtypeContext> pass_en_switchtype();

  class Pass_switchtypeContext : public ParserRuleContext {
  public:
    Pass_switchtypeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pass_switchtypeContext> pass_switchtype();

  class Module_instantiationContext : public ParserRuleContext {
  public:
    Module_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_identifierContext> module_identifier();
    std::vector<Ref<Hierarchical_instanceContext>> hierarchical_instance();
    Ref<Hierarchical_instanceContext> hierarchical_instance(int i);
    Ref<Parameter_value_assignmentContext> parameter_value_assignment();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_instantiationContext> module_instantiation();

  class Parameter_value_assignmentContext : public ParserRuleContext {
  public:
    Parameter_value_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_parameter_assignmentsContext> list_of_parameter_assignments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_parameter_assignmentsContext> list_of_parameter_assignments();

  class Ordered_parameter_assignmentContext : public ParserRuleContext {
  public:
    Ordered_parameter_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Param_expressionContext> param_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ordered_parameter_assignmentContext> ordered_parameter_assignment();

  class Named_parameter_assignmentContext : public ParserRuleContext {
  public:
    Named_parameter_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parameter_identifierContext> parameter_identifier();
    Ref<Param_expressionContext> param_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Named_parameter_assignmentContext> named_parameter_assignment();

  class Hierarchical_instanceContext : public ParserRuleContext {
  public:
    Hierarchical_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Name_of_instanceContext> name_of_instance();
    Ref<List_of_port_connectionsContext> list_of_port_connections();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_instanceContext> hierarchical_instance();

  class Name_of_instanceContext : public ParserRuleContext {
  public:
    Name_of_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Instance_identifierContext> instance_identifier();
    std::vector<Ref<Unpacked_dimensionContext>> unpacked_dimension();
    Ref<Unpacked_dimensionContext> unpacked_dimension(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_port_connectionsContext> list_of_port_connections();

  class Ordered_port_connectionContext : public ParserRuleContext {
  public:
    Ordered_port_connectionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Named_port_connectionContext> named_port_connection();

  class Interface_instantiationContext : public ParserRuleContext {
  public:
    Interface_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_identifierContext> interface_identifier();
    std::vector<Ref<Hierarchical_instanceContext>> hierarchical_instance();
    Ref<Hierarchical_instanceContext> hierarchical_instance(int i);
    Ref<Parameter_value_assignmentContext> parameter_value_assignment();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_instantiationContext> interface_instantiation();

  class Program_instantiationContext : public ParserRuleContext {
  public:
    Program_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Program_identifierContext> program_identifier();
    std::vector<Ref<Hierarchical_instanceContext>> hierarchical_instance();
    Ref<Hierarchical_instanceContext> hierarchical_instance(int i);
    Ref<Parameter_value_assignmentContext> parameter_value_assignment();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Program_instantiationContext> program_instantiation();

  class Checker_instantiationContext : public ParserRuleContext {
  public:
    Checker_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_checker_identifierContext> ps_checker_identifier();
    Ref<Name_of_instanceContext> name_of_instance();
    Ref<List_of_checker_port_connectionsContext> list_of_checker_port_connections();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_instantiationContext> checker_instantiation();

  class List_of_checker_port_connectionsContext : public ParserRuleContext {
  public:
    List_of_checker_port_connectionsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Ordered_checker_port_connectionContext>> ordered_checker_port_connection();
    Ref<Ordered_checker_port_connectionContext> ordered_checker_port_connection(int i);
    std::vector<Ref<Named_checker_port_connectionContext>> named_checker_port_connection();
    Ref<Named_checker_port_connectionContext> named_checker_port_connection(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_checker_port_connectionsContext> list_of_checker_port_connections();

  class Ordered_checker_port_connectionContext : public ParserRuleContext {
  public:
    Ordered_checker_port_connectionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Property_actual_argContext> property_actual_arg();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ordered_checker_port_connectionContext> ordered_checker_port_connection();

  class Named_checker_port_connectionContext : public ParserRuleContext {
  public:
    Named_checker_port_connectionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Formal_port_identifierContext> formal_port_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Property_actual_argContext> property_actual_arg();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Named_checker_port_connectionContext> named_checker_port_connection();

  class Generate_regionContext : public ParserRuleContext {
  public:
    Generate_regionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Generate_itemContext>> generate_item();
    Ref<Generate_itemContext> generate_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Generate_regionContext> generate_region();

  class Loop_generate_constructContext : public ParserRuleContext {
  public:
    Loop_generate_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Genvar_initializationContext> genvar_initialization();
    Ref<Genvar_expressionContext> genvar_expression();
    Ref<Genvar_iterationContext> genvar_iteration();
    Ref<Generate_blockContext> generate_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Loop_generate_constructContext> loop_generate_construct();

  class Genvar_initializationContext : public ParserRuleContext {
  public:
    Genvar_initializationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Genvar_identifierContext> genvar_identifier();
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Genvar_initializationContext> genvar_initialization();

  class Genvar_iterationContext : public ParserRuleContext {
  public:
    Genvar_iterationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Genvar_identifierContext> genvar_identifier();
    Ref<Assignment_operatorContext> assignment_operator();
    Ref<Genvar_expressionContext> genvar_expression();
    Ref<Inc_or_dec_operatorContext> inc_or_dec_operator();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Genvar_iterationContext> genvar_iteration();

  class Conditional_generate_constructContext : public ParserRuleContext {
  public:
    Conditional_generate_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<If_generate_constructContext> if_generate_construct();
    Ref<Case_generate_constructContext> case_generate_construct();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Conditional_generate_constructContext> conditional_generate_construct();

  class If_generate_constructContext : public ParserRuleContext {
  public:
    If_generate_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    std::vector<Ref<Generate_blockContext>> generate_block();
    Ref<Generate_blockContext> generate_block(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<If_generate_constructContext> if_generate_construct();

  class Case_generate_constructContext : public ParserRuleContext {
  public:
    Case_generate_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    std::vector<Ref<Case_generate_itemContext>> case_generate_item();
    Ref<Case_generate_itemContext> case_generate_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_generate_constructContext> case_generate_construct();

  class Case_generate_itemContext : public ParserRuleContext {
  public:
    Case_generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);
    Ref<Generate_blockContext> generate_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_generate_itemContext> case_generate_item();

  class Generate_blockContext : public ParserRuleContext {
  public:
    Generate_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Generate_itemContext>> generate_item();
    Ref<Generate_itemContext> generate_item(int i);
    std::vector<Ref<Generate_block_identifierContext>> generate_block_identifier();
    Ref<Generate_block_identifierContext> generate_block_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Generate_blockContext> generate_block();

  class Generate_itemContext : public ParserRuleContext {
  public:
    Generate_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_or_generate_itemContext> module_or_generate_item();
    Ref<Interface_or_generate_itemContext> interface_or_generate_item();
    Ref<Checker_or_generate_itemContext> checker_or_generate_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Generate_itemContext> generate_item();

  class Udp_nonansi_declarationContext : public ParserRuleContext {
  public:
    Udp_nonansi_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Udp_identifierContext> udp_identifier();
    Ref<Udp_port_listContext> udp_port_list();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_nonansi_declarationContext> udp_nonansi_declaration();

  class Udp_ansi_declarationContext : public ParserRuleContext {
  public:
    Udp_ansi_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Udp_identifierContext> udp_identifier();
    Ref<Udp_declaration_port_listContext> udp_declaration_port_list();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_ansi_declarationContext> udp_ansi_declaration();

  class Udp_declarationContext : public ParserRuleContext {
  public:
    Udp_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Udp_nonansi_declarationContext> udp_nonansi_declaration();
    std::vector<Ref<Udp_port_declarationContext>> udp_port_declaration();
    Ref<Udp_port_declarationContext> udp_port_declaration(int i);
    Ref<Udp_bodyContext> udp_body();
    std::vector<Ref<Udp_identifierContext>> udp_identifier();
    Ref<Udp_identifierContext> udp_identifier(int i);
    Ref<Udp_ansi_declarationContext> udp_ansi_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_declarationContext> udp_declaration();

  class Udp_port_listContext : public ParserRuleContext {
  public:
    Udp_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_port_identifierContext> output_port_identifier();
    std::vector<Ref<Input_port_identifierContext>> input_port_identifier();
    Ref<Input_port_identifierContext> input_port_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_port_listContext> udp_port_list();

  class Udp_declaration_port_listContext : public ParserRuleContext {
  public:
    Udp_declaration_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Udp_output_declarationContext> udp_output_declaration();
    std::vector<Ref<Udp_input_declarationContext>> udp_input_declaration();
    Ref<Udp_input_declarationContext> udp_input_declaration(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_declaration_port_listContext> udp_declaration_port_list();

  class Udp_port_declarationContext : public ParserRuleContext {
  public:
    Udp_port_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Udp_output_declarationContext> udp_output_declaration();
    Ref<Udp_input_declarationContext> udp_input_declaration();
    Ref<Udp_reg_declarationContext> udp_reg_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_port_declarationContext> udp_port_declaration();

  class Udp_output_declarationContext : public ParserRuleContext {
  public:
    Udp_output_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Port_identifierContext> port_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_output_declarationContext> udp_output_declaration();

  class Udp_input_declarationContext : public ParserRuleContext {
  public:
    Udp_input_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_udp_port_identifiersContext> list_of_udp_port_identifiers();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_input_declarationContext> udp_input_declaration();

  class Udp_reg_declarationContext : public ParserRuleContext {
  public:
    Udp_reg_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_reg_declarationContext> udp_reg_declaration();

  class Udp_bodyContext : public ParserRuleContext {
  public:
    Udp_bodyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Combinational_bodyContext> combinational_body();
    Ref<Sequential_bodyContext> sequential_body();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_bodyContext> udp_body();

  class Combinational_bodyContext : public ParserRuleContext {
  public:
    Combinational_bodyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Combinational_entryContext>> combinational_entry();
    Ref<Combinational_entryContext> combinational_entry(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Combinational_bodyContext> combinational_body();

  class Combinational_entryContext : public ParserRuleContext {
  public:
    Combinational_entryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Level_input_listContext> level_input_list();
    Ref<Output_symbolContext> output_symbol();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Combinational_entryContext> combinational_entry();

  class Sequential_bodyContext : public ParserRuleContext {
  public:
    Sequential_bodyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Sequential_entryContext>> sequential_entry();
    Ref<Sequential_entryContext> sequential_entry(int i);
    Ref<Udp_initial_statementContext> udp_initial_statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequential_bodyContext> sequential_body();

  class Udp_initial_statementContext : public ParserRuleContext {
  public:
    Udp_initial_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_port_identifierContext> output_port_identifier();
    Ref<Init_valContext> init_val();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_initial_statementContext> udp_initial_statement();

  class Init_valContext : public ParserRuleContext {
  public:
    Init_valContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Integral_number();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Init_valContext> init_val();

  class Sequential_entryContext : public ParserRuleContext {
  public:
    Sequential_entryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Seq_input_listContext> seq_input_list();
    Ref<Current_stateContext> current_state();
    Ref<Next_stateContext> next_state();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequential_entryContext> sequential_entry();

  class Seq_input_listContext : public ParserRuleContext {
  public:
    Seq_input_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Level_input_listContext> level_input_list();
    Ref<Edge_input_listContext> edge_input_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Seq_input_listContext> seq_input_list();

  class Level_input_listContext : public ParserRuleContext {
  public:
    Level_input_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Level_symbolContext>> level_symbol();
    Ref<Level_symbolContext> level_symbol(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Level_input_listContext> level_input_list();

  class Edge_input_listContext : public ParserRuleContext {
  public:
    Edge_input_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Edge_indicatorContext> edge_indicator();
    std::vector<Ref<Level_symbolContext>> level_symbol();
    Ref<Level_symbolContext> level_symbol(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Edge_input_listContext> edge_input_list();

  class Edge_indicatorContext : public ParserRuleContext {
  public:
    Edge_indicatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Level_symbolContext>> level_symbol();
    Ref<Level_symbolContext> level_symbol(int i);
    Ref<Edge_symbolContext> edge_symbol();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Edge_indicatorContext> edge_indicator();

  class Current_stateContext : public ParserRuleContext {
  public:
    Current_stateContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Level_symbolContext> level_symbol();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Current_stateContext> current_state();

  class Next_stateContext : public ParserRuleContext {
  public:
    Next_stateContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_symbolContext> output_symbol();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Next_stateContext> next_state();

  class Output_symbolContext : public ParserRuleContext {
  public:
    Output_symbolContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Integral_number();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Output_symbolContext> output_symbol();

  class Level_symbolContext : public ParserRuleContext {
  public:
    Level_symbolContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Unsigned_number();
    Ref<tree::TerminalNode> Simple_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Level_symbolContext> level_symbol();

  class Edge_symbolContext : public ParserRuleContext {
  public:
    Edge_symbolContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Simple_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Edge_symbolContext> edge_symbol();

  class Udp_instantiationContext : public ParserRuleContext {
  public:
    Udp_instantiationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Udp_identifierContext> udp_identifier();
    std::vector<Ref<Udp_instanceContext>> udp_instance();
    Ref<Udp_instanceContext> udp_instance(int i);
    Ref<Drive_strengthContext> drive_strength();
    Ref<Delay2Context> delay2();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_instantiationContext> udp_instantiation();

  class Udp_instanceContext : public ParserRuleContext {
  public:
    Udp_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_terminalContext> output_terminal();
    std::vector<Ref<Input_terminalContext>> input_terminal();
    Ref<Input_terminalContext> input_terminal(int i);
    Ref<Name_of_instanceContext> name_of_instance();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_instanceContext> udp_instance();

  class Continuous_assignContext : public ParserRuleContext {
  public:
    Continuous_assignContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_net_assignmentsContext> list_of_net_assignments();
    Ref<Drive_strengthContext> drive_strength();
    Ref<Delay3Context> delay3();
    Ref<List_of_variable_assignmentsContext> list_of_variable_assignments();
    Ref<Delay_controlContext> delay_control();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Continuous_assignContext> continuous_assign();

  class List_of_net_assignmentsContext : public ParserRuleContext {
  public:
    List_of_net_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Net_assignmentContext>> net_assignment();
    Ref<Net_assignmentContext> net_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_net_assignmentsContext> list_of_net_assignments();

  class List_of_variable_assignmentsContext : public ParserRuleContext {
  public:
    List_of_variable_assignmentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Variable_assignmentContext>> variable_assignment();
    Ref<Variable_assignmentContext> variable_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_variable_assignmentsContext> list_of_variable_assignments();

  class Net_aliasContext : public ParserRuleContext {
  public:
    Net_aliasContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Net_lvalueContext>> net_lvalue();
    Ref<Net_lvalueContext> net_lvalue(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_aliasContext> net_alias();

  class Net_assignmentContext : public ParserRuleContext {
  public:
    Net_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_lvalueContext> net_lvalue();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_assignmentContext> net_assignment();

  class Initial_constructContext : public ParserRuleContext {
  public:
    Initial_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Statement_or_nullContext> statement_or_null();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Initial_constructContext> initial_construct();

  class Always_constructContext : public ParserRuleContext {
  public:
    Always_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Always_keywordContext> always_keyword();
    Ref<StatementContext> statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Always_constructContext> always_construct();

  class Always_keywordContext : public ParserRuleContext {
  public:
    Always_keywordContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Always_keywordContext> always_keyword();

  class Final_constructContext : public ParserRuleContext {
  public:
    Final_constructContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_statementContext> function_statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Final_constructContext> final_construct();

  class Blocking_assignmentContext : public ParserRuleContext {
  public:
    Blocking_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<Delay_or_event_controlContext> delay_or_event_control();
    Ref<ExpressionContext> expression();
    Ref<Nonrange_variable_lvalueContext> nonrange_variable_lvalue();
    Ref<Dynamic_array_newContext> dynamic_array_new();
    Ref<Hierarchical_variable_identifierContext> hierarchical_variable_identifier();
    Ref<SelectContext> select();
    Ref<Class_newContext> class_new();
    Ref<Implicit_class_handleContext> implicit_class_handle();
    Ref<Class_scopeContext> class_scope();
    Ref<Package_scopeContext> package_scope();
    Ref<Operator_assignmentContext> operator_assignment();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Blocking_assignmentContext> blocking_assignment();

  class Operator_assignmentContext : public ParserRuleContext {
  public:
    Operator_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<Assignment_operatorContext> assignment_operator();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Operator_assignmentContext> operator_assignment();

  class Assignment_operatorContext : public ParserRuleContext {
  public:
    Assignment_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assignment_operatorContext> assignment_operator();

  class Nonblocking_assignmentContext : public ParserRuleContext {
  public:
    Nonblocking_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<ExpressionContext> expression();
    Ref<Delay_or_event_controlContext> delay_or_event_control();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Nonblocking_assignmentContext> nonblocking_assignment();

  class Procedural_continuous_assignmentContext : public ParserRuleContext {
  public:
    Procedural_continuous_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_assignmentContext> variable_assignment();
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<Net_assignmentContext> net_assignment();
    Ref<Net_lvalueContext> net_lvalue();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Procedural_continuous_assignmentContext> procedural_continuous_assignment();

  class Variable_assignmentContext : public ParserRuleContext {
  public:
    Variable_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_lvalueContext> variable_lvalue();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Variable_assignmentContext> variable_assignment();

  class Action_blockContext : public ParserRuleContext {
  public:
    Action_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Statement_or_nullContext> statement_or_null();
    Ref<StatementContext> statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Action_blockContext> action_block();

  class Seq_blockContext : public ParserRuleContext {
  public:
    Seq_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Block_identifierContext>> block_identifier();
    Ref<Block_identifierContext> block_identifier(int i);
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);
    std::vector<Ref<Statement_or_nullContext>> statement_or_null();
    Ref<Statement_or_nullContext> statement_or_null(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Seq_blockContext> seq_block();

  class Par_blockContext : public ParserRuleContext {
  public:
    Par_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Join_keywordContext> join_keyword();
    std::vector<Ref<Block_identifierContext>> block_identifier();
    Ref<Block_identifierContext> block_identifier(int i);
    std::vector<Ref<Block_item_declarationContext>> block_item_declaration();
    Ref<Block_item_declarationContext> block_item_declaration(int i);
    std::vector<Ref<Statement_or_nullContext>> statement_or_null();
    Ref<Statement_or_nullContext> statement_or_null(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Par_blockContext> par_block();

  class Join_keywordContext : public ParserRuleContext {
  public:
    Join_keywordContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Join_keywordContext> join_keyword();

  class Statement_or_nullContext : public ParserRuleContext {
  public:
    Statement_or_nullContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<StatementContext> statement();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Statement_or_nullContext> statement_or_null();

  class StatementContext : public ParserRuleContext {
  public:
    StatementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Statement_itemContext> statement_item();
    Ref<Block_identifierContext> block_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<StatementContext> statement();

  class Statement_itemContext : public ParserRuleContext {
  public:
    Statement_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Blocking_assignmentContext> blocking_assignment();
    Ref<Nonblocking_assignmentContext> nonblocking_assignment();
    Ref<Procedural_continuous_assignmentContext> procedural_continuous_assignment();
    Ref<Case_statementContext> case_statement();
    Ref<Conditional_statementContext> conditional_statement();
    Ref<Inc_or_dec_expressionContext> inc_or_dec_expression();
    Ref<Subroutine_call_statementContext> subroutine_call_statement();
    Ref<Disable_statementContext> disable_statement();
    Ref<Event_triggerContext> event_trigger();
    Ref<Loop_statementContext> loop_statement();
    Ref<Jump_statementContext> jump_statement();
    Ref<Par_blockContext> par_block();
    Ref<Procedural_timing_control_statementContext> procedural_timing_control_statement();
    Ref<Seq_blockContext> seq_block();
    Ref<Wait_statementContext> wait_statement();
    Ref<Procedural_assertion_statementContext> procedural_assertion_statement();
    Ref<Clocking_driveContext> clocking_drive();
    Ref<Randsequence_statementContext> randsequence_statement();
    Ref<Randcase_statementContext> randcase_statement();
    Ref<Expect_property_statementContext> expect_property_statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Statement_itemContext> statement_item();

  class Function_statementContext : public ParserRuleContext {
  public:
    Function_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<StatementContext> statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Function_statementContext> function_statement();

  class Function_statement_or_nullContext : public ParserRuleContext {
  public:
    Function_statement_or_nullContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_statementContext> function_statement();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Function_statement_or_nullContext> function_statement_or_null();

  class Variable_identifier_listContext : public ParserRuleContext {
  public:
    Variable_identifier_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Variable_identifierContext>> variable_identifier();
    Ref<Variable_identifierContext> variable_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Variable_identifier_listContext> variable_identifier_list();

  class Procedural_timing_control_statementContext : public ParserRuleContext {
  public:
    Procedural_timing_control_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Procedural_timing_controlContext> procedural_timing_control();
    Ref<Statement_or_nullContext> statement_or_null();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Procedural_timing_control_statementContext> procedural_timing_control_statement();

  class Delay_or_event_controlContext : public ParserRuleContext {
  public:
    Delay_or_event_controlContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Delay_controlContext> delay_control();
    Ref<Event_controlContext> event_control();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Delay_or_event_controlContext> delay_or_event_control();

  class Delay_controlContext : public ParserRuleContext {
  public:
    Delay_controlContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Delay_valueContext> delay_value();
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Delay_controlContext> delay_control();

  class Event_controlContext : public ParserRuleContext {
  public:
    Event_controlContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_event_identifierContext> hierarchical_event_identifier();
    Ref<Event_expressionContext> event_expression();
    Ref<Ps_or_hierarchical_sequence_identifierContext> ps_or_hierarchical_sequence_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Event_controlContext> event_control();

  class Event_expressionContext : public ParserRuleContext {
  public:
    Event_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Edge_identifierContext> edge_identifier();
    Ref<Sequence_instanceContext> sequence_instance();
    std::vector<Ref<Event_expressionContext>> event_expression();
    Ref<Event_expressionContext> event_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Event_expressionContext> event_expression();
  Ref<Event_expressionContext> event_expression(int precedence);
  class Procedural_timing_controlContext : public ParserRuleContext {
  public:
    Procedural_timing_controlContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Delay_controlContext> delay_control();
    Ref<Event_controlContext> event_control();
    Ref<Cycle_delayContext> cycle_delay();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Procedural_timing_controlContext> procedural_timing_control();

  class Jump_statementContext : public ParserRuleContext {
  public:
    Jump_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Jump_statementContext> jump_statement();

  class Wait_statementContext : public ParserRuleContext {
  public:
    Wait_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Statement_or_nullContext> statement_or_null();
    std::vector<Ref<Hierarchical_identifierContext>> hierarchical_identifier();
    Ref<Hierarchical_identifierContext> hierarchical_identifier(int i);
    Ref<Action_blockContext> action_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Wait_statementContext> wait_statement();

  class Event_triggerContext : public ParserRuleContext {
  public:
    Event_triggerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_event_identifierContext> hierarchical_event_identifier();
    Ref<Delay_or_event_controlContext> delay_or_event_control();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Event_triggerContext> event_trigger();

  class Disable_statementContext : public ParserRuleContext {
  public:
    Disable_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_task_identifierContext> hierarchical_task_identifier();
    Ref<Hierarchical_block_identifierContext> hierarchical_block_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Disable_statementContext> disable_statement();

  class Conditional_statementContext : public ParserRuleContext {
  public:
    Conditional_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Cond_predicateContext>> cond_predicate();
    Ref<Cond_predicateContext> cond_predicate(int i);
    std::vector<Ref<Statement_or_nullContext>> statement_or_null();
    Ref<Statement_or_nullContext> statement_or_null(int i);
    Ref<Unique_priorityContext> unique_priority();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Conditional_statementContext> conditional_statement();

  class Unique_priorityContext : public ParserRuleContext {
  public:
    Unique_priorityContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Unique_priorityContext> unique_priority();

  class Cond_predicateContext : public ParserRuleContext {
  public:
    Cond_predicateContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Expression_or_cond_patternContext>> expression_or_cond_pattern();
    Ref<Expression_or_cond_patternContext> expression_or_cond_pattern(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cond_predicateContext> cond_predicate();

  class Expression_or_cond_patternContext : public ParserRuleContext {
  public:
    Expression_or_cond_patternContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Cond_patternContext> cond_pattern();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Expression_or_cond_patternContext> expression_or_cond_pattern();

  class Cond_patternContext : public ParserRuleContext {
  public:
    Cond_patternContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<PatternContext> pattern();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cond_patternContext> cond_pattern();

  class Case_statementContext : public ParserRuleContext {
  public:
    Case_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Case_keywordContext> case_keyword();
    Ref<Case_expressionContext> case_expression();
    std::vector<Ref<Case_itemContext>> case_item();
    Ref<Case_itemContext> case_item(int i);
    Ref<Unique_priorityContext> unique_priority();
    std::vector<Ref<Case_pattern_itemContext>> case_pattern_item();
    Ref<Case_pattern_itemContext> case_pattern_item(int i);
    std::vector<Ref<Case_inside_itemContext>> case_inside_item();
    Ref<Case_inside_itemContext> case_inside_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_statementContext> case_statement();

  class Case_keywordContext : public ParserRuleContext {
  public:
    Case_keywordContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_keywordContext> case_keyword();

  class Case_expressionContext : public ParserRuleContext {
  public:
    Case_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_expressionContext> case_expression();

  class Case_itemContext : public ParserRuleContext {
  public:
    Case_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Case_item_expressionContext>> case_item_expression();
    Ref<Case_item_expressionContext> case_item_expression(int i);
    Ref<Statement_or_nullContext> statement_or_null();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_itemContext> case_item();

  class Case_pattern_itemContext : public ParserRuleContext {
  public:
    Case_pattern_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<PatternContext> pattern();
    Ref<Statement_or_nullContext> statement_or_null();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_pattern_itemContext> case_pattern_item();

  class Case_inside_itemContext : public ParserRuleContext {
  public:
    Case_inside_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Open_range_listContext> open_range_list();
    Ref<Statement_or_nullContext> statement_or_null();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_inside_itemContext> case_inside_item();

  class Case_item_expressionContext : public ParserRuleContext {
  public:
    Case_item_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Case_item_expressionContext> case_item_expression();

  class Randcase_statementContext : public ParserRuleContext {
  public:
    Randcase_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Randcase_itemContext>> randcase_item();
    Ref<Randcase_itemContext> randcase_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Randcase_statementContext> randcase_statement();

  class Randcase_itemContext : public ParserRuleContext {
  public:
    Randcase_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Statement_or_nullContext> statement_or_null();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Randcase_itemContext> randcase_item();

  class Open_range_listContext : public ParserRuleContext {
  public:
    Open_range_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Open_value_rangeContext>> open_value_range();
    Ref<Open_value_rangeContext> open_value_range(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Open_range_listContext> open_range_list();

  class Open_value_rangeContext : public ParserRuleContext {
  public:
    Open_value_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Value_rangeContext> value_range();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Open_value_rangeContext> open_value_range();

  class PatternContext : public ParserRuleContext {
  public:
    PatternContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();
    Ref<Constant_expressionContext> constant_expression();
    std::vector<Ref<Member_identifierContext>> member_identifier();
    Ref<Member_identifierContext> member_identifier(int i);
    std::vector<Ref<PatternContext>> pattern();
    Ref<PatternContext> pattern(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<PatternContext> pattern();

  class Assignment_patternContext : public ParserRuleContext {
  public:
    Assignment_patternContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    std::vector<Ref<Structure_pattern_keyContext>> structure_pattern_key();
    Ref<Structure_pattern_keyContext> structure_pattern_key(int i);
    std::vector<Ref<Array_pattern_keyContext>> array_pattern_key();
    Ref<Array_pattern_keyContext> array_pattern_key(int i);
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assignment_patternContext> assignment_pattern();

  class Structure_pattern_keyContext : public ParserRuleContext {
  public:
    Structure_pattern_keyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Member_identifierContext> member_identifier();
    Ref<Assignment_pattern_keyContext> assignment_pattern_key();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Structure_pattern_keyContext> structure_pattern_key();

  class Array_pattern_keyContext : public ParserRuleContext {
  public:
    Array_pattern_keyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<Assignment_pattern_keyContext> assignment_pattern_key();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Array_pattern_keyContext> array_pattern_key();

  class Assignment_pattern_keyContext : public ParserRuleContext {
  public:
    Assignment_pattern_keyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_typeContext> simple_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assignment_pattern_keyContext> assignment_pattern_key();

  class Assignment_pattern_expressionContext : public ParserRuleContext {
  public:
    Assignment_pattern_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Assignment_patternContext> assignment_pattern();
    Ref<Assignment_pattern_expression_typeContext> assignment_pattern_expression_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assignment_pattern_expressionContext> assignment_pattern_expression();

  class Assignment_pattern_expression_typeContext : public ParserRuleContext {
  public:
    Assignment_pattern_expression_typeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_type_identifierContext> ps_type_identifier();
    Ref<Ps_parameter_identifierContext> ps_parameter_identifier();
    Ref<Integer_atom_typeContext> integer_atom_type();
    Ref<Type_referenceContext> type_reference();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assignment_pattern_expression_typeContext> assignment_pattern_expression_type();

  class Constant_assignment_pattern_expressionContext : public ParserRuleContext {
  public:
    Constant_assignment_pattern_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Assignment_pattern_expressionContext> assignment_pattern_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_assignment_pattern_expressionContext> constant_assignment_pattern_expression();

  class Assignment_pattern_net_lvalueContext : public ParserRuleContext {
  public:
    Assignment_pattern_net_lvalueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Net_lvalueContext>> net_lvalue();
    Ref<Net_lvalueContext> net_lvalue(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assignment_pattern_net_lvalueContext> assignment_pattern_net_lvalue();

  class Assignment_pattern_variable_lvalueContext : public ParserRuleContext {
  public:
    Assignment_pattern_variable_lvalueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Variable_lvalueContext>> variable_lvalue();
    Ref<Variable_lvalueContext> variable_lvalue(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assignment_pattern_variable_lvalueContext> assignment_pattern_variable_lvalue();

  class Loop_statementContext : public ParserRuleContext {
  public:
    Loop_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Statement_or_nullContext> statement_or_null();
    Ref<ExpressionContext> expression();
    Ref<For_initializationContext> for_initialization();
    Ref<For_stepContext> for_step();
    Ref<Ps_or_hierarchical_array_identifierContext> ps_or_hierarchical_array_identifier();
    Ref<Loop_variablesContext> loop_variables();
    Ref<StatementContext> statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Loop_statementContext> loop_statement();

  class For_initializationContext : public ParserRuleContext {
  public:
    For_initializationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_variable_assignmentsContext> list_of_variable_assignments();
    std::vector<Ref<For_variable_declarationContext>> for_variable_declaration();
    Ref<For_variable_declarationContext> for_variable_declaration(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<For_initializationContext> for_initialization();

  class For_variable_declarationContext : public ParserRuleContext {
  public:
    For_variable_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_typeContext> data_type();
    std::vector<Ref<Variable_identifierContext>> variable_identifier();
    Ref<Variable_identifierContext> variable_identifier(int i);
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<For_variable_declarationContext> for_variable_declaration();

  class For_stepContext : public ParserRuleContext {
  public:
    For_stepContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<For_step_assignmentContext>> for_step_assignment();
    Ref<For_step_assignmentContext> for_step_assignment(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<For_stepContext> for_step();

  class For_step_assignmentContext : public ParserRuleContext {
  public:
    For_step_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Operator_assignmentContext> operator_assignment();
    Ref<Inc_or_dec_expressionContext> inc_or_dec_expression();
    Ref<Function_subroutine_callContext> function_subroutine_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<For_step_assignmentContext> for_step_assignment();

  class Loop_variablesContext : public ParserRuleContext {
  public:
    Loop_variablesContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Index_variable_identifierContext>> index_variable_identifier();
    Ref<Index_variable_identifierContext> index_variable_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Loop_variablesContext> loop_variables();

  class Subroutine_call_statementContext : public ParserRuleContext {
  public:
    Subroutine_call_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subroutine_callContext> subroutine_call();
    Ref<Function_subroutine_callContext> function_subroutine_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Subroutine_call_statementContext> subroutine_call_statement();

  class Assertion_itemContext : public ParserRuleContext {
  public:
    Assertion_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Concurrent_assertion_itemContext> concurrent_assertion_item();
    Ref<Deferred_immediate_assertion_itemContext> deferred_immediate_assertion_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Assertion_itemContext> assertion_item();

  class Deferred_immediate_assertion_itemContext : public ParserRuleContext {
  public:
    Deferred_immediate_assertion_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Deferred_immediate_assertion_statementContext> deferred_immediate_assertion_statement();
    Ref<Block_identifierContext> block_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Deferred_immediate_assertion_itemContext> deferred_immediate_assertion_item();

  class Procedural_assertion_statementContext : public ParserRuleContext {
  public:
    Procedural_assertion_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Concurrent_assertion_statementContext> concurrent_assertion_statement();
    Ref<Immediate_assertion_statementContext> immediate_assertion_statement();
    Ref<Checker_instantiationContext> checker_instantiation();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Procedural_assertion_statementContext> procedural_assertion_statement();

  class Immediate_assertion_statementContext : public ParserRuleContext {
  public:
    Immediate_assertion_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_immediate_assertion_statementContext> simple_immediate_assertion_statement();
    Ref<Deferred_immediate_assertion_statementContext> deferred_immediate_assertion_statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Immediate_assertion_statementContext> immediate_assertion_statement();

  class Simple_immediate_assertion_statementContext : public ParserRuleContext {
  public:
    Simple_immediate_assertion_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_immediate_assert_statementContext> simple_immediate_assert_statement();
    Ref<Simple_immediate_assume_statementContext> simple_immediate_assume_statement();
    Ref<Simple_immediate_cover_statementContext> simple_immediate_cover_statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Simple_immediate_assertion_statementContext> simple_immediate_assertion_statement();

  class Simple_immediate_assert_statementContext : public ParserRuleContext {
  public:
    Simple_immediate_assert_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Action_blockContext> action_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Simple_immediate_assert_statementContext> simple_immediate_assert_statement();

  class Simple_immediate_assume_statementContext : public ParserRuleContext {
  public:
    Simple_immediate_assume_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Action_blockContext> action_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Simple_immediate_assume_statementContext> simple_immediate_assume_statement();

  class Simple_immediate_cover_statementContext : public ParserRuleContext {
  public:
    Simple_immediate_cover_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Statement_or_nullContext> statement_or_null();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Simple_immediate_cover_statementContext> simple_immediate_cover_statement();

  class Deferred_immediate_assertion_statementContext : public ParserRuleContext {
  public:
    Deferred_immediate_assertion_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Deferred_immediate_assert_statementContext> deferred_immediate_assert_statement();
    Ref<Deferred_immediate_assume_statementContext> deferred_immediate_assume_statement();
    Ref<Deferred_immediate_cover_statementContext> deferred_immediate_cover_statement();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Deferred_immediate_assertion_statementContext> deferred_immediate_assertion_statement();

  class Deferred_immediate_assert_statementContext : public ParserRuleContext {
  public:
    Deferred_immediate_assert_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Unsigned_number();
    Ref<ExpressionContext> expression();
    Ref<Action_blockContext> action_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Deferred_immediate_assert_statementContext> deferred_immediate_assert_statement();

  class Deferred_immediate_assume_statementContext : public ParserRuleContext {
  public:
    Deferred_immediate_assume_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Unsigned_number();
    Ref<ExpressionContext> expression();
    Ref<Action_blockContext> action_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Deferred_immediate_assume_statementContext> deferred_immediate_assume_statement();

  class Deferred_immediate_cover_statementContext : public ParserRuleContext {
  public:
    Deferred_immediate_cover_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Unsigned_number();
    Ref<ExpressionContext> expression();
    Ref<Statement_or_nullContext> statement_or_null();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Deferred_immediate_cover_statementContext> deferred_immediate_cover_statement();

  class Clocking_declarationContext : public ParserRuleContext {
  public:
    Clocking_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Clocking_eventContext> clocking_event();
    std::vector<Ref<Clocking_identifierContext>> clocking_identifier();
    Ref<Clocking_identifierContext> clocking_identifier(int i);
    std::vector<Ref<Clocking_itemContext>> clocking_item();
    Ref<Clocking_itemContext> clocking_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clocking_declarationContext> clocking_declaration();

  class Clocking_eventContext : public ParserRuleContext {
  public:
    Clocking_eventContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<Event_expressionContext> event_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clocking_eventContext> clocking_event();

  class Clocking_itemContext : public ParserRuleContext {
  public:
    Clocking_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Default_skewContext> default_skew();
    Ref<Clocking_directionContext> clocking_direction();
    Ref<List_of_clocking_decl_assignContext> list_of_clocking_decl_assign();
    Ref<Assertion_item_declarationContext> assertion_item_declaration();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clocking_itemContext> clocking_item();

  class Default_skewContext : public ParserRuleContext {
  public:
    Default_skewContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Clocking_skewContext>> clocking_skew();
    Ref<Clocking_skewContext> clocking_skew(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Default_skewContext> default_skew();

  class Clocking_directionContext : public ParserRuleContext {
  public:
    Clocking_directionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Clocking_skewContext>> clocking_skew();
    Ref<Clocking_skewContext> clocking_skew(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clocking_directionContext> clocking_direction();

  class List_of_clocking_decl_assignContext : public ParserRuleContext {
  public:
    List_of_clocking_decl_assignContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Clocking_decl_assignContext>> clocking_decl_assign();
    Ref<Clocking_decl_assignContext> clocking_decl_assign(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_clocking_decl_assignContext> list_of_clocking_decl_assign();

  class Clocking_decl_assignContext : public ParserRuleContext {
  public:
    Clocking_decl_assignContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Signal_identifierContext> signal_identifier();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clocking_decl_assignContext> clocking_decl_assign();

  class Clocking_skewContext : public ParserRuleContext {
  public:
    Clocking_skewContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Edge_identifierContext> edge_identifier();
    Ref<Delay_controlContext> delay_control();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clocking_skewContext> clocking_skew();

  class Clocking_driveContext : public ParserRuleContext {
  public:
    Clocking_driveContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Clockvar_expressionContext> clockvar_expression();
    Ref<ExpressionContext> expression();
    Ref<Cycle_delayContext> cycle_delay();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clocking_driveContext> clocking_drive();

  class Cycle_delayContext : public ParserRuleContext {
  public:
    Cycle_delayContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Integral_number();
    Ref<IdentifierContext> identifier();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cycle_delayContext> cycle_delay();

  class ClockvarContext : public ParserRuleContext {
  public:
    ClockvarContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<ClockvarContext> clockvar();

  class Clockvar_expressionContext : public ParserRuleContext {
  public:
    Clockvar_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ClockvarContext> clockvar();
    Ref<SelectContext> select();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clockvar_expressionContext> clockvar_expression();

  class Randsequence_statementContext : public ParserRuleContext {
  public:
    Randsequence_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ProductionContext>> production();
    Ref<ProductionContext> production(int i);
    Ref<Production_identifierContext> production_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Randsequence_statementContext> randsequence_statement();

  class ProductionContext : public ParserRuleContext {
  public:
    ProductionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Production_identifierContext> production_identifier();
    std::vector<Ref<Rs_ruleContext>> rs_rule();
    Ref<Rs_ruleContext> rs_rule(int i);
    Ref<Data_type_or_voidContext> data_type_or_void();
    Ref<Tf_port_listContext> tf_port_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<ProductionContext> production();

  class Rs_ruleContext : public ParserRuleContext {
  public:
    Rs_ruleContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Rs_production_listContext> rs_production_list();
    Ref<Weight_specificationContext> weight_specification();
    Ref<Rs_code_blockContext> rs_code_block();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Rs_ruleContext> rs_rule();

  class Rs_production_listContext : public ParserRuleContext {
  public:
    Rs_production_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Rs_prodContext>> rs_prod();
    Ref<Rs_prodContext> rs_prod(int i);
    std::vector<Ref<Production_itemContext>> production_item();
    Ref<Production_itemContext> production_item(int i);
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Rs_production_listContext> rs_production_list();

  class Weight_specificationContext : public ParserRuleContext {
  public:
    Weight_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Integral_number();
    Ref<Ps_identifierContext> ps_identifier();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Weight_specificationContext> weight_specification();

  class Rs_code_blockContext : public ParserRuleContext {
  public:
    Rs_code_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Data_declarationContext>> data_declaration();
    Ref<Data_declarationContext> data_declaration(int i);
    std::vector<Ref<Statement_or_nullContext>> statement_or_null();
    Ref<Statement_or_nullContext> statement_or_null(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Rs_code_blockContext> rs_code_block();

  class Rs_prodContext : public ParserRuleContext {
  public:
    Rs_prodContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Production_itemContext> production_item();
    Ref<Rs_code_blockContext> rs_code_block();
    Ref<Rs_if_elseContext> rs_if_else();
    Ref<Rs_repeatContext> rs_repeat();
    Ref<Rs_caseContext> rs_case();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Rs_prodContext> rs_prod();

  class Production_itemContext : public ParserRuleContext {
  public:
    Production_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Production_identifierContext> production_identifier();
    Ref<List_of_argumentsContext> list_of_arguments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Production_itemContext> production_item();

  class Rs_if_elseContext : public ParserRuleContext {
  public:
    Rs_if_elseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    std::vector<Ref<Production_itemContext>> production_item();
    Ref<Production_itemContext> production_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Rs_if_elseContext> rs_if_else();

  class Rs_repeatContext : public ParserRuleContext {
  public:
    Rs_repeatContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Production_itemContext> production_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Rs_repeatContext> rs_repeat();

  class Rs_caseContext : public ParserRuleContext {
  public:
    Rs_caseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Case_expressionContext> case_expression();
    std::vector<Ref<Rs_case_itemContext>> rs_case_item();
    Ref<Rs_case_itemContext> rs_case_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Rs_caseContext> rs_case();

  class Rs_case_itemContext : public ParserRuleContext {
  public:
    Rs_case_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Case_item_expressionContext>> case_item_expression();
    Ref<Case_item_expressionContext> case_item_expression(int i);
    Ref<Production_itemContext> production_item();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Rs_case_itemContext> rs_case_item();

  class Specify_blockContext : public ParserRuleContext {
  public:
    Specify_blockContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Specify_itemContext>> specify_item();
    Ref<Specify_itemContext> specify_item(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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
    Ref<System_timing_checkContext> system_timing_check();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Specify_itemContext> specify_item();

  class Pulsestyle_declarationContext : public ParserRuleContext {
  public:
    Pulsestyle_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_outputsContext> list_of_path_outputs();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Pulsestyle_declarationContext> pulsestyle_declaration();

  class Showcancelled_declarationContext : public ParserRuleContext {
  public:
    Showcancelled_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_outputsContext> list_of_path_outputs();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Showcancelled_declarationContext> showcancelled_declaration();

  class Path_declarationContext : public ParserRuleContext {
  public:
    Path_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_path_declarationContext> simple_path_declaration();
    Ref<Edge_sensitive_path_declarationContext> edge_sensitive_path_declaration();
    Ref<State_dependent_path_declarationContext> state_dependent_path_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Path_declarationContext> path_declaration();

  class Simple_path_declarationContext : public ParserRuleContext {
  public:
    Simple_path_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parallel_path_descriptionContext> parallel_path_description();
    Ref<Path_delay_valueContext> path_delay_value();
    Ref<Full_path_descriptionContext> full_path_description();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Simple_path_declarationContext> simple_path_declaration();

  class Parallel_path_descriptionContext : public ParserRuleContext {
  public:
    Parallel_path_descriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor();
    Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor();
    Ref<Polarity_operatorContext> polarity_operator();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Parallel_path_descriptionContext> parallel_path_description();

  class Full_path_descriptionContext : public ParserRuleContext {
  public:
    Full_path_descriptionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_inputsContext> list_of_path_inputs();
    Ref<List_of_path_outputsContext> list_of_path_outputs();
    Ref<Polarity_operatorContext> polarity_operator();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Full_path_descriptionContext> full_path_description();

  class List_of_path_inputsContext : public ParserRuleContext {
  public:
    List_of_path_inputsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Specify_input_terminal_descriptorContext>> specify_input_terminal_descriptor();
    Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_path_inputsContext> list_of_path_inputs();

  class List_of_path_outputsContext : public ParserRuleContext {
  public:
    List_of_path_outputsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Specify_output_terminal_descriptorContext>> specify_output_terminal_descriptor();
    Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_path_outputsContext> list_of_path_outputs();

  class Specify_input_terminal_descriptorContext : public ParserRuleContext {
  public:
    Specify_input_terminal_descriptorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Input_identifierContext> input_identifier();
    Ref<Constant_range_expressionContext> constant_range_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor();

  class Specify_output_terminal_descriptorContext : public ParserRuleContext {
  public:
    Specify_output_terminal_descriptorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_identifierContext> output_identifier();
    Ref<Constant_range_expressionContext> constant_range_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor();

  class Input_identifierContext : public ParserRuleContext {
  public:
    Input_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Input_port_identifierContext> input_port_identifier();
    Ref<Inout_port_identifierContext> inout_port_identifier();
    Ref<Interface_identifierContext> interface_identifier();
    Ref<Port_identifierContext> port_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Input_identifierContext> input_identifier();

  class Output_identifierContext : public ParserRuleContext {
  public:
    Output_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Output_port_identifierContext> output_port_identifier();
    Ref<Inout_port_identifierContext> inout_port_identifier();
    Ref<Interface_identifierContext> interface_identifier();
    Ref<Port_identifierContext> port_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Output_identifierContext> output_identifier();

  class Path_delay_valueContext : public ParserRuleContext {
  public:
    Path_delay_valueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<List_of_path_delay_expressionsContext> list_of_path_delay_expressions();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_path_delay_expressionsContext> list_of_path_delay_expressions();

  class T_path_delay_expressionContext : public ParserRuleContext {
  public:
    T_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<T_path_delay_expressionContext> t_path_delay_expression();

  class Trise_path_delay_expressionContext : public ParserRuleContext {
  public:
    Trise_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Trise_path_delay_expressionContext> trise_path_delay_expression();

  class Tfall_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tfall_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tfall_path_delay_expressionContext> tfall_path_delay_expression();

  class Tz_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tz_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tz_path_delay_expressionContext> tz_path_delay_expression();

  class T01_path_delay_expressionContext : public ParserRuleContext {
  public:
    T01_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<T01_path_delay_expressionContext> t01_path_delay_expression();

  class T10_path_delay_expressionContext : public ParserRuleContext {
  public:
    T10_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<T10_path_delay_expressionContext> t10_path_delay_expression();

  class T0z_path_delay_expressionContext : public ParserRuleContext {
  public:
    T0z_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<T0z_path_delay_expressionContext> t0z_path_delay_expression();

  class Tz1_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tz1_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tz1_path_delay_expressionContext> tz1_path_delay_expression();

  class T1z_path_delay_expressionContext : public ParserRuleContext {
  public:
    T1z_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<T1z_path_delay_expressionContext> t1z_path_delay_expression();

  class Tz0_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tz0_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tz0_path_delay_expressionContext> tz0_path_delay_expression();

  class T0x_path_delay_expressionContext : public ParserRuleContext {
  public:
    T0x_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<T0x_path_delay_expressionContext> t0x_path_delay_expression();

  class Tx1_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tx1_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tx1_path_delay_expressionContext> tx1_path_delay_expression();

  class T1x_path_delay_expressionContext : public ParserRuleContext {
  public:
    T1x_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<T1x_path_delay_expressionContext> t1x_path_delay_expression();

  class Tx0_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tx0_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tx0_path_delay_expressionContext> tx0_path_delay_expression();

  class Txz_path_delay_expressionContext : public ParserRuleContext {
  public:
    Txz_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Txz_path_delay_expressionContext> txz_path_delay_expression();

  class Tzx_path_delay_expressionContext : public ParserRuleContext {
  public:
    Tzx_path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Path_delay_expressionContext> path_delay_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tzx_path_delay_expressionContext> tzx_path_delay_expression();

  class Path_delay_expressionContext : public ParserRuleContext {
  public:
    Path_delay_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Path_delay_expressionContext> path_delay_expression();

  class Edge_sensitive_path_declarationContext : public ParserRuleContext {
  public:
    Edge_sensitive_path_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parallel_edge_sensitive_path_descriptionContext> parallel_edge_sensitive_path_description();
    Ref<Path_delay_valueContext> path_delay_value();
    Ref<Full_edge_sensitive_path_descriptionContext> full_edge_sensitive_path_description();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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
    std::vector<Ref<Polarity_operatorContext>> polarity_operator();
    Ref<Polarity_operatorContext> polarity_operator(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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
    std::vector<Ref<Polarity_operatorContext>> polarity_operator();
    Ref<Polarity_operatorContext> polarity_operator(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Full_edge_sensitive_path_descriptionContext> full_edge_sensitive_path_description();

  class Data_source_expressionContext : public ParserRuleContext {
  public:
    Data_source_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Data_source_expressionContext> data_source_expression();

  class Edge_identifierContext : public ParserRuleContext {
  public:
    Edge_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Edge_identifierContext> edge_identifier();

  class State_dependent_path_declarationContext : public ParserRuleContext {
  public:
    State_dependent_path_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_path_expressionContext> module_path_expression();
    Ref<Simple_path_declarationContext> simple_path_declaration();
    Ref<Edge_sensitive_path_declarationContext> edge_sensitive_path_declaration();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<State_dependent_path_declarationContext> state_dependent_path_declaration();

  class Polarity_operatorContext : public ParserRuleContext {
  public:
    Polarity_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Polarity_operatorContext> polarity_operator();

  class System_timing_checkContext : public ParserRuleContext {
  public:
    System_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Setup_timing_checkContext> setup_timing_check();
    Ref<Hold_timing_checkContext> hold_timing_check();
    Ref<Setuphold_timing_checkContext> setuphold_timing_check();
    Ref<Recovery_timing_checkContext> recovery_timing_check();
    Ref<Removal_timing_checkContext> removal_timing_check();
    Ref<Recrem_timing_checkContext> recrem_timing_check();
    Ref<Skew_timing_checkContext> skew_timing_check();
    Ref<Timeskew_timing_checkContext> timeskew_timing_check();
    Ref<Fullskew_timing_checkContext> fullskew_timing_check();
    Ref<Period_timing_checkContext> period_timing_check();
    Ref<Width_timing_checkContext> width_timing_check();
    Ref<Nochange_timing_checkContext> nochange_timing_check();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<System_timing_checkContext> system_timing_check();

  class Setup_timing_checkContext : public ParserRuleContext {
  public:
    Setup_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Data_eventContext> data_event();
    Ref<Reference_eventContext> reference_event();
    Ref<Timing_check_limitContext> timing_check_limit();
    Ref<NotifierContext> notifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Setup_timing_checkContext> setup_timing_check();

  class Hold_timing_checkContext : public ParserRuleContext {
  public:
    Hold_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    Ref<Timing_check_limitContext> timing_check_limit();
    Ref<NotifierContext> notifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hold_timing_checkContext> hold_timing_check();

  class Setuphold_timing_checkContext : public ParserRuleContext {
  public:
    Setuphold_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    std::vector<Ref<Timing_check_limitContext>> timing_check_limit();
    Ref<Timing_check_limitContext> timing_check_limit(int i);
    Ref<NotifierContext> notifier();
    Ref<Timestamp_conditionContext> timestamp_condition();
    Ref<Timecheck_conditionContext> timecheck_condition();
    Ref<Delayed_referenceContext> delayed_reference();
    Ref<Delayed_dataContext> delayed_data();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Setuphold_timing_checkContext> setuphold_timing_check();

  class Recovery_timing_checkContext : public ParserRuleContext {
  public:
    Recovery_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    Ref<Timing_check_limitContext> timing_check_limit();
    Ref<NotifierContext> notifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Recovery_timing_checkContext> recovery_timing_check();

  class Removal_timing_checkContext : public ParserRuleContext {
  public:
    Removal_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    Ref<Timing_check_limitContext> timing_check_limit();
    Ref<NotifierContext> notifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Removal_timing_checkContext> removal_timing_check();

  class Recrem_timing_checkContext : public ParserRuleContext {
  public:
    Recrem_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    std::vector<Ref<Timing_check_limitContext>> timing_check_limit();
    Ref<Timing_check_limitContext> timing_check_limit(int i);
    Ref<NotifierContext> notifier();
    Ref<Timestamp_conditionContext> timestamp_condition();
    Ref<Timecheck_conditionContext> timecheck_condition();
    Ref<Delayed_referenceContext> delayed_reference();
    Ref<Delayed_dataContext> delayed_data();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Recrem_timing_checkContext> recrem_timing_check();

  class Skew_timing_checkContext : public ParserRuleContext {
  public:
    Skew_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    Ref<Timing_check_limitContext> timing_check_limit();
    Ref<NotifierContext> notifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Skew_timing_checkContext> skew_timing_check();

  class Timeskew_timing_checkContext : public ParserRuleContext {
  public:
    Timeskew_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    Ref<Timing_check_limitContext> timing_check_limit();
    Ref<NotifierContext> notifier();
    Ref<Event_based_flagContext> event_based_flag();
    Ref<Remain_active_flagContext> remain_active_flag();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Timeskew_timing_checkContext> timeskew_timing_check();

  class Fullskew_timing_checkContext : public ParserRuleContext {
  public:
    Fullskew_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    std::vector<Ref<Timing_check_limitContext>> timing_check_limit();
    Ref<Timing_check_limitContext> timing_check_limit(int i);
    Ref<NotifierContext> notifier();
    Ref<Event_based_flagContext> event_based_flag();
    Ref<Remain_active_flagContext> remain_active_flag();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Fullskew_timing_checkContext> fullskew_timing_check();

  class Period_timing_checkContext : public ParserRuleContext {
  public:
    Period_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Controlled_reference_eventContext> controlled_reference_event();
    Ref<Timing_check_limitContext> timing_check_limit();
    Ref<NotifierContext> notifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Period_timing_checkContext> period_timing_check();

  class Width_timing_checkContext : public ParserRuleContext {
  public:
    Width_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Controlled_reference_eventContext> controlled_reference_event();
    Ref<Timing_check_limitContext> timing_check_limit();
    Ref<ThresholdContext> threshold();
    Ref<NotifierContext> notifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Width_timing_checkContext> width_timing_check();

  class Nochange_timing_checkContext : public ParserRuleContext {
  public:
    Nochange_timing_checkContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Reference_eventContext> reference_event();
    Ref<Data_eventContext> data_event();
    Ref<Start_edge_offsetContext> start_edge_offset();
    Ref<End_edge_offsetContext> end_edge_offset();
    Ref<NotifierContext> notifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Nochange_timing_checkContext> nochange_timing_check();

  class Timecheck_conditionContext : public ParserRuleContext {
  public:
    Timecheck_conditionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Timecheck_conditionContext> timecheck_condition();

  class Controlled_reference_eventContext : public ParserRuleContext {
  public:
    Controlled_reference_eventContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Controlled_timing_check_eventContext> controlled_timing_check_event();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Controlled_reference_eventContext> controlled_reference_event();

  class Data_eventContext : public ParserRuleContext {
  public:
    Data_eventContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Timing_check_eventContext> timing_check_event();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Data_eventContext> data_event();

  class Delayed_dataContext : public ParserRuleContext {
  public:
    Delayed_dataContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Terminal_identifierContext> terminal_identifier();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Delayed_dataContext> delayed_data();

  class Delayed_referenceContext : public ParserRuleContext {
  public:
    Delayed_referenceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Terminal_identifierContext> terminal_identifier();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Delayed_referenceContext> delayed_reference();

  class End_edge_offsetContext : public ParserRuleContext {
  public:
    End_edge_offsetContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<End_edge_offsetContext> end_edge_offset();

  class Event_based_flagContext : public ParserRuleContext {
  public:
    Event_based_flagContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Event_based_flagContext> event_based_flag();

  class NotifierContext : public ParserRuleContext {
  public:
    NotifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<NotifierContext> notifier();

  class Reference_eventContext : public ParserRuleContext {
  public:
    Reference_eventContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Timing_check_eventContext> timing_check_event();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Reference_eventContext> reference_event();

  class Remain_active_flagContext : public ParserRuleContext {
  public:
    Remain_active_flagContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Remain_active_flagContext> remain_active_flag();

  class Timestamp_conditionContext : public ParserRuleContext {
  public:
    Timestamp_conditionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Timestamp_conditionContext> timestamp_condition();

  class Start_edge_offsetContext : public ParserRuleContext {
  public:
    Start_edge_offsetContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Start_edge_offsetContext> start_edge_offset();

  class ThresholdContext : public ParserRuleContext {
  public:
    ThresholdContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<ThresholdContext> threshold();

  class Timing_check_limitContext : public ParserRuleContext {
  public:
    Timing_check_limitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Timing_check_limitContext> timing_check_limit();

  class Timing_check_eventContext : public ParserRuleContext {
  public:
    Timing_check_eventContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Specify_terminal_descriptorContext> specify_terminal_descriptor();
    Ref<Timing_check_event_controlContext> timing_check_event_control();
    Ref<Timing_check_conditionContext> timing_check_condition();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Timing_check_eventContext> timing_check_event();

  class Controlled_timing_check_eventContext : public ParserRuleContext {
  public:
    Controlled_timing_check_eventContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Timing_check_event_controlContext> timing_check_event_control();
    Ref<Specify_terminal_descriptorContext> specify_terminal_descriptor();
    Ref<Timing_check_conditionContext> timing_check_condition();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Controlled_timing_check_eventContext> controlled_timing_check_event();

  class Timing_check_event_controlContext : public ParserRuleContext {
  public:
    Timing_check_event_controlContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Edge_control_specifierContext> edge_control_specifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Timing_check_event_controlContext> timing_check_event_control();

  class Specify_terminal_descriptorContext : public ParserRuleContext {
  public:
    Specify_terminal_descriptorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Specify_input_terminal_descriptorContext> specify_input_terminal_descriptor();
    Ref<Specify_output_terminal_descriptorContext> specify_output_terminal_descriptor();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Specify_terminal_descriptorContext> specify_terminal_descriptor();

  class Edge_control_specifierContext : public ParserRuleContext {
  public:
    Edge_control_specifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Edge_descriptorContext>> edge_descriptor();
    Ref<Edge_descriptorContext> edge_descriptor(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Edge_control_specifierContext> edge_control_specifier();

  class Edge_descriptorContext : public ParserRuleContext {
  public:
    Edge_descriptorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Unsigned_number();
    Ref<tree::TerminalNode> Simple_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Edge_descriptorContext> edge_descriptor();

  class Timing_check_conditionContext : public ParserRuleContext {
  public:
    Timing_check_conditionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Scalar_timing_check_conditionContext> scalar_timing_check_condition();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Timing_check_conditionContext> timing_check_condition();

  class Scalar_timing_check_conditionContext : public ParserRuleContext {
  public:
    Scalar_timing_check_conditionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Scalar_constantContext> scalar_constant();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Scalar_timing_check_conditionContext> scalar_timing_check_condition();

  class Scalar_constantContext : public ParserRuleContext {
  public:
    Scalar_constantContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Integral_number();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Scalar_constantContext> scalar_constant();

  class ConcatenationContext : public ParserRuleContext {
  public:
    ConcatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<ConcatenationContext> concatenation();

  class Constant_concatenationContext : public ParserRuleContext {
  public:
    Constant_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_concatenationContext> constant_concatenation();

  class Constant_multiple_concatenationContext : public ParserRuleContext {
  public:
    Constant_multiple_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<Constant_concatenationContext> constant_concatenation();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_multiple_concatenationContext> constant_multiple_concatenation();

  class Module_path_concatenationContext : public ParserRuleContext {
  public:
    Module_path_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Module_path_expressionContext>> module_path_expression();
    Ref<Module_path_expressionContext> module_path_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_path_concatenationContext> module_path_concatenation();

  class Module_path_multiple_concatenationContext : public ParserRuleContext {
  public:
    Module_path_multiple_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<Module_path_concatenationContext> module_path_concatenation();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_path_multiple_concatenationContext> module_path_multiple_concatenation();

  class Multiple_concatenationContext : public ParserRuleContext {
  public:
    Multiple_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<ConcatenationContext> concatenation();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Multiple_concatenationContext> multiple_concatenation();

  class Streaming_concatenationContext : public ParserRuleContext {
  public:
    Streaming_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Stream_operatorContext> stream_operator();
    Ref<Stream_concatenationContext> stream_concatenation();
    Ref<Slice_sizeContext> slice_size();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Streaming_concatenationContext> streaming_concatenation();

  class Stream_operatorContext : public ParserRuleContext {
  public:
    Stream_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Stream_operatorContext> stream_operator();

  class Slice_sizeContext : public ParserRuleContext {
  public:
    Slice_sizeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_typeContext> simple_type();
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Slice_sizeContext> slice_size();

  class Stream_concatenationContext : public ParserRuleContext {
  public:
    Stream_concatenationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Stream_expressionContext>> stream_expression();
    Ref<Stream_expressionContext> stream_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Stream_concatenationContext> stream_concatenation();

  class Stream_expressionContext : public ParserRuleContext {
  public:
    Stream_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Array_range_expressionContext> array_range_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Stream_expressionContext> stream_expression();

  class Array_range_expressionContext : public ParserRuleContext {
  public:
    Array_range_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Array_range_expressionContext> array_range_expression();

  class Empty_queueContext : public ParserRuleContext {
  public:
    Empty_queueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Empty_queueContext> empty_queue();

  class Constant_function_callContext : public ParserRuleContext {
  public:
    Constant_function_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Function_subroutine_callContext> function_subroutine_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_function_callContext> constant_function_call();

  class Tf_callContext : public ParserRuleContext {
  public:
    Tf_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_or_hierarchical_tf_identifierContext> ps_or_hierarchical_tf_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<List_of_argumentsContext> list_of_arguments();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tf_callContext> tf_call();

  class System_tf_callContext : public ParserRuleContext {
  public:
    System_tf_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> System_tf_identifier();
    Ref<List_of_argumentsContext> list_of_arguments();
    Ref<Data_typeContext> data_type();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<System_tf_callContext> system_tf_call();

  class Function_subroutine_callContext : public ParserRuleContext {
  public:
    Function_subroutine_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subroutine_callContext> subroutine_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Function_subroutine_callContext> function_subroutine_call();

  class Subroutine_callContext : public ParserRuleContext {
  public:
    Subroutine_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Tf_callContext> tf_call();
    Ref<System_tf_callContext> system_tf_call();
    Ref<Randomize_callContext> randomize_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Subroutine_callContext> subroutine_call();

  class Method_callContext : public ParserRuleContext {
  public:
    Method_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Method_call_rootContext> method_call_root();
    Ref<Method_call_bodyContext> method_call_body();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Method_callContext> method_call();

  class Method_call_rootContext : public ParserRuleContext {
  public:
    Method_call_rootContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<PrimaryContext> primary();
    Ref<Implicit_class_handleContext> implicit_class_handle();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Method_call_rootContext> method_call_root();

  class List_of_argumentsContext : public ParserRuleContext {
  public:
    List_of_argumentsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<List_of_argumentsContext> list_of_arguments();

  class Method_call_bodyContext : public ParserRuleContext {
  public:
    Method_call_bodyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Method_identifierContext> method_identifier();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<List_of_argumentsContext> list_of_arguments();
    Ref<Built_in_method_callContext> built_in_method_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Method_call_bodyContext> method_call_body();

  class Built_in_method_callContext : public ParserRuleContext {
  public:
    Built_in_method_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Array_manipulation_callContext> array_manipulation_call();
    Ref<Randomize_callContext> randomize_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Built_in_method_callContext> built_in_method_call();

  class Array_manipulation_callContext : public ParserRuleContext {
  public:
    Array_manipulation_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Array_method_nameContext> array_method_name();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<List_of_argumentsContext> list_of_arguments();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Array_manipulation_callContext> array_manipulation_call();

  class Randomize_callContext : public ParserRuleContext {
  public:
    Randomize_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Constraint_blockContext> constraint_block();
    Ref<Variable_identifier_listContext> variable_identifier_list();
    Ref<Identifier_listContext> identifier_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Randomize_callContext> randomize_call();

  class Array_method_nameContext : public ParserRuleContext {
  public:
    Array_method_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Method_identifierContext> method_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Array_method_nameContext> array_method_name();

  class Inc_or_dec_expressionContext : public ParserRuleContext {
  public:
    Inc_or_dec_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Inc_or_dec_operatorContext> inc_or_dec_operator();
    Ref<Variable_lvalueContext> variable_lvalue();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Inc_or_dec_expressionContext> inc_or_dec_expression();

  class Conditional_expressionContext : public ParserRuleContext {
  public:
    Conditional_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Cond_predicateContext> cond_predicate();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Conditional_expressionContext> conditional_expression();

  class Constant_expressionContext : public ParserRuleContext {
  public:
    Constant_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Unary_operatorContext> unary_operator();
    Ref<Constant_primaryContext> constant_primary();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);
    Ref<Binary_operatorContext> binary_operator();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_expressionContext> constant_expression();
  Ref<Constant_expressionContext> constant_expression(int precedence);
  class Constant_mintypmax_expressionContext : public ParserRuleContext {
  public:
    Constant_mintypmax_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();

  class Constant_param_expressionContext : public ParserRuleContext {
  public:
    Constant_param_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();
    Ref<Data_typeContext> data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_param_expressionContext> constant_param_expression();

  class Param_expressionContext : public ParserRuleContext {
  public:
    Param_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Mintypmax_expressionContext> mintypmax_expression();
    Ref<Data_typeContext> data_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Param_expressionContext> param_expression();

  class Constant_range_expressionContext : public ParserRuleContext {
  public:
    Constant_range_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();
    Ref<Constant_part_select_rangeContext> constant_part_select_range();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_range_expressionContext> constant_range_expression();

  class Constant_part_select_rangeContext : public ParserRuleContext {
  public:
    Constant_part_select_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_rangeContext> constant_range();
    Ref<Constant_indexed_rangeContext> constant_indexed_range();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_part_select_rangeContext> constant_part_select_range();

  class Constant_rangeContext : public ParserRuleContext {
  public:
    Constant_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_rangeContext> constant_range();

  class Constant_indexed_rangeContext : public ParserRuleContext {
  public:
    Constant_indexed_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_indexed_rangeContext> constant_indexed_range();

  class Expression_cond_or_insideContext : public ParserRuleContext {
  public:
    Expression_cond_or_insideContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<PatternContext> pattern();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Open_range_listContext> open_range_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Expression_cond_or_insideContext> expression_cond_or_inside();

  class ExpressionContext : public ParserRuleContext {
  public:
    ExpressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<PrimaryContext> primary();
    Ref<Unary_operatorContext> unary_operator();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Inc_or_dec_expressionContext> inc_or_dec_expression();
    Ref<Operator_assignmentContext> operator_assignment();
    Ref<Tagged_union_expressionContext> tagged_union_expression();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<Binary_operatorContext> binary_operator();
    Ref<Expression_cond_or_insideContext> expression_cond_or_inside();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<ExpressionContext> expression();
  Ref<ExpressionContext> expression(int precedence);
  class Tagged_union_expressionContext : public ParserRuleContext {
  public:
    Tagged_union_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Member_identifierContext> member_identifier();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tagged_union_expressionContext> tagged_union_expression();

  class Inside_expressionContext : public ParserRuleContext {
  public:
    Inside_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Open_range_listContext> open_range_list();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Inside_expressionContext> inside_expression();

  class Value_rangeContext : public ParserRuleContext {
  public:
    Value_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Value_rangeContext> value_range();

  class Mintypmax_expressionContext : public ParserRuleContext {
  public:
    Mintypmax_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_path_conditional_expressionContext> module_path_conditional_expression();

  class Module_path_expressionContext : public ParserRuleContext {
  public:
    Module_path_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Module_path_primaryContext> module_path_primary();
    Ref<Unary_module_path_operatorContext> unary_module_path_operator();
    std::vector<Ref<Attribute_instanceContext>> attribute_instance();
    Ref<Attribute_instanceContext> attribute_instance(int i);
    Ref<Module_path_conditional_expressionContext> module_path_conditional_expression();
    std::vector<Ref<Module_path_expressionContext>> module_path_expression();
    Ref<Module_path_expressionContext> module_path_expression(int i);
    Ref<Binary_module_path_operatorContext> binary_module_path_operator();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_path_expressionContext> module_path_expression();
  Ref<Module_path_expressionContext> module_path_expression(int precedence);
  class Module_path_mintypmax_expressionContext : public ParserRuleContext {
  public:
    Module_path_mintypmax_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Module_path_expressionContext>> module_path_expression();
    Ref<Module_path_expressionContext> module_path_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_path_mintypmax_expressionContext> module_path_mintypmax_expression();

  class Part_select_rangeContext : public ParserRuleContext {
  public:
    Part_select_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_rangeContext> constant_range();
    Ref<Indexed_rangeContext> indexed_range();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Part_select_rangeContext> part_select_range();

  class Indexed_rangeContext : public ParserRuleContext {
  public:
    Indexed_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Indexed_rangeContext> indexed_range();

  class Genvar_expressionContext : public ParserRuleContext {
  public:
    Genvar_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Genvar_expressionContext> genvar_expression();

  class Constant_primaryContext : public ParserRuleContext {
  public:
    Constant_primaryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_parameter_identifierContext> ps_parameter_identifier();
    Ref<Constant_selectContext> constant_select();
    Ref<Specparam_identifierContext> specparam_identifier();
    Ref<Constant_range_expressionContext> constant_range_expression();
    Ref<Genvar_identifierContext> genvar_identifier();
    Ref<Formal_port_identifierContext> formal_port_identifier();
    Ref<Enum_identifierContext> enum_identifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Class_scopeContext> class_scope();
    Ref<Constant_concatenationContext> constant_concatenation();
    Ref<Constant_multiple_concatenationContext> constant_multiple_concatenation();
    Ref<Constant_function_callContext> constant_function_call();
    Ref<Constant_let_expressionContext> constant_let_expression();
    Ref<Constant_mintypmax_expressionContext> constant_mintypmax_expression();
    Ref<Constant_castContext> constant_cast();
    Ref<Constant_assignment_pattern_expressionContext> constant_assignment_pattern_expression();
    Ref<Type_referenceContext> type_reference();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
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
    Ref<Function_subroutine_callContext> function_subroutine_call();
    Ref<Module_path_mintypmax_expressionContext> module_path_mintypmax_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_path_primaryContext> module_path_primary();

  class PrimaryContext : public ParserRuleContext {
  public:
    PrimaryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Primary_literalContext> primary_literal();
    Ref<Hierarchical_identifierContext> hierarchical_identifier();
    Ref<SelectContext> select();
    Ref<Class_qualifierContext> class_qualifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Empty_queueContext> empty_queue();
    Ref<ConcatenationContext> concatenation();
    Ref<Range_expressionContext> range_expression();
    Ref<Multiple_concatenationContext> multiple_concatenation();
    Ref<Function_subroutine_callContext> function_subroutine_call();
    Ref<Let_expressionContext> let_expression();
    Ref<Mintypmax_expressionContext> mintypmax_expression();
    Ref<CastContext> cast();
    Ref<Assignment_pattern_expressionContext> assignment_pattern_expression();
    Ref<Streaming_concatenationContext> streaming_concatenation();
    Ref<Sequence_method_callContext> sequence_method_call();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<PrimaryContext> primary();

  class Class_qualifierContext : public ParserRuleContext {
  public:
    Class_qualifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Implicit_class_handleContext> implicit_class_handle();
    Ref<Class_scopeContext> class_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_qualifierContext> class_qualifier();

  class Range_expressionContext : public ParserRuleContext {
  public:
    Range_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<Part_select_rangeContext> part_select_range();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Range_expressionContext> range_expression();

  class Primary_literalContext : public ParserRuleContext {
  public:
    Primary_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NumberContext> number();
    Ref<Time_literalContext> time_literal();
    Ref<tree::TerminalNode> Unbased_unsized_literal();
    Ref<tree::TerminalNode> String_literal();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Primary_literalContext> primary_literal();

  class Time_literalContext : public ParserRuleContext {
  public:
    Time_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Unsigned_number();
    Ref<Time_unitContext> time_unit();
    Ref<tree::TerminalNode> Fixed_point_number();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Time_literalContext> time_literal();

  class Time_unitContext : public ParserRuleContext {
  public:
    Time_unitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Time_unitContext> time_unit();

  class Implicit_class_handleContext : public ParserRuleContext {
  public:
    Implicit_class_handleContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Implicit_class_handleContext> implicit_class_handle();

  class Bit_selectContext : public ParserRuleContext {
  public:
    Bit_selectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bit_selectContext> bit_select();

  class SelectContext : public ParserRuleContext {
  public:
    SelectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Bit_selectContext>> bit_select();
    Ref<Bit_selectContext> bit_select(int i);
    std::vector<Ref<Member_identifierContext>> member_identifier();
    Ref<Member_identifierContext> member_identifier(int i);
    Ref<Part_select_rangeContext> part_select_range();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<SelectContext> select();

  class Nonrange_selectContext : public ParserRuleContext {
  public:
    Nonrange_selectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Bit_selectContext>> bit_select();
    Ref<Bit_selectContext> bit_select(int i);
    std::vector<Ref<Member_identifierContext>> member_identifier();
    Ref<Member_identifierContext> member_identifier(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Nonrange_selectContext> nonrange_select();

  class Constant_bit_selectContext : public ParserRuleContext {
  public:
    Constant_bit_selectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_bit_selectContext> constant_bit_select();

  class Constant_selectContext : public ParserRuleContext {
  public:
    Constant_selectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Constant_bit_selectContext>> constant_bit_select();
    Ref<Constant_bit_selectContext> constant_bit_select(int i);
    std::vector<Ref<Member_identifierContext>> member_identifier();
    Ref<Member_identifierContext> member_identifier(int i);
    Ref<Constant_part_select_rangeContext> constant_part_select_range();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_selectContext> constant_select();

  class Constant_castContext : public ParserRuleContext {
  public:
    Constant_castContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Casting_type_reducedContext> casting_type_reduced();
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_castContext> constant_cast();

  class Constant_let_expressionContext : public ParserRuleContext {
  public:
    Constant_let_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Let_expressionContext> let_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constant_let_expressionContext> constant_let_expression();

  class CastContext : public ParserRuleContext {
  public:
    CastContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Casting_typeContext> casting_type();
    Ref<ExpressionContext> expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<CastContext> cast();

  class Net_lvalueContext : public ParserRuleContext {
  public:
    Net_lvalueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Ps_or_hierarchical_net_identifierContext> ps_or_hierarchical_net_identifier();
    Ref<Constant_selectContext> constant_select();
    std::vector<Ref<Net_lvalueContext>> net_lvalue();
    Ref<Net_lvalueContext> net_lvalue(int i);
    Ref<Assignment_pattern_net_lvalueContext> assignment_pattern_net_lvalue();
    Ref<Assignment_pattern_expression_typeContext> assignment_pattern_expression_type();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_lvalueContext> net_lvalue();

  class Variable_lvalueContext : public ParserRuleContext {
  public:
    Variable_lvalueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_variable_identifierContext> hierarchical_variable_identifier();
    Ref<SelectContext> select();
    Ref<Implicit_class_handleContext> implicit_class_handle();
    Ref<Package_scopeContext> package_scope();
    std::vector<Ref<Variable_lvalueContext>> variable_lvalue();
    Ref<Variable_lvalueContext> variable_lvalue(int i);
    Ref<Assignment_pattern_variable_lvalueContext> assignment_pattern_variable_lvalue();
    Ref<Assignment_pattern_expression_typeContext> assignment_pattern_expression_type();
    Ref<Streaming_concatenationContext> streaming_concatenation();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Variable_lvalueContext> variable_lvalue();

  class Nonrange_variable_lvalueContext : public ParserRuleContext {
  public:
    Nonrange_variable_lvalueContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_variable_identifierContext> hierarchical_variable_identifier();
    Ref<Nonrange_selectContext> nonrange_select();
    Ref<Implicit_class_handleContext> implicit_class_handle();
    Ref<Package_scopeContext> package_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Nonrange_variable_lvalueContext> nonrange_variable_lvalue();

  class Unary_operatorContext : public ParserRuleContext {
  public:
    Unary_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Unary_operatorContext> unary_operator();

  class Binary_operatorContext : public ParserRuleContext {
  public:
    Binary_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Binary_operatorContext> binary_operator();

  class Inc_or_dec_operatorContext : public ParserRuleContext {
  public:
    Inc_or_dec_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Inc_or_dec_operatorContext> inc_or_dec_operator();

  class Unary_module_path_operatorContext : public ParserRuleContext {
  public:
    Unary_module_path_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Unary_module_path_operatorContext> unary_module_path_operator();

  class Binary_module_path_operatorContext : public ParserRuleContext {
  public:
    Binary_module_path_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Binary_module_path_operatorContext> binary_module_path_operator();

  class NumberContext : public ParserRuleContext {
  public:
    NumberContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Integral_number();
    Ref<tree::TerminalNode> Real_number();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<NumberContext> number();

  class Attribute_instanceContext : public ParserRuleContext {
  public:
    Attribute_instanceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Attr_specContext>> attr_spec();
    Ref<Attr_specContext> attr_spec(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Attribute_instanceContext> attribute_instance();

  class Attr_specContext : public ParserRuleContext {
  public:
    Attr_specContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Attr_nameContext> attr_name();
    Ref<Constant_expressionContext> constant_expression();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Attr_specContext> attr_spec();

  class Attr_nameContext : public ParserRuleContext {
  public:
    Attr_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Attr_nameContext> attr_name();

  class Array_identifierContext : public ParserRuleContext {
  public:
    Array_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Array_identifierContext> array_identifier();

  class Block_identifierContext : public ParserRuleContext {
  public:
    Block_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Block_identifierContext> block_identifier();

  class Bin_identifierContext : public ParserRuleContext {
  public:
    Bin_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Bin_identifierContext> bin_identifier();

  class C_identifierContext : public ParserRuleContext {
  public:
    C_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Simple_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<C_identifierContext> c_identifier();

  class Cell_identifierContext : public ParserRuleContext {
  public:
    Cell_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cell_identifierContext> cell_identifier();

  class Checker_identifierContext : public ParserRuleContext {
  public:
    Checker_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Checker_identifierContext> checker_identifier();

  class Class_identifierContext : public ParserRuleContext {
  public:
    Class_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_identifierContext> class_identifier();

  class Class_variable_identifierContext : public ParserRuleContext {
  public:
    Class_variable_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Class_variable_identifierContext> class_variable_identifier();

  class Clocking_identifierContext : public ParserRuleContext {
  public:
    Clocking_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Clocking_identifierContext> clocking_identifier();

  class Config_identifierContext : public ParserRuleContext {
  public:
    Config_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Config_identifierContext> config_identifier();

  class Const_identifierContext : public ParserRuleContext {
  public:
    Const_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Const_identifierContext> const_identifier();

  class Constraint_identifierContext : public ParserRuleContext {
  public:
    Constraint_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Constraint_identifierContext> constraint_identifier();

  class Covergroup_identifierContext : public ParserRuleContext {
  public:
    Covergroup_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Covergroup_identifierContext> covergroup_identifier();

  class Covergroup_variable_identifierContext : public ParserRuleContext {
  public:
    Covergroup_variable_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Covergroup_variable_identifierContext> covergroup_variable_identifier();

  class Cover_point_identifierContext : public ParserRuleContext {
  public:
    Cover_point_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cover_point_identifierContext> cover_point_identifier();

  class Cross_identifierContext : public ParserRuleContext {
  public:
    Cross_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Cross_identifierContext> cross_identifier();

  class Dynamic_array_variable_identifierContext : public ParserRuleContext {
  public:
    Dynamic_array_variable_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Variable_identifierContext> variable_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Dynamic_array_variable_identifierContext> dynamic_array_variable_identifier();

  class Enum_identifierContext : public ParserRuleContext {
  public:
    Enum_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Enum_identifierContext> enum_identifier();

  class Formal_identifierContext : public ParserRuleContext {
  public:
    Formal_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Formal_identifierContext> formal_identifier();

  class Formal_port_identifierContext : public ParserRuleContext {
  public:
    Formal_port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Formal_port_identifierContext> formal_port_identifier();

  class Function_identifierContext : public ParserRuleContext {
  public:
    Function_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Function_identifierContext> function_identifier();

  class Generate_block_identifierContext : public ParserRuleContext {
  public:
    Generate_block_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Generate_block_identifierContext> generate_block_identifier();

  class Genvar_identifierContext : public ParserRuleContext {
  public:
    Genvar_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Genvar_identifierContext> genvar_identifier();

  class Hierarchical_array_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_array_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_array_identifierContext> hierarchical_array_identifier();

  class Hierarchical_block_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_block_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_block_identifierContext> hierarchical_block_identifier();

  class Hierarchical_event_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_event_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_event_identifierContext> hierarchical_event_identifier();

  class Hierarchical_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    std::vector<Ref<Constant_bit_selectContext>> constant_bit_select();
    Ref<Constant_bit_selectContext> constant_bit_select(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_identifierContext> hierarchical_identifier();

  class Hierarchical_net_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_net_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_net_identifierContext> hierarchical_net_identifier();

  class Hierarchical_parameter_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_parameter_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_parameter_identifierContext> hierarchical_parameter_identifier();

  class Hierarchical_property_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_property_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_property_identifierContext> hierarchical_property_identifier();

  class Hierarchical_sequence_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_sequence_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_sequence_identifierContext> hierarchical_sequence_identifier();

  class Hierarchical_task_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_task_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_task_identifierContext> hierarchical_task_identifier();

  class Hierarchical_tf_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_tf_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_tf_identifierContext> hierarchical_tf_identifier();

  class Hierarchical_variable_identifierContext : public ParserRuleContext {
  public:
    Hierarchical_variable_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_identifierContext> hierarchical_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Hierarchical_variable_identifierContext> hierarchical_variable_identifier();

  class IdentifierContext : public ParserRuleContext {
  public:
    IdentifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> Simple_identifier();
    Ref<tree::TerminalNode> Escaped_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<IdentifierContext> identifier();

  class Index_variable_identifierContext : public ParserRuleContext {
  public:
    Index_variable_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Index_variable_identifierContext> index_variable_identifier();

  class Interface_identifierContext : public ParserRuleContext {
  public:
    Interface_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_identifierContext> interface_identifier();

  class Interface_instance_identifierContext : public ParserRuleContext {
  public:
    Interface_instance_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Interface_instance_identifierContext> interface_instance_identifier();

  class Inout_port_identifierContext : public ParserRuleContext {
  public:
    Inout_port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Inout_port_identifierContext> inout_port_identifier();

  class Input_port_identifierContext : public ParserRuleContext {
  public:
    Input_port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Input_port_identifierContext> input_port_identifier();

  class Instance_identifierContext : public ParserRuleContext {
  public:
    Instance_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Instance_identifierContext> instance_identifier();

  class Library_identifierContext : public ParserRuleContext {
  public:
    Library_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Library_identifierContext> library_identifier();

  class Member_identifierContext : public ParserRuleContext {
  public:
    Member_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Member_identifierContext> member_identifier();

  class Method_identifierContext : public ParserRuleContext {
  public:
    Method_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Method_identifierContext> method_identifier();

  class Modport_identifierContext : public ParserRuleContext {
  public:
    Modport_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Modport_identifierContext> modport_identifier();

  class Module_identifierContext : public ParserRuleContext {
  public:
    Module_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Module_identifierContext> module_identifier();

  class Net_identifierContext : public ParserRuleContext {
  public:
    Net_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_identifierContext> net_identifier();

  class Net_type_identifierContext : public ParserRuleContext {
  public:
    Net_type_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Net_type_identifierContext> net_type_identifier();

  class Output_port_identifierContext : public ParserRuleContext {
  public:
    Output_port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Output_port_identifierContext> output_port_identifier();

  class Package_identifierContext : public ParserRuleContext {
  public:
    Package_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Package_identifierContext> package_identifier();

  class Package_scopeContext : public ParserRuleContext {
  public:
    Package_scopeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Package_identifierContext> package_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Package_scopeContext> package_scope();

  class Parameter_identifierContext : public ParserRuleContext {
  public:
    Parameter_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Parameter_identifierContext> parameter_identifier();

  class Port_identifierContext : public ParserRuleContext {
  public:
    Port_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Port_identifierContext> port_identifier();

  class Production_identifierContext : public ParserRuleContext {
  public:
    Production_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Production_identifierContext> production_identifier();

  class Program_identifierContext : public ParserRuleContext {
  public:
    Program_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Program_identifierContext> program_identifier();

  class Property_identifierContext : public ParserRuleContext {
  public:
    Property_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Property_identifierContext> property_identifier();

  class Ps_class_identifierContext : public ParserRuleContext {
  public:
    Ps_class_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Class_identifierContext> class_identifier();
    Ref<Package_scopeContext> package_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_class_identifierContext> ps_class_identifier();

  class Ps_covergroup_identifierContext : public ParserRuleContext {
  public:
    Ps_covergroup_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Covergroup_identifierContext> covergroup_identifier();
    Ref<Package_scopeContext> package_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_covergroup_identifierContext> ps_covergroup_identifier();

  class Ps_checker_identifierContext : public ParserRuleContext {
  public:
    Ps_checker_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Checker_identifierContext> checker_identifier();
    Ref<Package_scopeContext> package_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_checker_identifierContext> ps_checker_identifier();

  class Ps_identifierContext : public ParserRuleContext {
  public:
    Ps_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<Package_scopeContext> package_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_identifierContext> ps_identifier();

  class Ps_or_hierarchical_array_identifierContext : public ParserRuleContext {
  public:
    Ps_or_hierarchical_array_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Hierarchical_array_identifierContext> hierarchical_array_identifier();
    Ref<Implicit_class_handleContext> implicit_class_handle();
    Ref<Class_scopeContext> class_scope();
    Ref<Package_scopeContext> package_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_or_hierarchical_array_identifierContext> ps_or_hierarchical_array_identifier();

  class Ps_or_hierarchical_net_identifierContext : public ParserRuleContext {
  public:
    Ps_or_hierarchical_net_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Net_identifierContext> net_identifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Hierarchical_net_identifierContext> hierarchical_net_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_or_hierarchical_net_identifierContext> ps_or_hierarchical_net_identifier();

  class Ps_or_hierarchical_property_identifierContext : public ParserRuleContext {
  public:
    Ps_or_hierarchical_property_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Property_identifierContext> property_identifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Hierarchical_property_identifierContext> hierarchical_property_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_or_hierarchical_property_identifierContext> ps_or_hierarchical_property_identifier();

  class Ps_or_hierarchical_sequence_identifierContext : public ParserRuleContext {
  public:
    Ps_or_hierarchical_sequence_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Sequence_identifierContext> sequence_identifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Hierarchical_sequence_identifierContext> hierarchical_sequence_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_or_hierarchical_sequence_identifierContext> ps_or_hierarchical_sequence_identifier();

  class Ps_or_hierarchical_tf_identifierContext : public ParserRuleContext {
  public:
    Ps_or_hierarchical_tf_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Tf_identifierContext> tf_identifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Hierarchical_tf_identifierContext> hierarchical_tf_identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_or_hierarchical_tf_identifierContext> ps_or_hierarchical_tf_identifier();

  class Ps_parameter_identifierContext : public ParserRuleContext {
  public:
    Ps_parameter_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Parameter_identifierContext> parameter_identifier();
    Ref<Package_scopeContext> package_scope();
    Ref<Class_scopeContext> class_scope();
    std::vector<Ref<Generate_block_identifierContext>> generate_block_identifier();
    Ref<Generate_block_identifierContext> generate_block_identifier(int i);
    std::vector<Ref<Constant_expressionContext>> constant_expression();
    Ref<Constant_expressionContext> constant_expression(int i);

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_parameter_identifierContext> ps_parameter_identifier();

  class Ps_type_identifierContext : public ParserRuleContext {
  public:
    Ps_type_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Type_identifierContext> type_identifier();
    Ref<Package_scopeContext> package_scope();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Ps_type_identifierContext> ps_type_identifier();

  class Sequence_identifierContext : public ParserRuleContext {
  public:
    Sequence_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Sequence_identifierContext> sequence_identifier();

  class Signal_identifierContext : public ParserRuleContext {
  public:
    Signal_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Signal_identifierContext> signal_identifier();

  class Specparam_identifierContext : public ParserRuleContext {
  public:
    Specparam_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Specparam_identifierContext> specparam_identifier();

  class Task_identifierContext : public ParserRuleContext {
  public:
    Task_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Task_identifierContext> task_identifier();

  class Tf_identifierContext : public ParserRuleContext {
  public:
    Tf_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Tf_identifierContext> tf_identifier();

  class Terminal_identifierContext : public ParserRuleContext {
  public:
    Terminal_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Terminal_identifierContext> terminal_identifier();

  class Topmodule_identifierContext : public ParserRuleContext {
  public:
    Topmodule_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Topmodule_identifierContext> topmodule_identifier();

  class Type_identifierContext : public ParserRuleContext {
  public:
    Type_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Type_identifierContext> type_identifier();

  class Udp_identifierContext : public ParserRuleContext {
  public:
    Udp_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Udp_identifierContext> udp_identifier();

  class Variable_identifierContext : public ParserRuleContext {
  public:
    Variable_identifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual antlrcpp::Any accept(tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref<Variable_identifierContext> variable_identifier();


  virtual bool sempred(Ref<RuleContext> const& _localctx, int ruleIndex, int predicateIndex) override;
  bool property_exprSempred(Ref<Property_exprContext> const& _localctx, int predicateIndex);
  bool sequence_exprSempred(Ref<Sequence_exprContext> const& _localctx, int predicateIndex);
  bool block_event_expressionSempred(Ref<Block_event_expressionContext> const& _localctx, int predicateIndex);
  bool select_expressionSempred(Ref<Select_expressionContext> const& _localctx, int predicateIndex);
  bool event_expressionSempred(Ref<Event_expressionContext> const& _localctx, int predicateIndex);
  bool constant_expressionSempred(Ref<Constant_expressionContext> const& _localctx, int predicateIndex);
  bool expressionSempred(Ref<ExpressionContext> const& _localctx, int predicateIndex);
  bool module_path_expressionSempred(Ref<Module_path_expressionContext> const& _localctx, int predicateIndex);

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

}  // namespace sv
