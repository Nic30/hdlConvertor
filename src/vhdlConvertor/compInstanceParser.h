#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/compInstance.h"

class CompInstanceParser {
public:
	static CompInstance * visitComponent_instantiation_statement(
			vhdl::vhdlParser::Component_instantiation_statementContext* ctx);
	static std::vector<Expr*> * visitPort_map_aspect(
			vhdl::vhdlParser::Port_map_aspectContext* ctx);
	static char * visitLabel_colon(
			vhdl::vhdlParser::Label_colonContext* ctx);
	static CompInstance * visitInstantiated_unit(
			vhdl::vhdlParser::Instantiated_unitContext* ctx);
	static std::vector<Expr*> * visitGeneric_map_aspect(
			vhdl::vhdlParser::Generic_map_aspectContext* ctx);
};
