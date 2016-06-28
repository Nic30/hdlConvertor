#pragma once

#include <iostream>
#include <fstream>
#include <unistd.h>

#include "hdlObjects/context.h"
#include "antlr4-runtime.h"

#include "VhdlParser/vhdlLexer.h"
#include "VhdlParser/vhdlParser.h"
#include "vhdlConvertor/designFileParser.h"

#include "VerilogParser/Verilog2001Lexer.h"
#include "VerilogParser/Verilog2001Parser.h"
#include "verilogConvertor/source_textParser.h"

#include "syntaxErrorLogger.h"
#include "langue.h"
#include "parserContainer.h"

using namespace antlr4;
using namespace vhdl;


class Convertor {

public:
	static const char * fileName;
	static Langue lang;
	static bool hierarchyOnly;
	static bool debug;
	static ParserErrors err;

	static Context * parse(
			const char * fileName,
			Langue lang,
			bool hierarchyOnly,
			bool debug);

};
