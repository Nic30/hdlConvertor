#include "symbol.h"

Symbol::Symbol(SymbolType type, LiteralVal value) {
	this->type = type;
	this->value = value;
	bits = -1;
}
Symbol::Symbol(BigInteger value, int bits) {
	type = symb_INT;
	this->value._int = value;
	this->bits = bits;
}
Symbol::~Symbol() {
	switch (type) {
	case symb_INT:
		free(value._int);
		break;
	case symb_ID:
	case symb_STRING:
		free((char *) value._str);
		break;
	default:
		break;
	}
}

PyObject * Symbol::toJson() const {
	PyObject * d = PyDict_New();

	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(SymbolType_toString(type)));

	PyObject * val;
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
			PyDict_SetItemString(d, "bits", PyLong_FromLong(bits));
		break;
	case symb_OPEN:
	default:
		val = Py_None;
		Py_INCREF(val);
		break;
	}
	PyDict_SetItemString(d, "value", val);
	Py_INCREF(d);
	return d;
}

void Symbol::dump(int indent) const {
	std::cout << "{\n";
	indent += INDENT_INCR;
	dumpVal("type", indent, SymbolType_toString(type)) << ",\n";
	char * _v;

	switch (type) {
	case symb_ID:
	case symb_STRING:
		dumpVal("value", indent, value._str) << "\n";
		break;
	case symb_FLOAT:
		dumpVal("value", indent, value._float) << "\n";
		break;
	case symb_INT:
		if (bits > 0)
			dumpVal("bits", indent, bits) << ",\n";
		_v = PyUnicode_AsUTF8(PyObject_Str(value._int));
		dumpVal("value", indent, _v) << "\n";
		break;
	case symb_ALL:
	case symb_OPEN:
	default:
		break;
	}
	mkIndent(indent - INDENT_INCR) << "}";
}
