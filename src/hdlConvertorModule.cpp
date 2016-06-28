#include "hdlConvertorModule.h"
#include "langue.h"
#include "convertor.h"

#define ch(str) ((const char *) str)
//inline char * __str__(PyObject* obj) {
//	return PyUnicode_AsUTF8(PyObject_Str(obj));
//}
//char * toLowercase(char * str) {
//	while (*str) {
//		*str = tolower(*str);
//		str++;
//	}
//	return str;
//}

static PyMethodDef hdlConvertorMethods[] =
		{
				{ "parse", (PyCFunction) hdlConvertor_parse,
				METH_VARARGS | METH_KEYWORDS,
						"parse(filename, language, lexErrorHandler=lambda..., hierarchyOnly=False, debug=False)"
								"@param filename: name of file to parse\n"
								"@param language: vhdl|verilog\n"
								"@param syntaxErrorHandler: syntax error callback params (filename, line, row, errDescriptionStr)\n"
								"                       If lexical error occurs this callback is called and then parsing\n"
								"                       process continues. \n"
								"                       Default is "
								"                       def f(filename, line, row, errDescriptionStr):"
								"                            sys.stderr.write(\"LEX_ERROR:%s:%d:%d:%s\"\n"
								"                                     %(filename, line, row, errDescriptionStr))     "
								"@param hierarchyOnly: If this flag is set only only items which are affecting hierarchy\n"
								"              are parsed that means only name and presence of entity, package/packageHeader,\n"
								"              architecture and name and presence of component instances inside "
								"              and all includes. \n"
								"@param debug: If this flag is set internal Error/NotImplemented/Unexpected exceptions"
								"              are printed on stderr\n" }, {
				NULL, NULL, 0, NULL } /* Sentinel */
		};

static struct PyModuleDef hdlConvertor = {
PyModuleDef_HEAD_INIT, ch("hdlConvertor"), /* name of module */
NULL, //spam_doc, /* module documentation, may be NULL */
		-1, /* size of per-interpreter state of the module,
		 or -1 if the module keeps state in global variables. */
		hdlConvertorMethods };

PyObject *
hdlConvertor_parse(PyObject *self, PyObject *args, PyObject *keywds) {
	char *filename = NULL, *langue = NULL;
	bool debug = false, hierarchyOnly = false;
	Langue _lang;
	PyObject * syntaxErrorHandler = NULL, *_debug = NULL,
			*_hierarchyOnly = NULL;

	static const char* const kwlist[] = { "filename", "language",
			"syntaxErrorHandler", "hierarchyOnly", "debug", NULL };

	if (!PyArg_ParseTupleAndKeywords(args, keywds, "ss|OOO", (char **) kwlist,
			&filename, &langue, &syntaxErrorHandler, &_hierarchyOnly,
			&_debug)) {
		return NULL;
	}
	if (_hierarchyOnly)
		hierarchyOnly = PyObject_IsTrue(_hierarchyOnly);
	if (_debug)
		debug = PyObject_IsTrue(_debug);

	//toLowercase((char *) langue);
	MOD_DEBUG("hierarchyOnly: " << hierarchyOnly); MOD_DEBUG("debug: " << debug); MOD_DEBUG("langue:" << langue);

	if (strcmp(langue, "vhdl") == 0) {
		_lang = VHDL;

	} else if (strcmp(langue, "verilog") == 0) {
		_lang = VERILOG;
	} else {
		PyErr_SetString(PyExc_TypeError,
				"Invalid language specified, only vhdl and verilog is available");
		return NULL;
	}
	Context * c = Convertor::parse(filename, _lang, hierarchyOnly, debug);
	if (!c) {
		switch (Convertor::err) {
		case PERR_FILE:
			PyErr_SetString(PyExc_IOError, strerror(errno));
			break;
		default:
			PyErr_SetString(PyExc_TypeError,
					"Converter::parse did not returned correct context for file");
		}
		return NULL;
	}

	MOD_DEBUG("cntx loaded");
	PyObject * d = c->toJson();
	delete c;
	MOD_DEBUG("cntx in json");
	return d;
}
PyMODINIT_FUNC PyInit_hdlConvertor(void) {
	return PyModule_Create(&hdlConvertor);
}
