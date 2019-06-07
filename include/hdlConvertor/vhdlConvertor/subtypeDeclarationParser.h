#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/variable.h>

namespace hdlConvertor {
namespace vhdl {

class SubtypeDeclarationParser {
public:
	using Variable = hdlObjects::Variable;
	using vhdlParser = vhdl_antlr::vhdlParser;


	static Variable * visitSubtype_declaration(
		vhdlParser::Subtype_declarationContext* ctx);

};

}
}
