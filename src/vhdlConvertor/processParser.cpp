#include <hdlConvertor/vhdlConvertor/processParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/subtypeDeclarationParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

HdlStmProcess * ProcessParser::visitProcess_statement(
		vhdlParser::Process_statementContext * ctx) {
	// process_statement:
	//       ( label COLON )?
	//           ( POSTPONED )? PROCESS ( LPAREN process_sensitivity_list RPAREN )? ( IS )?
	//               process_declarative_part
	//           BEGIN
	//               process_statement_part
	//           END ( POSTPONED )? PROCESS ( label )? SEMI
	// ;
	auto p = new HdlStmProcess();
	p->position.update_from_elem(ctx);
	if (ctx->label(0)) {
		auto l = LiteralParser::visitLabel(ctx->label(0));
		p->labels.push_back(l);
	}
	auto sl = ctx->process_sensitivity_list();
	if (sl) {
		visitProcess_sensitivity_list(sl, p->sensitivity_list());
		p->sensitivity_list_specified = true;
	}

	visitProcess_declarative_part(ctx->process_declarative_part(), p);

	auto statParts = visitProcess_statement_part(ctx->process_statement_part());
	for (auto sp : *statParts) {
		if (sp) {
			p->objs().push_back(sp);
		}
	}

	return p;
}
void ProcessParser::visitProcess_sensitivity_list(
		vhdlParser::Process_sensitivity_listContext *ctx,
		std::vector<iHdlExpr*> & sensitivity) {
	// process_sensitivity_list: ALL | sensitivity_list;
	if (ctx->ALL()) {
		sensitivity.push_back(iHdlExpr::all());
	} else {
		visitSensitivity_list(ctx->sensitivity_list(), sensitivity);
	}
}

void ProcessParser::visitSensitivity_list(
		vhdlParser::Sensitivity_listContext *ctx,
		std::vector<iHdlExpr*> & sensitivity) {
	// sensitivity_list: name ( COMMA name )*;
	for (auto n : ctx->name()) {
		sensitivity.push_back(ReferenceParser::visitName(n));
	}
}

void ProcessParser::visitProcess_declarative_part(
		vhdlParser::Process_declarative_partContext *ctx, HdlStmProcess * p) {
	//process_declarative_part
	//  : ( process_declarative_item )*
	//  ;
	for (auto pd : ctx->process_declarative_item()) {
		visitProcess_declarative_item(pd, p);
	}
}

void ProcessParser::visitProcess_declarative_item(
		vhdlParser::Process_declarative_itemContext *ctx, HdlStmProcess * p) {
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
		p->objs().push_back(
				SubProgramDeclarationParser::visitSubprogram_declaration(sp));
		return;
	}
	auto sb = ctx->subprogram_body();
	if (sb) {
		auto f = SubProgramParser::visitSubprogram_body(sb);
		p->objs().push_back(f);
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print("ProcessParser.visitType_declaration", td);
		return;
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = SubtypeDeclarationParser::visitSubtype_declaration(st);
		p->objs().push_back(_st);
		return;
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = ConstantParser::visitConstant_declaration(constd);
		for (auto c : *constants) {
			p->objs().push_back(c);
		}
		delete constants;
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VariableParser::visitVariable_declaration(vd);
		for (auto v : *variables) {
			p->objs().push_back(v);
		}
		delete variables;
		return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print("ProcessParser.visitFile_declaration", fd);
		return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print("ProcessParser.visitAlias_declaration", aliasd);
		return;
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print("ProcessParser.visitAttribute_declaration", atrd);
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
	NotImplementedLogger::print("ProcessParser.visitProcess_declarative_item", ctx);
	return;
}

std::vector<iHdlStatement *> * ProcessParser::visitProcess_statement_part(
		vhdlParser::Process_statement_partContext *ctx) {
	//process_statement_part
	//  : ( sequential_statement )*
	//  ;
	std::vector<iHdlStatement *> * statements = new std::vector<iHdlStatement*>();
	for (auto s : ctx->sequential_statement()) {
		statements->push_back(StatementParser::visitSequential_statement(s));
	}
	return statements;
}

}
}

