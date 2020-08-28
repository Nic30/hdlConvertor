#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlAst/hdlModuleDef.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>
#include <hdlConvertor/vhdlConvertor/baseVhdlParser.h>


namespace hdlConvertor {
namespace vhdl {

class VhdlArchParser : public BaseVhdlParser {
public:
	using BaseVhdlParser::BaseVhdlParser;
	using vhdlParser = vhdl_antlr::vhdlParser;

	std::unique_ptr<hdlAst::HdlModuleDef> visitArchitecture_body(
			vhdlParser::Architecture_bodyContext *ctx);

};

}
}
