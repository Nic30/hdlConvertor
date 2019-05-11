#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/entity.h"

namespace hdlConvertor {
namespace vhdl {

class EntityParser {

public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	bool hierarchyOnly;

	EntityParser(bool _hierarchyOnly);

	hdlObjects::Entity * visitEntity_declaration(
			vhdlParser::Entity_declarationContext* ctx);
	static void visitEntity_declarative_item(
			vhdlParser::Entity_declarative_itemContext* ctx);
	static void visitGeneric_clause(vhdlParser::Generic_clauseContext* ctx,
			std::vector<hdlObjects::Variable*> * generics);
	static void visitPort_clause(vhdlParser::Port_clauseContext* ctx,
			std::vector<hdlObjects::Port*> * ports);
	static void visitEntity_header(hdlObjects::Entity * e,
			vhdlParser::Entity_headerContext* ctx);
	void visitEntity_statement_part(
			vhdlParser::Entity_statement_partContext* ctx);
};

}
}
