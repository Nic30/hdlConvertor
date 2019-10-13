#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
#include <hdlConvertor/hdlObjects/hdlFunctionDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlSubProgramParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlObjects::HdlFunctionDef> visitSubprogram_body(
			vhdlParser::Subprogram_bodyContext *ctx);
	static std::unique_ptr<hdlObjects::HdlFunctionDef> visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlFunctionDef> visitProcedure_specification(
			vhdlParser::Procedure_specificationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlFunctionDef> visitFunction_specification(
			vhdlParser::Function_specificationContext *ctx);
	static std::unique_ptr<std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitFormal_parameter_list(
			vhdlParser::Formal_parameter_listContext *ctx);
	static void visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext *ctx);
};

}
}
