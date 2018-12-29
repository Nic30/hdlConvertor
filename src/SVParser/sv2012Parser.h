
// Generated from /home/tom/prog/git/hdlConvertor/grammars/sv2012.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace sv {


class  sv2012Parser : public antlr4::Parser {
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

  sv2012Parser(antlr4::TokenStream *input);
  ~sv2012Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


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

  class  Library_textContext : public antlr4::ParserRuleContext {
  public:
    Library_textContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Library_descriptionContext *> library_description();
    Library_descriptionContext* library_description(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Library_textContext* library_text();

  class  Library_descriptionContext : public antlr4::ParserRuleContext {
  public:
    Library_descriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Library_declarationContext *library_declaration();
    Include_statementContext *include_statement();
    Config_declarationContext *config_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Library_descriptionContext* library_description();

  class  Library_declarationContext : public antlr4::ParserRuleContext {
  public:
    Library_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Library_identifierContext *library_identifier();
    std::vector<antlr4::tree::TerminalNode *> File_path_spec();
    antlr4::tree::TerminalNode* File_path_spec(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Library_declarationContext* library_declaration();

  class  Include_statementContext : public antlr4::ParserRuleContext {
  public:
    Include_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *File_path_spec();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Include_statementContext* include_statement();

  class  Source_textContext : public antlr4::ParserRuleContext {
  public:
    Source_textContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    Timeunits_declarationContext *timeunits_declaration();
    std::vector<DescriptionContext *> description();
    DescriptionContext* description(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Source_textContext* source_text();

  class  DescriptionContext : public antlr4::ParserRuleContext {
  public:
    DescriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_declarationContext *module_declaration();
    Udp_declarationContext *udp_declaration();
    Interface_declarationContext *interface_declaration();
    Program_declarationContext *program_declaration();
    Package_declarationContext *package_declaration();
    Package_itemContext *package_item();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Bind_directiveContext *bind_directive();
    Config_declarationContext *config_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DescriptionContext* description();

  class  Module_nonansi_headerContext : public antlr4::ParserRuleContext {
  public:
    Module_nonansi_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_keywordContext *module_keyword();
    Module_identifierContext *module_identifier();
    List_of_portsContext *list_of_ports();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    LifetimeContext *lifetime();
    std::vector<Package_import_declarationContext *> package_import_declaration();
    Package_import_declarationContext* package_import_declaration(size_t i);
    Parameter_port_listContext *parameter_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_nonansi_headerContext* module_nonansi_header();

  class  Module_ansi_headerContext : public antlr4::ParserRuleContext {
  public:
    Module_ansi_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_keywordContext *module_keyword();
    Module_identifierContext *module_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    LifetimeContext *lifetime();
    std::vector<Package_import_declarationContext *> package_import_declaration();
    Package_import_declarationContext* package_import_declaration(size_t i);
    Parameter_port_listContext *parameter_port_list();
    List_of_port_declarationsContext *list_of_port_declarations();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_ansi_headerContext* module_ansi_header();

  class  Module_declarationContext : public antlr4::ParserRuleContext {
  public:
    Module_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_nonansi_headerContext *module_nonansi_header();
    Timeunits_declarationContext *timeunits_declaration();
    std::vector<Module_itemContext *> module_item();
    Module_itemContext* module_item(size_t i);
    std::vector<Module_identifierContext *> module_identifier();
    Module_identifierContext* module_identifier(size_t i);
    Module_ansi_headerContext *module_ansi_header();
    std::vector<Non_port_module_itemContext *> non_port_module_item();
    Non_port_module_itemContext* non_port_module_item(size_t i);
    Module_keywordContext *module_keyword();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    LifetimeContext *lifetime();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_declarationContext* module_declaration();

  class  Module_keywordContext : public antlr4::ParserRuleContext {
  public:
    Module_keywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_keywordContext* module_keyword();

  class  Interface_declarationContext : public antlr4::ParserRuleContext {
  public:
    Interface_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Interface_nonansi_headerContext *interface_nonansi_header();
    Timeunits_declarationContext *timeunits_declaration();
    std::vector<Interface_itemContext *> interface_item();
    Interface_itemContext* interface_item(size_t i);
    std::vector<Interface_identifierContext *> interface_identifier();
    Interface_identifierContext* interface_identifier(size_t i);
    Interface_ansi_headerContext *interface_ansi_header();
    std::vector<Non_port_interface_itemContext *> non_port_interface_item();
    Non_port_interface_itemContext* non_port_interface_item(size_t i);
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_declarationContext* interface_declaration();

  class  Interface_nonansi_headerContext : public antlr4::ParserRuleContext {
  public:
    Interface_nonansi_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Interface_identifierContext *interface_identifier();
    List_of_portsContext *list_of_ports();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    LifetimeContext *lifetime();
    std::vector<Package_import_declarationContext *> package_import_declaration();
    Package_import_declarationContext* package_import_declaration(size_t i);
    Parameter_port_listContext *parameter_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_nonansi_headerContext* interface_nonansi_header();

  class  Interface_ansi_headerContext : public antlr4::ParserRuleContext {
  public:
    Interface_ansi_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Interface_identifierContext *interface_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    LifetimeContext *lifetime();
    std::vector<Package_import_declarationContext *> package_import_declaration();
    Package_import_declarationContext* package_import_declaration(size_t i);
    Parameter_port_listContext *parameter_port_list();
    List_of_port_declarationsContext *list_of_port_declarations();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_ansi_headerContext* interface_ansi_header();

  class  Program_declarationContext : public antlr4::ParserRuleContext {
  public:
    Program_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Program_nonansi_headerContext *program_nonansi_header();
    Timeunits_declarationContext *timeunits_declaration();
    std::vector<Program_itemContext *> program_item();
    Program_itemContext* program_item(size_t i);
    std::vector<Program_identifierContext *> program_identifier();
    Program_identifierContext* program_identifier(size_t i);
    Program_ansi_headerContext *program_ansi_header();
    std::vector<Non_port_program_itemContext *> non_port_program_item();
    Non_port_program_itemContext* non_port_program_item(size_t i);
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_declarationContext* program_declaration();

  class  Program_nonansi_headerContext : public antlr4::ParserRuleContext {
  public:
    Program_nonansi_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Program_identifierContext *program_identifier();
    List_of_portsContext *list_of_ports();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    LifetimeContext *lifetime();
    std::vector<Package_import_declarationContext *> package_import_declaration();
    Package_import_declarationContext* package_import_declaration(size_t i);
    Parameter_port_listContext *parameter_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_nonansi_headerContext* program_nonansi_header();

  class  Program_ansi_headerContext : public antlr4::ParserRuleContext {
  public:
    Program_ansi_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Program_identifierContext *program_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    LifetimeContext *lifetime();
    std::vector<Package_import_declarationContext *> package_import_declaration();
    Package_import_declarationContext* package_import_declaration(size_t i);
    Parameter_port_listContext *parameter_port_list();
    List_of_port_declarationsContext *list_of_port_declarations();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_ansi_headerContext* program_ansi_header();

  class  Checker_declarationContext : public antlr4::ParserRuleContext {
  public:
    Checker_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Checker_identifierContext *> checker_identifier();
    Checker_identifierContext* checker_identifier(size_t i);
    std::vector<Checker_or_generate_itemContext *> checker_or_generate_item();
    Checker_or_generate_itemContext* checker_or_generate_item(size_t i);
    Checker_port_listContext *checker_port_list();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_declarationContext* checker_declaration();

  class  Class_declarationContext : public antlr4::ParserRuleContext {
  public:
    Class_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Class_identifierContext *> class_identifier();
    Class_identifierContext* class_identifier(size_t i);
    LifetimeContext *lifetime();
    Parameter_port_listContext *parameter_port_list();
    Class_typeContext *class_type();
    std::vector<Interface_class_typeContext *> interface_class_type();
    Interface_class_typeContext* interface_class_type(size_t i);
    std::vector<Class_itemContext *> class_item();
    Class_itemContext* class_item(size_t i);
    List_of_argumentsContext *list_of_arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_declarationContext* class_declaration();

  class  Interface_class_typeContext : public antlr4::ParserRuleContext {
  public:
    Interface_class_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_class_identifierContext *ps_class_identifier();
    Parameter_value_assignmentContext *parameter_value_assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_class_typeContext* interface_class_type();

  class  Interface_class_declarationContext : public antlr4::ParserRuleContext {
  public:
    Interface_class_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Class_identifierContext *> class_identifier();
    Class_identifierContext* class_identifier(size_t i);
    Parameter_port_listContext *parameter_port_list();
    std::vector<Interface_class_typeContext *> interface_class_type();
    Interface_class_typeContext* interface_class_type(size_t i);
    std::vector<Interface_class_itemContext *> interface_class_item();
    Interface_class_itemContext* interface_class_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_class_declarationContext* interface_class_declaration();

  class  Interface_class_itemContext : public antlr4::ParserRuleContext {
  public:
    Interface_class_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_declarationContext *type_declaration();
    Interface_class_methodContext *interface_class_method();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Local_parameter_declarationContext *local_parameter_declaration();
    Parameter_declarationContext *parameter_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_class_itemContext* interface_class_item();

  class  Interface_class_methodContext : public antlr4::ParserRuleContext {
  public:
    Interface_class_methodContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Method_prototypeContext *method_prototype();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_class_methodContext* interface_class_method();

  class  Package_declarationContext : public antlr4::ParserRuleContext {
  public:
    Package_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Package_identifierContext *> package_identifier();
    Package_identifierContext* package_identifier(size_t i);
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    LifetimeContext *lifetime();
    Timeunits_declarationContext *timeunits_declaration();
    std::vector<Package_itemContext *> package_item();
    Package_itemContext* package_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Package_declarationContext* package_declaration();

  class  Timeunits_declarationContext : public antlr4::ParserRuleContext {
  public:
    Timeunits_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Time_literalContext *> time_literal();
    Time_literalContext* time_literal(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Timeunits_declarationContext* timeunits_declaration();

  class  Parameter_port_listContext : public antlr4::ParserRuleContext {
  public:
    Parameter_port_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_param_assignmentsContext *list_of_param_assignments();
    std::vector<Parameter_port_declarationContext *> parameter_port_declaration();
    Parameter_port_declarationContext* parameter_port_declaration(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_port_listContext* parameter_port_list();

  class  Parameter_port_declarationContext : public antlr4::ParserRuleContext {
  public:
    Parameter_port_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parameter_declarationContext *parameter_declaration();
    Local_parameter_declarationContext *local_parameter_declaration();
    Data_typeContext *data_type();
    List_of_param_assignmentsContext *list_of_param_assignments();
    List_of_type_assignmentsContext *list_of_type_assignments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_port_declarationContext* parameter_port_declaration();

  class  List_of_portsContext : public antlr4::ParserRuleContext {
  public:
    List_of_portsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<PortContext *> port();
    PortContext* port(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_portsContext* list_of_ports();

  class  List_of_port_declarationsContext : public antlr4::ParserRuleContext {
  public:
    List_of_port_declarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Ansi_port_declarationContext *> ansi_port_declaration();
    Ansi_port_declarationContext* ansi_port_declaration(size_t i);
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_port_declarationsContext* list_of_port_declarations();

  class  Port_declarationContext : public antlr4::ParserRuleContext {
  public:
    Port_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Inout_declarationContext *inout_declaration();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Input_declarationContext *input_declaration();
    Output_declarationContext *output_declaration();
    Ref_declarationContext *ref_declaration();
    Interface_port_declarationContext *interface_port_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Port_declarationContext* port_declaration();

  class  PortContext : public antlr4::ParserRuleContext {
  public:
    PortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_expressionContext *port_expression();
    Port_identifierContext *port_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PortContext* port();

  class  Port_expressionContext : public antlr4::ParserRuleContext {
  public:
    Port_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Port_referenceContext *> port_reference();
    Port_referenceContext* port_reference(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Port_expressionContext* port_expression();

  class  Port_referenceContext : public antlr4::ParserRuleContext {
  public:
    Port_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_identifierContext *port_identifier();
    Constant_selectContext *constant_select();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Port_referenceContext* port_reference();

  class  Port_directionContext : public antlr4::ParserRuleContext {
  public:
    Port_directionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Port_directionContext* port_direction();

  class  Net_port_headerContext : public antlr4::ParserRuleContext {
  public:
    Net_port_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_port_typeContext *net_port_type();
    Port_directionContext *port_direction();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_port_headerContext* net_port_header();

  class  Variable_port_headerContext : public antlr4::ParserRuleContext {
  public:
    Variable_port_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_port_typeContext *variable_port_type();
    Port_directionContext *port_direction();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_port_headerContext* variable_port_header();

  class  Interface_port_headerContext : public antlr4::ParserRuleContext {
  public:
    Interface_port_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Interface_identifierContext *interface_identifier();
    Modport_identifierContext *modport_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_port_headerContext* interface_port_header();

  class  Ansi_port_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ansi_port_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_identifierContext *port_identifier();
    Net_port_headerContext *net_port_header();
    Interface_port_headerContext *interface_port_header();
    std::vector<Unpacked_dimensionContext *> unpacked_dimension();
    Unpacked_dimensionContext* unpacked_dimension(size_t i);
    Constant_expressionContext *constant_expression();
    Variable_port_headerContext *variable_port_header();
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    Port_directionContext *port_direction();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ansi_port_declarationContext* ansi_port_declaration();

  class  Elaboration_system_taskContext : public antlr4::ParserRuleContext {
  public:
    Elaboration_system_taskContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Finish_numberContext *finish_number();
    List_of_argumentsContext *list_of_arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elaboration_system_taskContext* elaboration_system_task();

  class  Finish_numberContext : public antlr4::ParserRuleContext {
  public:
    Finish_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Unsigned_number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Finish_numberContext* finish_number();

  class  Module_common_itemContext : public antlr4::ParserRuleContext {
  public:
    Module_common_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_or_generate_item_declarationContext *module_or_generate_item_declaration();
    Interface_instantiationContext *interface_instantiation();
    Program_instantiationContext *program_instantiation();
    Assertion_itemContext *assertion_item();
    Bind_directiveContext *bind_directive();
    Continuous_assignContext *continuous_assign();
    Net_aliasContext *net_alias();
    Initial_constructContext *initial_construct();
    Final_constructContext *final_construct();
    Always_constructContext *always_construct();
    Loop_generate_constructContext *loop_generate_construct();
    Conditional_generate_constructContext *conditional_generate_construct();
    Elaboration_system_taskContext *elaboration_system_task();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_common_itemContext* module_common_item();

  class  Module_itemContext : public antlr4::ParserRuleContext {
  public:
    Module_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_declarationContext *port_declaration();
    Non_port_module_itemContext *non_port_module_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_itemContext* module_item();

  class  Module_or_generate_itemContext : public antlr4::ParserRuleContext {
  public:
    Module_or_generate_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parameter_overrideContext *parameter_override();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Gate_instantiationContext *gate_instantiation();
    Udp_instantiationContext *udp_instantiation();
    Module_instantiationContext *module_instantiation();
    Module_common_itemContext *module_common_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_or_generate_itemContext* module_or_generate_item();

  class  Module_or_generate_item_declarationContext : public antlr4::ParserRuleContext {
  public:
    Module_or_generate_item_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Package_or_generate_item_declarationContext *package_or_generate_item_declaration();
    Genvar_declarationContext *genvar_declaration();
    Clocking_declarationContext *clocking_declaration();
    Clocking_identifierContext *clocking_identifier();
    Expression_or_distContext *expression_or_dist();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_or_generate_item_declarationContext* module_or_generate_item_declaration();

  class  Non_port_module_itemContext : public antlr4::ParserRuleContext {
  public:
    Non_port_module_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Generate_regionContext *generate_region();
    Module_or_generate_itemContext *module_or_generate_item();
    Specify_blockContext *specify_block();
    Specparam_declarationContext *specparam_declaration();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Program_declarationContext *program_declaration();
    Module_declarationContext *module_declaration();
    Interface_declarationContext *interface_declaration();
    Timeunits_declarationContext *timeunits_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Non_port_module_itemContext* non_port_module_item();

  class  Parameter_overrideContext : public antlr4::ParserRuleContext {
  public:
    Parameter_overrideContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_defparam_assignmentsContext *list_of_defparam_assignments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_overrideContext* parameter_override();

  class  Bind_directiveContext : public antlr4::ParserRuleContext {
  public:
    Bind_directiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bind_target_scopeContext *bind_target_scope();
    Bind_instantiationContext *bind_instantiation();
    Bind_target_instance_listContext *bind_target_instance_list();
    Bind_target_instanceContext *bind_target_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bind_directiveContext* bind_directive();

  class  Bind_target_scopeContext : public antlr4::ParserRuleContext {
  public:
    Bind_target_scopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_identifierContext *module_identifier();
    Interface_identifierContext *interface_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bind_target_scopeContext* bind_target_scope();

  class  Bind_target_instanceContext : public antlr4::ParserRuleContext {
  public:
    Bind_target_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();
    Constant_bit_selectContext *constant_bit_select();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bind_target_instanceContext* bind_target_instance();

  class  Bind_target_instance_listContext : public antlr4::ParserRuleContext {
  public:
    Bind_target_instance_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Bind_target_instanceContext *> bind_target_instance();
    Bind_target_instanceContext* bind_target_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bind_target_instance_listContext* bind_target_instance_list();

  class  Bind_instantiationContext : public antlr4::ParserRuleContext {
  public:
    Bind_instantiationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Program_instantiationContext *program_instantiation();
    Module_instantiationContext *module_instantiation();
    Interface_instantiationContext *interface_instantiation();
    Checker_instantiationContext *checker_instantiation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bind_instantiationContext* bind_instantiation();

  class  Config_declarationContext : public antlr4::ParserRuleContext {
  public:
    Config_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Config_identifierContext *> config_identifier();
    Config_identifierContext* config_identifier(size_t i);
    Design_statementContext *design_statement();
    std::vector<Local_parameter_declarationContext *> local_parameter_declaration();
    Local_parameter_declarationContext* local_parameter_declaration(size_t i);
    std::vector<Config_rule_statementContext *> config_rule_statement();
    Config_rule_statementContext* config_rule_statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Config_declarationContext* config_declaration();

  class  Design_statementContext : public antlr4::ParserRuleContext {
  public:
    Design_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Cell_identifierContext *> cell_identifier();
    Cell_identifierContext* cell_identifier(size_t i);
    std::vector<Library_identifierContext *> library_identifier();
    Library_identifierContext* library_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Design_statementContext* design_statement();

  class  Config_rule_statementContext : public antlr4::ParserRuleContext {
  public:
    Config_rule_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Default_clauseContext *default_clause();
    Liblist_clauseContext *liblist_clause();
    Inst_clauseContext *inst_clause();
    Use_clauseContext *use_clause();
    Cell_clauseContext *cell_clause();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Config_rule_statementContext* config_rule_statement();

  class  Default_clauseContext : public antlr4::ParserRuleContext {
  public:
    Default_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Default_clauseContext* default_clause();

  class  Inst_clauseContext : public antlr4::ParserRuleContext {
  public:
    Inst_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Inst_nameContext *inst_name();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inst_clauseContext* inst_clause();

  class  Inst_nameContext : public antlr4::ParserRuleContext {
  public:
    Inst_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Topmodule_identifierContext *topmodule_identifier();
    std::vector<Instance_identifierContext *> instance_identifier();
    Instance_identifierContext* instance_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inst_nameContext* inst_name();

  class  Cell_clauseContext : public antlr4::ParserRuleContext {
  public:
    Cell_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cell_identifierContext *cell_identifier();
    Library_identifierContext *library_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cell_clauseContext* cell_clause();

  class  Liblist_clauseContext : public antlr4::ParserRuleContext {
  public:
    Liblist_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Library_identifierContext *> library_identifier();
    Library_identifierContext* library_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Liblist_clauseContext* liblist_clause();

  class  Use_clauseContext : public antlr4::ParserRuleContext {
  public:
    Use_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cell_identifierContext *cell_identifier();
    Library_identifierContext *library_identifier();
    std::vector<Named_parameter_assignmentContext *> named_parameter_assignment();
    Named_parameter_assignmentContext* named_parameter_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Use_clauseContext* use_clause();

  class  Interface_or_generate_itemContext : public antlr4::ParserRuleContext {
  public:
    Interface_or_generate_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_common_itemContext *module_common_item();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Modport_declarationContext *modport_declaration();
    Extern_tf_declarationContext *extern_tf_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_or_generate_itemContext* interface_or_generate_item();

  class  Extern_tf_declarationContext : public antlr4::ParserRuleContext {
  public:
    Extern_tf_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Method_prototypeContext *method_prototype();
    Task_prototypeContext *task_prototype();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extern_tf_declarationContext* extern_tf_declaration();

  class  Interface_itemContext : public antlr4::ParserRuleContext {
  public:
    Interface_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_declarationContext *port_declaration();
    Non_port_interface_itemContext *non_port_interface_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_itemContext* interface_item();

  class  Non_port_interface_itemContext : public antlr4::ParserRuleContext {
  public:
    Non_port_interface_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Generate_regionContext *generate_region();
    Interface_or_generate_itemContext *interface_or_generate_item();
    Program_declarationContext *program_declaration();
    Interface_declarationContext *interface_declaration();
    Timeunits_declarationContext *timeunits_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Non_port_interface_itemContext* non_port_interface_item();

  class  Program_itemContext : public antlr4::ParserRuleContext {
  public:
    Program_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_declarationContext *port_declaration();
    Non_port_program_itemContext *non_port_program_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_itemContext* program_item();

  class  Non_port_program_itemContext : public antlr4::ParserRuleContext {
  public:
    Non_port_program_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Continuous_assignContext *continuous_assign();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Module_or_generate_item_declarationContext *module_or_generate_item_declaration();
    Initial_constructContext *initial_construct();
    Final_constructContext *final_construct();
    Concurrent_assertion_itemContext *concurrent_assertion_item();
    Timeunits_declarationContext *timeunits_declaration();
    Program_generate_itemContext *program_generate_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Non_port_program_itemContext* non_port_program_item();

  class  Program_generate_itemContext : public antlr4::ParserRuleContext {
  public:
    Program_generate_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Loop_generate_constructContext *loop_generate_construct();
    Conditional_generate_constructContext *conditional_generate_construct();
    Generate_regionContext *generate_region();
    Elaboration_system_taskContext *elaboration_system_task();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_generate_itemContext* program_generate_item();

  class  Checker_port_listContext : public antlr4::ParserRuleContext {
  public:
    Checker_port_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Checker_port_itemContext *> checker_port_item();
    Checker_port_itemContext* checker_port_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_port_listContext* checker_port_list();

  class  Checker_port_itemContext : public antlr4::ParserRuleContext {
  public:
    Checker_port_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_formal_typeContext *property_formal_type();
    Formal_port_identifierContext *formal_port_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Checker_port_directionContext *checker_port_direction();
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    Property_actual_argContext *property_actual_arg();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_port_itemContext* checker_port_item();

  class  Checker_port_directionContext : public antlr4::ParserRuleContext {
  public:
    Checker_port_directionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_port_directionContext* checker_port_direction();

  class  Checker_or_generate_itemContext : public antlr4::ParserRuleContext {
  public:
    Checker_or_generate_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Checker_or_generate_item_declarationContext *checker_or_generate_item_declaration();
    Initial_constructContext *initial_construct();
    Always_constructContext *always_construct();
    Final_constructContext *final_construct();
    Assertion_itemContext *assertion_item();
    Continuous_assignContext *continuous_assign();
    Checker_generate_itemContext *checker_generate_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_or_generate_itemContext* checker_or_generate_item();

  class  Checker_or_generate_item_declarationContext : public antlr4::ParserRuleContext {
  public:
    Checker_or_generate_item_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_declarationContext *data_declaration();
    Function_declarationContext *function_declaration();
    Checker_declarationContext *checker_declaration();
    Assertion_item_declarationContext *assertion_item_declaration();
    Covergroup_declarationContext *covergroup_declaration();
    Overload_declarationContext *overload_declaration();
    Genvar_declarationContext *genvar_declaration();
    Clocking_declarationContext *clocking_declaration();
    Clocking_identifierContext *clocking_identifier();
    Expression_or_distContext *expression_or_dist();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_or_generate_item_declarationContext* checker_or_generate_item_declaration();

  class  Checker_generate_itemContext : public antlr4::ParserRuleContext {
  public:
    Checker_generate_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Loop_generate_constructContext *loop_generate_construct();
    Conditional_generate_constructContext *conditional_generate_construct();
    Generate_regionContext *generate_region();
    Elaboration_system_taskContext *elaboration_system_task();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_generate_itemContext* checker_generate_item();

  class  Class_itemContext : public antlr4::ParserRuleContext {
  public:
    Class_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_propertyContext *class_property();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Class_methodContext *class_method();
    Class_constraintContext *class_constraint();
    Class_declarationContext *class_declaration();
    Covergroup_declarationContext *covergroup_declaration();
    Local_parameter_declarationContext *local_parameter_declaration();
    Parameter_declarationContext *parameter_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_itemContext* class_item();

  class  Class_propertyContext : public antlr4::ParserRuleContext {
  public:
    Class_propertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_declarationContext *data_declaration();
    std::vector<Property_qualifierContext *> property_qualifier();
    Property_qualifierContext* property_qualifier(size_t i);
    Data_typeContext *data_type();
    Const_identifierContext *const_identifier();
    std::vector<Class_item_qualifierContext *> class_item_qualifier();
    Class_item_qualifierContext* class_item_qualifier(size_t i);
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_propertyContext* class_property();

  class  Class_methodContext : public antlr4::ParserRuleContext {
  public:
    Class_methodContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Task_declarationContext *task_declaration();
    std::vector<Method_qualifierContext *> method_qualifier();
    Method_qualifierContext* method_qualifier(size_t i);
    Function_declarationContext *function_declaration();
    Method_prototypeContext *method_prototype();
    std::vector<Class_item_qualifierContext *> class_item_qualifier();
    Class_item_qualifierContext* class_item_qualifier(size_t i);
    Class_constructor_declarationContext *class_constructor_declaration();
    Class_constructor_prototypeContext *class_constructor_prototype();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_methodContext* class_method();

  class  Class_constructor_prototypeContext : public antlr4::ParserRuleContext {
  public:
    Class_constructor_prototypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Tf_port_listContext *tf_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_constructor_prototypeContext* class_constructor_prototype();

  class  Class_constraintContext : public antlr4::ParserRuleContext {
  public:
    Class_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constraint_prototypeContext *constraint_prototype();
    Constraint_declarationContext *constraint_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_constraintContext* class_constraint();

  class  Class_item_qualifierContext : public antlr4::ParserRuleContext {
  public:
    Class_item_qualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_item_qualifierContext* class_item_qualifier();

  class  Property_qualifierContext : public antlr4::ParserRuleContext {
  public:
    Property_qualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Random_qualifierContext *random_qualifier();
    Class_item_qualifierContext *class_item_qualifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_qualifierContext* property_qualifier();

  class  Random_qualifierContext : public antlr4::ParserRuleContext {
  public:
    Random_qualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Random_qualifierContext* random_qualifier();

  class  Method_qualifierContext : public antlr4::ParserRuleContext {
  public:
    Method_qualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_item_qualifierContext *class_item_qualifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_qualifierContext* method_qualifier();

  class  Method_prototypeContext : public antlr4::ParserRuleContext {
  public:
    Method_prototypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Task_prototypeContext *task_prototype();
    Function_prototypeContext *function_prototype();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_prototypeContext* method_prototype();

  class  Class_constructor_declarationContext : public antlr4::ParserRuleContext {
  public:
    Class_constructor_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_scopeContext *class_scope();
    Tf_port_listContext *tf_port_list();
    std::vector<Block_item_declarationContext *> block_item_declaration();
    Block_item_declarationContext* block_item_declaration(size_t i);
    std::vector<Function_statement_or_nullContext *> function_statement_or_null();
    Function_statement_or_nullContext* function_statement_or_null(size_t i);
    List_of_argumentsContext *list_of_arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_constructor_declarationContext* class_constructor_declaration();

  class  Constraint_declarationContext : public antlr4::ParserRuleContext {
  public:
    Constraint_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constraint_identifierContext *constraint_identifier();
    Constraint_blockContext *constraint_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_declarationContext* constraint_declaration();

  class  Constraint_blockContext : public antlr4::ParserRuleContext {
  public:
    Constraint_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constraint_block_itemContext *> constraint_block_item();
    Constraint_block_itemContext* constraint_block_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_blockContext* constraint_block();

  class  Constraint_block_itemContext : public antlr4::ParserRuleContext {
  public:
    Constraint_block_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Solve_before_listContext *> solve_before_list();
    Solve_before_listContext* solve_before_list(size_t i);
    Constraint_expressionContext *constraint_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_block_itemContext* constraint_block_item();

  class  Solve_before_listContext : public antlr4::ParserRuleContext {
  public:
    Solve_before_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constraint_primaryContext *> constraint_primary();
    Constraint_primaryContext* constraint_primary(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Solve_before_listContext* solve_before_list();

  class  Constraint_primaryContext : public antlr4::ParserRuleContext {
  public:
    Constraint_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();
    SelectContext *select();
    Implicit_class_handleContext *implicit_class_handle();
    Class_scopeContext *class_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_primaryContext* constraint_primary();

  class  Constraint_expressionContext : public antlr4::ParserRuleContext {
  public:
    Constraint_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expression_or_distContext *expression_or_dist();
    Uniqueness_constraintContext *uniqueness_constraint();
    ExpressionContext *expression();
    std::vector<Constraint_setContext *> constraint_set();
    Constraint_setContext* constraint_set(size_t i);
    Ps_or_hierarchical_array_identifierContext *ps_or_hierarchical_array_identifier();
    Loop_variablesContext *loop_variables();
    Constraint_primaryContext *constraint_primary();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_expressionContext* constraint_expression();

  class  Uniqueness_constraintContext : public antlr4::ParserRuleContext {
  public:
    Uniqueness_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Open_range_listContext *open_range_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Uniqueness_constraintContext* uniqueness_constraint();

  class  Constraint_setContext : public antlr4::ParserRuleContext {
  public:
    Constraint_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constraint_expressionContext *> constraint_expression();
    Constraint_expressionContext* constraint_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_setContext* constraint_set();

  class  Dist_listContext : public antlr4::ParserRuleContext {
  public:
    Dist_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Dist_itemContext *> dist_item();
    Dist_itemContext* dist_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dist_listContext* dist_list();

  class  Dist_itemContext : public antlr4::ParserRuleContext {
  public:
    Dist_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_rangeContext *value_range();
    Dist_weightContext *dist_weight();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dist_itemContext* dist_item();

  class  Dist_weightContext : public antlr4::ParserRuleContext {
  public:
    Dist_weightContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dist_weightContext* dist_weight();

  class  Constraint_prototypeContext : public antlr4::ParserRuleContext {
  public:
    Constraint_prototypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constraint_identifierContext *constraint_identifier();
    Constraint_prototype_qualifierContext *constraint_prototype_qualifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_prototypeContext* constraint_prototype();

  class  Constraint_prototype_qualifierContext : public antlr4::ParserRuleContext {
  public:
    Constraint_prototype_qualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_prototype_qualifierContext* constraint_prototype_qualifier();

  class  Extern_constraint_declarationContext : public antlr4::ParserRuleContext {
  public:
    Extern_constraint_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_scopeContext *class_scope();
    Constraint_identifierContext *constraint_identifier();
    Constraint_blockContext *constraint_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Extern_constraint_declarationContext* extern_constraint_declaration();

  class  Identifier_listContext : public antlr4::ParserRuleContext {
  public:
    Identifier_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Identifier_listContext* identifier_list();

  class  Package_itemContext : public antlr4::ParserRuleContext {
  public:
    Package_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Package_or_generate_item_declarationContext *package_or_generate_item_declaration();
    Anonymous_programContext *anonymous_program();
    Package_export_declarationContext *package_export_declaration();
    Timeunits_declarationContext *timeunits_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Package_itemContext* package_item();

  class  Package_or_generate_item_declarationContext : public antlr4::ParserRuleContext {
  public:
    Package_or_generate_item_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_declarationContext *net_declaration();
    Data_declarationContext *data_declaration();
    Task_declarationContext *task_declaration();
    Function_declarationContext *function_declaration();
    Checker_declarationContext *checker_declaration();
    Dpi_import_exportContext *dpi_import_export();
    Extern_constraint_declarationContext *extern_constraint_declaration();
    Class_declarationContext *class_declaration();
    Class_constructor_declarationContext *class_constructor_declaration();
    Local_parameter_declarationContext *local_parameter_declaration();
    Parameter_declarationContext *parameter_declaration();
    Covergroup_declarationContext *covergroup_declaration();
    Overload_declarationContext *overload_declaration();
    Assertion_item_declarationContext *assertion_item_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Package_or_generate_item_declarationContext* package_or_generate_item_declaration();

  class  Anonymous_programContext : public antlr4::ParserRuleContext {
  public:
    Anonymous_programContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Anonymous_program_itemContext *> anonymous_program_item();
    Anonymous_program_itemContext* anonymous_program_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Anonymous_programContext* anonymous_program();

  class  Anonymous_program_itemContext : public antlr4::ParserRuleContext {
  public:
    Anonymous_program_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Task_declarationContext *task_declaration();
    Function_declarationContext *function_declaration();
    Class_declarationContext *class_declaration();
    Covergroup_declarationContext *covergroup_declaration();
    Class_constructor_declarationContext *class_constructor_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Anonymous_program_itemContext* anonymous_program_item();

  class  Local_parameter_declarationContext : public antlr4::ParserRuleContext {
  public:
    Local_parameter_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_implicitContext *data_type_or_implicit();
    List_of_param_assignmentsContext *list_of_param_assignments();
    List_of_type_assignmentsContext *list_of_type_assignments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_parameter_declarationContext* local_parameter_declaration();

  class  Parameter_declarationContext : public antlr4::ParserRuleContext {
  public:
    Parameter_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_implicitContext *data_type_or_implicit();
    List_of_param_assignmentsContext *list_of_param_assignments();
    List_of_type_assignmentsContext *list_of_type_assignments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_declarationContext* parameter_declaration();

  class  Specparam_declarationContext : public antlr4::ParserRuleContext {
  public:
    Specparam_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_specparam_assignmentsContext *list_of_specparam_assignments();
    Packed_dimensionContext *packed_dimension();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Specparam_declarationContext* specparam_declaration();

  class  Inout_declarationContext : public antlr4::ParserRuleContext {
  public:
    Inout_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_port_typeContext *net_port_type();
    List_of_port_identifiersContext *list_of_port_identifiers();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inout_declarationContext* inout_declaration();

  class  Input_declarationContext : public antlr4::ParserRuleContext {
  public:
    Input_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_port_typeContext *net_port_type();
    List_of_port_identifiersContext *list_of_port_identifiers();
    Variable_port_typeContext *variable_port_type();
    List_of_variable_identifiersContext *list_of_variable_identifiers();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_declarationContext* input_declaration();

  class  Output_declarationContext : public antlr4::ParserRuleContext {
  public:
    Output_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_port_typeContext *net_port_type();
    List_of_port_identifiersContext *list_of_port_identifiers();
    Variable_port_typeContext *variable_port_type();
    List_of_variable_port_identifiersContext *list_of_variable_port_identifiers();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Output_declarationContext* output_declaration();

  class  Interface_port_declarationContext : public antlr4::ParserRuleContext {
  public:
    Interface_port_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Interface_identifierContext *interface_identifier();
    List_of_interface_identifiersContext *list_of_interface_identifiers();
    Modport_identifierContext *modport_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_port_declarationContext* interface_port_declaration();

  class  Ref_declarationContext : public antlr4::ParserRuleContext {
  public:
    Ref_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_port_typeContext *variable_port_type();
    List_of_variable_identifiersContext *list_of_variable_identifiers();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ref_declarationContext* ref_declaration();

  class  Data_declarationContext : public antlr4::ParserRuleContext {
  public:
    Data_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_implicitContext *data_type_or_implicit();
    List_of_variable_decl_assignmentsContext *list_of_variable_decl_assignments();
    LifetimeContext *lifetime();
    Type_declarationContext *type_declaration();
    Package_import_declarationContext *package_import_declaration();
    Net_type_declarationContext *net_type_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_declarationContext* data_declaration();

  class  Package_import_declarationContext : public antlr4::ParserRuleContext {
  public:
    Package_import_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Package_import_itemContext *> package_import_item();
    Package_import_itemContext* package_import_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Package_import_declarationContext* package_import_declaration();

  class  Package_import_itemContext : public antlr4::ParserRuleContext {
  public:
    Package_import_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Package_identifierContext *package_identifier();
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Package_import_itemContext* package_import_item();

  class  Package_export_declarationContext : public antlr4::ParserRuleContext {
  public:
    Package_export_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Package_import_itemContext *> package_import_item();
    Package_import_itemContext* package_import_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Package_export_declarationContext* package_export_declaration();

  class  Genvar_declarationContext : public antlr4::ParserRuleContext {
  public:
    Genvar_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_genvar_identifiersContext *list_of_genvar_identifiers();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Genvar_declarationContext* genvar_declaration();

  class  Net_declarationContext : public antlr4::ParserRuleContext {
  public:
    Net_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_typeContext *net_type();
    Data_type_or_implicitContext *data_type_or_implicit();
    List_of_net_decl_assignmentsContext *list_of_net_decl_assignments();
    Drive_strengthContext *drive_strength();
    Charge_strengthContext *charge_strength();
    Delay3Context *delay3();
    Net_type_identifierContext *net_type_identifier();
    Delay_controlContext *delay_control();
    Implicit_data_typeContext *implicit_data_type();
    std::vector<Net_identifierContext *> net_identifier();
    Net_identifierContext* net_identifier(size_t i);
    Delay_valueContext *delay_value();
    std::vector<Unpacked_dimensionContext *> unpacked_dimension();
    Unpacked_dimensionContext* unpacked_dimension(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_declarationContext* net_declaration();

  class  Type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_typeContext *data_type();
    std::vector<Type_identifierContext *> type_identifier();
    Type_identifierContext* type_identifier(size_t i);
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    Interface_instance_identifierContext *interface_instance_identifier();
    Constant_bit_selectContext *constant_bit_select();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_declarationContext* type_declaration();

  class  Net_type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Net_type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_typeContext *data_type();
    std::vector<Net_type_identifierContext *> net_type_identifier();
    Net_type_identifierContext* net_type_identifier(size_t i);
    Tf_identifierContext *tf_identifier();
    Package_scopeContext *package_scope();
    Class_scopeContext *class_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_type_declarationContext* net_type_declaration();

  class  LifetimeContext : public antlr4::ParserRuleContext {
  public:
    LifetimeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LifetimeContext* lifetime();

  class  Casting_type_reducedContext : public antlr4::ParserRuleContext {
  public:
    Casting_type_reducedContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_typeContext *simple_type();
    SigningContext *signing();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Casting_type_reducedContext* casting_type_reduced();

  class  Casting_typeContext : public antlr4::ParserRuleContext {
  public:
    Casting_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_typeContext *simple_type();
    Constant_primaryContext *constant_primary();
    SigningContext *signing();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Casting_typeContext* casting_type();

  class  Data_typeContext : public antlr4::ParserRuleContext {
  public:
    Data_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_vector_typeContext *integer_vector_type();
    SigningContext *signing();
    std::vector<Packed_dimensionContext *> packed_dimension();
    Packed_dimensionContext* packed_dimension(size_t i);
    Integer_atom_typeContext *integer_atom_type();
    Non_integer_typeContext *non_integer_type();
    Struct_unionContext *struct_union();
    std::vector<Struct_union_memberContext *> struct_union_member();
    Struct_union_memberContext* struct_union_member(size_t i);
    std::vector<Enum_name_declarationContext *> enum_name_declaration();
    Enum_name_declarationContext* enum_name_declaration(size_t i);
    Enum_base_typeContext *enum_base_type();
    Interface_identifierContext *interface_identifier();
    Parameter_value_assignmentContext *parameter_value_assignment();
    Modport_identifierContext *modport_identifier();
    Type_identifierContext *type_identifier();
    Class_scopeContext *class_scope();
    Package_scopeContext *package_scope();
    Class_typeContext *class_type();
    Ps_covergroup_identifierContext *ps_covergroup_identifier();
    Type_referenceContext *type_reference();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_typeContext* data_type();

  class  Data_type_or_implicitContext : public antlr4::ParserRuleContext {
  public:
    Data_type_or_implicitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_typeContext *data_type();
    Implicit_data_typeContext *implicit_data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_type_or_implicitContext* data_type_or_implicit();

  class  Implicit_data_typeContext : public antlr4::ParserRuleContext {
  public:
    Implicit_data_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SigningContext *signing();
    std::vector<Packed_dimensionContext *> packed_dimension();
    Packed_dimensionContext* packed_dimension(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Implicit_data_typeContext* implicit_data_type();

  class  Enum_base_typeContext : public antlr4::ParserRuleContext {
  public:
    Enum_base_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_atom_typeContext *integer_atom_type();
    SigningContext *signing();
    Integer_vector_typeContext *integer_vector_type();
    Packed_dimensionContext *packed_dimension();
    Type_identifierContext *type_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_base_typeContext* enum_base_type();

  class  Enum_name_declarationContext : public antlr4::ParserRuleContext {
  public:
    Enum_name_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Enum_identifierContext *enum_identifier();
    std::vector<antlr4::tree::TerminalNode *> Integral_number();
    antlr4::tree::TerminalNode* Integral_number(size_t i);
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_name_declarationContext* enum_name_declaration();

  class  Class_scopeContext : public antlr4::ParserRuleContext {
  public:
    Class_scopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_typeContext *class_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_scopeContext* class_scope();

  class  Class_typeContext : public antlr4::ParserRuleContext {
  public:
    Class_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_class_identifierContext *ps_class_identifier();
    std::vector<Parameter_value_assignmentContext *> parameter_value_assignment();
    Parameter_value_assignmentContext* parameter_value_assignment(size_t i);
    std::vector<Class_identifierContext *> class_identifier();
    Class_identifierContext* class_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_typeContext* class_type();

  class  Integer_typeContext : public antlr4::ParserRuleContext {
  public:
    Integer_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_vector_typeContext *integer_vector_type();
    Integer_atom_typeContext *integer_atom_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_typeContext* integer_type();

  class  Integer_atom_typeContext : public antlr4::ParserRuleContext {
  public:
    Integer_atom_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_atom_typeContext* integer_atom_type();

  class  Integer_vector_typeContext : public antlr4::ParserRuleContext {
  public:
    Integer_vector_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_vector_typeContext* integer_vector_type();

  class  Non_integer_typeContext : public antlr4::ParserRuleContext {
  public:
    Non_integer_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Non_integer_typeContext* non_integer_type();

  class  Net_typeContext : public antlr4::ParserRuleContext {
  public:
    Net_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_typeContext* net_type();

  class  Net_port_typeContext : public antlr4::ParserRuleContext {
  public:
    Net_port_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_implicitContext *data_type_or_implicit();
    Net_typeContext *net_type();
    Net_type_identifierContext *net_type_identifier();
    Implicit_data_typeContext *implicit_data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_port_typeContext* net_port_type();

  class  Variable_port_typeContext : public antlr4::ParserRuleContext {
  public:
    Variable_port_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_data_typeContext *var_data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_port_typeContext* variable_port_type();

  class  Var_data_typeContext : public antlr4::ParserRuleContext {
  public:
    Var_data_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_typeContext *data_type();
    Data_type_or_implicitContext *data_type_or_implicit();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_data_typeContext* var_data_type();

  class  SigningContext : public antlr4::ParserRuleContext {
  public:
    SigningContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SigningContext* signing();

  class  Simple_typeContext : public antlr4::ParserRuleContext {
  public:
    Simple_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Integer_typeContext *integer_type();
    Non_integer_typeContext *non_integer_type();
    Ps_type_identifierContext *ps_type_identifier();
    Ps_parameter_identifierContext *ps_parameter_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_typeContext* simple_type();

  class  Struct_union_memberContext : public antlr4::ParserRuleContext {
  public:
    Struct_union_memberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_voidContext *data_type_or_void();
    List_of_variable_decl_assignmentsContext *list_of_variable_decl_assignments();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Random_qualifierContext *random_qualifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Struct_union_memberContext* struct_union_member();

  class  Data_type_or_voidContext : public antlr4::ParserRuleContext {
  public:
    Data_type_or_voidContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_typeContext *data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_type_or_voidContext* data_type_or_void();

  class  Struct_unionContext : public antlr4::ParserRuleContext {
  public:
    Struct_unionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Struct_unionContext* struct_union();

  class  Type_referenceContext : public antlr4::ParserRuleContext {
  public:
    Type_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Data_typeContext *data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_referenceContext* type_reference();

  class  Drive_strengthContext : public antlr4::ParserRuleContext {
  public:
    Drive_strengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Strength0Context *strength0();
    Strength1Context *strength1();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Drive_strengthContext* drive_strength();

  class  Strength0Context : public antlr4::ParserRuleContext {
  public:
    Strength0Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Strength0Context* strength0();

  class  Strength1Context : public antlr4::ParserRuleContext {
  public:
    Strength1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Strength1Context* strength1();

  class  Charge_strengthContext : public antlr4::ParserRuleContext {
  public:
    Charge_strengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Charge_strengthContext* charge_strength();

  class  Delay3Context : public antlr4::ParserRuleContext {
  public:
    Delay3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Delay_valueContext *delay_value();
    std::vector<Mintypmax_expressionContext *> mintypmax_expression();
    Mintypmax_expressionContext* mintypmax_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delay3Context* delay3();

  class  Delay2Context : public antlr4::ParserRuleContext {
  public:
    Delay2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Delay_valueContext *delay_value();
    std::vector<Mintypmax_expressionContext *> mintypmax_expression();
    Mintypmax_expressionContext* mintypmax_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delay2Context* delay2();

  class  Delay_valueContext : public antlr4::ParserRuleContext {
  public:
    Delay_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Unsigned_number();
    antlr4::tree::TerminalNode *Real_number();
    Ps_identifierContext *ps_identifier();
    Time_literalContext *time_literal();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delay_valueContext* delay_value();

  class  List_of_defparam_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_defparam_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Defparam_assignmentContext *> defparam_assignment();
    Defparam_assignmentContext* defparam_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_defparam_assignmentsContext* list_of_defparam_assignments();

  class  List_of_genvar_identifiersContext : public antlr4::ParserRuleContext {
  public:
    List_of_genvar_identifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Genvar_identifierContext *> genvar_identifier();
    Genvar_identifierContext* genvar_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_genvar_identifiersContext* list_of_genvar_identifiers();

  class  List_of_interface_identifiersContext : public antlr4::ParserRuleContext {
  public:
    List_of_interface_identifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Interface_identifierContext *> interface_identifier();
    Interface_identifierContext* interface_identifier(size_t i);
    std::vector<Unpacked_dimensionContext *> unpacked_dimension();
    Unpacked_dimensionContext* unpacked_dimension(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_interface_identifiersContext* list_of_interface_identifiers();

  class  List_of_net_decl_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_net_decl_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Net_decl_assignmentContext *> net_decl_assignment();
    Net_decl_assignmentContext* net_decl_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_net_decl_assignmentsContext* list_of_net_decl_assignments();

  class  List_of_param_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_param_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Param_assignmentContext *> param_assignment();
    Param_assignmentContext* param_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_param_assignmentsContext* list_of_param_assignments();

  class  List_of_port_identifiersContext : public antlr4::ParserRuleContext {
  public:
    List_of_port_identifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Port_identifierContext *> port_identifier();
    Port_identifierContext* port_identifier(size_t i);
    std::vector<Unpacked_dimensionContext *> unpacked_dimension();
    Unpacked_dimensionContext* unpacked_dimension(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_port_identifiersContext* list_of_port_identifiers();

  class  List_of_udp_port_identifiersContext : public antlr4::ParserRuleContext {
  public:
    List_of_udp_port_identifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Port_identifierContext *> port_identifier();
    Port_identifierContext* port_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_udp_port_identifiersContext* list_of_udp_port_identifiers();

  class  List_of_specparam_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_specparam_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Specparam_assignmentContext *> specparam_assignment();
    Specparam_assignmentContext* specparam_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_specparam_assignmentsContext* list_of_specparam_assignments();

  class  List_of_tf_variable_identifiersContext : public antlr4::ParserRuleContext {
  public:
    List_of_tf_variable_identifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Port_identifierContext *> port_identifier();
    Port_identifierContext* port_identifier(size_t i);
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_tf_variable_identifiersContext* list_of_tf_variable_identifiers();

  class  List_of_type_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_type_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_assignmentContext *> type_assignment();
    Type_assignmentContext* type_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_type_assignmentsContext* list_of_type_assignments();

  class  List_of_variable_decl_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_variable_decl_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_decl_assignmentContext *> variable_decl_assignment();
    Variable_decl_assignmentContext* variable_decl_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_variable_decl_assignmentsContext* list_of_variable_decl_assignments();

  class  List_of_variable_identifiersContext : public antlr4::ParserRuleContext {
  public:
    List_of_variable_identifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_identifierContext *> variable_identifier();
    Variable_identifierContext* variable_identifier(size_t i);
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_variable_identifiersContext* list_of_variable_identifiers();

  class  List_of_variable_port_identifiersContext : public antlr4::ParserRuleContext {
  public:
    List_of_variable_port_identifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Port_identifierContext *> port_identifier();
    Port_identifierContext* port_identifier(size_t i);
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_variable_port_identifiersContext* list_of_variable_port_identifiers();

  class  Defparam_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Defparam_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_parameter_identifierContext *hierarchical_parameter_identifier();
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Defparam_assignmentContext* defparam_assignment();

  class  Net_decl_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Net_decl_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_identifierContext *net_identifier();
    std::vector<Unpacked_dimensionContext *> unpacked_dimension();
    Unpacked_dimensionContext* unpacked_dimension(size_t i);
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_decl_assignmentContext* net_decl_assignment();

  class  Param_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Param_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parameter_identifierContext *parameter_identifier();
    std::vector<Unpacked_dimensionContext *> unpacked_dimension();
    Unpacked_dimensionContext* unpacked_dimension(size_t i);
    Constant_param_expressionContext *constant_param_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Param_assignmentContext* param_assignment();

  class  Specparam_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Specparam_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Specparam_identifierContext *specparam_identifier();
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();
    Pulse_control_specparamContext *pulse_control_specparam();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Specparam_assignmentContext* specparam_assignment();

  class  Type_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Type_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_identifierContext *type_identifier();
    Data_typeContext *data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_assignmentContext* type_assignment();

  class  Pulse_control_specparamContext : public antlr4::ParserRuleContext {
  public:
    Pulse_control_specparamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reject_limit_valueContext *reject_limit_value();
    Error_limit_valueContext *error_limit_value();
    Specify_input_terminal_descriptorContext *specify_input_terminal_descriptor();
    Specify_output_terminal_descriptorContext *specify_output_terminal_descriptor();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pulse_control_specparamContext* pulse_control_specparam();

  class  Error_limit_valueContext : public antlr4::ParserRuleContext {
  public:
    Error_limit_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Limit_valueContext *limit_value();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Error_limit_valueContext* error_limit_value();

  class  Reject_limit_valueContext : public antlr4::ParserRuleContext {
  public:
    Reject_limit_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Limit_valueContext *limit_value();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Reject_limit_valueContext* reject_limit_value();

  class  Limit_valueContext : public antlr4::ParserRuleContext {
  public:
    Limit_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Limit_valueContext* limit_value();

  class  Variable_decl_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Variable_decl_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_identifierContext *variable_identifier();
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    ExpressionContext *expression();
    Dynamic_array_variable_identifierContext *dynamic_array_variable_identifier();
    Unsized_dimensionContext *unsized_dimension();
    Dynamic_array_newContext *dynamic_array_new();
    Class_variable_identifierContext *class_variable_identifier();
    Class_newContext *class_new();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_decl_assignmentContext* variable_decl_assignment();

  class  Class_newContext : public antlr4::ParserRuleContext {
  public:
    Class_newContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_scopeContext *class_scope();
    List_of_argumentsContext *list_of_arguments();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_newContext* class_new();

  class  Dynamic_array_newContext : public antlr4::ParserRuleContext {
  public:
    Dynamic_array_newContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dynamic_array_newContext* dynamic_array_new();

  class  Unpacked_dimensionContext : public antlr4::ParserRuleContext {
  public:
    Unpacked_dimensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_rangeContext *constant_range();
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unpacked_dimensionContext* unpacked_dimension();

  class  Packed_dimensionContext : public antlr4::ParserRuleContext {
  public:
    Packed_dimensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_rangeContext *constant_range();
    Unsized_dimensionContext *unsized_dimension();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Packed_dimensionContext* packed_dimension();

  class  Associative_dimensionContext : public antlr4::ParserRuleContext {
  public:
    Associative_dimensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_typeContext *data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Associative_dimensionContext* associative_dimension();

  class  Variable_dimensionContext : public antlr4::ParserRuleContext {
  public:
    Variable_dimensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unsized_dimensionContext *unsized_dimension();
    Unpacked_dimensionContext *unpacked_dimension();
    Associative_dimensionContext *associative_dimension();
    Queue_dimensionContext *queue_dimension();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_dimensionContext* variable_dimension();

  class  Queue_dimensionContext : public antlr4::ParserRuleContext {
  public:
    Queue_dimensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Queue_dimensionContext* queue_dimension();

  class  Unsized_dimensionContext : public antlr4::ParserRuleContext {
  public:
    Unsized_dimensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unsized_dimensionContext* unsized_dimension();

  class  Function_data_type_or_implicitContext : public antlr4::ParserRuleContext {
  public:
    Function_data_type_or_implicitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_voidContext *data_type_or_void();
    Implicit_data_typeContext *implicit_data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_data_type_or_implicitContext* function_data_type_or_implicit();

  class  Function_declarationContext : public antlr4::ParserRuleContext {
  public:
    Function_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_body_declarationContext *function_body_declaration();
    LifetimeContext *lifetime();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_declarationContext* function_declaration();

  class  Function_body_declarationContext : public antlr4::ParserRuleContext {
  public:
    Function_body_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_data_type_or_implicitContext *function_data_type_or_implicit();
    std::vector<Function_identifierContext *> function_identifier();
    Function_identifierContext* function_identifier(size_t i);
    Interface_identifierContext *interface_identifier();
    Class_scopeContext *class_scope();
    std::vector<Tf_item_declarationContext *> tf_item_declaration();
    Tf_item_declarationContext* tf_item_declaration(size_t i);
    std::vector<Function_statement_or_nullContext *> function_statement_or_null();
    Function_statement_or_nullContext* function_statement_or_null(size_t i);
    Tf_port_listContext *tf_port_list();
    std::vector<Block_item_declarationContext *> block_item_declaration();
    Block_item_declarationContext* block_item_declaration(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_body_declarationContext* function_body_declaration();

  class  Function_prototypeContext : public antlr4::ParserRuleContext {
  public:
    Function_prototypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_voidContext *data_type_or_void();
    Function_identifierContext *function_identifier();
    Tf_port_listContext *tf_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_prototypeContext* function_prototype();

  class  Dpi_import_exportContext : public antlr4::ParserRuleContext {
  public:
    Dpi_import_exportContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Dpi_spec_stringContext *dpi_spec_string();
    Dpi_function_protoContext *dpi_function_proto();
    Dpi_function_import_propertyContext *dpi_function_import_property();
    C_identifierContext *c_identifier();
    Dpi_task_protoContext *dpi_task_proto();
    Dpi_task_import_propertyContext *dpi_task_import_property();
    Function_identifierContext *function_identifier();
    Task_identifierContext *task_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dpi_import_exportContext* dpi_import_export();

  class  Dpi_spec_stringContext : public antlr4::ParserRuleContext {
  public:
    Dpi_spec_stringContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dpi_spec_stringContext* dpi_spec_string();

  class  Dpi_function_import_propertyContext : public antlr4::ParserRuleContext {
  public:
    Dpi_function_import_propertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dpi_function_import_propertyContext* dpi_function_import_property();

  class  Dpi_task_import_propertyContext : public antlr4::ParserRuleContext {
  public:
    Dpi_task_import_propertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dpi_task_import_propertyContext* dpi_task_import_property();

  class  Dpi_function_protoContext : public antlr4::ParserRuleContext {
  public:
    Dpi_function_protoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_prototypeContext *function_prototype();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dpi_function_protoContext* dpi_function_proto();

  class  Dpi_task_protoContext : public antlr4::ParserRuleContext {
  public:
    Dpi_task_protoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Task_prototypeContext *task_prototype();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dpi_task_protoContext* dpi_task_proto();

  class  Task_declarationContext : public antlr4::ParserRuleContext {
  public:
    Task_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Task_body_declarationContext *task_body_declaration();
    LifetimeContext *lifetime();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Task_declarationContext* task_declaration();

  class  Task_body_declarationContext : public antlr4::ParserRuleContext {
  public:
    Task_body_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Task_identifierContext *> task_identifier();
    Task_identifierContext* task_identifier(size_t i);
    Interface_identifierContext *interface_identifier();
    Class_scopeContext *class_scope();
    std::vector<Tf_item_declarationContext *> tf_item_declaration();
    Tf_item_declarationContext* tf_item_declaration(size_t i);
    std::vector<Statement_or_nullContext *> statement_or_null();
    Statement_or_nullContext* statement_or_null(size_t i);
    Tf_port_listContext *tf_port_list();
    std::vector<Block_item_declarationContext *> block_item_declaration();
    Block_item_declarationContext* block_item_declaration(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Task_body_declarationContext* task_body_declaration();

  class  Tf_item_declarationContext : public antlr4::ParserRuleContext {
  public:
    Tf_item_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Block_item_declarationContext *block_item_declaration();
    Tf_port_declarationContext *tf_port_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tf_item_declarationContext* tf_item_declaration();

  class  Tf_port_listContext : public antlr4::ParserRuleContext {
  public:
    Tf_port_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Tf_port_itemContext *> tf_port_item();
    Tf_port_itemContext* tf_port_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tf_port_listContext* tf_port_list();

  class  Tf_port_itemContext : public antlr4::ParserRuleContext {
  public:
    Tf_port_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_implicitContext *data_type_or_implicit();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Tf_port_directionContext *tf_port_direction();
    Port_identifierContext *port_identifier();
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tf_port_itemContext* tf_port_item();

  class  Tf_port_directionContext : public antlr4::ParserRuleContext {
  public:
    Tf_port_directionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_directionContext *port_direction();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tf_port_directionContext* tf_port_direction();

  class  Tf_port_declarationContext : public antlr4::ParserRuleContext {
  public:
    Tf_port_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Tf_port_directionContext *tf_port_direction();
    Data_type_or_implicitContext *data_type_or_implicit();
    List_of_tf_variable_identifiersContext *list_of_tf_variable_identifiers();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tf_port_declarationContext* tf_port_declaration();

  class  Task_prototypeContext : public antlr4::ParserRuleContext {
  public:
    Task_prototypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Task_identifierContext *task_identifier();
    Tf_port_listContext *tf_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Task_prototypeContext* task_prototype();

  class  Block_item_declarationContext : public antlr4::ParserRuleContext {
  public:
    Block_item_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_declarationContext *data_declaration();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Local_parameter_declarationContext *local_parameter_declaration();
    Parameter_declarationContext *parameter_declaration();
    Overload_declarationContext *overload_declaration();
    Let_declarationContext *let_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_item_declarationContext* block_item_declaration();

  class  Overload_declarationContext : public antlr4::ParserRuleContext {
  public:
    Overload_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Overload_operatorContext *overload_operator();
    Data_typeContext *data_type();
    Function_identifierContext *function_identifier();
    Overload_proto_formalsContext *overload_proto_formals();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Overload_declarationContext* overload_declaration();

  class  Overload_operatorContext : public antlr4::ParserRuleContext {
  public:
    Overload_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Overload_operatorContext* overload_operator();

  class  Overload_proto_formalsContext : public antlr4::ParserRuleContext {
  public:
    Overload_proto_formalsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Data_typeContext *> data_type();
    Data_typeContext* data_type(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Overload_proto_formalsContext* overload_proto_formals();

  class  Modport_declarationContext : public antlr4::ParserRuleContext {
  public:
    Modport_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Modport_itemContext *> modport_item();
    Modport_itemContext* modport_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_declarationContext* modport_declaration();

  class  Modport_itemContext : public antlr4::ParserRuleContext {
  public:
    Modport_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Modport_identifierContext *modport_identifier();
    std::vector<Modport_ports_declarationContext *> modport_ports_declaration();
    Modport_ports_declarationContext* modport_ports_declaration(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_itemContext* modport_item();

  class  Modport_ports_declarationContext : public antlr4::ParserRuleContext {
  public:
    Modport_ports_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Modport_simple_ports_declarationContext *modport_simple_ports_declaration();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Modport_tf_ports_declarationContext *modport_tf_ports_declaration();
    Modport_clocking_declarationContext *modport_clocking_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_ports_declarationContext* modport_ports_declaration();

  class  Modport_clocking_declarationContext : public antlr4::ParserRuleContext {
  public:
    Modport_clocking_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Clocking_identifierContext *clocking_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_clocking_declarationContext* modport_clocking_declaration();

  class  Modport_simple_ports_declarationContext : public antlr4::ParserRuleContext {
  public:
    Modport_simple_ports_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_directionContext *port_direction();
    std::vector<Modport_simple_portContext *> modport_simple_port();
    Modport_simple_portContext* modport_simple_port(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_simple_ports_declarationContext* modport_simple_ports_declaration();

  class  Modport_simple_portContext : public antlr4::ParserRuleContext {
  public:
    Modport_simple_portContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_identifierContext *port_identifier();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_simple_portContext* modport_simple_port();

  class  Modport_tf_ports_declarationContext : public antlr4::ParserRuleContext {
  public:
    Modport_tf_ports_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Import_exportContext *import_export();
    std::vector<Modport_tf_portContext *> modport_tf_port();
    Modport_tf_portContext* modport_tf_port(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_tf_ports_declarationContext* modport_tf_ports_declaration();

  class  Modport_tf_portContext : public antlr4::ParserRuleContext {
  public:
    Modport_tf_portContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Method_prototypeContext *method_prototype();
    Tf_identifierContext *tf_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_tf_portContext* modport_tf_port();

  class  Import_exportContext : public antlr4::ParserRuleContext {
  public:
    Import_exportContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_exportContext* import_export();

  class  Concurrent_assertion_itemContext : public antlr4::ParserRuleContext {
  public:
    Concurrent_assertion_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concurrent_assertion_statementContext *concurrent_assertion_statement();
    Block_identifierContext *block_identifier();
    Checker_instantiationContext *checker_instantiation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concurrent_assertion_itemContext* concurrent_assertion_item();

  class  Concurrent_assertion_statementContext : public antlr4::ParserRuleContext {
  public:
    Concurrent_assertion_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assert_property_statementContext *assert_property_statement();
    Assume_property_statementContext *assume_property_statement();
    Cover_property_statementContext *cover_property_statement();
    Cover_sequence_statementContext *cover_sequence_statement();
    Restrict_property_statementContext *restrict_property_statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Concurrent_assertion_statementContext* concurrent_assertion_statement();

  class  Assert_property_statementContext : public antlr4::ParserRuleContext {
  public:
    Assert_property_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_specContext *property_spec();
    Action_blockContext *action_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assert_property_statementContext* assert_property_statement();

  class  Assume_property_statementContext : public antlr4::ParserRuleContext {
  public:
    Assume_property_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_specContext *property_spec();
    Action_blockContext *action_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assume_property_statementContext* assume_property_statement();

  class  Cover_property_statementContext : public antlr4::ParserRuleContext {
  public:
    Cover_property_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_specContext *property_spec();
    Statement_or_nullContext *statement_or_null();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cover_property_statementContext* cover_property_statement();

  class  Expect_property_statementContext : public antlr4::ParserRuleContext {
  public:
    Expect_property_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_specContext *property_spec();
    Action_blockContext *action_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expect_property_statementContext* expect_property_statement();

  class  Cover_sequence_statementContext : public antlr4::ParserRuleContext {
  public:
    Cover_sequence_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_exprContext *sequence_expr();
    Statement_or_nullContext *statement_or_null();
    Clocking_eventContext *clocking_event();
    Expression_or_distContext *expression_or_dist();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cover_sequence_statementContext* cover_sequence_statement();

  class  Restrict_property_statementContext : public antlr4::ParserRuleContext {
  public:
    Restrict_property_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_specContext *property_spec();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Restrict_property_statementContext* restrict_property_statement();

  class  Property_instanceContext : public antlr4::ParserRuleContext {
  public:
    Property_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_or_hierarchical_property_identifierContext *ps_or_hierarchical_property_identifier();
    Property_list_of_argumentsContext *property_list_of_arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_instanceContext* property_instance();

  class  Property_list_of_argumentsContext : public antlr4::ParserRuleContext {
  public:
    Property_list_of_argumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Property_actual_argContext *> property_actual_arg();
    Property_actual_argContext* property_actual_arg(size_t i);
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_list_of_argumentsContext* property_list_of_arguments();

  class  Property_actual_argContext : public antlr4::ParserRuleContext {
  public:
    Property_actual_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_exprContext *property_expr();
    Sequence_actual_argContext *sequence_actual_arg();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_actual_argContext* property_actual_arg();

  class  Assertion_item_declarationContext : public antlr4::ParserRuleContext {
  public:
    Assertion_item_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_declarationContext *property_declaration();
    Sequence_declarationContext *sequence_declaration();
    Let_declarationContext *let_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assertion_item_declarationContext* assertion_item_declaration();

  class  Property_declarationContext : public antlr4::ParserRuleContext {
  public:
    Property_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Property_identifierContext *> property_identifier();
    Property_identifierContext* property_identifier(size_t i);
    Property_specContext *property_spec();
    std::vector<Assertion_variable_declarationContext *> assertion_variable_declaration();
    Assertion_variable_declarationContext* assertion_variable_declaration(size_t i);
    Property_port_listContext *property_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_declarationContext* property_declaration();

  class  Property_port_listContext : public antlr4::ParserRuleContext {
  public:
    Property_port_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Property_port_itemContext *> property_port_item();
    Property_port_itemContext* property_port_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_port_listContext* property_port_list();

  class  Property_port_itemContext : public antlr4::ParserRuleContext {
  public:
    Property_port_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_formal_typeContext *property_formal_type();
    Formal_port_identifierContext *formal_port_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    Property_actual_argContext *property_actual_arg();
    Property_lvar_port_directionContext *property_lvar_port_direction();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_port_itemContext* property_port_item();

  class  Property_lvar_port_directionContext : public antlr4::ParserRuleContext {
  public:
    Property_lvar_port_directionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_lvar_port_directionContext* property_lvar_port_direction();

  class  Property_formal_typeContext : public antlr4::ParserRuleContext {
  public:
    Property_formal_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_formal_typeContext *sequence_formal_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_formal_typeContext* property_formal_type();

  class  Property_specContext : public antlr4::ParserRuleContext {
  public:
    Property_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_exprContext *property_expr();
    Clocking_eventContext *clocking_event();
    Expression_or_distContext *expression_or_dist();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_specContext* property_spec();

  class  Property_exprContext : public antlr4::ParserRuleContext {
  public:
    Property_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_exprContext *sequence_expr();
    std::vector<Property_exprContext *> property_expr();
    Property_exprContext* property_expr(size_t i);
    Expression_or_distContext *expression_or_dist();
    std::vector<Property_case_itemContext *> property_case_item();
    Property_case_itemContext* property_case_item(size_t i);
    Constant_expressionContext *constant_expression();
    Cycle_delay_const_range_expressionContext *cycle_delay_const_range_expression();
    Constant_rangeContext *constant_range();
    Property_instanceContext *property_instance();
    Clocking_eventContext *clocking_event();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_exprContext* property_expr();
  Property_exprContext* property_expr(int precedence);
  class  Property_case_itemContext : public antlr4::ParserRuleContext {
  public:
    Property_case_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expression_or_distContext *> expression_or_dist();
    Expression_or_distContext* expression_or_dist(size_t i);
    Property_exprContext *property_expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_case_itemContext* property_case_item();

  class  Sequence_declarationContext : public antlr4::ParserRuleContext {
  public:
    Sequence_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Sequence_identifierContext *> sequence_identifier();
    Sequence_identifierContext* sequence_identifier(size_t i);
    Sequence_exprContext *sequence_expr();
    std::vector<Assertion_variable_declarationContext *> assertion_variable_declaration();
    Assertion_variable_declarationContext* assertion_variable_declaration(size_t i);
    Sequence_port_listContext *sequence_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_declarationContext* sequence_declaration();

  class  Sequence_port_listContext : public antlr4::ParserRuleContext {
  public:
    Sequence_port_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Sequence_port_itemContext *> sequence_port_item();
    Sequence_port_itemContext* sequence_port_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_port_listContext* sequence_port_list();

  class  Sequence_port_itemContext : public antlr4::ParserRuleContext {
  public:
    Sequence_port_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_formal_typeContext *sequence_formal_type();
    Formal_port_identifierContext *formal_port_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    Sequence_actual_argContext *sequence_actual_arg();
    Sequence_lvar_port_directionContext *sequence_lvar_port_direction();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_port_itemContext* sequence_port_item();

  class  Sequence_lvar_port_directionContext : public antlr4::ParserRuleContext {
  public:
    Sequence_lvar_port_directionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_lvar_port_directionContext* sequence_lvar_port_direction();

  class  Sequence_formal_typeContext : public antlr4::ParserRuleContext {
  public:
    Sequence_formal_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_implicitContext *data_type_or_implicit();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_formal_typeContext* sequence_formal_type();

  class  Sequence_exprContext : public antlr4::ParserRuleContext {
  public:
    Sequence_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Cycle_delay_rangeContext *> cycle_delay_range();
    Cycle_delay_rangeContext* cycle_delay_range(size_t i);
    std::vector<Sequence_exprContext *> sequence_expr();
    Sequence_exprContext* sequence_expr(size_t i);
    Expression_or_distContext *expression_or_dist();
    Boolean_abbrevContext *boolean_abbrev();
    Sequence_instanceContext *sequence_instance();
    Sequence_abbrevContext *sequence_abbrev();
    std::vector<Sequence_match_itemContext *> sequence_match_item();
    Sequence_match_itemContext* sequence_match_item(size_t i);
    Clocking_eventContext *clocking_event();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_exprContext* sequence_expr();
  Sequence_exprContext* sequence_expr(int precedence);
  class  Cycle_delay_rangeContext : public antlr4::ParserRuleContext {
  public:
    Cycle_delay_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_primaryContext *constant_primary();
    Cycle_delay_const_range_expressionContext *cycle_delay_const_range_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cycle_delay_rangeContext* cycle_delay_range();

  class  Sequence_method_callContext : public antlr4::ParserRuleContext {
  public:
    Sequence_method_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_instanceContext *sequence_instance();
    Method_identifierContext *method_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_method_callContext* sequence_method_call();

  class  Sequence_match_itemContext : public antlr4::ParserRuleContext {
  public:
    Sequence_match_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Operator_assignmentContext *operator_assignment();
    Inc_or_dec_expressionContext *inc_or_dec_expression();
    Subroutine_callContext *subroutine_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_match_itemContext* sequence_match_item();

  class  Sequence_instanceContext : public antlr4::ParserRuleContext {
  public:
    Sequence_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_or_hierarchical_sequence_identifierContext *ps_or_hierarchical_sequence_identifier();
    Sequence_list_of_argumentsContext *sequence_list_of_arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_instanceContext* sequence_instance();

  class  Sequence_list_of_argumentsContext : public antlr4::ParserRuleContext {
  public:
    Sequence_list_of_argumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Sequence_actual_argContext *> sequence_actual_arg();
    Sequence_actual_argContext* sequence_actual_arg(size_t i);
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_list_of_argumentsContext* sequence_list_of_arguments();

  class  Sequence_actual_argContext : public antlr4::ParserRuleContext {
  public:
    Sequence_actual_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Event_expressionContext *event_expression();
    Sequence_exprContext *sequence_expr();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_actual_argContext* sequence_actual_arg();

  class  Boolean_abbrevContext : public antlr4::ParserRuleContext {
  public:
    Boolean_abbrevContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Consecutive_repetitionContext *consecutive_repetition();
    Non_consecutive_repetitionContext *non_consecutive_repetition();
    Goto_repetitionContext *goto_repetition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Boolean_abbrevContext* boolean_abbrev();

  class  Sequence_abbrevContext : public antlr4::ParserRuleContext {
  public:
    Sequence_abbrevContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Consecutive_repetitionContext *consecutive_repetition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_abbrevContext* sequence_abbrev();

  class  Consecutive_repetitionContext : public antlr4::ParserRuleContext {
  public:
    Consecutive_repetitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_or_range_expressionContext *const_or_range_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Consecutive_repetitionContext* consecutive_repetition();

  class  Non_consecutive_repetitionContext : public antlr4::ParserRuleContext {
  public:
    Non_consecutive_repetitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_or_range_expressionContext *const_or_range_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Non_consecutive_repetitionContext* non_consecutive_repetition();

  class  Goto_repetitionContext : public antlr4::ParserRuleContext {
  public:
    Goto_repetitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_or_range_expressionContext *const_or_range_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Goto_repetitionContext* goto_repetition();

  class  Const_or_range_expressionContext : public antlr4::ParserRuleContext {
  public:
    Const_or_range_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();
    Cycle_delay_const_range_expressionContext *cycle_delay_const_range_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_or_range_expressionContext* const_or_range_expression();

  class  Cycle_delay_const_range_expressionContext : public antlr4::ParserRuleContext {
  public:
    Cycle_delay_const_range_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cycle_delay_const_range_expressionContext* cycle_delay_const_range_expression();

  class  Expression_or_distContext : public antlr4::ParserRuleContext {
  public:
    Expression_or_distContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Dist_listContext *dist_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_or_distContext* expression_or_dist();

  class  Assertion_variable_declarationContext : public antlr4::ParserRuleContext {
  public:
    Assertion_variable_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_data_typeContext *var_data_type();
    List_of_variable_decl_assignmentsContext *list_of_variable_decl_assignments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assertion_variable_declarationContext* assertion_variable_declaration();

  class  Let_declarationContext : public antlr4::ParserRuleContext {
  public:
    Let_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Let_identifierContext *let_identifier();
    ExpressionContext *expression();
    Let_port_listContext *let_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_declarationContext* let_declaration();

  class  Let_identifierContext : public antlr4::ParserRuleContext {
  public:
    Let_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_identifierContext* let_identifier();

  class  Let_port_listContext : public antlr4::ParserRuleContext {
  public:
    Let_port_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Let_port_itemContext *> let_port_item();
    Let_port_itemContext* let_port_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_port_listContext* let_port_list();

  class  Let_port_itemContext : public antlr4::ParserRuleContext {
  public:
    Let_port_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Let_formal_typeContext *let_formal_type();
    Formal_port_identifierContext *formal_port_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    std::vector<Variable_dimensionContext *> variable_dimension();
    Variable_dimensionContext* variable_dimension(size_t i);
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_port_itemContext* let_port_item();

  class  Let_formal_typeContext : public antlr4::ParserRuleContext {
  public:
    Let_formal_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_type_or_implicitContext *data_type_or_implicit();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_formal_typeContext* let_formal_type();

  class  Let_expressionContext : public antlr4::ParserRuleContext {
  public:
    Let_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Let_identifierContext *let_identifier();
    Package_scopeContext *package_scope();
    Let_list_of_argumentsContext *let_list_of_arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_expressionContext* let_expression();

  class  Let_list_of_argumentsContext : public antlr4::ParserRuleContext {
  public:
    Let_list_of_argumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Let_actual_argContext *> let_actual_arg();
    Let_actual_argContext* let_actual_arg(size_t i);
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_list_of_argumentsContext* let_list_of_arguments();

  class  Let_actual_argContext : public antlr4::ParserRuleContext {
  public:
    Let_actual_argContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Let_actual_argContext* let_actual_arg();

  class  Covergroup_declarationContext : public antlr4::ParserRuleContext {
  public:
    Covergroup_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Covergroup_identifierContext *> covergroup_identifier();
    Covergroup_identifierContext* covergroup_identifier(size_t i);
    Tf_port_listContext *tf_port_list();
    Coverage_eventContext *coverage_event();
    std::vector<Coverage_spec_or_optionContext *> coverage_spec_or_option();
    Coverage_spec_or_optionContext* coverage_spec_or_option(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Covergroup_declarationContext* covergroup_declaration();

  class  Coverage_spec_or_optionContext : public antlr4::ParserRuleContext {
  public:
    Coverage_spec_or_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Coverage_specContext *coverage_spec();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Coverage_optionContext *coverage_option();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Coverage_spec_or_optionContext* coverage_spec_or_option();

  class  Coverage_optionContext : public antlr4::ParserRuleContext {
  public:
    Coverage_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Member_identifierContext *member_identifier();
    ExpressionContext *expression();
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Coverage_optionContext* coverage_option();

  class  Coverage_specContext : public antlr4::ParserRuleContext {
  public:
    Coverage_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cover_pointContext *cover_point();
    Cover_crossContext *cover_cross();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Coverage_specContext* coverage_spec();

  class  Coverage_eventContext : public antlr4::ParserRuleContext {
  public:
    Coverage_eventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Clocking_eventContext *clocking_event();
    Tf_port_listContext *tf_port_list();
    Block_event_expressionContext *block_event_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Coverage_eventContext* coverage_event();

  class  Block_event_expressionContext : public antlr4::ParserRuleContext {
  public:
    Block_event_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_btf_identifierContext *hierarchical_btf_identifier();
    std::vector<Block_event_expressionContext *> block_event_expression();
    Block_event_expressionContext* block_event_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_event_expressionContext* block_event_expression();
  Block_event_expressionContext* block_event_expression(int precedence);
  class  Hierarchical_btf_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_btf_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_tf_identifierContext *hierarchical_tf_identifier();
    Hierarchical_block_identifierContext *hierarchical_block_identifier();
    Method_identifierContext *method_identifier();
    Hierarchical_identifierContext *hierarchical_identifier();
    Class_scopeContext *class_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_btf_identifierContext* hierarchical_btf_identifier();

  class  Cover_pointContext : public antlr4::ParserRuleContext {
  public:
    Cover_pointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    Bins_or_emptyContext *bins_or_empty();
    Data_type_or_implicitContext *data_type_or_implicit();
    Cover_point_identifierContext *cover_point_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cover_pointContext* cover_point();

  class  Bins_or_emptyContext : public antlr4::ParserRuleContext {
  public:
    Bins_or_emptyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    std::vector<Bins_or_optionsContext *> bins_or_options();
    Bins_or_optionsContext* bins_or_options(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bins_or_emptyContext* bins_or_empty();

  class  Bins_or_optionsContext : public antlr4::ParserRuleContext {
  public:
    Bins_or_optionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Coverage_optionContext *coverage_option();
    Bins_keywordContext *bins_keyword();
    Bin_identifierContext *bin_identifier();
    Covergroup_range_listContext *covergroup_range_list();
    With_covergroup_expressionContext *with_covergroup_expression();
    ExpressionContext *expression();
    Covergroup_expressionContext *covergroup_expression();
    Cover_point_identifierContext *cover_point_identifier();
    Set_covergroup_expressionContext *set_covergroup_expression();
    Trans_listContext *trans_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bins_or_optionsContext* bins_or_options();

  class  Bins_keywordContext : public antlr4::ParserRuleContext {
  public:
    Bins_keywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bins_keywordContext* bins_keyword();

  class  Trans_listContext : public antlr4::ParserRuleContext {
  public:
    Trans_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Trans_setContext *> trans_set();
    Trans_setContext* trans_set(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Trans_listContext* trans_list();

  class  Trans_setContext : public antlr4::ParserRuleContext {
  public:
    Trans_setContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Trans_range_listContext *> trans_range_list();
    Trans_range_listContext* trans_range_list(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Trans_setContext* trans_set();

  class  Trans_range_listContext : public antlr4::ParserRuleContext {
  public:
    Trans_range_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Trans_itemContext *trans_item();
    Repeat_rangeContext *repeat_range();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Trans_range_listContext* trans_range_list();

  class  Trans_itemContext : public antlr4::ParserRuleContext {
  public:
    Trans_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Covergroup_range_listContext *covergroup_range_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Trans_itemContext* trans_item();

  class  Repeat_rangeContext : public antlr4::ParserRuleContext {
  public:
    Repeat_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Covergroup_expressionContext *> covergroup_expression();
    Covergroup_expressionContext* covergroup_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Repeat_rangeContext* repeat_range();

  class  Cover_crossContext : public antlr4::ParserRuleContext {
  public:
    Cover_crossContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_cross_itemsContext *list_of_cross_items();
    Cross_bodyContext *cross_body();
    Cross_identifierContext *cross_identifier();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cover_crossContext* cover_cross();

  class  List_of_cross_itemsContext : public antlr4::ParserRuleContext {
  public:
    List_of_cross_itemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Cross_itemContext *> cross_item();
    Cross_itemContext* cross_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_cross_itemsContext* list_of_cross_items();

  class  Cross_itemContext : public antlr4::ParserRuleContext {
  public:
    Cross_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cover_point_identifierContext *cover_point_identifier();
    Variable_identifierContext *variable_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cross_itemContext* cross_item();

  class  Cross_bodyContext : public antlr4::ParserRuleContext {
  public:
    Cross_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Cross_body_itemContext *> cross_body_item();
    Cross_body_itemContext* cross_body_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cross_bodyContext* cross_body();

  class  Cross_body_itemContext : public antlr4::ParserRuleContext {
  public:
    Cross_body_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_declarationContext *function_declaration();
    Bins_selection_or_optionContext *bins_selection_or_option();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cross_body_itemContext* cross_body_item();

  class  Bins_selection_or_optionContext : public antlr4::ParserRuleContext {
  public:
    Bins_selection_or_optionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Coverage_optionContext *coverage_option();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Bins_selectionContext *bins_selection();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bins_selection_or_optionContext* bins_selection_or_option();

  class  Bins_selectionContext : public antlr4::ParserRuleContext {
  public:
    Bins_selectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bins_keywordContext *bins_keyword();
    Bin_identifierContext *bin_identifier();
    Select_expressionContext *select_expression();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bins_selectionContext* bins_selection();

  class  Select_expressionContext : public antlr4::ParserRuleContext {
  public:
    Select_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Select_conditionContext *select_condition();
    std::vector<Select_expressionContext *> select_expression();
    Select_expressionContext* select_expression(size_t i);
    Cross_identifierContext *cross_identifier();
    Cross_set_expressionContext *cross_set_expression();
    Integer_covergroup_expressionContext *integer_covergroup_expression();
    With_covergroup_expressionContext *with_covergroup_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Select_expressionContext* select_expression();
  Select_expressionContext* select_expression(int precedence);
  class  Select_conditionContext : public antlr4::ParserRuleContext {
  public:
    Select_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Bins_expressionContext *bins_expression();
    Covergroup_range_listContext *covergroup_range_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Select_conditionContext* select_condition();

  class  Bins_expressionContext : public antlr4::ParserRuleContext {
  public:
    Bins_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_identifierContext *variable_identifier();
    Cover_point_identifierContext *cover_point_identifier();
    Bin_identifierContext *bin_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bins_expressionContext* bins_expression();

  class  Covergroup_range_listContext : public antlr4::ParserRuleContext {
  public:
    Covergroup_range_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Covergroup_value_rangeContext *> covergroup_value_range();
    Covergroup_value_rangeContext* covergroup_value_range(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Covergroup_range_listContext* covergroup_range_list();

  class  Covergroup_value_rangeContext : public antlr4::ParserRuleContext {
  public:
    Covergroup_value_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Covergroup_expressionContext *> covergroup_expression();
    Covergroup_expressionContext* covergroup_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Covergroup_value_rangeContext* covergroup_value_range();

  class  With_covergroup_expressionContext : public antlr4::ParserRuleContext {
  public:
    With_covergroup_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Covergroup_expressionContext *covergroup_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  With_covergroup_expressionContext* with_covergroup_expression();

  class  Set_covergroup_expressionContext : public antlr4::ParserRuleContext {
  public:
    Set_covergroup_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Covergroup_expressionContext *covergroup_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Set_covergroup_expressionContext* set_covergroup_expression();

  class  Integer_covergroup_expressionContext : public antlr4::ParserRuleContext {
  public:
    Integer_covergroup_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Covergroup_expressionContext *covergroup_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Integer_covergroup_expressionContext* integer_covergroup_expression();

  class  Cross_set_expressionContext : public antlr4::ParserRuleContext {
  public:
    Cross_set_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Covergroup_expressionContext *covergroup_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cross_set_expressionContext* cross_set_expression();

  class  Covergroup_expressionContext : public antlr4::ParserRuleContext {
  public:
    Covergroup_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Covergroup_expressionContext* covergroup_expression();

  class  Gate_instantiationContext : public antlr4::ParserRuleContext {
  public:
    Gate_instantiationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cmos_switchtypeContext *cmos_switchtype();
    std::vector<Cmos_switch_instanceContext *> cmos_switch_instance();
    Cmos_switch_instanceContext* cmos_switch_instance(size_t i);
    Delay3Context *delay3();
    Enable_gatetypeContext *enable_gatetype();
    std::vector<Enable_gate_instanceContext *> enable_gate_instance();
    Enable_gate_instanceContext* enable_gate_instance(size_t i);
    Drive_strengthContext *drive_strength();
    Mos_switchtypeContext *mos_switchtype();
    std::vector<Mos_switch_instanceContext *> mos_switch_instance();
    Mos_switch_instanceContext* mos_switch_instance(size_t i);
    N_input_gatetypeContext *n_input_gatetype();
    std::vector<N_input_gate_instanceContext *> n_input_gate_instance();
    N_input_gate_instanceContext* n_input_gate_instance(size_t i);
    Delay2Context *delay2();
    N_output_gatetypeContext *n_output_gatetype();
    std::vector<N_output_gate_instanceContext *> n_output_gate_instance();
    N_output_gate_instanceContext* n_output_gate_instance(size_t i);
    Pass_en_switchtypeContext *pass_en_switchtype();
    std::vector<Pass_enable_switch_instanceContext *> pass_enable_switch_instance();
    Pass_enable_switch_instanceContext* pass_enable_switch_instance(size_t i);
    Pass_switchtypeContext *pass_switchtype();
    std::vector<Pass_switch_instanceContext *> pass_switch_instance();
    Pass_switch_instanceContext* pass_switch_instance(size_t i);
    std::vector<Pull_gate_instanceContext *> pull_gate_instance();
    Pull_gate_instanceContext* pull_gate_instance(size_t i);
    Pulldown_strengthContext *pulldown_strength();
    Pullup_strengthContext *pullup_strength();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Gate_instantiationContext* gate_instantiation();

  class  Cmos_switch_instanceContext : public antlr4::ParserRuleContext {
  public:
    Cmos_switch_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_terminalContext *output_terminal();
    Input_terminalContext *input_terminal();
    Ncontrol_terminalContext *ncontrol_terminal();
    Pcontrol_terminalContext *pcontrol_terminal();
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cmos_switch_instanceContext* cmos_switch_instance();

  class  Enable_gate_instanceContext : public antlr4::ParserRuleContext {
  public:
    Enable_gate_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_terminalContext *output_terminal();
    Input_terminalContext *input_terminal();
    Enable_terminalContext *enable_terminal();
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enable_gate_instanceContext* enable_gate_instance();

  class  Mos_switch_instanceContext : public antlr4::ParserRuleContext {
  public:
    Mos_switch_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_terminalContext *output_terminal();
    Input_terminalContext *input_terminal();
    Enable_terminalContext *enable_terminal();
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mos_switch_instanceContext* mos_switch_instance();

  class  N_input_gate_instanceContext : public antlr4::ParserRuleContext {
  public:
    N_input_gate_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_terminalContext *output_terminal();
    std::vector<Input_terminalContext *> input_terminal();
    Input_terminalContext* input_terminal(size_t i);
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  N_input_gate_instanceContext* n_input_gate_instance();

  class  N_output_gate_instanceContext : public antlr4::ParserRuleContext {
  public:
    N_output_gate_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Output_terminalContext *> output_terminal();
    Output_terminalContext* output_terminal(size_t i);
    Input_terminalContext *input_terminal();
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  N_output_gate_instanceContext* n_output_gate_instance();

  class  Pass_switch_instanceContext : public antlr4::ParserRuleContext {
  public:
    Pass_switch_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Inout_terminalContext *> inout_terminal();
    Inout_terminalContext* inout_terminal(size_t i);
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pass_switch_instanceContext* pass_switch_instance();

  class  Pass_enable_switch_instanceContext : public antlr4::ParserRuleContext {
  public:
    Pass_enable_switch_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Inout_terminalContext *> inout_terminal();
    Inout_terminalContext* inout_terminal(size_t i);
    Enable_terminalContext *enable_terminal();
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pass_enable_switch_instanceContext* pass_enable_switch_instance();

  class  Pull_gate_instanceContext : public antlr4::ParserRuleContext {
  public:
    Pull_gate_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_terminalContext *output_terminal();
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pull_gate_instanceContext* pull_gate_instance();

  class  Pulldown_strengthContext : public antlr4::ParserRuleContext {
  public:
    Pulldown_strengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Strength0Context *strength0();
    Strength1Context *strength1();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pulldown_strengthContext* pulldown_strength();

  class  Pullup_strengthContext : public antlr4::ParserRuleContext {
  public:
    Pullup_strengthContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Strength0Context *strength0();
    Strength1Context *strength1();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pullup_strengthContext* pullup_strength();

  class  Enable_terminalContext : public antlr4::ParserRuleContext {
  public:
    Enable_terminalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enable_terminalContext* enable_terminal();

  class  Inout_terminalContext : public antlr4::ParserRuleContext {
  public:
    Inout_terminalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_lvalueContext *net_lvalue();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inout_terminalContext* inout_terminal();

  class  Input_terminalContext : public antlr4::ParserRuleContext {
  public:
    Input_terminalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_terminalContext* input_terminal();

  class  Ncontrol_terminalContext : public antlr4::ParserRuleContext {
  public:
    Ncontrol_terminalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ncontrol_terminalContext* ncontrol_terminal();

  class  Output_terminalContext : public antlr4::ParserRuleContext {
  public:
    Output_terminalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_lvalueContext *net_lvalue();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Output_terminalContext* output_terminal();

  class  Pcontrol_terminalContext : public antlr4::ParserRuleContext {
  public:
    Pcontrol_terminalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pcontrol_terminalContext* pcontrol_terminal();

  class  Cmos_switchtypeContext : public antlr4::ParserRuleContext {
  public:
    Cmos_switchtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cmos_switchtypeContext* cmos_switchtype();

  class  Enable_gatetypeContext : public antlr4::ParserRuleContext {
  public:
    Enable_gatetypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enable_gatetypeContext* enable_gatetype();

  class  Mos_switchtypeContext : public antlr4::ParserRuleContext {
  public:
    Mos_switchtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mos_switchtypeContext* mos_switchtype();

  class  N_input_gatetypeContext : public antlr4::ParserRuleContext {
  public:
    N_input_gatetypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  N_input_gatetypeContext* n_input_gatetype();

  class  N_output_gatetypeContext : public antlr4::ParserRuleContext {
  public:
    N_output_gatetypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  N_output_gatetypeContext* n_output_gatetype();

  class  Pass_en_switchtypeContext : public antlr4::ParserRuleContext {
  public:
    Pass_en_switchtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pass_en_switchtypeContext* pass_en_switchtype();

  class  Pass_switchtypeContext : public antlr4::ParserRuleContext {
  public:
    Pass_switchtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pass_switchtypeContext* pass_switchtype();

  class  Module_instantiationContext : public antlr4::ParserRuleContext {
  public:
    Module_instantiationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_identifierContext *module_identifier();
    std::vector<Hierarchical_instanceContext *> hierarchical_instance();
    Hierarchical_instanceContext* hierarchical_instance(size_t i);
    Parameter_value_assignmentContext *parameter_value_assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_instantiationContext* module_instantiation();

  class  Parameter_value_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Parameter_value_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_parameter_assignmentsContext *list_of_parameter_assignments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_value_assignmentContext* parameter_value_assignment();

  class  List_of_parameter_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_parameter_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Ordered_parameter_assignmentContext *> ordered_parameter_assignment();
    Ordered_parameter_assignmentContext* ordered_parameter_assignment(size_t i);
    std::vector<Named_parameter_assignmentContext *> named_parameter_assignment();
    Named_parameter_assignmentContext* named_parameter_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_parameter_assignmentsContext* list_of_parameter_assignments();

  class  Ordered_parameter_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Ordered_parameter_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Param_expressionContext *param_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ordered_parameter_assignmentContext* ordered_parameter_assignment();

  class  Named_parameter_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Named_parameter_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parameter_identifierContext *parameter_identifier();
    Param_expressionContext *param_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_parameter_assignmentContext* named_parameter_assignment();

  class  Hierarchical_instanceContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Name_of_instanceContext *name_of_instance();
    List_of_port_connectionsContext *list_of_port_connections();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_instanceContext* hierarchical_instance();

  class  Name_of_instanceContext : public antlr4::ParserRuleContext {
  public:
    Name_of_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Instance_identifierContext *instance_identifier();
    std::vector<Unpacked_dimensionContext *> unpacked_dimension();
    Unpacked_dimensionContext* unpacked_dimension(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Name_of_instanceContext* name_of_instance();

  class  List_of_port_connectionsContext : public antlr4::ParserRuleContext {
  public:
    List_of_port_connectionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Ordered_port_connectionContext *> ordered_port_connection();
    Ordered_port_connectionContext* ordered_port_connection(size_t i);
    std::vector<Named_port_connectionContext *> named_port_connection();
    Named_port_connectionContext* named_port_connection(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_port_connectionsContext* list_of_port_connections();

  class  Ordered_port_connectionContext : public antlr4::ParserRuleContext {
  public:
    Ordered_port_connectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ordered_port_connectionContext* ordered_port_connection();

  class  Named_port_connectionContext : public antlr4::ParserRuleContext {
  public:
    Named_port_connectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_identifierContext *port_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_port_connectionContext* named_port_connection();

  class  Interface_instantiationContext : public antlr4::ParserRuleContext {
  public:
    Interface_instantiationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Interface_identifierContext *interface_identifier();
    std::vector<Hierarchical_instanceContext *> hierarchical_instance();
    Hierarchical_instanceContext* hierarchical_instance(size_t i);
    Parameter_value_assignmentContext *parameter_value_assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_instantiationContext* interface_instantiation();

  class  Program_instantiationContext : public antlr4::ParserRuleContext {
  public:
    Program_instantiationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Program_identifierContext *program_identifier();
    std::vector<Hierarchical_instanceContext *> hierarchical_instance();
    Hierarchical_instanceContext* hierarchical_instance(size_t i);
    Parameter_value_assignmentContext *parameter_value_assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_instantiationContext* program_instantiation();

  class  Checker_instantiationContext : public antlr4::ParserRuleContext {
  public:
    Checker_instantiationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_checker_identifierContext *ps_checker_identifier();
    Name_of_instanceContext *name_of_instance();
    List_of_checker_port_connectionsContext *list_of_checker_port_connections();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_instantiationContext* checker_instantiation();

  class  List_of_checker_port_connectionsContext : public antlr4::ParserRuleContext {
  public:
    List_of_checker_port_connectionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Ordered_checker_port_connectionContext *> ordered_checker_port_connection();
    Ordered_checker_port_connectionContext* ordered_checker_port_connection(size_t i);
    std::vector<Named_checker_port_connectionContext *> named_checker_port_connection();
    Named_checker_port_connectionContext* named_checker_port_connection(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_checker_port_connectionsContext* list_of_checker_port_connections();

  class  Ordered_checker_port_connectionContext : public antlr4::ParserRuleContext {
  public:
    Ordered_checker_port_connectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Property_actual_argContext *property_actual_arg();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ordered_checker_port_connectionContext* ordered_checker_port_connection();

  class  Named_checker_port_connectionContext : public antlr4::ParserRuleContext {
  public:
    Named_checker_port_connectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Formal_port_identifierContext *formal_port_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Property_actual_argContext *property_actual_arg();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Named_checker_port_connectionContext* named_checker_port_connection();

  class  Generate_regionContext : public antlr4::ParserRuleContext {
  public:
    Generate_regionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Generate_itemContext *> generate_item();
    Generate_itemContext* generate_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Generate_regionContext* generate_region();

  class  Loop_generate_constructContext : public antlr4::ParserRuleContext {
  public:
    Loop_generate_constructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Genvar_initializationContext *genvar_initialization();
    Genvar_expressionContext *genvar_expression();
    Genvar_iterationContext *genvar_iteration();
    Generate_blockContext *generate_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Loop_generate_constructContext* loop_generate_construct();

  class  Genvar_initializationContext : public antlr4::ParserRuleContext {
  public:
    Genvar_initializationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Genvar_identifierContext *genvar_identifier();
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Genvar_initializationContext* genvar_initialization();

  class  Genvar_iterationContext : public antlr4::ParserRuleContext {
  public:
    Genvar_iterationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Genvar_identifierContext *genvar_identifier();
    Assignment_operatorContext *assignment_operator();
    Genvar_expressionContext *genvar_expression();
    Inc_or_dec_operatorContext *inc_or_dec_operator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Genvar_iterationContext* genvar_iteration();

  class  Conditional_generate_constructContext : public antlr4::ParserRuleContext {
  public:
    Conditional_generate_constructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    If_generate_constructContext *if_generate_construct();
    Case_generate_constructContext *case_generate_construct();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_generate_constructContext* conditional_generate_construct();

  class  If_generate_constructContext : public antlr4::ParserRuleContext {
  public:
    If_generate_constructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();
    std::vector<Generate_blockContext *> generate_block();
    Generate_blockContext* generate_block(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_generate_constructContext* if_generate_construct();

  class  Case_generate_constructContext : public antlr4::ParserRuleContext {
  public:
    Case_generate_constructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();
    std::vector<Case_generate_itemContext *> case_generate_item();
    Case_generate_itemContext* case_generate_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_generate_constructContext* case_generate_construct();

  class  Case_generate_itemContext : public antlr4::ParserRuleContext {
  public:
    Case_generate_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);
    Generate_blockContext *generate_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_generate_itemContext* case_generate_item();

  class  Generate_blockContext : public antlr4::ParserRuleContext {
  public:
    Generate_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Generate_itemContext *> generate_item();
    Generate_itemContext* generate_item(size_t i);
    std::vector<Generate_block_identifierContext *> generate_block_identifier();
    Generate_block_identifierContext* generate_block_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Generate_blockContext* generate_block();

  class  Generate_itemContext : public antlr4::ParserRuleContext {
  public:
    Generate_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_or_generate_itemContext *module_or_generate_item();
    Interface_or_generate_itemContext *interface_or_generate_item();
    Checker_or_generate_itemContext *checker_or_generate_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Generate_itemContext* generate_item();

  class  Udp_nonansi_declarationContext : public antlr4::ParserRuleContext {
  public:
    Udp_nonansi_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udp_identifierContext *udp_identifier();
    Udp_port_listContext *udp_port_list();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_nonansi_declarationContext* udp_nonansi_declaration();

  class  Udp_ansi_declarationContext : public antlr4::ParserRuleContext {
  public:
    Udp_ansi_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udp_identifierContext *udp_identifier();
    Udp_declaration_port_listContext *udp_declaration_port_list();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_ansi_declarationContext* udp_ansi_declaration();

  class  Udp_declarationContext : public antlr4::ParserRuleContext {
  public:
    Udp_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udp_nonansi_declarationContext *udp_nonansi_declaration();
    std::vector<Udp_port_declarationContext *> udp_port_declaration();
    Udp_port_declarationContext* udp_port_declaration(size_t i);
    Udp_bodyContext *udp_body();
    std::vector<Udp_identifierContext *> udp_identifier();
    Udp_identifierContext* udp_identifier(size_t i);
    Udp_ansi_declarationContext *udp_ansi_declaration();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_declarationContext* udp_declaration();

  class  Udp_port_listContext : public antlr4::ParserRuleContext {
  public:
    Udp_port_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_port_identifierContext *output_port_identifier();
    std::vector<Input_port_identifierContext *> input_port_identifier();
    Input_port_identifierContext* input_port_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_port_listContext* udp_port_list();

  class  Udp_declaration_port_listContext : public antlr4::ParserRuleContext {
  public:
    Udp_declaration_port_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udp_output_declarationContext *udp_output_declaration();
    std::vector<Udp_input_declarationContext *> udp_input_declaration();
    Udp_input_declarationContext* udp_input_declaration(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_declaration_port_listContext* udp_declaration_port_list();

  class  Udp_port_declarationContext : public antlr4::ParserRuleContext {
  public:
    Udp_port_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udp_output_declarationContext *udp_output_declaration();
    Udp_input_declarationContext *udp_input_declaration();
    Udp_reg_declarationContext *udp_reg_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_port_declarationContext* udp_port_declaration();

  class  Udp_output_declarationContext : public antlr4::ParserRuleContext {
  public:
    Udp_output_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Port_identifierContext *port_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_output_declarationContext* udp_output_declaration();

  class  Udp_input_declarationContext : public antlr4::ParserRuleContext {
  public:
    Udp_input_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_udp_port_identifiersContext *list_of_udp_port_identifiers();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_input_declarationContext* udp_input_declaration();

  class  Udp_reg_declarationContext : public antlr4::ParserRuleContext {
  public:
    Udp_reg_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_identifierContext *variable_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_reg_declarationContext* udp_reg_declaration();

  class  Udp_bodyContext : public antlr4::ParserRuleContext {
  public:
    Udp_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Combinational_bodyContext *combinational_body();
    Sequential_bodyContext *sequential_body();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_bodyContext* udp_body();

  class  Combinational_bodyContext : public antlr4::ParserRuleContext {
  public:
    Combinational_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Combinational_entryContext *> combinational_entry();
    Combinational_entryContext* combinational_entry(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Combinational_bodyContext* combinational_body();

  class  Combinational_entryContext : public antlr4::ParserRuleContext {
  public:
    Combinational_entryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Level_input_listContext *level_input_list();
    Output_symbolContext *output_symbol();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Combinational_entryContext* combinational_entry();

  class  Sequential_bodyContext : public antlr4::ParserRuleContext {
  public:
    Sequential_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Sequential_entryContext *> sequential_entry();
    Sequential_entryContext* sequential_entry(size_t i);
    Udp_initial_statementContext *udp_initial_statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequential_bodyContext* sequential_body();

  class  Udp_initial_statementContext : public antlr4::ParserRuleContext {
  public:
    Udp_initial_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_port_identifierContext *output_port_identifier();
    Init_valContext *init_val();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_initial_statementContext* udp_initial_statement();

  class  Init_valContext : public antlr4::ParserRuleContext {
  public:
    Init_valContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integral_number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Init_valContext* init_val();

  class  Sequential_entryContext : public antlr4::ParserRuleContext {
  public:
    Sequential_entryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Seq_input_listContext *seq_input_list();
    Current_stateContext *current_state();
    Next_stateContext *next_state();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequential_entryContext* sequential_entry();

  class  Seq_input_listContext : public antlr4::ParserRuleContext {
  public:
    Seq_input_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Level_input_listContext *level_input_list();
    Edge_input_listContext *edge_input_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Seq_input_listContext* seq_input_list();

  class  Level_input_listContext : public antlr4::ParserRuleContext {
  public:
    Level_input_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Level_symbolContext *> level_symbol();
    Level_symbolContext* level_symbol(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Level_input_listContext* level_input_list();

  class  Edge_input_listContext : public antlr4::ParserRuleContext {
  public:
    Edge_input_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Edge_indicatorContext *edge_indicator();
    std::vector<Level_symbolContext *> level_symbol();
    Level_symbolContext* level_symbol(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_input_listContext* edge_input_list();

  class  Edge_indicatorContext : public antlr4::ParserRuleContext {
  public:
    Edge_indicatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Level_symbolContext *> level_symbol();
    Level_symbolContext* level_symbol(size_t i);
    Edge_symbolContext *edge_symbol();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_indicatorContext* edge_indicator();

  class  Current_stateContext : public antlr4::ParserRuleContext {
  public:
    Current_stateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Level_symbolContext *level_symbol();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Current_stateContext* current_state();

  class  Next_stateContext : public antlr4::ParserRuleContext {
  public:
    Next_stateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_symbolContext *output_symbol();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Next_stateContext* next_state();

  class  Output_symbolContext : public antlr4::ParserRuleContext {
  public:
    Output_symbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integral_number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Output_symbolContext* output_symbol();

  class  Level_symbolContext : public antlr4::ParserRuleContext {
  public:
    Level_symbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Unsigned_number();
    antlr4::tree::TerminalNode *Simple_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Level_symbolContext* level_symbol();

  class  Edge_symbolContext : public antlr4::ParserRuleContext {
  public:
    Edge_symbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Simple_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_symbolContext* edge_symbol();

  class  Udp_instantiationContext : public antlr4::ParserRuleContext {
  public:
    Udp_instantiationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Udp_identifierContext *udp_identifier();
    std::vector<Udp_instanceContext *> udp_instance();
    Udp_instanceContext* udp_instance(size_t i);
    Drive_strengthContext *drive_strength();
    Delay2Context *delay2();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_instantiationContext* udp_instantiation();

  class  Udp_instanceContext : public antlr4::ParserRuleContext {
  public:
    Udp_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_terminalContext *output_terminal();
    std::vector<Input_terminalContext *> input_terminal();
    Input_terminalContext* input_terminal(size_t i);
    Name_of_instanceContext *name_of_instance();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_instanceContext* udp_instance();

  class  Continuous_assignContext : public antlr4::ParserRuleContext {
  public:
    Continuous_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_net_assignmentsContext *list_of_net_assignments();
    Drive_strengthContext *drive_strength();
    Delay3Context *delay3();
    List_of_variable_assignmentsContext *list_of_variable_assignments();
    Delay_controlContext *delay_control();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Continuous_assignContext* continuous_assign();

  class  List_of_net_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_net_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Net_assignmentContext *> net_assignment();
    Net_assignmentContext* net_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_net_assignmentsContext* list_of_net_assignments();

  class  List_of_variable_assignmentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_variable_assignmentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_assignmentContext *> variable_assignment();
    Variable_assignmentContext* variable_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_variable_assignmentsContext* list_of_variable_assignments();

  class  Net_aliasContext : public antlr4::ParserRuleContext {
  public:
    Net_aliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Net_lvalueContext *> net_lvalue();
    Net_lvalueContext* net_lvalue(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_aliasContext* net_alias();

  class  Net_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Net_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_lvalueContext *net_lvalue();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_assignmentContext* net_assignment();

  class  Initial_constructContext : public antlr4::ParserRuleContext {
  public:
    Initial_constructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_or_nullContext *statement_or_null();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Initial_constructContext* initial_construct();

  class  Always_constructContext : public antlr4::ParserRuleContext {
  public:
    Always_constructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Always_keywordContext *always_keyword();
    StatementContext *statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Always_constructContext* always_construct();

  class  Always_keywordContext : public antlr4::ParserRuleContext {
  public:
    Always_keywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Always_keywordContext* always_keyword();

  class  Final_constructContext : public antlr4::ParserRuleContext {
  public:
    Final_constructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_statementContext *function_statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Final_constructContext* final_construct();

  class  Blocking_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Blocking_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_lvalueContext *variable_lvalue();
    Delay_or_event_controlContext *delay_or_event_control();
    ExpressionContext *expression();
    Nonrange_variable_lvalueContext *nonrange_variable_lvalue();
    Dynamic_array_newContext *dynamic_array_new();
    Hierarchical_variable_identifierContext *hierarchical_variable_identifier();
    SelectContext *select();
    Class_newContext *class_new();
    Implicit_class_handleContext *implicit_class_handle();
    Class_scopeContext *class_scope();
    Package_scopeContext *package_scope();
    Operator_assignmentContext *operator_assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Blocking_assignmentContext* blocking_assignment();

  class  Operator_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Operator_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_lvalueContext *variable_lvalue();
    Assignment_operatorContext *assignment_operator();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Operator_assignmentContext* operator_assignment();

  class  Assignment_operatorContext : public antlr4::ParserRuleContext {
  public:
    Assignment_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_operatorContext* assignment_operator();

  class  Nonblocking_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Nonblocking_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_lvalueContext *variable_lvalue();
    ExpressionContext *expression();
    Delay_or_event_controlContext *delay_or_event_control();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Nonblocking_assignmentContext* nonblocking_assignment();

  class  Procedural_continuous_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Procedural_continuous_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_assignmentContext *variable_assignment();
    Variable_lvalueContext *variable_lvalue();
    Net_assignmentContext *net_assignment();
    Net_lvalueContext *net_lvalue();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Procedural_continuous_assignmentContext* procedural_continuous_assignment();

  class  Variable_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Variable_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_lvalueContext *variable_lvalue();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_assignmentContext* variable_assignment();

  class  Action_blockContext : public antlr4::ParserRuleContext {
  public:
    Action_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_or_nullContext *statement_or_null();
    StatementContext *statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Action_blockContext* action_block();

  class  Seq_blockContext : public antlr4::ParserRuleContext {
  public:
    Seq_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Block_identifierContext *> block_identifier();
    Block_identifierContext* block_identifier(size_t i);
    std::vector<Block_item_declarationContext *> block_item_declaration();
    Block_item_declarationContext* block_item_declaration(size_t i);
    std::vector<Statement_or_nullContext *> statement_or_null();
    Statement_or_nullContext* statement_or_null(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Seq_blockContext* seq_block();

  class  Par_blockContext : public antlr4::ParserRuleContext {
  public:
    Par_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Join_keywordContext *join_keyword();
    std::vector<Block_identifierContext *> block_identifier();
    Block_identifierContext* block_identifier(size_t i);
    std::vector<Block_item_declarationContext *> block_item_declaration();
    Block_item_declarationContext* block_item_declaration(size_t i);
    std::vector<Statement_or_nullContext *> statement_or_null();
    Statement_or_nullContext* statement_or_null(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Par_blockContext* par_block();

  class  Join_keywordContext : public antlr4::ParserRuleContext {
  public:
    Join_keywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Join_keywordContext* join_keyword();

  class  Statement_or_nullContext : public antlr4::ParserRuleContext {
  public:
    Statement_or_nullContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_or_nullContext* statement_or_null();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_itemContext *statement_item();
    Block_identifierContext *block_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Statement_itemContext : public antlr4::ParserRuleContext {
  public:
    Statement_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Blocking_assignmentContext *blocking_assignment();
    Nonblocking_assignmentContext *nonblocking_assignment();
    Procedural_continuous_assignmentContext *procedural_continuous_assignment();
    Case_statementContext *case_statement();
    Conditional_statementContext *conditional_statement();
    Inc_or_dec_expressionContext *inc_or_dec_expression();
    Subroutine_call_statementContext *subroutine_call_statement();
    Disable_statementContext *disable_statement();
    Event_triggerContext *event_trigger();
    Loop_statementContext *loop_statement();
    Jump_statementContext *jump_statement();
    Par_blockContext *par_block();
    Procedural_timing_control_statementContext *procedural_timing_control_statement();
    Seq_blockContext *seq_block();
    Wait_statementContext *wait_statement();
    Procedural_assertion_statementContext *procedural_assertion_statement();
    Clocking_driveContext *clocking_drive();
    Randsequence_statementContext *randsequence_statement();
    Randcase_statementContext *randcase_statement();
    Expect_property_statementContext *expect_property_statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_itemContext* statement_item();

  class  Function_statementContext : public antlr4::ParserRuleContext {
  public:
    Function_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_statementContext* function_statement();

  class  Function_statement_or_nullContext : public antlr4::ParserRuleContext {
  public:
    Function_statement_or_nullContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_statementContext *function_statement();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_statement_or_nullContext* function_statement_or_null();

  class  Variable_identifier_listContext : public antlr4::ParserRuleContext {
  public:
    Variable_identifier_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_identifierContext *> variable_identifier();
    Variable_identifierContext* variable_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_identifier_listContext* variable_identifier_list();

  class  Procedural_timing_control_statementContext : public antlr4::ParserRuleContext {
  public:
    Procedural_timing_control_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Procedural_timing_controlContext *procedural_timing_control();
    Statement_or_nullContext *statement_or_null();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Procedural_timing_control_statementContext* procedural_timing_control_statement();

  class  Delay_or_event_controlContext : public antlr4::ParserRuleContext {
  public:
    Delay_or_event_controlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Delay_controlContext *delay_control();
    Event_controlContext *event_control();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delay_or_event_controlContext* delay_or_event_control();

  class  Delay_controlContext : public antlr4::ParserRuleContext {
  public:
    Delay_controlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Delay_valueContext *delay_value();
    Mintypmax_expressionContext *mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delay_controlContext* delay_control();

  class  Event_controlContext : public antlr4::ParserRuleContext {
  public:
    Event_controlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_event_identifierContext *hierarchical_event_identifier();
    Event_expressionContext *event_expression();
    Ps_or_hierarchical_sequence_identifierContext *ps_or_hierarchical_sequence_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_controlContext* event_control();

  class  Event_expressionContext : public antlr4::ParserRuleContext {
  public:
    Event_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    Edge_identifierContext *edge_identifier();
    Sequence_instanceContext *sequence_instance();
    std::vector<Event_expressionContext *> event_expression();
    Event_expressionContext* event_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_expressionContext* event_expression();
  Event_expressionContext* event_expression(int precedence);
  class  Procedural_timing_controlContext : public antlr4::ParserRuleContext {
  public:
    Procedural_timing_controlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Delay_controlContext *delay_control();
    Event_controlContext *event_control();
    Cycle_delayContext *cycle_delay();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Procedural_timing_controlContext* procedural_timing_control();

  class  Jump_statementContext : public antlr4::ParserRuleContext {
  public:
    Jump_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Jump_statementContext* jump_statement();

  class  Wait_statementContext : public antlr4::ParserRuleContext {
  public:
    Wait_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Statement_or_nullContext *statement_or_null();
    std::vector<Hierarchical_identifierContext *> hierarchical_identifier();
    Hierarchical_identifierContext* hierarchical_identifier(size_t i);
    Action_blockContext *action_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Wait_statementContext* wait_statement();

  class  Event_triggerContext : public antlr4::ParserRuleContext {
  public:
    Event_triggerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_event_identifierContext *hierarchical_event_identifier();
    Delay_or_event_controlContext *delay_or_event_control();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_triggerContext* event_trigger();

  class  Disable_statementContext : public antlr4::ParserRuleContext {
  public:
    Disable_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_task_identifierContext *hierarchical_task_identifier();
    Hierarchical_block_identifierContext *hierarchical_block_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Disable_statementContext* disable_statement();

  class  Conditional_statementContext : public antlr4::ParserRuleContext {
  public:
    Conditional_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Cond_predicateContext *> cond_predicate();
    Cond_predicateContext* cond_predicate(size_t i);
    std::vector<Statement_or_nullContext *> statement_or_null();
    Statement_or_nullContext* statement_or_null(size_t i);
    Unique_priorityContext *unique_priority();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_statementContext* conditional_statement();

  class  Unique_priorityContext : public antlr4::ParserRuleContext {
  public:
    Unique_priorityContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unique_priorityContext* unique_priority();

  class  Cond_predicateContext : public antlr4::ParserRuleContext {
  public:
    Cond_predicateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expression_or_cond_patternContext *> expression_or_cond_pattern();
    Expression_or_cond_patternContext* expression_or_cond_pattern(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cond_predicateContext* cond_predicate();

  class  Expression_or_cond_patternContext : public antlr4::ParserRuleContext {
  public:
    Expression_or_cond_patternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Cond_patternContext *cond_pattern();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_or_cond_patternContext* expression_or_cond_pattern();

  class  Cond_patternContext : public antlr4::ParserRuleContext {
  public:
    Cond_patternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    PatternContext *pattern();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cond_patternContext* cond_pattern();

  class  Case_statementContext : public antlr4::ParserRuleContext {
  public:
    Case_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Case_keywordContext *case_keyword();
    Case_expressionContext *case_expression();
    std::vector<Case_itemContext *> case_item();
    Case_itemContext* case_item(size_t i);
    Unique_priorityContext *unique_priority();
    std::vector<Case_pattern_itemContext *> case_pattern_item();
    Case_pattern_itemContext* case_pattern_item(size_t i);
    std::vector<Case_inside_itemContext *> case_inside_item();
    Case_inside_itemContext* case_inside_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_statementContext* case_statement();

  class  Case_keywordContext : public antlr4::ParserRuleContext {
  public:
    Case_keywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_keywordContext* case_keyword();

  class  Case_expressionContext : public antlr4::ParserRuleContext {
  public:
    Case_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_expressionContext* case_expression();

  class  Case_itemContext : public antlr4::ParserRuleContext {
  public:
    Case_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Case_item_expressionContext *> case_item_expression();
    Case_item_expressionContext* case_item_expression(size_t i);
    Statement_or_nullContext *statement_or_null();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_itemContext* case_item();

  class  Case_pattern_itemContext : public antlr4::ParserRuleContext {
  public:
    Case_pattern_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PatternContext *pattern();
    Statement_or_nullContext *statement_or_null();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_pattern_itemContext* case_pattern_item();

  class  Case_inside_itemContext : public antlr4::ParserRuleContext {
  public:
    Case_inside_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Open_range_listContext *open_range_list();
    Statement_or_nullContext *statement_or_null();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_inside_itemContext* case_inside_item();

  class  Case_item_expressionContext : public antlr4::ParserRuleContext {
  public:
    Case_item_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_item_expressionContext* case_item_expression();

  class  Randcase_statementContext : public antlr4::ParserRuleContext {
  public:
    Randcase_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Randcase_itemContext *> randcase_item();
    Randcase_itemContext* randcase_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Randcase_statementContext* randcase_statement();

  class  Randcase_itemContext : public antlr4::ParserRuleContext {
  public:
    Randcase_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Statement_or_nullContext *statement_or_null();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Randcase_itemContext* randcase_item();

  class  Open_range_listContext : public antlr4::ParserRuleContext {
  public:
    Open_range_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Open_value_rangeContext *> open_value_range();
    Open_value_rangeContext* open_value_range(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Open_range_listContext* open_range_list();

  class  Open_value_rangeContext : public antlr4::ParserRuleContext {
  public:
    Open_value_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_rangeContext *value_range();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Open_value_rangeContext* open_value_range();

  class  PatternContext : public antlr4::ParserRuleContext {
  public:
    PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_identifierContext *variable_identifier();
    Constant_expressionContext *constant_expression();
    std::vector<Member_identifierContext *> member_identifier();
    Member_identifierContext* member_identifier(size_t i);
    std::vector<PatternContext *> pattern();
    PatternContext* pattern(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PatternContext* pattern();

  class  Assignment_patternContext : public antlr4::ParserRuleContext {
  public:
    Assignment_patternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<Structure_pattern_keyContext *> structure_pattern_key();
    Structure_pattern_keyContext* structure_pattern_key(size_t i);
    std::vector<Array_pattern_keyContext *> array_pattern_key();
    Array_pattern_keyContext* array_pattern_key(size_t i);
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_patternContext* assignment_pattern();

  class  Structure_pattern_keyContext : public antlr4::ParserRuleContext {
  public:
    Structure_pattern_keyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Member_identifierContext *member_identifier();
    Assignment_pattern_keyContext *assignment_pattern_key();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Structure_pattern_keyContext* structure_pattern_key();

  class  Array_pattern_keyContext : public antlr4::ParserRuleContext {
  public:
    Array_pattern_keyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();
    Assignment_pattern_keyContext *assignment_pattern_key();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_pattern_keyContext* array_pattern_key();

  class  Assignment_pattern_keyContext : public antlr4::ParserRuleContext {
  public:
    Assignment_pattern_keyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_typeContext *simple_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_pattern_keyContext* assignment_pattern_key();

  class  Assignment_pattern_expressionContext : public antlr4::ParserRuleContext {
  public:
    Assignment_pattern_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignment_patternContext *assignment_pattern();
    Assignment_pattern_expression_typeContext *assignment_pattern_expression_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_pattern_expressionContext* assignment_pattern_expression();

  class  Assignment_pattern_expression_typeContext : public antlr4::ParserRuleContext {
  public:
    Assignment_pattern_expression_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_type_identifierContext *ps_type_identifier();
    Ps_parameter_identifierContext *ps_parameter_identifier();
    Integer_atom_typeContext *integer_atom_type();
    Type_referenceContext *type_reference();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_pattern_expression_typeContext* assignment_pattern_expression_type();

  class  Constant_assignment_pattern_expressionContext : public antlr4::ParserRuleContext {
  public:
    Constant_assignment_pattern_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Assignment_pattern_expressionContext *assignment_pattern_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_assignment_pattern_expressionContext* constant_assignment_pattern_expression();

  class  Assignment_pattern_net_lvalueContext : public antlr4::ParserRuleContext {
  public:
    Assignment_pattern_net_lvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Net_lvalueContext *> net_lvalue();
    Net_lvalueContext* net_lvalue(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_pattern_net_lvalueContext* assignment_pattern_net_lvalue();

  class  Assignment_pattern_variable_lvalueContext : public antlr4::ParserRuleContext {
  public:
    Assignment_pattern_variable_lvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_lvalueContext *> variable_lvalue();
    Variable_lvalueContext* variable_lvalue(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assignment_pattern_variable_lvalueContext* assignment_pattern_variable_lvalue();

  class  Loop_statementContext : public antlr4::ParserRuleContext {
  public:
    Loop_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Statement_or_nullContext *statement_or_null();
    ExpressionContext *expression();
    For_initializationContext *for_initialization();
    For_stepContext *for_step();
    Ps_or_hierarchical_array_identifierContext *ps_or_hierarchical_array_identifier();
    Loop_variablesContext *loop_variables();
    StatementContext *statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Loop_statementContext* loop_statement();

  class  For_initializationContext : public antlr4::ParserRuleContext {
  public:
    For_initializationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_variable_assignmentsContext *list_of_variable_assignments();
    std::vector<For_variable_declarationContext *> for_variable_declaration();
    For_variable_declarationContext* for_variable_declaration(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_initializationContext* for_initialization();

  class  For_variable_declarationContext : public antlr4::ParserRuleContext {
  public:
    For_variable_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_typeContext *data_type();
    std::vector<Variable_identifierContext *> variable_identifier();
    Variable_identifierContext* variable_identifier(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_variable_declarationContext* for_variable_declaration();

  class  For_stepContext : public antlr4::ParserRuleContext {
  public:
    For_stepContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<For_step_assignmentContext *> for_step_assignment();
    For_step_assignmentContext* for_step_assignment(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_stepContext* for_step();

  class  For_step_assignmentContext : public antlr4::ParserRuleContext {
  public:
    For_step_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Operator_assignmentContext *operator_assignment();
    Inc_or_dec_expressionContext *inc_or_dec_expression();
    Function_subroutine_callContext *function_subroutine_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_step_assignmentContext* for_step_assignment();

  class  Loop_variablesContext : public antlr4::ParserRuleContext {
  public:
    Loop_variablesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Index_variable_identifierContext *> index_variable_identifier();
    Index_variable_identifierContext* index_variable_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Loop_variablesContext* loop_variables();

  class  Subroutine_call_statementContext : public antlr4::ParserRuleContext {
  public:
    Subroutine_call_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subroutine_callContext *subroutine_call();
    Function_subroutine_callContext *function_subroutine_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Subroutine_call_statementContext* subroutine_call_statement();

  class  Assertion_itemContext : public antlr4::ParserRuleContext {
  public:
    Assertion_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concurrent_assertion_itemContext *concurrent_assertion_item();
    Deferred_immediate_assertion_itemContext *deferred_immediate_assertion_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assertion_itemContext* assertion_item();

  class  Deferred_immediate_assertion_itemContext : public antlr4::ParserRuleContext {
  public:
    Deferred_immediate_assertion_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Deferred_immediate_assertion_statementContext *deferred_immediate_assertion_statement();
    Block_identifierContext *block_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Deferred_immediate_assertion_itemContext* deferred_immediate_assertion_item();

  class  Procedural_assertion_statementContext : public antlr4::ParserRuleContext {
  public:
    Procedural_assertion_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Concurrent_assertion_statementContext *concurrent_assertion_statement();
    Immediate_assertion_statementContext *immediate_assertion_statement();
    Checker_instantiationContext *checker_instantiation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Procedural_assertion_statementContext* procedural_assertion_statement();

  class  Immediate_assertion_statementContext : public antlr4::ParserRuleContext {
  public:
    Immediate_assertion_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_immediate_assertion_statementContext *simple_immediate_assertion_statement();
    Deferred_immediate_assertion_statementContext *deferred_immediate_assertion_statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Immediate_assertion_statementContext* immediate_assertion_statement();

  class  Simple_immediate_assertion_statementContext : public antlr4::ParserRuleContext {
  public:
    Simple_immediate_assertion_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_immediate_assert_statementContext *simple_immediate_assert_statement();
    Simple_immediate_assume_statementContext *simple_immediate_assume_statement();
    Simple_immediate_cover_statementContext *simple_immediate_cover_statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_immediate_assertion_statementContext* simple_immediate_assertion_statement();

  class  Simple_immediate_assert_statementContext : public antlr4::ParserRuleContext {
  public:
    Simple_immediate_assert_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Action_blockContext *action_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_immediate_assert_statementContext* simple_immediate_assert_statement();

  class  Simple_immediate_assume_statementContext : public antlr4::ParserRuleContext {
  public:
    Simple_immediate_assume_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Action_blockContext *action_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_immediate_assume_statementContext* simple_immediate_assume_statement();

  class  Simple_immediate_cover_statementContext : public antlr4::ParserRuleContext {
  public:
    Simple_immediate_cover_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Statement_or_nullContext *statement_or_null();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_immediate_cover_statementContext* simple_immediate_cover_statement();

  class  Deferred_immediate_assertion_statementContext : public antlr4::ParserRuleContext {
  public:
    Deferred_immediate_assertion_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Deferred_immediate_assert_statementContext *deferred_immediate_assert_statement();
    Deferred_immediate_assume_statementContext *deferred_immediate_assume_statement();
    Deferred_immediate_cover_statementContext *deferred_immediate_cover_statement();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Deferred_immediate_assertion_statementContext* deferred_immediate_assertion_statement();

  class  Deferred_immediate_assert_statementContext : public antlr4::ParserRuleContext {
  public:
    Deferred_immediate_assert_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Unsigned_number();
    ExpressionContext *expression();
    Action_blockContext *action_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Deferred_immediate_assert_statementContext* deferred_immediate_assert_statement();

  class  Deferred_immediate_assume_statementContext : public antlr4::ParserRuleContext {
  public:
    Deferred_immediate_assume_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Unsigned_number();
    ExpressionContext *expression();
    Action_blockContext *action_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Deferred_immediate_assume_statementContext* deferred_immediate_assume_statement();

  class  Deferred_immediate_cover_statementContext : public antlr4::ParserRuleContext {
  public:
    Deferred_immediate_cover_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Unsigned_number();
    ExpressionContext *expression();
    Statement_or_nullContext *statement_or_null();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Deferred_immediate_cover_statementContext* deferred_immediate_cover_statement();

  class  Clocking_declarationContext : public antlr4::ParserRuleContext {
  public:
    Clocking_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Clocking_eventContext *clocking_event();
    std::vector<Clocking_identifierContext *> clocking_identifier();
    Clocking_identifierContext* clocking_identifier(size_t i);
    std::vector<Clocking_itemContext *> clocking_item();
    Clocking_itemContext* clocking_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clocking_declarationContext* clocking_declaration();

  class  Clocking_eventContext : public antlr4::ParserRuleContext {
  public:
    Clocking_eventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Event_expressionContext *event_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clocking_eventContext* clocking_event();

  class  Clocking_itemContext : public antlr4::ParserRuleContext {
  public:
    Clocking_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Default_skewContext *default_skew();
    Clocking_directionContext *clocking_direction();
    List_of_clocking_decl_assignContext *list_of_clocking_decl_assign();
    Assertion_item_declarationContext *assertion_item_declaration();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clocking_itemContext* clocking_item();

  class  Default_skewContext : public antlr4::ParserRuleContext {
  public:
    Default_skewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Clocking_skewContext *> clocking_skew();
    Clocking_skewContext* clocking_skew(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Default_skewContext* default_skew();

  class  Clocking_directionContext : public antlr4::ParserRuleContext {
  public:
    Clocking_directionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Clocking_skewContext *> clocking_skew();
    Clocking_skewContext* clocking_skew(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clocking_directionContext* clocking_direction();

  class  List_of_clocking_decl_assignContext : public antlr4::ParserRuleContext {
  public:
    List_of_clocking_decl_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Clocking_decl_assignContext *> clocking_decl_assign();
    Clocking_decl_assignContext* clocking_decl_assign(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_clocking_decl_assignContext* list_of_clocking_decl_assign();

  class  Clocking_decl_assignContext : public antlr4::ParserRuleContext {
  public:
    Clocking_decl_assignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Signal_identifierContext *signal_identifier();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clocking_decl_assignContext* clocking_decl_assign();

  class  Clocking_skewContext : public antlr4::ParserRuleContext {
  public:
    Clocking_skewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Edge_identifierContext *edge_identifier();
    Delay_controlContext *delay_control();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clocking_skewContext* clocking_skew();

  class  Clocking_driveContext : public antlr4::ParserRuleContext {
  public:
    Clocking_driveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Clockvar_expressionContext *clockvar_expression();
    ExpressionContext *expression();
    Cycle_delayContext *cycle_delay();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clocking_driveContext* clocking_drive();

  class  Cycle_delayContext : public antlr4::ParserRuleContext {
  public:
    Cycle_delayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integral_number();
    IdentifierContext *identifier();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cycle_delayContext* cycle_delay();

  class  ClockvarContext : public antlr4::ParserRuleContext {
  public:
    ClockvarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClockvarContext* clockvar();

  class  Clockvar_expressionContext : public antlr4::ParserRuleContext {
  public:
    Clockvar_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClockvarContext *clockvar();
    SelectContext *select();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clockvar_expressionContext* clockvar_expression();

  class  Randsequence_statementContext : public antlr4::ParserRuleContext {
  public:
    Randsequence_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ProductionContext *> production();
    ProductionContext* production(size_t i);
    Production_identifierContext *production_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Randsequence_statementContext* randsequence_statement();

  class  ProductionContext : public antlr4::ParserRuleContext {
  public:
    ProductionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Production_identifierContext *production_identifier();
    std::vector<Rs_ruleContext *> rs_rule();
    Rs_ruleContext* rs_rule(size_t i);
    Data_type_or_voidContext *data_type_or_void();
    Tf_port_listContext *tf_port_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductionContext* production();

  class  Rs_ruleContext : public antlr4::ParserRuleContext {
  public:
    Rs_ruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Rs_production_listContext *rs_production_list();
    Weight_specificationContext *weight_specification();
    Rs_code_blockContext *rs_code_block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rs_ruleContext* rs_rule();

  class  Rs_production_listContext : public antlr4::ParserRuleContext {
  public:
    Rs_production_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rs_prodContext *> rs_prod();
    Rs_prodContext* rs_prod(size_t i);
    std::vector<Production_itemContext *> production_item();
    Production_itemContext* production_item(size_t i);
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rs_production_listContext* rs_production_list();

  class  Weight_specificationContext : public antlr4::ParserRuleContext {
  public:
    Weight_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integral_number();
    Ps_identifierContext *ps_identifier();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Weight_specificationContext* weight_specification();

  class  Rs_code_blockContext : public antlr4::ParserRuleContext {
  public:
    Rs_code_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Data_declarationContext *> data_declaration();
    Data_declarationContext* data_declaration(size_t i);
    std::vector<Statement_or_nullContext *> statement_or_null();
    Statement_or_nullContext* statement_or_null(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rs_code_blockContext* rs_code_block();

  class  Rs_prodContext : public antlr4::ParserRuleContext {
  public:
    Rs_prodContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Production_itemContext *production_item();
    Rs_code_blockContext *rs_code_block();
    Rs_if_elseContext *rs_if_else();
    Rs_repeatContext *rs_repeat();
    Rs_caseContext *rs_case();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rs_prodContext* rs_prod();

  class  Production_itemContext : public antlr4::ParserRuleContext {
  public:
    Production_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Production_identifierContext *production_identifier();
    List_of_argumentsContext *list_of_arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Production_itemContext* production_item();

  class  Rs_if_elseContext : public antlr4::ParserRuleContext {
  public:
    Rs_if_elseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<Production_itemContext *> production_item();
    Production_itemContext* production_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rs_if_elseContext* rs_if_else();

  class  Rs_repeatContext : public antlr4::ParserRuleContext {
  public:
    Rs_repeatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Production_itemContext *production_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rs_repeatContext* rs_repeat();

  class  Rs_caseContext : public antlr4::ParserRuleContext {
  public:
    Rs_caseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Case_expressionContext *case_expression();
    std::vector<Rs_case_itemContext *> rs_case_item();
    Rs_case_itemContext* rs_case_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rs_caseContext* rs_case();

  class  Rs_case_itemContext : public antlr4::ParserRuleContext {
  public:
    Rs_case_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Case_item_expressionContext *> case_item_expression();
    Case_item_expressionContext* case_item_expression(size_t i);
    Production_itemContext *production_item();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rs_case_itemContext* rs_case_item();

  class  Specify_blockContext : public antlr4::ParserRuleContext {
  public:
    Specify_blockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Specify_itemContext *> specify_item();
    Specify_itemContext* specify_item(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Specify_blockContext* specify_block();

  class  Specify_itemContext : public antlr4::ParserRuleContext {
  public:
    Specify_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Specparam_declarationContext *specparam_declaration();
    Pulsestyle_declarationContext *pulsestyle_declaration();
    Showcancelled_declarationContext *showcancelled_declaration();
    Path_declarationContext *path_declaration();
    System_timing_checkContext *system_timing_check();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Specify_itemContext* specify_item();

  class  Pulsestyle_declarationContext : public antlr4::ParserRuleContext {
  public:
    Pulsestyle_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_path_outputsContext *list_of_path_outputs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pulsestyle_declarationContext* pulsestyle_declaration();

  class  Showcancelled_declarationContext : public antlr4::ParserRuleContext {
  public:
    Showcancelled_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_path_outputsContext *list_of_path_outputs();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Showcancelled_declarationContext* showcancelled_declaration();

  class  Path_declarationContext : public antlr4::ParserRuleContext {
  public:
    Path_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_path_declarationContext *simple_path_declaration();
    Edge_sensitive_path_declarationContext *edge_sensitive_path_declaration();
    State_dependent_path_declarationContext *state_dependent_path_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Path_declarationContext* path_declaration();

  class  Simple_path_declarationContext : public antlr4::ParserRuleContext {
  public:
    Simple_path_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parallel_path_descriptionContext *parallel_path_description();
    Path_delay_valueContext *path_delay_value();
    Full_path_descriptionContext *full_path_description();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_path_declarationContext* simple_path_declaration();

  class  Parallel_path_descriptionContext : public antlr4::ParserRuleContext {
  public:
    Parallel_path_descriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Specify_input_terminal_descriptorContext *specify_input_terminal_descriptor();
    Specify_output_terminal_descriptorContext *specify_output_terminal_descriptor();
    Polarity_operatorContext *polarity_operator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parallel_path_descriptionContext* parallel_path_description();

  class  Full_path_descriptionContext : public antlr4::ParserRuleContext {
  public:
    Full_path_descriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_path_inputsContext *list_of_path_inputs();
    List_of_path_outputsContext *list_of_path_outputs();
    Polarity_operatorContext *polarity_operator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Full_path_descriptionContext* full_path_description();

  class  List_of_path_inputsContext : public antlr4::ParserRuleContext {
  public:
    List_of_path_inputsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Specify_input_terminal_descriptorContext *> specify_input_terminal_descriptor();
    Specify_input_terminal_descriptorContext* specify_input_terminal_descriptor(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_path_inputsContext* list_of_path_inputs();

  class  List_of_path_outputsContext : public antlr4::ParserRuleContext {
  public:
    List_of_path_outputsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Specify_output_terminal_descriptorContext *> specify_output_terminal_descriptor();
    Specify_output_terminal_descriptorContext* specify_output_terminal_descriptor(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_path_outputsContext* list_of_path_outputs();

  class  Specify_input_terminal_descriptorContext : public antlr4::ParserRuleContext {
  public:
    Specify_input_terminal_descriptorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Input_identifierContext *input_identifier();
    Constant_range_expressionContext *constant_range_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Specify_input_terminal_descriptorContext* specify_input_terminal_descriptor();

  class  Specify_output_terminal_descriptorContext : public antlr4::ParserRuleContext {
  public:
    Specify_output_terminal_descriptorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_identifierContext *output_identifier();
    Constant_range_expressionContext *constant_range_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Specify_output_terminal_descriptorContext* specify_output_terminal_descriptor();

  class  Input_identifierContext : public antlr4::ParserRuleContext {
  public:
    Input_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Input_port_identifierContext *input_port_identifier();
    Inout_port_identifierContext *inout_port_identifier();
    Interface_identifierContext *interface_identifier();
    Port_identifierContext *port_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_identifierContext* input_identifier();

  class  Output_identifierContext : public antlr4::ParserRuleContext {
  public:
    Output_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Output_port_identifierContext *output_port_identifier();
    Inout_port_identifierContext *inout_port_identifier();
    Interface_identifierContext *interface_identifier();
    Port_identifierContext *port_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Output_identifierContext* output_identifier();

  class  Path_delay_valueContext : public antlr4::ParserRuleContext {
  public:
    Path_delay_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_path_delay_expressionsContext *list_of_path_delay_expressions();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Path_delay_valueContext* path_delay_value();

  class  List_of_path_delay_expressionsContext : public antlr4::ParserRuleContext {
  public:
    List_of_path_delay_expressionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    T_path_delay_expressionContext *t_path_delay_expression();
    Trise_path_delay_expressionContext *trise_path_delay_expression();
    Tfall_path_delay_expressionContext *tfall_path_delay_expression();
    Tz_path_delay_expressionContext *tz_path_delay_expression();
    T01_path_delay_expressionContext *t01_path_delay_expression();
    T10_path_delay_expressionContext *t10_path_delay_expression();
    T0z_path_delay_expressionContext *t0z_path_delay_expression();
    Tz1_path_delay_expressionContext *tz1_path_delay_expression();
    T1z_path_delay_expressionContext *t1z_path_delay_expression();
    Tz0_path_delay_expressionContext *tz0_path_delay_expression();
    T0x_path_delay_expressionContext *t0x_path_delay_expression();
    Tx1_path_delay_expressionContext *tx1_path_delay_expression();
    T1x_path_delay_expressionContext *t1x_path_delay_expression();
    Tx0_path_delay_expressionContext *tx0_path_delay_expression();
    Txz_path_delay_expressionContext *txz_path_delay_expression();
    Tzx_path_delay_expressionContext *tzx_path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_path_delay_expressionsContext* list_of_path_delay_expressions();

  class  T_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    T_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  T_path_delay_expressionContext* t_path_delay_expression();

  class  Trise_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Trise_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Trise_path_delay_expressionContext* trise_path_delay_expression();

  class  Tfall_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Tfall_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tfall_path_delay_expressionContext* tfall_path_delay_expression();

  class  Tz_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Tz_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tz_path_delay_expressionContext* tz_path_delay_expression();

  class  T01_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    T01_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  T01_path_delay_expressionContext* t01_path_delay_expression();

  class  T10_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    T10_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  T10_path_delay_expressionContext* t10_path_delay_expression();

  class  T0z_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    T0z_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  T0z_path_delay_expressionContext* t0z_path_delay_expression();

  class  Tz1_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Tz1_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tz1_path_delay_expressionContext* tz1_path_delay_expression();

  class  T1z_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    T1z_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  T1z_path_delay_expressionContext* t1z_path_delay_expression();

  class  Tz0_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Tz0_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tz0_path_delay_expressionContext* tz0_path_delay_expression();

  class  T0x_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    T0x_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  T0x_path_delay_expressionContext* t0x_path_delay_expression();

  class  Tx1_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Tx1_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tx1_path_delay_expressionContext* tx1_path_delay_expression();

  class  T1x_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    T1x_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  T1x_path_delay_expressionContext* t1x_path_delay_expression();

  class  Tx0_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Tx0_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tx0_path_delay_expressionContext* tx0_path_delay_expression();

  class  Txz_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Txz_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Txz_path_delay_expressionContext* txz_path_delay_expression();

  class  Tzx_path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Tzx_path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Path_delay_expressionContext *path_delay_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tzx_path_delay_expressionContext* tzx_path_delay_expression();

  class  Path_delay_expressionContext : public antlr4::ParserRuleContext {
  public:
    Path_delay_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Path_delay_expressionContext* path_delay_expression();

  class  Edge_sensitive_path_declarationContext : public antlr4::ParserRuleContext {
  public:
    Edge_sensitive_path_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parallel_edge_sensitive_path_descriptionContext *parallel_edge_sensitive_path_description();
    Path_delay_valueContext *path_delay_value();
    Full_edge_sensitive_path_descriptionContext *full_edge_sensitive_path_description();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_sensitive_path_declarationContext* edge_sensitive_path_declaration();

  class  Parallel_edge_sensitive_path_descriptionContext : public antlr4::ParserRuleContext {
  public:
    Parallel_edge_sensitive_path_descriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Specify_input_terminal_descriptorContext *specify_input_terminal_descriptor();
    Specify_output_terminal_descriptorContext *specify_output_terminal_descriptor();
    Data_source_expressionContext *data_source_expression();
    Edge_identifierContext *edge_identifier();
    std::vector<Polarity_operatorContext *> polarity_operator();
    Polarity_operatorContext* polarity_operator(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parallel_edge_sensitive_path_descriptionContext* parallel_edge_sensitive_path_description();

  class  Full_edge_sensitive_path_descriptionContext : public antlr4::ParserRuleContext {
  public:
    Full_edge_sensitive_path_descriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    List_of_path_inputsContext *list_of_path_inputs();
    List_of_path_outputsContext *list_of_path_outputs();
    Data_source_expressionContext *data_source_expression();
    Edge_identifierContext *edge_identifier();
    std::vector<Polarity_operatorContext *> polarity_operator();
    Polarity_operatorContext* polarity_operator(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Full_edge_sensitive_path_descriptionContext* full_edge_sensitive_path_description();

  class  Data_source_expressionContext : public antlr4::ParserRuleContext {
  public:
    Data_source_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_source_expressionContext* data_source_expression();

  class  Edge_identifierContext : public antlr4::ParserRuleContext {
  public:
    Edge_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_identifierContext* edge_identifier();

  class  State_dependent_path_declarationContext : public antlr4::ParserRuleContext {
  public:
    State_dependent_path_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_path_expressionContext *module_path_expression();
    Simple_path_declarationContext *simple_path_declaration();
    Edge_sensitive_path_declarationContext *edge_sensitive_path_declaration();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  State_dependent_path_declarationContext* state_dependent_path_declaration();

  class  Polarity_operatorContext : public antlr4::ParserRuleContext {
  public:
    Polarity_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Polarity_operatorContext* polarity_operator();

  class  System_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    System_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Setup_timing_checkContext *setup_timing_check();
    Hold_timing_checkContext *hold_timing_check();
    Setuphold_timing_checkContext *setuphold_timing_check();
    Recovery_timing_checkContext *recovery_timing_check();
    Removal_timing_checkContext *removal_timing_check();
    Recrem_timing_checkContext *recrem_timing_check();
    Skew_timing_checkContext *skew_timing_check();
    Timeskew_timing_checkContext *timeskew_timing_check();
    Fullskew_timing_checkContext *fullskew_timing_check();
    Period_timing_checkContext *period_timing_check();
    Width_timing_checkContext *width_timing_check();
    Nochange_timing_checkContext *nochange_timing_check();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  System_timing_checkContext* system_timing_check();

  class  Setup_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Setup_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Data_eventContext *data_event();
    Reference_eventContext *reference_event();
    Timing_check_limitContext *timing_check_limit();
    NotifierContext *notifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Setup_timing_checkContext* setup_timing_check();

  class  Hold_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Hold_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    Timing_check_limitContext *timing_check_limit();
    NotifierContext *notifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hold_timing_checkContext* hold_timing_check();

  class  Setuphold_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Setuphold_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    std::vector<Timing_check_limitContext *> timing_check_limit();
    Timing_check_limitContext* timing_check_limit(size_t i);
    NotifierContext *notifier();
    Timestamp_conditionContext *timestamp_condition();
    Timecheck_conditionContext *timecheck_condition();
    Delayed_referenceContext *delayed_reference();
    Delayed_dataContext *delayed_data();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Setuphold_timing_checkContext* setuphold_timing_check();

  class  Recovery_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Recovery_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    Timing_check_limitContext *timing_check_limit();
    NotifierContext *notifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Recovery_timing_checkContext* recovery_timing_check();

  class  Removal_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Removal_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    Timing_check_limitContext *timing_check_limit();
    NotifierContext *notifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Removal_timing_checkContext* removal_timing_check();

  class  Recrem_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Recrem_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    std::vector<Timing_check_limitContext *> timing_check_limit();
    Timing_check_limitContext* timing_check_limit(size_t i);
    NotifierContext *notifier();
    Timestamp_conditionContext *timestamp_condition();
    Timecheck_conditionContext *timecheck_condition();
    Delayed_referenceContext *delayed_reference();
    Delayed_dataContext *delayed_data();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Recrem_timing_checkContext* recrem_timing_check();

  class  Skew_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Skew_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    Timing_check_limitContext *timing_check_limit();
    NotifierContext *notifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Skew_timing_checkContext* skew_timing_check();

  class  Timeskew_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Timeskew_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    Timing_check_limitContext *timing_check_limit();
    NotifierContext *notifier();
    Event_based_flagContext *event_based_flag();
    Remain_active_flagContext *remain_active_flag();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Timeskew_timing_checkContext* timeskew_timing_check();

  class  Fullskew_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Fullskew_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    std::vector<Timing_check_limitContext *> timing_check_limit();
    Timing_check_limitContext* timing_check_limit(size_t i);
    NotifierContext *notifier();
    Event_based_flagContext *event_based_flag();
    Remain_active_flagContext *remain_active_flag();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Fullskew_timing_checkContext* fullskew_timing_check();

  class  Period_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Period_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Controlled_reference_eventContext *controlled_reference_event();
    Timing_check_limitContext *timing_check_limit();
    NotifierContext *notifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Period_timing_checkContext* period_timing_check();

  class  Width_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Width_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Controlled_reference_eventContext *controlled_reference_event();
    Timing_check_limitContext *timing_check_limit();
    ThresholdContext *threshold();
    NotifierContext *notifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Width_timing_checkContext* width_timing_check();

  class  Nochange_timing_checkContext : public antlr4::ParserRuleContext {
  public:
    Nochange_timing_checkContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Reference_eventContext *reference_event();
    Data_eventContext *data_event();
    Start_edge_offsetContext *start_edge_offset();
    End_edge_offsetContext *end_edge_offset();
    NotifierContext *notifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Nochange_timing_checkContext* nochange_timing_check();

  class  Timecheck_conditionContext : public antlr4::ParserRuleContext {
  public:
    Timecheck_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mintypmax_expressionContext *mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Timecheck_conditionContext* timecheck_condition();

  class  Controlled_reference_eventContext : public antlr4::ParserRuleContext {
  public:
    Controlled_reference_eventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Controlled_timing_check_eventContext *controlled_timing_check_event();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Controlled_reference_eventContext* controlled_reference_event();

  class  Data_eventContext : public antlr4::ParserRuleContext {
  public:
    Data_eventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Timing_check_eventContext *timing_check_event();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Data_eventContext* data_event();

  class  Delayed_dataContext : public antlr4::ParserRuleContext {
  public:
    Delayed_dataContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Terminal_identifierContext *terminal_identifier();
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delayed_dataContext* delayed_data();

  class  Delayed_referenceContext : public antlr4::ParserRuleContext {
  public:
    Delayed_referenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Terminal_identifierContext *terminal_identifier();
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Delayed_referenceContext* delayed_reference();

  class  End_edge_offsetContext : public antlr4::ParserRuleContext {
  public:
    End_edge_offsetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mintypmax_expressionContext *mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  End_edge_offsetContext* end_edge_offset();

  class  Event_based_flagContext : public antlr4::ParserRuleContext {
  public:
    Event_based_flagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Event_based_flagContext* event_based_flag();

  class  NotifierContext : public antlr4::ParserRuleContext {
  public:
    NotifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_identifierContext *variable_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NotifierContext* notifier();

  class  Reference_eventContext : public antlr4::ParserRuleContext {
  public:
    Reference_eventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Timing_check_eventContext *timing_check_event();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Reference_eventContext* reference_event();

  class  Remain_active_flagContext : public antlr4::ParserRuleContext {
  public:
    Remain_active_flagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Remain_active_flagContext* remain_active_flag();

  class  Timestamp_conditionContext : public antlr4::ParserRuleContext {
  public:
    Timestamp_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mintypmax_expressionContext *mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Timestamp_conditionContext* timestamp_condition();

  class  Start_edge_offsetContext : public antlr4::ParserRuleContext {
  public:
    Start_edge_offsetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mintypmax_expressionContext *mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Start_edge_offsetContext* start_edge_offset();

  class  ThresholdContext : public antlr4::ParserRuleContext {
  public:
    ThresholdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ThresholdContext* threshold();

  class  Timing_check_limitContext : public antlr4::ParserRuleContext {
  public:
    Timing_check_limitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Timing_check_limitContext* timing_check_limit();

  class  Timing_check_eventContext : public antlr4::ParserRuleContext {
  public:
    Timing_check_eventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Specify_terminal_descriptorContext *specify_terminal_descriptor();
    Timing_check_event_controlContext *timing_check_event_control();
    Timing_check_conditionContext *timing_check_condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Timing_check_eventContext* timing_check_event();

  class  Controlled_timing_check_eventContext : public antlr4::ParserRuleContext {
  public:
    Controlled_timing_check_eventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Timing_check_event_controlContext *timing_check_event_control();
    Specify_terminal_descriptorContext *specify_terminal_descriptor();
    Timing_check_conditionContext *timing_check_condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Controlled_timing_check_eventContext* controlled_timing_check_event();

  class  Timing_check_event_controlContext : public antlr4::ParserRuleContext {
  public:
    Timing_check_event_controlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Edge_control_specifierContext *edge_control_specifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Timing_check_event_controlContext* timing_check_event_control();

  class  Specify_terminal_descriptorContext : public antlr4::ParserRuleContext {
  public:
    Specify_terminal_descriptorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Specify_input_terminal_descriptorContext *specify_input_terminal_descriptor();
    Specify_output_terminal_descriptorContext *specify_output_terminal_descriptor();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Specify_terminal_descriptorContext* specify_terminal_descriptor();

  class  Edge_control_specifierContext : public antlr4::ParserRuleContext {
  public:
    Edge_control_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Edge_descriptorContext *> edge_descriptor();
    Edge_descriptorContext* edge_descriptor(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_control_specifierContext* edge_control_specifier();

  class  Edge_descriptorContext : public antlr4::ParserRuleContext {
  public:
    Edge_descriptorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Unsigned_number();
    antlr4::tree::TerminalNode *Simple_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_descriptorContext* edge_descriptor();

  class  Timing_check_conditionContext : public antlr4::ParserRuleContext {
  public:
    Timing_check_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Scalar_timing_check_conditionContext *scalar_timing_check_condition();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Timing_check_conditionContext* timing_check_condition();

  class  Scalar_timing_check_conditionContext : public antlr4::ParserRuleContext {
  public:
    Scalar_timing_check_conditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Scalar_constantContext *scalar_constant();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Scalar_timing_check_conditionContext* scalar_timing_check_condition();

  class  Scalar_constantContext : public antlr4::ParserRuleContext {
  public:
    Scalar_constantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integral_number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Scalar_constantContext* scalar_constant();

  class  ConcatenationContext : public antlr4::ParserRuleContext {
  public:
    ConcatenationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConcatenationContext* concatenation();

  class  Constant_concatenationContext : public antlr4::ParserRuleContext {
  public:
    Constant_concatenationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_concatenationContext* constant_concatenation();

  class  Constant_multiple_concatenationContext : public antlr4::ParserRuleContext {
  public:
    Constant_multiple_concatenationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();
    Constant_concatenationContext *constant_concatenation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_multiple_concatenationContext* constant_multiple_concatenation();

  class  Module_path_concatenationContext : public antlr4::ParserRuleContext {
  public:
    Module_path_concatenationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Module_path_expressionContext *> module_path_expression();
    Module_path_expressionContext* module_path_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_path_concatenationContext* module_path_concatenation();

  class  Module_path_multiple_concatenationContext : public antlr4::ParserRuleContext {
  public:
    Module_path_multiple_concatenationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();
    Module_path_concatenationContext *module_path_concatenation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_path_multiple_concatenationContext* module_path_multiple_concatenation();

  class  Multiple_concatenationContext : public antlr4::ParserRuleContext {
  public:
    Multiple_concatenationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    ConcatenationContext *concatenation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Multiple_concatenationContext* multiple_concatenation();

  class  Streaming_concatenationContext : public antlr4::ParserRuleContext {
  public:
    Streaming_concatenationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Stream_operatorContext *stream_operator();
    Stream_concatenationContext *stream_concatenation();
    Slice_sizeContext *slice_size();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Streaming_concatenationContext* streaming_concatenation();

  class  Stream_operatorContext : public antlr4::ParserRuleContext {
  public:
    Stream_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Stream_operatorContext* stream_operator();

  class  Slice_sizeContext : public antlr4::ParserRuleContext {
  public:
    Slice_sizeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Simple_typeContext *simple_type();
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Slice_sizeContext* slice_size();

  class  Stream_concatenationContext : public antlr4::ParserRuleContext {
  public:
    Stream_concatenationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Stream_expressionContext *> stream_expression();
    Stream_expressionContext* stream_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Stream_concatenationContext* stream_concatenation();

  class  Stream_expressionContext : public antlr4::ParserRuleContext {
  public:
    Stream_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Array_range_expressionContext *array_range_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Stream_expressionContext* stream_expression();

  class  Array_range_expressionContext : public antlr4::ParserRuleContext {
  public:
    Array_range_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_range_expressionContext* array_range_expression();

  class  Empty_queueContext : public antlr4::ParserRuleContext {
  public:
    Empty_queueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Empty_queueContext* empty_queue();

  class  Constant_function_callContext : public antlr4::ParserRuleContext {
  public:
    Constant_function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_subroutine_callContext *function_subroutine_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_function_callContext* constant_function_call();

  class  Tf_callContext : public antlr4::ParserRuleContext {
  public:
    Tf_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_or_hierarchical_tf_identifierContext *ps_or_hierarchical_tf_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    List_of_argumentsContext *list_of_arguments();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tf_callContext* tf_call();

  class  System_tf_callContext : public antlr4::ParserRuleContext {
  public:
    System_tf_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *System_tf_identifier();
    List_of_argumentsContext *list_of_arguments();
    Data_typeContext *data_type();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  System_tf_callContext* system_tf_call();

  class  Function_subroutine_callContext : public antlr4::ParserRuleContext {
  public:
    Function_subroutine_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Subroutine_callContext *subroutine_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_subroutine_callContext* function_subroutine_call();

  class  Subroutine_callContext : public antlr4::ParserRuleContext {
  public:
    Subroutine_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Tf_callContext *tf_call();
    System_tf_callContext *system_tf_call();
    Randomize_callContext *randomize_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Subroutine_callContext* subroutine_call();

  class  Method_callContext : public antlr4::ParserRuleContext {
  public:
    Method_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Method_call_rootContext *method_call_root();
    Method_call_bodyContext *method_call_body();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_callContext* method_call();

  class  Method_call_rootContext : public antlr4::ParserRuleContext {
  public:
    Method_call_rootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    Implicit_class_handleContext *implicit_class_handle();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_call_rootContext* method_call_root();

  class  List_of_argumentsContext : public antlr4::ParserRuleContext {
  public:
    List_of_argumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  List_of_argumentsContext* list_of_arguments();

  class  Method_call_bodyContext : public antlr4::ParserRuleContext {
  public:
    Method_call_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Method_identifierContext *method_identifier();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    List_of_argumentsContext *list_of_arguments();
    Built_in_method_callContext *built_in_method_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_call_bodyContext* method_call_body();

  class  Built_in_method_callContext : public antlr4::ParserRuleContext {
  public:
    Built_in_method_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Array_manipulation_callContext *array_manipulation_call();
    Randomize_callContext *randomize_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Built_in_method_callContext* built_in_method_call();

  class  Array_manipulation_callContext : public antlr4::ParserRuleContext {
  public:
    Array_manipulation_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Array_method_nameContext *array_method_name();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    List_of_argumentsContext *list_of_arguments();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_manipulation_callContext* array_manipulation_call();

  class  Randomize_callContext : public antlr4::ParserRuleContext {
  public:
    Randomize_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Constraint_blockContext *constraint_block();
    Variable_identifier_listContext *variable_identifier_list();
    Identifier_listContext *identifier_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Randomize_callContext* randomize_call();

  class  Array_method_nameContext : public antlr4::ParserRuleContext {
  public:
    Array_method_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Method_identifierContext *method_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_method_nameContext* array_method_name();

  class  Inc_or_dec_expressionContext : public antlr4::ParserRuleContext {
  public:
    Inc_or_dec_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Inc_or_dec_operatorContext *inc_or_dec_operator();
    Variable_lvalueContext *variable_lvalue();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inc_or_dec_expressionContext* inc_or_dec_expression();

  class  Conditional_expressionContext : public antlr4::ParserRuleContext {
  public:
    Conditional_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Cond_predicateContext *cond_predicate();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Conditional_expressionContext* conditional_expression();

  class  Constant_expressionContext : public antlr4::ParserRuleContext {
  public:
    Constant_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_operatorContext *unary_operator();
    Constant_primaryContext *constant_primary();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);
    Binary_operatorContext *binary_operator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_expressionContext* constant_expression();
  Constant_expressionContext* constant_expression(int precedence);
  class  Constant_mintypmax_expressionContext : public antlr4::ParserRuleContext {
  public:
    Constant_mintypmax_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_mintypmax_expressionContext* constant_mintypmax_expression();

  class  Constant_param_expressionContext : public antlr4::ParserRuleContext {
  public:
    Constant_param_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();
    Data_typeContext *data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_param_expressionContext* constant_param_expression();

  class  Param_expressionContext : public antlr4::ParserRuleContext {
  public:
    Param_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Mintypmax_expressionContext *mintypmax_expression();
    Data_typeContext *data_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Param_expressionContext* param_expression();

  class  Constant_range_expressionContext : public antlr4::ParserRuleContext {
  public:
    Constant_range_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();
    Constant_part_select_rangeContext *constant_part_select_range();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_range_expressionContext* constant_range_expression();

  class  Constant_part_select_rangeContext : public antlr4::ParserRuleContext {
  public:
    Constant_part_select_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_rangeContext *constant_range();
    Constant_indexed_rangeContext *constant_indexed_range();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_part_select_rangeContext* constant_part_select_range();

  class  Constant_rangeContext : public antlr4::ParserRuleContext {
  public:
    Constant_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_rangeContext* constant_range();

  class  Constant_indexed_rangeContext : public antlr4::ParserRuleContext {
  public:
    Constant_indexed_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_indexed_rangeContext* constant_indexed_range();

  class  Expression_cond_or_insideContext : public antlr4::ParserRuleContext {
  public:
    Expression_cond_or_insideContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    PatternContext *pattern();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Open_range_listContext *open_range_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expression_cond_or_insideContext* expression_cond_or_inside();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryContext *primary();
    Unary_operatorContext *unary_operator();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Inc_or_dec_expressionContext *inc_or_dec_expression();
    Operator_assignmentContext *operator_assignment();
    Tagged_union_expressionContext *tagged_union_expression();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    Binary_operatorContext *binary_operator();
    Expression_cond_or_insideContext *expression_cond_or_inside();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  Tagged_union_expressionContext : public antlr4::ParserRuleContext {
  public:
    Tagged_union_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Member_identifierContext *member_identifier();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tagged_union_expressionContext* tagged_union_expression();

  class  Inside_expressionContext : public antlr4::ParserRuleContext {
  public:
    Inside_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Open_range_listContext *open_range_list();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inside_expressionContext* inside_expression();

  class  Value_rangeContext : public antlr4::ParserRuleContext {
  public:
    Value_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_rangeContext* value_range();

  class  Mintypmax_expressionContext : public antlr4::ParserRuleContext {
  public:
    Mintypmax_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mintypmax_expressionContext* mintypmax_expression();

  class  Module_path_conditional_expressionContext : public antlr4::ParserRuleContext {
  public:
    Module_path_conditional_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Module_path_expressionContext *> module_path_expression();
    Module_path_expressionContext* module_path_expression(size_t i);
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_path_conditional_expressionContext* module_path_conditional_expression();

  class  Module_path_expressionContext : public antlr4::ParserRuleContext {
  public:
    Module_path_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Module_path_primaryContext *module_path_primary();
    Unary_module_path_operatorContext *unary_module_path_operator();
    std::vector<Attribute_instanceContext *> attribute_instance();
    Attribute_instanceContext* attribute_instance(size_t i);
    Module_path_conditional_expressionContext *module_path_conditional_expression();
    std::vector<Module_path_expressionContext *> module_path_expression();
    Module_path_expressionContext* module_path_expression(size_t i);
    Binary_module_path_operatorContext *binary_module_path_operator();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_path_expressionContext* module_path_expression();
  Module_path_expressionContext* module_path_expression(int precedence);
  class  Module_path_mintypmax_expressionContext : public antlr4::ParserRuleContext {
  public:
    Module_path_mintypmax_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Module_path_expressionContext *> module_path_expression();
    Module_path_expressionContext* module_path_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_path_mintypmax_expressionContext* module_path_mintypmax_expression();

  class  Part_select_rangeContext : public antlr4::ParserRuleContext {
  public:
    Part_select_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_rangeContext *constant_range();
    Indexed_rangeContext *indexed_range();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Part_select_rangeContext* part_select_range();

  class  Indexed_rangeContext : public antlr4::ParserRuleContext {
  public:
    Indexed_rangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Indexed_rangeContext* indexed_range();

  class  Genvar_expressionContext : public antlr4::ParserRuleContext {
  public:
    Genvar_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Genvar_expressionContext* genvar_expression();

  class  Constant_primaryContext : public antlr4::ParserRuleContext {
  public:
    Constant_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_parameter_identifierContext *ps_parameter_identifier();
    Constant_selectContext *constant_select();
    Specparam_identifierContext *specparam_identifier();
    Constant_range_expressionContext *constant_range_expression();
    Genvar_identifierContext *genvar_identifier();
    Formal_port_identifierContext *formal_port_identifier();
    Enum_identifierContext *enum_identifier();
    Package_scopeContext *package_scope();
    Class_scopeContext *class_scope();
    Constant_concatenationContext *constant_concatenation();
    Constant_multiple_concatenationContext *constant_multiple_concatenation();
    Constant_function_callContext *constant_function_call();
    Constant_let_expressionContext *constant_let_expression();
    Constant_mintypmax_expressionContext *constant_mintypmax_expression();
    Constant_castContext *constant_cast();
    Constant_assignment_pattern_expressionContext *constant_assignment_pattern_expression();
    Type_referenceContext *type_reference();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_primaryContext* constant_primary();

  class  Module_path_primaryContext : public antlr4::ParserRuleContext {
  public:
    Module_path_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    IdentifierContext *identifier();
    Module_path_concatenationContext *module_path_concatenation();
    Module_path_multiple_concatenationContext *module_path_multiple_concatenation();
    Function_subroutine_callContext *function_subroutine_call();
    Module_path_mintypmax_expressionContext *module_path_mintypmax_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_path_primaryContext* module_path_primary();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_literalContext *primary_literal();
    Hierarchical_identifierContext *hierarchical_identifier();
    SelectContext *select();
    Class_qualifierContext *class_qualifier();
    Package_scopeContext *package_scope();
    Empty_queueContext *empty_queue();
    ConcatenationContext *concatenation();
    Range_expressionContext *range_expression();
    Multiple_concatenationContext *multiple_concatenation();
    Function_subroutine_callContext *function_subroutine_call();
    Let_expressionContext *let_expression();
    Mintypmax_expressionContext *mintypmax_expression();
    CastContext *cast();
    Assignment_pattern_expressionContext *assignment_pattern_expression();
    Streaming_concatenationContext *streaming_concatenation();
    Sequence_method_callContext *sequence_method_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();

  class  Class_qualifierContext : public antlr4::ParserRuleContext {
  public:
    Class_qualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Implicit_class_handleContext *implicit_class_handle();
    Class_scopeContext *class_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_qualifierContext* class_qualifier();

  class  Range_expressionContext : public antlr4::ParserRuleContext {
  public:
    Range_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Part_select_rangeContext *part_select_range();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Range_expressionContext* range_expression();

  class  Primary_literalContext : public antlr4::ParserRuleContext {
  public:
    Primary_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberContext *number();
    Time_literalContext *time_literal();
    antlr4::tree::TerminalNode *Unbased_unsized_literal();
    antlr4::tree::TerminalNode *String_literal();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Primary_literalContext* primary_literal();

  class  Time_literalContext : public antlr4::ParserRuleContext {
  public:
    Time_literalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Unsigned_number();
    Time_unitContext *time_unit();
    antlr4::tree::TerminalNode *Fixed_point_number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Time_literalContext* time_literal();

  class  Time_unitContext : public antlr4::ParserRuleContext {
  public:
    Time_unitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Time_unitContext* time_unit();

  class  Implicit_class_handleContext : public antlr4::ParserRuleContext {
  public:
    Implicit_class_handleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Implicit_class_handleContext* implicit_class_handle();

  class  Bit_selectContext : public antlr4::ParserRuleContext {
  public:
    Bit_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bit_selectContext* bit_select();

  class  SelectContext : public antlr4::ParserRuleContext {
  public:
    SelectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Bit_selectContext *> bit_select();
    Bit_selectContext* bit_select(size_t i);
    std::vector<Member_identifierContext *> member_identifier();
    Member_identifierContext* member_identifier(size_t i);
    Part_select_rangeContext *part_select_range();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectContext* select();

  class  Nonrange_selectContext : public antlr4::ParserRuleContext {
  public:
    Nonrange_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Bit_selectContext *> bit_select();
    Bit_selectContext* bit_select(size_t i);
    std::vector<Member_identifierContext *> member_identifier();
    Member_identifierContext* member_identifier(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Nonrange_selectContext* nonrange_select();

  class  Constant_bit_selectContext : public antlr4::ParserRuleContext {
  public:
    Constant_bit_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_bit_selectContext* constant_bit_select();

  class  Constant_selectContext : public antlr4::ParserRuleContext {
  public:
    Constant_selectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_bit_selectContext *> constant_bit_select();
    Constant_bit_selectContext* constant_bit_select(size_t i);
    std::vector<Member_identifierContext *> member_identifier();
    Member_identifierContext* member_identifier(size_t i);
    Constant_part_select_rangeContext *constant_part_select_range();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_selectContext* constant_select();

  class  Constant_castContext : public antlr4::ParserRuleContext {
  public:
    Constant_castContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Casting_type_reducedContext *casting_type_reduced();
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_castContext* constant_cast();

  class  Constant_let_expressionContext : public antlr4::ParserRuleContext {
  public:
    Constant_let_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Let_expressionContext *let_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_let_expressionContext* constant_let_expression();

  class  CastContext : public antlr4::ParserRuleContext {
  public:
    CastContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Casting_typeContext *casting_type();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CastContext* cast();

  class  Net_lvalueContext : public antlr4::ParserRuleContext {
  public:
    Net_lvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Ps_or_hierarchical_net_identifierContext *ps_or_hierarchical_net_identifier();
    Constant_selectContext *constant_select();
    std::vector<Net_lvalueContext *> net_lvalue();
    Net_lvalueContext* net_lvalue(size_t i);
    Assignment_pattern_net_lvalueContext *assignment_pattern_net_lvalue();
    Assignment_pattern_expression_typeContext *assignment_pattern_expression_type();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_lvalueContext* net_lvalue();

  class  Variable_lvalueContext : public antlr4::ParserRuleContext {
  public:
    Variable_lvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_variable_identifierContext *hierarchical_variable_identifier();
    SelectContext *select();
    Implicit_class_handleContext *implicit_class_handle();
    Package_scopeContext *package_scope();
    std::vector<Variable_lvalueContext *> variable_lvalue();
    Variable_lvalueContext* variable_lvalue(size_t i);
    Assignment_pattern_variable_lvalueContext *assignment_pattern_variable_lvalue();
    Assignment_pattern_expression_typeContext *assignment_pattern_expression_type();
    Streaming_concatenationContext *streaming_concatenation();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_lvalueContext* variable_lvalue();

  class  Nonrange_variable_lvalueContext : public antlr4::ParserRuleContext {
  public:
    Nonrange_variable_lvalueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_variable_identifierContext *hierarchical_variable_identifier();
    Nonrange_selectContext *nonrange_select();
    Implicit_class_handleContext *implicit_class_handle();
    Package_scopeContext *package_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Nonrange_variable_lvalueContext* nonrange_variable_lvalue();

  class  Unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_operatorContext* unary_operator();

  class  Binary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Binary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_operatorContext* binary_operator();

  class  Inc_or_dec_operatorContext : public antlr4::ParserRuleContext {
  public:
    Inc_or_dec_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inc_or_dec_operatorContext* inc_or_dec_operator();

  class  Unary_module_path_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_module_path_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_module_path_operatorContext* unary_module_path_operator();

  class  Binary_module_path_operatorContext : public antlr4::ParserRuleContext {
  public:
    Binary_module_path_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Binary_module_path_operatorContext* binary_module_path_operator();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integral_number();
    antlr4::tree::TerminalNode *Real_number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  Attribute_instanceContext : public antlr4::ParserRuleContext {
  public:
    Attribute_instanceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Attr_specContext *> attr_spec();
    Attr_specContext* attr_spec(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attribute_instanceContext* attribute_instance();

  class  Attr_specContext : public antlr4::ParserRuleContext {
  public:
    Attr_specContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Attr_nameContext *attr_name();
    Constant_expressionContext *constant_expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attr_specContext* attr_spec();

  class  Attr_nameContext : public antlr4::ParserRuleContext {
  public:
    Attr_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Attr_nameContext* attr_name();

  class  Array_identifierContext : public antlr4::ParserRuleContext {
  public:
    Array_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_identifierContext* array_identifier();

  class  Block_identifierContext : public antlr4::ParserRuleContext {
  public:
    Block_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_identifierContext* block_identifier();

  class  Bin_identifierContext : public antlr4::ParserRuleContext {
  public:
    Bin_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bin_identifierContext* bin_identifier();

  class  C_identifierContext : public antlr4::ParserRuleContext {
  public:
    C_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Simple_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  C_identifierContext* c_identifier();

  class  Cell_identifierContext : public antlr4::ParserRuleContext {
  public:
    Cell_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cell_identifierContext* cell_identifier();

  class  Checker_identifierContext : public antlr4::ParserRuleContext {
  public:
    Checker_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Checker_identifierContext* checker_identifier();

  class  Class_identifierContext : public antlr4::ParserRuleContext {
  public:
    Class_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_identifierContext* class_identifier();

  class  Class_variable_identifierContext : public antlr4::ParserRuleContext {
  public:
    Class_variable_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_identifierContext *variable_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_variable_identifierContext* class_variable_identifier();

  class  Clocking_identifierContext : public antlr4::ParserRuleContext {
  public:
    Clocking_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Clocking_identifierContext* clocking_identifier();

  class  Config_identifierContext : public antlr4::ParserRuleContext {
  public:
    Config_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Config_identifierContext* config_identifier();

  class  Const_identifierContext : public antlr4::ParserRuleContext {
  public:
    Const_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_identifierContext* const_identifier();

  class  Constraint_identifierContext : public antlr4::ParserRuleContext {
  public:
    Constraint_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constraint_identifierContext* constraint_identifier();

  class  Covergroup_identifierContext : public antlr4::ParserRuleContext {
  public:
    Covergroup_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Covergroup_identifierContext* covergroup_identifier();

  class  Covergroup_variable_identifierContext : public antlr4::ParserRuleContext {
  public:
    Covergroup_variable_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_identifierContext *variable_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Covergroup_variable_identifierContext* covergroup_variable_identifier();

  class  Cover_point_identifierContext : public antlr4::ParserRuleContext {
  public:
    Cover_point_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cover_point_identifierContext* cover_point_identifier();

  class  Cross_identifierContext : public antlr4::ParserRuleContext {
  public:
    Cross_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cross_identifierContext* cross_identifier();

  class  Dynamic_array_variable_identifierContext : public antlr4::ParserRuleContext {
  public:
    Dynamic_array_variable_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Variable_identifierContext *variable_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Dynamic_array_variable_identifierContext* dynamic_array_variable_identifier();

  class  Enum_identifierContext : public antlr4::ParserRuleContext {
  public:
    Enum_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Enum_identifierContext* enum_identifier();

  class  Formal_identifierContext : public antlr4::ParserRuleContext {
  public:
    Formal_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Formal_identifierContext* formal_identifier();

  class  Formal_port_identifierContext : public antlr4::ParserRuleContext {
  public:
    Formal_port_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Formal_port_identifierContext* formal_port_identifier();

  class  Function_identifierContext : public antlr4::ParserRuleContext {
  public:
    Function_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_identifierContext* function_identifier();

  class  Generate_block_identifierContext : public antlr4::ParserRuleContext {
  public:
    Generate_block_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Generate_block_identifierContext* generate_block_identifier();

  class  Genvar_identifierContext : public antlr4::ParserRuleContext {
  public:
    Genvar_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Genvar_identifierContext* genvar_identifier();

  class  Hierarchical_array_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_array_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_array_identifierContext* hierarchical_array_identifier();

  class  Hierarchical_block_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_block_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_block_identifierContext* hierarchical_block_identifier();

  class  Hierarchical_event_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_event_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_event_identifierContext* hierarchical_event_identifier();

  class  Hierarchical_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<IdentifierContext *> identifier();
    IdentifierContext* identifier(size_t i);
    std::vector<Constant_bit_selectContext *> constant_bit_select();
    Constant_bit_selectContext* constant_bit_select(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_identifierContext* hierarchical_identifier();

  class  Hierarchical_net_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_net_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_net_identifierContext* hierarchical_net_identifier();

  class  Hierarchical_parameter_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_parameter_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_parameter_identifierContext* hierarchical_parameter_identifier();

  class  Hierarchical_property_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_property_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_property_identifierContext* hierarchical_property_identifier();

  class  Hierarchical_sequence_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_sequence_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_sequence_identifierContext* hierarchical_sequence_identifier();

  class  Hierarchical_task_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_task_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_task_identifierContext* hierarchical_task_identifier();

  class  Hierarchical_tf_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_tf_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_tf_identifierContext* hierarchical_tf_identifier();

  class  Hierarchical_variable_identifierContext : public antlr4::ParserRuleContext {
  public:
    Hierarchical_variable_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_identifierContext *hierarchical_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Hierarchical_variable_identifierContext* hierarchical_variable_identifier();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Simple_identifier();
    antlr4::tree::TerminalNode *Escaped_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  Index_variable_identifierContext : public antlr4::ParserRuleContext {
  public:
    Index_variable_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Index_variable_identifierContext* index_variable_identifier();

  class  Interface_identifierContext : public antlr4::ParserRuleContext {
  public:
    Interface_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_identifierContext* interface_identifier();

  class  Interface_instance_identifierContext : public antlr4::ParserRuleContext {
  public:
    Interface_instance_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Interface_instance_identifierContext* interface_instance_identifier();

  class  Inout_port_identifierContext : public antlr4::ParserRuleContext {
  public:
    Inout_port_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Inout_port_identifierContext* inout_port_identifier();

  class  Input_port_identifierContext : public antlr4::ParserRuleContext {
  public:
    Input_port_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Input_port_identifierContext* input_port_identifier();

  class  Instance_identifierContext : public antlr4::ParserRuleContext {
  public:
    Instance_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Instance_identifierContext* instance_identifier();

  class  Library_identifierContext : public antlr4::ParserRuleContext {
  public:
    Library_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Library_identifierContext* library_identifier();

  class  Member_identifierContext : public antlr4::ParserRuleContext {
  public:
    Member_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Member_identifierContext* member_identifier();

  class  Method_identifierContext : public antlr4::ParserRuleContext {
  public:
    Method_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Method_identifierContext* method_identifier();

  class  Modport_identifierContext : public antlr4::ParserRuleContext {
  public:
    Modport_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Modport_identifierContext* modport_identifier();

  class  Module_identifierContext : public antlr4::ParserRuleContext {
  public:
    Module_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_identifierContext* module_identifier();

  class  Net_identifierContext : public antlr4::ParserRuleContext {
  public:
    Net_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_identifierContext* net_identifier();

  class  Net_type_identifierContext : public antlr4::ParserRuleContext {
  public:
    Net_type_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Net_type_identifierContext* net_type_identifier();

  class  Output_port_identifierContext : public antlr4::ParserRuleContext {
  public:
    Output_port_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Output_port_identifierContext* output_port_identifier();

  class  Package_identifierContext : public antlr4::ParserRuleContext {
  public:
    Package_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Package_identifierContext* package_identifier();

  class  Package_scopeContext : public antlr4::ParserRuleContext {
  public:
    Package_scopeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Package_identifierContext *package_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Package_scopeContext* package_scope();

  class  Parameter_identifierContext : public antlr4::ParserRuleContext {
  public:
    Parameter_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parameter_identifierContext* parameter_identifier();

  class  Port_identifierContext : public antlr4::ParserRuleContext {
  public:
    Port_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Port_identifierContext* port_identifier();

  class  Production_identifierContext : public antlr4::ParserRuleContext {
  public:
    Production_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Production_identifierContext* production_identifier();

  class  Program_identifierContext : public antlr4::ParserRuleContext {
  public:
    Program_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_identifierContext* program_identifier();

  class  Property_identifierContext : public antlr4::ParserRuleContext {
  public:
    Property_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Property_identifierContext* property_identifier();

  class  Ps_class_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_class_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Class_identifierContext *class_identifier();
    Package_scopeContext *package_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_class_identifierContext* ps_class_identifier();

  class  Ps_covergroup_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_covergroup_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Covergroup_identifierContext *covergroup_identifier();
    Package_scopeContext *package_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_covergroup_identifierContext* ps_covergroup_identifier();

  class  Ps_checker_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_checker_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Checker_identifierContext *checker_identifier();
    Package_scopeContext *package_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_checker_identifierContext* ps_checker_identifier();

  class  Ps_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Package_scopeContext *package_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_identifierContext* ps_identifier();

  class  Ps_or_hierarchical_array_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_or_hierarchical_array_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Hierarchical_array_identifierContext *hierarchical_array_identifier();
    Implicit_class_handleContext *implicit_class_handle();
    Class_scopeContext *class_scope();
    Package_scopeContext *package_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_or_hierarchical_array_identifierContext* ps_or_hierarchical_array_identifier();

  class  Ps_or_hierarchical_net_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_or_hierarchical_net_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Net_identifierContext *net_identifier();
    Package_scopeContext *package_scope();
    Hierarchical_net_identifierContext *hierarchical_net_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_or_hierarchical_net_identifierContext* ps_or_hierarchical_net_identifier();

  class  Ps_or_hierarchical_property_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_or_hierarchical_property_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Property_identifierContext *property_identifier();
    Package_scopeContext *package_scope();
    Hierarchical_property_identifierContext *hierarchical_property_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_or_hierarchical_property_identifierContext* ps_or_hierarchical_property_identifier();

  class  Ps_or_hierarchical_sequence_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_or_hierarchical_sequence_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Sequence_identifierContext *sequence_identifier();
    Package_scopeContext *package_scope();
    Hierarchical_sequence_identifierContext *hierarchical_sequence_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_or_hierarchical_sequence_identifierContext* ps_or_hierarchical_sequence_identifier();

  class  Ps_or_hierarchical_tf_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_or_hierarchical_tf_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Tf_identifierContext *tf_identifier();
    Package_scopeContext *package_scope();
    Hierarchical_tf_identifierContext *hierarchical_tf_identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_or_hierarchical_tf_identifierContext* ps_or_hierarchical_tf_identifier();

  class  Ps_parameter_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_parameter_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Parameter_identifierContext *parameter_identifier();
    Package_scopeContext *package_scope();
    Class_scopeContext *class_scope();
    std::vector<Generate_block_identifierContext *> generate_block_identifier();
    Generate_block_identifierContext* generate_block_identifier(size_t i);
    std::vector<Constant_expressionContext *> constant_expression();
    Constant_expressionContext* constant_expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_parameter_identifierContext* ps_parameter_identifier();

  class  Ps_type_identifierContext : public antlr4::ParserRuleContext {
  public:
    Ps_type_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_identifierContext *type_identifier();
    Package_scopeContext *package_scope();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ps_type_identifierContext* ps_type_identifier();

  class  Sequence_identifierContext : public antlr4::ParserRuleContext {
  public:
    Sequence_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Sequence_identifierContext* sequence_identifier();

  class  Signal_identifierContext : public antlr4::ParserRuleContext {
  public:
    Signal_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Signal_identifierContext* signal_identifier();

  class  Specparam_identifierContext : public antlr4::ParserRuleContext {
  public:
    Specparam_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Specparam_identifierContext* specparam_identifier();

  class  Task_identifierContext : public antlr4::ParserRuleContext {
  public:
    Task_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Task_identifierContext* task_identifier();

  class  Tf_identifierContext : public antlr4::ParserRuleContext {
  public:
    Tf_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Tf_identifierContext* tf_identifier();

  class  Terminal_identifierContext : public antlr4::ParserRuleContext {
  public:
    Terminal_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Terminal_identifierContext* terminal_identifier();

  class  Topmodule_identifierContext : public antlr4::ParserRuleContext {
  public:
    Topmodule_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Topmodule_identifierContext* topmodule_identifier();

  class  Type_identifierContext : public antlr4::ParserRuleContext {
  public:
    Type_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_identifierContext* type_identifier();

  class  Udp_identifierContext : public antlr4::ParserRuleContext {
  public:
    Udp_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Udp_identifierContext* udp_identifier();

  class  Variable_identifierContext : public antlr4::ParserRuleContext {
  public:
    Variable_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_identifierContext* variable_identifier();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool property_exprSempred(Property_exprContext *_localctx, size_t predicateIndex);
  bool sequence_exprSempred(Sequence_exprContext *_localctx, size_t predicateIndex);
  bool block_event_expressionSempred(Block_event_expressionContext *_localctx, size_t predicateIndex);
  bool select_expressionSempred(Select_expressionContext *_localctx, size_t predicateIndex);
  bool event_expressionSempred(Event_expressionContext *_localctx, size_t predicateIndex);
  bool constant_expressionSempred(Constant_expressionContext *_localctx, size_t predicateIndex);
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool module_path_expressionSempred(Module_path_expressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace sv
