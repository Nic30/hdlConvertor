#include <hdlConvertor/hdlObjects/hdlModuleDec.h>
#include <assert.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlModuleDec::HdlModuleDec() :
		WithNameAndDoc() {
}
HdlVariableDef * HdlModuleDec::getPortByName(const std::string & name) {
	for (auto p : ports) {
		assert(!p->name.empty());
		if (p->name == name)
			return p;
	}
	return nullptr;
}

HdlModuleDec::~HdlModuleDec() {
	for (auto g : generics)
		delete g;
	for (auto p : ports)
		delete p;
}

}
}
