#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/context.h"
#include "../baseHdlParser/baseHdlParser.h"
#include <antlr4-common.h>

namespace hdlConvertor {
namespace vhdl {

class DesignFileParser: public BaseHdlParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	using Expr = hdlObjects::Expr;

	DesignFileParser(antlr4::TokenStream* tokens, hdlObjects::Context * ctx,
			bool _hierarchyOnly);
	void visitDesign_file(vhdlParser::Design_fileContext* ctx);
	void visitDesign_unit(vhdlParser::Design_unitContext* ctx);
	void visitLibrary_unit(vhdlParser::Library_unitContext* ctx);
	void visitSecondary_unit(vhdlParser::Secondary_unitContext* ctx);
	void visitContext_clause(vhdlParser::Context_clauseContext* ctx);
	void visitPrimary_unit(vhdlParser::Primary_unitContext* ctx);
	void visitContext_item(vhdlParser::Context_itemContext* ctx);
	std::vector<Expr*> visitUse_clause(vhdlParser::Use_clauseContext* ctx);
};

}
}
