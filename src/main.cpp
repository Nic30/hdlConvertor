#include "hdlConvertorModule.h"
#include "convertor.h"
#include <Python.h>
/*
 * This file is just test for parsers
 * Main file is file of python module (hdlConvertorModule.cpp).
 * */

const char *pycode = "from pprint import pprint\n"
		"\n"
		"pprint(c)";

#define PY

void printInPprint(Context * c) {
	PyObject *main_module, *main_dict;
	/* Setup the __main__ module for us to use */
	main_module = PyImport_ImportModule("__main__");
	main_dict = PyModule_GetDict(main_module);

	/* Inject a variable into __main__ */
	auto jsn = c->toJson();
	delete c;
	PyDict_SetItemString(main_dict, "c", jsn);

	/* Run the code snippet above in the current environment */
	PyRun_SimpleString(pycode);
}

int main(int argc, char *argv[]) {
	auto c = new Convertor();

	//const char * f = "../../samples/verilogCodesign/verilog/axiCrossbar.v";
	//const char * f = "../../samples/verilogCodesign/verilog/simpleParam.v";
	//const char * f = "../../samples/iLvl/vhdl/fnImportLog2/package0.vhd";
	//const char * f = "../../samples/iLvl/vhdl/dmaWrap/misc.vhd";
	//const char * f = "../../samples/iLvl/vhdl/dependencies0/simpleSubunit3_arch.vhd";
	//const char * f = "../../samples/iLvl/vhdl/sizeExpressions.vhd";
	//const char * f = "/home/nic30/Documents/workspace/sprobe10/fpgalibs/src/axi/pkg/axi_pkg.vhd";
	//const char * f = "../../samples/iLvl/vhdl/bitStringValuesEnt.vhd";
	//const char * f = "../../samples/iLvl/vhdl/minimals/packageBody.vhd";
	const char * f = "../../samples/iLvl/vhdl/minimals/functionBody.vhd";
	//const char * f = "../../samples/verilogCodesign/verilog/interfaceArrayAxi4.v";
#ifdef PY
	Py_SetProgramName((wchar_t*) "test"); /* optional but recommended */
	Py_Initialize();
#endif

	Context * ctx = c->parse(f, VHDL, false, true);
	delete c;

	if (ctx) {
#ifdef PY
		printInPprint(ctx);
#else
		ctx->dump(0);
#endif
	}else {
		perror("Error");
	}
#ifdef PY
	Py_Finalize();
#endif
	return 0;
}
