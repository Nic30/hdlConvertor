#include "constantParser.h"

std::vector<Variable*> * ConstantParser::visitConstant_declaration(
		vhdlParser::Constant_declarationContext* ctx) {	
	//constant_declaration :
	//    CONSTANT identifier_list COLON subtype_indication
	//    ( VARASGN expression )? SEMI
	//  ;

	//return InterfaceParser::extractVariables(ctx->identifier_list(),
	//		ctx->subtype_indication(), ctx->expression());
	// TODO: Expression

	NotImplementedLogger::print(
				"ConstantParser.visitConstant_declaration");

	return InterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), NULL);
}