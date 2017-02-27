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
	static Expr * visitSelected_name(vhdlParser::Selected_nameContext* ctx);
	static Expr * visitSuffix(vhdlParser::SuffixContext* ctx);

	static Expr * visitName(vhdlParser::NameContext* ctx);
	static Expr * visitAttribute_designator(
			Expr * selectedName,
			vhdlParser::Attribute_designatorContext* ctx);
	static Expr * visitName_attribute_part(
			Expr * selectedName,
			vhdlParser::Name_attribute_partContext* ctx);
	static Expr * visitName_part_specificator(
			Expr * selectedName,
			vhdlParser::Name_part_specificatorContext* ctx);
	static Expr * visitName_part(vhdlParser::Name_partContext* ctx);
};
