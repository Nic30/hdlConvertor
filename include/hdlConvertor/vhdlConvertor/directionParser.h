#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/hdlDirection.h>
#include <hdlConvertor/hdlAst/hdlOpType.h>

namespace hdlConvertor {
namespace vhdl {

hdlAst::HdlDirection visitSignalMode(
		vhdl_antlr::vhdlParser::Signal_modeContext *ctx);
hdlAst::HdlOpType visitDirection(
		vhdl_antlr::vhdlParser::DirectionContext *ctx);

}
}
