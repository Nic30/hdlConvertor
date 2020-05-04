#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/vhdlConvertor/variableParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlAst;

std::unique_ptr<std::vector<std::unique_ptr<HdlIdDef>>> VhdlVariableParser::visitVariable_declaration(
		vhdlParser::Variable_declarationContext *ctx) {
	// variable_declaration :
	// ( SHARED )? VARIABLE identifier_list COLON
	// subtype_indication ( VARASGN expression )? SEMI
	// ;

	if (ctx->KW_SHARED())
		NotImplementedLogger::print(
				"VariableParser.visitVariable_declaration - SHARED", ctx);

	auto vl = VhdlInterfaceParser::extractVariables(
			ctx->identifier_list(), ctx->subtype_indication(),
			ctx->expression());
	for (auto & v: *vl)
		v->is_latched = true;

	return vl;
}

}
}
