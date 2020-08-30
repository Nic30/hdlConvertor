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
#include <hdlConvertor/vhdlConvertor/baseVhdlParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlPackageHeaderParser : public BaseVhdlParser {
	std::unique_ptr<hdlAst::HdlValueIdspace> ph;
public:
	using BaseVhdlParser::BaseVhdlParser;
	using vhdlParser = vhdl_antlr::vhdlParser;

	std::unique_ptr<hdlAst::HdlValueIdspace> visitPackage_declaration(
			vhdlParser::Package_declarationContext *ctx);
	void visitPackage_declarative_item(
			vhdlParser::Package_declarative_itemContext *ctx);
	std::unique_ptr<hdlAst::HdlModuleDec> visitComponent_declaration(
			vhdlParser::Component_declarationContext *ctx);
};

}
}
