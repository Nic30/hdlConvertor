#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlReferenceParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlObjects::iHdlExpr> visitSelected_name(
			vhdlParser::Selected_nameContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitSuffix(
			vhdlParser::SuffixContext *ctx);

	static std::unique_ptr<hdlObjects::iHdlExpr> visitName(
			vhdlParser::NameContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitAttribute_name(
			vhdlParser::Attribute_nameContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitName_attribute_part(
			vhdlParser::Name_attribute_partContext *ctx,
			std::unique_ptr<hdlObjects::iHdlExpr> selected_name);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitAttribute_designator(
			vhdlParser::Attribute_designatorContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitName_literal(
			vhdlParser::Name_literalContext *ctx);
	static std::unique_ptr<hdlObjects::iHdlExpr> visitName_slice_part(
			vhdlParser::Name_slice_partContext *ctx,
			std::unique_ptr<hdlObjects::iHdlExpr> selected_name);
};

}
}
