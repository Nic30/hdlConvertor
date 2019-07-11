#pragma once

#include <antlr4-common.h>
#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>

#include <hdlConvertor/baseHdlParser/baseHdlParser.h>

namespace hdlConvertor {
namespace verilog {

class Source_textParser: public BaseHdlParser {
public:
	using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;

	Source_textParser(antlr4::TokenStream* tokens, hdlObjects::HdlContext * ctx,
			bool _hierarchyOnly);
	void visitSource_text(Verilog2001Parser::Source_textContext * ctx);
	void visitTiming_spec(Verilog2001Parser::Timing_specContext* ctx);
	void visitDescription(Verilog2001Parser::DescriptionContext* ctx);
};

}
}
