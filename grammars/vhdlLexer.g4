
lexer grammar vhdlLexer;

// case insensitive chars
fragment A:('a'|'A');
fragment B:('b'|'B');
fragment C:('c'|'C');
fragment D:('d'|'D');
fragment E:('e'|'E');
fragment F:('f'|'F');
fragment G:('g'|'G');
fragment H:('h'|'H');
fragment I:('i'|'I');
fragment J:('j'|'J');
fragment K:('k'|'K');
fragment L:('l'|'L');
fragment M:('m'|'M');
fragment N:('n'|'N');
fragment O:('o'|'O');
fragment P:('p'|'P');
fragment Q:('q'|'Q');
fragment R:('r'|'R');
fragment S:('s'|'S');
fragment T:('t'|'T');
fragment U:('u'|'U');
fragment V:('v'|'V');
fragment W:('w'|'W');
fragment X:('x'|'X');
fragment Y:('y'|'Y');
fragment Z:('z'|'Z');


fragment EXTENDED_DIGIT: DIGIT | LETTER;
fragment BASE_SPECIFIER: B | O | X | U B | U O | U X | S B | S O | S X | D;
// [note] GRAPHIC_CHARACTER group was reworked in order to resolve Ambiguity
fragment GRAPHIC_CHARACTER:
        SPECIAL_CHARACTER
      | LETTER_OR_DIGIT
      | OTHER_SPECIAL_CHARACTER
;
fragment SPECIAL_CHARACTER:
    HASHTAG | AMPERSAND | APOSTROPHE | LPAREN | RPAREN | MUL | PLUS
  | COMMA | MINUS | DOT | DIV | COLON | SEMI | LT | EQ
  | GT | QUESTIONMARK | AT | '[' | ']' | UNDERSCORE | GRAVE_ACCENT | BAR;

fragment OTHER_SPECIAL_CHARACTER:
    '!' | '$' | '%' | UP  | '{' | '}' | '~' | '´'
  | SPACE_CHARACTER | 'Ў' | 'ў' | 'Ј' | '¤' | 'Ґ'
  | 'Ё' | '©' | 'Є' | '«' | '¬' | '­' | '§' | 'Ї'
  | '°' | '±' | 'І' | 'і' | 'ґ' | 'µ' | '¶' | '·'
  | 'ё' | '№' | 'є' | '»' | 'ј' | 'Ѕ' | 'ѕ' | 'ї'
  | 'А' | 'Б' | 'В' | 'Г' | 'Д' | 'Е' | 'Ж' | 'З'
  | 'И' | 'Й' | 'К' | 'Л' | 'М' | 'Н' | 'О' | 'П'
  | 'Р' | 'С' | 'Т' | 'У' | 'Ф' | 'Х' | 'Ц' | 'Ч'
  | 'Ш' | 'Щ' | 'Ъ' | 'Ы' | 'Ь' | 'Э' | 'Ю' | 'Я'
  | 'а' | 'б' | 'в' | 'г' | 'д' | 'е' | 'ж' | 'з'
  | 'и' | 'й' | 'к' | 'л' | 'м' | 'н' | 'о' | 'п'
  | 'р' | 'с' | 'т' | 'у' | 'ф' | 'х' | 'ц' | 'ч'
  | 'ш' | 'щ' | 'ъ' | 'ы' | 'ь' | 'э' | 'ю' | 'я'
  | ' ' | '¡' | '¢' | '£' | '¦' | '¥' | '®' | '¯'
  | '¸' | '¹' | 'º' | '¼' | '½' | '¾' | '¿' | '²'
  | '³' | 'À' | 'Á' | 'Â' | 'Ã' | 'Ä' | 'Æ' | 'Ç'
  | 'È' | 'É' | 'Ê' | 'Ë' | 'Ì' | 'Í' | 'Î' | 'Ï'
  | 'Ð' | 'Ñ' | 'Ò' | 'Ó' | 'Ô' | 'Õ' | 'Ö' | '×'
  | 'Ø' | 'Ù' | 'Ú' | 'Û' | 'Ü' | 'Ý' | 'Þ' | 'ß'
  | 'à' | 'á' | 'â' | 'ã' | 'ä' | 'å' | 'æ' | 'ç'
  | 'è' | 'é' | 'ê' | 'ë' | 'ì' | 'í' | 'î' | 'ï'
  | 'ð' | 'ñ' | 'ò' | 'ó' | 'ô' | 'õ' | 'ö' | '÷'
  | 'ø' | 'ù' | 'ú' | 'û' | 'ü' | 'ý' | 'þ' | 'ÿ'
  | '¨' | 'ª' ;

fragment LETTER_OR_DIGIT: LETTER | DIGIT;
fragment LETTER: 'A'..'Z' | 'a'..'z' | 'Å';


KW_PROCESS: P R O C E S S;
KW_CONTEXT: C O N T E X T;
KW_POSTPONED: P O S T P O N E D;
KW_LINKAGE: L I N K A G E;
KW_COMPONENT: C O M P O N E N T;
KW_ABS: A B S;
KW_DEFAULT: D E F A U L T;
KW_THEN: T H E N;
KW_BLOCK: B L O C K;
KW_REM: R E M;
KW_INERTIAL: I N E R T I A L;
KW_NEXT: N E X T;
KW_ENTITY: E N T I T Y;
KW_ON: O N;
KW_GROUP: G R O U P;
KW_XNOR: X N O R;
KW_FILE: F I L E;
KW_PURE: P U R E;
KW_GUARDED: G U A R D E D;
KW_GENERIC: G E N E R I C;
KW_RANGE: R A N G E;
KW_ELSE: E L S E;
KW_USE: U S E;
KW_SHARED: S H A R E D;
KW_MOD: M O D;
KW_LOOP: L O O P;
KW_RECORD: R E C O R D;
KW_SIGNAL: S I G N A L;
KW_REJECT: R E J E C T;
KW_BEGIN: B E G I N;
KW_SLA: S L A;
KW_DISCONNECT: D I S C O N N E C T;
KW_OF: O F;
KW_PROCEDURE: P R O C E D U R E;
KW_SRL: S R L;
KW_VUNIT: V U N I T;
KW_ATTRIBUTE: A T T R I B U T E;
KW_VARIABLE: V A R I A B L E;
KW_PROPERTY: P R O P E R T Y;
KW_UNAFFECTED: U N A F F E C T E D;
KW_XOR: X O R;
KW_REGISTER: R E G I S T E R;
KW_SUBTYPE: S U B T Y P E;
KW_TO: T O;
KW_NEW: N E W;
KW_REPORT: R E P O R T;
KW_CONSTANT: C O N S T A N T;
KW_BUFFER: B U F F E R;
KW_BODY: B O D Y;
KW_AFTER: A F T E R;
KW_TRANSPORT: T R A N S P O R T;
KW_FUNCTION: F U N C T I O N;
KW_END: E N D;
KW_SELECT: S E L E C T;
KW_OR: O R;
KW_LIBRARY: L I B R A R Y;
KW_ELSIF: E L S I F;
KW_SLL: S L L;
KW_MAP: M A P;
KW_SRA: S R A;
KW_PROTECTED: P R O T E C T E D;
KW_DOWNTO: D O W N T O;
KW_LABEL: L A B E L;
KW_ALL: A L L;
KW_ALIAS: A L I A S;
KW_GENERATE: G E N E R A T E;
KW_NOR: N O R;
KW_IN: I N;
KW_RELEASE: R E L E A S E;
KW_EXIT: E X I T;
KW_RETURN: R E T U R N;
KW_WITH: W I T H;
KW_UNTIL: U N T I L;
KW_AND: A N D;
KW_INOUT: I N O U T;
KW_WAIT: W A I T;
KW_NAND: N A N D;
KW_ARRAY: A R R A Y;
KW_FORCE: F O R C E;
KW_WHILE: W H I L E;
KW_IMPURE: I M P U R E;
KW_PACKAGE: P A C K A G E;
KW_UNITS: U N I T S;
KW_ASSERT: A S S E R T;
KW_PARAMETER: P A R A M E T E R;
KW_SEVERITY: S E V E R I T Y;
KW_LITERAL: L I T E R A L;
KW_FOR: F O R;
KW_ROR: R O R;
KW_IF: I F;
KW_OUT: O U T;
KW_ROL: R O L;
KW_IS: I S;
KW_SEQUENCE: S E Q U E N C E;
KW_OTHERS: O T H E R S;
KW_TYPE: T Y P E;
KW_CASE: C A S E;
KW_NOT: N O T;
KW_CONFIGURATION: C O N F I G U R A T I O N;
KW_OPEN: O P E N;
KW_ARCHITECTURE: A R C H I T E C T U R E;
KW_BUS: B U S;
KW_ACCESS: A C C E S S;
KW_WHEN: W H E N;
KW_PORT: P O R T;
KW_NULL: N U L L;

BASIC_IDENTIFIER:
      LETTER ( ( UNDERSCORE )? LETTER_OR_DIGIT )*
;
EXTENDED_IDENTIFIER:
      BACKSLASH (GRAPHIC_CHARACTER | (BACKSLASH BACKSLASH))+ BACKSLASH
;
DECIMAL_LITERAL: INTEGER ( DOT INTEGER )? ( EXPONENT )?;
INTEGER: DIGIT ( ( UNDERSCORE )? DIGIT )*;
EXPONENT: E ( PLUS )? INTEGER | E MINUS INTEGER;
fragment BASE: INTEGER;
fragment BASED_INTEGER:
      EXTENDED_DIGIT ( ( UNDERSCORE )? EXTENDED_DIGIT )*
;
BASED_LITERAL:
      BASE HASHTAG BASED_INTEGER ( DOT BASED_INTEGER )? HASHTAG ( EXPONENT )?
;
CHARACTER_LITERAL: APOSTROPHE
                   // only if it is not '('x' because then it is '( 'x' and not '(' 'x
                   // [todo] this requires another lookahead  in some cases
				   { _input->LA(1) != '(' ||  _input->LA(4) != '\'' }?
                    (GRAPHIC_CHARACTER | DBLQUOTE | BACKSLASH)
                   APOSTROPHE 
;	
STRING_LITERAL: DBLQUOTE (GRAPHIC_CHARACTER | DBLQUOTE DBLQUOTE | BACKSLASH )* DBLQUOTE;
BIT_STRING_LITERAL: ( INTEGER )? BASE_SPECIFIER DBLQUOTE (
   // BIT_VALUE
   GRAPHIC_CHARACTER ( ( UNDERSCORE )? GRAPHIC_CHARACTER )*
   )? DBLQUOTE;
// [TODO] tool_directive removed

COMMENT: '--' ( ~'\n' )* -> channel(HIDDEN);
BLOCK_COMMENT: '/*' .*? '*/' -> channel(HIDDEN);
TAB: ( '\t' )+ -> skip;
SPACE: ( SPACE_CHARACTER )+ -> skip;
NEWLINE: '\n' -> skip;
CR: '\r' -> skip;

SPACE_CHARACTER: ' ';
DBLQUOTE: '"';
UNDERSCORE: '_';
DIGIT:  '0'..'9';
SEMI: ';';
LPAREN: '(';
RPAREN: ')';
LSQUARE_BR: '[';
RSQUARE_BR: ']';
APOSTROPHE: '\'';
SHIFT_LEFT: '<<';
SHIFT_RIGHT: '>>';
AT: '@';
HASHTAG: '#';
COMMA: ',';
DOT: '.';
QUESTIONMARK: '?';
COLON: ':';
EQ: '=';
NE: '/=';
LT: '<';
GT: '>';
GE: '>=';
EQ_MATCH: '?=';
NE_MATCH: '?/=';
LT_MATCH: '?<';
LE_MATCH: '?<=';
GT_MATCH: '?>';
GE_MATCH: '?>=';
PLUS: '+';
MINUS: '-';
AMPERSAND: '&';
BAR: '|';
BACKSLASH: '\\';
MUL: '*';
DIV: '/';
DOUBLESTAR: '**';
CONASGN: '<=';
GRAVE_ACCENT: '`';
UP: '^';
VARASGN: ':=';
BOX: '<>';
ARROW: '=>';
COND_OP: '?' '?';
