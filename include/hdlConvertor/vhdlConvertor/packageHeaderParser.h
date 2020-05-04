#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/hdlNamespace.h>
#include <hdlConvertor/hdlAst/hdlStmProcess.h>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/hdlAst/hdlFunctionDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlPackageHeaderParser {
	std::unique_ptr<hdlAst::HdlValueIdspace> ph;
	bool hierarchyOnly;
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	VhdlPackageHeaderParser(bool _hierarchyOnly);
	std::unique_ptr<hdlAst::HdlValueIdspace> visitPackage_declaration(
			vhdlParser::Package_declarationContext *ctx);
	void visitPackage_header(
			vhdlParser::Package_headerContext *ctx);
	void visitPackage_declarative_part(
			vhdlParser::Package_declarative_partContext *ctx);
	void visitPackage_declarative_item(
			vhdlParser::Package_declarative_itemContext *ctx);
	std::unique_ptr<hdlAst::HdlModuleDec> visitComponent_declaration(
			vhdlParser::Component_declarationContext *ctx);
};

}
}
