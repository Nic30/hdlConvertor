#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>

#include <hdlConvertor/svConvertor/commentParser.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace sv {

class ModuleParamParser {
	SVCommentParser & commentParser;
public:
	ModuleParamParser(SVCommentParser & commentParser);
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	std::vector<hdlObjects::HdlVariableDef*>* visitModule_parameter_port_list(
			sv2017Parser::Module_parameter_port_listContext * ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitParameter_declaration_(
			sv2017Parser::Parameter_declaration_Context * ctx);
	std::vector<hdlObjects::HdlVariableDef*> *visitList_of_param_assignments(
			sv2017Parser::List_of_param_assignmentsContext * ctx);
	hdlObjects::HdlVariableDef * visitParam_assignment(
			sv2017Parser::Param_assignmentContext * ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitParameter_declaration(
			sv2017Parser::Parameter_declarationContext * ctx);
};

}
}
