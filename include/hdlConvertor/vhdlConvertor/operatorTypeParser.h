# pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace vhdl {

inline hdlObjects::HdlOperatorType OperatorType_from(
		vhdl_antlr::vhdlParser::Shift_operatorContext * op) {
	// shift_operator
	// : SLL
	// | SRL
	// | SLA
	// | SRA
	// | ROL
	// | ROR
	// ;
	using hdlObjects::HdlOperatorType;
	if (op->SLL())
		return HdlOperatorType::SLL;
	if (op->SRL())
		return HdlOperatorType::SRL;
	if (op->SLA())
		return HdlOperatorType::SLA;
	if (op->SRA())
		return HdlOperatorType::SRA;
	if (op->ROL())
		return HdlOperatorType::ROL;
	//assert(op->ROR());
	return HdlOperatorType::ROR;

}
inline hdlObjects::HdlOperatorType OperatorType_from(
		vhdl_antlr::vhdlParser::Relational_operatorContext * op) {
	// relational_operator: EQ | NEQ | LT | CONASGN | GT | GE | MATCH_EQ | MATCH_NEQ | MATCH_LT | MATCH_LE | MATCH_GT | MATCH_GE;


	using hdlObjects::HdlOperatorType;
	if (op->EQ())
		return HdlOperatorType::EQ;
	if (op->NEQ())
		return HdlOperatorType::NEQ;

	if (op->CONASGN())
		return HdlOperatorType::LE;
	if (op->LT())
		return HdlOperatorType::LT;
	if (op->GT())
		return HdlOperatorType::GT;
	if (op->GE())
		return HdlOperatorType::GE;
	if (op->MATCH_EQ())
		return HdlOperatorType::MATCH_EQ;
	if (op->MATCH_NEQ())
		return HdlOperatorType::MATCH_NEQ;
	if (op->MATCH_LT())
		return HdlOperatorType::MATCH_LT;
	if (op->MATCH_LE())
		return HdlOperatorType::MATCH_LE;
	if (op->MATCH_GT())
		return HdlOperatorType::MATCH_GT;
	assert (op->MATCH_GE());
		return HdlOperatorType::MATCH_GE;
}
inline hdlObjects::HdlOperatorType OperatorType_from(
		vhdl_antlr::vhdlParser::Logical_operatorContext * op) {
	// logical_operator: AND | OR | NAND | NOR | XOR | XNOR;

	using hdlObjects::HdlOperatorType;
	if (op->AND())
		return HdlOperatorType::AND;
	if (op->OR())
		return HdlOperatorType::OR;
	if (op->NAND())
		return HdlOperatorType::NAND;
	if (op->NOR())
		return HdlOperatorType::NOR;
	if (op->XOR())
		return HdlOperatorType::XOR;
	//assert(op->XNOR());
	return HdlOperatorType::XNOR;
}

}
}
