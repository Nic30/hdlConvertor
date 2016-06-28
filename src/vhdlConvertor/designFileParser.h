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


using namespace antlr4;
using namespace vhdl;

class DesignFileParser {
public:
	bool hierarchyOnly;
	Context * context;
	DesignFileParser(bool hierarchyOnly);

	Context * getContext();
	void visitDesign_file(Ref<vhdlParser::Design_fileContext> ctx);
	void visitDesign_unit(Ref<vhdlParser::Design_unitContext> ctx);
	void visitLibrary_unit(Ref<vhdlParser::Library_unitContext> ctx);
	void visitSecondary_unit(Ref<vhdlParser::Secondary_unitContext> ctx);
	void visitContext_clause(Ref<vhdlParser::Context_clauseContext> ctx);
	void visitPrimary_unit(Ref<vhdlParser::Primary_unitContext> ctx);
	void visitContext_item(Ref<vhdlParser::Context_itemContext> ctx);
	std::vector<Expr*> visitUse_clause(Ref<vhdlParser::Use_clauseContext> ctx);
};
