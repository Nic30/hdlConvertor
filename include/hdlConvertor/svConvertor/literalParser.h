#pragma once

#include <vector>
#include <string>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace sv {

class VerLiteralParser {
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	using TerminalNode = antlr4::tree::TerminalNode;

	static hdlObjects::iHdlExpr* visitNumber(sv2017Parser::NumberContext *ctx);
	static hdlObjects::iHdlExpr* parseSIMPLE_IDENTIFIER(TerminalNode *n);
	static hdlObjects::iHdlExpr* parseC_IDENTIFIER(TerminalNode *n);
	static hdlObjects::iHdlExpr* parseEscaped_identifier(TerminalNode *n);
	static hdlObjects::iHdlExpr* parseIntNumber(TerminalNode *n, int radix);
	static hdlObjects::iHdlExpr* parseReal_number(TerminalNode *n);
	static hdlObjects::iHdlExpr* visitString(TerminalNode *n);
	static hdlObjects::HdlOperatorType visitUnary_operator(
			sv2017Parser::Unary_operatorContext *ctx);
	static hdlObjects::iHdlExpr* visitDolar_identifier(TerminalNode *n);
};

}
}
