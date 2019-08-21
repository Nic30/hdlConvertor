parser grammar sv2017Parser;
options { tokenVocab=sv2017Lexer; }

source_text:
 ( timeunits_declaration )? ( description )* EOF;
description:
 module_declaration 
  | udp_declaration 
  | interface_declaration 
  | program_declaration 
  | package_declaration 
  | ( attribute_instance )* ( package_item 
                              | bind_directive 
                              ) 
  | config_declaration 
 ;
module_nonansi_header:
 ( attribute_instance )* module_keyword ( lifetime )? identifier ( package_import_declaration )* 
      ( parameter_port_list )? list_of_ports SEMI;
module_ansi_header:
 ( attribute_instance )* module_keyword ( lifetime )? identifier ( package_import_declaration )* 
      ( parameter_port_list )? ( list_of_port_declarations )? SEMI;
module_declaration:
 KW_EXTERN ( module_nonansi_header 
              | module_ansi_header 
              ) 
  | ( ( module_nonansi_header 
          | ( attribute_instance )* module_keyword ( lifetime )? identifier LPAREN DOT MUL RPAREN 
          SEMI 
          ) ( timeunits_declaration )? ( module_item )* 
      | module_ansi_header ( timeunits_declaration )? ( non_port_module_item )* 
      ) KW_ENDMODULE ( COLON identifier )? 
 ;
module_keyword:
 KW_MODULE 
  | KW_MACROMODULE 
 ;
interface_declaration:
 KW_EXTERN ( interface_nonansi_header 
              | interface_ansi_header 
              ) 
  | ( ( interface_nonansi_header 
          | ( attribute_instance )* KW_INTERFACE identifier LPAREN DOT MUL RPAREN SEMI 
          ) ( timeunits_declaration )? ( interface_item )* 
      | interface_ansi_header ( timeunits_declaration )? ( non_port_interface_item )* 
      ) KW_ENDINTERFACE ( COLON identifier )? 
 ;
interface_nonansi_header:
 ( attribute_instance )* KW_INTERFACE ( lifetime )? identifier ( package_import_declaration )* 
      ( parameter_port_list )? list_of_ports SEMI;
interface_ansi_header:
 ( attribute_instance )* KW_INTERFACE ( lifetime )? identifier ( package_import_declaration )* 
      ( parameter_port_list )? ( list_of_port_declarations )? SEMI;
program_declaration:
 KW_EXTERN ( program_nonansi_header 
              | program_ansi_header 
              ) 
  | ( ( program_nonansi_header 
          | ( attribute_instance )* KW_PROGRAM identifier LPAREN DOT MUL RPAREN SEMI 
          ) ( timeunits_declaration )? ( program_item )* 
      | program_ansi_header ( timeunits_declaration )? ( non_port_program_item )* 
      ) KW_ENDPROGRAM ( COLON identifier )? 
 ;
program_nonansi_header:
 ( attribute_instance )* KW_PROGRAM ( lifetime )? identifier ( package_import_declaration )* 
      ( parameter_port_list )? list_of_ports SEMI;
program_ansi_header:
 ( attribute_instance )* KW_PROGRAM ( lifetime )? identifier ( package_import_declaration )* 
      ( parameter_port_list )? ( list_of_port_declarations )? SEMI;
checker_declaration:
 KW_CHECKER identifier ( LPAREN ( checker_port_list )? RPAREN )? SEMI ( ( attribute_instance )* 
      checker_or_generate_item )* KW_ENDCHECKER ( COLON identifier )?;
class_declaration:
 ( KW_VIRTUAL )? KW_CLASS ( lifetime )? identifier ( parameter_port_list )? ( KW_EXTENDS class_type ( 
      LPAREN list_of_arguments RPAREN )? )? ( KW_IMPLEMENTS interface_class_type ( COMMA 
      interface_class_type )* )? SEMI ( class_item )* KW_ENDCLASS ( COLON identifier )?;
interface_class_type:
 ps_identifier ( parameter_value_assignment )?;
interface_class_declaration:
 KW_INTERFACE KW_CLASS identifier ( parameter_port_list )? ( KW_EXTENDS interface_class_type ( COMMA 
      interface_class_type )* )? SEMI ( interface_class_item )* KW_ENDCLASS ( COLON identifier )?;
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
 ( attribute_instance )* KW_PACKAGE ( lifetime )? identifier SEMI ( timeunits_declaration )? ( 
      ( attribute_instance )* package_item )* KW_ENDPACKAGE ( COLON identifier )?;
timeunits_declaration:
 KW_TIMEUNIT TIME_LITERAL ( ( DIV 
                              | SEMI KW_TIMEPRECISION 
                              ) TIME_LITERAL )? SEMI 
  | KW_TIMEPRECISION TIME_LITERAL SEMI ( KW_TIMEUNIT TIME_LITERAL SEMI )? 
 ;
parameter_port_list:
 HASH LPAREN ( ( list_of_param_assignments 
              | parameter_port_declaration 
              ) ( COMMA parameter_port_declaration )* )? RPAREN;
parameter_port_declaration:
 KW_TYPE list_of_type_assignments 
  | parameter_declaration 
  | local_parameter_declaration 
  | data_type list_of_param_assignments 
 ;
list_of_ports:
 LPAREN ( port )? ( COMMA ( port )? )* RPAREN;
list_of_port_declarations:
 LPAREN ( ( attribute_instance )* ansi_port_declaration ( COMMA ( attribute_instance )* 
      ansi_port_declaration )* )? RPAREN;
port_declaration:
 ( attribute_instance )* ( inout_declaration 
                          | input_declaration 
                          | output_declaration 
                          | ref_declaration 
                          | interface_port_declaration 
                          );
port:
 DOT identifier LPAREN ( port_expression )? RPAREN 
  | port_expression 
 ;
port_expression:
 LBRACE port_reference ( COMMA port_reference )* RBRACE 
  | port_reference 
 ;
port_reference:
 identifier constant_select;
port_direction:
 KW_INPUT 
  | KW_OUTPUT 
  | KW_INOUT 
  | KW_REF 
 ;
ansi_port_declaration:
 ( ( port_direction ( net_port_type )? 
          | net_port_type 
          | ( KW_INTERFACE 
              | identifier 
              ) ( DOT identifier )? 
          )? identifier ( unpacked_dimension )* 
      | ( port_direction )? ( var_data_type )? identifier ( variable_dimension )* 
      ) ( ASSIGN constant_expression )? 
  | ( port_direction )? DOT identifier LPAREN ( expression )? RPAREN 
 ;
elaboration_system_task:
 ( KW_DOLAR_FATAL ( LPAREN UNSIGNED_NUMBER ( COMMA list_of_arguments )? RPAREN )? 
  | ( KW_DOLAR_ERROR 
      | KW_DOLAR_WARNING 
      | KW_DOLAR_INFO 
      ) ( LPAREN list_of_arguments RPAREN )? 
  ) SEMI;
module_item:
 port_declaration SEMI 
  | non_port_module_item 
 ;
non_port_module_item:
 generate_region 
  | ( attribute_instance )* ( parameter_override 
                              | gate_instantiation 
                              | udp_instantiation 
                              | module_instantiation 
                              | ( KW_DEFAULT ( KW_CLOCKING identifier 
                                              | KW_DISABLE KW_IFF expression_or_dist 
                                              ) 
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
                              | assertion_item_declaration 
                              | genvar_declaration 
                              | clocking_declaration 
                              | interface_instantiation 
                              | program_instantiation 
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
                              | specparam_declaration 
                              ) 
  | specify_block 
  | program_declaration 
  | module_declaration 
  | interface_declaration 
  | timeunits_declaration 
 ;
parameter_override:
 KW_DEFPARAM list_of_defparam_assignments SEMI;
bind_directive:
 KW_BIND ( identifier ( COLON bind_target_instance_list )? 
          | bind_target_instance 
          ) bind_instantiation SEMI;
bind_target_instance:
 hierarchical_identifier ( constant_bit_select )*;
bind_target_instance_list:
 bind_target_instance ( COMMA bind_target_instance )*;
bind_instantiation:
 program_instantiation 
  | module_instantiation 
  | interface_instantiation 
  | checker_instantiation 
 ;
config_declaration:
 KW_CONFIG identifier SEMI ( local_parameter_declaration SEMI )* design_statement 
      ( config_rule_statement )* KW_ENDCONFIG ( COLON identifier )?;
design_statement:
 KW_DESIGN ( ( identifier DOT )? identifier )* SEMI;
config_rule_statement:
 ( KW_DEFAULT liblist_clause 
  | ( inst_clause 
      | cell_clause 
      ) ( liblist_clause 
          | use_clause 
          ) 
  ) SEMI;
inst_clause:
 KW_INSTANCE inst_name;
inst_name:
 identifier ( DOT identifier )*;
cell_clause:
 KW_CELL ( identifier DOT )? identifier;
liblist_clause:
 KW_LIBLIST ( identifier )*;
use_clause:
 KW_USE ( ( identifier DOT )? identifier ( named_parameter_assignment ( COMMA 
          named_parameter_assignment )* )? 
          | named_parameter_assignment ( COMMA named_parameter_assignment )* 
          ) ( COLON KW_CONFIG )?;
extern_tf_declaration:
 KW_EXTERN ( KW_FORKJOIN task_prototype 
              | method_prototype 
              ) SEMI;
interface_item:
 port_declaration SEMI 
  | non_port_interface_item 
 ;
non_port_interface_item:
 generate_region 
  | ( attribute_instance )* ( ( KW_DEFAULT ( KW_CLOCKING identifier 
                                              | KW_DISABLE KW_IFF expression_or_dist 
                                              ) 
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
                              | assertion_item_declaration 
                              | genvar_declaration 
                              | clocking_declaration 
                              | interface_instantiation 
                              | program_instantiation 
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
program_item:
 port_declaration SEMI 
  | non_port_program_item 
 ;
non_port_program_item:
 ( attribute_instance )* ( continuous_assign 
                              | ( KW_DEFAULT ( KW_CLOCKING identifier 
                                              | KW_DISABLE KW_IFF expression_or_dist 
                                              ) 
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
                              | assertion_item_declaration 
                              | genvar_declaration 
                              | clocking_declaration 
                              | initial_construct 
                              | final_construct 
                              | concurrent_assertion_item 
                              ) 
  | timeunits_declaration 
  | program_generate_item 
 ;
program_generate_item:
 loop_generate_construct 
  | conditional_generate_construct 
  | generate_region 
  | elaboration_system_task 
 ;
checker_port_list:
 checker_port_item ( COMMA checker_port_item )*;
checker_port_item:
 ( attribute_instance )* ( checker_port_direction )? ( property_formal_type )? identifier 
      ( variable_dimension )* ( ASSIGN property_actual_arg )?;
checker_port_direction:
 KW_INPUT 
  | KW_OUTPUT 
 ;
checker_or_generate_item:
 ( KW_RAND )? data_declaration 
  | function_declaration 
  | checker_declaration 
  | assertion_item_declaration 
  | covergroup_declaration 
  | genvar_declaration 
  | clocking_declaration 
  | ( KW_DEFAULT ( KW_CLOCKING identifier 
              | KW_DISABLE KW_IFF expression_or_dist 
              ) )? SEMI 
  | initial_construct 
  | always_construct 
  | final_construct 
  | assertion_item 
  | continuous_assign 
  | program_generate_item 
 ;
class_item:
 ( attribute_instance )* ( class_property 
                              | class_method 
                              | class_constraint 
                              | class_declaration 
                              | interface_class_declaration 
                              | covergroup_declaration 
                              ) 
  | ( local_parameter_declaration 
      | parameter_declaration 
      )? SEMI 
 ;
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
class_constraint:
 constraint_prototype 
  | constraint_declaration 
 ;
class_item_qualifier:
 KW_STATIC 
  | KW_PROTECTED 
  | KW_LOCAL 
 ;
property_qualifier:
 random_qualifier 
  | class_item_qualifier 
 ;
random_qualifier:
 KW_RAND 
  | KW_RANDC 
 ;
method_qualifier:
 ( KW_PURE )? KW_VIRTUAL 
  | class_item_qualifier 
 ;
method_prototype:
 task_prototype 
  | function_prototype 
 ;
class_constructor_declaration:
 KW_FUNCTION ( class_scope )? KW_NEW ( LPAREN tf_port_list RPAREN )? SEMI 
      ( block_item_declaration )* ( KW_SUPER DOT KW_NEW ( LPAREN list_of_arguments RPAREN )? SEMI )? ( statement_or_null )* 
      KW_ENDFUNCTION ( COLON KW_NEW )?;
constraint_declaration:
 ( KW_STATIC )? KW_CONSTRAINT identifier constraint_block;
constraint_block:
 LBRACE ( constraint_block_item )* RBRACE;
constraint_block_item:
 KW_SOLVE solve_before_list KW_BEFORE solve_before_list SEMI 
  | constraint_expression 
 ;
solve_before_list:
 constraint_primary ( COMMA constraint_primary )*;
constraint_primary:
 ( implicit_class_handle DOT 
  | class_scope 
  )? hierarchical_identifier select;
constraint_expression:
 KW_IF LPAREN expression RPAREN constraint_set ( KW_ELSE constraint_set )? 
  | ( KW_DISABLE KW_SOFT constraint_primary 
      | ( KW_SOFT )? expression_or_dist 
      | uniqueness_constraint 
      ) SEMI 
  | ( KW_FOREACH LPAREN foreach_ps_or_hierarchical_array_identifier LSQUARE_BR loop_variables 
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
dist_list:
 dist_item ( COMMA dist_item )*;
dist_item:
 value_range ( dist_weight )?;
dist_weight:
 ( DIST_WEIGHT_ASSIGN 
  | DIST_WEIGHT_ASSIGN_DIV 
  ) expression;
constraint_prototype:
 ( constraint_prototype_qualifier )? ( KW_STATIC )? KW_CONSTRAINT identifier SEMI;
constraint_prototype_qualifier:
 KW_EXTERN 
  | KW_PURE 
 ;
extern_constraint_declaration:
 ( KW_STATIC )? KW_CONSTRAINT class_scope identifier constraint_block;
identifier_list:
 identifier ( COMMA identifier )*;
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
  | assertion_item_declaration 
  | anonymous_program 
  | package_export_declaration 
  | timeunits_declaration 
 ;
anonymous_program:
 KW_PROGRAM SEMI ( anonymous_program_item )* KW_ENDPROGRAM;
anonymous_program_item:
 SEMI 
  | task_declaration 
  | function_declaration 
  | class_declaration 
  | interface_class_declaration 
  | covergroup_declaration 
  | class_constructor_declaration 
 ;
local_parameter_declaration:
 KW_LOCALPARAM ( KW_TYPE list_of_type_assignments 
                  | ( data_type_or_implicit )? list_of_param_assignments 
                  );
parameter_declaration:
 KW_PARAMETER ( KW_TYPE list_of_type_assignments 
                  | ( data_type_or_implicit )? list_of_param_assignments 
                  );
specparam_declaration:
 KW_SPECPARAM ( packed_dimension )? list_of_specparam_assignments SEMI;
inout_declaration:
 KW_INOUT ( net_port_type )? list_of_port_identifiers;
input_declaration:
 KW_INPUT ( ( net_port_type )? list_of_port_identifiers 
              | ( var_data_type )? list_of_variable_identifiers 
              );
output_declaration:
 KW_OUTPUT ( ( net_port_type )? list_of_port_identifiers 
              | ( var_data_type )? list_of_variable_port_identifiers 
              );
interface_port_declaration:
 identifier ( DOT identifier )? list_of_interface_identifiers;
ref_declaration:
 KW_REF ( var_data_type )? list_of_variable_identifiers;
data_declaration:
 ( KW_CONST )? ( KW_VAR )? ( lifetime )? ( data_type_or_implicit )? 
  list_of_variable_decl_assignments SEMI 
  | type_declaration 
  | package_import_declaration 
  | net_type_declaration 
 ;
package_import_declaration:
 KW_IMPORT package_import_item ( COMMA package_import_item )* SEMI;
package_import_item:
 identifier DOUBLE_COLON ( MUL 
                          | identifier 
                          );
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
type_declaration:
 KW_TYPEDEF ( data_type identifier ( variable_dimension )* 
              | ( KW_ENUM 
                  | KW_STRUCT 
                  | KW_UNION 
                  | identifier ( constant_bit_select )* DOT identifier 
                  | ( KW_INTERFACE )? KW_CLASS 
                  )? identifier 
              ) SEMI;
net_type_declaration:
 KW_NETTYPE ( data_type identifier ( KW_WITH package_or_class_scoped_id )? 
              | package_or_class_scoped_id identifier 
              ) SEMI;
lifetime:
 KW_STATIC 
  | KW_AUTOMATIC 
 ;
casting_type:
 KW_STRING 
  | KW_CONST 
  | simple_type 
  | constant_primary_no_cast_no_call 
  | signing 
 ;
data_type:
 KW_STRING 
  | KW_CHANDLE 
  | KW_VIRTUAL ( KW_INTERFACE )? identifier ( parameter_value_assignment )? ( DOT identifier )? 
  | KW_EVENT 
  | ( integer_vector_type ( signing )? 
      | ( KW_ENUM ( enum_base_type )? LBRACE enum_name_declaration 
          ( COMMA enum_name_declaration )* 
          | struct_union ( KW_PACKED ( signing )? )? LBRACE struct_union_member 
          ( struct_union_member )* 
          ) RBRACE 
      | package_or_class_scoped_id 
      ) ( packed_dimension )* 
  | integer_atom_type ( signing )? 
  | non_integer_type 
  | class_type 
  | ps_identifier 
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
enum_base_type:
 integer_atom_type ( signing )? 
  | ( integer_vector_type ( signing )? 
      | identifier 
      ) ( packed_dimension )? 
 ;
enum_name_declaration:
 identifier ( LSQUARE_BR integral_number ( COLON integral_number )? RSQUARE_BR )? ( ASSIGN 
      constant_expression )?;
class_scope:
 ps_identifier ( parameter_value_assignment )? ( DOUBLE_COLON identifier 
      ( parameter_value_assignment )? )* DOUBLE_COLON;
class_type:
 ps_identifier ( parameter_value_assignment )? ( DOUBLE_COLON identifier 
      ( parameter_value_assignment )? )*;
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
net_port_type:
 KW_INTERCONNECT ( implicit_data_type )? 
  | net_type ( data_type_or_implicit )? 
  | data_type_or_implicit 
 ;
var_data_type:
 KW_VAR ( data_type_or_implicit )? 
  | data_type 
 ;
signing:
 KW_SIGNED 
  | KW_UNSIGNED 
 ;
simple_type:
 integer_type 
  | non_integer_type 
  | ps_type_identifier 
  | ps_parameter_identifier 
 ;
struct_union_member:
 ( attribute_instance )* ( random_qualifier )? data_type_or_void list_of_variable_decl_assignments 
      SEMI;
data_type_or_void:
 KW_VOID 
  | data_type 
 ;
struct_union:
 KW_STRUCT 
  | KW_UNION ( KW_TAGGED )? 
 ;
type_reference:
 KW_TYPE LPAREN ( expression 
                  | data_type 
                  ) RPAREN;
drive_strength:
 LPAREN ( KW_HIGHZ0 COMMA strength1 
          | KW_HIGHZ1 COMMA strength0 
          | strength0 COMMA ( KW_HIGHZ1 
                              | strength1 
                              ) 
          | strength1 COMMA ( KW_HIGHZ0 
                              | strength0 
                              ) 
          ) RPAREN;
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
delay3:
 HASH ( LPAREN mintypmax_expression 
          ( COMMA mintypmax_expression ( COMMA mintypmax_expression )? )? RPAREN 
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
list_of_defparam_assignments:
 defparam_assignment ( COMMA defparam_assignment )*;
list_of_interface_identifiers:
 identifier ( unpacked_dimension )* ( COMMA identifier ( unpacked_dimension )* )*;
list_of_net_decl_assignments:
 net_decl_assignment ( COMMA net_decl_assignment )*;
list_of_param_assignments:
 param_assignment ( COMMA param_assignment )*;
list_of_port_identifiers:
 identifier ( unpacked_dimension )* ( COMMA identifier ( unpacked_dimension )* )*;
list_of_specparam_assignments:
 specparam_assignment ( COMMA specparam_assignment )*;
list_of_tf_variable_identifiers:
 identifier ( variable_dimension )* ( ASSIGN expression )? ( COMMA identifier 
      ( variable_dimension )* ( ASSIGN expression )? )*;
list_of_type_assignments:
 type_assignment ( COMMA type_assignment )*;
list_of_variable_decl_assignments:
 variable_decl_assignment ( COMMA variable_decl_assignment )*;
list_of_variable_identifiers:
 identifier ( variable_dimension )* ( COMMA identifier ( variable_dimension )* )*;
list_of_variable_port_identifiers:
 identifier ( variable_dimension )* ( ASSIGN constant_expression )? ( COMMA identifier 
      ( variable_dimension )* ( ASSIGN constant_expression )? )*;
defparam_assignment:
 hierarchical_identifier ASSIGN constant_mintypmax_expression;
net_decl_assignment:
 identifier ( unpacked_dimension )* ( ASSIGN expression )?;
param_assignment:
 identifier ( unpacked_dimension )* ( ASSIGN constant_param_expression )?;
specparam_assignment:
 identifier ASSIGN constant_mintypmax_expression 
  | pulse_control_specparam 
 ;
type_assignment:
 identifier ( ASSIGN data_type )?;
pulse_control_specparam:
 KW_PATHPULSEDOLAR_ 
      ( specify_input_terminal_descriptor DOLAR specify_output_terminal_descriptor )? ASSIGN LPAREN reject_limit_value ( COMMA error_limit_value )? RPAREN;
error_limit_value: constant_mintypmax_expression;
reject_limit_value: constant_mintypmax_expression;
variable_decl_assignment:
 identifier ( ASSIGN ( expression 
                      | class_new 
                      ) 
              | ( variable_dimension )+ ( ASSIGN expression )? 
              | unsized_dimension ( variable_dimension )* ( ASSIGN dynamic_array_new )? 
              )?;
class_new:
 KW_NEW expression 
  | ( class_scope )? KW_NEW ( LPAREN list_of_arguments RPAREN )? 
 ;
dynamic_array_new:
 KW_NEW LSQUARE_BR expression RSQUARE_BR ( LPAREN expression RPAREN )?;
unpacked_dimension:
 LSQUARE_BR ( constant_range 
              | constant_expression 
              ) RSQUARE_BR;
packed_dimension:
 LSQUARE_BR constant_range RSQUARE_BR 
  | unsized_dimension 
 ;
associative_dimension:
 LSQUARE_BR ( MUL 
              | data_type 
              ) RSQUARE_BR;
variable_dimension:
 unsized_dimension 
  | unpacked_dimension 
  | associative_dimension 
  | queue_dimension 
 ;
queue_dimension:
 LSQUARE_BR DOLAR ( COLON constant_expression )? RSQUARE_BR;
unsized_dimension:
 LSQUARE_BR RSQUARE_BR;
function_data_type_or_implicit:
 data_type_or_void 
  | implicit_data_type 
 ;
function_declaration:
 KW_FUNCTION ( lifetime )? function_body_declaration;
function_body_declaration:
 ( function_data_type_or_implicit )? ( identifier DOT 
                                      | class_scope 
                                      )? identifier ( SEMI ( tf_item_declaration )* 
                                                          | LPAREN tf_port_list RPAREN SEMI 
                                                          ( block_item_declaration )* 
                                                          ) ( statement_or_null )* KW_ENDFUNCTION ( 
      COLON identifier )?;
function_prototype:
 KW_FUNCTION data_type_or_void identifier ( LPAREN tf_port_list RPAREN )?;
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
task_declaration:
 KW_TASK ( lifetime )? task_body_declaration;
task_body_declaration:
 ( identifier DOT 
  | class_scope 
  )? identifier ( SEMI ( tf_item_declaration )* 
                      | LPAREN tf_port_list RPAREN SEMI ( block_item_declaration )* 
                      ) ( statement_or_null )* KW_ENDTASK ( COLON identifier )?;
tf_item_declaration:
 block_item_declaration 
  | tf_port_declaration 
 ;
tf_port_list:
 tf_port_item ( COMMA tf_port_item )*;
tf_port_item:
 ( attribute_instance )* ( tf_port_direction )? ( KW_VAR )? ( data_type_or_implicit )? ( identifier 
      ( variable_dimension )* ( ASSIGN expression )? )?;
tf_port_direction:
 KW_CONST KW_REF 
  | port_direction 
 ;
tf_port_declaration:
 ( attribute_instance )* tf_port_direction ( KW_VAR )? ( data_type_or_implicit )? 
      list_of_tf_variable_identifiers SEMI;
task_prototype:
 KW_TASK identifier ( LPAREN tf_port_list RPAREN )?;
block_item_declaration:
 ( attribute_instance )* ( data_declaration 
                          | ( local_parameter_declaration 
                              | parameter_declaration 
                              ) SEMI 
                          | let_declaration 
                          );
modport_declaration:
 KW_MODPORT modport_item ( COMMA modport_item )* SEMI;
modport_item:
 identifier LPAREN modport_ports_declaration ( COMMA modport_ports_declaration )* RPAREN;
modport_ports_declaration:
 ( attribute_instance )* ( modport_simple_ports_declaration 
                          | modport_tf_ports_declaration 
                          | modport_clocking_declaration 
                          );
modport_clocking_declaration:
 KW_CLOCKING identifier;
modport_simple_ports_declaration:
 port_direction modport_simple_port ( COMMA modport_simple_port )*;
modport_simple_port:
 DOT identifier LPAREN ( expression )? RPAREN 
  | identifier 
 ;
modport_tf_ports_declaration:
 import_export modport_tf_port ( COMMA modport_tf_port )*;
modport_tf_port:
 method_prototype 
  | identifier 
 ;
import_export:
 KW_IMPORT 
  | KW_EXPORT 
 ;
concurrent_assertion_item:
 ( identifier COLON )? concurrent_assertion_statement 
  | checker_instantiation 
 ;
concurrent_assertion_statement:
 ( KW_ASSERT 
      | KW_ASSUME 
      ) KW_PROPERTY LPAREN property_spec RPAREN action_block 
  | KW_COVER ( KW_PROPERTY LPAREN property_spec 
              | KW_SEQUENCE LPAREN ( clocking_event )? ( KW_DISABLE KW_IFF LPAREN expression_or_dist 
              RPAREN )? sequence_expr 
              ) RPAREN statement_or_null 
  | KW_RESTRICT KW_PROPERTY LPAREN property_spec RPAREN SEMI 
 ;
expect_property_statement:
 KW_EXPECT LPAREN property_spec RPAREN action_block;
property_instance:
 ps_or_hierarchical_identifier ( LPAREN property_list_of_arguments RPAREN )?;
property_list_of_arguments:
 ( DOT identifier LPAREN ( property_actual_arg )? RPAREN 
  | property_actual_arg ( COMMA ( property_actual_arg )? )* 
  | ( COMMA ( property_actual_arg )? )+ 
  )? ( COMMA DOT identifier LPAREN ( property_actual_arg )? RPAREN )*;
property_actual_arg:
 property_expr 
  | sequence_actual_arg 
 ;
assertion_item_declaration:
 property_declaration 
  | sequence_declaration 
  | let_declaration 
 ;
property_declaration:
 KW_PROPERTY identifier ( LPAREN ( property_port_list )? RPAREN )? SEMI 
      ( assertion_variable_declaration )* property_spec ( SEMI )? KW_ENDPROPERTY ( COLON identifier )?;
property_port_list:
 property_port_item ( COMMA property_port_item )*;
property_port_item:
 ( attribute_instance )* ( KW_LOCAL ( KW_INPUT )? )? ( property_formal_type )? identifier 
      ( variable_dimension )* ( ASSIGN property_actual_arg )?;
property_formal_type:
 KW_PROPERTY 
  | sequence_formal_type 
 ;
property_spec:
 ( clocking_event )? ( KW_DISABLE KW_IFF LPAREN expression_or_dist RPAREN )? property_expr;
property_expr:
 property_expr_item ( ( KW_OR 
                      | KW_AND 
                      | KW_UNTIL 
                      | KW_S_UNTIL 
                      | KW_UNTIL_WITH 
                      | KW_S_UNTIL_WITH 
                      | KW_IMPLIES 
                      | KW_IFF 
                      ) property_expr )*;
property_expr_item:
 ( ( KW_STRONG 
          | KW_WEAK 
          ) LPAREN sequence_expr 
      | LPAREN property_expr 
      ) RPAREN 
  | KW_IF LPAREN expression_or_dist RPAREN property_expr ( KW_ELSE property_expr )? 
  | KW_CASE LPAREN expression_or_dist RPAREN property_case_item ( property_case_item )* KW_ENDCASE 
  | sequence_expr ( ( OVERLAPPING_IMPL 
                  | NONOVERLAPPING_IMPL 
                  | HASH_MINUS_HASH 
                  | HASH_EQ_HASH 
                  ) property_expr )? 
  | ( KW_NOT 
      | ( KW_S_ALWAYS 
          | KW_EVENTUALLY 
          ) LSQUARE_BR constant_range RSQUARE_BR 
      | ( KW_ACCEPT_ON 
          | KW_REJECT_ON 
          | KW_SYNC_ACCEPT_ON 
          | KW_SYNC_REJECT_ON 
          ) LPAREN expression_or_dist RPAREN 
      | ( KW_NEXTTIME 
          | KW_S_NEXTTIME 
          ) ( LSQUARE_BR constant_expression RSQUARE_BR )? 
      | ( KW_ALWAYS 
          | KW_S_EVENTUALLY 
          ) ( LSQUARE_BR cycle_delay_const_range_expression RSQUARE_BR )? 
      | clocking_event 
      ) property_expr 
  | property_instance 
 ;
property_case_item:
 ( KW_DEFAULT ( COLON )? 
  | expression_or_dist ( COMMA expression_or_dist )* COLON 
  ) property_expr SEMI;
sequence_declaration:
 KW_SEQUENCE identifier ( LPAREN ( sequence_port_list )? RPAREN )? SEMI 
      ( assertion_variable_declaration )* sequence_expr ( SEMI )? KW_ENDSEQUENCE ( COLON identifier )?;
sequence_port_list:
 sequence_port_item ( COMMA sequence_port_item )*;
sequence_port_item:
 ( attribute_instance )* ( KW_LOCAL ( sequence_lvar_port_direction )? )? ( sequence_formal_type )? 
      identifier ( variable_dimension )* ( ASSIGN sequence_actual_arg )?;
sequence_lvar_port_direction:
 KW_INPUT 
  | KW_INOUT 
  | KW_OUTPUT 
 ;
sequence_formal_type:
 KW_SEQUENCE 
  | KW_UNTYPED 
  | data_type_or_implicit 
 ;
sequence_expr:
 sequence_expr_item ( ( KW_AND 
                          | KW_INTERSECT 
                          | KW_OR 
                          | KW_WITHIN 
                          ) sequence_expr 
                      | cycle_delay_range sequence_expr ( cycle_delay_range sequence_expr )* 
                      )*;
sequence_expr_item:
 KW_FIRST_MATCH LPAREN sequence_expr ( COMMA sequence_match_item )* RPAREN 
  | cycle_delay_range sequence_expr ( cycle_delay_range sequence_expr )* 
  | expression_or_dist ( KW_THROUGHOUT sequence_expr 
                      | boolean_abbrev 
                      )? 
  | ( LPAREN sequence_expr ( COMMA sequence_match_item )* RPAREN 
      | sequence_instance 
      ) ( sequence_abbrev )? 
  | clocking_event sequence_expr 
 ;
cycle_delay_range:
 DOUBLE_HASH ( LSQUARE_BR ( MUL 
                          | PLUS 
                          | cycle_delay_const_range_expression 
                          ) RSQUARE_BR 
              | constant_primary 
              );
sequence_method_call:
 sequence_instance DOT identifier;
sequence_match_item:
 operator_assignment 
  | inc_or_dec_expression 
  | subroutine_call 
 ;
sequence_instance:
 ps_or_hierarchical_identifier ( LPAREN sequence_list_of_arguments RPAREN )?;
sequence_list_of_arguments:
 ( DOT identifier LPAREN ( sequence_actual_arg )? RPAREN 
  | sequence_actual_arg ( COMMA ( sequence_actual_arg )? )* 
  | ( COMMA ( sequence_actual_arg )? )+ 
  )? ( COMMA DOT identifier LPAREN ( sequence_actual_arg )? RPAREN )*;
sequence_actual_arg:
 event_expression 
  | sequence_expr 
 ;
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
const_or_range_expression:
 constant_expression 
  | cycle_delay_const_range_expression 
 ;
cycle_delay_const_range_expression:
 constant_expression COLON ( DOLAR 
                              | constant_expression 
                              );
expression_or_dist:
 expression ( KW_DIST LBRACE dist_list RBRACE )?;
assertion_variable_declaration:
 ( var_data_type )? list_of_variable_decl_assignments SEMI;
covergroup_declaration:
 KW_COVERGROUP identifier ( LPAREN tf_port_list RPAREN )? ( coverage_event )? SEMI 
      ( coverage_spec_or_option )* KW_ENDGROUP ( COLON identifier )?;
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
coverage_event:
 ( KW_WITH KW_FUNCTION KW_SAMPLE LPAREN tf_port_list 
      | DOUBLE_AT LPAREN block_event_expression 
      ) RPAREN 
  | clocking_event 
 ;
block_event_expression:
 block_event_expression_item ( KW_OR block_event_expression )*;
block_event_expression_item:
 ( KW_BEGIN 
  | KW_END 
  ) hierarchical_btf_identifier;
hierarchical_btf_identifier:
 hierarchical_identifier 
  | ( hierarchical_identifier DOT 
      | class_scope 
      )? identifier 
 ;
cover_point:
 ( ( data_type_or_implicit )? identifier COLON )? KW_COVERPOINT expression ( KW_IFF LPAREN 
      expression RPAREN )? bins_or_empty;
bins_or_empty:
 LBRACE ( attribute_instance )* ( bins_or_options SEMI )* RBRACE 
  | SEMI 
 ;
bins_or_options:
 coverage_option 
  | ( ( KW_WILDCARD )? bins_keyword identifier ( 
                                                  ( LSQUARE_BR ( covergroup_expression )? RSQUARE_BR )? ASSIGN ( LBRACE covergroup_range_list RBRACE ( 
                                                          KW_WITH LPAREN covergroup_expression RPAREN )? 
                                                          | identifier KW_WITH LPAREN 
                                                          covergroup_expression RPAREN 
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
bins_keyword:
 KW_BINS 
  | KW_ILLEGAL_BINS 
  | KW_IGNORE_BINS 
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
repeat_range:
 covergroup_expression ( COLON covergroup_expression )?;
cover_cross:
 ( identifier COLON )? KW_CROSS identifier_list_2plus ( KW_IFF LPAREN expression RPAREN )? 
      cross_body;
identifier_list_2plus:
 identifier COMMA identifier ( COMMA identifier )*;
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
  | select_expression ( ( LOG_AND 
                          | LOG_OR 
                          ) select_expression 
                      | KW_WITH LPAREN covergroup_expression RPAREN 
                      ( KW_MATCHES covergroup_expression )? 
                      ) 
  | identifier 
  | covergroup_expression ( KW_MATCHES covergroup_expression )? 
 ;
select_condition:
 KW_BINSOF LPAREN bins_expression RPAREN ( KW_INTERSECT LBRACE covergroup_range_list RBRACE )?;
bins_expression:
 identifier ( DOT identifier )?;
covergroup_range_list:
 covergroup_value_range ( COMMA covergroup_value_range )*;
covergroup_value_range:
 LSQUARE_BR covergroup_expression COLON covergroup_expression RSQUARE_BR 
  | covergroup_expression 
 ;
covergroup_expression: expression;
let_declaration:
 KW_LET identifier ( LPAREN ( let_port_list )? RPAREN )? ASSIGN expression SEMI;
let_port_list:
 let_port_item ( COMMA let_port_item )*;
let_port_item:
 ( attribute_instance )* ( let_formal_type )? identifier ( variable_dimension )* 
      ( ASSIGN expression )?;
let_formal_type:
 KW_UNTYPED 
  | data_type_or_implicit 
 ;
let_expression:
 ( package_scope )? identifier ( LPAREN let_list_of_arguments RPAREN )?;
let_list_of_arguments:
 ( DOT identifier LPAREN ( expression )? RPAREN 
  | expression ( COMMA ( expression )? )* 
  | ( COMMA ( expression )? )+ 
  )? ( COMMA DOT identifier LPAREN ( expression )? RPAREN )*;
gate_instantiation:
 ( ( KW_PULLDOWN ( pulldown_strength )? 
      | KW_PULLUP ( pullup_strength )? 
      ) pull_gate_instance ( COMMA pull_gate_instance )* 
  | cmos_switchtype ( delay3 )? cmos_switch_instance ( COMMA cmos_switch_instance )* 
  | enable_gatetype ( drive_strength )? ( delay3 )? enable_gate_instance 
  ( COMMA enable_gate_instance )* 
  | mos_switchtype ( delay3 )? mos_switch_instance ( COMMA mos_switch_instance )* 
  | n_input_gatetype ( drive_strength )? ( delay2 )? n_input_gate_instance ( COMMA 
  n_input_gate_instance )* 
  | n_output_gatetype ( drive_strength )? ( delay2 )? n_output_gate_instance ( COMMA 
  n_output_gate_instance )* 
  | pass_en_switchtype ( delay2 )? pass_enable_switch_instance 
  ( COMMA pass_enable_switch_instance )* 
  | pass_switchtype pass_switch_instance ( COMMA pass_switch_instance )* 
  ) SEMI;
cmos_switch_instance:
 ( name_of_instance )? LPAREN output_terminal COMMA input_terminal COMMA ncontrol_terminal COMMA 
      pcontrol_terminal RPAREN;
enable_gate_instance:
 ( name_of_instance )? LPAREN output_terminal COMMA input_terminal COMMA enable_terminal RPAREN;
mos_switch_instance:
 ( name_of_instance )? LPAREN output_terminal COMMA input_terminal COMMA enable_terminal RPAREN;
n_input_gate_instance:
 ( name_of_instance )? LPAREN output_terminal COMMA input_terminal ( COMMA input_terminal )* 
      RPAREN;
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
ncontrol_terminal: expression;
output_terminal: net_lvalue;
pcontrol_terminal: expression;
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
module_instantiation:
 identifier ( parameter_value_assignment )? hierarchical_instance ( COMMA hierarchical_instance )* 
      SEMI;
parameter_value_assignment:
 HASH LPAREN ( list_of_parameter_assignments )? RPAREN;
list_of_parameter_assignments:
 param_expression ( COMMA param_expression )* 
  | named_parameter_assignment ( COMMA named_parameter_assignment )* 
 ;
named_parameter_assignment:
 DOT identifier LPAREN ( param_expression )? RPAREN;
hierarchical_instance:
 name_of_instance LPAREN list_of_port_connections RPAREN;
name_of_instance:
 identifier ( unpacked_dimension )*;
list_of_port_connections:
 ordered_port_connection ( COMMA ordered_port_connection )* 
  | named_port_connection ( COMMA named_port_connection )* 
 ;
ordered_port_connection:
 ( attribute_instance )* ( expression )?;
named_port_connection:
 ( attribute_instance )* DOT ( MUL 
                              | identifier ( LPAREN ( expression )? RPAREN )? 
                              );
interface_instantiation:
 identifier ( parameter_value_assignment )? hierarchical_instance ( COMMA hierarchical_instance )* 
      SEMI;
program_instantiation:
 identifier ( parameter_value_assignment )? hierarchical_instance ( COMMA hierarchical_instance )* 
      SEMI;
checker_instantiation:
 ps_identifier name_of_instance LPAREN list_of_checker_port_connections RPAREN SEMI;
list_of_checker_port_connections:
 ordered_checker_port_connection ( COMMA ordered_checker_port_connection )* 
  | named_checker_port_connection ( COMMA named_checker_port_connection )* 
 ;
ordered_checker_port_connection:
 ( attribute_instance )* ( property_actual_arg )?;
named_checker_port_connection:
 ( attribute_instance )* DOT ( MUL 
                              | identifier ( LPAREN ( property_actual_arg )? RPAREN )? 
                              );
generate_region:
 KW_GENERATE ( generate_item )* KW_ENDGENERATE;
loop_generate_construct:
 KW_FOR LPAREN genvar_initialization SEMI genvar_expression SEMI genvar_iteration RPAREN 
      generate_block;
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
 KW_IF LPAREN constant_expression RPAREN generate_block ( KW_ELSE generate_block )?;
case_generate_construct:
 KW_CASE LPAREN constant_expression RPAREN case_generate_item ( case_generate_item )* KW_ENDCASE;
case_generate_item:
 ( KW_DEFAULT ( COLON )? 
  | constant_expression ( COMMA constant_expression )* COLON 
  ) generate_block;
generate_block:
 generate_item 
  | ( identifier COLON )? KW_BEGIN ( COLON identifier )? ( generate_item )* KW_END 
  ( COLON identifier )? 
 ;
generate_item:
 ( attribute_instance )* ( parameter_override 
                              | gate_instantiation 
                              | udp_instantiation 
                              | module_instantiation 
                              | ( KW_DEFAULT ( KW_CLOCKING identifier 
                                              | KW_DISABLE KW_IFF expression_or_dist 
                                              ) 
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
                              | assertion_item_declaration 
                              | genvar_declaration 
                              | clocking_declaration 
                              | interface_instantiation 
                              | program_instantiation 
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
  | checker_or_generate_item 
 ;
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
      ) udp_body KW_ENDPRIMITIVE ( COLON identifier )? 
 ;
udp_declaration_port_list:
 udp_output_declaration COMMA udp_input_declaration ( COMMA udp_input_declaration )*;
udp_port_declaration:
 ( udp_output_declaration 
  | udp_input_declaration 
  | udp_reg_declaration 
  ) SEMI;
udp_output_declaration:
 ( attribute_instance )* KW_OUTPUT ( KW_REG identifier ( ASSIGN constant_expression )? 
                                      | identifier 
                                      );
udp_input_declaration:
 ( attribute_instance )* KW_INPUT identifier_list;
udp_reg_declaration:
 ( attribute_instance )* KW_REG identifier;
udp_body:
 combinational_body 
  | sequential_body 
 ;
combinational_body:
 KW_TABLE combinational_entry ( combinational_entry )* KW_ENDTABLE;
combinational_entry:
 level_input_list COLON LEVEL_SYMBOL SEMI;
sequential_body:
 ( udp_initial_statement )? KW_TABLE sequential_entry ( sequential_entry )* KW_ENDTABLE;
udp_initial_statement:
 KW_INITIAL identifier ASSIGN integral_number SEMI;
sequential_entry:
 seq_input_list COLON current_state COLON next_state SEMI;
seq_input_list:
 level_input_list 
  | edge_input_list 
 ;
level_input_list:
 LEVEL_SYMBOL ( LEVEL_SYMBOL )*;
edge_input_list:
 ( LEVEL_SYMBOL )* edge_indicator ( LEVEL_SYMBOL )*;
edge_indicator:
 LPAREN LEVEL_SYMBOL LEVEL_SYMBOL RPAREN 
  | EDGE_SYMBOL 
 ;
current_state: LEVEL_SYMBOL;
next_state:
 LEVEL_SYMBOL 
  | MINUS 
 ;
udp_instantiation:
 identifier ( drive_strength )? ( delay2 )? udp_instance ( COMMA udp_instance )* SEMI;
udp_instance:
 ( name_of_instance )? LPAREN output_terminal COMMA input_terminal ( COMMA input_terminal )* 
      RPAREN;
continuous_assign:
 KW_ASSIGN ( ( drive_strength )? ( delay3 )? list_of_net_assignments 
              | ( delay_control )? list_of_variable_assignments 
              ) SEMI;
list_of_net_assignments:
 net_assignment ( COMMA net_assignment )*;
list_of_variable_assignments:
 variable_assignment ( COMMA variable_assignment )*;
net_alias:
 KW_ALIAS net_lvalue ASSIGN net_lvalue ( ASSIGN net_lvalue )* SEMI;
net_assignment:
 net_lvalue ASSIGN expression;
initial_construct:
 KW_INITIAL statement_or_null;
always_construct:
 always_keyword statement;
always_keyword:
 KW_ALWAYS 
  | KW_ALWAYS_COMB 
  | KW_ALWAYS_LATCH 
  | KW_ALWAYS_FF 
 ;
final_construct:
 KW_FINAL statement;
blocking_assignment:
 variable_lvalue ASSIGN delay_or_event_control expression 
  | nonrange_variable_lvalue ASSIGN dynamic_array_new 
  | ( implicit_class_handle DOT 
      | class_scope 
      | package_scope 
      )? hierarchical_identifier select ASSIGN class_new 
  | operator_assignment 
 ;
operator_assignment:
 variable_lvalue assignment_operator expression;
assignment_operator:
 ASSIGN 
  | PLUS_EQ 
  | MINUS_EQ 
  | MUL_EQ 
  | DIV_EQ 
  | MOD_EQ 
  | AND_EQ 
  | OR_EQ 
  | XOR_EQ 
  | SHIFT_LEFT_EQ 
  | SHIFT_RIGHT_EQ 
  | ARITH_SHIFT_LEFT_EQ 
  | ARITH_SHIFT_RIGHT_EQ 
 ;
nonblocking_assignment:
 variable_lvalue LE ( delay_or_event_control )? expression;
procedural_continuous_assignment:
 KW_ASSIGN variable_assignment 
  | KW_DEASSIGN variable_lvalue 
  | KW_FORCE ( variable_assignment 
              | net_assignment 
              ) 
  | KW_RELEASE ( variable_lvalue 
              | net_lvalue 
              ) 
 ;
variable_assignment:
 variable_lvalue ASSIGN expression;
action_block:
 ( ( statement )? KW_ELSE )? statement_or_null;
seq_block:
 KW_BEGIN ( COLON identifier )? ( block_item_declaration )* ( statement_or_null )* KW_END ( COLON 
      identifier )?;
par_block:
 KW_FORK ( COLON identifier )? ( block_item_declaration )* ( statement_or_null )* join_keyword ( 
      COLON identifier )?;
join_keyword:
 KW_JOIN 
  | KW_JOIN_ANY 
  | KW_JOIN_NONE 
 ;
statement_or_null:
 statement 
  | ( attribute_instance )* SEMI 
 ;
statement:
 ( identifier COLON )? ( attribute_instance )* statement_item;
statement_item:
 ( blocking_assignment 
      | nonblocking_assignment 
      | procedural_continuous_assignment 
      | inc_or_dec_expression 
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
randomize_arg_list:
 hierarchical_identifier ( COMMA hierarchical_identifier )*;
procedural_timing_control_statement:
 procedural_timing_control statement_or_null;
delay_or_event_control:
 delay_control 
  | ( KW_REPEAT LPAREN expression RPAREN )? event_control 
 ;
delay_control:
 HASH ( LPAREN mintypmax_expression RPAREN 
          | delay_value 
          );
event_control:
 AT ( LPAREN ( MUL 
              | event_expression 
              ) RPAREN 
      | MUL 
      | hierarchical_identifier 
      | ps_or_hierarchical_identifier 
      );
event_expression:
 event_expression_item ( ( KW_OR 
                          | COMMA 
                          ) event_expression )*;
event_expression_item:
 LPAREN event_expression RPAREN 
  | ( ( edge_identifier )? expression 
      | sequence_instance 
      ) ( KW_IFF expression )? 
 ;
procedural_timing_control:
 delay_control 
  | event_control 
  | cycle_delay 
 ;
jump_statement:
 ( KW_RETURN ( expression )? 
  | KW_BREAK 
  | KW_CONTINUE 
  ) SEMI;
wait_statement:
 KW_WAIT ( LPAREN expression RPAREN statement_or_null 
              | KW_FORK SEMI 
              ) 
  | KW_WAIT_ORDER LPAREN hierarchical_identifier ( COMMA hierarchical_identifier )* RPAREN 
  action_block 
 ;
event_trigger:
 ( ARROW 
  | DOUBLE_RIGHT_ARROW ( delay_or_event_control )? 
  ) hierarchical_identifier SEMI;
disable_statement:
 KW_DISABLE ( KW_FORK 
              | hierarchical_identifier 
              ) SEMI;
conditional_statement:
 ( unique_priority )? KW_IF LPAREN cond_predicate RPAREN statement_or_null ( KW_ELSE KW_IF LPAREN 
      cond_predicate RPAREN statement_or_null )* ( KW_ELSE statement_or_null )?;
unique_priority:
 KW_UNIQUE 
  | KW_UNIQUE0 
  | KW_PRIORITY 
 ;
cond_predicate:
 expression ( KW_MATCHES pattern )? ( TRIPLE_AND expression ( KW_MATCHES pattern )? )*;
case_statement:
 ( unique_priority )? ( KW_CASE LPAREN expression RPAREN KW_INSIDE case_inside_item 
                          ( case_inside_item )* 
                          | case_keyword LPAREN expression RPAREN ( KW_MATCHES case_pattern_item 
                                                                  ( case_pattern_item )* 
                                                                  | case_item ( case_item )* 
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
randcase_statement:
 KW_RANDCASE randcase_item ( randcase_item )* KW_ENDCASE;
randcase_item:
 expression COLON statement_or_null;
open_range_list:
 value_range ( COMMA value_range )*;
pattern:
 DOT ( MUL 
          | identifier 
          ) 
  | KW_TAGGED identifier ( pattern )? 
  | APOSTROPHE LBRACE ( pattern ( COMMA pattern )* 
                      | identifier COLON pattern ( COMMA identifier COLON pattern )* 
                      ) RBRACE 
  | constant_expression 
 ;
assignment_pattern:
 APOSTROPHE LBRACE ( expression ( COMMA expression )* 
                      | structure_pattern_key COLON expression ( COMMA structure_pattern_key COLON 
                      expression )* 
                      | array_pattern_key COLON expression 
                      ( COMMA array_pattern_key COLON expression )* 
                      | constant_expression LBRACE expression ( COMMA expression )* RBRACE 
                      ) RBRACE;
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
  | simple_type 
 ;
assignment_pattern_expression:
 ( assignment_pattern_expression_type )? assignment_pattern;
assignment_pattern_expression_type:
 ps_type_identifier 
  | ps_parameter_identifier 
  | integer_atom_type 
  | type_reference 
 ;
assignment_pattern_net_lvalue:
 APOSTROPHE LBRACE net_lvalue ( COMMA net_lvalue )* RBRACE;
assignment_pattern_variable_lvalue:
 APOSTROPHE LBRACE variable_lvalue ( COMMA variable_lvalue )* RBRACE;
loop_statement:
 ( KW_FOREVER 
      | ( ( KW_REPEAT 
              | KW_WHILE 
              ) LPAREN expression 
          | KW_FOR LPAREN ( for_initialization )? SEMI ( expression )? SEMI ( for_step )? 
          ) RPAREN 
      ) statement_or_null 
  | KW_DO statement_or_null KW_WHILE LPAREN expression RPAREN SEMI 
  | KW_FOREACH LPAREN foreach_ps_or_hierarchical_array_identifier LSQUARE_BR loop_variables 
  RSQUARE_BR RPAREN statement 
 ;
for_initialization:
 list_of_variable_assignments 
  | for_variable_declaration ( COMMA for_variable_declaration )* 
 ;
for_variable_declaration:
 ( KW_VAR )? data_type identifier ASSIGN expression ( COMMA identifier ASSIGN expression )*;
for_step:
 sequence_match_item ( COMMA sequence_match_item )*;
loop_variables:
 ( identifier )? ( COMMA ( identifier )? )*;
subroutine_call_statement:
 ( KW_VOID APOSTROPHE LPAREN subroutine_call RPAREN 
  | subroutine_call 
  ) SEMI;
assertion_item:
 concurrent_assertion_item 
  | deferred_immediate_assertion_item 
 ;
deferred_immediate_assertion_item:
 ( identifier COLON )? deferred_immediate_assertion_statement;
procedural_assertion_statement:
 concurrent_assertion_statement 
  | immediate_assertion_statement 
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
deferred_immediate_assert_statement:
 KW_ASSERT ( KW_FINAL 
              | primitive_delay 
              ) LPAREN expression RPAREN action_block;
deferred_immediate_assume_statement:
 KW_ASSUME ( KW_FINAL 
              | primitive_delay 
              ) LPAREN expression RPAREN action_block;
deferred_immediate_cover_statement:
 KW_COVER ( KW_FINAL 
              | primitive_delay 
              ) LPAREN expression RPAREN statement_or_null;
clocking_declaration:
 ( KW_GLOBAL KW_CLOCKING ( identifier )? clocking_event SEMI 
  | ( KW_DEFAULT )? KW_CLOCKING ( identifier )? clocking_event SEMI ( clocking_item )* 
  ) KW_ENDCLOCKING ( COLON identifier )?;
clocking_event:
 AT ( LPAREN event_expression RPAREN 
      | identifier 
      );
clocking_item:
 ( KW_DEFAULT default_skew 
      | clocking_direction list_of_clocking_decl_assign 
      ) SEMI 
  | ( attribute_instance )* assertion_item_declaration 
 ;
default_skew:
 KW_INPUT clocking_skew ( KW_OUTPUT clocking_skew )? 
  | KW_OUTPUT clocking_skew 
 ;
clocking_direction:
 KW_INPUT ( clocking_skew )? ( KW_OUTPUT ( clocking_skew )? )? 
  | KW_OUTPUT ( clocking_skew )? 
  | KW_INOUT 
 ;
list_of_clocking_decl_assign:
 clocking_decl_assign ( COMMA clocking_decl_assign )*;
clocking_decl_assign:
 identifier ( ASSIGN expression )?;
clocking_skew:
 edge_identifier ( delay_control )? 
  | delay_control 
 ;
clocking_drive:
 clockvar_expression LE ( cycle_delay )? expression;
cycle_delay:
 DOUBLE_HASH ( LPAREN expression RPAREN 
              | integral_number 
              | identifier 
              );
clockvar_expression:
 hierarchical_identifier select;
randsequence_statement:
 KW_RANDSEQUENCE LPAREN ( identifier )? RPAREN production ( production )* KW_ENDSEQUENCE;
production:
 ( data_type_or_void )? identifier ( LPAREN tf_port_list RPAREN )? COLON rs_rule ( BAR rs_rule )* 
      SEMI;
rs_rule:
 rs_production_list ( DIST_WEIGHT_ASSIGN weight_specification ( rs_code_block )? )?;
rs_production_list:
 KW_RAND KW_JOIN ( LPAREN expression RPAREN )? production_item production_item 
  ( production_item )* 
  | rs_prod ( rs_prod )* 
 ;
weight_specification:
 LPAREN expression RPAREN 
  | integral_number 
  | ps_identifier 
 ;
rs_code_block:
 LBRACE ( data_declaration )* ( statement_or_null )* RBRACE;
rs_prod:
 production_item 
  | rs_code_block 
  | rs_if_else 
  | rs_repeat 
  | rs_case 
 ;
production_item:
 identifier ( LPAREN list_of_arguments RPAREN )?;
rs_if_else:
 KW_IF LPAREN expression RPAREN production_item ( KW_ELSE production_item )?;
rs_repeat:
 KW_REPEAT LPAREN expression RPAREN production_item;
rs_case:
 KW_CASE LPAREN expression RPAREN rs_case_item ( rs_case_item )* KW_ENDCASE;
rs_case_item:
 ( KW_DEFAULT ( COLON )? 
  | expression ( COMMA expression )* COLON 
  ) production_item SEMI;
specify_block:
 KW_SPECIFY ( specify_item )* KW_ENDSPECIFY;
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
parallel_path_description:
 LPAREN specify_input_terminal_descriptor ( polarity_operator )? IMPLIES 
      specify_output_terminal_descriptor RPAREN;
full_path_description:
 LPAREN list_of_path_inputs ( polarity_operator )? PATH_FULL list_of_path_outputs RPAREN;
list_of_path_inputs:
 specify_input_terminal_descriptor ( COMMA specify_input_terminal_descriptor )*;
list_of_path_outputs:
 specify_output_terminal_descriptor ( COMMA specify_output_terminal_descriptor )*;
specify_input_terminal_descriptor:
 input_identifier ( LSQUARE_BR constant_range_expression RSQUARE_BR )?;
specify_output_terminal_descriptor:
 output_identifier ( LSQUARE_BR constant_range_expression RSQUARE_BR )?;
input_identifier:
 identifier ( DOT identifier )?;
output_identifier:
 identifier ( DOT identifier )?;
path_delay_value:
 LPAREN list_of_path_delay_expressions RPAREN 
  | list_of_path_delay_expressions 
 ;
list_of_path_delay_expressions:
 t_path_delay_expression 
  | trise_path_delay_expression COMMA tfall_path_delay_expression 
  ( COMMA tz_path_delay_expression )? 
  | t01_path_delay_expression COMMA t10_path_delay_expression COMMA t0z_path_delay_expression COMMA 
  tz1_path_delay_expression COMMA t1z_path_delay_expression COMMA tz0_path_delay_expression ( COMMA t0x_path_delay_expression 
  COMMA tx1_path_delay_expression COMMA t1x_path_delay_expression COMMA tx0_path_delay_expression COMMA 
  txz_path_delay_expression COMMA tzx_path_delay_expression )? 
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
edge_sensitive_path_declaration:
 ( parallel_edge_sensitive_path_description 
  | full_edge_sensitive_path_description 
  ) ASSIGN path_delay_value;
parallel_edge_sensitive_path_description:
 LPAREN ( edge_identifier )? specify_input_terminal_descriptor ( polarity_operator )? IMPLIES 
      LPAREN specify_output_terminal_descriptor ( polarity_operator )? COLON data_source_expression RPAREN 
      RPAREN;
full_edge_sensitive_path_description:
 LPAREN ( edge_identifier )? list_of_path_inputs ( polarity_operator )? PATH_FULL LPAREN 
      list_of_path_outputs ( polarity_operator )? COLON data_source_expression RPAREN RPAREN;
data_source_expression: expression;
edge_identifier:
 KW_POSEDGE 
  | KW_NEGEDGE 
  | KW_EDGE 
 ;
state_dependent_path_declaration:
 KW_IF LPAREN module_path_expression RPAREN ( simple_path_declaration 
                                              | edge_sensitive_path_declaration 
                                              ) 
  | KW_IFNONE simple_path_declaration 
 ;
polarity_operator:
 PLUS 
  | MINUS 
 ;
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
 KW_DOLAR_SETUP LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit ( COMMA 
      ( notifier )? )? RPAREN SEMI;
dolar_hold_timing_check:
 KW_DOLAR_HOLD LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit ( COMMA 
      ( notifier )? )? RPAREN SEMI;
dolar_setuphold_timing_check:
 KW_DOLAR_SETUPHOLD LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit 
      COMMA timing_check_limit ( COMMA ( notifier )? ( COMMA ( timestamp_condition )? ( COMMA 
      ( timecheck_condition )? ( COMMA ( delayed_reference )? ( COMMA ( delayed_reference )? )? )? )? )? )? RPAREN 
      SEMI;
dolar_recovery_timing_check:
 KW_DOLAR_RECOVERY LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit ( 
      COMMA ( notifier )? )? RPAREN SEMI;
dolar_removal_timing_check:
 KW_DOLAR_REMOVAL LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit ( COMMA 
      ( notifier )? )? RPAREN SEMI;
dolar_recrem_timing_check:
 KW_DOLAR_RECREM LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit COMMA 
      timing_check_limit ( COMMA ( notifier )? ( COMMA ( timestamp_condition )? ( COMMA ( timecheck_condition )? ( COMMA 
      ( delayed_reference )? ( COMMA ( delayed_reference )? )? )? )? )? )? RPAREN SEMI;
dolar_skew_timing_check:
 KW_DOLAR_SKEW LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit ( COMMA 
      ( notifier )? )? RPAREN SEMI;
dolar_timeskew_timing_check:
 KW_DOLAR_TIMESKEW LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit ( 
      COMMA ( notifier )? ( COMMA ( event_based_flag )? ( COMMA ( remain_active_flag )? )? )? )? 
      RPAREN SEMI;
dolar_fullskew_timing_check:
 KW_DOLAR_FULLSKEW LPAREN timing_check_event COMMA timing_check_event COMMA timing_check_limit 
      COMMA timing_check_limit ( COMMA ( notifier )? ( COMMA ( event_based_flag )? ( COMMA 
      ( remain_active_flag )? )? )? )? RPAREN SEMI;
dolar_period_timing_check:
 KW_DOLAR_PERIOD LPAREN controlled_reference_event COMMA timing_check_limit 
      ( COMMA ( notifier )? )? RPAREN SEMI;
dolar_width_timing_check:
 KW_DOLAR_WIDTH LPAREN controlled_reference_event COMMA timing_check_limit COMMA threshold ( COMMA 
      ( notifier )? )? RPAREN SEMI;
dolar_nochange_timing_check:
 KW_DOLAR_NOCHANGE LPAREN timing_check_event COMMA timing_check_event COMMA start_edge_offset COMMA 
      end_edge_offset ( COMMA ( notifier )? )? RPAREN SEMI;
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
controlled_timing_check_event:
 timing_check_event_control specify_terminal_descriptor ( TRIPLE_AND timing_check_condition )?;
timing_check_event_control:
 KW_POSEDGE 
  | KW_NEGEDGE 
  | KW_EDGE 
  | EDGE_CONTROL_SPECIFIER 
 ;
specify_terminal_descriptor:
 specify_input_terminal_descriptor 
  | specify_output_terminal_descriptor 
 ;
timing_check_condition:
 LPAREN scalar_timing_check_condition RPAREN 
  | scalar_timing_check_condition 
 ;
scalar_timing_check_condition:
 NEG expression 
  | expression ( ( EQ 
              | CASE_EQ 
              | NEQ 
              | CASE_NEQ 
              ) integral_number )? 
 ;
concatenation:
 LBRACE expression ( COMMA expression )* RBRACE;
constant_concatenation:
 LBRACE constant_expression ( COMMA constant_expression )* RBRACE;
constant_multiple_concatenation:
 LBRACE constant_expression constant_concatenation RBRACE;
module_path_concatenation:
 LBRACE module_path_expression ( COMMA module_path_expression )* RBRACE;
module_path_multiple_concatenation:
 LBRACE constant_expression module_path_concatenation RBRACE;
multiple_concatenation:
 LBRACE expression concatenation RBRACE;
streaming_concatenation:
 LBRACE stream_operator ( slice_size )? stream_concatenation RBRACE;
stream_operator:
 SHIFT_RIGHT 
  | SHIFT_LEFT 
 ;
slice_size:
 simple_type 
  | constant_expression 
 ;
stream_concatenation:
 LBRACE stream_expression ( COMMA stream_expression )* RBRACE;
stream_expression:
 expression ( KW_WITH LSQUARE_BR array_range_expression RSQUARE_BR )?;
array_range_expression:
 expression ( ( PLUS 
              | MINUS 
              )? COLON expression )?;
empty_unpacked_array_concatenation:
 LBRACE RBRACE;
subroutine_call_args:
 ( attribute_instance )* ( LPAREN list_of_arguments RPAREN )? 
      ( KW_WITH LPAREN expression RPAREN )?;
subroutine_call:
 ( primary_no_cast_no_call 
      | cast 
      ) subroutine_call_args ( DOT ( array_method_name 
                                  | randomize_call 
                                  | primary_no_cast_no_call 
                                  | cast 
                                  ) subroutine_call_args )* 
  | any_system_tf_identifier ( LPAREN ( list_of_arguments 
                                      | data_type ( COMMA expression )? 
                                      | expression ( COMMA ( expression )? )* ( COMMA 
                                      ( clocking_event )? )? 
                                      ) RPAREN )? 
  | ( KW_STD DOUBLE_COLON )? randomize_call 
 ;
list_of_arguments:
 ( DOT identifier LPAREN ( expression )? RPAREN 
  | expression ( COMMA ( expression )? )* 
  | ( COMMA ( expression )? )+ 
  )? ( COMMA DOT identifier LPAREN ( expression )? RPAREN )*;
randomize_call:
 KW_RANDOMIZE ( attribute_instance )* ( LPAREN ( KW_NULL 
                                              | randomize_arg_list 
                                              )? RPAREN )? ( KW_WITH ( LPAREN ( identifier_list )? 
      RPAREN )? constraint_block )?;
array_method_name:
 KW_UNIQUE 
  | KW_AND 
  | KW_OR 
  | KW_XOR 
  | identifier 
 ;
inc_or_dec_expression:
 inc_or_dec_operator ( attribute_instance )* variable_lvalue 
  | variable_lvalue ( attribute_instance )* inc_or_dec_operator 
 ;
constant_expression:
 constant_expression_12 ( ( ARROW 
                          | BI_DIR_ARROW 
                          ) ( attribute_instance )* constant_expression )*;
constant_expression_12:
 constant_expression_11 ( QUESTIONMARK ( attribute_instance )* constant_expression COLON 
      constant_expression )*;
constant_expression_11:
 constant_expression_10 ( LOG_OR ( attribute_instance )* constant_expression_11 )*;
constant_expression_10:
 constant_expression_9 ( LOG_AND ( attribute_instance )* constant_expression_10 )*;
constant_expression_9:
 constant_expression_8 ( BAR ( attribute_instance )* constant_expression_9 )*;
constant_expression_8:
 constant_expression_7 ( ( XOR 
                          | NXOR 
                          | XORN 
                          ) ( attribute_instance )* constant_expression_8 )*;
constant_expression_7:
 constant_expression_6 ( AMPERSAND ( attribute_instance )* constant_expression_7 )*;
constant_expression_6:
 constant_expression_5 ( ( EQ 
                          | NEQ 
                          | CASE_EQ 
                          | CASE_NEQ 
                          | WILDCARD_EQ 
                          | WILDCARD_NEQ 
                          ) ( attribute_instance )* constant_expression_6 )*;
constant_expression_5:
 constant_expression_4 ( ( LT 
                          | LE 
                          | GT 
                          | GE 
                          ) ( attribute_instance )* constant_expression_5 )*;
constant_expression_4:
 constant_expression_3 ( ( SHIFT_LEFT 
                          | SHIFT_RIGHT 
                          | ARITH_SHIFT_LEFT 
                          | ARITH_SHIFT_RIGHT 
                          ) ( attribute_instance )* constant_expression_4 )*;
constant_expression_3:
 constant_expression_2 ( ( PLUS 
                          | MINUS 
                          ) ( attribute_instance )* constant_expression_3 )*;
constant_expression_2:
 constant_expression_1 ( ( MUL 
                          | DIV 
                          | MOD 
                          ) ( attribute_instance )* constant_expression_2 )*;
constant_expression_1:
 constant_expression_0 ( DOUBLESTAR ( attribute_instance )* constant_expression_1 )*;
constant_expression_0:
 ( unary_operator ( attribute_instance )* )? constant_primary;
constant_mintypmax_expression:
 constant_expression ( COLON constant_expression COLON constant_expression )?;
constant_param_expression:
 DOLAR 
  | constant_mintypmax_expression 
  | data_type 
 ;
param_expression:
 DOLAR 
  | mintypmax_expression 
  | data_type 
 ;
constant_range_expression:
 constant_expression 
  | constant_part_select_range 
 ;
constant_part_select_range:
 constant_range 
  | constant_indexed_range 
 ;
constant_range:
 constant_expression COLON constant_expression;
constant_indexed_range:
 constant_expression ( PLUS 
                      | MINUS 
                      ) COLON constant_expression;
expression:
 expression_12 ( ( ARROW 
                  | BI_DIR_ARROW 
                  ) ( attribute_instance )* expression )*;
expression_12:
 expression_11 ( ( KW_MATCHES pattern )? ( TRIPLE_AND expression ( KW_MATCHES pattern )? )* 
      QUESTIONMARK ( attribute_instance )* expression COLON expression )*;
expression_11:
 expression_10 ( LOG_OR ( attribute_instance )* expression_11 )*;
expression_10:
 expression_9 ( LOG_AND ( attribute_instance )* expression_10 )*;
expression_9:
 expression_8 ( BAR ( attribute_instance )* expression_9 )*;
expression_8:
 expression_7 ( ( XOR 
                  | NXOR 
                  | XORN 
                  ) ( attribute_instance )* expression_8 )*;
expression_7:
 expression_6 ( AMPERSAND ( attribute_instance )* expression_7 )*;
expression_6:
 expression_5 ( ( EQ 
                  | NEQ 
                  | CASE_EQ 
                  | CASE_NEQ 
                  | WILDCARD_EQ 
                  | WILDCARD_NEQ 
                  ) ( attribute_instance )* expression_6 )*;
expression_5:
 expression_4 ( ( LT 
                      | LE 
                      | GT 
                      | GE 
                      ) ( attribute_instance )* expression_5 
                  | KW_INSIDE LBRACE open_range_list RBRACE 
                  )*;
expression_4:
 expression_3 ( ( SHIFT_LEFT 
                  | SHIFT_RIGHT 
                  | ARITH_SHIFT_LEFT 
                  | ARITH_SHIFT_RIGHT 
                  ) ( attribute_instance )* expression_4 )*;
expression_3:
 expression_2 ( ( PLUS 
                  | MINUS 
                  ) ( attribute_instance )* expression_3 )*;
expression_2:
 expression_1 ( ( MUL 
                  | DIV 
                  | MOD 
                  ) ( attribute_instance )* expression_2 )*;
expression_1:
 expression_0 ( DOUBLESTAR ( attribute_instance )* expression_1 )*;
expression_0:
 LPAREN operator_assignment RPAREN 
  | ( unary_operator ( attribute_instance )* )? primary 
  | inc_or_dec_expression 
  | tagged_union_expression 
 ;
tagged_union_expression:
 KW_TAGGED identifier ( expression )?;
value_range:
 LSQUARE_BR expression COLON expression RSQUARE_BR 
  | expression 
 ;
mintypmax_expression:
 expression ( COLON expression COLON expression )?;
module_path_expression:
 module_path_expression_item ( ( binary_module_path_operator ( attribute_instance )* 
                              module_path_expression )+ 
                              | ( QUESTIONMARK ( attribute_instance )* module_path_expression COLON 
                              module_path_expression )+ 
                              )?;
module_path_expression_item:
 ( unary_module_path_operator ( attribute_instance )* )? module_path_primary;
module_path_mintypmax_expression:
 module_path_expression ( COLON module_path_expression COLON module_path_expression )?;
part_select_range:
 constant_range 
  | indexed_range 
 ;
indexed_range:
 expression ( PLUS 
              | MINUS 
              ) COLON constant_expression;
genvar_expression: constant_expression;
constant_primary_no_cast_no_call:
 LPAREN constant_mintypmax_expression RPAREN 
  | KW_NULL 
  | primary_literal 
  | package_or_class_scoped_hier_id_with_const_select 
  | ( constant_concatenation 
      | constant_multiple_concatenation 
      ) ( LSQUARE_BR constant_range_expression RSQUARE_BR )? 
  | assignment_pattern_expression 
  | type_reference 
 ;
constant_primary:
 constant_primary_no_cast_no_call
  | subroutine_call
  | constant_cast 
 ;
module_path_primary:
 LPAREN module_path_mintypmax_expression RPAREN 
  | number 
  | identifier 
  | module_path_concatenation 
  | module_path_multiple_concatenation 
  | subroutine_call 
 ;
primary_no_cast_no_call:
 LPAREN mintypmax_expression RPAREN 
  | KW_THIS 
  | DOLAR 
  | KW_NULL 
  | primary_literal 
  | package_or_class_scoped_hier_id_with_const_select select 
  | empty_unpacked_array_concatenation 
  | ( concatenation 
      | multiple_concatenation 
      ) ( LSQUARE_BR range_expression RSQUARE_BR )? 
  | assignment_pattern_expression 
  | streaming_concatenation 
  | sequence_method_call 
 ;
primary:
 subroutine_call 
  | cast 
 ;
range_expression:
 expression 
  | part_select_range 
 ;
primary_literal:
 TIME_LITERAL 
  | UNBASED_UNSIZED_LITERAL 
  | STRING_LITERAL 
  | number 
 ;
implicit_class_handle:
 KW_THIS ( DOT KW_SUPER )? 
  | KW_SUPER 
 ;
bit_select:
 LSQUARE_BR expression RSQUARE_BR;
select:
 ( DOT identifier 
  | bit_select 
  )* ( LSQUARE_BR part_select_range RSQUARE_BR )?;
nonrange_select:
 ( DOT identifier 
  | bit_select 
  )*;
constant_bit_select:
 LSQUARE_BR constant_expression RSQUARE_BR;
constant_select:
 ( DOT identifier 
  | constant_bit_select 
  )* ( LSQUARE_BR constant_part_select_range RSQUARE_BR )?;
constant_cast:
 casting_type APOSTROPHE LPAREN constant_expression RPAREN;
cast:
 casting_type APOSTROPHE LPAREN expression RPAREN;
net_lvalue:
 LBRACE net_lvalue ( COMMA net_lvalue )* RBRACE 
  | ps_or_hierarchical_identifier constant_select 
  | ( assignment_pattern_expression_type )? assignment_pattern_net_lvalue 
 ;
variable_lvalue:
 LBRACE variable_lvalue ( COMMA variable_lvalue )* RBRACE 
  | ( implicit_class_handle DOT 
      | package_scope 
      )? hierarchical_identifier select 
  | ( assignment_pattern_expression_type )? assignment_pattern_variable_lvalue 
  | streaming_concatenation 
 ;
nonrange_variable_lvalue:
 ( implicit_class_handle DOT 
  | package_scope 
  )? hierarchical_identifier nonrange_select;
unary_operator:
 PLUS 
  | MINUS 
  | NOT 
  | NEG 
  | AMPERSAND 
  | NAND 
  | BAR 
  | NOR 
  | XOR 
  | NXOR 
  | XORN 
 ;
inc_or_dec_operator:
 INCR 
  | DECR 
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
binary_module_path_operator:
 EQ 
  | NEQ 
  | LOG_AND 
  | LOG_OR 
  | AMPERSAND 
  | BAR 
  | XOR 
  | XORN 
  | NXOR 
 ;
number:
 integral_number 
  | real_number 
 ;
integral_number:
 OCTAL_NUMBER 
  | BINARY_NUMBER 
  | HEX_NUMBER 
  | decimal_number 
 ;
decimal_number:
 DECIMAL_TRISTATE_NUMBER_WITH_BASE 
  | DECIMAL_INVALID_NUMBER_WITH_BASE 
  | DECIMAL_NUMBER_WITH_BASE 
  | UNSIGNED_NUMBER 
 ;
real_number:
 REAL_NUMBER_WITH_EXP 
  | FIXED_POINT_NUMBER 
 ;
attribute_instance:
 LPAREN MUL attr_spec ( COMMA attr_spec )* MUL RPAREN;
attr_spec:
 identifier ( ASSIGN constant_expression )?;
hierarchical_identifier:
 ( KW_DOLAR_ROOT DOT )? ( identifier ( constant_bit_select )* DOT )* identifier;
identifier:
 C_IDENTIFIER 
  | SIMPLE_IDENTIFIER 
  | ESCAPED_IDENTIFIER 
  | KW_TYPE_OPTION 
  | KW_SAMPLE 
  | KW_OPTION 
  | KW_RANDOMIZE 
  | KW_STD 
 ;
package_scope:
 ( KW_DOLAR_UNIT 
  | identifier 
  ) DOUBLE_COLON;
ps_identifier:
 ( package_scope )? identifier;
foreach_ps_or_hierarchical_array_identifier:
 ( implicit_class_handle DOT 
  | class_scope 
  | package_scope 
  )? hierarchical_identifier;
ps_parameter_identifier:
 package_or_class_scoped_id ( DOT identifier ( LSQUARE_BR constant_expression RSQUARE_BR )? )*;
ps_type_identifier:
 ( KW_LOCAL DOUBLE_COLON 
  | package_scope 
  | class_scope 
  )? identifier;
primitive_delay:
 HASH UNSIGNED_NUMBER;
ps_or_hierarchical_identifier:
 package_scope identifier 
  | hierarchical_identifier 
 ;
any_system_tf_identifier:
 SYSTEM_TF_IDENTIFIER 
  | KW_DOLAR_UNIT 
  | KW_DOLAR_FATAL 
  | KW_DOLAR_PERIOD 
  | KW_DOLAR_HOLD 
  | KW_DOLAR_SKEW 
  | KW_DOLAR_TIMESKEW 
  | KW_DOLAR_WIDTH 
  | KW_DOLAR_ROOT 
  | KW_DOLAR_WARNING 
  | KW_DOLAR_NOCHANGE 
  | KW_DOLAR_RECREM 
  | KW_DOLAR_SETUP 
  | KW_DOLAR_ERROR 
  | KW_DOLAR_SETUPHOLD 
  | KW_DOLAR_FULLSKEW 
  | KW_DOLAR_RECOVERY 
  | KW_DOLAR_INFO 
  | KW_DOLAR_REMOVAL 
 ;
package_or_class_scoped_id:
 ( KW_DOLAR_UNIT 
  | identifier ( parameter_value_assignment )? 
  ) ( DOUBLE_COLON identifier ( parameter_value_assignment )? )*;
package_or_class_scoped_hier_id_with_const_select:
 ( KW_LOCAL DOUBLE_COLON )? ( KW_DOLAR_ROOT 
                              | implicit_class_handle 
                              | ( KW_DOLAR_UNIT 
                                  | identifier ( parameter_value_assignment )? 
                                  ) ( DOUBLE_COLON identifier ( parameter_value_assignment )? )* 
                              ) ( constant_bit_select )* 
      ( DOT identifier ( constant_bit_select )* )*;
