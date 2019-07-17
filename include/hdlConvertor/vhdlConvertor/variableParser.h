#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class VariableParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::vector<hdlObjects::HdlVariableDef*> * visitVariable_declaration(
			vhdlParser::Variable_declarationContext* ctx);

};

}
}
