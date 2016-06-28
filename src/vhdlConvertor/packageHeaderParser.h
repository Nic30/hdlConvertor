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
			Ref<vhdlParser::Package_declarationContext> ctx);
	void visitPackage_declarative_part(
			PackageHeader * ph,
			Ref<vhdlParser::Package_declarative_partContext> ctx);
	static Function * visitSubprogram_declaration(
			Ref<vhdlParser::Subprogram_declarationContext> ctx);
	static Function * visitSubprogram_specification(
			Ref<vhdlParser::Subprogram_specificationContext> ctx);

	static Function * visitProcedure_specification(
			Ref<vhdlParser::Procedure_specificationContext> ctx);
	static Function * visitFunction_specification(
			Ref<vhdlParser::Function_specificationContext> ctx);

	static std::vector<Variable*> * visitFormal_parameter_list(
			Ref<vhdlParser::Formal_parameter_listContext> ctx);

	void visitPackage_declarative_item(
			Ref<vhdlParser::Package_declarative_itemContext> ctx);
	Entity * visitComponent_declaration(
			Ref<vhdlParser::Component_declarationContext> ctx);
	static std::vector<Variable*> * visitConstant_declaration(
			Ref<vhdlParser::Constant_declarationContext> context);
	static Variable * visitSubtype_declaration(Ref<vhdlParser::Subtype_declarationContext> ctx);
};
