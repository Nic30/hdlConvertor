#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/vhdlConvertor/constantParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlAst;
using vhdlParser = vhdl_antlr::vhdlParser;

std::unique_ptr<std::vector<std::unique_ptr<HdlIdDef>>> VhdlConstantParser::visitConstant_declaration(
		vhdlParser::Constant_declarationContext *ctx) {
	//constant_declaration :
	//    CONSTANT identifier_list COLON subtype_indication
	//    ( VARASGN expression )? SEMI
	//  ;

	auto vars = VhdlInterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	for (auto &v : *vars)
		v->is_const = true;

	return vars;
}

}
}
