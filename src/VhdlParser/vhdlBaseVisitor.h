
// Generated from vhdl.g4 by ANTLR 4.5.3

#pragma once


#include "antlr4-runtime.h"
#include "vhdlVisitor.h"


namespace vhdl {

/**
 * This class provides an empty implementation of vhdlVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 *
 * @param <T> The return type of the visit operation. Use void for operations with no return type.
 */
template <typename T>
class vhdlBaseVisitor : public tree::AbstractParseTreeVisitor<T>, public vhdlVisitor<T> {
public:

  virtual T* visitAbstract_literal(vhdlParser::Abstract_literalContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAccess_type_definition(vhdlParser::Access_type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAcross_aspect(vhdlParser::Across_aspectContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitActual_designator(vhdlParser::Actual_designatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitActual_parameter_part(vhdlParser::Actual_parameter_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitActual_part(vhdlParser::Actual_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAdding_operator(vhdlParser::Adding_operatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAggregate(vhdlParser::AggregateContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAlias_declaration(vhdlParser::Alias_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAlias_designator(vhdlParser::Alias_designatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAlias_indication(vhdlParser::Alias_indicationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAllocator(vhdlParser::AllocatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitArchitecture_body(vhdlParser::Architecture_bodyContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitArchitecture_declarative_part(vhdlParser::Architecture_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitArchitecture_statement(vhdlParser::Architecture_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitArchitecture_statement_part(vhdlParser::Architecture_statement_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitArray_nature_definition(vhdlParser::Array_nature_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitArray_type_definition(vhdlParser::Array_type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAssertion(vhdlParser::AssertionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAssertion_statement(vhdlParser::Assertion_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAssociation_element(vhdlParser::Association_elementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAssociation_list(vhdlParser::Association_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAttribute_declaration(vhdlParser::Attribute_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAttribute_designator(vhdlParser::Attribute_designatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitAttribute_specification(vhdlParser::Attribute_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBase_unit_declaration(vhdlParser::Base_unit_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBinding_indication(vhdlParser::Binding_indicationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBlock_configuration(vhdlParser::Block_configurationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBlock_declarative_item(vhdlParser::Block_declarative_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBlock_declarative_part(vhdlParser::Block_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBlock_header(vhdlParser::Block_headerContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBlock_specification(vhdlParser::Block_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBlock_statement(vhdlParser::Block_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBlock_statement_part(vhdlParser::Block_statement_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBranch_quantity_declaration(vhdlParser::Branch_quantity_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBreak_element(vhdlParser::Break_elementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBreak_list(vhdlParser::Break_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBreak_selector_clause(vhdlParser::Break_selector_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitBreak_statement(vhdlParser::Break_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitCase_statement(vhdlParser::Case_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitCase_statement_alternative(vhdlParser::Case_statement_alternativeContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitChoice(vhdlParser::ChoiceContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitChoices(vhdlParser::ChoicesContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitComponent_configuration(vhdlParser::Component_configurationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitComponent_declaration(vhdlParser::Component_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitComponent_instantiation_statement(vhdlParser::Component_instantiation_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitComponent_specification(vhdlParser::Component_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitComposite_nature_definition(vhdlParser::Composite_nature_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitComposite_type_definition(vhdlParser::Composite_type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConcurrent_assertion_statement(vhdlParser::Concurrent_assertion_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConcurrent_break_statement(vhdlParser::Concurrent_break_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConcurrent_procedure_call_statement(vhdlParser::Concurrent_procedure_call_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConcurrent_signal_assignment_statement(vhdlParser::Concurrent_signal_assignment_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitCondition(vhdlParser::ConditionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitCondition_clause(vhdlParser::Condition_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConditional_signal_assignment(vhdlParser::Conditional_signal_assignmentContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConditional_waveforms(vhdlParser::Conditional_waveformsContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConfiguration_declaration(vhdlParser::Configuration_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConfiguration_declarative_item(vhdlParser::Configuration_declarative_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConfiguration_declarative_part(vhdlParser::Configuration_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConfiguration_item(vhdlParser::Configuration_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConfiguration_specification(vhdlParser::Configuration_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConstant_declaration(vhdlParser::Constant_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConstrained_array_definition(vhdlParser::Constrained_array_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConstrained_nature_definition(vhdlParser::Constrained_nature_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitConstraint(vhdlParser::ConstraintContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitContext_clause(vhdlParser::Context_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitContext_item(vhdlParser::Context_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitDelay_mechanism(vhdlParser::Delay_mechanismContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitDesign_file(vhdlParser::Design_fileContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitDesign_unit(vhdlParser::Design_unitContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitDesignator(vhdlParser::DesignatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitDirection(vhdlParser::DirectionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitDisconnection_specification(vhdlParser::Disconnection_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitDiscrete_range(vhdlParser::Discrete_rangeContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitElement_association(vhdlParser::Element_associationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitElement_declaration(vhdlParser::Element_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitElement_subnature_definition(vhdlParser::Element_subnature_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitElement_subtype_definition(vhdlParser::Element_subtype_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_aspect(vhdlParser::Entity_aspectContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_class(vhdlParser::Entity_classContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_class_entry(vhdlParser::Entity_class_entryContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_class_entry_list(vhdlParser::Entity_class_entry_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_declaration(vhdlParser::Entity_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_declarative_item(vhdlParser::Entity_declarative_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_declarative_part(vhdlParser::Entity_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_designator(vhdlParser::Entity_designatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_header(vhdlParser::Entity_headerContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_name_list(vhdlParser::Entity_name_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_specification(vhdlParser::Entity_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_statement(vhdlParser::Entity_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_statement_part(vhdlParser::Entity_statement_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEntity_tag(vhdlParser::Entity_tagContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEnumeration_literal(vhdlParser::Enumeration_literalContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitEnumeration_type_definition(vhdlParser::Enumeration_type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitExit_statement(vhdlParser::Exit_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitExpression(vhdlParser::ExpressionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFactor(vhdlParser::FactorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFile_declaration(vhdlParser::File_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFile_logical_name(vhdlParser::File_logical_nameContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFile_open_information(vhdlParser::File_open_informationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFile_type_definition(vhdlParser::File_type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFormal_parameter_list(vhdlParser::Formal_parameter_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFormal_part(vhdlParser::Formal_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFree_quantity_declaration(vhdlParser::Free_quantity_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGenerate_statement(vhdlParser::Generate_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGeneration_scheme(vhdlParser::Generation_schemeContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGeneric_clause(vhdlParser::Generic_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGeneric_list(vhdlParser::Generic_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGeneric_map_aspect(vhdlParser::Generic_map_aspectContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGroup_constituent(vhdlParser::Group_constituentContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGroup_constituent_list(vhdlParser::Group_constituent_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGroup_declaration(vhdlParser::Group_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGroup_template_declaration(vhdlParser::Group_template_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitGuarded_signal_specification(vhdlParser::Guarded_signal_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitIdentifier(vhdlParser::IdentifierContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitIdentifier_list(vhdlParser::Identifier_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitIf_statement(vhdlParser::If_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitIndex_constraint(vhdlParser::Index_constraintContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitIndex_specification(vhdlParser::Index_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitIndex_subtype_definition(vhdlParser::Index_subtype_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInstantiated_unit(vhdlParser::Instantiated_unitContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInstantiation_list(vhdlParser::Instantiation_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_constant_declaration(vhdlParser::Interface_constant_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_declaration(vhdlParser::Interface_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_element(vhdlParser::Interface_elementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_file_declaration(vhdlParser::Interface_file_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_signal_list(vhdlParser::Interface_signal_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_port_list(vhdlParser::Interface_port_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_list(vhdlParser::Interface_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_quantity_declaration(vhdlParser::Interface_quantity_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_port_declaration(vhdlParser::Interface_port_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_signal_declaration(vhdlParser::Interface_signal_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_terminal_declaration(vhdlParser::Interface_terminal_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitInterface_variable_declaration(vhdlParser::Interface_variable_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitIteration_scheme(vhdlParser::Iteration_schemeContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitLabel_colon(vhdlParser::Label_colonContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitLibrary_clause(vhdlParser::Library_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitLibrary_unit(vhdlParser::Library_unitContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitLiteral(vhdlParser::LiteralContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitLogical_name(vhdlParser::Logical_nameContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitLogical_name_list(vhdlParser::Logical_name_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitLogical_operator(vhdlParser::Logical_operatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitLoop_statement(vhdlParser::Loop_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSignal_mode(vhdlParser::Signal_modeContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitMultiplying_operator(vhdlParser::Multiplying_operatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitName(vhdlParser::NameContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitName_part(vhdlParser::Name_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitName_part_specificator(vhdlParser::Name_part_specificatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitName_attribute_part(vhdlParser::Name_attribute_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitName_function_call_or_indexed_part(vhdlParser::Name_function_call_or_indexed_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitName_slice_part(vhdlParser::Name_slice_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSelected_name(vhdlParser::Selected_nameContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitNature_declaration(vhdlParser::Nature_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitNature_definition(vhdlParser::Nature_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitNature_element_declaration(vhdlParser::Nature_element_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitNext_statement(vhdlParser::Next_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitNumeric_literal(vhdlParser::Numeric_literalContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitObject_declaration(vhdlParser::Object_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitOpts(vhdlParser::OptsContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPackage_body(vhdlParser::Package_bodyContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPackage_body_declarative_item(vhdlParser::Package_body_declarative_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPackage_body_declarative_part(vhdlParser::Package_body_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPackage_declaration(vhdlParser::Package_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPackage_declarative_item(vhdlParser::Package_declarative_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPackage_declarative_part(vhdlParser::Package_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitParameter_specification(vhdlParser::Parameter_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPhysical_literal(vhdlParser::Physical_literalContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPhysical_type_definition(vhdlParser::Physical_type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPort_clause(vhdlParser::Port_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPort_list(vhdlParser::Port_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPort_map_aspect(vhdlParser::Port_map_aspectContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPrimary(vhdlParser::PrimaryContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitPrimary_unit(vhdlParser::Primary_unitContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcedural_declarative_item(vhdlParser::Procedural_declarative_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcedural_declarative_part(vhdlParser::Procedural_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcedural_statement_part(vhdlParser::Procedural_statement_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcedure_call(vhdlParser::Procedure_callContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcedure_call_statement(vhdlParser::Procedure_call_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcess_declarative_item(vhdlParser::Process_declarative_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcess_declarative_part(vhdlParser::Process_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcess_statement(vhdlParser::Process_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcess_statement_part(vhdlParser::Process_statement_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitQualified_expression(vhdlParser::Qualified_expressionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitQuantity_declaration(vhdlParser::Quantity_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitQuantity_list(vhdlParser::Quantity_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitQuantity_specification(vhdlParser::Quantity_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitRange(vhdlParser::RangeContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitExplicit_range(vhdlParser::Explicit_rangeContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitRange_constraint(vhdlParser::Range_constraintContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitRecord_nature_definition(vhdlParser::Record_nature_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitRecord_type_definition(vhdlParser::Record_type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitRelation(vhdlParser::RelationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitRelational_operator(vhdlParser::Relational_operatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitReport_statement(vhdlParser::Report_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitReturn_statement(vhdlParser::Return_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitScalar_nature_definition(vhdlParser::Scalar_nature_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitScalar_type_definition(vhdlParser::Scalar_type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSecondary_unit(vhdlParser::Secondary_unitContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSecondary_unit_declaration(vhdlParser::Secondary_unit_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSelected_signal_assignment(vhdlParser::Selected_signal_assignmentContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSelected_waveforms(vhdlParser::Selected_waveformsContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSensitivity_clause(vhdlParser::Sensitivity_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSensitivity_list(vhdlParser::Sensitivity_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSequence_of_statements(vhdlParser::Sequence_of_statementsContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSequential_statement(vhdlParser::Sequential_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitShift_expression(vhdlParser::Shift_expressionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitShift_operator(vhdlParser::Shift_operatorContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSignal_assignment_statement(vhdlParser::Signal_assignment_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSignal_declaration(vhdlParser::Signal_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSignal_kind(vhdlParser::Signal_kindContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSignal_list(vhdlParser::Signal_listContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSignature(vhdlParser::SignatureContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSimple_expression(vhdlParser::Simple_expressionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSimple_simultaneous_statement(vhdlParser::Simple_simultaneous_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSimultaneous_alternative(vhdlParser::Simultaneous_alternativeContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSimultaneous_case_statement(vhdlParser::Simultaneous_case_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSimultaneous_if_statement(vhdlParser::Simultaneous_if_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSimultaneous_procedural_statement(vhdlParser::Simultaneous_procedural_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSimultaneous_statement(vhdlParser::Simultaneous_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSimultaneous_statement_part(vhdlParser::Simultaneous_statement_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSource_aspect(vhdlParser::Source_aspectContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSource_quantity_declaration(vhdlParser::Source_quantity_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitStep_limit_specification(vhdlParser::Step_limit_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubnature_declaration(vhdlParser::Subnature_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubnature_indication(vhdlParser::Subnature_indicationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubprogram_body(vhdlParser::Subprogram_bodyContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubprogram_declaration(vhdlParser::Subprogram_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubprogram_declarative_item(vhdlParser::Subprogram_declarative_itemContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubprogram_declarative_part(vhdlParser::Subprogram_declarative_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubprogram_kind(vhdlParser::Subprogram_kindContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubprogram_specification(vhdlParser::Subprogram_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitProcedure_specification(vhdlParser::Procedure_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitFunction_specification(vhdlParser::Function_specificationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubprogram_statement_part(vhdlParser::Subprogram_statement_partContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubtype_declaration(vhdlParser::Subtype_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSubtype_indication(vhdlParser::Subtype_indicationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitSuffix(vhdlParser::SuffixContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitTarget(vhdlParser::TargetContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitTerm(vhdlParser::TermContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitTerminal_aspect(vhdlParser::Terminal_aspectContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitTerminal_declaration(vhdlParser::Terminal_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitThrough_aspect(vhdlParser::Through_aspectContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitTimeout_clause(vhdlParser::Timeout_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitTolerance_aspect(vhdlParser::Tolerance_aspectContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitType_declaration(vhdlParser::Type_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitType_definition(vhdlParser::Type_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitUnconstrained_array_definition(vhdlParser::Unconstrained_array_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitUnconstrained_nature_definition(vhdlParser::Unconstrained_nature_definitionContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitUse_clause(vhdlParser::Use_clauseContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitVariable_assignment_statement(vhdlParser::Variable_assignment_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitVariable_declaration(vhdlParser::Variable_declarationContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitWait_statement(vhdlParser::Wait_statementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitWaveform(vhdlParser::WaveformContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }

  virtual T* visitWaveform_element(vhdlParser::Waveform_elementContext *ctx) override {
    return tree::AbstractParseTreeVisitor<T>::visitChildren(ctx);
  }


};

}  // namespace vhdl
