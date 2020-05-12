#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlExpr.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlReferenceParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlAst::iHdlExprItem> visitSelected_name(
			vhdlParser::Selected_nameContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitSuffix(
			vhdlParser::SuffixContext *ctx);

	static std::unique_ptr<hdlAst::iHdlExprItem> visitName(
			vhdlParser::NameContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitAttribute_name(
			vhdlParser::Attribute_nameContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitName_attribute_part(
			vhdlParser::Name_attribute_partContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> selected_name);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitAttribute_designator(
			vhdlParser::Attribute_designatorContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitName_literal(
			vhdlParser::Name_literalContext *ctx);
	static std::unique_ptr<hdlAst::iHdlExprItem> visitName_slice_part(
			vhdlParser::Name_slice_partContext *ctx,
			std::unique_ptr<hdlAst::iHdlExprItem> selected_name);
};

}
}
