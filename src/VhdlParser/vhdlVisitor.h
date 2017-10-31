
// Generated from grammars/vhdl.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "vhdlParser.h"


namespace vhdl {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by vhdlParser.
 */
class  vhdlVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by vhdlParser.
   */
    virtual antlrcpp::Any visitAbstract_literal(vhdlParser::Abstract_literalContext *context) = 0;

    virtual antlrcpp::Any visitAccess_type_definition(vhdlParser::Access_type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitAcross_aspect(vhdlParser::Across_aspectContext *context) = 0;

    virtual antlrcpp::Any visitActual_designator(vhdlParser::Actual_designatorContext *context) = 0;

    virtual antlrcpp::Any visitActual_parameter_part(vhdlParser::Actual_parameter_partContext *context) = 0;

    virtual antlrcpp::Any visitActual_part(vhdlParser::Actual_partContext *context) = 0;

    virtual antlrcpp::Any visitAdding_operator(vhdlParser::Adding_operatorContext *context) = 0;

    virtual antlrcpp::Any visitAggregate(vhdlParser::AggregateContext *context) = 0;

    virtual antlrcpp::Any visitAlias_declaration(vhdlParser::Alias_declarationContext *context) = 0;

    virtual antlrcpp::Any visitAlias_designator(vhdlParser::Alias_designatorContext *context) = 0;

    virtual antlrcpp::Any visitAlias_indication(vhdlParser::Alias_indicationContext *context) = 0;

    virtual antlrcpp::Any visitAllocator(vhdlParser::AllocatorContext *context) = 0;

    virtual antlrcpp::Any visitArchitecture_body(vhdlParser::Architecture_bodyContext *context) = 0;

    virtual antlrcpp::Any visitArchitecture_declarative_part(vhdlParser::Architecture_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitArchitecture_statement(vhdlParser::Architecture_statementContext *context) = 0;

    virtual antlrcpp::Any visitArchitecture_statement_part(vhdlParser::Architecture_statement_partContext *context) = 0;

    virtual antlrcpp::Any visitArray_nature_definition(vhdlParser::Array_nature_definitionContext *context) = 0;

    virtual antlrcpp::Any visitArray_type_definition(vhdlParser::Array_type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitAssertion(vhdlParser::AssertionContext *context) = 0;

    virtual antlrcpp::Any visitAssertion_statement(vhdlParser::Assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitAssociation_element(vhdlParser::Association_elementContext *context) = 0;

    virtual antlrcpp::Any visitAssociation_list(vhdlParser::Association_listContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_declaration(vhdlParser::Attribute_declarationContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_designator(vhdlParser::Attribute_designatorContext *context) = 0;

    virtual antlrcpp::Any visitAttribute_specification(vhdlParser::Attribute_specificationContext *context) = 0;

    virtual antlrcpp::Any visitBase_unit_declaration(vhdlParser::Base_unit_declarationContext *context) = 0;

    virtual antlrcpp::Any visitBinding_indication(vhdlParser::Binding_indicationContext *context) = 0;

    virtual antlrcpp::Any visitBlock_configuration(vhdlParser::Block_configurationContext *context) = 0;

    virtual antlrcpp::Any visitBlock_declarative_item(vhdlParser::Block_declarative_itemContext *context) = 0;

    virtual antlrcpp::Any visitBlock_declarative_part(vhdlParser::Block_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitBlock_header(vhdlParser::Block_headerContext *context) = 0;

    virtual antlrcpp::Any visitBlock_specification(vhdlParser::Block_specificationContext *context) = 0;

    virtual antlrcpp::Any visitBlock_statement(vhdlParser::Block_statementContext *context) = 0;

    virtual antlrcpp::Any visitBlock_statement_part(vhdlParser::Block_statement_partContext *context) = 0;

    virtual antlrcpp::Any visitBranch_quantity_declaration(vhdlParser::Branch_quantity_declarationContext *context) = 0;

    virtual antlrcpp::Any visitBreak_element(vhdlParser::Break_elementContext *context) = 0;

    virtual antlrcpp::Any visitBreak_list(vhdlParser::Break_listContext *context) = 0;

    virtual antlrcpp::Any visitBreak_selector_clause(vhdlParser::Break_selector_clauseContext *context) = 0;

    virtual antlrcpp::Any visitBreak_statement(vhdlParser::Break_statementContext *context) = 0;

    virtual antlrcpp::Any visitCase_statement(vhdlParser::Case_statementContext *context) = 0;

    virtual antlrcpp::Any visitCase_statement_alternative(vhdlParser::Case_statement_alternativeContext *context) = 0;

    virtual antlrcpp::Any visitChoice(vhdlParser::ChoiceContext *context) = 0;

    virtual antlrcpp::Any visitChoices(vhdlParser::ChoicesContext *context) = 0;

    virtual antlrcpp::Any visitComponent_configuration(vhdlParser::Component_configurationContext *context) = 0;

    virtual antlrcpp::Any visitComponent_declaration(vhdlParser::Component_declarationContext *context) = 0;

    virtual antlrcpp::Any visitComponent_instantiation_statement(vhdlParser::Component_instantiation_statementContext *context) = 0;

    virtual antlrcpp::Any visitComponent_specification(vhdlParser::Component_specificationContext *context) = 0;

    virtual antlrcpp::Any visitComposite_nature_definition(vhdlParser::Composite_nature_definitionContext *context) = 0;

    virtual antlrcpp::Any visitComposite_type_definition(vhdlParser::Composite_type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitConcurrent_assertion_statement(vhdlParser::Concurrent_assertion_statementContext *context) = 0;

    virtual antlrcpp::Any visitConcurrent_break_statement(vhdlParser::Concurrent_break_statementContext *context) = 0;

    virtual antlrcpp::Any visitConcurrent_procedure_call_statement(vhdlParser::Concurrent_procedure_call_statementContext *context) = 0;

    virtual antlrcpp::Any visitConcurrent_signal_assignment_statement(vhdlParser::Concurrent_signal_assignment_statementContext *context) = 0;

    virtual antlrcpp::Any visitCondition(vhdlParser::ConditionContext *context) = 0;

    virtual antlrcpp::Any visitCondition_clause(vhdlParser::Condition_clauseContext *context) = 0;

    virtual antlrcpp::Any visitConditional_signal_assignment(vhdlParser::Conditional_signal_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitConditional_waveforms(vhdlParser::Conditional_waveformsContext *context) = 0;

    virtual antlrcpp::Any visitConfiguration_declaration(vhdlParser::Configuration_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConfiguration_declarative_item(vhdlParser::Configuration_declarative_itemContext *context) = 0;

    virtual antlrcpp::Any visitConfiguration_declarative_part(vhdlParser::Configuration_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitConfiguration_item(vhdlParser::Configuration_itemContext *context) = 0;

    virtual antlrcpp::Any visitConfiguration_specification(vhdlParser::Configuration_specificationContext *context) = 0;

    virtual antlrcpp::Any visitConstant_declaration(vhdlParser::Constant_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConstrained_array_definition(vhdlParser::Constrained_array_definitionContext *context) = 0;

    virtual antlrcpp::Any visitConstrained_nature_definition(vhdlParser::Constrained_nature_definitionContext *context) = 0;

    virtual antlrcpp::Any visitConstraint(vhdlParser::ConstraintContext *context) = 0;

    virtual antlrcpp::Any visitContext_clause(vhdlParser::Context_clauseContext *context) = 0;

    virtual antlrcpp::Any visitContext_item(vhdlParser::Context_itemContext *context) = 0;

    virtual antlrcpp::Any visitDelay_mechanism(vhdlParser::Delay_mechanismContext *context) = 0;

    virtual antlrcpp::Any visitDesign_file(vhdlParser::Design_fileContext *context) = 0;

    virtual antlrcpp::Any visitDesign_unit(vhdlParser::Design_unitContext *context) = 0;

    virtual antlrcpp::Any visitDesignator(vhdlParser::DesignatorContext *context) = 0;

    virtual antlrcpp::Any visitDirection(vhdlParser::DirectionContext *context) = 0;

    virtual antlrcpp::Any visitDisconnection_specification(vhdlParser::Disconnection_specificationContext *context) = 0;

    virtual antlrcpp::Any visitDiscrete_range(vhdlParser::Discrete_rangeContext *context) = 0;

    virtual antlrcpp::Any visitElement_association(vhdlParser::Element_associationContext *context) = 0;

    virtual antlrcpp::Any visitElement_declaration(vhdlParser::Element_declarationContext *context) = 0;

    virtual antlrcpp::Any visitElement_subnature_definition(vhdlParser::Element_subnature_definitionContext *context) = 0;

    virtual antlrcpp::Any visitElement_subtype_definition(vhdlParser::Element_subtype_definitionContext *context) = 0;

    virtual antlrcpp::Any visitEntity_aspect(vhdlParser::Entity_aspectContext *context) = 0;

    virtual antlrcpp::Any visitEntity_class(vhdlParser::Entity_classContext *context) = 0;

    virtual antlrcpp::Any visitEntity_class_entry(vhdlParser::Entity_class_entryContext *context) = 0;

    virtual antlrcpp::Any visitEntity_class_entry_list(vhdlParser::Entity_class_entry_listContext *context) = 0;

    virtual antlrcpp::Any visitEntity_declaration(vhdlParser::Entity_declarationContext *context) = 0;

    virtual antlrcpp::Any visitEntity_declarative_item(vhdlParser::Entity_declarative_itemContext *context) = 0;

    virtual antlrcpp::Any visitEntity_declarative_part(vhdlParser::Entity_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitEntity_designator(vhdlParser::Entity_designatorContext *context) = 0;

    virtual antlrcpp::Any visitEntity_header(vhdlParser::Entity_headerContext *context) = 0;

    virtual antlrcpp::Any visitEntity_name_list(vhdlParser::Entity_name_listContext *context) = 0;

    virtual antlrcpp::Any visitEntity_specification(vhdlParser::Entity_specificationContext *context) = 0;

    virtual antlrcpp::Any visitEntity_statement(vhdlParser::Entity_statementContext *context) = 0;

    virtual antlrcpp::Any visitEntity_statement_part(vhdlParser::Entity_statement_partContext *context) = 0;

    virtual antlrcpp::Any visitEntity_tag(vhdlParser::Entity_tagContext *context) = 0;

    virtual antlrcpp::Any visitEnumeration_literal(vhdlParser::Enumeration_literalContext *context) = 0;

    virtual antlrcpp::Any visitEnumeration_type_definition(vhdlParser::Enumeration_type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitExit_statement(vhdlParser::Exit_statementContext *context) = 0;

    virtual antlrcpp::Any visitExpression(vhdlParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFactor(vhdlParser::FactorContext *context) = 0;

    virtual antlrcpp::Any visitFile_declaration(vhdlParser::File_declarationContext *context) = 0;

    virtual antlrcpp::Any visitFile_logical_name(vhdlParser::File_logical_nameContext *context) = 0;

    virtual antlrcpp::Any visitFile_open_information(vhdlParser::File_open_informationContext *context) = 0;

    virtual antlrcpp::Any visitFile_type_definition(vhdlParser::File_type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitFormal_parameter_list(vhdlParser::Formal_parameter_listContext *context) = 0;

    virtual antlrcpp::Any visitFormal_part(vhdlParser::Formal_partContext *context) = 0;

    virtual antlrcpp::Any visitFree_quantity_declaration(vhdlParser::Free_quantity_declarationContext *context) = 0;

    virtual antlrcpp::Any visitGenerate_statement(vhdlParser::Generate_statementContext *context) = 0;

    virtual antlrcpp::Any visitGeneration_scheme(vhdlParser::Generation_schemeContext *context) = 0;

    virtual antlrcpp::Any visitGeneric_clause(vhdlParser::Generic_clauseContext *context) = 0;

    virtual antlrcpp::Any visitGeneric_list(vhdlParser::Generic_listContext *context) = 0;

    virtual antlrcpp::Any visitGeneric_map_aspect(vhdlParser::Generic_map_aspectContext *context) = 0;

    virtual antlrcpp::Any visitGroup_constituent(vhdlParser::Group_constituentContext *context) = 0;

    virtual antlrcpp::Any visitGroup_constituent_list(vhdlParser::Group_constituent_listContext *context) = 0;

    virtual antlrcpp::Any visitGroup_declaration(vhdlParser::Group_declarationContext *context) = 0;

    virtual antlrcpp::Any visitGroup_template_declaration(vhdlParser::Group_template_declarationContext *context) = 0;

    virtual antlrcpp::Any visitGuarded_signal_specification(vhdlParser::Guarded_signal_specificationContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(vhdlParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier_list(vhdlParser::Identifier_listContext *context) = 0;

    virtual antlrcpp::Any visitIf_statement(vhdlParser::If_statementContext *context) = 0;

    virtual antlrcpp::Any visitIndex_constraint(vhdlParser::Index_constraintContext *context) = 0;

    virtual antlrcpp::Any visitIndex_specification(vhdlParser::Index_specificationContext *context) = 0;

    virtual antlrcpp::Any visitIndex_subtype_definition(vhdlParser::Index_subtype_definitionContext *context) = 0;

    virtual antlrcpp::Any visitInstantiated_unit(vhdlParser::Instantiated_unitContext *context) = 0;

    virtual antlrcpp::Any visitInstantiation_list(vhdlParser::Instantiation_listContext *context) = 0;

    virtual antlrcpp::Any visitInterface_constant_declaration(vhdlParser::Interface_constant_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_declaration(vhdlParser::Interface_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_element(vhdlParser::Interface_elementContext *context) = 0;

    virtual antlrcpp::Any visitInterface_file_declaration(vhdlParser::Interface_file_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_signal_list(vhdlParser::Interface_signal_listContext *context) = 0;

    virtual antlrcpp::Any visitInterface_port_list(vhdlParser::Interface_port_listContext *context) = 0;

    virtual antlrcpp::Any visitInterface_list(vhdlParser::Interface_listContext *context) = 0;

    virtual antlrcpp::Any visitInterface_quantity_declaration(vhdlParser::Interface_quantity_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_port_declaration(vhdlParser::Interface_port_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_signal_declaration(vhdlParser::Interface_signal_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_terminal_declaration(vhdlParser::Interface_terminal_declarationContext *context) = 0;

    virtual antlrcpp::Any visitInterface_variable_declaration(vhdlParser::Interface_variable_declarationContext *context) = 0;

    virtual antlrcpp::Any visitIteration_scheme(vhdlParser::Iteration_schemeContext *context) = 0;

    virtual antlrcpp::Any visitLabel_colon(vhdlParser::Label_colonContext *context) = 0;

    virtual antlrcpp::Any visitLibrary_clause(vhdlParser::Library_clauseContext *context) = 0;

    virtual antlrcpp::Any visitLibrary_unit(vhdlParser::Library_unitContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(vhdlParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitLogical_name(vhdlParser::Logical_nameContext *context) = 0;

    virtual antlrcpp::Any visitLogical_name_list(vhdlParser::Logical_name_listContext *context) = 0;

    virtual antlrcpp::Any visitLogical_operator(vhdlParser::Logical_operatorContext *context) = 0;

    virtual antlrcpp::Any visitLoop_statement(vhdlParser::Loop_statementContext *context) = 0;

    virtual antlrcpp::Any visitSignal_mode(vhdlParser::Signal_modeContext *context) = 0;

    virtual antlrcpp::Any visitMultiplying_operator(vhdlParser::Multiplying_operatorContext *context) = 0;

    virtual antlrcpp::Any visitName(vhdlParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitName_part(vhdlParser::Name_partContext *context) = 0;

    virtual antlrcpp::Any visitName_part_specificator(vhdlParser::Name_part_specificatorContext *context) = 0;

    virtual antlrcpp::Any visitName_attribute_part(vhdlParser::Name_attribute_partContext *context) = 0;

    virtual antlrcpp::Any visitName_function_call_or_indexed_part(vhdlParser::Name_function_call_or_indexed_partContext *context) = 0;

    virtual antlrcpp::Any visitName_slice_part(vhdlParser::Name_slice_partContext *context) = 0;

    virtual antlrcpp::Any visitSelected_name(vhdlParser::Selected_nameContext *context) = 0;

    virtual antlrcpp::Any visitNature_declaration(vhdlParser::Nature_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNature_definition(vhdlParser::Nature_definitionContext *context) = 0;

    virtual antlrcpp::Any visitNature_element_declaration(vhdlParser::Nature_element_declarationContext *context) = 0;

    virtual antlrcpp::Any visitNext_statement(vhdlParser::Next_statementContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_literal(vhdlParser::Numeric_literalContext *context) = 0;

    virtual antlrcpp::Any visitObject_declaration(vhdlParser::Object_declarationContext *context) = 0;

    virtual antlrcpp::Any visitOpts(vhdlParser::OptsContext *context) = 0;

    virtual antlrcpp::Any visitPackage_body(vhdlParser::Package_bodyContext *context) = 0;

    virtual antlrcpp::Any visitPackage_body_declarative_item(vhdlParser::Package_body_declarative_itemContext *context) = 0;

    virtual antlrcpp::Any visitPackage_body_declarative_part(vhdlParser::Package_body_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitPackage_declaration(vhdlParser::Package_declarationContext *context) = 0;

    virtual antlrcpp::Any visitPackage_declarative_item(vhdlParser::Package_declarative_itemContext *context) = 0;

    virtual antlrcpp::Any visitPackage_declarative_part(vhdlParser::Package_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitParameter_specification(vhdlParser::Parameter_specificationContext *context) = 0;

    virtual antlrcpp::Any visitPhysical_literal(vhdlParser::Physical_literalContext *context) = 0;

    virtual antlrcpp::Any visitPhysical_type_definition(vhdlParser::Physical_type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitPort_clause(vhdlParser::Port_clauseContext *context) = 0;

    virtual antlrcpp::Any visitPort_list(vhdlParser::Port_listContext *context) = 0;

    virtual antlrcpp::Any visitPort_map_aspect(vhdlParser::Port_map_aspectContext *context) = 0;

    virtual antlrcpp::Any visitPrimary(vhdlParser::PrimaryContext *context) = 0;

    virtual antlrcpp::Any visitPrimary_unit(vhdlParser::Primary_unitContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_declarative_item(vhdlParser::Procedural_declarative_itemContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_declarative_part(vhdlParser::Procedural_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitProcedural_statement_part(vhdlParser::Procedural_statement_partContext *context) = 0;

    virtual antlrcpp::Any visitProcedure_call(vhdlParser::Procedure_callContext *context) = 0;

    virtual antlrcpp::Any visitProcedure_call_statement(vhdlParser::Procedure_call_statementContext *context) = 0;

    virtual antlrcpp::Any visitProcess_declarative_item(vhdlParser::Process_declarative_itemContext *context) = 0;

    virtual antlrcpp::Any visitProcess_declarative_part(vhdlParser::Process_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitProcess_statement(vhdlParser::Process_statementContext *context) = 0;

    virtual antlrcpp::Any visitProcess_statement_part(vhdlParser::Process_statement_partContext *context) = 0;

    virtual antlrcpp::Any visitQualified_expression(vhdlParser::Qualified_expressionContext *context) = 0;

    virtual antlrcpp::Any visitQuantity_declaration(vhdlParser::Quantity_declarationContext *context) = 0;

    virtual antlrcpp::Any visitQuantity_list(vhdlParser::Quantity_listContext *context) = 0;

    virtual antlrcpp::Any visitQuantity_specification(vhdlParser::Quantity_specificationContext *context) = 0;

    virtual antlrcpp::Any visitRange(vhdlParser::RangeContext *context) = 0;

    virtual antlrcpp::Any visitExplicit_range(vhdlParser::Explicit_rangeContext *context) = 0;

    virtual antlrcpp::Any visitRange_constraint(vhdlParser::Range_constraintContext *context) = 0;

    virtual antlrcpp::Any visitRecord_nature_definition(vhdlParser::Record_nature_definitionContext *context) = 0;

    virtual antlrcpp::Any visitRecord_type_definition(vhdlParser::Record_type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitRelation(vhdlParser::RelationContext *context) = 0;

    virtual antlrcpp::Any visitRelational_operator(vhdlParser::Relational_operatorContext *context) = 0;

    virtual antlrcpp::Any visitReport_statement(vhdlParser::Report_statementContext *context) = 0;

    virtual antlrcpp::Any visitReturn_statement(vhdlParser::Return_statementContext *context) = 0;

    virtual antlrcpp::Any visitScalar_nature_definition(vhdlParser::Scalar_nature_definitionContext *context) = 0;

    virtual antlrcpp::Any visitScalar_type_definition(vhdlParser::Scalar_type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitSecondary_unit(vhdlParser::Secondary_unitContext *context) = 0;

    virtual antlrcpp::Any visitSecondary_unit_declaration(vhdlParser::Secondary_unit_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSelected_signal_assignment(vhdlParser::Selected_signal_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitSelected_waveforms(vhdlParser::Selected_waveformsContext *context) = 0;

    virtual antlrcpp::Any visitSensitivity_clause(vhdlParser::Sensitivity_clauseContext *context) = 0;

    virtual antlrcpp::Any visitSensitivity_list(vhdlParser::Sensitivity_listContext *context) = 0;

    virtual antlrcpp::Any visitSequence_of_statements(vhdlParser::Sequence_of_statementsContext *context) = 0;

    virtual antlrcpp::Any visitSequential_statement(vhdlParser::Sequential_statementContext *context) = 0;

    virtual antlrcpp::Any visitShift_expression(vhdlParser::Shift_expressionContext *context) = 0;

    virtual antlrcpp::Any visitShift_operator(vhdlParser::Shift_operatorContext *context) = 0;

    virtual antlrcpp::Any visitSignal_assignment_statement(vhdlParser::Signal_assignment_statementContext *context) = 0;

    virtual antlrcpp::Any visitSignal_declaration(vhdlParser::Signal_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSignal_kind(vhdlParser::Signal_kindContext *context) = 0;

    virtual antlrcpp::Any visitSignal_list(vhdlParser::Signal_listContext *context) = 0;

    virtual antlrcpp::Any visitSignature(vhdlParser::SignatureContext *context) = 0;

    virtual antlrcpp::Any visitSimple_expression(vhdlParser::Simple_expressionContext *context) = 0;

    virtual antlrcpp::Any visitSimple_simultaneous_statement(vhdlParser::Simple_simultaneous_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimultaneous_alternative(vhdlParser::Simultaneous_alternativeContext *context) = 0;

    virtual antlrcpp::Any visitSimultaneous_case_statement(vhdlParser::Simultaneous_case_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimultaneous_if_statement(vhdlParser::Simultaneous_if_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimultaneous_procedural_statement(vhdlParser::Simultaneous_procedural_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimultaneous_statement(vhdlParser::Simultaneous_statementContext *context) = 0;

    virtual antlrcpp::Any visitSimultaneous_statement_part(vhdlParser::Simultaneous_statement_partContext *context) = 0;

    virtual antlrcpp::Any visitSource_aspect(vhdlParser::Source_aspectContext *context) = 0;

    virtual antlrcpp::Any visitSource_quantity_declaration(vhdlParser::Source_quantity_declarationContext *context) = 0;

    virtual antlrcpp::Any visitStep_limit_specification(vhdlParser::Step_limit_specificationContext *context) = 0;

    virtual antlrcpp::Any visitSubnature_declaration(vhdlParser::Subnature_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSubnature_indication(vhdlParser::Subnature_indicationContext *context) = 0;

    virtual antlrcpp::Any visitSubprogram_body(vhdlParser::Subprogram_bodyContext *context) = 0;

    virtual antlrcpp::Any visitSubprogram_declaration(vhdlParser::Subprogram_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSubprogram_declarative_item(vhdlParser::Subprogram_declarative_itemContext *context) = 0;

    virtual antlrcpp::Any visitSubprogram_declarative_part(vhdlParser::Subprogram_declarative_partContext *context) = 0;

    virtual antlrcpp::Any visitSubprogram_kind(vhdlParser::Subprogram_kindContext *context) = 0;

    virtual antlrcpp::Any visitSubprogram_specification(vhdlParser::Subprogram_specificationContext *context) = 0;

    virtual antlrcpp::Any visitProcedure_specification(vhdlParser::Procedure_specificationContext *context) = 0;

    virtual antlrcpp::Any visitFunction_specification(vhdlParser::Function_specificationContext *context) = 0;

    virtual antlrcpp::Any visitSubprogram_statement_part(vhdlParser::Subprogram_statement_partContext *context) = 0;

    virtual antlrcpp::Any visitSubtype_declaration(vhdlParser::Subtype_declarationContext *context) = 0;

    virtual antlrcpp::Any visitSubtype_indication(vhdlParser::Subtype_indicationContext *context) = 0;

    virtual antlrcpp::Any visitSuffix(vhdlParser::SuffixContext *context) = 0;

    virtual antlrcpp::Any visitTarget(vhdlParser::TargetContext *context) = 0;

    virtual antlrcpp::Any visitTerm(vhdlParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitTerminal_aspect(vhdlParser::Terminal_aspectContext *context) = 0;

    virtual antlrcpp::Any visitTerminal_declaration(vhdlParser::Terminal_declarationContext *context) = 0;

    virtual antlrcpp::Any visitThrough_aspect(vhdlParser::Through_aspectContext *context) = 0;

    virtual antlrcpp::Any visitTimeout_clause(vhdlParser::Timeout_clauseContext *context) = 0;

    virtual antlrcpp::Any visitTolerance_aspect(vhdlParser::Tolerance_aspectContext *context) = 0;

    virtual antlrcpp::Any visitType_declaration(vhdlParser::Type_declarationContext *context) = 0;

    virtual antlrcpp::Any visitType_definition(vhdlParser::Type_definitionContext *context) = 0;

    virtual antlrcpp::Any visitUnconstrained_array_definition(vhdlParser::Unconstrained_array_definitionContext *context) = 0;

    virtual antlrcpp::Any visitUnconstrained_nature_definition(vhdlParser::Unconstrained_nature_definitionContext *context) = 0;

    virtual antlrcpp::Any visitUse_clause(vhdlParser::Use_clauseContext *context) = 0;

    virtual antlrcpp::Any visitVariable_assignment_statement(vhdlParser::Variable_assignment_statementContext *context) = 0;

    virtual antlrcpp::Any visitVariable_declaration(vhdlParser::Variable_declarationContext *context) = 0;

    virtual antlrcpp::Any visitWait_statement(vhdlParser::Wait_statementContext *context) = 0;

    virtual antlrcpp::Any visitWaveform(vhdlParser::WaveformContext *context) = 0;

    virtual antlrcpp::Any visitWaveform_element(vhdlParser::Waveform_elementContext *context) = 0;


};

}  // namespace vhdl
