#include <hdlConvertor/vhdlConvertor/aliasParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/createObject.h>
#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlAst;

std::unique_ptr<HdlIdDef> VhdlAliasParser::visitAlias_declaration(
		vhdlParser::Alias_declarationContext *ctx) {
	//alias_declaration
	//	: SIGNAL alias_designator COLON
	//	( COLON subtype_indication )? KW_IS name ( signature )?
	//	;

	std::unique_ptr<iHdlExprItem> type = nullptr;
	auto si = ctx->subtype_indication();
	if (si)
		type = VhdlTypeDeclarationParser::visitSubtype_indication(si);

	//auto _type = VhdlTypeDeclarationParser::visitSubtype_indication(ctx->subtype_indication());
	//auto test = VhdlAliasParser::visitAlias_designator(ctx->alias_designator);
	auto _ad = ctx->alias_designator();
	auto name = VhdlReferenceParser::visitName(ctx->name());
	//auto sig = ctx->signature();


	auto a = create_object<HdlIdDef>(ctx, _ad->getText(), std::move(type), std::move(name));

	a->is_alias = true;

	//if (sig) {
	//	NotImplementedLogger::print(
	//			"VhdlAliasParser.visitSignature", sig);
	//}

	return a;
}
}
}
