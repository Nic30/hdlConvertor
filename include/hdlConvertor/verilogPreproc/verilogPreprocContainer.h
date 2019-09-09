#pragma once

#include <antlr4-runtime.h>

#include <hdlConvertor/syntaxErrorLogger.h>
#include <hdlConvertor/language.h>
#include <hdlConvertor/universal_fs.h>
#include <hdlConvertor/verilogPreproc/macroDB.h>

namespace hdlConvertor {
namespace verilog_pp {

/*
 * Container for context of preprocessor
 * */
class VerilogPreprocContainer {
public:
	verilog_pp::MacroDB & defineDB;
	// [todo] store also line no so it is possible to recover it
	std::vector<std::filesystem::path> stack_incfile;
	std::vector<std::filesystem::path> incdirs;
	Language lang;
	SyntaxErrorLogger &syntaxErrLogger;
	bool debug_dump_tokens;
	VerilogPreprocContainer(Language _lang, SyntaxErrorLogger &_syntaxErrLogger,
			verilog_pp::MacroDB & defineDB);

	void init(const std::vector<std::string> &_incdirs);
	std::string run_preproc(antlr4::ANTLRInputStream &input, bool added_incdir);
	bool add_parent_dir_to_incldirs(const std::filesystem::path &file_name);
	std::string run_preproc_file(const std::filesystem::path &file_name);
	std::string run_preproc_str(const std::string &input_str);

	void delete_non_persystent_macro_defs();
	virtual ~VerilogPreprocContainer();
};

}
}
