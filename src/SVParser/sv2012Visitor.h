
// Generated from grammars/sv2012.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "sv2012Parser.h"


namespace sv {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by sv2012Parser.
 */
class  sv2012Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by sv2012Parser.
   */
    virtual antlrcpp::Any visitLibrary_text(sv2012Parser::Library_textContext *context) = 0;

    virtual antlrcpp::Any visitLibrary_description(sv2012Parser::Library_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitLibrary_declaration(sv2012Parser::Library_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInclude_statement(sv2012Parser::Include_statementContext *context) = 0;

    virtual antlrcpp::Any visitSource_text(sv2012Parser::Source_textContext *context) = 0;

    virtual antlrcpp::Any visitDescription(sv2012Parser::DescriptionContext *context) = 0;

    virtual antlrcpp::Any visitModule_nonansi_header(sv2012Parser::Module_nonansi_headerContext *context) = 0;

    virtual antlrcpp::Any visitModule_ansi_header(sv2012Parser::Module_ansi_headerContext *context) = 0;

    virtual antlrcpp::Any visitModule_declaration(sv2012Parser::Module_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModule_keyword(sv2012Parser::Module_keywordContext *context) = 0;

    virtual antlrcpp::Any visitInterface_declaration(sv2012Parser::Interface_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_nonansi_header(sv2012Parser::Interface_nonansi_headerContext *context) = 0;

    virtual antlrcpp::Any visitInterface_ansi_header(sv2012Parser::Interface_ansi_headerContext *context) = 0;

    virtual antlrcpp::Any visitProgram_declaration(sv2012Parser::Program_declarationContext *context) = 0;

    virtual antlrcpp::Any visitProgram_nonansi_header(sv2012Parser::Program_nonansi_headerContext *context) = 0;

    virtual antlrcpp::Any visitProgram_ansi_header(sv2012Parser::Program_ansi_headerContext *context) = 0;

    virtual antlrcpp::Any visitChecker_declaration(sv2012Parser::Checker_declarationContext *context) = 0;

    virtual antlrcpp::Any visitClass_declaration(sv2012Parser::Class_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_class_type(sv2012Parser::Interface_class_typeContext *context) = 0;

    virtual antlrcpp::Any visitInterface_class_declaration(sv2012Parser::Interface_class_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_class_item(sv2012Parser::Interface_class_itemContext *context) = 0;

    virtual antlrcpp::Any visitInterface_class_method(sv2012Parser::Interface_class_methodContext *context) = 0;

    virtual antlrcpp::Any visitPackage_declaration(sv2012Parser::Package_declarationContext *context) = 0;

    virtual antlrcpp::Any visitTimeunits_declaration(sv2012Parser::Timeunits_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParameter_port_list(sv2012Parser::Parameter_port_listContext *context) = 0;

    virtual antlrcpp::Any visitParameter_port_declaration(sv2012Parser::Parameter_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitList_of_ports(sv2012Parser::List_of_portsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_port_declarations(sv2012Parser::List_of_port_declarationsContext *context) = 0;

    virtual antlrcpp::Any visitPort_declaration(sv2012Parser::Port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPort(sv2012Parser::PortContext *context) = 0;

    virtual antlrcpp::Any visitPort_expression(sv2012Parser::Port_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPort_reference(sv2012Parser::Port_referenceContext *context) = 0;

    virtual antlrcpp::Any visitPort_direction(sv2012Parser::Port_directionContext *context) = 0;

    virtual antlrcpp::Any visitNet_port_header(sv2012Parser::Net_port_headerContext *context) = 0;

    virtual antlrcpp::Any visitVariable_port_header(sv2012Parser::Variable_port_headerContext *context) = 0;

    virtual antlrcpp::Any visitInterface_port_header(sv2012Parser::Interface_port_headerContext *context) = 0;

    virtual antlrcpp::Any visitAnsi_port_declaration(sv2012Parser::Ansi_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitElaboration_system_task(sv2012Parser::Elaboration_system_taskContext *context) = 0;

    virtual antlrcpp::Any visitFinish_number(sv2012Parser::Finish_numberContext *context) = 0;

    virtual antlrcpp::Any visitModule_common_item(sv2012Parser::Module_common_itemContext *context) = 0;

    virtual antlrcpp::Any visitModule_item(sv2012Parser::Module_itemContext *context) = 0;

    virtual antlrcpp::Any visitModule_or_generate_item(sv2012Parser::Module_or_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitModule_or_generate_item_declaration(sv2012Parser::Module_or_generate_item_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNon_port_module_item(sv2012Parser::Non_port_module_itemContext *context) = 0;

    virtual antlrcpp::Any visitParameter_override(sv2012Parser::Parameter_overrideContext *context) = 0;

    virtual antlrcpp::Any visitBind_directive(sv2012Parser::Bind_directiveContext *context) = 0;

    virtual antlrcpp::Any visitBind_target_scope(sv2012Parser::Bind_target_scopeContext *context) = 0;

    virtual antlrcpp::Any visitBind_target_instance(sv2012Parser::Bind_target_instanceContext *context) = 0;

    virtual antlrcpp::Any visitBind_target_instance_list(sv2012Parser::Bind_target_instance_listContext *context) = 0;

    virtual antlrcpp::Any visitBind_instantiation(sv2012Parser::Bind_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitConfig_declaration(sv2012Parser::Config_declarationContext *context) = 0;

    virtual antlrcpp::Any visitDesign_statement(sv2012Parser::Design_statementContext *context) = 0;

    virtual antlrcpp::Any visitConfig_rule_statement(sv2012Parser::Config_rule_statementContext *context) = 0;

    virtual antlrcpp::Any visitDefault_clause(sv2012Parser::Default_clauseContext *context) = 0;

    virtual antlrcpp::Any visitInst_clause(sv2012Parser::Inst_clauseContext *context) = 0;

    virtual antlrcpp::Any visitInst_name(sv2012Parser::Inst_nameContext *context) = 0;

    virtual antlrcpp::Any visitCell_clause(sv2012Parser::Cell_clauseContext *context) = 0;

    virtual antlrcpp::Any visitLiblist_clause(sv2012Parser::Liblist_clauseContext *context) = 0;

    virtual antlrcpp::Any visitUse_clause(sv2012Parser::Use_clauseContext *context) = 0;

    virtual antlrcpp::Any visitInterface_or_generate_item(sv2012Parser::Interface_or_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitExtern_tf_declaration(sv2012Parser::Extern_tf_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_item(sv2012Parser::Interface_itemContext *context) = 0;

    virtual antlrcpp::Any visitNon_port_interface_item(sv2012Parser::Non_port_interface_itemContext *context) = 0;

    virtual antlrcpp::Any visitProgram_item(sv2012Parser::Program_itemContext *context) = 0;

    virtual antlrcpp::Any visitNon_port_program_item(sv2012Parser::Non_port_program_itemContext *context) = 0;

    virtual antlrcpp::Any visitProgram_generate_item(sv2012Parser::Program_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitChecker_port_list(sv2012Parser::Checker_port_listContext *context) = 0;

    virtual antlrcpp::Any visitChecker_port_item(sv2012Parser::Checker_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitChecker_port_direction(sv2012Parser::Checker_port_directionContext *context) = 0;

    virtual antlrcpp::Any visitChecker_or_generate_item(sv2012Parser::Checker_or_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitChecker_or_generate_item_declaration(sv2012Parser::Checker_or_generate_item_declarationContext *context) = 0;

    virtual antlrcpp::Any visitChecker_generate_item(sv2012Parser::Checker_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitClass_item(sv2012Parser::Class_itemContext *context) = 0;

    virtual antlrcpp::Any visitClass_property(sv2012Parser::Class_propertyContext *context) = 0;

    virtual antlrcpp::Any visitClass_method(sv2012Parser::Class_methodContext *context) = 0;

    virtual antlrcpp::Any visitClass_constructor_prototype(sv2012Parser::Class_constructor_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitClass_constraint(sv2012Parser::Class_constraintContext *context) = 0;

    virtual antlrcpp::Any visitClass_item_qualifier(sv2012Parser::Class_item_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitProperty_qualifier(sv2012Parser::Property_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitRandom_qualifier(sv2012Parser::Random_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitMethod_qualifier(sv2012Parser::Method_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitMethod_prototype(sv2012Parser::Method_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitClass_constructor_declaration(sv2012Parser::Class_constructor_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_declaration(sv2012Parser::Constraint_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_block(sv2012Parser::Constraint_blockContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_block_item(sv2012Parser::Constraint_block_itemContext *context) = 0;

    virtual antlrcpp::Any visitSolve_before_list(sv2012Parser::Solve_before_listContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_primary(sv2012Parser::Constraint_primaryContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_expression(sv2012Parser::Constraint_expressionContext *context) = 0;

    virtual antlrcpp::Any visitUniqueness_constraint(sv2012Parser::Uniqueness_constraintContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_set(sv2012Parser::Constraint_setContext *context) = 0;

    virtual antlrcpp::Any visitDist_list(sv2012Parser::Dist_listContext *context) = 0;

    virtual antlrcpp::Any visitDist_item(sv2012Parser::Dist_itemContext *context) = 0;

    virtual antlrcpp::Any visitDist_weight(sv2012Parser::Dist_weightContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_prototype(sv2012Parser::Constraint_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_prototype_qualifier(sv2012Parser::Constraint_prototype_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitExtern_constraint_declaration(sv2012Parser::Extern_constraint_declarationContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_list(sv2012Parser::Identifier_listContext *context) = 0;

    virtual antlrcpp::Any visitPackage_item(sv2012Parser::Package_itemContext *context) = 0;

    virtual antlrcpp::Any visitPackage_or_generate_item_declaration(sv2012Parser::Package_or_generate_item_declarationContext *context) = 0;

    virtual antlrcpp::Any visitAnonymous_program(sv2012Parser::Anonymous_programContext *context) = 0;

    virtual antlrcpp::Any visitAnonymous_program_item(sv2012Parser::Anonymous_program_itemContext *context) = 0;

    virtual antlrcpp::Any visitLocal_parameter_declaration(sv2012Parser::Local_parameter_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParameter_declaration(sv2012Parser::Parameter_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSpecparam_declaration(sv2012Parser::Specparam_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInout_declaration(sv2012Parser::Inout_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInput_declaration(sv2012Parser::Input_declarationContext *context) = 0;

    virtual antlrcpp::Any visitOutput_declaration(sv2012Parser::Output_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_port_declaration(sv2012Parser::Interface_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitRef_declaration(sv2012Parser::Ref_declarationContext *context) = 0;

    virtual antlrcpp::Any visitData_declaration(sv2012Parser::Data_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPackage_import_declaration(sv2012Parser::Package_import_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPackage_import_item(sv2012Parser::Package_import_itemContext *context) = 0;

    virtual antlrcpp::Any visitPackage_export_declaration(sv2012Parser::Package_export_declarationContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_declaration(sv2012Parser::Genvar_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNet_declaration(sv2012Parser::Net_declarationContext *context) = 0;

    virtual antlrcpp::Any visitType_declaration(sv2012Parser::Type_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNet_type_declaration(sv2012Parser::Net_type_declarationContext *context) = 0;

    virtual antlrcpp::Any visitLifetime(sv2012Parser::LifetimeContext *context) = 0;

    virtual antlrcpp::Any visitCasting_type_reduced(sv2012Parser::Casting_type_reducedContext *context) = 0;

    virtual antlrcpp::Any visitCasting_type(sv2012Parser::Casting_typeContext *context) = 0;

    virtual antlrcpp::Any visitData_type(sv2012Parser::Data_typeContext *context) = 0;

    virtual antlrcpp::Any visitData_type_or_implicit(sv2012Parser::Data_type_or_implicitContext *context) = 0;

    virtual antlrcpp::Any visitImplicit_data_type(sv2012Parser::Implicit_data_typeContext *context) = 0;

    virtual antlrcpp::Any visitEnum_base_type(sv2012Parser::Enum_base_typeContext *context) = 0;

    virtual antlrcpp::Any visitEnum_name_declaration(sv2012Parser::Enum_name_declarationContext *context) = 0;

    virtual antlrcpp::Any visitClass_scope(sv2012Parser::Class_scopeContext *context) = 0;

    virtual antlrcpp::Any visitClass_type(sv2012Parser::Class_typeContext *context) = 0;

    virtual antlrcpp::Any visitInteger_type(sv2012Parser::Integer_typeContext *context) = 0;

    virtual antlrcpp::Any visitInteger_atom_type(sv2012Parser::Integer_atom_typeContext *context) = 0;

    virtual antlrcpp::Any visitInteger_vector_type(sv2012Parser::Integer_vector_typeContext *context) = 0;

    virtual antlrcpp::Any visitNon_integer_type(sv2012Parser::Non_integer_typeContext *context) = 0;

    virtual antlrcpp::Any visitNet_type(sv2012Parser::Net_typeContext *context) = 0;

    virtual antlrcpp::Any visitNet_port_type(sv2012Parser::Net_port_typeContext *context) = 0;

    virtual antlrcpp::Any visitVariable_port_type(sv2012Parser::Variable_port_typeContext *context) = 0;

    virtual antlrcpp::Any visitVar_data_type(sv2012Parser::Var_data_typeContext *context) = 0;

    virtual antlrcpp::Any visitSigning(sv2012Parser::SigningContext *context) = 0;

    virtual antlrcpp::Any visitSimple_type(sv2012Parser::Simple_typeContext *context) = 0;

    virtual antlrcpp::Any visitStruct_union_member(sv2012Parser::Struct_union_memberContext *context) = 0;

    virtual antlrcpp::Any visitData_type_or_void(sv2012Parser::Data_type_or_voidContext *context) = 0;

    virtual antlrcpp::Any visitStruct_union(sv2012Parser::Struct_unionContext *context) = 0;

    virtual antlrcpp::Any visitType_reference(sv2012Parser::Type_referenceContext *context) = 0;

    virtual antlrcpp::Any visitDrive_strength(sv2012Parser::Drive_strengthContext *context) = 0;

    virtual antlrcpp::Any visitStrength0(sv2012Parser::Strength0Context *context) = 0;

    virtual antlrcpp::Any visitStrength1(sv2012Parser::Strength1Context *context) = 0;

    virtual antlrcpp::Any visitCharge_strength(sv2012Parser::Charge_strengthContext *context) = 0;

    virtual antlrcpp::Any visitDelay3(sv2012Parser::Delay3Context *context) = 0;

    virtual antlrcpp::Any visitDelay2(sv2012Parser::Delay2Context *context) = 0;

    virtual antlrcpp::Any visitDelay_value(sv2012Parser::Delay_valueContext *context) = 0;

    virtual antlrcpp::Any visitList_of_defparam_assignments(sv2012Parser::List_of_defparam_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_genvar_identifiers(sv2012Parser::List_of_genvar_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitList_of_interface_identifiers(sv2012Parser::List_of_interface_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitList_of_net_decl_assignments(sv2012Parser::List_of_net_decl_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_param_assignments(sv2012Parser::List_of_param_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_port_identifiers(sv2012Parser::List_of_port_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitList_of_udp_port_identifiers(sv2012Parser::List_of_udp_port_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitList_of_specparam_assignments(sv2012Parser::List_of_specparam_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_tf_variable_identifiers(sv2012Parser::List_of_tf_variable_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitList_of_type_assignments(sv2012Parser::List_of_type_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_decl_assignments(sv2012Parser::List_of_variable_decl_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_identifiers(sv2012Parser::List_of_variable_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_port_identifiers(sv2012Parser::List_of_variable_port_identifiersContext *context) = 0;

    virtual antlrcpp::Any visitDefparam_assignment(sv2012Parser::Defparam_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitNet_decl_assignment(sv2012Parser::Net_decl_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitParam_assignment(sv2012Parser::Param_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitSpecparam_assignment(sv2012Parser::Specparam_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitType_assignment(sv2012Parser::Type_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitPulse_control_specparam(sv2012Parser::Pulse_control_specparamContext *context) = 0;

    virtual antlrcpp::Any visitError_limit_value(sv2012Parser::Error_limit_valueContext *context) = 0;

    virtual antlrcpp::Any visitReject_limit_value(sv2012Parser::Reject_limit_valueContext *context) = 0;

    virtual antlrcpp::Any visitLimit_value(sv2012Parser::Limit_valueContext *context) = 0;

    virtual antlrcpp::Any visitVariable_decl_assignment(sv2012Parser::Variable_decl_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitClass_new(sv2012Parser::Class_newContext *context) = 0;

    virtual antlrcpp::Any visitDynamic_array_new(sv2012Parser::Dynamic_array_newContext *context) = 0;

    virtual antlrcpp::Any visitUnpacked_dimension(sv2012Parser::Unpacked_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitPacked_dimension(sv2012Parser::Packed_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitAssociative_dimension(sv2012Parser::Associative_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitVariable_dimension(sv2012Parser::Variable_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitQueue_dimension(sv2012Parser::Queue_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitUnsized_dimension(sv2012Parser::Unsized_dimensionContext *context) = 0;

    virtual antlrcpp::Any visitFunction_data_type_or_implicit(sv2012Parser::Function_data_type_or_implicitContext *context) = 0;

    virtual antlrcpp::Any visitFunction_declaration(sv2012Parser::Function_declarationContext *context) = 0;

    virtual antlrcpp::Any visitFunction_body_declaration(sv2012Parser::Function_body_declarationContext *context) = 0;

    virtual antlrcpp::Any visitFunction_prototype(sv2012Parser::Function_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitDpi_import_export(sv2012Parser::Dpi_import_exportContext *context) = 0;

    virtual antlrcpp::Any visitDpi_spec_string(sv2012Parser::Dpi_spec_stringContext *context) = 0;

    virtual antlrcpp::Any visitDpi_function_import_property(sv2012Parser::Dpi_function_import_propertyContext *context) = 0;

    virtual antlrcpp::Any visitDpi_task_import_property(sv2012Parser::Dpi_task_import_propertyContext *context) = 0;

    virtual antlrcpp::Any visitDpi_function_proto(sv2012Parser::Dpi_function_protoContext *context) = 0;

    virtual antlrcpp::Any visitDpi_task_proto(sv2012Parser::Dpi_task_protoContext *context) = 0;

    virtual antlrcpp::Any visitTask_declaration(sv2012Parser::Task_declarationContext *context) = 0;

    virtual antlrcpp::Any visitTask_body_declaration(sv2012Parser::Task_body_declarationContext *context) = 0;

    virtual antlrcpp::Any visitTf_item_declaration(sv2012Parser::Tf_item_declarationContext *context) = 0;

    virtual antlrcpp::Any visitTf_port_list(sv2012Parser::Tf_port_listContext *context) = 0;

    virtual antlrcpp::Any visitTf_port_item(sv2012Parser::Tf_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitTf_port_direction(sv2012Parser::Tf_port_directionContext *context) = 0;

    virtual antlrcpp::Any visitTf_port_declaration(sv2012Parser::Tf_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitTask_prototype(sv2012Parser::Task_prototypeContext *context) = 0;

    virtual antlrcpp::Any visitBlock_item_declaration(sv2012Parser::Block_item_declarationContext *context) = 0;

    virtual antlrcpp::Any visitOverload_declaration(sv2012Parser::Overload_declarationContext *context) = 0;

    virtual antlrcpp::Any visitOverload_operator(sv2012Parser::Overload_operatorContext *context) = 0;

    virtual antlrcpp::Any visitOverload_proto_formals(sv2012Parser::Overload_proto_formalsContext *context) = 0;

    virtual antlrcpp::Any visitModport_declaration(sv2012Parser::Modport_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_item(sv2012Parser::Modport_itemContext *context) = 0;

    virtual antlrcpp::Any visitModport_ports_declaration(sv2012Parser::Modport_ports_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_clocking_declaration(sv2012Parser::Modport_clocking_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_simple_ports_declaration(sv2012Parser::Modport_simple_ports_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_simple_port(sv2012Parser::Modport_simple_portContext *context) = 0;

    virtual antlrcpp::Any visitModport_tf_ports_declaration(sv2012Parser::Modport_tf_ports_declarationContext *context) = 0;

    virtual antlrcpp::Any visitModport_tf_port(sv2012Parser::Modport_tf_portContext *context) = 0;

    virtual antlrcpp::Any visitImport_export(sv2012Parser::Import_exportContext *context) = 0;

    virtual antlrcpp::Any visitConcurrent_assertion_item(sv2012Parser::Concurrent_assertion_itemContext *context) = 0;

    virtual antlrcpp::Any visitConcurrent_assertion_statement(sv2012Parser::Concurrent_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitAssert_property_statement(sv2012Parser::Assert_property_statementContext *context) = 0;

    virtual antlrcpp::Any visitAssume_property_statement(sv2012Parser::Assume_property_statementContext *context) = 0;

    virtual antlrcpp::Any visitCover_property_statement(sv2012Parser::Cover_property_statementContext *context) = 0;

    virtual antlrcpp::Any visitExpect_property_statement(sv2012Parser::Expect_property_statementContext *context) = 0;

    virtual antlrcpp::Any visitCover_sequence_statement(sv2012Parser::Cover_sequence_statementContext *context) = 0;

    virtual antlrcpp::Any visitRestrict_property_statement(sv2012Parser::Restrict_property_statementContext *context) = 0;

    virtual antlrcpp::Any visitProperty_instance(sv2012Parser::Property_instanceContext *context) = 0;

    virtual antlrcpp::Any visitProperty_list_of_arguments(sv2012Parser::Property_list_of_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitProperty_actual_arg(sv2012Parser::Property_actual_argContext *context) = 0;

    virtual antlrcpp::Any visitAssertion_item_declaration(sv2012Parser::Assertion_item_declarationContext *context) = 0;

    virtual antlrcpp::Any visitProperty_declaration(sv2012Parser::Property_declarationContext *context) = 0;

    virtual antlrcpp::Any visitProperty_port_list(sv2012Parser::Property_port_listContext *context) = 0;

    virtual antlrcpp::Any visitProperty_port_item(sv2012Parser::Property_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitProperty_lvar_port_direction(sv2012Parser::Property_lvar_port_directionContext *context) = 0;

    virtual antlrcpp::Any visitProperty_formal_type(sv2012Parser::Property_formal_typeContext *context) = 0;

    virtual antlrcpp::Any visitProperty_spec(sv2012Parser::Property_specContext *context) = 0;

    virtual antlrcpp::Any visitProperty_expr(sv2012Parser::Property_exprContext *context) = 0;

    virtual antlrcpp::Any visitProperty_case_item(sv2012Parser::Property_case_itemContext *context) = 0;

    virtual antlrcpp::Any visitSequence_declaration(sv2012Parser::Sequence_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSequence_port_list(sv2012Parser::Sequence_port_listContext *context) = 0;

    virtual antlrcpp::Any visitSequence_port_item(sv2012Parser::Sequence_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitSequence_lvar_port_direction(sv2012Parser::Sequence_lvar_port_directionContext *context) = 0;

    virtual antlrcpp::Any visitSequence_formal_type(sv2012Parser::Sequence_formal_typeContext *context) = 0;

    virtual antlrcpp::Any visitSequence_expr(sv2012Parser::Sequence_exprContext *context) = 0;

    virtual antlrcpp::Any visitCycle_delay_range(sv2012Parser::Cycle_delay_rangeContext *context) = 0;

    virtual antlrcpp::Any visitSequence_method_call(sv2012Parser::Sequence_method_callContext *context) = 0;

    virtual antlrcpp::Any visitSequence_match_item(sv2012Parser::Sequence_match_itemContext *context) = 0;

    virtual antlrcpp::Any visitSequence_instance(sv2012Parser::Sequence_instanceContext *context) = 0;

    virtual antlrcpp::Any visitSequence_list_of_arguments(sv2012Parser::Sequence_list_of_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitSequence_actual_arg(sv2012Parser::Sequence_actual_argContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_abbrev(sv2012Parser::Boolean_abbrevContext *context) = 0;

    virtual antlrcpp::Any visitSequence_abbrev(sv2012Parser::Sequence_abbrevContext *context) = 0;

    virtual antlrcpp::Any visitConsecutive_repetition(sv2012Parser::Consecutive_repetitionContext *context) = 0;

    virtual antlrcpp::Any visitNon_consecutive_repetition(sv2012Parser::Non_consecutive_repetitionContext *context) = 0;

    virtual antlrcpp::Any visitGoto_repetition(sv2012Parser::Goto_repetitionContext *context) = 0;

    virtual antlrcpp::Any visitConst_or_range_expression(sv2012Parser::Const_or_range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCycle_delay_const_range_expression(sv2012Parser::Cycle_delay_const_range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitExpression_or_dist(sv2012Parser::Expression_or_distContext *context) = 0;

    virtual antlrcpp::Any visitAssertion_variable_declaration(sv2012Parser::Assertion_variable_declarationContext *context) = 0;

    virtual antlrcpp::Any visitLet_declaration(sv2012Parser::Let_declarationContext *context) = 0;

    virtual antlrcpp::Any visitLet_identifier(sv2012Parser::Let_identifierContext *context) = 0;

    virtual antlrcpp::Any visitLet_port_list(sv2012Parser::Let_port_listContext *context) = 0;

    virtual antlrcpp::Any visitLet_port_item(sv2012Parser::Let_port_itemContext *context) = 0;

    virtual antlrcpp::Any visitLet_formal_type(sv2012Parser::Let_formal_typeContext *context) = 0;

    virtual antlrcpp::Any visitLet_expression(sv2012Parser::Let_expressionContext *context) = 0;

    virtual antlrcpp::Any visitLet_list_of_arguments(sv2012Parser::Let_list_of_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitLet_actual_arg(sv2012Parser::Let_actual_argContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_declaration(sv2012Parser::Covergroup_declarationContext *context) = 0;

    virtual antlrcpp::Any visitCoverage_spec_or_option(sv2012Parser::Coverage_spec_or_optionContext *context) = 0;

    virtual antlrcpp::Any visitCoverage_option(sv2012Parser::Coverage_optionContext *context) = 0;

    virtual antlrcpp::Any visitCoverage_spec(sv2012Parser::Coverage_specContext *context) = 0;

    virtual antlrcpp::Any visitCoverage_event(sv2012Parser::Coverage_eventContext *context) = 0;

    virtual antlrcpp::Any visitBlock_event_expression(sv2012Parser::Block_event_expressionContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_btf_identifier(sv2012Parser::Hierarchical_btf_identifierContext *context) = 0;

    virtual antlrcpp::Any visitCover_point(sv2012Parser::Cover_pointContext *context) = 0;

    virtual antlrcpp::Any visitBins_or_empty(sv2012Parser::Bins_or_emptyContext *context) = 0;

    virtual antlrcpp::Any visitBins_or_options(sv2012Parser::Bins_or_optionsContext *context) = 0;

    virtual antlrcpp::Any visitBins_keyword(sv2012Parser::Bins_keywordContext *context) = 0;

    virtual antlrcpp::Any visitTrans_list(sv2012Parser::Trans_listContext *context) = 0;

    virtual antlrcpp::Any visitTrans_set(sv2012Parser::Trans_setContext *context) = 0;

    virtual antlrcpp::Any visitTrans_range_list(sv2012Parser::Trans_range_listContext *context) = 0;

    virtual antlrcpp::Any visitTrans_item(sv2012Parser::Trans_itemContext *context) = 0;

    virtual antlrcpp::Any visitRepeat_range(sv2012Parser::Repeat_rangeContext *context) = 0;

    virtual antlrcpp::Any visitCover_cross(sv2012Parser::Cover_crossContext *context) = 0;

    virtual antlrcpp::Any visitList_of_cross_items(sv2012Parser::List_of_cross_itemsContext *context) = 0;

    virtual antlrcpp::Any visitCross_item(sv2012Parser::Cross_itemContext *context) = 0;

    virtual antlrcpp::Any visitCross_body(sv2012Parser::Cross_bodyContext *context) = 0;

    virtual antlrcpp::Any visitCross_body_item(sv2012Parser::Cross_body_itemContext *context) = 0;

    virtual antlrcpp::Any visitBins_selection_or_option(sv2012Parser::Bins_selection_or_optionContext *context) = 0;

    virtual antlrcpp::Any visitBins_selection(sv2012Parser::Bins_selectionContext *context) = 0;

    virtual antlrcpp::Any visitSelect_expression(sv2012Parser::Select_expressionContext *context) = 0;

    virtual antlrcpp::Any visitSelect_condition(sv2012Parser::Select_conditionContext *context) = 0;

    virtual antlrcpp::Any visitBins_expression(sv2012Parser::Bins_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_range_list(sv2012Parser::Covergroup_range_listContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_value_range(sv2012Parser::Covergroup_value_rangeContext *context) = 0;

    virtual antlrcpp::Any visitWith_covergroup_expression(sv2012Parser::With_covergroup_expressionContext *context) = 0;

    virtual antlrcpp::Any visitSet_covergroup_expression(sv2012Parser::Set_covergroup_expressionContext *context) = 0;

    virtual antlrcpp::Any visitInteger_covergroup_expression(sv2012Parser::Integer_covergroup_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCross_set_expression(sv2012Parser::Cross_set_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_expression(sv2012Parser::Covergroup_expressionContext *context) = 0;

    virtual antlrcpp::Any visitGate_instantiation(sv2012Parser::Gate_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitCmos_switch_instance(sv2012Parser::Cmos_switch_instanceContext *context) = 0;

    virtual antlrcpp::Any visitEnable_gate_instance(sv2012Parser::Enable_gate_instanceContext *context) = 0;

    virtual antlrcpp::Any visitMos_switch_instance(sv2012Parser::Mos_switch_instanceContext *context) = 0;

    virtual antlrcpp::Any visitN_input_gate_instance(sv2012Parser::N_input_gate_instanceContext *context) = 0;

    virtual antlrcpp::Any visitN_output_gate_instance(sv2012Parser::N_output_gate_instanceContext *context) = 0;

    virtual antlrcpp::Any visitPass_switch_instance(sv2012Parser::Pass_switch_instanceContext *context) = 0;

    virtual antlrcpp::Any visitPass_enable_switch_instance(sv2012Parser::Pass_enable_switch_instanceContext *context) = 0;

    virtual antlrcpp::Any visitPull_gate_instance(sv2012Parser::Pull_gate_instanceContext *context) = 0;

    virtual antlrcpp::Any visitPulldown_strength(sv2012Parser::Pulldown_strengthContext *context) = 0;

    virtual antlrcpp::Any visitPullup_strength(sv2012Parser::Pullup_strengthContext *context) = 0;

    virtual antlrcpp::Any visitEnable_terminal(sv2012Parser::Enable_terminalContext *context) = 0;

    virtual antlrcpp::Any visitInout_terminal(sv2012Parser::Inout_terminalContext *context) = 0;

    virtual antlrcpp::Any visitInput_terminal(sv2012Parser::Input_terminalContext *context) = 0;

    virtual antlrcpp::Any visitNcontrol_terminal(sv2012Parser::Ncontrol_terminalContext *context) = 0;

    virtual antlrcpp::Any visitOutput_terminal(sv2012Parser::Output_terminalContext *context) = 0;

    virtual antlrcpp::Any visitPcontrol_terminal(sv2012Parser::Pcontrol_terminalContext *context) = 0;

    virtual antlrcpp::Any visitCmos_switchtype(sv2012Parser::Cmos_switchtypeContext *context) = 0;

    virtual antlrcpp::Any visitEnable_gatetype(sv2012Parser::Enable_gatetypeContext *context) = 0;

    virtual antlrcpp::Any visitMos_switchtype(sv2012Parser::Mos_switchtypeContext *context) = 0;

    virtual antlrcpp::Any visitN_input_gatetype(sv2012Parser::N_input_gatetypeContext *context) = 0;

    virtual antlrcpp::Any visitN_output_gatetype(sv2012Parser::N_output_gatetypeContext *context) = 0;

    virtual antlrcpp::Any visitPass_en_switchtype(sv2012Parser::Pass_en_switchtypeContext *context) = 0;

    virtual antlrcpp::Any visitPass_switchtype(sv2012Parser::Pass_switchtypeContext *context) = 0;

    virtual antlrcpp::Any visitModule_instantiation(sv2012Parser::Module_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitParameter_value_assignment(sv2012Parser::Parameter_value_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitList_of_parameter_assignments(sv2012Parser::List_of_parameter_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitOrdered_parameter_assignment(sv2012Parser::Ordered_parameter_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitNamed_parameter_assignment(sv2012Parser::Named_parameter_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_instance(sv2012Parser::Hierarchical_instanceContext *context) = 0;

    virtual antlrcpp::Any visitName_of_instance(sv2012Parser::Name_of_instanceContext *context) = 0;

    virtual antlrcpp::Any visitList_of_port_connections(sv2012Parser::List_of_port_connectionsContext *context) = 0;

    virtual antlrcpp::Any visitOrdered_port_connection(sv2012Parser::Ordered_port_connectionContext *context) = 0;

    virtual antlrcpp::Any visitNamed_port_connection(sv2012Parser::Named_port_connectionContext *context) = 0;

    virtual antlrcpp::Any visitInterface_instantiation(sv2012Parser::Interface_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitProgram_instantiation(sv2012Parser::Program_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitChecker_instantiation(sv2012Parser::Checker_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitList_of_checker_port_connections(sv2012Parser::List_of_checker_port_connectionsContext *context) = 0;

    virtual antlrcpp::Any visitOrdered_checker_port_connection(sv2012Parser::Ordered_checker_port_connectionContext *context) = 0;

    virtual antlrcpp::Any visitNamed_checker_port_connection(sv2012Parser::Named_checker_port_connectionContext *context) = 0;

    virtual antlrcpp::Any visitGenerate_region(sv2012Parser::Generate_regionContext *context) = 0;

    virtual antlrcpp::Any visitLoop_generate_construct(sv2012Parser::Loop_generate_constructContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_initialization(sv2012Parser::Genvar_initializationContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_iteration(sv2012Parser::Genvar_iterationContext *context) = 0;

    virtual antlrcpp::Any visitConditional_generate_construct(sv2012Parser::Conditional_generate_constructContext *context) = 0;

    virtual antlrcpp::Any visitIf_generate_construct(sv2012Parser::If_generate_constructContext *context) = 0;

    virtual antlrcpp::Any visitCase_generate_construct(sv2012Parser::Case_generate_constructContext *context) = 0;

    virtual antlrcpp::Any visitCase_generate_item(sv2012Parser::Case_generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitGenerate_block(sv2012Parser::Generate_blockContext *context) = 0;

    virtual antlrcpp::Any visitGenerate_item(sv2012Parser::Generate_itemContext *context) = 0;

    virtual antlrcpp::Any visitUdp_nonansi_declaration(sv2012Parser::Udp_nonansi_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_ansi_declaration(sv2012Parser::Udp_ansi_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_declaration(sv2012Parser::Udp_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_port_list(sv2012Parser::Udp_port_listContext *context) = 0;

    virtual antlrcpp::Any visitUdp_declaration_port_list(sv2012Parser::Udp_declaration_port_listContext *context) = 0;

    virtual antlrcpp::Any visitUdp_port_declaration(sv2012Parser::Udp_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_output_declaration(sv2012Parser::Udp_output_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_input_declaration(sv2012Parser::Udp_input_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_reg_declaration(sv2012Parser::Udp_reg_declarationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_body(sv2012Parser::Udp_bodyContext *context) = 0;

    virtual antlrcpp::Any visitCombinational_body(sv2012Parser::Combinational_bodyContext *context) = 0;

    virtual antlrcpp::Any visitCombinational_entry(sv2012Parser::Combinational_entryContext *context) = 0;

    virtual antlrcpp::Any visitSequential_body(sv2012Parser::Sequential_bodyContext *context) = 0;

    virtual antlrcpp::Any visitUdp_initial_statement(sv2012Parser::Udp_initial_statementContext *context) = 0;

    virtual antlrcpp::Any visitInit_val(sv2012Parser::Init_valContext *context) = 0;

    virtual antlrcpp::Any visitSequential_entry(sv2012Parser::Sequential_entryContext *context) = 0;

    virtual antlrcpp::Any visitSeq_input_list(sv2012Parser::Seq_input_listContext *context) = 0;

    virtual antlrcpp::Any visitLevel_input_list(sv2012Parser::Level_input_listContext *context) = 0;

    virtual antlrcpp::Any visitEdge_input_list(sv2012Parser::Edge_input_listContext *context) = 0;

    virtual antlrcpp::Any visitEdge_indicator(sv2012Parser::Edge_indicatorContext *context) = 0;

    virtual antlrcpp::Any visitCurrent_state(sv2012Parser::Current_stateContext *context) = 0;

    virtual antlrcpp::Any visitNext_state(sv2012Parser::Next_stateContext *context) = 0;

    virtual antlrcpp::Any visitOutput_symbol(sv2012Parser::Output_symbolContext *context) = 0;

    virtual antlrcpp::Any visitLevel_symbol(sv2012Parser::Level_symbolContext *context) = 0;

    virtual antlrcpp::Any visitEdge_symbol(sv2012Parser::Edge_symbolContext *context) = 0;

    virtual antlrcpp::Any visitUdp_instantiation(sv2012Parser::Udp_instantiationContext *context) = 0;

    virtual antlrcpp::Any visitUdp_instance(sv2012Parser::Udp_instanceContext *context) = 0;

    virtual antlrcpp::Any visitContinuous_assign(sv2012Parser::Continuous_assignContext *context) = 0;

    virtual antlrcpp::Any visitList_of_net_assignments(sv2012Parser::List_of_net_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_variable_assignments(sv2012Parser::List_of_variable_assignmentsContext *context) = 0;

    virtual antlrcpp::Any visitNet_alias(sv2012Parser::Net_aliasContext *context) = 0;

    virtual antlrcpp::Any visitNet_assignment(sv2012Parser::Net_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitInitial_construct(sv2012Parser::Initial_constructContext *context) = 0;

    virtual antlrcpp::Any visitAlways_construct(sv2012Parser::Always_constructContext *context) = 0;

    virtual antlrcpp::Any visitAlways_keyword(sv2012Parser::Always_keywordContext *context) = 0;

    virtual antlrcpp::Any visitFinal_construct(sv2012Parser::Final_constructContext *context) = 0;

    virtual antlrcpp::Any visitBlocking_assignment(sv2012Parser::Blocking_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitOperator_assignment(sv2012Parser::Operator_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_operator(sv2012Parser::Assignment_operatorContext *context) = 0;

    virtual antlrcpp::Any visitNonblocking_assignment(sv2012Parser::Nonblocking_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_continuous_assignment(sv2012Parser::Procedural_continuous_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitVariable_assignment(sv2012Parser::Variable_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitAction_block(sv2012Parser::Action_blockContext *context) = 0;

    virtual antlrcpp::Any visitSeq_block(sv2012Parser::Seq_blockContext *context) = 0;

    virtual antlrcpp::Any visitPar_block(sv2012Parser::Par_blockContext *context) = 0;

    virtual antlrcpp::Any visitJoin_keyword(sv2012Parser::Join_keywordContext *context) = 0;

    virtual antlrcpp::Any visitStatement_or_null(sv2012Parser::Statement_or_nullContext *context) = 0;

    virtual antlrcpp::Any visitStatement(sv2012Parser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitStatement_item(sv2012Parser::Statement_itemContext *context) = 0;

    virtual antlrcpp::Any visitFunction_statement(sv2012Parser::Function_statementContext *context) = 0;

    virtual antlrcpp::Any visitFunction_statement_or_null(sv2012Parser::Function_statement_or_nullContext *context) = 0;

    virtual antlrcpp::Any visitVariable_identifier_list(sv2012Parser::Variable_identifier_listContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_timing_control_statement(sv2012Parser::Procedural_timing_control_statementContext *context) = 0;

    virtual antlrcpp::Any visitDelay_or_event_control(sv2012Parser::Delay_or_event_controlContext *context) = 0;

    virtual antlrcpp::Any visitDelay_control(sv2012Parser::Delay_controlContext *context) = 0;

    virtual antlrcpp::Any visitEvent_control(sv2012Parser::Event_controlContext *context) = 0;

    virtual antlrcpp::Any visitEvent_expression(sv2012Parser::Event_expressionContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_timing_control(sv2012Parser::Procedural_timing_controlContext *context) = 0;

    virtual antlrcpp::Any visitJump_statement(sv2012Parser::Jump_statementContext *context) = 0;

    virtual antlrcpp::Any visitWait_statement(sv2012Parser::Wait_statementContext *context) = 0;

    virtual antlrcpp::Any visitEvent_trigger(sv2012Parser::Event_triggerContext *context) = 0;

    virtual antlrcpp::Any visitDisable_statement(sv2012Parser::Disable_statementContext *context) = 0;

    virtual antlrcpp::Any visitConditional_statement(sv2012Parser::Conditional_statementContext *context) = 0;

    virtual antlrcpp::Any visitUnique_priority(sv2012Parser::Unique_priorityContext *context) = 0;

    virtual antlrcpp::Any visitCond_predicate(sv2012Parser::Cond_predicateContext *context) = 0;

    virtual antlrcpp::Any visitExpression_or_cond_pattern(sv2012Parser::Expression_or_cond_patternContext *context) = 0;

    virtual antlrcpp::Any visitCond_pattern(sv2012Parser::Cond_patternContext *context) = 0;

    virtual antlrcpp::Any visitCase_statement(sv2012Parser::Case_statementContext *context) = 0;

    virtual antlrcpp::Any visitCase_keyword(sv2012Parser::Case_keywordContext *context) = 0;

    virtual antlrcpp::Any visitCase_expression(sv2012Parser::Case_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCase_item(sv2012Parser::Case_itemContext *context) = 0;

    virtual antlrcpp::Any visitCase_pattern_item(sv2012Parser::Case_pattern_itemContext *context) = 0;

    virtual antlrcpp::Any visitCase_inside_item(sv2012Parser::Case_inside_itemContext *context) = 0;

    virtual antlrcpp::Any visitCase_item_expression(sv2012Parser::Case_item_expressionContext *context) = 0;

    virtual antlrcpp::Any visitRandcase_statement(sv2012Parser::Randcase_statementContext *context) = 0;

    virtual antlrcpp::Any visitRandcase_item(sv2012Parser::Randcase_itemContext *context) = 0;

    virtual antlrcpp::Any visitOpen_range_list(sv2012Parser::Open_range_listContext *context) = 0;

    virtual antlrcpp::Any visitOpen_value_range(sv2012Parser::Open_value_rangeContext *context) = 0;

    virtual antlrcpp::Any visitPattern(sv2012Parser::PatternContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern(sv2012Parser::Assignment_patternContext *context) = 0;

    virtual antlrcpp::Any visitStructure_pattern_key(sv2012Parser::Structure_pattern_keyContext *context) = 0;

    virtual antlrcpp::Any visitArray_pattern_key(sv2012Parser::Array_pattern_keyContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_key(sv2012Parser::Assignment_pattern_keyContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_expression(sv2012Parser::Assignment_pattern_expressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_expression_type(sv2012Parser::Assignment_pattern_expression_typeContext *context) = 0;

    virtual antlrcpp::Any visitConstant_assignment_pattern_expression(sv2012Parser::Constant_assignment_pattern_expressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_net_lvalue(sv2012Parser::Assignment_pattern_net_lvalueContext *context) = 0;

    virtual antlrcpp::Any visitAssignment_pattern_variable_lvalue(sv2012Parser::Assignment_pattern_variable_lvalueContext *context) = 0;

    virtual antlrcpp::Any visitLoop_statement(sv2012Parser::Loop_statementContext *context) = 0;

    virtual antlrcpp::Any visitFor_initialization(sv2012Parser::For_initializationContext *context) = 0;

    virtual antlrcpp::Any visitFor_variable_declaration(sv2012Parser::For_variable_declarationContext *context) = 0;

    virtual antlrcpp::Any visitFor_step(sv2012Parser::For_stepContext *context) = 0;

    virtual antlrcpp::Any visitFor_step_assignment(sv2012Parser::For_step_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitLoop_variables(sv2012Parser::Loop_variablesContext *context) = 0;

    virtual antlrcpp::Any visitSubroutine_call_statement(sv2012Parser::Subroutine_call_statementContext *context) = 0;

    virtual antlrcpp::Any visitAssertion_item(sv2012Parser::Assertion_itemContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_assertion_item(sv2012Parser::Deferred_immediate_assertion_itemContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_assertion_statement(sv2012Parser::Procedural_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitImmediate_assertion_statement(sv2012Parser::Immediate_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimple_immediate_assertion_statement(sv2012Parser::Simple_immediate_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimple_immediate_assert_statement(sv2012Parser::Simple_immediate_assert_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimple_immediate_assume_statement(sv2012Parser::Simple_immediate_assume_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimple_immediate_cover_statement(sv2012Parser::Simple_immediate_cover_statementContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_assertion_statement(sv2012Parser::Deferred_immediate_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_assert_statement(sv2012Parser::Deferred_immediate_assert_statementContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_assume_statement(sv2012Parser::Deferred_immediate_assume_statementContext *context) = 0;

    virtual antlrcpp::Any visitDeferred_immediate_cover_statement(sv2012Parser::Deferred_immediate_cover_statementContext *context) = 0;

    virtual antlrcpp::Any visitClocking_declaration(sv2012Parser::Clocking_declarationContext *context) = 0;

    virtual antlrcpp::Any visitClocking_event(sv2012Parser::Clocking_eventContext *context) = 0;

    virtual antlrcpp::Any visitClocking_item(sv2012Parser::Clocking_itemContext *context) = 0;

    virtual antlrcpp::Any visitDefault_skew(sv2012Parser::Default_skewContext *context) = 0;

    virtual antlrcpp::Any visitClocking_direction(sv2012Parser::Clocking_directionContext *context) = 0;

    virtual antlrcpp::Any visitList_of_clocking_decl_assign(sv2012Parser::List_of_clocking_decl_assignContext *context) = 0;

    virtual antlrcpp::Any visitClocking_decl_assign(sv2012Parser::Clocking_decl_assignContext *context) = 0;

    virtual antlrcpp::Any visitClocking_skew(sv2012Parser::Clocking_skewContext *context) = 0;

    virtual antlrcpp::Any visitClocking_drive(sv2012Parser::Clocking_driveContext *context) = 0;

    virtual antlrcpp::Any visitCycle_delay(sv2012Parser::Cycle_delayContext *context) = 0;

    virtual antlrcpp::Any visitClockvar(sv2012Parser::ClockvarContext *context) = 0;

    virtual antlrcpp::Any visitClockvar_expression(sv2012Parser::Clockvar_expressionContext *context) = 0;

    virtual antlrcpp::Any visitRandsequence_statement(sv2012Parser::Randsequence_statementContext *context) = 0;

    virtual antlrcpp::Any visitProduction(sv2012Parser::ProductionContext *context) = 0;

    virtual antlrcpp::Any visitRs_rule(sv2012Parser::Rs_ruleContext *context) = 0;

    virtual antlrcpp::Any visitRs_production_list(sv2012Parser::Rs_production_listContext *context) = 0;

    virtual antlrcpp::Any visitWeight_specification(sv2012Parser::Weight_specificationContext *context) = 0;

    virtual antlrcpp::Any visitRs_code_block(sv2012Parser::Rs_code_blockContext *context) = 0;

    virtual antlrcpp::Any visitRs_prod(sv2012Parser::Rs_prodContext *context) = 0;

    virtual antlrcpp::Any visitProduction_item(sv2012Parser::Production_itemContext *context) = 0;

    virtual antlrcpp::Any visitRs_if_else(sv2012Parser::Rs_if_elseContext *context) = 0;

    virtual antlrcpp::Any visitRs_repeat(sv2012Parser::Rs_repeatContext *context) = 0;

    virtual antlrcpp::Any visitRs_case(sv2012Parser::Rs_caseContext *context) = 0;

    virtual antlrcpp::Any visitRs_case_item(sv2012Parser::Rs_case_itemContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_block(sv2012Parser::Specify_blockContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_item(sv2012Parser::Specify_itemContext *context) = 0;

    virtual antlrcpp::Any visitPulsestyle_declaration(sv2012Parser::Pulsestyle_declarationContext *context) = 0;

    virtual antlrcpp::Any visitShowcancelled_declaration(sv2012Parser::Showcancelled_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPath_declaration(sv2012Parser::Path_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSimple_path_declaration(sv2012Parser::Simple_path_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParallel_path_description(sv2012Parser::Parallel_path_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitFull_path_description(sv2012Parser::Full_path_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitList_of_path_inputs(sv2012Parser::List_of_path_inputsContext *context) = 0;

    virtual antlrcpp::Any visitList_of_path_outputs(sv2012Parser::List_of_path_outputsContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_input_terminal_descriptor(sv2012Parser::Specify_input_terminal_descriptorContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_output_terminal_descriptor(sv2012Parser::Specify_output_terminal_descriptorContext *context) = 0;

    virtual antlrcpp::Any visitInput_identifier(sv2012Parser::Input_identifierContext *context) = 0;

    virtual antlrcpp::Any visitOutput_identifier(sv2012Parser::Output_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPath_delay_value(sv2012Parser::Path_delay_valueContext *context) = 0;

    virtual antlrcpp::Any visitList_of_path_delay_expressions(sv2012Parser::List_of_path_delay_expressionsContext *context) = 0;

    virtual antlrcpp::Any visitT_path_delay_expression(sv2012Parser::T_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTrise_path_delay_expression(sv2012Parser::Trise_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTfall_path_delay_expression(sv2012Parser::Tfall_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTz_path_delay_expression(sv2012Parser::Tz_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT01_path_delay_expression(sv2012Parser::T01_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT10_path_delay_expression(sv2012Parser::T10_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT0z_path_delay_expression(sv2012Parser::T0z_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTz1_path_delay_expression(sv2012Parser::Tz1_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT1z_path_delay_expression(sv2012Parser::T1z_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTz0_path_delay_expression(sv2012Parser::Tz0_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT0x_path_delay_expression(sv2012Parser::T0x_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTx1_path_delay_expression(sv2012Parser::Tx1_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitT1x_path_delay_expression(sv2012Parser::T1x_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTx0_path_delay_expression(sv2012Parser::Tx0_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTxz_path_delay_expression(sv2012Parser::Txz_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTzx_path_delay_expression(sv2012Parser::Tzx_path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPath_delay_expression(sv2012Parser::Path_delay_expressionContext *context) = 0;

    virtual antlrcpp::Any visitEdge_sensitive_path_declaration(sv2012Parser::Edge_sensitive_path_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParallel_edge_sensitive_path_description(sv2012Parser::Parallel_edge_sensitive_path_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitFull_edge_sensitive_path_description(sv2012Parser::Full_edge_sensitive_path_descriptionContext *context) = 0;

    virtual antlrcpp::Any visitData_source_expression(sv2012Parser::Data_source_expressionContext *context) = 0;

    virtual antlrcpp::Any visitEdge_identifier(sv2012Parser::Edge_identifierContext *context) = 0;

    virtual antlrcpp::Any visitState_dependent_path_declaration(sv2012Parser::State_dependent_path_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPolarity_operator(sv2012Parser::Polarity_operatorContext *context) = 0;

    virtual antlrcpp::Any visitSystem_timing_check(sv2012Parser::System_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitSetup_timing_check(sv2012Parser::Setup_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitHold_timing_check(sv2012Parser::Hold_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitSetuphold_timing_check(sv2012Parser::Setuphold_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitRecovery_timing_check(sv2012Parser::Recovery_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitRemoval_timing_check(sv2012Parser::Removal_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitRecrem_timing_check(sv2012Parser::Recrem_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitSkew_timing_check(sv2012Parser::Skew_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitTimeskew_timing_check(sv2012Parser::Timeskew_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitFullskew_timing_check(sv2012Parser::Fullskew_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitPeriod_timing_check(sv2012Parser::Period_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitWidth_timing_check(sv2012Parser::Width_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitNochange_timing_check(sv2012Parser::Nochange_timing_checkContext *context) = 0;

    virtual antlrcpp::Any visitTimecheck_condition(sv2012Parser::Timecheck_conditionContext *context) = 0;

    virtual antlrcpp::Any visitControlled_reference_event(sv2012Parser::Controlled_reference_eventContext *context) = 0;

    virtual antlrcpp::Any visitData_event(sv2012Parser::Data_eventContext *context) = 0;

    virtual antlrcpp::Any visitDelayed_data(sv2012Parser::Delayed_dataContext *context) = 0;

    virtual antlrcpp::Any visitDelayed_reference(sv2012Parser::Delayed_referenceContext *context) = 0;

    virtual antlrcpp::Any visitEnd_edge_offset(sv2012Parser::End_edge_offsetContext *context) = 0;

    virtual antlrcpp::Any visitEvent_based_flag(sv2012Parser::Event_based_flagContext *context) = 0;

    virtual antlrcpp::Any visitNotifier(sv2012Parser::NotifierContext *context) = 0;

    virtual antlrcpp::Any visitReference_event(sv2012Parser::Reference_eventContext *context) = 0;

    virtual antlrcpp::Any visitRemain_active_flag(sv2012Parser::Remain_active_flagContext *context) = 0;

    virtual antlrcpp::Any visitTimestamp_condition(sv2012Parser::Timestamp_conditionContext *context) = 0;

    virtual antlrcpp::Any visitStart_edge_offset(sv2012Parser::Start_edge_offsetContext *context) = 0;

    virtual antlrcpp::Any visitThreshold(sv2012Parser::ThresholdContext *context) = 0;

    virtual antlrcpp::Any visitTiming_check_limit(sv2012Parser::Timing_check_limitContext *context) = 0;

    virtual antlrcpp::Any visitTiming_check_event(sv2012Parser::Timing_check_eventContext *context) = 0;

    virtual antlrcpp::Any visitControlled_timing_check_event(sv2012Parser::Controlled_timing_check_eventContext *context) = 0;

    virtual antlrcpp::Any visitTiming_check_event_control(sv2012Parser::Timing_check_event_controlContext *context) = 0;

    virtual antlrcpp::Any visitSpecify_terminal_descriptor(sv2012Parser::Specify_terminal_descriptorContext *context) = 0;

    virtual antlrcpp::Any visitEdge_control_specifier(sv2012Parser::Edge_control_specifierContext *context) = 0;

    virtual antlrcpp::Any visitEdge_descriptor(sv2012Parser::Edge_descriptorContext *context) = 0;

    virtual antlrcpp::Any visitTiming_check_condition(sv2012Parser::Timing_check_conditionContext *context) = 0;

    virtual antlrcpp::Any visitScalar_timing_check_condition(sv2012Parser::Scalar_timing_check_conditionContext *context) = 0;

    virtual antlrcpp::Any visitScalar_constant(sv2012Parser::Scalar_constantContext *context) = 0;

    virtual antlrcpp::Any visitConcatenation(sv2012Parser::ConcatenationContext *context) = 0;

    virtual antlrcpp::Any visitConstant_concatenation(sv2012Parser::Constant_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitConstant_multiple_concatenation(sv2012Parser::Constant_multiple_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitModule_path_concatenation(sv2012Parser::Module_path_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitModule_path_multiple_concatenation(sv2012Parser::Module_path_multiple_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitMultiple_concatenation(sv2012Parser::Multiple_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitStreaming_concatenation(sv2012Parser::Streaming_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitStream_operator(sv2012Parser::Stream_operatorContext *context) = 0;

    virtual antlrcpp::Any visitSlice_size(sv2012Parser::Slice_sizeContext *context) = 0;

    virtual antlrcpp::Any visitStream_concatenation(sv2012Parser::Stream_concatenationContext *context) = 0;

    virtual antlrcpp::Any visitStream_expression(sv2012Parser::Stream_expressionContext *context) = 0;

    virtual antlrcpp::Any visitArray_range_expression(sv2012Parser::Array_range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitEmpty_queue(sv2012Parser::Empty_queueContext *context) = 0;

    virtual antlrcpp::Any visitConstant_function_call(sv2012Parser::Constant_function_callContext *context) = 0;

    virtual antlrcpp::Any visitTf_call(sv2012Parser::Tf_callContext *context) = 0;

    virtual antlrcpp::Any visitSystem_tf_call(sv2012Parser::System_tf_callContext *context) = 0;

    virtual antlrcpp::Any visitFunction_subroutine_call(sv2012Parser::Function_subroutine_callContext *context) = 0;

    virtual antlrcpp::Any visitSubroutine_call(sv2012Parser::Subroutine_callContext *context) = 0;

    virtual antlrcpp::Any visitMethod_call(sv2012Parser::Method_callContext *context) = 0;

    virtual antlrcpp::Any visitMethod_call_root(sv2012Parser::Method_call_rootContext *context) = 0;

    virtual antlrcpp::Any visitList_of_arguments(sv2012Parser::List_of_argumentsContext *context) = 0;

    virtual antlrcpp::Any visitMethod_call_body(sv2012Parser::Method_call_bodyContext *context) = 0;

    virtual antlrcpp::Any visitBuilt_in_method_call(sv2012Parser::Built_in_method_callContext *context) = 0;

    virtual antlrcpp::Any visitArray_manipulation_call(sv2012Parser::Array_manipulation_callContext *context) = 0;

    virtual antlrcpp::Any visitRandomize_call(sv2012Parser::Randomize_callContext *context) = 0;

    virtual antlrcpp::Any visitArray_method_name(sv2012Parser::Array_method_nameContext *context) = 0;

    virtual antlrcpp::Any visitInc_or_dec_expression(sv2012Parser::Inc_or_dec_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConditional_expression(sv2012Parser::Conditional_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_expression(sv2012Parser::Constant_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_mintypmax_expression(sv2012Parser::Constant_mintypmax_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_param_expression(sv2012Parser::Constant_param_expressionContext *context) = 0;

    virtual antlrcpp::Any visitParam_expression(sv2012Parser::Param_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_range_expression(sv2012Parser::Constant_range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_part_select_range(sv2012Parser::Constant_part_select_rangeContext *context) = 0;

    virtual antlrcpp::Any visitConstant_range(sv2012Parser::Constant_rangeContext *context) = 0;

    virtual antlrcpp::Any visitConstant_indexed_range(sv2012Parser::Constant_indexed_rangeContext *context) = 0;

    virtual antlrcpp::Any visitExpression_cond_or_inside(sv2012Parser::Expression_cond_or_insideContext *context) = 0;

    virtual antlrcpp::Any visitExpression(sv2012Parser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTagged_union_expression(sv2012Parser::Tagged_union_expressionContext *context) = 0;

    virtual antlrcpp::Any visitInside_expression(sv2012Parser::Inside_expressionContext *context) = 0;

    virtual antlrcpp::Any visitValue_range(sv2012Parser::Value_rangeContext *context) = 0;

    virtual antlrcpp::Any visitMintypmax_expression(sv2012Parser::Mintypmax_expressionContext *context) = 0;

    virtual antlrcpp::Any visitModule_path_conditional_expression(sv2012Parser::Module_path_conditional_expressionContext *context) = 0;

    virtual antlrcpp::Any visitModule_path_expression(sv2012Parser::Module_path_expressionContext *context) = 0;

    virtual antlrcpp::Any visitModule_path_mintypmax_expression(sv2012Parser::Module_path_mintypmax_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPart_select_range(sv2012Parser::Part_select_rangeContext *context) = 0;

    virtual antlrcpp::Any visitIndexed_range(sv2012Parser::Indexed_rangeContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_expression(sv2012Parser::Genvar_expressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant_primary(sv2012Parser::Constant_primaryContext *context) = 0;

    virtual antlrcpp::Any visitModule_path_primary(sv2012Parser::Module_path_primaryContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(sv2012Parser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitClass_qualifier(sv2012Parser::Class_qualifierContext *context) = 0;

    virtual antlrcpp::Any visitRange_expression(sv2012Parser::Range_expressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_literal(sv2012Parser::Primary_literalContext *context) = 0;

    virtual antlrcpp::Any visitTime_literal(sv2012Parser::Time_literalContext *context) = 0;

    virtual antlrcpp::Any visitTime_unit(sv2012Parser::Time_unitContext *context) = 0;

    virtual antlrcpp::Any visitImplicit_class_handle(sv2012Parser::Implicit_class_handleContext *context) = 0;

    virtual antlrcpp::Any visitBit_select(sv2012Parser::Bit_selectContext *context) = 0;

    virtual antlrcpp::Any visitSelect(sv2012Parser::SelectContext *context) = 0;

    virtual antlrcpp::Any visitNonrange_select(sv2012Parser::Nonrange_selectContext *context) = 0;

    virtual antlrcpp::Any visitConstant_bit_select(sv2012Parser::Constant_bit_selectContext *context) = 0;

    virtual antlrcpp::Any visitConstant_select(sv2012Parser::Constant_selectContext *context) = 0;

    virtual antlrcpp::Any visitConstant_cast(sv2012Parser::Constant_castContext *context) = 0;

    virtual antlrcpp::Any visitConstant_let_expression(sv2012Parser::Constant_let_expressionContext *context) = 0;

    virtual antlrcpp::Any visitCast(sv2012Parser::CastContext *context) = 0;

    virtual antlrcpp::Any visitNet_lvalue(sv2012Parser::Net_lvalueContext *context) = 0;

    virtual antlrcpp::Any visitVariable_lvalue(sv2012Parser::Variable_lvalueContext *context) = 0;

    virtual antlrcpp::Any visitNonrange_variable_lvalue(sv2012Parser::Nonrange_variable_lvalueContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(sv2012Parser::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitBinary_operator(sv2012Parser::Binary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitInc_or_dec_operator(sv2012Parser::Inc_or_dec_operatorContext *context) = 0;

    virtual antlrcpp::Any visitUnary_module_path_operator(sv2012Parser::Unary_module_path_operatorContext *context) = 0;

    virtual antlrcpp::Any visitBinary_module_path_operator(sv2012Parser::Binary_module_path_operatorContext *context) = 0;

    virtual antlrcpp::Any visitNumber(sv2012Parser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_instance(sv2012Parser::Attribute_instanceContext *context) = 0;

    virtual antlrcpp::Any visitAttr_spec(sv2012Parser::Attr_specContext *context) = 0;

    virtual antlrcpp::Any visitAttr_name(sv2012Parser::Attr_nameContext *context) = 0;

    virtual antlrcpp::Any visitArray_identifier(sv2012Parser::Array_identifierContext *context) = 0;

    virtual antlrcpp::Any visitBlock_identifier(sv2012Parser::Block_identifierContext *context) = 0;

    virtual antlrcpp::Any visitBin_identifier(sv2012Parser::Bin_identifierContext *context) = 0;

    virtual antlrcpp::Any visitC_identifier(sv2012Parser::C_identifierContext *context) = 0;

    virtual antlrcpp::Any visitCell_identifier(sv2012Parser::Cell_identifierContext *context) = 0;

    virtual antlrcpp::Any visitChecker_identifier(sv2012Parser::Checker_identifierContext *context) = 0;

    virtual antlrcpp::Any visitClass_identifier(sv2012Parser::Class_identifierContext *context) = 0;

    virtual antlrcpp::Any visitClass_variable_identifier(sv2012Parser::Class_variable_identifierContext *context) = 0;

    virtual antlrcpp::Any visitClocking_identifier(sv2012Parser::Clocking_identifierContext *context) = 0;

    virtual antlrcpp::Any visitConfig_identifier(sv2012Parser::Config_identifierContext *context) = 0;

    virtual antlrcpp::Any visitConst_identifier(sv2012Parser::Const_identifierContext *context) = 0;

    virtual antlrcpp::Any visitConstraint_identifier(sv2012Parser::Constraint_identifierContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_identifier(sv2012Parser::Covergroup_identifierContext *context) = 0;

    virtual antlrcpp::Any visitCovergroup_variable_identifier(sv2012Parser::Covergroup_variable_identifierContext *context) = 0;

    virtual antlrcpp::Any visitCover_point_identifier(sv2012Parser::Cover_point_identifierContext *context) = 0;

    virtual antlrcpp::Any visitCross_identifier(sv2012Parser::Cross_identifierContext *context) = 0;

    virtual antlrcpp::Any visitDynamic_array_variable_identifier(sv2012Parser::Dynamic_array_variable_identifierContext *context) = 0;

    virtual antlrcpp::Any visitEnum_identifier(sv2012Parser::Enum_identifierContext *context) = 0;

    virtual antlrcpp::Any visitFormal_identifier(sv2012Parser::Formal_identifierContext *context) = 0;

    virtual antlrcpp::Any visitFormal_port_identifier(sv2012Parser::Formal_port_identifierContext *context) = 0;

    virtual antlrcpp::Any visitFunction_identifier(sv2012Parser::Function_identifierContext *context) = 0;

    virtual antlrcpp::Any visitGenerate_block_identifier(sv2012Parser::Generate_block_identifierContext *context) = 0;

    virtual antlrcpp::Any visitGenvar_identifier(sv2012Parser::Genvar_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_array_identifier(sv2012Parser::Hierarchical_array_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_block_identifier(sv2012Parser::Hierarchical_block_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_event_identifier(sv2012Parser::Hierarchical_event_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_identifier(sv2012Parser::Hierarchical_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_net_identifier(sv2012Parser::Hierarchical_net_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_parameter_identifier(sv2012Parser::Hierarchical_parameter_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_property_identifier(sv2012Parser::Hierarchical_property_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_sequence_identifier(sv2012Parser::Hierarchical_sequence_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_task_identifier(sv2012Parser::Hierarchical_task_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_tf_identifier(sv2012Parser::Hierarchical_tf_identifierContext *context) = 0;

    virtual antlrcpp::Any visitHierarchical_variable_identifier(sv2012Parser::Hierarchical_variable_identifierContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(sv2012Parser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitIndex_variable_identifier(sv2012Parser::Index_variable_identifierContext *context) = 0;

    virtual antlrcpp::Any visitInterface_identifier(sv2012Parser::Interface_identifierContext *context) = 0;

    virtual antlrcpp::Any visitInterface_instance_identifier(sv2012Parser::Interface_instance_identifierContext *context) = 0;

    virtual antlrcpp::Any visitInout_port_identifier(sv2012Parser::Inout_port_identifierContext *context) = 0;

    virtual antlrcpp::Any visitInput_port_identifier(sv2012Parser::Input_port_identifierContext *context) = 0;

    virtual antlrcpp::Any visitInstance_identifier(sv2012Parser::Instance_identifierContext *context) = 0;

    virtual antlrcpp::Any visitLibrary_identifier(sv2012Parser::Library_identifierContext *context) = 0;

    virtual antlrcpp::Any visitMember_identifier(sv2012Parser::Member_identifierContext *context) = 0;

    virtual antlrcpp::Any visitMethod_identifier(sv2012Parser::Method_identifierContext *context) = 0;

    virtual antlrcpp::Any visitModport_identifier(sv2012Parser::Modport_identifierContext *context) = 0;

    virtual antlrcpp::Any visitModule_identifier(sv2012Parser::Module_identifierContext *context) = 0;

    virtual antlrcpp::Any visitNet_identifier(sv2012Parser::Net_identifierContext *context) = 0;

    virtual antlrcpp::Any visitNet_type_identifier(sv2012Parser::Net_type_identifierContext *context) = 0;

    virtual antlrcpp::Any visitOutput_port_identifier(sv2012Parser::Output_port_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPackage_identifier(sv2012Parser::Package_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPackage_scope(sv2012Parser::Package_scopeContext *context) = 0;

    virtual antlrcpp::Any visitParameter_identifier(sv2012Parser::Parameter_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPort_identifier(sv2012Parser::Port_identifierContext *context) = 0;

    virtual antlrcpp::Any visitProduction_identifier(sv2012Parser::Production_identifierContext *context) = 0;

    virtual antlrcpp::Any visitProgram_identifier(sv2012Parser::Program_identifierContext *context) = 0;

    virtual antlrcpp::Any visitProperty_identifier(sv2012Parser::Property_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_class_identifier(sv2012Parser::Ps_class_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_covergroup_identifier(sv2012Parser::Ps_covergroup_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_checker_identifier(sv2012Parser::Ps_checker_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_identifier(sv2012Parser::Ps_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_or_hierarchical_array_identifier(sv2012Parser::Ps_or_hierarchical_array_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_or_hierarchical_net_identifier(sv2012Parser::Ps_or_hierarchical_net_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_or_hierarchical_property_identifier(sv2012Parser::Ps_or_hierarchical_property_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_or_hierarchical_sequence_identifier(sv2012Parser::Ps_or_hierarchical_sequence_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_or_hierarchical_tf_identifier(sv2012Parser::Ps_or_hierarchical_tf_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_parameter_identifier(sv2012Parser::Ps_parameter_identifierContext *context) = 0;

    virtual antlrcpp::Any visitPs_type_identifier(sv2012Parser::Ps_type_identifierContext *context) = 0;

    virtual antlrcpp::Any visitSequence_identifier(sv2012Parser::Sequence_identifierContext *context) = 0;

    virtual antlrcpp::Any visitSignal_identifier(sv2012Parser::Signal_identifierContext *context) = 0;

    virtual antlrcpp::Any visitSpecparam_identifier(sv2012Parser::Specparam_identifierContext *context) = 0;

    virtual antlrcpp::Any visitTask_identifier(sv2012Parser::Task_identifierContext *context) = 0;

    virtual antlrcpp::Any visitTf_identifier(sv2012Parser::Tf_identifierContext *context) = 0;

    virtual antlrcpp::Any visitTerminal_identifier(sv2012Parser::Terminal_identifierContext *context) = 0;

    virtual antlrcpp::Any visitTopmodule_identifier(sv2012Parser::Topmodule_identifierContext *context) = 0;

    virtual antlrcpp::Any visitType_identifier(sv2012Parser::Type_identifierContext *context) = 0;

    virtual antlrcpp::Any visitUdp_identifier(sv2012Parser::Udp_identifierContext *context) = 0;

    virtual antlrcpp::Any visitVariable_identifier(sv2012Parser::Variable_identifierContext *context) = 0;


};

}  // namespace sv
