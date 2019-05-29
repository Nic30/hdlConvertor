#include "constantParser.h"
#include "interfaceParser.h"
#include "notImplementedLogger.h"

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

std::vector<Variable*> * ConstantParser::visitConstant_declaration(
		vhdlParser::Constant_declarationContext* ctx) {
	//constant_declaration :
	//    CONSTANT identifier_list COLON subtype_indication
	//    ( VARASGN expression )? SEMI
	//  ;

	return InterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());

}

}
}
