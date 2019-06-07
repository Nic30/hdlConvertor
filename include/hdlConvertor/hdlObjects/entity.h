#pragma once
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/variable.h>
#include <hdlConvertor/hdlObjects/position.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>


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
