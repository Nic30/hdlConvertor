grammar proto_grammar;

proto_file:
	(proto_rule WS)* EOF;

proto_rule: NAME WS? IS element;

element:
	  element_text
	| element_in_parenthesis
	| element_iteration
	| element_optional
	| element ('|' element)+;

element_iteration: '{' element+ '}' WS?;
element_in_parenthesis: WS? '(' element+ ')' WS?;
element_optional: WS? '[' element+ ']' WS?;
element_text_part: NAME | TERMINAL;
element_text: WS? element_text_part (WS element_text_part)? WS?;


//----------------- LEXER --------------

TERMINAL: '<b>' .*? '</b>';
IS: '::=';
WS: [ \n]+;
NAME: [a-zA-Z0-9_]+;
QUESTIONMARK: '?';
