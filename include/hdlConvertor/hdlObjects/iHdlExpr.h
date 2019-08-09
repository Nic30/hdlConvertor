#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <assert.h>

#include <hdlConvertor/hdlObjects/bigInteger.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExprItem.h>
#include <hdlConvertor/hdlObjects/hdlValue.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for expressions
 *
 * @note iHdlExpr is not an interface yet but it is planed to make it an interface
 *     and get rid of iHdlExprItem
 */
class iHdlExpr: public WithPos, public iHdlObj {
public:
	iHdlExprItem * data;

	iHdlExpr();
	// @note deepcopy
	iHdlExpr(const iHdlExpr & expr);

	iHdlExpr(HdlOperatorType operatorType, iHdlExpr * op0);
	iHdlExpr(iHdlExpr * op0, HdlOperatorType operatorType, iHdlExpr * op1);
	iHdlExpr(const HdlValue & value);
	iHdlExpr(HdlValue * value);
	iHdlExpr(const BigInteger & value, int bits);
	iHdlExpr(const BigInteger & value);

	static iHdlExpr * ID(const std::string & value);

	static iHdlExpr * TYPE_T();
	static iHdlExpr * AUTO_T();

	static iHdlExpr * INT(int64_t val);
	static iHdlExpr * INT(const std::string& strVal, int base);
	static iHdlExpr * INT(const std::string& strVal, int bits, int base);

	static iHdlExpr * FLOAT(double val);
	static iHdlExpr * STR(std::string strVal);
	static iHdlExpr * ARRAY(const std::vector<iHdlExpr*> & arr);
	static iHdlExpr * ternary(iHdlExpr * cond, iHdlExpr * ifTrue, iHdlExpr * ifFalse);
	static iHdlExpr * call(iHdlExpr * fnId, const std::vector<iHdlExpr*> & args);
	static iHdlExpr * slice(iHdlExpr * fnId, const std::vector<iHdlExpr*> & operands);

	static iHdlExpr * OPEN();
	static iHdlExpr * all();
	static iHdlExpr * null();
	static iHdlExpr * others();

	// @return id of the variable string if this Expr is string value
	const std::string & extractStr() const;

	~iHdlExpr();
};

}
}
