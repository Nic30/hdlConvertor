#pragma once

#include <antlr4-runtime.h>
#include <vector>
#include <string>
#include <memory>

#include "../VerilogParser/Verilog2001Parser.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/expr.h"
#include "../notImplementedLogger.h"
#include "literalParser.h"
#include "attributeParser.h"

using namespace antlr4;
using namespace verilog;

class VerExprParser {
public:
	static Expr * visitExpression(
			Verilog2001Parser::ExpressionContext * ctx);
	static Expr * visitConstant_expression(
			Verilog2001Parser::Constant_expressionContext * ctx);
	static Expr * visitRange_expression(
			Verilog2001Parser::Range_expressionContext * ctx);
	static Expr * visitRange(Verilog2001Parser::RangeContext * ctx);
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

	static Expr * visitEscaped_hierarchical_branch(
			Verilog2001Parser::Escaped_hierarchical_branchContext * ctx);
	static Expr * visitMintypmax_expression(
			Verilog2001Parser::Mintypmax_expressionContext * ctx);
};
