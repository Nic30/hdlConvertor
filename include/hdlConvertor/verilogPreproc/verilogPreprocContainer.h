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
	verilog_pp::MacroDB defineDB;
	std::vector<std::filesystem::path> stack_incfile;
	std::vector<std::filesystem::path> incdirs;
	Language lang;
	SyntaxErrorLogger *syntaxErrLogger;

	VerilogPreprocContainer(Language _lang, SyntaxErrorLogger *_syntaxErrLogger) :
			lang(_lang), syntaxErrLogger(_syntaxErrLogger) {
	}

	void init(const std::vector<std::string> &_incdirs);
	std::string run_preproc(antlr4::ANTLRInputStream &input, bool added_incdir);
	bool add_parent_dir_to_incldirs(const std::filesystem::path &file_name);
	std::string run_preproc_file(const std::filesystem::path &file_name);
	std::string run_preproc_str(const std::string &input_str);
};

}
}
