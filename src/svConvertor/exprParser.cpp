#include <hdlConvertor/svConvertor/exprParser.h>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/svConvertor/paramDefParser.h>
#include <hdlConvertor/svConvertor/moduleInstanceParser.h>
#include <hdlConvertor/svConvertor/literalParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/svConvertor/exprPrimaryParser.h>
#include <hdlConvertor/svConvertor/typeParser.h>

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlAst;

namespace hdlConvertor {
namespace sv {

VerExprParser::VerExprParser(SVCommentParser &_commentParser) :
		commentParser(_commentParser) {
}

unique_ptr<iHdlExprItem> VerExprParser::visitConstant_expression(
		sv2017Parser::Constant_expressionContext *ctx) {
	// constant_expression : expression ;
	return visitExpression(ctx->expression());
}

unique_ptr<iHdlExprItem> VerExprParser::visitRange_expression(
		sv2017Parser::Range_expressionContext *ctx) {
	// range_expression:
	//    expression ( COLON expression )?
	// ;
	auto exprs = ctx->expression();
	assert(exprs.size() >= 1);
	auto l = visitExpression(exprs[0]);
	if (exprs.size() == 2) {
		auto h = visitExpression(exprs[1]);
		return create_object<HdlOp>(ctx, move(l), HdlOpType::DOWNTO, move(h));
	} else {
		assert(exprs.size() == 1);
		return l;
	}
}

unique_ptr<iHdlExprItem> VerExprParser::visitNet_lvalue(
		sv2017Parser::Net_lvalueContext *ctx) {
	//net_lvalue: variable_lvalue;
	auto v = ctx->variable_lvalue();
	assert(v);
	return visitVariable_lvalue(v);
}

unique_ptr<iHdlExprItem> VerExprParser::visitPackage_scope(
		sv2017Parser::Package_scopeContext *ctx) {
	// package_scope: ( KW_DOLAR_UNIT | identifier ) DOUBLE_COLON;
	auto du = ctx->KW_DOLAR_UNIT();
	if (du) {
		return create_object<HdlValueId>(du, "$unit");
	} else {
		auto id = ctx->identifier();
		assert(id);
		return visitIdentifier(id);
	}
}

unique_ptr<iHdlExprItem> VerExprParser::visitPs_identifier(
		sv2017Parser::Ps_identifierContext *ctx) {
	// ps_identifier: ( package_scope )? identifier;
	auto id = ctx->identifier();
	assert(id);
	auto res = visitIdentifier(id);
	auto ps = ctx->package_scope();
	if (ps) {
		auto _ps = visitPackage_scope(ps);
		res = create_object<HdlOp>(ctx, move(_ps), HdlOpType::DOUBLE_COLON,
				move(res));
	}
	return res;
}

unique_ptr<iHdlExprItem> VerExprParser::visitArray_range_expression(
		sv2017Parser::Array_range_expressionContext *ctx) {
	// array_range_expression:
	//  expression ( ( operator_plus_minus )? COLON expression )?;
	auto es = ctx->expression();
	auto e0 = visitExpression(es[0]);
	if (es.size() == 1) {
		return e0;
	}
	assert(es.size() == 2);
	auto e1 = visitExpression(es[1]);
	auto _pm = ctx->operator_plus_minus();
	HdlOpType op = HdlOpType::DOWNTO;
	if (_pm) {
		// e0 is offset
		// e1 is width
		// pm specifies direction of slice from offset
		auto pm = VerLiteralParser::visitOperator_plus_minus(_pm);
		if (pm == HdlOpType::ADD) {
			op = HdlOpType::PART_SELECT_POST;
		} else {
			op = HdlOpType::PART_SELECT_PRE;
		}
	}
	return create_object<HdlOp>(ctx, move(e0), op, move(e1));
}

unique_ptr<iHdlExprItem> VerExprParser::visitIdentifier_doted_index_at_end(
		sv2017Parser::Identifier_doted_index_at_endContext *ctx) {
	// identifier_doted_index_at_end:
	//    identifier ( DOT identifier )?  ( LSQUARE_BR range_expression RSQUARE_BR )*;
	auto id = ctx->identifier();
	auto res = visitIdentifier(id[0]);
	if (id.size() >= 2) {
		res = append_expr(ctx, move(res), HdlOpType::DOT,
				visitIdentifier(id[1]));
	}
	for (auto _re : ctx->range_expression()) {
		auto re = visitRange_expression(_re);
		res = append_expr(_re, move(res), HdlOpType::INDEX, move(re));
	}
	return res;
}

unique_ptr<iHdlExprItem> VerExprParser::visitInc_or_dec_expression(
		sv2017Parser::Inc_or_dec_expressionContext *ctx) {
	// inc_or_dec_expression:
	//      inc_or_dec_operator ( attribute_instance )* variable_lvalue #Inc_or_dec_expressionPre
	//     | variable_lvalue ( attribute_instance )* inc_or_dec_operator  #Inc_or_dec_expressionPost
	// ;
	HdlOpType op;
	unique_ptr<iHdlExprItem> e;
	if (dynamic_cast<sv2017Parser::Inc_or_dec_expressionPreContext*>(ctx)) {
		auto c =
				static_cast<sv2017Parser::Inc_or_dec_expressionPreContext*>(ctx);
		auto _op = c->inc_or_dec_operator();
		op = VerLiteralParser::visitInc_or_dec_operator(_op, true);
		e = visitVariable_lvalue(c->variable_lvalue());
		VerAttributeParser::visitAttribute_instance(c->attribute_instance());
	} else {
		auto c =
				dynamic_cast<sv2017Parser::Inc_or_dec_expressionPostContext*>(ctx);
		assert(c);
		auto _op = c->inc_or_dec_operator();
		op = VerLiteralParser::visitInc_or_dec_operator(_op, false);
		e = visitVariable_lvalue(c->variable_lvalue());
		VerAttributeParser::visitAttribute_instance(c->attribute_instance());
	}
	return create_object<HdlOp>(ctx, op, move(e));
}

unique_ptr<iHdlExprItem> VerExprParser::visitExpression(
		sv2017Parser::ExpressionContext *ctx) {
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
	//   | expression AND_LOG              ( attribute_instance )* expression
	//   | expression OR_LOG               ( attribute_instance )* expression
	//   | expression ( KW_MATCHES pattern )? TRIPLE_AND expression ( KW_MATCHES pattern )?
	//   | expression ( KW_MATCHES pattern )? (QUESTIONMARK ( attribute_instance )* expression COLON expression)+ // right associative
	//   | expression (operator_impl        ( attribute_instance )* expression)+ // right associative
	// ;

	auto oa = ctx->operator_assignment();
	if (oa) {
		NotImplementedLogger::print(
				"VerExprParser.visitExpression.operator_assignment", ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}
	if (ctx->KW_TAGGED()) {
		NotImplementedLogger::print(
				"VerExprParser.visitExpression.KW_TAGGED identifier", ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}

	for (auto ai : ctx->attribute_instance()) {
		VerAttributeParser::visitAttribute_instance(ai);
	}

	auto _p = ctx->primary();
	if (_p) {
		VerExprPrimaryParser pp(commentParser);
		auto p = pp.visitPrimary(_p);
		auto _uo = ctx->unary_operator();
		if (_uo) {
			auto uo = VerLiteralParser::visitUnary_operator(_uo);
			assert(_p);
			return create_object<HdlOp>(_uo, uo, move(p));
		} else {
			return p;
		}
	}
	auto ide = ctx->inc_or_dec_expression();
	if (ide) {
		return visitInc_or_dec_expression(ide);
	}
	auto exprs = ctx->expression();
	//   | expression (operator_impl        ( attribute_instance )* expression)+ // right associative
	//auto oi = ctx->operator_impl();
	//if (oi.size()) {
	//	std::unique_ptr<iHdlExprItem> res = visitExpression(exprs[oi.size()]);
	//	for (size_t i = oi.size(); i != 0; i--) {
	//		// construct a implication operators by walking from backwards
	//		auto op = VerLiteralParser::visitOperator_impl(oi[i - 1]);
	//		auto e0 = visitExpression(exprs[i - 1]);
	//		res = create_object<HdlOp>(ctx, move(e0), op, move(res));
	//	}
	//	return res;
	//}

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
		//   | expression AND_LOG              ( attribute_instance )* expression
		//   | expression OR_LOG               ( attribute_instance )* expression
		HdlOpType op;
		do {
			if (ctx->DOUBLESTAR()) {
				op = HdlOpType::POW;
				break;
			}
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
				op = HdlOpType::AND;
				break;
			}
			auto ox = ctx->operator_xor();
			if (ox) {
				op = VerLiteralParser::visitOperator_xor(ox);
				break;
			}
			auto ob = ctx->BAR();
			if (ob) {
				op = HdlOpType::OR;
				break;
			}
			auto ola = ctx->AND_LOG();
			if (ola) {
				op = HdlOpType::AND_LOG;
				break;
			}
			auto olo = ctx->OR_LOG();
			if (olo) {
				op = HdlOpType::OR_LOG;
				break;
			}
			auto imp = ctx->operator_impl();
			if (imp) {
				op = VerLiteralParser::visitOperator_impl(imp);
				break;
			}

			assert(false && "unknown binary");
		} while (0);
		auto e0 = visitExpression(exprs[0]);
		auto e1 = visitExpression(exprs[1]);
		return create_object<HdlOp>(ctx, move(e0), op, move(e1));
	}
	//   | expression KW_INSIDE LBRACE open_range_list RBRACE
	auto inside = ctx->KW_INSIDE();
	if (inside) {
		NotImplementedLogger::print("VerExprParser.visitExpression - KW_INSIDE",
				ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}
	if (ctx->KW_MATCHES().size()) {
		NotImplementedLogger::print(
				"VerExprParser.visitExpression - KW_MATCHES", ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}
	//   | expression ( KW_MATCHES pattern )? TRIPLE_AND expression ( KW_MATCHES pattern )?
	if (ctx->TRIPLE_AND()) {
		NotImplementedLogger::print(
				"VerExprParser.visitExpression - TRIPLE_AND", ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}
	//   | expression (( KW_MATCHES pattern )? QUESTIONMARK ( attribute_instance )* expression COLON expression)+
	assert(exprs.size() == 3);
	auto qm = ctx->QUESTIONMARK();
	assert(qm);
	// construct a ternary operators by walking backwards
	auto e0 = visitExpression(exprs[0]);
	auto e1 = visitExpression(exprs[1]);
	auto e2 = visitExpression(exprs[2]);
	return HdlOp::ternary(ctx, move(e0), move(e1), move(e2));
}

unique_ptr<iHdlExprItem> VerExprParser::visitConcatenation(
		sv2017Parser::ConcatenationContext *ctx) {
	// concatenation:
	//    LBRACE (expression ( concatenation | ( COMMA expression )+)?)? RBRACE;
	auto c = ctx->concatenation();
	if (c) {
		auto _e = ctx->expression(0);
		auto e = visitExpression(_e);
		auto c2 = visitConcatenation(c);
		return create_object<HdlOp>(ctx, move(e), HdlOpType::REPL_CONCAT,
				move(c2));
	}
	unique_ptr<iHdlExprItem> res = nullptr;
	for (auto e : ctx->expression()) {
		auto p = VerExprParser::visitExpression(e);
		if (res == nullptr)
			res = move(p);
		else
			res = create_object<HdlOp>(e, move(res), HdlOpType::CONCAT,
					move(p));
	}
	return res;
}

unique_ptr<iHdlExprItem> VerExprParser::visitHierarchical_identifier(
		sv2017Parser::Hierarchical_identifierContext *ctx) {
	// hierarchical_identifier:
	//    ( KW_DOLAR_ROOT DOT )? ( identifier_with_bit_select DOT )* identifier;
	unique_ptr<iHdlExprItem> selected_name = nullptr;
	auto rd = ctx->KW_DOLAR_ROOT();
	if (rd) {
		selected_name = create_object<HdlValueId>(rd, "$root");
	}
	for (auto i : ctx->identifier_with_bit_select()) {
		selected_name = visitIdentifier_with_bit_select(move(i),
				move(selected_name));
	}
	auto _id = ctx->identifier();
	auto id = visitIdentifier(_id);
	return append_expr(ctx, move(selected_name), HdlOpType::DOT, move(id));
}

string VerExprParser::getIdentifierStr(sv2017Parser::IdentifierContext *ctx) {
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
		return ctx->getText();
	}
}

unique_ptr<iHdlExprItem> VerExprParser::visitIdentifier(
		sv2017Parser::IdentifierContext *ctx) {
	return create_object<HdlValueId>(ctx, getIdentifierStr(ctx));
}

unique_ptr<iHdlExprItem> VerExprParser::visitMintypmax_expression(
		sv2017Parser::Mintypmax_expressionContext *ctx) {
	// mintypmax_expression: expression ( COLON expression COLON expression )?;
	if (ctx->expression().size() > 1) {
		NotImplementedLogger::print(
				"VerExprParser.visitMintypmax_expression - type and max specified",
				ctx);
	}
	return visitExpression(ctx->expression(0));
}

unique_ptr<iHdlExprItem> VerExprParser::visitVariable_lvalue(
		sv2017Parser::Variable_lvalueContext *ctx) {
	//variable_lvalue:
	// LBRACE variable_lvalue ( COMMA variable_lvalue )* RBRACE
	//  | package_or_class_scoped_hier_id_with_select
	//  | ( assignment_pattern_expression_type )? assignment_pattern_variable_lvalue
	//  | streaming_concatenation
	//;
	auto vls = ctx->variable_lvalue();
	if (vls.size()) {
		if (vls.size() == 1) {
			return visitVariable_lvalue(vls[0]);
		}
		vector<unique_ptr<iHdlExprItem>> parts;
		for (auto vl : vls) {
			parts.push_back(visitVariable_lvalue(vl));
		}

		return reduce(parts, HdlOpType::CONCAT);
	}
	auto pid = ctx->package_or_class_scoped_hier_id_with_select();
	if (pid) {
		return visitPackage_or_class_scoped_hier_id_with_select(pid);
	}
	auto apvl = ctx->assignment_pattern_variable_lvalue();
	if (apvl) {
		NotImplementedLogger::print(
				"VerExprParser.visitVariable_lvalue - assignment_pattern_variable_lvalue",
				ctx);
	}
	auto sc = ctx->streaming_concatenation();
	assert(sc);
	NotImplementedLogger::print(
			"VerExprParser.visitVariable_lvalue - assignment_pattern_variable_lvalue",
			ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}

unique_ptr<iHdlExprItem> VerExprParser::visitEvent_trigger(
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
	return create_object<HdlOp>(ctx, HdlOpType::ARROW, move(e));
}

unique_ptr<iHdlExprItem> VerExprParser::visitBit_select(
		sv2017Parser::Bit_selectContext *ctx,
		unique_ptr<iHdlExprItem> selected_name) {
	// bit_select: LSQUARE_BR expression RSQUARE_BR;
	auto _e = ctx->expression();
	auto e = visitExpression(_e);
	return append_expr(_e, move(selected_name), HdlOpType::INDEX, move(e));
}

unique_ptr<iHdlExprItem> VerExprParser::visitIdentifier_with_bit_select(
		sv2017Parser::Identifier_with_bit_selectContext *ctx,
		unique_ptr<iHdlExprItem> selected_name) {
	// identifier_with_bit_select: identifier ( bit_select )*;
	auto id = ctx->identifier();
	auto res = VerExprParser::visitIdentifier(id);
	res = append_expr(ctx, move(selected_name), HdlOpType::DOT, move(res));
	for (auto bs : ctx->bit_select()) {
		res = visitBit_select(bs, move(res));
	}
	return res;
}

unique_ptr<iHdlExprItem> VerExprParser::visitPackage_or_class_scoped_hier_id_with_select(
		sv2017Parser::Package_or_class_scoped_hier_id_with_selectContext *ctx) {

	// // '::' separated then '.' separated
	// package_or_class_scoped_hier_id_with_select:
	//     package_or_class_scoped_path ( bit_select )*
	//     ( DOT identifier_with_bit_select )*
	//     ( LSQUARE_BR expression ( operator_plus_minus )? COLON expression RSQUARE_BR )?;
	auto pcsp = ctx->package_or_class_scoped_path();
	auto res = visitPackage_or_class_scoped_path(pcsp);
	for (auto bs : ctx->bit_select()) {
		res = visitBit_select(bs, move(res));
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
		auto sel = create_object<HdlOp>(ctx, move(e0), HdlOpType::DOWNTO,
				move(e1));
		return append_expr(ctx, move(res), HdlOpType::INDEX, move(sel));
	}
	return res;
}

std::vector<unique_ptr<iHdlExprItem>> VerExprParser::visitParameter_value_assignment(
		sv2017Parser::Parameter_value_assignmentContext *ctx) {
	// parameter_value_assignment:
	//   HASH LPAREN ( list_of_parameter_value_assignments )? RPAREN;
	auto lpa = ctx->list_of_parameter_value_assignments();
	if (lpa) {
		VerModuleInstanceParser mip(commentParser);
		return mip.visitList_of_parameter_value_assignments(lpa);
	} else {
		return {};
	}
}

unique_ptr<iHdlExprItem> VerExprParser::visitPackage_or_class_scoped_path_item(
		sv2017Parser::Package_or_class_scoped_path_itemContext *ctx,
		unique_ptr<iHdlExprItem> selected_name,
		hdlAst::HdlOpType subname_access_type) {
	// package_or_class_scoped_path_item:
	// 	identifier ( parameter_value_assignment )?
	// ;
	auto _id = ctx->identifier();
	auto id = visitIdentifier(_id);
	if (selected_name) {
		id = create_object<HdlOp>(ctx, move(selected_name), subname_access_type,
				move(id));
	}
	auto _pva = ctx->parameter_value_assignment();
	if (_pva) {
		auto pva = visitParameter_value_assignment(_pva);
		id = HdlOp::parametrization(_pva, move(id), pva);
	}
	return id;
}

unique_ptr<iHdlExprItem> VerExprParser::visitImplicit_class_handle(
		sv2017Parser::Implicit_class_handleContext *ctx,
		unique_ptr<iHdlExprItem> selected_name, HdlOpType subname_access_type) {
	// implicit_class_handle:
	//  KW_THIS ( DOT KW_SUPER )?
	//   | KW_SUPER
	//  ;
	auto this_ = ctx->KW_THIS();
	if (this_) {
		auto t = create_object<HdlValueId>(this_, "this");
		selected_name = append_expr(ctx, move(selected_name),
				subname_access_type, move(t));
		subname_access_type = HdlOpType::DOT;
	}
	auto sup = ctx->KW_SUPER();
	if (sup) {
		auto s = create_object<HdlValueId>(sup, "super");
		selected_name = append_expr(ctx, move(selected_name),
				subname_access_type, move(s));
	}
	assert(selected_name);
	return selected_name;
}

unique_ptr<iHdlExprItem> VerExprParser::visitPackage_or_class_scoped_path(
		sv2017Parser::Package_or_class_scoped_pathContext *ctx) {
	// // '::' separated
	// package_or_class_scoped_path:
	//    ( KW_LOCAL DOUBLE_COLON )? (
	//   		KW_DOLAR_ROOT
	//         | implicit_class_handle
	//         | KW_DOLAR_UNIT
	//         | package_or_class_scoped_path_item
	// 	) ( DOUBLE_COLON package_or_class_scoped_path_item)*;
	unique_ptr<iHdlExprItem> res = nullptr;
	auto loc = ctx->KW_LOCAL();
	if (ctx->KW_LOCAL()) {
		res = create_object<HdlValueId>(loc, "local");
	}
	auto r = ctx->KW_DOLAR_ROOT();
	if (r) {
		res = append_expr(ctx, move(res), HdlOpType::DOUBLE_COLON,
				create_object<HdlValueId>(r, "$root"));
	} else {
		auto _ich = ctx->implicit_class_handle();
		if (_ich) {
			res = visitImplicit_class_handle(_ich, move(res),
					HdlOpType::DOUBLE_COLON);
		} else {
			auto du = ctx->KW_DOLAR_UNIT();
			if (du) {
				auto part = create_object<HdlValueId>(du, "$unit");
				res = append_expr(ctx, move(res), HdlOpType::DOUBLE_COLON,
						move(part));
			} else {
				auto pcspi = ctx->package_or_class_scoped_path_item();
				assert(pcspi.size() > 0);
				for (auto i : pcspi) {
					res = visitPackage_or_class_scoped_path_item(i, move(res),
							HdlOpType::DOUBLE_COLON);
				}
				return res;
			}
		}
	}
	auto pcspi = ctx->package_or_class_scoped_path_item();
	for (auto i : pcspi) {
		res = visitPackage_or_class_scoped_path_item(i, move(res),
				HdlOpType::DOUBLE_COLON);
	}
	return res;
}

unique_ptr<iHdlExprItem> VerExprParser::visitCond_predicate(
		sv2017Parser::Cond_predicateContext *ctx) {
	// cond_predicate:
	//     expression ( KW_MATCHES pattern )? ( TRIPLE_AND expression ( KW_MATCHES pattern )? )*;
	if (ctx->KW_MATCHES().size()) {
		NotImplementedLogger::print(
				"VerExprParser.visitCond_predicate.KW_MATCHES", ctx);
	}
	if (ctx->TRIPLE_AND().size()) {
		NotImplementedLogger::print(
				"VerExprParser.visitCond_predicate.TRIPLE_AND", ctx);
	}
	return visitExpression(ctx->expression(0));
}

void VerExprParser::visitList_of_arguments(
		sv2017Parser::List_of_argumentsContext *ctx,
		vector<unique_ptr<iHdlExprItem>> &args) {
	// list_of_arguments_named_item: DOT identifier LPAREN ( expression )? RPAREN;
	// list_of_arguments:
	//     ( list_of_arguments_named_item
	//      | COMMA list_of_arguments_named_item
	//      | expression ( COMMA ( expression )? )*
	//      | ( COMMA ( expression )? )+
	//     )
	//     ( COMMA list_of_arguments_named_item )*;
	VerExprParser ep(commentParser);
	bool expecting_value = true;
	for (auto c : ctx->children) {
		auto t = dynamic_cast<antlr4::tree::TerminalNode*>(c);
		bool is_comma = t && t->getSymbol()->getType() == sv2017Parser::COMMA;
		if (expecting_value && is_comma) {
			args.push_back(create_object<HdlValueId>(c, "void"));
		}
		if (is_comma) {
			expecting_value = true;
		} else {
			auto _e = dynamic_cast<sv2017Parser::ExpressionContext*>(c);
			if (_e) {
				auto e = ep.visitExpression(_e);
				args.push_back(move(e));
			} else {
				auto _ni =
						dynamic_cast<sv2017Parser::List_of_arguments_named_itemContext*>(c);
				assert(_ni);
				auto name = ep.visitIdentifier(_ni->identifier());
				unique_ptr<iHdlExprItem> v = nullptr;
				auto _v = _ni->expression();
				if (_v)
					v = ep.visitExpression(_v);
				else
					v = create_object<HdlValueId>(c, "void");
				auto e = create_object<HdlOp>(c, move(name),
						HdlOpType::MAP_ASSOCIATION, move(v));
				args.push_back(move(e));
			}
			expecting_value = false;
		}
	}
}

unique_ptr<iHdlExprItem> VerExprParser::visitOperator_assignment(
		sv2017Parser::Operator_assignmentContext *ctx) {
	// operator_assignment: variable_lvalue assignment_operator expression;
	auto vlv = ctx->variable_lvalue();
	auto dst = visitVariable_lvalue(vlv);
	auto e = ctx->expression();
	auto src = visitExpression(e);
	auto op = VerLiteralParser::visitAssignment_operator(
			ctx->assignment_operator());
	return create_object<HdlOp>(ctx, move(dst), op, move(src));
}

}
}

