#include <hdlConvertor/verilogConvertor/exprParser.h>

#include <antlr4-runtime.h>

#include <hdlConvertor/verilogConvertor/moduleParamParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace verilog {

using namespace std;
using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;

iHdlExpr * reduce(const std::vector<iHdlExpr*> & ops, HdlOperatorType op) {
	iHdlExpr * res = nullptr;
	for (auto p : ops) {
		if (res == nullptr)
			res = p;
		else
			res = new iHdlExpr(res, op, p);
	}
	return res;
}

iHdlExpr * VerExprParser::visitConstant_expression(
		Verilog2001Parser::Constant_expressionContext * ctx) {
	// constant_expression : expression ;
	return visitExpression(ctx->expression());
}
iHdlExpr * VerExprParser::visitDimension(
		Verilog2001Parser::DimensionContext * ctx) {
	// dimension
	//    : '[' dimension_constant_expression ':' dimension_constant_expression ']'
	//    ;
	auto l = visitDimension_constant_expression(
			ctx->dimension_constant_expression(0));
	auto h = visitDimension_constant_expression(
			ctx->dimension_constant_expression(1));
	return new iHdlExpr(l, HdlOperatorType::DOWNTO, h);
}
iHdlExpr * VerExprParser::visitDimension_constant_expression(
		Verilog2001Parser::Dimension_constant_expressionContext * ctx) {
	// dimension_constant_expression
	//    : constant_expression
	//    ;
	return visitConstant_expression(ctx->constant_expression());
}
iHdlExpr * VerExprParser::visitRange_expression(
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
		return new iHdlExpr(l, HdlOperatorType::DOWNTO, h);
	}
	// msb_constant_expression : constant_expression ;
	// lsb_constant_expression : constant_expression ;
	// width_constant_expression : constant_expression ;
	// base_expression : expression ;
	NotImplementedLogger::print("VerExprParser.visitRange_expression", ctx);
	return nullptr;
}
iHdlExpr * VerExprParser::visitRange_(Verilog2001Parser::Range_Context * ctx) {
	// range : '[' msb_constant_expression ':' lsb_constant_expression ']' ;
	// msb_constant_expression : constant_expression ;
	// lsb_constant_expression : constant_expression ;
	return new iHdlExpr(
			visitConstant_expression(
					ctx->msb_constant_expression()->constant_expression()),
			DOWNTO,
			visitConstant_expression(
					ctx->lsb_constant_expression()->constant_expression()));

}

iHdlExpr * VerExprParser::visitNet_lvalue(
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
			id = new iHdlExpr(id, HdlOperatorType::INDEX, c);
		}
		return id;
	} else {
		auto nc = ctx->net_concatenation();
		return visitNet_concatenation(nc);
	}
}
iHdlExpr * VerExprParser::visitNet_concatenation(
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
	vector<iHdlExpr *> parts;
	auto ncvs = ctx->net_concatenation_value();
	assert(ncvs.size());
	for (auto ncv : ncvs) {
		auto hi = ncv->hierarchical_net_identifier();
		if (hi) {
			iHdlExpr * id = visitHierarchical_net_identifier(hi);
			for (auto ce : ncv->expression()) {
				auto c = visitExpression(ce);
				id = new iHdlExpr(id, HdlOperatorType::INDEX, c);
			}
			auto re = ncv->range_expression();
			if (re) {
				auto r = visitRange_expression(re);
				id = new iHdlExpr(id, HdlOperatorType::INDEX, r);
			}
			parts.push_back(id);
		} else {
			auto _nc = ncv->net_concatenation();
			auto nc = visitNet_concatenation(_nc);
			parts.push_back(nc);
		}
	}

	return reduce(parts, HdlOperatorType::CONCAT);
}
iHdlExpr * VerExprParser::visitHierarchical_net_identifier(
		Verilog2001Parser::Hierarchical_net_identifierContext * ctx) {
	// hierarchical_net_identifier
	//    : hierarchical_identifier
	//    ;
	return visitHierarchical_identifier(ctx->hierarchical_identifier());
}
iHdlExpr * VerExprParser::visitDelay_control(
		Verilog2001Parser::Delay_controlContext * ctx) {
	// delay_control
	//    : '#' delay_value
	//    | '#' '(' mintypmax_expression ')'
	//    ;
	auto dv = ctx->delay_value();
	if (dv)
		return visitDelay_value(dv);
	else {
		auto me = ctx->mintypmax_expression();
		return visitMintypmax_expression(me);
	}

}
iHdlExpr * VerExprParser::visitDelay_value(
		Verilog2001Parser::Delay_valueContext * ctx) {
	// delay_value
	//    : Decimal_number
	//    | parameter_identifier
	//    | specparam_identifier
	//    | mintypmax_expression
	//    ;
	auto dn = ctx->Decimal_number();
	if (dn) {
		return VerLiteralParser::parseIntNumber(dn, 10);
	}
	auto pi = ctx->parameter_identifier();
	if (pi) {
		ModuleParamParser::visitParameter_identifier(pi);
	}
	auto si = ctx->specparam_identifier();
	if (si)
		return visitSpecparam_identifier(si);
	auto me = ctx->mintypmax_expression();
	assert(me);
	return visitMintypmax_expression(me);

}
iHdlExpr * VerExprParser::visitSpecparam_identifier(
		Verilog2001Parser::Specparam_identifierContext * ctx) {
	// specparam_identifier
	//    : identifier
	//    ;
	return visitIdentifier(ctx->identifier());
}

iHdlExpr * VerExprParser::visitExpression(
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
	iHdlExpr * top = visitTerm((Verilog2001Parser::TermContext*) (*childs));
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
			top = new iHdlExpr(top, VerLiteralParser::visitBinary_operator(binOp),
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
			top = iHdlExpr::ternary(top, ifTrue, ifFalse);
			childs++;
		}
	}

	return top;
}
iHdlExpr * VerExprParser::visitTerm(Verilog2001Parser::TermContext* ctx) {
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
			auto o = VerLiteralParser::visitUnary_operator(uOp);
			return new iHdlExpr(e, o, nullptr);
		} else {
			return e;
		}
	}
	auto s = ctx->String();
	return VerLiteralParser::visitString(s);
}
iHdlExpr * VerExprParser::visitPrimary(Verilog2001Parser::PrimaryContext* ctx) {
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
		iHdlExpr * top = visitHierarchical_identifier(hi);
		for (auto ex : ctx->expression()) {
			top = new iHdlExpr(top, INDEX, visitExpression(ex));
		}
		auto r = ctx->range_expression();
		if (r) {
			top = new iHdlExpr(top, INDEX, visitRange_expression(r));
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
iHdlExpr * VerExprParser::visitConstant_function_call(
		Verilog2001Parser::Constant_function_callContext* ctx) {
	// constant_function_call :
	// function_identifier attribute_instance* '('
	// (constant_expression ( ',' constant_expression )*)? ')'
	// ;
	if (ctx->attribute_instance().size()) {
		NotImplementedLogger::print(
				"VerExprParser.visitConstant_function_call - attribute_instance", ctx);
	}

	auto fi = ctx->function_identifier();
	iHdlExpr * fn = visitFunction_identifier(fi);
	std::vector<iHdlExpr*> args;
	auto exprs = ctx->constant_expression();
	for (auto e : exprs) {
		iHdlExpr * a = visitConstant_expression(e);
		args.push_back(a);
	}
	return iHdlExpr::call(fn, args);
}
iHdlExpr * VerExprParser::visitFunction_identifier(
		Verilog2001Parser::Function_identifierContext * ctx) {
	// function_identifier
	//    : identifier
	//    ;
	return visitIdentifier(ctx->identifier());
}
iHdlExpr * VerExprParser::visitSystem_function_identifier(
		Verilog2001Parser::System_function_identifierContext *ctx) {
	// system_function_identifier
	//    : Dollar_Identifier
	//    ;
	return VerLiteralParser::visitDolar_identifier(ctx->Dollar_Identifier());
}
iHdlExpr * VerExprParser::visitSystem_function_call(
		Verilog2001Parser::System_function_callContext* ctx) {
	// system_function_call :
	// system_function_identifier (expression ( ',' expression )*)?
	// ;
	auto sfi = ctx->system_function_identifier();
	iHdlExpr * fn = visitSystem_function_identifier(sfi);
	std::vector<iHdlExpr*> args;
	auto exprs = ctx->expression();
	for (auto e : exprs) {
		iHdlExpr * a = visitExpression(e);
		args.push_back(a);
	}
	return iHdlExpr::call(fn, args);
}
iHdlExpr * VerExprParser::visitFunction_call(
		Verilog2001Parser::Function_callContext* ctx) {
	// function_call
	// : hierarchical_function_identifier attribute_instance*
	// '(' (expression ( ',' expression )*)? ')'
	// ;
	if (ctx->attribute_instance().size()) {
		NotImplementedLogger::print(
				"VerExprParser.visitFunction_call - attribute_instance", ctx);
	}
	auto hfi = ctx->hierarchical_function_identifier();
	iHdlExpr * fn = visitHierarchical_function_identifier(hfi);
	std::vector<iHdlExpr*> args;
	auto exprs = ctx->expression();
	for (auto e : exprs) {
		iHdlExpr * a = visitExpression(e);
		args.push_back(a);
	}
	return iHdlExpr::call(fn, args);
}
iHdlExpr * VerExprParser::visitHierarchical_function_identifier(
		Verilog2001Parser::Hierarchical_function_identifierContext * ctx) {
	// hierarchical_function_identifier
	//    : hierarchical_identifier
	//    ;
	return visitHierarchical_identifier(ctx->hierarchical_identifier());
}
iHdlExpr * VerExprParser::visitMultiple_concatenation(
		Verilog2001Parser::Multiple_concatenationContext * ctx) {
	// multiple_concatenation : '{' constant_expression concatenation '}' ;
	auto ce = visitConstant_expression(ctx->constant_expression());
	auto c = visitConcatenation(ctx->concatenation());
	return new iHdlExpr(ce, HdlOperatorType::REPL_CONCAT, c);
}
iHdlExpr * VerExprParser::visitConcatenation(
		Verilog2001Parser::ConcatenationContext * ctx) {
	// concatenation : '{' expression ( ',' expression )* '}' ;
	iHdlExpr * res = nullptr;
	for (auto e : ctx->expression()) {
		auto p = VerExprParser::visitExpression(e);
		if (res == nullptr)
			res = p;
		else
			res = new iHdlExpr(res, HdlOperatorType::CONCAT, p);
	}
	return res;
}
iHdlExpr * VerExprParser::visitHierarchical_identifier(
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
iHdlExpr * VerExprParser::visitEscaped_hierarchical_identifier(
		Verilog2001Parser::Escaped_hierarchical_identifierContext * ctx) {
	// escaped_hierarchical_identifier :
	// escaped_hierarchical_branch ( '.' simple_hierarchical_branch | '.'
	// escaped_hierarchical_branch )*
	// ;
	iHdlExpr * top = NULL;
	for (auto ch : ctx->children) {
		if (!top)
			top = visitEscaped_hierarchical_branch(
					ctx->escaped_hierarchical_branch(0));
		else {
			iHdlExpr * second;
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
			top = new iHdlExpr(top, DOT, second);
		}
	}
	return top;
}
iHdlExpr * VerExprParser::visitSimple_hierarchical_identifier(
		Verilog2001Parser::Simple_hierarchical_identifierContext * ctx) {
	// simple_hierarchical_identifier : simple_hierarchical_branch ( '.'
	// Escaped_identifier )? ;
	iHdlExpr * shb = visitSimple_hierarchical_branch(
			ctx->simple_hierarchical_branch());
	auto ei = ctx->Escaped_identifier();
	if (ei) {
		return new iHdlExpr(shb, HdlOperatorType::DOT,
				VerLiteralParser::parseEscaped_identifier(ei));
	}
	return shb;
}
iHdlExpr * VerExprParser::visitSimple_hierarchical_branch(
		Verilog2001Parser::Simple_hierarchical_branchContext * ctx) {
	// simple_hierarchical_branch :
	// Simple_identifier ( '[' Decimal_number ']' )?
	// ( '.' Simple_identifier ( '[' Decimal_number ']' )? )*
	// ;
	iHdlExpr * top = nullptr;
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
				top = new iHdlExpr(top, HdlOperatorType::DOT, id);
				next_is_dot_index = false;
			} else if (next_is_index) {
				auto i = VerLiteralParser::parseIntNumber(
						dynamic_cast<antlr4::tree::TerminalNode*>(ch), 10);
				top = new iHdlExpr(top, HdlOperatorType::INDEX, i);
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
iHdlExpr * VerExprParser::visitSystem_task_identifier(
		Verilog2001Parser::System_task_identifierContext *ctx) {
	// system_task_identifier
	//    : Dollar_Identifier
	//    ;
	auto di = ctx->Dollar_Identifier();
	return iHdlExpr::ID(di->getText());
}
iHdlExpr * VerExprParser::visitIdentifier(
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
iHdlExpr * VerExprParser::visitEscaped_hierarchical_branch(
		Verilog2001Parser::Escaped_hierarchical_branchContext * ctx) {
	// escaped_hierarchical_branch :
	// Escaped_identifier ( '[' Decimal_number ']' )?
	// ( '.' Escaped_identifier ( '[' Decimal_number ']' )? )*
	// ;
	NotImplementedLogger::print(
			"VerExprParser.visitEscaped_hierarchical_branch", ctx);
	return NULL;
}
iHdlExpr * VerExprParser::visitMintypmax_expression(
		Verilog2001Parser::Mintypmax_expressionContext* ctx) {
	// mintypmax_expression
	// : expression (':' expression ':' expression)?
	// ;
	if (ctx->expression().size() > 1) {
		NotImplementedLogger::print(
				"VerExprParser.visitMintypmax_expression - type and max specified",
				ctx);
	}
	return visitExpression(ctx->expression(0));
}

std::vector<iHdlExpr*> * VerExprParser::visitEvent_expression(
		Verilog2001Parser::Event_expressionContext * ctx) {
	// event_expression
	//    : event_primary ('or' event_primary | ',' event_primary)*
	//    ;
	// @note 'or' and ',' is a Verilog-1995/2001 difference, they work exactly the same

	auto res = new std::vector<iHdlExpr*>;
	for (auto ep : ctx->event_primary()) {
		auto e = visitEvent_primary(ep);
		res->push_back(e);
	}
	return res;
}

iHdlExpr * VerExprParser::visitEvent_primary(
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
		HdlOperatorType o;
		if (ctx->children[0]->getText() == "posedge") {
			o = HdlOperatorType::RISING;
		} else {
			o = HdlOperatorType::FALLING;
		}
		return new iHdlExpr(visitExpression(expr), o, nullptr);
	}
}

iHdlExpr * VerExprParser::visitVariable_lvalue(
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

	auto vc = ctx->variable_concatenation();
	if (vc)
		return visitVariable_concatenation(vc);

	auto hi =
			ctx->hierarchical_variable_identifier()->hierarchical_identifier();
	auto id = visitHierarchical_identifier(hi);
	for (auto e : ctx->expression()) {
		auto expr = visitExpression(e);
		id = new iHdlExpr(id, HdlOperatorType::INDEX, expr);
	}
	auto re = ctx->range_expression();
	if (re) {
		auto expr = visitRange_expression(re);
		id = new iHdlExpr(id, HdlOperatorType::INDEX, expr);
	}
	return id;
}

iHdlExpr * VerExprParser::visitVariable_concatenation(
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
	vector<iHdlExpr *> parts;
	for (auto ncv : ctx->variable_concatenation_value()) {
		auto hi =
				ncv->hierarchical_variable_identifier()->hierarchical_identifier();
		if (hi) {
			iHdlExpr * id = visitHierarchical_identifier(hi);
			for (auto ce : ncv->expression()) {
				auto c = visitExpression(ce);
				id = new iHdlExpr(id, HdlOperatorType::INDEX, c);
			}
			auto re = ncv->range_expression();
			if (re) {
				auto r = visitRange_expression(re);
				id = new iHdlExpr(id, HdlOperatorType::INDEX, r);
			}
			return id;
		} else {
			parts.push_back(
					visitVariable_concatenation(ncv->variable_concatenation()));
		}
	}

	return reduce(parts, HdlOperatorType::CONCAT);
}

iHdlExpr * VerExprParser::visitArrayed_identifier(
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
				e = new iHdlExpr(e, HdlOperatorType::INDEX, r);
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
		e = new iHdlExpr(e, HdlOperatorType::INDEX, r);
	}
	return e;

}

}
}
