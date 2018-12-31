#include "subtypeDeclarationParser.h"

Variable * SubtypeDeclarationParser::visitSubtype_declaration(
		vhdlParser::Subtype_declarationContext* ctx) {
	//subtype_declaration
	//  : SUBTYPE identifier IS subtype_indication SEMI
	//  ;
	auto t = ExprParser::visitSubtype_indication(ctx->subtype_indication());
	std::shared_ptr<Expr> tt(Expr::TYPE_T());
	Variable * v = new Variable(ctx->identifier()->getText(), tt, t);
	return v;
}