#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for namespace (namespace in System Verilog, package/package body in VHDL)
 * */
class HdlNamespace: public WithNameAndDoc, public iHdlObj {
public:
	bool defs_only;
	std::vector<iHdlObj*> objs;

	HdlNamespace();
	~HdlNamespace();
};

}
}
