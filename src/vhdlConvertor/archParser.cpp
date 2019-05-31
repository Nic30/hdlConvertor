#include "archParser.h"

#include "blockDeclarationParser.h"
#include "referenceParser.h"
#include "statementParser.h"

using vhdlParser = vhdl_antlr::vhdlParser;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace vhdl {

ArchParser::ArchParser(bool _hierarchyOnly) {
	hierarchyOnly = _hierarchyOnly;
}
Arch * ArchParser::visitArchitecture_body(
		vhdlParser::Architecture_bodyContext * ctx) {
	auto a = new Arch();
	// architecture_body:
	//       ARCHITECTURE identifier OF name IS
	//           architecture_declarative_part
	//       BEGIN
	//           architecture_statement_part
	//       END ( ARCHITECTURE )? ( simple_name )? SEMI
	// ;

	a->name = strdup(ctx->identifier()->getText().c_str());
	a->entityName = ReferenceParser::visitName(ctx->name());
	a->position.update_from_elem(ctx);

	if (!hierarchyOnly) {
		auto bdi =
				ctx->architecture_declarative_part()->block_declarative_item();
		for (auto bi : bdi) {
			// architecture_declarative_part
			// : ( block_declarative_item )*
			// ;
			BlockDeclarationParser bp(hierarchyOnly);
			bp.visitBlock_declarative_item(bi, a->objs);
		}
	}
	StatementParser sp(hierarchyOnly);
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
