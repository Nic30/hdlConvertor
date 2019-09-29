#include <hdlConvertor/svConvertor/exprParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/svConvertor/moduleParamParser.h>
#include <hdlConvertor/svConvertor/moduleInstanceParser.h>
#include <hdlConvertor/svConvertor/literalParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/svConvertor/exprPrimaryParser.h>


namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;

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
	//   primary
	//   | LPAREN operator_assignment RPAREN
	//   | KW_TAGGED identifier ( expression )?
	//   | unary_operator ( attribute_instance )* primary
	//   | inc_or_dec_expression
	//   | expression DOUBLESTAR           ( attribute_instance )* expression
	//   | expression operator_mul_div_mod ( attribute_instance )* expression
	//   | expression operator_plus_minus  ( attribute_instance )* expression
	//   | expression operator_shift       ( attribute_instance )* expression
	//   | expression operator_cmp         ( attribute_instance )* expression
	//   | expression KW_INSIDE LBRACE open_range_list RBRACE
	//   | expression operator_eq_neq      ( attribute_instance )* expression
	//   | expression AMPERSAND            ( attribute_instance )* expression
	//   | expression operator_xor         ( attribute_instance )* expression
	//   | expression BAR                  ( attribute_instance )* expression
	//   | expression LOG_AND              ( attribute_instance )* expression
	//   | expression LOG_OR               ( attribute_instance )* expression
	//   | expression ( KW_MATCHES pattern )? TRIPLE_AND expression ( KW_MATCHES pattern )?
	//   | expression ( KW_MATCHES pattern )? QUESTIONMARK ( attribute_instance )* expression COLON expression
	//   | expression operator_impl        ( attribute_instance )* expression
	// ;

	auto oa = ctx->operator_assignment();
	if (oa) {
		NotImplementedLogger::print(
				"VerExprParser.visitExpression - operator_assignment", ctx);
		return iHdlExpr::null();
	}
	if (ctx->KW_TAGGED()) {
		NotImplementedLogger::print(
				"VerExprParser.visitExpression - KW_TAGGED identifier", ctx);
		return iHdlExpr::null();
	}

	for (auto ai : ctx->attribute_instance()) {
		VerAttributeParser::visitAttribute_instance(ai);
	}

	auto _p = ctx->primary();
	if (_p) {
		auto p = VerExprPrimaryParser::visitPrimary(_p);
		auto _uo = ctx->unary_operator();
		if (_uo) {
			auto uo = VerLiteralParser::visitUnary_operator(_uo);
			assert(_p);
			return new iHdlExpr(uo, p);
		} else {
			return p;
		}
	}
	auto ide = ctx->inc_or_dec_expression();
	if (ide) {
		return visitInc_or_dec_expression(ide);
	}
	auto exprs = ctx->expression();
	if (exprs.size() == 2) {
		//   | expression DOUBLESTAR           ( attribute_instance )* expression
		//   | expression operator_mul_div_mod ( attribute_instance )* expression
		//   | expression operator_plus_minus  ( attribute_instance )* expression
		//   | expression operator_shift       ( attribute_instance )* expression
		//   | expression operator_cmp         ( attribute_instance )* expression
		//   | expression operator_eq_neq      ( attribute_instance )* expression
		//   | expression AMPERSAND            ( attribute_instance )* expression
		//   | expression operator_xor         ( attribute_instance )* expression
		//   | expression BAR                  ( attribute_instance )* expression
		//   | expression LOG_AND              ( attribute_instance )* expression
		//   | expression LOG_OR               ( attribute_instance )* expression
		//   | expression operator_impl        ( attribute_instance )* expression
		auto op = HdlOperatorType::POW;
		do {
			if (ctx->DOUBLESTAR())
				break;
			auto omudm = ctx->operator_mul_div_mod();
			if (omudm) {
				op = VerLiteralParser::visitOperator_mul_div_mod(omudm);
				break;
			}
			auto opm = ctx->operator_plus_minus();
			if (opm) {
				op = VerLiteralParser::visitOperator_plus_minus(opm);
				break;
			}
			auto os = ctx->operator_shift();
			if (os) {
				op = VerLiteralParser::visitOperator_shift(os);
				break;
			}
			auto oc = ctx->operator_cmp();
			if (oc) {
				op = VerLiteralParser::visitOperator_cmp(oc);
				break;
			}
			auto oe = ctx->operator_eq_neq();
			if (oe) {
				op = VerLiteralParser::visitOperator_eq_neq(oe);
				break;
			}
			auto oa = ctx->AMPERSAND();
			if (oa) {
				op = HdlOperatorType::AND;
				break;
			}
			auto ox = ctx->operator_xor();
			if (ox) {
				op = VerLiteralParser::visitOperator_xor(ox);
				break;
			}
			auto ob = ctx->BAR();
			if (ob) {
				op = HdlOperatorType::OR;
				break;
			}
			auto ola = ctx->LOG_AND();
			if (ola) {
				op = HdlOperatorType::LOG_AND;
				break;
			}
			auto olo = ctx->LOG_OR();
			if (olo) {
				op = HdlOperatorType::LOG_OR;
				break;
			}
			auto oi = ctx->operator_impl();
			if (oi) {
				op = VerLiteralParser::visitOperator_impl(oi);
				break;
			}

			assert(false && "unkown binary");
		} while (0);
		auto e0 = visitExpression(exprs[0]);
		auto e1 = visitExpression(exprs[1]);
		return new iHdlExpr(e0, op, e1);
	}
	//   | expression KW_INSIDE LBRACE open_range_list RBRACE
	auto inside = ctx->KW_INSIDE();
	if (inside) {
		NotImplementedLogger::print("VerExprParser.visitExpression - KW_INSIDE",
				ctx);
		return iHdlExpr::null();
	}
	if (ctx->KW_MATCHES().size()) {
		NotImplementedLogger::print(
				"VerExprParser.visitExpression - KW_MATCHES", ctx);
		return iHdlExpr::null();
	}
	//   | expression ( KW_MATCHES pattern )? TRIPLE_AND expression ( KW_MATCHES pattern )?
	if (ctx->TRIPLE_AND()) {
		NotImplementedLogger::print(
				"VerExprParser.visitExpression - TRIPLE_AND", ctx);
		return iHdlExpr::null();
	}
	//   | expression ( KW_MATCHES pattern )? QUESTIONMARK ( attribute_instance )* expression COLON expression
	assert(exprs.size() == 3);
	auto e0 = visitExpression(exprs[0]);
	auto e1 = visitExpression(exprs[1]);
	auto e2 = visitExpression(exprs[2]);
	return iHdlExpr::ternary(e0, e1, e2);
}

iHdlExpr* VerExprParser::visitConcatenation(
		sv2017Parser::ConcatenationContext *ctx) {
	// concatenation:
	//    LBRACE (expression ( concatenation | ( COMMA expression )+)?)? RBRACE;
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
iHdlExpr* VerExprParser::visitIdentifier(sv2017Parser::IdentifierContext *ctx) {
	// identifier:
	//     C_IDENTIFIER
	//     | SIMPLE_IDENTIFIER
	//     | ESCAPED_IDENTIFIER
	//     | KW_SAMPLE
	//     | KW_RANDOMIZE
	//     | KW_TYPE_OPTION
	//     | KW_OPTION
	//     | KW_STD
	// ;
	auto eid = ctx->ESCAPED_IDENTIFIER();
	if (eid) {
		return VerLiteralParser::visitESCAPED_IDENTIFIER(eid);
	} else {
		return iHdlExpr::ID(ctx->getText());
	}
}
iHdlExpr* VerExprParser::visitMintypmax_expression(
		sv2017Parser::Mintypmax_expressionContext *ctx) {
	// mintypmax_expression: expression ( COLON expression COLON expression )?;
	if (ctx->expression().size() > 1) {
		NotImplementedLogger::print(
				"VerExprParser.visitMintypmax_expression - type and max specified",
				ctx);
	}
	return visitExpression(ctx->expression(0));
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
iHdlExpr* VerExprParser::visitEvent_trigger(
		sv2017Parser::Event_triggerContext *ctx) {
	// event_trigger:
	//  ( ARROW
	//    | DOUBLE_RIGHT_ARROW ( delay_or_event_control )?
	//  ) hierarchical_identifier SEMI;

	if (ctx->delay_or_event_control()) {
		NotImplementedLogger::print(
				"VerExprParser.visitEvent_trigger - delay_or_event_control",
				ctx);
	}
	auto _e = ctx->hierarchical_identifier();
	auto e = visitHierarchical_identifier(_e);
	return new iHdlExpr(HdlOperatorType::ARROW, e);
}
iHdlExpr* VerExprParser::visitBit_select(sv2017Parser::Bit_selectContext *ctx,
		iHdlExpr *selected_name) {
	// bit_select: LSQUARE_BR expression RSQUARE_BR;
	auto _e = ctx->expression();
	auto e = visitExpression(_e);
	return append_expr(selected_name, HdlOperatorType::INDEX, e);
}
iHdlExpr* VerExprParser::visitIdentifier_with_bit_select(
		sv2017Parser::Identifier_with_bit_selectContext *ctx,
		iHdlExpr *selected_name) {
	// identifier_with_bit_select: identifier ( bit_select )*;
	auto id = ctx->identifier();
	auto res = VerExprParser::visitIdentifier(id);
	res = append_expr(selected_name, HdlOperatorType::DOT, res);
	for (auto bs : ctx->bit_select()) {
		res = visitBit_select(bs, res);
	}
	return res;
}
iHdlExpr* VerExprParser::visitPackage_or_class_scoped_hier_id_with_select(
		sv2017Parser::Package_or_class_scoped_hier_id_with_selectContext *ctx) {

	// // '::' separated then '.' separated
	// package_or_class_scoped_hier_id_with_select:
	//     package_or_class_scoped_path ( bit_select )*
	//     ( DOT identifier_with_bit_select )*
	//     ( LSQUARE_BR expression ( operator_plus_minus )? COLON expression RSQUARE_BR )?;
	auto pcsp = ctx->package_or_class_scoped_path();
	auto res = visitPackage_or_class_scoped_path(pcsp);
	for (auto bs : ctx->bit_select()) {
		res = visitBit_select(bs, res);
	}
	// "Vector bit-select and part-select addressing"
	if (ctx->operator_plus_minus()) {
		NotImplementedLogger::print(
				"VerExprParser.visitPackage_or_class_scoped_hier_id_with_select - operator_plus_minus",
				ctx);
	}
	auto exprs = ctx->expression();
	if (exprs.size()) {
		assert(exprs.size() == 2);
		auto e0 = visitExpression(exprs[0]);
		auto e1 = visitExpression(exprs[1]);
		auto sel = new iHdlExpr(e0, HdlOperatorType::DOWNTO, e1);
		return append_expr(res, HdlOperatorType::INDEX, sel);
	}
	return res;
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
		iHdlExpr *selected_name,
		hdlObjects::HdlOperatorType subname_access_type) {
	// package_or_class_scoped_path_item:
	// 	identifier ( parameter_value_assignment )?
	// ;
	auto _id = ctx->identifier();
	auto id = visitIdentifier(_id);
	if (selected_name) {
		id = new iHdlExpr(selected_name, subname_access_type, id);
	}
	auto _pva = ctx->parameter_value_assignment();
	if (_pva) {
		auto pva = visitParameter_value_assignment(_pva);
		id = iHdlExpr::parametrization(id, pva);
	}
	return id;
}
iHdlExpr* VerExprParser::visitImplicit_class_handle(
		sv2017Parser::Implicit_class_handleContext *ctx,
		iHdlExpr *selected_name, HdlOperatorType subname_access_type) {
	// implicit_class_handle:
	//  KW_THIS ( DOT KW_SUPER )?
	//   | KW_SUPER
	//  ;
	if (ctx->KW_THIS()) {
		auto t = iHdlExpr::ID("this");
		selected_name = append_expr(selected_name, subname_access_type, t);
		subname_access_type = HdlOperatorType::DOT;
	}
	if (ctx->KW_SUPER()) {
		auto s = iHdlExpr::ID("super");
		selected_name = append_expr(selected_name, subname_access_type, s);
	}
	assert(selected_name);
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
		res = append_expr(res, HdlOperatorType::DOUBLE_COLON,
				iHdlExpr::ID("$root"));
	} else {
		auto _ich = ctx->implicit_class_handle();
		if (_ich) {
			res = visitImplicit_class_handle(_ich, res,
					HdlOperatorType::DOUBLE_COLON);
		} else {
			if (ctx->KW_DOLAR_UNIT()) {
				auto part = iHdlExpr::ID("$unit");
				res = append_expr(res, HdlOperatorType::DOUBLE_COLON, part);
			} else {
				auto pcspi = ctx->package_or_class_scoped_path_item();
				assert(pcspi.size() > 0);
				for (auto i : pcspi) {
					res = visitPackage_or_class_scoped_path_item(i, res,
							HdlOperatorType::DOUBLE_COLON);
				}
				return res;
			}
		}
	}
	auto pcspi = ctx->package_or_class_scoped_path_item();
	for (auto i : pcspi) {
		res = visitPackage_or_class_scoped_path_item(i, res,
				HdlOperatorType::DOUBLE_COLON);
	}
	return res;
}
}
}
