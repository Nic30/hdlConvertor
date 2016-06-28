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
	Package * visitPackage_body(Ref<vhdlParser::Package_bodyContext> ctx);
	void visitPackage_body_declarative_part(
			aPackage * p,
			Ref<vhdlParser::Package_body_declarative_partContext> ctx);
	void visitPackage_body_declarative_item(
			Ref<vhdlParser::Package_body_declarative_itemContext> ctx);
	static Function * visitSubprogram_body(
			Ref<vhdlParser::Subprogram_bodyContext> ctx);
	static std::vector<Variable*>* visitSubprogram_declarative_part(
			Ref<vhdlParser::Subprogram_declarative_partContext> ctx);
	static std::vector<Variable *> * visitSubprogram_declarative_item(
			Ref<vhdlParser::Subprogram_declarative_itemContext> ctx);
	static std::vector<Variable*> * visitVariable_declaration(
			Ref<vhdlParser::Variable_declarationContext> ctx);
	void visitSubprogram_declaration(
			Ref<vhdlParser::Subprogram_declarationContext> ctx);
	static std::vector<Statement *> * visitSubprogram_statement_part(
			Ref<vhdlParser::Subprogram_statement_partContext> ctx);

};
