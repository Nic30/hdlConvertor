#include <hdlConvertor/verilogPreproc/verilogPreprocContainer.h>
#include <hdlConvertor/verilogPreproc/default_macro_defs.h>
#include <hdlConvertor/verilogPreproc/verilogPreproc.h>

namespace hdlConvertor {
namespace verilog_pp {
using namespace std;
using namespace antlr4;

void VerilogPreprocContainer::init(const vector<string> &_incdirs) {
	defineDB.clear();
	stack_incfile.clear();
	incdirs.clear();
	macroDB_add_default_defs(defineDB, lang);
	incdirs.reserve(_incdirs.size());
	for (auto p : _incdirs)
		incdirs.push_back(p);
}

string VerilogPreprocContainer::run_preproc(ANTLRInputStream &input,
		bool added_incdir) {
	verilogPreproc_antlr::verilogPreprocLexer pp_lexer(&input);
	pp_lexer.removeErrorListeners();
	pp_lexer.addErrorListener(syntaxErrLogger);

	CommonTokenStream tokens(&pp_lexer);

	verilogPreproc_antlr::verilogPreprocParser parser(&tokens);
	parser.removeErrorListeners();
	parser.addErrorListener(syntaxErrLogger);
	parser.language_version = lang;

	tree::ParseTree *tree = parser.file();
	if (debug_dump_tokens) {
		cout << "#tokens.size()=" << tokens.size() << endl;
		for (size_t i = 0; i < tokens.size(); i++) {
			cout << tokens.get(i)->toString() << endl;
		}
	}

	syntaxErrLogger->CheckErrors();

	verilog_pp::VerilogPreproc extractor(*this, tokens, added_incdir);
	extractor.visit(tree);
	string res = extractor._rewriter.getText();
	return res;
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
string VerilogPreprocContainer::run_preproc_file(
		const filesystem::path &file_name) {
	bool add_to_inc_dir = add_parent_dir_to_incldirs(file_name);
	// register the include file on the include file stack
	stack_incfile.push_back(file_name);

	ANTLRFileStream input(file_name.u8string());
	auto res = run_preproc(input, add_to_inc_dir);

	stack_incfile.pop_back();

	if (add_to_inc_dir)
		incdirs.pop_back();

	return res;
}

string VerilogPreprocContainer::run_preproc_str(const std::string &input_str) {
	ANTLRInputStream input_for_preprocessor(input_str);
	input_for_preprocessor.name = STRING_FILENAME;
	return run_preproc(input_for_preprocessor, false);
}

}
}
