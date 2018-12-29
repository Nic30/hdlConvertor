grammar vpp;

/* Process #define statements in a C file using fuzzy parsing.
*/

file
    :   .*? ( preprocess_directive .*? )*
    ;

preprocess_directive 
    : define
    | undef
    | conditional
    | include
    | token_id
    ;

define
    :   DEFINE macro_id '(' ID ( ',' ID )* ')' replacement //{System.out.println(">>> macro(parm) : " + $macro_id.text + " replace by :" + $replacement.text);} 
    |   DEFINE macro_id replacement //{System.out.println(">>> simple macro with space : " + $macro_id.text + " replace by :" + $replacement.text );}
    |   DEFINE macro_id //{System.out.println(">>> simple macro : " + $macro_id.text);}
    ;

replacement
    //:   (~'\n'| '`'|'$'|';'|'\\\n'| '\\\r\n' | '+'|'-'|'/'|'*'|':'|'('|')')+ '\n'
    :   ~'\n'+ '\n'
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
    : BACKTICK macro_toreplace '(' ID ( ',' ID )* ')'  //{System.out.println(">>> to replace : " + $macro_toreplace.text);}
    | BACKTICK macro_toreplace  //{ System.out.println(">>> to replace : " + $macro_toreplace.text);}
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
    :  '\\' '\r'? '\n' -> channel(HIDDEN)
    ;

LINE_COMMENT
    : '//' ~[\r\n]* '\r'? -> channel(HIDDEN) 
    ;


WS  :   [ \r\t\u000C]+ -> channel(HIDDEN)
    ;

OTHER 
    : . //-> channel(HIDDEN)
    ; 
