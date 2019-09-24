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
HdlModuleDef * VhdlArchParser::visitArchitecture_body(
		vhdlParser::Architecture_bodyContext * ctx) {
	auto a = new HdlModuleDef();
	// architecture_body:
	//       ARCHITECTURE identifier OF name IS
	//           architecture_declarative_part
	//       BEGIN
	//           architecture_statement_part
	//       END ( ARCHITECTURE )? ( identifier )? SEMI
	// ;

	a->name = ctx->identifier(0)->getText();
	a->entityName = VhdlReferenceParser::visitName(ctx->name());
	a->position.update_from_elem(ctx);

	if (!hierarchyOnly) {
		auto bdi =
				ctx->architecture_declarative_part()->block_declarative_item();
		for (auto bi : bdi) {
			// architecture_declarative_part
			// : ( block_declarative_item )*
			// ;
			VhdlBlockDeclarationParser bp(hierarchyOnly);
			bp.visitBlock_declarative_item(bi, a->objs);
		}
	}
	VhdlStatementParser sp(hierarchyOnly);
	for (auto s : ctx->architecture_statement_part()->concurrent_statement()) {
		// architecture_statement_part
		// : ( concurrent_statement )*
		// ;
		sp.visitConcurrent_statement(s, a->objs);
	}

	return a;
}

}
}
