#pragma once

enum OperatorType {
	RANGE, // range used in VHDL type specifications
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
	POW, // bin operator power of
	ABS, // absolute val
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
};

const char* OperatorType_toString(OperatorType opt);
int OperatorType_arity(OperatorType opt);
