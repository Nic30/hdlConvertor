#pragma once

#include <string.h>
#include "debugConfig.h"
#include "langue.h"

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#ifdef USE_PYTHON
#include <Python.h>


#if PY_MAJOR_VERSION < 3
#error "This module is python3.x only"
#endif

EXTERNC PyObject *
hdlConvertor_parse(PyObject *self, PyObject *args, PyObject *keywds);
PyMODINIT_FUNC PyInit_hdlConvertor(void);
#endif
