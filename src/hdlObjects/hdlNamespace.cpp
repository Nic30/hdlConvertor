#include <hdlConvertor/hdlObjects/hdlNamespace.h>

namespace hdlConvertor {
namespace hdlObjects {

using namespace std;

HdlNamespace::HdlNamespace() :
		WithNameAndDoc(), defs_only(false) {
}

HdlNamespace::~HdlNamespace() {
	for (auto o : objs)
		delete o;
}

}
}
