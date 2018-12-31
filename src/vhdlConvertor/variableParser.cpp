#include "variableParser.h"

std::vector<Variable*> * VariableParser::visitVariable_declaration(
		vhdlParser::Variable_declarationContext *ctx) {	
	// variable_declaration :
	// ( SHARED )? VARIABLE identifier_list COLON
	// subtype_indication ( VARASGN expression )? SEMI
	// ;

	if (ctx->SHARED())
		NotImplementedLogger::print(
				"VariableParser.visitVariable_declaration - SHARED");

	std::vector<Variable*> * vl = InterfaceParser::extractVariables(
			ctx->identifier_list(), ctx->subtype_indication(),
			ctx->expression());

	return vl;
}