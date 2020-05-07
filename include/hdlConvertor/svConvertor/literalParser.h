#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class VerLiteralParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	using TerminalNode = antlr4::tree::TerminalNode;

	static std::unique_ptr<hdlAst::iHdlExprItem> visitIntegral_number(
			sv2017Parser::Integral_numberContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitUNSIGNED_NUMBER(
			TerminalNode *ctx);
	static size_t parseSize_UNSIGNED_NUMBER(std::string str);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitANY_BASED_NUMBER(
			sv2017Parser::Integral_numberContext *ctx, std::string str,
			size_t size);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitNumber(
			sv2017Parser::NumberContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitSIMPLE_IDENTIFIER(
			TerminalNode *n);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitC_IDENTIFIER(
			TerminalNode *n);
	static std::string visitESCAPED_IDENTIFIER(TerminalNode *n);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitReal_number(
			sv2017Parser::Real_numberContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitTIME_LITERAL(
			TerminalNode *n);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitSTRING(TerminalNode *n);
	static hdlAst::HdlOpType visitUnary_module_path_operator(
			sv2017Parser::Unary_module_path_operatorContext *ctx);
	static hdlAst::HdlOpType visitUnary_operator(
			sv2017Parser::Unary_operatorContext *ctx);
	static hdlAst::HdlOpType visitOperator_mul_div_mod(
			sv2017Parser::Operator_mul_div_modContext *ctx);
	static hdlAst::HdlOpType visitOperator_plus_minus(
			sv2017Parser::Operator_plus_minusContext *ctx);
	static hdlAst::HdlOpType visitOperator_shift(
			sv2017Parser::Operator_shiftContext *ctx);
	static hdlAst::HdlOpType visitOperator_cmp(
			sv2017Parser::Operator_cmpContext *ctx);
	static hdlAst::HdlOpType visitOperator_eq_neq(
			sv2017Parser::Operator_eq_neqContext *ctx);
	static hdlAst::HdlOpType visitOperator_xor(
			sv2017Parser::Operator_xorContext *ctx);
	static hdlAst::HdlOpType visitOperator_impl(
			sv2017Parser::Operator_implContext *ctx);
	static hdlAst::HdlOpType visitAssignment_operator(
			sv2017Parser::Assignment_operatorContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitPrimary_literal(
			sv2017Parser::Primary_literalContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitAny_system_tf_identifier(
			sv2017Parser::Any_system_tf_identifierContext *ctx);
	static hdlAst::HdlOpType visitInc_or_dec_operator(
			sv2017Parser::Inc_or_dec_operatorContext *ctx, bool prefix);
};

}
}
