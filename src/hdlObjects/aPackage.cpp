#include "aPackage.h"

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

aPackage::aPackage() :
		WithNameAndDoc() {
}

aPackage::~aPackage() {
	for (auto c : components)
		delete c;
	for (auto f : function_headers)
		delete f;
	for (auto f : functions)
		delete f;
	for (auto s : subtype_headers)
		delete s;
	for (auto f : variables)
		delete f;
	for (auto s : signals)
		delete s;
}

}
}
