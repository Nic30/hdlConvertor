#include "entityParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/expr.h"
#include "interfaceParser.h"

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlObjects;

EntityParser::EntityParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
}
Entity * EntityParser::visitEntity_declaration(
		vhdlParser::Entity_declarationContext* ctx) {
	// entity_declaration:
	//       ENTITY identifier IS
	//           entity_header
	//           entity_declarative_part
	//       ( BEGIN
	//           entity_statement_part )?
	//       END ( ENTITY )? ( simple_name )? SEMI
	// ;

	Entity * e = new Entity();
	e->name = strdup(ctx->identifier()->getText().c_str());
	// entity_declarative_part
	// : ( entity_declarative_item )*
	// ;
	if (!hierarchyOnly) {
		visitEntity_header(e, ctx->entity_header());
		for (auto d : ctx->entity_declarative_part()->entity_declarative_item()) {
			visitEntity_declarative_item(d);
		}
	}
	e->position.update_from_elem(ctx);
	return e;
}

void EntityParser::visitEntity_declarative_item(
		vhdlParser::Entity_declarative_itemContext* ctx) {
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
void EntityParser::visitGeneric_clause(vhdlParser::Generic_clauseContext* ctx,
		std::vector<Variable*> * generics) {
	if (ctx) {
		// generic_clause:
		//       GENERIC LPAREN generic_list RPAREN SEMI
		// ;
		// generic_list: interface_list;
		auto gl = ctx->generic_list();
		auto gs = InterfaceParser::visitInterface_list(gl->interface_list());
		for (auto v : *gs) {
			assert(v);
			generics->push_back(v);
		}
		delete gs;
	}
}
void EntityParser::visitPort_clause(vhdlParser::Port_clauseContext* ctx,
		std::vector<Variable*> * ports) {
	if (ctx) {
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
			auto ps = InterfaceParser::visitInterface_element(ie);
			for (Variable * p : *ps) {
				p->position.update_from_elem(ie);
				ports->push_back(p);
			}
			delete ps;
		}
	}
}
void EntityParser::visitEntity_header(Entity * e,
		vhdlParser::Entity_headerContext* ctx) {
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
		vhdlParser::Entity_statement_partContext* ctx) {
	if (!ctx)
		return;
// entity_statement_part
// : ( entity_statement )*
// ;
	NotImplementedLogger::print("EntityParser.visitEntity_statement_part");
}

}
}
