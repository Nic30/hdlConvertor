#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>

#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

PackageHeaderParser::PackageHeaderParser(bool _hierarchyOnly) {
	ph = new HdlNamespace();
	ph->defs_only = true;
	hierarchyOnly = _hierarchyOnly;
}

HdlNamespace * PackageHeaderParser::visitPackage_declaration(
		vhdlParser::Package_declarationContext* ctx) {
	// package_declaration:
	//       PACKAGE identifier IS
	//           package_header
	//           package_declarative_part
	//       END ( PACKAGE )? ( simple_name )? SEMI
	// ;

	NotImplementedLogger::print(
			"PackageHeaderParser.visitPackage_declaration - package_header", ctx);

	iHdlExpr * name = LiteralParser::visitIdentifier(ctx->identifier());
	ph->name = name->extractStr();
	delete name;
	visitPackage_declarative_part(ctx->package_declarative_part());
	return ph;
}
void PackageHeaderParser::visitPackage_declarative_part(
		vhdlParser::Package_declarative_partContext* ctx) {
	// package_declarative_part
	// : ( package_declarative_item )*
	// ;
	for (auto i : ctx->package_declarative_item()) {
		visitPackage_declarative_item(i);
	}
}

void PackageHeaderParser::visitPackage_declarative_item(
		vhdlParser::Package_declarative_itemContext* ctx) {
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
		ph->objs.push_back(
				SubProgramDeclarationParser::visitSubprogram_declaration(sp));
		return;
	}
	auto sid = ctx->subprogram_instantiation_declaration();
	if (sid) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitPackage_declarative_item - subprogram_instantiation_declaration", sid);
		return;
	}
	auto pd = ctx->package_declaration();
	if (pd) {
		PackageHeaderParser php(hierarchyOnly);
		auto pac_header = php.visitPackage_declaration(pd);
		ph->objs.push_back(pac_header);
		return;
	}
	auto pid = ctx->package_instantiation_declaration();
	if (pid) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitPackage_declarative_item - package_instantiation_declaration", pid);
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitType_declaration", td);
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = SubtypeDeclarationParser::visitSubtype_declaration(st);
		ph->objs.push_back(_st);
		return;
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = ConstantParser::visitConstant_declaration(constd);
		for (auto c : *constants) {
			ph->objs.push_back(c);
		}
		delete constants;
		return;
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = SignalParser::visitSignal_declaration(sd);
		for (auto s : *signals) {
			ph->objs.push_back(s);
		}
		delete signals;
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VariableParser::visitVariable_declaration(vd);
		for (auto v : *variables) {
			ph->objs.push_back(v);
		}
		delete variables;
		return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print(
				"PackageHeaderParser.visitFile_declaration", fd);
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
HdlModuleDec * PackageHeaderParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext* ctx) {
	// component_declaration:
	//       COMPONENT identifier ( IS )?
	//           ( generic_clause )?
	//           ( port_clause )?
	//       END COMPONENT ( simple_name )? SEMI
	// ;

	HdlModuleDec * e = new HdlModuleDec();
	e->name = ctx->identifier()->getText();
	if (!hierarchyOnly) {
		auto gc = ctx->generic_clause();
		if (gc)
			EntityParser::visitGeneric_clause(gc, &e->generics);
		auto pc = ctx->port_clause();
		if (pc)
			EntityParser::visitPort_clause(pc, &e->ports);
	}
	return e;
}

}
}
