#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * The container for the vhdl architecture or the body of the module in verilog
 * */
class Arch: public WithNameAndDoc, public iHdlObj {
public:
	Expr * entityName;

	std::vector<iHdlObj*> objs;

	~Arch();
};

}
}
