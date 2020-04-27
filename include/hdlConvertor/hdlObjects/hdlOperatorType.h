#pragma once

namespace hdlConvertor {
namespace hdlObjects {

enum HdlOperatorType {
	ACROSS,
	THROUGH,
	REFERENCE,
	DEREFERENCE,
	TOLERANCE,
	TYPE_OF, // SV type operator
	INDEX, // array index
	MINUS_UNARY,
	PLUS_UNARY,
	OR_UNARY, // SV or reduction (|a)
	AND_UNARY, // SV and reduction (&a)
	NAND_UNARY, // SV nand reduction (~&a)
	NOR_UNARY, // SV nor reduction (~|a)
	XOR_UNARY, // SV xor reduction (^a)
	XNOR_UNARY, // SV and reduction (~^a) or (^~a)
	SUB,
	ADD,
	DIV,
	MUL,
	MOD, // modulo
	REM, // reminder
	CONCAT, // concatenation of signals
	REPL_CONCAT, // replicative concatenation {<N>, <item>}
	             //duplicates and concatenates the item N times
	POW, // power of
	ABS, // absolute value
	NEG_LOG, // logical negation "not" in vhdl
	NEG, // bitwise negation
	AND_LOG, // "and" in vhdl
	OR_LOG,  // "or" in vhdl
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
	EQ_MATCH, // VHDL-2008 matching ops (the X values are ignored while match)
	NEQ_MATCH,
	LT_MATCH,
	LE_MATCH,
	GT_MATCH,
	GE_MATCH,
	INCR_PRE,
	DECR_PRE,
	INCR_POST,
	DECR_POST,
    ASSIGN,
    PLUS_ASSIGN, // +=
    MINUS_ASSIGN, // -=
    MUL_ASSIGN, // *=
    DIV_ASSIGN, // /=
    MOD_ASSIGN, // %=
    AND_ASSIGN, // &=
    OR_ASSIGN, // |=
    XOR_ASSIGN, // ^=
    SHIFT_LEFT_ASSIGN, // <<=
    SHIFT_RIGHT_ASSIGN, // >>=
    ARITH_SHIFT_LEFT_ASSIGN, // <<<=
    ARITH_SHIFT_RIGHT_ASSIGN, // >>>=
};

enum HdlRangeDirection {TO, DOWNTO};

HdlOperatorType HdlOperatorType_toUnary(HdlOperatorType o);
const char* HdlOperatorType_toString(HdlOperatorType opt);

}
}
