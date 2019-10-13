# pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>

namespace hdlConvertor {
namespace vhdl {

hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Shift_operatorContext *op);
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Relational_operatorContext *op);
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Logical_operatorContext *op);
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::SignContext *op);
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Adding_operatorContext *op);
hdlObjects::HdlOperatorType HdlOperatorType_from(
		vhdl_antlr::vhdlParser::Multiplying_operatorContext *op);

}
}
