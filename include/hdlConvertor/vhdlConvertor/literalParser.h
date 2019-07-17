#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace vhdl {

class LiteralParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::iHdlExpr * visitLiteral(vhdlParser::LiteralContext* ctx);
	static hdlObjects::iHdlExpr * visitNumeric_literal(
			vhdlParser::Numeric_literalContext* ctx);
	static hdlObjects::iHdlExpr * visitPhysical_literal(
			vhdlParser::Physical_literalContext* ctx);
	static hdlObjects::iHdlExpr * visitAbstract_literal(
			vhdlParser::Abstract_literalContext* ctx);
	static hdlObjects::iHdlExpr * visitEnumeration_literal(
			vhdlParser::Enumeration_literalContext* ctx);
	static hdlObjects::iHdlExpr * visitString_literal(const std::string & ctx);
	static hdlObjects::iHdlExpr * visitCharacter_literal(
			const std::string & ctx);
	static hdlObjects::iHdlExpr * visitIdentifier(
			vhdlParser::IdentifierContext* ctx);
	static bool isStrDesignator(vhdlParser::DesignatorContext* ctx);
	static std::string visitDesignator(vhdlParser::DesignatorContext* ctx);
	static std::string visitLabel(vhdlParser::LabelContext * ctx);
};

}
}
