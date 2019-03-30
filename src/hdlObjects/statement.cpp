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
	case s_PROCESS:
		return "PROCESS";
	default:
		throw std::runtime_error("Invalid StatementType");
	}
}

Statement::Statement(StatementType type) {
	this->type = type;
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
	s->sub_statements.push_back(ifTrue);

	return s;
}
Statement* Statement::IF(Expr * cond, std::vector<Statement*>* ifTrue,
		std::vector<Statement*>* ifFalse) {
	Statement * s = new Statement(s_IF);
	s->op0 = cond;
	s->sub_statements.reserve(2);
	s->sub_statements.push_back(ifTrue);
	s->sub_statements.push_back(ifFalse);

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
	s->sub_statements.push_back(body);
	return s;

}

Statement* Statement::PROCECESS(std::vector<Expr*> * sensitivity,
		std::vector<Statement*>* body) {
	Statement * s = new Statement(s_PROCESS);
	s->sub_statements.reserve(2);
	s->sub_statements.push_back(
			reinterpret_cast<std::vector<Statement*> *>(sensitivity));
	s->sub_statements.push_back(body);
	return s;
}

#ifdef USE_PYTHON
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
		assert(sub_statements);
		_case = sub_statements[0];
		addJsonArrP(d, "ifTrue", *_case);
		if (sub_statements.size() > 1) {
			_case = sub_statements[1];
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
		addJsonArrP(d, "body", *sub_statements[0]);
		break;
	case s_PROCESS:
		if (sub_statements[0]) {
			addJsonArrP(d, "body",
					*reinterpret_cast<std::vector<Expr*>*>(sub_statements[0]));
		}
		addJsonArrP(d, "body", *sub_statements[1]);
		break;
	default:
		throw "Invalid StatementType ";
	}
	return d;
}
#endif

Statement::~Statement() {
	if (type == s_PROCESS) {
		delete reinterpret_cast<std::vector<Expr*>*>(sub_statements[0]);
		delete sub_statements[1];
	} else {
		for (auto sl : sub_statements) {
			for (auto stm : *sl) {
				delete stm;
			}
			delete sl;
		}

		if (op0)
			delete op0;

		if (op1)
			delete op1;
	}
}
