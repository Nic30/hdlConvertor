#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <stdexcept>
#include <assert.h>

namespace hdlConvertor {
namespace hdlObjects {

static const char* const opTypeToStr[HdlOperatorType::ARITH_SHIFT_RIGHT_ASSIGN + 1] = {
		"ACROSS",
		"THROUGH",
		"REFERENCE",
		"DEREFERENCE",
		"TOLERANCE",
		"TYPE_OF",
		"INDEX",
		"MINUS_UNARY",
		"PLUS_UNARY",
		"OR_UNARY",
		"AND_UNARY",
		"NAND_UNARY",
		"NOR_UNARY",
		"XOR_UNARY",
		"XNOR_UNARY",
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
		"NEG_LOG",
		"NEG",
		"AND_LOG",
		"OR_LOG",
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
		"EQ_MATCH",
		"NEQ_MATCH",
		"LT_MATCH",
		"LE_MATCH",
		"GT_MATCH",
		"GE_MATCH",
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


HdlOperatorType HdlOperatorType_toUnary(HdlOperatorType o) {
	switch(o) {
	case HdlOperatorType::SUB:
		return HdlOperatorType::MINUS_UNARY;
	case HdlOperatorType::ADD:
		return HdlOperatorType::PLUS_UNARY;
	case HdlOperatorType::OR:
		return HdlOperatorType::OR_UNARY;
	case HdlOperatorType::AND:
		return HdlOperatorType::AND_UNARY;
	case HdlOperatorType::NAND:
		return HdlOperatorType::NAND_UNARY;
	case HdlOperatorType::NOR:
		return HdlOperatorType::NOR_UNARY;
	case HdlOperatorType::XOR:
		return HdlOperatorType::XOR_UNARY;
	case HdlOperatorType::XNOR:
		return HdlOperatorType::XNOR;
	default:
		throw std::runtime_error("Invalid operator type");
	}
}

const char* HdlOperatorType_toString(HdlOperatorType opt) {
	if (opt > HdlOperatorType::ARITH_SHIFT_RIGHT_ASSIGN)
		throw std::runtime_error("Invalid operator type");
	return opTypeToStr[opt];
}


}
}
