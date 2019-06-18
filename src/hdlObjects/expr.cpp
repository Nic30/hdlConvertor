#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/literalVal.h>
#include <hdlConvertor/hdlObjects/operator.h>
#include <stdexcept>

namespace hdlConvertor {
namespace hdlObjects {

LiteralVal __v = { BigInteger(0) };
static LiteralVal Type_t(LiteralValType::symb_T); // symbol representing that expr is type of type;

Expr::Expr() {
	data = NULL;
}

Expr::Expr(const Expr & expr) {
	if (expr.data == nullptr || expr.data == &Type_t) {
		data = expr.data;
	} else {
		data = expr.data->clone();
	}
}
Expr::Expr(OperatorType operatorType, Expr * op0) {
	assert(op0);
	data = new Operator(operatorType, op0);
}
Expr::Expr(Expr * op0, OperatorType operatorType, Expr * op1) {
	assert(op0);
	data = new Operator(op0, operatorType, op1);
}
Expr::Expr(const LiteralVal & value) :
		data(new LiteralVal(value)) {
}
Expr::Expr(LiteralVal * value) :
		data(value) {
}

Expr::Expr(const BigInteger & value, int bits) {
	data = new LiteralVal(value, bits);
}
Expr::Expr(const BigInteger & value) :
		data(new LiteralVal(value, -1)) {
}
Expr * Expr::INT(const std::string & strVal, int base) {
	return new Expr(BigInteger(strVal, base));
}
Expr * Expr::INT(const std::string & strVal, int bits, int base) {
	return new Expr(new LiteralVal(BigInteger(strVal, base), bits));
}
Expr * Expr::INT(int64_t val) {
	return new Expr(BigInteger(val));
}
Expr * Expr::FLOAT(double val) {
	return new Expr(new LiteralVal(val));
}

Expr * Expr::STR(std::string strVal) {
	auto l = new LiteralVal(strVal);
	l->type == LiteralValType::symb_STRING;
	return new Expr(l);
}

Expr * Expr::ARRAY(const std::vector<Expr*> & arr) {
	auto _arr = new std::vector<Expr*>(arr);
	return new Expr(new LiteralVal(_arr));
}

Expr * Expr::OPEN() {
	Expr * e = new Expr(new LiteralVal(LiteralValType::symb_OPEN));
	return e;
}
Expr* Expr::ternary(Expr* cond, Expr* ifTrue, Expr* ifFalse) {
	Expr * e = new Expr();
	e->data = Operator::ternary(cond, ifTrue, ifFalse);
	return e;
}
Expr * Expr::call(Expr * fnId, const std::vector<Expr*> & args) {
	Expr * e = new Expr();
	e->data = Operator::call(fnId, args);
	return e;
}
Expr * Expr::slice(Expr * fnId, const std::vector<Expr*> & operands) {
	Expr * e = new Expr();
	e->data = Operator::slice(fnId, operands);
	return e;
}
Expr * Expr::ID(const std::string & value) {
	auto s = new LiteralVal(value);
	s->type = LiteralValType::symb_ID;
	return new Expr(s);
}

Expr * Expr::TYPE_T() {
	Expr * e = new Expr();
	e->data = &Type_t;
	return e;
}

Expr * Expr::all() {
	return new Expr(new LiteralVal(LiteralValType::symb_ALL));
}
Expr * Expr::null() {
	return new Expr(new LiteralVal(LiteralValType::symb_NULL));
}
Expr * Expr::others() {
	return new Expr(new LiteralVal(LiteralValType::symb_OTHERS));
}
const std::string & Expr::extractStr() const {
	LiteralVal * literal = dynamic_cast<LiteralVal*>(data);
	if (!literal)
		throw std::runtime_error(
				"Expr::extractStr called on expression which is not string or id");
	return literal->_str;
}

Expr::~Expr() {
	if (data && data != &Type_t)
		delete data;
}

}
}
