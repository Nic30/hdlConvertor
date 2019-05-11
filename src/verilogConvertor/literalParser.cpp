#include "literalParser.h"
#include "../notImplementedLogger.h"

using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace verilog {

Expr * VerLiteralParser::visitNumber(Verilog2001Parser::NumberContext* ctx) {
	// number :
	// Decimal_number
	// | Octal_number
	// | Binary_number
	// | Hex_number
	// | Real_number
	// ;
	auto n = ctx->Decimal_number();
	if (n) {
		return parseIntNumber(n, 10);
	}
	n = ctx->Octal_number();
	if (n) {
		return parseIntNumber(n, 8);
	}
	n = ctx->Binary_number();
	if (n) {
		return parseIntNumber(n, 2);
	}
	n = ctx->Hex_number();
	if (n) {
		return parseIntNumber(n, 16);
	}
	NotImplementedLogger::print("ExpressionParser.visitNumber - Real_number");
	return NULL;

}
Expr * VerLiteralParser::parseSimple_identifier(antlr4::tree::TerminalNode* n) {
	return Expr::ID(n->getText());
}
Expr * VerLiteralParser::parseEscaped_identifier(
		antlr4::tree::TerminalNode* n) {
	auto s = n->getText();
	s = s.substr(1);
	return Expr::ID(s);
}

Expr * VerLiteralParser::parseIntNumber(antlr4::tree::TerminalNode* n,
		int radix) {
	// Decimal_number :
	// Unsigned_number
	// | ( Size )? Decimal_base Unsigned_number
	// | ( Size )? Decimal_base X_digit ( '_' )*
	// | ( Size )? Decimal_base Z_digit ( '_' )*
	// ;

	// Unsigned_number : Decimal_digit ( '_' | Decimal_digit )* ;
	std::string s = n->getText();
	s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	int size = -1;
	int valuePartStart = 0;

	size_t baseStart = s.find('\'', 0);
	if (baseStart != std::string::npos) {
		if (baseStart > 0) {
			s[baseStart] = 0;
			size = atoi(s.c_str());
		}
		valuePartStart = baseStart + 2;
		if (s[baseStart + 1] == 's')
			valuePartStart += 1;
	}

	std::string strVal = s.substr(valuePartStart, s.length()); // cut off prefix
	for (int i = 0; strVal[i]; i++) {
		char ch = strVal[i];
		if (ch == 'x' || ch == 'z') {
			strVal[i] = '0';
		}
	}

	if (size != -1)
		return Expr::INT(strVal, size, radix);

	return Expr::INT(strVal, radix);
}

// Real_number :
// Unsigned_number '.' Unsigned_number
// | Unsigned_number ( '.' Unsigned_number )? [eE] ( [+-] )? Unsigned_number
// ;
//
//
// Binary_number : ( Size )? Binary_base Binary_value ;
// Octal_number : ( Size )? Octal_base Octal_value ;
// Hex_number : ( Size )? Hex_base Hex_value ;
Expr * VerLiteralParser::visitString(antlr4::tree::TerminalNode* n) {
	std::string s = n->getText();
	return Expr::STR(s.substr(1, s.length() - 2)); // skipping " at the end
}

}
}
