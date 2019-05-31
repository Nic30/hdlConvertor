#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/variable.h"

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
