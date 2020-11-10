#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/baseSvParser.h>

#include <hdlConvertor/hdlAst/iHdlStatement.h>

namespace hdlConvertor {
namespace sv {

class VerGateParser: public BaseSvParser {
public:
	using BaseSvParser::BaseSvParser;
	using sv2017Parser = sv2017_antlr::sv2017Parser;

	std::unique_ptr<hdlAst::iHdlExprItem> visitEnable_terminal(
			sv2017Parser::Enable_terminalContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitInout_terminal(
			sv2017Parser::Inout_terminalContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitInput_terminal(
			sv2017Parser::Input_terminalContext *ctx);
	std::unique_ptr<hdlAst::iHdlExprItem> visitOutput_terminal(
			sv2017Parser::Output_terminalContext *ctx);
	hdlAst::HdlOpType visitN_output_gatetype(
			sv2017Parser::N_output_gatetypeContext *ctx);
	// @return <output, input>
	std::pair<std::unique_ptr<hdlAst::iHdlExprItem>,
			std::unique_ptr<hdlAst::iHdlExprItem>> visitN_output_gate_instance(
			sv2017Parser::N_output_gate_instanceContext *ctx);
	void visitGate_instantiation(sv2017Parser::Gate_instantiationContext *ctx,
			std::vector<std::unique_ptr<hdlAst::iHdlObj>> &res);
};

}
}
