#pragma once

#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include "antlr4-runtime.h"
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/symbol.h"
#include "../hdlObjects/expr.h"

using namespace antlr4;
using namespace vhdl;

class LiteralParser {

public:
	static Expr * visitLiteral(Ref<vhdlParser::LiteralContext> ctx);
	static Expr * visitNumeric_literal(
			Ref<vhdlParser::Numeric_literalContext> ctx);
	static Expr * visitPhysical_literal(Ref<vhdlParser::Physical_literalContext> ctx);
	static Expr * visitAbstract_literal(
			Ref<vhdlParser::Abstract_literalContext> ctx);
	static Expr * visitEnumeration_literal(
			Ref<vhdlParser::Enumeration_literalContext> ctx);
	static Expr * visitSTRING_LITERAL(Ref<tree::TerminalNode> n);
	static Expr * visitCHARACTER_LITERAL(Ref<tree::TerminalNode> ctx);
	static Expr * visitIdentifier(Ref<vhdlParser::IdentifierContext> ctx);
	static bool isStrDesignator(Ref<vhdlParser::DesignatorContext> ctx);
	static char * visitDesignator(Ref<vhdlParser::DesignatorContext> ctx);
};
