#include <hdlConvertor/hdlObjects/hdlModuleDef.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlModuleDef::~HdlModuleDef() {
	for (auto o: objs)
		delete o;
}

}
}
