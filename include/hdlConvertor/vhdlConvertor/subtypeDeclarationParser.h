#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlSubtypeDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlObjects::HdlSubtypeDec> visitSubtype_declaration(
			vhdlParser::Subtype_declarationContext *ctx);

};

}
}
