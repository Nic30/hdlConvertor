/*
 * Grammar for parsing of grammar defined in PDFs with Verilog/VHDL standard 
 **/
grammar proto_grammar;

proto_file:
	(proto_rule)* EOF;

proto_rule: NAME WS? IS element END WS;

element:
	element_sequence
	| element_selection
;

element_block:
	  element_text
//	| element_in_parenthesis
	| element_iteration
	| element_optional
;
element_selection: element_sequence ('|' element_sequence)+;
element_sequence: WS? element_block (WS element_block)* WS?;


element_iteration: '{' element '}';
//element_in_parenthesis: '(' element ')';
element_optional: '[' element ']';
element_text: NAME | TERMINAL;


//----------------- LEXER --------------

TERMINAL: '<b>' .*? '</b>' ('-' '<b>' .*? '</b>')*;
IS: '::=';
WS: [ \n]+;
NAME: [a-zA-Z0-9_$]+;
QUESTIONMARK: '?';
END: '</br>';
