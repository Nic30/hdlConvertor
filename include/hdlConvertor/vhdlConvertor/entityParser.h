#pragma once

#include <vector>

#include <hdlConvertor/hdlObjects/entity.h>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>


namespace hdlConvertor {
namespace vhdl {

class EntityParser {
	CommentParser & commentParser;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	bool hierarchyOnly;

	EntityParser(CommentParser & commentParser, bool _hierarchyOnly);

	hdlObjects::Entity * visitEntity_declaration(
			vhdlParser::Entity_declarationContext* ctx);
	static void visitEntity_declarative_item(
			vhdlParser::Entity_declarative_itemContext* ctx);
	static void visitGeneric_clause(vhdlParser::Generic_clauseContext* ctx,
			std::vector<hdlObjects::Variable*> * generics);
	static void visitPort_clause(vhdlParser::Port_clauseContext* ctx,
			std::vector<hdlObjects::Variable*> * ports);
	static void visitEntity_header(hdlObjects::Entity * e,
			vhdlParser::Entity_headerContext* ctx);
	void visitEntity_statement_part(
			vhdlParser::Entity_statement_partContext* ctx);
};

}
}
