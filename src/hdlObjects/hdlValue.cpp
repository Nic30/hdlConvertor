#include <stdexcept>
#include <hdlConvertor/hdlObjects/hdlValue.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlValue::HdlValue(const HdlValue & other) :
		type(other.type), bits(other.bits), _int(other._int), _float(
				other._float), _str(other._str) {
	if (other._arr) {
		_arr = new std::vector<iHdlExpr*>(*other._arr);
	} else {
		_arr = nullptr;
	}
}
HdlValue::HdlValue(BigInteger __int) :
		type(LiteralValType::symb_INT), bits(-1), _int(__int), _float(0.0), _str(
				""), _arr(nullptr) {
}
HdlValue::HdlValue(const BigInteger & __int, int _bits) :
		type(LiteralValType::symb_INT), bits(_bits), _int(__int), _float(0.0), _str(
				""), _arr(nullptr) {

}
HdlValue::HdlValue(double __float) :
		type(LiteralValType::symb_FLOAT), bits(-1), _int(0), _float(__float), _str(
				""), _arr(nullptr) {
}
HdlValue::HdlValue(std::string __str) :
		type(LiteralValType::symb_ID), bits(-1), _int(0), _float(0.0), _str(__str), _arr(
				nullptr) {
}

HdlValue::HdlValue(LiteralValType _type) :
		type(_type), bits(-1), _int(0), _float(0.0), _str(""), _arr(nullptr) {

}

HdlValue::HdlValue(const std::vector<iHdlExpr*> * arr) :
		type(LiteralValType::symb_ARRAY), bits(-1), _int(0), _float(0.0), _str(""), _arr(
				arr) {

}

iHdlExprItem * HdlValue::clone() const {
	return new HdlValue(*this);
}

HdlValue::~HdlValue() {
	if (type == LiteralValType::symb_ARRAY)
		delete _arr;
}

const char * HdlValueType_toString(LiteralValType t) {
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
