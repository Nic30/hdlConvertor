#pragma once

#include <vector>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

#include <hdlConvertor/verilogConvertor/commentParser.h>

namespace hdlConvertor {
namespace verilog {

class PortParser {
	CommentParser &commentParser;
public:
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
	using Non_ANSI_port_info_t = std::pair<std::string, std::vector<hdlObjects::HdlVariableDef*>>;
	std::vector<Non_ANSI_port_info_t> &non_ansi_port_groups;

	PortParser(CommentParser &commentParser,
			std::vector<Non_ANSI_port_info_t> &non_ansi_port_groups);

	std::vector<hdlObjects::HdlVariableDef*>* addTypeSpecToPorts(
			hdlObjects::HdlDirection direction,
			Verilog2001Parser::Net_typeContext *net_type, bool signed_,
			bool reg_, const std::string &doc,
			Verilog2001Parser::Range_Context *range_,
			std::vector<hdlObjects::HdlVariableDef*> *ports);
	std::vector<hdlObjects::HdlVariableDef*>* visitList_of_ports(
			Verilog2001Parser::List_of_portsContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitPort(
			Verilog2001Parser::PortContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitPort_expression(
			Verilog2001Parser::Port_expressionContext *ctx);
	hdlObjects::HdlVariableDef* visitPort_reference(
			Verilog2001Parser::Port_referenceContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitList_of_port_declarations(
			Verilog2001Parser::List_of_port_declarationsContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitPort_declaration(
			Verilog2001Parser::Port_declarationContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitList_of_port_identifiers(
			Verilog2001Parser::List_of_port_identifiersContext *ctx);
	hdlObjects::HdlVariableDef* visitPort_identifier(
			Verilog2001Parser::Port_identifierContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitList_of_variable_port_identifiers(
			Verilog2001Parser::List_of_variable_port_identifiersContext *ctx);

	// wrap children on non_ansi ports to new ANSI port with name of parent port
	// module x (.a(b, c)); input b, c; endmodule -> module x (input [2:0] a); wire b, c; assign {b, c} = a; endmodule
	void convert_non_ansi_ports_to_ansi(
			std::vector<hdlObjects::HdlVariableDef*> &ports,
			std::vector<hdlObjects::iHdlObj*> &body);
};

}
}
