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
	//rhinton:: Although the grammar allows for a list of library 
	// names in a single library clause, it seems simpler to define
	// the hdlLibrary object with a single name.  If several library 
	// names are packed into a single library clause, the result will 
	// be one hdlLibrary object per name.
	HdlLibrary(const std::string& name);
	~HdlLibrary();
};

}
}
