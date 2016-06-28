# pragma once

#include "antlr4-runtime.h"
#include "../VhdlParser/vhdlParser.h"
#include "../hdlObjects/operatorType.h"


using namespace antlr4;
using namespace vhdl;

inline OperatorType OperatorType_from(Ref<vhdlParser::Shift_operatorContext> op) {
	// shift_operator
	// : SLL
	// | SRL
	// | SLA
	// | SRA
	// | ROL
	// | ROR
	// ;
	if (op->SLL())
		return SLL;
	if (op->SRL())
		return SRL;
	if (op->SLA())
		return SLA;
	if (op->SRA())
		return SRA;
	if (op->ROL())
		return ROL;
	//assert(op->ROR());
	return ROR;

}
inline OperatorType OperatorType_from(Ref<vhdlParser::Relational_operatorContext> op) {
	// relational_operator
	// : EQ
	// | NEQ
	// | LOWERTHAN
	// | LE
	// | GREATERTHAN
	// | GE
	// ;
	if (op->EQ())
		return EQ;
	if (op->NEQ())
		return NEQ;
	if (op->LOWERTHAN())
		return LOWERTHAN;
	if (op->LE())
		return LE;
	if (op->GREATERTHAN())
		return GREATERTHAN;
	//assert(op->GE());
	return GE;
}
inline OperatorType OperatorType_from(Ref<vhdlParser::Logical_operatorContext> op) {
	// logical_operator
	// : AND
	// | OR
	// | NAND
	// | NOR
	// | XOR
	// | XNOR
	// ;
	if (op->AND())
		return AND;
	if (op->OR())
		return OR;
	if (op->NAND())
		return NAND;
	if (op->NOR())
		return NOR;
	if (op->XOR())
		return XOR;
	//assert(op->XNOR());
	return XNOR;

}
