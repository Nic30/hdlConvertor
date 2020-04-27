#include <hdlConvertor/hdlObjects/named.h>
#include <stdlib.h>

namespace hdlConvertor {
namespace hdlObjects {

Named::Named() {
}

Named::Named(const std::string &name) :
		name(name) {
}

Named::~Named() {
}

WithDoc::~WithDoc() {
}

WithPos::~WithPos() {
}

WithNameAndDoc::WithNameAndDoc() :
		WithPos(), WithDoc(), Named() {
}

WithNameAndDoc::WithNameAndDoc(const std::string &name) :
		WithPos(), WithDoc(), Named(name) {
}

WithNameAndDoc::~WithNameAndDoc() {
}

}
}
