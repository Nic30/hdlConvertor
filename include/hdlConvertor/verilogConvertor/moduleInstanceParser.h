#pragma once

#include <vector>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>

#include <hdlConvertor/hdlObjects/hdlCompInstance.h>

namespace hdlConvertor {
namespace verilog {

class ModuleInstanceParser {
public:
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;

	static std::vector<hdlObjects::HdlCompInstance *> visitModule_instantiation(
			Verilog2001Parser::Module_instantiationContext* ctx);
	static std::vector<hdlObjects::iHdlExpr*> visitList_of_parameter_assignments(
			Verilog2001Parser::List_of_parameter_assignmentsContext * ctx);
	static hdlObjects::HdlCompInstance * visitModule_instance(
			Verilog2001Parser::Module_instanceContext * ctx,
			hdlObjects::iHdlExpr * module_id,
			std::vector<hdlObjects::iHdlExpr*> genericMap);
	static std::vector<hdlObjects::iHdlExpr*> visitList_of_port_connections(
			Verilog2001Parser::List_of_port_connectionsContext * ctx);
};

}
}
