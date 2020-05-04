#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/hdlIdDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlSignalParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>>> visitSignal_declaration(
			vhdlParser::Signal_declarationContext *ctx);

};

}
}
