#include "process.h"

namespace hdlConvertor {
namespace hdlObjects {

Process::Process() :
		WithNameAndDoc(), sensitivity_list_specified(false) {
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
	for (auto s : sensitivity_list)
		delete s;
	for (auto s : statements)
		delete s;
}

}
}
