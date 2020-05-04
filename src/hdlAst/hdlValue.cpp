#include <hdlConvertor/hdlAst/hdlValue.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

#include <array>
#include <assert.h>

using namespace std;

namespace hdlConvertor {
namespace hdlAst {

HdlValueArr::HdlValueArr(const HdlValueArr &other) :
		iHdlExprItem() {
	assert(other._arr);
	_arr = make_unique<vector<unique_ptr<iHdlExprItem>>>();
	clone_unique_ptr_vector(*other._arr, *_arr);
}

HdlValueArr::HdlValueArr(std::vector<std::unique_ptr<iHdlExprItem>> &arr) {
	_arr = make_unique<vector<unique_ptr<iHdlExprItem>>>(move(arr));
}
HdlValueArr::HdlValueArr(unique_ptr<vector<unique_ptr<iHdlExprItem>>> arr) :
		_arr(move(arr)) {
}
iHdlExprItem* HdlValueArr::clone() const {
	return new HdlValueArr(*this);
}
HdlValueArr::~HdlValueArr() {
}

HdlValueId::HdlValueId(string __str) :
		_str(__str) {
}
iHdlExprItem* HdlValueId::clone() const {
	return new HdlValueId(*this);
}
HdlValueId::~HdlValueId() {
}

HdlValueInt::HdlValueInt(BigInteger __int) :
		bits(-1), _int(__int) {
}

HdlValueInt::HdlValueInt(const BigInteger &__int, int _bits) :
		bits(_bits), _int(__int) {
}
HdlValueInt::HdlValueInt(const string &value, int radix) :
		HdlValueInt(BigInteger(value, radix)) {
}

HdlValueInt::HdlValueInt(const string &value, int bits, int radix) :
		HdlValueInt(BigInteger(value, radix), bits) {
}

iHdlExprItem* HdlValueInt::clone() const {
	return new HdlValueInt(*this);
}
HdlValueInt::~HdlValueInt() {
}

HdlValueFloat::HdlValueFloat(double __float) :
		_float(__float) {
}
iHdlExprItem* HdlValueFloat::clone() const {
	return new HdlValueFloat(*this);
}
HdlValueFloat::~HdlValueFloat() {
}

HdlValueStr::HdlValueStr(const string &s) :
		_str(s) {
}
iHdlExprItem* HdlValueStr::clone() const {
	return new HdlValueStr(*this);
}
HdlValueStr::~HdlValueStr() {
}

HdlValueSymbol::HdlValueSymbol(HdlValueSymbol_t _type) :
		symb(_type) {
}
unique_ptr<HdlValueSymbol> HdlValueSymbol::null() {
	return make_unique<HdlValueSymbol>(HdlValueSymbol_t::symb_NULL);
}
unique_ptr<HdlValueSymbol> HdlValueSymbol::open() {
	return make_unique<HdlValueSymbol>(HdlValueSymbol_t::symb_OPEN);
}
unique_ptr<HdlValueSymbol> HdlValueSymbol::all() {
	return make_unique<HdlValueSymbol>(HdlValueSymbol_t::symb_ALL);
}
unique_ptr<HdlValueSymbol> HdlValueSymbol::others() {
	return make_unique<HdlValueSymbol>(HdlValueSymbol_t::symb_OTHERS);
}
unique_ptr<HdlValueSymbol> HdlValueSymbol::type() {
	return make_unique<HdlValueSymbol>(HdlValueSymbol_t::symb_T);
}
unique_ptr<HdlValueSymbol> HdlValueSymbol::type_auto() {
	return make_unique<HdlValueSymbol>(HdlValueSymbol_t::symb_T_AUTO);
}
unique_ptr<HdlValueSymbol> HdlValueSymbol::type_subtype() {
	return make_unique<HdlValueSymbol>(HdlValueSymbol_t::symb_T_SUBTYPE);
}
iHdlExprItem* HdlValueSymbol::clone() const {
	return new HdlValueSymbol(symb);
}
HdlValueSymbol::~HdlValueSymbol() {
}

iHdlExprItem* HdlExprNotImplemented::clone() const {
	return new HdlExprNotImplemented();
}

HdlExprNotImplemented::~HdlExprNotImplemented() {
}

const array<const string, HdlValueSymbol_t::symb_T_AUTO + 1> HdlValueSymbol_t_str =
		{ "NULL", "OPEN", "ALL", "OTHERS", "T", "AUTO" };

const char* HdlValueSymbol::toString() {
	return HdlValueSymbol::toString(symb);
}

const char* HdlValueSymbol::toString(HdlValueSymbol_t t) {
	return HdlValueSymbol_t_str.at(t).c_str();
}

}
}
