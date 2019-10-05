#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/hdlModuleDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlArchParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;
	VhdlArchParser(bool _hierarchyOnly);
	std::unique_ptr<hdlObjects::HdlModuleDef> visitArchitecture_body(
			vhdlParser::Architecture_bodyContext *ctx);

};

}
}
