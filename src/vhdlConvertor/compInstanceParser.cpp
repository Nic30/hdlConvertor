#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

HdlCompInstance * CompInstanceParser::visitComponent_instantiation_statement(
		vhdlParser::Component_instantiation_statementContext * ctx) {
	// component_instantiation_statement
	// : label_colon instantiated_unit
	// ( generic_map_aspect )?
	// ( port_map_aspect )? SEMI
	// ;
	auto name = LiteralParser::visitLabel(ctx->label());
	auto ci = visitInstantiated_unit(ctx->instantiated_unit());
	ci->name = iHdlExpr::ID(name);
	ci->position.update_from_elem(ctx);

	auto gma = ctx->generic_map_aspect();
	if (gma) {
		std::vector<iHdlExpr*> * gmas = visitGeneric_map_aspect(gma);
		for (auto gm : *gmas) {
			ci->genericMap.push_back(gm);
		}
		delete gmas;
	}
	auto pma = ctx->port_map_aspect();
	if (pma) {
		std::vector<iHdlExpr*> * pmas = visitPort_map_aspect(pma);
		for (auto pm : *pmas) {
			ci->portMap.push_back(pm);
		}
		delete pmas;
	}

	return ci;
}

HdlCompInstance * CompInstanceParser::visitInstantiated_unit(
		vhdlParser::Instantiated_unitContext* ctx) {
	// instantiated_unit
	// : ( COMPONENT )? name
	// | ENTITY name ( LPAREN identifier RPAREN )?
	// | CONFIGURATION name
	// ;

	auto _id = ctx->identifier();
	if (_id) {
		iHdlExpr * id = LiteralParser::visitIdentifier(_id);
		NotImplementedLogger::print(
				"CompInstanceParser.visitInstantiated_unit - Identifier", _id);
		delete id;
	}

	auto ent = ReferenceParser::visitName(ctx->name());

	auto ci = new HdlCompInstance(NULL, ent);
	return ci;
}
std::vector<iHdlExpr*> * CompInstanceParser::visitGeneric_map_aspect(
		vhdlParser::Generic_map_aspectContext* ctx) {
	//generic_map_aspect
	//  : GENERIC MAP LPAREN association_list RPAREN
	//  ;

	return ExprParser::visitAssociation_list(ctx->association_list());
}
std::vector<iHdlExpr*> * CompInstanceParser::visitPort_map_aspect(
		vhdlParser::Port_map_aspectContext * ctx) {
	//port_map_aspect
	//  : PORT MAP LPAREN association_list RPAREN
	//  ;

	return ExprParser::visitAssociation_list(ctx->association_list());
}

}
}
