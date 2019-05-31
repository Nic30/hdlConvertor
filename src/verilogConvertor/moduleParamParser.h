#pragma once

#include <vector>
#include "../hdlObjects/variable.h"
#include "Verilog2001Parser/Verilog2001Parser.h"
#include "commentParser.h"

namespace hdlConvertor {
namespace verilog {

class ModuleParamParser {
	CommentParser & commentParser;
public:
	ModuleParamParser(CommentParser & commentParser);
	typedef hdlObjects::Variable Variable;
	typedef Verilog2001_antlr::Verilog2001Parser Verilog2001Parser;

	std::vector<Variable*>* visitModule_parameter_port_list(
			Verilog2001Parser::Module_parameter_port_listContext * ctx);
	std::vector<Variable*>* visitParameter_declaration_(
			Verilog2001Parser::Parameter_declaration_Context * ctx);
	std::vector<Variable*> *visitList_of_param_assignments(
			Verilog2001Parser::List_of_param_assignmentsContext * ctx);
	Variable * visitParam_assignment(
			Verilog2001Parser::Param_assignmentContext * ctx);
	std::vector<Variable*>* visitParameter_declaration(
			Verilog2001Parser::Parameter_declarationContext * ctx);
};

}
}
