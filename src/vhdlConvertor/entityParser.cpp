#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/designFileParser.h>
#include <hdlConvertor/vhdlConvertor/blockDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>



namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlAst;

VhdlEntityParser::VhdlEntityParser(VhdlCommentParser &_commentParser,
		bool _hierarchyOnly) :
		commentParser(_commentParser), hierarchyOnly(_hierarchyOnly) {
}
std::unique_ptr<HdlModuleDec> VhdlEntityParser::visitEntity_declaration(
		vhdlParser::Entity_declarationContext *ctx) {
	// entity_declaration:
	//       KW_ENTITY identifier KW_IS
	//           ( generic_clause )?
	//           ( port_clause )?
	//           ( entity_declarative_item )*
	//       ( KW_BEGIN ( entity_statement )* )?
	//       KW_END ( KW_ENTITY )? ( identifier )? SEMI
	// ;
	auto e = create_object_with_doc<HdlModuleDec>(ctx, commentParser);
	e->name = ctx->identifier(0)->getText();

	if (!hierarchyOnly) {
		auto g = ctx->generic_clause();
		if (g)
			visitGeneric_clause(g, e->generics);
		auto pc = ctx->port_clause();
		if (pc)
			visitPort_clause(pc, e->ports);
		for (auto d : ctx->entity_declarative_item()) {
			visitEntity_declarative_item(d, e->objs);
		}
		if (ctx->entity_statement().size()) {
			NotImplementedLogger::print("VhdlEntityParser.entity_statement", ctx);
		}
	}
	return e;
}

void VhdlEntityParser::visitEntity_declarative_item(
		vhdlParser::Entity_declarative_itemContext *ctx, std::vector<std::unique_ptr<iHdlObj>> & objs) {
	// entity_declarative_item:
	//       subprogram_declaration
	//       | subprogram_body
	//       | subprogram_instantiation_declaration
	//       | package_declaration
	//       | package_body
	//       | package_instantiation_declaration
	//       | type_declaration
	//       | subtype_declaration
	//       | constant_declaration
	//       | signal_declaration
	//       | variable_declaration
	//       | file_declaration
	//       | alias_declaration
	//       | attribute_declaration
	//       | attribute_specification
	//       | disconnection_specification
	//       | use_clause
	//       | group_template_declaration
	//       | group_declaration
	// ;

	auto sp = ctx->subprogram_declaration();
	if (sp) {
		auto f = VhdlSubProgramDeclarationParser::visitSubprogram_declaration(
				sp);
		objs.push_back(std::move(f));
		return;
	}
	auto sb = ctx->subprogram_body();
	if (sb) {
		auto f = VhdlSubProgramParser::visitSubprogram_body(sb);
		objs.push_back(std::move(f));
		return;
	}
	auto sid = ctx->subprogram_instantiation_declaration();
	if (sid) {
		NotImplementedLogger::print(
				"VhdlEntityParser.visitSubprogram_instantiation_declaration", sid);
		return;
	}
	auto pd = ctx->package_declaration();
	if (pd) {
		VhdlPackageHeaderParser ph(hierarchyOnly);
		auto pac_header = ph.visitPackage_declaration(pd);
		objs.push_back(std::move(pac_header));
		return;
	}
	auto pb = ctx->package_body();
	if (pb) {
		VhdlPackageParser pp(hierarchyOnly);
		auto p = pp.visitPackage_body(pb);
		objs.push_back(std::move(p));
		return;
	}
	auto pid = ctx->package_instantiation_declaration();
	if (pid) {
		NotImplementedLogger::print(
				"VhdlEntityParser.visitEntity_declarative_item - package_instantiation_declaration",
				pid);
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		auto t = VhdlTypeDeclarationParser::visitType_declaration(td);
		objs.push_back(std::move(t));
		return;
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = VhdlTypeDeclarationParser::visitSubtype_declaration(st);
		objs.push_back(std::move(_st));
		return;
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = VhdlConstantParser::visitConstant_declaration(constd);
		for (auto & c : *constants) {
			objs.push_back(std::move(c));
		}
		return;
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = VhdlSignalParser::visitSignal_declaration(sd);
		for (auto & s : *signals) {
			objs.push_back(std::move(s));
		}
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VhdlVariableParser::visitVariable_declaration(vd);
		for (auto & v : *variables) {
			objs.push_back(std::move(v));
		}
		return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print("VhdlEntityParser.visitFile_declaration", fd);
		return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print("VhdlEntityParser.visitAlias_declaration",
				aliasd);
		return;
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print("VhdlEntityParser.visitAttribute_declaration",
				atrd);
		return;
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print("VhdlEntityParser.visitAttribute_specification",
				as);
		return;
	}
	auto discs = ctx->disconnection_specification();
	if (discs) {
		NotImplementedLogger::print(
				"VhdlEntityParser.visitDisconnection_specification", discs);
		return;
	}
	auto uc = ctx->use_clause();
	if (uc) {
		HdlContext c;
		VhdlDesignFileParser dfp(commentParser.tokens, c, hierarchyOnly);
		dfp.visitUse_clause(uc, objs);
		assert(c.objs.size() == 0);
		return;
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"VhdlEntityParser.visitGroup_template_declaration", gtd);
		return;
	}
	auto gd = ctx->group_declaration();
	assert(gd);
	NotImplementedLogger::print("VhdlEntityParser.visitGroup_declaration", gd);
}
void VhdlEntityParser::visitGeneric_clause(
		vhdlParser::Generic_clauseContext *ctx,
		std::vector<std::unique_ptr<HdlIdDef>> &generics) {
	// generic_clause:
	//       GENERIC LPAREN generic_list RPAREN SEMI
	// ;
	// generic_list: interface_list;
	auto gl = ctx->generic_list();
	auto gs = VhdlInterfaceParser::visitInterface_list(gl->interface_list());
	for (auto &v : *gs) {
		assert(v);
		generics.push_back(std::move(v));
	}
}
void VhdlEntityParser::visitPort_clause(vhdlParser::Port_clauseContext *ctx,
		std::vector<std::unique_ptr<HdlIdDef>> &ports) {
	// port_clause:
	//       PORT LPAREN port_list RPAREN SEMI
	// ;
	// port_list: interface_list;
	auto pl = ctx->port_list();
	auto il = pl->interface_list();
	// interface_list:
	//       interface_element ( SEMI interface_element )*
	// ;

	for (auto ie : il->interface_element()) {
		auto ps = VhdlInterfaceParser::visitInterface_element(ie);
		for (auto &p : *ps) {
			ports.push_back(std::move(p));
		}
	}
}

}
}
