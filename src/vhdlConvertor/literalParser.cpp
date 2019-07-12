#include <hdlConvertor/vhdlConvertor/literalParser.h>

#include <vector>
#include <stdlib.h>
#include <algorithm>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

iHdlExpr * LiteralParser::visitLiteral(vhdlParser::LiteralContext* ctx) {
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

	auto sl = ctx->STRING_LITERAL();
	if (sl)
		return visitString_literal(sl->getText());

	if (ctx->NULL_SYM())
		return iHdlExpr::null();

	auto n = ctx->BIT_STRING_LITERAL();
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

	int bits = 0;
	if ((fdRadix > 0 && s[fdRadix - 1] != 'u')
			|| (fdRadix > 1 && s[fdRadix - 1] == 'u')) {
		bits = std::stoi(s);
	}

	s[s.length() - 1] = 0; // cut of "
	s.erase(std::remove(s.begin(), s.end(), '_'), s.end());
	const char * strVal = (char*) s.c_str() + fdRadix + 2; // cut off radix"
	if (bits == 0) {
		bits = strlen(strVal) * bitRatio;
	}

	return iHdlExpr::INT(strVal, bits, radix);
}

iHdlExpr * LiteralParser::visitNumeric_literal(
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
iHdlExpr * LiteralParser::visitPhysical_literal(
		vhdlParser::Physical_literalContext* ctx) {
	// physical_literal: ( abstract_literal )? name;
	auto _n = ctx->name();
	auto n = ReferenceParser::visitName(_n);
	auto _al = ctx->abstract_literal();
	if (_al) {
		// used for units (e.g. 1 ns)
		auto al = visitAbstract_literal(_al);
		return new iHdlExpr(al, HdlOperatorType::MUL, n);
	}
	return n;
}
iHdlExpr * LiteralParser::visitAbstract_literal(
		vhdlParser::Abstract_literalContext* ctx) {
	// abstract_literal: DECIMAL_LITERAL | BASED_LITERAL;
	auto dl = ctx->DECIMAL_LITERAL();
	if (dl) {
		// decimal_literal: integer ( DOT integer )? ( exponent )?;
		auto n = dl->getText();
		bool is_float = false;
		for (auto c : n) {
			if (c == '.' || c == 'e' || c == 'E') {
				is_float = true;
				break;
			}
		}
		if (is_float)
			return iHdlExpr::FLOAT(atof(n.c_str()));
		else {
			auto _n = atoi(n.c_str());
			return iHdlExpr::INT(_n);
		}
	}
	auto bl = ctx->based_literal();
	assert(bl);
	// based_literal:
	//       BASE HASHTAG BASED_INTEGER ( DOT BASED_INTEGER )? HASHTAG ( EXPONENT )?
	// ;

	// INTEGER must be checked to be between and including 2 and 16
	// (included) i.e. INTEGER >=2 and INTEGER <=16
	// A Based integer (a number without a . such as 3) should not have a
	// negative exponent A Based fractional number with a . i.e. 3.0 may
	// have a negative exponent These should be checked in the
	// Visitor/Listener whereby an appropriate error message
	// should be given

	// [TODO] exponent
	auto n = bl->BASE();
	auto _n = n->getText();
	int base = atoi(_n.c_str());
	BigInteger val = BigInteger(bl->BASED_INTEGER(0)->getText(), base);
	if (bl->EXPONENT()) {
		NotImplementedLogger::print(
				"LiteralParser.visitBased_literal - EXPONENT", ctx);
	}
	return new iHdlExpr(val);
}
iHdlExpr * LiteralParser::visitEnumeration_literal(
		vhdlParser::Enumeration_literalContext* ctx) {
	// enumeration_literal: identifier | character_literal;
	auto id = ctx->identifier();
	if (id)
		return visitIdentifier(id);

	auto _cl = ctx->CHARACTER_LITERAL()->getText();
	auto cl = visitCharacter_literal(_cl);
	dynamic_cast<HdlValue*>(cl->data)->bits = 8;
	return cl;
}
iHdlExpr * LiteralParser::visitString_literal(const std::string & ctx) {
	std::string str = ctx.substr(1, ctx.length() - 2);
	return iHdlExpr::STR(str);
}
iHdlExpr * LiteralParser::visitCharacter_literal(const std::string & ctx) {
	return iHdlExpr::INT(ctx.substr(1, 1), BigInteger::CHAR_BASE);
}
iHdlExpr * LiteralParser::visitIdentifier(vhdlParser::IdentifierContext * ctx) {
	std::string s = ctx->getText();
	return iHdlExpr::ID(s);
}
bool LiteralParser::isStrDesignator(vhdlParser::DesignatorContext* ctx) {
	// designator: identifier | operator_symbol
	return ctx->identifier() == nullptr;
}
std::string LiteralParser::visitDesignator(vhdlParser::DesignatorContext* ctx) {
	// designator: identifier | operator_symbol
	// operator_symbol: string_literal;;
	iHdlExpr * e;
	if (isStrDesignator(ctx)) {
		e = visitString_literal(
				ctx->operator_symbol()->STRING_LITERAL()->getText());
	} else {
		e = visitIdentifier(ctx->identifier());
	}
	auto s = dynamic_cast<HdlValue*>(e->data);
	e->data = NULL;
	delete e;
	return s->_str;
}

std::string LiteralParser::visitLabel(vhdlParser::LabelContext * ctx) {
	// label_colon
	// : identifier COLON
	// ;
	iHdlExpr * e = LiteralParser::visitIdentifier(ctx->identifier());
	std::string s = dynamic_cast<HdlValue*>(e->data)->_str;
	delete e;
	return s;
}

}
}
