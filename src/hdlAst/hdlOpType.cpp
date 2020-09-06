#include <hdlConvertor/hdlAst/hdlOpType.h>
#include <stdexcept>
#include <assert.h>

namespace hdlConvertor {
namespace hdlAst {

static const char* const opTypeToStr[HdlOpType::UNIT_SPEC + 1] = {
		"MINUS_UNARY",
		"PLUS_UNARY",
		"SUB",
		"ADD",
		"DIV",
		"MUL",
		"MOD",
		"REM",
		"POW",
		"ABS",
		"INCR_PRE",
		"DECR_PRE",
		"INCR_POST",
		"DECR_POST",
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
		"OR_UNARY",
		"AND_UNARY",
		"NAND_UNARY",
		"NOR_UNARY",
		"XOR_UNARY",
		"XNOR_UNARY",
		"SLL",
		"SRL",
		"SLA",
		"SRA",
		"ROL",
		"ROR",
		"EQ",
		"NE",
		"IS",
		"IS_NOT",
		"LT",
		"LE",
		"GT",
		"GE",
		"EQ_MATCH",
		"NE_MATCH",
		"LT_MATCH",
		"LE_MATCH",
		"GT_MATCH",
		"GE_MATCH",
		"INDEX",
		"CONCAT",
		"REPL_CONCAT",
		"PART_SELECT_POST",
		"PART_SELECT_PRE",
		"DOT",
		"DOUBLE_COLON",
		"APOSTROPHE",
		"ARROW",
		"REFERENCE",
		"DEREFERENCE",
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
		"TERNARY",
		"CALL",
		"RISING",
		"FALLING",
		"DOWNTO",
		"TO",
		"PARAMETRIZATION",
		"MAP_ASSOCIATION",
		"RANGE",
		"THROUGHOUT",
		"DEFINE_RESOLVER",
		"TYPE_OF",
		"UNIT_SPEC",
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
	if (opt > HdlOpType::UNIT_SPEC)
		throw std::range_error("Invalid operator type");
	return opTypeToStr[opt];
}


}
}
