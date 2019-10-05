#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlInterfaceParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> extractVariables(
			vhdlParser::Identifier_listContext *identifier_list,
			vhdlParser::Subtype_indicationContext *subType,
			vhdlParser::ExpressionContext *_expr);
	//static std::vector<Port*>* visitInterface_port_declaration(
	//		vhdlParser::Interface_port_declarationContext* ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitInterface_constant_declaration(
			vhdlParser::Interface_constant_declarationContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitInterface_signal_declaration(
			vhdlParser::Interface_signal_declarationContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitInterface_variable_declaration(
			vhdlParser::Interface_variable_declarationContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitInterface_file_declaration(
			vhdlParser::Interface_file_declarationContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitInterface_declaration(
			vhdlParser::Interface_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitInterface_type_declaration(
			vhdlParser::Interface_type_declarationContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitInterface_object_declaration(
			vhdlParser::Interface_object_declarationContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitInterface_list(
			vhdlParser::Interface_listContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitInterface_element(
			vhdlParser::Interface_elementContext *ctx);
};

}
}
