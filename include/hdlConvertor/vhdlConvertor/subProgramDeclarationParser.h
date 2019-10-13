#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlVariableDef.h>
#include <hdlConvertor/hdlObjects/hdlFunctionDef.h>

namespace hdlConvertor {
namespace vhdl {

class VhdlSubProgramDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static std::unique_ptr<hdlObjects::HdlFunctionDef> visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlFunctionDef> visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlFunctionDef> visitProcedure_specification(
			vhdlParser::Procedure_specificationContext *ctx);
	static std::unique_ptr<hdlObjects::HdlFunctionDef> visitFunction_specification(
			vhdlParser::Function_specificationContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitFormal_parameter_list(
			vhdlParser::Formal_parameter_listContext *ctx);
	static std::unique_ptr<
			std::vector<std::unique_ptr<hdlObjects::HdlVariableDef>>> visitSubprogram_declarative_item(
			vhdlParser::Subprogram_declarative_itemContext *ctx);
};

}
}
