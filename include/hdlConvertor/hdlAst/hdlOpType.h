#pragma once

namespace hdlConvertor {
namespace hdlAst {

enum HdlOpType {
	// arithmetic
	MINUS_UNARY,
	PLUS_UNARY,
	SUB, // -
	ADD, // +
	DIV, // /
	MUL, // *
	MOD, // % modulo
	REM, // remainder
	POW, // power of
	ABS, // absolute value
	INCR_PRE,  // ++x
	DECR_PRE,  // --x
	INCR_POST,  // x--
	DECR_POST,  // x++
	// bitwise log. operators
	NEG_LOG,  // ~, logical negation "not" in vhdl
	NEG,  // bitwise negation
	AND_LOG,  // "and" in vhdl, &&
	OR_LOG,  // "or" in vhdl, ||
	AND,  // & in vhdl
	OR,  // | in vhdl
	NAND,
	NOR,
	XOR,
	XNOR,
	// SV reduction operators
	OR_UNARY,  // or reduction (|a)
	AND_UNARY,  // and reduction (&a)
	NAND_UNARY,  // nand reduction (~&a)
	NOR_UNARY,  // nor reduction (~|a)
	XOR_UNARY,  // xor reduction (^a)
	XNOR_UNARY,  // and reduction (~^a) or (^~a)
	// shifts
	SLL,  // shift left logical
	SRL,  // shift right logical
	SLA,  // shift left arithmetical
	SRA,  // shift right arithmetical
	ROL,  // rotate left
	ROR,  // rotate right
	// comparison operators
	EQ,  // ==
	NE,  // !=
	IS,  // ===
	IS_NOT, // !==
	LT,  // <
	LE,   // <=
	GT,  // >
	GE,  // >=
	// VHDL-2008 matching ops (the X values are ignored while match)
	EQ_MATCH, // SV ==?
	NE_MATCH, // SV !=?
	LT_MATCH,
	LE_MATCH,
	GT_MATCH,
	GE_MATCH,
	// member accessing
	INDEX,  // array index
	CONCAT,  // concatenation of signals
	REPL_CONCAT,  // replicative concatenation {<N>, <item>}
				  // duplicates and concatenates the item N times
	PART_SELECT_POST, // logic [31: 0] a; logic [0 :31] b;  a[ 0 +: 8] == a[ 7 : 0]; b[ 0 +: 8] == b[0 : 7]
	PART_SELECT_PRE, // a[15 -: 8] == a[15 : 8]; b[15 -: 8] == b[8 :15]
	DOT,  // accessing of property
	DOUBLE_COLON,  // ::, SV accessing class/package static property/type
	APOSTROPHE,  // vhdl attribute access
	ARROW,  // pointer member access, VHDL arrow operator used in type descriptions
	REFERENCE,
	DEREFERENCE,
	// assignment operators
	ASSIGN,  // =
	PLUS_ASSIGN,  // +=
	MINUS_ASSIGN,  // -=
	MUL_ASSIGN,  // *=
	DIV_ASSIGN,  // /=
	MOD_ASSIGN,  // %=
	AND_ASSIGN,  // &=
	OR_ASSIGN,  // |=
	XOR_ASSIGN,  // ^=
	SHIFT_LEFT_ASSIGN,  // <<=
	SHIFT_RIGHT_ASSIGN,  // >>=
	ARITH_SHIFT_LEFT_ASSIGN,  // <<<=
	ARITH_SHIFT_RIGHT_ASSIGN,  // >>>=

	TERNARY, // cond ? a:b, a if cond else b
	CALL,  // call of HDL function
	RISING,  // rising edge/posedge event operator
	FALLING,  // falling edge/negedge event operator
	DOWNTO,  // downto for the slice specification
	TO,  // to for the slice specification
	PARAMETRIZATION,  // specification of template arguments
	MAP_ASSOCIATION, // arg=val
	RANGE,  // range used in VHDL type specifications
	THROUGHOUT,  // SV throughout operator
	DEFINE_RESOLVER,  // used in resolver specification in vhdl subtype definition
	TYPE_OF,  // SV type operator
	UNIT_SPEC, // vhdl unit specification eg. 10 ns
};

HdlOpType HdlOpType_toUnary(HdlOpType o);
const char* HdlOpType_toString(HdlOpType opt);

}
}
