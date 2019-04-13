#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/entity.h"

class EntityParser {

public:
	bool hierarchyOnly;
	EntityParser(bool _hierarchyOnly);
	Entity * visitEntity_declaration(
			vhdl::vhdlParser::Entity_declarationContext* ctx);
	static void visitEntity_declarative_item(
			vhdl::vhdlParser::Entity_declarative_itemContext* ctx);
	static void visitGeneric_clause(
			vhdl::vhdlParser::Generic_clauseContext* ctx,
			std::vector<Variable*> * generics);
	static void visitPort_clause(vhdl::vhdlParser::Port_clauseContext* ctx,
			std::vector<Port*> * ports);
	static void visitEntity_header(Entity * e,
			vhdl::vhdlParser::Entity_headerContext* ctx);
	void visitEntity_statement_part(
			vhdl::vhdlParser::Entity_statement_partContext* ctx);
};
