#pragma once

#include <assert.h>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/direction.h"

namespace hdlConvertor {
namespace vhdl {

inline hdlObjects::Direction visitSignalMode(
		vhdl_antlr::vhdlParser::Signal_modeContext * ctx) {
	using hdlObjects::Direction;

	if (ctx == nullptr || ctx->IN())
		return Direction::DIR_IN;
	else if (ctx->OUT())
		return Direction::DIR_OUT;
	else if (ctx->INOUT())
		return Direction::DIR_INOUT;
	else if (ctx->BUFFER())
		return Direction::DIR_BUFFER;
	else {
		//assert (sm->LINKAGE());
		return Direction::DIR_LINKAGE;
	}
}

inline hdlObjects::OperatorType visitDirection(
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
