#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace vhdl {

class ReferenceParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::iHdlExpr* visitSelected_name(
			vhdlParser::Selected_nameContext *ctx);
	static hdlObjects::iHdlExpr* visitSuffix(vhdlParser::SuffixContext *ctx);

	static hdlObjects::iHdlExpr* visitName(vhdlParser::NameContext *ctx);
	static hdlObjects::iHdlExpr* visitAttribute_name(
			vhdlParser::Attribute_nameContext *ctx);
	static hdlObjects::iHdlExpr* visitName_attribute_part(
			vhdlParser::Name_attribute_partContext *ctx,
			hdlObjects::iHdlExpr *selected_name);
	static hdlObjects::iHdlExpr* visitAttribute_designator(
			vhdlParser::Attribute_designatorContext *ctx);
	static hdlObjects::iHdlExpr* visitName_literal(
			vhdlParser::Name_literalContext *ctx);
	static hdlObjects::iHdlExpr* visitName_slice_part(
			vhdlParser::Name_slice_partContext *ctx,
			hdlObjects::iHdlExpr *selected_name);
};

}
}
