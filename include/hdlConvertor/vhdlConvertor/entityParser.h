#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>
#include <hdlConvertor/vhdlConvertor/baseVhdlParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlEntityParser : public BaseVhdlParser {
public:
	using BaseVhdlParser::BaseVhdlParser;
	using vhdlParser = vhdl_antlr::vhdlParser;

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
