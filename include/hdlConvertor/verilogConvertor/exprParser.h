#pragma once

#include <vector>
#include <string>
#include <memory>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/verilogConvertor/literalParser.h>
#include <hdlConvertor/verilogConvertor/attributeParser.h>

namespace hdlConvertor {
namespace verilog {

class VerExprParser {
public:
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;

	static hdlObjects::iHdlExpr * visitExpression(
			Verilog2001Parser::ExpressionContext * ctx);
	static hdlObjects::iHdlExpr * visitNet_lvalue(
			Verilog2001Parser::Net_lvalueContext * ctx);
	static hdlObjects::iHdlExpr * visitNet_concatenation(
			Verilog2001Parser::Net_concatenationContext * ctx);
	static hdlObjects::iHdlExpr * visitHierarchical_net_identifier(
			Verilog2001Parser::Hierarchical_net_identifierContext * ctx);
	static hdlObjects::iHdlExpr * visitDelay_control(
			Verilog2001Parser::Delay_controlContext * ctx);
	static hdlObjects::iHdlExpr * visitDelay_value(
			Verilog2001Parser::Delay_valueContext * ctx);
	static hdlObjects::iHdlExpr * visitSpecparam_identifier(
			Verilog2001Parser::Specparam_identifierContext * ctx);
	static hdlObjects::iHdlExpr * visitConstant_expression(
			Verilog2001Parser::Constant_expressionContext * ctx);
	static hdlObjects::iHdlExpr * visitDimension(
			Verilog2001Parser::DimensionContext * ctx);
	static hdlObjects::iHdlExpr * visitDimension_constant_expression(
			Verilog2001Parser::Dimension_constant_expressionContext * ctx);
	static hdlObjects::iHdlExpr * visitRange_expression(
			Verilog2001Parser::Range_expressionContext * ctx);
	static hdlObjects::iHdlExpr * visitRange_(
			Verilog2001Parser::Range_Context * ctx);
	static hdlObjects::iHdlExpr * visitTerm(
			Verilog2001Parser::TermContext * ctx);
	static hdlObjects::iHdlExpr * visitPrimary(
			Verilog2001Parser::PrimaryContext * ctx);
	static hdlObjects::iHdlExpr * visitConstant_function_call(
			Verilog2001Parser::Constant_function_callContext * ctx);
	static hdlObjects::iHdlExpr * visitFunction_identifier(
			Verilog2001Parser::Function_identifierContext * ctx);
	static hdlObjects::iHdlExpr * visitSystem_function_identifier(
			Verilog2001Parser::System_function_identifierContext *ctx);
	static hdlObjects::iHdlExpr * visitSystem_function_call(
			Verilog2001Parser::System_function_callContext * ctx);
	static hdlObjects::iHdlExpr * visitFunction_call(
			Verilog2001Parser::Function_callContext * ctx);
	static hdlObjects::iHdlExpr * visitHierarchical_function_identifier(
			Verilog2001Parser::Hierarchical_function_identifierContext * ctx);
	static hdlObjects::iHdlExpr * visitMultiple_concatenation(
			Verilog2001Parser::Multiple_concatenationContext * ctx);
	static hdlObjects::iHdlExpr * visitConcatenation(
			Verilog2001Parser::ConcatenationContext * ctx);
	static hdlObjects::iHdlExpr * visitHierarchical_identifier(
			Verilog2001Parser::Hierarchical_identifierContext * ctx);
	static hdlObjects::iHdlExpr * visitEscaped_hierarchical_identifier(
			Verilog2001Parser::Escaped_hierarchical_identifierContext * ctx);
	static hdlObjects::iHdlExpr * visitSimple_hierarchical_identifier(
			Verilog2001Parser::Simple_hierarchical_identifierContext * ctx);
	static hdlObjects::iHdlExpr * visitSimple_hierarchical_branch(
			Verilog2001Parser::Simple_hierarchical_branchContext * ctx);
	static hdlObjects::iHdlExpr * visitSystem_task_identifier(
			Verilog2001Parser::System_task_identifierContext *ctx);
	static hdlObjects::iHdlExpr * visitIdentifier(
			Verilog2001Parser::IdentifierContext * ctx);
	static hdlObjects::iHdlExpr * visitEscaped_hierarchical_branch(
			Verilog2001Parser::Escaped_hierarchical_branchContext * ctx);
	static hdlObjects::iHdlExpr * visitMintypmax_expression(
			Verilog2001Parser::Mintypmax_expressionContext * ctx);
	static std::vector<hdlObjects::iHdlExpr*> * visitEvent_expression(
			Verilog2001Parser::Event_expressionContext * ctx);
	static hdlObjects::iHdlExpr * visitEvent_primary(
			Verilog2001Parser::Event_primaryContext * ctx);
	static hdlObjects::iHdlExpr * visitVariable_lvalue(
			Verilog2001Parser::Variable_lvalueContext * ctx);
	static hdlObjects::iHdlExpr * visitVariable_concatenation(
			Verilog2001Parser::Variable_concatenationContext* ctx);
	static hdlObjects::iHdlExpr * visitArrayed_identifier(
			Verilog2001Parser::Arrayed_identifierContext * ctx);
};

}
}
