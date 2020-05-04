#pragma once

#include <vector>
#include <memory>
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlObj.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL library reference
 * */
class HdlLibrary : public WithNameAndDoc, public iHdlObj {
public:
	HdlLibrary(const std::string& name);
	~HdlLibrary();
};

}
}
