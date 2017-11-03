#include "symbol.h"

Symbol::Symbol(SymbolType type, LiteralVal value) {
	this->type = type;
	this->value = value;
	bits = -1;
	value_arr = NULL;
}

Symbol::Symbol(BigInteger value, int bits) {
	type = symb_INT;
	this->value._int = value;
	this->bits = bits;
	value_arr = NULL;
}

Symbol::Symbol(const std::vector<Symbol> * arr) {
	type = symb_ARRAY;
	value._str = NULL;
	bits = -1;
	value_arr = arr;
}

Symbol::~Symbol() {

	switch (type) {
#ifdef USE_PYTHON
	case symb_INT:
		if (value._int)
			Py_DECREF(value._int);
		break;
	case symb_ARRAY:
		if (value_arr)
			delete value_arr;
		break;
#endif
	case symb_ID:
	case symb_STRING:
		if (value._str)
			free((char *) value._str);
		break;
	default:
		break;
	}
}

#ifdef USE_PYTHON
PyObject * Symbol::toJson() const {
	PyObject * d = PyDict_New();
	PyObject * tmp = NULL;
	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(SymbolType_toString(type)));

	PyObject * val = NULL;
	size_t indx = 0;

	switch (type) {
	case symb_ID:
	case symb_STRING:
		assert(value._str);
		val = PyUnicode_FromString(value._str);
		break;
	case symb_FLOAT:
		val = PyFloat_FromDouble(value._float);
		break;
	case symb_INT:
		val = value._int;
		if (bits > 0)
			Py_IncRef(val);
		PyDict_SetItemString(d, "bits", PyLong_FromLong(bits));
		break;
	case symb_ARRAY:
		assert(value_arr);
		val = PyList_New(value_arr->size());
		for (auto symb : *value_arr) {
			tmp = symb.toJson();
			Py_IncRef(tmp);
			PyList_SetItem(val, indx, tmp);
			indx++;
		}
		break;
	case symb_OPEN:
	default:
		val = Py_None;
		Py_INCREF(val);
		break;
	}
	if (!val) {
		val = Py_None;
		Py_INCREF(val);
	}
	PyDict_SetItemString(d, "value", val);
	return d;
}
#endif

Symbol::Symbol(const Symbol & s) {
	bits = s.bits;
	type = s.type;
	value = LiteralVal_clone(s.value, s.type);
	if (s.value_arr) {
		value_arr = new std::vector<Symbol>(*s.value_arr);
	} else {
		value_arr = NULL;
	}
}
ExprItem * Symbol::clone() const {
	return new Symbol(*this);
}

void Symbol::dump(int indent) const {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpVal("type", indent, SymbolType_toString(type)) << ",\n";
	const char * _v;

	switch (type) {
	case symb_ID:
	case symb_STRING:
		dumpVal("value", indent, value._str) << "\n";
		break;
	case symb_FLOAT:
		dumpVal("value", indent, value._float) << "\n";
		break;
	case symb_ARRAY:
		assert(0 && "not implemented");
		break;
	case symb_INT:
		if (bits > 0)
			dumpVal("bits", indent, bits) << ",\n";
#ifdef USE_PYTHON
		_v = PyUnicode_AsUTF8(PyObject_Str(value._int));
#else
		_v = std::to_string(value._int).c_str();
#endif
		dumpVal("value", indent, _v) << "\n";
		break;
	case symb_ALL:
	case symb_OPEN:
	default:
		break;
	}
	mkIndent(indent - INDENT_INCR) << "}";
}
