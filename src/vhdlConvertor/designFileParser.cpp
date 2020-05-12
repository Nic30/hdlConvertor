#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlAst/hdlOp.h>
#include <hdlConvertor/hdlAst/hdlStm_others.h>
#include <hdlConvertor/hdlAst/hdlLibrary.h>
#include <hdlConvertor/vhdlConvertor/archParser.h>
#include <hdlConvertor/vhdlConvertor/designFileParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlAst;

VhdlDesignFileParser::VhdlDesignFileParser(antlr4::TokenStream &tokens,
		HdlContext &ctx, bool _hierarchyOnly) :
		BaseHdlParser(tokens, ctx, _hierarchyOnly), commentParser(tokens) {
}

void VhdlDesignFileParser::visitDesign_file(
		vhdlParser::Design_fileContext *ctx) {
	if (!ctx)
		return;
	// design_file
	// : ( design_unit )* EOF
	// ;
	for (auto u : ctx->design_unit()) {
		VhdlDesignFileParser::visitDesign_unit(u);
	}
}

void VhdlDesignFileParser::visitDesign_unit(
		vhdlParser::Design_unitContext *ctx) {
	if (!ctx)
		return;
	// design_unit
	// : context_clause library_unit
	// ;
	VhdlDesignFileParser::visitContext_clause(ctx->context_clause());
	VhdlDesignFileParser::visitLibrary_unit(ctx->library_unit());
}
void VhdlDesignFileParser::visitLibrary_unit(
		vhdlParser::Library_unitContext *ctx) {
	if (!ctx)
		return;
	// library_unit
	// : secondary_unit | primary_unit
	// ;

	VhdlDesignFileParser::visitSecondary_unit(ctx->secondary_unit());
	VhdlDesignFileParser::visitPrimary_unit(ctx->primary_unit());
}
void VhdlDesignFileParser::visitSecondary_unit(
		vhdlParser::Secondary_unitContext *ctx) {
	if (!ctx)
		return;
	// secondary_unit
	// : architecture_body
	// | package_body
	// ;
	auto arch = ctx->architecture_body();
	if (arch) {
		VhdlArchParser aparser(hierarchyOnly);
		auto a = aparser.visitArchitecture_body(arch);
		context.objs.push_back(move(a));
	}
	auto pack = ctx->package_body();
	if (pack) {
		VhdlPackageParser pparser(hierarchyOnly);
		auto p = pparser.visitPackage_body(pack);
		context.objs.push_back(move(p));

	}
}
void VhdlDesignFileParser::visitContext_clause(
		vhdlParser::Context_clauseContext *ctx) {
	if (!ctx)
		return;
	// context_clause
	// : ( context_item )*
	// ;
	for (auto item : ctx->context_item()) {
		visitContext_item(item);
	}
}
void VhdlDesignFileParser::visitPrimary_unit(
		vhdlParser::Primary_unitContext *ctx) {
	if (!ctx)
		return;
	// primary_unit
	// : entity_declaration
	// | configuration_declaration
	// | package_declaration
	// ;
	auto ed = ctx->entity_declaration();
	if (ed) {
		VhdlEntityParser eParser(commentParser, hierarchyOnly);
		auto e = eParser.visitEntity_declaration(ed);
		context.objs.push_back(move(e));
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
		VhdlPackageHeaderParser php(hierarchyOnly);
		auto ph = php.visitPackage_declaration(pd);
		context.objs.push_back(std::move(ph));
	}

}
void VhdlDesignFileParser::visitContext_item(
		vhdlParser::Context_itemContext *ctx) {
	// context_item
	// : library_clause
	// | use_clause
	// ;
	auto l = ctx->library_clause();
	if (l) {
		visitLibrary_clause(l);
	}
	auto u = ctx->use_clause();
	if (u) {
		visitUse_clause(u, context.objs);
	}
}

void VhdlDesignFileParser::visitLibrary_clause(
		vhdlParser::Library_clauseContext *ctx) {
	// library_clause: KW_LIBRARY logical_name_list SEMI;
	// logical_name_list: identifier_list;
	vhdlParser::Logical_name_listContext *lnl_ctx = ctx->logical_name_list();
	if (lnl_ctx) {
		vhdlParser::Identifier_listContext *il_ctx = lnl_ctx->identifier_list();
		if (il_ctx) {
			for (auto i : il_ctx->identifier()) {
				auto v = create_object<HdlLibrary>(i, i->getText());
				context.objs.push_back(std::move(v));
			}
		}
	}
}

void flatten_doted_expr(std::unique_ptr<iHdlExprItem> e,
		std::vector<std::unique_ptr<iHdlExprItem>> &arr) {
	auto o = dynamic_cast<HdlOp*>(e.get());
	if (o) {
		if (o->op == HdlOpType::DOT) {
			for (auto &_o : o->operands) {
				flatten_doted_expr(std::move(_o), arr);
			}
			o->operands.clear();
			return;
		}
	}
	arr.push_back(move(e));
}

void VhdlDesignFileParser::visitUse_clause(vhdlParser::Use_clauseContext *ctx,
		std::vector<std::unique_ptr<iHdlObj>> &res) {
	// use_clause:
	//       USE selected_name (COMMA selected_name)* SEMI
	// ;
	auto sns = ctx->selected_name();
	for (auto sn : sns) {
		auto r = VhdlReferenceParser::visitSelected_name(sn);
		std::vector<std::unique_ptr<iHdlExprItem>> ref;
		flatten_doted_expr(move(r), ref);
		auto imp = create_object<HdlStmImport>(sn, ref);
		res.push_back(std::move(imp));
	}
}

}
}
