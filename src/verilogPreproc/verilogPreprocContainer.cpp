#include <hdlConvertor/verilogPreproc/verilogPreprocContainer.h>
#include <hdlConvertor/verilogPreproc/default_macro_defs.h>
#include <hdlConvertor/verilogPreproc/verilogPreproc.h>
#include <hdlConvertor/encodingConversions.h>

namespace hdlConvertor {
namespace verilog_pp {

using namespace std;

VerilogPreprocContainer::VerilogPreprocContainer(Language _lang,
		SyntaxErrorLogger &_syntaxErrLogger, verilog_pp::MacroDB &_defineDB) :
		defineDB(_defineDB), lang(_lang), syntaxErrLogger(_syntaxErrLogger), max_macro_call_stack_size(
				DEFAULT_MAX_MACRO_CALL_STACK_SIZE), debug_dump_tokens(false), actual_input(
				nullptr) {
}

void VerilogPreprocContainer::init(const vector<string> &_incdirs) {
	delete_non_persystent_macro_defs();
	macroDB_add_default_defs(defineDB, lang);
	incfile_stack.clear();
	incdirs.clear();
	incdirs.reserve(_incdirs.size());
	for (auto p : _incdirs)
		incdirs.push_back(p);
}

void VerilogPreprocContainer::run_preproc(antlr4::ANTLRInputStream &input,
		bool added_incdir, const std::string &encoding,
		VerilogPreprocOutBuffer &res) {
	verilogPreproc_antlr::verilogPreprocLexer pp_lexer(&input);
	pp_lexer.removeErrorListeners();
	pp_lexer.addErrorListener(&syntaxErrLogger);

	antlr4::CommonTokenStream tokens(&pp_lexer);

	verilogPreproc_antlr::verilogPreprocParser parser(&tokens);
	parser.removeErrorListeners();
	parser.addErrorListener(&syntaxErrLogger);
	parser.language_version = lang;

	antlr4::tree::ParseTree *tree = parser.file();
	if (debug_dump_tokens) {
		auto rec = dynamic_cast<antlr4::Recognizer*>(&pp_lexer);
		cout << "#tokens.size()=" << tokens.size() << endl;
		for (size_t i = 0; i < tokens.size(); i++) {
			// base toString() does not print token names, because of this there is such a cast
			auto t = dynamic_cast<antlr4::CommonToken*>(tokens.get(i));
			cout << t->toString(rec) << endl;
		}
	}
	auto orig_err_prefix = syntaxErrLogger.error_prefix;
	syntaxErrLogger.error_prefix = "Preproc";
	try {
		syntaxErrLogger.check_errors();
	} catch (const std::exception &e) {
		syntaxErrLogger.error_prefix = orig_err_prefix;
		throw;
	}
	syntaxErrLogger.error_prefix = orig_err_prefix;

	auto prev_input = actual_input;
	actual_input = &input;
	verilog_pp::VerilogPreproc extractor(*this, res, tokens, added_incdir, encoding);
	extractor.visit(tree);
	actual_input = prev_input;
}

bool VerilogPreprocContainer::add_parent_dir_to_incldirs(
		const filesystem::path &file_name) {
	filesystem::path dir = file_name.parent_path();
	bool add_to_inc_dir = std::find(incdirs.begin(), incdirs.end(), dir)
			== incdirs.end();

	if (add_to_inc_dir)
		incdirs.push_back(dir);
	return add_to_inc_dir;
}

void VerilogPreprocContainer::run_preproc_file(
		const filesystem::path &file_name, const std::string &encoding,
		VerilogPreprocOutBuffer &res) {
	bool add_to_inc_dir = add_parent_dir_to_incldirs(file_name);
	// register the include file on the include file stack
	incfile_stack.push_back( { file_name, 0 });

	auto input = ANTLRFileStream_with_encoding(file_name, encoding);
	res.set_input_line(file_name.u8string(), 0);
	run_preproc(input, add_to_inc_dir, encoding, res);

	incfile_stack.pop_back();
	if (add_to_inc_dir)
		incdirs.pop_back();
}

void VerilogPreprocContainer::run_preproc_str(const std::string &input_str,
		const std::string &encoding, VerilogPreprocOutBuffer &res) {
	// get filename which should be used in errors if something unpredicted happen
	string formal_file_name;
	if (incfile_stack.size()) {
		formal_file_name = incfile_stack.back().first.u8string();
	} else {
		formal_file_name = STRING_FILENAME;
	}
	// map line 0 to line_offset-th line in formal_file_name
	res.set_input_line(formal_file_name, 0);

	antlr4::ANTLRInputStream input_for_preprocessor(
			_to_utf8(input_str, encoding));
	input_for_preprocessor.name = formal_file_name;
	run_preproc(input_for_preprocessor, false, encoding, res);
}

void VerilogPreprocContainer::delete_non_persystent_macro_defs() {
	auto it = defineDB.begin();
	for (; it != defineDB.end();) {
		if (!it->second->is_persistent) {
			defineDB.erase(it++);
		} else {
			++it;
		}
	}
}

VerilogPreprocContainer::~VerilogPreprocContainer() {
}

}
}
