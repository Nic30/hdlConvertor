#pragma once

#include <antlr4-runtime.h>
#include <vector>
#include <string>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace verilog {

class VerLiteralParser {
public:
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
	using TerminalNode = antlr4::tree::TerminalNode;

	static hdlObjects::iHdlExpr * visitNumber(
			Verilog2001Parser::NumberContext * ctx);
	static hdlObjects::iHdlExpr * parseSimple_identifier(TerminalNode * n);
	static hdlObjects::iHdlExpr * parseEscaped_identifier(TerminalNode* n);
	static hdlObjects::iHdlExpr * parseIntNumber(TerminalNode * n, int radix);
	static hdlObjects::iHdlExpr * visitString(TerminalNode * n);
	static hdlObjects::HdlOperatorType visitUnary_operator(
			Verilog2001Parser::Unary_operatorContext * ctx);
	static hdlObjects::HdlOperatorType visitBinary_operator(
			Verilog2001Parser::Binary_operatorContext * ctx);
	static hdlObjects::iHdlExpr * visitDolar_identifier(TerminalNode* n);
};

}
}
