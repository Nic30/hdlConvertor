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

	auto vl = VhdlInterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	bool is_shared = ctx->KW_SHARED();

	for (auto &v : *vl) {
		v->is_latched = true;
		v->is_shared = is_shared;
	}

	return vl;
}

}
}
