#include <hdlConvertor/verilogConvertor/utils.h>

#include <hdlConvertor/verilogConvertor/exprParser.h>
#include <hdlConvertor/hdlObjects/hdlValue.h>
#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Lexer.h>

namespace hdlConvertor {
namespace verilog {

using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using Verilog2001Lexer = Verilog2001_antlr::Verilog2001Lexer;
using namespace hdlConvertor::hdlObjects;

iHdlExpr *Utils::mkStringT() {
	return iHdlExpr::ID("__str__");
}

iHdlExpr* Utils::mkIntT() {
	return iHdlExpr::ID("integer");
}
iHdlExpr *Utils::mkWireT() {
	return iHdlExpr::ID("wire");
}

iHdlExpr *Utils::mkWireT(iHdlExpr * range, bool signed_) {
	std::vector<iHdlExpr*> operands = { range, iHdlExpr::INT(signed_ ? 1 : 0) };
	return iHdlExpr::call(mkWireT(), operands);
}

iHdlExpr *Utils::mkWireT(Verilog2001Parser::Range_Context * range,
		bool signed_) {
	if (range)
		return mkWireT(VerExprParser::visitRange_(range), signed_);
	else {
		assert(signed_ == false);
		return mkWireT();
	}
}

bool Utils::is_reg(antlr4::ParserRuleContext * ctx) {
	//assert(strcmp(Verilog2001Lexer::getVocabulary() == "reg") == 0)
	auto rt = ctx->getToken(Verilog2001Lexer::T__34, 0);
	bool reg_ = rt != nullptr;
	if (reg_ == true) {
		assert(rt->getText() == "reg");
	}
	return reg_;
}

bool Utils::is_signed(antlr4::ParserRuleContext * ctx) {
	//assert(strcmp(Verilog2001Lexer::getVocabulary() == "signed") == 0)
	auto st = ctx->getToken(Verilog2001Lexer::T__24, 0);
	bool signed_ = st != nullptr;
	if (signed_ == true) {
		assert(st->getText() == "signed");
	}
	return signed_;
}

}
}
