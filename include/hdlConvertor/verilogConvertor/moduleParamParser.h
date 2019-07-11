#pragma once

#include <vector>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>

#include <hdlConvertor/verilogConvertor/commentParser.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace verilog {

class ModuleParamParser {
	CommentParser & commentParser;
public:
	ModuleParamParser(CommentParser & commentParser);
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;

	static hdlObjects::iHdlExpr * visitParameter_identifier(
			Verilog2001Parser::Parameter_identifierContext * ctx);

	std::vector<hdlObjects::HdlVariableDef*>* visitModule_parameter_port_list(
			Verilog2001Parser::Module_parameter_port_listContext * ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitParameter_declaration_(
			Verilog2001Parser::Parameter_declaration_Context * ctx);
	std::vector<hdlObjects::HdlVariableDef*> *visitList_of_param_assignments(
			Verilog2001Parser::List_of_param_assignmentsContext * ctx);
	hdlObjects::HdlVariableDef * visitParam_assignment(
			Verilog2001Parser::Param_assignmentContext * ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitParameter_declaration(
			Verilog2001Parser::Parameter_declarationContext * ctx);
};

}
}
