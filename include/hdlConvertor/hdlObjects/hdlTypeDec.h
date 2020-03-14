#pragma once
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>


namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for module declaration
 * (part with ports and params for Verilog, Entity for VHDL)
 * */
class HdlTypeDec: public WithNameAndDoc, public iHdlObj {
public:
	enum TypeClass {hdltc_error, hdltc_enum, hdltc_array, hdltc_struct, 
		hdltc_physical, hdltc_integral, hdltc_float};
	HdlTypeDec(const std::string& name);
	virtual TypeClass typeClass() = 0;
	virtual ~HdlTypeDec();
};

class HdlEnumTypeDec: public HdlTypeDec {
public:
	std::vector<std::string> ids;
	//std::vector<std::unique_ptr<iHdlExpr>> path;
	//
	//rhinton: may need iHdlExpr to handle VHDL character literal vs. identifier
	//
	//rhinton: does SystemVerilog associate values to enums like C does?  If so, we'll need to store (optional?) values here as well

	//HdlEnumTypeDec();
	TypeClass typeClass() override;
	virtual ~HdlEnumTypeDec();
};

class HdlArrayTypeDec: public HdlTypeDec {
public:
	std::vector<std::unique_ptr<iHdlExpr>> indexes;
	std::unique_ptr<iHdlExpr> element;

	//HdlArrayTypeDec();
	TypeClass typeClass() override;
	virtual ~HdlArrayTypeDec();
};

class HdlStructTypeDec: public HdlTypeDec {
public:
	std::vector<std::unique_ptr<HdlVariableDef>> fields;

	//HdlStructTypeDec();
	TypeClass typeClass() override;
	virtual ~HdlStructTypeDec();
};



}
}
