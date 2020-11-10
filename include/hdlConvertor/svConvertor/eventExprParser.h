#pragma once

#include <hdlConvertor/hdlAst/hdlOpType.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/baseSvParser.h>

namespace hdlConvertor {
namespace sv {

class VerEventExprParser: public BaseSvParser {
public:
	using BaseSvParser::BaseSvParser;
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	void visitEvent_expression(sv2017Parser::Event_expressionContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> &items);
	void visitEvent_expression_item(
			sv2017Parser::Event_expression_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> &items);
	// @return edge operator, edge operator specified flag
	// @note SystemVerilog "edge" returns {rising, false}
	static std::pair<hdlAst::HdlOpType, bool> visitEvent_identifier(
			sv2017Parser::Edge_identifierContext *ctx);
};

}
}
