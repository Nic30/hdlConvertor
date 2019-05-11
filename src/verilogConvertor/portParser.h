#pragma once

#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/port.h"

class PortParser {
	antlr4::TokenStream * tokens;
public:
	PortParser(antlr4::TokenStream * tokens);

	std::vector<Port*>* addTypeSpecToPorts(Direction direction,
			Verilog2001::Verilog2001Parser::Net_typeContext * net_type,
			bool signed_, bool reg_, std::string doc,
			Verilog2001::Verilog2001Parser::Range_Context * range_,
			std::vector<Port*> * ports);
	std::vector<Port*>* visitList_of_ports(
			Verilog2001::Verilog2001Parser::List_of_portsContext* ctx);
	std::vector<Port*> * visitPort(
			Verilog2001::Verilog2001Parser::PortContext* ctx);
	std::vector<Port*> *visitPort_expression(
			Verilog2001::Verilog2001Parser::Port_expressionContext* ctx);
	Port * visitPort_reference(
			Verilog2001::Verilog2001Parser::Port_referenceContext* ctx);
	std::vector<Port*>* visitList_of_port_declarations(
			Verilog2001::Verilog2001Parser::List_of_port_declarationsContext* ctx);
	std::vector<Port*> * visitPort_declaration(
			Verilog2001::Verilog2001Parser::Port_declarationContext* ctx);
	std::vector<Port*> * visitList_of_port_identifiers(
			Verilog2001::Verilog2001Parser::List_of_port_identifiersContext* ctx);
	Port * visitPort_identifier(
			Verilog2001::Verilog2001Parser::Port_identifierContext * ctx);
	std::vector<Port*> *visitList_of_variable_port_identifiers(
			Verilog2001::Verilog2001Parser::List_of_variable_port_identifiersContext * ctx);
};
