#pragma once
#include <vector>
#include "../VhdlParser/vhdlParser.h"
#include "../hdlObjects/context.h"
#include "../notImplementedLogger.h"
#include "referenceParser.h"
#include "archParser.h"
#include "packageParser.h"
#include "entityParser.h"
#include "packageHeaderParser.h"
#include "../baseHdlParser/baseHdlParser.h"

using namespace antlr4;
using namespace vhdl;

class DesignFileParser : public BaseHdlParser {
public:
	DesignFileParser(bool _hierarchyOnly);
	void visitDesign_file(vhdlParser::Design_fileContext* ctx);
	void visitDesign_unit(vhdlParser::Design_unitContext* ctx);
	void visitLibrary_unit(vhdlParser::Library_unitContext* ctx);
	void visitSecondary_unit(vhdlParser::Secondary_unitContext* ctx);
	void visitContext_clause(vhdlParser::Context_clauseContext* ctx);
	void visitPrimary_unit(vhdlParser::Primary_unitContext* ctx);
	void visitContext_item(vhdlParser::Context_itemContext* ctx);
	std::vector<Expr*> visitUse_clause(vhdlParser::Use_clauseContext* ctx);
};
