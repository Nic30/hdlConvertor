#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/variable.h"


namespace hdlConvertor {
namespace vhdl {

class VariableParser {
public:
	using Variable = hdlObjects::Variable;
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::vector<Variable*> * visitVariable_declaration(
			vhdlParser::Variable_declarationContext* ctx);

};

}
}
