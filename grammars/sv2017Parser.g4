parser grammar sv2017Parser;
options { tokenVocab=sv2017Lexer; }

/*
 * IEEE1800-2017 grammar optimized for performance in the cost of allowing some ivalid syntax.
 * (= const/non-const is not checked, instance variants are same rule and ansi/non-ansi syntax can be mixed)
 * @note Thanks to lexer configuration abilities this grammar can be runtime configured to parse any previous
 *       SystemVerilog standard.  
 *
 * This parser grammar is nearly target language independent. You have to replace "_input->LA".
 * (e.g. to "_input.LA" for Java/Python)
 */
 
/**********************************************************************************************************************/
/* The start rule */
source_text: ( timeunits_declaration )? ( description )* EOF;
description:
   module_declaration
   | udp_declaration
   | interface_declaration
   | program_declaration
   | package_declaration
   | ( attribute_instance )* ( package_item | bind_directive )
   | config_declaration
;
/******************************************** token groups ************************************************************/
assignment_operator:
   ASSIGN
   | PLUS_ASSIGN
   | MINUS_ASSIGN
   | MUL_ASSIGN
   | DIV_ASSIGN
   | MOD_ASSIGN
   | AND_ASSIGN
   | OR_ASSIGN
   | XOR_ASSIGN
   | SHIFT_LEFT_ASSIGN
   | SHIFT_RIGHT_ASSIGN
   | ARITH_SHIFT_LEFT_ASSIGN
   | ARITH_SHIFT_RIGHT_ASSIGN
;
edge_identifier:
   KW_POSEDGE
   | KW_NEGEDGE
   | KW_EDGE
;
identifier:
    C_IDENTIFIER
    | SIMPLE_IDENTIFIER
    | ESCAPED_IDENTIFIER
    | KW_SAMPLE
    | KW_RANDOMIZE
    | KW_TYPE_OPTION
    | KW_OPTION
    | KW_STD
;
integer_type:
    integer_vector_type
    | integer_atom_type
;
integer_atom_type:
    KW_BYTE
    | KW_SHORTINT
    | KW_INT
    | KW_LONGINT
    | KW_INTEGER
    | KW_TIME
;
integer_vector_type:
    KW_BIT
    | KW_LOGIC
    | KW_REG
;
non_integer_type:
    KW_SHORTREAL
    | KW_REAL
    | KW_REALTIME
;
net_type:
    KW_SUPPLY0
    | KW_SUPPLY1
    | KW_TRI
    | KW_TRIAND
    | KW_TRIOR
    | KW_TRIREG
    | KW_TRI0
    | KW_TRI1
    | KW_UWIRE
    | KW_WIRE
    | KW_WAND
    | KW_WOR
;
unary_module_path_operator:
    NOT
    | NEG
    | AMPERSAND
    | NAND
    | BAR
    | NOR
    | XOR
    | NXOR
    | XORN
;
unary_operator:
    PLUS
    | MINUS
    | unary_module_path_operator
;
inc_or_dec_operator:
    INCR
    | DECR
;
implicit_class_handle:
    KW_THIS ( DOT KW_SUPER )?
    | KW_SUPER
;
integral_number:
   BASED_NUMBER_WITH_SIZE
   | ( UNSIGNED_NUMBER )? ANY_BASED_NUMBER
   | UNSIGNED_NUMBER
;
real_number:
   REAL_NUMBER_WITH_EXP
   | FIXED_POINT_NUMBER
;
any_system_tf_identifier:
    SYSTEM_TF_IDENTIFIER
    | KW_DOLAR_SETUPHOLD
    | KW_DOLAR_SETUP
    | KW_DOLAR_FULLSKEW
    | KW_DOLAR_WARNING
    | KW_DOLAR_WIDTH
    | KW_DOLAR_ROOT
    | KW_DOLAR_RECOVERY
    | KW_DOLAR_SKEW
    | KW_DOLAR_FATAL
    | KW_DOLAR_REMOVAL
    | KW_DOLAR_RECREM
    | KW_DOLAR_ERROR
    | KW_DOLAR_PERIOD
    | KW_DOLAR_HOLD
    | KW_DOLAR_INFO
    | KW_DOLAR_UNIT
    | KW_DOLAR_TIMESKEW
    | KW_DOLAR_NOCHANGE
;
signing:
    KW_SIGNED
    | KW_UNSIGNED
;
number:
    integral_number
    | real_number
;
timeunits_declaration:
    KW_TIMEUNIT TIME_LITERAL ( ( DIV
                                 | SEMI KW_TIMEPRECISION
                                 ) TIME_LITERAL )? SEMI
    | KW_TIMEPRECISION TIME_LITERAL SEMI ( KW_TIMEUNIT TIME_LITERAL SEMI )?
;
lifetime:
    KW_STATIC
    | KW_AUTOMATIC
;
port_direction:
    KW_INPUT
    | KW_OUTPUT
    | KW_INOUT
    | KW_REF
;
always_keyword:
    KW_ALWAYS
    | KW_ALWAYS_COMB
    | KW_ALWAYS_LATCH
    | KW_ALWAYS_FF
;
join_keyword:
    KW_JOIN
    | KW_JOIN_ANY
    | KW_JOIN_NONE
;
unique_priority:
    KW_UNIQUE
    | KW_UNIQUE0
    | KW_PRIORITY
;
drive_strength:
    LPAREN (
        KW_HIGHZ0 COMMA strength1
        | KW_HIGHZ1 COMMA strength0
        | strength0 COMMA ( KW_HIGHZ1 | strength1 )
        | strength1 COMMA ( KW_HIGHZ0 | strength0 )
 ) RPAREN
;
strength0:
 KW_SUPPLY0
  | KW_STRONG0
  | KW_PULL0
  | KW_WEAK0
;
strength1:
 KW_SUPPLY1
  | KW_STRONG1
  | KW_PULL1
  | KW_WEAK1
;
charge_strength:
 LPAREN ( KW_SMALL
          | KW_MEDIUM
          | KW_LARGE
          ) RPAREN;

sequence_lvar_port_direction:
 KW_INPUT
  | KW_INOUT
  | KW_OUTPUT
;
bins_keyword:
 KW_BINS
  | KW_ILLEGAL_BINS
  | KW_IGNORE_BINS
;
class_item_qualifier:
 KW_STATIC
  | KW_PROTECTED
  | KW_LOCAL
;
random_qualifier:
    KW_RAND
     | KW_RANDC
;
property_qualifier:
 random_qualifier
  | class_item_qualifier
;
method_qualifier:
 ( KW_PURE )? KW_VIRTUAL
  | class_item_qualifier
;
constraint_prototype_qualifier:
 KW_EXTERN
  | KW_PURE
;

cmos_switchtype:
 KW_CMOS
  | KW_RCMOS
;
enable_gatetype:
 KW_BUFIF0
  | KW_BUFIF1
  | KW_NOTIF0
  | KW_NOTIF1
;
mos_switchtype:
 KW_NMOS
  | KW_PMOS
  | KW_RNMOS
  | KW_RPMOS
;
n_input_gatetype:
 KW_AND
  | KW_NAND
  | KW_OR
  | KW_NOR
  | KW_XOR
  | KW_XNOR
;
n_output_gatetype:
 KW_BUF
  | KW_NOT
;
pass_en_switchtype:
 KW_TRANIF0
  | KW_TRANIF1
  | KW_RTRANIF1
  | KW_RTRANIF0
;
pass_switchtype:
 KW_TRAN
  | KW_RTRAN
;
any_implication:
 IMPLIES
  | IMPLIES_P
  | IMPLIES_N
;
timing_check_event_control:
 KW_POSEDGE
  | KW_NEGEDGE
  | KW_EDGE
  | EDGE_CONTROL_SPECIFIER
;
import_export:
 KW_IMPORT
  | KW_EXPORT
;
array_method_name:
 KW_UNIQUE
  | KW_AND
  | KW_OR
  | KW_XOR
  | identifier
;
operator_mul_div_mod:
	MUL
  | DIV
  | MOD
;
operator_plus_minus:
	PLUS
    | MINUS
;
operator_shift:
	SHIFT_LEFT
   | SHIFT_RIGHT
   | ARITH_SHIFT_LEFT
   | ARITH_SHIFT_RIGHT
;
operator_cmp:
	 LT
   | LE
   | GT
   | GE
;
operator_eq_neq:
	 EQ
   | NE
   | CASE_EQ
   | CASE_NE
   | WILDCARD_EQ
   | WILDCARD_NE
;
operator_xor:
	  XOR
	| NXOR
	| XORN
;
operator_impl:
	  ARROW
	| BI_DIR_ARROW
;
/****************************************** udp ***********************************************************************/
udp_nonansi_declaration:
 ( attribute_instance )* KW_PRIMITIVE identifier LPAREN identifier_list_2plus RPAREN SEMI;
udp_ansi_declaration:
 ( attribute_instance )* KW_PRIMITIVE identifier LPAREN udp_declaration_port_list RPAREN SEMI;
udp_declaration:
 KW_EXTERN ( udp_nonansi_declaration
              | udp_ansi_declaration
              )
  | ( ( udp_nonansi_declaration udp_port_declaration
          | ( attribute_instance )* KW_PRIMITIVE identifier LPAREN DOT MUL RPAREN SEMI
          ) ( udp_port_declaration )*
      | udp_ansi_declaration
      ) udp_body KW_ENDPRIMITIVE ( COLON identifier | {_input->LA(1) != COLON}? )
;
udp_declaration_port_list:
 udp_output_declaration ( COMMA udp_input_declaration )+;
udp_port_declaration:
 ( udp_output_declaration
  | udp_input_declaration
  | udp_reg_declaration
  ) SEMI;
udp_output_declaration:
 ( attribute_instance )* KW_OUTPUT ( KW_REG identifier ( ASSIGN constant_expression )?
                                      | identifier
                                      );
udp_input_declaration: ( attribute_instance )* KW_INPUT identifier_list;
udp_reg_declaration: ( attribute_instance )* KW_REG identifier;
udp_body:
 combinational_body
  | sequential_body
;
combinational_body: KW_TABLE ( combinational_entry )+ KW_ENDTABLE;
combinational_entry: level_input_list COLON LEVEL_SYMBOL SEMI;
sequential_body: ( udp_initial_statement )? KW_TABLE ( sequential_entry )+ KW_ENDTABLE;
udp_initial_statement: KW_INITIAL identifier ASSIGN integral_number SEMI;
sequential_entry: seq_input_list COLON current_state COLON next_state SEMI;
seq_input_list:
 level_input_list
  | edge_input_list
;
level_input_list: ( LEVEL_SYMBOL )+;
edge_input_list: ( LEVEL_SYMBOL )* edge_indicator ( LEVEL_SYMBOL )*;
edge_indicator:
    LPAREN LEVEL_SYMBOL LEVEL_SYMBOL RPAREN
    | EDGE_SYMBOL
;
current_state: LEVEL_SYMBOL;
next_state:
    LEVEL_SYMBOL
    | MINUS
;
/****************************************** interface *****************************************************************/
interface_declaration:
 KW_EXTERN interface_header
  | ( ( interface_header
          | ( attribute_instance )* KW_INTERFACE identifier LPAREN DOT MUL RPAREN SEMI
       ) ( timeunits_declaration )? ( interface_item )*
      ) KW_ENDINTERFACE ( COLON identifier
                          | {_input->LA(1) != COLON}?
                          )
;
interface_header:
    ( attribute_instance )* KW_INTERFACE ( lifetime )? identifier
    ( package_import_declaration )*
    ( parameter_port_list )?
    ( list_of_port_declarations )? SEMI
;
interface_item:
  ansi_port_declaration SEMI
  | generate_region
  | ( attribute_instance )*
    (
      ( default_clocking_or_dissable_construct
          | local_parameter_declaration
          | parameter_declaration
      )? SEMI
      | net_declaration
      | data_declaration
      | task_declaration
      | function_declaration
      | checker_declaration
      | dpi_import_export
      | extern_constraint_declaration
      | class_declaration
      | interface_class_declaration
      | class_constructor_declaration
      | covergroup_declaration
      | property_declaration
      | sequence_declaration
      | let_declaration
      | genvar_declaration
      | clocking_declaration
      | module_or_interface_or_program_or_udp_instantiation
      | assertion_item
      | bind_directive
      | continuous_assign
      | net_alias
      | initial_construct
      | final_construct
      | always_construct
      | loop_generate_construct
      | conditional_generate_construct
      | elaboration_system_task
      | extern_tf_declaration
    )
  | program_declaration
  | modport_declaration
  | interface_declaration
  | timeunits_declaration
;
/***************************************** modport  ****************************************************************/
modport_declaration: KW_MODPORT modport_item ( COMMA modport_item )* SEMI;
modport_item:
    identifier LPAREN modport_ports_declaration ( COMMA modport_ports_declaration )* RPAREN;
modport_ports_declaration:
    ( attribute_instance )*
    ( modport_simple_ports_declaration
      | modport_tf_ports_declaration
      | modport_clocking_declaration
    )
;
modport_clocking_declaration: KW_CLOCKING identifier;
modport_simple_ports_declaration:
    port_direction modport_simple_port ( COMMA modport_simple_port )*;
modport_simple_port:
   list_of_arguments_named_item
    | identifier
;
modport_tf_ports_declaration:
    import_export modport_tf_port ( COMMA modport_tf_port )*;
modport_tf_port:
    method_prototype
    | identifier
;
/***************************************** statements  ****************************************************************/
statement_or_null:
    statement
    | ( attribute_instance )* SEMI
;
initial_construct: KW_INITIAL statement_or_null;
default_clocking_or_dissable_construct:
	KW_DEFAULT (
	    KW_CLOCKING identifier
	    | KW_DISABLE KW_IFF expression_or_dist
	)
;
statement: ( identifier COLON )? ( attribute_instance )* statement_item;
statement_item:
  ( blocking_assignment
    | nonblocking_assignment
    | procedural_continuous_assignment
    | inc_or_dec_expression
    | primary
    | clocking_drive
  ) SEMI
  | case_statement
  | conditional_statement
  | subroutine_call_statement 
  | disable_statement 
  | event_trigger     
  | loop_statement    
  | jump_statement    
  | par_block         
  | procedural_timing_control_statement
  | seq_block                          
  | wait_statement                     
  | procedural_assertion_statement     
  | randsequence_statement             
  | randcase_statement                 
  | expect_property_statement          
;
cycle_delay:
   DOUBLE_HASH ( LPAREN expression RPAREN
                | integral_number
                | identifier
                );
clocking_drive: clockvar_expression LE cycle_delay expression;
clockvar_expression: hierarchical_identifier select;
final_construct: KW_FINAL statement;
blocking_assignment:
    variable_lvalue ASSIGN ( delay_or_event_control expression | dynamic_array_new )
    | package_or_class_scoped_hier_id_with_select ASSIGN class_new
    | operator_assignment
;
procedural_timing_control_statement: procedural_timing_control statement_or_null;
procedural_timing_control:
   delay_control
    | event_control
    | cycle_delay
    | cycle_delay_range
;
event_control:
   AT ( LPAREN ( MUL
                | event_expression
                ) RPAREN
        | MUL
        | package_or_class_scoped_hier_id_with_select
      );
delay_or_event_control:
    delay_control
    | ( KW_REPEAT LPAREN expression RPAREN )? event_control
;
delay3:
    HASH ( LPAREN mintypmax_expression
           ( COMMA mintypmax_expression 
            ( COMMA mintypmax_expression )? )? RPAREN
          | delay_value
         );
delay2:
    HASH ( LPAREN mintypmax_expression ( COMMA mintypmax_expression )? RPAREN
           | delay_value
         );
delay_value:
    UNSIGNED_NUMBER
    | TIME_LITERAL
    | KW_1STEP
    | real_number
    | ps_identifier
;
delay_control:
    HASH ( LPAREN mintypmax_expression RPAREN
           | delay_value
         );
nonblocking_assignment: variable_lvalue LE ( delay_or_event_control )? expression;
procedural_continuous_assignment:
    KW_ASSIGN variable_assignment
    | KW_DEASSIGN variable_lvalue
    | KW_FORCE variable_assignment
    | KW_RELEASE variable_lvalue
;
variable_assignment:
    variable_lvalue ASSIGN expression;
action_block:
   KW_ELSE statement_or_null
   | statement_or_null ( KW_ELSE statement_or_null | {_input->LA(1) != KW_ELSE}? )
;
seq_block:
    KW_BEGIN ( COLON identifier | {_input->LA(1) != COLON}? )
        ( block_item_declaration )* ( statement_or_null )* 
    KW_END (COLON identifier |  {_input->LA(1) != COLON}?);
par_block:
    KW_FORK ( COLON identifier | {_input->LA(1) != COLON}? )
        ( block_item_declaration )* ( statement_or_null )* 
    join_keyword ( COLON identifier |  {_input->LA(1) != COLON}? );
/******************************************** case ********************************************************************/
case_statement:
    ( unique_priority )?
    ( KW_CASE LPAREN expression RPAREN KW_INSIDE ( case_inside_item )+
      | case_keyword LPAREN expression RPAREN
        ( KW_MATCHES ( case_pattern_item )+ 
          | ( case_item )+
        )
    ) KW_ENDCASE;
case_keyword:
    KW_CASE
    | KW_CASEZ
    | KW_CASEX
;
case_item:
    ( KW_DEFAULT ( COLON )?
      | expression ( COMMA expression )* COLON
    ) statement_or_null;
case_pattern_item:
    ( KW_DEFAULT ( COLON )?
      | pattern ( TRIPLE_AND expression )? COLON
    ) statement_or_null;
case_inside_item:
    ( KW_DEFAULT ( COLON )?
     | open_range_list COLON
    ) statement_or_null;
randcase_statement: KW_RANDCASE ( randcase_item )+ KW_ENDCASE;
randcase_item: expression COLON statement_or_null;
/************************************************ if-then-else ********************************************************/
cond_predicate:
 expression ( KW_MATCHES pattern )? ( TRIPLE_AND expression ( KW_MATCHES pattern )? )*;
conditional_statement:
    ( unique_priority )? KW_IF LPAREN cond_predicate RPAREN statement_or_null
    ( KW_ELSE statement_or_null | {_input->LA(1) != KW_ELSE}? );
subroutine_call_statement:
    ( KW_VOID APOSTROPHE LPAREN expression RPAREN ) SEMI;
disable_statement:
    KW_DISABLE ( KW_FORK
                 | hierarchical_identifier
               ) SEMI;
event_trigger:
 ( ARROW
   | DOUBLE_RIGHT_ARROW ( delay_or_event_control )?
 ) hierarchical_identifier SEMI;
/*********************************************** loop statements ******************************************************/
loop_statement:
 ( KW_FOREVER
      | ( ( KW_REPEAT
              | KW_WHILE
              ) LPAREN expression
          | KW_FOR LPAREN ( for_initialization )? SEMI ( expression )? SEMI ( for_step )?
          ) RPAREN
      ) statement_or_null
  | KW_DO statement_or_null KW_WHILE LPAREN expression RPAREN SEMI
  | KW_FOREACH LPAREN package_or_class_scoped_hier_id_with_select LSQUARE_BR loop_variables
  RSQUARE_BR RPAREN statement
;
list_of_variable_assignments: variable_assignment ( COMMA variable_assignment )*;
for_initialization:
    list_of_variable_assignments
    | for_variable_declaration ( COMMA for_variable_declaration )*
;
for_variable_declaration_var_assign: identifier ASSIGN expression;
for_variable_declaration:
    ( KW_VAR )? data_type for_variable_declaration_var_assign
    ( COMMA for_variable_declaration_var_assign )*
;
for_step: sequence_match_item ( COMMA sequence_match_item )*;
loop_variables: ( identifier )? ( COMMA ( identifier )? )*;
jump_statement:
    ( KW_RETURN ( expression )?
      | KW_BREAK
      | KW_CONTINUE
    ) SEMI;
/**********************************************************************************************************************/
wait_statement:
    KW_WAIT ( LPAREN expression RPAREN statement_or_null
              | KW_FORK SEMI
            )
    | KW_WAIT_ORDER LPAREN hierarchical_identifier 
      ( COMMA hierarchical_identifier )* RPAREN action_block
;
/**********************************************************************************************************************/
name_of_instance: identifier ( unpacked_dimension )*;
checker_instantiation:
 ps_identifier name_of_instance LPAREN list_of_checker_port_connections RPAREN SEMI;
list_of_checker_port_connections:
 ordered_checker_port_connection ( COMMA ordered_checker_port_connection )*
  | named_checker_port_connection ( COMMA named_checker_port_connection )*
;
ordered_checker_port_connection:
    ( attribute_instance )* ( property_actual_arg )?;
named_checker_port_connection:
    ( attribute_instance )* DOT (
        MUL 
        | identifier ( LPAREN ( property_actual_arg )? RPAREN )?
    );
procedural_assertion_statement:
   concurrent_assertion_statement
   | immediate_assertion_statement
   | checker_instantiation
;
concurrent_assertion_statement:
   ( KW_ASSERT
     | KW_ASSUME
   ) KW_PROPERTY LPAREN property_spec RPAREN action_block
   | KW_COVER ( KW_PROPERTY LPAREN property_spec
                | KW_SEQUENCE LPAREN
                  ( clocking_event )? ( KW_DISABLE KW_IFF LPAREN expression_or_dist RPAREN )? sequence_expr
               ) RPAREN statement_or_null
   | KW_RESTRICT KW_PROPERTY LPAREN property_spec RPAREN SEMI
;
assertion_item:
   concurrent_assertion_item
   | ( identifier COLON )? deferred_immediate_assertion_statement
;
concurrent_assertion_item:
   ( identifier COLON )? concurrent_assertion_statement
   | checker_instantiation
;
immediate_assertion_statement:
   simple_immediate_assertion_statement
   | deferred_immediate_assertion_statement
;
simple_immediate_assertion_statement:
   simple_immediate_assert_statement
   | simple_immediate_assume_statement
   | simple_immediate_cover_statement
;
simple_immediate_assert_statement:
   KW_ASSERT LPAREN expression RPAREN action_block;
simple_immediate_assume_statement:
   KW_ASSUME LPAREN expression RPAREN action_block;
simple_immediate_cover_statement:
   KW_COVER LPAREN expression RPAREN statement_or_null;
deferred_immediate_assertion_statement:
   deferred_immediate_assert_statement
   | deferred_immediate_assume_statement
   | deferred_immediate_cover_statement
;
primitive_delay:
   HASH UNSIGNED_NUMBER;
deferred_immediate_assert_statement:
    KW_ASSERT ( KW_FINAL
                | primitive_delay
              )
    LPAREN expression RPAREN action_block;
deferred_immediate_assume_statement:
    KW_ASSUME ( KW_FINAL
                | primitive_delay
                 )
    LPAREN expression RPAREN action_block;
deferred_immediate_cover_statement:
    KW_COVER ( KW_FINAL
               | primitive_delay
             )
    LPAREN expression RPAREN statement_or_null;
/**********************************************************************************************************************/
weight_specification:
   LPAREN expression RPAREN
   | integral_number
   | ps_identifier
;
production_item: identifier ( LPAREN ( list_of_arguments )? RPAREN )?;
rs_code_block: LBRACE ( data_declaration )* ( statement_or_null )* RBRACE;
randsequence_statement:
    KW_RANDSEQUENCE LPAREN ( identifier )? RPAREN ( production )+ KW_ENDSEQUENCE;
rs_prod:
    production_item
    | rs_code_block
    | rs_if_else
    | rs_repeat
    | rs_case
;
rs_if_else:
    KW_IF LPAREN expression RPAREN production_item
    ( KW_ELSE production_item | {_input->LA(1) != KW_ELSE}? );
rs_repeat:
    KW_REPEAT LPAREN expression RPAREN production_item;
rs_case:
    KW_CASE LPAREN expression RPAREN ( rs_case_item )+ KW_ENDCASE;
rs_case_item:
    ( KW_DEFAULT ( COLON )?
      | expression ( COMMA expression )* COLON
    ) production_item SEMI;
rs_rule:
    rs_production_list ( DIST_WEIGHT_ASSIGN weight_specification ( rs_code_block )? )?;
rs_production_list:
    KW_RAND KW_JOIN ( LPAREN expression RPAREN )? production_item ( production_item )+
    | ( rs_prod )+
;
production:
    ( data_type_or_void )? identifier
    ( LPAREN tf_port_list RPAREN )? COLON rs_rule ( BAR rs_rule )*
    SEMI;
tf_item_declaration:
    block_item_declaration
    | tf_port_declaration
;
tf_port_list: tf_port_item ( COMMA tf_port_item )*;
tf_port_item:
    ( attribute_instance )* ( tf_port_direction )? ( KW_VAR )? ( data_type_or_implicit )?
    ( identifier ( variable_dimension )* ( ASSIGN expression )? )?;
tf_port_direction:
    KW_CONST KW_REF
    | port_direction
;
tf_port_declaration:
    ( attribute_instance )* tf_port_direction ( KW_VAR )? ( data_type_or_implicit )?
    list_of_tf_variable_identifiers SEMI
;
list_of_tf_variable_identifiers_item: identifier ( variable_dimension )* ( ASSIGN expression )?;
// list_of_variable_identifiers with a "= expr"
list_of_tf_variable_identifiers:
    list_of_tf_variable_identifiers_item
    ( COMMA list_of_tf_variable_identifiers_item )*
;
expect_property_statement: KW_EXPECT LPAREN property_spec RPAREN action_block;
block_item_declaration:
    ( attribute_instance )* (
        data_declaration
        | ( local_parameter_declaration
            | parameter_declaration
            ) SEMI
        | let_declaration
    )
;
param_assignment:
    identifier ( unpacked_dimension )* ( ASSIGN constant_param_expression )?;
type_assignment: identifier ( ASSIGN data_type )?;
list_of_type_assignments: type_assignment ( COMMA type_assignment )*;
list_of_param_assignments: param_assignment ( COMMA param_assignment )*;
local_parameter_declaration:
 KW_LOCALPARAM ( KW_TYPE list_of_type_assignments
                  | ( data_type_or_implicit )? list_of_param_assignments
                  );
parameter_declaration:
    KW_PARAMETER
    ( KW_TYPE list_of_type_assignments
      | ( data_type_or_implicit )? list_of_param_assignments
    );
type_declaration:
    KW_TYPEDEF (
        data_type identifier ( variable_dimension )*
        | ( KW_ENUM
            | KW_STRUCT
            | KW_UNION
            | identifier_with_bit_select DOT identifier
            | ( KW_INTERFACE )? KW_CLASS
          )? identifier
    ) SEMI;
net_type_declaration:
    KW_NETTYPE ( data_type identifier ( KW_WITH package_or_class_scoped_id )? ) SEMI;

/**********************************************************************************************************************/
let_declaration:
    KW_LET identifier ( LPAREN ( let_port_list )? RPAREN )? ASSIGN expression SEMI;
let_port_list: let_port_item ( COMMA let_port_item )*;
let_port_item:
    ( attribute_instance )* ( let_formal_type )? identifier
    ( variable_dimension )* ( ASSIGN expression )?;
let_formal_type:
    KW_UNTYPED
    | data_type_or_implicit
;
/**********************************************************************************************************************/
package_import_declaration:
    KW_IMPORT package_import_item ( COMMA package_import_item )* SEMI;
package_import_item:
    identifier DOUBLE_COLON ( MUL
                              | identifier
                            );

/****************************************** property expr *************************************************************/
property_list_of_arguments:
    ( DOT identifier LPAREN ( property_actual_arg )? RPAREN
        | property_actual_arg ( COMMA ( property_actual_arg )? )*
        | ( COMMA ( property_actual_arg )? )+
    )? ( COMMA DOT identifier LPAREN ( property_actual_arg )? RPAREN )*;
property_actual_arg:
    property_expr
    | sequence_actual_arg
;
property_formal_type:
    KW_PROPERTY
    | sequence_formal_type
;
sequence_formal_type:
    KW_SEQUENCE
    | KW_UNTYPED
    | data_type_or_implicit
;
property_instance:
    package_or_class_scoped_id ( LPAREN property_list_of_arguments RPAREN )?;
property_spec:
    ( clocking_event )? ( KW_DISABLE KW_IFF LPAREN expression_or_dist RPAREN )? property_expr;
property_expr:
  ( KW_STRONG | KW_WEAK )? LPAREN property_expr RPAREN
  | KW_IF LPAREN expression_or_dist RPAREN property_expr ( KW_ELSE property_expr
                                                          | {_input->LA(1) != KW_ELSE}?
                                                          )
  | KW_CASE LPAREN expression_or_dist RPAREN ( property_case_item )+ KW_ENDCASE
  | sequence_expr ( ( OVERLAPPING_IMPL
                  | NONOVERLAPPING_IMPL
                  | HASH_MINUS_HASH
                  | HASH_EQ_HASH
                  ) property_expr )?
  | ( KW_NOT
      | ( KW_S_ALWAYS
          | KW_EVENTUALLY
          ) LSQUARE_BR range_expression RSQUARE_BR
      | ( KW_ACCEPT_ON
          | KW_REJECT_ON
          | KW_SYNC_ACCEPT_ON
          | KW_SYNC_REJECT_ON
          ) LPAREN expression_or_dist RPAREN
      | ( KW_NEXTTIME
          | KW_S_NEXTTIME
          ) ( LSQUARE_BR expression RSQUARE_BR )?
      | ( KW_ALWAYS
          | KW_S_EVENTUALLY
          ) ( LSQUARE_BR cycle_delay_const_range_expression RSQUARE_BR )?
      | clocking_event
     ) property_expr
   | property_expr ( KW_OR
                      | KW_AND
                      | KW_UNTIL
                      | KW_S_UNTIL
                      | KW_UNTIL_WITH
                      | KW_S_UNTIL_WITH
                      | KW_IMPLIES
                      | KW_IFF
                      ) property_expr
  | property_instance
;
property_case_item:
 ( KW_DEFAULT ( COLON )?
   | expression_or_dist ( COMMA expression_or_dist )* COLON
 ) property_expr SEMI;
/****************************************** ids and selects ***********************************************************/
bit_select: LSQUARE_BR expression RSQUARE_BR;
identifier_with_bit_select: identifier ( bit_select )*;
// '::' separated then '.' separated
package_or_class_scoped_hier_id_with_select:
    package_or_class_scoped_path ( bit_select )* 
    ( DOT identifier_with_bit_select )* 
    ( LSQUARE_BR expression ( operator_plus_minus )? COLON expression RSQUARE_BR )?;
    
package_or_class_scoped_path_item: identifier ( parameter_value_assignment )?;
// '::' separated
package_or_class_scoped_path:
   ( KW_LOCAL DOUBLE_COLON )? (
  		KW_DOLAR_ROOT
        | implicit_class_handle
        | KW_DOLAR_UNIT
        | package_or_class_scoped_path_item
	) ( DOUBLE_COLON package_or_class_scoped_path_item)*;
hierarchical_identifier:
   ( KW_DOLAR_ROOT DOT )? ( identifier_with_bit_select DOT )* identifier;
package_or_class_scoped_id:
  ( KW_DOLAR_UNIT
    | package_or_class_scoped_path_item
  ) ( DOUBLE_COLON package_or_class_scoped_path_item )*;
select:
    ( DOT identifier
      | bit_select
    )* ( LSQUARE_BR array_range_expression RSQUARE_BR )?;

/************************************************ event_expression ****************************************************/
event_expression_item:
    LPAREN event_expression RPAREN
    | ( edge_identifier )? expression ( KW_IFF expression )?
;
event_expression: event_expression_item ( ( KW_OR | COMMA ) event_expression_item )*;
/************************************************ sequence_expr *******************************************************/
boolean_abbrev:
    consecutive_repetition
    | non_consecutive_repetition
    | goto_repetition
;
sequence_abbrev: consecutive_repetition;
consecutive_repetition:
 LSQUARE_BR ( MUL ( const_or_range_expression )?
              | PLUS
              ) RSQUARE_BR;
non_consecutive_repetition:
 LSQUARE_BR ASSIGN const_or_range_expression RSQUARE_BR;
goto_repetition:
 LSQUARE_BR ARROW const_or_range_expression RSQUARE_BR;
cycle_delay_const_range_expression:
    expression COLON ( DOLAR | expression);
sequence_instance:
  package_or_class_scoped_path  ( LPAREN (sequence_list_of_arguments)? RPAREN )?;
sequence_expr:
    KW_FIRST_MATCH LPAREN sequence_expr ( COMMA sequence_match_item )* RPAREN
    | ( cycle_delay_range sequence_expr )+
    | expression_or_dist ( KW_THROUGHOUT sequence_expr
                           | boolean_abbrev
                           )?
    | sequence_expr ( ( KW_AND
                        | KW_INTERSECT
                        | KW_OR
                        | KW_WITHIN
                        ) sequence_expr
                    | ( cycle_delay_range sequence_expr )+
                    )
    | ( LPAREN sequence_expr ( COMMA sequence_match_item )* RPAREN
        | sequence_instance
        ) ( sequence_abbrev )?
    | clocking_event sequence_expr
;
sequence_match_item:
    operator_assignment
    | expression
;
operator_assignment: variable_lvalue assignment_operator expression;
sequence_actual_arg:
    event_expression
    | sequence_expr
;
dist_weight:
    ( DIST_WEIGHT_ASSIGN
     | COLON DIV
    ) expression;
clocking_declaration:
    ( KW_GLOBAL KW_CLOCKING ( identifier )? clocking_event SEMI
      | ( KW_DEFAULT )? KW_CLOCKING ( identifier )? clocking_event SEMI ( clocking_item )*
    ) KW_ENDCLOCKING ( COLON identifier
                     | {_input->LA(1) != COLON}?)
;
clocking_item:
    ( KW_DEFAULT default_skew
      | clocking_direction list_of_clocking_decl_assign
    ) SEMI
    | ( attribute_instance )* (
         property_declaration
         | sequence_declaration
         | let_declaration
       )
;
list_of_clocking_decl_assign: clocking_decl_assign ( COMMA clocking_decl_assign )*;
clocking_decl_assign: attr_spec;
default_skew:
 KW_INPUT clocking_skew ( KW_OUTPUT clocking_skew )?
  | KW_OUTPUT clocking_skew
;
clocking_direction:
 KW_INPUT ( clocking_skew )? ( KW_OUTPUT ( clocking_skew )? )?
  | KW_OUTPUT ( clocking_skew )?
  | KW_INOUT
;
clocking_skew:
 edge_identifier ( delay_control )?
  | delay_control
;
clocking_event:
  AT ( identifier
       | LPAREN event_expression RPAREN
  );
cycle_delay_range:
 DOUBLE_HASH ( LSQUARE_BR ( MUL
                          | PLUS
                          | cycle_delay_const_range_expression
                          ) RSQUARE_BR
              | primary
              );
expression_or_dist:
 expression ( KW_DIST LBRACE dist_item ( COMMA dist_item )* RBRACE )?;

covergroup_declaration:
 KW_COVERGROUP identifier ( LPAREN tf_port_list RPAREN )? ( coverage_event )? SEMI
      ( coverage_spec_or_option )* KW_ENDGROUP ( COLON identifier
                  | {_input->LA(1) != COLON}?
                  );
cover_cross:
 ( identifier COLON )? KW_CROSS identifier_list_2plus ( KW_IFF LPAREN expression RPAREN )?
      cross_body;
identifier_list_2plus:
 identifier ( COMMA identifier )+;
cross_body:
 LBRACE ( cross_body_item )* RBRACE
  | SEMI
;
cross_body_item:
 function_declaration
  | bins_selection_or_option SEMI
;
bins_selection_or_option:
 ( attribute_instance )* ( coverage_option
                          | bins_selection
                          );
bins_selection:
 bins_keyword identifier ASSIGN select_expression ( KW_IFF LPAREN expression RPAREN )?;
select_expression:
    LPAREN select_expression RPAREN
    | ( NOT )? select_condition
    | select_expression ( AND_LOG
                            | OR_LOG
                        ) select_expression
    | select_expression KW_WITH LPAREN covergroup_expression RPAREN
                        ( KW_MATCHES covergroup_expression )?
    | covergroup_expression ( KW_MATCHES covergroup_expression )?
;
select_condition:
    KW_BINSOF LPAREN bins_expression RPAREN
    ( KW_INTERSECT LBRACE covergroup_range_list RBRACE )?;
bins_expression: identifier ( DOT identifier )?;
covergroup_range_list:
    covergroup_value_range ( COMMA covergroup_value_range )*;
covergroup_value_range:
    LSQUARE_BR covergroup_expression COLON covergroup_expression RSQUARE_BR
    | covergroup_expression
;
covergroup_expression: expression;
coverage_spec_or_option:
 ( attribute_instance )* ( coverage_spec
                           | coverage_option SEMI
                         );
coverage_option:
    KW_OPTION DOT identifier ASSIGN expression
    | KW_TYPE_OPTION DOT identifier ASSIGN constant_expression
;
coverage_spec:
    cover_point
    | cover_cross
;
cover_point:
    ( ( data_type_or_implicit )? identifier COLON )? KW_COVERPOINT expression
    ( KW_IFF LPAREN expression RPAREN )? bins_or_empty;
bins_or_empty:
    LBRACE ( attribute_instance )* ( bins_or_options SEMI )* RBRACE
    | SEMI
;
bins_or_options:
    coverage_option
    | ( ( KW_WILDCARD )? bins_keyword identifier (
         ( LSQUARE_BR ( covergroup_expression )? RSQUARE_BR )?
             ASSIGN ( LBRACE covergroup_range_list RBRACE
             (
                 KW_WITH LPAREN covergroup_expression RPAREN )?
                 | identifier KW_WITH LPAREN covergroup_expression RPAREN
                 | covergroup_expression
             )
            | ( LSQUARE_BR RSQUARE_BR )? ASSIGN trans_list
         )
        | bins_keyword identifier ( ASSIGN KW_DEFAULT KW_SEQUENCE
                                    | ( LSQUARE_BR ( covergroup_expression )? RSQUARE_BR )? ASSIGN
                                    KW_DEFAULT
                                    )
        ) ( KW_IFF LPAREN expression RPAREN )?
;
trans_list:
    LPAREN trans_set RPAREN ( COMMA LPAREN trans_set RPAREN )*;
trans_set:
    trans_range_list ( IMPLIES trans_range_list )*;
trans_range_list:
    covergroup_range_list ( LSQUARE_BR ( MUL
                                         | ARROW
                                         | ASSIGN
                                       ) repeat_range RSQUARE_BR )?;
repeat_range: covergroup_expression ( COLON covergroup_expression )?;
coverage_event:
    ( KW_WITH KW_FUNCTION KW_SAMPLE LPAREN tf_port_list
      | DOUBLE_AT LPAREN block_event_expression
    ) RPAREN
    | clocking_event
;
block_event_expression:
    ( KW_BEGIN
      | KW_END
    ) hierarchical_btf_identifier
    | block_event_expression KW_OR block_event_expression
;
hierarchical_btf_identifier:
    hierarchical_identifier
    | ( hierarchical_identifier DOT
        | class_scope
      )? identifier
;
assertion_variable_declaration: ( var_data_type )? list_of_variable_decl_assignments SEMI;
dist_item: value_range ( dist_weight )?;
value_range:
    LSQUARE_BR range_expression RSQUARE_BR
    | expression
;
/************************************************ attribute_instance **************************************************/
attribute_instance: LPAREN MUL attr_spec ( COMMA attr_spec )* MUL RPAREN;
attr_spec: identifier ( ASSIGN expression )?;
/************************************************ type defs and data_type *********************************************/
class_new:
    KW_NEW expression
    | ( class_scope )? KW_NEW ( LPAREN ( list_of_arguments )? RPAREN )?
;
param_expression:
    mintypmax_expression
    | data_type
;
constant_param_expression: param_expression ;
                  
unpacked_dimension: LSQUARE_BR range_expression RSQUARE_BR;
packed_dimension: LSQUARE_BR  ( range_expression )? RSQUARE_BR;
variable_dimension:
    LSQUARE_BR ( MUL
             | data_type
             | array_range_expression
              )? RSQUARE_BR
;
struct_union:
    KW_STRUCT
    | KW_UNION ( KW_TAGGED )?
;
enum_base_type:
    integer_atom_type ( signing )?
    | ( integer_vector_type ( signing )?
        | package_or_class_scoped_id
      ) ( variable_dimension )?
    | packed_dimension
;
data_type_primitive:
    integer_type ( signing )?
    | non_integer_type
;
data_type:
    KW_STRING
    | KW_CHANDLE
    | KW_VIRTUAL ( KW_INTERFACE )? identifier ( parameter_value_assignment )? ( DOT identifier )?
    | KW_EVENT
    | ( data_type_primitive
        | KW_ENUM ( enum_base_type )?
           LBRACE enum_name_declaration  ( COMMA enum_name_declaration )* RBRACE
        | struct_union ( KW_PACKED ( signing )? )?
            LBRACE ( struct_union_member )+ RBRACE
        | package_or_class_scoped_path
      ) ( variable_dimension )*
    | type_reference
;
data_type_or_implicit:
    data_type
    | implicit_data_type
;
implicit_data_type:
    signing ( packed_dimension )*
    | ( packed_dimension )+
;
/************************************************ list_of_arguments ***************************************************/
// first normal arguments and then named arguments, while keeping the list not eps
sequence_list_of_arguments_named_item: DOT identifier LPAREN ( sequence_actual_arg )? RPAREN;
sequence_list_of_arguments:
    ( sequence_list_of_arguments_named_item
     | COMMA sequence_list_of_arguments_named_item
     | sequence_actual_arg ( COMMA ( sequence_actual_arg )? )*
     | ( COMMA ( sequence_actual_arg )? )+
    )
    ( COMMA sequence_list_of_arguments_named_item )*;
list_of_arguments_named_item: DOT identifier LPAREN ( expression )? RPAREN;
list_of_arguments:
    ( list_of_arguments_named_item
     | COMMA list_of_arguments_named_item
     | expression ( COMMA ( expression )? )*
     | ( COMMA ( expression )? )+
    )
    ( COMMA list_of_arguments_named_item )*;
/************************************************ primary *************************************************************/
primary_literal:
    TIME_LITERAL
    | UNBASED_UNSIZED_LITERAL
    | STRING_LITERAL
    | number
    | KW_NULL
    | KW_THIS
    | DOLAR
;
type_reference:
    KW_TYPE LPAREN (
        expression
        | data_type
    ) RPAREN
;
package_scope: ( KW_DOLAR_UNIT | identifier ) DOUBLE_COLON;
ps_identifier: ( package_scope )? identifier;
list_of_parameter_value_assignments:
    param_expression ( COMMA param_expression )*
    | named_parameter_assignment ( COMMA named_parameter_assignment )*
;
parameter_value_assignment: HASH LPAREN ( list_of_parameter_value_assignments )? RPAREN;
class_type:
    ps_identifier ( parameter_value_assignment )? ( DOUBLE_COLON identifier
       ( parameter_value_assignment )? )*
;
class_scope: class_type DOUBLE_COLON;
range_expression: expression ( COLON expression )?;
constant_range_expression: range_expression;
constant_mintypmax_expression: mintypmax_expression;
mintypmax_expression: expression ( COLON expression COLON expression )?;
named_parameter_assignment: DOT identifier LPAREN ( param_expression )? RPAREN;
// original primary+constant_primary
// let_expression was remobed because it was same as call
primary:
    primary_literal                               #PrimaryLit
    | package_or_class_scoped_path                #PrimaryPath
    | LPAREN mintypmax_expression RPAREN          #PrimaryPar
    | ( KW_STRING
        | KW_CONST
        | integer_type
        | non_integer_type
        | signing
        ) APOSTROPHE LPAREN expression RPAREN     #PrimaryCast
    | primary APOSTROPHE LPAREN expression RPAREN #PrimaryCast2
    | primary bit_select                          #PrimaryBitSelect
    | primary DOT identifier                      #PrimaryDot
    | primary LSQUARE_BR array_range_expression RSQUARE_BR #PrimaryIndex
    | concatenation                                        #PrimaryConcat
    | streaming_concatenation                              #PrimaryStreaming_concatenation
    | any_system_tf_identifier ( LPAREN data_type (COMMA list_of_arguments)?
         ( COMMA clocking_event )? RPAREN
         | LPAREN list_of_arguments ( COMMA clocking_event )?  RPAREN
         )?                                       #PrimaryTfCall
    | ( KW_STD DOUBLE_COLON )?  randomize_call    #PrimaryRandomize
    | primary DOT randomize_call                  #PrimaryRandomize2
    | assignment_pattern_expression               #PrimaryAssig
    | type_reference                              #PrimaryTypeRef
    | primary ( DOT array_method_name )? ( attribute_instance )*
                  LPAREN ( list_of_arguments )? RPAREN
                  ( KW_WITH LPAREN expression RPAREN )? #PrimaryCall
    | primary DOT array_method_name               #PrimaryCallArrayMethodNoArgs
    | primary ( DOT array_method_name )? ( attribute_instance )*
             KW_WITH LPAREN expression RPAREN     #PrimaryCallWith
;
/************************************************** expression ********************************************************/
constant_expression: expression;
inc_or_dec_expression:
     inc_or_dec_operator ( attribute_instance )* variable_lvalue #Inc_or_dec_expressionPre
    | variable_lvalue ( attribute_instance )* inc_or_dec_operator  #Inc_or_dec_expressionPost
;
expression:
    primary
    | LPAREN operator_assignment RPAREN
    | KW_TAGGED identifier ( expression )?
    | unary_operator ( attribute_instance )* primary
    | inc_or_dec_expression
    | expression DOUBLESTAR           ( attribute_instance )* expression
    | expression operator_mul_div_mod ( attribute_instance )* expression
    | expression operator_plus_minus  ( attribute_instance )* expression
    | expression operator_shift       ( attribute_instance )* expression
    | expression operator_cmp         ( attribute_instance )* expression
    | expression KW_INSIDE LBRACE open_range_list RBRACE
    | expression operator_eq_neq      ( attribute_instance )* expression
    | expression AMPERSAND            ( attribute_instance )* expression
    | expression operator_xor         ( attribute_instance )* expression
    | expression BAR                  ( attribute_instance )* expression
    | expression AND_LOG              ( attribute_instance )* expression
    | expression OR_LOG               ( attribute_instance )* expression
    | expression ( KW_MATCHES pattern )? TRIPLE_AND expression ( KW_MATCHES pattern )?
    | <assoc=right> expression ( KW_MATCHES pattern )? QUESTIONMARK ( attribute_instance )* expression COLON expression
    | <assoc=right> expression operator_impl        ( attribute_instance )* expression
;

concatenation:
    LBRACE (expression ( concatenation | ( COMMA expression )+)?)? RBRACE;
dynamic_array_new:
    KW_NEW LSQUARE_BR expression RSQUARE_BR ( LPAREN expression RPAREN )?;
const_or_range_expression:
    expression ( COLON ( DOLAR | expression ) )?
;
variable_decl_assignment:
    identifier (
        ASSIGN ( expression | class_new )
        | ( variable_dimension )+ ( ASSIGN ( expression | dynamic_array_new ) )?
    )?
;
/* assignment_pattern_net_lvalue */
assignment_pattern_variable_lvalue:
    APOSTROPHE_LBRACE variable_lvalue ( COMMA variable_lvalue )* RBRACE;
stream_operator:
 SHIFT_RIGHT
  | SHIFT_LEFT
;
slice_size:
  integer_type
   | non_integer_type
   | package_or_class_scoped_path
   | expression
;
streaming_concatenation:
 LBRACE stream_operator ( slice_size )? stream_concatenation RBRACE;
stream_concatenation:
 LBRACE stream_expression ( COMMA stream_expression )* RBRACE;
stream_expression:
 expression ( KW_WITH LSQUARE_BR array_range_expression RSQUARE_BR )?;
array_range_expression:
 expression ( ( operator_plus_minus )? COLON expression )?;
open_range_list: value_range ( COMMA value_range )*;
pattern:
 DOT ( MUL | identifier )
  | KW_TAGGED identifier ( pattern )?
  | APOSTROPHE_LBRACE (
       pattern ( COMMA pattern )*
       | identifier COLON pattern ( COMMA identifier COLON pattern )*
    ) RBRACE
  | expression
;
assignment_pattern:
    APOSTROPHE_LBRACE (
        expression ( COMMA expression )*
        | structure_pattern_key COLON expression
           ( COMMA structure_pattern_key COLON expression )*
        | array_pattern_key COLON expression
           ( COMMA array_pattern_key COLON expression )*
        | constant_expression LBRACE expression ( COMMA expression )* RBRACE
    )? RBRACE;
structure_pattern_key:
 identifier
  | assignment_pattern_key
;
array_pattern_key:
 constant_expression
  | assignment_pattern_key
;
assignment_pattern_key:
 KW_DEFAULT
  | integer_type
  | non_integer_type
  | package_or_class_scoped_path
;
struct_union_member:
  ( attribute_instance )* ( random_qualifier )? data_type_or_void list_of_variable_decl_assignments
       SEMI;
data_type_or_void:
  KW_VOID
   | data_type
;
enum_name_declaration:
 identifier ( LSQUARE_BR integral_number ( COLON integral_number )? RSQUARE_BR )? ( ASSIGN expression )?;
assignment_pattern_expression:
 ( assignment_pattern_expression_type )? assignment_pattern;
assignment_pattern_expression_type:
   package_or_class_scoped_path
  | integer_atom_type
  | type_reference
;
net_lvalue: variable_lvalue;
variable_lvalue:
 LBRACE variable_lvalue ( COMMA variable_lvalue )* RBRACE
  | package_or_class_scoped_hier_id_with_select
  | ( assignment_pattern_expression_type )? assignment_pattern_variable_lvalue
  | streaming_concatenation
;
solve_before_list:
 primary ( COMMA primary )*;
constraint_block_item:
  KW_SOLVE solve_before_list KW_BEFORE solve_before_list SEMI
   | constraint_expression
;
constraint_expression:
    KW_IF LPAREN expression RPAREN constraint_set 
    ( KW_ELSE constraint_set | {_input->LA(1) != KW_ELSE}? )
    | ( KW_DISABLE KW_SOFT primary
        | ( KW_SOFT )? expression_or_dist
        | uniqueness_constraint
        ) SEMI
    | ( KW_FOREACH LPAREN primary LSQUARE_BR loop_variables
        RSQUARE_BR RPAREN
        | expression ARROW
        ) constraint_set
;
uniqueness_constraint:
 KW_UNIQUE LBRACE open_range_list RBRACE;
constraint_set:
 LBRACE ( constraint_expression )* RBRACE
  | constraint_expression
;
randomize_call:
 KW_RANDOMIZE ( attribute_instance )* (
    LPAREN ( KW_NULL | list_of_arguments )? RPAREN
    )?
    (
     KW_WITH ( LPAREN ( list_of_arguments )? RPAREN )?
               LBRACE ( constraint_block_item )* RBRACE
    )?;
/**************************************** module *********************************************************************/
module_header_common:
  ( attribute_instance )* module_keyword ( lifetime )? identifier
  ( package_import_declaration )* ( parameter_port_list )?;
module_declaration:
  KW_EXTERN module_header_common ( list_of_port_declarations )? SEMI
   | module_header_common (list_of_port_declarations | (LPAREN DOT MUL RPAREN) )? SEMI
       ( timeunits_declaration )? ( module_item )*
     KW_ENDMODULE ( COLON identifier | {_input->LA(1) != COLON}? )
;
module_keyword:
  KW_MODULE
   | KW_MACROMODULE
;
/************************************* package ************************************************************************/
net_port_type:
 KW_INTERCONNECT ( implicit_data_type )?
  | net_type ( data_type_or_implicit )?
  | data_type_or_implicit
;
var_data_type:
  KW_VAR ( data_type_or_implicit )?
   | data_type
;
net_or_var_data_type:
 KW_INTERCONNECT ( implicit_data_type )?
  | KW_VAR ( data_type_or_implicit )?
  | net_type ( data_type_or_implicit )?
  | data_type_or_implicit
;
list_of_defparam_assignments: defparam_assignment ( COMMA defparam_assignment )*;
list_of_net_decl_assignments: net_decl_assignment ( COMMA net_decl_assignment )*;
list_of_specparam_assignments: specparam_assignment ( COMMA specparam_assignment )*;
list_of_variable_decl_assignments:
    variable_decl_assignment ( COMMA variable_decl_assignment )*;
list_of_variable_identifiers_item: identifier ( variable_dimension )*;
/* list_of_port_identifiers */
list_of_variable_identifiers:
    list_of_variable_identifiers_item ( COMMA list_of_variable_identifiers_item )*;
list_of_variable_port_identifiers: list_of_tf_variable_identifiers;
defparam_assignment:
 hierarchical_identifier ASSIGN mintypmax_expression;
net_decl_assignment:
 identifier ( unpacked_dimension )* ( ASSIGN expression )?;
specparam_assignment:
 identifier ASSIGN mintypmax_expression
  | pulse_control_specparam
;
error_limit_value: mintypmax_expression;
reject_limit_value: mintypmax_expression;
pulse_control_specparam:
  KW_PATHPULSE_DOLAR
       ( specify_input_terminal_descriptor DOLAR specify_output_terminal_descriptor )?
       ASSIGN LPAREN reject_limit_value ( COMMA error_limit_value )? RPAREN;
identifier_doted_index_at_end:
   identifier ( DOT identifier )?  ( LSQUARE_BR range_expression RSQUARE_BR )*;
specify_terminal_descriptor: identifier_doted_index_at_end;
specify_input_terminal_descriptor: identifier_doted_index_at_end;
specify_output_terminal_descriptor: identifier_doted_index_at_end;
specify_item:
 specparam_declaration
  | pulsestyle_declaration
  | showcancelled_declaration
  | path_declaration
  | system_timing_check
;
pulsestyle_declaration:
 ( KW_PULSESTYLE_ONEVENT
  | KW_PULSESTYLE_ONDETECT
  ) list_of_path_outputs SEMI;
showcancelled_declaration:
 ( KW_SHOWCANCELLED
  | KW_NOSHOWCANCELLED
  ) list_of_path_outputs SEMI;
path_declaration:
 ( simple_path_declaration
  | edge_sensitive_path_declaration
  | state_dependent_path_declaration
  ) SEMI;
simple_path_declaration:
 ( parallel_path_description
  | full_path_description
  ) ASSIGN path_delay_value;
path_delay_value:
 LPAREN list_of_path_delay_expressions RPAREN
  | list_of_path_delay_expressions
;
list_of_path_outputs: list_of_paths;
list_of_path_inputs: list_of_paths;
list_of_paths: identifier_doted_index_at_end ( COMMA identifier_doted_index_at_end )*;
list_of_path_delay_expressions:
    t_path_delay_expression
    | trise_path_delay_expression COMMA
      tfall_path_delay_expression
      ( COMMA tz_path_delay_expression )?
    | t01_path_delay_expression COMMA
      t10_path_delay_expression COMMA
      t0z_path_delay_expression COMMA
      tz1_path_delay_expression COMMA
      t1z_path_delay_expression COMMA
      tz0_path_delay_expression
      ( COMMA 
        t0x_path_delay_expression COMMA
        tx1_path_delay_expression COMMA
        t1x_path_delay_expression COMMA
        tx0_path_delay_expression COMMA
        txz_path_delay_expression COMMA
        tzx_path_delay_expression )?
;
t_path_delay_expression: constant_mintypmax_expression;
trise_path_delay_expression: constant_mintypmax_expression;
tfall_path_delay_expression: constant_mintypmax_expression;
tz_path_delay_expression: constant_mintypmax_expression;
t01_path_delay_expression: constant_mintypmax_expression;
t10_path_delay_expression: constant_mintypmax_expression;
t0z_path_delay_expression: constant_mintypmax_expression;
tz1_path_delay_expression: constant_mintypmax_expression;
t1z_path_delay_expression: constant_mintypmax_expression;
tz0_path_delay_expression: constant_mintypmax_expression;
t0x_path_delay_expression: constant_mintypmax_expression;
tx1_path_delay_expression: constant_mintypmax_expression;
t1x_path_delay_expression: constant_mintypmax_expression;
tx0_path_delay_expression: constant_mintypmax_expression;
txz_path_delay_expression: constant_mintypmax_expression;
tzx_path_delay_expression: constant_mintypmax_expression;
parallel_path_description:
 LPAREN specify_input_terminal_descriptor any_implication specify_output_terminal_descriptor RPAREN;
full_path_description:
 LPAREN list_of_path_inputs ( operator_plus_minus )? PATH_FULL list_of_path_outputs RPAREN;
identifier_list: identifier ( COMMA identifier )*;
specparam_declaration:
 KW_SPECPARAM ( packed_dimension )? list_of_specparam_assignments SEMI;
edge_sensitive_path_declaration:
 ( parallel_edge_sensitive_path_description
  | full_edge_sensitive_path_description
  ) ASSIGN path_delay_value;
parallel_edge_sensitive_path_description:
 LPAREN ( edge_identifier )? specify_input_terminal_descriptor any_implication LPAREN
      specify_output_terminal_descriptor ( operator_plus_minus )? COLON data_source_expression RPAREN RPAREN;
full_edge_sensitive_path_description:
 LPAREN ( edge_identifier )? list_of_path_inputs ( operator_plus_minus )? PATH_FULL LPAREN
      list_of_path_outputs ( operator_plus_minus )? COLON data_source_expression RPAREN RPAREN;
data_source_expression: expression;
data_declaration:
 ( KW_CONST )? ( KW_VAR ( lifetime )? ( data_type_or_implicit )?
                  | ( lifetime )? data_type_or_implicit
                  ) list_of_variable_decl_assignments SEMI
  | type_declaration
  | package_import_declaration
  | net_type_declaration
;

module_path_expression: expression;
state_dependent_path_declaration:
 KW_IF LPAREN module_path_expression RPAREN ( simple_path_declaration
                                              | edge_sensitive_path_declaration
                                              )
  | KW_IFNONE simple_path_declaration
;
package_export_declaration:
 KW_EXPORT ( MUL DOUBLE_COLON MUL
              | package_import_item ( COMMA package_import_item )*
              ) SEMI;
genvar_declaration:
 KW_GENVAR identifier_list SEMI;
net_declaration:
 ( KW_INTERCONNECT ( implicit_data_type )? ( HASH delay_value )? identifier ( unpacked_dimension )* (
  COMMA identifier ( unpacked_dimension )* )?
  | ( net_type ( drive_strength
                  | charge_strength
                  )? ( KW_VECTORED
                          | KW_SCALARED
                          )? ( data_type_or_implicit )? ( delay3 )?
      | identifier ( delay_control )?
      ) list_of_net_decl_assignments
  ) SEMI;

parameter_port_list:
    HASH LPAREN (
       ( list_of_param_assignments
         | parameter_port_declaration
       ) ( COMMA parameter_port_declaration )* )? RPAREN;
parameter_port_declaration:
    KW_TYPE list_of_type_assignments
    | parameter_declaration
    | local_parameter_declaration
    | data_type list_of_param_assignments
;

list_of_port_declarations_ansi_item:
	( attribute_instance )* ansi_port_declaration
;
list_of_port_declarations:
    LPAREN
    (
      ( nonansi_port ( COMMA ( nonansi_port )? )* )
      | ( COMMA ( nonansi_port )? )+
      | ( list_of_port_declarations_ansi_item ( COMMA list_of_port_declarations_ansi_item )* )
    )? RPAREN;

nonansi_port_declaration:
   ( attribute_instance )* (
   KW_INOUT ( net_port_type )? list_of_variable_identifiers
  | KW_INPUT ( net_or_var_data_type )? list_of_variable_identifiers
  | KW_OUTPUT ( net_or_var_data_type )? list_of_variable_port_identifiers
  | identifier ( DOT identifier )? list_of_variable_identifiers // identifier=interface_identifier
  | KW_REF ( var_data_type )? list_of_variable_identifiers
  )
;

nonansi_port:
    nonansi_port__expr
    | DOT identifier LPAREN ( nonansi_port__expr )? RPAREN;
nonansi_port__expr:
    identifier_doted_index_at_end
    | LBRACE identifier_doted_index_at_end ( COMMA identifier_doted_index_at_end )* RBRACE
;
port_identifier: identifier;
ansi_port_declaration:
  ( port_direction ( net_or_var_data_type )? // net_port_header
    | net_or_var_data_type                   // net_port_header or variable_port_header
    | (identifier | KW_INTERFACE) (DOT identifier )? // interface_port_header
  )? port_identifier ( variable_dimension )*
   (ASSIGN constant_expression)?
  | (port_direction)? DOT port_identifier LPAREN (expression)? RPAREN
;

/**********************************************************************************************************************/
system_timing_check:
 dolar_setup_timing_check
  | dolar_hold_timing_check
  | dolar_setuphold_timing_check
  | dolar_recovery_timing_check
  | dolar_removal_timing_check
  | dolar_recrem_timing_check
  | dolar_skew_timing_check
  | dolar_timeskew_timing_check
  | dolar_fullskew_timing_check
  | dolar_period_timing_check
  | dolar_width_timing_check
  | dolar_nochange_timing_check
;
dolar_setup_timing_check:
    KW_DOLAR_SETUP LPAREN 
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit ( COMMA ( notifier )? )?
    RPAREN SEMI;
dolar_hold_timing_check:
    KW_DOLAR_HOLD LPAREN
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit ( COMMA ( notifier )? )?
    RPAREN SEMI;
dolar_setuphold_timing_check:
    KW_DOLAR_SETUPHOLD LPAREN
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit COMMA
        timing_check_limit ( COMMA 
            ( notifier )? ( COMMA 
                ( timestamp_condition )? ( COMMA
                    ( timecheck_condition )? ( COMMA
                        ( delayed_reference )? ( COMMA
                            ( delayed_reference )? )? )? )? )? )?
    RPAREN SEMI;
dolar_recovery_timing_check:
    KW_DOLAR_RECOVERY LPAREN
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit ( COMMA ( notifier )? )?
    RPAREN SEMI;
dolar_removal_timing_check:
    KW_DOLAR_REMOVAL LPAREN
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit ( COMMA ( notifier )? )?
    RPAREN SEMI;
dolar_recrem_timing_check:
    KW_DOLAR_RECREM LPAREN
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit COMMA
        timing_check_limit ( COMMA
            ( notifier )? ( COMMA
                ( timestamp_condition )? ( COMMA
                    ( timecheck_condition )? ( COMMA
                        ( delayed_reference )? ( COMMA
                             ( delayed_reference )? )? )? )? )? )?
    RPAREN SEMI;
dolar_skew_timing_check:
    KW_DOLAR_SKEW LPAREN
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit ( COMMA ( notifier )? )?
    RPAREN SEMI;
dolar_timeskew_timing_check:
    KW_DOLAR_TIMESKEW LPAREN 
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit ( COMMA
            ( notifier )? ( COMMA
                ( event_based_flag )? ( COMMA
                    ( remain_active_flag )? )? )? )?
    RPAREN SEMI;
dolar_fullskew_timing_check:
    KW_DOLAR_FULLSKEW LPAREN
        timing_check_event COMMA
        timing_check_event COMMA
        timing_check_limit COMMA
        timing_check_limit ( COMMA
            ( notifier )? ( COMMA
        	     ( event_based_flag )? ( COMMA 
        	          ( remain_active_flag )? )? )? )?
    RPAREN SEMI;
dolar_period_timing_check:
    KW_DOLAR_PERIOD LPAREN
        controlled_reference_event COMMA
        timing_check_limit ( COMMA ( notifier )? )?
    RPAREN SEMI;
dolar_width_timing_check:
    KW_DOLAR_WIDTH LPAREN
        controlled_reference_event COMMA
        timing_check_limit COMMA
        threshold ( COMMA ( notifier )? )?
    RPAREN SEMI;
dolar_nochange_timing_check:
    KW_DOLAR_NOCHANGE LPAREN
    	timing_check_event COMMA
    	timing_check_event COMMA
    	start_edge_offset COMMA
        end_edge_offset ( COMMA ( notifier )? )?
    RPAREN SEMI;
timecheck_condition: mintypmax_expression;
controlled_reference_event: controlled_timing_check_event;
delayed_reference:
    identifier ( LSQUARE_BR constant_mintypmax_expression RSQUARE_BR )?;
end_edge_offset: mintypmax_expression;
event_based_flag: constant_expression;
notifier: identifier;
remain_active_flag: constant_mintypmax_expression;
timestamp_condition: mintypmax_expression;
start_edge_offset: mintypmax_expression;
threshold: constant_expression;
timing_check_limit: expression;
timing_check_event:
    ( timing_check_event_control )? specify_terminal_descriptor
    ( TRIPLE_AND timing_check_condition )?;
timing_check_condition:
    LPAREN scalar_timing_check_condition RPAREN
    | scalar_timing_check_condition
;
scalar_timing_check_condition: expression;
controlled_timing_check_event:
    timing_check_event_control specify_terminal_descriptor ( TRIPLE_AND timing_check_condition )?;
/**********************************************************************************************************************/
function_data_type_or_implicit:
 data_type_or_void
  | implicit_data_type
;
extern_tf_declaration:
 KW_EXTERN ( KW_FORKJOIN task_prototype
              | method_prototype
              ) SEMI;
function_declaration:
    KW_FUNCTION ( lifetime )?
    ( function_data_type_or_implicit )? 
    task_and_function_declaration_common
    KW_ENDFUNCTION ( COLON identifier | {_input->LA(1) != COLON}? )
;
task_prototype: KW_TASK identifier ( LPAREN tf_port_list RPAREN )?;
function_prototype: KW_FUNCTION data_type_or_void identifier ( LPAREN tf_port_list RPAREN )?;
dpi_import_export:
 ( KW_IMPORT STRING_LITERAL ( ( dpi_function_import_property )? ( ( C_IDENTIFIER
                                                                  | ESCAPED_IDENTIFIER
                                                                  ) ASSIGN )? function_prototype
                              | ( dpi_task_import_property )? ( ( C_IDENTIFIER
                                                              | ESCAPED_IDENTIFIER
                                                              ) ASSIGN )? task_prototype
                              )
  | KW_EXPORT STRING_LITERAL ( ( C_IDENTIFIER
                              | ESCAPED_IDENTIFIER
                              ) ASSIGN )? ( KW_FUNCTION
                                              | KW_TASK
                                              ) identifier
  ) SEMI;
dpi_function_import_property:
   KW_CONTEXT
   | KW_PURE
;
dpi_task_import_property: KW_CONTEXT;
task_and_function_declaration_common:
    ( identifier DOT | class_scope )? identifier
    ( SEMI ( tf_item_declaration )*
      | LPAREN tf_port_list RPAREN SEMI ( block_item_declaration )*
    )
    ( statement_or_null )*
;
task_declaration:
    KW_TASK ( lifetime )?
	task_and_function_declaration_common
    KW_ENDTASK ( COLON identifier | {_input->LA(1) != COLON}? )
;
method_prototype:
    task_prototype
    | function_prototype
;
extern_constraint_declaration:
    ( KW_STATIC )? KW_CONSTRAINT class_scope identifier constraint_block;
constraint_block: LBRACE ( constraint_block_item )* RBRACE;
checker_port_list:
    checker_port_item ( COMMA checker_port_item )*;
checker_port_item:
 ( attribute_instance )* ( checker_port_direction )? ( property_formal_type )? identifier
      ( variable_dimension )* ( ASSIGN property_actual_arg )?;
checker_port_direction:
    KW_INPUT
    | KW_OUTPUT
;
checker_declaration:
    KW_CHECKER identifier ( LPAREN ( checker_port_list )? RPAREN )? SEMI 
    ( ( attribute_instance )* checker_or_generate_item )*
    KW_ENDCHECKER ( COLON identifier | {_input->LA(1) != COLON}? );
class_declaration:
    ( KW_VIRTUAL )? KW_CLASS ( lifetime )? identifier ( parameter_port_list )?
    ( KW_EXTENDS class_type ( LPAREN ( list_of_arguments )? RPAREN )? )?
    ( KW_IMPLEMENTS interface_class_type ( COMMA  interface_class_type )* )? SEMI
    ( class_item )*
    KW_ENDCLASS ( COLON identifier | {_input->LA(1) != COLON}? );
always_construct:
    always_keyword statement;
interface_class_type:
    ps_identifier ( parameter_value_assignment )?;
interface_class_declaration:
    KW_INTERFACE KW_CLASS identifier ( parameter_port_list )?
    ( KW_EXTENDS interface_class_type ( COMMA interface_class_type )* )? SEMI
    ( interface_class_item )*
    KW_ENDCLASS ( COLON identifier | {_input->LA(1) != COLON}? );
interface_class_item:
 type_declaration
  | ( attribute_instance )* interface_class_method
  | ( local_parameter_declaration
      | parameter_declaration
      )? SEMI
;
interface_class_method:
 KW_PURE KW_VIRTUAL method_prototype SEMI;
package_declaration:
 ( attribute_instance )* KW_PACKAGE ( lifetime )? identifier SEMI ( timeunits_declaration )?
 ( ( attribute_instance )* package_item )*
  KW_ENDPACKAGE ( COLON identifier | {_input->LA(1) != COLON}?)
;
package_item:
 net_declaration
  | data_declaration
  | task_declaration
  | function_declaration
  | checker_declaration
  | dpi_import_export
  | extern_constraint_declaration
  | class_declaration
  | interface_class_declaration
  | class_constructor_declaration
  | ( local_parameter_declaration
      | parameter_declaration
      )? SEMI
  | covergroup_declaration
  |  property_declaration
  | sequence_declaration
  | let_declaration
  | anonymous_program
  | package_export_declaration
  | timeunits_declaration
;
program_declaration:
 KW_EXTERN program_header
  | ( ( program_header
          | ( attribute_instance )* KW_PROGRAM identifier LPAREN DOT MUL RPAREN SEMI
          ) ( timeunits_declaration )? ( program_item )*
      ) KW_ENDPROGRAM ( COLON identifier | {_input->LA(1) != COLON}? )
;
program_header:
    ( attribute_instance )* KW_PROGRAM ( lifetime )? identifier ( package_import_declaration )*
    ( parameter_port_list )? ( list_of_port_declarations )? SEMI;
program_item:
    nonansi_port_declaration SEMI
    | non_port_program_item
;
non_port_program_item:
 ( attribute_instance )* (
 	continuous_assign
    | ( default_clocking_or_dissable_construct
        | local_parameter_declaration
        | parameter_declaration
       )? SEMI
    | net_declaration
    | data_declaration
    | task_declaration
    | function_declaration
    | checker_declaration
    | dpi_import_export
    | extern_constraint_declaration
    | class_declaration
    | interface_class_declaration
    | class_constructor_declaration
    | covergroup_declaration
    | property_declaration
    | sequence_declaration
    | let_declaration
    | genvar_declaration
    | clocking_declaration
    | initial_construct
    | final_construct
    | concurrent_assertion_item
  )
  | timeunits_declaration
  | program_generate_item
;
anonymous_program: KW_PROGRAM SEMI ( anonymous_program_item )* KW_ENDPROGRAM;
anonymous_program_item:
    SEMI
    | task_declaration
    | function_declaration
    | class_declaration
    | interface_class_declaration
    | covergroup_declaration
    | class_constructor_declaration
;
sequence_declaration:
 KW_SEQUENCE identifier ( LPAREN ( sequence_port_list )? RPAREN )? SEMI
      ( assertion_variable_declaration )* sequence_expr ( SEMI )? KW_ENDSEQUENCE ( COLON identifier
                                              | {_input->LA(1) != COLON}?
                                              );
sequence_port_list: sequence_port_item ( COMMA sequence_port_item )*;
sequence_port_item:
 ( attribute_instance )* ( KW_LOCAL ( sequence_lvar_port_direction )? )? ( sequence_formal_type )?
      identifier ( variable_dimension )* ( ASSIGN sequence_actual_arg )?;
property_declaration:
 KW_PROPERTY identifier ( LPAREN ( property_port_list )? RPAREN )? SEMI
      ( assertion_variable_declaration )* property_spec ( SEMI )? KW_ENDPROPERTY ( COLON identifier
                                              | {_input->LA(1) != COLON}?
                                              );
property_port_list: property_port_item ( COMMA property_port_item )*;
property_port_item:
 ( attribute_instance )* ( KW_LOCAL ( KW_INPUT )? )? ( property_formal_type )? identifier
      ( variable_dimension )* ( ASSIGN property_actual_arg )?;

continuous_assign:
 KW_ASSIGN ( ( drive_strength )? ( delay3 )? list_of_variable_assignments
              | delay_control list_of_variable_assignments
              ) SEMI;
checker_or_generate_item:
 ( KW_RAND )? data_declaration
  | function_declaration
  | checker_declaration
  | property_declaration
  | sequence_declaration
  | let_declaration
  | covergroup_declaration
  | genvar_declaration
  | clocking_declaration
  | ( default_clocking_or_dissable_construct )? SEMI
  | initial_construct
  | always_construct
  | final_construct
  | assertion_item
  | continuous_assign
  | program_generate_item
;
constraint_prototype:
  ( constraint_prototype_qualifier )? ( KW_STATIC )? KW_CONSTRAINT identifier SEMI;
class_constraint:
 constraint_prototype
  | constraint_declaration
;
constraint_declaration:
  ( KW_STATIC )? KW_CONSTRAINT identifier constraint_block;
class_constructor_declaration:
 KW_FUNCTION ( class_scope )? KW_NEW ( LPAREN tf_port_list RPAREN )? SEMI
      ( block_item_declaration )* ( KW_SUPER DOT KW_NEW ( LPAREN ( list_of_arguments )? RPAREN )? SEMI )?
      ( statement_or_null )*
      KW_ENDFUNCTION ( COLON KW_NEW )?;
class_property:
 KW_CONST ( class_item_qualifier )* data_type identifier ( ASSIGN constant_expression )? SEMI
  | ( property_qualifier )* data_declaration
;
class_method:
 KW_PURE KW_VIRTUAL ( class_item_qualifier )* method_prototype SEMI
  | KW_EXTERN ( method_qualifier )* ( method_prototype SEMI
                                      | class_constructor_prototype
                                      )
  | ( method_qualifier )* ( task_declaration
                          | function_declaration
                          | class_constructor_declaration
                          )
;
class_constructor_prototype:
   KW_FUNCTION KW_NEW ( LPAREN tf_port_list RPAREN )? SEMI;
class_item:
 ( attribute_instance )* 
   ( class_property
     | class_method
     | class_constraint
     | class_declaration
     | covergroup_declaration
   )
  | ( local_parameter_declaration
      | parameter_declaration
      )? SEMI
;
parameter_override: KW_DEFPARAM list_of_defparam_assignments SEMI;
/************************************************** gate **************************************************************/
gate_instantiation:
 ( ( KW_PULLDOWN ( pulldown_strength )?
      | KW_PULLUP ( pullup_strength )?
      ) pull_gate_instance ( COMMA pull_gate_instance )*
  | ( cmos_switchtype | mos_switchtype) ( delay3 )? enable_gate_or_mos_switch_or_cmos_switch_instance ( COMMA enable_gate_or_mos_switch_or_cmos_switch_instance )*
  | enable_gatetype ( drive_strength )? ( delay3 )? enable_gate_or_mos_switch_or_cmos_switch_instance ( COMMA enable_gate_or_mos_switch_or_cmos_switch_instance )*
  | n_input_gatetype ( drive_strength )? ( delay2 )? n_input_gate_instance ( COMMA  n_input_gate_instance )*
  | n_output_gatetype ( drive_strength )? ( delay2 )? n_output_gate_instance ( COMMA n_output_gate_instance )*
  | pass_en_switchtype ( delay2 )? pass_enable_switch_instance ( COMMA pass_enable_switch_instance )*
  | pass_switchtype pass_switch_instance ( COMMA pass_switch_instance )*
  ) SEMI
;
enable_gate_or_mos_switch_or_cmos_switch_instance:
 ( name_of_instance )? LPAREN output_terminal COMMA input_terminal COMMA expression ( COMMA expression )? RPAREN;
n_input_gate_instance:
 ( name_of_instance )? LPAREN output_terminal ( COMMA input_terminal )+ RPAREN;
n_output_gate_instance:
 ( name_of_instance )? LPAREN output_terminal ( COMMA output_terminal )* COMMA input_terminal
      RPAREN;
pass_switch_instance:
 ( name_of_instance )? LPAREN inout_terminal COMMA inout_terminal RPAREN;
pass_enable_switch_instance:
 ( name_of_instance )? LPAREN inout_terminal COMMA inout_terminal COMMA enable_terminal RPAREN;
pull_gate_instance:
 ( name_of_instance )? LPAREN output_terminal RPAREN;
pulldown_strength:
 LPAREN ( strength0 ( COMMA strength1 )?
          | strength1 COMMA strength0
          ) RPAREN;
pullup_strength:
 LPAREN ( strength0 COMMA strength1
          | strength1 ( COMMA strength0 )?
          ) RPAREN;
enable_terminal: expression;
inout_terminal: net_lvalue;
input_terminal: expression;
output_terminal: net_lvalue;
// udp_instantiation is designed to match only udp_instantiation which can not match other instantiations
udp_instantiation:
 identifier ( drive_strength ( delay2 )? ( name_of_instance )? 
 			  | delay2 ( name_of_instance )? )?
 udp_instance_body ( COMMA udp_instance )* SEMI;
udp_instance:
 ( name_of_instance )? udp_instance_body;
udp_instance_body:
 LPAREN output_terminal ( COMMA input_terminal )+ RPAREN;
module_or_interface_or_program_or_udp_instantiation:
    identifier ( parameter_value_assignment )?
    hierarchical_instance ( COMMA hierarchical_instance )* SEMI;
hierarchical_instance: name_of_instance LPAREN list_of_port_connections RPAREN;
list_of_port_connections:
    ordered_port_connection ( COMMA ordered_port_connection )*
    | named_port_connection ( COMMA named_port_connection )*
;
ordered_port_connection: ( attribute_instance )* ( expression )?;
named_port_connection:
 ( attribute_instance )* DOT ( MUL
                               | identifier ( LPAREN ( expression )? RPAREN )?
                              );
bind_directive:
 KW_BIND ( identifier ( COLON bind_target_instance_list )?
          | bind_target_instance
          ) bind_instantiation;
bind_target_instance: hierarchical_identifier ( bit_select )*;
bind_target_instance_list: bind_target_instance ( COMMA bind_target_instance )*;
bind_instantiation:
 module_or_interface_or_program_or_udp_instantiation
  | checker_instantiation
;
config_declaration:
 KW_CONFIG identifier SEMI ( local_parameter_declaration SEMI )* design_statement
      ( config_rule_statement )* KW_ENDCONFIG ( COLON identifier
                      | {_input->LA(1) != COLON}?
                      );
design_statement: KW_DESIGN ( ( identifier DOT )? identifier )* SEMI;
config_rule_statement:
 ( KW_DEFAULT liblist_clause
   | ( inst_clause
       | cell_clause
     ) ( liblist_clause
         | use_clause
       )
 ) SEMI;
inst_clause: KW_INSTANCE inst_name;
inst_name: identifier ( DOT identifier )*;
cell_clause: KW_CELL ( identifier DOT )? identifier;
liblist_clause: KW_LIBLIST ( identifier )*;
use_clause:
    KW_USE ( ( identifier DOT )? identifier
             ( named_parameter_assignment ( COMMA named_parameter_assignment )* )?
             | named_parameter_assignment ( COMMA named_parameter_assignment )*
             ) ( COLON KW_CONFIG )?;
net_alias: KW_ALIAS net_lvalue ( ASSIGN net_lvalue )+ SEMI;
specify_block: KW_SPECIFY ( specify_item )* KW_ENDSPECIFY;
/****************************************** generate ******************************************************************/
generate_region: KW_GENERATE ( generate_item )* KW_ENDGENERATE;
genvar_expression: constant_expression;
loop_generate_construct:
    KW_FOR LPAREN genvar_initialization SEMI genvar_expression SEMI genvar_iteration RPAREN
      generate_item;
genvar_initialization:
    ( KW_GENVAR )? identifier ASSIGN constant_expression;
genvar_iteration:
    identifier ( assignment_operator genvar_expression
                 | inc_or_dec_operator
                 )
    | inc_or_dec_operator identifier
;
conditional_generate_construct:
    if_generate_construct
    | case_generate_construct
;
if_generate_construct:
    KW_IF LPAREN constant_expression RPAREN generate_item 
    ( KW_ELSE generate_item | {_input->LA(1) != KW_ELSE}? );
case_generate_construct:
    KW_CASE LPAREN constant_expression RPAREN ( case_generate_item )+ KW_ENDCASE;
case_generate_item:
    ( KW_DEFAULT ( COLON )?
      | constant_expression ( COMMA constant_expression )* COLON
    ) generate_item;
generate_begin_end_block:
    ( identifier COLON )? KW_BEGIN ( COLON identifier | {_input->LA(1) != COLON}? )
        ( generate_item )*
    KW_END ( COLON identifier | {_input->LA(1) != COLON}? )
;
generate_item:
    ( attribute_instance )* 
		( module_or_generate_item
          | extern_tf_declaration
        )
        | KW_RAND data_declaration
        | generate_region
        | generate_begin_end_block
;
program_generate_item:
    loop_generate_construct
    | conditional_generate_construct
    | generate_region
    | elaboration_system_task
;
module_or_generate_item:
    parameter_override
    | gate_instantiation
    | udp_instantiation
    | module_or_interface_or_program_or_udp_instantiation
    | ( default_clocking_or_dissable_construct
        | local_parameter_declaration
        | parameter_declaration )? SEMI
    | net_declaration
    | data_declaration
    | task_declaration
    | function_declaration
    | checker_declaration
    | dpi_import_export
    | extern_constraint_declaration
    | class_declaration
    | interface_class_declaration
    | class_constructor_declaration
    | covergroup_declaration
    | property_declaration
    | sequence_declaration
    | let_declaration
    | genvar_declaration
    | clocking_declaration
    | assertion_item
    | bind_directive
    | continuous_assign
    | net_alias
    | initial_construct
    | final_construct
    | always_construct
    | loop_generate_construct
    | conditional_generate_construct
    | elaboration_system_task
;
/**********************************************************************************************************************/
elaboration_system_task:
    ( KW_DOLAR_FATAL ( LPAREN UNSIGNED_NUMBER ( COMMA ( list_of_arguments )? )? RPAREN )?
     | ( KW_DOLAR_ERROR
         | KW_DOLAR_WARNING
         | KW_DOLAR_INFO
         ) ( LPAREN ( list_of_arguments )? RPAREN )?
    ) SEMI
;
/************************************************* module item  *******************************************************/
module_item_item:
    module_or_generate_item
    | specparam_declaration
;
module_item:
    generate_region
    | ( attribute_instance )* module_item_item
    | specify_block
    | program_declaration
    | module_declaration
    | interface_declaration
    | timeunits_declaration
    | nonansi_port_declaration SEMI
;
