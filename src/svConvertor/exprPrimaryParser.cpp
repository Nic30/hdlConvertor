#include <hdlConvertor/svConvertor/exprPrimaryParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/literalParser.h>
#include <hdlConvertor/notImplementedLogger.h>


namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;

iHdlExpr* VerExprPrimaryParser::visitPrimary(
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
		return VerLiteralParser::visitPackage_or_class_scoped_path();
	}

	if (dynamic_cast<sv2017Parser::PrimaryParContext*>(ctx)) {
		auto e =
				static_cast<sv2017Parser::PrimaryParContext*>(ctx)->mintypmax_expression();
		return VerExprParser::visitMintypmax_expression(e);
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
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryCast(
		sv2017Parser::PrimaryCastContext *ctx) {
	//     | ( KW_STRING
	//         | KW_CONST
	//         | integer_type
	//         | non_integer_type
	//         | signing
	//         ) APOSTROPHE LPAREN expression RPAREN     #PrimaryCast

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryCast", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryCast2(
		sv2017Parser::PrimaryCast2Context *ctx) {
	//     | primary APOSTROPHE LPAREN expression RPAREN #PrimaryCast2

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryCast2", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryBitSelect(
		sv2017Parser::PrimaryBitSelectContext *ctx) {
	//     | primary bit_select                          #PrimaryBitSelect

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryBitSelect",
			ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryDot(
		sv2017Parser::PrimaryDotContext *ctx) {
	//     | primary DOT identifier                      #PrimaryDot

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryDot", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryIndex(
		sv2017Parser::PrimaryIndexContext *ctx) {
	//     | primary LSQUARE_BR array_range_expression RSQUARE_BR #PrimaryIndex

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryIndex", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryConcat(
		sv2017Parser::PrimaryConcatContext *ctx) {
	//     | concatenation                                        #PrimaryConcat

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryConcat", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryStreaming_concatenation(
		sv2017Parser::PrimaryStreaming_concatenationContext *ctx) {
	//     | streaming_concatenation                              #PrimaryStreaming_concatenation

	NotImplementedLogger::print(
			"VerExprPrimaryParser.visitPrimaryStreaming_concatenation", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryTfCall(
		sv2017Parser::PrimaryTfCallContext *ctx) {
	//     | any_system_tf_identifier ( LPAREN data_type COMMA list_of_arguments
	//          ( COMMA clocking_event )? RPAREN
	//          | LPAREN list_of_arguments COMMA clocking_event  RPAREN
	//          )?                                       #PrimaryTfCall

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryTfCall", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryRandomize(
		sv2017Parser::PrimaryRandomizeContext *ctx) {
	//     | ( KW_STD DOUBLE_COLON )?  randomize_call    #PrimaryRandomize

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryRandomize",
			ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryRandomize2(
		sv2017Parser::PrimaryRandomize2Context *ctx) {
	//     | primary DOT randomize_call                  #PrimaryRandomize2

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryRandomize2",
			ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryAssig(
		sv2017Parser::PrimaryAssigContext *ctx) {
	//     | assignment_pattern_expression               #PrimaryAssig

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryAssig", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryTypeRef(
		sv2017Parser::PrimaryTypeRefContext *ctx) {
	//     | type_reference                              #PrimaryTypeRef

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryTypeRef",
			ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryCall(
		sv2017Parser::PrimaryCallContext *ctx) {
	//     | primary ( DOT array_method_name )? ( attribute_instance )*
	//                   LPAREN ( list_of_arguments )? RPAREN
	//                   ( KW_WITH LPAREN expression RPAREN )? #PrimaryCall

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryCall", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryCallArrayMethodNoArgs(
		sv2017Parser::PrimaryCallArrayMethodNoArgsContext *ctx) {
	//     | primary DOT array_method_name               #PrimaryCallArrayMethodNoArgs

	NotImplementedLogger::print(
			"VerExprPrimaryParser.visitPrimaryCallArrayMethodNoArgs", ctx);
	return iHdlExpr::null();
}
hdlObjects::iHdlExpr* VerExprPrimaryParser::visitPrimaryCallWith(
		sv2017Parser::PrimaryCallWithContext *ctx) {
	//     | primary ( DOT array_method_name )? ( attribute_instance )*
	//              KW_WITH LPAREN expression RPAREN     #PrimaryCallWith

	NotImplementedLogger::print("VerExprPrimaryParser.visitPrimaryCallWith",
			ctx);
	return iHdlExpr::null();
}

}
}
