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
	static Expr * visitLiteral(vhdlParser::LiteralContext* ctx);
	static Expr * visitNumeric_literal(
			vhdlParser::Numeric_literalContext* ctx);
	static Expr * visitPhysical_literal(vhdlParser::Physical_literalContext* ctx);
	static Expr * visitAbstract_literal(
			vhdlParser::Abstract_literalContext* ctx);
	static Expr * visitEnumeration_literal(
			vhdlParser::Enumeration_literalContext* ctx);
	static Expr * visitSTRING_LITERAL(tree::TerminalNode* n);
	static Expr * visitCHARACTER_LITERAL(tree::TerminalNode* ctx);
	static Expr * visitIdentifier(vhdlParser::IdentifierContext* ctx);
	static bool isStrDesignator(vhdlParser::DesignatorContext* ctx);
	static char * visitDesignator(vhdlParser::DesignatorContext* ctx);
};
