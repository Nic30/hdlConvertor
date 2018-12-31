#pragma once
#include <vector>
#include "../VhdlParser/vhdlParser.h"
#include "../hdlObjects/context.h"
#include "../notImplementedLogger.h"
#include "referenceParser.h"
#include "../hdlObjects/named.h"
#include "../hdlObjects/function.h"
#include "../hdlObjects/variable.h"
#include "../hdlObjects/packageHeader.h"

#include "compInstanceParser.h"
#include "exprParser.h"
#include "entityParser.h"
#include "interfaceParser.h"
#include "processParser.h"

using namespace antlr4;
using namespace vhdl;

class SubtypeDeclarationParser {
public:
	static Variable * visitSubtype_declaration(
		vhdlParser::Subtype_declarationContext* ctx); 	

};