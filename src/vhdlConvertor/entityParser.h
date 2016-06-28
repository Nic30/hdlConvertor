#pragma once

#include <vector>
#include <stdlib.h>
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/entity.h"
#include "interfaceParser.h"


using namespace antlr4;
using namespace vhdl;

class EntityParser {

public:
	bool hierarchyOnly;
	EntityParser(bool _hierarchyOnly);
	Entity * visitEntity_declaration(
			Ref<vhdlParser::Entity_declarationContext> ctx);
	static void visitEntity_declarative_item(
			Ref<vhdlParser::Entity_declarative_itemContext> ctx);
	static void visitGeneric_clause(
			Ref<vhdlParser::Generic_clauseContext> ctx,
			std::vector<Variable*> * generics);
	static void visitPort_clause(
			Ref<vhdlParser::Port_clauseContext> ctx,
			std::vector<Port*> * ports);
	static void visitEntity_header(
			Entity * e,
			Ref<vhdlParser::Entity_headerContext> ctx);
	void visitEntity_statement_part(
			Ref<vhdlParser::Entity_statement_partContext> ctx);
};
