#pragma once

#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

class VerEventExprParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	SVCommentParser &commentParser;

	VerEventExprParser(SVCommentParser &commentParser);

	void visitEvent_expression(sv2017Parser::Event_expressionContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlExpr>> &items);
	void visitEvent_expression_item(
			sv2017Parser::Event_expression_itemContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::iHdlExpr>> &items);
	// @return edge operator, edge operator specified flag
	// @note SystemVerilog "edge" returns {rising, false}
	static std::pair<hdlObjects::HdlOperatorType, bool> visitEvent_identifier(
			sv2017Parser::Edge_identifierContext *ctx);
};

}
}
