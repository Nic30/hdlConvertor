#pragma once

namespace hdlConvertor {
namespace hdlAst {

enum HdlOpType {
	RANGE, // range used in VHDL type specifications
	THROUGHOUT, // sv throughout operator
	REFERENCE,
	DEREFERENCE,
	DEFINE_RESOLVER, // used in resolver specification in vhdl subtype definition
	TYPE_OF, // SV type operator
	INDEX, // array index
	DOWNTO, // downto for the slice specification
	TO,  // to for the slice specification
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
	AND,
	OR,
	NAND,
	NOR,
	XOR,
	XNOR,
	EQ,  // ==
	NE, // !=
	IS,  // ===
	IS_NOT, // !==
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
	EQ_MATCH, // SV ==? VHDL-2008 matching ops (the X values are ignored while match)
	NE_MATCH, // SV !=?
	LT_MATCH,
	LE_MATCH,
	GT_MATCH,
	GE_MATCH,
	INCR_PRE,  // ++x
	DECR_PRE,  // --x
	INCR_POST, // x--
	DECR_POST, // x++
    ASSIGN, // =
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

HdlOpType HdlOpType_toUnary(HdlOpType o);
const char* HdlOpType_toString(HdlOpType opt);

}
}
