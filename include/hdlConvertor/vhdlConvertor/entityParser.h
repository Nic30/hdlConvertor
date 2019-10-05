#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlEntityParser {
	VhdlCommentParser &commentParser;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	bool hierarchyOnly;

	VhdlEntityParser(VhdlCommentParser &commentParser, bool _hierarchyOnly);

	std::unique_ptr<hdlObjects::HdlModuleDec> visitEntity_declaration(
			vhdlParser::Entity_declarationContext *ctx);
	static void visitEntity_declarative_item(
			vhdlParser::Entity_declarative_itemContext *ctx);
	static void visitGeneric_clause(vhdlParser::Generic_clauseContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>> &generics);
	static void visitPort_clause(vhdlParser::Port_clauseContext *ctx,
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>> &ports);

};

}
}
