#pragma once

#include <vector>
#include "statement.h"

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Class for representation of the process in HDL
 * @note the process may may be described only by statement in HDL
 * 		this means that it does not have to have name or sensitivity list
 * 		specified explicitly
 * */
class Process: public Statement {
public:

	bool sensitivity_list_specified;

	std::vector<Expr*> & sensitivity_list();
	std::vector<iHdlObj*> & objs();

	const std::vector<Expr*> & sensitivity_list() const;
	const std::vector<iHdlObj*> & objs() const;

	Process();
	Process(std::vector<Expr*> * sensitivity, std::vector<iHdlObj*> * body);
};

}
}

