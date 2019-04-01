#include "statement.h"
#include <tuple>

using namespace std;

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
	if (default_)
		s->sub_statements.push_back(default_);
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
	if (dst == nullptr or src == nullptr) {
		throw runtime_error("wrong assig initialization");
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

pair<PyObject *, size_t> cases_toJson(vector<Expr*>::const_iterator cond_begin,
		vector<Expr*>::const_iterator cond_end,
		vector<vector<Statement*>*>::const_iterator stms_begin) {
	PyObject * cases = nullptr;
	size_t size = cond_begin != cond_end;
	if (cond_begin != cond_end)
		cases = PyList_New(size);
	for (size_t case_cnt = 0; case_cnt < size; case_cnt++) {
		// build tuple representing the elif item
		auto case_ = PyTuple_New(2);
		Expr* c = *cond_begin;
		PyTuple_SetItem(case_, 0, c->toJson());
		// fill statements in elif
		auto stms = *stms_begin;
		PyObject * objList = PyList_New(stms->size());
		for (unsigned i = 0; i < stms->size(); i++) {
			auto _o = (*stms)[i];
			assert(_o);
			PyObject * o = _o->toJson();
			PyList_SetItem(objList, i, o);
		}
		//Py_IncRef(objList);
		PyTuple_SetItem(case_, 1, objList);
		// add to elif list
		PyList_SetItem(cases, case_cnt, objList);
		++cond_begin;
		++stms_begin;
	}
	return {cases, size};
}

#ifdef USE_PYTHON
PyObject * Statement::toJson() const {
	PyObject * d = PyDict_New();
	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(StatementType_toString(type)));

	if (type == s_EXPR) {
		return exprs[0]->toJson();
	} else if (type == s_IF) {
		PyDict_SetItemString(d, "cond", exprs[0]->toJson());
		assert(sub_statements);
		addJsonArrP(d, "ifTrue", *sub_statements[0]);
		PyObject * elseIfs;
		size_t elif_cnt;
		tie(elseIfs, elif_cnt) = cases_toJson(exprs.begin() + 1, exprs.end(),
				sub_statements.begin() + 1);
		if (elseIfs) {
			PyDict_SetItemString(d, "elseIfs", elseIfs);
		}
		if (sub_statements.size() > elif_cnt + 1) {
			addJsonArrP(d, "ifFalse", *sub_statements.at(elif_cnt + 1));
		}
	} else if (type == s_CASE) {
		PyDict_SetItemString(d, "switchOn", exprs[0]->toJson());
		PyObject * c;
		size_t c_cnt;
		tie(c, c_cnt) = cases_toJson(exprs.begin() + 1, exprs.end(),
				sub_statements.begin() + 1);
		if (c) {
			PyDict_SetItemString(d, "cases", c);
		}
		if (sub_statements.size() == c_cnt) {
			addJsonArrP(d, "ifFalse", *sub_statements.at(c_cnt - 1));
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
		auto & body = *sub_statements[0];
		addJsonArrP(d, "body", body);
	} else {
		throw runtime_error("Invalid StatementType");
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

