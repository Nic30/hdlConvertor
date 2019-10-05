#include <hdlConvertor/hdlObjects/hdlCall.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlCall::HdlCall() {
	op = HdlOperatorType::ARROW;
	operands.reserve(2);
}

HdlCall::HdlCall(const HdlCall &o) {
	operands.reserve(o.operands.size());
	for (auto &op : o.operands) {
		operands.push_back(make_unique<iHdlExpr>(*op));
	}
	op = o.op;
}

HdlCall::HdlCall(HdlOperatorType operatorType, unique_ptr<iHdlExpr> op0) {
	operands.push_back(move(op0));
	this->op = operatorType;

}

HdlCall::HdlCall(unique_ptr<iHdlExpr> op0, HdlOperatorType operatorType,
		unique_ptr<iHdlExpr> op1) {
	if (op0) {
		operands.push_back(move(op0));
		//assert(!op1);
	}
	if (op1)
		operands.push_back(move(op1));
	this->op = operatorType;
}

HdlCall* HdlCall::call(unique_ptr<iHdlExpr> fn,
		std::vector<unique_ptr<iHdlExpr>> &operands) {
	auto o = new HdlCall();
	o->op = HdlOperatorType::CALL;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(move(fn));
	for (auto &op : operands)
		o->operands.push_back(move(op));
	return o;
}

HdlCall* HdlCall::parametrization(unique_ptr<iHdlExpr> fn,
		std::vector<unique_ptr<iHdlExpr>> &operands) {
	auto o = new HdlCall();
	o->op = HdlOperatorType::PARAMETRIZATION;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(move(fn));
	for (auto &op : operands)
		o->operands.push_back(move(op));
	return o;
}

HdlCall* HdlCall::slice(unique_ptr<iHdlExpr> fn,
		std::vector<unique_ptr<iHdlExpr>> &operands) {
	auto o = new HdlCall();
	o->op = HdlOperatorType::INDEX;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(move(fn));
	for (auto &op : operands)
		o->operands.push_back(move(op));
	return o;
}

HdlCall* HdlCall::ternary(unique_ptr<iHdlExpr> cond,
		unique_ptr<iHdlExpr> ifTrue, unique_ptr<iHdlExpr> ifFalse) {
	HdlCall *op = new HdlCall();
	op->op = HdlOperatorType::TERNARY;
	op->operands.push_back(move(cond));
	op->operands.push_back(move(ifTrue));

	if (ifFalse)
		op->operands.push_back(move(ifFalse));

	return op;
}

HdlCall::~HdlCall() {
}

iHdlExprItem* HdlCall::clone() const {
	return new HdlCall(*this);
}

}
}
