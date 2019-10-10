#pragma once

#include <vector>
#include <memory>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Container of any HDL objects
 * */
class HdlContext {
public:
	std::vector<std::unique_ptr<iHdlObj>> objs;

	~HdlContext();
};

}
}
