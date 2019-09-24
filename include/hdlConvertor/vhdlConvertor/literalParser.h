#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlLiteralParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::iHdlExpr* visitNumeric_literal(
			vhdlParser::Numeric_literalContext *ctx);
	static hdlObjects::iHdlExpr* visitPhysical_literal(
			vhdlParser::Physical_literalContext *ctx);
	static hdlObjects::iHdlExpr* visitEnumeration_literal(
			vhdlParser::Enumeration_literalContext *ctx);
	static hdlObjects::iHdlExpr* visitSTRING_LITERAL(const std::string &ctx);
	static hdlObjects::iHdlExpr* visitCHARACTER_LITERAL(const std::string &ctx);
	static hdlObjects::iHdlExpr* visitBIT_STRING_LITERAL(const std::string &s);
	static hdlObjects::iHdlExpr* visitDECIMAL_LITERAL(antlr4::tree::TerminalNode* ctx);
	static hdlObjects::iHdlExpr* visitBASED_LITERAL(antlr4::tree::TerminalNode* ctx);
	static hdlObjects::iHdlExpr* visitIdentifier(
			vhdlParser::IdentifierContext *ctx);
	static bool isStrDesignator(vhdlParser::DesignatorContext *ctx);
	static std::string visitDesignator(vhdlParser::DesignatorContext *ctx);
	static std::string visitLabel(vhdlParser::LabelContext *ctx);
};

}
}
