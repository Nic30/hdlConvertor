#include <hdlConvertor/svConvertor/exprParser.h>

#include <antlr4-runtime.h>

#include <hdlConvertor/svConvertor/moduleParamParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;

iHdlExpr* VerExprParser::reduce(const std::vector<iHdlExpr*> &ops,
		HdlOperatorType op) {
	iHdlExpr *res = nullptr;
	for (auto p : ops) {
		if (res == nullptr)
			res = p;
		else
			res = new iHdlExpr(res, op, p);
	}
	return res;
}

iHdlExpr* VerExprParser::visitConstant_expression(
		sv2017Parser::Constant_expressionContext *ctx) {
	// constant_expression : expression ;
	return visitExpression(ctx->expression());
}
iHdlExpr* VerExprParser::visitRange_expression(
		sv2017Parser::Range_expressionContext *ctx) {
	// range_expression:
	//    expression ( COLON expression )?
	// ;
	auto exprs = ctx->expression();
	assert(exprs.size() >= 1);
	auto l = visitExpression(exprs[0]);
	if (exprs.size() == 2) {
		auto h = visitExpression(exprs[1]);
		return new iHdlExpr(l, HdlOperatorType::DOWNTO, h);
	} else {
		assert(exprs.size() == 1);
		return l;
	}
}

iHdlExpr* VerExprParser::visitNet_lvalue(sv2017Parser::Net_lvalueContext *ctx) {
	//net_lvalue: variable_lvalue;
	auto v = ctx->variable_lvalue();
	assert(v);
	return visitVariable_lvalue(v);
}
iHdlExpr* VerExprParser::visitNet_concatenation(
		sv2017Parser::Net_concatenationContext *ctx) {
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
	vector<iHdlExpr*> parts;
	auto ncvs = ctx->net_concatenation_value();
	assert(ncvs.size());
	for (auto ncv : ncvs) {
		auto hi = ncv->hierarchical_net_identifier();
		if (hi) {
			iHdlExpr *id = visitHierarchical_net_identifier(hi);
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

iHdlExpr* VerExprParser::visitDelay_control(
		sv2017Parser::Delay_controlContext *ctx) {
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
iHdlExpr* VerExprParser::visitDelay_value(
		sv2017Parser::Delay_valueContext *ctx) {
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
		return ModuleParamParser::visitParameter_identifier(pi);
	}
	auto si = ctx->specparam_identifier();
	if (si)
		return visitSpecparam_identifier(si);
	auto me = ctx->mintypmax_expression();
	assert(me);
	return visitMintypmax_expression(me);

}

iHdlExpr* VerExprParser::visitExpression(sv2017Parser::ExpressionContext *ctx) {
	// expression:
	// term
	// (
	// binary_operator attribute_instance* term
	// | '?' attribute_instance* expression ':' term
	// )*
	// ;
	antlr4::tree::ParseTree *ch;
	antlr4::tree::ParseTree *ch2 = nullptr;
	auto childs = ctx->children.begin();
	iHdlExpr *top = visitTerm((sv2017Parser::TermContext*) (*childs));
	childs++;
	// skip attribs
	while (childs != ctx->children.end()) {
		ch = *childs;
		childs++;
		auto binOp = dynamic_cast<sv2017Parser::Binary_operatorContext*>(ch);
		if (binOp) {
			while (true) {
				ch2 = *childs;
				childs++;
				auto aic =
						dynamic_cast<sv2017Parser::Attribute_instanceContext*>(ch2);
				if (aic) {
					AttributeParser::visitAttribute_instance(aic);
				} else {
					break;
				}
			}
			top = new iHdlExpr(top,
					VerLiteralParser::visitBinary_operator(binOp),
					visitTerm((sv2017Parser::TermContext*) ch2));
		} else {
			while (true) {
				ch2 = *childs;
				childs++;
				auto _aic =
						dynamic_cast<sv2017Parser::Attribute_instanceContext*>(ch2);
				if (_aic) {
					AttributeParser::visitAttribute_instance(_aic);
				} else {
					break;
				}
			}
			childs++; // consume ":"
			auto ifTrue = visitExpression(
					dynamic_cast<sv2017Parser::ExpressionContext*>(ch2));
			assert(ifTrue);
			auto ifFalse = visitTerm(
					dynamic_cast<sv2017Parser::TermContext*>(*childs));
			assert(ifFalse);
			top = iHdlExpr::ternary(top, ifTrue, ifFalse);
			childs++;
		}
	}

	return top;
}
iHdlExpr* VerExprParser::visitTerm(sv2017Parser::TermContext *ctx) {
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
			return new iHdlExpr(o, e);
		} else {
			return e;
		}
	}
	auto s = ctx->String();
	return VerLiteralParser::visitString(s);
}
iHdlExpr* VerExprParser::visitPrimary(sv2017Parser::PrimaryContext *ctx) {
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
		iHdlExpr *top = visitHierarchical_identifier(hi);
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
iHdlExpr* VerExprParser::visitConstant_function_call(
		sv2017Parser::Constant_function_callContext *ctx) {
	// constant_function_call :
	// function_identifier attribute_instance* '('
	// (constant_expression ( ',' constant_expression )*)? ')'
	// ;
	if (ctx->attribute_instance().size()) {
		NotImplementedLogger::print(
				"VerExprParser.visitConstant_function_call - attribute_instance",
				ctx);
	}

	auto fi = ctx->function_identifier();
	iHdlExpr *fn = visitFunction_identifier(fi);
	std::vector<iHdlExpr*> args;
	auto exprs = ctx->constant_expression();
	for (auto e : exprs) {
		iHdlExpr *a = visitConstant_expression(e);
		args.push_back(a);
	}
	return iHdlExpr::call(fn, args);
}
iHdlExpr* VerExprParser::visitFunction_identifier(
		sv2017Parser::Function_identifierContext *ctx) {
	// function_identifier
	//    : identifier
	//    ;
	return visitIdentifier(ctx->identifier());
}
iHdlExpr* VerExprParser::visitSystem_function_identifier(
		sv2017Parser::System_function_identifierContext *ctx) {
	// system_function_identifier
	//    : Dollar_Identifier
	//    ;
	return VerLiteralParser::visitDolar_identifier(ctx->Dollar_Identifier());
}
iHdlExpr* VerExprParser::visitSystem_function_call(
		sv2017Parser::System_function_callContext *ctx) {
	// system_function_call :
	// system_function_identifier (expression ( ',' expression )*)?
	// ;
	auto sfi = ctx->system_function_identifier();
	iHdlExpr *fn = visitSystem_function_identifier(sfi);
	std::vector<iHdlExpr*> args;
	auto exprs = ctx->expression();
	for (auto e : exprs) {
		iHdlExpr *a = visitExpression(e);
		args.push_back(a);
	}
	return iHdlExpr::call(fn, args);
}
iHdlExpr* VerExprParser::visitFunction_call(
		sv2017Parser::Function_callContext *ctx) {
	// function_call
	// : hierarchical_function_identifier attribute_instance*
	// '(' (expression ( ',' expression )*)? ')'
	// ;
	if (ctx->attribute_instance().size()) {
		NotImplementedLogger::print(
				"VerExprParser.visitFunction_call - attribute_instance", ctx);
	}
	auto hfi = ctx->hierarchical_function_identifier();
	iHdlExpr *fn = visitHierarchical_function_identifier(hfi);
	std::vector<iHdlExpr*> args;
	auto exprs = ctx->expression();
	for (auto e : exprs) {
		iHdlExpr *a = visitExpression(e);
		args.push_back(a);
	}
	return iHdlExpr::call(fn, args);
}
iHdlExpr* VerExprParser::visitHierarchical_function_identifier(
		sv2017Parser::Hierarchical_function_identifierContext *ctx) {
	// hierarchical_function_identifier
	//    : hierarchical_identifier
	//    ;
	return visitHierarchical_identifier(ctx->hierarchical_identifier());
}
iHdlExpr* VerExprParser::visitMultiple_concatenation(
		sv2017Parser::Multiple_concatenationContext *ctx) {
	// multiple_concatenation : '{' constant_expression concatenation '}' ;
	auto ce = visitConstant_expression(ctx->constant_expression());
	auto c = visitConcatenation(ctx->concatenation());
	return new iHdlExpr(ce, HdlOperatorType::REPL_CONCAT, c);
}
iHdlExpr* VerExprParser::visitConcatenation(
		sv2017Parser::ConcatenationContext *ctx) {
	// concatenation : '{' expression ( ',' expression )* '}' ;
	iHdlExpr *res = nullptr;
	for (auto e : ctx->expression()) {
		auto p = VerExprParser::visitExpression(e);
		if (res == nullptr)
			res = p;
		else
			res = new iHdlExpr(res, HdlOperatorType::CONCAT, p);
	}
	return res;
}
iHdlExpr* VerExprParser::visitHierarchical_identifier(
		sv2017Parser::Hierarchical_identifierContext *ctx) {
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
iHdlExpr* VerExprParser::visitEscaped_hierarchical_identifier(
		sv2017Parser::Escaped_hierarchical_identifierContext *ctx) {
	// escaped_hierarchical_identifier :
	// escaped_hierarchical_branch ( '.' simple_hierarchical_branch | '.'
	// escaped_hierarchical_branch )*
	// ;
	iHdlExpr *top = NULL;
	for (auto ch : ctx->children) {
		if (!top)
			top = visitEscaped_hierarchical_branch(
					ctx->escaped_hierarchical_branch(0));
		else {
			iHdlExpr *second = nullptr;
			auto ehbc =
					dynamic_cast<sv2017Parser::Escaped_hierarchical_branchContext*>(ch);
			if (ehbc) {
				second = visitEscaped_hierarchical_branch(ehbc);
			} else {
				auto shbc =
						dynamic_cast<sv2017Parser::Simple_hierarchical_branchContext*>(ch);
				if (shbc) {
					second = visitSimple_hierarchical_branch(shbc);
				}
			}
			if (second) {
				top = new iHdlExpr(top, DOT, second);
			}
		}
	}
	return top;
}
iHdlExpr* VerExprParser::visitSimple_hierarchical_identifier(
		sv2017Parser::Simple_hierarchical_identifierContext *ctx) {
	// simple_hierarchical_identifier : simple_hierarchical_branch ( '.'
	// Escaped_identifier )? ;
	iHdlExpr *shb = visitSimple_hierarchical_branch(
			ctx->simple_hierarchical_branch());
	auto ei = ctx->Escaped_identifier();
	if (ei) {
		return new iHdlExpr(shb, HdlOperatorType::DOT,
				VerLiteralParser::parseEscaped_identifier(ei));
	}
	return shb;
}
iHdlExpr* VerExprParser::visitSimple_hierarchical_branch(
		sv2017Parser::Simple_hierarchical_branchContext *ctx) {
	// simple_hierarchical_branch :
	// Simple_identifier ( '[' Decimal_number ']' )?
	// ( '.' Simple_identifier ( '[' Decimal_number ']' )? )*
	// ;
	iHdlExpr *top = nullptr;
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
iHdlExpr* VerExprParser::visitSystem_task_identifier(
		sv2017Parser::System_task_identifierContext *ctx) {
	// system_task_identifier
	//    : Dollar_Identifier
	//    ;
	auto di = ctx->Dollar_Identifier();
	return iHdlExpr::ID(di->getText());
}
iHdlExpr* VerExprParser::visitIdentifier(sv2017Parser::IdentifierContext *ctx) {
	// identifier
	//    : Simple_identifier
	//    | Escaped_identifier
	//    ;
	auto sid = ctx->Simple_identifier();
	if (sid)
		return VerLiteralParser::parseSimple_identifier(sid);
	else {
		auto eid = ctx->Escaped_identifier();
		return VerLiteralParser::parseEscaped_identifier(eid);
	}
}
iHdlExpr* VerExprParser::visitEscaped_hierarchical_branch(
		sv2017Parser::Escaped_hierarchical_branchContext *ctx) {
	// escaped_hierarchical_branch :
	// Escaped_identifier ( '[' Decimal_number ']' )?
	// ( '.' Escaped_identifier ( '[' Decimal_number ']' )? )*
	// ;
	iHdlExpr *res = nullptr;
	for (auto &c : ctx->children) {
		antlr4::tree::TerminalNode *tnode =
				dynamic_cast<antlr4::tree::TerminalNode*>(c);
		antlr4::Token *symbol = tnode->getSymbol();
		if (symbol->getType() == sv2017Parser::Escaped_identifier) {
			auto tmp = VerLiteralParser::parseEscaped_identifier(tnode);
			if (res == nullptr) {
				res = tmp;
			} else {
				res = new iHdlExpr(res, HdlOperatorType::DOT, tmp);
			}
		} else if (symbol->getType() == sv2017Parser::Decimal_number) {
			auto d = VerLiteralParser::parseIntNumber(tnode, 10);
			res = new iHdlExpr(res, HdlOperatorType::INDEX, d);
		}
	}
	return res;
}
iHdlExpr* VerExprParser::visitMintypmax_expression(
		sv2017Parser::Mintypmax_expressionContext *ctx) {
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

std::vector<iHdlExpr*>* VerExprParser::visitEvent_expression(
		sv2017Parser::Event_expressionContext *ctx) {
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

iHdlExpr* VerExprParser::visitEvent_primary(
		sv2017Parser::Event_primaryContext *ctx) {
	// event_primary
	//    : (expression | 'posedge' expression | 'negedge' expression)
	//    ;
	auto first_as_expr =
			dynamic_cast<sv2017Parser::ExpressionContext*>(ctx->children[0]);
	if (first_as_expr) {
		return visitExpression(first_as_expr);
	} else {
		auto expr =
				dynamic_cast<sv2017Parser::ExpressionContext*>(ctx->children[1]);
		HdlOperatorType o;
		if (ctx->children[0]->getText() == "posedge") {
			o = HdlOperatorType::RISING;
		} else {
			o = HdlOperatorType::FALLING;
		}
		return new iHdlExpr(visitExpression(expr), o, nullptr);
	}
}

iHdlExpr* VerExprParser::visitVariable_lvalue(
		sv2017Parser::Variable_lvalueContext *ctx) {
	//variable_lvalue:
	// LBRACE variable_lvalue ( COMMA variable_lvalue )* RBRACE
	//  | package_or_class_scoped_hier_id_with_select
	//  | ( assignment_pattern_expression_type )? assignment_pattern_variable_lvalue
	//  | streaming_concatenation
	//;
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
	auto vls = ctx->variable_lvalue();
	if (vls.size()) {
		vector<iHdlExpr*> parts;
		for (auto vl : vls) {
			parts.push_back(visitVariable_lvalue(vl));
		}

		return reduce(parts, HdlOperatorType::CONCAT);
	}
	auto pid = ctx->package_or_class_scoped_hier_id_with_select();
	if (pid) {
		return visitPackage_or_class_scoped_hier_id_with_select(pid);
	}

}

iHdlExpr* VerExprParser::visitArrayed_identifier(
		sv2017Parser::Arrayed_identifierContext *ctx) {
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

iHdlExpr* VerExprParser::visitEvent_trigger(
		sv2017Parser::Event_triggerContext *ctx) {
	// event_trigger
	//    : '->' hierarchical_event_identifier ';'
	//    ;
	// hierarchical_event_identifier
	//    : hierarchical_identifier
	//    ;

	auto _e = ctx->hierarchical_event_identifier()->hierarchical_identifier();
	auto e = visitHierarchical_identifier(_e);
	return new iHdlExpr(HdlOperatorType::ARROW, e);
}

iHdlExpr* VerExprParser::visitPackage_or_class_scoped_hier_id_with_select(
		sv2017Parser::Package_or_class_scoped_hier_id_with_selectContext *ctx) {
	// package_or_class_scoped_hier_id_with_select:
	//  package_or_class_scoped_path ( bit_select )* ( DOT identifier ( bit_select )* )* ( LSQUARE_BR
	//       expression ( PLUS
	//       | MINUS
	//       )? COLON expression RSQUARE_BR )?;

}

std::vector<iHdlExpr*> VerExprParser::visitParameter_value_assignment(
		sv2017Parser::Parameter_value_assignmentContext *ctx) {
	// parameter_value_assignment:
	//   HASH LPAREN ( list_of_parameter_assignments )? RPAREN;
	auto lpa = ctx->list_of_parameter_assignments();
	return ModuleInstanceParser::visitList_of_parameter_assignments(lpa);
}

iHdlExpr* VerExprParser::visitPackage_or_class_scoped_path_item(
		sv2017Parser::Package_or_class_scoped_path_itemContext *ctx,
		iHdlExpr *selected_name) {
	// package_or_class_scoped_path_item:
	// 	identifier ( parameter_value_assignment )?
	// ;
	auto _id = ctx->identifier();
	auto id = visitIdentifier(_id);
	auto _pva = ctx->parameter_value_assignment();
	if (_pva) {
		auto pva = visitParameter_value_assignment(_pva);
		id = iHdlExpr::parametrization(id, pva);
	}
	return id;
}

iHdlExpr* VerExprParser::visitimplicit_class_handle(
		sv2017Parser::Implicit_class_handleContext *ctx,
		iHdlExpr *selected_name) {
	// implicit_class_handle:
	//  KW_THIS ( DOT KW_SUPER )?
	//   | KW_SUPER
	//  ;
	if (ctx->KW_THIS()) {
		auto t = iHdlExpr::ID("this");
		selected_name = append_dot_separated_expr(selected_name, t);
	}
	if (ctx->KW_SUPER()) {
		auto s = iHdlExpr::ID("super");
		selected_name = append_dot_separated_expr(selected_name, s);
	}
	return selected_name;
}

iHdlExpr* VerExprParser::visitPackage_or_class_scoped_path(
		sv2017Parser::Package_or_class_scoped_pathContext *ctx) {
	// // '::' separated
	// package_or_class_scoped_path:
	//    ( KW_LOCAL DOUBLE_COLON )? (
	//   		KW_DOLAR_ROOT
	//         | implicit_class_handle
	//         | KW_DOLAR_UNIT
	//         | package_or_class_scoped_path_item
	// 	) ( DOUBLE_COLON package_or_class_scoped_path_item)*;
	iHdlExpr *res = nullptr;
	if (ctx->KW_LOCAL()) {
		res = iHdlExpr::ID("local");
	}
	if (ctx->KW_DOLAR_ROOT()) {
		res = append_dot_separated_expr(res, iHdlExpr::ID("$root"));
	} else {
		auto _ich = ctx->implicit_class_handle();
		if (_ich) {
			res = visitImplicit_class_handle(_ich, res);
		} else {
			if (ctx->KW_DOLAR_UNIT()) {
				auto part = iHdlExpr::ID("$unit");
				res = append_dot_separated_expr(res, part);
			} else {
				auto pcspi = ctx->package_or_class_scoped_path_item();
				assert(pcspi.size() > 0);
				for (auto i : pcspi) {
					res = visitPackage_or_class_scoped_path_item(i, res);
				}
				return res;
			}
		}
	}
	auto pcspi = ctx->package_or_class_scoped_path_item();
	for (auto i : pcspi) {
		res = visitPackage_or_class_scoped_path_item(i, res);
	}
	return res;
}
}
}
