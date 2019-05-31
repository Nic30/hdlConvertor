#include "port.h"

namespace hdlConvertor {
namespace hdlObjects {

Port::Port(Direction direction, Variable * variable) {
	this->direction = direction;
	this->variable = variable;
}

Port::~Port() {
	if (variable)
		delete variable;
}

}
}
