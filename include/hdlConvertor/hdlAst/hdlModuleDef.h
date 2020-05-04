#pragma once

#include <vector>
#include <hdlConvertor/hdlAst/hdlModuleDec.h>


namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for module definition (the body of the module in Verilog, Architecture in VHDL)
 * */
class HdlModuleDef: public WithNameAndDoc, public iHdlObj {
public:
	std::unique_ptr<iHdlExprItem> module_name;
	std::unique_ptr<HdlModuleDec> dec;

	std::vector<std::unique_ptr<iHdlObj>> objs;

	~HdlModuleDef();
};

}
}
