#pragma once

#include <vector>
#include "iHdlObj.h"

namespace hdlConvertor {
namespace hdlObjects {

class Context {
public:
	std::vector<iHdlObj*> objs;

	~Context();
};

}
}
