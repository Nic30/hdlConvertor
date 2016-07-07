#include "arch.h"

#ifdef USE_PYTHON
PyObject * Arch::toJson() const {
	PyObject * o = Named::toJson();
	JSN_DEBUG("Arch - name")
	PyDict_SetItemString(o, "name", PyUnicode_FromString(name));

	JSN_DEBUG("Arch - entityName")
	PyDict_SetItemString(o, "entityName", PyUnicode_FromString(entityName));

	JSN_DEBUG("Arch - componentInstances")
	addJsonArrP(o, "componentInstances", componentInstances);
	Py_INCREF(o);
	return o;
}
#endif
