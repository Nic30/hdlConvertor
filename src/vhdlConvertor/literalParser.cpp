#include "literalParser.h"

Expr * LiteralParser::visitLiteral(Ref<vhdlParser::LiteralContext> ctx) {
	// literal
	// : NULL
	// | BIT_STRING_LITERAL
	// | STRING_LITERAL
	// | enumeration_literal
	// | numeric_literal
	// ;
	if (ctx->NULL_SYM())
		return Expr::null();

	auto n = ctx->BIT_STRING_LITERAL();
	if (n) {
		std::string s = n->getText();
		std::transform(s.begin(), s.end(), s.begin(), ::tolower);
		int radix = 0;
		int bitRatio = 0;
		switch (s[0]) {
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
		}

		s[s.length() - 1] = 0; // cut of "
		char * strVal = (char*) s.c_str() + 2; // cut off radix"
		BigInteger val = BigInteger_fromStr(strVal, radix);
		return new Expr(val, strlen(strVal) * bitRatio);
	}

	n = ctx->STRING_LITERAL();
	if (n)
		return visitSTRING_LITERAL(n);

	auto el = ctx->enumeration_literal();
	if (el)
		return visitEnumeration_literal(el);

	auto nl = ctx->numeric_literal();
	return visitNumeric_literal(nl);
}
Expr * LiteralParser::visitNumeric_literal(
		Ref<vhdlParser::Numeric_literalContext> ctx) {
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
		Ref<vhdlParser::Physical_literalContext> ctx) {
	// physical_literal
	// : abstract_literal (: identifier)
	// ;
	NotImplementedLogger::print("ExprParser.visitPhysical_literal");
	return NULL;
}
Expr * LiteralParser::visitAbstract_literal(
		Ref<vhdlParser::Abstract_literalContext> ctx) {
	// abstract_literal
	// : INTEGER
	// | REAL_LITERAL
	// | BASE_LITERAL
	// ;
	auto n = ctx->INTEGER();
	if (n)
		return Expr::INT(n->getText(), 10);
	n = ctx->REAL_LITERAL();
	if (n)
		return Expr::FLOAT(atof(n->getText().c_str()));

	// INTEGER must be checked to be between and including 2 and 16
	// (included) i.e. INTEGER >=2 and INTEGER <=16
	// A Based integer (a number without a . such as 3) should not have a
	// negative exponent A Based fractional number with a . i.e. 3.0 may
	// have a negative exponent These should be checked in the
	// Visitor/Listener whereby an appropriate error message
	// should be given

	// BASE_LITERAL
	// : INTEGER '#' BASED_INTEGER ('.'BASED_INTEGER)? '#' (EXPONENT)?
	// ;
	// [TODO] exponent
	n = ctx->BASE_LITERAL();
	int base = atoi(n->getChild(0)->getText().c_str());
	BigInteger val = BigInteger_fromStr(n->getChild(2)->getText().c_str(),
			base);
	return new Expr(val);
}
Expr * LiteralParser::visitEnumeration_literal(
		Ref<vhdlParser::Enumeration_literalContext> ctx) {
	// enumeration_literal
	// : identifier
	// | CHARACTER_LITERAL
	// ;
	// CHARACTER_LITERAL
	// : APOSTROPHE . APOSTROPHE
	// ;
	auto id = ctx->identifier();
	if (id)
		return visitIdentifier(id);

	return visitCHARACTER_LITERAL(ctx->CHARACTER_LITERAL());
}
Expr * LiteralParser::visitSTRING_LITERAL(Ref<tree::TerminalNode> n) {
	std::string s = n->getText();
	std::string str = s.substr(1, s.length() - 2);
	return Expr::STR(str);

}
Expr * LiteralParser::visitCHARACTER_LITERAL(Ref<tree::TerminalNode> ctx) {
	return Expr::INT(ctx->getText()[1] - '0');
}
Expr * LiteralParser::visitIdentifier(Ref<vhdlParser::IdentifierContext> ctx) {
	std::string s = ctx->getText();
	return Expr::ID(s);
}
bool LiteralParser::isStrDesignator(Ref<vhdlParser::DesignatorContext> ctx) {
	// designator
	// : identifier
	// | STRING_LITERAL
	// ;
	return ctx->STRING_LITERAL() != NULL;
}
char * LiteralParser::visitDesignator(Ref<vhdlParser::DesignatorContext> ctx) {
	// designator
	// : identifier
	// | STRING_LITERAL
	// ;
	Expr * e;
	if (isStrDesignator(ctx)) {
		e = visitSTRING_LITERAL(ctx->STRING_LITERAL());
	} else {
		e = visitIdentifier(ctx->identifier());
	}
	Symbol* s = dynamic_cast<Symbol*>(e->data);
	return s->value._str;
}
