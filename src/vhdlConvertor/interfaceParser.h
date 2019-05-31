#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/port.h"

namespace hdlConvertor {
namespace vhdl {

class InterfaceParser {
public:
	using Variable = hdlObjects::Variable;
	using Port = hdlObjects::Port;
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::vector<Variable*>* extractVariables(
			vhdlParser::Identifier_listContext * identifier_list,
			vhdlParser::Subtype_indicationContext * subType,
			vhdlParser::ExpressionContext * _expr);
	static std::vector<Port*>* visitInterface_port_declaration(
			vhdlParser::Interface_port_declarationContext* ctx);
	static std::vector<Variable*> *visitInterface_constant_declaration(
			vhdlParser::Interface_constant_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_signal_declaration(
			vhdlParser::Interface_signal_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_variable_declaration(
			vhdlParser::Interface_variable_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_file_declaration(
			vhdlParser::Interface_file_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_terminal_declaration(
			vhdlParser::Interface_terminal_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_quantity_declaration(
			vhdlParser::Interface_quantity_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_declaration(
			vhdlParser::Interface_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_list(
			vhdlParser::Interface_listContext* ctx);
	static std::vector<Variable*> * visitInterface_element(
			vhdlParser::Interface_elementContext* ctx);
};

}
}
