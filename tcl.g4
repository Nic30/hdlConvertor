grammar tcl;

statement_list:
 statement*;

statement:
	(return_stm 
	| array_set_stm
	| set_stm
	| func
	| if_stm
	| foreach_stm
	| for_stm
	| switch_stm
	| source_stm
	| (IDENTIFIER expr*)) ';'?;


// it is possibe to use grammar without explicit statements
// but we are using them to simplify parser code

func:
	'proc' IDENTIFIER '{' func_arg* '}' '{' statement* '}';

func_arg:
	(IDENTIFIER|func_arg_with_def_val);

func_arg_with_def_val:
	'{' IDENTIFIER expr '}';

if_stm:
	'if' '{' expr '}' '{' statement_list '}' if_elif*  if_else?;

if_else:
	'else' '{' statement_list '}';

if_elif: 
   'elseif' '{' expr '}' '{' statement_list '}';

foreach_stm:
  'foreach' expr expr '{' statement_list '}'; 

for_stm:
  'for' '{' statement '}' '{' expr '}' '{' statement '}' '{' statement_list '}'; 

switch_case: 
	expr '{' statement_list '}';

switch_stm:
	'switch' expr* '{'
		switch_case*
	 '}';

return_stm:
	'return' expr;

set_stm:
	'set' IDENTIFIER expr;

source_stm:
	'source'  (file_path_str | evaluation)+;

array_set_stm:
	'array' set_stm;

simple_expr:
	command_expr
	| unary_op
	| block_expr
	| terminal_expr
	| '(' expr ')'
	| terminal_expr argument_list;


expr:
	simple_expr
	| bin_op;

command_expr : 
	'[' statement ']';

block_expr:
	'{' expr* '}';

argument_list:
	'(' expr* ')';

terminal_expr:
	IDENTIFIER | NUMBER | QUOTED_STRING | evaluation;

evaluation:
	'$' (IDENTIFIER | block_expr);

unary_op:
	('+' | '-' ) expr;

bin_op:
	simple_expr ('+' | '-' | '*' | '/' | '%'  | '&&' | '||'
				| '<' | '<=' | '==' | '!=' | '>=' | '>'
				) expr;
	

file_path_str: ('.'| '/' | './')? (IDENTIFIER ('.'| '/')?)+;
NUMBER: [0-9]+ | [0-9]+ '.' [0-9]+;
IDENTIFIER:  ( [a-zA-Z_] | '*' )( [a-zA-Z0-9_-]  | '*' )*;
QUOTED_STRING: '"' (~('"' | '\\') | '\\' . )* '"';

SKIP_:
	( SPACES | COMMENT | LINE_JOINING ) -> skip;

 
fragment SPACES:
	([ \t\n] | '\\\n')+;

fragment COMMENT:
	'#' ~[\r\n\f]*;

fragment LINE_JOINING: 
	'\\' SPACES? ( '\r'? '\n' | '\r' | '\f');