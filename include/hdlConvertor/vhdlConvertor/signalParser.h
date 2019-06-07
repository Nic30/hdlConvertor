#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/variable.h>

namespace hdlConvertor {
namespace vhdl {


class SignalParser {
public:
	using Variable = hdlObjects::Variable;
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::vector<Variable*> * visitSignal_declaration(
		    vhdlParser::Signal_declarationContext* ctx);

};

}
}
