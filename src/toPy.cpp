#include "toPy.h"
#include <assert.h>
#include <tuple>

namespace hdlConvertor {

using namespace hdlObjects;

ToPy::ToPy() {
	hdlAst_module = PyImport_ImportModule("hdlConvertor.hdlAst");
	assert(hdlAst_module != nullptr);

	auto import = [this](PyObject*& obj, const std::string & name) {
		obj = PyObject_GetAttrString(hdlAst_module, name.c_str());
		assert(obj != NULL);
	};
	import(ContextCls, "HdlContext");
	import(CodePositionCls, "CodePosition");
	import(HdlModuleDefCls, "HdlModuleDef");
	import(HdlModuleDecCls, "HdlModuleDec");
	import(HdlVariableDefCls, "HdlVariableDef");
	import(HdlCallCls, "HdlCall");
	import(HdlBuildinFnEnum, "HdlBuildinFn");
	import(HdlIntValueCls, "HdlIntValue");
	import(HdlNameCls, "HdlName");
	import(HdlDirectionEnum, "HdlDirection");
	import(HdlAllCls, "HdlAll");
	import(HdlTypeTypeCls, "HdlTypeType");
	import(HdlIfStmCls, "HdlIfStm");
	import(HdlAssignStmCls, "HdlAssignStm");
	import(HdlProcessStmCls, "HdlProcessStm");
	import(HdlCaseStmCls, "HdlCaseStm");
	import(HdlForStmCls, "HdlForStm");
	import(HdlWhileStmCls, "HdlWhileStm");
	import(HdlReturnCls, "HdlReturn");
	import(HdlBreakStmCls, "HdlBreakStm");
	import(HdlContinueStmCls, "HdlContinueStm");
	import(HdlImportCls, "HdlImport");
}

PyObject* ToPy::toPy(const Context * o) {
	PyObject* py_inst = PyObject_CallObject(CodePositionCls, NULL);
	for (auto obj : o->objs) {
		auto pyO = toPy(obj);
		int e = PyList_Append(py_inst, pyO);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	}
	return py_inst;
}

PyObject* ToPy::toPy(const iHdlObj * o) {
	auto c = dynamic_cast<const Context*>(o);
	if (c)
		return toPy(c);
	auto md = dynamic_cast<const Entity*>(o);
	if (md)
		return toPy(md);
	auto ex = dynamic_cast<const Expr*>(o);
	if (ex)
		return toPy(ex);
	auto v = dynamic_cast<const Variable*>(o);
	if (v)
		return toPy(v);
	auto s = dynamic_cast<const Statement*>(o);
	if (s)
		return toPy(s);

	assert(false);
	return nullptr;
}

void ToPy::toPy(const WithNameAndDoc * o, PyObject * py_inst) {
	PyObject_SetAttrString(py_inst, "name", PyUnicode_FromString(o->name));
	toPy(static_cast<const WithDoc*>(o), py_inst);
}

void ToPy::toPy(const WithDoc * o, PyObject * py_inst) {
	PyObject_SetAttrString(py_inst, "doc",
			PyUnicode_FromString(o->__doc__.c_str()));
}

PyObject* ToPy::toPy(const Entity * o) {
	PyObject* py_inst = PyObject_CallObject(HdlModuleDecCls, NULL);
	toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
	toPy_arr(py_inst, "params", o->generics);
	toPy_arr(py_inst, "ports", o->ports);

	return py_inst;
}

PyObject* ToPy::toPy(const Expr * o) {
	Operator * op = dynamic_cast<Operator*>(o->data);
	if (op) {
		return toPy(op);
	} else {
		Symbol * literal = dynamic_cast<Symbol*>(o->data);
		if (literal)
			return toPy(literal);
		else if (o->data)
			throw std::runtime_error("Expr is improperly initialised");
		else
			throw std::runtime_error("Expr has NULL data");
	}
}

PyObject* ToPy::toPy(const Symbol * o) {
	auto t = o->type;

	if (t == symb_ID) {
		assert(o->value._str);
		auto v = PyUnicode_FromString(o->value._str);
		return PyObject_CallFunctionObjArgs(HdlNameCls, v, NULL);
	} else if (t == symb_INT) {
		PyObject* pArgs = PyTuple_New(2);
		PyObject* v = o->value._int;
		PyObject* b;
		if (o->bits > 0) {
			b = PyLong_FromLong(o->bits);
		} else {
			Py_INCREF(Py_None);
			b = Py_None;
		}
		int error = PyTuple_SetItem(pArgs, 0, v);
		error |= PyTuple_SetItem(pArgs, 1, b);
		assert(error == 0);
		return PyObject_CallFunctionObjArgs(HdlIntValueCls, pArgs, NULL);
	} else if (t == symb_FLOAT) {
		return PyFloat_FromDouble(o->value._float);
	} else if (t == symb_STRING) {
		assert(o->value._str);
		return PyUnicode_FromString(o->value._str);
	} else if (t == symb_OPEN) {
		Py_RETURN_NONE;
	} else if (t == symb_ARRAY) {
		assert(o->value_arr);
		auto val = PyList_New(o->value_arr->size());
		size_t indx = 0;
		for (auto symb : *o->value_arr) {
			auto tmp = toPy(&symb);
			Py_IncRef(tmp);
			PyList_SetItem(val, indx, tmp);
			indx++;
		}
		return val;
	} else if (t == symb_ALL) {
		Py_INCREF(HdlAllCls);
		return HdlAllCls;
	} else if (t == symb_NULL) {
		Py_RETURN_NONE;
	} else {
		assert(t == symb_T);
		Py_INCREF(HdlTypeTypeCls);
		return PyObject_CallObject(HdlTypeTypeCls, NULL);
	}
}

PyObject* ToPy::toPy(const OperatorType o) {
	auto name = OperatorType_toString(o);
	return PyObject_GetAttrString(HdlBuildinFnEnum, name);
}

PyObject* ToPy::toPy(const Direction o) {
	PyObject *pArgs = PyTuple_New(1);
	auto v = PyLong_FromLong(o);
	int error = PyTuple_SetItem(pArgs, 0, v);
	if (error) {
		Py_DECREF(pArgs);
		Py_DECREF(v);
		return nullptr;
	}
	return PyObject_CallFunctionObjArgs(HdlDirectionEnum, pArgs, NULL);
}

PyObject* ToPy::toPy(const Operator * o) {
	PyObject* py_inst = PyObject_CallObject(HdlCallCls, NULL);
	assert(py_inst);
	int e = PyObject_SetAttrString(py_inst, "fn", toPy(o->op));
	if (e) {
		Py_DECREF(py_inst);
		return nullptr;
	}
	toPy_arr(py_inst, "ops", o->operands);
	return py_inst;
}

PyObject* ToPy::toPy(const Variable * o) {
	PyObject* py_inst = PyObject_CallObject(HdlModuleDecCls, NULL);
	assert(py_inst);
	toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
	int e = 0;
	e |= PyObject_SetAttrString(py_inst, "type", toPy(o->type));
	e |= PyObject_SetAttrString(py_inst, "value", toPy(o->value));
	e |= PyObject_SetAttrString(py_inst, "latched",
			PyBool_FromLong((long) o->latched));
	e |= PyObject_SetAttrString(py_inst, "is_const",
			PyBool_FromLong((long) o->is_const));
	e |= PyObject_SetAttrString(py_inst, "direction", toPy(o->direction));
	assert(e == 0);
	return py_inst;
}

std::pair<PyObject *, size_t> ToPy::cases_toPy(
		std::vector<Expr*>::const_iterator cond_begin,
		std::vector<Expr*>::const_iterator cond_end,
		std::vector<std::vector<iHdlObj*>*>::const_iterator stms_begin) {
	PyObject * cases = nullptr;
	size_t size = cond_end - cond_begin;
	if (size)
		cases = PyList_New(size);
	for (size_t case_cnt = 0; case_cnt < size; case_cnt++) {
		// build tuple representing the elif item
		auto case_ = PyTuple_New(2);
		Expr* c = *cond_begin;
		PyTuple_SetItem(case_, 0, toPy(c));
		// fill statements in elif
		auto stms = *stms_begin;
		PyObject * stm_list = PyList_New(stms->size());
		for (unsigned i = 0; i < stms->size(); i++) {
			auto _o = (*stms)[i];
			assert(_o);
			PyObject * o = toPy(_o);
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

PyObject* ToPy::toPy(const Statement * o) {
	auto & exprs = o->exprs;
	auto & sub_statements = o->sub_statements;
	auto type = o->type;
	PyObject* py_inst = nullptr;

	if (type == s_EXPR) {
		return toPy(exprs[0]);
	} else if (type == s_IF) {
		py_inst = PyObject_CallObject(HdlIfStmCls, NULL);
		PyObject_SetAttrString(py_inst, "cond", toPy(exprs[0]));
		assert(sub_statements.size());
		toPy_arr(py_inst, "ifTrue", *sub_statements[0]);
		PyObject * elseIfs;
		size_t elif_cnt;
		std::tie(elseIfs, elif_cnt) = cases_toPy(exprs.begin() + 1, exprs.end(),
				sub_statements.begin() + 1);
		if (elseIfs) {
			PyObject_SetAttrString(py_inst, "elifs", elseIfs);
		}
		if (sub_statements.size() > elif_cnt + 1) {
			toPy_arr(py_inst, "ifFalse", *sub_statements.at(elif_cnt + 1));
		}
	} else if (type == s_CASE) {
		py_inst = PyObject_CallObject(HdlCaseStmCls, NULL);
		PyObject_SetAttrString(py_inst, "switchOn", toPy(exprs[0]));
		PyObject * c;
		size_t c_cnt;
		std::tie(c, c_cnt) = cases_toPy(exprs.begin() + 1, exprs.end(),
				sub_statements.begin() + 1);
		if (c) {
			PyObject_SetAttrString(py_inst, "cases", c);
		}
		if (sub_statements.size() > c_cnt) {
			toPy_arr(py_inst, "default", *sub_statements.at(c_cnt - 1));
		}
	} else if (type == s_FOR) {
		py_inst = PyObject_CallObject(HdlForStmCls, NULL);
		toPy_arr(py_inst, "param", exprs);
		toPy_arr(py_inst, "body", *sub_statements[0]);
	} else if (type == s_RETURN) {
		py_inst = PyObject_CallObject(HdlReturnCls, NULL);
		PyObject* v;
		if (exprs.size()) {
			assert(exprs.size() == 1);
			v = toPy(exprs[0]);
		} else {
			Py_INCREF(Py_None);
			v = Py_None;
		}
		PyObject_SetAttrString(py_inst, "val", v);
	} else if (type == s_BREAK) {
		py_inst = PyObject_CallObject(HdlBreakStmCls, NULL);
	} else if (type == s_CONTINUE) {
		py_inst = PyObject_CallObject(HdlContinueStmCls, NULL);
	} else if (type == s_ASSIGMENT) {
		py_inst = PyObject_CallObject(HdlAssignStmCls, NULL);
		PyObject_SetAttrString(py_inst, "dst", toPy(exprs[0]));
		PyObject_SetAttrString(py_inst, "src", toPy(exprs[1]));
	} else if (type == s_WHILE) {
		py_inst = PyObject_CallObject(HdlWhileStmCls, NULL);
		PyObject_SetAttrString(py_inst, "cond", toPy(exprs[0]));
		toPy_arr(py_inst, "body", *sub_statements[0]);
	} else if (type == s_PROCESS) {
		py_inst = PyObject_CallObject(HdlProcessStmCls, NULL);
		if (exprs.size() && exprs[0]) {
			assert(exprs.size() == 1);
			toPy_arr(py_inst, "sensitivity", exprs);
		}
		auto & body = *sub_statements[0];
		toPy_arr(py_inst, "body", body);
	} else if (type == s_IMPORT) {
		py_inst = PyObject_CallObject(HdlImportCls, NULL);

	} else {
		throw std::runtime_error("Invalid StatementType");
	}
	toPy(static_cast<const WithDoc*>(o), py_inst);
	toPy_arr(py_inst, "labels", o->labels);
	return py_inst;
}

PyObject* ToPy::toPy(const std::string & o) {
	return PyUnicode_FromString(o.c_str());
}

ToPy::~ToPy() {
	Py_XDECREF(HdlImportCls);
	Py_XDECREF(HdlContinueStmCls);
	Py_XDECREF(HdlBreakStmCls);
	Py_XDECREF(HdlReturnCls);
	Py_XDECREF(HdlWhileStmCls);
	Py_XDECREF(HdlForStmCls);
	Py_XDECREF(HdlCaseStmCls);
	Py_XDECREF(HdlProcessStmCls);
	Py_XDECREF(HdlAssignStmCls);
	Py_XDECREF(HdlIfStmCls);
	Py_XDECREF(HdlTypeTypeCls);
	Py_XDECREF(HdlDirectionEnum);
	Py_XDECREF(HdlNameCls);
	Py_XDECREF(HdlIntValueCls);
	Py_XDECREF(HdlBuildinFnEnum);
	Py_XDECREF(HdlCallCls);
	Py_XDECREF(HdlVariableDefCls);
	Py_XDECREF(HdlModuleDecCls);
	Py_XDECREF(HdlModuleDefCls);
	Py_XDECREF(CodePositionCls);
	Py_XDECREF(ContextCls);
	Py_XDECREF(hdlAst_module);
}

}
