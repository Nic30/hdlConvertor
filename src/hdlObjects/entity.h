#pragma once
#include "named.h"
#include "variable.h"
#include "port.h"
#include "position.h"

namespace hdlConvertor {
namespace hdlObjects {

class Entity: public WithNameAndDoc {
public:
	std::vector<Variable*> generics;
	std::vector<Port*> ports;

	Entity();
	Port * getPortByName(const char * name);
	~Entity();
};

}
}
