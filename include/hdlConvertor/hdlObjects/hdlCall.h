#pragma once
#include <vector>
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
	std::vector<iHdlExpr*> operands;
	HdlCall(const HdlCall & o);
	HdlCall(HdlOperatorType operatorType, iHdlExpr* op0);
	HdlCall(iHdlExpr* op0, HdlOperatorType operatorType, iHdlExpr* op1);

	static HdlCall * call(iHdlExpr* fn, const std::vector<iHdlExpr*> & operands);
	static HdlCall * slice(iHdlExpr* fn, const std::vector<iHdlExpr*> & operands);
	static HdlCall * ternary(iHdlExpr* cond, iHdlExpr* ifTrue, iHdlExpr* ifFalse);
	iHdlExprItem * clone() const;
	~HdlCall();
};

}
}
