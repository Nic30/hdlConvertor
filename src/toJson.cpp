#include "toJson.h"
#include <vector>
#include <exception>
#include <tuple>

using namespace std;

namespace hdlConvertor {

using namespace hdlConvertor::hdlObjects;

#ifdef USE_PYTHON
PyObject * addJsonArr_empty(PyObject * parent, const char * name) {
	PyObject * objList = PyList_New(0);
	PyDict_SetItem(parent, PyUnicode_FromString(name), objList);
	Py_IncRef(objList);
	return objList;
}

PyObject * ToJson::toJson(const aPackage * p) {
	PyObject *d = toJson(static_cast<const WithNameAndDoc*>(p));
	addJsonArrP(d, "components", p->components);
	addJsonArrP(d, "functions", p->functions);
	addJsonArrP(d, "variables", p->variables);
	Py_INCREF(d);
	return d;
}
PyObject * ToJson::toJson(const Arch * a) {
	JSN_DEBUG("Arch - name")
	PyObject *o = toJson(static_cast<const WithNameAndDoc*>(a));

	JSN_DEBUG("Arch - entityName")
	if (a->entityName)
		PyDict_SetItemString(o, "entityName",
				PyUnicode_FromString(a->entityName));

	JSN_DEBUG("Arch - variables")
	addJsonArrP(o, "variables", a->variables);

	JSN_DEBUG("Arch - componentInstances")
	addJsonArrP(o, "componentInstances", a->componentInstances);

	JSN_DEBUG("Arch - statements")
	addJsonArrP(o, "statements", a->statements);

	return o;
}
PyObject * ToJson::toJson(const CompInstance * ci) {
	PyObject * d = toJson(static_cast<const WithDoc*>(ci));

	char * name_str = nullptr;
	Symbol * name_lit = dynamic_cast<Symbol*>(ci->name->data);
	if (name_lit && name_lit->type == SymbolType::symb_ID) {
		name_str = name_lit->value._str;
	}
	if (name_str)
		PyDict_SetItemString(d, "name", PyUnicode_FromString(name_str));
	else
		PyDict_SetItemString(d, "name", toJson(ci->name));

	PyDict_SetItemString(d, "entityName", toJson(ci->entityName));
	addJsonArrP(d, "portMap", ci->portMap);
	addJsonArrP(d, "genericMap", ci->genericMap);

	return d;
}
PyObject * ToJson::toJson(const hdlObjects::Context * c) {
	PyObject * d = PyDict_New();

	JSN_DEBUG("Context - imports")
	addJsonArrP(d, "imports", c->imports);

	JSN_DEBUG("Context - entities")
	addJsonArrP(d, "entities", c->entities);

	JSN_DEBUG("Context - architectures")
	addJsonArrP(d, "architectures", c->architectures);

	JSN_DEBUG("Context - packages")
	addJsonArrP(d, "packages", c->packages);

	JSN_DEBUG("Context - packageHeaders")
	addJsonArrP(d, "packageHeaders", c->packageHeaders);

	JSN_DEBUG("Context - variables")
	addJsonArrP(d, "variables", c->variables);
	return d;
}

PyObject * ToJson::toJson(const hdlObjects::Entity * e) {
	PyObject *d = toJson(static_cast<const WithNameAndDoc*>(e));
	addJsonArrP(d, "generics", e->generics);
	addJsonArrP(d, "ports", e->ports);
	return d;
}
PyObject * ToJson::toJson(const Expr * e) {
	PyObject *d = PyDict_New();
	Operator * op = dynamic_cast<Operator*>(e->data);
	if (op) {
		PyDict_SetItemString(d, "binOperator", toJson(op));
	} else {
		Symbol * literal = dynamic_cast<Symbol*>(e->data);
		if (literal)
			PyDict_SetItemString(d, "literal", toJson(literal));
		else if (e->data)
			throw std::runtime_error("Expr is improperly initialised");
		else
			throw std::runtime_error("Expr has NULL data");
	}
	return d;
}
PyObject * ToJson::toJson(const hdlObjects::Function * fn) {
	PyObject *d = toJson(static_cast<const WithNameAndDoc*>(fn));
	PyDict_SetItemString(d, "isOperator", PyBool_FromLong(fn->isOperator));
	if (fn->returnT) {
		PyDict_SetItemString(d, "returnT", toJson(fn->returnT));
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "returnT", Py_None);
	}
	addJsonArrP(d, "params", *fn->params);
	addJsonArrP(d, "locals", fn->locals);
	addJsonArrP(d, "body", fn->body);
	return d;
}
PyObject * ToJson::toJson(const hdlObjects::Named * n) {
	PyObject *d = PyDict_New();
	if (n->name) {
		PyDict_SetItemString(d, "name", PyUnicode_FromString(n->name));
	}
	return d;
}
PyObject * ToJson::toJson(const WithDoc * wd) {
	PyObject *d = PyDict_New();
	if (wd->__doc__.size()) {
		PyDict_SetItemString(d, "__doc__",
				PyUnicode_FromString(wd->__doc__.c_str()));
	}
	return d;
}
PyObject * ToJson::toJson(const WithNameAndDoc * wnd) {
	PyObject *d = PyDict_New();
	if (wnd->name) {
		PyDict_SetItemString(d, "name", PyUnicode_FromString(wnd->name));
	}
	if (wnd->__doc__.size()) {
		PyDict_SetItemString(d, "__doc__",
				PyUnicode_FromString(wnd->__doc__.c_str()));
	}
	return d;
}
PyObject * ToJson::toJson(const Port * p) {
	PyObject *d = PyDict_New();
	PyDict_SetItemString(d, "direction",
			PyUnicode_FromString(Direction_toString(p->direction)));
	PyDict_SetItemString(d, "variable", toJson(p->variable));
	return d;
}
PyObject * ToJson::toJson(const Process * p) {
	PyObject *d = toJson(static_cast<const WithNameAndDoc*>(p));
	if (p->sensitivity_list_specified)
		addJsonArrP(d, "sensitivity_list", p->sensitivity_list);
	addJsonArrP(d, "statements", p->statements);
	return d;
}

pair<PyObject *, size_t> ToJson::cases_toJson(vector<Expr*>::const_iterator cond_begin,
		vector<Expr*>::const_iterator cond_end,
		vector<vector<Statement*>*>::const_iterator stms_begin) {
	PyObject * cases = nullptr;
	size_t size = cond_end - cond_begin;
	if (size)
		cases = PyList_New(size);
	for (size_t case_cnt = 0; case_cnt < size; case_cnt++) {
		// build tuple representing the elif item
		auto case_ = PyTuple_New(2);
		Expr* c = *cond_begin;
		PyTuple_SetItem(case_, 0, toJson(c));
		// fill statements in elif
		auto stms = *stms_begin;
		PyObject * stm_list = PyList_New(stms->size());
		for (unsigned i = 0; i < stms->size(); i++) {
			auto _o = (*stms)[i];
			assert(_o);
			PyObject * o = toJson(_o);
			PyList_SetItem(stm_list, i, o);
		}
		//Py_IncRef(objList);
		PyTuple_SetItem(case_, 1, stm_list);
		// add to elif list
		PyList_SetItem(cases, case_cnt, case_);
		++cond_begin;
		++stms_begin;
	}
	return {cases, size};
}

PyObject * ToJson::toJson(const Statement * s) {
	PyObject *d = toJson(static_cast<const WithDoc*>(s));

	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(StatementType_toString(s->type)));
	auto & exprs = s->exprs;
	auto & sub_statements = s->sub_statements;
	auto type = s->type;
	if (type == s_EXPR) {
		return toJson(exprs[0]);
	} else if (type == s_IF) {
		PyDict_SetItemString(d, "cond", toJson(exprs[0]));
		assert(sub_statements.size());
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
		PyDict_SetItemString(d, "switchOn", toJson(exprs[0]));
		PyObject * c;
		size_t c_cnt;
		tie(c, c_cnt) = cases_toJson(exprs.begin() + 1, exprs.end(),
				sub_statements.begin() + 1);
		if (c) {
			PyDict_SetItemString(d, "cases", c);
		}
		if (sub_statements.size() > c_cnt) {
			addJsonArrP(d, "default", *sub_statements.at(c_cnt - 1));
		}
	} else if (type == s_RETURN) {
		PyDict_SetItemString(d, "val", toJson(exprs[0]));
	} else if (type == s_ASSIGMENT) {
		PyDict_SetItemString(d, "dst", toJson(exprs[0]));
		PyDict_SetItemString(d, "src", toJson(exprs[1]));
	} else if (type == s_WHILE) {
		PyDict_SetItemString(d, "cond", toJson(exprs[0]));
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

PyObject * ToJson::toJson(const Symbol * s) {
	PyObject * d = PyDict_New();
	PyObject * tmp = nullptr;
	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(SymbolType_toString(s->type)));

	PyObject * val = nullptr;
	size_t indx = 0;

	switch (s->type) {
	case symb_ID:
	case symb_STRING:
		assert(s->value._str);
		val = PyUnicode_FromString(s->value._str);
		break;
	case symb_FLOAT:
		val = PyFloat_FromDouble(s->value._float);
		break;
	case symb_INT:
		val = s->value._int;
		if (s->bits > 0)
			Py_IncRef(val);
		PyDict_SetItemString(d, "bits", PyLong_FromLong(s->bits));
		break;
	case symb_ARRAY:
		assert(s->value_arr);
		val = PyList_New(s->value_arr->size());
		for (auto symb : *s->value_arr) {
			tmp = toJson(&symb);
			Py_IncRef(tmp);
			PyList_SetItem(val, indx, tmp);
			indx++;
		}
		break;
	case symb_OPEN:
	default:
		val = Py_None;
		Py_INCREF(val);
		break;
	}
	if (!val) {
		val = Py_None;
		Py_INCREF(val);
	}
	PyDict_SetItemString(d, "value", val);
	return d;
}
PyObject* ToJson::toJson(const Variable * v) {
	PyObject *d = toJson(static_cast<const WithNameAndDoc*>(v));
	if (!v->type)
		throw std::runtime_error("Variable has no type");

	PyDict_SetItemString(d, "type", toJson(v->type));

	if (v->value) {
		PyDict_SetItemString(d, "value", toJson(v->value));
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "value", Py_None);
	}
	if (v->latched) {
		Py_IncRef (Py_True);
		PyDict_SetItemString(d, "latched", Py_True);
	}
	return d;
}

PyObject * ToJson::toJson(const Operator * o) {
	PyObject *d = PyDict_New();
	PyDict_SetItemString(d, "op0", toJson(o->op0));
	PyDict_SetItemString(d, "operator",
			PyUnicode_FromString(OperatorType_toString(o->op)));

	int arity = OperatorType_arity(o->op);
	switch (arity) {
	case -1:
	case 3:
		addJsonArrP(d, "operands", *o->operands);
		break;
	case 1:
		break;
	case 2:
		// some of the bin. operators may appear as unary in verilog
		if (o->op1)
			PyDict_SetItemString(d, "op1", toJson(o->op1));
		break;
	default:
		throw runtime_error("Invalid arity of operator");
	}
	return d;
}

#endif

}
