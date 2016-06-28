#pragma once

#include <string.h>
#include <Python.h>
#include "debugConfig.h"

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

EXTERNC  PyObject *
hdlConvertor_parse(PyObject *self, PyObject *args, PyObject *keywds);
PyMODINIT_FUNC PyInit_hdlConvertor(void);
