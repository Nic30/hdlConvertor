#include "generate.h"

namespace hdlConvertor {
namespace hdlObjects {

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

Generate::Generate() :
		WithNameAndDoc(), type(g_NONE) {
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

}
}
