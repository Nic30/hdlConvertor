#pragma once

#include <vector>
#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/named.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/packageHeader.h"
#include "../hdlObjects/process.h"

#include "compInstanceParser.h"
#include "exprParser.h"
#include "entityParser.h"
#include "interfaceParser.h"
#include "literalParser.h"
#include "referenceParser.h"
#include "subProgramDeclarationParser.h"
#include "variableParser.h"
#include "constantParser.h"
#include "signalParser.h"
#include "statementParser.h"
#include "subtypeDeclarationParser.h"
#include "subProgramParser.h" 


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
	void visitPackage_declarative_item(
			vhdlParser::Package_declarative_itemContext* ctx);
	Entity * visitComponent_declaration(
			vhdlParser::Component_declarationContext* ctx);
	static std::vector<Variable*> * visitConstant_declaration(
			vhdlParser::Constant_declarationContext* ctx);
	static Variable * visitSubtype_declaration(vhdlParser::Subtype_declarationContext* ctx);
};
