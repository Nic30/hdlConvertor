#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/process.h"
#include "../hdlObjects/statement.h"

namespace hdlConvertor {
namespace vhdl {

class ProcessParser {

public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	using Expr = hdlObjects::Expr;
	using Process = hdlObjects::Process;
	using Statement = hdlObjects::Statement;

	static Process * visitProcess_statement(
			vhdlParser::Process_statementContext * ctx);
	static char * visitLabel_colon(vhdlParser::Label_colonContext * ctx);
	static std::vector<Expr*> * visitSensitivity_list(
			vhdlParser::Sensitivity_listContext *ctx);
	static void visitProcess_declarative_item(
			vhdlParser::Process_declarative_itemContext *ctx, Process * p);
	static void visitProcess_declarative_part(
			vhdlParser::Process_declarative_partContext *ctx, Process * p);
	static std::vector<Statement *> * visitProcess_statement_part(
			vhdlParser::Process_statement_partContext *ctx);
};

}
}
