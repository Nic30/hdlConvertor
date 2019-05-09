#pragma once

#include <vector>
#include "../hdlObjects/compInstance.h"
#include "Verilog2001Parser/Verilog2001Parser.h"

class ModuleInstanceParser {
public:
	static std::vector<CompInstance *> visitModule_instantiation(
			Verilog2001::Verilog2001Parser::Module_instantiationContext* ctx);
	static Expr * visitParameter_identifier(
			Verilog2001::Verilog2001Parser::Parameter_identifierContext * ctx);
	static std::vector<Expr*> visitList_of_parameter_assignments(
			Verilog2001::Verilog2001Parser::List_of_parameter_assignmentsContext * ctx);
	static CompInstance * visitModule_instance(
			Verilog2001::Verilog2001Parser::Module_instanceContext * ctx,
			Expr * module_id, std::vector<Expr*> genericMap);
	static std::vector<Expr*> visitList_of_port_connections(
			Verilog2001::Verilog2001Parser::List_of_port_connectionsContext * ctx);
};
