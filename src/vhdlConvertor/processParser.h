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
#include "../hdlObjects/position.h"

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

class ProcessParser {

public:
    static Process * visitProcess_statement(
                vhdlParser::Process_statementContext * ctx); 
    static char * visitLabel_colon(
		        vhdlParser::Label_colonContext * ctx);            
    static std::vector<Expr*> * visitSensitivity_list(
                vhdlParser::Sensitivity_listContext *ctx);            
    static void visitProcess_declarative_item(
                vhdlParser::Process_declarative_itemContext *ctx, Process * p);
    static void visitProcess_declarative_part(
                vhdlParser::Process_declarative_partContext *ctx, Process * p);	
    static std::vector<Statement *> * visitProcess_statement_part(
		        vhdlParser::Process_statement_partContext *ctx);            
};            