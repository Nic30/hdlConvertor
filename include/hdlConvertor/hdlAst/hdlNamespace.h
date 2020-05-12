#pragma once

#include <vector>
#include <memory>
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlObj.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for namespace (namespace in System Verilog, package/package body in VHDL)
 * */
class HdlValueIdspace: public WithNameAndDoc, public iHdlObj {
public:
	bool defs_only;  // true for VHDL package, false for VHDL package body
	std::vector<std::unique_ptr<iHdlObj>> objs;

	HdlValueIdspace();
	virtual ~HdlValueIdspace() override;
};

}
}
