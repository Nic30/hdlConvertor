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
	exprs.reserve(4);
}

Statement * Statement::EXPR(Expr * e) {
	Statement * s = new Statement(s_EXPR);
	s->exprs.push_back(e);
	return s;
}
Statement* Statement::IF(Expr * cond, std::vector<Statement*> * ifTrue) {
	Statement * s = new Statement(s_IF);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(ifTrue);

	return s;
}
Statement* Statement::IF(Expr * cond, std::vector<Statement*>* ifTrue,
		std::vector<Statement*>* ifFalse) {
	Statement * s = new Statement(s_IF);
	s->exprs.push_back(cond);
	s->sub_statements.reserve(2);
	s->sub_statements.push_back(ifTrue);
	s->sub_statements.push_back(ifFalse);

	return s;
}
Statement* Statement::RETURN(Expr * val) {
	Statement * s = RETURN();
	s->exprs.push_back(val);
	return s;
}
Statement* Statement::RETURN() {
	return new Statement(s_RETURN);
}
Statement* Statement::ASSIG(Expr * dst, Expr * src) {
	Statement * s = new Statement(s_ASSIGMENT);
	s->exprs.push_back(dst);
	s->exprs.push_back(src);
	return s;
}
Statement* Statement::WHILE(Expr * cond, std::vector<Statement*> * body) {
	Statement * s = new Statement(s_WHILE);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(body);
	return s;
}

Statement* Statement::PROCECESS(std::vector<Expr*> * sensitivity,
		std::vector<Statement*>* body) {
	Statement * s = new Statement(s_PROCESS);
	if (sensitivity) {
		s->exprs.resize(sensitivity->size());
		std::copy(sensitivity->begin(), sensitivity->end(), s->exprs.begin());
	} else {
		s->exprs.push_back(nullptr);
	}
	s->sub_statements.push_back(body);
	return s;
}

#ifdef USE_PYTHON
PyObject * Statement::toJson() const {
	PyObject * d = PyDict_New();
	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(StatementType_toString(type)));
	std::vector<Statement*> * _case = NULL;

	if (type == s_EXPR) {
		return exprs[0]->toJson();
	} else if (type == s_IF) {
		PyDict_SetItemString(d, "cond", exprs[0]->toJson());
		assert(sub_statements);
		_case = sub_statements[0];
		addJsonArrP(d, "ifTrue", *_case);
		if (sub_statements.size() > 1) {
			_case = sub_statements[1];
			addJsonArrP(d, "ifFalse", *_case);
		} else {
			addJsonArr_empty(d, "ifFalse");
		}
	} else if (type == s_RETURN) {
		PyDict_SetItemString(d, "val", exprs[0]->toJson());
	} else if (type == s_ASSIGMENT) {
		PyDict_SetItemString(d, "dst", exprs[0]->toJson());
		PyDict_SetItemString(d, "src", exprs[1]->toJson());
	} else if (type == s_WHILE) {
		PyDict_SetItemString(d, "cond", exprs[0]->toJson());
		addJsonArrP(d, "body", *sub_statements[0]);
	} else if (type == s_PROCESS) {
		if (exprs[0]) {
			addJsonArrP(d, "sensitivity", exprs);
		}
		addJsonArrP(d, "body", *sub_statements[1]);
	} else {
		throw std::runtime_error("Invalid StatementType");
	}
	return d;
}
#endif

Statement::~Statement() {
	for (auto sl : sub_statements) {
		for (auto stm : *sl) {
			delete stm;
		}
		delete sl;
	}
	for (auto e : exprs)
		delete e;
}

