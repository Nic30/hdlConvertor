#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace antlr4
{
  class ParserRuleContext;
  namespace tree
  {
    class TerminalNode;
  }
}

namespace hdlConvertor {
namespace vhdl {

class VhdlLiteralParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
  using TerminalNode = antlr4::tree::TerminalNode;
  using ParserRuleContext = antlr4::ParserRuleContext;

	static std::unique_ptr<hdlObjects::iHdlExpr> visitNumeric_literal(
			vhdlParser::Numeric_literalContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitPhysical_literal(
			vhdlParser::Physical_literalContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitEnumeration_literal(
			vhdlParser::Enumeration_literalContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitSTRING_LITERAL(
			TerminalNode *n, const std::string &ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitCHARACTER_LITERAL(
			TerminalNode *n, const std::string &ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitBIT_STRING_LITERAL(
			TerminalNode *ctx, const std::string &s);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitDECIMAL_LITERAL(
			TerminalNode *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitBASED_LITERAL(
			TerminalNode *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitIdentifier(
			vhdlParser::IdentifierContext *ctx);
	static std::string getIdentifierStr(vhdlParser::IdentifierContext *ctx);
	static bool isStrDesignator(vhdlParser::DesignatorContext *ctx);
	static std::string visitDesignator(vhdlParser::DesignatorContext *ctx);
	static std::string visitLabel(vhdlParser::LabelContext *ctx);
};

}
}
