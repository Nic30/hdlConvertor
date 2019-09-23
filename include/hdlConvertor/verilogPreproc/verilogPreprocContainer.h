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
	verilog_pp::MacroDB &defineDB;
	// <path, line_no>
	std::vector<std::pair<std::filesystem::path, size_t>> incfile_stack;
	std::vector<std::filesystem::path> incdirs;
	Language lang;
	SyntaxErrorLogger &syntaxErrLogger;
	// [TODO] make this configurable
	static constexpr size_t DEFAULT_MAX_MACRO_CALL_STACK_SIZE = 128;
	size_t max_macro_call_stack_size;
	std::vector<std::string> macro_call_stack;
	bool debug_dump_tokens;

	VerilogPreprocContainer(Language _lang, SyntaxErrorLogger &_syntaxErrLogger,
			verilog_pp::MacroDB &defineDB);

	void init(const std::vector<std::string> &_incdirs);
	std::string run_preproc(antlr4::ANTLRInputStream &input, bool added_incdir);
	bool add_parent_dir_to_incldirs(const std::filesystem::path &file_name);
	std::string run_preproc_file(const std::filesystem::path &file_name);
	/*
	 * @param input_str input for preprocessor
	 * @note file_name for the error messages and for `__FILE__ directive is taken from incfile_stack or default is is used
	 * @param line_offset the line offset for debug and `__LINE__
	 * */
	std::string run_preproc_str(const std::string &input_str,
			size_t line_offset);

	void delete_non_persystent_macro_defs();
	virtual ~VerilogPreprocContainer();
};

}
}
