#include <hdlConvertor/vhdlConvertor/entityParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlObjects;

EntityParser::EntityParser(CommentParser &_commentParser, bool _hierarchyOnly) :
		commentParser(_commentParser), hierarchyOnly(_hierarchyOnly) {
}
HdlModuleDec* EntityParser::visitEntity_declaration(
		vhdlParser::Entity_declarationContext *ctx) {
	// entity_declaration:
	//       KW_ENTITY identifier KW_IS
	//           ( generic_clause )?
	//           ( port_clause )?
	//           ( entity_declarative_item )*
	//       ( KW_BEGIN ( entity_statement )* )?
	//       KW_END ( KW_ENTITY )? ( simple_name )? SEMI
	// ;
	HdlModuleDec *e = new HdlModuleDec();
	e->name = ctx->identifier()->getText();
	e->__doc__ = commentParser.parse(ctx);

	if (!hierarchyOnly) {
		auto g = ctx->generic_clause();
		if (g)
			visitGeneric_clause(g, &e->generics);
		auto pc = ctx->port_clause();
		if (pc)
			visitPort_clause(pc, &e->ports);
		for (auto d : ctx->entity_declarative_item()) {
			visitEntity_declarative_item(d);
		}
		if (ctx->entity_statement().size()) {
			NotImplementedLogger::print("EntityParser.entity_statement", ctx);
		}
	}
	e->position.update_from_elem(ctx);
	return e;
}

void EntityParser::visitEntity_declarative_item(
		vhdlParser::Entity_declarative_itemContext *ctx) {
	// entity_declarative_item:
	//       subprogram_declaration
	//       | subprogram_body
	//       | subprogram_instantiation_declaration
	//       | package_declaration
	//       | package_body
	//       | package_instantiation_declaration
	//       | type_declaration
	//       | subtype_declaration
	//       | constant_declaration
	//       | signal_declaration
	//       | variable_declaration
	//       | file_declaration
	//       | alias_declaration
	//       | attribute_declaration
	//       | attribute_specification
	//       | disconnection_specification
	//       | use_clause
	//       | group_template_declaration
	//       | group_declaration
	// ;

	NotImplementedLogger::print("EntityParser.visitEntity_declarative_item",
			ctx);
}
void EntityParser::visitGeneric_clause(vhdlParser::Generic_clauseContext *ctx,
		std::vector<HdlVariableDef*> *generics) {
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
void EntityParser::visitPort_clause(vhdlParser::Port_clauseContext *ctx,
		std::vector<HdlVariableDef*> *ports) {
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
		for (HdlVariableDef *p : *ps) {
			p->position.update_from_elem(ie);
			ports->push_back(p);
		}
		delete ps;
	}
}

}
}
