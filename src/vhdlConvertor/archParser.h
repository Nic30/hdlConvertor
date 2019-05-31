#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/arch.h"

namespace hdlConvertor {
namespace vhdl {

class ArchParser: public hdlObjects::Named {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;
	ArchParser(bool _hierarchyOnly);
	hdlObjects::Arch * visitArchitecture_body(
			vhdlParser::Architecture_bodyContext * ctx);

};

}
}
