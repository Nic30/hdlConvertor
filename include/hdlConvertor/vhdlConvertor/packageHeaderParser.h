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
#include <hdlConvertor/hdlObjects/hdlFunctionDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlPackageHeaderParser {
	std::unique_ptr<hdlObjects::HdlNamespace> ph;
	bool hierarchyOnly;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	VhdlPackageHeaderParser(bool _hierarchyOnly);
	std::unique_ptr<hdlObjects::HdlNamespace> visitPackage_declaration(
			vhdlParser::Package_declarationContext *ctx);
	void visitPackage_declarative_part(
			vhdlParser::Package_declarative_partContext *ctx);
	void visitPackage_declarative_item(
			vhdlParser::Package_declarative_itemContext *ctx);
	std::unique_ptr<hdlObjects::HdlModuleDec> visitComponent_declaration(
			vhdlParser::Component_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlVariableDef> visitSubtype_declaration(
			vhdlParser::Subtype_declarationContext *ctx);
};

}
}
