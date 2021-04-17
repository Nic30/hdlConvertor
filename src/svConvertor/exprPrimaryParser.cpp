#include <hdlConvertor/svConvertor/exprPrimaryParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/literalParser.h>
#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/utils.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/createObject.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using namespace hdlConvertor::hdlAst;

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimary(
		sv2017Parser::PrimaryContext *ctx) {
	// primary:
	//     primary_literal                               #primaryLit
	//     | package_or_class_scoped_path                #primaryPath
	//     | LPAREN mintypmax_expression RPAREN          #primaryPar
	//     | ( KW_STRING
	//         | KW_CONST
	//         | integer_type
	//         | non_integer_type
	//         | signing
	//         ) APOSTROPHE LPAREN expression RPAREN     #primaryCast
	//     | primary APOSTROPHE LPAREN expression RPAREN #primaryCast2
	//     | primary bit_select                          #primaryBitSelect
	//     | primary DOT identifier                      #primaryDot
	//     | primary LSQUARE_BR array_range_expression RSQUARE_BR #primaryIndex
	//     | concatenation                                        #primaryConcat
	//     | streaming_concatenation                              #primaryStreaming_concatenation
	//     | any_system_tf_identifier ( LPAREN data_type COMMA list_of_arguments
	//          ( COMMA clocking_event )? RPAREN
	//          | LPAREN list_of_arguments COMMA clocking_event  RPAREN
	//          )?                                       #primaryTfCall
	//     | ( KW_STD DOUBLE_COLON )?  randomize_call    #primaryRandomize
	//     | primary DOT randomize_call                  #primaryRandomize2
	//     /*| let_expression                            #primaryLet (same as call)*/
	//     | assignment_pattern_expression               #primaryAssig
	//     | type_reference                              #primaryTypeRef
	//     | primary ( DOT array_method_name )? ( attribute_instance )*
	//                   LPAREN ( list_of_arguments )? RPAREN
	//                   ( KW_WITH LPAREN expression RPAREN )? #primaryCall
	//     | primary DOT array_method_name               # primaryCallArrayMethodNoArgs
	//     | primary ( DOT array_method_name )? ( attribute_instance )*
	//              KW_WITH LPAREN expression RPAREN     #primaryCallWith
	// ;
	if (dynamic_cast<sv2017Parser::PrimaryLitContext*>(ctx)) {
		auto l =
				static_cast<sv2017Parser::PrimaryLitContext*>(ctx)->primary_literal();
		return VerLiteralParser::visitPrimary_literal(l);
	}

	if (dynamic_cast<sv2017Parser::PrimaryPathContext*>(ctx)) {
		auto p =
				static_cast<sv2017Parser::PrimaryPathContext*>(ctx)->package_or_class_scoped_path();
		VerExprParser ep(this);
		return ep.visitPackage_or_class_scoped_path(p);
	}

	if (dynamic_cast<sv2017Parser::PrimaryParContext*>(ctx)) {
		auto e =
				static_cast<sv2017Parser::PrimaryParContext*>(ctx)->mintypmax_expression();
		return VerExprParser(this).visitMintypmax_expression(e);
	}

	if (dynamic_cast<sv2017Parser::PrimaryCastContext*>(ctx)) {
		return visitPrimaryCast(
				static_cast<sv2017Parser::PrimaryCastContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryCast2Context*>(ctx)) {
		return visitPrimaryCast2(
				static_cast<sv2017Parser::PrimaryCast2Context*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryBitSelectContext*>(ctx)) {
		return visitPrimaryBitSelect(
				static_cast<sv2017Parser::PrimaryBitSelectContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryDotContext*>(ctx)) {
		return visitPrimaryDot(
				static_cast<sv2017Parser::PrimaryDotContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryIndexContext*>(ctx)) {
		return visitPrimaryIndex(
				static_cast<sv2017Parser::PrimaryIndexContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryConcatContext*>(ctx)) {
		return visitPrimaryConcat(
				static_cast<sv2017Parser::PrimaryConcatContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryStreaming_concatenationContext*>(ctx)) {
		return visitPrimaryStreaming_concatenation(
				static_cast<sv2017Parser::PrimaryStreaming_concatenationContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryTfCallContext*>(ctx)) {
		return visitPrimaryTfCall(
				static_cast<sv2017Parser::PrimaryTfCallContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryRandomizeContext*>(ctx)) {
		return visitPrimaryRandomize(
				static_cast<sv2017Parser::PrimaryRandomizeContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryRandomize2Context*>(ctx)) {
		return visitPrimaryRandomize2(
				static_cast<sv2017Parser::PrimaryRandomize2Context*>(ctx));
	}
	if (dynamic_cast<sv2017Parser::PrimaryAssigContext*>(ctx)) {
		return visitPrimaryAssig(
				static_cast<sv2017Parser::PrimaryAssigContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryTypeRefContext*>(ctx)) {
		return visitPrimaryTypeRef(
				static_cast<sv2017Parser::PrimaryTypeRefContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryCallContext*>(ctx)) {
		return visitPrimaryCall(
				static_cast<sv2017Parser::PrimaryCallContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryCallArrayMethodNoArgsContext*>(ctx)) {
		return visitPrimaryCallArrayMethodNoArgs(
				static_cast<sv2017Parser::PrimaryCallArrayMethodNoArgsContext*>(ctx));
	}

	if (dynamic_cast<sv2017Parser::PrimaryCallWithContext*>(ctx)) {
		return visitPrimaryCallWith(
				static_cast<sv2017Parser::PrimaryCallWithContext*>(ctx));
	}
	assert(false && "unexpected item in this context");
	return nullptr;
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryCast(
		sv2017Parser::PrimaryCastContext *ctx) {
	//     | ( KW_STRING
	//         | KW_CONST
	//         | integer_type
	//         | non_integer_type
	//         | signing
	//         ) APOSTROPHE LPAREN expression RPAREN     #PrimaryCast

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryCast", ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryCast2(
		sv2017Parser::PrimaryCast2Context *ctx) {
	//     | primary APOSTROPHE LPAREN expression RPAREN #PrimaryCast2
	auto _p = ctx->primary();
	auto p = visitPrimary(_p);
	auto _e = ctx->expression();
	VerExprParser ep(this);
	auto e = ep.visitExpression(_e);
	return create_object<HdlOp>(ctx, move(p), HdlOpType::CALL, move(e));
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryBitSelect(
		sv2017Parser::PrimaryBitSelectContext *ctx) {
	//     | primary bit_select                          #PrimaryBitSelect
	auto _p = ctx->primary();
	auto p = visitPrimary(_p);
	auto _bs = ctx->bit_select();
	VerExprParser ep(this);
	return ep.visitBit_select(_bs, move(p));
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryDot(
		sv2017Parser::PrimaryDotContext *ctx) {
	//     | primary DOT identifier                      #PrimaryDot
	auto _p = ctx->primary();
	auto p = visitPrimary(_p);
	auto _id = ctx->identifier();
	auto id = VerExprParser::visitIdentifier(_id);
	return append_expr(_p, move(p), HdlOpType::DOT, move(id));
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryIndex(
		sv2017Parser::PrimaryIndexContext *ctx) {
	//     | primary LSQUARE_BR array_range_expression RSQUARE_BR #PrimaryIndex
	auto _p = ctx->primary();
	auto p = visitPrimary(_p);
	auto _are = ctx->array_range_expression();
	VerExprParser ep(this);
	auto are = ep.visitArray_range_expression(_are);
	p = append_expr(_p, move(p), HdlOpType::INDEX, move(are));
	return p;
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryConcat(
		sv2017Parser::PrimaryConcatContext *ctx) {
	//     | concatenation                                        #PrimaryConcat
	auto c = ctx->concatenation();
	VerExprParser ep(this);
	return ep.visitConcatenation(c);
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryStreaming_concatenation(
		sv2017Parser::PrimaryStreaming_concatenationContext *ctx) {
	//     | streaming_concatenation                              #PrimaryStreaming_concatenation

	NotImplementedLogger::print(
			"VerExprPrimaryParser.visitPrimaryStreaming_concatenation", ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryTfCall(
		sv2017Parser::PrimaryTfCallContext *ctx) {
	//     | any_system_tf_identifier ( LPAREN data_type COMMA list_of_arguments
	//          ( COMMA clocking_event )? RPAREN
	//          | LPAREN list_of_arguments ( COMMA clocking_event )?  RPAREN
	//          )?                                       #PrimaryTfCall
	auto astfi = ctx->any_system_tf_identifier();
	auto id = VerLiteralParser::visitAny_system_tf_identifier(astfi);

	VerExprParser ep(this);
	VerTypeParser tp(this);
	vector<unique_ptr<iHdlExprItem>> args;
	auto _dt = ctx->data_type();
	if (_dt)
		args.push_back(tp.visitData_type(_dt));
	auto loa = ctx->list_of_arguments();
	if (loa)
		ep.visitList_of_arguments(loa, args);

	auto ce = ctx->clocking_event();
	if (ce) {
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitPrimaryTfCall.clocking_event", ctx);
		// args.push_back(ep.visitClocking_event(ce));
	}
	return HdlOp::call(ctx, move(id), args);
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryRandomize(
		sv2017Parser::PrimaryRandomizeContext *ctx) {
	//     | ( KW_STD DOUBLE_COLON )?  randomize_call    #PrimaryRandomize

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryRandomize",
			ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}
unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryRandomize2(
		sv2017Parser::PrimaryRandomize2Context *ctx) {
	//     | primary DOT randomize_call                  #PrimaryRandomize2

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryRandomize2",
			ctx);
	return create_object<HdlExprNotImplemented>(ctx);
}
unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryAssig(
		sv2017Parser::PrimaryAssigContext *ctx) {
	//     | assignment_pattern_expression               #PrimaryAssig
	// assignment_pattern_expression:
	//  ( assignment_pattern_expression_type )? assignment_pattern;
	auto ape = ctx->assignment_pattern_expression();
	if (ape->assignment_pattern_expression_type()) {
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitPrimaryAssig assignment_pattern_expression_type",
				ctx);
	}
	return visitAssignment_pattern(ape->assignment_pattern());
}

std::unique_ptr<hdlAst::iHdlExprItem> VerExprPrimaryParser::visitStructure_pattern_key(
		sv2017Parser::Structure_pattern_keyContext *ctx) {
	// structure_pattern_key:
	//  identifier
	//   | assignment_pattern_key
	// ;
	auto i = ctx->identifier();
	if (i) {
		VerExprParser ep(this);
		return ep.visitIdentifier(i);
	} else {
		return visitAssignment_pattern_key(ctx->assignment_pattern_key());
	}
}
std::unique_ptr<hdlAst::iHdlExprItem> VerExprPrimaryParser::visitArray_pattern_key(
		sv2017Parser::Array_pattern_keyContext *ctx) {
	// array_pattern_key:
	//  constant_expression
	//   | assignment_pattern_key
	// ;
	auto ce = ctx->constant_expression();
	if (ce) {
		VerExprParser ep(this);
		return ep.visitConstant_expression(ce);
	} else {
		auto apk = ctx->assignment_pattern_key();
		assert(apk);
		return visitAssignment_pattern_key(apk);
	}
}
std::unique_ptr<hdlAst::iHdlExprItem> VerExprPrimaryParser::visitAssignment_pattern_key(
		sv2017Parser::Assignment_pattern_keyContext *ctx) {
	// assignment_pattern_key:
	//  KW_DEFAULT
	//   | integer_type
	//   | non_integer_type
	//   | package_or_class_scoped_path
	// ;
	if (ctx->KW_DEFAULT()) {
		return make_unique<HdlValueId>("default");
	}
	auto it = ctx->integer_type();
	if (it) {
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitAssignment_pattern_key integer_type",
				ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}
	auto nit = ctx->non_integer_type();
	if (nit) {
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitAssignment_pattern non_integer_type",
				ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}
	auto pcsp = ctx->package_or_class_scoped_path();
	assert(pcsp);
	VerExprParser ep(this);
	return ep.visitPackage_or_class_scoped_path(pcsp);
}

std::unique_ptr<hdlAst::iHdlExprItem> VerExprPrimaryParser::visitAssignment_pattern(
		sv2017Parser::Assignment_patternContext *ctx) {
	// assignment_pattern:
	//     APOSTROPHE_LBRACE (
	//         expression ( COMMA expression )*
	//         | structure_pattern_key COLON expression
	//            ( COMMA structure_pattern_key COLON expression )*
	//         | array_pattern_key COLON expression
	//            ( COMMA array_pattern_key COLON expression )*
	//         | constant_expression LBRACE expression ( COMMA expression )* RBRACE
	//     )? RBRACE;
	std::vector<std::unique_ptr<iHdlExprItem>> keys;
	auto exprs = make_unique<std::vector<std::unique_ptr<iHdlExprItem>>>();
	for (auto e : ctx->expression()) {
		auto o = VerExprParser(this).visitExpression(e);
		exprs->push_back(move(o));
	}
	auto sp = ctx->structure_pattern_key();
	if (sp.size()) {
		for (auto _sp : sp) {
			keys.push_back(visitStructure_pattern_key(_sp));
		}
	} else {
		auto ap = ctx->array_pattern_key();
		if (ap.size()) {
			for (auto _ap : ap) {
				keys.push_back(visitArray_pattern_key(_ap));
			}
		}
	}
	auto ce = ctx->constant_expression();
	if (ce) {
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitAssignment_pattern constant_expression",
				ctx);
		return create_object<HdlExprNotImplemented>(ctx);
	}
	if (keys.size()) {
		// associate keys with items (create a list of key:expr)
		auto new_exprs =
				make_unique<std::vector<std::unique_ptr<iHdlExprItem>>>();
		auto e_it = exprs->begin();
		assert(keys.size() == exprs->size());
		for (auto &k : keys) {
			auto n_e = make_unique<HdlOp>(move(k), HdlOpType::MAP_ASSOCIATION,
					move(*e_it));
			new_exprs->push_back(move(n_e));
			++e_it;
		}
		exprs = move(new_exprs);
	}

	return make_unique<HdlValueArr>(move(exprs));
}
unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryTypeRef(
		sv2017Parser::PrimaryTypeRefContext *ctx) {
	//     | type_reference                              #PrimaryTypeRef
	auto t = ctx->type_reference();
	VerTypeParser tp(this);
	return tp.visitType_reference(t);
}
unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryCall(
		sv2017Parser::PrimaryCallContext *ctx) {
	//     | primary ( DOT array_method_name )? ( attribute_instance )*
	//                   LPAREN ( list_of_arguments )? RPAREN
	//                   ( KW_WITH LPAREN expression RPAREN )? #PrimaryCall
	auto _p = ctx->primary();
	auto p = visitPrimary(_p);
	auto _amn = ctx->array_method_name();
	if (_amn) {
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitPrimaryCall.array_method_name",
				_amn);
		// auto amn = visitArray_method_name(_amn);
		// p = make_unique<HdlOp>(p, HdlOpType::DOT, amn);
	}
	VerAttributeParser::visitAttribute_instance(ctx->attribute_instance());
	if (ctx->KW_WITH())
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitPrimaryCall.with", ctx);

	VerExprParser ep(this);
	vector<unique_ptr<iHdlExprItem>> args;
	auto loa = ctx->list_of_arguments();
	if (loa) {
		ep.visitList_of_arguments(loa, args);
		return HdlOp::call(ctx, move(p), args);
	} else {
		return p;
	}
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryCallArrayMethodNoArgs(
		sv2017Parser::PrimaryCallArrayMethodNoArgsContext *ctx) {
	//     | primary DOT array_method_name               #PrimaryCallArrayMethodNoArgs

	auto _p = ctx->primary();
	auto p = visitPrimary(_p);
	auto _amn = ctx->array_method_name();
	NotImplementedLogger::print(
			"VerExprPrimaryParser.visitPrimaryCallArrayMethodNoArgs.array_method_name",
			_amn);
	// auto amn = visitArray_method_name(_amn);
	// p = make_unique<HdlOp>(move(p), HdlOpType::DOT, move(amn));

	VerExprParser ep(this);
	vector<unique_ptr<iHdlExprItem>> args;
	return HdlOp::call(ctx, move(p), args);
}

unique_ptr<iHdlExprItem> VerExprPrimaryParser::visitPrimaryCallWith(
		sv2017Parser::PrimaryCallWithContext *ctx) {
	//     | primary ( DOT array_method_name )? ( attribute_instance )*
	//              KW_WITH LPAREN expression RPAREN     #PrimaryCallWith

	auto _p = ctx->primary();
	auto p = visitPrimary(_p);
	auto _amn = ctx->array_method_name();
	if (_amn) {
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitPrimaryCallWith.array_method_name",
				_amn);
		// auto amn = visitArray_method_name(_amn);
		// p = make_unique<HdlOp>(p, HdlOpType::DOT, amn);
	}
	VerAttributeParser::visitAttribute_instance(ctx->attribute_instance());
	if (ctx->KW_WITH())
		NotImplementedLogger::print(
				"VerExprPrimaryParser.visitPrimaryCallWith.with", ctx);

	VerExprParser ep(this);
	vector<unique_ptr<iHdlExprItem>> args;
	return HdlOp::call(ctx, move(p), args);
}

}
}
