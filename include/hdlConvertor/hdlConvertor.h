#pragma once

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <streambuf>

#include <hdlConvertor/conversion_exception.h>
#include <hdlConvertor/syntaxErrorLogger.h>
#include <hdlConvertor/language.h>
#include <hdlConvertor/parserContainer.h>
#include <hdlConvertor/hdlAst/hdlContext.h>
#include <hdlConvertor/verilogPreproc/verilogPreproc.h>

namespace hdlConvertor {

class HdlConvertor {

public:
	bool hierarchyOnly;
	static bool debug;
	hdlAst::HdlContext &c;
	verilog_pp::MacroDB defineDB;

	HdlConvertor(hdlAst::HdlContext &c);

	void parse(const std::vector<std::string> &fileNames, Language lang,
			std::vector<std::string> incdirs, const std::string &encoding,
			bool hierarchyOnly, bool debug);
	void parse_str(const std::string &hdl_str, Language lang,
			std::vector<std::string> incdirs, const std::string &encoding,
			bool hierarchyOnly, bool debug);

	std::string verilog_pp(const std::string &filename,
			const std::vector<std::string> incdirs, Language lang,
			const std::string &encoding);
	std::string verilog_pp_str(const std::string &verilog_str,
			const std::vector<std::string> incdirs, Language lang,
			const std::string &encoding);

	virtual ~HdlConvertor();
};

}
