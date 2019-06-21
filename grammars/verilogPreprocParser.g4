parser grammar verilogPreprocParser;

options { tokenVocab=verilogPreprocLexer;}

@parser::header {

#include <hdlConvertor/language.h>

}

@parser::members {

unsigned int mode;

inline bool isVerilog2005() {
  return mode == hdlConvertor::Language::VERILOG2005;
}

inline bool isSV2012() {
  return isVerilog2005() || mode == hdlConvertor::Language::SV2012;
}

inline bool isSV2017() {
  return isSV2012() || mode == hdlConvertor::Language::SV2017;
}

}

file: text* EOF;

text:
   preprocess_directive
  | LINE_COMMENT
  | CODE
  | NEW_LINE
  | NUM
  | ID
  | STR
  | NEW_LINE
  | COMMENT
;

preprocess_directive:
    define
    | conditional
    | token_id
    | resetall
    | undef
    | include
    | celldefine
    | endcelldefine
    | unconnected_drive
    | nounconnected_drive
    | default_nettype
    | line_directive
    | timing_spec
    | {isSV2012() || isSV2017()}? undefineall
    | {isVerilog2005() || isSV2012() || isSV2017()}? (
		keywords_directive
        | endkeywords_directive
        | pragma
        )
    ;
define:
    DEFINE macro_id ( LP define_args RP )? WS* replacement? (LINE_COMMENT | NEW_LINE)
;

define_args:
     { isSV2012() || isSV2017() }? define_args_with_def_val
 	| { !( isSV2012() || isSV2017()) }? define_args_basic
;

define_args_with_def_val:
	param_with_def_val ( COMMA param_with_def_val )*
;
param_with_def_val:
	var_id (EQUAL default_text?) ?
;
define_args_basic:
	var_id ( COMMA var_id )*
;

replacement: CODE+;
default_text: CODE+;


conditional:
    ifdef_directive
    | ifndef_directive
    ;

ifdef_directive:
      IFDEF cond_id group_of_lines
      ( ELSIF cond_id group_of_lines )*
      ( ELSE else_group_of_lines )?
      ENDIF
;


ifndef_directive:
      IFNDEF cond_id group_of_lines
      ( ELSIF cond_id group_of_lines )*
      ( ELSE else_group_of_lines )?
      ENDIF
;

else_group_of_lines: group_of_lines;
group_of_lines: text*;

token_id:
	OTHER_MACRO_NO_ARGS
	| OTHER_MACRO_WITH_ARGS value? (COMMA value? )* RP
;

value: text+;

macro_id: ID;
var_id: COMMENT* ID COMMENT*;
cond_id: ID;
undef: UNDEF ID NEW_LINE;
celldefine: CELLDEFINE;
endcelldefine: ENDCELLDEFINE;
unconnected_drive: UNCONNECTED_DRIVE;
nounconnected_drive: NOUNCONNECTED_DRIVE;

default_nettype:
    DEFAULT_NETTYPE default_nettype_value
;

default_nettype_value
    : WIRE
    | TRI
    | TRI0
    | TRI1
    | WAND
    | TRIAND
    | WOR
    | TRIOR
    | TRIREG
    | UWIRE
    | NONE
    | {isVerilog2005()}? UWIRE
    ;

line_directive:
   LINE NUM STR NUM
;

timing_spec:
   TIMESCALE Time_Identifier TIMING_SPEC_MODE_SLASH Time_Identifier
;

resetall: RESETALL;
undefineall: UNDEFINEALL;

keywords_directive:
   BEGIN_KEYWORDS version_specifier
;

version_specifier:
     {isSV2017()}? V18002017
   | {isSV2012()}? V18002012
   | {isSV2012()}? V18002009
   | {isSV2012()}? V18002005
   | {isVerilog2005()}? V13642005
   | V13642001
   | V13642001noconfig
   | V13641995
;

endkeywords_directive: END_KEYWORDS;
include: INCLUDE stringLiteral;

stringLiteral:
    STR
    | INCLUDE_MODE_StringLiteral_chevrons
    | {isSV2012() || isSV2017()}? token_id
;

pragma:
    PRAGMA pragma_name ( pragma_expression ( COMMA pragma_expression )* )? NEW_LINE
;

pragma_name : ID;
pragma_expression:
    pragma_keyword
    | pragma_keyword EQUAL pragma_value
    | pragma_value
;

pragma_value :
    LP pragma_expression ( COMMA pragma_expression )* RP
    | NUM
    | STR
    | ID
;

pragma_keyword : ID;

