
// Generated from grammars/sv2012.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "sv2012Visitor.h"


namespace sv {

/**
 * This class provides an empty implementation of sv2012Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  sv2012BaseVisitor : public sv2012Visitor {
public:

  virtual antlrcpp::Any visitLibrary_text(sv2012Parser::Library_textContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibrary_description(sv2012Parser::Library_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibrary_declaration(sv2012Parser::Library_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInclude_statement(sv2012Parser::Include_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSource_text(sv2012Parser::Source_textContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDescription(sv2012Parser::DescriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_nonansi_header(sv2012Parser::Module_nonansi_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_ansi_header(sv2012Parser::Module_ansi_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_declaration(sv2012Parser::Module_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_keyword(sv2012Parser::Module_keywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_declaration(sv2012Parser::Interface_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_nonansi_header(sv2012Parser::Interface_nonansi_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_ansi_header(sv2012Parser::Interface_ansi_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_declaration(sv2012Parser::Program_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_nonansi_header(sv2012Parser::Program_nonansi_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_ansi_header(sv2012Parser::Program_ansi_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_declaration(sv2012Parser::Checker_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_declaration(sv2012Parser::Class_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_class_type(sv2012Parser::Interface_class_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_class_declaration(sv2012Parser::Interface_class_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_class_item(sv2012Parser::Interface_class_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_class_method(sv2012Parser::Interface_class_methodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_declaration(sv2012Parser::Package_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimeunits_declaration(sv2012Parser::Timeunits_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_port_list(sv2012Parser::Parameter_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_port_declaration(sv2012Parser::Parameter_port_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_ports(sv2012Parser::List_of_portsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_port_declarations(sv2012Parser::List_of_port_declarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_declaration(sv2012Parser::Port_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort(sv2012Parser::PortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_expression(sv2012Parser::Port_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_reference(sv2012Parser::Port_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_direction(sv2012Parser::Port_directionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_port_header(sv2012Parser::Net_port_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_port_header(sv2012Parser::Variable_port_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_port_header(sv2012Parser::Interface_port_headerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnsi_port_declaration(sv2012Parser::Ansi_port_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElaboration_system_task(sv2012Parser::Elaboration_system_taskContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFinish_number(sv2012Parser::Finish_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_common_item(sv2012Parser::Module_common_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_item(sv2012Parser::Module_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_or_generate_item(sv2012Parser::Module_or_generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_or_generate_item_declaration(sv2012Parser::Module_or_generate_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNon_port_module_item(sv2012Parser::Non_port_module_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_override(sv2012Parser::Parameter_overrideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBind_directive(sv2012Parser::Bind_directiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBind_target_scope(sv2012Parser::Bind_target_scopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBind_target_instance(sv2012Parser::Bind_target_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBind_target_instance_list(sv2012Parser::Bind_target_instance_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBind_instantiation(sv2012Parser::Bind_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfig_declaration(sv2012Parser::Config_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDesign_statement(sv2012Parser::Design_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfig_rule_statement(sv2012Parser::Config_rule_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefault_clause(sv2012Parser::Default_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInst_clause(sv2012Parser::Inst_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInst_name(sv2012Parser::Inst_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCell_clause(sv2012Parser::Cell_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiblist_clause(sv2012Parser::Liblist_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUse_clause(sv2012Parser::Use_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_or_generate_item(sv2012Parser::Interface_or_generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtern_tf_declaration(sv2012Parser::Extern_tf_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_item(sv2012Parser::Interface_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNon_port_interface_item(sv2012Parser::Non_port_interface_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_item(sv2012Parser::Program_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNon_port_program_item(sv2012Parser::Non_port_program_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_generate_item(sv2012Parser::Program_generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_port_list(sv2012Parser::Checker_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_port_item(sv2012Parser::Checker_port_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_port_direction(sv2012Parser::Checker_port_directionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_or_generate_item(sv2012Parser::Checker_or_generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_or_generate_item_declaration(sv2012Parser::Checker_or_generate_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_generate_item(sv2012Parser::Checker_generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_item(sv2012Parser::Class_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_property(sv2012Parser::Class_propertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_method(sv2012Parser::Class_methodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_constructor_prototype(sv2012Parser::Class_constructor_prototypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_constraint(sv2012Parser::Class_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_item_qualifier(sv2012Parser::Class_item_qualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_qualifier(sv2012Parser::Property_qualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRandom_qualifier(sv2012Parser::Random_qualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_qualifier(sv2012Parser::Method_qualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_prototype(sv2012Parser::Method_prototypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_constructor_declaration(sv2012Parser::Class_constructor_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_declaration(sv2012Parser::Constraint_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_block(sv2012Parser::Constraint_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_block_item(sv2012Parser::Constraint_block_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSolve_before_list(sv2012Parser::Solve_before_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_primary(sv2012Parser::Constraint_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_expression(sv2012Parser::Constraint_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUniqueness_constraint(sv2012Parser::Uniqueness_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_set(sv2012Parser::Constraint_setContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDist_list(sv2012Parser::Dist_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDist_item(sv2012Parser::Dist_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDist_weight(sv2012Parser::Dist_weightContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_prototype(sv2012Parser::Constraint_prototypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_prototype_qualifier(sv2012Parser::Constraint_prototype_qualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExtern_constraint_declaration(sv2012Parser::Extern_constraint_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier_list(sv2012Parser::Identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_item(sv2012Parser::Package_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_or_generate_item_declaration(sv2012Parser::Package_or_generate_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnonymous_program(sv2012Parser::Anonymous_programContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnonymous_program_item(sv2012Parser::Anonymous_program_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLocal_parameter_declaration(sv2012Parser::Local_parameter_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_declaration(sv2012Parser::Parameter_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecparam_declaration(sv2012Parser::Specparam_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInout_declaration(sv2012Parser::Inout_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInput_declaration(sv2012Parser::Input_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_declaration(sv2012Parser::Output_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_port_declaration(sv2012Parser::Interface_port_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRef_declaration(sv2012Parser::Ref_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData_declaration(sv2012Parser::Data_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_import_declaration(sv2012Parser::Package_import_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_import_item(sv2012Parser::Package_import_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_export_declaration(sv2012Parser::Package_export_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_declaration(sv2012Parser::Genvar_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_declaration(sv2012Parser::Net_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_declaration(sv2012Parser::Type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_type_declaration(sv2012Parser::Net_type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLifetime(sv2012Parser::LifetimeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCasting_type_reduced(sv2012Parser::Casting_type_reducedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCasting_type(sv2012Parser::Casting_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData_type(sv2012Parser::Data_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData_type_or_implicit(sv2012Parser::Data_type_or_implicitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImplicit_data_type(sv2012Parser::Implicit_data_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_base_type(sv2012Parser::Enum_base_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_name_declaration(sv2012Parser::Enum_name_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_scope(sv2012Parser::Class_scopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_type(sv2012Parser::Class_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_type(sv2012Parser::Integer_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_atom_type(sv2012Parser::Integer_atom_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_vector_type(sv2012Parser::Integer_vector_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNon_integer_type(sv2012Parser::Non_integer_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_type(sv2012Parser::Net_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_port_type(sv2012Parser::Net_port_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_port_type(sv2012Parser::Variable_port_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_data_type(sv2012Parser::Var_data_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSigning(sv2012Parser::SigningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_type(sv2012Parser::Simple_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct_union_member(sv2012Parser::Struct_union_memberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData_type_or_void(sv2012Parser::Data_type_or_voidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStruct_union(sv2012Parser::Struct_unionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_reference(sv2012Parser::Type_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDrive_strength(sv2012Parser::Drive_strengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrength0(sv2012Parser::Strength0Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStrength1(sv2012Parser::Strength1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharge_strength(sv2012Parser::Charge_strengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay3(sv2012Parser::Delay3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay2(sv2012Parser::Delay2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay_value(sv2012Parser::Delay_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_defparam_assignments(sv2012Parser::List_of_defparam_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_genvar_identifiers(sv2012Parser::List_of_genvar_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_interface_identifiers(sv2012Parser::List_of_interface_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_net_decl_assignments(sv2012Parser::List_of_net_decl_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_param_assignments(sv2012Parser::List_of_param_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_port_identifiers(sv2012Parser::List_of_port_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_udp_port_identifiers(sv2012Parser::List_of_udp_port_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_specparam_assignments(sv2012Parser::List_of_specparam_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_tf_variable_identifiers(sv2012Parser::List_of_tf_variable_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_type_assignments(sv2012Parser::List_of_type_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_variable_decl_assignments(sv2012Parser::List_of_variable_decl_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_variable_identifiers(sv2012Parser::List_of_variable_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_variable_port_identifiers(sv2012Parser::List_of_variable_port_identifiersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefparam_assignment(sv2012Parser::Defparam_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_decl_assignment(sv2012Parser::Net_decl_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_assignment(sv2012Parser::Param_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecparam_assignment(sv2012Parser::Specparam_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_assignment(sv2012Parser::Type_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPulse_control_specparam(sv2012Parser::Pulse_control_specparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitError_limit_value(sv2012Parser::Error_limit_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReject_limit_value(sv2012Parser::Reject_limit_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLimit_value(sv2012Parser::Limit_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_decl_assignment(sv2012Parser::Variable_decl_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_new(sv2012Parser::Class_newContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDynamic_array_new(sv2012Parser::Dynamic_array_newContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnpacked_dimension(sv2012Parser::Unpacked_dimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPacked_dimension(sv2012Parser::Packed_dimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssociative_dimension(sv2012Parser::Associative_dimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_dimension(sv2012Parser::Variable_dimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQueue_dimension(sv2012Parser::Queue_dimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsized_dimension(sv2012Parser::Unsized_dimensionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_data_type_or_implicit(sv2012Parser::Function_data_type_or_implicitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_declaration(sv2012Parser::Function_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_body_declaration(sv2012Parser::Function_body_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_prototype(sv2012Parser::Function_prototypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDpi_import_export(sv2012Parser::Dpi_import_exportContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDpi_spec_string(sv2012Parser::Dpi_spec_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDpi_function_import_property(sv2012Parser::Dpi_function_import_propertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDpi_task_import_property(sv2012Parser::Dpi_task_import_propertyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDpi_function_proto(sv2012Parser::Dpi_function_protoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDpi_task_proto(sv2012Parser::Dpi_task_protoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_declaration(sv2012Parser::Task_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_body_declaration(sv2012Parser::Task_body_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_item_declaration(sv2012Parser::Tf_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_port_list(sv2012Parser::Tf_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_port_item(sv2012Parser::Tf_port_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_port_direction(sv2012Parser::Tf_port_directionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_port_declaration(sv2012Parser::Tf_port_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_prototype(sv2012Parser::Task_prototypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_item_declaration(sv2012Parser::Block_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOverload_declaration(sv2012Parser::Overload_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOverload_operator(sv2012Parser::Overload_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOverload_proto_formals(sv2012Parser::Overload_proto_formalsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_declaration(sv2012Parser::Modport_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_item(sv2012Parser::Modport_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_ports_declaration(sv2012Parser::Modport_ports_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_clocking_declaration(sv2012Parser::Modport_clocking_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_simple_ports_declaration(sv2012Parser::Modport_simple_ports_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_simple_port(sv2012Parser::Modport_simple_portContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_tf_ports_declaration(sv2012Parser::Modport_tf_ports_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_tf_port(sv2012Parser::Modport_tf_portContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_export(sv2012Parser::Import_exportContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_assertion_item(sv2012Parser::Concurrent_assertion_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcurrent_assertion_statement(sv2012Parser::Concurrent_assertion_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssert_property_statement(sv2012Parser::Assert_property_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssume_property_statement(sv2012Parser::Assume_property_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCover_property_statement(sv2012Parser::Cover_property_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpect_property_statement(sv2012Parser::Expect_property_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCover_sequence_statement(sv2012Parser::Cover_sequence_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRestrict_property_statement(sv2012Parser::Restrict_property_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_instance(sv2012Parser::Property_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_list_of_arguments(sv2012Parser::Property_list_of_argumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_actual_arg(sv2012Parser::Property_actual_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssertion_item_declaration(sv2012Parser::Assertion_item_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_declaration(sv2012Parser::Property_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_port_list(sv2012Parser::Property_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_port_item(sv2012Parser::Property_port_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_lvar_port_direction(sv2012Parser::Property_lvar_port_directionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_formal_type(sv2012Parser::Property_formal_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_spec(sv2012Parser::Property_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_expr(sv2012Parser::Property_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_case_item(sv2012Parser::Property_case_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_declaration(sv2012Parser::Sequence_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_port_list(sv2012Parser::Sequence_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_port_item(sv2012Parser::Sequence_port_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_lvar_port_direction(sv2012Parser::Sequence_lvar_port_directionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_formal_type(sv2012Parser::Sequence_formal_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_expr(sv2012Parser::Sequence_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCycle_delay_range(sv2012Parser::Cycle_delay_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_method_call(sv2012Parser::Sequence_method_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_match_item(sv2012Parser::Sequence_match_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_instance(sv2012Parser::Sequence_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_list_of_arguments(sv2012Parser::Sequence_list_of_argumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_actual_arg(sv2012Parser::Sequence_actual_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_abbrev(sv2012Parser::Boolean_abbrevContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_abbrev(sv2012Parser::Sequence_abbrevContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConsecutive_repetition(sv2012Parser::Consecutive_repetitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNon_consecutive_repetition(sv2012Parser::Non_consecutive_repetitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGoto_repetition(sv2012Parser::Goto_repetitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_or_range_expression(sv2012Parser::Const_or_range_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCycle_delay_const_range_expression(sv2012Parser::Cycle_delay_const_range_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_or_dist(sv2012Parser::Expression_or_distContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssertion_variable_declaration(sv2012Parser::Assertion_variable_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet_declaration(sv2012Parser::Let_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet_identifier(sv2012Parser::Let_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet_port_list(sv2012Parser::Let_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet_port_item(sv2012Parser::Let_port_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet_formal_type(sv2012Parser::Let_formal_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet_expression(sv2012Parser::Let_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet_list_of_arguments(sv2012Parser::Let_list_of_argumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet_actual_arg(sv2012Parser::Let_actual_argContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCovergroup_declaration(sv2012Parser::Covergroup_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCoverage_spec_or_option(sv2012Parser::Coverage_spec_or_optionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCoverage_option(sv2012Parser::Coverage_optionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCoverage_spec(sv2012Parser::Coverage_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCoverage_event(sv2012Parser::Coverage_eventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_event_expression(sv2012Parser::Block_event_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_btf_identifier(sv2012Parser::Hierarchical_btf_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCover_point(sv2012Parser::Cover_pointContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBins_or_empty(sv2012Parser::Bins_or_emptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBins_or_options(sv2012Parser::Bins_or_optionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBins_keyword(sv2012Parser::Bins_keywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrans_list(sv2012Parser::Trans_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrans_set(sv2012Parser::Trans_setContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrans_range_list(sv2012Parser::Trans_range_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrans_item(sv2012Parser::Trans_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeat_range(sv2012Parser::Repeat_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCover_cross(sv2012Parser::Cover_crossContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_cross_items(sv2012Parser::List_of_cross_itemsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCross_item(sv2012Parser::Cross_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCross_body(sv2012Parser::Cross_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCross_body_item(sv2012Parser::Cross_body_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBins_selection_or_option(sv2012Parser::Bins_selection_or_optionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBins_selection(sv2012Parser::Bins_selectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_expression(sv2012Parser::Select_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_condition(sv2012Parser::Select_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBins_expression(sv2012Parser::Bins_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCovergroup_range_list(sv2012Parser::Covergroup_range_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCovergroup_value_range(sv2012Parser::Covergroup_value_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWith_covergroup_expression(sv2012Parser::With_covergroup_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSet_covergroup_expression(sv2012Parser::Set_covergroup_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInteger_covergroup_expression(sv2012Parser::Integer_covergroup_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCross_set_expression(sv2012Parser::Cross_set_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCovergroup_expression(sv2012Parser::Covergroup_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGate_instantiation(sv2012Parser::Gate_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCmos_switch_instance(sv2012Parser::Cmos_switch_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnable_gate_instance(sv2012Parser::Enable_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMos_switch_instance(sv2012Parser::Mos_switch_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitN_input_gate_instance(sv2012Parser::N_input_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitN_output_gate_instance(sv2012Parser::N_output_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_switch_instance(sv2012Parser::Pass_switch_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_enable_switch_instance(sv2012Parser::Pass_enable_switch_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPull_gate_instance(sv2012Parser::Pull_gate_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPulldown_strength(sv2012Parser::Pulldown_strengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPullup_strength(sv2012Parser::Pullup_strengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnable_terminal(sv2012Parser::Enable_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInout_terminal(sv2012Parser::Inout_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInput_terminal(sv2012Parser::Input_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNcontrol_terminal(sv2012Parser::Ncontrol_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_terminal(sv2012Parser::Output_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPcontrol_terminal(sv2012Parser::Pcontrol_terminalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCmos_switchtype(sv2012Parser::Cmos_switchtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnable_gatetype(sv2012Parser::Enable_gatetypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMos_switchtype(sv2012Parser::Mos_switchtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitN_input_gatetype(sv2012Parser::N_input_gatetypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitN_output_gatetype(sv2012Parser::N_output_gatetypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_en_switchtype(sv2012Parser::Pass_en_switchtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_switchtype(sv2012Parser::Pass_switchtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_instantiation(sv2012Parser::Module_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_value_assignment(sv2012Parser::Parameter_value_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_parameter_assignments(sv2012Parser::List_of_parameter_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrdered_parameter_assignment(sv2012Parser::Ordered_parameter_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_parameter_assignment(sv2012Parser::Named_parameter_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_instance(sv2012Parser::Hierarchical_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName_of_instance(sv2012Parser::Name_of_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_port_connections(sv2012Parser::List_of_port_connectionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrdered_port_connection(sv2012Parser::Ordered_port_connectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_port_connection(sv2012Parser::Named_port_connectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_instantiation(sv2012Parser::Interface_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_instantiation(sv2012Parser::Program_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_instantiation(sv2012Parser::Checker_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_checker_port_connections(sv2012Parser::List_of_checker_port_connectionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOrdered_checker_port_connection(sv2012Parser::Ordered_checker_port_connectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamed_checker_port_connection(sv2012Parser::Named_checker_port_connectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_region(sv2012Parser::Generate_regionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop_generate_construct(sv2012Parser::Loop_generate_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_initialization(sv2012Parser::Genvar_initializationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_iteration(sv2012Parser::Genvar_iterationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_generate_construct(sv2012Parser::Conditional_generate_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_generate_construct(sv2012Parser::If_generate_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_generate_construct(sv2012Parser::Case_generate_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_generate_item(sv2012Parser::Case_generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_block(sv2012Parser::Generate_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_item(sv2012Parser::Generate_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_nonansi_declaration(sv2012Parser::Udp_nonansi_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_ansi_declaration(sv2012Parser::Udp_ansi_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_declaration(sv2012Parser::Udp_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_port_list(sv2012Parser::Udp_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_declaration_port_list(sv2012Parser::Udp_declaration_port_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_port_declaration(sv2012Parser::Udp_port_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_output_declaration(sv2012Parser::Udp_output_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_input_declaration(sv2012Parser::Udp_input_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_reg_declaration(sv2012Parser::Udp_reg_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_body(sv2012Parser::Udp_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCombinational_body(sv2012Parser::Combinational_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCombinational_entry(sv2012Parser::Combinational_entryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequential_body(sv2012Parser::Sequential_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_initial_statement(sv2012Parser::Udp_initial_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInit_val(sv2012Parser::Init_valContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequential_entry(sv2012Parser::Sequential_entryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSeq_input_list(sv2012Parser::Seq_input_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLevel_input_list(sv2012Parser::Level_input_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_input_list(sv2012Parser::Edge_input_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_indicator(sv2012Parser::Edge_indicatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCurrent_state(sv2012Parser::Current_stateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNext_state(sv2012Parser::Next_stateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_symbol(sv2012Parser::Output_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLevel_symbol(sv2012Parser::Level_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_symbol(sv2012Parser::Edge_symbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_instantiation(sv2012Parser::Udp_instantiationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_instance(sv2012Parser::Udp_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinuous_assign(sv2012Parser::Continuous_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_net_assignments(sv2012Parser::List_of_net_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_variable_assignments(sv2012Parser::List_of_variable_assignmentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_alias(sv2012Parser::Net_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_assignment(sv2012Parser::Net_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInitial_construct(sv2012Parser::Initial_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlways_construct(sv2012Parser::Always_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlways_keyword(sv2012Parser::Always_keywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFinal_construct(sv2012Parser::Final_constructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlocking_assignment(sv2012Parser::Blocking_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperator_assignment(sv2012Parser::Operator_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_operator(sv2012Parser::Assignment_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonblocking_assignment(sv2012Parser::Nonblocking_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedural_continuous_assignment(sv2012Parser::Procedural_continuous_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_assignment(sv2012Parser::Variable_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction_block(sv2012Parser::Action_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSeq_block(sv2012Parser::Seq_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPar_block(sv2012Parser::Par_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_keyword(sv2012Parser::Join_keywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_or_null(sv2012Parser::Statement_or_nullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(sv2012Parser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_item(sv2012Parser::Statement_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_statement(sv2012Parser::Function_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_statement_or_null(sv2012Parser::Function_statement_or_nullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_identifier_list(sv2012Parser::Variable_identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedural_timing_control_statement(sv2012Parser::Procedural_timing_control_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay_or_event_control(sv2012Parser::Delay_or_event_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelay_control(sv2012Parser::Delay_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_control(sv2012Parser::Event_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_expression(sv2012Parser::Event_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedural_timing_control(sv2012Parser::Procedural_timing_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJump_statement(sv2012Parser::Jump_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWait_statement(sv2012Parser::Wait_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_trigger(sv2012Parser::Event_triggerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDisable_statement(sv2012Parser::Disable_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_statement(sv2012Parser::Conditional_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnique_priority(sv2012Parser::Unique_priorityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond_predicate(sv2012Parser::Cond_predicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_or_cond_pattern(sv2012Parser::Expression_or_cond_patternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond_pattern(sv2012Parser::Cond_patternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_statement(sv2012Parser::Case_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_keyword(sv2012Parser::Case_keywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_expression(sv2012Parser::Case_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_item(sv2012Parser::Case_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_pattern_item(sv2012Parser::Case_pattern_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_inside_item(sv2012Parser::Case_inside_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_item_expression(sv2012Parser::Case_item_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRandcase_statement(sv2012Parser::Randcase_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRandcase_item(sv2012Parser::Randcase_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpen_range_list(sv2012Parser::Open_range_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpen_value_range(sv2012Parser::Open_value_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPattern(sv2012Parser::PatternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_pattern(sv2012Parser::Assignment_patternContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructure_pattern_key(sv2012Parser::Structure_pattern_keyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_pattern_key(sv2012Parser::Array_pattern_keyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_pattern_key(sv2012Parser::Assignment_pattern_keyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_pattern_expression(sv2012Parser::Assignment_pattern_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_pattern_expression_type(sv2012Parser::Assignment_pattern_expression_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_assignment_pattern_expression(sv2012Parser::Constant_assignment_pattern_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_pattern_net_lvalue(sv2012Parser::Assignment_pattern_net_lvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment_pattern_variable_lvalue(sv2012Parser::Assignment_pattern_variable_lvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop_statement(sv2012Parser::Loop_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_initialization(sv2012Parser::For_initializationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_variable_declaration(sv2012Parser::For_variable_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_step(sv2012Parser::For_stepContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_step_assignment(sv2012Parser::For_step_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop_variables(sv2012Parser::Loop_variablesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubroutine_call_statement(sv2012Parser::Subroutine_call_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssertion_item(sv2012Parser::Assertion_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeferred_immediate_assertion_item(sv2012Parser::Deferred_immediate_assertion_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedural_assertion_statement(sv2012Parser::Procedural_assertion_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImmediate_assertion_statement(sv2012Parser::Immediate_assertion_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_immediate_assertion_statement(sv2012Parser::Simple_immediate_assertion_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_immediate_assert_statement(sv2012Parser::Simple_immediate_assert_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_immediate_assume_statement(sv2012Parser::Simple_immediate_assume_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_immediate_cover_statement(sv2012Parser::Simple_immediate_cover_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeferred_immediate_assertion_statement(sv2012Parser::Deferred_immediate_assertion_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeferred_immediate_assert_statement(sv2012Parser::Deferred_immediate_assert_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeferred_immediate_assume_statement(sv2012Parser::Deferred_immediate_assume_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeferred_immediate_cover_statement(sv2012Parser::Deferred_immediate_cover_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClocking_declaration(sv2012Parser::Clocking_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClocking_event(sv2012Parser::Clocking_eventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClocking_item(sv2012Parser::Clocking_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefault_skew(sv2012Parser::Default_skewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClocking_direction(sv2012Parser::Clocking_directionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_clocking_decl_assign(sv2012Parser::List_of_clocking_decl_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClocking_decl_assign(sv2012Parser::Clocking_decl_assignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClocking_skew(sv2012Parser::Clocking_skewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClocking_drive(sv2012Parser::Clocking_driveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCycle_delay(sv2012Parser::Cycle_delayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockvar(sv2012Parser::ClockvarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClockvar_expression(sv2012Parser::Clockvar_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRandsequence_statement(sv2012Parser::Randsequence_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProduction(sv2012Parser::ProductionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRs_rule(sv2012Parser::Rs_ruleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRs_production_list(sv2012Parser::Rs_production_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWeight_specification(sv2012Parser::Weight_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRs_code_block(sv2012Parser::Rs_code_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRs_prod(sv2012Parser::Rs_prodContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProduction_item(sv2012Parser::Production_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRs_if_else(sv2012Parser::Rs_if_elseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRs_repeat(sv2012Parser::Rs_repeatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRs_case(sv2012Parser::Rs_caseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRs_case_item(sv2012Parser::Rs_case_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_block(sv2012Parser::Specify_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_item(sv2012Parser::Specify_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPulsestyle_declaration(sv2012Parser::Pulsestyle_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShowcancelled_declaration(sv2012Parser::Showcancelled_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPath_declaration(sv2012Parser::Path_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_path_declaration(sv2012Parser::Simple_path_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParallel_path_description(sv2012Parser::Parallel_path_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFull_path_description(sv2012Parser::Full_path_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_path_inputs(sv2012Parser::List_of_path_inputsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_path_outputs(sv2012Parser::List_of_path_outputsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_input_terminal_descriptor(sv2012Parser::Specify_input_terminal_descriptorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_output_terminal_descriptor(sv2012Parser::Specify_output_terminal_descriptorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInput_identifier(sv2012Parser::Input_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_identifier(sv2012Parser::Output_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPath_delay_value(sv2012Parser::Path_delay_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_path_delay_expressions(sv2012Parser::List_of_path_delay_expressionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT_path_delay_expression(sv2012Parser::T_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrise_path_delay_expression(sv2012Parser::Trise_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTfall_path_delay_expression(sv2012Parser::Tfall_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTz_path_delay_expression(sv2012Parser::Tz_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT01_path_delay_expression(sv2012Parser::T01_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT10_path_delay_expression(sv2012Parser::T10_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT0z_path_delay_expression(sv2012Parser::T0z_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTz1_path_delay_expression(sv2012Parser::Tz1_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT1z_path_delay_expression(sv2012Parser::T1z_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTz0_path_delay_expression(sv2012Parser::Tz0_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT0x_path_delay_expression(sv2012Parser::T0x_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTx1_path_delay_expression(sv2012Parser::Tx1_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitT1x_path_delay_expression(sv2012Parser::T1x_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTx0_path_delay_expression(sv2012Parser::Tx0_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTxz_path_delay_expression(sv2012Parser::Txz_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTzx_path_delay_expression(sv2012Parser::Tzx_path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPath_delay_expression(sv2012Parser::Path_delay_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_sensitive_path_declaration(sv2012Parser::Edge_sensitive_path_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParallel_edge_sensitive_path_description(sv2012Parser::Parallel_edge_sensitive_path_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFull_edge_sensitive_path_description(sv2012Parser::Full_edge_sensitive_path_descriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData_source_expression(sv2012Parser::Data_source_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_identifier(sv2012Parser::Edge_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitState_dependent_path_declaration(sv2012Parser::State_dependent_path_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPolarity_operator(sv2012Parser::Polarity_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSystem_timing_check(sv2012Parser::System_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetup_timing_check(sv2012Parser::Setup_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHold_timing_check(sv2012Parser::Hold_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetuphold_timing_check(sv2012Parser::Setuphold_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecovery_timing_check(sv2012Parser::Recovery_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRemoval_timing_check(sv2012Parser::Removal_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRecrem_timing_check(sv2012Parser::Recrem_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSkew_timing_check(sv2012Parser::Skew_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimeskew_timing_check(sv2012Parser::Timeskew_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFullskew_timing_check(sv2012Parser::Fullskew_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPeriod_timing_check(sv2012Parser::Period_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWidth_timing_check(sv2012Parser::Width_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNochange_timing_check(sv2012Parser::Nochange_timing_checkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimecheck_condition(sv2012Parser::Timecheck_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControlled_reference_event(sv2012Parser::Controlled_reference_eventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitData_event(sv2012Parser::Data_eventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelayed_data(sv2012Parser::Delayed_dataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelayed_reference(sv2012Parser::Delayed_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnd_edge_offset(sv2012Parser::End_edge_offsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEvent_based_flag(sv2012Parser::Event_based_flagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotifier(sv2012Parser::NotifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReference_event(sv2012Parser::Reference_eventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRemain_active_flag(sv2012Parser::Remain_active_flagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimestamp_condition(sv2012Parser::Timestamp_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart_edge_offset(sv2012Parser::Start_edge_offsetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThreshold(sv2012Parser::ThresholdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTiming_check_limit(sv2012Parser::Timing_check_limitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTiming_check_event(sv2012Parser::Timing_check_eventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitControlled_timing_check_event(sv2012Parser::Controlled_timing_check_eventContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTiming_check_event_control(sv2012Parser::Timing_check_event_controlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecify_terminal_descriptor(sv2012Parser::Specify_terminal_descriptorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_control_specifier(sv2012Parser::Edge_control_specifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEdge_descriptor(sv2012Parser::Edge_descriptorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTiming_check_condition(sv2012Parser::Timing_check_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalar_timing_check_condition(sv2012Parser::Scalar_timing_check_conditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalar_constant(sv2012Parser::Scalar_constantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConcatenation(sv2012Parser::ConcatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_concatenation(sv2012Parser::Constant_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_multiple_concatenation(sv2012Parser::Constant_multiple_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_concatenation(sv2012Parser::Module_path_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_multiple_concatenation(sv2012Parser::Module_path_multiple_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultiple_concatenation(sv2012Parser::Multiple_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStreaming_concatenation(sv2012Parser::Streaming_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStream_operator(sv2012Parser::Stream_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSlice_size(sv2012Parser::Slice_sizeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStream_concatenation(sv2012Parser::Stream_concatenationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStream_expression(sv2012Parser::Stream_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_range_expression(sv2012Parser::Array_range_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmpty_queue(sv2012Parser::Empty_queueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_function_call(sv2012Parser::Constant_function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_call(sv2012Parser::Tf_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSystem_tf_call(sv2012Parser::System_tf_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_subroutine_call(sv2012Parser::Function_subroutine_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubroutine_call(sv2012Parser::Subroutine_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_call(sv2012Parser::Method_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_call_root(sv2012Parser::Method_call_rootContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitList_of_arguments(sv2012Parser::List_of_argumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_call_body(sv2012Parser::Method_call_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBuilt_in_method_call(sv2012Parser::Built_in_method_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_manipulation_call(sv2012Parser::Array_manipulation_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRandomize_call(sv2012Parser::Randomize_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_method_name(sv2012Parser::Array_method_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInc_or_dec_expression(sv2012Parser::Inc_or_dec_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConditional_expression(sv2012Parser::Conditional_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_expression(sv2012Parser::Constant_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_mintypmax_expression(sv2012Parser::Constant_mintypmax_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_param_expression(sv2012Parser::Constant_param_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_expression(sv2012Parser::Param_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_range_expression(sv2012Parser::Constant_range_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_part_select_range(sv2012Parser::Constant_part_select_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_range(sv2012Parser::Constant_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_indexed_range(sv2012Parser::Constant_indexed_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression_cond_or_inside(sv2012Parser::Expression_cond_or_insideContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(sv2012Parser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTagged_union_expression(sv2012Parser::Tagged_union_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInside_expression(sv2012Parser::Inside_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue_range(sv2012Parser::Value_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMintypmax_expression(sv2012Parser::Mintypmax_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_conditional_expression(sv2012Parser::Module_path_conditional_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_expression(sv2012Parser::Module_path_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_mintypmax_expression(sv2012Parser::Module_path_mintypmax_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPart_select_range(sv2012Parser::Part_select_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexed_range(sv2012Parser::Indexed_rangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_expression(sv2012Parser::Genvar_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_primary(sv2012Parser::Constant_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_path_primary(sv2012Parser::Module_path_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary(sv2012Parser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_qualifier(sv2012Parser::Class_qualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange_expression(sv2012Parser::Range_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimary_literal(sv2012Parser::Primary_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTime_literal(sv2012Parser::Time_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTime_unit(sv2012Parser::Time_unitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImplicit_class_handle(sv2012Parser::Implicit_class_handleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBit_select(sv2012Parser::Bit_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect(sv2012Parser::SelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonrange_select(sv2012Parser::Nonrange_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_bit_select(sv2012Parser::Constant_bit_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_select(sv2012Parser::Constant_selectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_cast(sv2012Parser::Constant_castContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_let_expression(sv2012Parser::Constant_let_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCast(sv2012Parser::CastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_lvalue(sv2012Parser::Net_lvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_lvalue(sv2012Parser::Variable_lvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonrange_variable_lvalue(sv2012Parser::Nonrange_variable_lvalueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(sv2012Parser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_operator(sv2012Parser::Binary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInc_or_dec_operator(sv2012Parser::Inc_or_dec_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_module_path_operator(sv2012Parser::Unary_module_path_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinary_module_path_operator(sv2012Parser::Binary_module_path_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(sv2012Parser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttribute_instance(sv2012Parser::Attribute_instanceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttr_spec(sv2012Parser::Attr_specContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttr_name(sv2012Parser::Attr_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_identifier(sv2012Parser::Array_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_identifier(sv2012Parser::Block_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBin_identifier(sv2012Parser::Bin_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitC_identifier(sv2012Parser::C_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCell_identifier(sv2012Parser::Cell_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChecker_identifier(sv2012Parser::Checker_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_identifier(sv2012Parser::Class_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClass_variable_identifier(sv2012Parser::Class_variable_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClocking_identifier(sv2012Parser::Clocking_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConfig_identifier(sv2012Parser::Config_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_identifier(sv2012Parser::Const_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstraint_identifier(sv2012Parser::Constraint_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCovergroup_identifier(sv2012Parser::Covergroup_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCovergroup_variable_identifier(sv2012Parser::Covergroup_variable_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCover_point_identifier(sv2012Parser::Cover_point_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCross_identifier(sv2012Parser::Cross_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDynamic_array_variable_identifier(sv2012Parser::Dynamic_array_variable_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEnum_identifier(sv2012Parser::Enum_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormal_identifier(sv2012Parser::Formal_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFormal_port_identifier(sv2012Parser::Formal_port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_identifier(sv2012Parser::Function_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenerate_block_identifier(sv2012Parser::Generate_block_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGenvar_identifier(sv2012Parser::Genvar_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_array_identifier(sv2012Parser::Hierarchical_array_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_block_identifier(sv2012Parser::Hierarchical_block_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_event_identifier(sv2012Parser::Hierarchical_event_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_identifier(sv2012Parser::Hierarchical_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_net_identifier(sv2012Parser::Hierarchical_net_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_parameter_identifier(sv2012Parser::Hierarchical_parameter_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_property_identifier(sv2012Parser::Hierarchical_property_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_sequence_identifier(sv2012Parser::Hierarchical_sequence_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_task_identifier(sv2012Parser::Hierarchical_task_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_tf_identifier(sv2012Parser::Hierarchical_tf_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHierarchical_variable_identifier(sv2012Parser::Hierarchical_variable_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(sv2012Parser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex_variable_identifier(sv2012Parser::Index_variable_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_identifier(sv2012Parser::Interface_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInterface_instance_identifier(sv2012Parser::Interface_instance_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInout_port_identifier(sv2012Parser::Inout_port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInput_port_identifier(sv2012Parser::Input_port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstance_identifier(sv2012Parser::Instance_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibrary_identifier(sv2012Parser::Library_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMember_identifier(sv2012Parser::Member_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethod_identifier(sv2012Parser::Method_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModport_identifier(sv2012Parser::Modport_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_identifier(sv2012Parser::Module_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_identifier(sv2012Parser::Net_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNet_type_identifier(sv2012Parser::Net_type_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOutput_port_identifier(sv2012Parser::Output_port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_identifier(sv2012Parser::Package_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackage_scope(sv2012Parser::Package_scopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter_identifier(sv2012Parser::Parameter_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPort_identifier(sv2012Parser::Port_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProduction_identifier(sv2012Parser::Production_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_identifier(sv2012Parser::Program_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProperty_identifier(sv2012Parser::Property_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_class_identifier(sv2012Parser::Ps_class_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_covergroup_identifier(sv2012Parser::Ps_covergroup_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_checker_identifier(sv2012Parser::Ps_checker_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_identifier(sv2012Parser::Ps_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_or_hierarchical_array_identifier(sv2012Parser::Ps_or_hierarchical_array_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_or_hierarchical_net_identifier(sv2012Parser::Ps_or_hierarchical_net_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_or_hierarchical_property_identifier(sv2012Parser::Ps_or_hierarchical_property_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_or_hierarchical_sequence_identifier(sv2012Parser::Ps_or_hierarchical_sequence_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_or_hierarchical_tf_identifier(sv2012Parser::Ps_or_hierarchical_tf_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_parameter_identifier(sv2012Parser::Ps_parameter_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPs_type_identifier(sv2012Parser::Ps_type_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequence_identifier(sv2012Parser::Sequence_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignal_identifier(sv2012Parser::Signal_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSpecparam_identifier(sv2012Parser::Specparam_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTask_identifier(sv2012Parser::Task_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTf_identifier(sv2012Parser::Tf_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerminal_identifier(sv2012Parser::Terminal_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTopmodule_identifier(sv2012Parser::Topmodule_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_identifier(sv2012Parser::Type_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUdp_identifier(sv2012Parser::Udp_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_identifier(sv2012Parser::Variable_identifierContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace sv
