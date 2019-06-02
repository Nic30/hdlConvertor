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
	import(HdlReturnStmCls, "HdlReturnStm");
	import(HdlBreakStmCls, "HdlBreakStm");
	import(HdlContinueStmCls, "HdlContinueStm");
	import(HdlImportCls, "HdlImport");
	import(HdlComponentInstCls, "HdlComponentInst");
	import(HdlFunctionCls, "HdlFunction");
}

std::string ToPy::PyObject_repr(PyObject * o) {
	PyObject* args = Py_BuildValue("(O)", PyObject_Repr(o));
	if (!args)
		return "";
	const char* s = nullptr;
	if (!PyArg_ParseTuple(args, "s", &s)) {
		Py_DECREF(args);
		return "";
	}
	std::string ret = s;
	Py_DECREF(args);
	return ret;
}

PyObject* ToPy::toPy(const Context * o) {
	Py_INCREF(ContextCls);
	PyObject* py_inst = PyObject_CallObject(ContextCls, NULL);
	if (!py_inst)
		return nullptr;
	int e = toPy_arr(py_inst, "objs", o->objs);
	if (e) {
		Py_DECREF(py_inst);
		return nullptr;
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
	auto mdef = dynamic_cast<const Arch *>(o);
	if (mdef)
		return toPy(mdef);
	auto ci = dynamic_cast<const CompInstance *>(o);
	if (ci)
		return toPy(ci);
	auto na = dynamic_cast<const Package *>(o);
	if (na)
		return toPy(na);
	auto naDec = dynamic_cast<const PackageHeader *>(o);
	if (naDec)
		return toPy(naDec);

	auto fn = dynamic_cast<const Function*>(o);
	if (fn)
		return toPy(fn);

	std::string err_msg = std::string("ToPy::toPy unknown type of iHdlObj:")
			+ std::string(typeid(*o).name());
	PyErr_SetString(PyExc_ValueError, err_msg.c_str());
	return nullptr;
}

int ToPy::toPy(const WithNameAndDoc * o, PyObject * py_inst) {
	if (!o) {
		PyErr_SetString(PyExc_ValueError, "ToPy::toPy invalid WithNameAndDoc*");
		return -1;
	}
	int e;
	if (o->name) {
		auto n = PyUnicode_FromString(o->name);
		if (!n) {
			PyErr_SetString(PyExc_ValueError,
					"ToPy::toPy invalid WithNameAndDoc->name");
			return -1;
		}
		e = PyObject_SetAttrString(py_inst, "name", n);
		if (e < 0)
			return e;
	}
	e = toPy(static_cast<const WithDoc*>(o), py_inst);
	if (e < 0)
		return e;
	return 0;
}

int ToPy::toPy(const WithDoc * o, PyObject * py_inst) {
	return PyObject_SetAttrString(py_inst, "doc",
			PyUnicode_FromString(o->__doc__.c_str()));
}

PyObject* ToPy::toPy(const Arch * o) {
	PyObject* py_inst = PyObject_CallObject(HdlModuleDefCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	for (;;) {
		int e = toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
		if (e)
			break;
		if (o->entityName) {
			auto en = toPy(o->entityName);
			if (!en)
				break;
			e = PyObject_SetAttrString(py_inst, "module_name", en);
			if (e)
				break;
		}
		e = toPy_arr(py_inst, "objs", o->objs);
		if (e)
			break;

		return py_inst;
	}
	Py_DECREF(py_inst);
	return nullptr;
}

PyObject* ToPy::toPy(const hdlObjects::CompInstance * o) {
	PyObject* py_inst = PyObject_CallObject(HdlComponentInstCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	auto n = toPy(o->name);
	if (!n) {
		Py_DECREF(py_inst);
		return nullptr;
	}
	int e = PyObject_SetAttrString(py_inst, "name", n);
	if (!e) {
		auto module_name = toPy(o->entityName);
		if (!module_name) {
			e = -1;
		} else {
			e = PyObject_SetAttrString(py_inst, "module_name", module_name);
		}
	}
	if (!e)
		e = toPy_arr(py_inst, "param_map", o->genericMap);
	if (!e)
		e = toPy_arr(py_inst, "port_map", o->portMap);

	if (e) {
		Py_DECREF(py_inst);
		return nullptr;
	}
	return py_inst;
}

PyObject* ToPy::toPy(const Entity * o) {
	PyObject* py_inst = PyObject_CallObject(HdlModuleDecCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	for (;;) {
		int e = toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
		if (e)
			break;

		e = toPy_arr(py_inst, "params", o->generics);
		if (e)
			break;

		e = toPy_arr(py_inst, "ports", o->ports);
		if (e)
			break;

		return py_inst;
	}
	Py_DECREF(py_inst);
	return nullptr;
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
			PyErr_SetString(PyExc_ValueError,
					"ToPy::toPy - Expr is improperly initialised");
		else
			PyErr_SetString(PyExc_ValueError,
					"ToPy::toPy - Expr has NULL data");
	}
	return nullptr;
}

PyObject* ToPy::toPy(const Function * o) {
	PyObject* py_inst = PyObject_CallObject(HdlFunctionCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	for (;;) {
		int e = toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
		if (e)
			break;
		if (o->params) {
			e = toPy_arr(py_inst, "params", *o->params);
			if (e)
				break;
		}
		if (o->returnT) {
			auto r_t = toPy(o->returnT);
			if (!r_t)
				break;
			e = PyObject_SetAttrString(py_inst, "return_t", r_t);
			if (e)
				break;
		}
		e = toPy_arr(py_inst, "body", o->locals);
		if (e)
			break;

		e = toPy_arr(py_inst, "body", o->body);
		if (e)
			break;

		return py_inst;
	}
	Py_DECREF(py_inst);
	return nullptr;
}

PyObject* ToPy::toPy(const Symbol * o) {
	auto t = o->type;

	if (t == symb_ID) {
		assert(o->value._str);
		auto v = PyUnicode_FromString(o->value._str);
		return PyObject_CallFunctionObjArgs(HdlNameCls, v, NULL);
	} else if (t == symb_INT) {
		PyObject* v = o->value._int;
		PyObject* b;
		if (o->bits > 0) {
			b = PyLong_FromLong(o->bits);
		} else {
			Py_INCREF(Py_None);
			b = Py_None;
		}

		return PyObject_CallFunctionObjArgs(HdlIntValueCls, v, b, NULL);
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
		if (!val)
			return nullptr;
		size_t indx = 0;
		for (auto symb : *o->value_arr) {
			auto tmp = toPy(&symb);
			if (!tmp) {
				Py_DECREF(val);
				return nullptr;
			}
			int e = PyList_SetItem(val, indx, tmp);
			if (e) {
				Py_DECREF(val);
				return nullptr;
			}
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
		return PyObject_CallObject(HdlTypeTypeCls, NULL);
	}
}

PyObject* ToPy::toPy(const OperatorType o) {
	auto name = OperatorType_toString(o);
	return PyObject_GetAttrString(HdlBuildinFnEnum, name);
}

PyObject* ToPy::toPy(const Direction o) {
	auto v = PyLong_FromLong(o);
	if (!v) {
		Py_DECREF(v);
		return nullptr;
	}

	return PyObject_CallFunctionObjArgs(HdlDirectionEnum, v, NULL);
}

PyObject* ToPy::toPy(const Operator * o) {
	PyObject* py_inst = PyObject_CallObject(HdlCallCls, NULL);
	if (!py_inst)
		return nullptr;

	int e = PyObject_SetAttrString(py_inst, "fn", toPy(o->op));
	if (e) {
		Py_DECREF(py_inst);
		return nullptr;
	}
	e = toPy_arr(py_inst, "ops", o->operands);
	if (e) {
		Py_DECREF(py_inst);
		return nullptr;
	}
	return py_inst;
}

// [TODO] too similar with the code for Arch
PyObject* ToPy::toPy(const Package* o) {
	PyObject* py_inst = PyObject_CallObject(HdlModuleDefCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	for (;;) {
		int e = toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
		if (e)
			break;
		e = toPy_arr(py_inst, "objs", o->objs);
		if (e)
			break;

		return py_inst;
	}
	Py_DECREF(py_inst);
	return nullptr;
}
PyObject* ToPy::toPy(const PackageHeader* o) {
	return toPy(reinterpret_cast<const Package*>(o));
}

PyObject* ToPy::toPy(const Variable * o) {
	PyObject* py_inst = PyObject_CallObject(HdlVariableDefCls, NULL);
	if (!py_inst)
		return nullptr;
	int e = toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
	if (!e) {
		for (;;) {
			auto t = toPy(o->type);
			if (!t)
				break;
			e = PyObject_SetAttrString(py_inst, "type", t);
			if (e < 0)
				break;
			if (o->value) {
				auto v = toPy(o->value);
				if (!v)
					break;
				e = PyObject_SetAttrString(py_inst, "value", v);
				if (e < 0)
					break;
			} // else let it to be None

			e = PyObject_SetAttrString(py_inst, "latched",
					PyBool_FromLong((long) o->latched));
			if (e < 0)
				break;

			e = PyObject_SetAttrString(py_inst, "is_const",
					PyBool_FromLong((long) o->is_const));
			if (e < 0)
				break;

			e = PyObject_SetAttrString(py_inst, "direction",
					toPy(o->direction));
			return py_inst;
		}
	}
	Py_XDECREF(py_inst);
	return nullptr;
}

std::pair<PyObject *, size_t> ToPy::cases_toPy(
		std::vector<Expr*>::const_iterator cond_begin,
		std::vector<Expr*>::const_iterator cond_end,
		std::vector<std::vector<iHdlObj*>*>::const_iterator stms_begin) {
	PyObject * cases = nullptr;
	size_t size = cond_end - cond_begin;
	if (size) {
		cases = PyList_New(size);
		if (!cases) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}
	}
	for (size_t case_cnt = 0; case_cnt < size; case_cnt++) {
		// build tuple representing the elif item
		auto case_ = PyTuple_New(2);
		if (!case_) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}
		// add to elif/case list
		int e = PyList_SetItem(cases, case_cnt, case_);
		if (e) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}

		Expr* _c = *cond_begin;
		auto c = toPy(_c);
		if (!c) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}

		e = PyTuple_SetItem(case_, 0, c);
		if (e) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}

		// fill statements in elif/case
		auto & stms = **stms_begin;
		PyObject * stm_list = PyList_New(stms.size());
		if (!stm_list) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}
		e = PyTuple_SetItem(case_, 1, stm_list);
		if (e) {
			Py_DECREF(cases);
			return {nullptr, SIZE_T_ERR};
		}
		for (unsigned i = 0; i < stms.size(); i++) {
			auto _o = stms[i];
			assert(_o);
			PyObject * o = toPy(_o);
			if (!o) {
				Py_DECREF(cases);
				return {nullptr, SIZE_T_ERR};
			}
			e = PyList_SetItem(stm_list, i, o);
			if (e) {
				Py_DECREF(cases);
				return {nullptr, SIZE_T_ERR};
			}
		}

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
	int e = 0;

	if (type == s_EXPR) {
		return toPy(exprs[0]);
	} else if (type == s_IF) {
		py_inst = PyObject_CallObject(HdlIfStmCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = PyObject_SetAttrString(py_inst, "cond", toPy(exprs[0]));
		if (e < 0) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		assert(sub_statements.size());
		e = toPy_arr(py_inst, "if_true", *sub_statements[0]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		PyObject * elseIfs;
		size_t elif_cnt;
		std::tie(elseIfs, elif_cnt) = cases_toPy(exprs.begin() + 1, exprs.end(),
				sub_statements.begin() + 1);
		if (elseIfs) {
			if (PyObject_SetAttrString(py_inst, "elifs", elseIfs) < 0) {
				Py_DECREF(py_inst);
				return nullptr;
			}
		}
		if (elif_cnt == SIZE_T_ERR) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		if (sub_statements.size() > elif_cnt + 1) {
			auto & if_false = *sub_statements.at(elif_cnt + 1);
			auto py_if_false = PyList_New(0);
			if (!py_if_false)
				e = -1;
			if (!e)
				e = PyObject_SetAttrString(py_inst, "if_false", py_if_false);
			if (!e)
				e = toPy_arr(py_inst, "if_false", if_false);
			if (e) {
				Py_DECREF(py_inst);
				return nullptr;
			}
		}

	} else if (type == s_CASE) {
		py_inst = PyObject_CallObject(HdlCaseStmCls, NULL);
		if (!py_inst) {
			return nullptr;
		}
		e = PyObject_SetAttrString(py_inst, "switch_on", toPy(exprs[0]));
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		PyObject * c;
		size_t c_cnt;
		std::tie(c, c_cnt) = cases_toPy(exprs.begin() + 1, exprs.end(),
				sub_statements.begin());
		if (c) {
			PyObject_SetAttrString(py_inst, "cases", c);
		}
		if (c_cnt == SIZE_T_ERR) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		if (sub_statements.size() > c_cnt) {
			auto & def = *sub_statements.at(c_cnt - 1);
			auto py_def = PyList_New(0);
			if (!py_def)
				e = -1;
			if (!e)
				e = PyObject_SetAttrString(py_inst, "default", py_def);
			if (!e)
				e = toPy_arr(py_inst, "default", def);

			if (e) {
				Py_DECREF(py_inst);
				return nullptr;
			}
		}

	} else if (type == s_FOR) {
		py_inst = PyObject_CallObject(HdlForStmCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = toPy_arr(py_inst, "param", exprs);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		e = toPy_arr(py_inst, "body", *sub_statements[0]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}

	} else if (type == s_RETURN) {
		py_inst = PyObject_CallObject(HdlReturnStmCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		PyObject* v;
		if (exprs.size()) {
			assert(exprs.size() == 1);
			v = toPy(exprs[0]);
		} else {
			Py_INCREF(Py_None);
			v = Py_None;
		}
		e = PyObject_SetAttrString(py_inst, "val", v);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}

	} else if (type == s_BREAK) {
		py_inst = PyObject_CallObject(HdlBreakStmCls, NULL);
	} else if (type == s_CONTINUE) {
		py_inst = PyObject_CallObject(HdlContinueStmCls, NULL);
	} else if (type == s_ASSIGMENT) {
		auto src = toPy(o->exprs[0]);
		if (!src)
			e = -1;
		if (!e) {
			auto dst = toPy(o->exprs[0]);
			if (!dst)
				e = -1;
			if (!e) {

				py_inst = PyObject_CallFunctionObjArgs(HdlAssignStmCls, src,
						dst, NULL);
			}
		}
		if (e || !py_inst) {
			return nullptr;
		}

	} else if (type == s_WHILE) {

		py_inst = PyObject_CallObject(HdlWhileStmCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = PyObject_SetAttrString(py_inst, "cond", toPy(exprs[0]));
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
		e = toPy_arr(py_inst, "body", *sub_statements[0]);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	} else if (type == s_PROCESS) {
		auto p = dynamic_cast<const Process*>(o);
		assert(p);

		py_inst = PyObject_CallObject(HdlProcessStmCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		if (p->sensitivity_list_specified) {
			auto & sl = p->sensitivity_list();
			auto py_sl = PyList_New(0);
			if (!py_sl)
				e = -1;
			if (!e)
				e = PyObject_SetAttrString(py_inst, "sensitivity", py_sl);
			if (!e)
				e = toPy_arr(py_inst, "sensitivity", sl);
		} else {
			assert(exprs.size() == 0);
		}
		if (!e)
			e = toPy_arr(py_inst, "body", p->objs());
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	} else if (type == s_IMPORT) {
		py_inst = PyObject_CallObject(HdlImportCls, NULL);
		if (!py_inst) {
			return nullptr;
		}

		e = toPy_arr(py_inst, "path", o->exprs);
		if (e) {
			Py_DECREF(py_inst);
			return nullptr;
		}
	} else {
		throw std::runtime_error("Invalid StatementType");
	}
	if (!e)
		e = toPy(static_cast<const WithDoc*>(o), py_inst);
	if (!e)
		e = toPy_arr(py_inst, "labels", o->labels);
	if (!e)
		e = PyObject_SetAttrString(py_inst, "in_prepoc",
				PyBool_FromLong((long) o->in_preproc));
	if (e < 0) {
		Py_DECREF(py_inst);
		return nullptr;
	}

	return py_inst;
}

PyObject* ToPy::toPy(const std::string & o) {
	return PyUnicode_FromString(o.c_str());
}

ToPy::~ToPy() {
	Py_XDECREF(HdlFunctionCls);
	Py_XDECREF(HdlComponentInstCls);
	Py_XDECREF(HdlImportCls);
	Py_XDECREF(HdlContinueStmCls);
	Py_XDECREF(HdlBreakStmCls);
	Py_XDECREF(HdlReturnStmCls);
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
