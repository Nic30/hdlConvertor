#include <hdlConvertor/vhdlConvertor/operatorTypeParser.h>

namespace hdlConvertor {
namespace vhdl {

hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Shift_operatorContext *op) {
	// shift_operator
	// : SLL
	// | SRL
	// | SLA
	// | SRA
	// | ROL
	// | ROR
	// ;
	using hdlObjects::HdlOperatorType;
	if (op->KW_SLL())
		return HdlOperatorType::SLL;
	if (op->KW_SRL())
		return HdlOperatorType::SRL;
	if (op->KW_SLA())
		return HdlOperatorType::SLA;
	if (op->KW_SRA())
		return HdlOperatorType::SRA;
	if (op->KW_ROL())
		return HdlOperatorType::ROL;
	//assert(op->ROR());
	return HdlOperatorType::ROR;

}
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Relational_operatorContext *op) {
	// relational_operator: EQ | NEQ | LT | CONASGN | GT | GE | EQ_MATCH | NEQ_MATCH | LT_MATCH | LE_MATCH | GT_MATCH | GE_MATCH;
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
	if (op->EQ_MATCH())
		return HdlOperatorType::EQ_MATCH;
	if (op->NEQ_MATCH())
		return HdlOperatorType::NEQ_MATCH;
	if (op->LT_MATCH())
		return HdlOperatorType::LT_MATCH;
	if (op->LE_MATCH())
		return HdlOperatorType::LE_MATCH;
	if (op->GT_MATCH())
		return HdlOperatorType::GT_MATCH;
	assert(op->GE_MATCH());
	return HdlOperatorType::GE_MATCH;
}
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Logical_operatorContext *op) {
	// logical_operator: AND | OR | NAND | NOR | XOR | XNOR;

	using hdlObjects::HdlOperatorType;
	if (op->KW_AND())
		return HdlOperatorType::AND;
	if (op->KW_OR())
		return HdlOperatorType::OR;
	if (op->KW_NAND())
		return HdlOperatorType::NAND;
	if (op->KW_NOR())
		return HdlOperatorType::NOR;
	if (op->KW_XOR())
		return HdlOperatorType::XOR;
	assert(op->KW_XNOR());
	return HdlOperatorType::XNOR;
}
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::SignContext *op) {
	// sign: PLUS | MINUS;
	using hdlObjects::HdlOperatorType;
	if (op->PLUS())
		return HdlOperatorType::ADD;
	assert(op->MINUS());
	return HdlOperatorType::SUB;
}
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Adding_operatorContext *op) {
	// adding_operator: PLUS | MINUS | AMPERSAND;
	using hdlObjects::HdlOperatorType;
	if (op->PLUS())
		return HdlOperatorType::ADD;
	if (op->MINUS())
		return HdlOperatorType::SUB;
	assert(op->AMPERSAND());
	return HdlOperatorType::AND;
}
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Multiplying_operatorContext *op) {
	// multiplying_operator: MUL | DIV | KW_MOD | KW_REM;
	using hdlObjects::HdlOperatorType;
	if (op->MUL())
		return HdlOperatorType::MUL;
	if (op->DIV())
		return HdlOperatorType::DIV;
	if (op->KW_MOD())
		return HdlOperatorType::MOD;
	assert(op->KW_REM());
	return HdlOperatorType::REM;
}

}
}
