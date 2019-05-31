#include "aPackage.h"

using namespace std;

namespace hdlConvertor {
namespace hdlObjects {

aPackage::aPackage() :
		WithNameAndDoc() {
}

aPackage::~aPackage() {
	for (auto o : objs)
		delete o;
}

}
}
