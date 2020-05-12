#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

class VerExprParser {
	SVCommentParser &commentParser;
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	VerExprParser(SVCommentParser &commentParser);

	std::unique_ptr<hdlAst::iHdlExprItem> visitExpression(
			sv2017Parser::ExpressionContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitNet_lvalue(
			sv2017Parser::Net_lvalueContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitConstant_expression(
			sv2017Parser::Constant_expressionContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitRange_expression(
			sv2017Parser::Range_expressionContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitConcatenation(
			sv2017Parser::ConcatenationContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitHierarchical_identifier(
			sv2017Parser::Hierarchical_identifierContext *ctx);
	static std::string getIdentifierStr(sv2017Parser::IdentifierContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitIdentifier(
			sv2017Parser::IdentifierContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitMintypmax_expression(
			sv2017Parser::Mintypmax_expressionContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitVariable_lvalue(
			sv2017Parser::Variable_lvalueContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitEvent_trigger(
			sv2017Parser::Event_triggerContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitBit_select(
			sv2017Parser::Bit_selectContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> selected_name);
	// @note selected_name can be nullptr
	std::unique_ptr<hdlAst::iHdlExprItem> visitIdentifier_with_bit_select(
			sv2017Parser::Identifier_with_bit_selectContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> selected_name);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPackage_or_class_scoped_hier_id_with_select(
			sv2017Parser::Package_or_class_scoped_hier_id_with_selectContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPackage_or_class_scoped_path(
			sv2017Parser::Package_or_class_scoped_pathContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitImplicit_class_handle(
			sv2017Parser::Implicit_class_handleContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> selected_name,
			hdlAst::HdlOpType subname_access_type);
	std::unique_ptr<hdlAst::iHdlExprItem> visitPackage_or_class_scoped_path_item(
			sv2017Parser::Package_or_class_scoped_path_itemContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> selected_name,
			hdlAst::HdlOpType subname_access_type);
	std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> visitParameter_value_assignment(
			sv2017Parser::Parameter_value_assignmentContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitInc_or_dec_expression(
			sv2017Parser::Inc_or_dec_expressionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitPackage_scope(
			sv2017Parser::Package_scopeContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitPs_identifier(
			sv2017Parser::Ps_identifierContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitArray_range_expression(
			sv2017Parser::Array_range_expressionContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitIdentifier_doted_index_at_end(
			sv2017Parser::Identifier_doted_index_at_endContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitCond_predicate(
			sv2017Parser::Cond_predicateContext *ctx);
	void visitList_of_arguments(sv2017Parser::List_of_argumentsContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> &args);
	std::unique_ptr<hdlAst::iHdlExprItem> visitOperator_assignment(
			sv2017Parser::Operator_assignmentContext *ctx);
};

}
}
