#pragma once

// antlr4-runtime/
#include <ParserRuleContext.h>

#include <hdlConvertor/hdlAst/hdlOpType.h>
#include <hdlConvertor/hdlAst/iHdlExprItem.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for call of HDL function or operator
 * */
class HdlOp: public virtual iHdlExprItem {
	HdlOp();
public:
	using ParserRuleContext = antlr4::ParserRuleContext;
	HdlOpType op;
	std::vector<std::unique_ptr<iHdlExprItem>> operands;

	HdlOp(const HdlOp &o);
	HdlOp(HdlOpType operatorType, std::unique_ptr<iHdlExprItem> op0);
	HdlOp(std::unique_ptr<iHdlExprItem> op0, HdlOpType operatorType,
			std::unique_ptr<iHdlExprItem> op1);

	// syntax sugar, named constructors
	static std::unique_ptr<HdlOp> call(std::unique_ptr<iHdlExprItem> fn,
			std::vector<std::unique_ptr<iHdlExprItem>> &operands);
	static std::unique_ptr<HdlOp> parametrization(
			std::unique_ptr<iHdlExprItem> fn,
			std::vector<std::unique_ptr<iHdlExprItem>> &args);
	static std::unique_ptr<HdlOp> ternary(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlExprItem> ifTrue,
			std::unique_ptr<iHdlExprItem> ifFalse);

	// syntax sugar, named constructors with code position set
	static std::unique_ptr<HdlOp> ternary(ParserRuleContext *ctx,
			std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlExprItem> ifTrue,
			std::unique_ptr<iHdlExprItem> ifFalse);
	static std::unique_ptr<HdlOp> call(ParserRuleContext *ctx,
			std::unique_ptr<iHdlExprItem> fnId,
			std::vector<std::unique_ptr<iHdlExprItem>> &args);
	static std::unique_ptr<HdlOp> parametrization(
			ParserRuleContext *ctx,
			std::unique_ptr<iHdlExprItem> fnId,
			std::vector<std::unique_ptr<iHdlExprItem>> &args);

	virtual iHdlExprItem * clone() const override;
	virtual ~HdlOp() override;
};

}
}
