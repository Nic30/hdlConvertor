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
	for (auto f : functions)
		delete f;
	for (auto f : variables)
		delete f;
}

}
}
