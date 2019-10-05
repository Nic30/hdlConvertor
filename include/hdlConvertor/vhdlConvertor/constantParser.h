#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlConstantParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitConstant_declaration(
			vhdlParser::Constant_declarationContext *ctx);

};

}
}
