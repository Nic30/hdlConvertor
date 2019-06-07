#pragma once
#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/entity.h>
#include <hdlConvertor/hdlObjects/statement.h>

namespace hdlConvertor {
namespace vhdl {

class GenerateStatementParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	using Statement = hdlObjects::Statement;

	bool hierarchyOnly;

	GenerateStatementParser(bool _hierarchyOnly);

	Statement * visitGenerate_statement(
			vhdlParser::Generate_statementContext *ctx);
	Statement * visitFor_generate_statement(
			vhdlParser::For_generate_statementContext *ctx);
	Statement * visitIf_generate_statement(
			vhdlParser::If_generate_statementContext *ctx);
	Statement * visitCase_generate_statement(
			vhdlParser::Case_generate_statementContext *ctx);
	void visitGenerate_statement_body(
			vhdlParser::Generate_statement_bodyContext *ctx,
			std::vector<hdlObjects::iHdlObj*> & objs);
	static hdlObjects::Entity * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);
};

}
}
