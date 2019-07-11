#pragma once

#include <vector>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/verilogConvertor/commentParser.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace verilog {

class PortParser {
	CommentParser & commentParser;
public:
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;

	PortParser(CommentParser & commentParser);

	std::vector<hdlObjects::HdlVariableDef*>* addTypeSpecToPorts(
			hdlObjects::HdlDirection direction,
			Verilog2001Parser::Net_typeContext * net_type, bool signed_,
			bool reg_, const std::string & doc,
			Verilog2001Parser::Range_Context * range_,
			std::vector<hdlObjects::HdlVariableDef*> * ports);
	std::vector<hdlObjects::HdlVariableDef*>* visitList_of_ports(
			Verilog2001Parser::List_of_portsContext* ctx);
	std::vector<hdlObjects::HdlVariableDef*> * visitPort(
			Verilog2001Parser::PortContext* ctx);
	std::vector<hdlObjects::HdlVariableDef*> *visitPort_expression(
			Verilog2001Parser::Port_expressionContext* ctx);
	hdlObjects::HdlVariableDef * visitPort_reference(
			Verilog2001Parser::Port_referenceContext* ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitList_of_port_declarations(
			Verilog2001Parser::List_of_port_declarationsContext* ctx);
	std::vector<hdlObjects::HdlVariableDef*> * visitPort_declaration(
			Verilog2001Parser::Port_declarationContext* ctx);
	std::vector<hdlObjects::HdlVariableDef*> * visitList_of_port_identifiers(
			Verilog2001Parser::List_of_port_identifiersContext* ctx);
	hdlObjects::HdlVariableDef * visitPort_identifier(
			Verilog2001Parser::Port_identifierContext * ctx);
	std::vector<hdlObjects::HdlVariableDef*> *visitList_of_variable_port_identifiers(
			Verilog2001Parser::List_of_variable_port_identifiersContext * ctx);
};

}
}
