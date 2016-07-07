#include "jsonable.h"


#ifdef USE_PYTHON
PyObject * addJsonArr_empty(PyObject * parent, const char * name) {
	PyObject * objList = PyList_New(0);
	PyDict_SetItem(parent, PyUnicode_FromString(name), objList);
	Py_IncRef(objList);
	return objList;
}
#endif
