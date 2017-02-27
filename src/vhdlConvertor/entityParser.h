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
			vhdlParser::Entity_declarationContext* ctx);
	static void visitEntity_declarative_item(
			vhdlParser::Entity_declarative_itemContext* ctx);
	static void visitGeneric_clause(
			vhdlParser::Generic_clauseContext* ctx,
			std::vector<Variable*> * generics);
	static void visitPort_clause(
			vhdlParser::Port_clauseContext* ctx,
			std::vector<Port*> * ports);
	static void visitEntity_header(
			Entity * e,
			vhdlParser::Entity_headerContext* ctx);
	void visitEntity_statement_part(
			vhdlParser::Entity_statement_partContext* ctx);
};
