#include <hdlConvertor/verilogConvertor/literalParser.h>
#include <algorithm>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace verilog {

using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;
using TerminalNode = antlr4::tree::TerminalNode;

iHdlExpr * VerLiteralParser::visitNumber(
		Verilog2001Parser::NumberContext* ctx) {
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
	NotImplementedLogger::print("ExpressionParser.visitNumber - Real_number",
			ctx);
	return NULL;

}
iHdlExpr * VerLiteralParser::parseSimple_identifier(TerminalNode* n) {
	return iHdlExpr::ID(n->getText());
}
iHdlExpr * VerLiteralParser::parseEscaped_identifier(TerminalNode* n) {
	auto s = n->getText();
	s = s.substr(1);
	return iHdlExpr::ID(s);
}

iHdlExpr * VerLiteralParser::parseIntNumber(TerminalNode* n, int radix) {
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
	if (size != -1)
		return iHdlExpr::INT(strVal, size, radix);
	if (radix == 10) {
		auto v = atoi(strVal.c_str());
		return iHdlExpr::INT(v);
	}
	return iHdlExpr::INT(strVal, radix);
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
iHdlExpr * VerLiteralParser::visitString(TerminalNode* n) {
	std::string s = n->getText();
	return iHdlExpr::STR(s.substr(1, s.length() - 2)); // skipping " at the end
}

HdlOperatorType VerLiteralParser::visitUnary_operator(
		Verilog2001Parser::Unary_operatorContext * ctx) {
	// unary_operator
	//    : '+'
	//    | '-'
	//    | '!'
	//    | '~'
	//    | '&'
	//    | '~&'
	//    | '|'
	//    | '~|'
	//    | '^'
	//    | '~^'
	//    | '^~'
	//    ;
	std::string op = ctx->getText();

	if (op == "+") {
		return HdlOperatorType::ADD;
	} else if (op == "-") {
		return HdlOperatorType::SUB;
	} else if (op == "!") {
		return HdlOperatorType::NOT;
	} else if (op == "~") {
		return HdlOperatorType::NEG;
	} else if (op == "&") {
		return HdlOperatorType::AND;
	} else if (op == "~&") {
		return HdlOperatorType::NAND;
	} else if (op == "|") {
		return HdlOperatorType::OR;
	} else if (op == "~|") {
		return HdlOperatorType::NOR;
	} else if (op == "^") {
		return HdlOperatorType::XOR;
	} else if (op == "~^") {
		return HdlOperatorType::XNOR;
	} else if (op == "^~") {
		return HdlOperatorType::XNOR;
	}

	throw std::runtime_error("Unsupported unary operator " + op);
}
HdlOperatorType VerLiteralParser::visitBinary_operator(
		Verilog2001Parser::Binary_operatorContext * ctx) {
	// binary_operator : '+' | '-' | '*' | '/' | '%' | '==' | '!=' | '===' |
	// '!==' | '&&' | '||' | '**' | '<' | '<=' | '>' | '>=' | '&' | '|' |
	// '^' | '^~' | '~^' | '>>' | '<<' | '>>>' | '<<<' ;
	// [TODO] log eq, neq
	std::string op = ctx->getText();

	if (op.compare("+") == 0)
		return HdlOperatorType::ADD;
	else if (op.compare("-") == 0)
		return HdlOperatorType::SUB;
	else if (op.compare("*") == 0)
		return HdlOperatorType::MUL;
	else if (op.compare("/") == 0)
		return HdlOperatorType::DIV;
	else if (op.compare("%") == 0)
		return HdlOperatorType::MOD;
	else if (op.compare("==") == 0 || op.compare("===") == 0)
		return HdlOperatorType::EQ;
	else if (op.compare("!=") == 0 || op.compare("!==") == 0)
		return HdlOperatorType::NEQ;
	else if (op.compare("&&") == 0)
		return HdlOperatorType::LOG_AND;
	else if (op.compare("||") == 0)
		return HdlOperatorType::LOG_OR;
	else if (op.compare("**") == 0)
		return HdlOperatorType::POW;
	else if (op.compare("<") == 0)
		return HdlOperatorType::LT;
	else if (op.compare("<=") == 0)
		return HdlOperatorType::LE;
	else if (op.compare(">") == 0)
		return HdlOperatorType::GT;
	else if (op.compare(">=") == 0)
		return HdlOperatorType::GE;
	else if (op.compare("&") == 0)
		return HdlOperatorType::AND;
	else if (op.compare("|") == 0)
		return HdlOperatorType::OR;
	else if (op.compare("^") == 0)
		return HdlOperatorType::XOR;
	else if (op.compare("^~") == 0 || op.compare("~^") == 0
			|| op.compare(">>") == 0)
		return HdlOperatorType::SRL;
	else if (op.compare("<<") == 0)
		return HdlOperatorType::SLL;
	else if (op.compare(">>>") == 0)
		return HdlOperatorType::SRA;

	assert(op.compare("<<<") == 0);
	return HdlOperatorType::SLA;

}

iHdlExpr * VerLiteralParser::visitDolar_identifier(TerminalNode* n) {
	return iHdlExpr::ID(n->getText());
}

}
}
