#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class SignalParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::vector<hdlObjects::HdlVariableDef*> * visitSignal_declaration(
			vhdlParser::Signal_declarationContext* ctx);

};

}
}
