#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
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

VhdlPackageHeaderParser::VhdlPackageHeaderParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
}

std::unique_ptr<HdlNamespace> VhdlPackageHeaderParser::visitPackage_declaration(
		vhdlParser::Package_declarationContext *ctx) {
	// package_declaration:
	//       PACKAGE identifier IS
	//           package_header
	//           package_declarative_part
	//       END ( PACKAGE )? ( identifier )? SEMI
	// ;
	ph = create_object<HdlNamespace>(ctx);
	ph->defs_only = true;
	NotImplementedLogger::print(
			"PackageHeaderParser.visitPackage_declaration - package_header",
			ctx);

	ph->name = VhdlLiteralParser::getIdentifierStr(ctx->identifier(0));
	visitPackage_declarative_part(ctx->package_declarative_part());
	return std::move(ph);
}
void VhdlPackageHeaderParser::visitPackage_declarative_part(
		vhdlParser::Package_declarative_partContext *ctx) {
	// package_declarative_part
	// : ( package_declarative_item )*
	// ;
	for (auto i : ctx->package_declarative_item()) {
		visitPackage_declarative_item(i);
	}
}

void VhdlPackageHeaderParser::visitPackage_declarative_item(
		vhdlParser::Package_declarative_itemContext *ctx) {
	// package_declarative_item
	// : subprogram_declaration
	// | type_declaration
	// | subtype_declaration
	// | constant_declaration
	// | signal_declaration
	// | variable_declaration
	// | file_declaration
	// | alias_declaration
	// | component_declaration
	// | attribute_declaration
	// | attribute_specification
	// | disconnection_specification
	// | use_clause
	// | group_template_declaration
	// | group_declaration
	// | nature_declaration
	// | subnature_declaration
	// | terminal_declaration
	// ;
	auto sp = ctx->subprogram_declaration();
	if (sp) {
		auto f = VhdlSubProgramDeclarationParser::visitSubprogram_declaration(
				sp);
		ph->objs.push_back(std::move(f));
		return;
	}
	auto sid = ctx->subprogram_instantiation_declaration();
	if (sid) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitPackage_declarative_item - subprogram_instantiation_declaration",
				sid);
		return;
	}
	auto pd = ctx->package_declaration();
	if (pd) {
		VhdlPackageHeaderParser php(hierarchyOnly);
		auto pac_header = php.visitPackage_declaration(pd);
		ph->objs.push_back(std::move(pac_header));
		return;
	}
	auto pid = ctx->package_instantiation_declaration();
	if (pid) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitPackage_declarative_item - package_instantiation_declaration",
				pid);
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print("PackageHeaderParser.visitType_declaration",
				td);
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = VhdlSubtypeDeclarationParser::visitSubtype_declaration(st);
		ph->objs.push_back(move(_st));
		return;
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = VhdlConstantParser::visitConstant_declaration(constd);
		for (auto & c : *constants) {
			ph->objs.push_back(move(c));
		}
		return;
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = VhdlSignalParser::visitSignal_declaration(sd);
		for (auto & s : *signals) {
			ph->objs.push_back(move(s));
		}
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VhdlVariableParser::visitVariable_declaration(vd);
		for (auto & v : *variables) {
			ph->objs.push_back(move(v));
		}
		return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print("PackageHeaderParser.visitFile_declaration",
				fd);
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitAlias_declaration", aliasd);
	}
	auto compd = ctx->component_declaration();
	if (compd) {
		ph->objs.push_back(visitComponent_declaration(compd));
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitAttribute_declaration", atrd);
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitAttribute_specification", as);
	}
	auto discs = ctx->disconnection_specification();
	if (discs) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitDisconnection_specification", discs);
	}
	auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("PackageHeaderParser.visitUse_clause", uc);
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitGroup_template_declaration", gtd);
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitGroup_declaration", gd);
	}
}
std::unique_ptr<HdlModuleDec> VhdlPackageHeaderParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext *ctx) {
	// component_declaration:
	//       COMPONENT identifier ( IS )?
	//           ( generic_clause )?
	//           ( port_clause )?
	//       END COMPONENT ( identifier )? SEMI
	// ;

	auto e = create_object<HdlModuleDec>(ctx);
	e->name = ctx->identifier(0)->getText();
	if (!hierarchyOnly) {
		auto gc = ctx->generic_clause();
		if (gc)
			VhdlEntityParser::visitGeneric_clause(gc, e->generics);
		auto pc = ctx->port_clause();
		if (pc)
			VhdlEntityParser::visitPort_clause(pc, e->ports);
	}
	return e;
}

}
}
