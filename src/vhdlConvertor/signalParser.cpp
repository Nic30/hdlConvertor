#include "signalParser.h"

std::vector<Variable*> * SignalParser::visitSignal_declaration(
		vhdlParser::Signal_declarationContext* ctx) {
	//signal_declaration
	//	: SIGNAL identifier_list COLON
	//	subtype_indication ( signal_kind )? ( VARASGN expression )? SEMI
	//	;
	return InterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
}