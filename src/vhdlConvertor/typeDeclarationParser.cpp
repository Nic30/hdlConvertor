#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitType_declaration(
		vhdlParser::Type_declarationContext *ctx) {
	//type_declaration:
	//      full_type_declaration
	//      | incomplete_type_declaration
	//;
	auto ftd = ctx->full_type_declaration();
	if (ftd) 
		return visitFull_type_declaration(ftd);
	else
		return visitIncomplete_type_declaration(ctx->incomplete_type_declaration());
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitIncomplete_type_declaration(
		vhdlParser::Incomplete_type_declarationContext *ctx) {
	//incomplete_type_declaration: KW_TYPE identifier SEMI;
	NotImplementedLogger::print(
			"TypeDeclarationParser.visitIncomplete_type_declaration", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitFull_type_declaration(
		vhdlParser::Full_type_declarationContext *ctx) {
	//full_type_declaration:
	//      KW_TYPE identifier KW_IS type_definition SEMI
	//;
	return visitType_definition(
		VhdlLiteralParser::getIdentifierStr(ctx->identifier()), 
		ctx->type_definition());
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitType_definition(
		std::string &&name, vhdlParser::Type_definitionContext *ctx) {
	//type_definition:
	//      scalar_type_definition
	//      | composite_type_definition
	//      | access_type_definition
	//      | file_type_definition
	//      | protected_type_definition
	//;
	auto scl = ctx->scalar_type_definition();
	if (scl) 
		return visitScalar_type_definition(name, scl);
	auto cmp = ctx->composite_type_definition();
	if (cmp)
		return visitComposite_type_definition(name, cmp);
	auto acc = ctx->access_type_definition();
	if (acc)
		return visitAccess_type_definition(name, acc);
	auto fil = ctx->file_type_definition();
	if (fil)
		return visitFile_type_definition(name, fil);
	auto pro = ctx->protected_type_definition();
	if (pro)
		return visitProtected_type_definition(name, pro);

	NotImplementedLogger::print("TypeDeclarationParser.type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitScalar_type_definition(
		std::string &&name, vhdlParser::Scalar_type_definitionContext *ctx) {
	//scalar_type_definition:
	//      enumeration_type_definition
	//      | integer_type_definition
	//      | floating_type_definition
	//      | physical_type_definition
	//;
	auto e = ctx->enumeration_type_definition();
	if (e)
		return visitEnumeration_type_definition(name, e);
	auto i = ctx->integer_type_definition();
	if (i)
		return visitInteger_type_definition(name, i);
	auto f = ctx->floating_type_definition();
	if (f)
		return visitFloating_type_definition(name, f);
	auto p = ctx->physical_type_definition();
	if (p)
		return visitPhysical_type_definition();
	
	NotImplementedLogger::print("TypeDeclarationParser.type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitComposite_type_definition(
		std::string &&name, vhdlParser::Composite_type_definitionContext *ctx) {
	//composite_type_definition:
	//      array_type_definition
	//      | record_type_definition
	//;
	auto arr = ctx->array_type_definition();
	if (arr)
		return visitArray_type_definition(name, arr);
	auto rec = ctx->record_type_definition();
	if (rec)
		return visitRecord_type_definition(name, arr);

	NotImplementedLogger::print("TypeDeclarationParser.composite_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitAccess_type_definition(
		std::string &&name, vhdlParser::Access_type_definitionContext *ctx) {
	
	NotImplementedLogger::print("TypeDeclarationParser.access_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitFile_type_definition(
		std::string &&name, vhdlParser::File_type_definitionContext *ctx) {
	
	NotImplementedLogger::print("TypeDeclarationParser.file_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitProtected_type_definition(
		std::string &&name, vhdlParser::Protected_type_definitionContext *ctx) {
	
	NotImplementedLogger::print("TypeDeclarationParser.protected_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitEnumeration_type_definition(
		std::string &&name, vhdlParser::Enumeration_type_definitionContext *ctx) {
	//enumeration_type_definition:
	//      LPAREN enumeration_literal ( COMMA enumeration_literal )* RPAREN
	//;
	std::unique_ptr<HdlEnumTypeDec> typ = create_object<HdlEnumTypeDec>(ctx, name);
	for (auto lit : ctx->enumeration_literal()) {
		id = lit->identifier();
                cl = lit->CHARACTER_LITERAL();
		if (id)
			typ.ids.push(std::create_pair(id->getText(), nullptr));
                else if (cl)
			typ.ids.push(std::create_pair(cl->getText(), nullptr));
		else
			NotImplementedLogger::print("TypeDeclarationParser.enumeration_literal", ctx);
	}
	return typ;
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitInteger_type_definition(
		std::string &&name, vhdlParser::Integer_type_definitionContext *ctx) {
	
	NotImplementedLogger::print("TypeDeclarationParser.integer_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitFloating_type_definition(
		std::string &&name, vhdlParser::Floating_type_definitionContext *ctx) {
	
	NotImplementedLogger::print("TypeDeclarationParser.floating_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitPhysical_type_definition(
		std::string &&name, vhdlParser::Physical_type_definitionContext *ctx) {
	
	NotImplementedLogger::print("TypeDeclarationParser.physical_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitArray_type_definition(
		std::string &&name, vhdlParser::Array_type_definitionContext *ctx) {
	//array_type_definition:
	//      unbounded_array_definition | constrained_array_definition
	//;
	auto ub = ctx->unbounded_array_definition();
	if (ub)
		return visitUnbounded_array_definition(name, ub);
	auto con = ctx->constrained_array_definition();
	if (con)
		return visitConstrained_array_definition(name, con);

	NotImplementedLogger::print("TypeDeclarationParser.array_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> visitUnbounded_array_definition(
		std::string &&name, vhdlParser::Unbounded_array_definitionContext *ctx) {
	//unbounded_array_definition:
	//      KW_ARRAY LPAREN index_subtype_definition ( COMMA index_subtype_definition )* RPAREN
	//          KW_OF subtype_indication
	//;
	Here!!
	
	auto t = VhdlExprParser::visitSubtype_indication(ctx->subtype_indication());
	
	
	
	NotImplementedLogger::print("TypeDeclarationParser.unbounded_array_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> visitConstrained_array_definition(
		std::string &&name, vhdlParser::Constrained_array_definitionContext *ctx) {
	//constrained_array_definition:
	//      KW_ARRAY index_constraint KW_OF subtype_indication
	//;
	
	NotImplementedLogger::print("TypeDeclarationParser.constrained_array_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}

static std::unique_ptr<hdlObjects::HdlTypeDec> VhdlTypeDeclarationParser::visitRecord_type_definition(
		std::string &&name, vhdlParser::Record_type_definitionContext *ctx) {
	
	NotImplementedLogger::print("TypeDeclarationParser.record_type_definition", ctx);
	return nullptr;
	//todo: create an hdltc_error type
}



}
}
