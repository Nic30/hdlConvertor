#include "entityParser.h"

EntityParser::EntityParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
}
Entity * EntityParser::visitEntity_declaration(
		Ref<vhdlParser::Entity_declarationContext> ctx) {

	// entity_declaration
	// : ENTITY identifier IS entity_header
	// entity_declarative_part
	// ( BEGIN entity_statement_part )?
	// END ( ENTITY )? ( identifier )? SEMI
	// ;
	Entity * e = new Entity();
	e->name = strdup(ctx->identifier(0)->getText().c_str());
	// entity_declarative_part
	// : ( entity_declarative_item )*
	// ;
	if (!hierarchyOnly) {
		visitEntity_header(e, ctx->entity_header());
		for (auto d : ctx->entity_declarative_part()->entity_declarative_item()) {
			visitEntity_declarative_item(d);
		}
	}
	return e;
}

void EntityParser::visitEntity_declarative_item(
		Ref<vhdlParser::Entity_declarative_itemContext> ctx) {
	// entity_declarative_item
	// : subprogram_declaration
	// | subprogram_body
	// | type_declaration
	// | subtype_declaration
	// | constant_declaration
	// | signal_declaration
	// | variable_declaration
	// | file_declaration
	// | alias_declaration
	// | attribute_declaration
	// | attribute_specification
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

	NotImplementedLogger::print("EntityParser.visitEntity_declarative_item");
}
void EntityParser::visitGeneric_clause(
		Ref<vhdlParser::Generic_clauseContext> ctx,
		std::vector<Variable*> * generics) {
	if (ctx) {
		// generic_clause
		// : GENERIC LPAREN generic_list RPAREN SEMI
		// ;
		// generic_list
		// : interface_constant_declaration (SEMI
		// interface_constant_declaration)*
		// ;
		auto gl = ctx->generic_list();
		for (auto ic : gl->interface_constant_declaration()) {
			std::vector<Variable*> * vl =
					InterfaceParser::visitInterface_constant_declaration(ic);
			for (auto v : *vl){
				assert(v);
				generics->push_back(v);
			}
			delete vl;
		}
	}
}
void EntityParser::visitPort_clause(
		Ref<vhdlParser::Port_clauseContext> ctx,
		std::vector<Port*> * ports) {
	if (ctx) {
		// port_clause
		// : PORT LPAREN port_list RPAREN SEMI
		// ;
		// port_list
		// : interface_port_list
		// ;
		auto pl = ctx->port_list();
		auto ipl = pl->interface_port_list();
		// interface_port_list
		// : interface_port_declaration ( SEMI interface_port_declaration )*
		// ;

		for (auto ipd : ipl->interface_port_declaration()) {
			auto ps = InterfaceParser::visitInterface_port_declaration(ipd);
			for (Port * p : *ps)
				ports->push_back(p);
			delete ps;
		}
	}
}
void EntityParser::visitEntity_header(
		Entity * e,
		Ref<vhdlParser::Entity_headerContext> ctx) {
// entity_header
// : ( generic_clause )?
// ( port_clause )?
// ;
//
	auto g = ctx->generic_clause();
	visitGeneric_clause(g, &e->generics);
	auto pc = ctx->port_clause();
	visitPort_clause(pc, &e->ports);
}
void EntityParser::visitEntity_statement_part(
		Ref<vhdlParser::Entity_statement_partContext> ctx) {
	if (!ctx)
		return;
// entity_statement_part
// : ( entity_statement )*
// ;
	NotImplementedLogger::print("EntityParser.visitEntity_statement_part");
}
