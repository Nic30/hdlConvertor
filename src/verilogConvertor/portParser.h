#pragma once

#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/port.h"

class PortParser {
public:
	static std::vector<Port*>* addTypeSpecToPorts(Direction direction,
			Verilog2001::Verilog2001Parser::Net_typeContext * net_type,
			bool signed_, bool reg_,
			Verilog2001::Verilog2001Parser::Range_Context * range_,
			std::vector<Port*> * ports);
	static std::vector<Port*>* visitList_of_ports(
			Verilog2001::Verilog2001Parser::List_of_portsContext* ctx);
	static std::vector<Port*> * visitPort(
			Verilog2001::Verilog2001Parser::PortContext* ctx);
	static std::vector<Port*> *visitPort_expression(
			Verilog2001::Verilog2001Parser::Port_expressionContext* ctx);
	static Port * visitPort_reference(
			Verilog2001::Verilog2001Parser::Port_referenceContext* ctx);
	static std::vector<Port*>* visitList_of_port_declarations(
			Verilog2001::Verilog2001Parser::List_of_port_declarationsContext* ctx);
	static std::vector<Port*> * visitPort_declaration(
			Verilog2001::Verilog2001Parser::Port_declarationContext* ctx);
	static std::vector<Port*> * visitList_of_port_identifiers(
			Verilog2001::Verilog2001Parser::List_of_port_identifiersContext* ctx);
	static Port * visitPort_identifier(
			Verilog2001::Verilog2001Parser::Port_identifierContext * ctx);
	static std::vector<Port*> *visitList_of_variable_port_identifiers(
			Verilog2001::Verilog2001Parser::List_of_variable_port_identifiersContext * ctx);
};
