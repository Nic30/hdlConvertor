#include "archParser.h"
#include "notImplementedLogger.h"
#include "generateStatementParser.h"
#include "variableParser.h"
#include "subtypeDeclarationParser.h"
#include "subProgramDeclarationParser.h"
#include "constantParser.h"
#include "signalParser.h"
#include "processParser.h"
#include "compInstanceParser.h"
#include "entityParser.h"


using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace vhdl {


ArchParser::ArchParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
	a = new Arch();
}
Arch * ArchParser::visitArchitecture_body(
		vhdlParser::Architecture_bodyContext * ctx) {
	a = new Arch();
	// architecture_body
	// : ARCHITECTURE identifier OF identifier IS
	// architecture_declarative_part
	// BEGIN
	// architecture_statement_part
	// END ( ARCHITECTURE )? ( identifier )? SEMI
	// ;

	a->name = strdup(ctx->identifier(0)->getText().c_str());
	a->entityName = strdup(ctx->identifier(1)->getText().c_str());
	a->position = Position(ctx->getStart()->getLine(), ctx->getStop()->getLine(), -1, -1);
	if (!hierarchyOnly) {
		for (auto bi : ctx->architecture_declarative_part()->block_declarative_item()) {
			// architecture_declarative_part
			// : ( block_declarative_item )*
			// ;
			visitBlock_declarative_item(bi);
		}
	}
	for (auto s : ctx->architecture_statement_part()->architecture_statement()) {
		// architecture_statement_part
		// : ( architecture_statement )*
		// ;
		visitArchitecture_statement(s);
	}
	return a;
}

void ArchParser::visitBlock_declarative_item(
		vhdlParser::Block_declarative_itemContext * ctx) {
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
		a->function_headers.push_back(SubProgramDeclarationParser::visitSubprogram_declaration(sp));
		return;
	}
	auto sb = ctx->subprogram_body();
	if (sb) {
		// TODO: Implement
		//Function * f = SubProgramParser::visitSubprogram_body(sb);
		//a->functions.push_back(f);
		NotImplementedLogger::print(
				"ArchParser.visitSubprogram_body");
		return;
	}
	auto td = ctx->type_declaration();
	if (td) {
		NotImplementedLogger::print(
				"ArchParser.visitType_declaration");
		return;
	}
	auto st = ctx->subtype_declaration();
	if (st) {
		auto _st = SubtypeDeclarationParser::visitSubtype_declaration(st);
		a->subtype_headers.push_back(_st);
		return;
	}
	auto constd = ctx->constant_declaration();
	if (constd) {
		auto constants = ConstantParser::visitConstant_declaration(constd);
		for (auto c : *constants) {
			a->constants.push_back(c);
		}
		delete constants;
		return;
	}
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = SignalParser::visitSignal_declaration(sd);
		for (auto s : *signals) {
			a->signals.push_back(s);
		}
		delete signals;
		return;
	}
	auto vd = ctx->variable_declaration();
	if (vd) {
		auto variables = VariableParser::visitVariable_declaration(vd);
		for (auto v : *variables) {
			a->variables.push_back(v);
		}
		delete variables;
        return;
	}
	auto fd = ctx->file_declaration();
	if (fd) {
		NotImplementedLogger::print(
				"ArchParser.visitFile_declaration");
		return;
	}
	auto aliasd = ctx->alias_declaration();
	if (aliasd) {
		NotImplementedLogger::print(
				"ArchParser.visitAlias_declaration");
		return;
	}
	auto compd = ctx->component_declaration();
	if (compd) {
		a->components.push_back(visitComponent_declaration(compd));
		return;
	}
	auto atrd = ctx->attribute_declaration();
	if (atrd) {
		NotImplementedLogger::print(
				"ArchParser.visitAttribute_declaration");
		return;
	}
	auto as = ctx->attribute_specification();
	if (as) {
		NotImplementedLogger::print(
				"ArchParser.visitAttribute_specification");
		return;
	}
	auto discs = ctx->disconnection_specification();
	if (discs) {
		NotImplementedLogger::print(
				"ArchParser.visitDisconnection_specification");
		return;
	}
	auto uc = ctx->use_clause();
	if (uc) {
		NotImplementedLogger::print("ArchParser.visitUse_clause");
		return;
	}
	auto gtd = ctx->group_template_declaration();
	if (gtd) {
		NotImplementedLogger::print(
				"ArchParser.visitGroup_template_declaration");
		return;
	}
	auto gd = ctx->group_declaration();
	if (gd) {
		NotImplementedLogger::print(
				"ArchParser.visitGroup_declaration");
		return;
	}
	auto nd = ctx->nature_declaration();
	if (nd) {
		NotImplementedLogger::print(
				"ArchParser.visitNature_declaration");
		return;
	}
	auto snd = ctx->subnature_declaration();
	if (snd) {
		NotImplementedLogger::print(
				"ArchParser.visitSubnature_declaration");
		return;
	}
	auto tdc = ctx->terminal_declaration();
	if (tdc) {
		NotImplementedLogger::print(
				"ArchParser.visitTerminal_declaration");
		return;
	}
}
void ArchParser::visitArchitecture_statement(
		vhdlParser::Architecture_statementContext * ctx) {
	//architecture_statement
	//  : block_statement
	//  | process_statement
	//  | ( label_colon )? concurrent_procedure_call_statement
	//  | ( label_colon )? concurrent_assertion_statement
	//  | ( label_colon )? ( POSTPONED )? concurrent_signal_assignment_statement
	//  | component_instantiation_statement
	//  | generate_statement
	//  | concurrent_break_statement
	//  | simultaneous_statement
	//  ;
	// [TODO]

	auto b = ctx->block_statement();
	if (b) {
		NotImplementedLogger::print(
				"ArchParser.visitBlock_statement");
		return;
	}
	auto p = ctx->process_statement();
	if (p) {
		a->processes.push_back(
				ProcessParser::visitProcess_statement(p));
		return;
	}
	auto ci = ctx->component_instantiation_statement();
	if (ci) {
		a->componentInstances.push_back(
				CompInstanceParser::visitComponent_instantiation_statement(ci));
		return;
	}

	auto gs = ctx->generate_statement();
	if (gs) {
		a->generates.push_back(
			GenerateStatementParser::visitGenerate_statement(gs));
		return;
	}
	NotImplementedLogger::print(
					"ArchParser.visitArchitecture_statement - unspecified next rule");
}
Entity * ArchParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext* ctx) {
	// component_declaration
	// : COMPONENT identifier ( IS )?
	// ( generic_clause )?
	// ( port_clause )?
	// END COMPONENT ( identifier )? SEMI
	// ;
	Entity * e = new Entity();
	e->name = strdup(ctx->identifier(0)->getText().c_str());
	if (!hierarchyOnly) {
		EntityParser::visitGeneric_clause(ctx->generic_clause(), &e->generics);
		EntityParser::visitPort_clause(ctx->port_clause(), &e->ports);
	}
	return e;
}

}
}
