#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>

namespace hdlConvertor {
namespace vhdl {

class ReferenceParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::iHdlExpr * visitSelected_name(
			vhdlParser::Selected_nameContext* ctx);
	static hdlObjects::iHdlExpr * visitSuffix(vhdlParser::SuffixContext* ctx);

	static hdlObjects::iHdlExpr * visitName(vhdlParser::NameContext* ctx);
	static hdlObjects::iHdlExpr* visitAttribute_name(
			vhdlParser::Attribute_nameContext *ctx);
	static hdlObjects::iHdlExpr * visitAttribute_designator(
			vhdlParser::Attribute_designatorContext* ctx);
	static hdlObjects::iHdlExpr * visitName_attribute_part(
			vhdlParser::Name_attribute_partContext* ctx);
	static hdlObjects::iHdlExpr * visitName_part_specificator(
			hdlObjects::iHdlExpr * selectedName,
			vhdlParser::Name_part_specificatorContext* ctx);
	static hdlObjects::iHdlExpr * visitName_part(
			vhdlParser::Name_partContext* ctx);
	static std::vector<hdlObjects::iHdlExpr*> * visitName_slice_part(
			vhdlParser::Name_slice_partContext *ctx);
	static hdlObjects::iHdlExpr * visitSimple_name(
			vhdlParser::Simple_nameContext * ctx);
};

}
}
