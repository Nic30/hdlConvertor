#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>

#include <hdlConvertor/createObject.h>

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

namespace hdlConvertor {
namespace vhdl {

std::unique_ptr<HdlTypeDec> VhdlSubtypeDeclarationParser::visitSubtype_declaration(
		vhdlParser::Subtype_declarationContext *ctx) {
	//subtype_declaration
	//  : SUBTYPE identifier IS subtype_indication SEMI
	//  ;
	auto st = VhdlExprParser::visitSubtype_indication(ctx->subtype_indication());
	auto v = create_object<HdlTypeDec>(ctx,
			VhdlLiteralParser::getIdentifierStr(ctx->identifier()),
			std::move(st));
	return v;
}

}
}
