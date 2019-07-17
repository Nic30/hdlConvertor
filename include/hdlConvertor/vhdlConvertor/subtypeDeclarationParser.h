#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class SubtypeDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::HdlVariableDef * visitSubtype_declaration(
			vhdlParser::Subtype_declarationContext* ctx);

};

}
}
