#include <hdlConvertor/vhdlConvertor/archParser.h>
#include <hdlConvertor/vhdlConvertor/blockDeclarationParser.h>
#include <hdlConvertor/vhdlConvertor/referenceParser.h>
#include <hdlConvertor/vhdlConvertor/statementParser.h>

#include <hdlConvertor/createObject.h>

namespace hdlConvertor {
namespace vhdl {

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlAst;

std::unique_ptr<HdlModuleDef> VhdlArchParser::visitArchitecture_body(
		vhdlParser::Architecture_bodyContext *ctx) {
	auto a = create_object<HdlModuleDef>(ctx);
	// architecture_body:
	//       ARCHITECTURE identifier OF name IS
	//           ( block_declarative_item )*
	//       BEGIN
	//           ( concurrent_statement )*
	//       END ( ARCHITECTURE )? ( identifier )? SEMI
	// ;

	a->name = ctx->identifier(0)->getText();
	a->module_name = VhdlReferenceParser::visitName(ctx->name());

	if (!hierarchyOnly) {
		for (auto bi : ctx->block_declarative_item()) {
			VhdlBlockDeclarationParser bp(commentParser, hierarchyOnly);
			bp.visitBlock_declarative_item(bi, a->objs);
		}
	}
	VhdlStatementParser sp(commentParser, hierarchyOnly);
	for (auto s : ctx->concurrent_statement()) {
		sp.visitConcurrent_statement(s, a->objs);
	}

	return a;
}

}
}
