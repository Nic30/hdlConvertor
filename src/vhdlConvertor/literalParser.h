#pragma once

#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"

namespace hdlConvertor {
namespace vhdl {

class LiteralParser {
public:
	using Expr = hdlObjects::Expr;
	using vhdlParser = vhdl_antlr::vhdlParser;

	static Expr * visitLiteral(vhdlParser::LiteralContext* ctx);
	static Expr * visitNumeric_literal(vhdlParser::Numeric_literalContext* ctx);
	static Expr * visitPhysical_literal(
			vhdlParser::Physical_literalContext* ctx);
	static Expr * visitAbstract_literal(
			vhdlParser::Abstract_literalContext* ctx);
	static Expr * visitEnumeration_literal(
			vhdlParser::Enumeration_literalContext* ctx);
	static Expr * visitString_literal(vhdlParser::String_literalContext * ctx);
	static Expr * visitCharacter_literal(vhdlParser::Character_literalContext* ctx);
	static Expr * visitIdentifier(vhdlParser::IdentifierContext* ctx);
	static bool isStrDesignator(vhdlParser::DesignatorContext* ctx);
	static char * visitDesignator(vhdlParser::DesignatorContext* ctx);
	static char * visitLabel(vhdlParser::LabelContext * ctx);
};

}
}
