#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <assert.h>

#include "bigInteger.h"
#include "symbolType.h"
#include "operatorType.h"
#include "exprItem.h"
#include "../debugConfig.h"

class Expr {
public:
	ExprItem * data;
	Expr();

	Expr(Expr * op0, OperatorType operatorType, Expr * op1);
	Expr(SymbolType type, LiteralVal value);
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
	static Expr * ternary(Expr * cond, Expr * ifTrue, Expr * ifFalse);
	static Expr * call(Expr * fnId, std::vector<Expr*> * operands);

	static Expr * OPEN();
	static Expr * all();
	static Expr * null();
	char * extractStr();
#ifdef USE_PYTHON
	PyObject * toJson() const;
#endif
	void dump(int indent) const;
	~Expr();
};
