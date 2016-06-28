#pragma once

#include <vector>
#include <cstddef>
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/operatorType.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "literalParser.h"
#include "exprParser.h"

using namespace antlr4;
using namespace vhdl;

class ReferenceParser {
public:
	static Expr * visitSelected_name(Ref<vhdlParser::Selected_nameContext> ctx);
	static Expr * visitSuffix(Ref<vhdlParser::SuffixContext> ctx);

	static Expr * visitName(Ref<vhdlParser::NameContext> ctx);
	static Expr * visitAttribute_designator(
			Expr * selectedName,
			Ref<vhdlParser::Attribute_designatorContext> ctx);
	static Expr * visitName_attribute_part(
			Expr * selectedName,
			Ref<vhdlParser::Name_attribute_partContext> ctx);
	static Expr * visitName_part_specificator(
			Expr * selectedName,
			Ref<vhdlParser::Name_part_specificatorContext> ctx);
	static Expr * visitName_part(Ref<vhdlParser::Name_partContext> ctx);
};
