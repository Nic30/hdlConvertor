#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlStmBlock.h>
#include <hdlConvertor/hdlObjects/hdlStmIf.h>
#include <hdlConvertor/hdlObjects/hdlStmCase.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlGenerateStatementParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;

	VhdlGenerateStatementParser(bool _hierarchyOnly);

	std::unique_ptr<hdlObjects::iHdlStatement> visitGenerate_statement(
			vhdlParser::Generate_statementContext *ctx);
	std::unique_ptr<hdlObjects::iHdlStatement> visitFor_generate_statement(
			vhdlParser::For_generate_statementContext *ctx);
	std::unique_ptr<hdlObjects::HdlStmIf> visitIf_generate_statement(
			vhdlParser::If_generate_statementContext *ctx);
	std::unique_ptr<hdlObjects::HdlStmCase> visitCase_generate_statement(
			vhdlParser::Case_generate_statementContext *ctx);
	std::unique_ptr<hdlObjects::HdlStmBlock> visitGenerate_statement_body(
			vhdlParser::Generate_statement_bodyContext *ctx);
	static hdlObjects::HdlModuleDec* visitComponent_declaration(
			vhdlParser::Component_declarationContext *ctx);
};

}
}
