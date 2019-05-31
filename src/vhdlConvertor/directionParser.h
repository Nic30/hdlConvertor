#pragma once

#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/direction.h"

namespace hdlConvertor {
namespace vhdl {

inline hdlObjects::Direction Direction_from(
		vhdl_antlr::vhdlParser::Signal_modeContext * sm) {
	using hdlObjects::Direction;
	if (sm->IN())
		return Direction::DIR_IN;
	else if (sm->OUT())
		return Direction::DIR_OUT;
	else if (sm->INOUT())
		return Direction::DIR_INOUT;
	else if (sm->BUFFER())
		return Direction::DIR_BUFFER;
	else {
		//assert (sm->LINKAGE());
		return Direction::DIR_LINKAGE;
	}
}

}
}
