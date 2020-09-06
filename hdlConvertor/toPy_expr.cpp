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

PyObject* ToPy::toPy(const iHdlExprItem *o) {
	auto c = dynamic_cast<const HdlOp*>(o);
	if (c)
		return toPy(c);
	auto va = dynamic_cast<const HdlValueArr*>(o);
	if (va)
		return toPy(va);
	auto vf = dynamic_cast<const HdlValueFloat*>(o);
	if (vf)
		return toPy(vf);
	auto vi = dynamic_cast<const HdlValueId*>(o);
	if (vi)
		return toPy(vi);
	auto vint = dynamic_cast<const HdlValueInt*>(o);
	if (vint)
		return toPy(vint);
	auto vs = dynamic_cast<const HdlValueStr*>(o);
	if (vs)
		return toPy(vs);
	auto vsymb = dynamic_cast<const HdlValueSymbol*>(o);
	if (vsymb)
		return toPy(vsymb);
	auto cls = dynamic_cast<const HdlClassDef*>(o);
	if (cls)
		return toPy(cls);
    auto pd = dynamic_cast<const HdlPhysicalDef*>(o);
	if (pd)
		return toPy(pd);
	auto ed = dynamic_cast<const HdlEnumDef*>(o);
	if (ed)
		return toPy(ed);
	auto vni = dynamic_cast<const HdlExprNotImplemented*>(o);
	if (vni)
		return toPy(vni);

	std::string err_msg;
	if (o)
		err_msg = std::string("ToPy::toPy unknown type of iHdlExprItem:")
				+ std::string(typeid(*o).name());
	else
		err_msg = "ToPy::toPy called for nullptr";
	PyErr_SetString(PyExc_ValueError, err_msg.c_str());
	return nullptr;
}

PyObject* ToPy::toPy(const HdlValueId *o) {
	assert(!o->_str.empty());
	auto v = PyUnicode_FromString(o->_str.c_str());
	if (!v)
		return nullptr;
	return PyObject_CallFunctionObjArgs(HdlValueIdCls, v, NULL);
}

PyObject* ToPy::toPy(const HdlValueInt *o) {
	auto &_v = o->_int;
	PyObject *v, *bits, *base = nullptr;
	if (_v.is_bitstring()) {
		v = PyUnicode_FromString(_v.bitstring.c_str());
	} else {
		v = PyLong_FromLong(_v.val);
	}
	if (!v)
		return nullptr;
	if (_v.is_bitstring()) {
		base = PyLong_FromLong(_v.bitstring_base);
		if (!base) {
			Py_DECREF(v);
			return nullptr;
		}
	} else {
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

	return PyObject_CallFunctionObjArgs(HdlValueIntCls, v, bits, base, NULL);
}

PyObject* ToPy::toPy(const HdlValueFloat *o) {
	return PyFloat_FromDouble(o->_float);
}

PyObject* ToPy::toPy(const HdlValueStr *o) {
	return PyUnicode_FromString(o->_str.c_str());
}

PyObject* ToPy::toPy(const HdlValueArr *o) {
	assert(o->_arr);
	auto val = PyList_New(o->_arr->size());
	if (!val)
		return nullptr;
	size_t indx = 0;
	for (auto &elem : *o->_arr) {
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
}

PyObject* ToPy::toPy(const HdlValueSymbol *o) {
	switch (o->symb) {
	case HdlValueSymbol_t::symb_OPEN:
		Py_RETURN_NONE;
	case HdlValueSymbol_t::symb_ALL:
		Py_INCREF(HdlAllCls);
		return HdlAllCls;
	case HdlValueSymbol_t::symb_NULL:
		Py_RETURN_NONE;
	case HdlValueSymbol_t::symb_T:
		Py_INCREF(HdlTypeTypeCls);
		return HdlTypeTypeCls;
	case HdlValueSymbol_t::symb_T_AUTO:
		Py_INCREF(HdlTypeAutoCls);
		return HdlTypeAutoCls;
	case HdlValueSymbol_t::symb_T_SUBTYPE:
		Py_INCREF(HdlTypeSubtypeCls);
		return HdlTypeSubtypeCls;
	case HdlValueSymbol_t::symb_OTHERS:
		Py_INCREF(HdlOthersCls);
		return HdlOthersCls;
	default:
		PyErr_SetString(PyExc_AssertionError, "invalid type of the HdlValue");
		return nullptr;
	}
}

PyObject* ToPy::toPy(const HdlExprNotImplemented *o) {
	PyObject *py_inst = PyObject_CallObject(HdlExprNotImplementedCls, NULL);
	if (py_inst == nullptr)
		return nullptr;
	if (toPy(static_cast<const WithPos*>(o), py_inst))
		return nullptr;
	return py_inst;
}

PyObject* ToPy::toPy(const HdlOpType o) {
	const char *name;
	try {
		name = HdlOpType_toString(o);
	} catch (const std::runtime_error &e) {
		PyErr_SetString(PyExc_ValueError, e.what());
		return nullptr;
	}
	return PyObject_GetAttrString(HdlOpTypeEnum, name);
}

}
