#pragma once


namespace hdlConvertor {
namespace hdlObjects {

enum OperatorType {
	RANGE, // range used in VHDL type specifications
	REVERSE_RANGE,
	ACROSS,
	THROUGH,
	REFERENCE,
	TOLERANCE,
	INDEX, // array index
	DOWNTO, // downto for the slice specification
	TO,  // to for the slice specification
	SUB, // can also be unary minus
	ADD, // can also be unary plus
	DIV,
	MUL,
	MOD,
	REM,
	CONCAT,// concatenation of signals
	REPL_CONCAT, // replicative concatenation {<N>, <item>} duplicates and concatenates the item N times
	POW, // bin operator power of
	ABS, // absolute value
	NOT,
	NEG, // negation
	LOG_AND,
	LOG_OR,
	AND,
	OR,
	NAND,
	NOR,
	XOR,
	XNOR,
	EQ,  // ==
	NEQ, // ~
	LOWERTHAN, // <
	LE,   // <=
	GREATERTHAN, // >
	GE,  // >=
	SLL, // shift left logical
	SRL, // shift right logical
	SLA, // shift left arithmetical
	SRA, // shift right arithmetical
	ROL, // rotate left
	ROR, // rotate right
	TERNARY,
	DOT,
	CALL,
	ARROW, // arrow operator used in vhdl type descriptions
	RISING, // rising edge/posedge event operator
	FALLING,// falling edge/negedge event operator
	MAP_ASSOCIATION,
};

const char* OperatorType_toString(OperatorType opt);
int OperatorType_arity(OperatorType opt);

}
}
