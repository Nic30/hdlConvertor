#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

std::unique_ptr<hdlObjects::HdlStmProcess> VhdlProcessParser::visitProcess_statement(
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
				std::vector<std::unique_ptr<iHdlExpr>>>();
		visitProcess_sensitivity_list(sl, *p->sensitivity_list);
	}
	for (auto pd : ctx->process_declarative_item()) {
		visitProcess_declarative_item(pd, stms);
	}
	for (auto s : ctx->sequential_statement()) {
		stms.push_back(VhdlStatementParser::visitSequential_statement(s));
	}

	return p;
}
void VhdlProcessParser::visitProcess_sensitivity_list(
		vhdlParser::Process_sensitivity_listContext *ctx,
		std::vector<std::unique_ptr<iHdlExpr>> &sensitivity) {
	// process_sensitivity_list: ALL | sensitivity_list;
	if (ctx->KW_ALL()) {
		sensitivity.push_back(iHdlExpr::all());
	} else {
		visitSensitivity_list(ctx->sensitivity_list(), sensitivity);
	}
}

void VhdlProcessParser::visitSensitivity_list(
		vhdlParser::Sensitivity_listContext *ctx,
		std::vector<std::unique_ptr<iHdlExpr>> &sensitivity) {
	// sensitivity_list: name ( COMMA name )*;
	for (auto n : ctx->name()) {
		sensitivity.push_back(VhdlReferenceParser::visitName(n));
	}
}

void VhdlProcessParser::visitProcess_declarative_item(
		vhdlParser::Process_declarative_itemContext *ctx,
		std::vector<std::unique_ptr<iHdlObj>> &objs) {
	//process_declarative_item
	//  : subprogram_declaration
	//  | subprogram_body
	//  | type_declaration
	//  | subtype_declaration
	//  | constant_declaration
	//  | variable_declaration
	//  | file_declaration
	//  | alias_declaration
	//  | attribute_declaration
	//  | attribute_specification
	//  | use_clause
	//  | group_template_declaration
	//  | group_declaration
	//  ;
	auto sp = ctx->subprogram_declaration();
	if (sp) {
		objs.push_back(
				VhdlSubProgramDeclarationParser::visitSubprogram_declaration(
						sp));
		return;
	}
	auto sb = ctx->subprogram_body();
	if (sb) {
		auto f = VhdlSubProgramParser::visitSubprogram_body(sb);
		objs.push_back(std::move(f));
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print("ProcessParser.visitType_declaration", td);
		return;
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = VhdlSubtypeDeclarationParser::visitSubtype_declaration(st);
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
		NotImplementedLogger::print("ProcessParser.visitFile_declaration", fd);
		return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print("ProcessParser.visitAlias_declaration",
				aliasd);
		return;
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print("ProcessParser.visitAttribute_declaration",
				atrd);
		return;
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print(
				"ProcessParser.visitAttribute_specification", as);
		return;
	}
	auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("ProcessParser.visitUse_clause", uc);
		return;
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"ProcessParser.visitGroup_template_declaration", gtd);
		return;
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print("ProcessParser.visitGroup_declaration", gd);
		return;
	}
	NotImplementedLogger::print("ProcessParser.visitProcess_declarative_item",
			ctx);
	return;
}

}
}

