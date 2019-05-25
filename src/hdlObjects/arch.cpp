#include "arch.h"

namespace hdlConvertor {
namespace hdlObjects {

Arch::~Arch() {
	for (auto c : componentInstances)
		delete c;
	for (auto s : statements)
		delete s;
	for (auto v : variables)
		delete v;
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
