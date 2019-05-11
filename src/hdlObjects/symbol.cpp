#include "symbol.h"

namespace hdlConvertor {
namespace hdlObjects {

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


}
}
