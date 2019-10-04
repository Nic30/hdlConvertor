#pragma once

#include <vector>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/hdlCompInstance.h>
#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

class VerModuleInstanceParser {
	SVCommentParser &commentParser;
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	VerModuleInstanceParser(SVCommentParser &commentParser);

	void visitModule_or_interface_or_program_or_udp_instantiation(
			sv2017Parser::Module_or_interface_or_program_or_udp_instantiationContext *ctx,
			std::vector<hdlObjects::HdlCompInstance*> &res);
	std::vector<hdlObjects::iHdlExpr*> visitList_of_parameter_value_assignments(
			sv2017Parser::List_of_parameter_value_assignmentsContext *ctx);
	hdlObjects::HdlCompInstance* visitHierarchical_instance(
			sv2017Parser::Hierarchical_instanceContext *ctx,
			hdlObjects::iHdlExpr *module_id,
			std::vector<hdlObjects::iHdlExpr*> genericMap);
	std::vector<hdlObjects::iHdlExpr*> visitList_of_port_connections(
			sv2017Parser::List_of_port_connectionsContext *ctx);
};

}
}
