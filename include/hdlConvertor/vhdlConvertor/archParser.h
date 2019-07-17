#pragma once

#include <vector>
#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/hdlModuleDef.h>

namespace hdlConvertor {
namespace vhdl {

class ArchParser: public hdlObjects::Named {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;
	ArchParser(bool _hierarchyOnly);
	hdlObjects::HdlModuleDef * visitArchitecture_body(
			vhdlParser::Architecture_bodyContext * ctx);

};

}
}
