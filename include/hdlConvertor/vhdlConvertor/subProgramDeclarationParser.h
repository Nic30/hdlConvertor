#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/hdlAst/hdlFunctionDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlSubProgramDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlAst::HdlFunctionDef> visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext *ctx);
	static std::unique_ptr<hdlAst::HdlFunctionDef> visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext *ctx);
	static std::unique_ptr<hdlAst::HdlFunctionDef> visitProcedure_specification(
			vhdlParser::Procedure_specificationContext *ctx);
	static std::unique_ptr<hdlAst::HdlFunctionDef> visitFunction_specification(
			vhdlParser::Function_specificationContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlAst::HdlIdDef>>> visitFormal_parameter_list(
			vhdlParser::Formal_parameter_listContext *ctx);
};

}
}
