#pragma once

#include <antlr4-runtime.h>
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

	static hdlObjects::iHdlExpr * visitNumber(
			sv2017Parser::NumberContext * ctx);
	static hdlObjects::iHdlExpr * parseSimple_identifier(TerminalNode * n);
	static hdlObjects::iHdlExpr * parseEscaped_identifier(TerminalNode* n);
	static hdlObjects::iHdlExpr * parseIntNumber(TerminalNode * n, int radix);
	static hdlObjects::iHdlExpr * parseReal_number(TerminalNode * n);
	static hdlObjects::iHdlExpr * visitString(TerminalNode * n);
	static hdlObjects::HdlOperatorType visitUnary_operator(
			sv2017Parser::Unary_operatorContext * ctx);
	static hdlObjects::HdlOperatorType visitBinary_operator(
			sv2017Parser::Binary_operatorContext * ctx);
	static hdlObjects::iHdlExpr * visitDolar_identifier(TerminalNode* n);
};

}
}
