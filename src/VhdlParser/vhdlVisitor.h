
// Generated from vhdl.g4 by ANTLR 4.5.3

#pragma once


#include "antlr4-runtime.h"
#include "vhdlParser.h"


namespace vhdl {

/**
 * This template class defines an abstract visitor for a parse tree
 * produced by vhdlParser.
 *
 * @param <T> The return type of the visit operation. Use void for
 * operations with no return type.
 */
template <typename T>
class vhdlVisitor : public antlr4::tree::ParseTreeVisitor<T> {
public:

  /**
   * Visit parse trees produced by vhdlParser.
   */
    virtual T* visitAbstract_literal(vhdlParser::Abstract_literalContext *context) = 0;

    virtual T* visitAccess_type_definition(vhdlParser::Access_type_definitionContext *context) = 0;

    virtual T* visitAcross_aspect(vhdlParser::Across_aspectContext *context) = 0;

    virtual T* visitActual_designator(vhdlParser::Actual_designatorContext *context) = 0;

    virtual T* visitActual_parameter_part(vhdlParser::Actual_parameter_partContext *context) = 0;

    virtual T* visitActual_part(vhdlParser::Actual_partContext *context) = 0;

    virtual T* visitAdding_operator(vhdlParser::Adding_operatorContext *context) = 0;

    virtual T* visitAggregate(vhdlParser::AggregateContext *context) = 0;

    virtual T* visitAlias_declaration(vhdlParser::Alias_declarationContext *context) = 0;

    virtual T* visitAlias_designator(vhdlParser::Alias_designatorContext *context) = 0;

    virtual T* visitAlias_indication(vhdlParser::Alias_indicationContext *context) = 0;

    virtual T* visitAllocator(vhdlParser::AllocatorContext *context) = 0;

    virtual T* visitArchitecture_body(vhdlParser::Architecture_bodyContext *context) = 0;

    virtual T* visitArchitecture_declarative_part(vhdlParser::Architecture_declarative_partContext *context) = 0;

    virtual T* visitArchitecture_statement(vhdlParser::Architecture_statementContext *context) = 0;

    virtual T* visitArchitecture_statement_part(vhdlParser::Architecture_statement_partContext *context) = 0;

    virtual T* visitArray_nature_definition(vhdlParser::Array_nature_definitionContext *context) = 0;

    virtual T* visitArray_type_definition(vhdlParser::Array_type_definitionContext *context) = 0;

    virtual T* visitAssertion(vhdlParser::AssertionContext *context) = 0;

    virtual T* visitAssertion_statement(vhdlParser::Assertion_statementContext *context) = 0;

    virtual T* visitAssociation_element(vhdlParser::Association_elementContext *context) = 0;

    virtual T* visitAssociation_list(vhdlParser::Association_listContext *context) = 0;

    virtual T* visitAttribute_declaration(vhdlParser::Attribute_declarationContext *context) = 0;

    virtual T* visitAttribute_designator(vhdlParser::Attribute_designatorContext *context) = 0;

    virtual T* visitAttribute_specification(vhdlParser::Attribute_specificationContext *context) = 0;

    virtual T* visitBase_unit_declaration(vhdlParser::Base_unit_declarationContext *context) = 0;

    virtual T* visitBinding_indication(vhdlParser::Binding_indicationContext *context) = 0;

    virtual T* visitBlock_configuration(vhdlParser::Block_configurationContext *context) = 0;

    virtual T* visitBlock_declarative_item(vhdlParser::Block_declarative_itemContext *context) = 0;

    virtual T* visitBlock_declarative_part(vhdlParser::Block_declarative_partContext *context) = 0;

    virtual T* visitBlock_header(vhdlParser::Block_headerContext *context) = 0;

    virtual T* visitBlock_specification(vhdlParser::Block_specificationContext *context) = 0;

    virtual T* visitBlock_statement(vhdlParser::Block_statementContext *context) = 0;

    virtual T* visitBlock_statement_part(vhdlParser::Block_statement_partContext *context) = 0;

    virtual T* visitBranch_quantity_declaration(vhdlParser::Branch_quantity_declarationContext *context) = 0;

    virtual T* visitBreak_element(vhdlParser::Break_elementContext *context) = 0;

    virtual T* visitBreak_list(vhdlParser::Break_listContext *context) = 0;

    virtual T* visitBreak_selector_clause(vhdlParser::Break_selector_clauseContext *context) = 0;

    virtual T* visitBreak_statement(vhdlParser::Break_statementContext *context) = 0;

    virtual T* visitCase_statement(vhdlParser::Case_statementContext *context) = 0;

    virtual T* visitCase_statement_alternative(vhdlParser::Case_statement_alternativeContext *context) = 0;

    virtual T* visitChoice(vhdlParser::ChoiceContext *context) = 0;

    virtual T* visitChoices(vhdlParser::ChoicesContext *context) = 0;

    virtual T* visitComponent_configuration(vhdlParser::Component_configurationContext *context) = 0;

    virtual T* visitComponent_declaration(vhdlParser::Component_declarationContext *context) = 0;

    virtual T* visitComponent_instantiation_statement(vhdlParser::Component_instantiation_statementContext *context) = 0;

    virtual T* visitComponent_specification(vhdlParser::Component_specificationContext *context) = 0;

    virtual T* visitComposite_nature_definition(vhdlParser::Composite_nature_definitionContext *context) = 0;

    virtual T* visitComposite_type_definition(vhdlParser::Composite_type_definitionContext *context) = 0;

    virtual T* visitConcurrent_assertion_statement(vhdlParser::Concurrent_assertion_statementContext *context) = 0;

    virtual T* visitConcurrent_break_statement(vhdlParser::Concurrent_break_statementContext *context) = 0;

    virtual T* visitConcurrent_procedure_call_statement(vhdlParser::Concurrent_procedure_call_statementContext *context) = 0;

    virtual T* visitConcurrent_signal_assignment_statement(vhdlParser::Concurrent_signal_assignment_statementContext *context) = 0;

    virtual T* visitCondition(vhdlParser::ConditionContext *context) = 0;

    virtual T* visitCondition_clause(vhdlParser::Condition_clauseContext *context) = 0;

    virtual T* visitConditional_signal_assignment(vhdlParser::Conditional_signal_assignmentContext *context) = 0;

    virtual T* visitConditional_waveforms(vhdlParser::Conditional_waveformsContext *context) = 0;

    virtual T* visitConfiguration_declaration(vhdlParser::Configuration_declarationContext *context) = 0;

    virtual T* visitConfiguration_declarative_item(vhdlParser::Configuration_declarative_itemContext *context) = 0;

    virtual T* visitConfiguration_declarative_part(vhdlParser::Configuration_declarative_partContext *context) = 0;

    virtual T* visitConfiguration_item(vhdlParser::Configuration_itemContext *context) = 0;

    virtual T* visitConfiguration_specification(vhdlParser::Configuration_specificationContext *context) = 0;

    virtual T* visitConstant_declaration(vhdlParser::Constant_declarationContext *context) = 0;

    virtual T* visitConstrained_array_definition(vhdlParser::Constrained_array_definitionContext *context) = 0;

    virtual T* visitConstrained_nature_definition(vhdlParser::Constrained_nature_definitionContext *context) = 0;

    virtual T* visitConstraint(vhdlParser::ConstraintContext *context) = 0;

    virtual T* visitContext_clause(vhdlParser::Context_clauseContext *context) = 0;

    virtual T* visitContext_item(vhdlParser::Context_itemContext *context) = 0;

    virtual T* visitDelay_mechanism(vhdlParser::Delay_mechanismContext *context) = 0;

    virtual T* visitDesign_file(vhdlParser::Design_fileContext *context) = 0;

    virtual T* visitDesign_unit(vhdlParser::Design_unitContext *context) = 0;

    virtual T* visitDesignator(vhdlParser::DesignatorContext *context) = 0;

    virtual T* visitDirection(vhdlParser::DirectionContext *context) = 0;

    virtual T* visitDisconnection_specification(vhdlParser::Disconnection_specificationContext *context) = 0;

    virtual T* visitDiscrete_range(vhdlParser::Discrete_rangeContext *context) = 0;

    virtual T* visitElement_association(vhdlParser::Element_associationContext *context) = 0;

    virtual T* visitElement_declaration(vhdlParser::Element_declarationContext *context) = 0;

    virtual T* visitElement_subnature_definition(vhdlParser::Element_subnature_definitionContext *context) = 0;

    virtual T* visitElement_subtype_definition(vhdlParser::Element_subtype_definitionContext *context) = 0;

    virtual T* visitEntity_aspect(vhdlParser::Entity_aspectContext *context) = 0;

    virtual T* visitEntity_class(vhdlParser::Entity_classContext *context) = 0;

    virtual T* visitEntity_class_entry(vhdlParser::Entity_class_entryContext *context) = 0;

    virtual T* visitEntity_class_entry_list(vhdlParser::Entity_class_entry_listContext *context) = 0;

    virtual T* visitEntity_declaration(vhdlParser::Entity_declarationContext *context) = 0;

    virtual T* visitEntity_declarative_item(vhdlParser::Entity_declarative_itemContext *context) = 0;

    virtual T* visitEntity_declarative_part(vhdlParser::Entity_declarative_partContext *context) = 0;

    virtual T* visitEntity_designator(vhdlParser::Entity_designatorContext *context) = 0;

    virtual T* visitEntity_header(vhdlParser::Entity_headerContext *context) = 0;

    virtual T* visitEntity_name_list(vhdlParser::Entity_name_listContext *context) = 0;

    virtual T* visitEntity_specification(vhdlParser::Entity_specificationContext *context) = 0;

    virtual T* visitEntity_statement(vhdlParser::Entity_statementContext *context) = 0;

    virtual T* visitEntity_statement_part(vhdlParser::Entity_statement_partContext *context) = 0;

    virtual T* visitEntity_tag(vhdlParser::Entity_tagContext *context) = 0;

    virtual T* visitEnumeration_literal(vhdlParser::Enumeration_literalContext *context) = 0;

    virtual T* visitEnumeration_type_definition(vhdlParser::Enumeration_type_definitionContext *context) = 0;

    virtual T* visitExit_statement(vhdlParser::Exit_statementContext *context) = 0;

    virtual T* visitExpression(vhdlParser::ExpressionContext *context) = 0;

    virtual T* visitFactor(vhdlParser::FactorContext *context) = 0;

    virtual T* visitFile_declaration(vhdlParser::File_declarationContext *context) = 0;

    virtual T* visitFile_logical_name(vhdlParser::File_logical_nameContext *context) = 0;

    virtual T* visitFile_open_information(vhdlParser::File_open_informationContext *context) = 0;

    virtual T* visitFile_type_definition(vhdlParser::File_type_definitionContext *context) = 0;

    virtual T* visitFormal_parameter_list(vhdlParser::Formal_parameter_listContext *context) = 0;

    virtual T* visitFormal_part(vhdlParser::Formal_partContext *context) = 0;

    virtual T* visitFree_quantity_declaration(vhdlParser::Free_quantity_declarationContext *context) = 0;

    virtual T* visitGenerate_statement(vhdlParser::Generate_statementContext *context) = 0;

    virtual T* visitGeneration_scheme(vhdlParser::Generation_schemeContext *context) = 0;

    virtual T* visitGeneric_clause(vhdlParser::Generic_clauseContext *context) = 0;

    virtual T* visitGeneric_list(vhdlParser::Generic_listContext *context) = 0;

    virtual T* visitGeneric_map_aspect(vhdlParser::Generic_map_aspectContext *context) = 0;

    virtual T* visitGroup_constituent(vhdlParser::Group_constituentContext *context) = 0;

    virtual T* visitGroup_constituent_list(vhdlParser::Group_constituent_listContext *context) = 0;

    virtual T* visitGroup_declaration(vhdlParser::Group_declarationContext *context) = 0;

    virtual T* visitGroup_template_declaration(vhdlParser::Group_template_declarationContext *context) = 0;

    virtual T* visitGuarded_signal_specification(vhdlParser::Guarded_signal_specificationContext *context) = 0;

    virtual T* visitIdentifier(vhdlParser::IdentifierContext *context) = 0;

    virtual T* visitIdentifier_list(vhdlParser::Identifier_listContext *context) = 0;

    virtual T* visitIf_statement(vhdlParser::If_statementContext *context) = 0;

    virtual T* visitIndex_constraint(vhdlParser::Index_constraintContext *context) = 0;

    virtual T* visitIndex_specification(vhdlParser::Index_specificationContext *context) = 0;

    virtual T* visitIndex_subtype_definition(vhdlParser::Index_subtype_definitionContext *context) = 0;

    virtual T* visitInstantiated_unit(vhdlParser::Instantiated_unitContext *context) = 0;

    virtual T* visitInstantiation_list(vhdlParser::Instantiation_listContext *context) = 0;

    virtual T* visitInterface_constant_declaration(vhdlParser::Interface_constant_declarationContext *context) = 0;

    virtual T* visitInterface_declaration(vhdlParser::Interface_declarationContext *context) = 0;

    virtual T* visitInterface_element(vhdlParser::Interface_elementContext *context) = 0;

    virtual T* visitInterface_file_declaration(vhdlParser::Interface_file_declarationContext *context) = 0;

    virtual T* visitInterface_signal_list(vhdlParser::Interface_signal_listContext *context) = 0;

    virtual T* visitInterface_port_list(vhdlParser::Interface_port_listContext *context) = 0;

    virtual T* visitInterface_list(vhdlParser::Interface_listContext *context) = 0;

    virtual T* visitInterface_quantity_declaration(vhdlParser::Interface_quantity_declarationContext *context) = 0;

    virtual T* visitInterface_port_declaration(vhdlParser::Interface_port_declarationContext *context) = 0;

    virtual T* visitInterface_signal_declaration(vhdlParser::Interface_signal_declarationContext *context) = 0;

    virtual T* visitInterface_terminal_declaration(vhdlParser::Interface_terminal_declarationContext *context) = 0;

    virtual T* visitInterface_variable_declaration(vhdlParser::Interface_variable_declarationContext *context) = 0;

    virtual T* visitIteration_scheme(vhdlParser::Iteration_schemeContext *context) = 0;

    virtual T* visitLabel_colon(vhdlParser::Label_colonContext *context) = 0;

    virtual T* visitLibrary_clause(vhdlParser::Library_clauseContext *context) = 0;

    virtual T* visitLibrary_unit(vhdlParser::Library_unitContext *context) = 0;

    virtual T* visitLiteral(vhdlParser::LiteralContext *context) = 0;

    virtual T* visitLogical_name(vhdlParser::Logical_nameContext *context) = 0;

    virtual T* visitLogical_name_list(vhdlParser::Logical_name_listContext *context) = 0;

    virtual T* visitLogical_operator(vhdlParser::Logical_operatorContext *context) = 0;

    virtual T* visitLoop_statement(vhdlParser::Loop_statementContext *context) = 0;

    virtual T* visitSignal_mode(vhdlParser::Signal_modeContext *context) = 0;

    virtual T* visitMultiplying_operator(vhdlParser::Multiplying_operatorContext *context) = 0;

    virtual T* visitName(vhdlParser::NameContext *context) = 0;

    virtual T* visitName_part(vhdlParser::Name_partContext *context) = 0;

    virtual T* visitName_part_specificator(vhdlParser::Name_part_specificatorContext *context) = 0;

    virtual T* visitName_attribute_part(vhdlParser::Name_attribute_partContext *context) = 0;

    virtual T* visitName_function_call_or_indexed_part(vhdlParser::Name_function_call_or_indexed_partContext *context) = 0;

    virtual T* visitName_slice_part(vhdlParser::Name_slice_partContext *context) = 0;

    virtual T* visitSelected_name(vhdlParser::Selected_nameContext *context) = 0;

    virtual T* visitNature_declaration(vhdlParser::Nature_declarationContext *context) = 0;

    virtual T* visitNature_definition(vhdlParser::Nature_definitionContext *context) = 0;

    virtual T* visitNature_element_declaration(vhdlParser::Nature_element_declarationContext *context) = 0;

    virtual T* visitNext_statement(vhdlParser::Next_statementContext *context) = 0;

    virtual T* visitNumeric_literal(vhdlParser::Numeric_literalContext *context) = 0;

    virtual T* visitObject_declaration(vhdlParser::Object_declarationContext *context) = 0;

    virtual T* visitOpts(vhdlParser::OptsContext *context) = 0;

    virtual T* visitPackage_body(vhdlParser::Package_bodyContext *context) = 0;

    virtual T* visitPackage_body_declarative_item(vhdlParser::Package_body_declarative_itemContext *context) = 0;

    virtual T* visitPackage_body_declarative_part(vhdlParser::Package_body_declarative_partContext *context) = 0;

    virtual T* visitPackage_declaration(vhdlParser::Package_declarationContext *context) = 0;

    virtual T* visitPackage_declarative_item(vhdlParser::Package_declarative_itemContext *context) = 0;

    virtual T* visitPackage_declarative_part(vhdlParser::Package_declarative_partContext *context) = 0;

    virtual T* visitParameter_specification(vhdlParser::Parameter_specificationContext *context) = 0;

    virtual T* visitPhysical_literal(vhdlParser::Physical_literalContext *context) = 0;

    virtual T* visitPhysical_type_definition(vhdlParser::Physical_type_definitionContext *context) = 0;

    virtual T* visitPort_clause(vhdlParser::Port_clauseContext *context) = 0;

    virtual T* visitPort_list(vhdlParser::Port_listContext *context) = 0;

    virtual T* visitPort_map_aspect(vhdlParser::Port_map_aspectContext *context) = 0;

    virtual T* visitPrimary(vhdlParser::PrimaryContext *context) = 0;

    virtual T* visitPrimary_unit(vhdlParser::Primary_unitContext *context) = 0;

    virtual T* visitProcedural_declarative_item(vhdlParser::Procedural_declarative_itemContext *context) = 0;

    virtual T* visitProcedural_declarative_part(vhdlParser::Procedural_declarative_partContext *context) = 0;

    virtual T* visitProcedural_statement_part(vhdlParser::Procedural_statement_partContext *context) = 0;

    virtual T* visitProcedure_call(vhdlParser::Procedure_callContext *context) = 0;

    virtual T* visitProcedure_call_statement(vhdlParser::Procedure_call_statementContext *context) = 0;

    virtual T* visitProcess_declarative_item(vhdlParser::Process_declarative_itemContext *context) = 0;

    virtual T* visitProcess_declarative_part(vhdlParser::Process_declarative_partContext *context) = 0;

    virtual T* visitProcess_statement(vhdlParser::Process_statementContext *context) = 0;

    virtual T* visitProcess_statement_part(vhdlParser::Process_statement_partContext *context) = 0;

    virtual T* visitQualified_expression(vhdlParser::Qualified_expressionContext *context) = 0;

    virtual T* visitQuantity_declaration(vhdlParser::Quantity_declarationContext *context) = 0;

    virtual T* visitQuantity_list(vhdlParser::Quantity_listContext *context) = 0;

    virtual T* visitQuantity_specification(vhdlParser::Quantity_specificationContext *context) = 0;

    virtual T* visitRange(vhdlParser::RangeContext *context) = 0;

    virtual T* visitExplicit_range(vhdlParser::Explicit_rangeContext *context) = 0;

    virtual T* visitRange_constraint(vhdlParser::Range_constraintContext *context) = 0;

    virtual T* visitRecord_nature_definition(vhdlParser::Record_nature_definitionContext *context) = 0;

    virtual T* visitRecord_type_definition(vhdlParser::Record_type_definitionContext *context) = 0;

    virtual T* visitRelation(vhdlParser::RelationContext *context) = 0;

    virtual T* visitRelational_operator(vhdlParser::Relational_operatorContext *context) = 0;

    virtual T* visitReport_statement(vhdlParser::Report_statementContext *context) = 0;

    virtual T* visitReturn_statement(vhdlParser::Return_statementContext *context) = 0;

    virtual T* visitScalar_nature_definition(vhdlParser::Scalar_nature_definitionContext *context) = 0;

    virtual T* visitScalar_type_definition(vhdlParser::Scalar_type_definitionContext *context) = 0;

    virtual T* visitSecondary_unit(vhdlParser::Secondary_unitContext *context) = 0;

    virtual T* visitSecondary_unit_declaration(vhdlParser::Secondary_unit_declarationContext *context) = 0;

    virtual T* visitSelected_signal_assignment(vhdlParser::Selected_signal_assignmentContext *context) = 0;

    virtual T* visitSelected_waveforms(vhdlParser::Selected_waveformsContext *context) = 0;

    virtual T* visitSensitivity_clause(vhdlParser::Sensitivity_clauseContext *context) = 0;

    virtual T* visitSensitivity_list(vhdlParser::Sensitivity_listContext *context) = 0;

    virtual T* visitSequence_of_statements(vhdlParser::Sequence_of_statementsContext *context) = 0;

    virtual T* visitSequential_statement(vhdlParser::Sequential_statementContext *context) = 0;

    virtual T* visitShift_expression(vhdlParser::Shift_expressionContext *context) = 0;

    virtual T* visitShift_operator(vhdlParser::Shift_operatorContext *context) = 0;

    virtual T* visitSignal_assignment_statement(vhdlParser::Signal_assignment_statementContext *context) = 0;

    virtual T* visitSignal_declaration(vhdlParser::Signal_declarationContext *context) = 0;

    virtual T* visitSignal_kind(vhdlParser::Signal_kindContext *context) = 0;

    virtual T* visitSignal_list(vhdlParser::Signal_listContext *context) = 0;

    virtual T* visitSignature(vhdlParser::SignatureContext *context) = 0;

    virtual T* visitSimple_expression(vhdlParser::Simple_expressionContext *context) = 0;

    virtual T* visitSimple_simultaneous_statement(vhdlParser::Simple_simultaneous_statementContext *context) = 0;

    virtual T* visitSimultaneous_alternative(vhdlParser::Simultaneous_alternativeContext *context) = 0;

    virtual T* visitSimultaneous_case_statement(vhdlParser::Simultaneous_case_statementContext *context) = 0;

    virtual T* visitSimultaneous_if_statement(vhdlParser::Simultaneous_if_statementContext *context) = 0;

    virtual T* visitSimultaneous_procedural_statement(vhdlParser::Simultaneous_procedural_statementContext *context) = 0;

    virtual T* visitSimultaneous_statement(vhdlParser::Simultaneous_statementContext *context) = 0;

    virtual T* visitSimultaneous_statement_part(vhdlParser::Simultaneous_statement_partContext *context) = 0;

    virtual T* visitSource_aspect(vhdlParser::Source_aspectContext *context) = 0;

    virtual T* visitSource_quantity_declaration(vhdlParser::Source_quantity_declarationContext *context) = 0;

    virtual T* visitStep_limit_specification(vhdlParser::Step_limit_specificationContext *context) = 0;

    virtual T* visitSubnature_declaration(vhdlParser::Subnature_declarationContext *context) = 0;

    virtual T* visitSubnature_indication(vhdlParser::Subnature_indicationContext *context) = 0;

    virtual T* visitSubprogram_body(vhdlParser::Subprogram_bodyContext *context) = 0;

    virtual T* visitSubprogram_declaration(vhdlParser::Subprogram_declarationContext *context) = 0;

    virtual T* visitSubprogram_declarative_item(vhdlParser::Subprogram_declarative_itemContext *context) = 0;

    virtual T* visitSubprogram_declarative_part(vhdlParser::Subprogram_declarative_partContext *context) = 0;

    virtual T* visitSubprogram_kind(vhdlParser::Subprogram_kindContext *context) = 0;

    virtual T* visitSubprogram_specification(vhdlParser::Subprogram_specificationContext *context) = 0;

    virtual T* visitProcedure_specification(vhdlParser::Procedure_specificationContext *context) = 0;

    virtual T* visitFunction_specification(vhdlParser::Function_specificationContext *context) = 0;

    virtual T* visitSubprogram_statement_part(vhdlParser::Subprogram_statement_partContext *context) = 0;

    virtual T* visitSubtype_declaration(vhdlParser::Subtype_declarationContext *context) = 0;

    virtual T* visitSubtype_indication(vhdlParser::Subtype_indicationContext *context) = 0;

    virtual T* visitSuffix(vhdlParser::SuffixContext *context) = 0;

    virtual T* visitTarget(vhdlParser::TargetContext *context) = 0;

    virtual T* visitTerm(vhdlParser::TermContext *context) = 0;

    virtual T* visitTerminal_aspect(vhdlParser::Terminal_aspectContext *context) = 0;

    virtual T* visitTerminal_declaration(vhdlParser::Terminal_declarationContext *context) = 0;

    virtual T* visitThrough_aspect(vhdlParser::Through_aspectContext *context) = 0;

    virtual T* visitTimeout_clause(vhdlParser::Timeout_clauseContext *context) = 0;

    virtual T* visitTolerance_aspect(vhdlParser::Tolerance_aspectContext *context) = 0;

    virtual T* visitType_declaration(vhdlParser::Type_declarationContext *context) = 0;

    virtual T* visitType_definition(vhdlParser::Type_definitionContext *context) = 0;

    virtual T* visitUnconstrained_array_definition(vhdlParser::Unconstrained_array_definitionContext *context) = 0;

    virtual T* visitUnconstrained_nature_definition(vhdlParser::Unconstrained_nature_definitionContext *context) = 0;

    virtual T* visitUse_clause(vhdlParser::Use_clauseContext *context) = 0;

    virtual T* visitVariable_assignment_statement(vhdlParser::Variable_assignment_statementContext *context) = 0;

    virtual T* visitVariable_declaration(vhdlParser::Variable_declarationContext *context) = 0;

    virtual T* visitWait_statement(vhdlParser::Wait_statementContext *context) = 0;

    virtual T* visitWaveform(vhdlParser::WaveformContext *context) = 0;

    virtual T* visitWaveform_element(vhdlParser::Waveform_elementContext *context) = 0;


};

}  // namespace vhdl
