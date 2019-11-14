#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/archParser.h>
#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>

#include <hdlConvertor/vhdlConvertor/variableParser.h>

#include <hdlConvertor/createObject.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

VhdlPackageParser::VhdlPackageParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
}
std::unique_ptr<HdlNamespace> VhdlPackageParser::visitPackage_body(
		vhdlParser::Package_bodyContext* ctx) {
	// package_body:
	//       PACKAGE BODY identifier IS
	//           ( package_body_declarative_item )*
	//       END ( PACKAGE BODY )? ( identifier )? SEMI
	// ;
	p = create_object<HdlNamespace>(ctx);
	p->name = VhdlLiteralParser::getIdentifierStr(ctx->identifier(0));

	if (!hierarchyOnly) {
		auto pbdi = ctx->package_body_declarative_item();
		for (auto i : pbdi) {
			visitPackage_body_declarative_item(i);
		}
	}
	return std::move(p);
}

void VhdlPackageParser::visitPackage_body_declarative_item(
		vhdlParser::Package_body_declarative_itemContext* ctx) {
	// package_body_declarative_item
	//   : subprogram_declaration
	//   | subprogram_body
	//   | type_declaration
	//   | subtype_declaration
	//   | constant_declaration
	//   | variable_declaration
	//   | file_declaration
	//   | alias_declaration
	//   | use_clause
	//   | group_template_declaration
	//   | group_declaration
	//   ;
    //
	//package_body_declarative_item:
	//      subprogram_declaration
	//      | subprogram_body
	//      | subprogram_instantiation_declaration
	//      | package_declaration
	//      | package_body
	//      | package_instantiation_declaration
	//      | type_declaration
	//      | subtype_declaration
	//      | constant_declaration
	//      | variable_declaration
	//      | file_declaration
	//      | alias_declaration
	//      | attribute_declaration
	//      | attribute_specification
	//      | use_clause
	//      | group_template_declaration
	//      | group_declaration
	//;


    auto sp = ctx->subprogram_declaration();
	if (sp) {
		p->objs.push_back(VhdlSubProgramDeclarationParser::visitSubprogram_declaration(sp));
        return;
	}
    auto sb = ctx->subprogram_body();
	if (sb) {
		auto f = VhdlSubProgramParser::visitSubprogram_body(sb);
		p->objs.push_back(std::move(f));
		return;
	}
    auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"PackageParser.visitType_declaration", td);
        return;
	}
    auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = VhdlSubtypeDeclarationParser::visitSubtype_declaration(st);
		p->objs.push_back(std::move(_st));
		return;
	}
    auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = VhdlConstantParser::visitConstant_declaration(constd);
		for (auto & c : *constants) {
			p->objs.push_back(std::move(c));
		}
        return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VhdlVariableParser::visitVariable_declaration(vd);
		for (auto & v : *variables) {
			p->objs.push_back(std::move(v));
		}
        return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print(
				"PackageParser.visitFile_declaration", fd);
        return;
	}

	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print(
				"PackageParser.visitAlias_declaration", aliasd);
        return;
	}
    auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("PackageParser.visitUse_clause", uc);
        return;
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"PackageParser.visitGroup_template_declaration", gtd);
        return;
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print(
				"PackageParser.visitGroup_declaration", gd);
        return;
	}
	NotImplementedLogger::print(
			"PackageParser.visitProcess_declarative_item", ctx);
}

}
}
