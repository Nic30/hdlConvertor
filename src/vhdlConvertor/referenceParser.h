#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"

namespace hdlConvertor {
namespace vhdl {

class ReferenceParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	using Expr = hdlObjects::Expr;

	static Expr * visitSelected_name(vhdlParser::Selected_nameContext* ctx);
	static Expr * visitSuffix(vhdlParser::SuffixContext* ctx);

	static Expr * visitName(vhdlParser::NameContext* ctx);
	static Expr * visitAttribute_designator(Expr * selectedName,
			vhdlParser::Attribute_designatorContext* ctx);
	static Expr * visitName_attribute_part(Expr * selectedName,
			vhdlParser::Name_attribute_partContext* ctx);
	static Expr * visitName_part_specificator(Expr * selectedName,
			vhdlParser::Name_part_specificatorContext* ctx);
	static Expr * visitName_part(vhdlParser::Name_partContext* ctx);
	static std::vector<Expr*> * visitName_slice_part(vhdlParser::Name_slice_partContext *ctx);
};

}
}
