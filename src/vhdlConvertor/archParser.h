#pragma once
#include <vector>
#include "../VhdlParser/vhdlParser.h"
#include "../hdlObjects/context.h"
#include "../notImplementedLogger.h"
#include "referenceParser.h"
#include "../hdlObjects/named.h"
#include "compInstanceParser.h"

using namespace antlr4;
using namespace vhdl;

class ArchParser : public Named {
public:
	Arch * a;
	bool hierarchyOnly;
	ArchParser(bool _hierarchyOnly);
	Arch * visitArchitecture_body(
			Ref<vhdlParser::Architecture_bodyContext> ctx);
	void visitBlock_declarative_item(
			Ref<vhdlParser::Block_declarative_itemContext> ctx);
	void visitArchitecture_statement(
			Ref<vhdlParser::Architecture_statementContext> ctx);

};
