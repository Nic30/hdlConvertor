#include <hdlConvertor/hdlObjects/entity.h>

namespace hdlConvertor {
namespace hdlObjects {

Entity::Entity() :
		WithNameAndDoc() {
}
Variable * Entity::getPortByName(const std::string & name) {
	for (auto p : ports) {
		assert(p->name);
		if (p->name == name)
			return p;
	}
	return nullptr;
}

Entity::~Entity() {
	for (auto g : generics)
		delete g;
	for (auto p : ports)
		delete p;
}

}
}
