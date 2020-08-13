#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlBlockDeclarationParser {
	VhdlCommentParser &commentParser;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;
	VhdlBlockDeclarationParser(VhdlCommentParser &_commentParser, bool hierarchyOnly);

	void visitBlock_declarative_item(
			vhdlParser::Block_declarative_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &objs);
	std::unique_ptr<hdlAst::HdlModuleDec> visitComponent_declaration(
			vhdlParser::Component_declarationContext *ctx);
};

}
}
