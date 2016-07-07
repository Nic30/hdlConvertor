#include "named.h"


Named::Named() {
	name = NULL;
}

#ifdef USE_PYTHON
PyObject * Named::toJson() const {
	PyObject *d = PyDict_New();
	assert(name != NULL);
	PyDict_SetItemString(d, "name", PyUnicode_FromString(name));
	Py_IncRef(d);
	return d;
}
#endif

void Named::dump(int indent) const {
	std::cout << "{\n";
	mkIndent(indent + INDENT_INCR) << "\"name\":\"" << name << "\",\n";
}

Named::~Named() {
	free(name);
}
