#include "generate.h"

const char * GenerateType_toString(GenerateType type) {
	switch (type) {
	case g_NONE:
		return "NONE";		
	case g_IF:
		return "IF";
	case g_ELSIF:
		return "ELSIF";		
	case g_ELSE:
		return "ELSE";			
	case g_CASE: 
		return "CASE";
	case g_WHILE:
		return "WHILE";
	case g_FOR:
		return "FOR";	
	default:
		throw "Invalid StatementType";
	}
}

#ifdef USE_PYTHON
PyObject * Generate::toJson() const {
	PyObject *d = PyDict_New();

	if (name) {
		JSN_DEBUG("Generate - name")
		PyDict_SetItemString(d, "name", PyUnicode_FromString(name));
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "name", Py_None);
	}

	if (position) {
		JSN_DEBUG("Generate - position")
		PyDict_SetItemString(d, "position", position->toJson());
	} else {
		Py_IncRef (Py_None);
		PyDict_SetItemString(d, "position", Py_None);
	}

	PyDict_SetItemString(d, "type",
			PyUnicode_FromString(GenerateType_toString(type)));

	JSN_DEBUG("Arch - componentInstances")
	addJsonArrP(d, "componentInstances", componentInstances);

	JSN_DEBUG("Arch - components")
	addJsonArrP(d, "components", components);

	JSN_DEBUG("Arch - function_headers")
	addJsonArrP(d, "function_headers", function_headers);

	JSN_DEBUG("Arch - functions")
	addJsonArrP(d, "functions", functions);

	JSN_DEBUG("Arch - subtype_headers")
	addJsonArrP(d, "subtype_headers", subtype_headers);

	JSN_DEBUG("Arch - variables")
	addJsonArrP(d, "variables", variables);

	JSN_DEBUG("Arch - signals")
	addJsonArrP(d, "signals", signals);

	JSN_DEBUG("Arch - constants")
	addJsonArrP(d, "constants", constants);

	JSN_DEBUG("Arch - processes")
	addJsonArrP(d, "processes", processes);

	JSN_DEBUG("Arch - generates")
	addJsonArrP(d, "generates", generates);
	
	return d;
}
#endif

void Generate::dump(int indent) const {
	mkIndent(indent) << "{\n";
	indent += INDENT_INCR;
	dumpArrP("componentInstances", indent, componentInstances) << ",\n";
	dumpArrP("components", indent, components) << ",\n";	
	dumpArrP("constants", indent, constants) << ",\n";	
	dumpArrP("function_headers", indent, function_headers) << ",\n";	
	dumpArrP("functions", indent, functions) << ",\n";	
	dumpArrP("subtype_headers", indent, subtype_headers) << ",\n";	
	dumpArrP("variables", indent, variables) << ",\n";						
	dumpArrP("processes", indent, processes) << ",\n";
	dumpArrP("generates", indent, generates) << ",\n";		
	indent -= INDENT_INCR;
	mkIndent(indent) << "}";
}


Generate::~Generate() {
	for (auto c : componentInstances)
		delete c;
	for (auto c : components)
		delete c;
	for (auto c : constants)
		delete c;		
	for (auto fh : function_headers)
		delete fh;
	for (auto f : functions)
		delete f;
	for (auto sh : subtype_headers)
		delete sh;				
	for (auto v : variables)
		delete v;	
	for (auto p : processes)
		delete p;	
	for (auto g : generates)
		delete g;	  	
}
