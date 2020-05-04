#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/hdlCompInst.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlCompInstParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlAst::HdlCompInst> visitComponent_instantiation_statement(
			vhdlParser::Component_instantiation_statementContext *ctx,
			const std::string &name);
	static std::unique_ptr<std::vector<std::unique_ptr<hdlAst::iHdlExprItem>>> visitPort_map_aspect(
			vhdlParser::Port_map_aspectContext *ctx);
	static std::unique_ptr<hdlAst::HdlCompInst> visitInstantiated_unit(
			vhdlParser::Instantiated_unitContext *ctx);
	static std::unique_ptr<std::vector<std::unique_ptr<hdlAst::iHdlExprItem>>> visitGeneric_map_aspect(
			vhdlParser::Generic_map_aspectContext *ctx);
};

}
}
