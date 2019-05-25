#include "expr.h"
#include "symbol.h"
#include "operator.h"

namespace hdlConvertor {
namespace hdlObjects {

LiteralVal __v = { NULL };
static Symbol Type_t(symbol_T, __v); // symbol representing that expr is type of type;

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

Expr::Expr(Expr * op0, OperatorType operatorType, Expr * op1) {
	assert(op0);
	data = new Operator(op0, operatorType, op1);
}
Expr::Expr(SymbolType type, LiteralVal value) {
	data = new Symbol(type, value);
}
Expr::Expr(SymbolType type, Symbol * value) {
	data = value;
}

Expr::Expr(BigInteger value, int bits) {
	data = new Symbol(value, bits);
}
Expr::Expr(BigInteger value) {
	LiteralVal v;
	v._int = value;
	data = new Symbol(symb_INT, v);
}
Expr * Expr::INT(std::string strVal, int base) {
	return Expr::INT(strVal.c_str(), base);
}
Expr * Expr::INT(const char * strVal, int base) {
	LiteralVal v;
	v._int = BigInteger_fromStr(strVal, base);
	return new Expr(symb_INT, v);
}
Expr * Expr::INT(const char * strVal, int bits, int base) {
	auto val = BigInteger_fromStr(strVal, base);
	return new Expr(val, bits);
}
Expr * Expr::INT(std::string strVal, int bits, int base) {
	return INT(strVal.c_str(), bits, base);
}
Expr * Expr::INT(long long val) {
	LiteralVal v;
	v._int = BigInteger_fromLong(val);

	return new Expr(symb_INT, v);
}
Expr * Expr::FLOAT(double val) {
	LiteralVal v;
	v._float = val;
	return new Expr(symb_FLOAT, v);
}

Expr * Expr::STR(std::string strVal) {
	LiteralVal v;
	v._str = strdup(strVal.c_str());
	return new Expr(symb_STRING, v);
}

Expr * Expr::ARRAY(std::vector<Expr*> arr) {
	auto _arr = new std::vector<Symbol>();
	for (auto item : arr) {
		_arr->push_back(*dynamic_cast<Symbol*>(item->data));
		item->data = NULL;
		delete item;
	}

	return new Expr(symb_ARRAY, new Symbol(_arr));
}

Expr * Expr::OPEN() {
	Expr * e = new Expr();
	LiteralVal v;
	v._str = NULL;
	e->data = new Symbol(symb_OPEN, v);
	return e;
}
Expr* Expr::ternary(Expr* cond, Expr* ifTrue, Expr* ifFalse) {
	Expr * e = new Expr();
	e->data = Operator::ternary(cond, ifTrue, ifFalse);
	return e;
}
Expr * Expr::call(Expr * fnId, std::vector<Expr*> * operands) {
	Expr * e = new Expr();
	e->data = Operator::call(fnId, operands);
	return e;
}
Expr * Expr::slice(Expr * fnId, std::vector<Expr*> * operands) {
	Expr * e = new Expr();
	e->data = Operator::slice(fnId, operands);
	return e;
}
Expr * Expr::ID(const char * value) {
	LiteralVal v;
	v._str = strdup(value);
	return new Expr(symb_ID, v);
}
Expr * Expr::ID(std::string value) {
	return Expr::ID(value.c_str());
}

Expr * Expr::TYPE_T() {
	Expr * e = new Expr();
	e->data = &Type_t;
	return e;
}

Expr * Expr::all() {
	Expr * e = new Expr();
	LiteralVal v;
	v._str = NULL;
	e->data = new Symbol(symb_ALL, v);
	return e;
}
Expr * Expr::null() {
	Expr * e = new Expr();
	LiteralVal v;
	v._str = NULL;
	e->data = new Symbol(symb_NULL, v);
	return e;
}

char * Expr::extractStr() {
	Symbol * literal = dynamic_cast<Symbol*>(data);
	return literal->value._str;
}

Expr::~Expr() {
	if (data && data != &Type_t)
		delete data;
}

}
}
