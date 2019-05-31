#include "literalParser.h"
#include <vector>
#include <stdlib.h>
#include <algorithm>

#include "../notImplementedLogger.h"
using vhdlParser = vhdl_antlr::vhdlParser;

using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace vhdl {

Expr * LiteralParser::visitLiteral(vhdlParser::LiteralContext* ctx) {
	// literal:
	//       numeric_literal
	//       | enumeration_literal
	//       | string_literal
	//       | bit_string_literal
	//       | NULL_SYM
	// ;

	auto nl = ctx->numeric_literal();
	if (nl)
		return visitNumeric_literal(nl);
	auto el = ctx->enumeration_literal();
	if (el)
		return visitEnumeration_literal(el);

	auto sl = ctx->string_literal();
	if (sl)
		return visitString_literal(sl);

	if (ctx->NULL_SYM())
		return Expr::null();

	auto n = ctx->bit_string_literal();
	assert(n);
	std::string s = n->getText();
	std::size_t fdRadix = s.find('"') - 1;
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	int radix = 0;
	int bitRatio = 0;
	switch (s[fdRadix]) {
	case 'b':
		radix = 2;
		bitRatio = 1;
		break;
	case 'o':
		radix = 8;
		bitRatio = 2;
		break;
	case 'x':
		radix = 16;
		bitRatio = 4;
		break;
	case 'd':
		radix = 16;
		bitRatio = 4;
		break;
	}

	int integer = 0;
	if ((fdRadix > 0 && s[fdRadix - 1] != 'u')
			|| (fdRadix > 1 && s[fdRadix - 1] == 'u')) {
		integer = std::stoi(s);
	}

	s[s.length() - 1] = 0; // cut of "
	s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
	char * strVal = (char*) s.c_str() + fdRadix + 2; // cut off radix"
	int bits;
	if (integer != 0) {
		bits = integer;
	} else {
		bits = strlen(strVal) * bitRatio;
	}

// TODO: Not correct implementation for don't care.
	if (s.find('-') != std::string::npos) {
		BigInteger val = BigInteger_fromStr("0", radix);
		return new Expr(val, bits);
	} else {
		BigInteger val = BigInteger_fromStr(strVal, radix);
		return new Expr(val, bits);
	}

}

Expr * LiteralParser::visitNumeric_literal(
		vhdlParser::Numeric_literalContext* ctx) {
	// numeric_literal
	// : abstract_literal
	// | physical_literal
	// ;
	auto al = ctx->abstract_literal();
	if (al)
		return visitAbstract_literal(al);
	else
		return visitPhysical_literal(ctx->physical_literal());
}
Expr * LiteralParser::visitPhysical_literal(
		vhdlParser::Physical_literalContext* ctx) {
	// physical_literal
	// : abstract_literal (: identifier)
	// ;
	NotImplementedLogger::print("LiteralParser.visitPhysical_literal");
	return NULL;
}
Expr * LiteralParser::visitAbstract_literal(
		vhdlParser::Abstract_literalContext* ctx) {
	// abstract_literal: decimal_literal | based_literal;

	// abstract_literal: decimal_literal | based_literal;
	auto dl = ctx->decimal_literal();
	if (dl) {
		// decimal_literal: integer ( DOT integer )? ( exponent )?;
		auto n = dl->integer();
		if (n.size() == 1)
			return Expr::INT(n[0]->getText(), 10);

		NotImplementedLogger::print("LiteralParser.visitAbstract_literal - float");
		return nullptr;
		//return Expr::FLOAT(atof(n[0]->getText().c_str()));
	}
	auto bl = ctx->based_literal();
	assert(bl);
	// based_literal:
	//       base HASHTAG based_integer ( DOT based_integer )? HASHTAG ( exponent )?
	// ;

	// INTEGER must be checked to be between and including 2 and 16
	// (included) i.e. INTEGER >=2 and INTEGER <=16
	// A Based integer (a number without a . such as 3) should not have a
	// negative exponent A Based fractional number with a . i.e. 3.0 may
	// have a negative exponent These should be checked in the
	// Visitor/Listener whereby an appropriate error message
	// should be given

	// [TODO] exponent
	auto n = bl->base();
	int base = atoi(n->children[0]->getText().c_str());
	BigInteger val = BigInteger_fromStr(bl->children[2]->getText().c_str(),
			base);
	if (bl->exponent()) {
		NotImplementedLogger::print("LiteralParser.visitBased_literal - exponent");
	}
	return new Expr(val);
}
Expr * LiteralParser::visitEnumeration_literal(
		vhdlParser::Enumeration_literalContext* ctx) {
	// enumeration_literal: identifier | character_literal;
	auto id = ctx->identifier();
	if (id)
		return visitIdentifier(id);

	return visitCharacter_literal(ctx->character_literal());
}
Expr * LiteralParser::visitString_literal(vhdlParser::String_literalContext * ctx) {
	std::string s = ctx->getText();
	std::string str = s.substr(1, s.length() - 2);
	return Expr::STR(str);

}
Expr * LiteralParser::visitCharacter_literal(vhdlParser::Character_literalContext* ctx) {
	return Expr::INT(ctx->getText()[1] - '0');
}
Expr * LiteralParser::visitIdentifier(vhdlParser::IdentifierContext * ctx) {
	std::string s = ctx->getText();
	return Expr::ID(s);
}
bool LiteralParser::isStrDesignator(vhdlParser::DesignatorContext* ctx) {
	// designator: identifier | operator_symbol
	return ctx->identifier() == nullptr;
}
char * LiteralParser::visitDesignator(vhdlParser::DesignatorContext* ctx) {
	// designator: identifier | operator_symbol
	// operator_symbol: string_literal;;
	Expr * e;
	if (isStrDesignator(ctx)) {
		e = visitString_literal(ctx->operator_symbol()->string_literal());
	} else {
		e = visitIdentifier(ctx->identifier());
	}
	Symbol* s = dynamic_cast<Symbol*>(e->data);
	e->data = NULL;
	delete e;
	return s->value._str;
}

char * LiteralParser::visitLabel(vhdlParser::LabelContext * ctx) {
	// label_colon
	// : identifier COLON
	// ;
	Expr * e = LiteralParser::visitIdentifier(ctx->identifier());
	char * s = strdup(dynamic_cast<Symbol*>(e->data)->value._str);
	delete e;
	return s;
}

}
}
