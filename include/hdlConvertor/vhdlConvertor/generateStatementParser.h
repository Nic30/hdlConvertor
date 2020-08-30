#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlStmBlock.h>
#include <hdlConvertor/hdlAst/hdlStmIf.h>
#include <hdlConvertor/hdlAst/hdlStmCase.h>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <hdlConvertor/vhdlConvertor/commentParser.h>
#include <hdlConvertor/vhdlConvertor/baseVhdlParser.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlGenerateStatementParser : public BaseVhdlParser {
public:
	using BaseVhdlParser::BaseVhdlParser;
	using vhdlParser = vhdl_antlr::vhdlParser;

	std::unique_ptr<hdlAst::iHdlStatement> visitGenerate_statement(
			vhdlParser::Generate_statementContext *ctx);
	std::unique_ptr<hdlAst::iHdlStatement> visitFor_generate_statement(
			vhdlParser::For_generate_statementContext *ctx);
	std::unique_ptr<hdlAst::HdlStmIf> visitIf_generate_statement(
			vhdlParser::If_generate_statementContext *ctx);
	std::unique_ptr<hdlAst::HdlStmCase> visitCase_generate_statement(
			vhdlParser::Case_generate_statementContext *ctx);
	template<typename CTX_T>
	std::unique_ptr<hdlAst::iHdlObj> visitGenerate_statement_body(CTX_T *ctx);
	static hdlAst::HdlModuleDec* visitComponent_declaration(
			vhdlParser::Component_declarationContext *ctx);
};

}
}
