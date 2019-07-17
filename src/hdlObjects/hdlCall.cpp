#include <hdlConvertor/hdlObjects/hdlCall.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlCall::HdlCall() {
	op = ARROW;
	operands.reserve(2);
}

HdlCall::HdlCall(const HdlCall & o) {
	operands.reserve(o.operands.size());
	for (auto op : o.operands) {
		operands.push_back(new iHdlExpr(*op));
	}
	op = o.op;
}

HdlCall::HdlCall(HdlOperatorType operatorType, iHdlExpr* op0) {
	operands.push_back(op0);
	this->op = operatorType;

}
HdlCall::HdlCall(iHdlExpr* op0, HdlOperatorType operatorType, iHdlExpr* op1) {
	if (op0) {
		operands.push_back(op0);
		//assert(!op1);
	}
	if (op1)
		operands.push_back(op1);
	this->op = operatorType;
}

HdlCall * HdlCall::call(iHdlExpr* fn, const std::vector<iHdlExpr*> & operands) {
	HdlCall * o = new HdlCall();
	o->op = CALL;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(fn);
	for (auto op : operands)
		o->operands.push_back(op);
	return o;
}
HdlCall * HdlCall::slice(iHdlExpr* fn,
		const std::vector<iHdlExpr*> & operands) {
	HdlCall * o = new HdlCall();
	o->op = INDEX;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(fn);
	for (auto op : operands)
		o->operands.push_back(op);
	return o;
}
HdlCall * HdlCall::ternary(iHdlExpr* cond, iHdlExpr* ifTrue,
		iHdlExpr* ifFalse) {
	HdlCall * op = new HdlCall();
	op->op = TERNARY;
	if (ifFalse)
		op->operands = {cond, ifTrue, ifFalse};
		else
		op->operands = {cond, ifTrue};

	return op;
}
HdlCall::~HdlCall() {
	for (auto o : operands) {
		delete o;
	}
}
iHdlExprItem * HdlCall::clone() const {
	return new HdlCall(*this);
}

}
}
