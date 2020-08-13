#include <hdlConvertor/vhdlConvertor/operatorTypeParser.h>

namespace hdlConvertor {
namespace vhdl {

hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Shift_operatorContext *op) {
	// shift_operator
	// : SLL
	// | SRL
	// | SLA
	// | SRA
	// | ROL
	// | ROR
	// ;
	using hdlAst::HdlOpType;
	if (op->KW_SLL())
		return HdlOpType::SLL;
	if (op->KW_SRL())
		return HdlOpType::SRL;
	if (op->KW_SLA())
		return HdlOpType::SLA;
	if (op->KW_SRA())
		return HdlOpType::SRA;
	if (op->KW_ROL())
		return HdlOpType::ROL;
	//assert(op->ROR());
	return HdlOpType::ROR;

}
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Relational_operatorContext *op) {
	// relational_operator: EQ | NE | LT | CONASGN | GT | GE | EQ_MATCH | NE_MATCH | LT_MATCH | LE_MATCH | GT_MATCH | GE_MATCH;
	using hdlAst::HdlOpType;
	if (op->EQ())
		return HdlOpType::EQ;
	if (op->NE())
		return HdlOpType::NE;
	if (op->CONASGN())
		return HdlOpType::LE;
	if (op->LT())
		return HdlOpType::LT;
	if (op->GT())
		return HdlOpType::GT;
	if (op->GE())
		return HdlOpType::GE;
	if (op->EQ_MATCH())
		return HdlOpType::EQ_MATCH;
	if (op->NE_MATCH())
		return HdlOpType::NE_MATCH;
	if (op->LT_MATCH())
		return HdlOpType::LT_MATCH;
	if (op->LE_MATCH())
		return HdlOpType::LE_MATCH;
	if (op->GT_MATCH())
		return HdlOpType::GT_MATCH;
	assert(op->GE_MATCH());
	return HdlOpType::GE_MATCH;
}
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Logical_operatorContext *op) {
	// logical_operator: AND | OR | NAND | NOR | XOR | XNOR;

	using hdlAst::HdlOpType;
	if (op->KW_AND())
		return HdlOpType::AND;
	if (op->KW_OR())
		return HdlOpType::OR;
	if (op->KW_NAND())
		return HdlOpType::NAND;
	if (op->KW_NOR())
		return HdlOpType::NOR;
	if (op->KW_XOR())
		return HdlOpType::XOR;
	assert(op->KW_XNOR());
	return HdlOpType::XNOR;
}
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::SignContext *op) {
	// sign: PLUS | MINUS;
	using hdlAst::HdlOpType;
	if (op->PLUS())
		return HdlOpType::ADD;
	assert(op->MINUS());
	return HdlOpType::SUB;
}
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Adding_operatorContext *op) {
	// adding_operator: PLUS | MINUS | AMPERSAND;
	using hdlAst::HdlOpType;
	if (op->PLUS())
		return HdlOpType::ADD;
	if (op->MINUS())
		return HdlOpType::SUB;
	assert(op->AMPERSAND());
	return HdlOpType::CONCAT;
}
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Multiplying_operatorContext *op) {
	// multiplying_operator: MUL | DIV | KW_MOD | KW_REM;
	using hdlAst::HdlOpType;
	if (op->MUL())
		return HdlOpType::MUL;
	if (op->DIV())
		return HdlOpType::DIV;
	if (op->KW_MOD())
		return HdlOpType::MOD;
	assert(op->KW_REM());
	return HdlOpType::REM;
}

}
}
