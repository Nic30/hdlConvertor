#include <hdlConvertor/hdlObjects/hdlCall.h>
#include <hdlConvertor/createObject.h>

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

HdlCall::HdlCall() {
	op = HdlOperatorType::ARROW;
	operands.reserve(2);
}

HdlCall::HdlCall(const HdlCall &o): iHdlExprItem() {
	operands.reserve(o.operands.size());
	for (auto &op : o.operands) {
		operands.push_back(op->clone_uniq());
	}
	op = o.op;
}

HdlCall::HdlCall(HdlOperatorType operatorType, unique_ptr<iHdlExprItem> op0) {
	operands.push_back(move(op0));
	this->op = operatorType;

}

HdlCall::HdlCall(unique_ptr<iHdlExprItem> op0, HdlOperatorType operatorType,
		unique_ptr<iHdlExprItem> op1) {
	if (op0) {
		operands.push_back(move(op0));
		//assert(!op1);
	}
	if (op1)
		operands.push_back(move(op1));
	this->op = operatorType;
}


unique_ptr<HdlCall> HdlCall::call(unique_ptr<iHdlExprItem> fn,
		vector<unique_ptr<iHdlExprItem>> &operands) {
	auto o = unique_ptr<HdlCall>(new HdlCall());

	o->op = HdlOperatorType::CALL;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(move(fn));
	for (auto &op : operands)
		o->operands.push_back(move(op));
	return o;
}

unique_ptr<HdlCall> HdlCall::parametrization(unique_ptr<iHdlExprItem> fn,
		vector<unique_ptr<iHdlExprItem>> &operands) {
	auto o = unique_ptr<HdlCall>(new HdlCall());

	o->op = HdlOperatorType::PARAMETRIZATION;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(move(fn));
	for (auto &op : operands)
		o->operands.push_back(move(op));
	return o;
}

unique_ptr<HdlCall> HdlCall::ternary(unique_ptr<iHdlExprItem> cond,
		unique_ptr<iHdlExprItem> ifTrue, unique_ptr<iHdlExprItem> ifFalse) {
	auto o = unique_ptr<HdlCall>(new HdlCall());

	o->op = HdlOperatorType::TERNARY;
	o->operands.push_back(move(cond));
	o->operands.push_back(move(ifTrue));

	if (ifFalse)
		o->operands.push_back(move(ifFalse));

	return o;
}

unique_ptr<HdlCall> HdlCall::ternary(ParserRuleContext *ctx,
		unique_ptr<iHdlExprItem> cond,
		unique_ptr<iHdlExprItem> ifTrue,
		unique_ptr<iHdlExprItem> ifFalse) {
	return update_code_position(HdlCall::ternary(move(cond), move(ifTrue), move(ifFalse)), ctx);
}
unique_ptr<HdlCall> HdlCall::call(ParserRuleContext *ctx,
		unique_ptr<iHdlExprItem> fnId,
		vector<unique_ptr<iHdlExprItem>> &args) {
	return update_code_position(HdlCall::call(move(fnId), args), ctx);
}
unique_ptr<HdlCall> HdlCall::parametrization(
		ParserRuleContext *ctx,
		unique_ptr<iHdlExprItem> fnId,
		vector<unique_ptr<iHdlExprItem>> &args) {
	return update_code_position(HdlCall::parametrization(move(fnId), args), ctx);
}

HdlCall::~HdlCall() {
}

iHdlExprItem* HdlCall::clone() const {
	return new HdlCall(*this);
}

}
}
