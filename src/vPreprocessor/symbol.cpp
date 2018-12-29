
#include "symbol.h"

void symbol::enterPattern(symbolParser::PatternContext *ctx){
/*	
	std::vector<antlr4::tree::TerminalNode *>::iterator i;
       	while(i != ctx->SYMBOL.end()) {
		if (i== ctx->SYMBOL.begin()) {
			_macroName = (*i)->getText();
		}
		else {
			args.push_back((*i)->getText();
		}
	}
*/
	for (unsigned int i =0 ;i < ctx->SYMBOL().size(); i++) {
       		if (i==0) {
			data.macroName = ctx->SYMBOL(i)->getText();
		}
		else {
			data.args.push_back(ctx->SYMBOL(i)->getText());
		}
	}
}
