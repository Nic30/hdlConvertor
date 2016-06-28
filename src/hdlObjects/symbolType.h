#pragma once

#include "bigInteger.h"

union LiteralVal {
	BigInteger _int;
	double _float;
	char * _str;
};

enum SymbolType {
	symb_ID, symb_INT, symb_FLOAT, symb_STRING, symb_OPEN, symb_ALL, symb_NULL, symbol_T
};

inline const char * SymbolType_toString(SymbolType t) {
	switch (t) {
	case symb_ID:
		return "ID";
	case symb_INT:
		return "INT";
	case symb_FLOAT:
		return "FLOAT";
	case symb_STRING:
		return "STRING";
	case symb_OPEN:
		return "OPEN";
	case symb_ALL:
		return "ALL";
	case symbol_T:
		return "TYPE";
	default:
		return "NULL";
	}
}
