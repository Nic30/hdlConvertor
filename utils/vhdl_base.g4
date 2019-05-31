LOWER_CASE_LETTER: 'a'..'z';
UPPER_CASE_LETTER: 'A'..'Z';

COMMENT: '--' ( ~'\n' )* -> channel(HIDDEN);
TAB: ( '\t' )+ -> skip;
SPACE: ( ' ' )+ -> skip;
NEWLINE: '\n' -> skip;
CR: '\r' -> skip;

SPECIAL_CHARACTER:
    '"' | '#' | '&' | '\'' | '(' | ')' | '*' | '+'
  | ',' | '-' | '.' | '/' | ':' | ';' | '<' | '='
  | '>' | '?' | '@' | '[' | ']' | '_' | '`' | '|';

OTHER_SPECIAL_CHARACTER:
    '!' | '$' | '%' | '@' | '?' | '^' | '`' | '{' | '}' | '~'
  | ' ' | 'Ў' | 'ў' | 'Ј' | '¤' | 'Ґ' | '¦' | '§'
  | 'Ё' | '©' | 'Є' | '«' | '¬' | '­' | '®' | 'Ї'
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
  ;

FORMAT_EFFECTOR: '\t' | '\n' ; // | '\v' | '\c' | '\f';
SPACE_CHARACTER: ' ';
UNDERLINE: '_';
DIGIT:  '0'..'9';
E_SIGN: 'e' | 'E';
NULL_SYM: N U L L;

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


// name:
//       simple_name
//       | operator_symbol
//       | character_literal
//       | selected_name
//       | indexed_name
//       | slice_name
//       | attribute_name
//       | external_name
// ;
// prefix:
//       name
//       | function_call
// ;
// selected_name: prefix DOT suffix;
// suffix:
//       simple_name
//       | character_literal
//       | operator_symbol
//       | ALL
// ;
// indexed_name: prefix LPAREN expression ( COMMA expression )* RPAREN;
// slice_name: prefix LPAREN discrete_range RPAREN;
// attribute_name:
//       prefix ( signature )? APOSTROPHE attribute_designator ( LPAREN expression RPAREN )?
// ;
//
// changed to avoid left-recursion to name (from selected_name, indexed_name,
// slice_name, and attribute_name, respectively)
// (2.2.2004, e.f.)
name
  : selected_name
  | name_part ( DOT name_part)*
  | external_name
  ;

name_part
   : selected_name (name_part_specificator)*
   ;

name_part_specificator
   : name_attribute_part
   | name_function_call_or_indexed_part
   | name_slice_part
   ;

name_attribute_part
   : APOSTROPHE attribute_designator ( expression ( COMMA expression )* )?
   ;

name_function_call_or_indexed_part
   : LPAREN actual_parameter_part? RPAREN
   ;

name_slice_part
   : LPAREN explicit_range ( COMMA explicit_range )* RPAREN
   ;

explicit_range
  : simple_expression direction simple_expression
  ;

selected_name :
   identifier (DOT suffix)*
   ;
