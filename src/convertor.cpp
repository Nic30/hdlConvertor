#include "convertor.h"

using namespace antlr4;
using namespace antlr4::tree;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {

bool Convertor::debug = false;

void parseFnVerilog(Verilog2001_antlr::Verilog2001Parser * antlrParser,
		verilog::Source_textParser * hdlParser) {
	Verilog2001_antlr::Verilog2001Parser::Source_textContext *tree =
			antlrParser->source_text();
	hdlParser->visitSource_text(tree);
}

void parseFnVHDL(vhdl_antlr::vhdlParser * antlrParser,
		vhdl::DesignFileParser * hdlParser) {
	vhdl_antlr::vhdlParser::Design_fileContext *tree =
			antlrParser->design_file();
	hdlParser->visitDesign_file(tree);
}

#ifdef SV_PARSER
void parseFnSystemVerilog(sv2012_antlr::sv2012Parser * antlrParser,
		sv::source_textParser * hdlParser) {
	sv2012_antlr::sv2012Parser::Source_textContext *tree =
			antlrParser->source_text();
	hdlParser->visitSource_text(tree);
}
#endif

Context * Convertor::parse(std::vector<std::string> _fileNames, Language _lang,
		std::vector<std::string> incdir, bool _hierarchyOnly, bool _debug) {

	Context * c = nullptr;
	hierarchyOnly = _hierarchyOnly;
	debug = _debug;
	for (const auto & _fileName : _fileNames) {
		struct stat buffer;
		fileName = _fileName;
		lang = _lang;
		std::string str;

		if (stat(_fileName.c_str(), &buffer) != 0) {
			throw ParseException(_fileName + " does not exist.");
		}

		if (lang == VHDL) {

			ANTLRFileStream input(fileName);
			auto pc = new ParserContainer<vhdl_antlr::vhdlLexer,
					vhdl_antlr::vhdlParser, vhdl::DesignFileParser>(c);
			pc->parseFile(input, hierarchyOnly, debug, parseFnVHDL);
			c = pc->context;
			delete pc;

		} else if (lang == VERILOG) {

			auto pc = new ParserContainer<Verilog2001_antlr::Verilog2001Lexer,
					Verilog2001_antlr::Verilog2001Parser,
					verilog::Source_textParser>(c);
			verilog_pp::macroSymbol defineDB;
			std::vector<std::string> stack_incfile;
			str = return_preprocessed_file(fileName, incdir, defineDB,
					stack_incfile, verilog_pp::vPreprocessor::VERILOG2001);

			ANTLRInputStream input(str);
			input.name = fileName;

			pc->parseFile(input, hierarchyOnly, debug, parseFnVerilog);
			c = pc->context;
			delete pc;

#ifdef SV_PARSER
		} else if (lang == SYSTEM_VERILOG) {
			auto pc = new ParserContainer<sv2012_antlr::sv2012Lexer,
					sv2012_antlr::sv2012Parser, sv::source_textParser>(c);

			verilog_pp::macroSymbol defineDB;
			std::vector<std::string> stack_incfile;
			str = return_preprocessed_file(fileName, incdir, defineDB,
					stack_incfile, verilog_pp::vPreprocessor::SV2012);

			ANTLRInputStream input(str);
			input.name = fileName;

			pc->parseFile(input, hierarchyOnly, debug, parseFnSystemVerilog);
			c = pc->context;
			delete pc;
#endif
		} else {
			throw std::runtime_error("Unsupported language.");
		}
	}
	return c;
}

std::string Convertor::verilog_pp(const std::string fileName,
		std::vector<std::string> incdir, unsigned int mode) {

	struct stat buffer;
	if (stat(fileName.c_str(), &buffer) != 0) {
		throw ParseException(fileName + " does not exist.");
	}

	verilog_pp::macroSymbol defineDB;
	std::vector<std::string> stack_incfile;
	std::string result = return_preprocessed_file(fileName, incdir, defineDB,
			stack_incfile, mode);
	return result;

}

}
