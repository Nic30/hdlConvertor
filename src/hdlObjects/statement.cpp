#include <hdlConvertor/hdlObjects/statement.h>
#include <tuple>
#include <hdlConvertor/hdlObjects/process.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

const char * StatementType_toString(StatementType type) {
	// [TODO] to array of names
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
	case s_CONTINUE:
		return "CONTINUE";
	case s_FOR:
		return "FOR";
	case s_FOR_IN:
		return "FOR_IN";
	case s_RETURN:
		return "RETURN";
	case s_ASSIGNMENT:
		return "ASSIGNMENT";
	case s_PROCESS:
		return "PROCESS";
	case s_WAIT:
		return "WAIT";
	case s_IMPORT:
		return "IMPORT";
	default:
		throw runtime_error("Invalid StatementType");
	}
}

Statement::Statement(StatementType type) {
	this->type = type;
	exprs.reserve(4);
	in_preproc = false;
}
Statement * Statement::EXPR(Expr * e) {
	Statement * s = new Statement(s_EXPR);
	s->exprs.push_back(e);
	return s;
}
Statement * Statement::IMPORT(const std::vector<Expr *> & path) {
	Statement * s = new Statement(s_IMPORT);
	for (auto n : path)
		s->exprs.push_back(n);
	return s;
}
Statement* Statement::IF(Expr * cond, vector<iHdlObj*> * ifTrue) {
	Statement * s = new Statement(s_IF);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(ifTrue);

	return s;
}
Statement* Statement::IF(Expr * cond, vector<iHdlObj*>* ifTrue,
		vector<iHdlObj*>* ifFalse) {
	Statement * s = new Statement(s_IF);
	s->exprs.push_back(cond);
	s->sub_statements.reserve(2);
	s->sub_statements.push_back(ifTrue);
	if (ifFalse)
		s->sub_statements.push_back(ifFalse);
	return s;
}
Statement* Statement::IF(Expr * cond, vector<iHdlObj*>* ifTrue,
		const vector<case_t> & elseIfs, vector<iHdlObj*>* ifFalse) {
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

Statement* Statement::IF(Expr* cond, vector<Statement*>* ifTrue) {
	return Statement::IF(cond, reinterpret_cast<vector<iHdlObj*>*>(ifTrue));
}
Statement* Statement::IF(Expr* cond, vector<Statement*>* ifTrue,
		vector<Statement*>* ifFalse) {
	return Statement::IF(cond, reinterpret_cast<vector<iHdlObj*>*>(ifTrue),
			reinterpret_cast<vector<iHdlObj*>*>(ifFalse));
}
Statement* Statement::IF(Expr* cond, vector<Statement*>* ifTrue,
		const vector<pair<Expr*, vector<Statement*>*>> & elseIfs,
		vector<Statement*>* ifFalse) {
	return Statement::IF(cond, reinterpret_cast<vector<iHdlObj*>*>(ifTrue),
			*reinterpret_cast<const vector<case_t>*>(&elseIfs),
			reinterpret_cast<vector<iHdlObj*>*>(ifFalse));
}

Statement* Statement::CASE(Expr * switchOn, const vector<case_t> cases,
		vector<iHdlObj*>* default_) {
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
Statement* Statement::WAIT(const std::vector<Expr*> & val) {
	Statement * s = new Statement(s_WAIT);
	for (auto v : val) {
		s->exprs.push_back(v);
	}
	return s;
}

Statement* Statement::WHILE(Expr* cond, std::vector<Statement*>* body) {
	return WHILE(cond, reinterpret_cast<std::vector<iHdlObj*>*>(body));
}
Statement* Statement::WHILE(Expr * cond, vector<iHdlObj*> * body) {
	Statement * s = new Statement(s_WHILE);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(body);
	return s;
}
Statement* Statement::BREAK() {
	return new Statement(s_BREAK);
}
Statement* Statement::CONTINUE() {
	return new Statement(s_CONTINUE);
}
Statement* Statement::PROCESS(vector<Expr*> * sensitivity,
		vector<iHdlObj*>* body) {
	return new Process(sensitivity, body);
}

Statement* Statement::FOR(Statement* _init, Expr* cond, Statement* _step,
		std::vector<iHdlObj*>* body) {
	Statement * s = new Statement(s_FOR);
	auto init = new vector<iHdlObj*>( { static_cast<iHdlObj*>(_init) });
	auto step = new vector<iHdlObj*>( { static_cast<iHdlObj*>(_step) });

	s->sub_statements.push_back(init);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(step);
	s->sub_statements.push_back(body);
	return s;
}
Statement* Statement::FOR(Statement* init, Expr* cond, Statement* step,
		std::vector<Statement*>* _body) {
	auto body = reinterpret_cast<std::vector<iHdlObj*>*>(_body);
	return FOR(init, cond, step, body);
}
Statement* Statement::FOR_IN(Expr* _var, Expr *collection,
		std::vector<iHdlObj*>* body) {
	return FOR_IN(Statement::EXPR(_var), collection, body);
}
Statement* Statement::FOR_IN(Statement* _var, Expr *collection,
		std::vector<iHdlObj*>* body) {
	Statement * s = new Statement(s_FOR_IN);
	auto var = new vector<iHdlObj*>( { static_cast<iHdlObj*>(_var) });
	s->sub_statements.push_back(var);
	s->exprs.push_back(collection);
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
