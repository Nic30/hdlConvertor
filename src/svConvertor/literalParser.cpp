#include <hdlConvertor/svConvertor/literalParser.h>

#include <algorithm>
#include <assert.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace sv {

using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;
using TerminalNode = antlr4::tree::TerminalNode;

iHdlExpr* VerLiteralParser::visitIntegral_number(
		sv2017Parser::Integral_numberContext *ctx) {
	// integral_number:
	//    BASED_NUMBER_WITH_SIZE
	//    | ( UNSIGNED_NUMBER )? ANY_BASED_NUMBER
	//    | UNSIGNED_NUMBER
	// ;
	auto bnws = ctx->BASED_NUMBER_WITH_SIZE();
	if (bnws) {
		// BASED_NUMBER_WITH_SIZE:
		//     UNSIGNED_NUMBER ANY_BASED_NUMBER;
		auto t = bnws->getText();
		auto f = t.find("'");
		assert(f != std::string::npos);
		size_t size = parseSize_UNSIGNED_NUMBER(t.substr(0, f));
		auto _v = t.substr(f);
		return visitANY_BASED_NUMBER(_v, size);
	}
	auto abn = ctx->ANY_BASED_NUMBER();
	if (abn) {
		size_t size = -1;
		auto un = ctx->UNSIGNED_NUMBER();
		if (un) {
			size = parseSize_UNSIGNED_NUMBER(un->getText());
		}
		return visitANY_BASED_NUMBER(abn->getText(), size);
	}
	auto un = ctx->UNSIGNED_NUMBER();
	return visitUNSIGNED_NUMBER(un);
}
size_t VerLiteralParser::parseSize_UNSIGNED_NUMBER(std::string str) {
	str.erase(std::remove(str.begin(), str.end(), '_'), str.end());
	return atoi(str.c_str());
}
iHdlExpr* VerLiteralParser::visitUNSIGNED_NUMBER(TerminalNode *ctx) {
	std::string str = ctx->getText();
	str.erase(std::remove(str.begin(), str.end(), '_'), str.end());
	return iHdlExpr::INT(str, 10);
}
iHdlExpr* VerLiteralParser::visitANY_BASED_NUMBER(std::string s, size_t size) {
	s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);

	assert(s[0] == '\'');
	int valuePartStart = 2;
	if (s[1] == 's')
		valuePartStart += 1;
	int radix;
	switch (s[valuePartStart - 1]) {
	case 'b':
	case 'B':
		radix = 2;
		break;
	case 'o':
	case 'O':
		radix = 8;
		break;
	case 'd':
	case 'D':
		radix = 10;
		break;
	case 'h':
	case 'H':
		radix = 16;
		break;
	default:
		throw std::runtime_error(
				std::string("Unknown number base:") + s[valuePartStart - 1]);
	}

	std::string strVal = s.substr(valuePartStart, s.length()); // cut off prefix
	if (size != std::string::npos)
		return iHdlExpr::INT(strVal, size, radix);
	return iHdlExpr::INT(strVal, radix);

}
iHdlExpr* VerLiteralParser::visitNumber(sv2017Parser::NumberContext *ctx) {
	// number:
	//     integral_number
	//     | real_number
	// ;
	auto i = ctx->integral_number();
	if (i) {
		return visitIntegral_number(i);
	}
	auto r = ctx->real_number();
	assert(r);
	return visitReal_number(r);
}
iHdlExpr* VerLiteralParser::visitSIMPLE_IDENTIFIER(TerminalNode *n) {
	return iHdlExpr::ID(n->getText());
}
iHdlExpr* VerLiteralParser::visitC_IDENTIFIER(TerminalNode *n) {
	return iHdlExpr::ID(n->getText());
}
std::string VerLiteralParser::visitESCAPED_IDENTIFIER(TerminalNode *n) {
	auto s = n->getText();
	s = s.substr(1);
	return s;
}
iHdlExpr* VerLiteralParser::visitTIME_LITERAL(TerminalNode *n) {
	NotImplementedLogger::print("VerLiteralParser.visitTIME_LITERAL", n);
	return iHdlExpr::null();
}
iHdlExpr* VerLiteralParser::visitReal_number(
		sv2017Parser::Real_numberContext *ctx) {
	// real_number:
	//    REAL_NUMBER_WITH_EXP
	//    | FIXED_POINT_NUMBER
	// ;
	std::string s = ctx->getText();
	double val = stod(s);
	return iHdlExpr::FLOAT(val);
}
iHdlExpr* VerLiteralParser::visitSTRING(TerminalNode *n) {
	std::string s = n->getText();
	return iHdlExpr::STR(s.substr(1, s.length() - 2)); // skipping " at the end
}
HdlOperatorType VerLiteralParser::visitUnary_module_path_operator(
		sv2017Parser::Unary_module_path_operatorContext *ctx) {
	// unary_module_path_operator:
	//     NOT
	//     | NEG
	//     | AMPERSAND
	//     | NAND
	//     | BAR
	//     | NOR
	//     | XOR
	//     | NXOR
	//     | XORN
	// ;
	if (ctx->NOT()) {
		return HdlOperatorType::NOT;
	} else if (ctx->NEG()) {
		return HdlOperatorType::NEG;
	} else if (ctx->AMPERSAND()) {
		return HdlOperatorType::AND;
	} else if (ctx->NAND()) {
		return HdlOperatorType::NAND;
	} else if (ctx->BAR()) {
		return HdlOperatorType::OR;
	} else if (ctx->NOR()) {
		return HdlOperatorType::NOR;
	} else if (ctx->XOR()) {
		return HdlOperatorType::XOR;
	} else if (ctx->NXOR()) {
		return HdlOperatorType::XNOR;
	} else {
		assert(ctx->XORN());
		return HdlOperatorType::XNOR;
	}
}
HdlOperatorType VerLiteralParser::visitUnary_operator(
		sv2017Parser::Unary_operatorContext *ctx) {
	// unary_operator:
	//     PLUS
	//     | MINUS
	//     | unary_module_path_operator
	// ;
	if (ctx->PLUS()) {
		return HdlOperatorType::ADD;
	} else if (ctx->MINUS()) {
		return HdlOperatorType::SUB;
	} else {
		auto umpo = ctx->unary_module_path_operator();
		assert(umpo);
		return visitUnary_module_path_operator(umpo);
	}
}
HdlOperatorType VerLiteralParser::visitOperator_mul_div_mod(
		sv2017Parser::Operator_mul_div_modContext *ctx) {
	// operator_mul_div_mod:
	// 	   MUL
	//     | DIV
	//     | MOD
	// ;
	if (ctx->MUL())
		return HdlOperatorType::MUL;
	else if (ctx->DIV())
		return HdlOperatorType::DIV;
	else {
		assert(ctx->MOD());
		return HdlOperatorType::MOD;
	}
}
HdlOperatorType VerLiteralParser::visitOperator_plus_minus(
		sv2017Parser::Operator_plus_minusContext *ctx) {
	// operator_plus_minus:
	// 	   PLUS
	//     | MINUS
	// ;
	if (ctx->PLUS())
		return HdlOperatorType::ADD;
	else {
		assert(ctx->MINUS());
		return HdlOperatorType::SUB;
	}
}
HdlOperatorType VerLiteralParser::visitOperator_shift(
		sv2017Parser::Operator_shiftContext *ctx) {
	// operator_shift:
	// 	SHIFT_LEFT
	//    | SHIFT_RIGHT
	//    | ARITH_SHIFT_LEFT
	//    | ARITH_SHIFT_RIGHT
	// ;
	if (ctx->SHIFT_LEFT())
		return HdlOperatorType::SRL;
	else if (ctx->SHIFT_RIGHT())
		return HdlOperatorType::SLL;
	else if (ctx->ARITH_SHIFT_LEFT())
		return HdlOperatorType::SLA;
	else {
		assert(ctx->ARITH_SHIFT_RIGHT());
		return HdlOperatorType::SRA;
	}
}
HdlOperatorType VerLiteralParser::visitOperator_cmp(
		sv2017Parser::Operator_cmpContext *ctx) {
	// operator_cmp:
	// 	 LT
	//    | LE
	//    | GT
	//    | GE
	// ;
	if (ctx->LT())
		return HdlOperatorType::LT;
	else if (ctx->LE())
		return HdlOperatorType::LE;
	else if (ctx->GT())
		return HdlOperatorType::GT;
	else {
		assert(ctx->GE());
		return HdlOperatorType::GE;
	}
}
HdlOperatorType VerLiteralParser::visitOperator_eq_neq(
		sv2017Parser::Operator_eq_neqContext *ctx) {
	// operator_eq_neq:
	// 	    EQ
	//    | NEQ
	//    | CASE_EQ
	//    | CASE_NEQ
	//    | WILDCARD_EQ
	//    | WILDCARD_NEQ
	// ;
	if (ctx->EQ())
		return HdlOperatorType::EQ;
	else if (ctx->NEQ())
		return HdlOperatorType::NEQ;
	else if (ctx->CASE_EQ()) {
		NotImplementedLogger::print(
				"VerLiteralParser::visitOperator_eq_neq CASE_EQ", ctx);
		return HdlOperatorType::EQ;
	} else if (ctx->CASE_NEQ()) {
		NotImplementedLogger::print(
				"VerLiteralParser::visitOperator_eq_neq CASE_NEQ", ctx);
		return HdlOperatorType::NEQ;
	} else if (ctx->WILDCARD_EQ()) {
		NotImplementedLogger::print(
				"VerLiteralParser::visitOperator_eq_neq WILDCARD_EQ", ctx);
		return HdlOperatorType::EQ;
	} else if (ctx->WILDCARD_EQ()) {
		NotImplementedLogger::print(
				"VerLiteralParser::visitOperator_eq_neq WILDCARD_EQ", ctx);
		return HdlOperatorType::EQ;
	} else {
		assert(ctx->WILDCARD_NEQ());
		NotImplementedLogger::print(
				"VerLiteralParser::visitOperator_eq_neq WILDCARD_NEQ", ctx);
		return HdlOperatorType::NEQ;
	}
}
HdlOperatorType VerLiteralParser::visitOperator_xor(
		sv2017Parser::Operator_xorContext *ctx) {
	// operator_xor:
	// 	  XOR
	// 	| NXOR
	// 	| XORN
	// ;
	if (ctx->XOR())
		return HdlOperatorType::XOR;
	else {
		assert(ctx->NXOR() || ctx->XORN());
		return HdlOperatorType::XNOR;
	}
}
HdlOperatorType VerLiteralParser::visitOperator_impl(
		sv2017Parser::Operator_implContext *ctx) {
	// operator_impl:
	// 	  ARROW
	// 	| BI_DIR_ARROW
	// ;
	if (ctx->ARROW()) {
		return HdlOperatorType::ARROW;
	} else {
		assert(ctx->BI_DIR_ARROW());
		NotImplementedLogger::print(
				"VerLiteralParser.visitOperator_impl - BI_DIR_ARROW", ctx);
		return HdlOperatorType::ARROW;
	}
}

HdlOperatorType VerLiteralParser::visitAssignment_operator(
		sv2017Parser::Assignment_operatorContext *ctx) {
	// assignment_operator:
	//    ASSIGN
	//    | PLUS_ASSIGN
	//    | MINUS_ASSIGN
	//    | MUL_ASSIGN
	//    | DIV_ASSIGN
	//    | MOD_ASSIGN
	//    | AND_ASSIGN
	//    | OR_ASSIGN
	//    | XOR_ASSIGN
	//    | SHIFT_LEFT_ASSIGN
	//    | SHIFT_RIGHT_ASSIGN
	//    | ARITH_SHIFT_LEFT_ASSIGN
	//    | ARITH_SHIFT_RIGHT_ASSIGN
	// ;
	switch (ctx->start->getType()) {
	case sv2017Parser::ASSIGN:
		return HdlOperatorType::ASSIGN;
	case sv2017Parser::PLUS_ASSIGN:
		return HdlOperatorType::PLUS_ASSIGN;
	case sv2017Parser::MINUS_ASSIGN:
		return HdlOperatorType::MINUS_ASSIGN;
	case sv2017Parser::MUL_ASSIGN:
		return HdlOperatorType::MUL_ASSIGN;
	case sv2017Parser::DIV_ASSIGN:
		return HdlOperatorType::DIV_ASSIGN;
	case sv2017Parser::MOD_ASSIGN:
		return HdlOperatorType::MOD_ASSIGN;
	case sv2017Parser::AND_ASSIGN:
		return HdlOperatorType::AND_ASSIGN;
	case sv2017Parser::OR_ASSIGN:
		return HdlOperatorType::OR_ASSIGN;
	case sv2017Parser::XOR_ASSIGN:
		return HdlOperatorType::XOR_ASSIGN;
	case sv2017Parser::SHIFT_LEFT_ASSIGN:
		return HdlOperatorType::SHIFT_LEFT_ASSIGN;
	case sv2017Parser::SHIFT_RIGHT_ASSIGN:
		return HdlOperatorType::SHIFT_RIGHT_ASSIGN;
	case sv2017Parser::ARITH_SHIFT_LEFT_ASSIGN:
		return HdlOperatorType::ARITH_SHIFT_LEFT_ASSIGN;
	case sv2017Parser::ARITH_SHIFT_RIGHT_ASSIGN:
		return HdlOperatorType::ARITH_SHIFT_RIGHT_ASSIGN;
	default:
		assert(false);
		return HdlOperatorType::ARITH_SHIFT_RIGHT_ASSIGN;
	};
}

iHdlExpr* VerLiteralParser::visitPrimary_literal(
		sv2017Parser::Primary_literalContext *ctx) {
	// primary_literal:
	//     TIME_LITERAL
	//     | UNBASED_UNSIZED_LITERAL
	//     | STRING_LITERAL
	//     | number
	//     | KW_NULL
	//     | KW_THIS
	//     | DOLAR
	// ;

	auto tl = ctx->TIME_LITERAL();
	if (tl) {
		return visitTIME_LITERAL(tl);
	}
	auto uul = ctx->UNBASED_UNSIZED_LITERAL();
	if (uul) {
		// UNBASED_UNSIZED_LITERAL:
		//     APOSTROPHE Z_OR_X
		//     | '\'0'
		//     | '\'1'
		// ;
		auto t = uul->getText();
		assert(t.size() == 2);
		return iHdlExpr::INT(t.substr(1), 10);
	}
	auto sl = ctx->STRING_LITERAL();
	if (sl) {
		return visitSTRING(sl);
	}
	auto n = ctx->number();
	if (n) {
		return visitNumber(n);
	}
	if (ctx->KW_NULL())
		return iHdlExpr::null();
	if (ctx->KW_THIS())
		return iHdlExpr::ID("this");
	assert(ctx->DOLAR());
	return iHdlExpr::ID("$");
}

}
}
