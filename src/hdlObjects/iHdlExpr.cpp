#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <stdexcept>
#include <string.h>
#include <assert.h>

#include <hdlConvertor/hdlObjects/hdlCall.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlValue __v = { BigInteger(0) };
static HdlValue AutoType_t(HdlValueType::symb_AUTO);
static HdlValue Type_t(HdlValueType::symb_T); // symbol representing that expr is type of type;

iHdlExpr::iHdlExpr() {
	data = nullptr;
}

iHdlExpr::iHdlExpr(const iHdlExpr &expr) {
	if (expr.data == nullptr || expr.data == &Type_t
			|| expr.data == &AutoType_t) {
		data = expr.data;
	} else {
		data = expr.data->clone();
	}
}
iHdlExpr::iHdlExpr(HdlOperatorType operatorType,
		std::unique_ptr<iHdlExpr> op0) {
	assert(op0);
	data = new HdlCall(operatorType, move(op0));
}
iHdlExpr::iHdlExpr(std::unique_ptr<iHdlExpr> op0, HdlOperatorType operatorType,
		std::unique_ptr<iHdlExpr> op1) {
	assert(op0);
	data = new HdlCall(move(op0), operatorType, move(op1));
}
iHdlExpr::iHdlExpr(const HdlValue &value) :
		data(new HdlValue(value)) {
}
iHdlExpr::iHdlExpr(HdlValue *value) :
		data(value) {
}

iHdlExpr::iHdlExpr(const BigInteger &value, int bits) {
	data = new HdlValue(value, bits);
}
iHdlExpr::iHdlExpr(const BigInteger &value) :
		data(new HdlValue(value, -1)) {
}
std::unique_ptr<iHdlExpr> iHdlExpr::INT(const std::string &strVal, int base) {
	return make_unique<iHdlExpr>(BigInteger(strVal, base));
}
std::unique_ptr<iHdlExpr> iHdlExpr::INT(const std::string &strVal, int bits,
		int base) {
	return make_unique<iHdlExpr>(new HdlValue(BigInteger(strVal, base), bits));
}
std::unique_ptr<iHdlExpr> iHdlExpr::INT(int64_t val) {
	return make_unique<iHdlExpr>(BigInteger(val));
}
std::unique_ptr<iHdlExpr> iHdlExpr::FLOAT(double val) {
	return make_unique<iHdlExpr>(new HdlValue(val));
}

std::unique_ptr<iHdlExpr> iHdlExpr::STR(std::string strVal) {
	auto l = new HdlValue(strVal);
	l->type = HdlValueType::symb_STRING;
	return make_unique<iHdlExpr>(l);
}

std::unique_ptr<iHdlExpr> iHdlExpr::ARRAY(
		std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> arr) {
	return make_unique<iHdlExpr>(new HdlValue(move(arr)));
}

std::unique_ptr<iHdlExpr> iHdlExpr::ARRAY(
		std::vector<std::unique_ptr<iHdlExpr>> &arr) {
	auto _arr = make_unique<std::vector<std::unique_ptr<iHdlExpr>>>(move(arr));
	return ARRAY(move(_arr));
}

std::unique_ptr<iHdlExpr> iHdlExpr::OPEN() {
	return make_unique<iHdlExpr>(new HdlValue(HdlValueType::symb_OPEN));
}
std::unique_ptr<iHdlExpr> iHdlExpr::ternary(std::unique_ptr<iHdlExpr> cond,
		std::unique_ptr<iHdlExpr> ifTrue, std::unique_ptr<iHdlExpr> ifFalse) {
	auto e = make_unique<iHdlExpr>();
	e->data = HdlCall::ternary(move(cond), move(ifTrue), move(ifFalse));
	return e;
}
std::unique_ptr<iHdlExpr> iHdlExpr::call(std::unique_ptr<iHdlExpr> fnId,
		std::vector<std::unique_ptr<iHdlExpr>> &args) {
	auto e = make_unique<iHdlExpr>();
	e->data = HdlCall::call(move(fnId), args);
	return e;
}
std::unique_ptr<iHdlExpr> iHdlExpr::parametrization(
		std::unique_ptr<iHdlExpr> fnId,
		std::vector<std::unique_ptr<iHdlExpr>> &args) {
	auto e = make_unique<iHdlExpr>();
	e->data = HdlCall::parametrization(move(fnId), args);
	return e;
}

std::unique_ptr<iHdlExpr> iHdlExpr::slice(std::unique_ptr<iHdlExpr> fnId,
		std::vector<std::unique_ptr<iHdlExpr>> &operands) {
	auto e = make_unique<iHdlExpr>();
	e->data = HdlCall::slice(move(fnId), operands);
	return e;
}

std::unique_ptr<iHdlExpr> iHdlExpr::ID(const std::string &value) {
	auto s = new HdlValue(value);
	s->type = HdlValueType::symb_ID;
	return make_unique<iHdlExpr>(s);
}

std::unique_ptr<iHdlExpr> iHdlExpr::TYPE_T() {
	std::unique_ptr<iHdlExpr> e = make_unique<iHdlExpr>();
	e->data = &Type_t;
	return e;
}

std::unique_ptr<iHdlExpr> iHdlExpr::AUTO_T() {
	auto e = make_unique<iHdlExpr>();
	e->data = &AutoType_t;
	return e;
}

std::unique_ptr<iHdlExpr> iHdlExpr::all() {
	return make_unique<iHdlExpr>(new HdlValue(HdlValueType::symb_ALL));
}
std::unique_ptr<iHdlExpr> iHdlExpr::null() {
	return make_unique<iHdlExpr>(new HdlValue(HdlValueType::symb_NULL));
}
std::unique_ptr<iHdlExpr> iHdlExpr::others() {
	return make_unique<iHdlExpr>(new HdlValue(HdlValueType::symb_OTHERS));
}
iHdlExpr::~iHdlExpr() {
	if (data && data != &Type_t && data != &AutoType_t)
		delete data;
}

}
}
