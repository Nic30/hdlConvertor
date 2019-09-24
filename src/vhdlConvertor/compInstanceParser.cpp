#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>
#include <hdlConvertor/vhdlConvertor/exprParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

HdlCompInstance* VhdlCompInstanceParser::visitComponent_instantiation_statement(
		vhdlParser::Component_instantiation_statementContext *ctx,
		const std::string &name) {
	// component_instantiation_statement:
	//       instantiated_unit
	//           ( generic_map_aspect )?
	//           ( port_map_aspect )? SEMI
	// ;
	auto ci = visitInstantiated_unit(ctx->instantiated_unit());
	ci->name = iHdlExpr::ID(name);
	ci->position.update_from_elem(ctx);

	auto gma = ctx->generic_map_aspect();
	if (gma) {
		std::vector<iHdlExpr*> *gmas = visitGeneric_map_aspect(gma);
		for (auto gm : *gmas) {
			ci->genericMap.push_back(gm);
		}
		delete gmas;
	}
	auto pma = ctx->port_map_aspect();
	if (pma) {
		std::vector<iHdlExpr*> *pmas = visitPort_map_aspect(pma);
		for (auto pm : *pmas) {
			ci->portMap.push_back(pm);
		}
		delete pmas;
	}

	return ci;
}

HdlCompInstance* VhdlCompInstanceParser::visitInstantiated_unit(
		vhdlParser::Instantiated_unitContext *ctx) {
	// instantiated_unit
	// : ( COMPONENT )? name
	// | ENTITY name ( LPAREN identifier RPAREN )?
	// | CONFIGURATION name
	// ;

	auto _id = ctx->identifier();
	if (_id) {
		iHdlExpr *id = VhdlLiteralParser::visitIdentifier(_id);
		NotImplementedLogger::print(
				"CompInstanceParser.visitInstantiated_unit - Identifier", _id);
		delete id;
	}

	auto ent = VhdlReferenceParser::visitName(ctx->name());

	auto ci = new HdlCompInstance(NULL, ent);
	return ci;
}
std::vector<iHdlExpr*>* VhdlCompInstanceParser::visitGeneric_map_aspect(
		vhdlParser::Generic_map_aspectContext *ctx) {
	//generic_map_aspect
	//  : GENERIC MAP LPAREN association_list RPAREN
	//  ;

	return VhdlExprParser::visitAssociation_list(ctx->association_list());
}
std::vector<iHdlExpr*>* VhdlCompInstanceParser::visitPort_map_aspect(
		vhdlParser::Port_map_aspectContext *ctx) {
	//port_map_aspect
	//  : PORT MAP LPAREN association_list RPAREN
	//  ;

	return VhdlExprParser::visitAssociation_list(ctx->association_list());
}

}
}
