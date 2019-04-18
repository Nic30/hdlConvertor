lexer grammar verilogPreprocLexer;

channels { CH_LINE_ESCAPE, CH_LINE_COMMENT, CH_COMMENT}

@lexer::members {
/*
int lastType[2] = {-1,-1};
antlr4::Token * lastToken;

antlr4::Token * emit() {
  lastToken = antlr4::Lexer::emit();
  lastType[1] = lastType[0];
  lastType[0] = lastToken->getType();
  return lastToken;
}
*/
bool define_parentesis_rp_seen = false;
unsigned int define_parentesis_count = 0;
unsigned int token_id_parentesis_count = 0;

}


LINE_ESCAPE :  '\\' '\r'? '\n' -> channel(CH_LINE_ESCAPE);
LINE_COMMENT : '//' ~[\r\n]* '\r'? '\n' -> channel(CH_LINE_COMMENT);

INCLUDE: [ \t]* '`include' [ \t]+ -> mode(INCLUDE_MODE);
DEFINE: [ \t]* '`define' [ \t]+ -> mode(DEFINE_MODE);
IFNDEF: [ \t]* '`ifndef' [ \t]+ -> mode(IFDEF_MODE);
UNDEF: [ \t]* '`undef' [ \t]+ -> mode(UNDEF_MODE);
IFDEF: [ \t]* '`ifdef' [ \t]+ ->mode(IFDEF_MODE);
ELSIF: [ \t]* '`elsif' [ \t]+ ->mode(IFDEF_MODE);
ELSE: [ \t]* '`else' [ \t\r\n]*;
ENDIF: [ \t]* '`endif' [ \t\r\n]*;

DOUBLE_BACKTICK: '``';
FILE_NB: '`__FILE__';
LINE_NB: '`__LINE__';
BEGIN_KEYWORDS: [ \t]* '`begin_keywords' [ \t] ->mode(KEYWOORDS_MODE);
END_KEYWORDS: [ \t]* '`end_keywords' '\r'? '\n';
PRAGMA: [ \t]* '`pragma' [ \t] -> mode(PRAGMA_MODE);
UNDEFINEALL: [ \t]* '`undefineall' '\r'? '\n';
RESETALL: [ \t]* '`resetall' [ \t]* '\r'? '\n';
CELLDEFINE: [ \t]* '`celldefine' [ \t]* '\r'? '\n'; 
ENDCELLDEFINE: [ \t]* '`endcelldefine' [ \t]* '\r'? '\n' ;
TIMESCALE: [ \t]* '`timescale' [ \t]+ ->mode(TIMING_SPEC_MODE);
DEFAULT_NETTYPE: [ \t]* '`default_nettype' [ \t]+ -> mode(DEFAULT_NETTYPE_MODE);
LINE: [ \t]* '`line' [ \t]+ -> mode(LINE_MODE) ;
UNCONNECTED_DRIVE: [ \t]* '`unconnected_drive' [ \t]* '\r'? '\n';
NOUNCONNECTED_DRIVE: [ \t]* '`nounconnected_drive' [ \t]* '\r'? '\n'; 

DStringLiteral_double_quote 
    :  '"' ( ~('\\'|'"') )* '"' ->type(CODE)
    ;


COMMA: ','->type(CODE);
LP : '(' ->type(CODE);
RP : ')'-> type(CODE);
EQUAL : '=' ->type(CODE);
BACKTICK: '`' -> mode(MACRO_REPLACE);

fragment ID_FIRST : LETTER | '_' ;
fragment LETTER   : [a-zA-Z] ;
DUMMY_DIGIT    : [0-9] ->type(CODE);
DIGIT    : [0-9] ;
DUMMY_ID : ID_FIRST (ID_FIRST | DUMMY_DIGIT)*->type(CODE);
ID : ID_FIRST (ID_FIRST | DIGIT)*;
DUMMY_NEW_LINE : '\r'? '\n' -> type(CODE);
NEW_LINE : '\r'? '\n';
WS : [ \t] -> type(CODE);
//WS : [ \t] -> skip;
//CODE : ~'`'* '\r'? '\n';
CODE : .;

mode DEFINE_MODE;
DN_COMMENT : '/*' .*? '*/' -> channel(CH_COMMENT);
DM_LINE_ESCAPE :  '\\' '\r'? '\n' ->channel(CH_LINE_ESCAPE);
DM_DIGIT    : [0-9] ;
DM_ID : ID_FIRST (ID_FIRST | DM_DIGIT)*
      {
      define_parentesis_rp_seen =  false;
      };
DM_LP : '('
      {
      define_parentesis_count++;
      if (define_parentesis_rp_seen ==  true) {
        setType(DNM_CODE);
        setMode(DEFINE_NEXT_MODE);
      }
      }
;
DM_RP : ')'
      {
      define_parentesis_count--;
      if (define_parentesis_count == 0) {
          define_parentesis_rp_seen = true;
      }
      }
;
DM_COMMA: ',';
DM_EQUAL: '=' -> mode(DEFINE_DEFAULT_TEXT);

DM_LINE_COMMENT : '//' ~[\r\n]* '\r'? '\n'
                {
                   setChannel(CH_LINE_COMMENT);
                   if (define_parentesis_count == 0) {
                      setMode(DEFAULT_MODE);
                   }
                }
                ;
DM_COMMENT : '/*' .*? '*/' -> channel(CH_COMMENT);
DM_NEW_LINE: '\n'
           {  
              setType(NEW_LINE);
              if (define_parentesis_count == 0) {
                  setMode(DEFAULT_MODE);
              }
              else {
                skip();
              }
           }
           ;

DM_WS : [ \t]+ {
   
   if (define_parentesis_count == 0) {
     setMode(DEFINE_NEXT_MODE);
     setType(DM_WS);
   }
   else {
     skip();
   }
}
;

DM_ANY : .->type(DNM_CODE),mode(DEFINE_NEXT_MODE);

mode DEFINE_NEXT_MODE;
DNM_LINE_COMMENT : '//' ~[\r\n]* '\r'? '\n'->channel(CH_LINE_COMMENT);
DNM_COMMENT : '/*' .*? '*/' -> channel(CH_COMMENT);
DNM_LINE_ESCAPE :  '\\' '\r'? '\n' ->channel(CH_LINE_ESCAPE);
DNM_NEW_LINE: '\r'? '\n' -> type(NEW_LINE),mode(DEFAULT_MODE);
DNM_CODE :  . ;

mode DEFINE_DEFAULT_TEXT;
DDT_LP : '('
      {
      define_parentesis_count++;
      setType(DM_DTXT);
      }
      ;
DDT_RP : ')'
      {
      define_parentesis_count--;
      if (define_parentesis_count >= 1) {
          setType(DM_DTXT);
      }
      else {
          setType(DM_RP);
          setMode(DEFINE_MODE);
      }
      }
      ;
DDT_COMMA : ','
      {
         if (define_parentesis_count > 1) {
            setType(DM_DTXT);
         }
         else {
             setType(DM_COMMA);
             setMode(DEFINE_MODE);
         }
      }
      ;
DM_DTXT: . ;

mode MACRO_REPLACE;
MR_DIGIT: [0-9];
MR_ID: ID_FIRST (ID_FIRST | MR_DIGIT)* ->type(ID);
MR_LP: [ \t]* '('
     {
       setType(LP);
       setMode(MACRO_DEFAULT_TEXT);
       token_id_parentesis_count = 1;
     }; 

MR_ANY: . ->type(CODE),mode(DEFAULT_MODE);

mode MACRO_DEFAULT_TEXT;
MR_COMMA: ','
        {
          if (token_id_parentesis_count == 1) {
            setType(MR_COMMA);
          }
          else{
            setType(MR_CODE);
          }
        }
        ;
MDT_LP: '(' 
     {
       token_id_parentesis_count ++;
       setType(MR_CODE);
     }
     ;
MR_RP: ')'
     {
       token_id_parentesis_count --;
       if (token_id_parentesis_count == 0) {
          setType(RP);
          setMode(DEFAULT_MODE);
       }
       else {
          setType(MR_CODE);
       }
     }
     ;
MR_CODE : ~[,)];

mode IFDEF_MODE;
IFDM_DIGIT    : [0-9] ;
IFDM_ID : ID_FIRST (ID_FIRST | DM_DIGIT)* ->type(ID),mode(DEFAULT_MODE);

mode UNDEF_MODE;
UNDEF_DIGIT    : [0-9] ;
UNDEF_ID : ID_FIRST (ID_FIRST | DM_DIGIT)* ->type(ID);
UNDEF_NEW_LINE : '\n' ->type(NEW_LINE),mode(DEFAULT_MODE);

mode DEFAULT_NETTYPE_MODE;
WIRE : 'wire';
TRI : 'tri';
TRI0 : 'tri0';
TRI1 : 'tri1';
WAND : 'wand';
TRIAND : 'triand';
WOR : 'wor';
TRIOR : 'trior';
TRIREG : 'trireg';
UWIRE : 'uwire';
NONE : 'none';
DEFAULT_NETTYPE_NEW_LINE : '\n' ->type(NEW_LINE),mode(DEFAULT_MODE);

mode LINE_MODE;
LINE_MODE_DIGIT : [0-9] ->type(DIGIT);
StringLiteral_double_quote 
    :  '"' ( ~('\\'|'"') )* '"'
    ;
LM_WS: [ \t] ->skip;
LINE_MODE_NEW_LINE: '\n' ->type(NEW_LINE),mode(DEFAULT_MODE);

mode TIMING_SPEC_MODE;
TIMING_SPEC_MODE_DIGIT : [0-9];
Time_Identifier
   : TIMING_SPEC_MODE_DIGIT+ ' '* [mnpf]? 's'
   ;
SLASH : '/';
TSM_WS : [ \t]->skip;
TIMING_SPEC_MODE_NEW_LINE : '\n' ->type(NEW_LINE),mode(DEFAULT_MODE);

mode KEYWOORDS_MODE;
KEYWOORDS_MODE_WS : [ \t]+ -> skip;
KEYWOORDS_MODE_WS_LINE_COMMENT : '//' ~[\r\n]* ->channel(CH_LINE_COMMENT);
KEYWOORDS_COMMENT : '/*' .*? '*/' -> channel(CH_COMMENT);
V18002017 : '"1800-2017"' ;
V18002012 : '"1800-2012"' ;
V18002009 : '"1800-2009"' ;
V18002005 : '"1800-2005"' ; 
V13642005 : '"1364-2005"' ;
V13642001 : '"1364-2001"' ;
V13642001noconfig : '"1364-2001-noconfig"' ;
V13641995 : '"1364-1995"';
KEYWOORDS_MODE_NEW_LINE : '\r'? '\n' ->type(NEW_LINE),mode(DEFAULT_MODE);


mode INCLUDE_MODE;
INCLUDE_MODE_StringLiteral_double_quote 
    :  '"' ( ~('\\'|'"') )* '"' ->type(StringLiteral_double_quote),mode(DEFAULT_MODE)
    ;
StringLiteral_chevrons 
    :  '<' ( ~('\\'|'"') )* '>' ->mode(DEFAULT_MODE)
    ;
IM_WS : [ \t] ->skip;
IM_BACKTICK : '`' ->type(BACKTICK),mode(MACRO_REPLACE);

mode PRAGMA_MODE;
PRAGMA_WS : [ \t]+ -> skip;
PRAGMA_DIGIT    : [0-9] ->type(DIGIT);
PRAGMA_ID : ID_FIRST (ID_FIRST | DIGIT)* ->type(ID);
PRAGMA_StringLiteral_double_quote 
    :  '"' ( ~('\\'|'"') )* '"' ->type(StringLiteral_double_quote)
    ;
PRAGMA_COMMA :  ',' ->type(COMMA);
PRAGMA_EQUAL: '=' ->type(EQUAL);
PRAGMA_LP: '(' -> type(LP);
PRAGMA_RP: ')' -> type(RP);
PRAGMA_NEW_LINE : '\n' ->type(NEW_LINE),mode(DEFAULT_MODE);
