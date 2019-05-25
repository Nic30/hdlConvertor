#pragma once
#include <vector>

#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/generate.h"
#include "../hdlObjects/entity.h"

namespace hdlConvertor {
namespace vhdl {

class GenerateStatementParser {
public:
	using Generate = hdlObjects::Generate;
	using vhdlParser = vhdl_antlr::vhdlParser;


	static Generate * visitGenerate_statement(
			vhdlParser::Generate_statementContext *ctx);
	static Generate * visitFor_generate_statement(
			vhdlParser::For_generate_statementContext *ctx);
	static Generate * visitIf_generate_statement(
			vhdlParser::If_generate_statementContext *ctx);
	static Generate * visitCase_generate_statement(
			vhdlParser::Case_generate_statementContext *ctx);
	static char * visitLabel_colon(vhdlParser::Label_colonContext * ctx);
	static void visitCase_generate_alternative(
			vhdlParser::Case_generate_alternativeContext *ctx, Generate * g);
	static void visitBlock_declarative_item(
			vhdlParser::Block_declarative_itemContext * ctx, Generate * g);
	static void visitGenerate_statement_body(
			vhdlParser::Generate_statement_bodyContext *ctx, Generate * g);
	static void visitArchitecture_statement(
			vhdlParser::Architecture_statementContext * ctx, Generate * g);
	static hdlObjects::Entity * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);

};

}
}
