#include <hdlConvertor/hdlAst/hdlLibrary.h>

namespace hdlConvertor {
namespace hdlAst {

HdlLibrary::HdlLibrary(const std::string& name) :
		WithNameAndDoc(name), iHdlObj() {
}
    
HdlLibrary::~HdlLibrary() {
}

}
}
