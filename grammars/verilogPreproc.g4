grammar verilogPreproc;

@lexer::members {
static  const unsigned int CH_LINE_ESCAPE = 4;
static  const unsigned int CH_LINE_COMMENT = 5;
}

//channels { LINE_ESCAPE, LINE_COMMENT}

/* Process #define statements in a C file using fuzzy parsing.
*/

file
    :   .*? ( preprocess_directive .*? )*
    ;

preprocess_directive 
    : define
    | resetall 
    | undef
    | conditional
    | include
    | celldefine
    | endcelldefine
    | unconnected_drive
    | nounconnected_drive
    | default_nettype
    | line_directive
    | timing_spec
    | token_id
    ;

resetall
   : '`resetall'
   ;

celldefine
   : '`celldefine'
   ;

endcelldefine
   : '`endcelldefine'
   ;

timing_spec
   : '`timescale' Time_Identifier '/' Time_Identifier
   ;

Time_Identifier
   : [0-9]+ ' '* [mnpf]? 's'
   ;

default_nettype 
   : '`default_nettype' default_nettype_value
   ;

default_nettype_value 
   : 'wire' | 'tri' | 'tri0' | 'tri1' | 'wand' | 'triand' | 'wor' | 'trior' | 'trireg' | 'uwire' | 'none'
   ;

line_directive 
   : Line
   ;

Line 
   : '`line' [0-9]+ '"' StringLiteral '"' ('0' | '1' | '2')
   ; 

unconnected_drive
   : '`unconnected_drive'
   ;

nounconnected_drive
   : '`nounconnected_drive'
   ;

define
    // SystemVerilog  :   DEFINE macro_id LP NEW_LINE* ID NEW_LINE* ('=' default_text) ? ( ',' NEW_LINE* ID NEW_LINE* ('=' default_text)? )* RP replacement 
    :   DEFINE macro_id LP NEW_LINE* ID NEW_LINE* ( ',' NEW_LINE* ID NEW_LINE* )* RP replacement 
    |   DEFINE macro_id replacement
    |   DEFINE macro_id
    ;

replacement
    :   ~'\n'+ '\n'+
    ;

default_text
    : ~(',' | ')')+
    ;

undef 
    : UNDEF ID ;

conditional
    : ifdef_directive
    | ifndef_directive
    ;

ifdef_directive 
    : IFDEF ID ifdef_group_of_lines 
      ( ELSIF ID elsif_group_of_lines )* 
      ( ELSE else_group_of_lines )? ENDIF ;


ifndef_directive 
    : IFNDEF ID ifndef_group_of_lines 
      ( ELSIF ID elsif_group_of_lines )* 
      ( ELSE else_group_of_lines )? ENDIF ;

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
    : .*? ( preprocess_directive .*? )*
    ;

token_id
    : BACKTICK macro_toreplace NEW_LINE* LP NEW_LINE* value? NEW_LINE* ( ',' NEW_LINE* value? NEW_LINE* )* RP
    | BACKTICK macro_toreplace
    ;

value
    : token_id 
    | (ID|OTHER|StringLiteral)+
    | LP value* RP
    | '"' value* '"'
    | '{' value* '}'
    | '[' value* ']'
    ;

include
    : INCLUDE StringLiteral
    ;

INCLUDE
    : '`include'
    ;

DEFINE
    : '`define'
    ;

IFNDEF
    : '`ifndef'
    ;

UNDEF
    : '`undef'
    ;

IFDEF
    : '`ifdef'
    ;


ELSIF
    : '`elsif'
    ;

ELSE
    : '`else'
    ;

ENDIF
    :'`endif'
    ;

LP 
    : '('
    ;
    
RP
    : ')'
    ;

IGNORED_DIRECTIVE
    : BACKTICK Ignored_directive
    ;

BACKTICK
    : '`'
    ;

fragment Ignored_directive
    : 'begin_keywords' | 'celldefine' | 'default_nettype' 
    | 'end_keywords' | 'endcelldefine' | 'line' 
    | 'nounconnected_drive' | 'pragma' | 'resetall'
    | 'timescale' | 'unconnected_drive'
    ;
 
macro_id
    : ID
    ;

macro_toreplace
    : ID
    ;

ID  :   ( ID_FIRST (ID_FIRST | DIGIT)* ) ;

fragment DIGIT    : [0-9] ;
fragment ID_FIRST : LETTER | '_' ;
fragment LETTER   : [a-zA-Z] ;

/* from
http://media.pragprog.com/titles/tpantlr2/code/reference/FuzzyJava.g4 */

CharacterLiteral
    :   '\'' ( EscapeSequence | ~('\''|'\\') ) '\''
    ;

StringLiteral
    :  '"' ( EscapeSequence | ~('\\'|'"') )* '"'
    |  '<' ( EscapeSequence | ~('\\'|'>') )* '>'
    ;

fragment
EscapeSequence
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\')
    |   UnicodeEscape
    |   OctalEscape
    ;

fragment
OctalEscape
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UnicodeEscape
    :   '\\' 'u' HexDigit HexDigit HexDigit HexDigit
    ;

fragment
HexDigit : ('0'..'9'|'a'..'f'|'A'..'F') ;

COMMENT
    :   '/*' .*? '*/'    -> channel(HIDDEN) // match anything between /* and */
    ;

LINE_ESCAPE
    //:  '\\' '\r'? '\n' -> channel(LINE_ESCAPE)
    :  '\\' '\r'? '\n' -> channel(4)
    ;

LINE_COMMENT
    //: '//' ~[\r\n]* '\r'? -> channel(LINE_COMMENT) 
    : '//' ~[\r\n]* '\r'? -> channel(5) 
    ;


WS  :   [ \r\t\u000C]+ -> channel(HIDDEN)
     ;



NEW_LINE 
    : '\n'
    ;

OTHER 
    : . //-> channel(HIDDEN)
    ; 
