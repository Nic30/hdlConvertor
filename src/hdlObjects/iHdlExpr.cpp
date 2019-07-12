#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <stdexcept>

#include <hdlConvertor/hdlObjects/hdlValue.h>
#include <hdlConvertor/hdlObjects/hdlCall.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlValue __v = { BigInteger(0) };
static HdlValue AutoType_t(HdlValueType::symb_AUTO);
static HdlValue Type_t(HdlValueType::symb_T); // symbol representing that expr is type of type;

iHdlExpr::iHdlExpr() {
	data = NULL;
}

iHdlExpr::iHdlExpr(const iHdlExpr & expr) {
	if (expr.data == nullptr || expr.data == &Type_t) {
		data = expr.data;
	} else {
		data = expr.data->clone();
	}
}
iHdlExpr::iHdlExpr(HdlOperatorType operatorType, iHdlExpr * op0) {
	assert(op0);
	data = new HdlCall(operatorType, op0);
}
iHdlExpr::iHdlExpr(iHdlExpr * op0, HdlOperatorType operatorType,
		iHdlExpr * op1) {
	assert(op0);
	data = new HdlCall(op0, operatorType, op1);
}
iHdlExpr::iHdlExpr(const HdlValue & value) :
		data(new HdlValue(value)) {
}
iHdlExpr::iHdlExpr(HdlValue * value) :
		data(value) {
}

iHdlExpr::iHdlExpr(const BigInteger & value, int bits) {
	data = new HdlValue(value, bits);
}
iHdlExpr::iHdlExpr(const BigInteger & value) :
		data(new HdlValue(value, -1)) {
}
iHdlExpr * iHdlExpr::INT(const std::string & strVal, int base) {
	return new iHdlExpr(BigInteger(strVal, base));
}
iHdlExpr * iHdlExpr::INT(const std::string & strVal, int bits, int base) {
	return new iHdlExpr(new HdlValue(BigInteger(strVal, base), bits));
}
iHdlExpr * iHdlExpr::INT(int64_t val) {
	return new iHdlExpr(BigInteger(val));
}
iHdlExpr * iHdlExpr::FLOAT(double val) {
	return new iHdlExpr(new HdlValue(val));
}

iHdlExpr * iHdlExpr::STR(std::string strVal) {
	auto l = new HdlValue(strVal);
	l->type = HdlValueType::symb_STRING;
	return new iHdlExpr(l);
}

iHdlExpr * iHdlExpr::ARRAY(const std::vector<iHdlExpr*> & arr) {
	auto _arr = new std::vector<iHdlExpr*>(arr);
	return new iHdlExpr(new HdlValue(_arr));
}

iHdlExpr * iHdlExpr::OPEN() {
	iHdlExpr * e = new iHdlExpr(new HdlValue(HdlValueType::symb_OPEN));
	return e;
}
iHdlExpr* iHdlExpr::ternary(iHdlExpr* cond, iHdlExpr* ifTrue,
		iHdlExpr* ifFalse) {
	iHdlExpr * e = new iHdlExpr();
	e->data = HdlCall::ternary(cond, ifTrue, ifFalse);
	return e;
}
iHdlExpr * iHdlExpr::call(iHdlExpr * fnId,
		const std::vector<iHdlExpr*> & args) {
	iHdlExpr * e = new iHdlExpr();
	e->data = HdlCall::call(fnId, args);
	return e;
}
iHdlExpr * iHdlExpr::slice(iHdlExpr * fnId,
		const std::vector<iHdlExpr*> & operands) {
	iHdlExpr * e = new iHdlExpr();
	e->data = HdlCall::slice(fnId, operands);
	return e;
}
iHdlExpr * iHdlExpr::ID(const std::string & value) {
	auto s = new HdlValue(value);
	s->type = HdlValueType::symb_ID;
	return new iHdlExpr(s);
}

iHdlExpr * iHdlExpr::TYPE_T() {
	iHdlExpr * e = new iHdlExpr();
	e->data = &Type_t;
	return e;
}
iHdlExpr * iHdlExpr::AUTO_T() {
	iHdlExpr * e = new iHdlExpr();
	e->data = &AutoType_t;
	return e;
}

iHdlExpr * iHdlExpr::all() {
	return new iHdlExpr(new HdlValue(HdlValueType::symb_ALL));
}
iHdlExpr * iHdlExpr::null() {
	return new iHdlExpr(new HdlValue(HdlValueType::symb_NULL));
}
iHdlExpr * iHdlExpr::others() {
	return new iHdlExpr(new HdlValue(HdlValueType::symb_OTHERS));
}
const std::string & iHdlExpr::extractStr() const {
	HdlValue * literal = dynamic_cast<HdlValue*>(data);
	if (!literal)
		throw std::runtime_error(
				"Expr::extractStr called on expression which is not string or id");
	return literal->_str;
}

iHdlExpr::~iHdlExpr() {
	if (data && data != &Type_t && data != &AutoType_t)
		delete data;
}

}
}
