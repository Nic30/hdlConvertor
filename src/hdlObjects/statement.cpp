#include "statement.h"

const char * StatementType_toString(StatementType type) {
	switch (type) {
	case s_EXPR:
		return "EXPR";
	case s_IF:
		return "IF";
	case s_WHILE:
		return "WHILE";
	case s_RETURN:
		return "RETURN";
	case s_ASSIGMENT:
		return "ASSIGMENT";
	default:
		throw "Invalid StatementType";
	}
}

Statement::Statement(StatementType type) {
	this->type = type;
	this->ops = NULL;
	this->op0 = NULL;
	this->op1 = NULL;
}

Statement * Statement::EXPR(Expr * e) {
	Statement * s = new Statement(s_EXPR);
	s->op0 = e;
	return s;
}
Statement* Statement::IF(Expr * cond, std::vector<Statement*> * ifTrue) {
	Statement * s = new Statement(s_IF);
	s->op0 = cond;
	s->ops = new std::vector<std::vector<Statement*>*>(1);
	s->ops->push_back(ifTrue);

	return s;
}
Statement* Statement::IF(
		Expr * cond,
		std::vector<Statement*>* ifTrue,
		std::vector<Statement*>* ifFalse) {
	Statement * s = new Statement(s_IF);
	s->op0 = cond;
	s->ops = new std::vector<std::vector<Statement*>*>(2);
	s->ops->push_back(ifTrue);
	s->ops->push_back(ifFalse);

	return s;
}
Statement* Statement::RETURN(Expr * val) {
	Statement * s = RETURN();
	s->op0 = val;
	return s;
}
Statement* Statement::RETURN() {
	return new Statement(s_RETURN);
}
Statement* Statement::ASSIG(Expr * dst, Expr * src) {
	Statement * s = new Statement(s_ASSIGMENT);
	s->op0 = dst;
	s->op1 = src;

	return s;
}
Statement* Statement::WHILE(Expr * cond, std::vector<Statement*> * body) {
	Statement * s = new Statement(s_WHILE);
	s->op0 = cond;
	s->ops = new std::vector<std::vector<Statement*> *>(1);
	s->ops->push_back(body);
	return s;

}
PyObject * Statement::toJson() const {
	PyObject * d = PyDict_New();
	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(StatementType_toString(type)));
	std::vector<Statement*> * _case = NULL;

	switch (type) {
	case s_EXPR:
		return op0->toJson();
	case s_IF:
		PyDict_SetItemString(d, "cond", op0->toJson());
		assert(ops);
		_case = (*ops)[0];
		addJsonArrP(d, "ifTrue", *_case);
		if (ops->size() > 1) {
			_case = (*ops)[1];
			addJsonArrP(d, "ifFalse", *_case);
		} else {
			addJsonArr_empty(d, "ifFalse");
		}

		break;
	case s_RETURN:
		PyDict_SetItemString(d, "val", op0->toJson());
		break;
	case s_ASSIGMENT:
		PyDict_SetItemString(d, "dst", op0->toJson());
		PyDict_SetItemString(d, "src", op1->toJson());
		break;
	case s_WHILE:
		PyDict_SetItemString(d, "cond", op0->toJson());
		addJsonArrP(d, "body", *(*ops)[0]);
		break;
	default:
		throw "Invalid StatementType ";
	}
	Py_IncRef(d);
	return d;
}
