#include <hdlConvertor/svConvertor/eventExprParser.h>
#include <memory>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/notImplementedLogger.h>

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlAst;


namespace hdlConvertor {
namespace sv {

VerEventExprParser::VerEventExprParser(SVCommentParser &_commentParser) :
		commentParser(_commentParser) {
}

void VerEventExprParser::visitEvent_expression(
		sv2017Parser::Event_expressionContext *ctx,
		std::vector<std::unique_ptr<iHdlExprItem>> &items) {
	// event_expression: event_expression_item ( ( KW_OR | COMMA ) event_expression_item )*;
	// @note 'or' and ',' is a Verilog-1995/2001 difference, they work exactly the same

	for (auto ep : ctx->event_expression_item()) {
		visitEvent_expression_item(ep, items);
	}
}

void VerEventExprParser::visitEvent_expression_item(
		sv2017Parser::Event_expression_itemContext *ctx,
		std::vector<unique_ptr<iHdlExprItem>> &items) {
	// event_expression_item:
	//     LPAREN event_expression RPAREN
	//     | ( edge_identifier )? expression ( KW_IFF expression )?
	// ;
	auto ee = ctx->event_expression();
	if (ee) {
		visitEvent_expression(ee, items);
	} else {
		auto _e = ctx->expression();
		VerExprParser ep(commentParser);
		auto e = ep.visitExpression(_e[0]);
		auto ei = ctx->edge_identifier();
		if (ei) {
			// [todo] must have
			auto edge_type = visitEvent_identifier(ei);
			if (edge_type.second)
				e = create_object<HdlOp>(_e[0], edge_type.first, move(e));
		}
		if (_e.size() != 1) {
			NotImplementedLogger::print(
					"VerEventExprParser.visitEvent_expression_item - KW_IFF",
					ctx);
		}
		items.push_back(move(e));
	}
}
std::pair<HdlOpType, bool> VerEventExprParser::visitEvent_identifier(
		sv2017Parser::Edge_identifierContext *ctx) {
	// edge_identifier:
	//    KW_POSEDGE
	//    | KW_NEGEDGE
	//    | KW_EDGE
	// ;
	if (ctx->KW_POSEDGE()) {
		return {HdlOpType::RISING, true};
	} else if (ctx->KW_NEGEDGE()) {
		return {HdlOpType::FALLING, true};
	} else {
		assert(ctx->KW_EDGE());
		return {HdlOpType::RISING, false};
	}
}

}
}
