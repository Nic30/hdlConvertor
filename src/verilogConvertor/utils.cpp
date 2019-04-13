#include "utils.h"
#include "exprParser.h"
#include "Verilog2001Parser/Verilog2001Lexer.h"
#include "../hdlObjects/symbolType.h"

using namespace Verilog2001;

Expr *Utils::mkStringT() {
	return Expr::ID("__str__");
}

Expr *Utils::mkWireT() {
	return Expr::ID("wire");
}

Expr *Utils::mkWireT(Expr * range, bool signed_) {
	std::vector<Expr*> * operands = new std::vector<Expr*>();
	operands->push_back(range);
	operands->push_back(Expr::INT(signed_));
	return Expr::call(mkWireT(), operands);
}

Expr *Utils::mkWireT(Verilog2001Parser::Range_Context * range, bool signed_) {
	if (range)
		return mkWireT(VerExprParser::visitRange_(range), signed_);
	else {
		assert(signed_ == false);
		return mkWireT();
	}
}
bool Utils::is_signed(antlr4::ParserRuleContext * ctx) {
	//assert(strcmp(Verilog2001Lexer::getVocabulary() == "signed") == 0)
	auto st = ctx->getToken(Verilog2001Lexer::T__25, 0);
	bool signed_ = st != nullptr;
	if (signed_ == true) {
		assert(st->getText() == "signed");
	}
	return signed_;
}
