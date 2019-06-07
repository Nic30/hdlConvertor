#pragma once
#include <vector>
#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/variable.h>


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
