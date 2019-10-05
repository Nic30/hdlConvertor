#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlVariableParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitVariable_declaration(
			vhdlParser::Variable_declarationContext *ctx);

};

}
}
