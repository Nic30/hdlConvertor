#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>

namespace hdlConvertor {
namespace vhdl {

class BlockDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;
	BlockDeclarationParser(bool hierarchyOnly);

	void visitBlock_declarative_part(
			vhdlParser::Block_declarative_partContext * ctx,
			std::vector<hdlObjects::iHdlObj*> & objs);
	void visitBlock_declarative_item(
			vhdlParser::Block_declarative_itemContext * ctx,
			std::vector<hdlObjects::iHdlObj*> & objs);
	hdlObjects::HdlModuleDec * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);
};

}
}
