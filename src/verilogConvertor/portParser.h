#pragma once

#include <antlr4-runtime.h>
#include <vector>
#include <memory>

#include "../VerilogParser/Verilog2001Parser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/port.h"
#include "../hdlObjects/direction.h"
#include "../notImplementedLogger.h"
#include "utils.h"
#include "exprParser.h"

using namespace antlr4;
using namespace verilog;

class PortParser {
public:
	static std::vector<Port*>* addTypeSpecToPorts(Direction direction,
			Verilog2001Parser::Net_typeContext * net_type, bool _signed,
			Verilog2001Parser::RangeContext * range,
			std::vector<Port*> * ports);
	static std::vector<Port*>* visitList_of_ports(
			Verilog2001Parser::List_of_portsContext* ctx);
	static std::vector<Port*> * visitPort(
			Verilog2001Parser::PortContext* ctx);
	static std::vector<Port*> *visitPort_expression(
			Verilog2001Parser::Port_expressionContext* ctx);
	static Port * visitPort_reference(
			Verilog2001Parser::Port_referenceContext* ctx);
	static std::vector<Port*>* visitList_of_port_declarations(
			Verilog2001Parser::List_of_port_declarationsContext* ctx);
	static std::vector<Port*> * visitPort_declaration(
			Verilog2001Parser::Port_declarationContext* ctx);
	static std::vector<Port*> * visitList_of_port_identifiers(
			Verilog2001Parser::List_of_port_identifiersContext* ctx);
	static Port * visitPort_identifier(
			Verilog2001Parser::Port_identifierContext * ctx);
	static std::vector<Port*> *visitList_of_variable_port_identifiers(
			Verilog2001Parser::List_of_variable_port_identifiersContext * ctx);
};
