#include "subtypeDeclarationParser.h"
#include "exprParser.h"

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

Variable * SubtypeDeclarationParser::visitSubtype_declaration(
		vhdlParser::Subtype_declarationContext* ctx) {
	//subtype_declaration
	//  : SUBTYPE identifier IS subtype_indication SEMI
	//  ;
	auto t = ExprParser::visitSubtype_indication(ctx->subtype_indication());
	Variable * v = new Variable(ctx->identifier()->getText(), Expr::TYPE_T(), t);
	return v;
}

}
}
