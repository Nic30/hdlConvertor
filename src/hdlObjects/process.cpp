#include "process.h"

Process::Process() :
		Named(), sensitivity_list_specified(false) {
}

#ifdef USE_PYTHON
PyObject * Process::toJson() const {
	PyObject *d = PyDict_New();
	if (name)
		PyDict_SetItemString(d, "name", PyUnicode_FromString(name));
	if (sensitivity_list_specified)
		addJsonArrP(d, "sensitivity_list", sensitivity_list);

	addJsonArrP(d, "statements", statements);

	return d;
}
#endif

Process::~Process() {
	for (auto stm : statements)
		delete stm;
}
