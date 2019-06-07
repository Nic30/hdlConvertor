#pragma once

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <streambuf>

#include <hdlConvertor/hdlObjects/context.h>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlLexer.h>
#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/vhdlConvertor/designFileParser.h>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Lexer.h>
#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>
#include <hdlConvertor/verilogConvertor/source_textParser.h>

#define SV_PARSER

#ifdef SV_PARSER
#include <hdlConvertor/svConvertor/sv2012Parser/sv2012Lexer.h>
#include <hdlConvertor/svConvertor/sv2012Parser/sv2012Parser.h>
#include <hdlConvertor/svConvertor/source_textParser.h>
#endif

#include <hdlConvertor/verilogPreproc/vPreprocessor.h>

#include <hdlConvertor/conversion_exception.h>
#include <hdlConvertor/syntaxErrorLogger.h>
#include <hdlConvertor/language.h>
#include <hdlConvertor/parserContainer.h>

namespace hdlConvertor {

class Convertor {

public:
	std::string fileName;
	Language lang;
	bool hierarchyOnly;
	static bool debug;

	hdlObjects::Context * parse(std::vector<std::string> fileNames,
			Language lang, std::vector<std::string>,
			bool hierarchyOnly, bool debug);

	std::string verilog_pp(const std::string, std::vector<std::string> incdir,
			unsigned int mode);

};

}
