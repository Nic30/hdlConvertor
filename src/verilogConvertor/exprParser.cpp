#include "exprParser.h"

using namespace std;
using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace verilog {

Expr * reduce(const std::vector<Expr*> & ops, OperatorType op) {
	Expr * res = nullptr;
	for (auto p : ops) {
		if (res == nullptr)
			res = p;
		else
			res = new Expr(res, op, p);
	}
	return res;
}

Expr * VerExprParser::visitConstant_expression(
		Verilog2001Parser::Constant_expressionContext * ctx) {
	// constant_expression : expression ;
	return visitExpression(ctx->expression());
}
Expr * VerExprParser::visitDimension(
		Verilog2001Parser::DimensionContext * ctx) {
	// dimension
	//    : '[' dimension_constant_expression ':' dimension_constant_expression ']'
	//    ;
	auto l = visitDimension_constant_expression(
			ctx->dimension_constant_expression(0));
	auto h = visitDimension_constant_expression(
			ctx->dimension_constant_expression(1));
	return new Expr(l, OperatorType::DOWNTO, h);
}
Expr * VerExprParser::visitDimension_constant_expression(
		Verilog2001Parser::Dimension_constant_expressionContext * ctx) {
	// dimension_constant_expression
	//    : constant_expression
	//    ;
	return visitConstant_expression(ctx->constant_expression());
}
Expr * VerExprParser::visitRange_expression(
		Verilog2001Parser::Range_expressionContext * ctx) {
	// range_expression :
	// expression
	// | msb_constant_expression ':' lsb_constant_expression
	// | base_expression '+:' width_constant_expression
	// | base_expression '-:' width_constant_expression
	// ;

	auto msb = ctx->msb_constant_expression();
	if (msb) {
		auto h = visitConstant_expression(msb->constant_expression());
		auto lsb = ctx->lsb_constant_expression();
		auto l = visitConstant_expression(lsb->constant_expression());
		return new Expr(l, OperatorType::DOWNTO, h);
	}
	// msb_constant_expression : constant_expression ;
	// lsb_constant_expression : constant_expression ;
	// width_constant_expression : constant_expression ;
	// base_expression : expression ;
	NotImplementedLogger::print("ExpressionParser.visitRange_expression");
	return nullptr;
}
Expr * VerExprParser::visitRange_(Verilog2001Parser::Range_Context * ctx) {
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
OperatorType VerExprParser::visitUnary_operator(
		Verilog2001Parser::Unary_operatorContext * ctx) {
	// unary_operator
	//    : '+'
	//    | '-'
	//    | '!'
	//    | '~'
	//    | '&'
	//    | '~&'
	//    | '|'
	//    | '~|'
	//    | '^'
	//    | '~^'
	//    | '^~'
	//    ;
	std::string op = ctx->getText();

	if (op == "+") {
		return ADD;
	} else if (op == "-") {
		return SUB;
	} else if (op == "!") {
		return NOT;
	} else if (op == "~") {
		return NEG;
	} else if (op == "&") {
		return AND;
	} else if (op == "~&") {
		return NAND;
	} else if (op == "|") {
		return OR;
	} else if (op == "~|") {
		return NOR;
	} else if (op == "^") {
		return XOR;
	} else if (op == "~^") {
		return XNOR;
	} else if (op == "^~") {
		return XNOR;
	}

	throw std::runtime_error("Unsupported unary operator " + op);
}
OperatorType VerExprParser::visitBinary_operator(
		Verilog2001Parser::Binary_operatorContext * ctx) {
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
Expr * VerExprParser::visitNet_lvalue(
		Verilog2001Parser::Net_lvalueContext * ctx) {
	// net_lvalue
	//    : hierarchical_net_identifier
	//    | hierarchical_net_identifier '[' constant_expression ']' ('[' constant_expression ']')*
	//    | hierarchical_net_identifier '[' constant_expression ']' ('[' constant_expression ']')* '[' constant_range_expression ']'
	//    | hierarchical_net_identifier '[' constant_range_expression ']'
	//    | net_concatenation
	//    ;
	auto hni = ctx->hierarchical_net_identifier();
	if (hni) {
		auto id = visitHierarchical_net_identifier(hni);
		for (auto ce : ctx->constant_expression()) {
			auto c = visitConstant_expression(ce);
			id = new Expr(id, OperatorType::INDEX, c);
		}
		return id;
	} else {
		auto nc = ctx->net_concatenation();
		return visitNet_concatenation(nc);
	}
}
Expr * VerExprParser::visitNet_concatenation(
		Verilog2001Parser::Net_concatenationContext * ctx) {
	// net_concatenation
	//    : '{' net_concatenation_value (',' net_concatenation_value)* '}'
	//    ;
	//
	// net_concatenation_value
	//    : hierarchical_net_identifier
	//    | hierarchical_net_identifier '[' expression ']' ('[' expression ']')*
	//    | hierarchical_net_identifier '[' expression ']' ('[' expression ']')* '[' range_expression ']'
	//    | hierarchical_net_identifier '[' range_expression ']'
	//    | net_concatenation
	//    ;
	// collect operands of concatenation
	vector<Expr *> parts;
	for (auto ncv : ctx->net_concatenation_value()) {
		auto hi = ncv->hierarchical_net_identifier();
		if (hi) {
			Expr * id = visitHierarchical_net_identifier(hi);
			for (auto ce : ncv->expression()) {
				auto c = visitExpression(ce);
				id = new Expr(id, OperatorType::INDEX, c);
			}
			auto re = ncv->range_expression();
			if (re) {
				auto r = visitRange_expression(re);
				id = new Expr(id, OperatorType::INDEX, r);
			}
			return id;
		} else {
			parts.push_back(visitNet_concatenation(ncv->net_concatenation()));
		}
	}

	return reduce(parts, OperatorType::CONCAT);
}
Expr * VerExprParser::visitHierarchical_net_identifier(
		Verilog2001Parser::Hierarchical_net_identifierContext * ctx) {
	// hierarchical_net_identifier
	//    : hierarchical_identifier
	//    ;
	return visitHierarchical_identifier(ctx->hierarchical_identifier());
}
Expr * VerExprParser::visitExpression(
		Verilog2001Parser::ExpressionContext * ctx) {
	// expression:
	// term
	// (
	// binary_operator attribute_instance* term
	// | '?' attribute_instance* expression ':' term
	// )*
	// ;
	antlr4::tree::ParseTree* ch;
	antlr4::tree::ParseTree* ch2 = nullptr;
	auto childs = ctx->children.begin();
	Expr * top = visitTerm((Verilog2001Parser::TermContext*) (*childs));
	childs++;
	// skip attribs
	while (childs != ctx->children.end()) {
		ch = *childs;
		childs++;
		auto binOp =
				dynamic_cast<Verilog2001Parser::Binary_operatorContext*>(ch);
		if (binOp) {
			while (true) {
				ch2 = *childs;
				childs++;
				auto aic =
						dynamic_cast<Verilog2001Parser::Attribute_instanceContext*>(ch2);
				if (aic) {
					AttributeParser::visitAttribute_instance(aic);
				} else {
					break;
				}
			}
			top = new Expr(top, visitBinary_operator(binOp),
					visitTerm((Verilog2001Parser::TermContext*) ch2));
		} else {
			while (true) {
				ch2 = *childs;
				childs++;
				auto _aic =
						dynamic_cast<Verilog2001Parser::Attribute_instanceContext*>(ch2);
				if (_aic) {
					AttributeParser::visitAttribute_instance(_aic);
				} else {
					break;
				}
			}
			childs++; // consume ":"
			auto ifTrue = visitExpression(
					dynamic_cast<Verilog2001Parser::ExpressionContext*>(ch2));
			assert(ifTrue);
			auto ifFalse = visitTerm(
					dynamic_cast<Verilog2001Parser::TermContext*>(*childs));
			assert(ifFalse);
			top = Expr::ternary(top, ifTrue, ifFalse);
			childs++;
		}
	}

	return top;
}
Expr * VerExprParser::visitTerm(Verilog2001Parser::TermContext* ctx) {
	// term :
	// unary_operator attribute_instance* primary
	// | primary
	// | String
	// ;
	auto p = ctx->primary();
	if (p) {
		auto e = visitPrimary(p);
		auto uOp = ctx->unary_operator();
		if (uOp) {
			auto o = visitUnary_operator(uOp);
			return new Expr(e, o, nullptr);
		} else {
			return e;
		}
	}
	auto s = ctx->String();
	return VerLiteralParser::visitString(s);
}
Expr * VerExprParser::visitPrimary(Verilog2001Parser::PrimaryContext* ctx) {
	// primary :
	// number
	// | hierarchical_identifier
	// | hierarchical_identifier ( '[' expression ']' )+
	// | hierarchical_identifier ( '[' expression ']' )+ '[' range_expression ']'
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
		Verilog2001Parser::Constant_function_callContext* ctx) {
	// constant_function_call :
	// function_identifier attribute_instance* '('
	// (constant_expression ( ',' constant_expression )*)? ')'
	// ;
	NotImplementedLogger::print("ExpressionParser.visitConstant_function_call");
	return NULL;
}
Expr * VerExprParser::visitSystem_function_call(
		Verilog2001Parser::System_function_callContext* ctx) {
	// system_function_call :
	// system_function_identifier (expression ( ',' expression )*)?
	// ;
	NotImplementedLogger::print("ExpressionParser.visitSystem_function_call");
	return NULL;
}
Expr * VerExprParser::visitFunction_call(
		Verilog2001Parser::Function_callContext* ctx) {
	// function_call
	// : hierarchical_function_identifier attribute_instance*
	// '(' (expression ( ',' expression )*)? ')'
	// ;
	NotImplementedLogger::print("ExpressionParser.visitFunction_call");
	return NULL;
}
Expr * VerExprParser::visitMultiple_concatenation(
		Verilog2001Parser::Multiple_concatenationContext * ctx) {
	// multiple_concatenation : '{' constant_expression concatenation '}' ;
	auto ce = visitConstant_expression(ctx->constant_expression());
	auto c = visitConcatenation(ctx->concatenation());
	return new Expr(ce, OperatorType::REPL_CONCAT, c);
}
Expr * VerExprParser::visitConcatenation(
		Verilog2001Parser::ConcatenationContext * ctx) {
	// concatenation : '{' expression ( ',' expression )* '}' ;
	Expr * res = nullptr;
	for (auto e : ctx->expression()) {
		auto p = VerExprParser::visitExpression(e);
		if (res == nullptr)
			res = p;
		else
			res = new Expr(res, OperatorType::CONCAT, p);
	}
	return res;
}
Expr * VerExprParser::visitHierarchical_identifier(
		Verilog2001Parser::Hierarchical_identifierContext* ctx) {
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
		Verilog2001Parser::Escaped_hierarchical_identifierContext * ctx) {
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
			auto ehbc =
					dynamic_cast<Verilog2001Parser::Escaped_hierarchical_branchContext*>(ch);
			if (ehbc) {
				second = visitEscaped_hierarchical_branch(ehbc);
			} else {
				auto shbc =
						dynamic_cast<Verilog2001Parser::Simple_hierarchical_branchContext*>(ch);
				assert(shbc);
				second = visitSimple_hierarchical_branch(shbc);
			}
			top = new Expr(top, DOT, second);
		}
	}
	return top;
}
Expr * VerExprParser::visitSimple_hierarchical_identifier(
		Verilog2001Parser::Simple_hierarchical_identifierContext * ctx) {
	// simple_hierarchical_identifier : simple_hierarchical_branch ( '.'
	// Escaped_identifier )? ;
	Expr * shb = visitSimple_hierarchical_branch(
			ctx->simple_hierarchical_branch());
	auto ei = ctx->Escaped_identifier();
	if (ei) {
		return new Expr(shb, OperatorType::DOT,
				VerLiteralParser::parseEscaped_identifier(ei));
	}
	return shb;
}
Expr * VerExprParser::visitSimple_hierarchical_branch(
		Verilog2001Parser::Simple_hierarchical_branchContext * ctx) {
	// simple_hierarchical_branch :
	// Simple_identifier ( '[' Decimal_number ']' )?
	// ( '.' Simple_identifier ( '[' Decimal_number ']' )? )*
	// ;
	Expr * top = nullptr;
	bool next_is_dot_index = false;
	bool next_is_index = false;
	for (auto ch : ctx->children) {
		if (top == nullptr) {
			top = VerLiteralParser::parseSimple_identifier(
					dynamic_cast<antlr4::tree::TerminalNode*>(ch));
		} else {
			if (next_is_dot_index) {
				auto id = VerLiteralParser::parseSimple_identifier(
						dynamic_cast<antlr4::tree::TerminalNode*>(ch));
				top = new Expr(top, OperatorType::DOT, id);
				next_is_dot_index = false;
			} else if (next_is_index) {
				auto i = VerLiteralParser::parseIntNumber(
						dynamic_cast<antlr4::tree::TerminalNode*>(ch), 10);
				top = new Expr(top, OperatorType::INDEX, i);
				next_is_index = false;
			} else {
				auto t = ch->getText();
				if (t == "[")
					next_is_index = true;
				else if (t == ".")
					next_is_dot_index = true;
			}
		}

	}
	return top;
}
Expr * VerExprParser::visitIdentifier(
		Verilog2001Parser::IdentifierContext * ctx) {
	// identifier
	//    : Simple_identifier
	//    | Escaped_identifier
	//    ;
	auto sid = ctx->Simple_identifier();
	if (sid)
		return VerLiteralParser::parseSimple_identifier(sid);
	else
		return VerLiteralParser::parseEscaped_identifier(sid);
}
Expr * VerExprParser::visitEscaped_hierarchical_branch(
		Verilog2001Parser::Escaped_hierarchical_branchContext * ctx) {
	// escaped_hierarchical_branch :
	// Escaped_identifier ( '[' Decimal_number ']' )?
	// ( '.' Escaped_identifier ( '[' Decimal_number ']' )? )*
	// ;
	NotImplementedLogger::print(
			"ExpressionParser.visitEscaped_hierarchical_branch");
	return NULL;
}
Expr * VerExprParser::visitMintypmax_expression(
		Verilog2001Parser::Mintypmax_expressionContext* ctx) {
	// mintypmax_expression
	// : expression (':' expression ':' expression)?
	// ;
	if (ctx->expression().size() > 1) {
		NotImplementedLogger::print(
				"ExpressionParser.visitMintypmax_expression - type and max specified");
	}
	return visitExpression(ctx->expression(0));
}

std::vector<Expr*> * VerExprParser::visitEvent_expression(
		Verilog2001Parser::Event_expressionContext * ctx) {
	// event_expression
	//    : event_primary ('or' event_primary | ',' event_primary)*
	//    ;
	auto res = new std::vector<Expr*>;
	Expr * actual_exp = nullptr;
	for (auto child : ctx->children) {
		auto ep = dynamic_cast<Verilog2001Parser::Event_primaryContext *>(child);
		if (ep) {
			auto new_e = visitEvent_primary(ep);
			if (actual_exp == nullptr) {
				actual_exp = new_e;
			} else {
				actual_exp = new Expr(actual_exp, OperatorType::OR, new_e);
			}
		} else if (child->getText() == ",") {
			res->push_back(actual_exp);
			actual_exp = nullptr;
		}
	}
	if (actual_exp)
		res->push_back(actual_exp);
	return res;
}

Expr * VerExprParser::visitEvent_primary(
		Verilog2001Parser::Event_primaryContext * ctx) {
	// event_primary
	//    : (expression | 'posedge' expression | 'negedge' expression)
	//    ;
	auto first_as_expr =
			dynamic_cast<Verilog2001Parser::ExpressionContext*>(ctx->children[0]);
	if (first_as_expr) {
		return visitExpression(first_as_expr);
	} else {
		auto expr =
				dynamic_cast<Verilog2001Parser::ExpressionContext*>(ctx->children[1]);
		OperatorType o;
		if (ctx->children[0]->getText() == "posedge") {
			o = OperatorType::RISING;
		} else {
			o = OperatorType::FALLING;
		}
		return new Expr(visitExpression(expr), o, nullptr);
	}
}

Expr * VerExprParser::visitVariable_lvalue(
		Verilog2001Parser::Variable_lvalueContext * ctx) {
	// variable_lvalue
	//    : hierarchical_variable_identifier
	//    | hierarchical_variable_identifier '[' expression ']' ('[' expression ']')*
	//    | hierarchical_variable_identifier '[' expression ']' ('[' expression ']')* '[' range_expression ']'
	//    | hierarchical_variable_identifier '[' range_expression ']'
	//    | variable_concatenation
	//    ;

	// hierarchical_variable_identifier
	//    : hierarchical_identifier
	//    ;
	auto hi =
			ctx->hierarchical_variable_identifier()->hierarchical_identifier();
	if (hi) {
		auto id = visitHierarchical_identifier(hi);
		for (auto e : ctx->expression()) {
			auto expr = visitExpression(e);
			id = new Expr(id, OperatorType::INDEX, expr);
		}
		return id;
	} else {
		auto vc = ctx->variable_concatenation();
		return visitVariable_concatenation(vc);
	}
}

Expr * VerExprParser::visitVariable_concatenation(
		Verilog2001Parser::Variable_concatenationContext* ctx) {
	// variable_concatenation
	//    : '{' variable_concatenation_value (',' variable_concatenation_value)* '}'
	//    ;
	//
	// variable_concatenation_value
	//    : hierarchical_variable_identifier
	//    | hierarchical_variable_identifier '[' expression ']' ('[' expression ']')*
	//    | hierarchical_variable_identifier '[' expression ']' ('[' expression ']')* '[' range_expression ']'
	//    | hierarchical_variable_identifier '[' range_expression ']'
	//    | variable_concatenation
	//    ;
	// collect operands of concatenation
	vector<Expr *> parts;
	for (auto ncv : ctx->variable_concatenation_value()) {
		auto hi =
				ncv->hierarchical_variable_identifier()->hierarchical_identifier();
		if (hi) {
			Expr * id = visitHierarchical_identifier(hi);
			for (auto ce : ncv->expression()) {
				auto c = visitExpression(ce);
				id = new Expr(id, OperatorType::INDEX, c);
			}
			auto re = ncv->range_expression();
			if (re) {
				auto r = visitRange_expression(re);
				id = new Expr(id, OperatorType::INDEX, r);
			}
			return id;
		} else {
			parts.push_back(
					visitVariable_concatenation(ncv->variable_concatenation()));
		}
	}

	return reduce(parts, OperatorType::CONCAT);
}

Expr * VerExprParser::visitArrayed_identifier(
		Verilog2001Parser::Arrayed_identifierContext * ctx) {
	// arrayed_identifier
	//    : simple_arrayed_identifier
	//    | escaped_arrayed_identifier
	//    ;
	{
		auto sai = ctx->simple_arrayed_identifier();
		// simple_arrayed_identifier
		//    : Simple_identifier (range_)?
		//    ;
		if (sai) {
			auto e = VerLiteralParser::parseSimple_identifier(
					sai->Simple_identifier());
			auto _r = sai->range_();
			if (_r) {
				auto r = visitRange_(_r);
				e = new Expr(e, OperatorType::INDEX, r);
			}
			return e;
		}
	}
	auto eai = ctx->escaped_arrayed_identifier();
	// escaped_arrayed_identifier
	//    : Escaped_identifier (range_)?
	//    ;
	auto e = VerLiteralParser::parseEscaped_identifier(
			eai->Escaped_identifier());
	auto _r = eai->range_();
	if (_r) {
		auto r = visitRange_(_r);
		e = new Expr(e, OperatorType::INDEX, r);
	}
	return e;

}

}
}
