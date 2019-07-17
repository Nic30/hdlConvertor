#include <hdlConvertor/verilogPreproc/default_macro_defs.h>
#include <hdlConvertor/verilogPreproc/verilogPreproc.h>

namespace hdlConvertor {
namespace verilog_pp {
using namespace std;
using namespace antlr4;

#define unused(x)

MacroDef__LINE__::MacroDef__LINE__() :
		aMacroDef("__line__") {
}
// [TODO] MacroDef__LINE__, MacroDef__FILE__ are showing the position in current file
//        See chapter 22.13 __FILE__ and __LINE__ of system verilog 2012 spec.
std::string MacroDef__LINE__::replace(std::vector<std::string> unused(args),
		bool args_specified, VerilogPreproc * unused(pp),
		antlr4::ParserRuleContext * ctx) {
	if (args_specified) {
		throw_doest_not_support_args();
	}
	string replacement = to_string(ctx->getStart()->getLine());
	return replacement;
}

MacroDef__FILE__::MacroDef__FILE__() :
		aMacroDef("__file__") {
}

std::string MacroDef__FILE__::replace(std::vector<std::string> unused(args),
		bool args_specified, VerilogPreproc * pp,
		antlr4::ParserRuleContext * unused(ctx)) {
	if (args_specified) {
		throw_doest_not_support_args();
	}
	// [TODO] escape
	string replacement = "\"" + pp->_tokens.getSourceName() + "\"";
	return replacement;
}

void macroDB_add_default_defs(MacroDB & db) {
	db.insert({"__LINE__", new MacroDef__LINE__()});
	db.insert({"__FILE__", new MacroDef__FILE__()});
}

}
}
