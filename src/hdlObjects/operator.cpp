#include "operator.h"

Operator::Operator() {
	operands = NULL;
	op0 = NULL;
	op1 = NULL;
	op = ARROW;
}

Operator::Operator(Expr* op0, OperatorType operatorType, Expr* op1) {
	this->op0 = op0;
	this->op = operatorType;
	this->op1 = op1;
	operands = NULL;
}
Operator * Operator::call(Expr* fn, std::vector<Expr*> * operands) {
	Operator * o = new Operator();
	o->op0 = fn;
	o->op = CALL;
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

#ifdef USE_PYTHON
PyObject * Operator::toJson() const {
	PyObject *d = PyDict_New();
	PyDict_SetItemString(d, "op0", op0->toJson());
	PyDict_SetItemString(d, "operator",
			PyUnicode_FromString(OperatorType_toString(op)));

	int arity = OperatorType_arity(op);
	switch (arity) {
	case -1:
	case 3:
		addJsonArrP(d, "operands", *operands);
		break;
	case 1:
		break;
	case 2:
		PyDict_SetItemString(d, "op1", op1->toJson());
		break;
	default:
		throw "Invalid arity of operator";
	}
	Py_IncRef(d);
	return d;
}
#endif

void Operator::dump(int indent) const {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpItemP("op0", indent, op0) << ",\n";
	dumpVal("operator", indent, OperatorType_toString(op)) << ",\n";

	int arity = OperatorType_arity(op);
	switch (arity) {
	case -1:
	case 3:
		dumpArrP("operands", indent, *operands) << "\n";
		break;
	case 1:
		break;
	case 2:
		dumpItemP("op1", indent, op1) << "\n";
		break;
	default:
		throw "Invalid arity of operator";
	}
	mkIndent(indent - INDENT_INCR) << "}";
}
