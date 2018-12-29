grammar symbol;

pattern : 
    SYMBOL ('(' SYMBOL ( ',' SYMBOL )* ')' )? EOF;

SYMBOL: LETTER (LETTER | [0-9] | '_' )* ;


LETTER
    : [A-Za-z_]
    ;

WS: [ \t\r\n]+ -> skip;
