#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/variable.h"

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
