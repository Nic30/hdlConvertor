grammar verilogPreproc;

@lexer::members {
static  const unsigned int CH_LINE_ESCAPE = 4;
static  const unsigned int CH_LINE_COMMENT = 5;

enum { VERILOG2001=0, VERILOG2005=1, SV2012=2};
unsigned int mode = VERILOG2001;

unsigned int nesting = 0;
unsigned int nesting_save = 0;

bool define_mode = false;
bool define_mode_plus = false;
bool token_mode = false;
bool token_mode_plus = false;

int lastType[2] = {-1,-1};
antlr4::Token * lastToken;

bool isVerilog2005() {
  if (mode == VERILOG2005) {
     return true;
  } else {
     return false;
  }
}

bool isSV2012() {
  if (mode == VERILOG2005 || mode == SV2012) {
    return true;
  }
  else {
    return false;
  }
}

antlr4::Token * emit() {
  lastToken = antlr4::Lexer::emit();
  lastType[1] = lastType[0];
  lastType[0] = lastToken->getType();
  return lastToken;
}

}

@parser::members {
enum { VERILOG2001=0, VERILOG2005=1, SV2012=2};
unsigned int mode = VERILOG2001;

bool isVerilog2005() {
  if (mode == VERILOG2005) {
     return true;
  } else {
     return false;
  }
}

bool isSV2012() {
  if (mode == VERILOG2005 || mode == SV2012) {
    return true;
  }
  else {
    return false;
  }
}

}


//custom channels are not supported in combined grammars
//channels { CH_LINE_ESCAPE, CH_LINE_COMMENT}

/* Process #define statements in a C file using fuzzy parsing.
*/


LINE_ESCAPE
    //:  '\\' '\r'? '\n' -> channel(CH_LINE_ESCAPE)
    :  '\\' '\r'? '\n' -> channel(4)
    ;

LINE_COMMENT
    //: '//' ~[\r\n]* '\r'? -> channel(CH_LINE_COMMENT) 
    : '//' ~[\r\n]* '\r'? -> channel(5) 
    ;

file
    :   .*? ( preprocess_directive .*? )*
    ;

preprocess_directive 
    :
    {isSV2012()}? file_nb 
    | {isSV2012()}? line_nb
    | {isSV2012()}? undefineall
    | {isVerilog2005() || isSV2012()}? keywords_directive  
    | {isVerilog2005() || isSV2012()}? endkeywords_directive
    | {isVerilog2005() || isSV2012()}? pragma
    | define
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

file_nb
    : '`__FILE__'
    ;
 
line_nb
    : '`__LINE__'
    ;

keywords_directive : '`begin_keywords' '"' version_specifier '"' NEW_LINE ;

version_specifier :
 {isSV2012()}? '1800-2012'
|{isSV2012()}? '1800-2009'
|{isSV2012()}? '1800-2005'
| '1364-2005'
| '1364-2001'
| '1364-2001-noconfig'
| '1364-1995'
;

endkeywords_directive : '`end_keywords';

pragma :
'`pragma' pragma_name ( pragma_expression ( COMMA pragma_expression )? )?
;

pragma_name : ID;

pragma_expression :
pragma_keyword
| pragma_keyword '=' pragma_value
| pragma_value
;

pragma_value :
'(' pragma_expression ( COMMA pragma_expression )* ')'
| DIGIT+
| StringLiteral_double_quote
| ID
;

pragma_keyword : ID;

undefineall
   : '`undefineall'
   ;

resetall
   : '`resetall' NEW_LINE
   ;

celldefine
   : '`celldefine' NEW_LINE
   ;

endcelldefine
   : '`endcelldefine' NEW_LINE
   ;

timing_spec
   : '`timescale' Time_Identifier '/' Time_Identifier NEW_LINE
   ;

Time_Identifier
   : [0-9]+ ' '* [mnpf]? 's'
   ;

default_nettype 
   : '`default_nettype' default_nettype_value NEW_LINE
   ;

default_nettype_value 
   : 'wire' | 'tri' | 'tri0' | 'tri1' | 'wand' | 'triand' | 'wor' | 'trior' | 'trireg' | 'uwire' | 'none' | {isVerilog2005()}? 'uwire'
   ;

line_directive
   : '`line' DIGIT+ StringLiteral_double_quote DIGIT NEW_LINE
   ; 

unconnected_drive
   : '`unconnected_drive' NEW_LINE
   ;

nounconnected_drive
   : '`nounconnected_drive' NEW_LINE
   ;

define
    : {isSV2012()}? DEFINE macro_id LP NEW_LINE* ID NEW_LINE* ('=' default_text) ? ( ',' NEW_LINE* ID NEW_LINE* ('=' default_text)? )* RP replacement 
    |   DEFINE macro_id LP NEW_LINE* ID NEW_LINE* ( COMMA NEW_LINE* ID NEW_LINE* )* RP replacement 
    |   DEFINE macro_id replacement
    |   DEFINE macro_id NEW_LINE
    ;

replacement
    :   ~'\n'+ '\n'
    ;

default_text
    : ~(COMMA | ')')+
    ;

undef 
    : UNDEF ID NEW_LINE
    ;

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
    : BACKTICK macro_toreplace NEW_LINE* LP NEW_LINE* value? NEW_LINE* ( COMMA NEW_LINE* value? NEW_LINE* )* RP
    | BACKTICK macro_toreplace
    ;

value
    : token_id 
    | (ID|OTHER|DIGIT)+
    | LP value* RP
    | '"' value* '"'
    | '{' value* '}'
    | '[' value* ']'
    ;

include
    : INCLUDE stringLiteral
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
    : '(' {
            //printf("LP : token_mode : %i, define_mode : %i\n",
            //        token_mode,define_mode
            //      );
            nesting++;
            if (token_mode ==  true && token_mode_plus == false) {
              token_mode_plus = true;
              nesting_save = nesting;
            }
            if (define_mode ==  true && define_mode_plus == false) {
              define_mode_plus = true;
              nesting_save = nesting;
            }
            if (nesting > nesting_save) {
              //printf("LP : %i,%i\n", nesting,nesting_save);
              setType(OTHER);
            }
          }
    ;
    
RP
    : ')' {
            if (nesting > nesting_save) {
              setType(OTHER);
            }
            if (nesting == nesting_save && token_mode ==  true) {
              token_mode_plus = false;
              nesting_save = 0;
            }
            if (nesting == nesting_save && define_mode ==  true) {
              define_mode_plus = false;
              nesting_save = 0;
            }
           nesting--;
          }
    ;

DOUBLE_BACKTICK 
    : '``'
    ;

BACKTICK
    : '`'
      { 
        if (token_mode_plus == true) {
          setType(OTHER);
        }
      }
    ;

 
macro_id
    : ID
    ;

macro_toreplace
    : ID
    ;

ID  :   ( ID_FIRST (ID_FIRST | DIGIT)* ) 
      {
        //printf("ID : lastType[0]:%i lastType[1]:%i\n",lastType[0],lastType[1]);
        if (lastType[0] == BACKTICK) {
          token_mode = true;
        }
        else if (lastType[1] == DEFINE) {
          define_mode = true;
        }
        //printf("ID token_mode:%i, define_mode:%i\n",
        //      token_mode,
        //      define_mode
        //      );
      }
    ;

DIGIT    : [0-9] ;
fragment ID_FIRST : LETTER | '_' ;
fragment LETTER   : [a-zA-Z] ;

/* from
http://media.pragprog.com/titles/tpantlr2/code/reference/FuzzyJava.g4 */

CharacterLiteral
    :   '\'' ( EscapeSequence | ~('\''|'\\') ) '\''
    ;

stringLiteral
    : StringLiteral_double_quote | StringLiteral_chevrons
    ;

StringLiteral_double_quote 
    :  '"' ( EscapeSequence | ~('\\'|'"') )* '"' { if (nesting > 0) setType(OTHER);}
    ;
StringLiteral_chevrons  
    :  '<' ( EscapeSequence | ~('\\'|'>') )* '>'
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



WS  :   [ \r\t]+ { 
                   setChannel(HIDDEN);
                   if (token_mode == true) {
                     token_mode == false;
                   }
                 }
     ;

COMMA 
    : ',' {
           if (nesting > nesting_save) { 
             setType(OTHER);
           }
           //printf("',' nesting : %i, nesting_save : %i\n",nesting,nesting_save);
          }
    ;
    

NEW_LINE 
    : '\n' {
             if (token_mode == true) {
               token_mode = false;
             }
             if (define_mode == true) {
               define_mode = false;
             }
             if (nesting > nesting_save) { 
                setType(OTHER); 
                setChannel(HIDDEN);
             }
             //printf("\\n token_mode:%i, define_mode:%i  nesting : %i, nesting_save : %i\n",
             //       token_mode,
             //       define_mode,
             //       nesting,nesting_save);
           }
    ;

OTHER 
    : . //-> channel(HIDDEN)
    ; 
