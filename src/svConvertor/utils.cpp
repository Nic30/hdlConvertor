#include <hdlConvertor/svConvertor/utils.h>

#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/hdlObjects/hdlValue.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Lexer.h>

namespace hdlConvertor {
namespace sv {

using sv2017Parser = sv2017_antlr::sv2017Parser;
using sv2017Lexer = sv2017_antlr::sv2017Lexer;
using namespace hdlConvertor::hdlObjects;

iHdlExpr* Utils::mkStringT() {
	return iHdlExpr::ID("__str__");
}

iHdlExpr* Utils::mkIntT() {
	return iHdlExpr::ID("integer");
}
iHdlExpr* Utils::mkWireT() {
	return iHdlExpr::ID("wire");
}

iHdlExpr* Utils::mkWireT(iHdlExpr *range, bool signed_) {
	std::vector<iHdlExpr*> operands = { range, iHdlExpr::INT(signed_ ? 1 : 0) };
	return iHdlExpr::call(mkWireT(), operands);
}

bool Utils::is_reg(antlr4::ParserRuleContext *ctx) {
	auto rt = ctx->getToken(sv2017Lexer::KW_REG, 0);
	bool reg_ = rt != nullptr;
	if (reg_ == true) {
		assert(rt->getText() == "reg");
	}
	return reg_;
}

bool Utils::is_signed(antlr4::ParserRuleContext *ctx) {
	auto st = ctx->getToken(sv2017Lexer::KW_SIGNED, 0);
	bool signed_ = st != nullptr;
	if (signed_ == true) {
		assert(st->getText() == "signed");
	}
	return signed_;
}

iHdlExpr* append_dot_separated_expr(iHdlExpr *selected_name,
		iHdlExpr *new_part) {
	if (selected_name) {
		return new iHdlExpr(selected_name, HdlOperatorType::DOT, new_part);
	} else {
		return new_part;
	}
}


}
}
