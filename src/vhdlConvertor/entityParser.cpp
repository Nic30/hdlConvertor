#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>



namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlAst;

std::unique_ptr<HdlModuleDec> VhdlEntityParser::visitEntity_declaration(
		vhdlParser::Entity_declarationContext *ctx) {
	// entity_declaration:
	//       KW_ENTITY identifier KW_IS
	//           ( generic_clause )?
	//           ( port_clause )?
	//           ( entity_declarative_item )*
	//       ( KW_BEGIN ( entity_statement )* )?
	//       KW_END ( KW_ENTITY )? ( identifier )? SEMI
	// ;
	auto e = create_object_with_doc<HdlModuleDec>(ctx, commentParser);
	e->name = ctx->identifier(0)->getText();

	if (!hierarchyOnly) {
		auto g = ctx->generic_clause();
		if (g)
			visitGeneric_clause(g, e->generics);
		auto pc = ctx->port_clause();
		if (pc)
			visitPort_clause(pc, e->ports);
		for (auto d : ctx->entity_declarative_item()) {
			visitEntity_declarative_item(d, e->objs);
		}
		if (ctx->entity_statement().size()) {
			NotImplementedLogger::print("VhdlEntityParser.entity_statement", ctx);
		}
	}
	return e;
}

void VhdlEntityParser::visitEntity_declarative_item(
		vhdlParser::Entity_declarative_itemContext *ctx, std::vector<std::unique_ptr<iHdlObj>> & objs) {
	// entity_declarative_item:
	//       signal_declaration
	//       | process_declarative_item
	//       | disconnection_specification
	// ;
	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = VhdlSignalParser::visitSignal_declaration(sd);
		for (auto & s : *signals) {
			objs.push_back(std::move(s));
		}
		return;
	}
	auto pdi = ctx->process_declarative_item();
	if (pdi) {
		VhdlProcessParser pp(commentParser, hierarchyOnly);
		pp.visitProcess_declarative_item(pdi, objs);
		return;
	}
	auto discs = ctx->disconnection_specification();
	assert(discs);
		NotImplementedLogger::print(
				"VhdlEntityParser.visitDisconnection_specification", discs);
}
void VhdlEntityParser::visitGeneric_clause(
		vhdlParser::Generic_clauseContext *ctx,
		std::vector<std::unique_ptr<HdlIdDef>> &generics) {
	// generic_clause:
	//       GENERIC LPAREN generic_list RPAREN SEMI
	// ;
	// generic_list: interface_list;
	auto gl = ctx->generic_list();
	auto gs = VhdlInterfaceParser::visitInterface_list(gl->interface_list());
	for (auto &v : *gs) {
		assert(v);
		generics.push_back(std::move(v));
	}
}
void VhdlEntityParser::visitPort_clause(vhdlParser::Port_clauseContext *ctx,
		std::vector<std::unique_ptr<HdlIdDef>> &ports) {
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
		auto ps = VhdlInterfaceParser::visitInterface_element(ie);
		for (auto &p : *ps) {
			ports.push_back(std::move(p));
		}
	}
}

}
}
