#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlNamespace.h>
#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
#include "../hdlObjects/hdlFunctionDef.h"

namespace hdlConvertor {
namespace vhdl {

class PackageHeaderParser {
	hdlObjects::HdlNamespace * ph;
	bool hierarchyOnly;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	PackageHeaderParser(bool _hierarchyOnly);
	hdlObjects::HdlNamespace * visitPackage_declaration(
			vhdlParser::Package_declarationContext* ctx);
	void visitPackage_declarative_part(
			vhdlParser::Package_declarative_partContext* ctx);
	void visitPackage_declarative_item(
			vhdlParser::Package_declarative_itemContext* ctx);
	hdlObjects::HdlModuleDec * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);
	static hdlObjects::HdlVariableDef * visitSubtype_declaration(
			vhdlParser::Subtype_declarationContext* ctx);
};

}
}
