#include <hdlConvertor/hdlObjects/process.h>

namespace hdlConvertor {
namespace hdlObjects {

Process::Process() :
		Statement(s_PROCESS), sensitivity_list_specified(false) {
	sub_statements.push_back(new std::vector<iHdlObj*>());
}
Process::Process(std::vector<Expr*> * sensitivity, std::vector<iHdlObj*> * body) :
		Statement(s_PROCESS) {
	if (sensitivity) {
		exprs.resize(sensitivity->size());
		std::copy(sensitivity->begin(), sensitivity->end(), exprs.begin());
		sensitivity_list_specified = true;
		delete sensitivity;
	} else {
		sensitivity_list_specified = false;
	}
	sub_statements.push_back(body);
}
std::vector<Expr*> & Process::sensitivity_list() {
	return exprs;
}
std::vector<iHdlObj*> & Process::objs() {
	return *sub_statements[0];
}
const std::vector<Expr*> & Process::sensitivity_list() const {
	return exprs;
}
const std::vector<iHdlObj*> & Process::objs() const {
	return *sub_statements[0];
}
}
}
