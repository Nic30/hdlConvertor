#include "position.h"

Position::Position(size_t startLine, size_t stopLine, size_t startColumn, size_t stopColumn) {
	this->startLine = startLine;
	this->stopLine = stopLine;
	this->startColumn = startColumn;
	this->stopColumn = stopColumn;
}

#ifdef USE_PYTHON
PyObject * Position::toJson() const {
	PyObject *d = PyDict_New();

	if (startLine) {
		JSN_DEBUG("Position - startLine")
		PyDict_SetItemString(d, "startLine", PyLong_FromSize_t(startLine));
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "startLine", Py_None);
	}

	if (stopLine) {
		JSN_DEBUG("Position - stopLine")
		PyDict_SetItemString(d, "stopLine", PyLong_FromSize_t(stopLine));
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "stopLine", Py_None);
	}

	if (startColumn) {
		JSN_DEBUG("Position - startColumn")
		PyDict_SetItemString(d, "startColumn", PyLong_FromSize_t(startColumn));
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "startColumn", Py_None);
	}

	if (stopColumn) {
		JSN_DEBUG("Position - stopColumn")
		PyDict_SetItemString(d, "stopColumn", PyLong_FromSize_t(stopColumn));
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "stopColumn", Py_None);
	}
	
	return d;
}
#endif

void Position::dump(int indent) const {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}


Position::~Position() {
		     
}