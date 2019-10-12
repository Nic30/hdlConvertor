#pragma once

namespace hdlConvertor {
namespace hdlObjects {

enum HdlOperatorType {
	RANGE, // range used in VHDL type specifications
	REVERSE_RANGE,
	ACROSS,
	THROUGH,
	REFERENCE,
	TOLERANCE,
	TYPE_OF,
	INDEX, // array index
	DOWNTO, // downto for the slice specification
	TO,  // to for the slice specification
	SUB, // can also be unary minus
	ADD, // can also be unary plus
	DIV,
	MUL,
	MOD,
	REM,
	CONCAT, // concatenation of signals
	REPL_CONCAT, // replicative concatenation {<N>, <item>} duplicates and concatenates the item N times
	POW, // bin operator power of
	ABS, // absolute value
	NOT,
	NEG, // negation
	LOG_AND, // "and" in vhdl
	LOG_OR,  // "or" in vhdl
	AND, // & in vhdl
	OR,  // | in vhdl
	NAND,
	NOR,
	XOR,
	XNOR,
	EQ,  // ==
	NEQ, // ~
	LT, // <
	LE,   // <=
	GT, // >
	GE,  // >=
	SLL, // shift left logical
	SRL, // shift right logical
	SLA, // shift left arithmetical
	SRA, // shift right arithmetical
	ROL, // rotate left
	ROR, // rotate right
	TERNARY,
	DOT, // accessing of property
	DOUBLE_COLON, // SV accessing class/package static property/type
	APOSTROPHE, // vhdl attribute access
	CALL, // call of HDL function
	PARAMETRIZATION, // specification of template arguments
	ARROW, // arrow operator used in vhdl type descriptions
	RISING, // rising edge/posedge event operator
	FALLING, // falling edge/negedge event operator
	MAP_ASSOCIATION,
	MATCH_EQ, // VHDL-2008 matching ops (the X values are ignored while match)
	MATCH_NEQ,
	MATCH_LT,
	MATCH_LE,
	MATCH_GT,
	MATCH_GE,
	INCR_PRE,
	DECR_PRE,
	INCR_POST,
	DECR_POST,
    ASSIGN,
    PLUS_ASSIGN,
    MINUS_ASSIGN,
    MUL_ASSIGN,
    DIV_ASSIGN,
    MOD_ASSIGN,
    AND_ASSIGN,
    OR_ASSIGN,
    XOR_ASSIGN,
    SHIFT_LEFT_ASSIGN,
    SHIFT_RIGHT_ASSIGN,
    ARITH_SHIFT_LEFT_ASSIGN,
    ARITH_SHIFT_RIGHT_ASSIGN,
};

const char* HdlOperatorType_toString(HdlOperatorType opt);

}
}
