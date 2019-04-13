#include "named.h"

Named::Named() {
	name = NULL;
}

#ifdef USE_PYTHON
PyObject * Named::toJson() const {
	PyObject *d = PyDict_New();
	if (name) {
		PyDict_SetItemString(d, "name", PyUnicode_FromString(name));
	}
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

#ifdef USE_PYTHON
PyObject * WithDoc::toJson() const {
	PyObject *d = PyDict_New();
	if (__doc__.size()) {
		PyDict_SetItemString(d, "__doc__",
				PyUnicode_FromString(__doc__.c_str()));
	}
	return d;
}
#endif

void WithDoc::dump(int indent) const {
	std::cout << "{\n";
	// [NOTE] .c_str() because of the msvc
	mkIndent(indent + INDENT_INCR) << "\"__doc__\":\"" << __doc__.c_str() << "\",\n";
}

WithNameAndDoc::WithNameAndDoc() :
		Named() {
}

#ifdef USE_PYTHON
PyObject * WithNameAndDoc::toJson() const {
	PyObject *d = PyDict_New();
	if (name) {
		PyDict_SetItemString(d, "name", PyUnicode_FromString(name));
	}
	if (__doc__.size()) {
		PyDict_SetItemString(d, "__doc__",
				PyUnicode_FromString(__doc__.c_str()));
	}
	return d;
}
#endif

void WithNameAndDoc::dump(int indent) const {
	std::cout << "{\n";
	mkIndent(indent + INDENT_INCR) << "\"name\":\"" << name << "\",\n";

	// [NOTE] .c_str() because of the msvc
	mkIndent(indent + INDENT_INCR) << "\"__doc__\":\"" << __doc__.c_str() << "\",\n";
}
