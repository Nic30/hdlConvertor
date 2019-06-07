#pragma once
#include <vector>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/expr.h>
#include <hdlConvertor/hdlObjects/position.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

class CompInstance: public WithDoc, public WithPos, public iHdlObj {
public:
	Expr * name;
	Expr * entityName;
	std::vector<Expr*> genericMap;
	std::vector<Expr*> portMap;

	CompInstance(Expr * name, Expr * _entityName);
	~CompInstance();
};

}
}
