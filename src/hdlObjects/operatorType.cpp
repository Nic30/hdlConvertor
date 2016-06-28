#include "operatorType.h"

static const char* const opTypeToStr[] = {
	"RANGE",
	"INDEX",
	"DOWNTO",
	"TO",
	"UN_MINUS",
	"UN_PLUS",
	"SUB",
	"ADD",
	"DIV",
	"MUL",
	"MOD",
	"REM",
	"CONCAT",
	"POW",
	"ABS",
	"NOT",
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
	"ARROW"
};

const char* OperatorType_toString(OperatorType opt) {
	if (opt < RANGE || opt > ARROW)
		throw "Invalid operator type";

	return opTypeToStr[opt];
}

int OperatorType_arity(OperatorType opt) {
	switch (opt) {
	case CALL:
		return -1;
	case NOT:
	case UN_MINUS:
	case UN_PLUS:
	case ABS:
	case RANGE:
		return 1;
	case TERNARY:
		return 3;
	default:
		return 2;
	}
}
