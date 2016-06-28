#pragma once

#include <vector>
#include "antlr4-runtime.h"
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/compInstance.h"
#include "literalParser.h"
#include "referenceParser.h"

using namespace antlr4;
using namespace vhdl;

class CompInstanceParser {
public:
	static CompInstance * visitComponent_instantiation_statement(
			Ref<vhdlParser::Component_instantiation_statementContext> ctx);
	static std::vector<Expr*> * visitPort_map_aspect(
			Ref<vhdlParser::Port_map_aspectContext> ctx);
	static char * visitLabel_colon(
			Ref<vhdlParser::Label_colonContext> ctx);
	static CompInstance * visitInstantiated_unit(
			Ref<vhdlParser::Instantiated_unitContext> ctx);
	static std::vector<Expr*> * visitGeneric_map_aspect(
			Ref<vhdlParser::Generic_map_aspectContext> ctx);
};
