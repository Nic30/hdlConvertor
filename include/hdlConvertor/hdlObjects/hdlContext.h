#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Container of any HDL objects
 * */
class HdlContext {
public:
	std::vector<iHdlObj*> objs;

	~HdlContext();
};

}
}
