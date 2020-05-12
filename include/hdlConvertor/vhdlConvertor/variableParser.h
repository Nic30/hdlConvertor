#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/hdlIdDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlVariableParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>>> visitVariable_declaration(
			vhdlParser::Variable_declarationContext *ctx);

};

}
}
