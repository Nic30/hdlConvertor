#include <hdlConvertor/hdlAst/hdlModuleDec.h>
#include <assert.h>

namespace hdlConvertor {
namespace hdlAst {

HdlModuleDec::HdlModuleDec() :
		WithNameAndDoc() {
}
HdlIdDef* HdlModuleDec::getPortByName(const std::string &name) {
	for (auto & p : ports) {
		if (p->name == name)
			return p.get();
	}
	return nullptr;
}

HdlModuleDec::~HdlModuleDec() {
}

}
}
