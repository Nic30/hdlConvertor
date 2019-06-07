#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/expr.h>

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
	static Expr * visitString_literal(const std::string & ctx);
	static Expr * visitCharacter_literal(const std::string & ctx);
	static Expr * visitIdentifier(vhdlParser::IdentifierContext* ctx);
	static bool isStrDesignator(vhdlParser::DesignatorContext* ctx);
	static char * visitDesignator(vhdlParser::DesignatorContext* ctx);
	static std::string visitLabel(vhdlParser::LabelContext * ctx);
};

}
}
