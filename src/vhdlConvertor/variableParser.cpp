#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;

std::vector<HdlVariableDef*> * VariableParser::visitVariable_declaration(
		vhdlParser::Variable_declarationContext *ctx) {
	// variable_declaration :
	// ( SHARED )? VARIABLE identifier_list COLON
	// subtype_indication ( VARASGN expression )? SEMI
	// ;

	if (ctx->SHARED())
		NotImplementedLogger::print(
				"VariableParser.visitVariable_declaration - SHARED", ctx);

	std::vector<HdlVariableDef*> * vl = InterfaceParser::extractVariables(
			ctx->identifier_list(), ctx->subtype_indication(),
			ctx->expression());
	for (auto v: *vl)
		v->is_latched = true;

	return vl;
}

}
}
