#pragma once

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <streambuf>

#include <hdlConvertor/hdlObjects/hdlContext.h>

#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlLexer.h>
#include <hdlConvertor/vhdlConvertor/vhdlParser/vhdlParser.h>
#include <hdlConvertor/vhdlConvertor/designFileParser.h>

#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Lexer.h>
#include <hdlConvertor/verilogConvertor/Verilog2001Parser/Verilog2001Parser.h>
#include <hdlConvertor/verilogConvertor/source_textParser.h>

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Lexer.h>
#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/source_textParser.h>

#include <hdlConvertor/verilogPreproc/verilogPreproc.h>

#include <hdlConvertor/conversion_exception.h>
#include <hdlConvertor/syntaxErrorLogger.h>
#include <hdlConvertor/language.h>
#include <hdlConvertor/parserContainer.h>

namespace hdlConvertor {

class Convertor {

public:
	bool hierarchyOnly;
	static bool debug;
	hdlObjects::HdlContext *c;

	hdlObjects::HdlContext* parse(const std::vector<std::string> &fileNames,
			Language lang, std::vector<std::string> incdirs, bool hierarchyOnly,
			bool debug);
	hdlObjects::HdlContext* parse_str(const std::string &hdl_str, Language lang,
			std::vector<std::string> incdirs, bool hierarchyOnly, bool debug);

	std::string verilog_pp(const std::string &filename,
			const std::vector<std::string> incdirs, Language lang);
	std::string verilog_pp_str(const std::string &verilog_str,
			const std::vector<std::string> incdirs, Language lang);

};

}
