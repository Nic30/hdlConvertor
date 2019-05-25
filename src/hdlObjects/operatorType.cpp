#include "operatorType.h"

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
		"LOWERTHAN",
		"LE",
		"GREATERTHAN",
		"GE",
		"SLL",
		"SRL",
		"SLA",
		"SRA",
		"ROL",
		"ROR",
		"TERNARY",
		"DOT",
		"CALL",
		"ARROW",
		"RISING",
		"FALLING",
		"MAP_ASSOCIATION",
};

const char* OperatorType_toString(OperatorType opt) {
	if (opt < RANGE || opt > MAP_ASSOCIATION)
		throw "Invalid operator type";

	return opTypeToStr[opt];
}

int OperatorType_arity(OperatorType opt) {
	switch (opt) {
	case CALL:
		return -1;
	case NOT:
	case ABS:
	case RANGE || REVERSE_RANGE || ACROSS || THROUGH || REFERENCE || TOLERANCE:
		return 1;
	case TERNARY:
		return 3;
	default:
		return 2;
	}
}

}
}
