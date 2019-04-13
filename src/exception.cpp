#include "exception.h"
#include <Python.h>

extern PyObject *parseExceptionerror;

void raise_py_error() {
	try {
		throw;
	}
	catch (parseException &e) {
		PyErr_SetString(parseExceptionerror, e.what());
	}
	catch (const std::exception &e) {
		PyErr_SetString(PyExc_RuntimeError, e.what());
	}
}
