#pragma once

#include <vector>
#include "bigInteger.h"
#include "symbolType.h"
#include "exprItem.h"

namespace hdlConvertor {
namespace hdlObjects {

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

	ExprItem * clone() const;

	~Symbol();
};

}
}
