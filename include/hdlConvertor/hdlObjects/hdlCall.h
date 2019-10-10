#pragma once

#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlExprItem.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for call of HDL function or operator
 * */
class HdlCall: public iHdlExprItem {
	HdlCall();
public:
	HdlOperatorType op;
	std::vector<std::unique_ptr<iHdlExpr>> operands;

	HdlCall(const HdlCall &o);
	HdlCall(HdlOperatorType operatorType, std::unique_ptr<iHdlExpr> op0);
	HdlCall(std::unique_ptr<iHdlExpr> op0, HdlOperatorType operatorType,
			std::unique_ptr<iHdlExpr> op1);

	static HdlCall* call(std::unique_ptr<iHdlExpr> fn,
			std::vector<std::unique_ptr<iHdlExpr>> &operands);
	static HdlCall* parametrization(std::unique_ptr<iHdlExpr> fn,
			std::vector<std::unique_ptr<iHdlExpr>> &operands);
	static HdlCall* slice(std::unique_ptr<iHdlExpr> fn,
			std::vector<std::unique_ptr<iHdlExpr>> &operands);
	static HdlCall* ternary(std::unique_ptr<iHdlExpr> cond,
			std::unique_ptr<iHdlExpr> ifTrue,
			std::unique_ptr<iHdlExpr> ifFalse);
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlCall() override;
};

}
}
