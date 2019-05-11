#include "symbolType.h"

namespace hdlConvertor {
namespace hdlObjects {

LiteralVal LiteralVal_clone(const LiteralVal & val, enum SymbolType t) {
	LiteralVal v;
	switch (t) {
	case symb_ID:
	case symb_STRING:
		v._str = strdup(val._str);
		assert(v._str);
		break;
	case symb_INT:
		v._int = val._int;
		assert(v._int);
		Py_INCREF(v._int);
		break;
	case symb_FLOAT:
		v._float = val._float;
		break;
	case symb_OPEN:
	case symb_ARRAY:
	case symb_ALL:
	case symbol_T:
	default:
		v._str = NULL;
		break;
	}
	return v;
}

}
}
