#include <hdlConvertor/vhdlConvertor/constantParser.h>

#include <hdlConvertor/vhdlConvertor/interfaceParser.h>
#include <hdlConvertor/notImplementedLogger.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

std::vector<HdlVariableDef*> * ConstantParser::visitConstant_declaration(
		vhdlParser::Constant_declarationContext* ctx) {
	//constant_declaration :
	//    CONSTANT identifier_list COLON subtype_indication
	//    ( VARASGN expression )? SEMI
	//  ;

	auto vars = InterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
	for (auto v : *vars)
		v->is_const = true;

	return vars;
}

}
}
