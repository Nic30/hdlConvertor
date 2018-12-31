#include "statement.h"

const char * StatementType_toString(StatementType type) {
	switch (type) {
	case s_NONE:
		return "NONE";	
	case s_EXPR:
		return "EXPR";
	case s_IFBODY:
		return "IFBODY";	
	case s_IF:
		return "IF";
	case s_ELSIF:
		return "ELSIF";		
	case s_ELSE:
		return "ELSE";			
	case s_CASE: 
		return "CASE";
	case s_WHILE:
		return "WHILE";
	case s_FOR:
		return "FOR";	
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
Statement * Statement::NONE() {
	Statement * s = new Statement(s_NONE);
	return s;
}
Statement * Statement::EXPR(Expr * e) {
	Statement * s = new Statement(s_EXPR);
	s->op0 = e;
	return s;
}
Statement* Statement::IFBODY(std::vector<Statement*> * body) {
	Statement * s = new Statement(s_IFBODY);
	s->ops = new std::vector<std::vector<Statement*>*>(1);
	(*s->ops)[0] = body;
	return s;
}
Statement* Statement::IF(Expr * cond, std::vector<Statement*> * body) {
	Statement * s = new Statement(s_IF);
	s->op0 = cond;
	s->ops = new std::vector<std::vector<Statement*>*>(1);
	(*s->ops)[0] = body;
	return s;
}
Statement* Statement::ELSIF(Expr * cond, std::vector<Statement*> * body) {
	Statement * s = new Statement(s_ELSIF);
	s->op0 = cond;
	s->ops = new std::vector<std::vector<Statement*>*>(1);
	(*s->ops)[0] = body;
	return s;
}
Statement* Statement::ELSE(std::vector<Statement*> * body) {
	Statement * s = new Statement(s_ELSE);
	s->ops = new std::vector<std::vector<Statement*>*>(1);
	(*s->ops)[0] = body;
	return s;
}
Statement* Statement::CASE(Expr * cond, std::vector<Statement*>* body) {
	Statement * s = new Statement(s_CASE);
	s->op0 = cond;
	s->ops = new std::vector<std::vector<Statement*>*>(1);
	(*s->ops)[0] = body;
	return s;
}
Statement* Statement::CASE(std::vector<Expr*> * cond, std::vector<Statement*>* body) {
	Statement * s = new Statement(s_CASE);
	for (auto c : *cond)
		s->op.push_back(c);
	s->ops = new std::vector<std::vector<Statement*>*>(1);
	(*s->ops)[0] = body;
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
	(*s->ops)[0] = body;
	return s;

}

Statement* Statement::FOR(std::vector<Expr*> * cond, std::vector<Statement*>* body) {
	Statement * s = new Statement(s_FOR);
	for (auto c : *cond)
		s->op.push_back(c);
	s->ops = new std::vector<std::vector<Statement*> *>(1);
	(*s->ops)[0] = body;
	return s;	
}

#ifdef USE_PYTHON
PyObject * Statement::toJson() const {
	PyObject * d = PyDict_New();
	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(StatementType_toString(type)));

	if (position) {
		JSN_DEBUG("Statement - position")
		PyDict_SetItemString(d, "position", position->toJson());
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "position", Py_None);
	}

	switch (type) {
	case s_NONE:
		break;	
	case s_EXPR:
		return op0->toJson();
	case s_IFBODY: 
		addJsonArrP(d, "body", *(*ops)[0]);
		break;
	case s_IF:
		PyDict_SetItemString(d, "cond", op0->toJson());
		addJsonArrP(d, "body", *(*ops)[0]);
		break;
	case s_ELSIF:
		PyDict_SetItemString(d, "cond", op0->toJson());
		addJsonArrP(d, "body", *(*ops)[0]);
		break;	
	case s_ELSE:
		addJsonArrP(d, "body", *(*ops)[0]);
		break;					
	case s_CASE:
		addJsonArrP(d, "cond", op);
		addJsonArrP(d, "body", *(*ops)[0]);
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
	case s_FOR:
		addJsonArrP(d, "param", op);
		addJsonArrP(d, "body", *(*ops)[0]);	 
		break;	
	default:
		throw "Invalid StatementType ";
	}
	return d;
}
#endif

Statement::~Statement() {
	if (ops) {
		for (auto sl : *ops) {
			for (auto stm : *sl) {
				delete stm;
			}
			delete sl;
		}
		delete ops;
	}

    for (auto o : op)
		delete o; 

	if (op0)
		delete op0;

	if (op1)
		delete op1;

}
