#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/port.h"
#include "../hdlObjects/direction.h"

class InterfaceParser {
public:
	static std::vector<Variable*>* extractVariables(
			vhdl::vhdlParser::Identifier_listContext * identifier_list,
			vhdl::vhdlParser::Subtype_indicationContext * subType,
			vhdl::vhdlParser::ExpressionContext * _expr);
	static std::vector<Port*>* visitInterface_port_declaration(
			vhdl::vhdlParser::Interface_port_declarationContext* ctx);
	static std::vector<Variable*> *visitInterface_constant_declaration(
			vhdl::vhdlParser::Interface_constant_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_signal_declaration(
			vhdl::vhdlParser::Interface_signal_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_variable_declaration(
			vhdl::vhdlParser::Interface_variable_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_file_declaration(
			vhdl::vhdlParser::Interface_file_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_terminal_declaration(
			vhdl::vhdlParser::Interface_terminal_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_quantity_declaration(
			vhdl::vhdlParser::Interface_quantity_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_declaration(
			vhdl::vhdlParser::Interface_declarationContext* ctx);
	static std::vector<Variable*> * visitInterface_list(
			vhdl::vhdlParser::Interface_listContext* ctx);
	static std::vector<Variable*> * visitInterface_element(
			vhdl::vhdlParser::Interface_elementContext* ctx);
};
