#pragma once

#include <vector>
#include <memory>
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
	std::vector<std::unique_ptr<iHdlObj>> objs;

	HdlNamespace();
	virtual ~HdlNamespace() override;
};

}
}
