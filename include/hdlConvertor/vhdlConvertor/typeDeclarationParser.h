#pragma once

//copy:#include <vector>
//copy:
//copy:#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
//copy:
//copy:#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
//copy:#include <hdlConvertor/hdlObjects/hdlFunctionDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlTypeDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlObjects::HdlTypeDec> visitType_declaration(
			vhdlParser::Type_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitFull_type_declaration(
			vhdlParser::Full_type_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitIncomplete_type_declaration(
			vhdlParser::Incomplete_type_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitType_definition(
			std::string &&name, vhdlParser::Type_definitionContext *ctx);

	static std::unique_ptr<hdlObjects::HdlTypeDec> visitScalar_type_definition(
			std::string &&name, vhdlParser::Scalar_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitComposite_type_definition(
			std::string &&name, vhdlParser::Composite_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitAccess_type_definition(
			std::string &&name, vhdlParser::Access_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitFile_type_definition(
			std::string &&name, vhdlParser::File_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitProtected_type_definition(
			std::string &&name, vhdlParser::Protected_type_definitionContext *ctx);
	
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitEnumeration_type_definition(
			std::string &&name, vhdlParser::Enumeration_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitInteger_type_definition(
			std::string &&name, vhdlParser::Integer_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitFloating_type_definition(
			std::string &&name, vhdlParser::Floating_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitPhysical_type_definition(
			std::string &&name, vhdlParser::Physical_type_definitionContext *ctx);

	static std::unique_ptr<hdlObjects::HdlTypeDec> visitArray_type_definition(
			std::string &&name, vhdlParser::Array_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitUnbounded_array_definition(
			std::string &&name, vhdlParser::Unbounded_array_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitConstrained_array_definition(
			std::string &&name, vhdlParser::Constrained_array_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlTypeDec> visitRecord_type_definition(
			std::string &&name, vhdlParser::Record_type_definitionContext *ctx);

};

}
}
