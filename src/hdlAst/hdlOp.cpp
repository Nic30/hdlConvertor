#include <hdlConvertor/hdlAst/hdlOp.h>
#include <hdlConvertor/createObject.h>

using namespace std;

namespace hdlConvertor {
namespace hdlAst {

HdlOp::HdlOp() {
	op = HdlOpType::ARROW;
	operands.reserve(2);
}

HdlOp::HdlOp(const HdlOp &o): iHdlExprItem() {
	operands.reserve(o.operands.size());
	for (auto &op : o.operands) {
		operands.push_back(op->clone_uniq());
	}
	op = o.op;
}

HdlOp::HdlOp(HdlOpType operatorType, unique_ptr<iHdlExprItem> op0) {
	operands.push_back(move(op0));
	this->op = operatorType;

}

HdlOp::HdlOp(unique_ptr<iHdlExprItem> op0, HdlOpType operatorType,
		unique_ptr<iHdlExprItem> op1) {
	if (op0) {
		operands.push_back(move(op0));
		//assert(!op1);
	}
	if (op1)
		operands.push_back(move(op1));
	this->op = operatorType;
}


unique_ptr<HdlOp> HdlOp::call(unique_ptr<iHdlExprItem> fn,
		vector<unique_ptr<iHdlExprItem>> &operands) {
	auto o = unique_ptr<HdlOp>(new HdlOp());

	o->op = HdlOpType::CALL;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(move(fn));
	for (auto &op : operands)
		o->operands.push_back(move(op));
	return o;
}

unique_ptr<HdlOp> HdlOp::parametrization(unique_ptr<iHdlExprItem> fn,
		vector<unique_ptr<iHdlExprItem>> &operands) {
	auto o = unique_ptr<HdlOp>(new HdlOp());

	o->op = HdlOpType::PARAMETRIZATION;
	o->operands.reserve(operands.size() + 1);
	o->operands.push_back(move(fn));
	for (auto &op : operands)
		o->operands.push_back(move(op));
	return o;
}

unique_ptr<HdlOp> HdlOp::ternary(unique_ptr<iHdlExprItem> cond,
		unique_ptr<iHdlExprItem> ifTrue, unique_ptr<iHdlExprItem> ifFalse) {
	auto o = unique_ptr<HdlOp>(new HdlOp());

	o->op = HdlOpType::TERNARY;
	o->operands.push_back(move(cond));
	o->operands.push_back(move(ifTrue));

	if (ifFalse)
		o->operands.push_back(move(ifFalse));

	return o;
}

unique_ptr<HdlOp> HdlOp::ternary(ParserRuleContext *ctx,
		unique_ptr<iHdlExprItem> cond,
		unique_ptr<iHdlExprItem> ifTrue,
		unique_ptr<iHdlExprItem> ifFalse) {
	return update_code_position(HdlOp::ternary(move(cond), move(ifTrue), move(ifFalse)), ctx);
}
unique_ptr<HdlOp> HdlOp::call(ParserRuleContext *ctx,
		unique_ptr<iHdlExprItem> fnId,
		vector<unique_ptr<iHdlExprItem>> &args) {
	return update_code_position(HdlOp::call(move(fnId), args), ctx);
}
unique_ptr<HdlOp> HdlOp::parametrization(
		ParserRuleContext *ctx,
		unique_ptr<iHdlExprItem> fnId,
		vector<unique_ptr<iHdlExprItem>> &args) {
	return update_code_position(HdlOp::parametrization(move(fnId), args), ctx);
}

HdlOp::~HdlOp() {
}

iHdlExprItem* HdlOp::clone() const {
	return new HdlOp(*this);
}

}
}
