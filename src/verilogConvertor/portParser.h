#pragma once

#include <vector>

#include "Verilog2001Parser/Verilog2001Parser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/port.h"
#include "commentParser.h"

namespace hdlConvertor {
namespace verilog {

class PortParser {
	CommentParser & commentParser;
public:
	using Port = hdlObjects::Port;
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;

	PortParser(CommentParser & commentParser);

	std::vector<Port*>* addTypeSpecToPorts(hdlObjects::Direction direction,
			Verilog2001Parser::Net_typeContext * net_type, bool signed_,
			bool reg_, std::string doc,
			Verilog2001Parser::Range_Context * range_, std::vector<Port*> * ports);
	std::vector<Port*>* visitList_of_ports(
			Verilog2001Parser::List_of_portsContext* ctx);
	std::vector<Port*> * visitPort(Verilog2001Parser::PortContext* ctx);
	std::vector<Port*> *visitPort_expression(
			Verilog2001Parser::Port_expressionContext* ctx);
	Port * visitPort_reference(Verilog2001Parser::Port_referenceContext* ctx);
	std::vector<Port*>* visitList_of_port_declarations(
			Verilog2001Parser::List_of_port_declarationsContext* ctx);
	std::vector<Port*> * visitPort_declaration(
			Verilog2001Parser::Port_declarationContext* ctx);
	std::vector<Port*> * visitList_of_port_identifiers(
			Verilog2001Parser::List_of_port_identifiersContext* ctx);
	Port * visitPort_identifier(
			Verilog2001Parser::Port_identifierContext * ctx);
	std::vector<Port*> *visitList_of_variable_port_identifiers(
			Verilog2001Parser::List_of_variable_port_identifiersContext * ctx);
};

}
}
