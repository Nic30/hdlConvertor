#include "named.h"
#include <stdlib.h>

namespace hdlConvertor {
namespace hdlObjects {

Named::Named() {
	name = nullptr;
}

Named::Named(char * name) :
		name(name) {
}

Named::~Named() {
	free(name);
}

WithNameAndDoc::WithNameAndDoc() :
		Named() {
}

WithNameAndDoc::WithNameAndDoc(char * name) :
		Named(name) {
}

}
}
