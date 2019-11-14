#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <stdexcept>
#include <string.h>
#include <assert.h>

#include <hdlConvertor/hdlObjects/hdlCall.h>
#include <hdlConvertor/createObject.h>

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
std::unique_ptr<iHdlExpr> iHdlExpr::INT(
		TerminalNode *node, const std::string &strVal, int base) {
  return create_object<iHdlExpr>(node, BigInteger(strVal, base));
}
std::unique_ptr<iHdlExpr> iHdlExpr::INT(
		TerminalNode *node, const std::string &strVal, int bits, int base) {
	return create_object<iHdlExpr>(node, new HdlValue(BigInteger(strVal, base), bits));
}
std::unique_ptr<iHdlExpr> iHdlExpr::INT(TerminalNode *node, int64_t val) {
	return create_object<iHdlExpr>(node, BigInteger(val));
}
std::unique_ptr<iHdlExpr> iHdlExpr::FLOAT(TerminalNode *node, double val) {
	return create_object<iHdlExpr>(node, new HdlValue(val));
}

std::unique_ptr<iHdlExpr> iHdlExpr::STR(TerminalNode *node, std::string strVal) {
	auto l = new HdlValue(strVal);
	l->type = HdlValueType::symb_STRING;
	return create_object<iHdlExpr>(node, l);
}

std::unique_ptr<iHdlExpr> iHdlExpr::ARRAY(
		ParserRuleContext *ctx, std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> arr) {
	return create_object<iHdlExpr>(ctx, new HdlValue(move(arr)));
}

std::unique_ptr<iHdlExpr> iHdlExpr::ARRAY(
		ParserRuleContext *ctx, std::vector<std::unique_ptr<iHdlExpr>> &arr) {
	auto _arr = make_unique<std::vector<std::unique_ptr<iHdlExpr>>>(move(arr));
	return ARRAY(ctx, move(_arr));
}

std::unique_ptr<iHdlExpr> iHdlExpr::OPEN() {
	return create_object<iHdlExpr>(nullptr, new HdlValue(HdlValueType::symb_OPEN));
}
std::unique_ptr<iHdlExpr> iHdlExpr::ternary(
		ParserRuleContext *ctx, std::unique_ptr<iHdlExpr> cond,
		std::unique_ptr<iHdlExpr> ifTrue, std::unique_ptr<iHdlExpr> ifFalse) {
	auto e = create_object<iHdlExpr>(ctx);
	e->data = HdlCall::ternary(move(cond), move(ifTrue), move(ifFalse));
	return e;
}
std::unique_ptr<iHdlExpr> iHdlExpr::call(
		ParserRuleContext *ctx, std::unique_ptr<iHdlExpr> fnId,
		std::vector<std::unique_ptr<iHdlExpr>> &args) {
	auto e = create_object<iHdlExpr>(ctx);
	e->data = HdlCall::call(move(fnId), args);
	return e;
}
std::unique_ptr<iHdlExpr> iHdlExpr::parametrization(
		ParserRuleContext *ctx,
		std::unique_ptr<iHdlExpr> fnId,
		std::vector<std::unique_ptr<iHdlExpr>> &args) {
	auto e = create_object<iHdlExpr>(ctx);
	e->data = HdlCall::parametrization(move(fnId), args);
	return e;
}

std::unique_ptr<iHdlExpr> iHdlExpr::slice(
		ParserRuleContext *ctx,
		std::unique_ptr<iHdlExpr> fnId,
		std::vector<std::unique_ptr<iHdlExpr>> &operands) {
	auto e = create_object<iHdlExpr>(ctx);
	e->data = HdlCall::slice(move(fnId), operands);
	return e;
}

std::unique_ptr<iHdlExpr> iHdlExpr::ID(const std::string &value) {
	auto s = new HdlValue(value);
	s->type = HdlValueType::symb_ID;
	return create_object<iHdlExpr>(nullptr, s);
}

std::unique_ptr<iHdlExpr> iHdlExpr::TYPE_T() {
	std::unique_ptr<iHdlExpr> e = create_object<iHdlExpr>(nullptr);
	e->data = &Type_t;
	return e;
}

std::unique_ptr<iHdlExpr> iHdlExpr::AUTO_T() {
	auto e = create_object<iHdlExpr>(nullptr);
	e->data = &AutoType_t;
	return e;
}

std::unique_ptr<iHdlExpr> iHdlExpr::all() {
	return create_object<iHdlExpr>(nullptr, new HdlValue(HdlValueType::symb_ALL));
}
std::unique_ptr<iHdlExpr> iHdlExpr::null() {
	return create_object<iHdlExpr>(nullptr, new HdlValue(HdlValueType::symb_NULL));
}
std::unique_ptr<iHdlExpr> iHdlExpr::others() {
	return create_object<iHdlExpr>(nullptr, new HdlValue(HdlValueType::symb_OTHERS));
}
iHdlExpr::~iHdlExpr() {
	if (data && data != &Type_t && data != &AutoType_t)
		delete data;
}

}
}
