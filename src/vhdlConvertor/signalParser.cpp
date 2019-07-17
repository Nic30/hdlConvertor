#include <hdlConvertor/vhdlConvertor/signalParser.h>
#include <hdlConvertor/vhdlConvertor/interfaceParser.h>

namespace hdlConvertor {
namespace vhdl {

using namespace hdlConvertor::hdlObjects;
using vhdlParser = vhdl_antlr::vhdlParser;

std::vector<HdlVariableDef*> * SignalParser::visitSignal_declaration(
		vhdlParser::Signal_declarationContext* ctx) {
	//signal_declaration
	//	: SIGNAL identifier_list COLON
	//	subtype_indication ( signal_kind )? ( VARASGN expression )? SEMI
	//	;
	return InterfaceParser::extractVariables(ctx->identifier_list(),
			ctx->subtype_indication(), ctx->expression());
}

}
}
