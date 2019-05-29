#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/statement.h"

namespace hdlConvertor {
namespace vhdl {

class SimultaneousStatementParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	using Statement = hdlObjects::Statement;

	static Statement * visitSimultaneous_statement(
			vhdlParser::Simultaneous_statementContext * ctx);
	static Statement * visitSimple_simultaneous_statement(
			vhdlParser::Simple_simultaneous_statementContext * ctx);
	static Statement * visitSimultaneous_if_statement(
			vhdlParser::Simultaneous_if_statementContext * ctx);
	static Statement * visitSimultaneous_case_statement(
			vhdlParser::Simultaneous_case_statementContext * ctx);
	static Statement * visitSimultaneous_procedural_statement(
			vhdlParser::Simultaneous_procedural_statementContext * ctx);
	static std::vector<Statement *> * visitSimultaneous_statement_part(
			vhdlParser::Simultaneous_statement_partContext * ctx);
};

}
}
