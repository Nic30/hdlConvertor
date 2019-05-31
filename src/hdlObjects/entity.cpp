#include "entity.h"

namespace hdlConvertor {
namespace hdlObjects {

Entity::Entity() :
		WithNameAndDoc() {
}
Variable * Entity::getPortByName(const char * name) {
	for (auto p : ports) {
		assert(p->name);
		if (strcmp(p->name, name) == 0)
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
