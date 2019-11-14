#pragma once

#include <vector>
#include <string>
#include <memory>

#include <hdlConvertor/hdlObjects/bigInteger.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExprItem.h>
#include <hdlConvertor/hdlObjects/hdlValue.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace antlr4
{
	class ParserRuleContext;
	namespace tree
	{
		class TerminalNode;
	}
}

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
	using TerminalNode = antlr4::tree::TerminalNode;
	using ParserRuleContext = antlr4::ParserRuleContext;

	iHdlExprItem *data;

	iHdlExpr();
	// @note deepcopy
	iHdlExpr(const iHdlExpr &expr);

	iHdlExpr(HdlOperatorType operatorType, std::unique_ptr<iHdlExpr> op0);
	iHdlExpr(std::unique_ptr<iHdlExpr> op0, HdlOperatorType operatorType,
			std::unique_ptr<iHdlExpr> op1);
	iHdlExpr(const HdlValue &value);
	iHdlExpr(HdlValue *value);
	iHdlExpr(const BigInteger &value, int bits);
	iHdlExpr(const BigInteger &value);

	static std::unique_ptr<iHdlExpr> ID(const std::string &value);

	static std::unique_ptr<iHdlExpr> TYPE_T();
	static std::unique_ptr<iHdlExpr> AUTO_T();

	static std::unique_ptr<iHdlExpr> INT(TerminalNode *node, int64_t val);
	static std::unique_ptr<iHdlExpr> INT(TerminalNode *node, const std::string &strVal, int base);
	static std::unique_ptr<iHdlExpr> INT(TerminalNode *node, const std::string &strVal, int bits,
			int base);
	static std::unique_ptr<iHdlExpr> FLOAT(TerminalNode *node, double val);
	static std::unique_ptr<iHdlExpr> STR(TerminalNode *node, std::string strVal);
	static std::unique_ptr<iHdlExpr> ARRAY(ParserRuleContext *ctx,
			std::vector<std::unique_ptr<iHdlExpr>> &arr);
	static std::unique_ptr<iHdlExpr> ARRAY(ParserRuleContext *ctx,
			std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> arr);
	static std::unique_ptr<iHdlExpr> ternary(ParserRuleContext *ctx,
			std::unique_ptr<iHdlExpr> cond,
			std::unique_ptr<iHdlExpr> ifTrue,
			std::unique_ptr<iHdlExpr> ifFalse);
	static std::unique_ptr<iHdlExpr> call(ParserRuleContext *ctx,
			std::unique_ptr<iHdlExpr> fnId,
			std::vector<std::unique_ptr<iHdlExpr>> &args);
	static std::unique_ptr<iHdlExpr> parametrization(
			ParserRuleContext *ctx,
			std::unique_ptr<iHdlExpr> fnId,
			std::vector<std::unique_ptr<iHdlExpr>> &args);
	static std::unique_ptr<iHdlExpr> slice(
			ParserRuleContext *ctx,
			std::unique_ptr<iHdlExpr> fnId,
			std::vector<std::unique_ptr<iHdlExpr>> &operands);

	static std::unique_ptr<iHdlExpr> OPEN();
	static std::unique_ptr<iHdlExpr> all();
	static std::unique_ptr<iHdlExpr> null();
	static std::unique_ptr<iHdlExpr> others();

	~iHdlExpr();
};

}
}
