#pragma once

#include <vector>
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/packageHeader.h"

#include "exprParser.h"
#include "entityParser.h"
#include "interfaceParser.h"

using namespace antlr4;
using namespace vhdl;

class PackageHeaderParser {
	PackageHeader * ph;
	bool hierarchyOnly;
public:
	PackageHeaderParser(bool _hierarchyOnly);
	PackageHeader * visitPackage_declaration(
			vhdlParser::Package_declarationContext* ctx);
	void visitPackage_declarative_part(
			PackageHeader * ph,
			vhdlParser::Package_declarative_partContext* ctx);
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

	void visitPackage_declarative_item(
			vhdlParser::Package_declarative_itemContext* ctx);
	Entity * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);
	static std::vector<Variable*> * visitConstant_declaration(
			vhdlParser::Constant_declarationContext* ctx);
	static Variable * visitSubtype_declaration(vhdlParser::Subtype_declarationContext* ctx);
};
