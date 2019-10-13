#include <hdlConvertor/hdlObjects/hdlValue.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

#include <array>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlValue::HdlValue(const HdlValue &other) :
		type(other.type), bits(other.bits), _int(other._int), _float(
				other._float), _str(other._str) {
	if (other._arr) {
		_arr = make_unique<vector<unique_ptr<iHdlExpr>>>();
		clone_unique_ptr_vector(*other._arr, *_arr);
	} else {
		_arr = nullptr;
	}
}

HdlValue::HdlValue(BigInteger __int) :
		type(HdlValueType::symb_INT), bits(-1), _int(__int), _float(0.0), _str(
				""), _arr(nullptr) {
}

HdlValue::HdlValue(const BigInteger &__int, int _bits) :
		type(HdlValueType::symb_INT), bits(_bits), _int(__int), _float(0.0), _str(
				""), _arr(nullptr) {
}

HdlValue::HdlValue(double __float) :
		type(HdlValueType::symb_FLOAT), bits(-1), _int(0), _float(__float), _str(
				""), _arr(nullptr) {
}

HdlValue::HdlValue(string __str) :
		type(HdlValueType::symb_ID), bits(-1), _int(0), _float(0.0), _str(
				__str), _arr(nullptr) {
}

HdlValue::HdlValue(HdlValueType _type) :
		type(_type), bits(-1), _int(0), _float(0.0), _str(""), _arr(nullptr) {
}

HdlValue::HdlValue(unique_ptr<vector<unique_ptr<iHdlExpr>>> arr) :
		type(HdlValueType::symb_ARRAY), bits(-1), _int(0), _float(0.0), _str(
				""), _arr(move(arr)) {
}

iHdlExprItem* HdlValue::clone() const {
	return new HdlValue(*this);
}

HdlValue::~HdlValue() {
}

const array<const string, HdlValueType::symb_AUTO + 1> HdlValueType_str = {
		"ID", "INT", "FLOAT", "STRING", "ARRAY", "NULL", "OPEN", "ALL",
		"OTHERS", "T", "AUTO" };

const char* HdlValueType_toString(HdlValueType t) {
	return HdlValueType_str.at(t).c_str();
}

}
}
