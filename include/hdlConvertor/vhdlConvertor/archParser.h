#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlAst/hdlModuleDef.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlArchParser {
	VhdlCommentParser &commentParser;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;
	VhdlArchParser(VhdlCommentParser & _commentParser, bool _hierarchyOnly);
	std::unique_ptr<hdlAst::HdlModuleDef> visitArchitecture_body(
			vhdlParser::Architecture_bodyContext *ctx);

};

}
}
