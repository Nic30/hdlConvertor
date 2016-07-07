#include "convertor.h"
#include "atn/PredictionMode.h"

const char * Convertor::fileName = NULL;
Langue Convertor::lang = VHDL;
bool Convertor::hierarchyOnly = false;
bool Convertor::debug = false;
ParserErrors Convertor::err = PERR_OK;

void parseFnVerilog(
		Verilog2001Parser * antlrParser,
		Source_textParser * hdlParser) {
	Ref<Verilog2001Parser::Source_textContext> tree =
			antlrParser->source_text();
	hdlParser->visitSource_text(tree);
	tree.reset();
}

void parseFnVHDL(vhdlParser * antlrParser, DesignFileParser * hdlParser) {
	Ref<vhdlParser::Design_fileContext> tree = antlrParser->design_file();
	hdlParser->visitDesign_file(tree);
	tree.reset();
}

Context * Convertor::parse(
		const char * _fileName,
		Langue _lang,
		bool _hierarchyOnly,
		bool _debug) {
	fileName = _fileName;
	lang = _lang;
	hierarchyOnly = _hierarchyOnly;
	debug = _debug;
	Context * c = NULL;

	if (lang == VHDL) {
		auto pc =
				new ParserContainer<vhdlLexer, vhdlParser, DesignFileParser>();
		err = pc->parseFile(fileName, hierarchyOnly, debug, parseFnVHDL);
		c = pc->context;
		delete pc;

	} else if (lang == VERILOG) {
		auto pc = new ParserContainer<Verilog2001Lexer, Verilog2001Parser,
				Source_textParser>();
		err = pc->parseFile(fileName, hierarchyOnly, debug, parseFnVerilog);
		c = pc->context;
		delete pc;

	}
	return c;
}
