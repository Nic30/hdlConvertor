#include "toPy.h"

#include <Python.h>

#include <iterator>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>

#include <hdlConvertor/hdlObjects/bigInteger.h>
#include <hdlConvertor/hdlObjects/hdlDirection.h>
#include <hdlConvertor/hdlObjects/hdlValue.h>

namespace hdlConvertor {

using namespace hdlObjects;

ToPy::ToPy() {
	hdlAst_module = PyImport_ImportModule("hdlConvertor.hdlAst");
	if (hdlAst_module == nullptr) {
		// this could happen only if there are missing files in library
		PyErr_Print();
		throw std::runtime_error("can not import hdlConvertor.hdlAst");
	}
	auto import = [this](PyObject*& obj, const std::string & name) {
		obj = PyObject_GetAttrString(hdlAst_module, name.c_str());
		assert(obj != NULL &&
				"Bug in this library hdlConvertor.hdlAst not as expected from C");
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
	import(HdlOthersCls, "HdlOthers");
	import(HdlTypeAutoCls, "HdlTypeAuto");
	import(HdlTypeTypeCls, "HdlTypeType");
	import(HdlStmIfCls, "HdlStmIf");
	import(HdlStmAssignCls, "HdlStmAssign");
	import(HdlStmProcessCls, "HdlStmProcess");
	import(HdlStmCaseCls, "HdlStmCase");
	import(HdlStmForCls, "HdlStmFor");
	import(HdlStmForInCls, "HdlStmForIn");
	import(HdlStmWhileCls, "HdlStmWhile");
	import(HdlStmReturnCls, "HdlStmReturn");
	import(HdlStmBreakCls, "HdlStmBreak");
	import(HdlStmContinueCls, "HdlStmContinue");
	import(HdlStmWaitCls, "HdlStmWait");
	import(HdlImportCls, "HdlImport");
	import(HdlComponentInstCls, "HdlComponentInst");
	import(HdlFunctionDefCls, "HdlFunctionDef");
	import(HdlNamespaceCls, "HdlNamespace");
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

PyObject* ToPy::toPy(const HdlContext * o) {
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
	auto c = dynamic_cast<const HdlContext*>(o);
	if (c)
		return toPy(c);
	auto md = dynamic_cast<const HdlModuleDec*>(o);
	if (md)
		return toPy(md);
	auto ex = dynamic_cast<const iHdlExpr*>(o);
	if (ex)
		return toPy(ex);
	auto v = dynamic_cast<const HdlVariableDef*>(o);
	if (v)
		return toPy(v);
	auto s = dynamic_cast<const iHdlStatement*>(o);
	if (s)
		return toPy(s);
	auto mdef = dynamic_cast<const HdlModuleDef *>(o);
	if (mdef)
		return toPy(mdef);
	auto ci = dynamic_cast<const HdlCompInstance *>(o);
	if (ci)
		return toPy(ci);
	auto ns = dynamic_cast<const HdlNamespace *>(o);
	if (ns)
		return toPy(ns);
	auto fn = dynamic_cast<const HdlFunctionDef*>(o);
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
	if (o->name.size()) {
		auto n = PyUnicode_FromString(o->name.c_str());
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

PyObject* ToPy::toPy(const HdlModuleDef * o) {
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

PyObject* ToPy::toPy(const hdlObjects::HdlCompInstance * o) {
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

PyObject* ToPy::toPy(const HdlModuleDec * o) {
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

PyObject* ToPy::toPy(const iHdlExpr * o) {
	HdlCall * op = dynamic_cast<HdlCall*>(o->data);
	if (op) {
		return toPy(op);
	} else {
		HdlValue * literal = dynamic_cast<HdlValue*>(o->data);
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

PyObject* ToPy::toPy(const HdlFunctionDef * o) {
	PyObject* py_inst = PyObject_CallObject(HdlFunctionDefCls, NULL);
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

PyObject* ToPy::toPy(const HdlValue * o) {
	auto t = o->type;

	if (t == HdlValueType::symb_ID) {
		assert(!o->_str.empty());
		auto v = PyUnicode_FromString(o->_str.c_str());
		if (!v)
			return nullptr;
		return PyObject_CallFunctionObjArgs(HdlNameCls, v, NULL);
	} else if (t == HdlValueType::symb_INT) {
		auto & _v = o->_int;
		PyObject * v, * bits, * base = nullptr;
		if (_v.is_bitstring()) {
			v = PyUnicode_FromString(_v.bitstring.c_str());
		} else {
			v = PyLong_FromLong(_v.val);
		}
		if (!v)
			return nullptr;
		if (_v.is_bitstring()) {
			base =  PyLong_FromLong(_v.bitstring_base);
			if (!base) {
				Py_DECREF(v);
				return nullptr;
			}
		}else {
			Py_INCREF(Py_None);
			base = Py_None;
		}
		if (o->bits > 0) {
			bits = PyLong_FromLong(o->bits);
			if (!bits) {
				Py_XDECREF(base);
				Py_DECREF(v);
				return nullptr;
			}
		} else {
			Py_INCREF(Py_None);
			bits = Py_None;
		}

		return PyObject_CallFunctionObjArgs(HdlIntValueCls, v, bits, base, NULL);
	} else if (t == HdlValueType::symb_FLOAT) {
		return PyFloat_FromDouble(o->_float);
	} else if (t == HdlValueType::symb_STRING) {
		return PyUnicode_FromString(o->_str.c_str());
	} else if (t == HdlValueType::symb_OPEN) {
		Py_RETURN_NONE;
	} else if (t == HdlValueType::symb_ARRAY) {
		assert(o->_arr);
		auto val = PyList_New(o->_arr->size());
		if (!val)
			return nullptr;
		size_t indx = 0;
		for (auto elem : *o->_arr) {
			auto tmp = toPy(elem);
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
	} else if (t == HdlValueType::symb_ALL) {
		Py_INCREF(HdlAllCls);
		return HdlAllCls;
	} else if (t == HdlValueType::symb_NULL) {
		Py_RETURN_NONE;
	} else if (t == HdlValueType::symb_T) {
		Py_INCREF(HdlTypeTypeCls);
		return HdlTypeTypeCls;
	} else if (t == HdlValueType::symb_AUTO) {
		Py_INCREF(HdlTypeAutoCls);
		return HdlTypeAutoCls;
	} else if (t == HdlValueType::symb_ALL) {
		Py_INCREF(HdlAllCls);
		return HdlAllCls;
	} else if (t == HdlValueType::symb_OTHERS) {
		Py_INCREF(HdlOthersCls);
		return HdlOthersCls;
	} else {
		PyErr_SetString(PyExc_AssertionError, "invalid type of the HdlValue");
		return nullptr;
	}
}

PyObject* ToPy::toPy(const HdlOperatorType o) {
	auto name = HdlOperatorType_toString(o);
	return PyObject_GetAttrString(HdlBuildinFnEnum, name);
}

PyObject* ToPy::toPy(const HdlDirection o) {
	auto v = PyLong_FromLong(o);
	if (!v) {
		Py_DECREF(v);
		return nullptr;
	}

	return PyObject_CallFunctionObjArgs(HdlDirectionEnum, v, NULL);
}

PyObject* ToPy::toPy(const HdlCall * o) {
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

// [TODO] too similar with the code for HdlModuleDef
PyObject* ToPy::toPy(const HdlNamespace* o) {
	PyObject* py_inst = PyObject_CallObject(HdlNamespaceCls, NULL);
	for (;;) {
		if (py_inst == nullptr)
			break;
		int e = toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
		if (e)
			break;
		e = toPy_arr(py_inst, "objs", o->objs);
		if (e)
			break;

		auto dec_only = PyBool_FromLong(o->defs_only);
		if (!dec_only)
			break;

		if (PyObject_SetAttrString(py_inst, "declaration_only", dec_only))
			break;

		return py_inst;
	}
	Py_XDECREF(py_inst);
	return nullptr;
}

PyObject* ToPy::toPy(const HdlVariableDef * o) {
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

			e = PyObject_SetAttrString(py_inst, "is_latched",
					PyBool_FromLong((long) o->is_latched));
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

PyObject* ToPy::toPy(const std::string & o) {
	return PyUnicode_FromString(o.c_str());
}

ToPy::~ToPy() {
	Py_XDECREF(HdlNamespaceCls);
	Py_XDECREF(HdlFunctionDefCls);
	Py_XDECREF(HdlComponentInstCls);
	Py_XDECREF(HdlImportCls);
	Py_XDECREF(HdlStmWaitCls);
	Py_XDECREF(HdlStmContinueCls);
	Py_XDECREF(HdlStmBreakCls);
	Py_XDECREF(HdlStmReturnCls);
	Py_XDECREF(HdlStmWhileCls);
	Py_XDECREF(HdlStmForCls);
	Py_XDECREF(HdlStmForInCls);
	Py_XDECREF(HdlStmCaseCls);
	Py_XDECREF(HdlStmProcessCls);
	Py_XDECREF(HdlStmAssignCls);
	Py_XDECREF(HdlStmIfCls);
	Py_XDECREF(HdlOthersCls);
	Py_XDECREF(HdlAllCls);
	Py_XDECREF(HdlTypeAutoCls);
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
