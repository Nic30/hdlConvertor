#pragma once

#include <vector>

#include "vhdlParser/vhdlParser.h"

#include "../hdlObjects/statement.h"
#include "../hdlObjects/package.h"
#include "../hdlObjects/packageHeader.h"
#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/named.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/process.h"
#include "../hdlObjects/package.h"
#include "../hdlObjects/packageHeader.h"

namespace hdlConvertor {
namespace vhdl {

class PackageParser {
public:
	using Variable = hdlObjects::Variable;
	using Statement = hdlObjects::Statement;
	using vhdlParser = vhdl_antlr::vhdlParser;

	hdlObjects::Package * p;
	bool hierarchyOnly;

	PackageParser(bool _hierarchyOnly);
	hdlObjects::Package * visitPackage_body(
			vhdlParser::Package_bodyContext* ctx);
	void visitPackage_body_declarative_part(hdlObjects::aPackage * p,
			vhdlParser::Package_body_declarative_partContext* ctx);
	void visitPackage_body_declarative_item(
			vhdlParser::Package_body_declarative_itemContext* ctx);

};

}
}
