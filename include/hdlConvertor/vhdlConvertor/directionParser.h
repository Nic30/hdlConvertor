#pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlDirection.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace vhdl {

hdlObjects::HdlDirection visitSignalMode(
		vhdl_antlr::vhdlParser::Signal_modeContext *ctx);
hdlObjects::HdlOperatorType visitDirection(
		vhdl_antlr::vhdlParser::DirectionContext *ctx);

}
}
