#pragma once

#include <vector>
#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/arch.h>

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
