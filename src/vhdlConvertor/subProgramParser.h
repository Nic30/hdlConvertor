#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/statement.h"


namespace hdlConvertor {
namespace vhdl {

class SubProgramParser {
public:
	using Function = hdlObjects::Function;
	using Variable = hdlObjects::Variable;
	using Statement = hdlObjects::Statement;
	using vhdlParser = vhdl_antlr::vhdlParser;

	static Function * visitSubprogram_body(
			vhdlParser::Subprogram_bodyContext* ctx);
	static Function * visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext* ctx);
	static Function * visitProcedure_specification(
			vhdlParser::Procedure_specificationContext* ctx);
	static Function * visitFunction_specification(
			vhdlParser::Function_specificationContext* ctx);
	static std::vector<Variable*> * visitFormal_parameter_list(
			vhdlParser::Formal_parameter_listContext* ctx);
	static void visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext* ctx);
	static std::vector<Statement *> * visitSubprogram_statement_part(
			vhdlParser::Subprogram_statement_partContext* ctx);
};

}
}
