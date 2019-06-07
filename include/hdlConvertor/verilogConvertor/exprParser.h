#pragma once

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include <memory>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/expr.h"
#include "../notImplementedLogger.h"
#include "literalParser.h"
#include "attributeParser.h"

namespace hdlConvertor {
namespace verilog {

class VerExprParser {
public:
	typedef hdlObjects::Expr Expr;
	typedef hdlObjects::OperatorType OperatorType;
	typedef Verilog2001_antlr::Verilog2001Parser Verilog2001Parser;

	static Expr * visitExpression(Verilog2001Parser::ExpressionContext * ctx);
	static Expr * visitNet_lvalue(Verilog2001Parser::Net_lvalueContext * ctx);
	static Expr * visitNet_concatenation(
			Verilog2001Parser::Net_concatenationContext * ctx);
	static Expr * visitHierarchical_net_identifier(
			Verilog2001Parser::Hierarchical_net_identifierContext * ctx);
	static Expr * visitConstant_expression(
			Verilog2001Parser::Constant_expressionContext * ctx);
	static Expr * visitDimension(Verilog2001Parser::DimensionContext * ctx);
	static Expr * visitDimension_constant_expression(
			Verilog2001Parser::Dimension_constant_expressionContext * ctx);
	static Expr * visitRange_expression(
			Verilog2001Parser::Range_expressionContext * ctx);
	static Expr * visitRange_(Verilog2001Parser::Range_Context * ctx);
	static OperatorType visitUnary_operator(
			Verilog2001Parser::Unary_operatorContext * ctx);
	static OperatorType visitBinary_operator(
			Verilog2001Parser::Binary_operatorContext * ctx);
	static Expr * visitTerm(Verilog2001Parser::TermContext * ctx);
	static Expr * visitPrimary(Verilog2001Parser::PrimaryContext * ctx);
	static Expr * visitConstant_function_call(
			Verilog2001Parser::Constant_function_callContext * ctx);
	static Expr * visitSystem_function_call(
			Verilog2001Parser::System_function_callContext * ctx);
	static Expr * visitFunction_call(
			Verilog2001Parser::Function_callContext * ctx);
	static Expr * visitMultiple_concatenation(
			Verilog2001Parser::Multiple_concatenationContext * ctx);
	static Expr * visitConcatenation(
			Verilog2001Parser::ConcatenationContext * ctx);
	static Expr * visitHierarchical_identifier(
			Verilog2001Parser::Hierarchical_identifierContext * ctx);
	static Expr * visitEscaped_hierarchical_identifier(
			Verilog2001Parser::Escaped_hierarchical_identifierContext * ctx);
	static Expr * visitSimple_hierarchical_identifier(
			Verilog2001Parser::Simple_hierarchical_identifierContext * ctx);
	static Expr * visitSimple_hierarchical_branch(
			Verilog2001Parser::Simple_hierarchical_branchContext * ctx);
	static Expr * visitIdentifier(Verilog2001Parser::IdentifierContext * ctx);
	static Expr * visitEscaped_hierarchical_branch(
			Verilog2001Parser::Escaped_hierarchical_branchContext * ctx);
	static Expr * visitMintypmax_expression(
			Verilog2001Parser::Mintypmax_expressionContext * ctx);
	static std::vector<Expr*> * visitEvent_expression(
			Verilog2001Parser::Event_expressionContext * ctx);
	static Expr * visitEvent_primary(
			Verilog2001Parser::Event_primaryContext * ctx);
	static Expr * visitVariable_lvalue(
			Verilog2001Parser::Variable_lvalueContext * ctx);
	static Expr * visitVariable_concatenation(
			Verilog2001Parser::Variable_concatenationContext* ctx);
	static Expr * visitArrayed_identifier(
			Verilog2001Parser::Arrayed_identifierContext * ctx);
};

}
}
