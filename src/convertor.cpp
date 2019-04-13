#include "convertor.h"

using namespace antlr4;
using namespace antlr4::tree;
using namespace vhdl;
using namespace Verilog2001;

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
		std::string str;

		if (stat(_fileName.c_str(), &buffer) != 0) {
			throw ParseException(_fileName + " does not exist.");
		}

		if (lang == VHDL) {

			ANTLRFileStream input(fileName);
			auto pc = new ParserContainer<vhdlLexer, vhdlParser,
					DesignFileParser>(c);
			pc->parseFile(input, hierarchyOnly, debug, parseFnVHDL);
			c = pc->context;
			delete pc;

		} else if (lang == VERILOG) {

			auto pc = new ParserContainer<Verilog2001Lexer, Verilog2001Parser,
					Source_textParser>(c);
			macroSymbol defineDB;
    			std::vector<std::string> stack_incfile;
			str = return_preprocessed_file(fileName, incdir, defineDB,stack_incfile,vPreprocessor::VERILOG2001);

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
    			std::vector<std::string> stack_incfile;
			str = return_preprocessed_file(fileName, incdir, defineDB,stack_incfile,vPreprocessor::SV2012);

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

    struct stat buffer;
    if (stat(fileName.c_str(), &buffer) != 0) {
        throw ParseException(fileName + " does not exist.");
    }
    
    macroSymbol defineDB;
    std::vector<std::string> stack_incfile;
    std::string result = return_preprocessed_file(fileName, incdir, defineDB, stack_incfile, mode);
    return result;

}

