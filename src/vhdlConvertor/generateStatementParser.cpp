#include "generateStatementParser.h"

#include "compInstanceParser.h"
#include "constantParser.h"
#include "entityParser.h"
#include "exprParser.h"
#include "interfaceParser.h"
#include "literalParser.h"
#include "referenceParser.h"
#include "referenceParser.h"
#include "signalParser.h"
#include "statementParser.h"
#include "subProgramDeclarationParser.h"
#include "subProgramParser.h"
#include "subtypeDeclarationParser.h"
#include "variableParser.h"
#include "notImplementedLogger.h"
#include "processParser.h"

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

Generate * GenerateStatementParser::visitGenerate_statement(
		vhdlParser::Generate_statementContext *ctx) {
	//generate_statement
	//  : for_generate_statement
	//  | if_generate_statement
	//  | case_generate_statement
	//  ;

	auto fgs = ctx->for_generate_statement();
	if (fgs) {
		return visitFor_generate_statement(fgs);
	}

	auto ifs = ctx->if_generate_statement();
	if (ifs) {
		return visitIf_generate_statement(ifs);
	}

	auto cgs = ctx->case_generate_statement();
	assert(cgs);
	return visitCase_generate_statement(cgs);

}

Generate * GenerateStatementParser::visitFor_generate_statement(
		vhdlParser::For_generate_statementContext *ctx) {
	//for_generate_statement
	//  : label_colon FOR parameter_specification
	//    GENERATE
	//    generate_statement_body
	//    END GENERATE ( identifier )? SEMI
	//  ;

	Generate * g = new Generate();
	g->position.startLine = ctx->getStart()->getLine();
	g->position.startColumn = ctx->getStop()->getLine();
	g->type = g_FOR;

	g->name = visitLabel_colon(ctx->label_colon());
	visitGenerate_statement_body(ctx->generate_statement_body(), g);

	return g;
}

Generate * GenerateStatementParser::visitIf_generate_statement(
		vhdlParser::If_generate_statementContext *ctx) {
	//if_generate_statement
	//  : ( label_colon )? IF condition GENERATE
	//    generate_statement_body
	//    ( ELSIF condition GENERATE generate_statement_body )*
	//    ( ELSE GENERATE generate_statement_body)?
	//    END GENERATE ( identifier )? SEMI
	//  ;

	Generate * g = new Generate();
	g->position.startLine = ctx->getStart()->getLine();
	g->position.startColumn = ctx->getStop()->getLine();
	g->type = g_IF;

	if (ctx->label_colon()) {
		g->name = visitLabel_colon(ctx->label_colon());
	}

	for (auto gbs : ctx->generate_statement_body()) {
		visitGenerate_statement_body(gbs, g);
	}

	return g;

}

Generate * GenerateStatementParser::visitCase_generate_statement(
		vhdlParser::Case_generate_statementContext *ctx) {
	//case_generate_statement
	//  : ( label_colon )? CASE expression GENERATE
	//    ( case_generate_alternative )+
	//    END GENERATE ( identifier )? SEMI
	//  ;

	Generate * g = new Generate();
	g->position = Position(ctx->getStart()->getLine(), ctx->getStop()->getLine(), -1, -1);
	g->type = g_CASE;

	if (ctx->label_colon()) {
		g->name = visitLabel_colon(ctx->label_colon());
	}

	for (auto cga : ctx->case_generate_alternative()) {
		visitCase_generate_alternative(cga, g);
	}

	return g;
}

char * GenerateStatementParser::visitLabel_colon(
		vhdlParser::Label_colonContext * ctx) {
	// label_colon
	// : identifier COLON
	// ;
	Expr * e = LiteralParser::visitIdentifier(ctx->identifier());
	char * s = strdup(dynamic_cast<Symbol*>(e->data)->value._str);
	delete e;
	return s;
}

void GenerateStatementParser::visitCase_generate_alternative(
		vhdlParser::Case_generate_alternativeContext *ctx, Generate * g) {
	//case_generate_alternative
	//  : WHEN choices ARROW generate_statement_body
	//  ;

	visitGenerate_statement_body(ctx->generate_statement_body(), g);

}

void GenerateStatementParser::visitGenerate_statement_body(
		vhdlParser::Generate_statement_bodyContext *ctx, Generate * g) {
	//generate_statement_body
	//  : ( ( block_declarative_item )* BEGIN )?
	//    ( architecture_statement )*
	//  ;
	for (auto bi : ctx->block_declarative_item()) {
		// architecture_declarative_part
		// : ( block_declarative_item )*
		// ;
		visitBlock_declarative_item(bi, g);
	}

	for (auto as : ctx->architecture_statement()) {
		visitArchitecture_statement(as, g);
	}

}

void GenerateStatementParser::visitBlock_declarative_item(
		vhdlParser::Block_declarative_itemContext * ctx, Generate * g) {
	// block_declarative_item
	// : subprogram_declaration
	// | subprogram_body
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
	// | configuration_specification
	// | disconnection_specification
	// | step_limit_specification
	// | use_clause
	// | group_template_declaration
	// | group_declaration
	// | nature_declaration
	// | subnature_declaration
	// | quantity_declaration
	// | terminal_declaration
	// ;
	auto sp = ctx->subprogram_declaration();
	if (sp) {
		g->function_headers.push_back(
				SubProgramDeclarationParser::visitSubprogram_declaration(sp));
		return;
	}
	auto sb = ctx->subprogram_body();
	if (sb) {
		// TODO: Implement
		//Function * f = SubProgramParser::visitSubprogram_body(sb);
		//a->functions.push_back(f);
		NotImplementedLogger::print(
				"GenerateStatementParser.visitSubprogram_body");
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitType_declaration");
		return;
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = SubtypeDeclarationParser::visitSubtype_declaration(st);
		g->subtype_headers.push_back(_st);
		return;
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = ConstantParser::visitConstant_declaration(constd);
		for (auto c : *constants) {
			g->constants.push_back(c);
		}
		delete constants;
		return;
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = SignalParser::visitSignal_declaration(sd);
		for (auto s : *signals) {
			g->signals.push_back(s);
		}
		delete signals;
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VariableParser::visitVariable_declaration(vd);
		for (auto v : *variables) {
			g->variables.push_back(v);
		}
		delete variables;
		return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitFile_declaration");
		return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitAlias_declaration");
		return;
	}
	auto compd = ctx->component_declaration();
	if (compd) {
		g->components.push_back(visitComponent_declaration(compd));
		return;
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitAttribute_declaration");
		return;
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitAttribute_specification");
		return;
	}
	auto discs = ctx->disconnection_specification();
	if (discs) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitDisconnection_specification");
		return;
	}
	auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("GenerateStatementParser.visitUse_clause");
		return;
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitGroup_template_declaration");
		return;
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitGroup_declaration");
		return;
	}
	auto nd = ctx->nature_declaration();
	if (nd) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitNature_declaration");
		return;
	}
	auto snd = ctx->subnature_declaration();
	if (snd) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitSubnature_declaration");
		return;
	}
	auto tdc = ctx->terminal_declaration();
	if (tdc) {
		NotImplementedLogger::print(
				"GenerateStatementParser.visitTerminal_declaration");
		return;
	}
}

void GenerateStatementParser::visitArchitecture_statement(
		vhdlParser::Architecture_statementContext * ctx, Generate * g) {
	// architecture_statement
	// : block_statement
	// | process_statement
	// | ( label_colon )? concurrent_procedure_call_statement
	// | ( label_colon )? concurrent_assertion_statement
	// | ( label_colon )? ( POSTPONED )? concurrent_signal_assignment_statement
	// | component_instantiation_statement
	// | generate_statement
	// | concurrent_break_statement
	// | simultaneous_statement
	// ;

	auto b = ctx->block_statement();
	if (b) {
		NotImplementedLogger::print("ArchParser.visitBlock_statement");
		return;
	}
	auto p = ctx->process_statement();
	if (p) {
		g->processes.push_back(ProcessParser::visitProcess_statement(p));
		return;
	}
	auto ci = ctx->component_instantiation_statement();
	if (ci) {
		g->componentInstances.push_back(
				CompInstanceParser::visitComponent_instantiation_statement(ci));
		return;
	}

	auto gs = ctx->generate_statement();
	if (gs) {
		g->generates.push_back(visitGenerate_statement(gs));
		return;
	}

}
Entity * GenerateStatementParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext* ctx) {
	// component_declaration
	// : COMPONENT identifier ( IS )?
	// ( generic_clause )?
	// ( port_clause )?
	// END COMPONENT ( identifier )? SEMI
	// ;
	Entity * e = new Entity();
	e->name = strdup(ctx->identifier(0)->getText().c_str());
	EntityParser::visitGeneric_clause(ctx->generic_clause(), &e->generics);
	EntityParser::visitPort_clause(ctx->port_clause(), &e->ports);

	return e;
}

}
}
