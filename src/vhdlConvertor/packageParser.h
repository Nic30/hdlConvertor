#pragma once

#include <vector>
#include <stdlib.h>

#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"

#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/statement.h"
#include "../hdlObjects/package.h"
#include "../hdlObjects/packageHeader.h"

#include "literalParser.h"
#include "interfaceParser.h"
#include "packageHeaderParser.h"
#include "statementParser.h"

using namespace antlr4;
using namespace vhdl;

class PackageParser {
public:
	Package * p;
	bool hierarchyOnly;
	PackageParser(bool _hierarchyOnly);
	Package * visitPackage_body(vhdlParser::Package_bodyContext* ctx);
	void visitPackage_body_declarative_part(
			aPackage * p,
			vhdlParser::Package_body_declarative_partContext* ctx);
	void visitPackage_body_declarative_item(
			vhdlParser::Package_body_declarative_itemContext* ctx);
	static Function * visitSubprogram_body(
			vhdlParser::Subprogram_bodyContext* ctx);
	static std::vector<Variable*>* visitSubprogram_declarative_part(
			vhdlParser::Subprogram_declarative_partContext* ctx);
	static std::vector<Variable *> * visitSubprogram_declarative_item(
			vhdlParser::Subprogram_declarative_itemContext* ctx);
	static std::vector<Variable*> * visitVariable_declaration(
			vhdlParser::Variable_declarationContext* ctx);
	void visitSubprogram_declaration(
			vhdlParser::Subprogram_declarationContext* ctx);
	static std::vector<Statement *> * visitSubprogram_statement_part(
			vhdlParser::Subprogram_statement_partContext* ctx);

};
