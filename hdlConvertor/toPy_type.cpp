#include "toPy.h"

namespace hdlConvertor {

using namespace hdlObjects;

PyObject* ToPy::toPy(const HdlClassType o) {
	const char *name;
	try {
		name = HdlClassType_toString(o);
	} catch (const std::runtime_error &e) {
		PyErr_SetString(PyExc_ValueError, e.what());
		return nullptr;
	}
	return PyObject_GetAttrString(HdlClassTypeEnum, name);
}

PyObject* ToPy::toPy(const HdlClassDef *o) {
	PyObject *py_inst = PyObject_CallObject(HdlClassDefCls, NULL);
	if (!py_inst)
		return nullptr;
	if (toPy_property(py_inst, "type", o->type)) {
		return nullptr;
	}
	if (toPy_arr(py_inst, "members", o->members)) {
		return nullptr;
	}

	return py_inst;
}

PyObject* ToPy::toPy(const HdlEnumDef *o) {
	PyObject *py_inst = PyObject_CallObject(HdlEnumDefCls, NULL);
	if (!py_inst)
		return nullptr;
	return py_inst;
}

}
