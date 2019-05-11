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
}

}
}
