#include <hdlConvertor/vhdlConvertor/compInstanceParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/processParser.h>

#include <hdlConvertor/createObject.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlAst;

std::unique_ptr<HdlValueIdspace> VhdlPackageHeaderParser::visitPackage_declaration(
		vhdlParser::Package_declarationContext *ctx) {
	// package_declaration:
	//       KW_PACKAGE identifier KW_IS
	//           (
	//              generic_clause  ( generic_map_aspect SEMI )?
	//           )?
	//           ( package_declarative_item )*
	//       KW_END ( KW_PACKAGE )? ( identifier )? SEMI
	// ;
	ph = create_object<HdlValueIdspace>(ctx);
	ph->name = VhdlLiteralParser::getIdentifierStr(ctx->identifier(0));
	ph->defs_only = true;

	if (!hierarchyOnly) {
		auto gc = ctx->generic_clause();
		if (gc)
			//visitGeneric_clause(gc);
			NotImplementedLogger::print("VhdlPackageHeaderParser.visitGeneric_clause",
					gc);
		auto gma = ctx->generic_map_aspect();
		if (gma)
			//visitGeneric_map_aspect(gma);
			NotImplementedLogger::print(
					"VhdlPackageHeaderParser.visitGeneric_map_aspect", gma);
		for (auto i : ctx->package_declarative_item()) {
			visitPackage_declarative_item(i);
		}
	}
	return std::move(ph);
}
void VhdlPackageHeaderParser::visitPackage_declarative_item(
		vhdlParser::Package_declarative_itemContext *ctx) {
	// package_declarative_item:
	//       process_or_package_declarative_item
	//       | signal_declaration
	//       | component_declaration
	//       | disconnection_specification
	// ;
	auto ppdi = ctx->process_or_package_declarative_item();
	if (ppdi) {
		VhdlProcessParser pp(commentParser, hierarchyOnly);
		pp.visitProcess_or_package_declarative_item(ppdi, ph->objs);
		return;
	}

	auto sd = ctx->signal_declaration();
	if (sd) {
		auto signals = VhdlSignalParser::visitSignal_declaration(sd);
		for (auto &s : *signals) {
			ph->objs.push_back(move(s));
		}
		return;
	}
	auto compd = ctx->component_declaration();
	if (compd) {
		ph->objs.push_back(visitComponent_declaration(compd));
		return;
	}
	auto discs = ctx->disconnection_specification();
	assert(discs);
	NotImplementedLogger::print(
			"VhdlPackageHeaderParser.visitDisconnection_specification", discs);
}
std::unique_ptr<HdlModuleDec> VhdlPackageHeaderParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext *ctx) {
	// component_declaration:
	//       COMPONENT identifier ( IS )?
	//           ( generic_clause )?
	//           ( port_clause )?
	//       END COMPONENT ( identifier )? SEMI
	// ;

	auto e = create_object<HdlModuleDec>(ctx);
	e->name = ctx->identifier(0)->getText();
	if (!hierarchyOnly) {
		auto gc = ctx->generic_clause();
		if (gc)
			VhdlEntityParser::visitGeneric_clause(gc, e->generics);
		auto pc = ctx->port_clause();
		if (pc)
			VhdlEntityParser::visitPort_clause(pc, e->ports);
	}
	return e;
}

}
}
