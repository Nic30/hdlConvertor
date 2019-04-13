#pragma once

#include <vector>

#include "vhdlParser/vhdlParser.h"

#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/statement.h"
#include "../hdlObjects/package.h"
#include "../hdlObjects/packageHeader.h"

class PackageParser {
public:
	Package * p;
	bool hierarchyOnly;
	PackageParser(bool _hierarchyOnly);
	Package * visitPackage_body(vhdl::vhdlParser::Package_bodyContext* ctx);
	void visitPackage_body_declarative_part(aPackage * p,
			vhdl::vhdlParser::Package_body_declarative_partContext* ctx);
	void visitPackage_body_declarative_item(
			vhdl::vhdlParser::Package_body_declarative_itemContext* ctx);
	static Function * visitSubprogram_body(
			vhdl::vhdlParser::Subprogram_bodyContext* ctx);
	static std::vector<Variable*>* visitSubprogram_declarative_part(
			vhdl::vhdlParser::Subprogram_declarative_partContext* ctx);
	static std::vector<Variable *> * visitSubprogram_declarative_item(
			vhdl::vhdlParser::Subprogram_declarative_itemContext* ctx);
	static std::vector<Variable*> * visitVariable_declaration(
			vhdl::vhdlParser::Variable_declarationContext* ctx);
	void visitSubprogram_declaration(
			vhdl::vhdlParser::Subprogram_declarationContext* ctx);
	static std::vector<Statement *> * visitSubprogram_statement_part(
			vhdl::vhdlParser::Subprogram_statement_partContext* ctx);

};
