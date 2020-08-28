#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>
#include <hdlConvertor/hdlAst/hdlFunctionDef.h>
#include <hdlConvertor/vhdlConvertor/baseVhdlParser.h>


namespace hdlConvertor {
namespace vhdl {

class VhdlSubProgramParser : public BaseVhdlParser {
public:
	using BaseVhdlParser::BaseVhdlParser;
	using vhdlParser = vhdl_antlr::vhdlParser;

	std::unique_ptr<hdlAst::HdlFunctionDef> visitSubprogram_body(
			vhdlParser::Subprogram_bodyContext *ctx);
	std::unique_ptr<hdlAst::HdlFunctionDef> visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext *ctx);
	std::unique_ptr<hdlAst::HdlFunctionDef> visitProcedure_specification(
			vhdlParser::Procedure_specificationContext *ctx);
	std::unique_ptr<hdlAst::HdlFunctionDef> visitFunction_specification(
			vhdlParser::Function_specificationContext *ctx);
	std::unique_ptr<std::vector<std::unique_ptr<hdlAst::HdlIdDef>>> visitFormal_parameter_list(
			vhdlParser::Formal_parameter_listContext *ctx);
	void visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext *ctx);
};

}
}
