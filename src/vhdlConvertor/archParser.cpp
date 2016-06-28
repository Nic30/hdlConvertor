#include "archParser.h"

ArchParser::ArchParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
	a = new Arch();
}
Arch * ArchParser::visitArchitecture_body(
		Ref<vhdlParser::Architecture_bodyContext> ctx) {
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
		Ref<vhdlParser::Block_declarative_itemContext> ctx) {
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
	NotImplementedLogger::print(
			"ArchParser.visitArchitecture_declarative_part");
}
void ArchParser::visitArchitecture_statement(
		Ref<vhdlParser::Architecture_statementContext> ctx) {
	// architecture_statement
	// : block_statement
	// | process_statement
	// | ( label_colon )? concurrent_procedure_call_statement
	// | ( label_colon )? concurrent_assertion_statement
	// | ( label_colon )? ( POSTPONED )?
	// concurrent_signal_assignment_statement
	// | component_instantiation_statement
	// | generate_statement
	// | concurrent_break_statement
	// | simultaneous_statement
	// ;
	// [TODO]
	auto ci = ctx->component_instantiation_statement();
	if (ci) {
		a->componentInstances.push_back(
				CompInstanceParser::visitComponent_instantiation_statement(ci));
	} else {
		if (!hierarchyOnly) {
			NotImplementedLogger::print(
					"ArchParser.visitArchitecture_statement - unspecified next rule");
		}
	}
}
