#include "hdlConvertorModule.h"
#include "convertor.h"

#include <iostream>

#include "antlr4-runtime.h"
#include "VhdlParser/vhdlLexer.h"
#include "VhdlParser/vhdlParser.h"
#include "VhdlParser/vhdlVisitor.h"

#include "support/StringUtils.h"

/*
 * This file is just test for parsers
 * Main file is file of python module (hdlConvertorModule.cpp).
 * */

#ifdef USE_PYTHON
const char *pycode = "from pprint import pprint\n"
		"\n"
		"pprint(c)";

void printInPprint(Context * c) {
	PyObject *main_module, *main_dict;
	/* Setup the __main__ module for us to use */
	main_module = PyImport_ImportModule("__main__");
	main_dict = PyModule_GetDict(main_module);

	/* Inject a variable into __main__ */
	try {
		auto jsn = c->toJson();
		delete c;
		PyDict_SetItemString(main_dict, "c", jsn);
	} catch (const char * errStr) {
		std::cerr << "Error while toJson(): " << errStr << std::endl;
		return;
	}

	/* Run the code snippet above in the current environment */
	PyRun_SimpleString(pycode);
}
#endif

using namespace antlr4;
using namespace vhdl;

//int main(int argc, const char* argv[]) {
//  ANTLRInputStream input(
//    "package body package0 is\n"
//    " function fn0 (param0 : bitvector) return bit is\n"
//    "  begin\n"
//    "  end fn0;\n"
//    "end package0;"
//  );
//  vhdlLexer lexer(&input);
//  CommonTokenStream tokens(&lexer);
//
//  tokens.fill();
//  //for (auto token : tokens.getTokens())
//  //  std::cout << token->toString() << std::endl;
//
//  vhdlParser parser(&tokens);
//
//  Ref<tree::ParseTree> tree = parser.design_file();
//
//
//  return 0;
//}

int main(int argc, char *argv[]) {
	auto c = new Convertor();

	//const char * f = "../../samples/verilogCodesign/verilog/axiCrossbar.v";
	//const char * f = "../../samples/verilogCodesign/verilog/simpleParam.v";
	//const char * f = "../hwtLib/hwtLib/samples/vhdlCodesign/vhdl/fnImportLog2/package0.vhd";
	//const char * f = "../../samples/iLvl/vhdl/dmaWrap/misc.vhd";
	//const char * f = "../../samples/iLvl/vhdl/dependencies0/simpleSubunit3_arch.vhd";
	//const char * f = "../../samples/iLvl/vhdl/sizeExpressions.vhd";
	//const char * f = "/home/nic30/Documents/workspace/sprobe10/fpgalibs/src/axi/pkg/axi_pkg.vhd";
	//const char * f = "../../samples/iLvl/vhdl/bitStringValuesEnt.vhd";
	//const char * f = "../../samples/iLvl/vhdl/minimals/packageBody.vhd";
	// const char * f = "../hwtLib/hwtLib/samples/vhdlCodesign/vhdl/minimals/functionBody.vhd";
	//const char * f = "../../samples/verilogCodesign/verilog/interfaceArrayAxi4.v";
	//const char * f = "tests/mux.vhd";
	//const char * f = "tests/uart.v";
	//const char * f = "tests/mem_base_object.sv";
	//const char * f = "tests/package_example.vhd";
	const char * f = "tests/stcu_integr_pkg.vhd";

#ifdef USE_PYTHON
	Py_SetProgramName((wchar_t*) "test"); /* optional but recommended */
	Py_Initialize();
#endif

	Context * ctx = c->parse(f, VHDL, false, true);
	delete c;

	if (ctx) {
#ifdef USE_PYTHON
		printInPprint(ctx);
#else
		ctx->dump(0);
#endif
	} else {
		perror("Error");
	}
#ifdef USE_PYTHON
	Py_Finalize();
#endif
	return 0;
}
