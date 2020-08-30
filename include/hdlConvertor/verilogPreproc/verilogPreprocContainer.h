#pragma once

#include <antlr4-runtime.h>

#include <hdlConvertor/syntaxErrorLogger.h>
#include <hdlConvertor/language.h>
#include <hdlConvertor/universal_fs.h>
#include <hdlConvertor/verilogPreproc/macroDB.h>
#include <hdlConvertor/verilogPreproc/out_buffer.h>

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
	// if set to true the tokens will be print on std::cout
	bool debug_dump_tokens;
	antlr4::ANTLRInputStream *actual_input;

	VerilogPreprocContainer(Language _lang, SyntaxErrorLogger &_syntaxErrLogger,
			verilog_pp::MacroDB &defineDB);

	void init(const std::vector<std::string> &_incdirs);
	void run_preproc(antlr4::ANTLRInputStream &input, bool added_incdir,
			const std::string &encoding, VerilogPreprocOutBuffer &res);
	bool add_parent_dir_to_incldirs(const std::filesystem::path &file_name);
	void run_preproc_file(const std::filesystem::path &file_name,
			const std::string &encoding, VerilogPreprocOutBuffer &res);
	/*
	 * @param input_str input for preprocessor
	 * @note file_name for the error messages and for `__FILE__ directive
	 *       is taken from incfile_stack or default is is used
	 * @note line offset for debug and `__LINE__ is set in 'res'
	 * */
	void run_preproc_str(const std::string &input_str,
			const std::string &encoding, VerilogPreprocOutBuffer &res);

	void delete_non_persystent_macro_defs();
	virtual ~VerilogPreprocContainer();
};

}
}
