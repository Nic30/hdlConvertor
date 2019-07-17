#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlCompInstance.h>

namespace hdlConvertor {
namespace vhdl {

class CompInstanceParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::HdlCompInstance * visitComponent_instantiation_statement(
			vhdlParser::Component_instantiation_statementContext* ctx);
	static std::vector<hdlObjects::iHdlExpr*> * visitPort_map_aspect(
			vhdlParser::Port_map_aspectContext* ctx);
	static hdlObjects::HdlCompInstance * visitInstantiated_unit(
			vhdlParser::Instantiated_unitContext* ctx);
	static std::vector<hdlObjects::iHdlExpr*> * visitGeneric_map_aspect(
			vhdlParser::Generic_map_aspectContext* ctx);
};

}
}
