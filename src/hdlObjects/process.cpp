#include "process.h"

namespace hdlConvertor {
namespace hdlObjects {

Process::Process() :
		WithNameAndDoc(), sensitivity_list_specified(false) {
}

#ifdef USE_PYTHON
PyObject * Process::toJson() const {
	PyObject *d = WithNameAndDoc::toJson();
	if (sensitivity_list_specified)
		addJsonArrP(d, "sensitivity_list", sensitivity_list);

	addJsonArrP(d, "statements", statements);

	return d;
}
#endif

Process::~Process() {
	for (auto stm : statements)
		delete stm;
}

}
}
