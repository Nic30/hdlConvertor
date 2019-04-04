#pragma once

#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/direction.h"

inline Direction Direction_from(vhdl::vhdlParser::Signal_modeContext * sm) {
	if (sm->IN())
		return DIR_IN;
	else if (sm->OUT())
		return DIR_OUT;
	else if (sm->INOUT())
		return DIR_INOUT;
	else if (sm->BUFFER())
		return DIR_BUFFER;
	else {
		//assert (sm->LINKAGE());
		return DIR_LINKAGE;
	}
}
