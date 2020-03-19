#pragma once
#include <vector>
#include <utility>
#include <memory>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>


namespace hdlConvertor {
namespace hdlObjects {

class iHdlExpr;
class HdlVariableDef;

/*
 * HDL AST node for module declaration
 * (part with ports and params for Verilog, Entity for VHDL)
 * */
class HdlTypeDec: public WithNameAndDoc, public iHdlObj {
public:
	// enum to indicate which class of type declaration this is, useful
	// when visiting the AST
	enum TypeClass {hdltc_error, hdltc_incomplete, hdltc_enum, hdltc_array, 
		hdltc_struct, hdltc_class, hdltc_physical, hdltc_integral, 
		hdltc_float, hdltc_access, hdltc_file, hdltc_protected};

	HdlTypeDec(const std::string& name);
	virtual TypeClass typeClass() {return hdltc_error;};
	virtual ~HdlTypeDec();
};

class HdlEnumTypeDec: public HdlTypeDec {
public:
	// VHDL character enumerations are stored as strings including the
	// single-quotes, e.g. "'U'"s; SV allows identifiers to have an
	// associated value, while VHDL scalar types do not have this concept
	std::vector<std::pair<std::string, std::unique_ptr<iHdlExpr>>> ids;

	TypeClass typeClass() override {return hdltc_enum;};
	virtual ~HdlEnumTypeDec();
};

class HdlArrayTypeDec: public HdlTypeDec {
public:
	std::vector<std::unique_ptr<iHdlExpr>> indexes;
	std::unique_ptr<iHdlExpr> element;

	TypeClass typeClass() override {return hdltc_array;};
	virtual ~HdlArrayTypeDec();
};

// HdlStructTypeDec class handles VHDL records, SV structs, and SV unions
class HdlStructTypeDec: public HdlTypeDec {
public:
	bool isUnion;
	std::vector<std::unique_ptr<HdlVariableDef>> fields;

	HdlStructTypeDec(const std::string& name) : HdlTypeDec(name), isUnion(false) {};
	TypeClass typeClass() override {return hdltc_struct;};
	virtual ~HdlStructTypeDec();
};

//TODO:: SV classes; VHDL physical types, integral types, floating-point types,
// access types



}
}
