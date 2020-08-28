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
#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/hdlAst/hdlFunctionDef.h>
#include <hdlConvertor/vhdlConvertor/baseVhdlParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlPackageParser : public BaseVhdlParser {
public:
	using BaseVhdlParser::BaseVhdlParser;
	using vhdlParser = vhdl_antlr::vhdlParser;

	std::unique_ptr<hdlAst::HdlValueIdspace> p;

	std::unique_ptr<hdlAst::HdlValueIdspace> visitPackage_body(
			vhdlParser::Package_bodyContext *ctx);

};

}
}
