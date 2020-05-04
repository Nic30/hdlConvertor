#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlBlockDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;
	VhdlBlockDeclarationParser(bool hierarchyOnly);

	void visitBlock_declarative_item(
			vhdlParser::Block_declarative_itemContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &objs);
	std::unique_ptr<hdlAst::HdlModuleDec> visitComponent_declaration(
			vhdlParser::Component_declarationContext *ctx);
};

}
}
