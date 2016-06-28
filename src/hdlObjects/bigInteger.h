#pragma once
#include <Python.h>
#include <string>
#include <iostream>

typedef PyObject * BigInteger;

inline BigInteger BigInteger_fromStr(const char * str, int base) {
	auto v = PyLong_FromString(str, NULL, base);

	//PyTypeObject* type = v->ob_type;
	//const char* p = type->tp_name;
	//std::cout << "My type is " << p << std::endl;
    //
	//auto s = PyObject_Str(v);
	//std::cout << PyUnicode_AsUTF8(s) << "\n";
	return v;
}
inline BigInteger BigInteger_fromStr(std::string str, int base) {
	return PyLong_FromString(str.c_str(), NULL, base);
}
inline BigInteger BigInteger_fromLong(long long val) {
	BigInteger v = PyLong_FromLongLong(val);

	//PyTypeObject* type = v->ob_type;
	//const char* p = type->tp_name;
	//std::cout << "My type is " << p << std::endl;
    //
	//auto s = PyObject_Str(v);
	//std::cout << PyUnicode_AsUTF8(s) << "\n";

	return v;
}
