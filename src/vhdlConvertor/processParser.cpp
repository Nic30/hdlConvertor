#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>
#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/designFileParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlAst;
using vhdlParser = vhdl_antlr::vhdlParser;

std::unique_ptr<hdlAst::HdlStmProcess> VhdlProcessParser::visitProcess_statement(
		vhdlParser::Process_statementContext *ctx) {
	// process_statement:
	//           ( KW_POSTPONED )? KW_PROCESS ( LPAREN process_sensitivity_list RPAREN )? ( KW_IS )?
	//               ( process_declarative_item )*
	//           KW_BEGIN
	//               ( sequential_statement )*
	//           KW_END ( KW_POSTPONED )? KW_PROCESS ( label )? SEMI
	// ;
	auto p = create_object<HdlStmProcess>(ctx);
	auto &stms = dynamic_cast<HdlStmBlock*>(p->body.get())->statements;
	auto sl = ctx->process_sensitivity_list();
	if (sl) {
		p->sensitivity_list = std::make_unique<
				std::vector<std::unique_ptr<iHdlExprItem>>>();
		visitProcess_sensitivity_list(sl, *p->sensitivity_list);
	}
	for (auto pd : ctx->process_declarative_item()) {
		visitProcess_declarative_item(pd, stms);
	}
	VhdlStatementParser sp(commentParser, hierarchyOnly);
	for (auto s : ctx->sequential_statement()) {
		stms.push_back(sp.visitSequential_statement(s));
	}

	return p;
}
void VhdlProcessParser::visitProcess_sensitivity_list(
		vhdlParser::Process_sensitivity_listContext *ctx,
		std::vector<std::unique_ptr<iHdlExprItem>> &sensitivity) {
	// process_sensitivity_list: ALL | sensitivity_list;
	if (ctx->KW_ALL()) {
		sensitivity.push_back(HdlValueSymbol::all());
	} else {
		visitSensitivity_list(ctx->sensitivity_list(), sensitivity);
	}
}

void VhdlProcessParser::visitSensitivity_list(
		vhdlParser::Sensitivity_listContext *ctx,
		std::vector<std::unique_ptr<iHdlExprItem>> &sensitivity) {
	// sensitivity_list: name ( COMMA name )*;
	for (auto n : ctx->name()) {
		sensitivity.push_back(VhdlReferenceParser::visitName(n));
	}
}
void VhdlProcessParser::visitProcess_declarative_item(
		vhdlParser::Process_declarative_itemContext *ctx,
		std::vector<std::unique_ptr<iHdlObj>> &objs) {
	// process_declarative_item:
	//       process_or_package_declarative_item
	//       | subprogram_body
	//       | package_body
	// ;
	auto ppdi = ctx->process_or_package_declarative_item();
	if (ppdi) {
		visitProcess_or_package_declarative_item(ppdi, objs);
		return;
	}
	auto sb = ctx->subprogram_body();
	if (sb) {
		VhdlSubProgramParser spp(commentParser, hierarchyOnly);
		auto f = spp.visitSubprogram_body(sb);
		objs.push_back(std::move(f));
		return;
	}
	auto pb = ctx->package_body();
	assert(pb);
	VhdlPackageParser pp(commentParser, hierarchyOnly);
	auto p = pp.visitPackage_body(pb);
	objs.push_back(std::move(p));
}

void VhdlProcessParser::visitProcess_or_package_declarative_item(
		vhdlParser::Process_or_package_declarative_itemContext *ctx,
		std::vector<std::unique_ptr<iHdlObj>> &objs) {
	// process_or_package_declarative_item:
	//       subprogram_declaration
	//       | subprogram_instantiation_declaration
	//       | package_declaration
	//       | package_instantiation_declaration
	//       | type_declaration
	//       | subtype_declaration
	//       | constant_declaration
	//       | variable_declaration
	//       | file_declaration
	//       | alias_declaration
	//       | attribute_declaration
	//       | attribute_specification
	//       | use_clause
	//       | group_template_declaration
	//       | group_declaration
	// ;
	auto sp = ctx->subprogram_declaration();
	if (sp) {
		objs.push_back(
				VhdlSubProgramDeclarationParser::visitSubprogram_declaration(
						sp));
		return;
	}
	auto sid = ctx->subprogram_instantiation_declaration();
	if (sid) {
		NotImplementedLogger::print(
				"VhdlProcessParser.visitSubprogram_instantiation_declaration",
				sid);
		return;
	}
	auto pd = ctx->package_declaration();
	if (pd) {
		VhdlPackageHeaderParser ph(commentParser, hierarchyOnly);
		auto pac_header = ph.visitPackage_declaration(pd);
		objs.push_back(std::move(pac_header));
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
		for (auto &c : *constants) {
			objs.push_back(std::move(c));
		}
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VhdlVariableParser::visitVariable_declaration(vd);
		for (auto &v : *variables) {
			objs.push_back(std::move(v));
		}
		return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print("VhdlProcessParser.visitFile_declaration",
				fd);
		return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print("VhdlProcessParser.visitAlias_declaration",
				aliasd);
		return;
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print(
				"VhdlProcessParser.visitAttribute_declaration", atrd);
		return;
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print(
				"VhdlProcessParser.visitAttribute_specification", as);
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
				"VhdlProcessParser.visitGroup_template_declaration", gtd);
		return;
	}
	auto gd = ctx->group_declaration();
	assert(gd);
	NotImplementedLogger::print("VhdlProcessParser.visitGroup_declaration", gd);
	return;
}

}
}

