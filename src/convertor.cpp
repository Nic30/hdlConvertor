#include "convertor.h"

bool Convertor::debug = false;

void parseFnVerilog(Verilog2001Parser * antlrParser,
		Source_textParser * hdlParser) {
	Verilog2001Parser::Source_textContext *tree = antlrParser->source_text();
	hdlParser->visitSource_text(tree);
}

void parseFnVHDL(vhdlParser * antlrParser, DesignFileParser * hdlParser) {
	vhdlParser::Design_fileContext *tree = antlrParser->design_file();
	hdlParser->visitDesign_file(tree);
}

#ifdef SV_PARSER
void parseFnSystemVerilog(sv2012::sv2012Parser * antlrParser,
		source_textParser * hdlParser) {
	sv2012::sv2012Parser::Source_textContext *tree = antlrParser->source_text();
	hdlParser->visitSource_text(tree);
}
#endif

Context * Convertor::parse(std::vector<std::string> _fileNames, Langue _lang,
		std::vector<std::string> incdir, bool _hierarchyOnly, bool _debug) {

	Context * c = NULL;
	hierarchyOnly = _hierarchyOnly;
	debug = _debug;
	for (const auto & _fileName : _fileNames) {
		struct stat buffer;
		fileName = _fileName;
		lang = _lang;

		if (stat(_fileName.c_str(), &buffer) != 0) {
			throw parseException(_fileName + " does not exist.");
		}
		std::ifstream t(fileName);
		std::string str((std::istreambuf_iterator<char>(t)),
				std::istreambuf_iterator<char>());

		if (lang == VHDL) {

			ANTLRInputStream input(str);
			input.name = fileName;
			auto pc = new ParserContainer<vhdlLexer, vhdlParser,
					DesignFileParser>(c);
			pc->parseFile(input, hierarchyOnly, debug, parseFnVHDL);
			c = pc->context;
			delete pc;

		} else if (lang == VERILOG) {

			auto pc = new ParserContainer<Verilog2001Lexer, Verilog2001Parser,
					Source_textParser>(c);
			macroSymbol defineDB;
			str = return_preprocessed(str, incdir, defineDB,vPreprocessor::VERILOG2001);

			ANTLRInputStream input(str);
			input.name = fileName;

			pc->parseFile(input, hierarchyOnly, debug, parseFnVerilog);
			c = pc->context;
			delete pc;

#ifdef SV_PARSER
		} else if (lang == SYSTEM_VERILOG) {
			auto pc = new ParserContainer<sv2012::sv2012Lexer,
					sv2012::sv2012Parser, source_textParser>(c);

			macroSymbol defineDB;
			str = return_preprocessed(str, incdir, defineDB,vPreprocessor::SV2012);

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
		std::vector<std::string> incdir,unsigned int mode) {

	std::ifstream t(fileName);
	std::string str((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());

	macroSymbol defineDB;
	std::string result = return_preprocessed(str, incdir, defineDB, mode);
	return result;

}

