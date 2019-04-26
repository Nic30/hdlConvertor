#include "exception.h"
#include <Python.h>

PyAPI_DATA(PyObject *) ParseExceptionT;

void raise_py_error() {
	try {
		throw;
	} catch (ParseException &e) {
		PyErr_SetString(ParseExceptionT, e.what());
	} catch (const std::exception &e) {
		PyErr_SetString(PyExc_RuntimeError, e.what());
	}
}
