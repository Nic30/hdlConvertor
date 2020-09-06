#include "toPy.h"

#include <typeinfo>
#include <iterator>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>

#include <hdlConvertor/hdlAst/bigInteger.h>
#include <hdlConvertor/hdlAst/hdlDirection.h>
#include <hdlConvertor/hdlAst/hdlValue.h>
#include <hdlConvertor/conversion_exception.h>

namespace hdlConvertor {

using namespace hdlAst;

ToPy::ToPy() {
	hdlAst_module = PyImport_ImportModule("hdlConvertorAst.hdlAst");
	if (hdlAst_module == nullptr) {
		// this could happen only if there are missing files in library
		PyErr_Print();
		throw std::runtime_error("can not import hdlConvertorAst.hdlAst");
	}
	auto import = [this](PyObject *&obj, const std::string &name) {
		obj = PyObject_GetAttrString(hdlAst_module, name.c_str());
		assert(obj != NULL && "hdlConvertorAst.hdlAst not as expected from hdlConvertor");
	};
	import(ContextCls, "HdlContext");
	import(CodePositionCls, "CodePosition");
	import(HdlModuleDefCls, "HdlModuleDef");
	import(HdlModuleDecCls, "HdlModuleDec");
	import(HdlIdDefCls, "HdlIdDef");
	import(HdlOpCls, "HdlOp");
	import(HdlOpTypeEnum, "HdlOpType");
	import(HdlValueIntCls, "HdlValueInt");
	import(HdlExprNotImplementedCls, "HdlExprNotImplemented");
	import(HdlValueIdCls, "HdlValueId");
	import(HdlDirectionEnum, "HdlDirection");
	import(HdlAllCls, "HdlAll");
	import(HdlOthersCls, "HdlOthers");
	import(HdlTypeAutoCls, "HdlTypeAuto");
	import(HdlTypeTypeCls, "HdlTypeType");
	import(HdlTypeSubtypeCls, "HdlTypeSubtype");
	import(HdlClassTypeEnum, "HdlClassType");
	import(HdlClassDefCls, "HdlClassDef");
	import(HdlPhysicalDefCls, "HdlPhysicalDef");
	import(HdlEnumDefCls, "HdlEnumDef");
	import(HdlStmIfCls, "HdlStmIf");
	import(HdlStmAssignCls, "HdlStmAssign");
	import(HdlStmProcessCls, "HdlStmProcess");
	import(HdlStmCaseTypeEnum, "HdlStmCaseType");
	import(HdlStmCaseCls, "HdlStmCase");
	import(HdlStmForCls, "HdlStmFor");
	import(HdlStmForInCls, "HdlStmForIn");
	import(HdlStmWhileCls, "HdlStmWhile");
	import(HdlStmReturnCls, "HdlStmReturn");
	import(HdlStmRepeatCls, "HdlStmRepeat");
	import(HdlStmBreakCls, "HdlStmBreak");
	import(HdlStmContinueCls, "HdlStmContinue");
	import(HdlStmWaitCls, "HdlStmWait");
	import(HdlStmBlockJoinTypeCls, "HdlStmBlockJoinType");
	import(HdlStmBlockCls, "HdlStmBlock");
	import(HdlLibraryCls, "HdlLibrary");
	import(HdlImportCls, "HdlImport");
	import(HdlCompInstCls, "HdlCompInst");
	import(HdlFunctionDefCls, "HdlFunctionDef");
	import(HdlValueIdspaceCls, "HdlValueIdspace");
}

std::string ToPy::PyObject_repr(PyObject *o) {
	PyObject *args = Py_BuildValue("(O)", PyObject_Repr(o));
	if (!args)
		return "";
	const char *s = nullptr;
	if (!PyArg_ParseTuple(args, "s", &s)) {
		Py_DECREF(args);
		return "";
	}
	std::string ret = s;
	Py_DECREF(args);
	return ret;
}

PyObject* ToPy::toPy(const HdlContext *o) {
	PyObject *py_inst = PyObject_CallObject(ContextCls, NULL);
	if (!py_inst)
		return nullptr;
	if (toPy_arr(py_inst, "objs", o->objs)) {
		return nullptr;
	}
	return py_inst;
}

PyObject* ToPy::toPy(const HdlLibrary *o) {
	Py_INCREF(Py_None);
	PyObject *py_inst = PyObject_CallFunctionObjArgs(HdlLibraryCls, Py_None,
	NULL);
	if (!py_inst)
		return nullptr;
	if (toPy(static_cast<const WithNameAndDoc*>(o), py_inst))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const iHdlObj *o) {
	auto ex = dynamic_cast<const iHdlExprItem*>(o);
	if (ex)
		return toPy(ex);
	auto fn = dynamic_cast<const HdlFunctionDef*>(o);
	if (fn)
		return toPy(fn);
	auto v = dynamic_cast<const HdlIdDef*>(o);
	if (v)
		return toPy(v);
	auto s = dynamic_cast<const iHdlStatement*>(o);
	if (s)
		return toPy(s);
	auto md = dynamic_cast<const HdlModuleDec*>(o);
	if (md)
		return toPy(md);
	auto mdef = dynamic_cast<const HdlModuleDef*>(o);
	if (mdef)
		return toPy(mdef);
	auto ci = dynamic_cast<const HdlCompInst*>(o);
	if (ci)
		return toPy(ci);
	auto ns = dynamic_cast<const HdlValueIdspace*>(o);
	if (ns)
		return toPy(ns);
	auto lib = dynamic_cast<const HdlLibrary*>(o);
	if (lib)
		return toPy(lib);
	auto c = dynamic_cast<const HdlContext*>(o);
	if (c)
		return toPy(c);

	std::string err_msg;
	if (o)
		err_msg = std::string("ToPy::toPy unknown type of iHdlObj:")
				+ std::string(typeid(*o).name());
	else
		err_msg = "ToPy::toPy called for nullptr";
	PyErr_SetString(PyExc_ValueError, err_msg.c_str());
	return nullptr;
}

int ToPy::toPy(const WithNameAndDoc *o, PyObject *py_inst) {
	if (!o) {
		PyErr_SetString(PyExc_ValueError, "ToPy::toPy invalid WithNameAndDoc*");
		Py_DECREF(py_inst);
		return -1;
	}
	int e;
	if (o->name.size()) {
		if (toPy_property(py_inst, "name", o->name))
			return -1;
	}
	e = toPy(static_cast<const WithDoc*>(o), py_inst);
	if (e < 0)
		return e;
	return toPy(static_cast<const WithPos*>(o), py_inst);
}

int ToPy::toPy(const WithDoc *o, PyObject *py_inst) {
	if (o->__doc__.size())
		if (toPy_property(py_inst, "doc", o->__doc__))
			return -1;
	return 0;
}

int ToPy::toPy(const WithPos *o, PyObject *py_inst) {
	if (toPy_property(py_inst, "position", o->position))
		return -1;
	return 0;
}

PyObject* ToPy::toPy(const CodePosition o) {
	PyObject *py_inst = PyObject_CallObject(CodePositionCls, NULL);
	if (!py_inst)
		return nullptr;
	if (toPy_property(py_inst, "start_line", o.start_line))
		return nullptr;
	if (toPy_property(py_inst, "start_column", o.start_column))
		return nullptr;
	if (toPy_property(py_inst, "stop_line", o.stop_line))
		return nullptr;
	if (toPy_property(py_inst, "stop_column", o.stop_column))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const HdlModuleDef *o) {
	PyObject *py_inst = PyObject_CallObject(HdlModuleDefCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	if (toPy(static_cast<const WithNameAndDoc*>(o), py_inst))
		return nullptr;
	if (o->module_name) {
		if (toPy_property(py_inst, "module_name", o->module_name))
			return nullptr;
	}
	if (o->dec) {
		if (toPy_property(py_inst, "dec", o->dec))
			return nullptr;
	}
	if (toPy_arr(py_inst, "objs", o->objs))
		return nullptr;

	return py_inst;
}

PyObject* ToPy::toPy(const hdlAst::HdlCompInst *o) {
	PyObject *py_inst = PyObject_CallObject(HdlCompInstCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	if (toPy_property(py_inst, "name", o->name))
		return nullptr;
	if (toPy_property(py_inst, "module_name", o->module_name))
		return nullptr;
	if (toPy_arr(py_inst, "param_map", o->genericMap))
		return nullptr;
	if (toPy_arr(py_inst, "port_map", o->portMap))
		return nullptr;

	return py_inst;
}

PyObject* ToPy::toPy(const HdlModuleDec *o) {
	PyObject *py_inst = PyObject_CallObject(HdlModuleDecCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	int e = toPy(static_cast<const WithNameAndDoc*>(o), py_inst);
	if (e)
		return nullptr;

	if (toPy_arr(py_inst, "params", o->generics))
		return nullptr;

	if (toPy_arr(py_inst, "ports", o->ports))
		return nullptr;

	if (toPy_arr(py_inst, "objs", o->objs))
		return nullptr;

	return py_inst;
}

PyObject* ToPy::toPy(const HdlFunctionDef *o) {
	PyObject *py_inst = PyObject_CallObject(HdlFunctionDefCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	if (toPy(static_cast<const WithNameAndDoc*>(o), py_inst))
		return nullptr;
	if (toPy_property(py_inst, "is_declaration_only", o->is_declaration_only))
		return nullptr;
	if (toPy_property(py_inst, "is_operator", o->is_operator))
		return nullptr;
	if (toPy_property(py_inst, "is_static", o->is_static))
		return nullptr;
	if (toPy_property(py_inst, "is_task", o->is_task))
		return nullptr;
	if (toPy_property(py_inst, "is_virtual", o->is_virtual))
		return nullptr;
	if (o->params) {
		if (toPy_arr(py_inst, "params", *o->params))
			return nullptr;
	}
	if (o->returnT) {
		if (toPy_property(py_inst, "return_t", o->returnT))
			return nullptr;
	}
	if (toPy_arr(py_inst, "body", o->body))
		return nullptr;

	return py_inst;
}

PyObject* ToPy::toPy(const HdlDirection o) {
	const char *name;
	try {
		name = HdlDirection_toString(o);
	} catch (const std::runtime_error &e) {
		PyErr_SetString(PyExc_ValueError, e.what());
		return nullptr;
	}
	return PyObject_GetAttrString(HdlDirectionEnum, name);
}

PyObject* ToPy::toPy(const HdlOp *o) {
	auto fn = toPy(o->op);
	if (!fn) {
		return nullptr;
	}
	auto ops = PyList_New(0);
	if (!ops) {
		Py_DECREF(fn);
		return nullptr;
	}
	if (toPy_arr(ops, o->operands)) {
		Py_DECREF(fn);
		return nullptr;
	}

	return PyObject_CallFunctionObjArgs(HdlOpCls, fn, ops, NULL);
}

// [TODO] too similar with the code for HdlModuleDef
PyObject* ToPy::toPy(const HdlValueIdspace *o) {
	PyObject *py_inst = PyObject_CallObject(HdlValueIdspaceCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	if (toPy(static_cast<const WithNameAndDoc*>(o), py_inst))
		return nullptr;
	if (toPy_arr(py_inst, "objs", o->objs))
		return nullptr;

	auto dec_only = PyBool_FromLong(o->defs_only);
	if (!dec_only) {
		Py_DECREF(py_inst);
		return nullptr;
	}

	if (PyObject_SetAttrString(py_inst, "declaration_only", dec_only)) {
		Py_DECREF(py_inst);
		Py_DECREF(dec_only);
		return nullptr;
	}

	return py_inst;
}

PyObject* ToPy::toPy(const HdlIdDef *o) {
	PyObject *py_inst = PyObject_CallObject(HdlIdDefCls, NULL);
	if (!py_inst)
		return nullptr;
	if (toPy(static_cast<const WithNameAndDoc*>(o), py_inst))
		return nullptr;

	if (toPy_property(py_inst, "type", o->type))
		return nullptr;
	if (o->value) {
		if (toPy_property(py_inst, "value", o->value))
			return nullptr;
	} // else let it to be None
	if (toPy_property(py_inst, "is_latched", o->is_latched))
		return nullptr;
	if (toPy_property(py_inst, "is_const", o->is_const))
		return nullptr;
	if (toPy_property(py_inst, "is_static", o->is_static))
		return nullptr;
	if (toPy_property(py_inst, "direction", o->direction))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(size_t o) {
	if (o == std::numeric_limits<size_t>::max()) {
		Py_RETURN_NONE;
	} else {
		return PyLong_FromLong((long) o);
	}
}

PyObject* ToPy::toPy(bool o) {
	return PyBool_FromLong((long) o);
}

PyObject* ToPy::toPy(const std::string &o) {
	return PyUnicode_FromString(o.c_str());
}

ToPy::~ToPy() {
	Py_XDECREF(HdlValueIdspaceCls);
	Py_XDECREF(HdlFunctionDefCls);
	Py_XDECREF(HdlCompInstCls);
	Py_XDECREF(HdlImportCls);
	Py_XDECREF(HdlLibraryCls);
	Py_XDECREF(HdlStmBlockCls);
	Py_XDECREF(HdlStmBlockJoinTypeCls);
	Py_XDECREF(HdlStmWaitCls);
	Py_XDECREF(HdlStmContinueCls);
	Py_XDECREF(HdlStmBreakCls);
	Py_XDECREF(HdlStmReturnCls);
	Py_XDECREF(HdlStmRepeatCls);
	Py_XDECREF(HdlStmWhileCls);
	Py_XDECREF(HdlStmForCls);
	Py_XDECREF(HdlStmForInCls);
	Py_XDECREF(HdlStmCaseCls);
	Py_XDECREF(HdlStmCaseTypeEnum);
	Py_XDECREF(HdlStmProcessCls);
	Py_XDECREF(HdlStmAssignCls);
	Py_XDECREF(HdlStmIfCls);
	Py_XDECREF(HdlOthersCls);
	Py_XDECREF(HdlAllCls);
	Py_XDECREF(HdlPhysicalDefCls);
	Py_XDECREF(HdlEnumDefCls);
	Py_XDECREF(HdlClassDefCls);
	Py_XDECREF(HdlClassTypeEnum);
	Py_XDECREF(HdlTypeSubtypeCls);
	Py_XDECREF(HdlTypeTypeCls);
	Py_XDECREF(HdlTypeAutoCls);
	Py_XDECREF(HdlDirectionEnum);
	Py_XDECREF(HdlValueIdCls);
	Py_XDECREF(HdlExprNotImplementedCls);
	Py_XDECREF(HdlValueIntCls);
	Py_XDECREF(HdlOpTypeEnum);
	Py_XDECREF(HdlOpCls);
	Py_XDECREF(HdlIdDefCls);
	Py_XDECREF(HdlModuleDecCls);
	Py_XDECREF(HdlModuleDefCls);
	Py_XDECREF(CodePositionCls);
	Py_XDECREF(ContextCls);
	Py_XDECREF(hdlAst_module);
}

const char* get_cpp_py_error_message() {
	try {
		throw;
	} catch (const ParseException &e) {
		return e.what();
	} catch (const std::exception &e) {
		return e.what();
	}
	return "<unknown C++ exception>";
}

}
