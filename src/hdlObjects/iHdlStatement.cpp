#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <tuple>

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

iHdlStatement::iHdlStatement(StatementType type) {
	this->type = type;
	exprs.reserve(4);
	in_preproc = false;
}
iHdlStatement * iHdlStatement::EXPR(iHdlExpr * e) {
	iHdlStatement * s = new iHdlStatement(s_EXPR);
	s->exprs.push_back(e);
	return s;
}
iHdlStatement * iHdlStatement::IMPORT(const std::vector<iHdlExpr *> & path) {
	iHdlStatement * s = new iHdlStatement(s_IMPORT);
	for (auto n : path)
		s->exprs.push_back(n);
	return s;
}
iHdlStatement* iHdlStatement::IF(iHdlExpr * cond, vector<iHdlObj*> * ifTrue) {
	iHdlStatement * s = new iHdlStatement(s_IF);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(ifTrue);

	return s;
}
iHdlStatement* iHdlStatement::IF(iHdlExpr * cond, vector<iHdlObj*>* ifTrue,
		vector<iHdlObj*>* ifFalse) {
	iHdlStatement * s = new iHdlStatement(s_IF);
	s->exprs.push_back(cond);
	s->sub_statements.reserve(2);
	s->sub_statements.push_back(ifTrue);
	if (ifFalse)
		s->sub_statements.push_back(ifFalse);
	return s;
}
iHdlStatement* iHdlStatement::IF(iHdlExpr * cond, vector<iHdlObj*>* ifTrue,
		const vector<case_t> & elseIfs, vector<iHdlObj*>* ifFalse) {
	iHdlStatement * s = new iHdlStatement(s_IF);
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

iHdlStatement* iHdlStatement::IF(iHdlExpr* cond, vector<iHdlStatement*>* ifTrue) {
	return iHdlStatement::IF(cond, reinterpret_cast<vector<iHdlObj*>*>(ifTrue));
}
iHdlStatement* iHdlStatement::IF(iHdlExpr* cond, vector<iHdlStatement*>* ifTrue,
		vector<iHdlStatement*>* ifFalse) {
	return iHdlStatement::IF(cond, reinterpret_cast<vector<iHdlObj*>*>(ifTrue),
			reinterpret_cast<vector<iHdlObj*>*>(ifFalse));
}
iHdlStatement* iHdlStatement::IF(iHdlExpr* cond, vector<iHdlStatement*>* ifTrue,
		const vector<pair<iHdlExpr*, vector<iHdlStatement*>*>> & elseIfs,
		vector<iHdlStatement*>* ifFalse) {
	return iHdlStatement::IF(cond, reinterpret_cast<vector<iHdlObj*>*>(ifTrue),
			*reinterpret_cast<const vector<case_t>*>(&elseIfs),
			reinterpret_cast<vector<iHdlObj*>*>(ifFalse));
}

iHdlStatement* iHdlStatement::CASE(iHdlExpr * switchOn, const vector<case_t> cases,
		vector<iHdlObj*>* default_) {
	auto s = new iHdlStatement(s_CASE);
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
iHdlStatement* iHdlStatement::RETURN(iHdlExpr * val) {
	iHdlStatement * s = RETURN();
	s->exprs.push_back(val);
	return s;
}
iHdlStatement* iHdlStatement::RETURN() {
	return new iHdlStatement(s_RETURN);
}
iHdlStatement* iHdlStatement::WAIT(const std::vector<iHdlExpr*> & val) {
	iHdlStatement * s = new iHdlStatement(s_WAIT);
	for (auto v : val) {
		s->exprs.push_back(v);
	}
	return s;
}

iHdlStatement* iHdlStatement::WHILE(iHdlExpr* cond, std::vector<iHdlStatement*>* body) {
	return WHILE(cond, reinterpret_cast<std::vector<iHdlObj*>*>(body));
}
iHdlStatement* iHdlStatement::WHILE(iHdlExpr * cond, vector<iHdlObj*> * body) {
	iHdlStatement * s = new iHdlStatement(s_WHILE);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(body);
	return s;
}
iHdlStatement* iHdlStatement::BREAK() {
	return new iHdlStatement(s_BREAK);
}
iHdlStatement* iHdlStatement::CONTINUE() {
	return new iHdlStatement(s_CONTINUE);
}

iHdlStatement* iHdlStatement::FOR(iHdlStatement* _init, iHdlExpr* cond, iHdlStatement* _step,
		std::vector<iHdlObj*>* body) {
	iHdlStatement * s = new iHdlStatement(s_FOR);
	auto init = new vector<iHdlObj*>( { static_cast<iHdlObj*>(_init) });
	auto step = new vector<iHdlObj*>( { static_cast<iHdlObj*>(_step) });

	s->sub_statements.push_back(init);
	s->exprs.push_back(cond);
	s->sub_statements.push_back(step);
	s->sub_statements.push_back(body);
	return s;
}
iHdlStatement* iHdlStatement::FOR(iHdlStatement* init, iHdlExpr* cond, iHdlStatement* step,
		std::vector<iHdlStatement*>* _body) {
	auto body = reinterpret_cast<std::vector<iHdlObj*>*>(_body);
	return FOR(init, cond, step, body);
}
iHdlStatement* iHdlStatement::FOR_IN(iHdlExpr* _var, iHdlExpr *collection,
		std::vector<iHdlObj*>* body) {
	return FOR_IN(iHdlStatement::EXPR(_var), collection, body);
}
iHdlStatement* iHdlStatement::FOR_IN(iHdlStatement* _var, iHdlExpr *collection,
		std::vector<iHdlObj*>* body) {
	iHdlStatement * s = new iHdlStatement(s_FOR_IN);
	auto var = new vector<iHdlObj*>( { static_cast<iHdlObj*>(_var) });
	s->sub_statements.push_back(var);
	s->exprs.push_back(collection);
	s->sub_statements.push_back(body);
	return s;
}

iHdlStatement::~iHdlStatement() {
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
