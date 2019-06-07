#include <hdlConvertor/hdlObjects/arch.h>

namespace hdlConvertor {
namespace hdlObjects {

Arch::~Arch() {
	for (auto o: objs)
		delete o;
}

}
}
