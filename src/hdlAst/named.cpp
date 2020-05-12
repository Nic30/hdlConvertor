#include <hdlConvertor/hdlAst/named.h>
#include <stdlib.h>

namespace hdlConvertor {
namespace hdlAst {

Named::Named() {
}

Named::Named(const std::string & name) :
		name(name) {
}

Named::~Named() {
}

WithNameAndDoc::WithNameAndDoc() :
		Named() {
}

WithNameAndDoc::WithNameAndDoc(const std::string & name) :
		Named(name) {
}

}
}
