#pragma once

#include <vector>
#include <stdlib.h>
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/port.h"
#include "../hdlObjects/direction.h"

#include "exprParser.h"
#include "directionParser.h"

class InterfaceParser {
public:
	static std::vector<Variable*>* extractVariables(
			Ref<vhdlParser::Identifier_listContext> identifier_list,
			Ref<vhdlParser::Subtype_indicationContext> subType,
			Ref<vhdlParser::ExpressionContext> _expr);
	static std::vector<Port*>* visitInterface_port_declaration(
			Ref<vhdlParser::Interface_port_declarationContext> ctx);
	static std::vector<Variable*> *visitInterface_constant_declaration(
			Ref<vhdlParser::Interface_constant_declarationContext> ctx);
	static std::vector<Variable*> * visitInterface_signal_declaration(
			Ref<vhdlParser::Interface_signal_declarationContext> ctx);
	static std::vector<Variable*> * visitInterface_variable_declaration(
			Ref<vhdlParser::Interface_variable_declarationContext> ctx);
	static std::vector<Variable*> * visitInterface_file_declaration(
			Ref<vhdlParser::Interface_file_declarationContext> ctx);
	static std::vector<Variable*> * visitInterface_terminal_declaration(
			Ref<vhdlParser::Interface_terminal_declarationContext> ctx);
	static std::vector<Variable*> * visitInterface_quantity_declaration(
			Ref<vhdlParser::Interface_quantity_declarationContext> ctx);
	static std::vector<Variable*> * visitInterface_declaration(
			Ref<vhdlParser::Interface_declarationContext> ctx);
	static std::vector<Variable*> * visitInterface_list(
			Ref<vhdlParser::Interface_listContext> ctx);
	static std::vector<Variable*> * visitInterface_element(
			Ref<vhdlParser::Interface_elementContext> ctx);
};
