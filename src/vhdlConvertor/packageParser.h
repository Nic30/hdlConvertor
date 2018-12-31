#pragma once

#include <vector>
#include <stdlib.h>

#include "../VhdlParser/vhdlParser.h"
#include "../notImplementedLogger.h"

#include "../hdlObjects/symbolType.h"
#include "../hdlObjects/named.h"
#include "../hdlObjects/expr.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/process.h"
#include "../hdlObjects/package.h"
#include "../hdlObjects/packageHeader.h"

#include "packageHeaderParser.h"
#include "compInstanceParser.h"
#include "exprParser.h"
#include "entityParser.h"
#include "interfaceParser.h"
#include "literalParser.h"
#include "referenceParser.h"
#include "subProgramDeclarationParser.h"
#include "variableParser.h"
#include "constantParser.h"
#include "statementParser.h"
#include "subtypeDeclarationParser.h"
#include "subProgramParser.h" 

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

};
