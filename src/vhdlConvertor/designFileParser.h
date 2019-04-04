#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/context.h"
#include "../baseHdlParser/baseHdlParser.h"

class DesignFileParser : public BaseHdlParser {
public:
	DesignFileParser(Context * ctx, bool _hierarchyOnly);
	void visitDesign_file(vhdl::vhdlParser::Design_fileContext* ctx);
	void visitDesign_unit(vhdl::vhdlParser::Design_unitContext* ctx);
	void visitLibrary_unit(vhdl::vhdlParser::Library_unitContext* ctx);
	void visitSecondary_unit(vhdl::vhdlParser::Secondary_unitContext* ctx);
	void visitContext_clause(vhdl::vhdlParser::Context_clauseContext* ctx);
	void visitPrimary_unit(vhdl::vhdlParser::Primary_unitContext* ctx);
	void visitContext_item(vhdl::vhdlParser::Context_itemContext* ctx);
	std::vector<Expr*> visitUse_clause(vhdl::vhdlParser::Use_clauseContext* ctx);
};
