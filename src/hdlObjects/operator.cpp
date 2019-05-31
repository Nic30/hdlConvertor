#include "operator.h"

namespace hdlConvertor {
namespace hdlObjects {

Operator::Operator() {
	operands = NULL;
	op0 = NULL;
	op1 = NULL;
	op = ARROW;
}

Operator::Operator(const Operator & o) {
	if (o.operands) {
		auto ops = new std::vector<Expr*>();
		for (auto op : *o.operands) {
			ops->push_back(new Expr(*op));
		}
		operands = ops;
	} else {
		operands = NULL;
	}
	if (o.op0) {
		op0 = new Expr(*o.op0);
	} else {
		op0 = NULL;
	}
	if (o.op1) {
		op1 = new Expr(*o.op1);
	} else {
		op1 = NULL;
	}
	op = o.op;
}

Operator::Operator(Expr* op0, OperatorType operatorType, Expr* op1) {
	this->op0 = op0;
	this->op = operatorType;
	this->op1 = op1;
	operands = nullptr;
}
Operator * Operator::call(Expr* fn, std::vector<Expr*> * operands) {
	Operator * o = new Operator();
	o->op0 = fn;
	o->op = CALL;
	o->operands = operands;
	return o;
}
Operator * Operator::slice(Expr* fn, std::vector<Expr*> * operands) {
	Operator * o = new Operator();
	o->op0 = fn;
	o->op = INDEX;
	o->operands = operands;
	return o;
}
Operator * Operator::ternary(Expr* cond, Expr* ifTrue, Expr* ifFalse) {
	Operator * op = new Operator();
	op->op = TERNARY;
	op->op0 = cond;

	std::vector<Expr*> * ops = new std::vector<Expr*>(2);
	(*ops)[0] = ifTrue;
	(*ops)[1] = ifFalse;
	op->operands = ops;

	return op;
}
Operator::~Operator() {
	// do not delete the variables as they may be shared
	// and they are deleted on delete of scope itself
	if (operands) {
		for (auto o : *operands) {
			delete o;
		}
		delete operands;
	}
	if (op0)
		delete op0;
	if (op1)
		delete op1;
}

ExprItem * Operator::clone() const {
	return new Operator(*this);
}

}
}
