#pragma once

#include <vector>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/hdlCompInstance.h>

namespace hdlConvertor {
namespace sv {

class ModuleInstanceParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	static std::vector<hdlObjects::HdlCompInstance *> visitModule_or_interface_or_program_instantiation(
			sv2017Parser::Module_or_interface_or_program_instantiationContext* ctx);
	static std::vector<hdlObjects::iHdlExpr*> visitList_of_parameter_value_assignments(
			sv2017Parser::List_of_parameter_value_assignmentsContext * ctx);
	static hdlObjects::HdlCompInstance * visitHierarchical_instance(
			sv2017Parser::Hierarchical_identifierContext* ctx,
			hdlObjects::iHdlExpr * module_id,
			std::vector<hdlObjects::iHdlExpr*> genericMap);
	static std::vector<hdlObjects::iHdlExpr*> visitList_of_port_connections(
			sv2017Parser::List_of_port_connectionsContext * ctx);
};

}
}
