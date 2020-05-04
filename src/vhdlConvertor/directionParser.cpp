#include <hdlConvertor/vhdlConvertor/directionParser.h>
#include <assert.h>


namespace hdlConvertor {
namespace vhdl {

hdlAst::HdlDirection visitSignalMode(
		vhdl_antlr::vhdlParser::Signal_modeContext *ctx) {
	using hdlAst::HdlDirection;

	if (ctx == nullptr || ctx->KW_IN())
		return HdlDirection::DIR_IN;
	else if (ctx->KW_OUT())
		return HdlDirection::DIR_OUT;
	else if (ctx->KW_INOUT())
		return HdlDirection::DIR_INOUT;
	else if (ctx->KW_BUFFER())
		return HdlDirection::DIR_BUFFER;
	else {
		//assert (sm->LINKAGE());
		return HdlDirection::DIR_LINKAGE;
	}
}

hdlAst::HdlOpType visitDirection(
		vhdl_antlr::vhdlParser::DirectionContext *ctx) {
	// direction: TO | DOWNTO;
	if (ctx->KW_TO())
		return hdlAst::TO;
	else {
		assert(ctx->KW_DOWNTO());
		return hdlAst::DOWNTO;
	}
}

}
}
