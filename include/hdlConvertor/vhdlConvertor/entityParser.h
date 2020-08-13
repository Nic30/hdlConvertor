#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlEntityParser {
	VhdlCommentParser &commentParser;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	bool hierarchyOnly;

	VhdlEntityParser(VhdlCommentParser &commentParser, bool _hierarchyOnly);

	std::unique_ptr<hdlAst::HdlModuleDec> visitEntity_declaration(
			vhdlParser::Entity_declarationContext *ctx);
	void visitEntity_declarative_item(
			vhdlParser::Entity_declarative_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &objs);
	static void visitGeneric_clause(vhdlParser::Generic_clauseContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &generics);
	static void visitPort_clause(vhdlParser::Port_clauseContext *ctx,
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>> &ports);

};

}
}
