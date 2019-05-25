#include "processParser.h"
#include "statementParser.h"
#include "constantParser.h"
#include "variableParser.h"
#include "literalParser.h"
#include "subtypeDeclarationParser.h"
#include "notImplementedLogger.h"
#include "referenceParser.h"
#include "subProgramDeclarationParser.h"

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

Process * ProcessParser::visitProcess_statement(
		vhdlParser::Process_statementContext * ctx) {
        //process_statement
        //  : ( label_colon )? ( POSTPONED )? PROCESS
        //    ( LPAREN sensitivity_list RPAREN )? ( IS )?
        //    process_declarative_part
        //    BEGIN
        //    process_statement_part
        //    END ( POSTPONED )? PROCESS ( identifier )? SEMI
        //  ;

    Process * p = new Process();
	p->position = Position(ctx->getStart()->getLine(), ctx->getStop()->getLine(), -1, -1);
    if (ctx->label_colon()) {
        p->name = visitLabel_colon(ctx->label_colon());
    }

	if (ctx->sensitivity_list()) {
		auto sensList = visitSensitivity_list(ctx->sensitivity_list());
		for (auto sl : *sensList) {
			if (sl) {
    			p->sensitivity_list.push_back(sl);
			}
		}
		p->sensitivity_list_specified = true;
	}

    visitProcess_declarative_part(ctx->process_declarative_part(), p);

	auto statParts = visitProcess_statement_part(ctx->process_statement_part());
	for (auto sp : *statParts) {
		if (sp) {
			p->statements.push_back(sp);
		}
	}

    return p;
}

char * ProcessParser::visitLabel_colon(
		vhdlParser::Label_colonContext * ctx) {
	// label_colon
	// : identifier COLON
	// ;
	Expr * e = LiteralParser::visitIdentifier(ctx->identifier());
	char * s = strdup(dynamic_cast<Symbol*>(e->data)->value._str);
	delete e;
	return s;
}

std::vector<Expr*> * ProcessParser::visitSensitivity_list (
        vhdlParser::Sensitivity_listContext *ctx) {
    //sensitivity_list
    //  : name ( COMMA name )*
    //  | ALL
    //  ;
    std::vector<Expr*> * sensitivity = new std::vector<Expr*>();
    if (ctx->ALL()) {
        sensitivity->push_back(Expr::all());
    } else {
        for (auto n : ctx->name()) {
            sensitivity->push_back(ReferenceParser::visitName(n));
        }
    }
    return sensitivity;
}

void ProcessParser::visitProcess_declarative_part (
        vhdlParser::Process_declarative_partContext *ctx, Process * p) {
    //process_declarative_part
    //  : ( process_declarative_item )*
    //  ;
	for (auto pd : ctx->process_declarative_item()) {
        visitProcess_declarative_item(pd, p);
	}
}

void ProcessParser::visitProcess_declarative_item (
        vhdlParser::Process_declarative_itemContext *ctx, Process * p) {
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
		p->function_headers.push_back(SubProgramDeclarationParser::visitSubprogram_declaration(sp));
        return;
	}
    auto sb = ctx->subprogram_body();
	if (sb) {
		// TODO: Implement
		//Function * f = SubProgramParser::visitSubprogram_body(sb);
		//p->functions.push_back(f);
		return;
	}
    auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"ProcessParser.visitType_declaration");
        return;
	}
    auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = SubtypeDeclarationParser::visitSubtype_declaration(st);
		p->subtype_headers.push_back(_st);
		return;
	}
    auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = ConstantParser::visitConstant_declaration(constd);
		for (auto c : *constants) {
			p->constants.push_back(c);
		}
		delete constants;
        return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VariableParser::visitVariable_declaration(vd);
		for (auto v : *variables) {
			p->variables.push_back(v);
		}
		delete variables;
        return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print(
				"ProcessParser.visitFile_declaration");
        return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print(
				"ProcessParser.visitAlias_declaration");
        return;
	}
    auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print(
				"ProcessParser.visitAttribute_declaration");
        return;
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print(
				"ProcessParser.visitAttribute_specification");
        return;
	}
    auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("ProcessParser.visitUse_clause");
        return;
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"ProcessParser.visitGroup_template_declaration");
        return;
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print(
				"ProcessParser.visitGroup_declaration");
        return;
	}
	NotImplementedLogger::print(
			"ProcessParser.visitProcess_declarative_item");
	return;
}

std::vector<Statement *> * ProcessParser::visitProcess_statement_part(
		vhdlParser::Process_statement_partContext *ctx) {
    //process_statement_part
    //  : ( sequential_statement )*
    //  ;
	std::vector<Statement *> * statements = new std::vector<Statement*>();
	for (auto s : ctx->sequential_statement()) {
		statements->push_back(StatementParser::visitSequential_statement(s));
	}
	return statements;
}

}
}



