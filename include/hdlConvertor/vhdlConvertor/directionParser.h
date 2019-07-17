#pragma once

#include <assert.h>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlDirection.h>

namespace hdlConvertor {
namespace vhdl {

inline hdlObjects::HdlDirection visitSignalMode(
		vhdl_antlr::vhdlParser::Signal_modeContext * ctx) {
	using hdlObjects::HdlDirection;

	if (ctx == nullptr || ctx->IN())
		return HdlDirection::DIR_IN;
	else if (ctx->OUT())
		return HdlDirection::DIR_OUT;
	else if (ctx->INOUT())
		return HdlDirection::DIR_INOUT;
	else if (ctx->BUFFER())
		return HdlDirection::DIR_BUFFER;
	else {
		//assert (sm->LINKAGE());
		return HdlDirection::DIR_LINKAGE;
	}
}

inline hdlObjects::HdlOperatorType visitDirection(
		vhdl_antlr::vhdlParser::DirectionContext * ctx) {
	// direction: TO | DOWNTO;
	if (ctx->TO())
		return hdlObjects::TO;
	else {
		assert(ctx->DOWNTO());
		return hdlObjects::DOWNTO;
	}
}

}
}
