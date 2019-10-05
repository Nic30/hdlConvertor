#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlNamespace.h>
#include <hdlConvertor/hdlObjects/hdlNamespace.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlStmProcess.h>
#include <hdlConvertor/hdlObjects/hdlNamespace.h>
#include <hdlConvertor/hdlObjects/hdlNamespace.h>
#include <hdlConvertor/hdlObjects/hdlValue.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
#include <hdlConvertor/hdlObjects/hdlFunctionDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlPackageParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	std::unique_ptr<hdlObjects::HdlNamespace> p;
	bool hierarchyOnly;

	VhdlPackageParser(bool _hierarchyOnly);
	std::unique_ptr<hdlObjects::HdlNamespace> visitPackage_body(
			vhdlParser::Package_bodyContext *ctx);
	void visitPackage_body_declarative_item(
			vhdlParser::Package_body_declarative_itemContext *ctx);

};

}
}
