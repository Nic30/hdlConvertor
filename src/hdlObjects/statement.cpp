#include "statement.h"
#include <tuple>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

const char * StatementType_toString(StatementType type) {
	switch (type) {
	case s_EXPR:
		return "EXPR";
	case s_IF:
		return "IF";
	case s_CASE:
		return "CASE";
	case s_WHILE:
		return "WHILE";
	case s_BREAK:
		return "BREAK";
	case s_FOR:
		return "FOR";
	case s_RETURN:
		return "RETURN";
	case s_ASSIGMENT:
		return "ASSIGMENT";
	case s_PROCESS:
		return "PROCESS";
	default:
		throw runtime_error("Invalid StatementType");
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
Statement* Statement::IF(Expr * cond, vector<Statement*> * ifTrue) {
	Statement * s = new Statement(s_IF);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(ifTrue);

	return s;
}
Statement* Statement::IF(Expr * cond, vector<Statement*>* ifTrue,
		vector<Statement*>* ifFalse) {
	Statement * s = new Statement(s_IF);
	s->exprs.push_back(cond);
	s->sub_statements.reserve(2);
	s->sub_statements.push_back(ifTrue);
	if (ifFalse)
		s->sub_statements.push_back(ifFalse);
	return s;
}
Statement* Statement::IF(Expr * cond, vector<Statement*>* ifTrue,
		const vector<case_t> & elseIfs, vector<Statement*>* ifFalse) {
	Statement * s = new Statement(s_IF);
	s->exprs.reserve(1 + elseIfs.size());
	s->exprs.push_back(cond);
	s->sub_statements.reserve(2 + elseIfs.size());
	s->sub_statements.push_back(ifTrue);
	for (auto el : elseIfs) {
		s->exprs.push_back(el.first);
		s->sub_statements.push_back(el.second);
	}
	if (ifFalse != nullptr)
		s->sub_statements.push_back(ifFalse);
	return s;
}
Statement* Statement::CASE(Expr * switchOn, const vector<case_t> cases,
		vector<Statement*>* default_) {
	auto s = new Statement(s_CASE);
	s->exprs.reserve(1 + cases.size());
	s->exprs.push_back(switchOn);
	s->sub_statements.reserve(cases.size() + 1);
	for (auto c : cases) {
		s->exprs.push_back(c.first);
		s->sub_statements.push_back(c.second);
	}
	if (default_) {
		s->sub_statements.push_back(default_);
	}
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
	if (dst == nullptr || src == nullptr) {
		throw runtime_error("wrong assign initialisation");
	}
	Statement * s = new Statement(s_ASSIGMENT);
	s->exprs.push_back(dst);
	s->exprs.push_back(src);
	return s;
}
Statement* Statement::WHILE(Expr * cond, vector<Statement*> * body) {
	Statement * s = new Statement(s_WHILE);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(body);
	return s;
}
Statement* Statement::BREAK() {
	return new Statement(s_BREAK);
}

Statement* Statement::PROCESS(vector<Expr*> * sensitivity,
		vector<Statement*>* body) {
	Statement * s = new Statement(s_PROCESS);
	if (sensitivity) {
		s->exprs.resize(sensitivity->size());
		copy(sensitivity->begin(), sensitivity->end(), s->exprs.begin());
	} else {
		s->exprs.push_back(nullptr);
	}
	s->sub_statements.push_back(body);
	return s;
}

Statement* Statement::FOR(const vector<Expr*> & args, std::vector<Statement*>* body) {
	Statement * s = new Statement(s_FOR);
	for (auto e: args)
		s->exprs.push_back(e);
	s->sub_statements.push_back(body);
	return s;
}


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

}
}
