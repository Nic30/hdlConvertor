#pragma once
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/hdlVariableDef.h>
#include <hdlConvertor/hdlAst/codePosition.h>


namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for module declaration
 * (part with ports and params for Verilog, Entity for VHDL)
 * */
class HdlModuleDec: public WithNameAndDoc, public iHdlObj {
public:
	std::vector<std::unique_ptr<HdlIdDef>> generics;
	std::vector<std::unique_ptr<HdlIdDef>> ports;

	HdlModuleDec();
	HdlIdDef * getPortByName(const std::string & name);
	~HdlModuleDec();
};

}
}
