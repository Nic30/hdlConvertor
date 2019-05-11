#include "entity.h"

namespace hdlConvertor {
namespace hdlObjects {

Entity::Entity() :
		WithNameAndDoc() {
}
Port * Entity::getPortByName(const char * name) {
	for (auto p : ports) {
		assert(p->variable->name);
		if (strcmp(p->variable->name, name) == 0)
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
