#include <hdlConvertor/hdlAst/hdlOpType.h>
#include <stdexcept>
#include <assert.h>

namespace hdlConvertor {
namespace hdlAst {

static const char* const opTypeToStr[HdlOpType::ARITH_SHIFT_RIGHT_ASSIGN + 1] = {
		"RANGE",
		"THROUGHOUT",
		"REFERENCE",
		"DEREFERENCE",
		"DEFINE_RESOLVER",
		"TYPE_OF",
		"INDEX",
		"DOWNTO",
		"TO",
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
		"NE",
		"IS",
		"IS_NOT",
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
		"NE_MATCH",
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


HdlOpType HdlOpType_toUnary(HdlOpType o) {
	switch(o) {
	case HdlOpType::SUB:
		return HdlOpType::MINUS_UNARY;
	case HdlOpType::ADD:
		return HdlOpType::PLUS_UNARY;
	case HdlOpType::OR:
		return HdlOpType::OR_UNARY;
	case HdlOpType::AND:
		return HdlOpType::AND_UNARY;
	case HdlOpType::NAND:
		return HdlOpType::NAND_UNARY;
	case HdlOpType::NOR:
		return HdlOpType::NOR_UNARY;
	case HdlOpType::XOR:
		return HdlOpType::XOR_UNARY;
	case HdlOpType::XNOR:
		return HdlOpType::XNOR;
	default:
		throw std::runtime_error("Invalid operator type");
	}
}

const char* HdlOpType_toString(HdlOpType opt) {
	if (opt > HdlOpType::ARITH_SHIFT_RIGHT_ASSIGN)
		throw std::runtime_error("Invalid operator type");
	return opTypeToStr[opt];
}


}
}
