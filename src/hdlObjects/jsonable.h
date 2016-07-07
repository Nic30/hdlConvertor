#pragma once

#include <vector>
#include <iostream>
#include "../debugConfig.h"

#define INDENT_INCR 2

#ifdef USE_PYTHON
PyObject * addJsonArr_empty(PyObject * parent, const char * name);

template<typename T>
void addJsonArrP(
		PyObject * parent,
		const char * name,
		std::vector<T> const & objects) {
	PyObject * objList = PyList_New(objects.size());

	for (unsigned i = 0; i < objects.size(); i++) {
		auto _o = objects[i];
		assert(_o);
		PyObject * o = _o->toJson();
		PyList_SetItem(objList, i, o);
	}
	Py_IncRef(objList);
	PyDict_SetItemString(parent, name, objList);
}
#endif

inline std::ostream& mkIndent(int indent) {
	for (int i = 0; i < indent; i++) {
		std::cout << ' ';
	}
	return std::cout;
}

inline std::ostream & dumpKey(const char * key, int indent) {
	return mkIndent(indent) << "\"" << key << "\":";
}

template<typename T>
std::ostream & dumpVal(const char * key, int indent, T val) {
	return dumpKey(key, indent) << "\"" << val << "\"";
}

template<typename T>
std::ostream & dumpArrP(
		const char * name,
		int indent,
		std::vector<T> const & objects) {
	dumpKey(name, indent) << "[";
	indent += INDENT_INCR;
	for (auto it : objects) {
		mkIndent(indent);
		it->dump(indent);
		std::cout << ",\n";
	}
	mkIndent(indent - INDENT_INCR);
	std::cout << "]";
	return std::cout;
}

template<typename T>
std::ostream & dumpItemP(const char * name, int indent, T const & object) {
	mkIndent(indent) << "\"" << name << "\":";
	object->dump(indent);
	return std::cout;
}
