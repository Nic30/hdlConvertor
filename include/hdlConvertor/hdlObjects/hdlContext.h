#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

class HdlContext {
public:
	std::vector<iHdlObj*> objs;

	~HdlContext();
};

}
}
