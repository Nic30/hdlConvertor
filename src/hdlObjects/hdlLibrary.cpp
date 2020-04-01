#include <hdlConvertor/hdlObjects/hdlLibrary.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlLibrary::HdlLibrary(const std::string& name) :
		WithNameAndDoc(name), iHdlObj() {
}
    
HdlLibrary::~HdlLibrary() {
}

}
}
