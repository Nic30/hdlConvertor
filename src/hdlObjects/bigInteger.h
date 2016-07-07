#pragma once

#include <string>
#include "../debugConfig.h"

#ifdef USE_PYTHON
typedef PyObject * BigInteger;
#else
typedef long long int BigInteger;
#endif

inline BigInteger BigInteger_fromStr(const char * str, int base) {
#ifdef USE_PYTHON
	auto v = PyLong_FromString((char *)str, NULL, base);
	return v;
#else
	return atoi(str);
#endif
}
inline BigInteger BigInteger_fromStr(std::string str, int base) {
	return BigInteger_fromStr(str.c_str(), base);
}
inline BigInteger BigInteger_fromLong(long long val) {
#ifdef USE_PYTHON
	return PyLong_FromLongLong(val);
#else
	return val;
#endif
}
