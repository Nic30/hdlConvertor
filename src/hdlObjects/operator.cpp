#include <hdlConvertor/hdlObjects/operator.h>

namespace hdlConvertor {
namespace hdlObjects {

Operator::Operator() {
	op = ARROW;
	operands.reserve(2);
}

Operator::Operator(const Operator & o) {
	operands.reserve(o.operands.size());
	for (auto op : o.operands) {
		operands.push_back(new Expr(*op));
	}
	op = o.op;
}

Operator::Operator(Expr* op0, OperatorType operatorType, Expr* op1) {
	if (op0) {
		operands.push_back(op0);
		assert(!op1);
	}
	if (op1)
		operands.push_back(op1);
	this->op = operatorType;
}

Operator * Operator::call(Expr* fn, const std::vector<Expr*> & operands) {
	Operator * o = new Operator();
	o->op = CALL;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(fn);
	for (auto op : operands)
		o->operands.push_back(op);
	return o;
}
Operator * Operator::slice(Expr* fn, const std::vector<Expr*> & operands) {
	Operator * o = new Operator();
	o->op = INDEX;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(fn);
	for (auto op : operands)
		o->operands.push_back(op);
	return o;
}
Operator * Operator::ternary(Expr* cond, Expr* ifTrue, Expr* ifFalse) {
	Operator * op = new Operator();
	op->op = TERNARY;
	op->operands = {cond, ifTrue, ifFalse};
	return op;
}
Operator::~Operator() {
	for (auto o : operands) {
		delete o;
	}
}
ExprItem * Operator::clone() const {
	return new Operator(*this);
}

}
}
