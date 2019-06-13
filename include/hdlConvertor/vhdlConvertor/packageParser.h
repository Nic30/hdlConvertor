#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/statement.h>
#include <hdlConvertor/hdlObjects/package.h>
#include <hdlConvertor/hdlObjects/packageHeader.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/function.h>
#include <hdlConvertor/hdlObjects/variable.h>
#include <hdlConvertor/hdlObjects/process.h>
#include <hdlConvertor/hdlObjects/package.h>
#include <hdlConvertor/hdlObjects/packageHeader.h>
#include "../hdlObjects/literalVal.h"

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
	void visitPackage_body_declarative_part(
			vhdlParser::Package_body_declarative_partContext* ctx);
	void visitPackage_body_declarative_item(
			vhdlParser::Package_body_declarative_itemContext* ctx);

};

}
}
