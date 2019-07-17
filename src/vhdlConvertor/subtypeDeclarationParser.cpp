#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

HdlVariableDef * SubtypeDeclarationParser::visitSubtype_declaration(
		vhdlParser::Subtype_declarationContext* ctx) {
	//subtype_declaration
	//  : SUBTYPE identifier IS subtype_indication SEMI
	//  ;
	auto t = ExprParser::visitSubtype_indication(ctx->subtype_indication());
	auto v = new HdlVariableDef(ctx->identifier()->getText(),
			iHdlExpr::TYPE_T(), t);
	return v;
}

}
}
