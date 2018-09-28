#include "hdlConvertorModule.h"
#include "convertor.h"

#ifdef USE_PYTHON

static PyMethodDef hdlConvertorMethods[] = {
	{
		"parse",                          // method name
		(PyCFunction) hdlConvertor_parse, // method function
		METH_VARARGS | METH_KEYWORDS,     // flags
		"parse(filename, language, lexErrorHandler=lambda..., hierarchyOnly=False, debug=False)"
		"\n"
		":param filename: name of file to parse\n"
		":param language: vhdl|verilog\n"
		":param syntaxErrorHandler: syntax error callback params (filename, line, row, errDescriptionStr)\n"
		"                       If lexical error occurs this callback is called and then parsing\n"
		"                       process continues. \n"
		"                       Default is "
		"                       def f(filename, line, row, errDescriptionStr):"
		"                            sys.stderr.write(\"LEX_ERROR:%s:%d:%d:%s\"\n"
		"                                     %(filename, line, row, errDescriptionStr))     "
		":param hierarchyOnly: If this flag is set only only items which are affecting hierarchy\n"
		"              are parsed that means only name and presence of entity, package/packageHeader,\n"
		"              architecture and name and presence of component instances inside "
		"              and all includes. \n"
		":param debug: If this flag is set internal Error/NotImplemented/Unexpected exceptions"
		"              are printed on stderr\n"
	}, {nullptr, nullptr, 0, nullptr} // Sentinel
};

static struct PyModuleDef hdlConvertor = {
	PyModuleDef_HEAD_INIT,
	"hdlConvertor",            // name of module
	"parser of VHDL/Verilog and other HDL languages", // module documentation, may be nullptr
	-1, /* size of per-interpreter state of the module,
	 or -1 if the module keeps state in global variables. */
	hdlConvertorMethods
};

PyObject *
hdlConvertor_parse(PyObject *self, PyObject *args, PyObject *keywds) {
	char *filename = nullptr, *langue = nullptr;
	bool debug = false, hierarchyOnly = false;
	Langue _lang;
	PyObject * syntaxErrorHandler = nullptr, *_debug = nullptr,
			*_hierarchyOnly = nullptr;

	static const char* const kwlist[] = { "filename", "language",
			"syntaxErrorHandler", "hierarchyOnly", "debug", nullptr };

	if (!PyArg_ParseTupleAndKeywords(args, keywds, "ss|OOO", (char **) kwlist,
			&filename, &langue, &syntaxErrorHandler, &_hierarchyOnly,
			&_debug)) {
		return nullptr;
	}
	if (_hierarchyOnly)
		hierarchyOnly = PyObject_IsTrue(_hierarchyOnly);
	if (_debug)
		debug = PyObject_IsTrue(_debug);

	//toLowercase((char *) langue);
	MOD_DEBUG("hierarchyOnly: " << hierarchyOnly);
	MOD_DEBUG("debug: " << debug);
	MOD_DEBUG("langue:" << langue);

	if (strcmp(langue, "vhdl") == 0) {
		_lang = VHDL;
	} else if (strcmp(langue, "verilog") == 0) {
		_lang = VERILOG;
	} else if (strcmp(langue, "system_verilog") == 0) {
		_lang = SYSTEM_VERILOG;
	} else {
		PyErr_SetString(PyExc_TypeError,
				"Invalid language specified, only vhdl, verilog and system_verilog is available");
		return nullptr;
	}
	Context * c = Convertor::parse(filename, _lang, hierarchyOnly, debug);
	if (!c) {
		switch (Convertor::err) {
		case PERR_FILE:
			PyErr_SetString(PyExc_IOError, strerror(errno));
			break;
		case PARSING_ERR:
			PyErr_SetString(PyExc_Exception, Convertor::errStr);
			break;
		case CONVERTING_ERR:
			PyErr_SetString(PyExc_Exception, Convertor::errStr);
			break;
		default:
			PyErr_SetString(PyExc_TypeError,
					"Converter::parse did not returned correct context for file");
		}
		return nullptr;
	}

	MOD_DEBUG("cntx loaded");
	PyObject * d = nullptr;
	try {
		d = c->toJson();
	} catch (const char * errStr) {
		PyErr_SetString(PyExc_Exception, errStr);
	}
	delete c;
	MOD_DEBUG("cntx in json");
	return d;
}

PyMODINIT_FUNC PyInit_hdlConvertor(void) {
	return PyModule_Create(&hdlConvertor);
}
#endif
