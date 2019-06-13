#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <assert.h>

#include <hdlConvertor/hdlObjects/bigInteger.h>
#include <hdlConvertor/hdlObjects/operatorType.h>
#include <hdlConvertor/hdlObjects/exprItem.h>
#include <hdlConvertor/hdlObjects/literalVal.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include "literalVal.h"

namespace hdlConvertor {
namespace hdlObjects {

class Expr: public WithPos, public iHdlObj {
public:
	ExprItem * data;

	Expr();
	// @note deepcopy
	Expr(const Expr & expr);

	Expr(OperatorType operatorType, Expr * op0);
	Expr(Expr * op0, OperatorType operatorType, Expr * op1);
	Expr(const LiteralVal & value);
	Expr(LiteralVal * value);
	Expr(const BigInteger & value, int bits);
	Expr(const BigInteger & value);

	static Expr * ID(const std::string & value);

	static Expr * TYPE_T();

	static Expr * INT(int64_t val);
	static Expr * INT(const std::string& strVal, int base);
	static Expr * INT(const std::string& strVal, int bits, int base);

	static Expr * FLOAT(double val);
	static Expr * STR(std::string strVal);
	static Expr * ARRAY(const std::vector<Expr*> & arr);
	static Expr * ternary(Expr * cond, Expr * ifTrue, Expr * ifFalse);
	static Expr * call(Expr * fnId, const std::vector<Expr*> & operands);
	static Expr * slice(Expr * fnId, const std::vector<Expr*> & operands);

	static Expr * OPEN();
	static Expr * all();
	static Expr * null();
	static Expr * others();

	// @return id of the variable string if this Expr is string value
	const std::string & extractStr() const;

	~Expr();
};

}
}
