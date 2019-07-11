#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace hdlObjects {

static const char* const opTypeToStr[] = {
		"RANGE",
		"REVERSE_RANGE",
		"ACROSS",
		"THROUGH",
		"REFERENCE",
		"TOLERANCE",
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
		"APOSTROPHE",
		"CALL",
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
};

const char* HdlOperatorType_toString(HdlOperatorType opt) {
	if (opt < RANGE || opt > MAP_ASSOCIATION)
		throw "Invalid operator type";

	return opTypeToStr[opt];
}


}
}
