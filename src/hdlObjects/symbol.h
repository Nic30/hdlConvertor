#pragma once
#include "jsonable.h"
#include "bigInteger.h"
#include "symbolType.h"
#include "exprItem.h"

class Symbol: public virtual ExprItem {
public:
	SymbolType type;
	int bits;
	LiteralVal value;

	Symbol(SymbolType type, LiteralVal value);
	Symbol(BigInteger value, int bits);
	PyObject * toJson() const;
	void dump(int indent) const;

	~Symbol();
};
