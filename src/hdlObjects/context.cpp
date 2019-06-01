#include "context.h"

namespace hdlConvertor {
namespace hdlObjects {

Context::~Context() {
	for (auto o: objs)
		delete o;
}

}
}
