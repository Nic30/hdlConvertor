#include <hdlConvertor/vhdlConvertor/blockDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/entityParser.h>
#include <hdlConvertor/vhdlConvertor/packageHeaderParser.h>
#include <hdlConvertor/vhdlConvertor/packageParser.h>
#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/subProgramParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>
#include <hdlConvertor/vhdlConvertor/typeDeclarationParser.h>

#include <hdlConvertor/createObject.h>

#include <string.h>

namespace hdlConvertor {
namespace vhdl {

/*
 * @note Some declarations can spot multiple objects
 * 		 that is why this function just does not return hdlAst::iHdlObj*
 * */
void VhdlBlockDeclarationParser::visitBlock_declarative_item(
		vhdlParser::Block_declarative_itemContext *ctx,
		std::vector<std::unique_ptr<hdlAst::iHdlObj>> &objs) {
	// block_declarative_item:
	//	entity_declarative_item
	//	| component_declaration
	//	| configuration_specification
    // ;
	auto edi = ctx->entity_declarative_item();
	if (edi) {
		VhdlEntityParser ep(commentParser, hierarchyOnly);
		ep.visitEntity_declarative_item(edi, objs);
		return;
	}
	auto compd = ctx->component_declaration();
	if (compd) {
		objs.push_back(visitComponent_declaration(compd));
		return;
	}
	auto cs = ctx->configuration_specification();
	assert(cs);
		NotImplementedLogger::print(
				"VhdlBlockDeclarationParser.visitconfiguration_specification", cs);
		return;
}

std::unique_ptr<hdlAst::HdlModuleDec> VhdlBlockDeclarationParser::visitComponent_declaration(
		vhdlParser::Component_declarationContext *ctx) {
	// component_declaration:
	//       COMPONENT identifier ( IS )?
	//           ( generic_clause )?
	//           ( port_clause )?
	//       END COMPONENT ( identifier )? SEMI
	// ;
	auto e = create_object<hdlAst::HdlModuleDec>(ctx);
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
