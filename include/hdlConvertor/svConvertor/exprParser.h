#pragma once

#include <vector>
#include <string>
#include <memory>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/svConvertor/literalParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>

namespace hdlConvertor {
namespace sv {

class {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	static hdlObjects::iHdlExpr* visitExpression(
			sv2017Parser::ExpressionContext *ctx);
	static hdlObjects::iHdlExpr* visitNet_lvalue(
			sv2017Parser::Net_lvalueContext *ctx);
	static hdlObjects::iHdlExpr* visitNet_concatenation(
			sv2017Parser::Net_concatenationContext *ctx);
	static hdlObjects::iHdlExpr* visitDelay_control(
			sv2017Parser::Delay_controlContext *ctx);
	static hdlObjects::iHdlExpr* visitDelay_value(
			sv2017Parser::Delay_valueContext *ctx);
	static hdlObjects::iHdlExpr* visitConstant_expression(
			sv2017Parser::Constant_expressionContext *ctx);
	static hdlObjects::iHdlExpr* visitRange_expression(
			sv2017Parser::Range_expressionContext *ctx);
	static hdlObjects::iHdlExpr* visitRange_(sv2017Parser::Range_Context *ctx);
	static hdlObjects::iHdlExpr* visitTerm(sv2017Parser::TermContext *ctx);
	static hdlObjects::iHdlExpr* visitPrimary(
			sv2017Parser::PrimaryContext *ctx);
	static hdlObjects::iHdlExpr* visitConstant_function_call(
			sv2017Parser::Constant_function_callContext *ctx);
	static hdlObjects::iHdlExpr* visitFunction_identifier(
			sv2017Parser::Function_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitSystem_function_identifier(
			sv2017Parser::System_function_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitSystem_function_call(
			sv2017Parser::System_function_callContext *ctx);
	static hdlObjects::iHdlExpr* visitFunction_call(
			sv2017Parser::Function_callContext *ctx);
	static hdlObjects::iHdlExpr* visitHierarchical_function_identifier(
			sv2017Parser::Hierarchical_function_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitMultiple_concatenation(
			sv2017Parser::Multiple_concatenationContext *ctx);
	static hdlObjects::iHdlExpr* visitConcatenation(
			sv2017Parser::ConcatenationContext *ctx);
	static hdlObjects::iHdlExpr* visitHierarchical_identifier(
			sv2017Parser::Hierarchical_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitEscaped_hierarchical_identifier(
			sv2017Parser::Escaped_hierarchical_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitSimple_hierarchical_identifier(
			sv2017Parser::Simple_hierarchical_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitSimple_hierarchical_branch(
			sv2017Parser::Simple_hierarchical_branchContext *ctx);
	static hdlObjects::iHdlExpr* visitSystem_task_identifier(
			sv2017Parser::System_task_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitIdentifier(
			sv2017Parser::IdentifierContext *ctx);
	static hdlObjects::iHdlExpr* visitEscaped_hierarchical_branch(
			sv2017Parser::Escaped_hierarchical_branchContext *ctx);
	static hdlObjects::iHdlExpr* visitMintypmax_expression(
			sv2017Parser::Mintypmax_expressionContext *ctx);
	static std::vector<hdlObjects::iHdlExpr*>* visitEvent_expression(
			sv2017Parser::Event_expressionContext *ctx);
	static hdlObjects::iHdlExpr* visitEvent_primary(
			sv2017Parser::Event_primaryContext *ctx);
	static hdlObjects::iHdlExpr* visitVariable_lvalue(
			sv2017Parser::Variable_lvalueContext *ctx);
	static hdlObjects::iHdlExpr* visitArrayed_identifier(
			sv2017Parser::Arrayed_identifierContext *ctx);
	static hdlObjects::iHdlExpr* visitEvent_trigger(
			sv2017Parser::Event_triggerContext *ctx);
	static hdlObjects::iHdlExpr* reduce(
			const std::vector<hdlObjects::iHdlExpr*> &ops,
			hdlObjects::HdlOperatorType op);
	static hdlObjects::iHdlExpr* visitPackage_or_class_scoped_hier_id_with_select(
			sv2017Parser::Package_or_class_scoped_hier_id_with_selectContext *ctx);
	static hdlObjects::iHdlExpr* visitPackage_or_class_scoped_path(
			sv2017Parser::Package_or_class_scoped_pathContext *ctx);
	static hdlObjects::iHdlExpr* visitPackage_or_class_scoped_path_item(
			sv2017Parser::Package_or_class_scoped_path_itemContext *ctx,
			hdlObjects::iHdlExpr *selected_name);
	static std::vector<hdlObjects::iHdlExpr*> visitParameter_value_assignment(
			sv2017Parser::Parameter_value_assignmentContext *ctx);
	static hdlObjects::iHdlExpr* visitimplicit_class_handle(
			sv2017Parser::Implicit_class_handleContext *ctx,
			hdlObjects::iHdlExpr *selected_name);
};

}
}
