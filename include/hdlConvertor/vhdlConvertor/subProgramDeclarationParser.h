#pragma once
#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/variable.h"

namespace hdlConvertor {
namespace vhdl {

class SubProgramDeclarationParser {
public:
	using vhdlParser = vhdl_antlr::vhdlParser;
	using Function = hdlObjects::Function;
	using Variable = hdlObjects::Variable;

	static Function * visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext* ctx);
	static Function * visitSubprogram_specification(
			vhdlParser::Subprogram_specificationContext* ctx);
	static Function * visitProcedure_specification(
			vhdlParser::Procedure_specificationContext* ctx);
	static Function * visitFunction_specification(
			vhdlParser::Function_specificationContext* ctx);
	static std::vector<Variable*> * visitFormal_parameter_list(
			vhdlParser::Formal_parameter_listContext* ctx);
	static std::vector<Variable*>* visitSubprogram_declarative_part(
			vhdlParser::Subprogram_declarative_partContext* ctx);
	static std::vector<Variable*> * visitSubprogram_declarative_item(
			vhdlParser::Subprogram_declarative_itemContext* ctx);
};

}
}
