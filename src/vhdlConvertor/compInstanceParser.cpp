#include "compInstanceParser.h"

CompInstance * CompInstanceParser::visitComponent_instantiation_statement(
		Ref<vhdlParser::Component_instantiation_statementContext> ctx) {
	// component_instantiation_statement
	// : label_colon instantiated_unit
	// ( generic_map_aspect )?
	// ( port_map_aspect )? SEMI
	// ;
	char * name = visitLabel_colon(ctx->label_colon());
	CompInstance * ci = visitInstantiated_unit(ctx->instantiated_unit());
	ci->name = name;
	auto gma = ctx->generic_map_aspect();
	if (gma) {
		std::vector<Expr*> * gmas = visitGeneric_map_aspect(gma);
		for (auto gm : *gmas) {
			ci->genericMap.push_back(gm);
		}
		delete gmas;
	}
	auto pma = ctx->port_map_aspect();
	if (pma) {
		std::vector<Expr*> * pmas = visitPort_map_aspect(pma);
		for (auto pm : *pmas) {
			ci->portMap.push_back(pm);
		}
		delete pmas;
	}

	return ci;
}
std::vector<Expr*> * CompInstanceParser::visitPort_map_aspect(
		Ref<vhdlParser::Port_map_aspectContext> ctx) {
	NotImplementedLogger::print("CompInstanceParser.visitPort_map_aspect");
	return new std::vector<Expr*>();
}
char * CompInstanceParser::visitLabel_colon(
		Ref<vhdlParser::Label_colonContext> ctx) {
	// label_colon
	// : identifier COLON
	// ;
	Expr * e = LiteralParser::visitIdentifier(ctx->identifier());
	char * s = strdup(dynamic_cast<Symbol*>(e->data)->value._str);
	delete e;
	return s;
}
CompInstance * CompInstanceParser::visitInstantiated_unit(
		Ref<vhdlParser::Instantiated_unitContext> ctx) {
	// instantiated_unit
	// : ( COMPONENT )? name
	// | ENTITY name ( LPAREN identifier RPAREN )?
	// | CONFIGURATION name
	// ;

	auto _id = ctx->identifier();
	if (_id) {
		Expr * id = LiteralParser::visitIdentifier(_id);
		NotImplementedLogger::print(
				"CompInstanceParser.visitInstantiated_unit - Identifier");
		delete id;
	}

	Expr * ent = ReferenceParser::visitName(ctx->name());

	CompInstance * ci = new CompInstance(NULL, ent);
	return ci;
}
std::vector<Expr*> * CompInstanceParser::visitGeneric_map_aspect(
		Ref<vhdlParser::Generic_map_aspectContext> ctx) {
	NotImplementedLogger::print("CompInstanceParser.visitGeneric_map_aspect");
	return new std::vector<Expr*>();
}
