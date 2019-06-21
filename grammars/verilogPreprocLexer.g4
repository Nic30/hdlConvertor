lexer grammar verilogPreprocLexer;

channels { CH_LINE_ESCAPE, CH_LINE_COMMENT, CH_COMMENT}

@lexer::members {

bool define_in_body = false;
bool define_in_def_val = false;
int define_parentesis_count = 0;
int token_id_parentesis_count = 0;

}

fragment CRLF : '\r'? '\n';
fragment LETTER: [a-zA-Z] ;
fragment ID_FIRST: LETTER | '_' ;
fragment F_DIGIT: [0-9] ;
fragment F_ID : ID_FIRST (ID_FIRST | F_DIGIT)*;
fragment ANY_WS: (WS | NEW_LINE)*;
fragment WS_ENDING_NEW_LINE: WS* CRLF;
fragment F_WS: [ \t];
fragment F_LINE_ESCAPE: '\\' CRLF;
// string with escaped newlines and '"'
STR: '"' ( (('\\' '"') | ('\\' '\r'? '\n')) | ~["\r\n])* '"';


LINE_COMMENT : '//' ~[\r\n]* CRLF -> channel(CH_LINE_COMMENT);
COMMENT : '/*' .*? '*/' -> channel(CH_COMMENT);

INCLUDE: '`include' F_WS+ -> mode(INCLUDE_MODE);
DEFINE:  '`define'  F_WS+ {
		define_in_body = false;
	} -> mode(DEFINE_MODE);
IFNDEF:  '`ifndef'  F_WS+ -> mode(IFDEF_MODE);
UNDEF:   '`undef'   F_WS+ -> mode(UNDEF_MODE);
IFDEF:   '`ifdef'   F_WS+ ->mode(IFDEF_MODE);
ELSIF:   '`elsif'   F_WS+ ->mode(IFDEF_MODE);
ELSE:    '`else'    ANY_WS;
ENDIF:   '`endif'   ANY_WS;

BEGIN_KEYWORDS:  '`begin_keywords' F_WS ->mode(KEYWOORDS_MODE);
END_KEYWORDS:    '`end_keywords' CRLF;
PRAGMA:          '`pragma'        F_WS -> mode(PRAGMA_MODE);
UNDEFINEALL:     '`undefineall'   WS_ENDING_NEW_LINE;
RESETALL:        '`resetall'      WS_ENDING_NEW_LINE;
CELLDEFINE:      '`celldefine'    WS_ENDING_NEW_LINE;
ENDCELLDEFINE:   '`endcelldefine' WS_ENDING_NEW_LINE ;
TIMESCALE:       '`timescale'     F_WS+ ->mode(TIMING_SPEC_MODE);
DEFAULT_NETTYPE: '`default_nettype' F_WS+ -> mode(DEFAULT_NETTYPE_MODE);
LINE:            '`line'          F_WS+ -> mode(LINE_MODE) ;
UNCONNECTED_DRIVE: '`unconnected_drive'     WS_ENDING_NEW_LINE;
NOUNCONNECTED_DRIVE: '`nounconnected_drive' WS_ENDING_NEW_LINE;
OTHER_MACRO_WITH_ARGS:  '`' F_ID F_WS* '(' {
    	token_id_parentesis_count = 1;
    } -> mode(MACRO_PARAMS);
OTHER_MACRO_NO_ARGS:    '`' F_ID;

// used when parsing the id, param list and body of define macro
mode DEFINE_MODE;
	DM_LINE_COMMENT: LINE_COMMENT {
		if (define_parentesis_count == 0) {
			// this define will not have any more parameter or body lines
			setType(LINE_COMMENT);
			setMode(DEFAULT_MODE);
		} else {
			skip();
		}
	};
	DM_COMMENT: COMMENT {
	    if (define_in_body || define_in_def_val) {
	        setType(CODE);
        } else {
        	skip();
        }
    };
    LINE_ESCAPE: F_LINE_ESCAPE -> channel(CH_LINE_ESCAPE);
    LP: '(' {
        if (define_in_body || define_in_def_val) {
            // is in the definition of the macro body
            setType(CODE);
        }
        if (!define_in_body) {
        	define_parentesis_count++;
        }
    };
    RP: ')' ({!define_in_body}? WS*)? {
    	if (define_in_body) {
    	    // is in the definition of the macro body
            setType(CODE);
    	} else {
	        define_parentesis_count--;
	        if (define_parentesis_count == 0) {
	    		// is ')' in the param list
	            define_in_body = true;
	            define_in_def_val = false;
	        } else {
		        if (define_in_def_val)
			        setType(CODE);
		    }
        }
    };
    COMMA: ',' {
       if(define_in_body || define_in_def_val) {
       		if (define_parentesis_count == 1 && define_in_def_val) {
       			// not in '(' expr ')' and on end of def val spec
       			define_in_def_val = false;
       		} else {
       			setType(CODE);
       		}
       }
    };
    EQUAL: '=' {
       if(define_in_body || define_in_def_val) {
       	   setType(CODE);
       } else if (!define_in_body) {
	       define_in_def_val = true;;
       }
    };
    DM_NEW_LINE: CRLF {
       if (define_parentesis_count == 0) {
           setMode(DEFAULT_MODE);
       	   setType(NEW_LINE);
       } else {
           skip();
       }
    };
    WS: F_WS+ {
       if(define_in_body || define_in_def_val) {
       		setType(CODE);
       } else if (define_parentesis_count == 0) {
       	   // inside of define body
	       define_in_body = true;
       } else {

           skip();
       }
    };
    ID: F_ID {
    	if (define_in_body || define_in_def_val) {
    		setType(CODE);
    	}
    };
	DM_STR: STR {
    	if (define_in_body || define_in_def_val) {
    		setType(CODE);
    	}
    }; // string can appear only in bo
    DM_LINE_ESCAPE :  F_LINE_ESCAPE -> channel(CH_LINE_ESCAPE);
    DN_NEW_LINE: CRLF -> type(NEW_LINE),mode(DEFAULT_MODE);
    DN_CODE:  ( ~('\\'| '\n') | ( '\\'+ ~[\n]) )+? -> type(CODE); // verything except newline or esacped newline

// used when parsing the macro argument list
mode MACRO_PARAMS;
    // there has to be argument list or any non id/num value behind the macro call
    MP_COMMA: ',' {
        if (token_id_parentesis_count == 0) {
        	// this macro has not a argument and this ',' is behind it
           setType(COMMA);
           setMode(DEFAULT_MODE);
        } else if (token_id_parentesis_count == 1) {
            // this is a ',' in the arg list of macro
            setType(COMMA);
        } else {
            // this is a comma in expression of the argument value
            setType(CODE);
        }
    };
    MP_LP: '(' {
		// this is a '(' in expression of the argument
	    setType(CODE);
        token_id_parentesis_count++;
    };
    MP_RP: ')' {
        if (token_id_parentesis_count == 1) {
           // this is a last ')' which is closing the argument list
           setType(RP);
           setMode(DEFAULT_MODE);
        } else {
           // this is ')' in arg expression
           setType(CODE);
        }
        token_id_parentesis_count--;
    };
    MP_CODE: (STR | ~[,()] )+? -> type(CODE); // string or non parenthesis

mode IFDEF_MODE;
    NUM: F_DIGIT+;
    IFDEF_MODE_ID : F_ID -> type(ID),mode(DEFAULT_MODE);

mode UNDEF_MODE;
    UNDEF_MODE_NUM: F_DIGIT+ -> type(NUM);
    UNDEF_MODE_ID: F_ID -> type(ID);
    UNDEF_NEW_LINE : CRLF -> type(NEW_LINE),mode(DEFAULT_MODE);

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
    DEFAULT_NETTYPE_NEW_LINE : CRLF ->type(NEW_LINE),mode(DEFAULT_MODE);

mode LINE_MODE;
    LINE_MODE_NUM: F_DIGIT+ -> type(NUM);
    LINE_MODE_STR: STR ->type(STR);
    LINE_MODE_WS: F_WS ->skip;
    LINE_MODE_NEW_LINE: CRLF ->type(NEW_LINE),mode(DEFAULT_MODE);

mode TIMING_SPEC_MODE;
    Time_Identifier:
       F_DIGIT+ ' '* [mnpf]? 's'
    ;
    TIMING_SPEC_MODE_SLASH : '/';
    TIMING_SPEC_MODE_WS : WS->skip;
    TIMING_SPEC_MODE_NEW_LINE : CRLF ->type(NEW_LINE),mode(DEFAULT_MODE);

mode KEYWOORDS_MODE;
    V18002017: '"1800-2017"' -> mode(DEFAULT_MODE);
    V18002012: '"1800-2012"' -> mode(DEFAULT_MODE);
    V18002009: '"1800-2009"' -> mode(DEFAULT_MODE);
    V18002005: '"1800-2005"' -> mode(DEFAULT_MODE);
    V13642005: '"1364-2005"' -> mode(DEFAULT_MODE);
    V13642001: '"1364-2001"' -> mode(DEFAULT_MODE);
    V13642001noconfig: '"1364-2001-noconfig"' -> mode(DEFAULT_MODE);
    V13641995: '"1364-1995"' -> mode(DEFAULT_MODE);


mode INCLUDE_MODE;
    INCLUDE_MODE_STR
        :  STR ->type(STR),mode(DEFAULT_MODE)
        ;
    INCLUDE_MODE_StringLiteral_chevrons
        :  '<' ( ~('\\'|'>') )* '>' ->mode(DEFAULT_MODE)
        ;
    INCLUDE_MODE_WS : WS ->skip;

mode PRAGMA_MODE;
    PRAGMA_WS : WS+ -> skip;
    PRAGMA_NUM: F_DIGIT+ -> type(NUM);
    PRAGMA_ID : ID_FIRST (ID_FIRST | F_DIGIT)* ->type(ID);
    PRAGMA_STR: STR ->type(STR);
    PRAGMA_COMMA :  ',' ->type(COMMA);
    PRAGMA_EQUAL: '=' ->type(EQUAL);
    PRAGMA_LP: '(' -> type(LP);
    PRAGMA_RP: ')' -> type(RP);
    PRAGMA_NEW_LINE : CRLF ->type(NEW_LINE),mode(DEFAULT_MODE);


mode DEFAULT_MODE;
	CODE: ~('`' | '\n' )+;
	NEW_LINE: CRLF;

