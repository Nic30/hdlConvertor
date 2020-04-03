#pragma once
#include <vector>
#include <utility>
#include <memory>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/hdlOperatorType.h>
#include <hdlConvertor/hdlObjects/iHdlExprItem.h>


namespace hdlConvertor {
namespace hdlObjects {

class iHdlExpr;
class HdlVariableDef;

/* Constraints for ranges, arrays, and structures for use with data types */
class HdlConstraint : public iHdlObj {
public:
	virtual ~HdlConstraint();
};

class HdlNoConstraint : public HdlConstraint {
	virtual ~HdlNoConstraint();
};

class HdlRange;

class HdlRangeConstraint : public HdlConstraint {
public:
	std::unique_ptr<HdlRange> range;
	HdlRangeConstraint();
	virtual ~HdlRangeConstraint();
};

class HdlRecordConstraint : public HdlConstraint {
public:
	//maybe?std::vector<std::unique_ptr<HdlVariableDef>> field_cons;
	std::vector<std::pair<std::string, std::unique_ptr<HdlConstraint>>> field_cons;
	virtual ~HdlRecordConstraint();
};

class HdlArrayConstraint : public HdlConstraint {
public:
	std::vector<std::unique_ptr<HdlRange>> indexes;
	std::unique_ptr<HdlConstraint> element;
	virtual ~HdlArrayConstraint();
};


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

// HdlSubtype represents a "subtype indication" in VHDL
class HdlSubtype : public iHdlObj {
public:
	std::unique_ptr<iHdlExpr> parent_type; // must be a type mark
	std::unique_ptr<HdlConstraint> constraint;
	
	HdlSubtype();
	// @note deepcopy
	HdlSubtype(const HdlSubtype& other);
	virtual ~HdlSubtype();
};

// HdlSubtypeDec represents a subtype declaration in VHDL, which has a name and
// associated subtype indication.
class HdlSubtypeDec : public HdlTypeDec {
public:
	std::unique_ptr<HdlSubtype> subtype;
	HdlSubtypeDec(const std::string& name, std::unique_ptr<HdlSubtype> subtype);
	virtual TypeClass typeClass() {return hdltc_error;};
	virtual ~HdlSubtypeDec();
};

class HdlSimpleRange : public iHdlObj {
public:
	std::unique_ptr<iHdlExpr> left;
	HdlRangeDirection dir;
	std::unique_ptr<iHdlExpr> right;
	HdlSimpleRange(std::unique_ptr<iHdlExpr> left, HdlRangeDirection dir, std::unique_ptr<iHdlExpr> right);
	// @note deepcopy
	HdlSimpleRange(const HdlSimpleRange& rng);
	virtual ~HdlSimpleRange();
};

// HdlRange is a conflation of the different ways of specifying a range.
class HdlRange : public iHdlExprItem {
public:
	std::unique_ptr<HdlSubtype> subtype;
	std::unique_ptr<HdlSimpleRange> range;
	std::unique_ptr<iHdlExpr> attribute;
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlRange();
};

class HdlEnumTypeDec: public HdlTypeDec {
public:
	// VHDL character enumerations are stored as strings including the
	// single-quotes, e.g. "'U'"s; SV allows identifiers to have an
	// associated value, while VHDL scalar types do not have this concept
	std::vector<std::pair<std::string, std::unique_ptr<iHdlExpr>>> ids;
	std::unique_ptr<HdlSubtypeDec> base_type;

	HdlEnumTypeDec(const std::string& name);
	TypeClass typeClass() override {return hdltc_enum;};
	virtual ~HdlEnumTypeDec();
};

class HdlArrayTypeDec: public HdlTypeDec {
public:
	HdlArrayConstraint cons;

	HdlArrayTypeDec(const std::string& name);
	virtual ~HdlArrayTypeDec();
	TypeClass typeClass() override {return hdltc_array;};
};

// HdlStructTypeDec class handles VHDL records, SV structs, and SV unions
class HdlStructTypeDec: public HdlTypeDec {
public:
	bool isUnion;
	std::vector<std::unique_ptr<HdlVariableDef>> fields;

	HdlStructTypeDec(const std::string& name);
	virtual ~HdlStructTypeDec();
	TypeClass typeClass() override {return hdltc_struct;};
};

//TODO:: SV classes; VHDL physical types, integral types, floating-point types,
// access types



}
}
