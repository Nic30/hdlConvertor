#pragma once

#include "../VhdlParser/vhdlParser.h"
#include "../hdlObjects/direction.h"

using namespace antlr4;
using namespace vhdl;

inline Direction Direction_from(Ref<vhdlParser::Signal_modeContext> sm) {
	if (sm->IN())
		return IN;
	else if (sm->OUT())
		return OUT;
	else if (sm->INOUT())
		return INOUT;
	else if (sm->BUFFER())
		return BUFFER;
	else {
		//assert (sm->LINKAGE());
		return LINKAGE;
	}
}
