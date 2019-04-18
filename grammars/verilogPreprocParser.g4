parser grammar verilogPreprocParser;

options { tokenVocab=verilogPreprocLexer;}

@parser::members {

enum { VERILOG2001=0, VERILOG2005=1, SV2012=2, SV2017};
unsigned int mode = VERILOG2001;

bool isVerilog2005() {
  if (mode == 1) {
     return true;
  } else {
     return false;
  }
}

bool isSV2012() {
  if (mode == 1 || mode == 2) {
    return true;
  }
  else {
    return false;
  }
}

bool isSV2017() {
  if (mode == 1 || mode == 2 || mode == 3) {
    return true;
  }
  else {
    return false;
  }
}


}

file
    :  text* EOF
    ;

text :
    code 
   | preprocess_directive
   ;

code
 : LINE_COMMENT|CODE
;


preprocess_directive 
    :
    define NEW_LINE
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
    | {isSV2012() || isSV2017()}? file_nb 
    | {isSV2012() || isSV2017()}? line_nb
    | {isSV2012() || isSV2017()}? undefineall
    | {isVerilog2005() || isSV2012() || isSV2017()}? keywords_directive  
    | {isVerilog2005() || isSV2012() || isSV2017()}? endkeywords_directive
    | {isVerilog2005() || isSV2012() ||  isSV2017()}? pragma
    ;

define
    : { isSV2012() || isSV2017() }? DEFINE macro_id DM_LP var_id (DM_EQUAL default_text?) ? ( DM_COMMA var_id (DM_EQUAL default_text?)? )* DM_RP DM_WS? replacement?
    | {!( isSV2012() || isSV2017()) }?DEFINE macro_id DM_LP var_id ( DM_COMMA var_id )* DM_RP DM_WS? replacement?
    | DEFINE macro_id DM_WS? replacement?
    ;

replacement
    : DNM_CODE+
    ;

default_text
    : DM_DTXT+
    ;


conditional
    : ifdef_directive
    | ifndef_directive
    ;

ifdef_directive 
    : IFDEF cond_id ifdef_group_of_lines 
      ( ELSIF cond_id elsif_group_of_lines )* 
      ( ELSE else_group_of_lines )? ENDIF
    ;


ifndef_directive 
    : IFNDEF cond_id ifndef_group_of_lines 
      ( ELSIF cond_id elsif_group_of_lines )* 
      ( ELSE else_group_of_lines )? ENDIF 
    ;

ifdef_group_of_lines
    : group_of_lines
    ;

ifndef_group_of_lines
    : group_of_lines
    ;

elsif_group_of_lines
    : group_of_lines
    ;
else_group_of_lines
    : group_of_lines
    ;

group_of_lines
    : text*
    ;

token_id
    : BACKTICK macro_toreplace LP value? (MR_COMMA value? )* RP
    | BACKTICK macro_toreplace
    ;

value
    : MR_CODE+
    ;
 
macro_id
    : DM_ID
    ;
var_id
    : DM_ID
    ;

macro_toreplace
    : ID
    ;

cond_id
    : ID
    ;

undef
    : UNDEF ID NEW_LINE
    ;

celldefine
    : CELLDEFINE
    ;

endcelldefine
    : ENDCELLDEFINE
    ;

unconnected_drive
    : UNCONNECTED_DRIVE
    ;

nounconnected_drive
    : NOUNCONNECTED_DRIVE
    ;

default_nettype
    : DEFAULT_NETTYPE default_nettype_value NEW_LINE
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

line_directive
   : LINE DIGIT+ StringLiteral_double_quote DIGIT NEW_LINE
   ;
   
timing_spec
   : TIMESCALE Time_Identifier SLASH Time_Identifier NEW_LINE
   ;

resetall
   : RESETALL
   ;

file_nb
   : FILE_NB
   ;

line_nb
   : LINE_NB
   ;

undefineall
   : UNDEFINEALL
   ;

keywords_directive
  : BEGIN_KEYWORDS version_specifier NEW_LINE
  ;

version_specifier 
  : {isSV2017()}? V18002017
  | {isSV2012()}? V18002012
  | {isSV2012()}? V18002009
  | {isSV2012()}? V18002005
  | {isVerilog2005()}? V13642005
  | V13642001
  | V13642001noconfig
  | V13641995
  ;

endkeywords_directive
  : END_KEYWORDS
  ;

include
  : INCLUDE stringLiteral
  ;

stringLiteral
    : StringLiteral_double_quote | StringLiteral_chevrons | {isSV2012() || isSV2017()}? token_id
    ;

pragma 
  : PRAGMA pragma_name ( pragma_expression ( COMMA pragma_expression )* )? NEW_LINE
  ;

pragma_name : ID;

pragma_expression :
pragma_keyword
| pragma_keyword EQUAL pragma_value
| pragma_value
;

pragma_value :
LP pragma_expression ( COMMA pragma_expression )* RP
| DIGIT+
| StringLiteral_double_quote
| ID
;

pragma_keyword : ID;

