
// Generated from vhdl.g4 by ANTLR 4.5.3

#pragma once


#include "antlr4-runtime.h"


using namespace antlr4;

namespace vhdl {

template <typename T>
class vhdlVisitor;

class vhdlParser : public Parser {
public:
  enum {
    ABS = 1, ACCESS = 2, ACROSS = 3, AFTER = 4, ALIAS = 5, ALL = 6, AND = 7, 
    ARCHITECTURE = 8, ARRAY = 9, ASSERT = 10, ATTRIBUTE = 11, BEGIN = 12, 
    BLOCK = 13, BODY = 14, BREAK = 15, BUFFER = 16, BUS = 17, CASE = 18, 
    COMPONENT = 19, CONFIGURATION = 20, CONSTANT = 21, DISCONNECT = 22, 
    DOWNTO = 23, END = 24, ENTITY = 25, ELSE = 26, ELSIF = 27, EXIT = 28, 
    FILE = 29, FOR = 30, FUNCTION = 31, GENERATE = 32, GENERIC = 33, GROUP = 34, 
    GUARDED = 35, IF = 36, IMPURE = 37, IN = 38, INERTIAL = 39, INOUT = 40, 
    IS = 41, LABEL = 42, LIBRARY = 43, LIMIT = 44, LINKAGE = 45, LITERAL = 46, 
    LOOP = 47, MAP = 48, MOD = 49, NAND = 50, NATURE = 51, NEW = 52, NEXT = 53, 
    NOISE = 54, NOR = 55, NOT = 56, NULL_SYM = 57, OF = 58, ON = 59, OPEN = 60, 
    OR = 61, OTHERS = 62, OUT = 63, PACKAGE = 64, PORT = 65, POSTPONED = 66, 
    PROCESS = 67, PROCEDURE = 68, PROCEDURAL = 69, PURE = 70, QUANTITY = 71, 
    RANGE = 72, REVERSE_RANGE = 73, REJECT = 74, REM = 75, RECORD = 76, 
    REFERENCE = 77, REGISTER = 78, REPORT = 79, RETURN = 80, ROL = 81, ROR = 82, 
    SELECT = 83, SEVERITY = 84, SHARED = 85, SIGNAL = 86, SLA = 87, SLL = 88, 
    SPECTRUM = 89, SRA = 90, SRL = 91, SUBNATURE = 92, SUBTYPE = 93, TERMINAL = 94, 
    THEN = 95, THROUGH = 96, TO = 97, TOLERANCE = 98, TRANSPORT = 99, TYPE = 100, 
    UNAFFECTED = 101, UNITS = 102, UNTIL = 103, USE = 104, VARIABLE = 105, 
    WAIT = 106, WITH = 107, WHEN = 108, WHILE = 109, XNOR = 110, XOR = 111, 
    BASE_LITERAL = 112, BIT_STRING_LITERAL = 113, BIT_STRING_LITERAL_BINARY = 114, 
    BIT_STRING_LITERAL_OCTAL = 115, BIT_STRING_LITERAL_HEX = 116, REAL_LITERAL = 117, 
    BASIC_IDENTIFIER = 118, EXTENDED_IDENTIFIER = 119, LETTER = 120, COMMENT = 121, 
    TAB = 122, SPACE = 123, NEWLINE = 124, CR = 125, CHARACTER_LITERAL = 126, 
    STRING_LITERAL = 127, OTHER_SPECIAL_CHARACTER = 128, DOUBLESTAR = 129, 
    ASSIGN = 130, LE = 131, GE = 132, ARROW = 133, NEQ = 134, VARASGN = 135, 
    BOX = 136, DBLQUOTE = 137, SEMI = 138, COMMA = 139, AMPERSAND = 140, 
    LPAREN = 141, RPAREN = 142, LBRACKET = 143, RBRACKET = 144, COLON = 145, 
    MUL = 146, DIV = 147, PLUS = 148, MINUS = 149, LOWERTHAN = 150, GREATERTHAN = 151, 
    EQ = 152, BAR = 153, DOT = 154, BACKSLASH = 155, EXPONENT = 156, HEXDIGIT = 157, 
    INTEGER = 158, DIGIT = 159, BASED_INTEGER = 160, EXTENDED_DIGIT = 161, 
    APOSTROPHE = 162
  };

  enum {
    RuleAbstract_literal = 0, RuleAccess_type_definition = 1, RuleAcross_aspect = 2, 
    RuleActual_designator = 3, RuleActual_parameter_part = 4, RuleActual_part = 5, 
    RuleAdding_operator = 6, RuleAggregate = 7, RuleAlias_declaration = 8, 
    RuleAlias_designator = 9, RuleAlias_indication = 10, RuleAllocator = 11, 
    RuleArchitecture_body = 12, RuleArchitecture_declarative_part = 13, 
    RuleArchitecture_statement = 14, RuleArchitecture_statement_part = 15, 
    RuleArray_nature_definition = 16, RuleArray_type_definition = 17, RuleAssertion = 18, 
    RuleAssertion_statement = 19, RuleAssociation_element = 20, RuleAssociation_list = 21, 
    RuleAttribute_declaration = 22, RuleAttribute_designator = 23, RuleAttribute_specification = 24, 
    RuleBase_unit_declaration = 25, RuleBinding_indication = 26, RuleBlock_configuration = 27, 
    RuleBlock_declarative_item = 28, RuleBlock_declarative_part = 29, RuleBlock_header = 30, 
    RuleBlock_specification = 31, RuleBlock_statement = 32, RuleBlock_statement_part = 33, 
    RuleBranch_quantity_declaration = 34, RuleBreak_element = 35, RuleBreak_list = 36, 
    RuleBreak_selector_clause = 37, RuleBreak_statement = 38, RuleCase_statement = 39, 
    RuleCase_statement_alternative = 40, RuleChoice = 41, RuleChoices = 42, 
    RuleComponent_configuration = 43, RuleComponent_declaration = 44, RuleComponent_instantiation_statement = 45, 
    RuleComponent_specification = 46, RuleComposite_nature_definition = 47, 
    RuleComposite_type_definition = 48, RuleConcurrent_assertion_statement = 49, 
    RuleConcurrent_break_statement = 50, RuleConcurrent_procedure_call_statement = 51, 
    RuleConcurrent_signal_assignment_statement = 52, RuleCondition = 53, 
    RuleCondition_clause = 54, RuleConditional_signal_assignment = 55, RuleConditional_waveforms = 56, 
    RuleConfiguration_declaration = 57, RuleConfiguration_declarative_item = 58, 
    RuleConfiguration_declarative_part = 59, RuleConfiguration_item = 60, 
    RuleConfiguration_specification = 61, RuleConstant_declaration = 62, 
    RuleConstrained_array_definition = 63, RuleConstrained_nature_definition = 64, 
    RuleConstraint = 65, RuleContext_clause = 66, RuleContext_item = 67, 
    RuleDelay_mechanism = 68, RuleDesign_file = 69, RuleDesign_unit = 70, 
    RuleDesignator = 71, RuleDirection = 72, RuleDisconnection_specification = 73, 
    RuleDiscrete_range = 74, RuleElement_association = 75, RuleElement_declaration = 76, 
    RuleElement_subnature_definition = 77, RuleElement_subtype_definition = 78, 
    RuleEntity_aspect = 79, RuleEntity_class = 80, RuleEntity_class_entry = 81, 
    RuleEntity_class_entry_list = 82, RuleEntity_declaration = 83, RuleEntity_declarative_item = 84, 
    RuleEntity_declarative_part = 85, RuleEntity_designator = 86, RuleEntity_header = 87, 
    RuleEntity_name_list = 88, RuleEntity_specification = 89, RuleEntity_statement = 90, 
    RuleEntity_statement_part = 91, RuleEntity_tag = 92, RuleEnumeration_literal = 93, 
    RuleEnumeration_type_definition = 94, RuleExit_statement = 95, RuleExpression = 96, 
    RuleFactor = 97, RuleFile_declaration = 98, RuleFile_logical_name = 99, 
    RuleFile_open_information = 100, RuleFile_type_definition = 101, RuleFormal_parameter_list = 102, 
    RuleFormal_part = 103, RuleFree_quantity_declaration = 104, RuleGenerate_statement = 105, 
    RuleGeneration_scheme = 106, RuleGeneric_clause = 107, RuleGeneric_list = 108, 
    RuleGeneric_map_aspect = 109, RuleGroup_constituent = 110, RuleGroup_constituent_list = 111, 
    RuleGroup_declaration = 112, RuleGroup_template_declaration = 113, RuleGuarded_signal_specification = 114, 
    RuleIdentifier = 115, RuleIdentifier_list = 116, RuleIf_statement = 117, 
    RuleIndex_constraint = 118, RuleIndex_specification = 119, RuleIndex_subtype_definition = 120, 
    RuleInstantiated_unit = 121, RuleInstantiation_list = 122, RuleInterface_constant_declaration = 123, 
    RuleInterface_declaration = 124, RuleInterface_element = 125, RuleInterface_file_declaration = 126, 
    RuleInterface_signal_list = 127, RuleInterface_port_list = 128, RuleInterface_list = 129, 
    RuleInterface_quantity_declaration = 130, RuleInterface_port_declaration = 131, 
    RuleInterface_signal_declaration = 132, RuleInterface_terminal_declaration = 133, 
    RuleInterface_variable_declaration = 134, RuleIteration_scheme = 135, 
    RuleLabel_colon = 136, RuleLibrary_clause = 137, RuleLibrary_unit = 138, 
    RuleLiteral = 139, RuleLogical_name = 140, RuleLogical_name_list = 141, 
    RuleLogical_operator = 142, RuleLoop_statement = 143, RuleSignal_mode = 144, 
    RuleMultiplying_operator = 145, RuleName = 146, RuleName_part = 147, 
    RuleName_part_specificator = 148, RuleName_attribute_part = 149, RuleName_function_call_or_indexed_part = 150, 
    RuleName_slice_part = 151, RuleSelected_name = 152, RuleNature_declaration = 153, 
    RuleNature_definition = 154, RuleNature_element_declaration = 155, RuleNext_statement = 156, 
    RuleNumeric_literal = 157, RuleObject_declaration = 158, RuleOpts = 159, 
    RulePackage_body = 160, RulePackage_body_declarative_item = 161, RulePackage_body_declarative_part = 162, 
    RulePackage_declaration = 163, RulePackage_declarative_item = 164, RulePackage_declarative_part = 165, 
    RuleParameter_specification = 166, RulePhysical_literal = 167, RulePhysical_type_definition = 168, 
    RulePort_clause = 169, RulePort_list = 170, RulePort_map_aspect = 171, 
    RulePrimary = 172, RulePrimary_unit = 173, RuleProcedural_declarative_item = 174, 
    RuleProcedural_declarative_part = 175, RuleProcedural_statement_part = 176, 
    RuleProcedure_call = 177, RuleProcedure_call_statement = 178, RuleProcess_declarative_item = 179, 
    RuleProcess_declarative_part = 180, RuleProcess_statement = 181, RuleProcess_statement_part = 182, 
    RuleQualified_expression = 183, RuleQuantity_declaration = 184, RuleQuantity_list = 185, 
    RuleQuantity_specification = 186, RuleRange = 187, RuleExplicit_range = 188, 
    RuleRange_constraint = 189, RuleRecord_nature_definition = 190, RuleRecord_type_definition = 191, 
    RuleRelation = 192, RuleRelational_operator = 193, RuleReport_statement = 194, 
    RuleReturn_statement = 195, RuleScalar_nature_definition = 196, RuleScalar_type_definition = 197, 
    RuleSecondary_unit = 198, RuleSecondary_unit_declaration = 199, RuleSelected_signal_assignment = 200, 
    RuleSelected_waveforms = 201, RuleSensitivity_clause = 202, RuleSensitivity_list = 203, 
    RuleSequence_of_statements = 204, RuleSequential_statement = 205, RuleShift_expression = 206, 
    RuleShift_operator = 207, RuleSignal_assignment_statement = 208, RuleSignal_declaration = 209, 
    RuleSignal_kind = 210, RuleSignal_list = 211, RuleSignature = 212, RuleSimple_expression = 213, 
    RuleSimple_simultaneous_statement = 214, RuleSimultaneous_alternative = 215, 
    RuleSimultaneous_case_statement = 216, RuleSimultaneous_if_statement = 217, 
    RuleSimultaneous_procedural_statement = 218, RuleSimultaneous_statement = 219, 
    RuleSimultaneous_statement_part = 220, RuleSource_aspect = 221, RuleSource_quantity_declaration = 222, 
    RuleStep_limit_specification = 223, RuleSubnature_declaration = 224, 
    RuleSubnature_indication = 225, RuleSubprogram_body = 226, RuleSubprogram_declaration = 227, 
    RuleSubprogram_declarative_item = 228, RuleSubprogram_declarative_part = 229, 
    RuleSubprogram_kind = 230, RuleSubprogram_specification = 231, RuleProcedure_specification = 232, 
    RuleFunction_specification = 233, RuleSubprogram_statement_part = 234, 
    RuleSubtype_declaration = 235, RuleSubtype_indication = 236, RuleSuffix = 237, 
    RuleTarget = 238, RuleTerm = 239, RuleTerminal_aspect = 240, RuleTerminal_declaration = 241, 
    RuleThrough_aspect = 242, RuleTimeout_clause = 243, RuleTolerance_aspect = 244, 
    RuleType_declaration = 245, RuleType_definition = 246, RuleUnconstrained_array_definition = 247, 
    RuleUnconstrained_nature_definition = 248, RuleUse_clause = 249, RuleVariable_assignment_statement = 250, 
    RuleVariable_declaration = 251, RuleWait_statement = 252, RuleWaveform = 253, 
    RuleWaveform_element = 254
  };

  vhdlParser(TokenStream *input);
  ~vhdlParser();

  virtual std::string getGrammarFileName() const override;
  virtual const atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual dfa::Vocabulary& getVocabulary() const override;


  class Abstract_literalContext;
  class Access_type_definitionContext;
  class Across_aspectContext;
  class Actual_designatorContext;
  class Actual_parameter_partContext;
  class Actual_partContext;
  class Adding_operatorContext;
  class AggregateContext;
  class Alias_declarationContext;
  class Alias_designatorContext;
  class Alias_indicationContext;
  class AllocatorContext;
  class Architecture_bodyContext;
  class Architecture_declarative_partContext;
  class Architecture_statementContext;
  class Architecture_statement_partContext;
  class Array_nature_definitionContext;
  class Array_type_definitionContext;
  class AssertionContext;
  class Assertion_statementContext;
  class Association_elementContext;
  class Association_listContext;
  class Attribute_declarationContext;
  class Attribute_designatorContext;
  class Attribute_specificationContext;
  class Base_unit_declarationContext;
  class Binding_indicationContext;
  class Block_configurationContext;
  class Block_declarative_itemContext;
  class Block_declarative_partContext;
  class Block_headerContext;
  class Block_specificationContext;
  class Block_statementContext;
  class Block_statement_partContext;
  class Branch_quantity_declarationContext;
  class Break_elementContext;
  class Break_listContext;
  class Break_selector_clauseContext;
  class Break_statementContext;
  class Case_statementContext;
  class Case_statement_alternativeContext;
  class ChoiceContext;
  class ChoicesContext;
  class Component_configurationContext;
  class Component_declarationContext;
  class Component_instantiation_statementContext;
  class Component_specificationContext;
  class Composite_nature_definitionContext;
  class Composite_type_definitionContext;
  class Concurrent_assertion_statementContext;
  class Concurrent_break_statementContext;
  class Concurrent_procedure_call_statementContext;
  class Concurrent_signal_assignment_statementContext;
  class ConditionContext;
  class Condition_clauseContext;
  class Conditional_signal_assignmentContext;
  class Conditional_waveformsContext;
  class Configuration_declarationContext;
  class Configuration_declarative_itemContext;
  class Configuration_declarative_partContext;
  class Configuration_itemContext;
  class Configuration_specificationContext;
  class Constant_declarationContext;
  class Constrained_array_definitionContext;
  class Constrained_nature_definitionContext;
  class ConstraintContext;
  class Context_clauseContext;
  class Context_itemContext;
  class Delay_mechanismContext;
  class Design_fileContext;
  class Design_unitContext;
  class DesignatorContext;
  class DirectionContext;
  class Disconnection_specificationContext;
  class Discrete_rangeContext;
  class Element_associationContext;
  class Element_declarationContext;
  class Element_subnature_definitionContext;
  class Element_subtype_definitionContext;
  class Entity_aspectContext;
  class Entity_classContext;
  class Entity_class_entryContext;
  class Entity_class_entry_listContext;
  class Entity_declarationContext;
  class Entity_declarative_itemContext;
  class Entity_declarative_partContext;
  class Entity_designatorContext;
  class Entity_headerContext;
  class Entity_name_listContext;
  class Entity_specificationContext;
  class Entity_statementContext;
  class Entity_statement_partContext;
  class Entity_tagContext;
  class Enumeration_literalContext;
  class Enumeration_type_definitionContext;
  class Exit_statementContext;
  class ExpressionContext;
  class FactorContext;
  class File_declarationContext;
  class File_logical_nameContext;
  class File_open_informationContext;
  class File_type_definitionContext;
  class Formal_parameter_listContext;
  class Formal_partContext;
  class Free_quantity_declarationContext;
  class Generate_statementContext;
  class Generation_schemeContext;
  class Generic_clauseContext;
  class Generic_listContext;
  class Generic_map_aspectContext;
  class Group_constituentContext;
  class Group_constituent_listContext;
  class Group_declarationContext;
  class Group_template_declarationContext;
  class Guarded_signal_specificationContext;
  class IdentifierContext;
  class Identifier_listContext;
  class If_statementContext;
  class Index_constraintContext;
  class Index_specificationContext;
  class Index_subtype_definitionContext;
  class Instantiated_unitContext;
  class Instantiation_listContext;
  class Interface_constant_declarationContext;
  class Interface_declarationContext;
  class Interface_elementContext;
  class Interface_file_declarationContext;
  class Interface_signal_listContext;
  class Interface_port_listContext;
  class Interface_listContext;
  class Interface_quantity_declarationContext;
  class Interface_port_declarationContext;
  class Interface_signal_declarationContext;
  class Interface_terminal_declarationContext;
  class Interface_variable_declarationContext;
  class Iteration_schemeContext;
  class Label_colonContext;
  class Library_clauseContext;
  class Library_unitContext;
  class LiteralContext;
  class Logical_nameContext;
  class Logical_name_listContext;
  class Logical_operatorContext;
  class Loop_statementContext;
  class Signal_modeContext;
  class Multiplying_operatorContext;
  class NameContext;
  class Name_partContext;
  class Name_part_specificatorContext;
  class Name_attribute_partContext;
  class Name_function_call_or_indexed_partContext;
  class Name_slice_partContext;
  class Selected_nameContext;
  class Nature_declarationContext;
  class Nature_definitionContext;
  class Nature_element_declarationContext;
  class Next_statementContext;
  class Numeric_literalContext;
  class Object_declarationContext;
  class OptsContext;
  class Package_bodyContext;
  class Package_body_declarative_itemContext;
  class Package_body_declarative_partContext;
  class Package_declarationContext;
  class Package_declarative_itemContext;
  class Package_declarative_partContext;
  class Parameter_specificationContext;
  class Physical_literalContext;
  class Physical_type_definitionContext;
  class Port_clauseContext;
  class Port_listContext;
  class Port_map_aspectContext;
  class PrimaryContext;
  class Primary_unitContext;
  class Procedural_declarative_itemContext;
  class Procedural_declarative_partContext;
  class Procedural_statement_partContext;
  class Procedure_callContext;
  class Procedure_call_statementContext;
  class Process_declarative_itemContext;
  class Process_declarative_partContext;
  class Process_statementContext;
  class Process_statement_partContext;
  class Qualified_expressionContext;
  class Quantity_declarationContext;
  class Quantity_listContext;
  class Quantity_specificationContext;
  class RangeContext;
  class Explicit_rangeContext;
  class Range_constraintContext;
  class Record_nature_definitionContext;
  class Record_type_definitionContext;
  class RelationContext;
  class Relational_operatorContext;
  class Report_statementContext;
  class Return_statementContext;
  class Scalar_nature_definitionContext;
  class Scalar_type_definitionContext;
  class Secondary_unitContext;
  class Secondary_unit_declarationContext;
  class Selected_signal_assignmentContext;
  class Selected_waveformsContext;
  class Sensitivity_clauseContext;
  class Sensitivity_listContext;
  class Sequence_of_statementsContext;
  class Sequential_statementContext;
  class Shift_expressionContext;
  class Shift_operatorContext;
  class Signal_assignment_statementContext;
  class Signal_declarationContext;
  class Signal_kindContext;
  class Signal_listContext;
  class SignatureContext;
  class Simple_expressionContext;
  class Simple_simultaneous_statementContext;
  class Simultaneous_alternativeContext;
  class Simultaneous_case_statementContext;
  class Simultaneous_if_statementContext;
  class Simultaneous_procedural_statementContext;
  class Simultaneous_statementContext;
  class Simultaneous_statement_partContext;
  class Source_aspectContext;
  class Source_quantity_declarationContext;
  class Step_limit_specificationContext;
  class Subnature_declarationContext;
  class Subnature_indicationContext;
  class Subprogram_bodyContext;
  class Subprogram_declarationContext;
  class Subprogram_declarative_itemContext;
  class Subprogram_declarative_partContext;
  class Subprogram_kindContext;
  class Subprogram_specificationContext;
  class Procedure_specificationContext;
  class Function_specificationContext;
  class Subprogram_statement_partContext;
  class Subtype_declarationContext;
  class Subtype_indicationContext;
  class SuffixContext;
  class TargetContext;
  class TermContext;
  class Terminal_aspectContext;
  class Terminal_declarationContext;
  class Through_aspectContext;
  class Timeout_clauseContext;
  class Tolerance_aspectContext;
  class Type_declarationContext;
  class Type_definitionContext;
  class Unconstrained_array_definitionContext;
  class Unconstrained_nature_definitionContext;
  class Use_clauseContext;
  class Variable_assignment_statementContext;
  class Variable_declarationContext;
  class Wait_statementContext;
  class WaveformContext;
  class Waveform_elementContext; 

  class Abstract_literalContext : public ParserRuleContext {
  public:
    Abstract_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> INTEGER();
    Ref<tree::TerminalNode> REAL_LITERAL();
    Ref<tree::TerminalNode> BASE_LITERAL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAbstract_literal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Abstract_literalContext> abstract_literal();

  class Access_type_definitionContext : public ParserRuleContext {
  public:
    Access_type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ACCESS();
    Ref<Subtype_indicationContext> subtype_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAccess_type_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Access_type_definitionContext> access_type_definition();

  class Across_aspectContext : public ParserRuleContext {
  public:
    Across_aspectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> ACROSS();
    Ref<Tolerance_aspectContext> tolerance_aspect();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAcross_aspect(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Across_aspectContext> across_aspect();

  class Actual_designatorContext : public ParserRuleContext {
  public:
    Actual_designatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> OPEN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitActual_designator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Actual_designatorContext> actual_designator();

  class Actual_parameter_partContext : public ParserRuleContext {
  public:
    Actual_parameter_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Association_listContext> association_list();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitActual_parameter_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Actual_parameter_partContext> actual_parameter_part();

  class Actual_partContext : public ParserRuleContext {
  public:
    Actual_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NameContext> name();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Actual_designatorContext> actual_designator();
    Ref<tree::TerminalNode> RPAREN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitActual_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Actual_partContext> actual_part();

  class Adding_operatorContext : public ParserRuleContext {
  public:
    Adding_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> PLUS();
    Ref<tree::TerminalNode> MINUS();
    Ref<tree::TerminalNode> AMPERSAND();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAdding_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Adding_operatorContext> adding_operator();

  class AggregateContext : public ParserRuleContext {
  public:
    AggregateContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> LPAREN();
    std::vector<Ref<Element_associationContext>> element_association();
    Ref<Element_associationContext> element_association(int i);
    Ref<tree::TerminalNode> RPAREN();
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAggregate(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<AggregateContext> aggregate();

  class Alias_declarationContext : public ParserRuleContext {
  public:
    Alias_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ALIAS();
    Ref<Alias_designatorContext> alias_designator();
    Ref<tree::TerminalNode> IS();
    Ref<NameContext> name();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> COLON();
    Ref<Alias_indicationContext> alias_indication();
    Ref<SignatureContext> signature();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAlias_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Alias_declarationContext> alias_declaration();

  class Alias_designatorContext : public ParserRuleContext {
  public:
    Alias_designatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> CHARACTER_LITERAL();
    Ref<tree::TerminalNode> STRING_LITERAL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAlias_designator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Alias_designatorContext> alias_designator();

  class Alias_indicationContext : public ParserRuleContext {
  public:
    Alias_indicationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subnature_indicationContext> subnature_indication();
    Ref<Subtype_indicationContext> subtype_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAlias_indication(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Alias_indicationContext> alias_indication();

  class AllocatorContext : public ParserRuleContext {
  public:
    AllocatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> NEW();
    Ref<Qualified_expressionContext> qualified_expression();
    Ref<Subtype_indicationContext> subtype_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAllocator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<AllocatorContext> allocator();

  class Architecture_bodyContext : public ParserRuleContext {
  public:
    Architecture_bodyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> ARCHITECTURE();
    Ref<tree::TerminalNode> ARCHITECTURE(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    Ref<tree::TerminalNode> OF();
    Ref<tree::TerminalNode> IS();
    Ref<Architecture_declarative_partContext> architecture_declarative_part();
    Ref<tree::TerminalNode> BEGIN();
    Ref<Architecture_statement_partContext> architecture_statement_part();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitArchitecture_body(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Architecture_bodyContext> architecture_body();

  class Architecture_declarative_partContext : public ParserRuleContext {
  public:
    Architecture_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Block_declarative_itemContext>> block_declarative_item();
    Ref<Block_declarative_itemContext> block_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitArchitecture_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Architecture_declarative_partContext> architecture_declarative_part();

  class Architecture_statementContext : public ParserRuleContext {
  public:
    Architecture_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_statementContext> block_statement();
    Ref<Process_statementContext> process_statement();
    Ref<Concurrent_procedure_call_statementContext> concurrent_procedure_call_statement();
    Ref<Label_colonContext> label_colon();
    Ref<Concurrent_assertion_statementContext> concurrent_assertion_statement();
    Ref<Concurrent_signal_assignment_statementContext> concurrent_signal_assignment_statement();
    Ref<tree::TerminalNode> POSTPONED();
    Ref<Component_instantiation_statementContext> component_instantiation_statement();
    Ref<Generate_statementContext> generate_statement();
    Ref<Concurrent_break_statementContext> concurrent_break_statement();
    Ref<Simultaneous_statementContext> simultaneous_statement();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitArchitecture_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Architecture_statementContext> architecture_statement();

  class Architecture_statement_partContext : public ParserRuleContext {
  public:
    Architecture_statement_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Architecture_statementContext>> architecture_statement();
    Ref<Architecture_statementContext> architecture_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitArchitecture_statement_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Architecture_statement_partContext> architecture_statement_part();

  class Array_nature_definitionContext : public ParserRuleContext {
  public:
    Array_nature_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Unconstrained_nature_definitionContext> unconstrained_nature_definition();
    Ref<Constrained_nature_definitionContext> constrained_nature_definition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitArray_nature_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Array_nature_definitionContext> array_nature_definition();

  class Array_type_definitionContext : public ParserRuleContext {
  public:
    Array_type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Unconstrained_array_definitionContext> unconstrained_array_definition();
    Ref<Constrained_array_definitionContext> constrained_array_definition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitArray_type_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Array_type_definitionContext> array_type_definition();

  class AssertionContext : public ParserRuleContext {
  public:
    AssertionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ASSERT();
    Ref<ConditionContext> condition();
    Ref<tree::TerminalNode> REPORT();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<tree::TerminalNode> SEVERITY();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAssertion(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<AssertionContext> assertion();

  class Assertion_statementContext : public ParserRuleContext {
  public:
    Assertion_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<AssertionContext> assertion();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAssertion_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Assertion_statementContext> assertion_statement();

  class Association_elementContext : public ParserRuleContext {
  public:
    Association_elementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Actual_partContext> actual_part();
    Ref<Formal_partContext> formal_part();
    Ref<tree::TerminalNode> ARROW();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAssociation_element(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Association_elementContext> association_element();

  class Association_listContext : public ParserRuleContext {
  public:
    Association_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Association_elementContext>> association_element();
    Ref<Association_elementContext> association_element(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAssociation_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Association_listContext> association_list();

  class Attribute_declarationContext : public ParserRuleContext {
  public:
    Attribute_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ATTRIBUTE();
    Ref<Label_colonContext> label_colon();
    Ref<NameContext> name();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAttribute_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Attribute_declarationContext> attribute_declaration();

  class Attribute_designatorContext : public ParserRuleContext {
  public:
    Attribute_designatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> RANGE();
    Ref<tree::TerminalNode> REVERSE_RANGE();
    Ref<tree::TerminalNode> ACROSS();
    Ref<tree::TerminalNode> THROUGH();
    Ref<tree::TerminalNode> REFERENCE();
    Ref<tree::TerminalNode> TOLERANCE();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAttribute_designator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Attribute_designatorContext> attribute_designator();

  class Attribute_specificationContext : public ParserRuleContext {
  public:
    Attribute_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ATTRIBUTE();
    Ref<Attribute_designatorContext> attribute_designator();
    Ref<tree::TerminalNode> OF();
    Ref<Entity_specificationContext> entity_specification();
    Ref<tree::TerminalNode> IS();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitAttribute_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Attribute_specificationContext> attribute_specification();

  class Base_unit_declarationContext : public ParserRuleContext {
  public:
    Base_unit_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBase_unit_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Base_unit_declarationContext> base_unit_declaration();

  class Binding_indicationContext : public ParserRuleContext {
  public:
    Binding_indicationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> USE();
    Ref<Entity_aspectContext> entity_aspect();
    Ref<Generic_map_aspectContext> generic_map_aspect();
    Ref<Port_map_aspectContext> port_map_aspect();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBinding_indication(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Binding_indicationContext> binding_indication();

  class Block_configurationContext : public ParserRuleContext {
  public:
    Block_configurationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> FOR();
    Ref<tree::TerminalNode> FOR(int i);
    Ref<Block_specificationContext> block_specification();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    std::vector<Ref<Use_clauseContext>> use_clause();
    Ref<Use_clauseContext> use_clause(int i);
    std::vector<Ref<Configuration_itemContext>> configuration_item();
    Ref<Configuration_itemContext> configuration_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBlock_configuration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_configurationContext> block_configuration();

  class Block_declarative_itemContext : public ParserRuleContext {
  public:
    Block_declarative_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_declarationContext> subprogram_declaration();
    Ref<Subprogram_bodyContext> subprogram_body();
    Ref<Type_declarationContext> type_declaration();
    Ref<Subtype_declarationContext> subtype_declaration();
    Ref<Constant_declarationContext> constant_declaration();
    Ref<Signal_declarationContext> signal_declaration();
    Ref<Variable_declarationContext> variable_declaration();
    Ref<File_declarationContext> file_declaration();
    Ref<Alias_declarationContext> alias_declaration();
    Ref<Component_declarationContext> component_declaration();
    Ref<Attribute_declarationContext> attribute_declaration();
    Ref<Attribute_specificationContext> attribute_specification();
    Ref<Configuration_specificationContext> configuration_specification();
    Ref<Disconnection_specificationContext> disconnection_specification();
    Ref<Step_limit_specificationContext> step_limit_specification();
    Ref<Use_clauseContext> use_clause();
    Ref<Group_template_declarationContext> group_template_declaration();
    Ref<Group_declarationContext> group_declaration();
    Ref<Nature_declarationContext> nature_declaration();
    Ref<Subnature_declarationContext> subnature_declaration();
    Ref<Quantity_declarationContext> quantity_declaration();
    Ref<Terminal_declarationContext> terminal_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBlock_declarative_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_declarative_itemContext> block_declarative_item();

  class Block_declarative_partContext : public ParserRuleContext {
  public:
    Block_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Block_declarative_itemContext>> block_declarative_item();
    Ref<Block_declarative_itemContext> block_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBlock_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_declarative_partContext> block_declarative_part();

  class Block_headerContext : public ParserRuleContext {
  public:
    Block_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Generic_clauseContext> generic_clause();
    Ref<Port_clauseContext> port_clause();
    Ref<Generic_map_aspectContext> generic_map_aspect();
    std::vector<Ref<tree::TerminalNode>> SEMI();
    Ref<tree::TerminalNode> SEMI(int i);
    Ref<Port_map_aspectContext> port_map_aspect();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBlock_header(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_headerContext> block_header();

  class Block_specificationContext : public ParserRuleContext {
  public:
    Block_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Index_specificationContext> index_specification();
    Ref<tree::TerminalNode> RPAREN();
    Ref<NameContext> name();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBlock_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_specificationContext> block_specification();

  class Block_statementContext : public ParserRuleContext {
  public:
    Block_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Label_colonContext> label_colon();
    std::vector<Ref<tree::TerminalNode>> BLOCK();
    Ref<tree::TerminalNode> BLOCK(int i);
    Ref<Block_headerContext> block_header();
    Ref<Block_declarative_partContext> block_declarative_part();
    Ref<tree::TerminalNode> BEGIN();
    Ref<Block_statement_partContext> block_statement_part();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> LPAREN();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> IS();
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBlock_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_statementContext> block_statement();

  class Block_statement_partContext : public ParserRuleContext {
  public:
    Block_statement_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Architecture_statementContext>> architecture_statement();
    Ref<Architecture_statementContext> architecture_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBlock_statement_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Block_statement_partContext> block_statement_part();

  class Branch_quantity_declarationContext : public ParserRuleContext {
  public:
    Branch_quantity_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> QUANTITY();
    Ref<Terminal_aspectContext> terminal_aspect();
    Ref<tree::TerminalNode> SEMI();
    Ref<Across_aspectContext> across_aspect();
    Ref<Through_aspectContext> through_aspect();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBranch_quantity_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Branch_quantity_declarationContext> branch_quantity_declaration();

  class Break_elementContext : public ParserRuleContext {
  public:
    Break_elementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NameContext> name();
    Ref<tree::TerminalNode> ARROW();
    Ref<ExpressionContext> expression();
    Ref<Break_selector_clauseContext> break_selector_clause();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBreak_element(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Break_elementContext> break_element();

  class Break_listContext : public ParserRuleContext {
  public:
    Break_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Break_elementContext>> break_element();
    Ref<Break_elementContext> break_element(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBreak_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Break_listContext> break_list();

  class Break_selector_clauseContext : public ParserRuleContext {
  public:
    Break_selector_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> FOR();
    Ref<NameContext> name();
    Ref<tree::TerminalNode> USE();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBreak_selector_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Break_selector_clauseContext> break_selector_clause();

  class Break_statementContext : public ParserRuleContext {
  public:
    Break_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> BREAK();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<Break_listContext> break_list();
    Ref<tree::TerminalNode> WHEN();
    Ref<ConditionContext> condition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitBreak_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Break_statementContext> break_statement();

  class Case_statementContext : public ParserRuleContext {
  public:
    Case_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> CASE();
    Ref<tree::TerminalNode> CASE(int i);
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> IS();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    std::vector<Ref<Case_statement_alternativeContext>> case_statement_alternative();
    Ref<Case_statement_alternativeContext> case_statement_alternative(int i);
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitCase_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Case_statementContext> case_statement();

  class Case_statement_alternativeContext : public ParserRuleContext {
  public:
    Case_statement_alternativeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> WHEN();
    Ref<ChoicesContext> choices();
    Ref<tree::TerminalNode> ARROW();
    Ref<Sequence_of_statementsContext> sequence_of_statements();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitCase_statement_alternative(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Case_statement_alternativeContext> case_statement_alternative();

  class ChoiceContext : public ParserRuleContext {
  public:
    ChoiceContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<Discrete_rangeContext> discrete_range();
    Ref<Simple_expressionContext> simple_expression();
    Ref<tree::TerminalNode> OTHERS();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitChoice(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<ChoiceContext> choice();

  class ChoicesContext : public ParserRuleContext {
  public:
    ChoicesContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ChoiceContext>> choice();
    Ref<ChoiceContext> choice(int i);
    std::vector<Ref<tree::TerminalNode>> BAR();
    Ref<tree::TerminalNode> BAR(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitChoices(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<ChoicesContext> choices();

  class Component_configurationContext : public ParserRuleContext {
  public:
    Component_configurationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> FOR();
    Ref<tree::TerminalNode> FOR(int i);
    Ref<Component_specificationContext> component_specification();
    Ref<tree::TerminalNode> END();
    std::vector<Ref<tree::TerminalNode>> SEMI();
    Ref<tree::TerminalNode> SEMI(int i);
    Ref<Binding_indicationContext> binding_indication();
    Ref<Block_configurationContext> block_configuration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitComponent_configuration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Component_configurationContext> component_configuration();

  class Component_declarationContext : public ParserRuleContext {
  public:
    Component_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> COMPONENT();
    Ref<tree::TerminalNode> COMPONENT(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> IS();
    Ref<Generic_clauseContext> generic_clause();
    Ref<Port_clauseContext> port_clause();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitComponent_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Component_declarationContext> component_declaration();

  class Component_instantiation_statementContext : public ParserRuleContext {
  public:
    Component_instantiation_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Label_colonContext> label_colon();
    Ref<Instantiated_unitContext> instantiated_unit();
    Ref<tree::TerminalNode> SEMI();
    Ref<Generic_map_aspectContext> generic_map_aspect();
    Ref<Port_map_aspectContext> port_map_aspect();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitComponent_instantiation_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Component_instantiation_statementContext> component_instantiation_statement();

  class Component_specificationContext : public ParserRuleContext {
  public:
    Component_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Instantiation_listContext> instantiation_list();
    Ref<tree::TerminalNode> COLON();
    Ref<NameContext> name();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitComponent_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Component_specificationContext> component_specification();

  class Composite_nature_definitionContext : public ParserRuleContext {
  public:
    Composite_nature_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Array_nature_definitionContext> array_nature_definition();
    Ref<Record_nature_definitionContext> record_nature_definition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitComposite_nature_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Composite_nature_definitionContext> composite_nature_definition();

  class Composite_type_definitionContext : public ParserRuleContext {
  public:
    Composite_type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Array_type_definitionContext> array_type_definition();
    Ref<Record_type_definitionContext> record_type_definition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitComposite_type_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Composite_type_definitionContext> composite_type_definition();

  class Concurrent_assertion_statementContext : public ParserRuleContext {
  public:
    Concurrent_assertion_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<AssertionContext> assertion();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<tree::TerminalNode> POSTPONED();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConcurrent_assertion_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Concurrent_assertion_statementContext> concurrent_assertion_statement();

  class Concurrent_break_statementContext : public ParserRuleContext {
  public:
    Concurrent_break_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> BREAK();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<Break_listContext> break_list();
    Ref<Sensitivity_clauseContext> sensitivity_clause();
    Ref<tree::TerminalNode> WHEN();
    Ref<ConditionContext> condition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConcurrent_break_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Concurrent_break_statementContext> concurrent_break_statement();

  class Concurrent_procedure_call_statementContext : public ParserRuleContext {
  public:
    Concurrent_procedure_call_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Procedure_callContext> procedure_call();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<tree::TerminalNode> POSTPONED();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConcurrent_procedure_call_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Concurrent_procedure_call_statementContext> concurrent_procedure_call_statement();

  class Concurrent_signal_assignment_statementContext : public ParserRuleContext {
  public:
    Concurrent_signal_assignment_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Conditional_signal_assignmentContext> conditional_signal_assignment();
    Ref<Selected_signal_assignmentContext> selected_signal_assignment();
    Ref<Label_colonContext> label_colon();
    Ref<tree::TerminalNode> POSTPONED();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConcurrent_signal_assignment_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Concurrent_signal_assignment_statementContext> concurrent_signal_assignment_statement();

  class ConditionContext : public ParserRuleContext {
  public:
    ConditionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitCondition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<ConditionContext> condition();

  class Condition_clauseContext : public ParserRuleContext {
  public:
    Condition_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> UNTIL();
    Ref<ConditionContext> condition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitCondition_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Condition_clauseContext> condition_clause();

  class Conditional_signal_assignmentContext : public ParserRuleContext {
  public:
    Conditional_signal_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<TargetContext> target();
    Ref<tree::TerminalNode> LE();
    Ref<OptsContext> opts();
    Ref<Conditional_waveformsContext> conditional_waveforms();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConditional_signal_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Conditional_signal_assignmentContext> conditional_signal_assignment();

  class Conditional_waveformsContext : public ParserRuleContext {
  public:
    Conditional_waveformsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<WaveformContext> waveform();
    Ref<tree::TerminalNode> WHEN();
    Ref<ConditionContext> condition();
    Ref<tree::TerminalNode> ELSE();
    Ref<Conditional_waveformsContext> conditional_waveforms();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConditional_waveforms(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Conditional_waveformsContext> conditional_waveforms();

  class Configuration_declarationContext : public ParserRuleContext {
  public:
    Configuration_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> CONFIGURATION();
    Ref<tree::TerminalNode> CONFIGURATION(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    Ref<tree::TerminalNode> OF();
    Ref<NameContext> name();
    Ref<tree::TerminalNode> IS();
    Ref<Configuration_declarative_partContext> configuration_declarative_part();
    Ref<Block_configurationContext> block_configuration();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConfiguration_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Configuration_declarationContext> configuration_declaration();

  class Configuration_declarative_itemContext : public ParserRuleContext {
  public:
    Configuration_declarative_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Use_clauseContext> use_clause();
    Ref<Attribute_specificationContext> attribute_specification();
    Ref<Group_declarationContext> group_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConfiguration_declarative_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Configuration_declarative_itemContext> configuration_declarative_item();

  class Configuration_declarative_partContext : public ParserRuleContext {
  public:
    Configuration_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Configuration_declarative_itemContext>> configuration_declarative_item();
    Ref<Configuration_declarative_itemContext> configuration_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConfiguration_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Configuration_declarative_partContext> configuration_declarative_part();

  class Configuration_itemContext : public ParserRuleContext {
  public:
    Configuration_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Block_configurationContext> block_configuration();
    Ref<Component_configurationContext> component_configuration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConfiguration_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Configuration_itemContext> configuration_item();

  class Configuration_specificationContext : public ParserRuleContext {
  public:
    Configuration_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> FOR();
    Ref<Component_specificationContext> component_specification();
    Ref<Binding_indicationContext> binding_indication();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConfiguration_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Configuration_specificationContext> configuration_specification();

  class Constant_declarationContext : public ParserRuleContext {
  public:
    Constant_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> CONSTANT();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConstant_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constant_declarationContext> constant_declaration();

  class Constrained_array_definitionContext : public ParserRuleContext {
  public:
    Constrained_array_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ARRAY();
    Ref<Index_constraintContext> index_constraint();
    Ref<tree::TerminalNode> OF();
    Ref<Subtype_indicationContext> subtype_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConstrained_array_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constrained_array_definitionContext> constrained_array_definition();

  class Constrained_nature_definitionContext : public ParserRuleContext {
  public:
    Constrained_nature_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ARRAY();
    Ref<Index_constraintContext> index_constraint();
    Ref<tree::TerminalNode> OF();
    Ref<Subnature_indicationContext> subnature_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConstrained_nature_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Constrained_nature_definitionContext> constrained_nature_definition();

  class ConstraintContext : public ParserRuleContext {
  public:
    ConstraintContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Range_constraintContext> range_constraint();
    Ref<Index_constraintContext> index_constraint();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitConstraint(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<ConstraintContext> constraint();

  class Context_clauseContext : public ParserRuleContext {
  public:
    Context_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Context_itemContext>> context_item();
    Ref<Context_itemContext> context_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitContext_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Context_clauseContext> context_clause();

  class Context_itemContext : public ParserRuleContext {
  public:
    Context_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Library_clauseContext> library_clause();
    Ref<Use_clauseContext> use_clause();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitContext_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Context_itemContext> context_item();

  class Delay_mechanismContext : public ParserRuleContext {
  public:
    Delay_mechanismContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> TRANSPORT();
    Ref<tree::TerminalNode> INERTIAL();
    Ref<tree::TerminalNode> REJECT();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitDelay_mechanism(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Delay_mechanismContext> delay_mechanism();

  class Design_fileContext : public ParserRuleContext {
  public:
    Design_fileContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> EOF();
    std::vector<Ref<Design_unitContext>> design_unit();
    Ref<Design_unitContext> design_unit(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitDesign_file(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Design_fileContext> design_file();

  class Design_unitContext : public ParserRuleContext {
  public:
    Design_unitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Context_clauseContext> context_clause();
    Ref<Library_unitContext> library_unit();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitDesign_unit(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Design_unitContext> design_unit();

  class DesignatorContext : public ParserRuleContext {
  public:
    DesignatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> STRING_LITERAL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitDesignator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<DesignatorContext> designator();

  class DirectionContext : public ParserRuleContext {
  public:
    DirectionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> TO();
    Ref<tree::TerminalNode> DOWNTO();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitDirection(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<DirectionContext> direction();

  class Disconnection_specificationContext : public ParserRuleContext {
  public:
    Disconnection_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> DISCONNECT();
    Ref<Guarded_signal_specificationContext> guarded_signal_specification();
    Ref<tree::TerminalNode> AFTER();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitDisconnection_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Disconnection_specificationContext> disconnection_specification();

  class Discrete_rangeContext : public ParserRuleContext {
  public:
    Discrete_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<RangeContext> range();
    Ref<Subtype_indicationContext> subtype_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitDiscrete_range(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Discrete_rangeContext> discrete_range();

  class Element_associationContext : public ParserRuleContext {
  public:
    Element_associationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();
    Ref<ChoicesContext> choices();
    Ref<tree::TerminalNode> ARROW();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitElement_association(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Element_associationContext> element_association();

  class Element_declarationContext : public ParserRuleContext {
  public:
    Element_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Element_subtype_definitionContext> element_subtype_definition();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitElement_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Element_declarationContext> element_declaration();

  class Element_subnature_definitionContext : public ParserRuleContext {
  public:
    Element_subnature_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subnature_indicationContext> subnature_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitElement_subnature_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Element_subnature_definitionContext> element_subnature_definition();

  class Element_subtype_definitionContext : public ParserRuleContext {
  public:
    Element_subtype_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subtype_indicationContext> subtype_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitElement_subtype_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Element_subtype_definitionContext> element_subtype_definition();

  class Entity_aspectContext : public ParserRuleContext {
  public:
    Entity_aspectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ENTITY();
    Ref<NameContext> name();
    Ref<tree::TerminalNode> LPAREN();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> CONFIGURATION();
    Ref<tree::TerminalNode> OPEN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_aspect(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_aspectContext> entity_aspect();

  class Entity_classContext : public ParserRuleContext {
  public:
    Entity_classContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ENTITY();
    Ref<tree::TerminalNode> ARCHITECTURE();
    Ref<tree::TerminalNode> CONFIGURATION();
    Ref<tree::TerminalNode> PROCEDURE();
    Ref<tree::TerminalNode> FUNCTION();
    Ref<tree::TerminalNode> PACKAGE();
    Ref<tree::TerminalNode> TYPE();
    Ref<tree::TerminalNode> SUBTYPE();
    Ref<tree::TerminalNode> CONSTANT();
    Ref<tree::TerminalNode> SIGNAL();
    Ref<tree::TerminalNode> VARIABLE();
    Ref<tree::TerminalNode> COMPONENT();
    Ref<tree::TerminalNode> LABEL();
    Ref<tree::TerminalNode> LITERAL();
    Ref<tree::TerminalNode> UNITS();
    Ref<tree::TerminalNode> GROUP();
    Ref<tree::TerminalNode> FILE();
    Ref<tree::TerminalNode> NATURE();
    Ref<tree::TerminalNode> SUBNATURE();
    Ref<tree::TerminalNode> QUANTITY();
    Ref<tree::TerminalNode> TERMINAL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_class(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_classContext> entity_class();

  class Entity_class_entryContext : public ParserRuleContext {
  public:
    Entity_class_entryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Entity_classContext> entity_class();
    Ref<tree::TerminalNode> BOX();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_class_entry(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_class_entryContext> entity_class_entry();

  class Entity_class_entry_listContext : public ParserRuleContext {
  public:
    Entity_class_entry_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Entity_class_entryContext>> entity_class_entry();
    Ref<Entity_class_entryContext> entity_class_entry(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_class_entry_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_class_entry_listContext> entity_class_entry_list();

  class Entity_declarationContext : public ParserRuleContext {
  public:
    Entity_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> ENTITY();
    Ref<tree::TerminalNode> ENTITY(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    Ref<tree::TerminalNode> IS();
    Ref<Entity_headerContext> entity_header();
    Ref<Entity_declarative_partContext> entity_declarative_part();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> BEGIN();
    Ref<Entity_statement_partContext> entity_statement_part();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_declarationContext> entity_declaration();

  class Entity_declarative_itemContext : public ParserRuleContext {
  public:
    Entity_declarative_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_declarationContext> subprogram_declaration();
    Ref<Subprogram_bodyContext> subprogram_body();
    Ref<Type_declarationContext> type_declaration();
    Ref<Subtype_declarationContext> subtype_declaration();
    Ref<Constant_declarationContext> constant_declaration();
    Ref<Signal_declarationContext> signal_declaration();
    Ref<Variable_declarationContext> variable_declaration();
    Ref<File_declarationContext> file_declaration();
    Ref<Alias_declarationContext> alias_declaration();
    Ref<Attribute_declarationContext> attribute_declaration();
    Ref<Attribute_specificationContext> attribute_specification();
    Ref<Disconnection_specificationContext> disconnection_specification();
    Ref<Step_limit_specificationContext> step_limit_specification();
    Ref<Use_clauseContext> use_clause();
    Ref<Group_template_declarationContext> group_template_declaration();
    Ref<Group_declarationContext> group_declaration();
    Ref<Nature_declarationContext> nature_declaration();
    Ref<Subnature_declarationContext> subnature_declaration();
    Ref<Quantity_declarationContext> quantity_declaration();
    Ref<Terminal_declarationContext> terminal_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_declarative_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_declarative_itemContext> entity_declarative_item();

  class Entity_declarative_partContext : public ParserRuleContext {
  public:
    Entity_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Entity_declarative_itemContext>> entity_declarative_item();
    Ref<Entity_declarative_itemContext> entity_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_declarative_partContext> entity_declarative_part();

  class Entity_designatorContext : public ParserRuleContext {
  public:
    Entity_designatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Entity_tagContext> entity_tag();
    Ref<SignatureContext> signature();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_designator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_designatorContext> entity_designator();

  class Entity_headerContext : public ParserRuleContext {
  public:
    Entity_headerContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Generic_clauseContext> generic_clause();
    Ref<Port_clauseContext> port_clause();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_header(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_headerContext> entity_header();

  class Entity_name_listContext : public ParserRuleContext {
  public:
    Entity_name_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Entity_designatorContext>> entity_designator();
    Ref<Entity_designatorContext> entity_designator(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);
    Ref<tree::TerminalNode> OTHERS();
    Ref<tree::TerminalNode> ALL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_name_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_name_listContext> entity_name_list();

  class Entity_specificationContext : public ParserRuleContext {
  public:
    Entity_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Entity_name_listContext> entity_name_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Entity_classContext> entity_class();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_specificationContext> entity_specification();

  class Entity_statementContext : public ParserRuleContext {
  public:
    Entity_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Concurrent_assertion_statementContext> concurrent_assertion_statement();
    Ref<Process_statementContext> process_statement();
    Ref<Concurrent_procedure_call_statementContext> concurrent_procedure_call_statement();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_statementContext> entity_statement();

  class Entity_statement_partContext : public ParserRuleContext {
  public:
    Entity_statement_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Entity_statementContext>> entity_statement();
    Ref<Entity_statementContext> entity_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_statement_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_statement_partContext> entity_statement_part();

  class Entity_tagContext : public ParserRuleContext {
  public:
    Entity_tagContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> CHARACTER_LITERAL();
    Ref<tree::TerminalNode> STRING_LITERAL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEntity_tag(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Entity_tagContext> entity_tag();

  class Enumeration_literalContext : public ParserRuleContext {
  public:
    Enumeration_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> CHARACTER_LITERAL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEnumeration_literal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Enumeration_literalContext> enumeration_literal();

  class Enumeration_type_definitionContext : public ParserRuleContext {
  public:
    Enumeration_type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> LPAREN();
    std::vector<Ref<Enumeration_literalContext>> enumeration_literal();
    Ref<Enumeration_literalContext> enumeration_literal(int i);
    Ref<tree::TerminalNode> RPAREN();
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitEnumeration_type_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Enumeration_type_definitionContext> enumeration_type_definition();

  class Exit_statementContext : public ParserRuleContext {
  public:
    Exit_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> EXIT();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> WHEN();
    Ref<ConditionContext> condition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitExit_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Exit_statementContext> exit_statement();

  class ExpressionContext : public ParserRuleContext {
  public:
    ExpressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<RelationContext>> relation();
    Ref<RelationContext> relation(int i);
    std::vector<Ref<Logical_operatorContext>> logical_operator();
    Ref<Logical_operatorContext> logical_operator(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitExpression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<ExpressionContext> expression();

  class FactorContext : public ParserRuleContext {
  public:
    FactorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<PrimaryContext>> primary();
    Ref<PrimaryContext> primary(int i);
    Ref<tree::TerminalNode> DOUBLESTAR();
    Ref<tree::TerminalNode> ABS();
    Ref<tree::TerminalNode> NOT();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFactor(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<FactorContext> factor();

  class File_declarationContext : public ParserRuleContext {
  public:
    File_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> FILE();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> SEMI();
    Ref<File_open_informationContext> file_open_information();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFile_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<File_declarationContext> file_declaration();

  class File_logical_nameContext : public ParserRuleContext {
  public:
    File_logical_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFile_logical_name(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<File_logical_nameContext> file_logical_name();

  class File_open_informationContext : public ParserRuleContext {
  public:
    File_open_informationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> IS();
    Ref<File_logical_nameContext> file_logical_name();
    Ref<tree::TerminalNode> OPEN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFile_open_information(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<File_open_informationContext> file_open_information();

  class File_type_definitionContext : public ParserRuleContext {
  public:
    File_type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> FILE();
    Ref<tree::TerminalNode> OF();
    Ref<Subtype_indicationContext> subtype_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFile_type_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<File_type_definitionContext> file_type_definition();

  class Formal_parameter_listContext : public ParserRuleContext {
  public:
    Formal_parameter_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_listContext> interface_list();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFormal_parameter_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Formal_parameter_listContext> formal_parameter_list();

  class Formal_partContext : public ParserRuleContext {
  public:
    Formal_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Explicit_rangeContext> explicit_range();
    Ref<tree::TerminalNode> RPAREN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFormal_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Formal_partContext> formal_part();

  class Free_quantity_declarationContext : public ParserRuleContext {
  public:
    Free_quantity_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> QUANTITY();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFree_quantity_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Free_quantity_declarationContext> free_quantity_declaration();

  class Generate_statementContext : public ParserRuleContext {
  public:
    Generate_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Label_colonContext> label_colon();
    Ref<Generation_schemeContext> generation_scheme();
    std::vector<Ref<tree::TerminalNode>> GENERATE();
    Ref<tree::TerminalNode> GENERATE(int i);
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> BEGIN();
    std::vector<Ref<Architecture_statementContext>> architecture_statement();
    Ref<Architecture_statementContext> architecture_statement(int i);
    Ref<IdentifierContext> identifier();
    std::vector<Ref<Block_declarative_itemContext>> block_declarative_item();
    Ref<Block_declarative_itemContext> block_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGenerate_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generate_statementContext> generate_statement();

  class Generation_schemeContext : public ParserRuleContext {
  public:
    Generation_schemeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> FOR();
    Ref<Parameter_specificationContext> parameter_specification();
    Ref<tree::TerminalNode> IF();
    Ref<ConditionContext> condition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGeneration_scheme(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generation_schemeContext> generation_scheme();

  class Generic_clauseContext : public ParserRuleContext {
  public:
    Generic_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> GENERIC();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Generic_listContext> generic_list();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGeneric_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generic_clauseContext> generic_clause();

  class Generic_listContext : public ParserRuleContext {
  public:
    Generic_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Interface_constant_declarationContext>> interface_constant_declaration();
    Ref<Interface_constant_declarationContext> interface_constant_declaration(int i);
    std::vector<Ref<tree::TerminalNode>> SEMI();
    Ref<tree::TerminalNode> SEMI(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGeneric_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generic_listContext> generic_list();

  class Generic_map_aspectContext : public ParserRuleContext {
  public:
    Generic_map_aspectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> GENERIC();
    Ref<tree::TerminalNode> MAP();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Association_listContext> association_list();
    Ref<tree::TerminalNode> RPAREN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGeneric_map_aspect(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Generic_map_aspectContext> generic_map_aspect();

  class Group_constituentContext : public ParserRuleContext {
  public:
    Group_constituentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NameContext> name();
    Ref<tree::TerminalNode> CHARACTER_LITERAL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGroup_constituent(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Group_constituentContext> group_constituent();

  class Group_constituent_listContext : public ParserRuleContext {
  public:
    Group_constituent_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Group_constituentContext>> group_constituent();
    Ref<Group_constituentContext> group_constituent(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGroup_constituent_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Group_constituent_listContext> group_constituent_list();

  class Group_declarationContext : public ParserRuleContext {
  public:
    Group_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> GROUP();
    Ref<Label_colonContext> label_colon();
    Ref<NameContext> name();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Group_constituent_listContext> group_constituent_list();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGroup_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Group_declarationContext> group_declaration();

  class Group_template_declarationContext : public ParserRuleContext {
  public:
    Group_template_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> GROUP();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> IS();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Entity_class_entry_listContext> entity_class_entry_list();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGroup_template_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Group_template_declarationContext> group_template_declaration();

  class Guarded_signal_specificationContext : public ParserRuleContext {
  public:
    Guarded_signal_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Signal_listContext> signal_list();
    Ref<tree::TerminalNode> COLON();
    Ref<NameContext> name();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitGuarded_signal_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Guarded_signal_specificationContext> guarded_signal_specification();

  class IdentifierContext : public ParserRuleContext {
  public:
    IdentifierContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> BASIC_IDENTIFIER();
    Ref<tree::TerminalNode> EXTENDED_IDENTIFIER();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitIdentifier(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<IdentifierContext> identifier();

  class Identifier_listContext : public ParserRuleContext {
  public:
    Identifier_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitIdentifier_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Identifier_listContext> identifier_list();

  class If_statementContext : public ParserRuleContext {
  public:
    If_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> IF();
    Ref<tree::TerminalNode> IF(int i);
    std::vector<Ref<ConditionContext>> condition();
    Ref<ConditionContext> condition(int i);
    std::vector<Ref<tree::TerminalNode>> THEN();
    Ref<tree::TerminalNode> THEN(int i);
    std::vector<Ref<Sequence_of_statementsContext>> sequence_of_statements();
    Ref<Sequence_of_statementsContext> sequence_of_statements(int i);
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    std::vector<Ref<tree::TerminalNode>> ELSIF();
    Ref<tree::TerminalNode> ELSIF(int i);
    Ref<tree::TerminalNode> ELSE();
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitIf_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<If_statementContext> if_statement();

  class Index_constraintContext : public ParserRuleContext {
  public:
    Index_constraintContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> LPAREN();
    std::vector<Ref<Discrete_rangeContext>> discrete_range();
    Ref<Discrete_rangeContext> discrete_range(int i);
    Ref<tree::TerminalNode> RPAREN();
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitIndex_constraint(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Index_constraintContext> index_constraint();

  class Index_specificationContext : public ParserRuleContext {
  public:
    Index_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Discrete_rangeContext> discrete_range();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitIndex_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Index_specificationContext> index_specification();

  class Index_subtype_definitionContext : public ParserRuleContext {
  public:
    Index_subtype_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NameContext> name();
    Ref<tree::TerminalNode> RANGE();
    Ref<tree::TerminalNode> BOX();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitIndex_subtype_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Index_subtype_definitionContext> index_subtype_definition();

  class Instantiated_unitContext : public ParserRuleContext {
  public:
    Instantiated_unitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NameContext> name();
    Ref<tree::TerminalNode> COMPONENT();
    Ref<tree::TerminalNode> ENTITY();
    Ref<tree::TerminalNode> LPAREN();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> CONFIGURATION();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInstantiated_unit(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Instantiated_unitContext> instantiated_unit();

  class Instantiation_listContext : public ParserRuleContext {
  public:
    Instantiation_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);
    Ref<tree::TerminalNode> OTHERS();
    Ref<tree::TerminalNode> ALL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInstantiation_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Instantiation_listContext> instantiation_list();

  class Interface_constant_declarationContext : public ParserRuleContext {
  public:
    Interface_constant_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> CONSTANT();
    Ref<tree::TerminalNode> IN();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_constant_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_constant_declarationContext> interface_constant_declaration();

  class Interface_declarationContext : public ParserRuleContext {
  public:
    Interface_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_constant_declarationContext> interface_constant_declaration();
    Ref<Interface_signal_declarationContext> interface_signal_declaration();
    Ref<Interface_variable_declarationContext> interface_variable_declaration();
    Ref<Interface_file_declarationContext> interface_file_declaration();
    Ref<Interface_terminal_declarationContext> interface_terminal_declaration();
    Ref<Interface_quantity_declarationContext> interface_quantity_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_declarationContext> interface_declaration();

  class Interface_elementContext : public ParserRuleContext {
  public:
    Interface_elementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_declarationContext> interface_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_element(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_elementContext> interface_element();

  class Interface_file_declarationContext : public ParserRuleContext {
  public:
    Interface_file_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> FILE();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_file_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_file_declarationContext> interface_file_declaration();

  class Interface_signal_listContext : public ParserRuleContext {
  public:
    Interface_signal_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Interface_signal_declarationContext>> interface_signal_declaration();
    Ref<Interface_signal_declarationContext> interface_signal_declaration(int i);
    std::vector<Ref<tree::TerminalNode>> SEMI();
    Ref<tree::TerminalNode> SEMI(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_signal_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_signal_listContext> interface_signal_list();

  class Interface_port_listContext : public ParserRuleContext {
  public:
    Interface_port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Interface_port_declarationContext>> interface_port_declaration();
    Ref<Interface_port_declarationContext> interface_port_declaration(int i);
    std::vector<Ref<tree::TerminalNode>> SEMI();
    Ref<tree::TerminalNode> SEMI(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_port_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_port_listContext> interface_port_list();

  class Interface_listContext : public ParserRuleContext {
  public:
    Interface_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Interface_elementContext>> interface_element();
    Ref<Interface_elementContext> interface_element(int i);
    std::vector<Ref<tree::TerminalNode>> SEMI();
    Ref<tree::TerminalNode> SEMI(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_listContext> interface_list();

  class Interface_quantity_declarationContext : public ParserRuleContext {
  public:
    Interface_quantity_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> QUANTITY();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> IN();
    Ref<tree::TerminalNode> OUT();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_quantity_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_quantity_declarationContext> interface_quantity_declaration();

  class Interface_port_declarationContext : public ParserRuleContext {
  public:
    Interface_port_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Signal_modeContext> signal_mode();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> BUS();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_port_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_port_declarationContext> interface_port_declaration();

  class Interface_signal_declarationContext : public ParserRuleContext {
  public:
    Interface_signal_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> SIGNAL();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> BUS();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> IN();
    Ref<tree::TerminalNode> OUT();
    Ref<tree::TerminalNode> INOUT();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_signal_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_signal_declarationContext> interface_signal_declaration();

  class Interface_terminal_declarationContext : public ParserRuleContext {
  public:
    Interface_terminal_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> TERMINAL();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subnature_indicationContext> subnature_indication();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_terminal_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_terminal_declarationContext> interface_terminal_declaration();

  class Interface_variable_declarationContext : public ParserRuleContext {
  public:
    Interface_variable_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> VARIABLE();
    Ref<Signal_modeContext> signal_mode();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitInterface_variable_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Interface_variable_declarationContext> interface_variable_declaration();

  class Iteration_schemeContext : public ParserRuleContext {
  public:
    Iteration_schemeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> WHILE();
    Ref<ConditionContext> condition();
    Ref<tree::TerminalNode> FOR();
    Ref<Parameter_specificationContext> parameter_specification();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitIteration_scheme(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Iteration_schemeContext> iteration_scheme();

  class Label_colonContext : public ParserRuleContext {
  public:
    Label_colonContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> COLON();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitLabel_colon(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Label_colonContext> label_colon();

  class Library_clauseContext : public ParserRuleContext {
  public:
    Library_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> LIBRARY();
    Ref<Logical_name_listContext> logical_name_list();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitLibrary_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Library_clauseContext> library_clause();

  class Library_unitContext : public ParserRuleContext {
  public:
    Library_unitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Secondary_unitContext> secondary_unit();
    Ref<Primary_unitContext> primary_unit();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitLibrary_unit(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Library_unitContext> library_unit();

  class LiteralContext : public ParserRuleContext {
  public:
    LiteralContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> NULL_SYM();
    Ref<tree::TerminalNode> BIT_STRING_LITERAL();
    Ref<tree::TerminalNode> STRING_LITERAL();
    Ref<Enumeration_literalContext> enumeration_literal();
    Ref<Numeric_literalContext> numeric_literal();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitLiteral(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<LiteralContext> literal();

  class Logical_nameContext : public ParserRuleContext {
  public:
    Logical_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitLogical_name(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Logical_nameContext> logical_name();

  class Logical_name_listContext : public ParserRuleContext {
  public:
    Logical_name_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Logical_nameContext>> logical_name();
    Ref<Logical_nameContext> logical_name(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitLogical_name_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Logical_name_listContext> logical_name_list();

  class Logical_operatorContext : public ParserRuleContext {
  public:
    Logical_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> AND();
    Ref<tree::TerminalNode> OR();
    Ref<tree::TerminalNode> NAND();
    Ref<tree::TerminalNode> NOR();
    Ref<tree::TerminalNode> XOR();
    Ref<tree::TerminalNode> XNOR();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitLogical_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Logical_operatorContext> logical_operator();

  class Loop_statementContext : public ParserRuleContext {
  public:
    Loop_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> LOOP();
    Ref<tree::TerminalNode> LOOP(int i);
    Ref<Sequence_of_statementsContext> sequence_of_statements();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<Iteration_schemeContext> iteration_scheme();
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitLoop_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Loop_statementContext> loop_statement();

  class Signal_modeContext : public ParserRuleContext {
  public:
    Signal_modeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> IN();
    Ref<tree::TerminalNode> OUT();
    Ref<tree::TerminalNode> INOUT();
    Ref<tree::TerminalNode> BUFFER();
    Ref<tree::TerminalNode> LINKAGE();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSignal_mode(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Signal_modeContext> signal_mode();

  class Multiplying_operatorContext : public ParserRuleContext {
  public:
    Multiplying_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> MUL();
    Ref<tree::TerminalNode> DIV();
    Ref<tree::TerminalNode> MOD();
    Ref<tree::TerminalNode> REM();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitMultiplying_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Multiplying_operatorContext> multiplying_operator();

  class NameContext : public ParserRuleContext {
  public:
    NameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Selected_nameContext> selected_name();
    std::vector<Ref<Name_partContext>> name_part();
    Ref<Name_partContext> name_part(int i);
    std::vector<Ref<tree::TerminalNode>> DOT();
    Ref<tree::TerminalNode> DOT(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitName(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<NameContext> name();

  class Name_partContext : public ParserRuleContext {
  public:
    Name_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Selected_nameContext> selected_name();
    std::vector<Ref<Name_part_specificatorContext>> name_part_specificator();
    Ref<Name_part_specificatorContext> name_part_specificator(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitName_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Name_partContext> name_part();

  class Name_part_specificatorContext : public ParserRuleContext {
  public:
    Name_part_specificatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Name_attribute_partContext> name_attribute_part();
    Ref<Name_function_call_or_indexed_partContext> name_function_call_or_indexed_part();
    Ref<Name_slice_partContext> name_slice_part();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitName_part_specificator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Name_part_specificatorContext> name_part_specificator();

  class Name_attribute_partContext : public ParserRuleContext {
  public:
    Name_attribute_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> APOSTROPHE();
    Ref<Attribute_designatorContext> attribute_designator();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitName_attribute_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Name_attribute_partContext> name_attribute_part();

  class Name_function_call_or_indexed_partContext : public ParserRuleContext {
  public:
    Name_function_call_or_indexed_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> LPAREN();
    Ref<tree::TerminalNode> RPAREN();
    Ref<Actual_parameter_partContext> actual_parameter_part();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitName_function_call_or_indexed_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Name_function_call_or_indexed_partContext> name_function_call_or_indexed_part();

  class Name_slice_partContext : public ParserRuleContext {
  public:
    Name_slice_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> LPAREN();
    std::vector<Ref<Explicit_rangeContext>> explicit_range();
    Ref<Explicit_rangeContext> explicit_range(int i);
    Ref<tree::TerminalNode> RPAREN();
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitName_slice_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Name_slice_partContext> name_slice_part();

  class Selected_nameContext : public ParserRuleContext {
  public:
    Selected_nameContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    std::vector<Ref<tree::TerminalNode>> DOT();
    Ref<tree::TerminalNode> DOT(int i);
    std::vector<Ref<SuffixContext>> suffix();
    Ref<SuffixContext> suffix(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSelected_name(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Selected_nameContext> selected_name();

  class Nature_declarationContext : public ParserRuleContext {
  public:
    Nature_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> NATURE();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> IS();
    Ref<Nature_definitionContext> nature_definition();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitNature_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Nature_declarationContext> nature_declaration();

  class Nature_definitionContext : public ParserRuleContext {
  public:
    Nature_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Scalar_nature_definitionContext> scalar_nature_definition();
    Ref<Composite_nature_definitionContext> composite_nature_definition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitNature_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Nature_definitionContext> nature_definition();

  class Nature_element_declarationContext : public ParserRuleContext {
  public:
    Nature_element_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Element_subnature_definitionContext> element_subnature_definition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitNature_element_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Nature_element_declarationContext> nature_element_declaration();

  class Next_statementContext : public ParserRuleContext {
  public:
    Next_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> NEXT();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> WHEN();
    Ref<ConditionContext> condition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitNext_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Next_statementContext> next_statement();

  class Numeric_literalContext : public ParserRuleContext {
  public:
    Numeric_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Abstract_literalContext> abstract_literal();
    Ref<Physical_literalContext> physical_literal();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitNumeric_literal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Numeric_literalContext> numeric_literal();

  class Object_declarationContext : public ParserRuleContext {
  public:
    Object_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Constant_declarationContext> constant_declaration();
    Ref<Signal_declarationContext> signal_declaration();
    Ref<Variable_declarationContext> variable_declaration();
    Ref<File_declarationContext> file_declaration();
    Ref<Terminal_declarationContext> terminal_declaration();
    Ref<Quantity_declarationContext> quantity_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitObject_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Object_declarationContext> object_declaration();

  class OptsContext : public ParserRuleContext {
  public:
    OptsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> GUARDED();
    Ref<Delay_mechanismContext> delay_mechanism();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitOpts(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<OptsContext> opts();

  class Package_bodyContext : public ParserRuleContext {
  public:
    Package_bodyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> PACKAGE();
    Ref<tree::TerminalNode> PACKAGE(int i);
    std::vector<Ref<tree::TerminalNode>> BODY();
    Ref<tree::TerminalNode> BODY(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    Ref<tree::TerminalNode> IS();
    Ref<Package_body_declarative_partContext> package_body_declarative_part();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPackage_body(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Package_bodyContext> package_body();

  class Package_body_declarative_itemContext : public ParserRuleContext {
  public:
    Package_body_declarative_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_declarationContext> subprogram_declaration();
    Ref<Subprogram_bodyContext> subprogram_body();
    Ref<Type_declarationContext> type_declaration();
    Ref<Subtype_declarationContext> subtype_declaration();
    Ref<Constant_declarationContext> constant_declaration();
    Ref<Variable_declarationContext> variable_declaration();
    Ref<File_declarationContext> file_declaration();
    Ref<Alias_declarationContext> alias_declaration();
    Ref<Use_clauseContext> use_clause();
    Ref<Group_template_declarationContext> group_template_declaration();
    Ref<Group_declarationContext> group_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPackage_body_declarative_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Package_body_declarative_itemContext> package_body_declarative_item();

  class Package_body_declarative_partContext : public ParserRuleContext {
  public:
    Package_body_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Package_body_declarative_itemContext>> package_body_declarative_item();
    Ref<Package_body_declarative_itemContext> package_body_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPackage_body_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Package_body_declarative_partContext> package_body_declarative_part();

  class Package_declarationContext : public ParserRuleContext {
  public:
    Package_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> PACKAGE();
    Ref<tree::TerminalNode> PACKAGE(int i);
    std::vector<Ref<IdentifierContext>> identifier();
    Ref<IdentifierContext> identifier(int i);
    Ref<tree::TerminalNode> IS();
    Ref<Package_declarative_partContext> package_declarative_part();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPackage_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Package_declarationContext> package_declaration();

  class Package_declarative_itemContext : public ParserRuleContext {
  public:
    Package_declarative_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_declarationContext> subprogram_declaration();
    Ref<Type_declarationContext> type_declaration();
    Ref<Subtype_declarationContext> subtype_declaration();
    Ref<Constant_declarationContext> constant_declaration();
    Ref<Signal_declarationContext> signal_declaration();
    Ref<Variable_declarationContext> variable_declaration();
    Ref<File_declarationContext> file_declaration();
    Ref<Alias_declarationContext> alias_declaration();
    Ref<Component_declarationContext> component_declaration();
    Ref<Attribute_declarationContext> attribute_declaration();
    Ref<Attribute_specificationContext> attribute_specification();
    Ref<Disconnection_specificationContext> disconnection_specification();
    Ref<Use_clauseContext> use_clause();
    Ref<Group_template_declarationContext> group_template_declaration();
    Ref<Group_declarationContext> group_declaration();
    Ref<Nature_declarationContext> nature_declaration();
    Ref<Subnature_declarationContext> subnature_declaration();
    Ref<Terminal_declarationContext> terminal_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPackage_declarative_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Package_declarative_itemContext> package_declarative_item();

  class Package_declarative_partContext : public ParserRuleContext {
  public:
    Package_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Package_declarative_itemContext>> package_declarative_item();
    Ref<Package_declarative_itemContext> package_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPackage_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Package_declarative_partContext> package_declarative_part();

  class Parameter_specificationContext : public ParserRuleContext {
  public:
    Parameter_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> IN();
    Ref<Discrete_rangeContext> discrete_range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitParameter_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Parameter_specificationContext> parameter_specification();

  class Physical_literalContext : public ParserRuleContext {
  public:
    Physical_literalContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Abstract_literalContext> abstract_literal();
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPhysical_literal(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Physical_literalContext> physical_literal();

  class Physical_type_definitionContext : public ParserRuleContext {
  public:
    Physical_type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Range_constraintContext> range_constraint();
    std::vector<Ref<tree::TerminalNode>> UNITS();
    Ref<tree::TerminalNode> UNITS(int i);
    Ref<Base_unit_declarationContext> base_unit_declaration();
    Ref<tree::TerminalNode> END();
    std::vector<Ref<Secondary_unit_declarationContext>> secondary_unit_declaration();
    Ref<Secondary_unit_declarationContext> secondary_unit_declaration(int i);
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPhysical_type_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Physical_type_definitionContext> physical_type_definition();

  class Port_clauseContext : public ParserRuleContext {
  public:
    Port_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> PORT();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Port_listContext> port_list();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPort_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Port_clauseContext> port_clause();

  class Port_listContext : public ParserRuleContext {
  public:
    Port_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Interface_port_listContext> interface_port_list();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPort_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Port_listContext> port_list();

  class Port_map_aspectContext : public ParserRuleContext {
  public:
    Port_map_aspectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> PORT();
    Ref<tree::TerminalNode> MAP();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Association_listContext> association_list();
    Ref<tree::TerminalNode> RPAREN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPort_map_aspect(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Port_map_aspectContext> port_map_aspect();

  class PrimaryContext : public ParserRuleContext {
  public:
    PrimaryContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<LiteralContext> literal();
    Ref<Qualified_expressionContext> qualified_expression();
    Ref<tree::TerminalNode> LPAREN();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> RPAREN();
    Ref<AllocatorContext> allocator();
    Ref<AggregateContext> aggregate();
    Ref<NameContext> name();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPrimary(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<PrimaryContext> primary();

  class Primary_unitContext : public ParserRuleContext {
  public:
    Primary_unitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Entity_declarationContext> entity_declaration();
    Ref<Configuration_declarationContext> configuration_declaration();
    Ref<Package_declarationContext> package_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitPrimary_unit(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Primary_unitContext> primary_unit();

  class Procedural_declarative_itemContext : public ParserRuleContext {
  public:
    Procedural_declarative_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_declarationContext> subprogram_declaration();
    Ref<Subprogram_bodyContext> subprogram_body();
    Ref<Type_declarationContext> type_declaration();
    Ref<Subtype_declarationContext> subtype_declaration();
    Ref<Constant_declarationContext> constant_declaration();
    Ref<Variable_declarationContext> variable_declaration();
    Ref<Alias_declarationContext> alias_declaration();
    Ref<Attribute_declarationContext> attribute_declaration();
    Ref<Attribute_specificationContext> attribute_specification();
    Ref<Use_clauseContext> use_clause();
    Ref<Group_template_declarationContext> group_template_declaration();
    Ref<Group_declarationContext> group_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcedural_declarative_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Procedural_declarative_itemContext> procedural_declarative_item();

  class Procedural_declarative_partContext : public ParserRuleContext {
  public:
    Procedural_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Procedural_declarative_itemContext>> procedural_declarative_item();
    Ref<Procedural_declarative_itemContext> procedural_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcedural_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Procedural_declarative_partContext> procedural_declarative_part();

  class Procedural_statement_partContext : public ParserRuleContext {
  public:
    Procedural_statement_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Sequential_statementContext>> sequential_statement();
    Ref<Sequential_statementContext> sequential_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcedural_statement_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Procedural_statement_partContext> procedural_statement_part();

  class Procedure_callContext : public ParserRuleContext {
  public:
    Procedure_callContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Selected_nameContext> selected_name();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Actual_parameter_partContext> actual_parameter_part();
    Ref<tree::TerminalNode> RPAREN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcedure_call(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Procedure_callContext> procedure_call();

  class Procedure_call_statementContext : public ParserRuleContext {
  public:
    Procedure_call_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Procedure_callContext> procedure_call();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcedure_call_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Procedure_call_statementContext> procedure_call_statement();

  class Process_declarative_itemContext : public ParserRuleContext {
  public:
    Process_declarative_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_declarationContext> subprogram_declaration();
    Ref<Subprogram_bodyContext> subprogram_body();
    Ref<Type_declarationContext> type_declaration();
    Ref<Subtype_declarationContext> subtype_declaration();
    Ref<Constant_declarationContext> constant_declaration();
    Ref<Variable_declarationContext> variable_declaration();
    Ref<File_declarationContext> file_declaration();
    Ref<Alias_declarationContext> alias_declaration();
    Ref<Attribute_declarationContext> attribute_declaration();
    Ref<Attribute_specificationContext> attribute_specification();
    Ref<Use_clauseContext> use_clause();
    Ref<Group_template_declarationContext> group_template_declaration();
    Ref<Group_declarationContext> group_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcess_declarative_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Process_declarative_itemContext> process_declarative_item();

  class Process_declarative_partContext : public ParserRuleContext {
  public:
    Process_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Process_declarative_itemContext>> process_declarative_item();
    Ref<Process_declarative_itemContext> process_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcess_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Process_declarative_partContext> process_declarative_part();

  class Process_statementContext : public ParserRuleContext {
  public:
    Process_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> PROCESS();
    Ref<tree::TerminalNode> PROCESS(int i);
    Ref<Process_declarative_partContext> process_declarative_part();
    Ref<tree::TerminalNode> BEGIN();
    Ref<Process_statement_partContext> process_statement_part();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    std::vector<Ref<tree::TerminalNode>> POSTPONED();
    Ref<tree::TerminalNode> POSTPONED(int i);
    Ref<tree::TerminalNode> LPAREN();
    Ref<Sensitivity_listContext> sensitivity_list();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> IS();
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcess_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Process_statementContext> process_statement();

  class Process_statement_partContext : public ParserRuleContext {
  public:
    Process_statement_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Sequential_statementContext>> sequential_statement();
    Ref<Sequential_statementContext> sequential_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcess_statement_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Process_statement_partContext> process_statement_part();

  class Qualified_expressionContext : public ParserRuleContext {
  public:
    Qualified_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> APOSTROPHE();
    Ref<AggregateContext> aggregate();
    Ref<tree::TerminalNode> LPAREN();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> RPAREN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitQualified_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Qualified_expressionContext> qualified_expression();

  class Quantity_declarationContext : public ParserRuleContext {
  public:
    Quantity_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Free_quantity_declarationContext> free_quantity_declaration();
    Ref<Branch_quantity_declarationContext> branch_quantity_declaration();
    Ref<Source_quantity_declarationContext> source_quantity_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitQuantity_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Quantity_declarationContext> quantity_declaration();

  class Quantity_listContext : public ParserRuleContext {
  public:
    Quantity_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<NameContext>> name();
    Ref<NameContext> name(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);
    Ref<tree::TerminalNode> OTHERS();
    Ref<tree::TerminalNode> ALL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitQuantity_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Quantity_listContext> quantity_list();

  class Quantity_specificationContext : public ParserRuleContext {
  public:
    Quantity_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Quantity_listContext> quantity_list();
    Ref<tree::TerminalNode> COLON();
    Ref<NameContext> name();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitQuantity_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Quantity_specificationContext> quantity_specification();

  class RangeContext : public ParserRuleContext {
  public:
    RangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Explicit_rangeContext> explicit_range();
    Ref<NameContext> name();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitRange(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<RangeContext> range();

  class Explicit_rangeContext : public ParserRuleContext {
  public:
    Explicit_rangeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Simple_expressionContext>> simple_expression();
    Ref<Simple_expressionContext> simple_expression(int i);
    Ref<DirectionContext> direction();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitExplicit_range(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Explicit_rangeContext> explicit_range();

  class Range_constraintContext : public ParserRuleContext {
  public:
    Range_constraintContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> RANGE();
    Ref<RangeContext> range();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitRange_constraint(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Range_constraintContext> range_constraint();

  class Record_nature_definitionContext : public ParserRuleContext {
  public:
    Record_nature_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> RECORD();
    Ref<tree::TerminalNode> RECORD(int i);
    Ref<tree::TerminalNode> END();
    std::vector<Ref<Nature_element_declarationContext>> nature_element_declaration();
    Ref<Nature_element_declarationContext> nature_element_declaration(int i);
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitRecord_nature_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Record_nature_definitionContext> record_nature_definition();

  class Record_type_definitionContext : public ParserRuleContext {
  public:
    Record_type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> RECORD();
    Ref<tree::TerminalNode> RECORD(int i);
    Ref<tree::TerminalNode> END();
    std::vector<Ref<Element_declarationContext>> element_declaration();
    Ref<Element_declarationContext> element_declaration(int i);
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitRecord_type_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Record_type_definitionContext> record_type_definition();

  class RelationContext : public ParserRuleContext {
  public:
    RelationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Shift_expressionContext>> shift_expression();
    Ref<Shift_expressionContext> shift_expression(int i);
    Ref<Relational_operatorContext> relational_operator();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitRelation(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<RelationContext> relation();

  class Relational_operatorContext : public ParserRuleContext {
  public:
    Relational_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> EQ();
    Ref<tree::TerminalNode> NEQ();
    Ref<tree::TerminalNode> LOWERTHAN();
    Ref<tree::TerminalNode> LE();
    Ref<tree::TerminalNode> GREATERTHAN();
    Ref<tree::TerminalNode> GE();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitRelational_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Relational_operatorContext> relational_operator();

  class Report_statementContext : public ParserRuleContext {
  public:
    Report_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> REPORT();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<tree::TerminalNode> SEVERITY();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitReport_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Report_statementContext> report_statement();

  class Return_statementContext : public ParserRuleContext {
  public:
    Return_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> RETURN();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitReturn_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Return_statementContext> return_statement();

  class Scalar_nature_definitionContext : public ParserRuleContext {
  public:
    Scalar_nature_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<NameContext>> name();
    Ref<NameContext> name(int i);
    Ref<tree::TerminalNode> ACROSS();
    Ref<tree::TerminalNode> THROUGH();
    Ref<tree::TerminalNode> REFERENCE();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitScalar_nature_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Scalar_nature_definitionContext> scalar_nature_definition();

  class Scalar_type_definitionContext : public ParserRuleContext {
  public:
    Scalar_type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Physical_type_definitionContext> physical_type_definition();
    Ref<Enumeration_type_definitionContext> enumeration_type_definition();
    Ref<Range_constraintContext> range_constraint();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitScalar_type_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Scalar_type_definitionContext> scalar_type_definition();

  class Secondary_unitContext : public ParserRuleContext {
  public:
    Secondary_unitContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Architecture_bodyContext> architecture_body();
    Ref<Package_bodyContext> package_body();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSecondary_unit(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Secondary_unitContext> secondary_unit();

  class Secondary_unit_declarationContext : public ParserRuleContext {
  public:
    Secondary_unit_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> EQ();
    Ref<Physical_literalContext> physical_literal();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSecondary_unit_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Secondary_unit_declarationContext> secondary_unit_declaration();

  class Selected_signal_assignmentContext : public ParserRuleContext {
  public:
    Selected_signal_assignmentContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> WITH();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> SELECT();
    Ref<TargetContext> target();
    Ref<tree::TerminalNode> LE();
    Ref<OptsContext> opts();
    Ref<Selected_waveformsContext> selected_waveforms();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSelected_signal_assignment(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Selected_signal_assignmentContext> selected_signal_assignment();

  class Selected_waveformsContext : public ParserRuleContext {
  public:
    Selected_waveformsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<WaveformContext>> waveform();
    Ref<WaveformContext> waveform(int i);
    std::vector<Ref<tree::TerminalNode>> WHEN();
    Ref<tree::TerminalNode> WHEN(int i);
    std::vector<Ref<ChoicesContext>> choices();
    Ref<ChoicesContext> choices(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSelected_waveforms(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Selected_waveformsContext> selected_waveforms();

  class Sensitivity_clauseContext : public ParserRuleContext {
  public:
    Sensitivity_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ON();
    Ref<Sensitivity_listContext> sensitivity_list();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSensitivity_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Sensitivity_clauseContext> sensitivity_clause();

  class Sensitivity_listContext : public ParserRuleContext {
  public:
    Sensitivity_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<NameContext>> name();
    Ref<NameContext> name(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSensitivity_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Sensitivity_listContext> sensitivity_list();

  class Sequence_of_statementsContext : public ParserRuleContext {
  public:
    Sequence_of_statementsContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Sequential_statementContext>> sequential_statement();
    Ref<Sequential_statementContext> sequential_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSequence_of_statements(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Sequence_of_statementsContext> sequence_of_statements();

  class Sequential_statementContext : public ParserRuleContext {
  public:
    Sequential_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Wait_statementContext> wait_statement();
    Ref<Assertion_statementContext> assertion_statement();
    Ref<Report_statementContext> report_statement();
    Ref<Signal_assignment_statementContext> signal_assignment_statement();
    Ref<Variable_assignment_statementContext> variable_assignment_statement();
    Ref<If_statementContext> if_statement();
    Ref<Case_statementContext> case_statement();
    Ref<Loop_statementContext> loop_statement();
    Ref<Next_statementContext> next_statement();
    Ref<Exit_statementContext> exit_statement();
    Ref<Return_statementContext> return_statement();
    Ref<tree::TerminalNode> NULL_SYM();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<Break_statementContext> break_statement();
    Ref<Procedure_call_statementContext> procedure_call_statement();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSequential_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Sequential_statementContext> sequential_statement();

  class Shift_expressionContext : public ParserRuleContext {
  public:
    Shift_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Simple_expressionContext>> simple_expression();
    Ref<Simple_expressionContext> simple_expression(int i);
    Ref<Shift_operatorContext> shift_operator();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitShift_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Shift_expressionContext> shift_expression();

  class Shift_operatorContext : public ParserRuleContext {
  public:
    Shift_operatorContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> SLL();
    Ref<tree::TerminalNode> SRL();
    Ref<tree::TerminalNode> SLA();
    Ref<tree::TerminalNode> SRA();
    Ref<tree::TerminalNode> ROL();
    Ref<tree::TerminalNode> ROR();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitShift_operator(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Shift_operatorContext> shift_operator();

  class Signal_assignment_statementContext : public ParserRuleContext {
  public:
    Signal_assignment_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<TargetContext> target();
    Ref<tree::TerminalNode> LE();
    Ref<WaveformContext> waveform();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<Delay_mechanismContext> delay_mechanism();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSignal_assignment_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Signal_assignment_statementContext> signal_assignment_statement();

  class Signal_declarationContext : public ParserRuleContext {
  public:
    Signal_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> SIGNAL();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> SEMI();
    Ref<Signal_kindContext> signal_kind();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSignal_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Signal_declarationContext> signal_declaration();

  class Signal_kindContext : public ParserRuleContext {
  public:
    Signal_kindContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> REGISTER();
    Ref<tree::TerminalNode> BUS();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSignal_kind(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Signal_kindContext> signal_kind();

  class Signal_listContext : public ParserRuleContext {
  public:
    Signal_listContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<NameContext>> name();
    Ref<NameContext> name(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);
    Ref<tree::TerminalNode> OTHERS();
    Ref<tree::TerminalNode> ALL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSignal_list(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Signal_listContext> signal_list();

  class SignatureContext : public ParserRuleContext {
  public:
    SignatureContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> LBRACKET();
    Ref<tree::TerminalNode> RBRACKET();
    std::vector<Ref<NameContext>> name();
    Ref<NameContext> name(int i);
    Ref<tree::TerminalNode> RETURN();
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSignature(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<SignatureContext> signature();

  class Simple_expressionContext : public ParserRuleContext {
  public:
    Simple_expressionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<TermContext>> term();
    Ref<TermContext> term(int i);
    std::vector<Ref<Adding_operatorContext>> adding_operator();
    Ref<Adding_operatorContext> adding_operator(int i);
    Ref<tree::TerminalNode> PLUS();
    Ref<tree::TerminalNode> MINUS();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSimple_expression(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simple_expressionContext> simple_expression();

  class Simple_simultaneous_statementContext : public ParserRuleContext {
  public:
    Simple_simultaneous_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Simple_expressionContext>> simple_expression();
    Ref<Simple_expressionContext> simple_expression(int i);
    Ref<tree::TerminalNode> ASSIGN();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<Tolerance_aspectContext> tolerance_aspect();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSimple_simultaneous_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simple_simultaneous_statementContext> simple_simultaneous_statement();

  class Simultaneous_alternativeContext : public ParserRuleContext {
  public:
    Simultaneous_alternativeContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> WHEN();
    Ref<ChoicesContext> choices();
    Ref<tree::TerminalNode> ARROW();
    Ref<Simultaneous_statement_partContext> simultaneous_statement_part();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSimultaneous_alternative(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simultaneous_alternativeContext> simultaneous_alternative();

  class Simultaneous_case_statementContext : public ParserRuleContext {
  public:
    Simultaneous_case_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> CASE();
    Ref<tree::TerminalNode> CASE(int i);
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> USE();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    std::vector<Ref<Simultaneous_alternativeContext>> simultaneous_alternative();
    Ref<Simultaneous_alternativeContext> simultaneous_alternative(int i);
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSimultaneous_case_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simultaneous_case_statementContext> simultaneous_case_statement();

  class Simultaneous_if_statementContext : public ParserRuleContext {
  public:
    Simultaneous_if_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> IF();
    std::vector<Ref<ConditionContext>> condition();
    Ref<ConditionContext> condition(int i);
    std::vector<Ref<tree::TerminalNode>> USE();
    Ref<tree::TerminalNode> USE(int i);
    std::vector<Ref<Simultaneous_statement_partContext>> simultaneous_statement_part();
    Ref<Simultaneous_statement_partContext> simultaneous_statement_part(int i);
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    std::vector<Ref<tree::TerminalNode>> ELSIF();
    Ref<tree::TerminalNode> ELSIF(int i);
    Ref<tree::TerminalNode> ELSE();
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSimultaneous_if_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simultaneous_if_statementContext> simultaneous_if_statement();

  class Simultaneous_procedural_statementContext : public ParserRuleContext {
  public:
    Simultaneous_procedural_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<tree::TerminalNode>> PROCEDURAL();
    Ref<tree::TerminalNode> PROCEDURAL(int i);
    Ref<Procedural_declarative_partContext> procedural_declarative_part();
    Ref<tree::TerminalNode> BEGIN();
    Ref<Procedural_statement_partContext> procedural_statement_part();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<tree::TerminalNode> IS();
    Ref<IdentifierContext> identifier();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSimultaneous_procedural_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simultaneous_procedural_statementContext> simultaneous_procedural_statement();

  class Simultaneous_statementContext : public ParserRuleContext {
  public:
    Simultaneous_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Simple_simultaneous_statementContext> simple_simultaneous_statement();
    Ref<Simultaneous_if_statementContext> simultaneous_if_statement();
    Ref<Simultaneous_case_statementContext> simultaneous_case_statement();
    Ref<Simultaneous_procedural_statementContext> simultaneous_procedural_statement();
    Ref<tree::TerminalNode> NULL_SYM();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSimultaneous_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simultaneous_statementContext> simultaneous_statement();

  class Simultaneous_statement_partContext : public ParserRuleContext {
  public:
    Simultaneous_statement_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Simultaneous_statementContext>> simultaneous_statement();
    Ref<Simultaneous_statementContext> simultaneous_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSimultaneous_statement_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Simultaneous_statement_partContext> simultaneous_statement_part();

  class Source_aspectContext : public ParserRuleContext {
  public:
    Source_aspectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> SPECTRUM();
    std::vector<Ref<Simple_expressionContext>> simple_expression();
    Ref<Simple_expressionContext> simple_expression(int i);
    Ref<tree::TerminalNode> COMMA();
    Ref<tree::TerminalNode> NOISE();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSource_aspect(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Source_aspectContext> source_aspect();

  class Source_quantity_declarationContext : public ParserRuleContext {
  public:
    Source_quantity_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> QUANTITY();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<Source_aspectContext> source_aspect();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSource_quantity_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Source_quantity_declarationContext> source_quantity_declaration();

  class Step_limit_specificationContext : public ParserRuleContext {
  public:
    Step_limit_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> LIMIT();
    Ref<Quantity_specificationContext> quantity_specification();
    Ref<tree::TerminalNode> WITH();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitStep_limit_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Step_limit_specificationContext> step_limit_specification();

  class Subnature_declarationContext : public ParserRuleContext {
  public:
    Subnature_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> SUBNATURE();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> IS();
    Ref<Subnature_indicationContext> subnature_indication();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubnature_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subnature_declarationContext> subnature_declaration();

  class Subnature_indicationContext : public ParserRuleContext {
  public:
    Subnature_indicationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NameContext> name();
    Ref<Index_constraintContext> index_constraint();
    Ref<tree::TerminalNode> TOLERANCE();
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<tree::TerminalNode> ACROSS();
    Ref<tree::TerminalNode> THROUGH();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubnature_indication(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subnature_indicationContext> subnature_indication();

  class Subprogram_bodyContext : public ParserRuleContext {
  public:
    Subprogram_bodyContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_specificationContext> subprogram_specification();
    Ref<tree::TerminalNode> IS();
    Ref<Subprogram_declarative_partContext> subprogram_declarative_part();
    Ref<tree::TerminalNode> BEGIN();
    Ref<Subprogram_statement_partContext> subprogram_statement_part();
    Ref<tree::TerminalNode> END();
    Ref<tree::TerminalNode> SEMI();
    Ref<Subprogram_kindContext> subprogram_kind();
    Ref<DesignatorContext> designator();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubprogram_body(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subprogram_bodyContext> subprogram_body();

  class Subprogram_declarationContext : public ParserRuleContext {
  public:
    Subprogram_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_specificationContext> subprogram_specification();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubprogram_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subprogram_declarationContext> subprogram_declaration();

  class Subprogram_declarative_itemContext : public ParserRuleContext {
  public:
    Subprogram_declarative_itemContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Subprogram_declarationContext> subprogram_declaration();
    Ref<Subprogram_bodyContext> subprogram_body();
    Ref<Type_declarationContext> type_declaration();
    Ref<Subtype_declarationContext> subtype_declaration();
    Ref<Constant_declarationContext> constant_declaration();
    Ref<Variable_declarationContext> variable_declaration();
    Ref<File_declarationContext> file_declaration();
    Ref<Alias_declarationContext> alias_declaration();
    Ref<Attribute_declarationContext> attribute_declaration();
    Ref<Attribute_specificationContext> attribute_specification();
    Ref<Use_clauseContext> use_clause();
    Ref<Group_template_declarationContext> group_template_declaration();
    Ref<Group_declarationContext> group_declaration();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubprogram_declarative_item(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subprogram_declarative_itemContext> subprogram_declarative_item();

  class Subprogram_declarative_partContext : public ParserRuleContext {
  public:
    Subprogram_declarative_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Subprogram_declarative_itemContext>> subprogram_declarative_item();
    Ref<Subprogram_declarative_itemContext> subprogram_declarative_item(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubprogram_declarative_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subprogram_declarative_partContext> subprogram_declarative_part();

  class Subprogram_kindContext : public ParserRuleContext {
  public:
    Subprogram_kindContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> PROCEDURE();
    Ref<tree::TerminalNode> FUNCTION();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubprogram_kind(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subprogram_kindContext> subprogram_kind();

  class Subprogram_specificationContext : public ParserRuleContext {
  public:
    Subprogram_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Procedure_specificationContext> procedure_specification();
    Ref<Function_specificationContext> function_specification();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubprogram_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subprogram_specificationContext> subprogram_specification();

  class Procedure_specificationContext : public ParserRuleContext {
  public:
    Procedure_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> PROCEDURE();
    Ref<DesignatorContext> designator();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Formal_parameter_listContext> formal_parameter_list();
    Ref<tree::TerminalNode> RPAREN();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitProcedure_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Procedure_specificationContext> procedure_specification();

  class Function_specificationContext : public ParserRuleContext {
  public:
    Function_specificationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> FUNCTION();
    Ref<DesignatorContext> designator();
    Ref<tree::TerminalNode> RETURN();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> LPAREN();
    Ref<Formal_parameter_listContext> formal_parameter_list();
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> PURE();
    Ref<tree::TerminalNode> IMPURE();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitFunction_specification(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Function_specificationContext> function_specification();

  class Subprogram_statement_partContext : public ParserRuleContext {
  public:
    Subprogram_statement_partContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Sequential_statementContext>> sequential_statement();
    Ref<Sequential_statementContext> sequential_statement(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubprogram_statement_part(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subprogram_statement_partContext> subprogram_statement_part();

  class Subtype_declarationContext : public ParserRuleContext {
  public:
    Subtype_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> SUBTYPE();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> IS();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubtype_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subtype_declarationContext> subtype_declaration();

  class Subtype_indicationContext : public ParserRuleContext {
  public:
    Subtype_indicationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Selected_nameContext>> selected_name();
    Ref<Selected_nameContext> selected_name(int i);
    Ref<ConstraintContext> constraint();
    Ref<Tolerance_aspectContext> tolerance_aspect();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSubtype_indication(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Subtype_indicationContext> subtype_indication();

  class SuffixContext : public ParserRuleContext {
  public:
    SuffixContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> CHARACTER_LITERAL();
    Ref<tree::TerminalNode> STRING_LITERAL();
    Ref<tree::TerminalNode> ALL();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitSuffix(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<SuffixContext> suffix();

  class TargetContext : public ParserRuleContext {
  public:
    TargetContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<NameContext> name();
    Ref<AggregateContext> aggregate();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitTarget(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<TargetContext> target();

  class TermContext : public ParserRuleContext {
  public:
    TermContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<FactorContext>> factor();
    Ref<FactorContext> factor(int i);
    std::vector<Ref<Multiplying_operatorContext>> multiplying_operator();
    Ref<Multiplying_operatorContext> multiplying_operator(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitTerm(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<TermContext> term();

  class Terminal_aspectContext : public ParserRuleContext {
  public:
    Terminal_aspectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<NameContext>> name();
    Ref<NameContext> name(int i);
    Ref<tree::TerminalNode> TO();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitTerminal_aspect(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Terminal_aspectContext> terminal_aspect();

  class Terminal_declarationContext : public ParserRuleContext {
  public:
    Terminal_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> TERMINAL();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subnature_indicationContext> subnature_indication();
    Ref<tree::TerminalNode> SEMI();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitTerminal_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Terminal_declarationContext> terminal_declaration();

  class Through_aspectContext : public ParserRuleContext {
  public:
    Through_aspectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> THROUGH();
    Ref<Tolerance_aspectContext> tolerance_aspect();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitThrough_aspect(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Through_aspectContext> through_aspect();

  class Timeout_clauseContext : public ParserRuleContext {
  public:
    Timeout_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> FOR();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitTimeout_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Timeout_clauseContext> timeout_clause();

  class Tolerance_aspectContext : public ParserRuleContext {
  public:
    Tolerance_aspectContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> TOLERANCE();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitTolerance_aspect(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Tolerance_aspectContext> tolerance_aspect();

  class Type_declarationContext : public ParserRuleContext {
  public:
    Type_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> TYPE();
    Ref<IdentifierContext> identifier();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> IS();
    Ref<Type_definitionContext> type_definition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitType_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Type_declarationContext> type_declaration();

  class Type_definitionContext : public ParserRuleContext {
  public:
    Type_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<Scalar_type_definitionContext> scalar_type_definition();
    Ref<Composite_type_definitionContext> composite_type_definition();
    Ref<Access_type_definitionContext> access_type_definition();
    Ref<File_type_definitionContext> file_type_definition();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitType_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Type_definitionContext> type_definition();

  class Unconstrained_array_definitionContext : public ParserRuleContext {
  public:
    Unconstrained_array_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ARRAY();
    Ref<tree::TerminalNode> LPAREN();
    std::vector<Ref<Index_subtype_definitionContext>> index_subtype_definition();
    Ref<Index_subtype_definitionContext> index_subtype_definition(int i);
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> OF();
    Ref<Subtype_indicationContext> subtype_indication();
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitUnconstrained_array_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Unconstrained_array_definitionContext> unconstrained_array_definition();

  class Unconstrained_nature_definitionContext : public ParserRuleContext {
  public:
    Unconstrained_nature_definitionContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> ARRAY();
    Ref<tree::TerminalNode> LPAREN();
    std::vector<Ref<Index_subtype_definitionContext>> index_subtype_definition();
    Ref<Index_subtype_definitionContext> index_subtype_definition(int i);
    Ref<tree::TerminalNode> RPAREN();
    Ref<tree::TerminalNode> OF();
    Ref<Subnature_indicationContext> subnature_indication();
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitUnconstrained_nature_definition(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Unconstrained_nature_definitionContext> unconstrained_nature_definition();

  class Use_clauseContext : public ParserRuleContext {
  public:
    Use_clauseContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> USE();
    std::vector<Ref<Selected_nameContext>> selected_name();
    Ref<Selected_nameContext> selected_name(int i);
    Ref<tree::TerminalNode> SEMI();
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitUse_clause(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Use_clauseContext> use_clause();

  class Variable_assignment_statementContext : public ParserRuleContext {
  public:
    Variable_assignment_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<TargetContext> target();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitVariable_assignment_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Variable_assignment_statementContext> variable_assignment_statement();

  class Variable_declarationContext : public ParserRuleContext {
  public:
    Variable_declarationContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> VARIABLE();
    Ref<Identifier_listContext> identifier_list();
    Ref<tree::TerminalNode> COLON();
    Ref<Subtype_indicationContext> subtype_indication();
    Ref<tree::TerminalNode> SEMI();
    Ref<tree::TerminalNode> SHARED();
    Ref<tree::TerminalNode> VARASGN();
    Ref<ExpressionContext> expression();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitVariable_declaration(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Variable_declarationContext> variable_declaration();

  class Wait_statementContext : public ParserRuleContext {
  public:
    Wait_statementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    Ref<tree::TerminalNode> WAIT();
    Ref<tree::TerminalNode> SEMI();
    Ref<Label_colonContext> label_colon();
    Ref<Sensitivity_clauseContext> sensitivity_clause();
    Ref<Condition_clauseContext> condition_clause();
    Ref<Timeout_clauseContext> timeout_clause();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitWait_statement(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Wait_statementContext> wait_statement();

  class WaveformContext : public ParserRuleContext {
  public:
    WaveformContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<Waveform_elementContext>> waveform_element();
    Ref<Waveform_elementContext> waveform_element(int i);
    std::vector<Ref<tree::TerminalNode>> COMMA();
    Ref<tree::TerminalNode> COMMA(int i);
    Ref<tree::TerminalNode> UNAFFECTED();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitWaveform(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<WaveformContext> waveform();

  class Waveform_elementContext : public ParserRuleContext {
  public:
    Waveform_elementContext(std::weak_ptr<ParserRuleContext> parent, int invokingState);
    virtual ssize_t getRuleIndex() const override;
    std::vector<Ref<ExpressionContext>> expression();
    Ref<ExpressionContext> expression(int i);
    Ref<tree::TerminalNode> AFTER();

    virtual void enterRule(tree::ParseTreeListener *listener) override;
    virtual void exitRule(tree::ParseTreeListener *listener) override;

    template <typename T>
    T* accept(tree::ParseTreeVisitor<T> *visitor) {
      if (dynamic_cast<vhdlVisitor<T>*>(visitor) != nullptr)
        return ((vhdlVisitor<T> *)visitor)->visitWaveform_element(this);
      else
        return visitor->visitChildren(this);
    }
   
  };

  Ref<Waveform_elementContext> waveform_element();


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

}  // namespace vhdl
