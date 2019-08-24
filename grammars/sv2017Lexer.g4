lexer grammar sv2017Lexer;

@lexer::header {
#include <hdlConvertor/language.h>
}
@lexer::members {
    hdlConvertor::Language language_version;
}
KW_DOLAR_ERROR: '$error';
KW_DOLAR_FATAL: '$fatal';
KW_DOLAR_FULLSKEW: '$fullskew';
KW_DOLAR_HOLD: '$hold';
KW_DOLAR_INFO: '$info';
KW_DOLAR_NOCHANGE: '$nochange';
KW_DOLAR_PERIOD: '$period';
KW_DOLAR_RECOVERY: '$recovery';
KW_DOLAR_RECREM: '$recrem';
KW_DOLAR_REMOVAL: '$removal';
KW_DOLAR_ROOT: '$root';
KW_DOLAR_SETUP: '$setup';
KW_DOLAR_SETUPHOLD: '$setuphold';
KW_DOLAR_SKEW: '$skew';
KW_DOLAR_TIMESKEW: '$timeskew';
KW_DOLAR_UNIT: '$unit';
KW_DOLAR_WARNING: '$warning';
KW_DOLAR_WIDTH: '$width';
KW_1STEP: '1step';
KW_PATHPULSEDOLAR_: 'PATHPULSE$';
KW_ACCEPT_ON:
 {language_version >= hdlConvertor::Language::SV2009}? 'accept_on';
KW_ALIAS:
 {language_version >= hdlConvertor::Language::SV2005}? 'alias';
KW_ALWAYS: 'always';
KW_ALWAYS_COMB:
 {language_version >= hdlConvertor::Language::SV2005}? 'always_comb';
KW_ALWAYS_FF:
 {language_version >= hdlConvertor::Language::SV2005}? 'always_ff';
KW_ALWAYS_LATCH:
 {language_version >= hdlConvertor::Language::SV2005}? 'always_latch';
KW_AND: 'and';
KW_ASSERT:
 {language_version >= hdlConvertor::Language::SV2005}? 'assert';
KW_ASSIGN: 'assign';
KW_ASSUME:
 {language_version >= hdlConvertor::Language::SV2005}? 'assume';
KW_AUTOMATIC:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'automatic';
KW_BEFORE:
 {language_version >= hdlConvertor::Language::SV2005}? 'before';
KW_BEGIN: 'begin';
KW_BIND:
 {language_version >= hdlConvertor::Language::SV2005}? 'bind';
KW_BINS:
 {language_version >= hdlConvertor::Language::SV2005}? 'bins';
KW_BINSOF:
 {language_version >= hdlConvertor::Language::SV2005}? 'binsof';
KW_BIT:
 {language_version >= hdlConvertor::Language::SV2005}? 'bit';
KW_BREAK:
 {language_version >= hdlConvertor::Language::SV2005}? 'break';
KW_BUF: 'buf';
KW_BUFIF0: 'bufif0';
KW_BUFIF1: 'bufif1';
KW_BYTE:
 {language_version >= hdlConvertor::Language::SV2005}? 'byte';
KW_CASE: 'case';
KW_CASEX: 'casex';
KW_CASEZ: 'casez';
KW_CELL:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'cell';
KW_CHANDLE:
 {language_version >= hdlConvertor::Language::SV2005}? 'chandle';
KW_CHECKER:
 {language_version >= hdlConvertor::Language::SV2009}? 'checker';
KW_CLASS:
 {language_version >= hdlConvertor::Language::SV2005}? 'class';
KW_CLOCKING:
 {language_version >= hdlConvertor::Language::SV2005}? 'clocking';
KW_CMOS: 'cmos';
KW_CONFIG:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'config';
KW_CONST:
 {language_version >= hdlConvertor::Language::SV2005}? 'const';
KW_CONSTRAINT:
 {language_version >= hdlConvertor::Language::SV2005}? 'constraint';
KW_CONTEXT:
 {language_version >= hdlConvertor::Language::SV2005}? 'context';
KW_CONTINUE:
 {language_version >= hdlConvertor::Language::SV2005}? 'continue';
KW_COVER:
 {language_version >= hdlConvertor::Language::SV2005}? 'cover';
KW_COVERGROUP:
 {language_version >= hdlConvertor::Language::SV2005}? 'covergroup';
KW_COVERPOINT:
 {language_version >= hdlConvertor::Language::SV2005}? 'coverpoint';
KW_CROSS:
 {language_version >= hdlConvertor::Language::SV2005}? 'cross';
KW_DEASSIGN: 'deassign';
KW_DEFAULT: 'default';
KW_DEFPARAM: 'defparam';
KW_DESIGN:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'design';
KW_DISABLE: 'disable';
KW_DIST:
 {language_version >= hdlConvertor::Language::SV2005}? 'dist';
KW_DO:
 {language_version >= hdlConvertor::Language::SV2005}? 'do';
KW_EDGE: 'edge';
KW_ELSE: 'else';
KW_END: 'end';
KW_ENDCASE: 'endcase';
KW_ENDCHECKER:
 {language_version >= hdlConvertor::Language::SV2009}? 'endchecker';
KW_ENDCLASS:
 {language_version >= hdlConvertor::Language::SV2005}? 'endclass';
KW_ENDCLOCKING:
 {language_version >= hdlConvertor::Language::SV2005}? 'endclocking';
KW_ENDCONFIG:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'endconfig';
KW_ENDFUNCTION: 'endfunction';
KW_ENDGENERATE:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'endgenerate';
KW_ENDGROUP:
 {language_version >= hdlConvertor::Language::SV2005}? 'endgroup';
KW_ENDINTERFACE:
 {language_version >= hdlConvertor::Language::SV2005}? 'endinterface';
KW_ENDMODULE: 'endmodule';
KW_ENDPACKAGE:
 {language_version >= hdlConvertor::Language::SV2005}? 'endpackage';
KW_ENDPRIMITIVE: 'endprimitive';
KW_ENDPROGRAM:
 {language_version >= hdlConvertor::Language::SV2005}? 'endprogram';
KW_ENDPROPERTY:
 {language_version >= hdlConvertor::Language::SV2005}? 'endproperty';
KW_ENDSEQUENCE:
 {language_version >= hdlConvertor::Language::SV2005}? 'endsequence';
KW_ENDSPECIFY: 'endspecify';
KW_ENDTASK: 'endtask';
KW_ENUM:
 {language_version >= hdlConvertor::Language::SV2005}? 'enum';
KW_EVENT: 'event';
KW_EVENTUALLY:
 {language_version >= hdlConvertor::Language::SV2009}? 'eventually';
KW_EXPECT:
 {language_version >= hdlConvertor::Language::SV2005}? 'expect';
KW_EXPORT:
 {language_version >= hdlConvertor::Language::SV2005}? 'export';
KW_EXTENDS:
 {language_version >= hdlConvertor::Language::SV2005}? 'extends';
KW_EXTERN:
 {language_version >= hdlConvertor::Language::SV2005}? 'extern';
KW_FINAL:
 {language_version >= hdlConvertor::Language::SV2005}? 'final';
KW_FIRST_MATCH:
 {language_version >= hdlConvertor::Language::SV2005}? 'first_match';
KW_FOR: 'for';
KW_FORCE: 'force';
KW_FOREACH:
 {language_version >= hdlConvertor::Language::SV2005}? 'foreach';
KW_FOREVER: 'forever';
KW_FORK: 'fork';
KW_FORKJOIN:
 {language_version >= hdlConvertor::Language::SV2005}? 'forkjoin';
KW_FUNCTION: 'function';
KW_GENERATE:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'generate';
KW_GENVAR:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'genvar';
KW_GLOBAL:
 {language_version >= hdlConvertor::Language::SV2009}? 'global';
KW_HIGHZ0: 'highz0';
KW_HIGHZ1: 'highz1';
KW_IF: 'if';
KW_IFF:
 {language_version >= hdlConvertor::Language::SV2005}? 'iff';
KW_IFNONE: 'ifnone';
KW_IGNORE_BINS:
 {language_version >= hdlConvertor::Language::SV2005}? 'ignore_bins';
KW_ILLEGAL_BINS:
 {language_version >= hdlConvertor::Language::SV2005}? 'illegal_bins';
KW_IMPLEMENTS:
 {language_version >= hdlConvertor::Language::SV2012}? 'implements';
KW_IMPLIES:
 {language_version >= hdlConvertor::Language::SV2009}? 'implies';
KW_IMPORT:
 {language_version >= hdlConvertor::Language::SV2005}? 'import';
KW_INITIAL: 'initial';
KW_INOUT: 'inout';
KW_INPUT: 'input';
KW_INSIDE:
 {language_version >= hdlConvertor::Language::SV2005}? 'inside';
KW_INSTANCE:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'instance';
KW_INT:
 {language_version >= hdlConvertor::Language::SV2005}? 'int';
KW_INTEGER: 'integer';
KW_INTERCONNECT:
 {language_version >= hdlConvertor::Language::SV2012}? 'interconnect';
KW_INTERFACE:
 {language_version >= hdlConvertor::Language::SV2005}? 'interface';
KW_INTERSECT:
 {language_version >= hdlConvertor::Language::SV2005}? 'intersect';
KW_JOIN: 'join';
KW_JOIN_ANY:
 {language_version >= hdlConvertor::Language::SV2005}? 'join_any';
KW_JOIN_NONE:
 {language_version >= hdlConvertor::Language::SV2005}? 'join_none';
KW_LARGE: 'large';
KW_LET:
 {language_version >= hdlConvertor::Language::SV2009}? 'let';
KW_LIBLIST:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'liblist';
KW_LOCAL:
 {language_version >= hdlConvertor::Language::SV2005}? 'local';
KW_LOCALPARAM:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'localparam';
KW_LOGIC:
 {language_version >= hdlConvertor::Language::SV2005}? 'logic';
KW_LONGINT:
 {language_version >= hdlConvertor::Language::SV2005}? 'longint';
KW_MACROMODULE: 'macromodule';
KW_MATCHES:
 {language_version >= hdlConvertor::Language::SV2005}? 'matches';
KW_MEDIUM: 'medium';
KW_MODPORT:
 {language_version >= hdlConvertor::Language::SV2005}? 'modport';
KW_MODULE: 'module';
KW_NAND: 'nand';
KW_NEGEDGE: 'negedge';
KW_NETTYPE:
 {language_version >= hdlConvertor::Language::SV2012}? 'nettype';
KW_NEW:
 {language_version >= hdlConvertor::Language::SV2005}? 'new';
KW_NEXTTIME:
 {language_version >= hdlConvertor::Language::SV2009}? 'nexttime';
KW_NMOS: 'nmos';
KW_NOR: 'nor';
KW_NOSHOWCANCELLED:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'noshowcancelled';
KW_NOT: 'not';
KW_NOTIF0: 'notif0';
KW_NOTIF1: 'notif1';
KW_NULL:
 {language_version >= hdlConvertor::Language::SV2005}? 'null';
KW_OPTION: 'option';
KW_OR: 'or';
KW_OUTPUT: 'output';
KW_PACKAGE:
 {language_version >= hdlConvertor::Language::SV2005}? 'package';
KW_PACKED:
 {language_version >= hdlConvertor::Language::SV2005}? 'packed';
KW_PARAMETER: 'parameter';
KW_PMOS: 'pmos';
KW_POSEDGE: 'posedge';
KW_PRIMITIVE: 'primitive';
KW_PRIORITY:
 {language_version >= hdlConvertor::Language::SV2005}? 'priority';
KW_PROGRAM:
 {language_version >= hdlConvertor::Language::SV2005}? 'program';
KW_PROPERTY:
 {language_version >= hdlConvertor::Language::SV2005}? 'property';
KW_PROTECTED:
 {language_version >= hdlConvertor::Language::SV2005}? 'protected';
KW_PULL0: 'pull0';
KW_PULL1: 'pull1';
KW_PULLDOWN: 'pulldown';
KW_PULLUP: 'pullup';
KW_PULSESTYLE_ONDETECT:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'pulsestyle_ondetect';
KW_PULSESTYLE_ONEVENT:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'pulsestyle_onevent';
KW_PURE:
 {language_version >= hdlConvertor::Language::SV2005}? 'pure';
KW_RAND:
 {language_version >= hdlConvertor::Language::SV2005}? 'rand';
KW_RANDC:
 {language_version >= hdlConvertor::Language::SV2005}? 'randc';
KW_RANDCASE:
 {language_version >= hdlConvertor::Language::SV2005}? 'randcase';
KW_RANDOMIZE: 'randomize';
KW_RANDSEQUENCE:
 {language_version >= hdlConvertor::Language::SV2005}? 'randsequence';
KW_RCMOS: 'rcmos';
KW_REAL: 'real';
KW_REALTIME: 'realtime';
KW_REF:
 {language_version >= hdlConvertor::Language::SV2005}? 'ref';
KW_REG: 'reg';
KW_REJECT_ON:
 {language_version >= hdlConvertor::Language::SV2009}? 'reject_on';
KW_RELEASE: 'release';
KW_REPEAT: 'repeat';
KW_RESTRICT:
 {language_version >= hdlConvertor::Language::SV2009}? 'restrict';
KW_RETURN:
 {language_version >= hdlConvertor::Language::SV2005}? 'return';
KW_RNMOS: 'rnmos';
KW_RPMOS: 'rpmos';
KW_RTRAN: 'rtran';
KW_RTRANIF0: 'rtranif0';
KW_RTRANIF1: 'rtranif1';
KW_S_ALWAYS:
 {language_version >= hdlConvertor::Language::SV2009}? 's_always';
KW_S_EVENTUALLY:
 {language_version >= hdlConvertor::Language::SV2009}? 's_eventually';
KW_S_NEXTTIME:
 {language_version >= hdlConvertor::Language::SV2009}? 's_nexttime';
KW_S_UNTIL:
 {language_version >= hdlConvertor::Language::SV2009}? 's_until';
KW_S_UNTIL_WITH:
 {language_version >= hdlConvertor::Language::SV2009}? 's_until_with';
KW_SAMPLE: 'sample';
KW_SCALARED: 'scalared';
KW_SEQUENCE:
 {language_version >= hdlConvertor::Language::SV2005}? 'sequence';
KW_SHORTINT:
 {language_version >= hdlConvertor::Language::SV2005}? 'shortint';
KW_SHORTREAL:
 {language_version >= hdlConvertor::Language::SV2005}? 'shortreal';
KW_SHOWCANCELLED:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'showcancelled';
KW_SIGNED:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'signed';
KW_SMALL: 'small';
KW_SOFT:
 {language_version >= hdlConvertor::Language::SV2012}? 'soft';
KW_SOLVE:
 {language_version >= hdlConvertor::Language::SV2005}? 'solve';
KW_SPECIFY: 'specify';
KW_SPECPARAM: 'specparam';
KW_STATIC:
 {language_version >= hdlConvertor::Language::SV2005}? 'static';
KW_STD: 'std';
KW_STRING:
 {language_version >= hdlConvertor::Language::SV2005}? 'string';
KW_STRONG:
 {language_version >= hdlConvertor::Language::SV2009}? 'strong';
KW_STRONG0: 'strong0';
KW_STRONG1: 'strong1';
KW_STRUCT:
 {language_version >= hdlConvertor::Language::SV2005}? 'struct';
KW_SUPER:
 {language_version >= hdlConvertor::Language::SV2005}? 'super';
KW_SUPPLY0: 'supply0';
KW_SUPPLY1: 'supply1';
KW_SYNC_ACCEPT_ON:
 {language_version >= hdlConvertor::Language::SV2009}? 'sync_accept_on';
KW_SYNC_REJECT_ON:
 {language_version >= hdlConvertor::Language::SV2009}? 'sync_reject_on';
KW_TABLE: 'table' -> pushMode(TABLE_MODE);
KW_TAGGED:
 {language_version >= hdlConvertor::Language::SV2005}? 'tagged';
KW_TASK: 'task';
KW_THIS:
 {language_version >= hdlConvertor::Language::SV2005}? 'this';
KW_THROUGHOUT:
 {language_version >= hdlConvertor::Language::SV2005}? 'throughout';
KW_TIME: 'time';
KW_TIMEPRECISION:
 {language_version >= hdlConvertor::Language::SV2005}? 'timeprecision';
KW_TIMEUNIT:
 {language_version >= hdlConvertor::Language::SV2005}? 'timeunit';
KW_TRAN: 'tran';
KW_TRANIF0: 'tranif0';
KW_TRANIF1: 'tranif1';
KW_TRI: 'tri';
KW_TRI0: 'tri0';
KW_TRI1: 'tri1';
KW_TRIAND: 'triand';
KW_TRIOR: 'trior';
KW_TRIREG: 'trireg';
KW_TYPE:
 {language_version >= hdlConvertor::Language::SV2005}? 'type';
KW_TYPE_OPTION: 'type_option';
KW_TYPEDEF:
 {language_version >= hdlConvertor::Language::SV2005}? 'typedef';
KW_UNION:
 {language_version >= hdlConvertor::Language::SV2005}? 'union';
KW_UNIQUE:
 {language_version >= hdlConvertor::Language::SV2005}? 'unique';
KW_UNIQUE0:
 {language_version >= hdlConvertor::Language::SV2009}? 'unique0';
KW_UNSIGNED:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'unsigned';
KW_UNTIL:
 {language_version >= hdlConvertor::Language::SV2009}? 'until';
KW_UNTIL_WITH:
 {language_version >= hdlConvertor::Language::SV2009}? 'until_with';
KW_UNTYPED:
 {language_version >= hdlConvertor::Language::SV2009}? 'untyped';
KW_USE:
 {language_version >= hdlConvertor::Language::VERILOG2001}? 'use';
KW_UWIRE:
 {language_version >= hdlConvertor::Language::VERILOG2005}? 'uwire';
KW_VAR:
 {language_version >= hdlConvertor::Language::SV2005}? 'var';
KW_VECTORED: 'vectored';
KW_VIRTUAL:
 {language_version >= hdlConvertor::Language::SV2005}? 'virtual';
KW_VOID:
 {language_version >= hdlConvertor::Language::SV2005}? 'void';
KW_WAIT: 'wait';
KW_WAIT_ORDER:
 {language_version >= hdlConvertor::Language::SV2005}? 'wait_order';
KW_WAND: 'wand';
KW_WEAK:
 {language_version >= hdlConvertor::Language::SV2009}? 'weak';
KW_WEAK0: 'weak0';
KW_WEAK1: 'weak1';
KW_WHILE: 'while';
KW_WILDCARD:
 {language_version >= hdlConvertor::Language::SV2005}? 'wildcard';
KW_WIRE: 'wire';
KW_WITH:
 {language_version >= hdlConvertor::Language::SV2005}? 'with';
KW_WITHIN:
 {language_version >= hdlConvertor::Language::SV2005}? 'within';
KW_WOR: 'wor';
KW_XNOR: 'xnor';
KW_XOR: 'xor';
EDGE_CONTROL_SPECIFIER:
 'edge' LSQUARE_BR EDGE_DESCRIPTOR ( COMMA EDGE_DESCRIPTOR )* RSQUARE_BR;
TIME_LITERAL:
 ( UNSIGNED_NUMBER 
  | FIXED_POINT_NUMBER 
  ) TIME_UNIT;
DECIMAL_NUMBER_WITH_BASE:
 ( SIZE )? DECIMAL_BASE UNSIGNED_NUMBER;
DECIMAL_INVALID_NUMBER_WITH_BASE:
 ( SIZE )? DECIMAL_BASE X_DIGIT ( UNDERSCORE )*;
DECIMAL_TRISTATE_NUMBER_WITH_BASE:
 ( SIZE )? DECIMAL_BASE Z_DIGIT ( UNDERSCORE )*;
BINARY_NUMBER:
 ( SIZE )? BINARY_BASE BINARY_VALUE;
OCTAL_NUMBER:
 ( SIZE )? OCTAL_BASE OCTAL_VALUE;
HEX_NUMBER:
 ( SIZE )? HEX_BASE HEX_VALUE;
REAL_NUMBER_WITH_EXP:
 UNSIGNED_NUMBER ( DOT UNSIGNED_NUMBER )? EXP ( SIGN )? UNSIGNED_NUMBER;
FIXED_POINT_NUMBER:
 UNSIGNED_NUMBER DOT UNSIGNED_NUMBER;
UNSIGNED_NUMBER:
 DECIMAL_DIGIT ( UNDERSCORE 
                  | DECIMAL_DIGIT 
                  )*;
UNBASED_UNSIZED_LITERAL:
 APOSTROPHE Z_OR_X 
  | '\'0' 
  | '\'1' 
 ;
STRING_LITERAL:
 DBLQUOTE ( ANY_ASCII_CHARACTERS )* DBLQUOTE;
C_IDENTIFIER:
 [a-zA-Z_] ( [a-zA-Z0-9_] )*;
ESCAPED_IDENTIFIER:
 BACKSLASH ( ANY_PRINTABLE_ASCII_CHARACTER_EXCEPT_WHITE_SPACE )* WHITE_SPACE;
SIMPLE_IDENTIFIER:
 [a-zA-Z_] ( [a-zA-Z0-9_$] )*;
SYSTEM_TF_IDENTIFIER:
 DOLAR [a-zA-Z0-9_$] ( [a-zA-Z0-9_$] )*;
SEMI: ';';
LPAREN: '(';
RPAREN: ')';
LSQUARE_BR: '[';
RSQUARE_BR: ']';
LBRACE: '{';
RBRACE: '}';
APOSTROPHE: '\'';
SHIFT_LEFT: '<<';
SHIFT_RIGHT: '>>';
ARITH_SHIFT_LEFT: '<<<';
ARITH_SHIFT_RIGHT: '>>>';
DOLAR: '$';
UNDERSCORE: '_';
MOD: '%';
NOT: '!';
NEG: '~';
NAND: '~&';
NOR: '~|';
XOR: '^';
NXOR: '~^';
XORN: '^~';
COMMA: ',';
DOT: '.';
QUESTIONMARK: '?';
COLON: ':';
DOUBLE_COLON: '::';
EQ: '==';
NEQ: '!=';
CASE_EQ: '===';
CASE_NEQ: '!==';
WILDCARD_EQ: '==?';
WILDCARD_NEQ: '!=?';
ASSIGN: '=';
LT: '<';
GT: '>';
GE: '>=';
LE: '<=';
PLUS_EQ: '+=';
MINUS_EQ: '-=';
MUL_EQ: '*=';
DIV_EQ: '/=';
MOD_EQ: '%=';
AND_EQ: '&=';
OR_EQ: '|=';
XOR_EQ: '^=';
SHIFT_LEFT_EQ: '<<=';
SHIFT_RIGHT_EQ: '>>=';
ARITH_SHIFT_LEFT_EQ: '<<<=';
ARITH_SHIFT_RIGHT_EQ: '>>>=';
PLUS: '+';
MINUS: '-';
AMPERSAND: '&';
LOG_AND: '&&';
BAR: '|';
LOG_OR: '||';
BACKSLASH: '\\';
MUL: '*';
DIV: '/';
DOUBLESTAR: '**';
BI_DIR_ARROW: '<->';
ARROW: '->';
DOUBLE_RIGHT_ARROW: '->>';
INCR: '++';
DECR: '--';
DIST_WEIGHT_ASSIGN: ':=';
DIST_WEIGHT_ASSIGN_DIV: ':/';
OVERLAPPING_IMPL: '|->';
NONOVERLAPPING_IMPL: '|=>';
IMPLIES: '=>';
PATH_FULL: '*>';
HASH_MINUS_HASH: '#-#';
HASH_EQ_HASH: '#=#';
AT: '@';
DOUBLE_AT: '@@';
HASH: '#';
DOUBLE_HASH: '##';
TRIPLE_AND: '&&&';
ONE_LINE_COMMENT:
 '//' .*? ( '\r' )? '\n' -> channel(HIDDEN);
BLOCK_COMMENT:
 '/*' .*? '*/' -> channel(HIDDEN);
WHITE_SPACE: [ \t\n\r] + -> channel(HIDDEN);
fragment EDGE_DESCRIPTOR:
 Z_OR_X ZERO_OR_ONE 
  | ZERO_OR_ONE Z_OR_X 
  | '01' 
  | '10' 
 ;
fragment ZERO_OR_ONE: [01];
fragment Z_OR_X: [xXzZ];
fragment TIME_UNIT:
 's' 
  | 'ms' 
  | 'us' 
  | 'ns' 
  | 'ps' 
  | 'fs' 
 ;
fragment SIGN:
 PLUS 
  | MINUS 
 ;
fragment SIZE: NON_ZERO_UNSIGNED_NUMBER;
fragment NON_ZERO_UNSIGNED_NUMBER:
 NON_ZERO_DECIMAL_DIGIT ( UNDERSCORE 
                          | DECIMAL_DIGIT 
                          )*;
fragment EXP: [eE];
fragment BINARY_VALUE:
 BINARY_DIGIT ( UNDERSCORE 
                  | BINARY_DIGIT 
                  )*;
fragment OCTAL_VALUE:
 OCTAL_DIGIT ( UNDERSCORE 
              | OCTAL_DIGIT 
              )*;
fragment HEX_VALUE:
 HEX_DIGIT ( UNDERSCORE 
              | HEX_DIGIT 
              )*;
fragment DECIMAL_BASE:
 APOSTROPHE ( [sS] )? [dD];
fragment BINARY_BASE:
 APOSTROPHE ( [sS] )? [bB];
fragment OCTAL_BASE:
 APOSTROPHE ( [sS] )? [oO];
fragment HEX_BASE:
 APOSTROPHE ( [sS] )? [hH];
fragment NON_ZERO_DECIMAL_DIGIT: [1-9];
fragment DECIMAL_DIGIT: [0-9];
fragment BINARY_DIGIT:
 X_DIGIT 
  | Z_DIGIT 
  | [01] 
 ;
fragment OCTAL_DIGIT:
 X_DIGIT 
  | Z_DIGIT 
  | [0-7] 
 ;
fragment HEX_DIGIT:
 X_DIGIT 
  | Z_DIGIT 
  | [0-9a-fA-F] 
 ;
fragment X_DIGIT: [xX];
fragment Z_DIGIT:
 QUESTIONMARK 
  | [zZ] 
 ;
fragment DBLQUOTE: '"';
fragment ANY_ASCII_CHARACTERS:
 ~["\\\r\n] 
  | '\\\n' 
  | '\\\r\n' 
  | '\\' [nt\\"vfa] 
  | '\\' [0-9] [0-9]? [0-9]? 
  | '\\' 'x' [0-9A-Fa-f] [0-9A-Fa-f]? 
 ;
fragment ANY_PRINTABLE_ASCII_CHARACTER_EXCEPT_WHITE_SPACE: '\u0021'..'\u007E';

mode TABLE_MODE;
    KW_ENDTABLE: 'endtable' -> popMode;
    LEVEL_SYMBOL:
 QUESTIONMARK 
  | [01xXbB] 
 ;
    EDGE_SYMBOL:
 MUL 
  | [rRfFpPnN] 
 ;
    TABLE_MODE_BLOCK_COMMENT:
 '/*' .*? '*/' -> channel(HIDDEN),type(BLOCK_COMMENT);
    TABLE_MODE_COLON: ':' -> type(COLON);
    TABLE_MODE_LPAREN: '(' -> type(LPAREN);
    TABLE_MODE_MINUS: '-' -> type(MINUS);
    TABLE_MODE_ONE_LINE_COMMENT:
 '//' .*? ( '\r' )? '\n' -> channel(HIDDEN),type(ONE_LINE_COMMENT);
    TABLE_MODE_RPAREN: ')' -> type(RPAREN);
    TABLE_MODE_SEMI: ';' -> type(SEMI);
    TABLE_MODE_WHITE_SPACE: [ \t\n\r] + -> channel(HIDDEN),type(WHITE_SPACE);
