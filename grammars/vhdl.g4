
/*
 * Grammar extracted from the 2008 standard
 */

grammar vhdl;

PROCESS: P R O C E S S;
CONTEXT: C O N T E X T;
POSTPONED: P O S T P O N E D;
LINKAGE: L I N K A G E;
COMPONENT: C O M P O N E N T;
ABS: A B S;
DEFAULT: D E F A U L T;
UX: U X;
THEN: T H E N;
BLOCK: B L O C K;
REM: R E M;
INERTIAL: I N E R T I A L;
NEXT: N E X T;
ENTITY: E N T I T Y;
ON: O N;
GROUP: G R O U P;
XNOR: X N O R;
FILE: F I L E;
PURE: P U R E;
GUARDED: G U A R D E D;
GENERIC: G E N E R I C;
RANGE: R A N G E;
ELSE: E L S E;
USE: U S E;
SHARED: S H A R E D;
MOD: M O D;
LOOP: L O O P;
RECORD: R E C O R D;
SIGNAL: S I G N A L;
REJECT: R E J E C T;
BEGIN: B E G I N;
SLA: S L A;
DISCONNECT: D I S C O N N E C T;
OF: O F;
PROCEDURE: P R O C E D U R E;
SRL: S R L;
SO: S O;
VUNIT: V U N I T;
ATTRIBUTE: A T T R I B U T E;
VARIABLE: V A R I A B L E;
PROPERTY: P R O P E R T Y;
UNAFFECTED: U N A F F E C T E D;
XOR: X O R;
REGISTER: R E G I S T E R;
SUBTYPE: S U B T Y P E;
UO: U O;
TO: T O;
NEW: N E W;
REPORT: R E P O R T;
CONSTANT: C O N S T A N T;
BUFFER: B U F F E R;
BODY: B O D Y;
AFTER: A F T E R;
TRANSPORT: T R A N S P O R T;
FUNCTION: F U N C T I O N;
END: E N D;
SELECT: S E L E C T;
OR: O R;
LIBRARY: L I B R A R Y;
SX: S X;
ELSIF: E L S I F;
SLL: S L L;
MAP: M A P;
SRA: S R A;
PROTECTED: P R O T E C T E D;
DOWNTO: D O W N T O;
LABEL: L A B E L;
ALL: A L L;
ALIAS: A L I A S;
GENERATE: G E N E R A T E;
NOR: N O R;
IN: I N;
RELEASE: R E L E A S E;
SB: S B;
EXIT: E X I T;
RETURN: R E T U R N;
WITH: W I T H;
UNTIL: U N T I L;
AND: A N D;
INOUT: I N O U T;
WAIT: W A I T;
NAND: N A N D;
ARRAY: A R R A Y;
FORCE: F O R C E;
UB: U B;
WHILE: W H I L E;
IMPURE: I M P U R E;
PACKAGE: P A C K A G E;
UNITS: U N I T S;
ASSERT: A S S E R T;
PARAMETER: P A R A M E T E R;
SEVERITY: S E V E R I T Y;
LITERAL: L I T E R A L;
FOR: F O R;
ROR: R O R;
IF: I F;
OUT: O U T;
ROL: R O L;
IS: I S;
SEQUENCE: S E Q U E N C E;
OTHERS: O T H E R S;
TYPE: T Y P E;
CASE: C A S E;
NOT: N O T;
CONFIGURATION: C O N F I G U R A T I O N;
OPEN: O P E N;
ARCHITECTURE: A R C H I T E C T U R E;
BUS: B U S;
ACCESS: A C C E S S;
WHEN: W H E N;
PORT: P O R T;
NULL_SYM: N U L L;

any_keyword:
    PROCESS
    |CONTEXT
    |POSTPONED
    |LINKAGE
    |COMPONENT
    |ABS
    |DEFAULT
    |UX
    |THEN
    |BLOCK
    |REM
    |INERTIAL
    |NEXT
    |ENTITY
    |ON
    |GROUP
    |XNOR
    |FILE
    |PURE
    |GUARDED
    |GENERIC
    |RANGE
    |ELSE
    |USE
    |SHARED
    |MOD
    |LOOP
    |RECORD
    |SIGNAL
    |REJECT
    |BEGIN
    |SLA
    |DISCONNECT
    |OF
    |PROCEDURE
    |SRL
    |SO
    |VUNIT
    |ATTRIBUTE
    |VARIABLE
    |PROPERTY
    |UNAFFECTED
    |XOR
    |REGISTER
    |SUBTYPE
    |UO
    |TO
    |NEW
    |REPORT
    |CONSTANT
    |BUFFER
    |BODY
    |AFTER
    |TRANSPORT
    |FUNCTION
    |END
    |SELECT
    |OR
    |LIBRARY
    |SX
    |ELSIF
    |SLL
    |MAP
    |SRA
    |PROTECTED
    |DOWNTO
    |LABEL
    |ALL
    |ALIAS
    |GENERATE
    |NOR
    |IN
    |RELEASE
    |SB
    |EXIT
    |RETURN
    |WITH
    |UNTIL
    |AND
    |INOUT
    |WAIT
    |NAND
    |ARRAY
    |FORCE
    |UB
    |WHILE
    |IMPURE
    |PACKAGE
    |UNITS
    |ASSERT
    |PARAMETER
    |SEVERITY
    |LITERAL
    |FOR
    |ROR
    |IF
    |OUT
    |ROL
    |IS
    |SEQUENCE
    |OTHERS
    |TYPE
    |CASE
    |NOT
    |CONFIGURATION
    |OPEN
    |ARCHITECTURE
    |BUS
    |ACCESS
    |WHEN
    |PORT
    |NULL_SYM
;


// case insensitive chars
fragment A:('a'|'A');
fragment B:('b'|'B');
fragment C:('c'|'C');
fragment D:('d'|'D');
fragment E:('e'|'E');
fragment F:('f'|'F');
fragment G:('g'|'G');
fragment H:('h'|'H');
fragment I:('i'|'I');
fragment J:('j'|'J');
fragment K:('k'|'K');
fragment L:('l'|'L');
fragment M:('m'|'M');
fragment N:('n'|'N');
fragment O:('o'|'O');
fragment P:('p'|'P');
fragment Q:('q'|'Q');
fragment R:('r'|'R');
fragment S:('s'|'S');
fragment T:('t'|'T');
fragment U:('u'|'U');
fragment V:('v'|'V');
fragment W:('w'|'W');
fragment X:('x'|'X');
fragment Y:('y'|'Y');
fragment Z:('z'|'Z');


fragment EXTENDED_DIGIT: DIGIT | LETTER;
fragment BASE_SPECIFIER: B | O | X | UB | UO | UX | SB | SO | SX | D;
// [note] GRAPHIC_CHARACTER group wa reworked in order to resolve Ambiguity
fragment GRAPHIC_CHARACTER:
        SPECIAL_CHARACTER
      | LETTER_OR_DIGIT
      | OTHER_SPECIAL_CHARACTER
;
// [TODO] DBLQUOTE |
fragment SPECIAL_CHARACTER:
    HASHTAG | AMPERSAND | APOSTROPHE | LPAREN | RPAREN | MUL | PLUS
  | COMMA | MINUS | DOT | DIV | COLON | SEMI | LT | EQ
  | GT | QUESTIONMARK | AT | '[' | ']' | UNDERSCORE | GRAVE_ACCENT | BAR;

fragment OTHER_SPECIAL_CHARACTER:
    '!' | '$' | '%' | UP | '{' | '}' | '~'
  | SPACE_CHARACTER | 'Ў' | 'ў' | 'Ј' | '¤' | 'Ґ' | '¦' | '§'
  | 'Ё' | '©' | 'Є' | '«' | '¬' | '­' | '®' | 'Ї'
  | '°' | '±' | 'І' | 'і' | 'ґ' | 'µ' | '¶' | '·'
  | 'ё' | '№' | 'є' | '»' | 'ј' | 'Ѕ' | 'ѕ' | 'ї'
  | 'А' | 'Б' | 'В' | 'Г' | 'Д' | 'Е' | 'Ж' | 'З'
  | 'И' | 'Й' | 'К' | 'Л' | 'М' | 'Н' | 'О' | 'П'
  | 'Р' | 'С' | 'Т' | 'У' | 'Ф' | 'Х' | 'Ц' | 'Ч'
  | 'Ш' | 'Щ' | 'Ъ' | 'Ы' | 'Ь' | 'Э' | 'Ю' | 'Я'
  | 'а' | 'б' | 'в' | 'г' | 'д' | 'е' | 'ж' | 'з'
  | 'и' | 'й' | 'к' | 'л' | 'м' | 'н' | 'о' | 'п'
  | 'р' | 'с' | 'т' | 'у' | 'ф' | 'х' | 'ц' | 'ч'
  | 'ш' | 'щ' | 'ъ' | 'ы' | 'ь' | 'э' | 'ю' | 'я'
  ;

fragment LETTER_OR_DIGIT: LETTER | DIGIT;
fragment LETTER: 'A'..'Z' | 'a'..'z';


// name:
//       simple_name
//       | operator_symbol
//       | character_literal
//       | selected_name
//       | indexed_name
//       | slice_name
//       | attribute_name
//       | external_name
// ;
// prefix:
//       name
//       | function_call
// ;
// indexed_name: prefix LPAREN expression ( COMMA expression )* RPAREN;
// slice_name: prefix LPAREN discrete_range RPAREN;
// attribute_name:
//       prefix ( signature )? APOSTROPHE attribute_designator ( LPAREN expression RPAREN )?
// ;
//
// changed to avoid left-recursion to name (from selected_name, indexed_name,
// slice_name, and attribute_name, respectively)
// (2.2.2004, e.f.)
name:
      name_part ( DOT name_part)*
      | external_name
;

name_part:
      selected_name (name_part_specificator)*
;

name_part_specificator:
      name_attribute_part
      | LPAREN (name_function_call_or_indexed_part | name_slice_part) RPAREN
;

name_attribute_part:
      APOSTROPHE attribute_designator ( expression ( COMMA expression )* )?
;

name_function_call_or_indexed_part:  actual_parameter_part?;

name_slice_part: explicit_range ( COMMA explicit_range )*;

explicit_range:
      simple_expression direction simple_expression
;

selected_name:
      identifier (DOT suffix)*
;
entity_declaration:
      ENTITY identifier IS
          entity_header
          entity_declarative_part
      ( BEGIN
          entity_statement_part )?
      END ( ENTITY )? ( simple_name )? SEMI
;
entity_header:
      ( generic_clause )?
      ( port_clause )?
;
entity_declarative_part:
      ( entity_declarative_item )*
;
entity_declarative_item:
      subprogram_declaration
      | subprogram_body
      | subprogram_instantiation_declaration
      | package_declaration
      | package_body
      | package_instantiation_declaration
      | type_declaration
      | subtype_declaration
      | constant_declaration
      | signal_declaration
      | variable_declaration
      | file_declaration
      | alias_declaration
;
entity_statement_part:
      ( entity_statement )*
;
entity_statement:
      concurrent_assertion_statement
      | concurrent_procedure_call_statement
;
architecture_body:
      ARCHITECTURE identifier OF name IS
          architecture_declarative_part
      BEGIN
          architecture_statement_part
      END ( ARCHITECTURE )? ( simple_name )? SEMI
;
architecture_declarative_part:
      ( block_declarative_item )*
;
block_declarative_item:
      subprogram_declaration
      | subprogram_body
      | subprogram_instantiation_declaration
      | package_declaration
      | package_body
      | package_instantiation_declaration
      | type_declaration
      | subtype_declaration
      | constant_declaration
      | signal_declaration
      | variable_declaration
      | file_declaration
      | alias_declaration
      | component_declaration
      | attribute_declaration
      | attribute_specification
      | configuration_specification
      | disconnection_specification
      | use_clause
      | group_template_declaration
      | group_declaration
     ;
architecture_statement_part:
      ( concurrent_statement )*
;
configuration_declaration:
      CONFIGURATION identifier OF name IS
          configuration_declarative_part
          ( verification_unit_binding_indication SEMI )*
          block_configuration
      END ( CONFIGURATION )? ( simple_name )? SEMI
;
configuration_declarative_part:
      ( configuration_declarative_item )*
;
configuration_declarative_item:
      use_clause
      | attribute_specification
      | group_declaration
;
block_configuration:
      FOR block_specification
          ( use_clause )*
          ( configuration_item )*
      END FOR SEMI
;
block_specification:
      name
      | label
      | label ( LPAREN generate_specification RPAREN )?
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
      FOR component_specification
          ( binding_indication SEMI )?
          ( verification_unit_binding_indication SEMI )*
          ( block_configuration )?
      END FOR SEMI
;
subprogram_declaration:
      subprogram_specification SEMI
;
subprogram_specification:
      procedure_specification | function_specification
;
procedure_specification:
      PROCEDURE designator
          subprogram_header
          ( ( PARAMETER )? LPAREN formal_parameter_list RPAREN )?
;
function_specification:
      ( PURE IMPURE )? FUNCTION designator
          subprogram_header
          ( ( PARAMETER )? LPAREN formal_parameter_list RPAREN )? RETURN type_mark
;
subprogram_header:
      ( GENERIC LPAREN generic_list RPAREN
      ( generic_map_aspect )? )?
;
designator: identifier | operator_symbol;
operator_symbol: STRING_LITERAL;
formal_parameter_list: interface_list;
subprogram_body:
      subprogram_specification IS
          subprogram_declarative_part
      BEGIN
          subprogram_statement_part
      END ( subprogram_kind )? ( designator )? SEMI
;
subprogram_declarative_part:
      ( subprogram_declarative_item )*
;
subprogram_declarative_item:
      subprogram_declaration
      | subprogram_body
      | subprogram_instantiation_declaration
      | package_declaration
      | package_body
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
subprogram_statement_part:
      ( sequential_statement )*
;
subprogram_kind: PROCEDURE | FUNCTION;
subprogram_instantiation_declaration:
      subprogram_kind designator IS NEW name ( signature )?
          ( generic_map_aspect )? SEMI
;
signature: type_mark ( COMMA type_mark )*
      | type_mark ( COMMA type_mark )* RETURN type_mark
      | RETURN type_mark
;
package_declaration:
      PACKAGE identifier IS
          package_header
          package_declarative_part
      END ( PACKAGE )? ( simple_name )? SEMI
;
package_header:
      ( generic_clause
      ( generic_map_aspect SEMI )? )?
;
package_declarative_part:
      ( package_declarative_item )*
;
package_declarative_item:
      subprogram_declaration
      | subprogram_instantiation_declaration
      | package_declaration
      | package_instantiation_declaration
      | type_declaration
      | subtype_declaration
      | constant_declaration
      | signal_declaration
      | variable_declaration
      | file_declaration
      | alias_declaration
      | component_declaration
      | attribute_declaration
      | attribute_specification
      | disconnection_specification
      | use_clause
      | group_template_declaration
      | group_declaration
     ;
package_body:
      PACKAGE BODY simple_name IS
          package_body_declarative_part
      END ( PACKAGE BODY )? ( simple_name )? SEMI
;
package_body_declarative_part:
      ( package_body_declarative_item )*
;
package_body_declarative_item:
      subprogram_declaration
      | subprogram_body
      | subprogram_instantiation_declaration
      | package_declaration
      | package_body
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
package_instantiation_declaration:
      PACKAGE identifier IS NEW name
          ( generic_map_aspect )? SEMI
;
scalar_type_definition:
      enumeration_type_definition
      | integer_type_definition
      | floating_type_definition
      | physical_type_definition
;
range_constraint: RANGE range;
range:
      attribute_name
      | simple_expression direction simple_expression
;
direction: TO | DOWNTO;
enumeration_type_definition:
      LPAREN enumeration_literal ( COMMA enumeration_literal )* RPAREN
;
enumeration_literal: identifier | CHARACTER_LITERAL;
integer_type_definition: range_constraint;
physical_type_definition:
      range_constraint
          UNITS
              primary_unit_declaration
              ( secondary_unit_declaration )*
          END UNITS ( simple_name )?
;
primary_unit_declaration: identifier SEMI;
secondary_unit_declaration: identifier EQ physical_literal SEMI;
physical_literal: ( abstract_literal )? name;
floating_type_definition: range_constraint;
composite_type_definition:
      array_type_definition
      | record_type_definition
;
array_type_definition:
      unbounded_array_definition | constrained_array_definition
;
unbounded_array_definition:
      ARRAY LPAREN index_subtype_definition ( COMMA index_subtype_definition )* RPAREN
          OF subtype_indication
;
constrained_array_definition:
      ARRAY index_constraint OF subtype_indication
;
index_subtype_definition: type_mark RANGE BOX;
array_constraint:
      index_constraint ( array_element_constraint )?
      | LPAREN OPEN RPAREN ( array_element_constraint )?
;
array_element_constraint: element_constraint;
index_constraint: LPAREN discrete_range ( COMMA discrete_range )* RPAREN;
discrete_range: subtype_indication | range;
record_type_definition:
      RECORD
          element_declaration
          ( element_declaration )*
      END RECORD ( simple_name )?
;
element_declaration:
      identifier_list COLON element_subtype_definition SEMI
;
identifier_list: identifier ( COMMA identifier )*;
element_subtype_definition: subtype_indication;
record_constraint:
      LPAREN record_element_constraint ( COMMA record_element_constraint )* RPAREN
;
record_element_constraint: simple_name element_constraint;
access_type_definition: ACCESS subtype_indication;
incomplete_type_declaration: TYPE identifier SEMI;
file_type_definition: FILE OF type_mark;
protected_type_definition:
      protected_type_declaration
      | protected_type_body
;
protected_type_declaration:
      PROTECTED
          protected_type_declarative_part
      END PROTECTED ( simple_name )?
;
protected_type_declarative_part:
      ( protected_type_declarative_item )*
;
protected_type_declarative_item:
      subprogram_declaration
      | subprogram_instantiation_declaration
      | attribute_specification
      | use_clause
;
protected_type_body:
      PROTECTED BODY
          protected_type_body_declarative_part
      END PROTECTED BODY ( simple_name )?
;
protected_type_body_declarative_part:
      ( protected_type_body_declarative_item )*
;
protected_type_body_declarative_item:
      subprogram_declaration
      | subprogram_body
      | subprogram_instantiation_declaration
      | package_declaration
      | package_body
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
type_declaration:
      full_type_declaration
      | incomplete_type_declaration
;
full_type_declaration:
      TYPE identifier IS type_definition SEMI
;
type_definition:
      scalar_type_definition
      | composite_type_definition
      | access_type_definition
      | file_type_definition
      | protected_type_definition
;
subtype_declaration:
      SUBTYPE identifier IS subtype_indication SEMI
;
subtype_indication:
      ( resolution_indication )? type_mark ( constraint )?
;
resolution_indication:
      name | LPAREN element_resolution RPAREN
;
element_resolution: array_element_resolution | record_resolution;
array_element_resolution: resolution_indication;
record_resolution: record_element_resolution ( COMMA record_element_resolution )*;
record_element_resolution: simple_name resolution_indication;
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
      CONSTANT identifier_list COLON subtype_indication ( VARASGN expression )? SEMI
;
signal_declaration:
      SIGNAL identifier_list COLON subtype_indication ( signal_kind )? ( VARASGN expression )? SEMI
;
signal_kind: REGISTER | BUS;
variable_declaration:
      ( SHARED )? VARIABLE identifier_list COLON subtype_indication ( VARASGN expression )? SEMI
;
file_declaration:
      FILE identifier_list COLON subtype_indication ( file_open_information )? SEMI
;
file_open_information: ( OPEN expression )? IS file_logical_name;
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
      CONSTANT identifier_list COLON ( IN )? subtype_indication ( VARASGN expression )?
;
interface_signal_declaration:
      ( SIGNAL )? identifier_list COLON ( signal_mode )? subtype_indication ( BUS )? ( VARASGN expression )?
;
interface_variable_declaration:
      VARIABLE identifier_list COLON ( signal_mode )? subtype_indication ( VARASGN expression )?
;
interface_file_declaration:
      FILE identifier_list COLON subtype_indication
;
signal_mode: IN | OUT | INOUT | BUFFER | LINKAGE;
interface_type_declaration:
      interface_incomplete_type_declaration
;
interface_incomplete_type_declaration: TYPE identifier;
interface_subprogram_declaration:
      interface_subprogram_specification ( IS interface_subprogram_default )?
;
interface_subprogram_specification:
      interface_procedure_specification | interface_function_specification
;
interface_procedure_specification:
      PROCEDURE designator
          ( ( PARAMETER )? LPAREN formal_parameter_list RPAREN )?
;
interface_function_specification:
      ( PURE IMPURE )? FUNCTION designator
          ( ( PARAMETER )? LPAREN formal_parameter_list RPAREN )? RETURN type_mark
;
interface_subprogram_default: name | BOX;
interface_package_declaration:
      PACKAGE identifier IS NEW name interface_package_generic_map_aspect
;
interface_package_generic_map_aspect:
      generic_map_aspect
      | GENERIC MAP LPAREN BOX RPAREN
      | GENERIC MAP LPAREN DEFAULT RPAREN
;
interface_list:
      interface_element ( SEMI interface_element )*
;
interface_element: interface_declaration;
generic_clause:
      GENERIC LPAREN generic_list RPAREN SEMI
;
generic_list: interface_list;
port_clause:
      PORT LPAREN port_list RPAREN SEMI
;
port_list: interface_list;
association_list:
      association_element ( COMMA association_element )*
;
association_element:
      ( formal_part ARROW )? actual_part
;
formal_part:
      formal_designator
      | name LPAREN formal_designator RPAREN
      | type_mark LPAREN formal_designator RPAREN
;
formal_designator:
      name
;
actual_part:
      name LPAREN actual_designator RPAREN
      | actual_designator
;
actual_designator:
      ( INERTIAL )? expression
      | subtype_indication
      | OPEN
;
generic_map_aspect:
      GENERIC MAP LPAREN association_list RPAREN
;
port_map_aspect:
      PORT MAP LPAREN association_list RPAREN
;
alias_declaration:
      ALIAS alias_designator ( COLON subtype_indication )? IS name ( signature )? SEMI
;
alias_designator: identifier | CHARACTER_LITERAL | operator_symbol;
attribute_declaration:
      ATTRIBUTE identifier COLON type_mark SEMI
;
component_declaration:
      COMPONENT identifier ( IS )?
          ( generic_clause )?
          ( port_clause )?
      END COMPONENT ( simple_name )? SEMI
;
group_template_declaration:
      GROUP identifier IS LPAREN entity_class_entry_list RPAREN SEMI
;
entity_class_entry_list:
      entity_class_entry ( COMMA entity_class_entry )*
;
entity_class_entry: entity_class ( BOX )?;
group_declaration:
      GROUP identifier COLON name LPAREN group_constituent_list RPAREN SEMI
;
group_constituent_list: group_constituent ( COMMA group_constituent )*;
group_constituent: name | CHARACTER_LITERAL;
attribute_specification:
      ATTRIBUTE attribute_designator OF entity_specification IS expression SEMI
;
entity_specification:
      entity_name_list COLON entity_class
;
entity_class:
      ENTITY
      | ARCHITECTURE
      | CONFIGURATION
      | PROCEDURE
      | FUNCTION
      | PACKAGE
      | TYPE
      | SUBTYPE
      | CONSTANT
      | SIGNAL
      | VARIABLE
      | COMPONENT
      | LABEL
      | LITERAL
      | UNITS
      | GROUP
      | FILE
      | PROPERTY
      | SEQUENCE
;
entity_name_list:
      entity_designator ( COMMA entity_designator )*
      | OTHERS
      | ALL
;
entity_designator: entity_tag ( signature )?;
entity_tag: simple_name | CHARACTER_LITERAL | operator_symbol;
configuration_specification:
      simple_configuration_specification
      | compound_configuration_specification
;
simple_configuration_specification:
      FOR component_specification binding_indication SEMI
      ( END FOR SEMI )?
;
compound_configuration_specification:
      FOR component_specification binding_indication SEMI
          verification_unit_binding_indication SEMI
          ( verification_unit_binding_indication SEMI )*
      END FOR SEMI
;
component_specification:
      instantiation_list COLON name
;
instantiation_list:
      label ( COMMA label )*
      | OTHERS
      | ALL
;
binding_indication:
      ( USE entity_aspect )?
      ( generic_map_aspect )?
      ( port_map_aspect )?
;
entity_aspect:
      ENTITY name ( LPAREN identifier RPAREN )?
      | CONFIGURATION name
      | OPEN
;
verification_unit_binding_indication:
      USE VUNIT verification_unit_list
;
verification_unit_list: name ( COMMA name )*;
disconnection_specification:
      DISCONNECT guarded_signal_specification AFTER expression SEMI
;
guarded_signal_specification:
      signal_list COLON type_mark
;
signal_list:
      name ( COMMA name )*
      | OTHERS
      | ALL
;
prefix:
      name
      | function_call
;
simple_name: identifier;
suffix:
      simple_name
      | CHARACTER_LITERAL
      | operator_symbol
      | ALL
;
attribute_name:
      prefix ( signature )? APOSTROPHE attribute_designator ( LPAREN expression RPAREN )?
;
attribute_designator: simple_name | any_keyword;
external_name:
      SHIFT_LEFT (VARIABLE | CONSTANT | SIGNAL) external_pathname COLON subtype_indication SHIFT_RIGHT
;
external_pathname:
      package_pathname
      | absolute_pathname
      | relative_pathname
;
package_pathname:
      AT logical_name DOT simple_name DOT ( simple_name DOT )* simple_name
;
absolute_pathname: DOT partial_pathname;
relative_pathname: ( UP DOT )* partial_pathname;
partial_pathname: ( pathname_element DOT )* simple_name;
pathname_element:
      simple_name
      | label
      | label
      | label ( LPAREN expression RPAREN )?
      | simple_name
;
expression:
      condition_operator primary
      | logical_expression
;
logical_expression:
      relation ( logical_operator relation )*
;
relation:
      shift_expression ( relational_operator shift_expression )?
;
shift_expression:
      simple_expression ( shift_operator simple_expression )?
;
simple_expression:
      ( sign )? term ( adding_operator term )*
;
term:
      factor ( multiplying_operator factor )*
;
factor:
      primary ( DOUBLESTAR primary )?
      | ABS primary
      | NOT primary
      | logical_operator primary
;
primary:
        literal
      | LPAREN expression RPAREN
      | allocator
      | aggregate
      | function_call
      | type_conversion
      | qualified_expression
      | name
;
condition_operator: COND_OP;
logical_operator: AND | OR | NAND | NOR | XOR | XNOR;
relational_operator: EQ | NEQ | LT | CONASGN | GT | GE | MATCH_EQ | MATCH_NEQ | MATCH_LT | MATCH_LE | MATCH_GT | MATCH_GE;
shift_operator: SLL | SRL | SLA | SRA | ROL | ROR;
adding_operator: PLUS | MINUS | AMPERSAND;
sign: PLUS | MINUS;
multiplying_operator: MUL | DIV | MOD | REM;
miscellaneous_operator: DOUBLESTAR | ABS | NOT;
literal:
      numeric_literal
      | enumeration_literal
      | STRING_LITERAL
      | BIT_STRING_LITERAL
      | NULL_SYM
;
numeric_literal:
      abstract_literal
      | physical_literal
;
aggregate:
      LPAREN element_association ( COMMA element_association )* RPAREN
;
element_association:
      ( choices ARROW )? expression
;
choices: ( choice )+;
// [rm non determinism]      | simple_name
choice:
      discrete_range
      | simple_expression
      | OTHERS
;
function_call:
      name ( LPAREN actual_parameter_part RPAREN )?
;
actual_parameter_part: association_list;
qualified_expression:
      type_mark APOSTROPHE
      	(LPAREN expression RPAREN)
      	| aggregate
;
type_conversion: type_mark LPAREN expression RPAREN;
allocator:
      NEW subtype_indication
      | NEW qualified_expression
;
sequence_of_statements:
      ( sequential_statement )*
;
sequential_statement:
      wait_statement
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
;
wait_statement:
      ( label COLON )? WAIT ( sensitivity_clause )? ( condition_clause )? ( timeout_clause )? SEMI
;
sensitivity_clause: ON sensitivity_list;
sensitivity_list: name ( COMMA name )*;
condition_clause: UNTIL condition;
condition: expression;
timeout_clause: FOR expression;
assertion_statement: ( label COLON )? assertion SEMI;
assertion:
      ASSERT condition
          ( REPORT expression )?
          ( SEVERITY expression )?
;
report_statement:
      ( label COLON )?
          REPORT expression
              ( SEVERITY expression )? SEMI
;
signal_assignment_statement:
      ( label COLON )? simple_signal_assignment
      | ( label COLON )? conditional_signal_assignment
      | ( label COLON )? selected_signal_assignment
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
      target CONASGN FORCE ( force_mode )? expression SEMI
;
simple_release_assignment:
      target CONASGN RELEASE ( force_mode )? SEMI
;
force_mode: IN | OUT;
delay_mechanism:
      TRANSPORT
      | ( REJECT expression )? INERTIAL
;
target:
      name
      | aggregate
;
waveform:
      waveform_element ( COMMA waveform_element )*
      | UNAFFECTED
;
waveform_element:
      expression ( AFTER expression )?
      | NULL_SYM ( AFTER expression )?
;
conditional_signal_assignment:
      conditional_waveform_assignment
      | conditional_force_assignment
;
conditional_waveform_assignment:
      target CONASGN ( delay_mechanism )? conditional_waveforms SEMI
;
conditional_waveforms:
      waveform WHEN condition
      ( ELSE waveform WHEN condition )*
      ( ELSE waveform )?
;
conditional_force_assignment:
      target CONASGN FORCE ( force_mode )? conditional_expressions SEMI
;
conditional_expressions:
      expression WHEN condition
      ( ELSE expression WHEN condition )*
      ( ELSE expression )?
;
selected_signal_assignment:
      selected_waveform_assignment
      | selected_force_assignment
;
selected_waveform_assignment:
      WITH expression SELECT ( QUESTIONMARK )?
          target CONASGN ( delay_mechanism )? selected_waveforms SEMI
;
selected_waveforms:
      ( waveform WHEN choices COMMA )*
      waveform WHEN choices
;
selected_force_assignment:
      WITH expression SELECT ( QUESTIONMARK )?
          target CONASGN FORCE ( force_mode )? selected_expressions SEMI
;
selected_expressions:
      ( expression WHEN choices COMMA )*
      expression WHEN choices
;
variable_assignment_statement:
      ( label COLON )? (
          simple_variable_assignment
	      | conditional_variable_assignment
	      | selected_variable_assignment
      )
;
simple_variable_assignment:
      target VARASGN expression SEMI
;
conditional_variable_assignment:
      target VARASGN conditional_expressions SEMI
;
selected_variable_assignment:
      WITH expression SELECT ( QUESTIONMARK )?
          target VARASGN selected_expressions SEMI
;
procedure_call_statement: ( label COLON )? procedure_call SEMI;
//  ( LPAREN actual_parameter_part RPAREN )? can be part of the "name"
procedure_call: name;
if_statement:
      ( label COLON )?
          IF condition THEN
              sequence_of_statements
          ( ELSIF condition THEN
              sequence_of_statements )*
          ( ELSE
              sequence_of_statements )?
          END IF ( label )? SEMI
;
case_statement:
      ( label COLON )?
          CASE ( QUESTIONMARK )? expression IS
              case_statement_alternative
              ( case_statement_alternative )*
          END CASE ( QUESTIONMARK )? ( label )? SEMI
;
case_statement_alternative:
      WHEN choices ARROW
          sequence_of_statements
;
loop_statement:
      ( label COLON )?
          ( iteration_scheme )? LOOP
              sequence_of_statements
          END LOOP ( label )? SEMI
;
iteration_scheme:
      WHILE condition
      | FOR parameter_specification
;
parameter_specification:
      identifier IN discrete_range
;
next_statement:
      ( label COLON )? NEXT ( label )? ( WHEN condition )? SEMI
;
exit_statement:
      ( label COLON )? EXIT ( label )? ( WHEN condition )? SEMI
;
return_statement:
      ( label COLON )? RETURN ( expression )? SEMI
;
null_statement:
      ( label COLON )? NULL_SYM SEMI
;
concurrent_statement:
      block_statement
      | process_statement
      | concurrent_procedure_call_statement
      | concurrent_assertion_statement
      | concurrent_signal_assignment_statement
      | component_instantiation_statement
      | generate_statement
     ;
block_statement:
      label COLON
          BLOCK ( LPAREN condition RPAREN )? ( IS )?
              block_header
              block_declarative_part
          BEGIN
              block_statement_part
          END BLOCK ( label )? SEMI
;
block_header:
      ( generic_clause
      ( generic_map_aspect SEMI )? )?
      ( port_clause
      ( port_map_aspect SEMI )? )?
;
block_declarative_part:
      ( block_declarative_item )*
;
block_statement_part:
      ( concurrent_statement )*
;
process_statement:
      ( label COLON )?
          ( POSTPONED )? PROCESS ( LPAREN process_sensitivity_list RPAREN )? ( IS )?
              process_declarative_part
          BEGIN
              process_statement_part
          END ( POSTPONED )? PROCESS ( label )? SEMI
;
process_sensitivity_list: ALL | sensitivity_list;
process_declarative_part:
      ( process_declarative_item )*
;
process_declarative_item:
      subprogram_declaration
      | subprogram_body
      | subprogram_instantiation_declaration
      | package_declaration
      | package_body
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
process_statement_part:
      ( sequential_statement )*
;
concurrent_procedure_call_statement:
      ( label COLON )? ( POSTPONED )? procedure_call SEMI
;
concurrent_assertion_statement:
      ( label COLON )? ( POSTPONED )? assertion SEMI
;
// simplified: concurrent_signal_assignment_statement,
//             concurrent_simple_signal_assignment,
//             concurrent_conditional_signal_assignment
concurrent_signal_assignment_statement:
      ( label COLON )? ( POSTPONED )? (
          concurrent_signal_assignment_any
	      | concurrent_selected_signal_assignment
      )
;
concurrent_signal_assignment_any:
	  target CONASGN ( GUARDED )? ( delay_mechanism )?
 	  ( waveform | conditional_waveforms ) SEMI
;

concurrent_selected_signal_assignment:
      WITH expression SELECT ( QUESTIONMARK )?
          target CONASGN ( GUARDED )? ( delay_mechanism )? selected_waveforms SEMI
;
component_instantiation_statement:
      label COLON
          instantiated_unit
              ( generic_map_aspect )?
              ( port_map_aspect )? SEMI
;
instantiated_unit:
      ( COMPONENT )? name
      | ENTITY name ( LPAREN identifier RPAREN )?
      | CONFIGURATION name
;
generate_statement:
      for_generate_statement
      | if_generate_statement
      | case_generate_statement
;
for_generate_statement:
      label COLON
          FOR parameter_specification GENERATE
              generate_statement_body
          END GENERATE ( label )? SEMI
;
if_generate_statement:
      label COLON
          IF ( label COLON )? condition GENERATE
              generate_statement_body
          ( ELSIF ( label COLON )? condition GENERATE
              generate_statement_body )*
          ( ELSE ( label COLON )? GENERATE
              generate_statement_body )?
          END GENERATE ( label )? SEMI
;
case_generate_statement:
      label COLON
          CASE expression GENERATE
              case_generate_alternative
              ( case_generate_alternative )*
          END GENERATE ( label )? SEMI
;
case_generate_alternative:
      WHEN ( label COLON )? choices ARROW
          generate_statement_body
;
generate_statement_body: ( block_declarative_part
      BEGIN )?
      ( concurrent_statement )*
      ( END ( label )? SEMI )?
;
label: identifier;
// only one selected_name as selected_name can contain "." and previous expr was uselless
use_clause:
      USE selected_name SEMI
;
design_file: design_unit ( design_unit )*;
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
library_clause: LIBRARY logical_name_list SEMI;
logical_name_list: logical_name ( COMMA logical_name )*;
logical_name: identifier;
context_declaration:
      CONTEXT identifier IS
          context_clause
      END ( CONTEXT )? ( simple_name )? SEMI
;
context_clause: ( context_item )*;
context_item:
      library_clause
      | use_clause
      | context_reference
;
context_reference:
      CONTEXT selected_name ( COMMA selected_name )* SEMI
;






identifier: BASIC_IDENTIFIER | EXTENDED_IDENTIFIER;
BASIC_IDENTIFIER:
      LETTER ( ( UNDERSCORE )? LETTER_OR_DIGIT )*
;
EXTENDED_IDENTIFIER:
      BACKSLASH (GRAPHIC_CHARACTER)+ BACKSLASH
;
abstract_literal: DECIMAL_LITERAL | based_literal;
DECIMAL_LITERAL: INTEGER ( DOT INTEGER )? ( EXPONENT )?;
INTEGER: DIGIT ( ( UNDERSCORE )? DIGIT )*;
EXPONENT: E ( PLUS )? INTEGER | E MINUS INTEGER;
based_literal:
      BASE HASHTAG BASED_INTEGER ( DOT BASED_INTEGER )? HASHTAG ( EXPONENT )?
;
BASE: INTEGER;
BASED_INTEGER:
      EXTENDED_DIGIT ( ( UNDERSCORE )? EXTENDED_DIGIT )*
;
CHARACTER_LITERAL: APOSTROPHE GRAPHIC_CHARACTER APOSTROPHE;
STRING_LITERAL: DBLQUOTE (GRAPHIC_CHARACTER)* DBLQUOTE;
BIT_STRING_LITERAL: ( INTEGER )? BASE_SPECIFIER DBLQUOTE (
   // BIT_VALUE
   GRAPHIC_CHARACTER ( ( UNDERSCORE )? GRAPHIC_CHARACTER )*
   )? DBLQUOTE;
// [TODO] tool_directive removed

COMMENT: '--' ( ~'\n' )* -> channel(HIDDEN);
TAB: ( '\t' )+ -> skip;
SPACE: ( SPACE_CHARACTER )+ -> skip;
NEWLINE: '\n' -> skip;
CR: '\r' -> skip;

SPACE_CHARACTER: ' ';
DBLQUOTE: '"';
UNDERSCORE: '_';
DIGIT:  '0'..'9';
SEMI: ';';
LPAREN: '(';
RPAREN: ')';
APOSTROPHE: '\'';
SHIFT_LEFT: '<<';
SHIFT_RIGHT: '>>';
AT: '@';
HASHTAG: '#';
COMMA: ',';
DOT: '.';
QUESTIONMARK: '?';
COLON: ':';
EQ: '=';
NEQ: '/=';
LT: '<';
GT: '>';
GE: '>=';
MATCH_EQ: '?=';
MATCH_NEQ: '?/=';
MATCH_LT: '?<';
MATCH_LE: '?<=';
MATCH_GT: '?>';
MATCH_GE: '?>=';
PLUS: '+';
MINUS: '-';
AMPERSAND: '&';
BAR: '|';
BACKSLASH: '\\';
MUL: '*';
DIV: '/';
DOUBLESTAR: '**';
CONASGN: '<=';
GRAVE_ACCENT: '`';
UP: '^';
VARASGN: ':=';
BOX: '<>';
ARROW: '=>';
COND_OP: '?' '?';


