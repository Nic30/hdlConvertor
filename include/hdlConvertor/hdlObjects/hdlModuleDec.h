#pragma once
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/position.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>


namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for module declaration
 * (part with ports and params for Verilog, Entity for VHDL)
 * */
class HdlModuleDec: public WithNameAndDoc, public iHdlObj {
public:
	std::vector<std::unique_ptr<HdlVariableDef>> generics;
	std::vector<std::unique_ptr<HdlVariableDef>> ports;

	HdlModuleDec();
	HdlVariableDef * getPortByName(const std::string & name);
	~HdlModuleDec();
};

}
}
