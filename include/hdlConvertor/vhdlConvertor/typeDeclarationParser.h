#pragma once

#include <hdlConvertor/vhdlConvertor/literalParser.h>
#include <hdlConvertor/hdlAst/hdlTypes.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlTypeDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlAst::iHdlExprItem> visitSubtype_indication(
			vhdlParser::Subtype_indicationContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitConstraint(
			std::unique_ptr<hdlAst::iHdlExprItem> selectedName,
			vhdlParser::ConstraintContext *ctx);
	static std::pair<std::unique_ptr<hdlAst::iHdlExprItem>,
			std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> > visitArray_constraint(
			vhdlParser::Array_constraintContext *ctx);
	static std::vector<std::unique_ptr<hdlAst::iHdlExprItem>> visitIndex_constraint(
			vhdlParser::Index_constraintContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitRecord_constraint(
			vhdlParser::Record_constraintContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitArray_element_constraint(
			vhdlParser::Array_element_constraintContext *ctx);

	static std::unique_ptr<hdlAst::HdlIdDef> visitType_declaration(
			vhdlParser::Type_declarationContext *ctx);
	static std::unique_ptr<hdlAst::HdlIdDef> visitFull_type_declaration(
			vhdlParser::Full_type_declarationContext *ctx);
	static std::unique_ptr<hdlAst::HdlIdDef> visitIncomplete_type_declaration(
			vhdlParser::Incomplete_type_declarationContext *ctx);
	static std::unique_ptr<hdlAst::HdlIdDef> visitType_definition(
			std::string &&name, vhdlParser::Type_definitionContext *ctx);

	static std::unique_ptr<hdlAst::iHdlExprItem> visitScalar_type_definition(
			vhdlParser::Scalar_type_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitComposite_type_definition(
			vhdlParser::Composite_type_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitAccess_type_definition(
			vhdlParser::Access_type_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitFile_type_definition(
			vhdlParser::File_type_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitProtected_type_definition(
			vhdlParser::Protected_type_definitionContext *ctx);

	static std::unique_ptr<hdlAst::HdlEnumDef> visitEnumeration_type_definition(
			vhdlParser::Enumeration_type_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitRange_constraint(
			vhdlParser::Range_constraintContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitInteger_type_definition(
			vhdlParser::Integer_type_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitFloating_type_definition(
			vhdlParser::Floating_type_definitionContext *ctx);
	static std::unique_ptr<hdlAst::HdlPhysicalDef> visitPhysical_type_definition(
			vhdlParser::Physical_type_definitionContext *ctx);

	static std::unique_ptr<hdlAst::iHdlExprItem> visitArray_type_definition(
			vhdlParser::Array_type_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitUnbounded_array_definition(
			vhdlParser::Unbounded_array_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitIndex_subtype_definition(
			vhdlParser::Index_subtype_definitionContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitConstrained_array_definition(
			vhdlParser::Constrained_array_definitionContext *ctx);
	static std::unique_ptr<hdlAst::HdlClassDef> visitRecord_type_definition(
			vhdlParser::Record_type_definitionContext *ctx);
	static std::unique_ptr<std::vector<std::unique_ptr<hdlAst::HdlIdDef>>> visitElement_declaration(
			vhdlParser::Element_declarationContext *ctx);

	static std::unique_ptr<hdlAst::HdlIdDef> visitSubtype_declaration(
			vhdlParser::Subtype_declarationContext *ctx);

};

}
}
