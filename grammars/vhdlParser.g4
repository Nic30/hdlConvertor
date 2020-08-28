parser grammar vhdlParser;
options { tokenVocab=vhdlLexer; }

/*
 * Grammar extracted from the 2008 standard
 */

any_keyword:
    KW_PROCESS
    | KW_CONTEXT
    | KW_POSTPONED
    | KW_LINKAGE
    | KW_COMPONENT
    | KW_ABS
    | KW_DEFAULT
    | KW_THEN
    | KW_BLOCK
    | KW_REM
    | KW_INERTIAL
    | KW_NEXT
    | KW_ENTITY
    | KW_ON
    | KW_GROUP
    | KW_XNOR
    | KW_FILE
    | KW_PURE
    | KW_GUARDED
    | KW_GENERIC
    | KW_RANGE
    | KW_ELSE
    | KW_USE
    | KW_SHARED
    | KW_MOD
    | KW_LOOP
    | KW_RECORD
    | KW_SIGNAL
    | KW_REJECT
    | KW_BEGIN
    | KW_SLA
    | KW_DISCONNECT
    | KW_OF
    | KW_PROCEDURE
    | KW_SRL
    | KW_VUNIT
    | KW_ATTRIBUTE
    | KW_VARIABLE
    | KW_PROPERTY
    | KW_UNAFFECTED
    | KW_XOR
    | KW_REGISTER
    | KW_SUBTYPE
    | KW_TO
    | KW_NEW
    | KW_REPORT
    | KW_CONSTANT
    | KW_BUFFER
    | KW_BODY
    | KW_AFTER
    | KW_TRANSPORT
    | KW_FUNCTION
    | KW_END
    | KW_SELECT
    | KW_OR
    | KW_LIBRARY
    | KW_ELSIF
    | KW_SLL
    | KW_MAP
    | KW_SRA
    | KW_PROTECTED
    | KW_DOWNTO
    | KW_LABEL
    | KW_ALL
    | KW_ALIAS
    | KW_GENERATE
    | KW_NOR
    | KW_IN
    | KW_RELEASE
    | KW_EXIT
    | KW_RETURN
    | KW_WITH
    | KW_UNTIL
    | KW_AND
    | KW_INOUT
    | KW_WAIT
    | KW_NAND
    | KW_ARRAY
    | KW_FORCE
    | KW_WHILE
    | KW_IMPURE
    | KW_PACKAGE
    | KW_UNITS
    | KW_ASSERT
    | KW_PARAMETER
    | KW_SEVERITY
    | KW_LITERAL
    | KW_FOR
    | KW_ROR
    | KW_IF
    | KW_OUT
    | KW_ROL
    | KW_IS
    | KW_SEQUENCE
    | KW_OTHERS
    | KW_TYPE
    | KW_CASE
    | KW_NOT
    | KW_CONFIGURATION
    | KW_OPEN
    | KW_ARCHITECTURE
    | KW_BUS
    | KW_ACCESS
    | KW_WHEN
    | KW_PORT
    | KW_NULL
;
name_literal:
        identifier     
       | operator_symbol   
       | CHARACTER_LITERAL 

;
name:
    name_literal
      | name (
            name_slice_part // name_index was removed as it is same as call
            | name_attribute_part
            | association_list // call args
            | DOT suffix
        )
      | external_name
;
name_slice_part:
    LPAREN explicit_range RPAREN
;
name_attribute_part:
    ( signature )? APOSTROPHE attribute_designator
;
attribute_name:
    name name_attribute_part
;

suffix:
    name_literal
    | KW_ALL
;

explicit_range:
      simple_expression direction simple_expression
;

selected_name:
      identifier (DOT suffix)*
;
entity_declaration:
      KW_ENTITY identifier KW_IS
          ( generic_clause )?
          ( port_clause )?
          ( entity_declarative_item )*
      ( KW_BEGIN ( entity_statement )* )?
      KW_END ( KW_ENTITY )? ( identifier )? SEMI
;
entity_declarative_item:
      signal_declaration
      | process_declarative_item
      | disconnection_specification
;
entity_statement:
    ( label COLON )? (
      concurrent_assertion_statement
      | concurrent_procedure_call_statement
      | process_statement
      // | PSL_PSL_Directive
     )
;
architecture_body:
      KW_ARCHITECTURE identifier KW_OF name KW_IS
          ( block_declarative_item )*
      KW_BEGIN
          ( concurrent_statement )*
      KW_END ( KW_ARCHITECTURE )? ( identifier )? SEMI
;
block_declarative_item:
      entity_declarative_item
      | component_declaration
      | configuration_specification
;
configuration_declaration:
    KW_CONFIGURATION identifier KW_OF name KW_IS
        ( configuration_declarative_item )*
        ( verification_unit_binding_indication SEMI )*
        block_configuration
    KW_END ( KW_CONFIGURATION )? ( identifier )? SEMI
;
configuration_declarative_item:
    use_clause
    | attribute_specification
    | group_declaration
;
block_configuration:
    KW_FOR block_specification
        ( use_clause )*
        ( configuration_item )*
    KW_END KW_FOR SEMI
;
block_specification:
    label ( LPAREN generate_specification RPAREN )?
;
generate_specification:
    discrete_range
    | expression
    | label
;
configuration_item:
    block_configuration
    | component_configuration
;
component_configuration:
    KW_FOR component_specification
        ( binding_indication SEMI )?
        ( verification_unit_binding_indication SEMI )*
        ( block_configuration )?
    KW_END KW_FOR SEMI
;
subprogram_declaration:
    subprogram_specification SEMI
;
subprogram_specification:
    procedure_specification
    | function_specification
;
procedure_specification:
    KW_PROCEDURE designator
    ( subprogram_header )?
    ( ( KW_PARAMETER )? LPAREN formal_parameter_list RPAREN )?
;
function_specification:
    ( KW_PURE | KW_IMPURE )? KW_FUNCTION designator
    ( subprogram_header )?
    ( ( KW_PARAMETER )? LPAREN formal_parameter_list RPAREN )? KW_RETURN type_mark
;
subprogram_header:
    KW_GENERIC LPAREN generic_list RPAREN
    ( generic_map_aspect )?
;
designator: identifier | operator_symbol;
operator_symbol: STRING_LITERAL;
formal_parameter_list: interface_list;
subprogram_body:
      subprogram_specification KW_IS
          ( process_declarative_item )*
      KW_BEGIN
          ( sequential_statement )*
      KW_END ( subprogram_kind )? ( designator )? SEMI
;
subprogram_kind: KW_PROCEDURE | KW_FUNCTION;
subprogram_instantiation_declaration:
      subprogram_kind designator KW_IS KW_NEW name ( signature )?
          ( generic_map_aspect )? SEMI
;

signature: LSQUARE_BR ( type_mark ( COMMA type_mark )* )? ( KW_RETURN type_mark )? RSQUARE_BR
;
package_declaration:
      KW_PACKAGE identifier KW_IS
          (
             generic_clause  ( generic_map_aspect SEMI )?
          )?
          ( package_declarative_item )*
      KW_END ( KW_PACKAGE )? ( identifier )? SEMI
;
package_declarative_item:
      process_or_package_declarative_item
      | signal_declaration
      | component_declaration
      | disconnection_specification
;
package_body:
      KW_PACKAGE KW_BODY identifier KW_IS
          ( process_declarative_item )*
      KW_END ( KW_PACKAGE KW_BODY )? ( identifier )? SEMI
;
package_instantiation_declaration:
      KW_PACKAGE identifier KW_IS KW_NEW name
          ( generic_map_aspect )? SEMI
;
scalar_type_definition:
      enumeration_type_definition
      | integer_type_definition
      | floating_type_definition
      | physical_type_definition
;
range_constraint: KW_RANGE range;
range:
      attribute_name
      | simple_expression direction simple_expression
;
direction: KW_TO | KW_DOWNTO;
enumeration_type_definition:
      LPAREN enumeration_literal ( COMMA enumeration_literal )* RPAREN
;
enumeration_literal: identifier | CHARACTER_LITERAL;
integer_type_definition: range_constraint;
physical_type_definition:
      range_constraint
          KW_UNITS
              primary_unit_declaration
              ( secondary_unit_declaration )*
          KW_END KW_UNITS ( identifier )?
;
primary_unit_declaration: identifier SEMI;
secondary_unit_declaration: identifier EQ physical_literal SEMI;
floating_type_definition: range_constraint;
composite_type_definition:
      array_type_definition
      | record_type_definition
;
array_type_definition:
      unbounded_array_definition | constrained_array_definition
;
unbounded_array_definition:
      KW_ARRAY LPAREN index_subtype_definition ( COMMA index_subtype_definition )* RPAREN
          KW_OF subtype_indication
;
constrained_array_definition:
      KW_ARRAY index_constraint KW_OF subtype_indication
;
index_subtype_definition: type_mark KW_RANGE BOX;
array_constraint:
      index_constraint ( array_element_constraint )?
      | LPAREN KW_OPEN RPAREN ( array_element_constraint )?
;
array_element_constraint: element_constraint;
index_constraint: LPAREN discrete_range ( COMMA discrete_range )* RPAREN;
discrete_range: subtype_indication | range;
record_type_definition:
      KW_RECORD
          ( element_declaration )+
      KW_END KW_RECORD ( identifier )?
;
element_declaration:
      identifier_list COLON element_subtype_definition SEMI
;
identifier_list: identifier ( COMMA identifier )*;
element_subtype_definition: subtype_indication;
record_constraint:
      LPAREN record_element_constraint ( COMMA record_element_constraint )* RPAREN
;
record_element_constraint: identifier element_constraint;
access_type_definition: KW_ACCESS subtype_indication;
incomplete_type_declaration: KW_TYPE identifier SEMI;
file_type_definition: KW_FILE KW_OF type_mark;
protected_type_definition:
      protected_type_declaration
      | protected_type_body
;
protected_type_declaration:
      KW_PROTECTED
          ( protected_type_declarative_item )*
      KW_END KW_PROTECTED ( identifier )?
;
protected_type_declarative_item:
      subprogram_declaration
      | subprogram_instantiation_declaration
      | attribute_specification
      | use_clause
;
protected_type_body:
      KW_PROTECTED KW_BODY
          ( process_declarative_item )*
      KW_END KW_PROTECTED KW_BODY ( identifier )?
;
type_declaration:
      full_type_declaration
      | incomplete_type_declaration
;
full_type_declaration:
      KW_TYPE identifier KW_IS type_definition SEMI
;
type_definition:
      scalar_type_definition
      | composite_type_definition
      | access_type_definition
      | file_type_definition
      | protected_type_definition
;
subtype_declaration:
      KW_SUBTYPE identifier KW_IS subtype_indication SEMI
;
subtype_indication:
      ( resolution_indication )? type_mark ( constraint )?
;
resolution_indication:
      name
      | LPAREN element_resolution RPAREN
;
element_resolution: array_element_resolution | record_resolution;
array_element_resolution: resolution_indication;
record_resolution: record_element_resolution ( COMMA record_element_resolution )*;
record_element_resolution: identifier resolution_indication;
type_mark: name;
constraint:
      range_constraint
      | array_constraint
      | record_constraint
;
element_constraint:
      array_constraint
      | record_constraint
;
object_declaration:
      constant_declaration
      | signal_declaration
      | variable_declaration
      | file_declaration
;
constant_declaration:
      KW_CONSTANT identifier_list COLON subtype_indication ( VARASGN expression )? SEMI
;
signal_declaration:
      KW_SIGNAL identifier_list COLON subtype_indication ( signal_kind )? ( VARASGN expression )? SEMI
;
signal_kind: KW_REGISTER | KW_BUS;
variable_declaration:
      ( KW_SHARED )? KW_VARIABLE identifier_list COLON subtype_indication ( VARASGN expression )? SEMI
;
file_declaration:
      KW_FILE identifier_list COLON subtype_indication ( file_open_information )? SEMI
;
file_open_information: ( KW_OPEN expression )? KW_IS 
	(KW_IN | KW_OUT)? // v87 only
    file_logical_name;
file_logical_name: expression;
interface_declaration:
      interface_object_declaration
      | interface_type_declaration
      | interface_subprogram_declaration
      | interface_package_declaration
;
interface_object_declaration:
      interface_constant_declaration
      | interface_signal_declaration
      | interface_variable_declaration
      | interface_file_declaration
;
// [note] constant as variables can be parsed as a signal if their keyword is not specified
interface_constant_declaration:
      KW_CONSTANT identifier_list COLON ( KW_IN )? subtype_indication ( VARASGN expression )?
;
interface_signal_declaration:
      ( KW_SIGNAL )? identifier_list COLON ( signal_mode )? subtype_indication ( KW_BUS )? ( VARASGN expression )?
;
interface_variable_declaration:
      KW_VARIABLE identifier_list COLON ( signal_mode )? subtype_indication ( VARASGN expression )?
;
interface_file_declaration:
      KW_FILE identifier_list COLON subtype_indication
;
signal_mode: KW_IN | KW_OUT | KW_INOUT | KW_BUFFER | KW_LINKAGE;
interface_type_declaration:
      interface_incomplete_type_declaration
;
interface_incomplete_type_declaration: KW_TYPE identifier;
interface_subprogram_declaration:
      interface_subprogram_specification ( KW_IS interface_subprogram_default )?
;
interface_subprogram_specification:
        interface_procedure_specification
      | interface_function_specification
;
interface_procedure_specification:
      KW_PROCEDURE designator
          ( ( KW_PARAMETER )? LPAREN formal_parameter_list RPAREN )?
;
interface_function_specification:
      ( KW_PURE | KW_IMPURE )? KW_FUNCTION designator
          ( ( KW_PARAMETER )? LPAREN formal_parameter_list RPAREN )? KW_RETURN type_mark
;
interface_subprogram_default: name | BOX;
interface_package_declaration:
      KW_PACKAGE identifier KW_IS KW_NEW name interface_package_generic_map_aspect
;
interface_package_generic_map_aspect:
      generic_map_aspect
      | KW_GENERIC KW_MAP LPAREN BOX RPAREN
      | KW_GENERIC KW_MAP LPAREN KW_DEFAULT RPAREN
;
interface_list:
      interface_element ( SEMI interface_element )*
;
interface_element: interface_declaration;
generic_clause:
      KW_GENERIC LPAREN generic_list RPAREN SEMI
;
generic_list: interface_list;
port_clause:
      KW_PORT LPAREN port_list RPAREN SEMI
;
port_list: interface_list;
association_list:
    LPAREN association_element ( COMMA association_element )* RPAREN
;
association_element:
      ( formal_part ARROW )? actual_part
;
formal_part:
      name (LPAREN name RPAREN)?
;
// [todo] performance problem, actual_designator can become just name, but name(name) is part of name
actual_part:
      name LPAREN actual_designator RPAREN
      | actual_designator
;
actual_designator:
      ( KW_INERTIAL )? expression
      | subtype_indication
      | KW_OPEN
;
generic_map_aspect:
      KW_GENERIC KW_MAP association_list
;
port_map_aspect:
      KW_PORT KW_MAP association_list
;
alias_declaration:
      KW_ALIAS alias_designator ( COLON subtype_indication )? KW_IS name ( signature )? SEMI
;
alias_designator: identifier | CHARACTER_LITERAL | operator_symbol;
attribute_declaration:
      KW_ATTRIBUTE identifier COLON type_mark SEMI
;
component_declaration:
      KW_COMPONENT identifier ( KW_IS )?
          ( generic_clause )?
          ( port_clause )?
      KW_END KW_COMPONENT ( identifier )? SEMI
;
group_template_declaration:
      KW_GROUP identifier KW_IS LPAREN entity_class_entry_list RPAREN SEMI
;
entity_class_entry_list:
      entity_class_entry ( COMMA entity_class_entry )*
;
entity_class_entry: entity_class ( BOX )?;
group_declaration:
      KW_GROUP identifier COLON name LPAREN group_constituent_list RPAREN SEMI
;
group_constituent_list: group_constituent ( COMMA group_constituent )*;
group_constituent: name;
attribute_specification:
      KW_ATTRIBUTE attribute_designator KW_OF entity_specification KW_IS expression SEMI
;
entity_specification:
      entity_name_list COLON entity_class
;
entity_class:
      KW_ENTITY
      | KW_ARCHITECTURE
      | KW_CONFIGURATION
      | KW_PROCEDURE
      | KW_FUNCTION
      | KW_PACKAGE
      | KW_TYPE
      | KW_SUBTYPE
      | KW_CONSTANT
      | KW_SIGNAL
      | KW_VARIABLE
      | KW_COMPONENT
      | KW_LABEL
      | KW_LITERAL
      | KW_UNITS
      | KW_GROUP
      | KW_FILE
      | KW_PROPERTY
      | KW_SEQUENCE
;
entity_name_list:
      entity_designator ( COMMA entity_designator )*
      | KW_OTHERS
      | KW_ALL
;
entity_designator: entity_tag ( signature )?;
entity_tag: identifier | CHARACTER_LITERAL | operator_symbol;
configuration_specification:
      simple_configuration_specification
      | compound_configuration_specification
;
simple_configuration_specification:
      KW_FOR component_specification binding_indication SEMI
      ( KW_END KW_FOR SEMI )?
;
compound_configuration_specification:
      KW_FOR component_specification binding_indication SEMI
          ( verification_unit_binding_indication SEMI )+
      KW_END KW_FOR SEMI
;
component_specification:
      instantiation_list COLON name
;
instantiation_list:
      label ( COMMA label )*
      | KW_OTHERS
      | KW_ALL
;
binding_indication:
      ( KW_USE entity_aspect )?
      ( generic_map_aspect )?
      ( port_map_aspect )?
;
entity_aspect:
      KW_ENTITY name ( LPAREN identifier RPAREN )?
      | KW_CONFIGURATION name
      | KW_OPEN
;
verification_unit_binding_indication:
      KW_USE KW_VUNIT verification_unit_list
;
verification_unit_list: name ( COMMA name )*;
disconnection_specification:
      KW_DISCONNECT guarded_signal_specification KW_AFTER expression SEMI
;
guarded_signal_specification:
      signal_list COLON type_mark
;
signal_list:
      name ( COMMA name )*
      | KW_OTHERS
      | KW_ALL
;

attribute_designator: identifier | any_keyword;
external_name:
      SHIFT_LEFT (KW_VARIABLE | KW_CONSTANT | KW_SIGNAL) external_pathname COLON subtype_indication SHIFT_RIGHT
;
external_pathname:
      package_pathname
      | absolute_pathname
      | relative_pathname
;
package_pathname:
      AT identifier DOT identifier DOT identifier ( DOT identifier )*
;
absolute_pathname: DOT partial_pathname;
relative_pathname: ( UP DOT )* partial_pathname;
partial_pathname: ( pathname_element DOT )* identifier;
pathname_element:
      label ( LPAREN expression RPAREN )?
;
expression:
      COND_OP primary
      | simple_expression
      | expression shift_operator expression
      | expression relational_operator expression
      | expression logical_operator expression
;
simple_expression:
      primary ( DOUBLESTAR primary )?
      | ( KW_ABS | KW_NOT | logical_operator) simple_expression
      | simple_expression multiplying_operator simple_expression
      | sign simple_expression
      | simple_expression adding_operator simple_expression
;
primary:
      numeric_literal        // 1      // [attention] numeric literal also contains name
                             //             name can contain string and char
      | BIT_STRING_LITERAL   // 2
      | KW_NULL              // 3
      | allocator            // 4
      | aggregate            // 5
      | qualified_expression // 7
;
logical_operator: KW_AND | KW_OR | KW_NAND | KW_NOR | KW_XOR | KW_XNOR;
relational_operator: EQ | NE | LT | CONASGN | GT | GE | EQ_MATCH | NE_MATCH | LT_MATCH | LE_MATCH | GT_MATCH | GE_MATCH;
shift_operator: KW_SLL | KW_SRL | KW_SLA | KW_SRA | KW_ROL | KW_ROR;
adding_operator: PLUS | MINUS | AMPERSAND;
sign: PLUS | MINUS;
multiplying_operator: MUL | DIV | KW_MOD | KW_REM;
miscellaneous_operator: DOUBLESTAR | KW_ABS | KW_NOT;
numeric_literal: // name there means name of unit, but there is ambiguity with any other name
      DECIMAL_LITERAL (name)?
      | BASED_LITERAL (name)?
      | name
;
physical_literal: ( DECIMAL_LITERAL |  BASED_LITERAL )? name;
aggregate:
      LPAREN element_association ( COMMA element_association )* RPAREN
;
element_association:
      ( choices ARROW )? expression
;
choices: choice ( BAR choice )*;
// [rm non determinism]      | identifier
choice:
      discrete_range
      | simple_expression
      | KW_OTHERS
;

qualified_expression:
      type_mark APOSTROPHE aggregate // aggregate can also be LPAREN expression RPAREN
;
allocator:
      KW_NEW ( subtype_indication | qualified_expression )
;
sequence_of_statements:
      ( sequential_statement )*
;
sequential_statement:
      ( label COLON )?
      ( wait_statement
        | assertion_statement
        | report_statement
        | signal_assignment_statement
        | variable_assignment_statement
        | procedure_call_statement
        | if_statement
        | case_statement
        | loop_statement
        | next_statement
        | exit_statement
        | return_statement
        | null_statement
      )
;
wait_statement:
       KW_WAIT ( sensitivity_clause )? ( condition_clause )? ( timeout_clause )? SEMI
;
sensitivity_clause: KW_ON sensitivity_list;
sensitivity_list: name ( COMMA name )*;
condition_clause: KW_UNTIL condition;
condition: expression;
timeout_clause: KW_FOR expression;
assertion_statement: assertion SEMI;
assertion:
      KW_ASSERT condition
          ( KW_REPORT expression )?
          ( KW_SEVERITY expression )?
;
report_statement:
          KW_REPORT expression
              ( KW_SEVERITY expression )? SEMI
;
signal_assignment_statement:
       simple_signal_assignment
      | conditional_signal_assignment
      | selected_signal_assignment
;
simple_signal_assignment:
      simple_waveform_assignment
      | simple_force_assignment
      | simple_release_assignment
;
simple_waveform_assignment:
      target CONASGN ( delay_mechanism )? waveform SEMI
;
simple_force_assignment:
      target CONASGN KW_FORCE ( force_mode )? expression SEMI
;
simple_release_assignment:
      target CONASGN KW_RELEASE ( force_mode )? SEMI
;
force_mode: KW_IN | KW_OUT;
delay_mechanism:
      KW_TRANSPORT
      | ( KW_REJECT expression )? KW_INERTIAL
;
target:
      name
      | aggregate
;
waveform:
      waveform_element ( COMMA waveform_element )*
      | KW_UNAFFECTED
;
waveform_element:
      expression ( KW_AFTER expression )?
      | KW_NULL ( KW_AFTER expression )?
;
conditional_signal_assignment:
      conditional_waveform_assignment
      | conditional_force_assignment
;
conditional_waveform_assignment:
      target CONASGN ( delay_mechanism )? conditional_waveforms SEMI
;
conditional_waveforms:
      waveform KW_WHEN condition
      ( KW_ELSE waveform KW_WHEN condition )*
      ( KW_ELSE waveform | {_input->LA(1) != KW_ELSE}? )
;
conditional_force_assignment:
      target CONASGN KW_FORCE ( force_mode )? conditional_expressions SEMI
;
conditional_expressions:
      expression KW_WHEN condition
      ( KW_ELSE expression KW_WHEN condition )*
      ( KW_ELSE expression | {_input->LA(1) != KW_ELSE}? )
;
selected_signal_assignment:
      selected_waveform_assignment
      | selected_force_assignment
;
selected_waveform_assignment:
      KW_WITH expression KW_SELECT ( QUESTIONMARK )?
          target CONASGN ( delay_mechanism )? selected_waveforms SEMI
;
selected_waveforms:
      waveform KW_WHEN choices (COMMA waveform KW_WHEN choices)*
;
selected_force_assignment:
      KW_WITH expression KW_SELECT ( QUESTIONMARK )?
          target CONASGN KW_FORCE ( force_mode )? selected_expressions SEMI
;
selected_expressions:
      expression KW_WHEN choices ( COMMA 
      expression KW_WHEN choices )*
;
variable_assignment_statement:
     simple_variable_assignment
     | conditional_variable_assignment
     | selected_variable_assignment
;
simple_variable_assignment:
      target VARASGN expression SEMI
;
conditional_variable_assignment:
      target VARASGN conditional_expressions SEMI
;
selected_variable_assignment:
      KW_WITH expression KW_SELECT ( QUESTIONMARK )?
          target VARASGN selected_expressions SEMI
;
procedure_call_statement: procedure_call  SEMI;
procedure_call: name ( association_list )?;
if_statement:
          KW_IF condition KW_THEN
              sequence_of_statements
          ( KW_ELSIF condition KW_THEN
              sequence_of_statements )*
          ( KW_ELSE sequence_of_statements | | {_input->LA(1) != KW_ELSE}? )
          KW_END KW_IF ( label )? SEMI
;
case_statement:
          KW_CASE ( QUESTIONMARK )? expression KW_IS
              case_statement_alternative+
          KW_END KW_CASE ( QUESTIONMARK )? ( label )? SEMI
;
case_statement_alternative:
      KW_WHEN choices ARROW
          sequence_of_statements
;
loop_statement:
          ( iteration_scheme )? KW_LOOP
              sequence_of_statements
          KW_END KW_LOOP ( label )? SEMI
;
iteration_scheme:
      KW_WHILE condition
      | KW_FOR parameter_specification
;
parameter_specification:
      identifier KW_IN discrete_range
;
next_statement:
      KW_NEXT ( label )? ( KW_WHEN condition )? SEMI
;
exit_statement:
      KW_EXIT ( label )? ( KW_WHEN condition )? SEMI
;
return_statement:
      KW_RETURN ( expression )? SEMI
;
null_statement:
      KW_NULL SEMI
;
concurrent_statement_with_optional_label:
      process_statement
      | concurrent_procedure_call_statement
      | concurrent_assertion_statement
      | concurrent_signal_assignment_statement
;
concurrent_statement:
      label COLON (block_statement
                   | component_instantiation_statement
                   | generate_statement
                   | concurrent_statement_with_optional_label)
      | concurrent_statement_with_optional_label
;
block_statement:
     KW_BLOCK ( LPAREN condition RPAREN )? ( KW_IS )?
         block_header
         ( block_declarative_item )*
     KW_BEGIN
         ( concurrent_statement )*
     KW_END KW_BLOCK ( label )? SEMI
;
block_header:
      ( generic_clause
      ( generic_map_aspect SEMI )? )?
      ( port_clause
      ( port_map_aspect SEMI )? )?
;
process_statement:
          ( KW_POSTPONED )? KW_PROCESS ( LPAREN process_sensitivity_list RPAREN )? ( KW_IS )?
              ( process_declarative_item )*
          KW_BEGIN
              ( sequential_statement )*
          KW_END ( KW_POSTPONED )? KW_PROCESS ( label )? SEMI
;
process_sensitivity_list: KW_ALL | sensitivity_list;
process_or_package_declarative_item:
      subprogram_declaration
      | subprogram_instantiation_declaration
      | package_declaration
      | package_instantiation_declaration
      | type_declaration
      | subtype_declaration
      | constant_declaration
      | variable_declaration
      | file_declaration
      | alias_declaration
      | attribute_declaration
      | attribute_specification
      | use_clause
      | group_template_declaration
      | group_declaration
;
process_declarative_item:
      process_or_package_declarative_item
      | subprogram_body
      | package_body
;
concurrent_procedure_call_statement:
      ( KW_POSTPONED )? procedure_call SEMI
;
concurrent_assertion_statement:
      ( KW_POSTPONED )? assertion SEMI
;
// simplified: concurrent_signal_assignment_statement,
//             concurrent_simple_signal_assignment,
//             concurrent_conditional_signal_assignment
concurrent_signal_assignment_statement:
      ( KW_POSTPONED )? (
          concurrent_signal_assignment_any
          | concurrent_selected_signal_assignment
      )
;
concurrent_signal_assignment_any:
      target CONASGN ( KW_GUARDED )? ( delay_mechanism )?
       ( waveform | conditional_waveforms ) SEMI
;

concurrent_selected_signal_assignment:
      KW_WITH expression KW_SELECT ( QUESTIONMARK )?
          target CONASGN ( KW_GUARDED )? ( delay_mechanism )? selected_waveforms SEMI
;
component_instantiation_statement:
      instantiated_unit
          ( generic_map_aspect )?
          ( port_map_aspect )? SEMI
;
instantiated_unit:
    ( KW_COMPONENT )? name
    | KW_ENTITY name ( LPAREN identifier RPAREN )?
    | KW_CONFIGURATION name
;
generate_statement:
    for_generate_statement
    | if_generate_statement
    | case_generate_statement
;
for_generate_statement:
    KW_FOR parameter_specification KW_GENERATE
        generate_statement_body
    KW_END KW_GENERATE ( label )? SEMI
;
if_generate_statement:
    KW_IF ( label COLON )? condition KW_GENERATE
        generate_statement_body
    ( KW_ELSIF ( label COLON )? condition KW_GENERATE
        generate_statement_body )*
    ( KW_ELSE ( label COLON )? KW_GENERATE
        generate_statement_body | {_input->LA(1) != KW_ELSE}? )
    KW_END KW_GENERATE ( label )? SEMI
;
case_generate_statement:
    KW_CASE expression KW_GENERATE
        ( case_generate_alternative )+
    KW_END KW_GENERATE ( label )? SEMI
;
case_generate_alternative:
    KW_WHEN ( label COLON )? choices ARROW
        generate_statement_body_with_begin_end
;
generate_statement_body_with_begin_end:
    ( block_declarative_item*
      KW_BEGIN
        ( concurrent_statement )*
      KW_END ( label )? SEMI
     )
     | ( concurrent_statement )*
;
generate_statement_body:
    ( block_declarative_item*
      KW_BEGIN
        ( concurrent_statement )*
     )
     | ( concurrent_statement )*
;
label: identifier;
use_clause:
    KW_USE selected_name (COMMA selected_name)* SEMI
;
// the start rule
design_file: design_unit* EOF;
design_unit: context_clause library_unit;
library_unit:
    primary_unit
    | secondary_unit
;
primary_unit:
    entity_declaration
    | configuration_declaration
    | package_declaration
    | package_instantiation_declaration
    | context_declaration
;
secondary_unit:
    architecture_body
    | package_body
;
library_clause: KW_LIBRARY logical_name_list SEMI;
logical_name_list: identifier_list;
context_declaration:
    KW_CONTEXT identifier KW_IS
        context_clause
    KW_END ( KW_CONTEXT )? ( identifier )? SEMI
;
context_clause: ( context_item )*;
context_item:
    library_clause
    | use_clause
    | context_reference
;
context_reference:
    KW_CONTEXT selected_name ( COMMA selected_name )* SEMI
;
identifier: BASIC_IDENTIFIER | EXTENDED_IDENTIFIER;
