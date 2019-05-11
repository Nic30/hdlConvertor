#include "process.h"

namespace hdlConvertor {
namespace hdlObjects {

Process::Process() :
		WithNameAndDoc(), sensitivity_list_specified(false) {
}

Process::~Process() {
	for (auto stm : statements)
		delete stm;
}

}
}
