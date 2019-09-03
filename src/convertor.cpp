#include <hdlConvertor/convertor.h>

#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/verilogPreproc/verilogPreproc.h>
namespace hdlConvertor {

using namespace std;
using namespace antlr4;
using namespace antlr4::tree;
using namespace hdlConvertor::hdlObjects;

bool Convertor::debug = false;

class VHDLParserContainer: public iParserContainer<vhdl_antlr::vhdlLexer,
		vhdl_antlr::vhdlParser, vhdl::DesignFileParser> {
	using iParserContainer::iParserContainer;
	virtual void parseFn() override {
		vhdl_antlr::vhdlParser::Design_fileContext *tree =
				antlrParser->design_file();
		syntaxErrLogger.CheckErrors(); // Throw exception if errors
		hdlParser->visitDesign_file(tree);
	}
};

template<class antlrLexerT, class antlrParserT, class hdlParserT>
class VerilogParserContainerCommon: public iParserContainer<antlrLexerT,
		antlrParserT, hdlParserT> {
public:
	verilog_pp::VerilogPreprocContainer preproc;
	void parse_str(std::string &input_str, bool hierarchyOnly) = delete;
	void parse_file(const filesystem::path &file_name, bool hierarchyOnly) = delete;

public:

	VerilogParserContainerCommon(hdlObjects::HdlContext *context,
			Language _lang) :
			iParserContainer<antlrLexerT, antlrParserT, hdlParserT>(context,
					_lang), preproc(_lang, &this->syntaxErrLogger) {
	}

	void parse_file(const filesystem::path &file_name, bool hierarchyOnly,
			std::vector<std::string> &_incdirs) {
		preproc.init(_incdirs);
		string preprocessed_code = preproc.run_preproc_file(file_name);
		ANTLRInputStream input_for_parser(preprocessed_code);
		input_for_parser.name = file_name.u8string();
		this->_parse(input_for_parser, hierarchyOnly);
	}

	void parse_str(const std::string &input_str, bool hierarchyOnly,
			const std::vector<string> &_incdirs) {
		preproc.init(_incdirs);
		string preprocessed_code = preproc.run_preproc_str(input_str);
		ANTLRInputStream input_for_parser(preprocessed_code);
		input_for_parser.name = STRING_FILENAME;
		this->_parse(input_for_parser, hierarchyOnly);
	}
};

class VerilogParserContainer: public VerilogParserContainerCommon<
		Verilog2001_antlr::Verilog2001Lexer,
		Verilog2001_antlr::Verilog2001Parser, verilog::Source_textParser> {
public:
	using VerilogParserContainerCommon::VerilogParserContainerCommon;
private:
	virtual void parseFn() override {
		Verilog2001_antlr::Verilog2001Parser::Source_textContext *tree =
				antlrParser->source_text();
		syntaxErrLogger.CheckErrors(); // Throw exception if errors
		hdlParser->visitSource_text(tree);
	}
};

class SVParserContainer: public VerilogParserContainerCommon<
		sv2017_antlr::sv2017Lexer, sv2017_antlr::sv2017Parser,
		sv::source_textParser> {
public:
	using VerilogParserContainerCommon::VerilogParserContainerCommon;
private:
	virtual void parseFn() override {
		lexer->language_version = lang;
		sv2017_antlr::sv2017Parser::Source_textContext *tree =
				antlrParser->source_text();
		syntaxErrLogger.CheckErrors(); // Throw exception if errors
		hdlParser->visitSource_text(tree);
	}
};

bool is_system_verilog(Language lang) {
	return lang == Language::SV2005 || lang == Language::SV2009
			|| lang == Language::SV2012 || lang == Language::SV2017;
}

HdlContext* Convertor::parse(const vector<string> &_fileNames, Language lang,
		vector<string> incdir, bool _hierarchyOnly, bool _debug) {

	hierarchyOnly = _hierarchyOnly;
	debug = _debug;
	NotImplementedLogger::ENABLE = _debug;

	for (const auto &fileName : _fileNames) {
		struct stat buffer;

		if (stat(fileName.c_str(), &buffer) != 0) {
			throw ParseException(fileName + " does not exist.");
		}

		if (lang == Language::VHDL) {
			VHDLParserContainer pc(c, lang);
			pc.parse_file(fileName, hierarchyOnly);
			c = pc.context;
		} else if (lang == Language::VERILOG1995 || lang == Language::VERILOG2001) {
			VerilogParserContainer pc(c, lang);
			pc.parse_file(fileName, hierarchyOnly, incdir);
			c = pc.context;

		} else if (lang == Language::VERILOG2001_NOCONFIG
				|| lang == Language::VERILOG2005 || is_system_verilog(lang)) {
			SVParserContainer pc(c, lang);
			pc.parse_file(fileName, hierarchyOnly, incdir);
			c = pc.context;
		} else {
			throw runtime_error("Unsupported language.");
		}
	}
	return c;
}

HdlContext* Convertor::parse_str(const string &hdl_str, Language lang,
		vector<string> incdir, bool _hierarchyOnly, bool _debug) {
	hierarchyOnly = _hierarchyOnly;
	debug = _debug;
	NotImplementedLogger::ENABLE = _debug;

	if (lang == VHDL) {
		VHDLParserContainer pc(c, lang);
		pc.parse_str(hdl_str, hierarchyOnly);
		c = pc.context;
	} else if (lang == VERILOG) {
		VerilogParserContainer pc(c, lang);
		pc.parse_str(hdl_str, hierarchyOnly, incdir);
		c = pc.context;
	} else if (is_system_verilog(lang)) {
		SVParserContainer pc(c, lang);
		pc.parse_str(hdl_str, hierarchyOnly, incdir);
		c = pc.context;
	} else {
		throw runtime_error("Unsupported language.");
	}
	return c;
}

string Convertor::verilog_pp(const string &fileName,
		const vector<string> _incdirs, Language lang) {
	SVParserContainer pc(nullptr, lang);
	pc.preproc.init(_incdirs);
	return pc.preproc.run_preproc_file(fileName);
}

string Convertor::verilog_pp_str(const string &verilog_str,
		const vector<string> _incdirs, Language lang) {
	SVParserContainer pc(nullptr, lang);
	pc.preproc.init(_incdirs);
	return pc.preproc.run_preproc_str(verilog_str);
}

}
