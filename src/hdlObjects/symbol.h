#pragma once

#include <stdlib.h>
#include "jsonable.h"
#include "bigInteger.h"
#include "symbolType.h"
#include "exprItem.h"

class Symbol: public virtual ExprItem {
public:
	SymbolType type;
	int bits;
	LiteralVal value;
	const std::vector<Symbol> * value_arr;

	Symbol(const Symbol & s);
	Symbol(SymbolType type, LiteralVal value);
	Symbol(BigInteger value, int bits);
	Symbol(const std::vector<Symbol> * arr);

#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	ExprItem * clone() const;

	~Symbol();
};
