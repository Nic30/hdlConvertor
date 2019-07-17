#include <hdlConvertor/convertor.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/verilogPreproc/default_macro_defs.h>

namespace hdlConvertor {

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;
using namespace hdlConvertor::hdlObjects;

bool Convertor::debug = false;

void parseFnVerilog(SyntaxErrorLogger * syntaxErrLogger,
		Verilog2001_antlr::Verilog2001Parser * antlrParser,
		verilog::Source_textParser * hdlParser) {
	Verilog2001_antlr::Verilog2001Parser::Source_textContext *tree =
			antlrParser->source_text();
	syntaxErrLogger->CheckErrors(); // Throw exception if errors
	hdlParser->visitSource_text(tree);
}

void parseFnVHDL(SyntaxErrorLogger * syntaxErrLogger,
		vhdl_antlr::vhdlParser * antlrParser,
		vhdl::DesignFileParser * hdlParser) {
	vhdl_antlr::vhdlParser::Design_fileContext *tree =
			antlrParser->design_file();
	syntaxErrLogger->CheckErrors(); // Throw exception if errors
	hdlParser->visitDesign_file(tree);
}

#ifdef SV_PARSER
void parseFnSystemVerilog(SyntaxErrorLogger * syntaxErrLogger,
		sv2012_antlr::sv2012Parser * antlrParser,
		sv::source_textParser * hdlParser) {
	sv2012_antlr::sv2012Parser::Source_textContext *tree =
			antlrParser->source_text();
	syntaxErrLogger->CheckErrors(); // Throw exception if errors
	hdlParser->visitSource_text(tree);
}
#endif

void Convertor::parse_vhdl(ANTLRInputStream & input) {
	auto pc = new ParserContainer<vhdl_antlr::vhdlLexer, vhdl_antlr::vhdlParser,
			vhdl::DesignFileParser>(c);
	pc->parseFile(input, hierarchyOnly, parseFnVHDL);
	c = pc->context;
	delete pc;
}

void Convertor::parse_verilog_file(const string & fileName,
		vector<string> & _incdirs) {
	auto pc = new ParserContainer<Verilog2001_antlr::Verilog2001Lexer,
			Verilog2001_antlr::Verilog2001Parser, verilog::Source_textParser>(
			c);
	verilog_pp::MacroDB defineDB;
	macroDB_add_default_defs(defineDB);
	vector<filesystem::path> stack_incfile;
	vector<filesystem::path> incdirs;
	incdirs.reserve(_incdirs.size());
	for (auto p : _incdirs)
		incdirs.push_back(p);
	string str = verilog_pp::run_verilog_preproc_file(fileName, incdirs,
			defineDB, stack_incfile, Language::VERILOG2001);

	ANTLRInputStream input(str);
	input.name = fileName;

	pc->parseFile(input, hierarchyOnly, parseFnVerilog);
	c = pc->context;
	delete pc;
}

void Convertor::parse_verilog_str(const string & verilog_str,
		vector<string> & _incdirs) {
	auto pc = new ParserContainer<Verilog2001_antlr::Verilog2001Lexer,
			Verilog2001_antlr::Verilog2001Parser, verilog::Source_textParser>(
			c);
	verilog_pp::MacroDB defineDB;
	macroDB_add_default_defs(defineDB);
	vector<filesystem::path> stack_incfile;
	vector<filesystem::path> incdirs;
	incdirs.reserve(_incdirs.size());
	for (auto p : _incdirs)
		incdirs.push_back(p);
	string str = verilog_pp::run_verilog_preproc_str(verilog_str, incdirs,
			defineDB, stack_incfile, Language::VERILOG2001);

	ANTLRInputStream input(str);
	input.name = "<string>";

	pc->parseFile(input, hierarchyOnly, parseFnVerilog);
	c = pc->context;
	delete pc;
}

#ifdef SV_PARSER
void Convertor::parse_sv_file(const string & fileName,
		vector<string> & _incdirs) {
	auto pc = new ParserContainer<sv2012_antlr::sv2012Lexer,
			sv2012_antlr::sv2012Parser, sv::source_textParser>(c);

	verilog_pp::MacroDB defineDB;
	macroDB_add_default_defs(defineDB);
	vector<filesystem::path> stack_incfile;
	vector<filesystem::path> incdirs;
	incdirs.reserve(_incdirs.size());
	for (auto p : _incdirs)
		incdirs.push_back(p);
	string str = verilog_pp::run_verilog_preproc_file(fileName, incdirs,
			defineDB, stack_incfile, Language::SV2012);

	ANTLRInputStream input(str);
	input.name = fileName;

	pc->parseFile(input, hierarchyOnly, parseFnSystemVerilog);
	c = pc->context;
	delete pc;
}

void Convertor::parse_sv_str(const string & verilog_str,
		vector<string> & _incdirs) {
	auto pc = new ParserContainer<sv2012_antlr::sv2012Lexer,
			sv2012_antlr::sv2012Parser, sv::source_textParser>(c);

	verilog_pp::MacroDB defineDB;
	macroDB_add_default_defs(defineDB);
	vector<filesystem::path> stack_incfile;
	vector<filesystem::path> incdirs;
	incdirs.reserve(_incdirs.size());
	for (auto p : _incdirs)
		incdirs.push_back(p);
	string str = verilog_pp::run_verilog_preproc_str(verilog_str, incdirs,
			defineDB, stack_incfile, Language::SV2012);

	ANTLRInputStream input(str);
	input.name = "<string>";

	pc->parseFile(input, hierarchyOnly, parseFnSystemVerilog);
	c = pc->context;
	delete pc;
}
#endif

HdlContext * Convertor::parse(const vector<string> & _fileNames, Language lang,
		vector<string> incdir, bool _hierarchyOnly, bool _debug) {

	hierarchyOnly = _hierarchyOnly;
	debug = _debug;
	NotImplementedLogger::ENABLE = _debug;

	for (const auto & fileName : _fileNames) {
		struct stat buffer;

		if (stat(fileName.c_str(), &buffer) != 0) {
			throw ParseException(fileName + " does not exist.");
		}

		if (lang == VHDL) {
			ANTLRFileStream input(fileName);
			parse_vhdl(input);

		} else if (lang == VERILOG) {
			parse_verilog_file(fileName, incdir);
#ifdef SV_PARSER
		} else if (lang == SYSTEM_VERILOG) {
			parse_sv_file(fileName, incdir);
#endif
		} else {
			throw runtime_error("Unsupported language.");
		}
	}
	return c;
}
HdlContext * Convertor::parse_str(const string & hdl_str, Language lang,
		vector<string> incdir, bool _hierarchyOnly, bool _debug) {
	hierarchyOnly = _hierarchyOnly;
	debug = _debug;
	NotImplementedLogger::ENABLE = _debug;

	if (lang == VHDL) {
		ANTLRInputStream input(hdl_str);
		input.name = "<string>";
		parse_vhdl(input);
	} else if (lang == VERILOG) {
		parse_verilog_str(hdl_str, incdir);
#ifdef SV_PARSER
	} else if (lang == SYSTEM_VERILOG) {
		parse_sv_str(hdl_str, incdir);
#endif
	} else {
		throw runtime_error("Unsupported language.");
	}
	return c;
}

string Convertor::verilog_pp(const string & fileName,
		const vector<string> _incdirs, Language mode) {
	verilog_pp::MacroDB defineDB;
	macroDB_add_default_defs(defineDB);
	vector<filesystem::path> stack_incfile;
	vector<filesystem::path> incdirs;
	incdirs.reserve(_incdirs.size());
	for (auto p : _incdirs)
		incdirs.push_back(p);

	string result = run_verilog_preproc_file(fileName, incdirs, defineDB,
			stack_incfile, mode);
	return result;
}

string Convertor::verilog_pp_str(const string & verilog_str,
		const vector<string> _incdirs, Language mode) {
	verilog_pp::MacroDB defineDB;
	macroDB_add_default_defs(defineDB);
	vector<filesystem::path> stack_incfile;
	vector<filesystem::path> incdirs;
	incdirs.reserve(_incdirs.size());
	for (auto p : _incdirs)
		incdirs.push_back(p);

	string result = run_verilog_preproc_str(verilog_str, incdirs, defineDB,
			stack_incfile, mode);
	return result;
}

}
