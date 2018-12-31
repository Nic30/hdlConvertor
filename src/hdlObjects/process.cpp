#include "process.h"

Process::Process() {
}

#ifdef USE_PYTHON
PyObject * Process::toJson() const {
	PyObject *d = PyDict_New();

	if (name) {
		JSN_DEBUG("Process - name")
		PyDict_SetItemString(d, "name", PyUnicode_FromString(name));
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "name", Py_None);
	}

	if (position) {
		JSN_DEBUG("Process - position")
		PyDict_SetItemString(d, "position", position->toJson());
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "position", Py_None);
	}

	JSN_DEBUG("Process - function_headers")
	addJsonArrP(d, "function_headers", function_headers);

	JSN_DEBUG("Process - functions")
	addJsonArrP(d, "functions", functions);

	JSN_DEBUG("Process - subtype_headers")
	addJsonArrP(d, "subtype_headers", subtype_headers);

	JSN_DEBUG("Process - constants")
	addJsonArrP(d, "constants", constants);

	JSN_DEBUG("Process - variable")
	addJsonArrP(d, "variables", variables);

	JSN_DEBUG("Process - sensitivities")
	addJsonArrP(d, "sensitivities", sensitivities);

	if (!body.empty()) {
		JSN_DEBUG("Process - body")
		addJsonArrP(d, "body", body);	
	}
	return d;
}
#endif

void Process::dump(int indent) const {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	dumpArrP("function_headers", indent, function_headers) << ",\n";
	dumpArrP("functions", indent, functions) << ",\n";
	dumpArrP("subtype_headers", indent, subtype_headers) << ",\n";		
	dumpArrP("constants", indent, constants) << ",\n";
	dumpArrP("variables", indent, variables) << ",\n";
	dumpArrP("sensitivities", indent, sensitivities) << ",\n";
	
	//dumpArrP("body", indent, body) << ",\n";
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}


Process::~Process() {
	for (auto fh : function_headers)
		delete fh;
	for (auto f : functions)
		delete f;
	for (auto sh : subtype_headers)
		delete sh;	
    for (auto c : constants)
		delete c;
	for (auto v : variables)
		delete v;	    
    for (auto s : sensitivities)
		delete s;	        
    for (auto b : body)
		delete b; 		     
}