#pragma once

#include <vector>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

#include <hdlConvertor/svConvertor/commentParser.h>

namespace hdlConvertor {
namespace sv {

class VerPortParser {
	SVCommentParser &commentParser;
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	using Non_ANSI_port_info_t = std::pair<std::string, std::vector<hdlObjects::HdlVariableDef*>>;
	std::vector<Non_ANSI_port_info_t> &non_ansi_port_groups;

	VerPortParser(SVCommentParser &commentParser,
			std::vector<Non_ANSI_port_info_t> &non_ansi_port_groups);

	std::vector<hdlObjects::HdlVariableDef*>* addTypeSpecToPorts(
			hdlObjects::HdlDirection direction,
			sv2017Parser::Net_typeContext *net_type, bool signed_, bool reg_,
			const std::string &doc, sv2017Parser::Range_Context *range_,
			std::vector<hdlObjects::HdlVariableDef*> *ports);
	std::vector<hdlObjects::HdlVariableDef*>* visitNonansi_port(
			sv2017Parser::Nonansi_portContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitNonansi_port__expr(
			sv2017Parser::Nonansi_port__exprContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitList_of_port_declarations(
			sv2017Parser::List_of_port_declarationsContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitNonansi_port_declaration(
			sv2017Parser::Nonansi_port_declarationContext *ctx);
	std::vector<hdlObjects::HdlVariableDef*>* visitList_of_variable_port_identifiers(
			sv2017Parser::List_of_variable_port_identifiersContext *ctx);

	// wrap children on non_ansi ports to new ANSI port with name of parent port
	// module x (.a(b, c)); input b, c; endmodule -> module x (input [2:0] a); wire b, c; assign {b, c} = a; endmodule
	void convert_non_ansi_ports_to_ansi(
			std::vector<hdlObjects::HdlVariableDef*> &ports,
			std::vector<hdlObjects::iHdlObj*> &body);
};

}
}
