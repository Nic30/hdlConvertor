#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
#include "../hdlObjects/hdlFunctionDef.h"

namespace hdlConvertor {
namespace vhdl {

class SubProgramParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::HdlFunctionDef * visitSubprogram_body(
			vhdlParser::Subprogram_bodyContext* ctx);
	static hdlObjects::HdlFunctionDef * visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext* ctx);
	static hdlObjects::HdlFunctionDef * visitProcedure_specification(
			vhdlParser::Procedure_specificationContext* ctx);
	static hdlObjects::HdlFunctionDef * visitFunction_specification(
			vhdlParser::Function_specificationContext* ctx);
	static std::vector<hdlObjects::HdlVariableDef*> * visitFormal_parameter_list(
			vhdlParser::Formal_parameter_listContext* ctx);
	static void visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext* ctx);
	static std::vector<hdlObjects::iHdlStatement *> * visitSubprogram_statement_part(
			vhdlParser::Subprogram_statement_partContext* ctx);
};

}
}
