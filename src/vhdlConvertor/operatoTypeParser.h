# pragma once

#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/operatorType.h"

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
	// relational_operator
	// : EQ
	// | NEQ
	// | LOWERTHAN
	// | LE
	// | GREATERTHAN
	// | GE
	// ;

	using hdlObjects::OperatorType;
	if (op->EQ())
		return OperatorType::EQ;
	if (op->NEQ())
		return OperatorType::NEQ;
	if (op->LOWERTHAN())
		return OperatorType::LOWERTHAN;
	if (op->LE())
		return OperatorType::LE;
	if (op->GREATERTHAN())
		return OperatorType::GREATERTHAN;
	//assert(op->GE());
	return OperatorType::GE;
}
inline hdlObjects::OperatorType OperatorType_from(
		vhdl_antlr::vhdlParser::Logical_operatorContext * op) {
	// logical_operator
	// : AND
	// | OR
	// | NAND
	// | NOR
	// | XOR
	// | XNOR
	// ;

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
