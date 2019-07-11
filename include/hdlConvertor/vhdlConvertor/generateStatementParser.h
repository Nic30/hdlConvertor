#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlModuleDec.h>

namespace hdlConvertor {
namespace vhdl {

class GenerateStatementParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	bool hierarchyOnly;

	GenerateStatementParser(bool _hierarchyOnly);

	hdlObjects::iHdlStatement * visitGenerate_statement(
			vhdlParser::Generate_statementContext *ctx);
	hdlObjects::iHdlStatement * visitFor_generate_statement(
			vhdlParser::For_generate_statementContext *ctx);
	hdlObjects::iHdlStatement * visitIf_generate_statement(
			vhdlParser::If_generate_statementContext *ctx);
	hdlObjects::iHdlStatement * visitCase_generate_statement(
			vhdlParser::Case_generate_statementContext *ctx);
	void visitGenerate_statement_body(
			vhdlParser::Generate_statement_bodyContext *ctx,
			std::vector<hdlObjects::iHdlObj*> & objs);
	static hdlObjects::HdlModuleDec * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);
};

}
}
