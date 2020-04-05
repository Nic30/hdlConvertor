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

class HdlRange;

/* Constraints for ranges, arrays, and structures for use with data types */
class HdlConstraint : public iHdlObj {
public:
	// scalar range constraint
	std::unique_ptr<HdlRange> range;
	// scalar range constraint
	std::vector<std::pair<std::string, std::unique_ptr<HdlConstraint>>> field_cons; 
	// array constraint
	std::vector<std::unique_ptr<HdlRange>> indexes;
	std::unique_ptr<HdlConstraint> element;

	HdlConstraint();
	// @note deepcopy
	HdlConstraint(const HdlConstraint& other);
	virtual ~HdlConstraint();
};

/* HdlSubtype represents a "subtype indication" in VHDL, generally it's "the
   type of a thingy". */
class HdlSubtype : public iHdlObj {
public:
	std::unique_ptr<iHdlExpr> parent_type; // must be a type mark
	std::unique_ptr<HdlConstraint> constraint;
	
	HdlSubtype();
	// @note deepcopy
	HdlSubtype(const HdlSubtype& other);
	virtual ~HdlSubtype();
};

class HdlSimpleRange : public iHdlObj {
public:
	std::unique_ptr<iHdlExpr> left;
	HdlRangeDirection dir;
	std::unique_ptr<iHdlExpr> right;

	HdlSimpleRange(std::unique_ptr<iHdlExpr> left, HdlRangeDirection dir, 
		std::unique_ptr<iHdlExpr> right);
	HdlSimpleRange(const HdlSimpleRange& rng);
	~HdlSimpleRange();
};

/* HdlRange is a conflation of the different ways of specifying a range. */
class HdlRange : public iHdlExprItem {
public:
	std::unique_ptr<HdlSimpleRange> range;
	std::unique_ptr<HdlSubtype> subtype;
	std::unique_ptr<iHdlExpr> attribute;

	virtual iHdlExprItem* clone() const override;
	HdlRange();
	// @note deepcopy
	HdlRange(const HdlRange& other);
	virtual ~HdlRange();
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

	TypeClass type;  // which kind of type-ish declaration

	// declared subtype
	std::unique_ptr<HdlSubtype> subtype;

	// Enumerated "scalar" type declaration: VHDL character enumerations
	// are stored as strings including the single-quotes, e.g. "'U'"s; SV
	// allows identifiers to have an associated value, while VHDL scalar
	// types do not have this concept
	std::vector<std::pair<std::string, std::unique_ptr<iHdlExpr>>> ids;
	std::unique_ptr<HdlSubtype> base_type;

	// Array type declaration: uses the same information as an array
	// constraint
	std::unique_ptr<HdlConstraint> array_cons;

	// Structure, union, record type declaration
	bool isUnion;
	std::vector<std::pair<std::string, std::unique_ptr<HdlSubtype>>> fields;
	
	HdlTypeDec(const std::string& name);
	HdlTypeDec(const std::string& name, const std::unique_ptr<HdlSubtype>& sti);  // subtype declaration
	virtual TypeClass typeClass() {return hdltc_error;};
	virtual ~HdlTypeDec();
};

//TODO:: SV classes; VHDL physical types, integral types, floating-point types,
// access types



}
}
