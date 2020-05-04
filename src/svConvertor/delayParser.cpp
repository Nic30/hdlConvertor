#include <hdlConvertor/svConvertor/delayParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/literalParser.h>
#include <hdlConvertor/svConvertor/eventExprParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/createObject.h>


using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlAst;

namespace hdlConvertor {
namespace sv {

VerDelayParser::VerDelayParser(SVCommentParser &_commentParser) :
		commentParser(_commentParser) {

}
VerDelayParser::HdlEventList VerDelayParser::visitEvent_control(
		sv2017Parser::Event_controlContext *ctx) {
	// event_control:
	//    AT ( LPAREN ( MUL
	//                 | event_expression
	//                 ) RPAREN
	//         | MUL
	//         | package_or_class_scoped_hier_id_with_select
	//       );
	auto res = make_unique<vector<unique_ptr<iHdlExprItem>>>();
	if (ctx->MUL()) {
		res->push_back(HdlValueSymbol::all());
		return res;
	}
	auto pid = ctx->package_or_class_scoped_hier_id_with_select();
	if (pid) {
		VerExprParser ep(commentParser);
		res->push_back(
				ep.visitPackage_or_class_scoped_hier_id_with_select(pid));
		return res;
	}
	auto ee = ctx->event_expression();
	assert(ee);
	VerEventExprParser eep(commentParser);
	eep.visitEvent_expression(ee, *res);
	return res;
}

pair<unique_ptr<iHdlExprItem>, unique_ptr<vector<unique_ptr<iHdlExprItem>>>> VerDelayParser::visitProcedural_timing_control(
		sv2017Parser::Procedural_timing_controlContext *ctx) {
	// procedural_timing_control:
	//    delay_control
	//     | event_control
	//     | cycle_delay
	//     | cycle_delay_range
	// ;
	auto _dc = ctx->delay_control();
	if (_dc) {
		auto dc = visitDelay_control(_dc);
		return {move(dc), nullptr};
	}
	auto _ec = ctx->event_control();
	if (_ec) {
		auto ec = visitEvent_control(_ec);
		return {nullptr, move(ec)};
	}
	if (ctx->cycle_delay()) {
		NotImplementedLogger::print(
				"VerDelayParser.visitProcedural_timing_control.cycle_delay",
				ctx);
		return {create_object<HdlExprNotImplemented>(ctx), nullptr};
	}
	assert(ctx->cycle_delay_range());
	NotImplementedLogger::print(
			"VerDelayParser.visitProcedural_timing_control.cycle_delay_range",
			ctx);
	return {create_object<HdlExprNotImplemented>(ctx), nullptr};
}

unique_ptr<iHdlExprItem> VerDelayParser::visitDelay_control(
		sv2017Parser::Delay_controlContext *ctx) {
	// delay_control:
	//     HASH ( LPAREN mintypmax_expression RPAREN
	//            | delay_value
	//          );
	auto dv = ctx->delay_value();
	if (dv)
		return visitDelay_value(dv);
	else {
		auto me = ctx->mintypmax_expression();
		VerExprParser ep(commentParser);
		return ep.visitMintypmax_expression(me);
	}
}

unique_ptr<iHdlExprItem> VerDelayParser::visitDelay_value(
		sv2017Parser::Delay_valueContext *ctx) {
	// delay_value:
	//     UNSIGNED_NUMBER
	//     | TIME_LITERAL
	//     | KW_1STEP
	//     | real_number
	//     | ps_identifier;
	auto un = ctx->UNSIGNED_NUMBER();
	if (un) {
		return VerLiteralParser::visitUNSIGNED_NUMBER(un);
	}
	auto tl = ctx->TIME_LITERAL();
	if (tl) {
		return VerLiteralParser::visitTIME_LITERAL(tl);
	}
	if (ctx->KW_1STEP())
		return create_object<HdlValueId>(ctx, "1step");
	auto r = ctx->real_number();
	if (r) {
		return VerLiteralParser::visitReal_number(r);
	}
	auto pi = ctx->ps_identifier();
	assert(pi);
	return VerExprParser(commentParser).visitPs_identifier(pi);
}

pair<unique_ptr<iHdlExprItem>, VerDelayParser::HdlEventList> VerDelayParser::visitDelay_or_event_control(
		sv2017Parser::Delay_or_event_controlContext *ctx) {
	// delay_or_event_control:
	//     delay_control
	//     | ( KW_REPEAT LPAREN expression RPAREN )? event_control
	// ;
	auto _d = ctx->delay_control();
	if (_d) {
		auto d = visitDelay_control(_d);
		return {move(d), nullptr};
	}
	auto ec = ctx->event_control();
	auto e = ctx->expression();
	if (e) {
		NotImplementedLogger::print(
				"VerStatementParser.visitDelay_or_event_control.repeat", e);
	}
	return {nullptr, visitEvent_control(ec)};
}

}
}
