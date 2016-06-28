#include "exprParser.h"

Expr * VerExprParser::visitConstant_expression(
		Ref<Verilog2001Parser::Constant_expressionContext> ctx) {
	// constant_expression : expression ;
	return visitExpression(ctx->expression());
}
Expr * VerExprParser::visitRange_expression(
		Ref<Verilog2001Parser::Range_expressionContext> ctx) {
	// range_expression :
	// expression
	// | msb_constant_expression ':' lsb_constant_expression
	// | base_expression '+:' width_constant_expression
	// | base_expression '-:' width_constant_expression
	// ;

	// msb_constant_expression : constant_expression ;
	// lsb_constant_expression : constant_expression ;
	// width_constant_expression : constant_expression ;
	// base_expression : expression ;
	NotImplementedLogger::print("ExpressionParser.visitRange_expression");
	return NULL;
}
Expr * VerExprParser::visitRange(Ref<Verilog2001Parser::RangeContext> ctx) {
	// range : '[' msb_constant_expression ':' lsb_constant_expression ']' ;
	// msb_constant_expression : constant_expression ;
	// lsb_constant_expression : constant_expression ;
	return new Expr(
			visitConstant_expression(
					ctx->msb_constant_expression()->constant_expression()),
			DOWNTO,
			visitConstant_expression(
					ctx->lsb_constant_expression()->constant_expression()));

}
OperatorType VerExprParser::visitBinary_operator(
		Ref<Verilog2001Parser::Binary_operatorContext> ctx) {
	// binary_operator : '+' | '-' | '*' | '/' | '%' | '==' | '!=' | '===' |
	// '!==' | '&&' | '||' | '**' | '<' | '<=' | '>' | '>=' | '&' | '|' |
	// '^' | '^~' | '~^' | '>>' | '<<' | '>>>' | '<<<' ;
	// [TODO] log eq, neq
	std::string op = ctx->getText();

	if (op.compare("+") == 0)
		return ADD;
	else if (op.compare("-") == 0)
		return SUB;
	else if (op.compare("*") == 0)
		return MUL;
	else if (op.compare("/") == 0)
		return DIV;
	else if (op.compare("%") == 0)
		return MOD;
	else if (op.compare("==") == 0 || op.compare("===") == 0)
		return EQ;
	else if (op.compare("!=") == 0 || op.compare("!==") == 0)
		return NEQ;
	else if (op.compare("&&") == 0)
		return LOG_AND;
	else if (op.compare("||") == 0)
		return LOG_OR;
	else if (op.compare("**") == 0)
		return POW;
	else if (op.compare("<") == 0)
		return LOWERTHAN;
	else if (op.compare("<=") == 0)
		return LE;
	else if (op.compare(">") == 0)
		return GREATERTHAN;
	else if (op.compare(">=") == 0)
		return GE;
	else if (op.compare("&") == 0)
		return AND;
	else if (op.compare("|") == 0)
		return OR;
	else if (op.compare("^") == 0)
		return XOR;
	else if (op.compare("^~") == 0 || op.compare("~^") == 0
			|| op.compare(">>") == 0)
		return SRL;
	else if (op.compare("<<") == 0)
		return SLL;
	else if (op.compare(">>>") == 0)
		return SRA;

	assert(op.compare("<<<") == 0);
	return SLA;

}
Expr * VerExprParser::visitExpression(
		Ref<Verilog2001Parser::ExpressionContext> ctx) {
	// expression:
	// term
	// (
	// binary_operator attribute_instance* term
	// | '?' attribute_instance* expression ':' term
	// )*
	// ;
	Ref<antlr4::tree::ParseTree> ch;
	Ref<antlr4::tree::ParseTree> ch2 = NULL;
	auto childs = ctx->children.begin();
	Expr * top = visitTerm(
			std::dynamic_pointer_cast<Verilog2001Parser::TermContext>(*childs));
	childs++;
	// skip attribs
	while (childs != ctx->children.end()) {
		ch = *childs;
		childs++;
		auto binOp = std::dynamic_pointer_cast<
				Verilog2001Parser::Binary_operatorContext>(ch);
		if (binOp) {
			while (true) {
				ch2 = *childs;
				childs++;
				auto aic = std::dynamic_pointer_cast<
						Verilog2001Parser::Attribute_instanceContext>(ch2);
				if (aic) {
					AttributeParser::visitAttribute_instance(aic);
				} else {
					break;
				}
			}
			top = new Expr(top, visitBinary_operator(binOp),
					visitTerm(
							std::dynamic_pointer_cast<
									Verilog2001Parser::TermContext>(ch2)));
		} else {
			while (true) {
				ch2 = *childs;
				childs++;
				auto _aic = std::dynamic_pointer_cast<
						Verilog2001Parser::Attribute_instanceContext>(ch2);
				if (_aic) {
					AttributeParser::visitAttribute_instance(_aic);
				} else {
					break;
				}
			}
			childs++; // consume ":"
			auto ifTrue = visitExpression(
					std::dynamic_pointer_cast<
							Verilog2001Parser::ExpressionContext>(ch2));
			assert(ifTrue);
			auto ifFalse = visitTerm(
					std::dynamic_pointer_cast<Verilog2001Parser::TermContext>(
							*childs));
			assert(ifFalse);
			top = Expr::ternary(top, ifTrue, ifFalse);
			childs++;
		}
	}

	return top;
}
Expr * VerExprParser::visitTerm(Ref<Verilog2001Parser::TermContext> ctx) {
// term :
// unary_operator attribute_instance* primary
// | primary
// | String
// ;
	auto uOp = ctx->unary_operator();
	if (uOp) {
		NotImplementedLogger::print(
				"ExpressionParser.visitTerm - unary_operator");
		return NULL;
	}
	auto p = ctx->primary();
	if (p)
		return visitPrimary(p);
	return VerLiteralParser::visitString(ctx->String());
}
Expr * VerExprParser::visitPrimary(Ref<Verilog2001Parser::PrimaryContext> ctx) {
// primary :
// number
// | hierarchical_identifier
// | hierarchical_identifier ( '[' expression ']' )+
// | hierarchical_identifier ( '[' expression ']' )+ '['
// range_expression
// ']'
// | hierarchical_identifier '[' range_expression ']'
// | concatenation
// | multiple_concatenation
// | function_call
// | system_function_call
// | constant_function_call
// | '(' mintypmax_expression ')'
// ;
	auto n = ctx->number();
	if (n)
		return VerLiteralParser::visitNumber(n);

	auto hi = ctx->hierarchical_identifier();
	if (hi) {
		Expr * top = visitHierarchical_identifier(hi);
		for (auto ex : ctx->expression()) {
			top = new Expr(top, INDEX, visitExpression(ex));
		}
		auto r = ctx->range_expression();
		if (r) {
			top = new Expr(top, INDEX, visitRange_expression(r));
		}
		return top;
	}

	auto c = ctx->concatenation();
	if (c) {
		return visitConcatenation(c);
	}
	auto mc = ctx->multiple_concatenation();
	if (mc) {
		return visitMultiple_concatenation(mc);
	}

	auto fc = ctx->function_call();
	if (fc) {
		return visitFunction_call(fc);
	}
	auto sfc = ctx->system_function_call();
	if (sfc) {
		return visitSystem_function_call(sfc);
	}
	auto cfc = ctx->constant_function_call();
	if (cfc) {
		return visitConstant_function_call(cfc);
	}
	return visitMintypmax_expression(ctx->mintypmax_expression());
}
Expr * VerExprParser::visitConstant_function_call(
		Ref<Verilog2001Parser::Constant_function_callContext> ctx) {
// constant_function_call :
// function_identifier attribute_instance* '('
// (constant_expression ( ',' constant_expression )*)? ')'
// ;
	NotImplementedLogger::print("ExpressionParser.visitConstant_function_call");
	return NULL;
}
Expr * VerExprParser::visitSystem_function_call(
		Ref<Verilog2001Parser::System_function_callContext> ctx) {
// system_function_call :
// system_function_identifier (expression ( ',' expression )*)?
// ;
	NotImplementedLogger::print("ExpressionParser.visitSystem_function_call");
	return NULL;
}
Expr * VerExprParser::visitFunction_call(
		Ref<Verilog2001Parser::Function_callContext> ctx) {
// function_call
// : hierarchical_function_identifier attribute_instance*
// '(' (expression ( ',' expression )*)? ')'
// ;
	NotImplementedLogger::print("ExpressionParser.visitFunction_call");
	return NULL;
}
Expr * VerExprParser::visitMultiple_concatenation(
		Ref<Verilog2001Parser::Multiple_concatenationContext> ctx) {
// multiple_concatenation : '{' constant_expression concatenation '}' ;
	NotImplementedLogger::print("ExpressionParser.visitMultiple_concatenation");
	return NULL;
}
Expr * VerExprParser::visitConcatenation(
		Ref<Verilog2001Parser::ConcatenationContext> ctx) {
// concatenation : '{' expression ( ',' expression )* '}' ;
	NotImplementedLogger::print("ExpressionParser.visitConcatenation");
	return NULL;
}
Expr * VerExprParser::visitHierarchical_identifier(
		Ref<Verilog2001Parser::Hierarchical_identifierContext> ctx) {
// hierarchical_identifier :
// simple_hierarchical_identifier
// | escaped_hierarchical_identifier
// ;
	auto s = ctx->simple_hierarchical_identifier();
	if (s)
		return visitSimple_hierarchical_identifier(s);
	else
		return visitEscaped_hierarchical_identifier(
				ctx->escaped_hierarchical_identifier());
}
Expr * VerExprParser::visitEscaped_hierarchical_identifier(
		Ref<Verilog2001Parser::Escaped_hierarchical_identifierContext> ctx) {
// escaped_hierarchical_identifier :
// escaped_hierarchical_branch ( '.' simple_hierarchical_branch | '.'
// escaped_hierarchical_branch )*
// ;
	Expr * top = NULL;
	for (auto ch : ctx->children) {
		if (!top)
			top = visitEscaped_hierarchical_branch(
					ctx->escaped_hierarchical_branch(0));
		else {
			Expr * second;
			auto ehbc = std::dynamic_pointer_cast<
					Verilog2001Parser::Escaped_hierarchical_branchContext>(ch);
			if (ehbc) {
				second = visitEscaped_hierarchical_branch(ehbc);
			} else {
				auto shbc = std::dynamic_pointer_cast<
						Verilog2001Parser::Simple_hierarchical_branchContext>(
						ch);
				assert(shbc);
				second = visitSimple_hierarchical_branch(shbc);
			}
			top = new Expr(top, DOT, second);
		}
	}
	return top;
}
Expr * VerExprParser::visitSimple_hierarchical_identifier(
		Ref<Verilog2001Parser::Simple_hierarchical_identifierContext> ctx) {
// simple_hierarchical_identifier : simple_hierarchical_branch ( '.'
// Escaped_identifier )? ;
	Expr * shb = visitSimple_hierarchical_branch(
			ctx->simple_hierarchical_branch());
// [TODO] Escaped_identifier
	return shb;
}
Expr * VerExprParser::visitSimple_hierarchical_branch(
		Ref<Verilog2001Parser::Simple_hierarchical_branchContext> ctx) {
// simple_hierarchical_branch :
// Simple_identifier ( '[' Decimal_number ']' )?
// ( '.' Simple_identifier ( '[' Decimal_number ']' )? )*
// ;
	Expr * top = NULL;
	for (auto ch : ctx->children) {
		if (!top) {
			top = VerLiteralParser::parseSimple_identifier(
					std::dynamic_pointer_cast<antlr4::tree::TerminalNode>(ch));
		} else {
			NotImplementedLogger::print(
					"ExpressionParser.visitSimple_hierarchical_branch");
		}

	}
	return top;
}

Expr * VerExprParser::visitEscaped_hierarchical_branch(
		Ref<Verilog2001Parser::Escaped_hierarchical_branchContext> ctx) {
// escaped_hierarchical_branch :
// Escaped_identifier ( '[' Decimal_number ']' )?
// ( '.' Escaped_identifier ( '[' Decimal_number ']' )? )*
// ;
	NotImplementedLogger::print(
			"ExpressionParser.visitEscaped_hierarchical_branch");
	return NULL;
}
Expr * VerExprParser::visitMintypmax_expression(
		Ref<Verilog2001Parser::Mintypmax_expressionContext> ctx) {
// mintypmax_expression
// : expression (':' expression ':' expression)?
// ;
	if (ctx->expression().size() > 1) {
		NotImplementedLogger::print(
				"ExpressionParser.visitMintypmax_expression - type and max specified");
	}
	return visitExpression(ctx->expression(0));
}
