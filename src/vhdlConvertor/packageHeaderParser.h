#pragma once

#include <vector>
#include "vhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/packageHeader.h"

class PackageHeaderParser {
	PackageHeader * ph;
	bool hierarchyOnly;
public:
	PackageHeaderParser(bool _hierarchyOnly);
	PackageHeader * visitPackage_declaration(
			vhdl::vhdlParser::Package_declarationContext* ctx);
	void visitPackage_declarative_part(
			PackageHeader * ph,
			vhdl::vhdlParser::Package_declarative_partContext* ctx);
	static Function * visitSubprogram_declaration(
			vhdl::vhdlParser::Subprogram_declarationContext* ctx);
	static Function * visitSubprogram_specification(
			vhdl::vhdlParser::Subprogram_specificationContext* ctx);

	static Function * visitProcedure_specification(
			vhdl::vhdlParser::Procedure_specificationContext* ctx);
	static Function * visitFunction_specification(
			vhdl::vhdlParser::Function_specificationContext* ctx);

	static std::vector<Variable*> * visitFormal_parameter_list(
			vhdl::vhdlParser::Formal_parameter_listContext* ctx);

	void visitPackage_declarative_item(
			vhdl::vhdlParser::Package_declarative_itemContext* ctx);
	Entity * visitComponent_declaration(
			vhdl::vhdlParser::Component_declarationContext* ctx);
	static std::vector<Variable*> * visitConstant_declaration(
			vhdl::vhdlParser::Constant_declarationContext* ctx);
	static Variable * visitSubtype_declaration(
			vhdl::vhdlParser::Subtype_declarationContext* ctx);
};
