# pragma once

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlAst/hdlOpType.h>

namespace hdlConvertor {
namespace vhdl {

hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Shift_operatorContext *op);
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Relational_operatorContext *op);
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Logical_operatorContext *op);
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::SignContext *op);
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Adding_operatorContext *op);
hdlAst::HdlOpType HdlOpType_from(
		vhdl_antlr::vhdlParser::Multiplying_operatorContext *op);

}
}
