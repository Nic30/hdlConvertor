#pragma once
#include <vector>
#include "../VhdlParser/vhdlParser.h"
#include "../hdlObjects/context.h"
#include "../notImplementedLogger.h"
#include "referenceParser.h"
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
#include "subProgramDeclarationParser.h"
#include "variableParser.h"
#include "constantParser.h"
#include "statementParser.h"
#include "subtypeDeclarationParser.h"

using namespace antlr4;
using namespace vhdl;

class SubProgramParser {

public:

    static Function * visitSubprogram_body(
                vhdlParser::Subprogram_bodyContext* ctx);
    static Function * visitSubprogram_specification(
                vhdlParser::Subprogram_specificationContext* ctx);
    static Function * visitProcedure_specification(
                vhdlParser::Procedure_specificationContext* ctx);
    static Function * visitFunction_specification(
                vhdlParser::Function_specificationContext* ctx);
    static std::vector<Variable*> * visitFormal_parameter_list(
                vhdlParser::Formal_parameter_listContext* ctx);
    static void visitSubprogram_declaration(
		        vhdlParser::Subprogram_declarationContext* ctx);
    static std::vector<Statement *> * visitSubprogram_statement_part(
                vhdlParser::Subprogram_statement_partContext* ctx);


};            