#include <hdlConvertor/hdlObjects/hdlStmProcess.h>

namespace hdlConvertor {
namespace hdlObjects {

HdlStmProcess::HdlStmProcess() :
		iHdlStatement(s_PROCESS), sensitivity_list_specified(false) {
	sub_statements.push_back(new std::vector<iHdlObj*>());
}
HdlStmProcess::HdlStmProcess(std::vector<iHdlExpr*> * sensitivity,
		std::vector<iHdlObj*> * body) :
		iHdlStatement(s_PROCESS) {
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
std::vector<iHdlExpr*> & HdlStmProcess::sensitivity_list() {
	return exprs;
}
std::vector<iHdlObj*> & HdlStmProcess::objs() {
	return *sub_statements[0];
}
const std::vector<iHdlExpr*> & HdlStmProcess::sensitivity_list() const {
	return exprs;
}
const std::vector<iHdlObj*> & HdlStmProcess::objs() const {
	return *sub_statements[0];
}

}
}
