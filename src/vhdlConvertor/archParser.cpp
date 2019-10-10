#include <hdlConvertor/vhdlConvertor/archParser.h>
#include <hdlConvertor/vhdlConvertor/blockDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

VhdlArchParser::VhdlArchParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
}
std::unique_ptr<HdlModuleDef> VhdlArchParser::visitArchitecture_body(
		vhdlParser::Architecture_bodyContext * ctx) {
	auto a = std::make_unique<HdlModuleDef>();
	// architecture_body:
	//       ARCHITECTURE identifier OF name IS
	//           ( block_declarative_item )*
	//       BEGIN
	//           ( concurrent_statement )*
	//       END ( ARCHITECTURE )? ( identifier )? SEMI
	// ;

	a->name = ctx->identifier(0)->getText();
	a->entityName = VhdlReferenceParser::visitName(ctx->name());
	a->position.update_from_elem(ctx);

	if (!hierarchyOnly) {
		for (auto bi : ctx->block_declarative_item()) {
			VhdlBlockDeclarationParser bp(hierarchyOnly);
			bp.visitBlock_declarative_item(bi, a->objs);
		}
	}
	VhdlStatementParser sp(hierarchyOnly);
	for (auto s : ctx->concurrent_statement()) {
		sp.visitConcurrent_statement(s, a->objs);
	}

	return a;
}

}
}
