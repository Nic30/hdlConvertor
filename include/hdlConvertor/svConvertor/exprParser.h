#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class VerExprParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	static hdlObjects::iHdlExpr* visitExpression(
			sv2017Parser::ExpressionContext *ctx);
	static hdlObjects::iHdlExpr* visitNet_lvalue(
			sv2017Parser::Net_lvalueContext *ctx);
	static hdlObjects::iHdlExpr* visitDelay_control(
			sv2017Parser::Delay_controlContext *ctx);
	static hdlObjects::iHdlExpr* visitDelay_value(
			sv2017Parser::Delay_valueContext *ctx);
	static hdlObjects::iHdlExpr* visitConstant_expression(
			sv2017Parser::Constant_expressionContext *ctx);
	static hdlObjects::iHdlExpr* visitRange_expression(
			sv2017Parser::Range_expressionContext *ctx);
	static hdlObjects::iHdlExpr* visitConcatenation(
			sv2017Parser::ConcatenationContext *ctx);
	static hdlObjects::iHdlExpr* visitHierarchical_identifier(
			sv2017Parser::Hierarchical_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitIdentifier(
			sv2017Parser::IdentifierContext *ctx);
	static hdlObjects::iHdlExpr* visitMintypmax_expression(
			sv2017Parser::Mintypmax_expressionContext *ctx);
	static hdlObjects::iHdlExpr* visitVariable_lvalue(
			sv2017Parser::Variable_lvalueContext *ctx);
	static hdlObjects::iHdlExpr* visitEvent_trigger(
			sv2017Parser::Event_triggerContext *ctx);
	static hdlObjects::iHdlExpr* visitBit_select(
			sv2017Parser::Bit_selectContext *ctx,
			hdlObjects::iHdlExpr *selected_name);
	static hdlObjects::iHdlExpr* visitIdentifier_with_bit_select(
			sv2017Parser::Identifier_with_bit_selectContext *ctx,
			hdlObjects::iHdlExpr *selected_name);
	static hdlObjects::iHdlExpr* visitPackage_or_class_scoped_hier_id_with_select(
			sv2017Parser::Package_or_class_scoped_hier_id_with_selectContext *ctx);
	static hdlObjects::iHdlExpr* visitPackage_or_class_scoped_path(
			sv2017Parser::Package_or_class_scoped_pathContext *ctx);
	static hdlObjects::iHdlExpr* visitImplicit_class_handle(
			sv2017Parser::Implicit_class_handleContext *ctx,
			hdlObjects::iHdlExpr *selected_name,
			hdlObjects::HdlOperatorType subname_access_type);
	static hdlObjects::iHdlExpr* visitPackage_or_class_scoped_path_item(
			sv2017Parser::Package_or_class_scoped_path_itemContext *ctx,
			hdlObjects::iHdlExpr *selected_name,
			hdlObjects::HdlOperatorType subname_access_type);
	static std::vector<hdlObjects::iHdlExpr*> visitParameter_value_assignment(
			sv2017Parser::Parameter_value_assignmentContext *ctx);
};

}
}
