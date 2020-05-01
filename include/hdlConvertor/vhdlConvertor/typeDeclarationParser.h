#pragma once

#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/hdlObjects/hdlTypes.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlTypeDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlObjects::iHdlExprItem> visitSubtype_indication(
			vhdlParser::Subtype_indicationContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitConstraint(
			std::unique_ptr<hdlObjects::iHdlExprItem> selectedName,
			vhdlParser::ConstraintContext *ctx);
	static std::pair<std::unique_ptr<hdlObjects::iHdlExprItem>,
			std::vector<std::unique_ptr<hdlObjects::iHdlExprItem>> > visitArray_constraint(
			vhdlParser::Array_constraintContext *ctx);
	static std::vector<std::unique_ptr<hdlObjects::iHdlExprItem>> visitIndex_constraint(
			vhdlParser::Index_constraintContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitArray_element_constraint(
			vhdlParser::Array_element_constraintContext *ctx);

	static std::unique_ptr<hdlObjects::HdlVariableDef> visitType_declaration(
			vhdlParser::Type_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlVariableDef> visitFull_type_declaration(
			vhdlParser::Full_type_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlVariableDef> visitIncomplete_type_declaration(
			vhdlParser::Incomplete_type_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlVariableDef> visitType_definition(
			std::string &&name, vhdlParser::Type_definitionContext *ctx);

	static std::unique_ptr<hdlObjects::iHdlExprItem> visitScalar_type_definition(
			vhdlParser::Scalar_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitComposite_type_definition(
			vhdlParser::Composite_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitAccess_type_definition(
			vhdlParser::Access_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitFile_type_definition(
			vhdlParser::File_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitProtected_type_definition(
			vhdlParser::Protected_type_definitionContext *ctx);
	
	static std::unique_ptr<hdlObjects::HdlEnumDef> visitEnumeration_type_definition(
			vhdlParser::Enumeration_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitInteger_type_definition(
			vhdlParser::Integer_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitFloating_type_definition(
			vhdlParser::Floating_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitPhysical_type_definition(
			vhdlParser::Physical_type_definitionContext *ctx);

	static std::unique_ptr<hdlObjects::iHdlExprItem> visitArray_type_definition(
			vhdlParser::Array_type_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitUnbounded_array_definition(
			vhdlParser::Unbounded_array_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitConstrained_array_definition(
			vhdlParser::Constrained_array_definitionContext *ctx);
	static std::unique_ptr<hdlObjects::HdlClassDef> visitRecord_type_definition(
			vhdlParser::Record_type_definitionContext *ctx);

	static std::unique_ptr<hdlObjects::HdlVariableDef> visitSubtype_declaration(
			vhdlParser::Subtype_declarationContext *ctx);

};

}
}
