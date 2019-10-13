#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <stdexcept>
#include <assert.h>

namespace hdlConvertor {
namespace hdlObjects {

static const char* const opTypeToStr[HdlOperatorType::ARITH_SHIFT_RIGHT_ASSIGN + 1] = {
		"RANGE",
		"REVERSE_RANGE",
		"ACROSS",
		"THROUGH",
		"REFERENCE",
		"TOLERANCE",
		"TYPE_OF",
		"INDEX",
		"DOWNTO",
		"TO",
		"SUB",
		"ADD",
		"DIV",
		"MUL",
		"MOD",
		"REM",
		"CONCAT",
		"REPL_CONCAT",
		"POW",
		"ABS",
		"NOT",
		"NEG",
		"LOG_AND",
		"LOG_OR",
		"AND",
		"OR",
		"NAND",
		"NOR",
		"XOR",
		"XNOR",
		"EQ",
		"NEQ",
		"LT",
		"LE",
		"GT",
		"GE",
		"SLL",
		"SRL",
		"SLA",
		"SRA",
		"ROL",
		"ROR",
		"TERNARY",
		"DOT",
		"DOUBLE_COLON",
		"APOSTROPHE",
		"CALL",
		"PARAMETRIZATION",
		"ARROW",
		"RISING",
		"FALLING",
		"MAP_ASSOCIATION",
		"MATCH_EQ",
		"MATCH_NEQ",
		"MATCH_LT",
		"MATCH_LE",
		"MATCH_GT",
		"MATCH_GE",
		"INCR_PRE",
		"DECR_PRE",
		"INCR_POST",
		"DECR_POST",
	    "ASSIGN",
	    "PLUS_ASSIGN",
	    "MINUS_ASSIGN",
	    "MUL_ASSIGN",
	    "DIV_ASSIGN",
	    "MOD_ASSIGN",
	    "AND_ASSIGN",
	    "OR_ASSIGN",
	    "XOR_ASSIGN",
	    "SHIFT_LEFT_ASSIGN",
	    "SHIFT_RIGHT_ASSIGN",
	    "ARITH_SHIFT_LEFT_ASSIGN",
	    "ARITH_SHIFT_RIGHT_ASSIGN",
};

const char* HdlOperatorType_toString(HdlOperatorType opt) {
	if (opt > HdlOperatorType::ARITH_SHIFT_RIGHT_ASSIGN)
		throw std::runtime_error("Invalid operator type");
	return opTypeToStr[opt];
}


}
}
