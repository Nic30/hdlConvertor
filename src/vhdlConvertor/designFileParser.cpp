#include <hdlConvertor/vhdlConvertor/designFileParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/hdlCall.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/archParser.h>


namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

DesignFileParser::DesignFileParser(antlr4::TokenStream* tokens, HdlContext * ctx,
		bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly), commentParser(tokens) {
}

void DesignFileParser::visitDesign_file(vhdlParser::Design_fileContext* ctx) {
	if (!ctx)
		return;
	// design_file
	// : ( design_unit )* EOF
	// ;
	for (auto u : ctx->design_unit()) {
		DesignFileParser::visitDesign_unit(u);
	}
}

void DesignFileParser::visitDesign_unit(vhdlParser::Design_unitContext* ctx) {
	if (!ctx)
		return;
	// design_unit
	// : context_clause library_unit
	// ;
	DesignFileParser::visitContext_clause(ctx->context_clause());
	DesignFileParser::visitLibrary_unit(ctx->library_unit());
}
void DesignFileParser::visitLibrary_unit(vhdlParser::Library_unitContext* ctx) {
	if (!ctx)
		return;
	// library_unit
	// : secondary_unit | primary_unit
	// ;

	DesignFileParser::visitSecondary_unit(ctx->secondary_unit());
	DesignFileParser::visitPrimary_unit(ctx->primary_unit());
}
void DesignFileParser::visitSecondary_unit(
		vhdlParser::Secondary_unitContext* ctx) {
	if (!ctx)
		return;
	// secondary_unit
	// : architecture_body
	// | package_body
	// ;
	auto arch = ctx->architecture_body();
	if (arch) {
		ArchParser aparser(hierarchyOnly);
		HdlModuleDef * a = aparser.visitArchitecture_body(arch);
		context->objs.push_back(a);
	}
	auto pack = ctx->package_body();
	if (pack) {
		PackageParser pparser(hierarchyOnly);
		auto p = pparser.visitPackage_body(pack);
		context->objs.push_back(p);

	}
}
void DesignFileParser::visitContext_clause(
		vhdlParser::Context_clauseContext* ctx) {
	if (!ctx)
		return;
	// context_clause
	// : ( context_item )*
	// ;
	for (auto item : ctx->context_item()) {
		visitContext_item(item);
	}
}
void DesignFileParser::visitPrimary_unit(vhdlParser::Primary_unitContext* ctx) {
	if (!ctx)
		return;
	// primary_unit
	// : entity_declaration
	// | configuration_declaration
	// | package_declaration
	// ;
	auto ed = ctx->entity_declaration();
	if (ed) {
		EntityParser eParser(commentParser, hierarchyOnly);
		HdlModuleDec * e = eParser.visitEntity_declaration(ed);
		context->objs.push_back(e);
		return;
	}
	auto cd = ctx->configuration_declaration();
	if (cd) {
		NotImplementedLogger::print(
				"DesignFileParser.visitConfiguration_declaration", cd);
		return;
	}
	auto pd = ctx->package_declaration();
	if (pd) {
		PackageHeaderParser php(hierarchyOnly);
		auto ph = php.visitPackage_declaration(pd);
		context->objs.push_back(ph);
	}

}
void DesignFileParser::visitContext_item(vhdlParser::Context_itemContext* ctx) {
	// context_item
	// : library_clause
	// | use_clause
	// ;
	auto l = ctx->library_clause();
	if (l) {
		NotImplementedLogger::print(
				"DesignFileParser.visitContext_item - library_clause", l);
		return; //libraries are ignored
	}
	auto u = ctx->use_clause();
	if (u) {
		context->objs.push_back(visitUse_clause(u));
	}
}

void flatten_doted_expr(iHdlExpr * e, std::vector<iHdlExpr*> & arr) {
	auto o = dynamic_cast<HdlCall*>(e->data);
	if (o) {
		if(o->op == HdlOperatorType::DOT) {
			for (auto _o: o->operands) {
				flatten_doted_expr(_o, arr);
			}
			o->operands.clear();
			return;
		}
	}
	arr.push_back(e);
}

iHdlStatement * DesignFileParser::visitUse_clause(
		vhdlParser::Use_clauseContext* ctx) {
	// use_clause: USE selected_name SEMI
	// ;
	auto sn = ctx->selected_name();
	auto r = ReferenceParser::visitSelected_name(sn);
	std::vector<iHdlExpr*> ref;
	flatten_doted_expr(r, ref);
	delete r;

	return iHdlStatement::IMPORT(ref);
}

}
}
