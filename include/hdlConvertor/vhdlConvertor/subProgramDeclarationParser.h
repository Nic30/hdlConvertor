#pragma once

#include <vector>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>

#include <hdlConvertor/hdlObjects/hdlFunction.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace vhdl {

class SubProgramDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;

	static hdlObjects::HdlFunction * visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext* ctx);
	static hdlObjects::HdlFunction * visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext* ctx);
	static hdlObjects::HdlFunction * visitProcedure_specification(
			vhdlParser::Procedure_specificationContext* ctx);
	static hdlObjects::HdlFunction * visitFunction_specification(
			vhdlParser::Function_specificationContext* ctx);
	static std::vector<hdlObjects::HdlVariableDef*> * visitFormal_parameter_list(
			vhdlParser::Formal_parameter_listContext* ctx);
	static std::vector<hdlObjects::HdlVariableDef*>* visitSubprogram_declarative_part(
			vhdlParser::Subprogram_declarative_partContext* ctx);
	static std::vector<hdlObjects::HdlVariableDef*> * visitSubprogram_declarative_item(
			vhdlParser::Subprogram_declarative_itemContext* ctx);
};

}
}
