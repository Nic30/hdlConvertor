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

	Symbol(SymbolType type, LiteralVal value);
	Symbol(BigInteger value, int bits);
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;

	~Symbol();
};
