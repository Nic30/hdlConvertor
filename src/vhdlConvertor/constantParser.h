#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/variable.h"


namespace hdlConvertor {
namespace vhdl {

class ConstantParser {
public:
using Variable = hdlObjects::Variable;
using vhdlParser = vhdl_antlr::vhdlParser;
	static std::vector<Variable*> * visitConstant_declaration(
			vhdlParser::Constant_declarationContext* ctx);

};

}
}
