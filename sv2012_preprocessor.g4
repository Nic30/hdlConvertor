
grammar sv2012_preprocessor;
///////////////////////////////////////////////////////preprocessor////////////////////////////////////////
// [TODO] compiler directives should be in separate grammar
// 20.0

compiler_directive :
'`__FILE__'
| '`__LINE__'
| '`resetall'
| directive_include
| text_macro_definition
| text_macro_usage
| undefine_compiler_directive
| '`undefineall'
| timescale_compiler_directive
| default_nettype_compiler_directive
| '`unconnected_drive'
| '`nounconnected_drive'
| '`celldefine'
| '`endcelldefine'
| pragma
| line_compiler_directive
| keywords_directive
;

directive_include :
'`include' (('"' filename '"')| ('<' filename '>'))
;

//22.5.1 `define
text_macro_definition :
 '`define' text_macro_name macro_text
;

text_macro_name :
 text_macro_identifier ( '(' list_of_formal_arguments ')' )?
;

list_of_formal_arguments :
 formal_argument ( ',' formal_argument )*
;

formal_argument :
 Simple_identifier ( '=' default_text )
;

text_macro_identifier :
 identifier
;


text_macro_usage :
 text_macro_identifier ( '(' list_of_actual_arguments ')' )?
;

list_of_actual_arguments :
actual_argument ( ',' actual_argument)*
;

actual_argument :
expression
;


undefine_compiler_directive :
'`undef' text_macro_identifier
;


// 22.6 `ifdef, `else, `elsif, `endif , `ifndef
conditional_compilation_directive :
ifdef_directive
| ifndef_directive
;

ifdef_directive :
'`ifdef' text_macro_identifier ifdef_group_of_lines
( '`elsif' text_macro_identifier elsif_group_of_lines )*
( '`else' else_group_of_lines )?
'`endif'
;

ifndef_directive :
'`ifndef' text_macro_identifier ifndef_group_of_lines
( '`elsif' text_macro_identifier elsif_group_of_lines )*
( '`else' else_group_of_lines )?
'`endif'
;


timescale_compiler_directive :
'`timescale' time_unit '/' time_precision
;

default_nettype_compiler_directive :
'`default_nettype' default_nettype_value
;
default_nettype_value :
 'wire' | 'tri' | 'tri0' | 'tri1' | 'wand' | 'triand' | 'wor' | 'trior' | 'trireg' | 'uwire' | 'none'
;


// 22.11 `pragma
pragma :
'`pragma' pragma_name ( pragma_expression ( ',' pragma_expression )? )?
;

pragma_name : Simple_identifier;

pragma_expression :
pragma_keyword
| pragma_keyword '=' pragma_value
| pragma_value
;

pragma_value :
'(' pragma_expression ( ',' pragma_expression )* ')'
| number
| String_literal
| identifier
;

pragma_keyword : Simple_identifier;


line_compiler_directive :
'`line' number '"' filename '"' line_compiler_directive_level
;

line_compiler_directive_level : '0' | '1' | '2'; 

// 22.14 `begin_keywords, `end_keywords

keywords_directive : '`begin_keywords' '"' version_specifier '"';

version_specifier :
'1800-2012'
| '1800-2009'
| '1800-2005'
| '1364-2005'
| '1364-2001'
| '1364-2001-noconfig'
| '1364-1995'
;
endkeywords_directive : '`end_keywords';


