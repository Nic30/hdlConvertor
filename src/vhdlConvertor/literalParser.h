#pragma once

#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"

class LiteralParser {
public:
	static Expr * visitLiteral(vhdl::vhdlParser::LiteralContext* ctx);
	static Expr * visitNumeric_literal(
			vhdl::vhdlParser::Numeric_literalContext* ctx);
	static Expr * visitPhysical_literal(vhdl::vhdlParser::Physical_literalContext* ctx);
	static Expr * visitAbstract_literal(
			vhdl::vhdlParser::Abstract_literalContext* ctx);
	static Expr * visitEnumeration_literal(
			vhdl::vhdlParser::Enumeration_literalContext* ctx);
	static Expr * visitSTRING_LITERAL(antlr4::tree::TerminalNode* n);
	static Expr * visitCHARACTER_LITERAL(antlr4::tree::TerminalNode* ctx);
	static Expr * visitIdentifier(vhdl::vhdlParser::IdentifierContext* ctx);
	static bool isStrDesignator(vhdl::vhdlParser::DesignatorContext* ctx);
	static char * visitDesignator(vhdl::vhdlParser::DesignatorContext* ctx);
};
