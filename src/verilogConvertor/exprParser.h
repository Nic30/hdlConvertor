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
			Ref<Verilog2001Parser::ExpressionContext> ctx);
	static Expr * visitConstant_expression(
			Ref<Verilog2001Parser::Constant_expressionContext> ctx);
	static Expr * visitRange_expression(
			Ref<Verilog2001Parser::Range_expressionContext> ctx);
	static Expr * visitRange(Ref<Verilog2001Parser::RangeContext> ctx);
	static OperatorType visitBinary_operator(
			Ref<Verilog2001Parser::Binary_operatorContext> ctx);
	static Expr * visitTerm(Ref<Verilog2001Parser::TermContext> ctx);
	static Expr * visitPrimary(Ref<Verilog2001Parser::PrimaryContext> ctx);
	static Expr * visitConstant_function_call(
			Ref<Verilog2001Parser::Constant_function_callContext> ctx);
	static Expr * visitSystem_function_call(
			Ref<Verilog2001Parser::System_function_callContext> ctx);
	static Expr * visitFunction_call(
			Ref<Verilog2001Parser::Function_callContext> ctx);
	static Expr * visitMultiple_concatenation(
			Ref<Verilog2001Parser::Multiple_concatenationContext> ctx);
	static Expr * visitConcatenation(
			Ref<Verilog2001Parser::ConcatenationContext> ctx);
	static Expr * visitHierarchical_identifier(
			Ref<Verilog2001Parser::Hierarchical_identifierContext> ctx);
	static Expr * visitEscaped_hierarchical_identifier(
			Ref<Verilog2001Parser::Escaped_hierarchical_identifierContext> ctx);
	static Expr * visitSimple_hierarchical_identifier(
			Ref<Verilog2001Parser::Simple_hierarchical_identifierContext> ctx);
	static Expr * visitSimple_hierarchical_branch(
			Ref<Verilog2001Parser::Simple_hierarchical_branchContext> ctx);

	static Expr * visitEscaped_hierarchical_branch(
			Ref<Verilog2001Parser::Escaped_hierarchical_branchContext> ctx);
	static Expr * visitMintypmax_expression(
			Ref<Verilog2001Parser::Mintypmax_expressionContext> ctx);
};
