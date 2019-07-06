#include <hdlConvertor/verilogConvertor/literalParser.h>
#include <algorithm>
#include <hdlConvertor/notImplementedLogger.h>

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
	NotImplementedLogger::print("ExpressionParser.visitNumber - Real_number", ctx);
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
	if (size != -1)
		return Expr::INT(strVal, size, radix);
	if (radix == 10) {
		auto v = atoi(strVal.c_str());
		return Expr::INT(v);
	}
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

OperatorType VerLiteralParser::visitUnary_operator(
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
		return ADD;
	} else if (op == "-") {
		return SUB;
	} else if (op == "!") {
		return NOT;
	} else if (op == "~") {
		return NEG;
	} else if (op == "&") {
		return AND;
	} else if (op == "~&") {
		return NAND;
	} else if (op == "|") {
		return OR;
	} else if (op == "~|") {
		return NOR;
	} else if (op == "^") {
		return XOR;
	} else if (op == "~^") {
		return XNOR;
	} else if (op == "^~") {
		return XNOR;
	}

	throw std::runtime_error("Unsupported unary operator " + op);
}
OperatorType VerLiteralParser::visitBinary_operator(
		Verilog2001Parser::Binary_operatorContext * ctx) {
	// binary_operator : '+' | '-' | '*' | '/' | '%' | '==' | '!=' | '===' |
	// '!==' | '&&' | '||' | '**' | '<' | '<=' | '>' | '>=' | '&' | '|' |
	// '^' | '^~' | '~^' | '>>' | '<<' | '>>>' | '<<<' ;
	// [TODO] log eq, neq
	std::string op = ctx->getText();

	if (op.compare("+") == 0)
		return ADD;
	else if (op.compare("-") == 0)
		return SUB;
	else if (op.compare("*") == 0)
		return MUL;
	else if (op.compare("/") == 0)
		return DIV;
	else if (op.compare("%") == 0)
		return MOD;
	else if (op.compare("==") == 0 || op.compare("===") == 0)
		return EQ;
	else if (op.compare("!=") == 0 || op.compare("!==") == 0)
		return NEQ;
	else if (op.compare("&&") == 0)
		return LOG_AND;
	else if (op.compare("||") == 0)
		return LOG_OR;
	else if (op.compare("**") == 0)
		return POW;
	else if (op.compare("<") == 0)
		return LT;
	else if (op.compare("<=") == 0)
		return LE;
	else if (op.compare(">") == 0)
		return GT;
	else if (op.compare(">=") == 0)
		return GE;
	else if (op.compare("&") == 0)
		return AND;
	else if (op.compare("|") == 0)
		return OR;
	else if (op.compare("^") == 0)
		return XOR;
	else if (op.compare("^~") == 0 || op.compare("~^") == 0
			|| op.compare(">>") == 0)
		return SRL;
	else if (op.compare("<<") == 0)
		return SLL;
	else if (op.compare(">>>") == 0)
		return SRA;

	assert(op.compare("<<<") == 0);
	return SLA;

}

Expr * VerLiteralParser::visitDolar_identifier(TerminalNode* n) {
	return Expr::ID(n->getText());
}

}
}
