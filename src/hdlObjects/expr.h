#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <assert.h>

#include "bigInteger.h"
#include "symbolType.h"
#include "operatorType.h"
#include "exprItem.h"
#include "symbol.h"
#include "named.h"

namespace hdlConvertor {
namespace hdlObjects {

class Expr: public WithPos {
public:
	ExprItem * data;

	Expr();
	// @note deepcopy
	Expr(const Expr & expr);

	Expr(Expr * op0, OperatorType operatorType, Expr * op1);
	Expr(SymbolType type, LiteralVal value);
	Expr(SymbolType type, Symbol * value);
	Expr(BigInteger value, int bits);
	Expr(BigInteger value);

	static Expr * ID(const char * value);
	static Expr * ID(std::string value);

	static Expr * TYPE_T();

	static Expr * INT(long long val);
	static Expr * INT(std::string strVal, int base);
	static Expr * INT(const char * strVal, int base);
	static Expr * INT(std::string strVal, int bits, int base);
	static Expr * INT(const char * strVal, int size, int base);

	static Expr * FLOAT(double val);
	static Expr * STR(std::string strVal);
	static Expr * ARRAY(std::vector<Expr*> arr);
	static Expr * ternary(Expr * cond, Expr * ifTrue, Expr * ifFalse);
	static Expr * call(Expr * fnId, std::vector<Expr*> * operands);
	static Expr * slice(Expr * fnId, std::vector<Expr*> * operands);

	static Expr * OPEN();
	static Expr * all();
	static Expr * null();

	// @return char* of the variable string if this Expr is string value
	char * extractStr();

	~Expr();
};

}
}
