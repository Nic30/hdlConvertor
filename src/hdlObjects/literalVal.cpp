#include <stdexcept>
#include <hdlConvertor/hdlObjects/literalVal.h>

namespace hdlConvertor {
namespace hdlObjects {

LiteralVal::LiteralVal(const LiteralVal & other) :
		type(other.type), bits(other.bits), _int(other._int), _float(
				other._float), _str(other._str) {
	if (other._arr) {
		_arr = new std::vector<Expr*>(*other._arr);
	} else {
		_arr = nullptr;
	}
}
LiteralVal::LiteralVal(BigInteger __int) :
		type(LiteralValType::symb_INT), bits(-1), _int(__int), _float(0.0), _str(
				""), _arr(nullptr) {
}
LiteralVal::LiteralVal(const BigInteger & __int, int _bits) :
		type(LiteralValType::symb_INT), bits(_bits), _int(__int), _float(0.0), _str(
				""), _arr(nullptr) {

}
LiteralVal::LiteralVal(double __float) :
		type(LiteralValType::symb_FLOAT), bits(-1), _int(0), _float(__float), _str(
				""), _arr(nullptr) {
}
LiteralVal::LiteralVal(std::string __str) :
		type(LiteralValType::symb_ID), bits(-1), _int(0), _float(0.0), _str(__str), _arr(
				nullptr) {
}

LiteralVal::LiteralVal(LiteralValType _type) :
		type(_type), bits(-1), _int(0), _float(0.0), _str(""), _arr(nullptr) {

}

LiteralVal::LiteralVal(const std::vector<Expr*> * arr) :
		type(LiteralValType::symb_ARRAY), bits(-1), _int(0), _float(0.0), _str(""), _arr(
				arr) {

}

ExprItem * LiteralVal::clone() const {
	return new LiteralVal(*this);
}

LiteralVal::~LiteralVal() {
	if (type == LiteralValType::symb_ARRAY)
		delete _arr;
}

const char * LiteralValType_toString(LiteralValType t) {
	switch (t) {
	case LiteralValType::symb_ID:
		return "ID";
	case LiteralValType::symb_INT:
		return "INT";
	case LiteralValType::symb_FLOAT:
		return "FLOAT";
	case LiteralValType::symb_STRING:
		return "STRING";
	case LiteralValType::symb_OPEN:
		return "OPEN";
	case LiteralValType::symb_ARRAY:
		return "ARRAY";
	case LiteralValType::symb_ALL:
		return "ALL";
	case LiteralValType::symb_OTHERS:
		return "OTHERS";
	case LiteralValType::symb_T:
		return "TYPE";
	default:
		return "NULL";
	}
}

}
}
