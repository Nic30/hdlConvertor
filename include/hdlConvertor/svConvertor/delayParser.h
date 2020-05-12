#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/commentParser.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class VerDelayParser {
	SVCommentParser &commentParser;
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	using HdlEventList = std::unique_ptr<std::vector<std::unique_ptr<hdlAst::iHdlExprItem>>>;

	VerDelayParser(SVCommentParser &commentParser);
	std::unique_ptr<hdlAst::iHdlExprItem> visitDelay_control(
			sv2017Parser::Delay_controlContext *ctx);
	// @returns <delay, events>
	std::pair<std::unique_ptr<hdlAst::iHdlExprItem>,
			std::unique_ptr<std::vector<std::unique_ptr<hdlAst::iHdlExprItem>>>> visitProcedural_timing_control(
			sv2017Parser::Procedural_timing_controlContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitDelay_value(
			sv2017Parser::Delay_valueContext *ctx);
	HdlEventList visitEvent_control(sv2017Parser::Event_controlContext *ctx);
	// @returns <delay, events>
	std::pair<std::unique_ptr<hdlAst::iHdlExprItem>, HdlEventList> visitDelay_or_event_control(
			sv2017Parser::Delay_or_event_controlContext *ctx);
};

}

}
