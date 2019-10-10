#pragma once

#include <vector>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for module definition (the body of the module in Verilog, Architecture in VHDL)
 * */
class HdlModuleDef: public WithNameAndDoc, public iHdlObj {
public:
	std::unique_ptr<iHdlExpr> entityName;

	std::vector<std::unique_ptr<iHdlObj>> objs;

	~HdlModuleDef();
};

}
}
