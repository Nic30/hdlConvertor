#include "process.h"

namespace hdlConvertor {
namespace hdlObjects {

Process::Process() :
		WithNameAndDoc(), sensitivity_list_specified(false) {
}

Process::~Process() {
	for (auto s: sensitivity_list)
		delete s;
	for (auto o: objs)
		delete o;
}

}
}
