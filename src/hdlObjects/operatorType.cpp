#include "operatorType.h"

static const char* const opTypeToStr[] = {
	"RANGE",
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
	"FALLING"
};

const char* OperatorType_toString(OperatorType opt) {
	if (opt < RANGE || opt > FALLING)
		throw "Invalid operator type";

	return opTypeToStr[opt];
}

int OperatorType_arity(OperatorType opt) {
	switch (opt) {
	case CALL:
		return -1;
	case NOT:
	case ABS:
	case RANGE:
		return 1;
	case TERNARY:
		return 3;
	default:
		return 2;
	}
}
