#pragma once

// antlr4-runtime/
#include <ParserRuleContext.h>

#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExprItem.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for call of HDL function or operator
 * */
class HdlCall: public virtual iHdlExprItem {
	HdlCall();
public:
	using ParserRuleContext = antlr4::ParserRuleContext;
	HdlOperatorType op;
	std::vector<std::unique_ptr<iHdlExprItem>> operands;

	HdlCall(const HdlCall &o);
	HdlCall(HdlOperatorType operatorType, std::unique_ptr<iHdlExprItem> op0);
	HdlCall(std::unique_ptr<iHdlExprItem> op0, HdlOperatorType operatorType,
			std::unique_ptr<iHdlExprItem> op1);

	// syntax sugar, named constructors
	static std::unique_ptr<HdlCall> call(std::unique_ptr<iHdlExprItem> fn,
			std::vector<std::unique_ptr<iHdlExprItem>> &operands);
	static std::unique_ptr<HdlCall> parametrization(
			std::unique_ptr<iHdlExprItem> fn,
			std::vector<std::unique_ptr<iHdlExprItem>> &args);
	static std::unique_ptr<HdlCall> ternary(std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlExprItem> ifTrue,
			std::unique_ptr<iHdlExprItem> ifFalse);

	// syntax sugar, named constructors with code position set
	static std::unique_ptr<HdlCall> ternary(ParserRuleContext *ctx,
			std::unique_ptr<iHdlExprItem> cond,
			std::unique_ptr<iHdlExprItem> ifTrue,
			std::unique_ptr<iHdlExprItem> ifFalse);
	static std::unique_ptr<HdlCall> call(ParserRuleContext *ctx,
			std::unique_ptr<iHdlExprItem> fnId,
			std::vector<std::unique_ptr<iHdlExprItem>> &args);
	static std::unique_ptr<HdlCall> parametrization(
			ParserRuleContext *ctx,
			std::unique_ptr<iHdlExprItem> fnId,
			std::vector<std::unique_ptr<iHdlExprItem>> &args);

	virtual iHdlExprItem * clone() const override;
	virtual ~HdlCall() override;
};

}
}
