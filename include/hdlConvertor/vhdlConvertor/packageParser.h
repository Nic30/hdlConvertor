#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlNamespace.h>
#include <hdlConvertor/hdlAst/hdlNamespace.h>
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/hdlNamespace.h>
#include <hdlConvertor/hdlAst/hdlNamespace.h>
#include <hdlConvertor/hdlAst/hdlValue.h>
#include <hdlConvertor/hdlAst/hdlVariableDef.h>
#include <hdlConvertor/hdlAst/hdlFunctionDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlPackageParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	std::unique_ptr<hdlAst::HdlValueIdspace> p;
	bool hierarchyOnly;

	VhdlPackageParser(bool _hierarchyOnly);
	std::unique_ptr<hdlAst::HdlValueIdspace> visitPackage_body(
			vhdlParser::Package_bodyContext *ctx);
	void visitPackage_body_declarative_item(
			vhdlParser::Package_body_declarative_itemContext *ctx);

};

}
}
