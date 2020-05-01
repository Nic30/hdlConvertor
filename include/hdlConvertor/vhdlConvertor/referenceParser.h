#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlReferenceParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlObjects::iHdlExprItem> visitSelected_name(
			vhdlParser::Selected_nameContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitSuffix(
			vhdlParser::SuffixContext *ctx);

	static std::unique_ptr<hdlObjects::iHdlExprItem> visitName(
			vhdlParser::NameContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitAttribute_name(
			vhdlParser::Attribute_nameContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitName_attribute_part(
			vhdlParser::Name_attribute_partContext *ctx,
			std::unique_ptr<hdlObjects::iHdlExprItem> selected_name);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitAttribute_designator(
			vhdlParser::Attribute_designatorContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitName_literal(
			vhdlParser::Name_literalContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExprItem> visitName_slice_part(
			vhdlParser::Name_slice_partContext *ctx,
			std::unique_ptr<hdlObjects::iHdlExprItem> selected_name);
};

}
}
