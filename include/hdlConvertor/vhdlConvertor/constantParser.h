#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class ConstantParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::vector<hdlObjects::HdlVariableDef*> * visitConstant_declaration(
			vhdlParser::Constant_declarationContext* ctx);

};

}
}
