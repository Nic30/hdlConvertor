# pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/operatorType.h>

namespace hdlConvertor {
namespace vhdl {

inline hdlObjects::OperatorType OperatorType_from(
		vhdl_antlr::vhdlParser::Shift_operatorContext * op) {
	// shift_operator
	// : SLL
	// | SRL
	// | SLA
	// | SRA
	// | ROL
	// | ROR
	// ;
	using hdlObjects::OperatorType;
	if (op->SLL())
		return OperatorType::SLL;
	if (op->SRL())
		return OperatorType::SRL;
	if (op->SLA())
		return OperatorType::SLA;
	if (op->SRA())
		return OperatorType::SRA;
	if (op->ROL())
		return OperatorType::ROL;
	//assert(op->ROR());
	return OperatorType::ROR;

}
inline hdlObjects::OperatorType OperatorType_from(
		vhdl_antlr::vhdlParser::Relational_operatorContext * op) {
	// relational_operator: EQ | NEQ | LT | CONASGN | GT | GE | MATCH_EQ | MATCH_NEQ | MATCH_LT | MATCH_LE | MATCH_GT | MATCH_GE;


	using hdlObjects::OperatorType;
	if (op->EQ())
		return OperatorType::EQ;
	if (op->NEQ())
		return OperatorType::NEQ;

	if (op->CONASGN())
		return OperatorType::LE;
	if (op->LT())
		return OperatorType::LT;
	if (op->GT())
		return OperatorType::GT;
	if (op->GE())
		return OperatorType::GE;
	if (op->MATCH_EQ())
		return OperatorType::MATCH_EQ;
	if (op->MATCH_NEQ())
		return OperatorType::MATCH_NEQ;
	if (op->MATCH_LT())
		return OperatorType::MATCH_LT;
	if (op->MATCH_LE())
		return OperatorType::MATCH_LE;
	if (op->MATCH_GT())
		return OperatorType::MATCH_GT;
	assert (op->MATCH_GE());
		return OperatorType::MATCH_GE;
}
inline hdlObjects::OperatorType OperatorType_from(
		vhdl_antlr::vhdlParser::Logical_operatorContext * op) {
	// logical_operator: AND | OR | NAND | NOR | XOR | XNOR;

	using hdlObjects::OperatorType;
	if (op->AND())
		return OperatorType::AND;
	if (op->OR())
		return OperatorType::OR;
	if (op->NAND())
		return OperatorType::NAND;
	if (op->NOR())
		return OperatorType::NOR;
	if (op->XOR())
		return OperatorType::XOR;
	//assert(op->XNOR());
	return OperatorType::XNOR;
}

}
}
