#include "compInstanceParser.h"

#include "../notImplementedLogger.h"
#include "literalParser.h"
#include "referenceParser.h"
#include "exprParser.h"

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

CompInstance * CompInstanceParser::visitComponent_instantiation_statement(
		vhdlParser::Component_instantiation_statementContext * ctx) {
	// component_instantiation_statement
	// : label_colon instantiated_unit
	// ( generic_map_aspect )?
	// ( port_map_aspect )? SEMI
	// ;
	char * name = LiteralParser::visitLabel_colon(ctx->label_colon());
	CompInstance * ci = visitInstantiated_unit(ctx->instantiated_unit());
	ci->name = Expr::ID(name);
	ci->position.startLine = ctx->getStart()->getLine(), ci->position.startColumn =
			ctx->getStop()->getLine();

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
char * CompInstanceParser::visitLabel_colon(
		vhdlParser::Label_colonContext * ctx) {
	// label_colon
	// : identifier COLON
	// ;
	Expr * e = LiteralParser::visitIdentifier(ctx->identifier());
	char * s = strdup(dynamic_cast<Symbol*>(e->data)->value._str);
	delete e;
	return s;
}
CompInstance * CompInstanceParser::visitInstantiated_unit(
		vhdlParser::Instantiated_unitContext* ctx) {
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
		vhdlParser::Generic_map_aspectContext* ctx) {
	//generic_map_aspect
	//  : GENERIC MAP LPAREN association_list RPAREN
	//  ;

	return ExprParser::visitAssociation_list(ctx->association_list());
}
std::vector<Expr*> * CompInstanceParser::visitPort_map_aspect(
		vhdlParser::Port_map_aspectContext * ctx) {
	//port_map_aspect
	//  : PORT MAP LPAREN association_list RPAREN
	//  ;

	return ExprParser::visitAssociation_list(ctx->association_list());
}

}
}
