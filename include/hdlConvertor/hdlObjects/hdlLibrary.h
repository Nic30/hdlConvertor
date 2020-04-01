#pragma once

#include <vector>
#include <memory>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

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
