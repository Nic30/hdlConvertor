#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlFunction.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class SubProgramParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::HdlFunction * visitSubprogram_body(
			vhdlParser::Subprogram_bodyContext* ctx);
	static hdlObjects::HdlFunction * visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext* ctx);
	static hdlObjects::HdlFunction * visitProcedure_specification(
			vhdlParser::Procedure_specificationContext* ctx);
	static hdlObjects::HdlFunction * visitFunction_specification(
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
