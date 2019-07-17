#include <hdlConvertor/vhdlConvertor/entityParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlObjects;

EntityParser::EntityParser(CommentParser & _commentParser, bool _hierarchyOnly) :
		commentParser(_commentParser), hierarchyOnly(_hierarchyOnly) {
}
HdlModuleDec * EntityParser::visitEntity_declaration(
		vhdlParser::Entity_declarationContext* ctx) {
	// entity_declaration:
	//       ENTITY identifier IS
	//           entity_header
	//           entity_declarative_part
	//       ( BEGIN
	//           entity_statement_part )?
	//       END ( ENTITY )? ( simple_name )? SEMI
	// ;

	HdlModuleDec * e = new HdlModuleDec();
	e->name = ctx->identifier()->getText();
	e->__doc__ = commentParser.parse(ctx);
	// entity_declarative_part
	// : ( entity_declarative_item )*
	// ;
	if (!hierarchyOnly) {
		auto h = ctx->entity_header();
		if (h)
			visitEntity_header(e, h);
		auto edp = ctx->entity_declarative_part();
		if (edp)
			for (auto d : edp->entity_declarative_item()) {
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

	NotImplementedLogger::print("EntityParser.visitEntity_declarative_item", ctx);
}
void EntityParser::visitGeneric_clause(vhdlParser::Generic_clauseContext* ctx,
		std::vector<HdlVariableDef*> * generics) {
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
void EntityParser::visitPort_clause(vhdlParser::Port_clauseContext* ctx,
		std::vector<HdlVariableDef*> * ports) {
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
		for (HdlVariableDef * p : *ps) {
			p->position.update_from_elem(ie);
			ports->push_back(p);
		}
		delete ps;
	}
}
void EntityParser::visitEntity_header(HdlModuleDec * e,
		vhdlParser::Entity_headerContext* ctx) {
	// entity_header:
	//       ( generic_clause )?
	//       ( port_clause )?
	// ;
	auto g = ctx->generic_clause();
	if (g)
		visitGeneric_clause(g, &e->generics);
	auto pc = ctx->port_clause();
	if (pc)
		visitPort_clause(pc, &e->ports);
}
void EntityParser::visitEntity_statement_part(
		vhdlParser::Entity_statement_partContext* ctx) {
	if (!ctx)
		return;
	// entity_statement_part
	// : ( entity_statement )*
	// ;
	NotImplementedLogger::print("EntityParser.visitEntity_statement_part", ctx);
}

}
}
