#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"

class ReferenceParser {
public:
	static Expr * visitSelected_name(vhdl::vhdlParser::Selected_nameContext* ctx);
	static Expr * visitSuffix(vhdl::vhdlParser::SuffixContext* ctx);

	static Expr * visitName(vhdl::vhdlParser::NameContext* ctx);
	static Expr * visitAttribute_designator(
			Expr * selectedName,
			vhdl::vhdlParser::Attribute_designatorContext* ctx);
	static Expr * visitName_attribute_part(
			Expr * selectedName,
			vhdl::vhdlParser::Name_attribute_partContext* ctx);
	static Expr * visitName_part_specificator(
			Expr * selectedName,
			vhdl::vhdlParser::Name_part_specificatorContext* ctx);
	static Expr * visitName_part(vhdl::vhdlParser::Name_partContext* ctx);
};
