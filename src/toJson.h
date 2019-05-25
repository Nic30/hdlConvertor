#pragma once
#include <string>
#include "debugConfig.h"
#include "hdlObjects/aPackage.h"
#include "hdlObjects/arch.h"
#include "hdlObjects/compInstance.h"
#include "hdlObjects/context.h"
#include "hdlObjects/operator.h"
#include "hdlObjects/named.h"
#include "hdlObjects/process.h"
#include "hdlObjects/statement.h"
#include "hdlObjects/generate.h"

namespace hdlConvertor {

class ToJson {
#ifdef USE_PYTHON
	static PyObject * addJsonArr_empty(PyObject * parent, const char * name);

	template<typename T>
	static void addJsonArrP(PyObject * parent, const char * name,
			std::vector<T> const & objects) {
		PyObject * objList = PyList_New(objects.size());

		for (unsigned i = 0; i < objects.size(); i++) {
			auto _o = objects[i];
			assert(_o);
			PyObject * o = toJson(_o);
			PyList_SetItem(objList, i, o);
		}
		Py_IncRef(objList);
		PyDict_SetItemString(parent, name, objList);
	}
	static std::pair<PyObject *, size_t> cases_toJson(
			std::vector<hdlObjects::Expr*>::const_iterator cond_begin,
			std::vector<hdlObjects::Expr*>::const_iterator cond_end,
			std::vector<std::vector<hdlObjects::Statement*>*>::const_iterator stms_begin);

public:
	static void toJson(const hdlObjects::WithPos * o, PyObject *d);

	static PyObject * toJson(const hdlObjects::aPackage * p);
	static PyObject * toJson(const hdlObjects::Arch * p);
	static PyObject * toJson(const hdlObjects::CompInstance * ci);
	static PyObject * toJson(const hdlObjects::Context * c);
	static PyObject * toJson(const hdlObjects::Entity * c);
	static PyObject * toJson(const hdlObjects::Expr * e);
	static PyObject * toJson(const hdlObjects::Function * e);
	static PyObject * toJson(const hdlObjects::Named * n);
	static PyObject * toJson(const hdlObjects::WithDoc * wd);
	static PyObject * toJson(const hdlObjects::WithNameAndDoc * wnd);
	static PyObject * toJson(const hdlObjects::Process * p);
	static PyObject * toJson(const hdlObjects::Port * p);
	static PyObject * toJson(const hdlObjects::Statement * p);
	static PyObject * toJson(const hdlObjects::Symbol * p);
	static PyObject * toJson(const hdlObjects::Variable * p);
	static PyObject * toJson(const hdlObjects::Operator * p);
	static PyObject * toJson(const hdlObjects::Generate * o);
	static PyObject * toJson(const hdlObjects::Position * o);


#endif

};

}
