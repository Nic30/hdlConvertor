#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

// [TODO] change to namespace
class aPackage: public WithNameAndDoc, public iHdlObj {
public:

	std::vector<iHdlObj*> objs;

	aPackage();
	~aPackage();
};

}
}
