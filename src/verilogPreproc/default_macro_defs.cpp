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
std::string MacroDef__LINE__::replace(std::vector<std::string> unused(args),
		bool args_specified, VerilogPreproc* pp,
		antlr4::ParserRuleContext *ctx) {
	if (args_specified) {
		throw_doest_not_support_args();
	}
	auto offset = pp->preproc_out.input_line_begin;
	auto line = offset + ctx->getStart()->getLine();
	assert(line > 0);
	// numbering starts at 1
	return to_string(line);
}
bool MacroDef__LINE__::requires_args() {
	return false;
}
MacroDef__FILE__::MacroDef__FILE__() :
		aMacroDef("__file__") {
}

std::string MacroDef__FILE__::replace(std::vector<std::string> unused(args),
		bool args_specified, VerilogPreproc *pp,
		antlr4::ParserRuleContext*unused(ctx)) {
	if (args_specified) {
		throw_doest_not_support_args();
	}
	string replacement = "\"" + pp->preproc_out.file_line_map.back().file_override + "\"";
#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)
	auto replace_all = [](std::string &data, const std::string &to_search,
			const std::string &replace_str) {
		size_t pos = data.find(to_search);
		while (pos != std::string::npos) {
			data.replace(pos, to_search.size(), replace_str);
			pos = data.find(to_search, pos + replace_str.size());
		}
	};
	replace_all(replacement, "\\", "\\\\");
#endif
	return replacement;
}
bool MacroDef__FILE__::requires_args() {
	return false;
}

void macroDB_add_default_defs(MacroDB &db, Language lang) {
	if (lang >= Language::SV2009) {
		db.insert( { "__LINE__", new MacroDef__LINE__() });
		db.insert( { "__FILE__", new MacroDef__FILE__() });
	}
}

}
}
