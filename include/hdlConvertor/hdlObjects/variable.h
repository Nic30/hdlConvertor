#pragma once

#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/direction.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * Class for representation of port constants, signals and other variables
 *
 * @note if variable is a port the direction is set to something else than Direction::DIR_INTERNAL
 * @note latched flag corresponds to verilog "reg" or vhdl variable
 **/
class Variable: public WithNameAndDoc, public iHdlObj {
public:
	Expr * type;
	Expr * value;
	bool latched;
	bool is_const;
	Direction direction;

	Variable(std::string id, Expr * type, Expr * val);
	~Variable();
};

}
}
