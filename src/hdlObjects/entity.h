#pragma once
#include "named.h"
#include "variable.h"
#include "position.h"
#include "iHdlObj.h"


namespace hdlConvertor {
namespace hdlObjects {

class Entity: public WithNameAndDoc, public iHdlObj {
public:
	std::vector<Variable*> generics;
	std::vector<Variable*> ports;

	Entity();
	Variable * getPortByName(const char * name);
	~Entity();
};

}
}
