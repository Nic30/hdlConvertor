#pragma once

#include <vector>
#include <string>
#include <memory>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class VerEventExprParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	static void visitEvent_expression(
			sv2017Parser::Event_expressionContext *ctx,
			std::vector<hdlObjects::iHdlExpr*> &items);
	static void visitEvent_expression_item(
			sv2017Parser::Event_expression_itemContext *ctx,
			std::vector<hdlObjects::iHdlExpr*> &items);
	// @return edge operator, edge operator specified flag
	// @note systemverilog "edge" returns {rising, false}
	static std::pair<hdlObjects::HdlOperatorType, bool> visitEvent_identifier(
			sv2017Parser::Edge_identifierContext *ctx);
};

}
}
