#include <hdlConvertor/hdlObjects/hdlContext.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlContext::~HdlContext() {
	for (auto o: objs)
		delete o;
}

}
}
