#pragma once

#include <vector>
#include <memory>
#include <hdlConvertor/hdlAst/iHdlObj.h>

namespace hdlConvertor {
namespace hdlAst {

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
