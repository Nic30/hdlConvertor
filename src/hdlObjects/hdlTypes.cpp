#include <hdlConvertor/hdlObjects/hdlTypes.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace hdlObjects {


// constraints
HdlConstraint::~HdlConstraint() {}
//HdlNoConstraint::~HdlNoConstraint() {}
HdlRangeConstraint::HdlRangeConstraint() {}
HdlRangeConstraint::~HdlRangeConstraint() {}
HdlRecordConstraint::~HdlRecordConstraint() {}
HdlArrayConstraint::~HdlArrayConstraint() {}

// type declaration base class
HdlTypeDec::HdlTypeDec(const std::string& name) :
		WithNameAndDoc(name), iHdlObj() {
}
    
HdlTypeDec::~HdlTypeDec() {
}

// subtype
HdlSubtype::HdlSubtype() {
}
HdlSubtype::HdlSubtype(const HdlSubtype& other) : iHdlObj(other)
{
	if (other.parent_type)
		parent_type = std::make_unique<iHdlExpr>(*other.parent_type);
	if (other.constraint)
		constraint = std::make_unique<HdlConstraint>(*other.constraint);
}
HdlSubtype::~HdlSubtype() {}

HdlSubtypeDec::HdlSubtypeDec(const std::string& name, std::unique_ptr<HdlSubtype> sti)
	: HdlTypeDec(name), subtype(std::move(subtype))
{
}

HdlSubtypeDec::~HdlSubtypeDec() {}

// ranges
HdlSimpleRange::HdlSimpleRange(
		std::unique_ptr<iHdlExpr> left, HdlRangeDirection dir, 
		std::unique_ptr<iHdlExpr> right)
	: left(std::move(left)), dir(dir), right(std::move(right))
{
}
HdlSimpleRange::HdlSimpleRange(const HdlSimpleRange& rng)
	: left(std::make_unique<iHdlExpr>(*rng.left)), 
		dir(rng.dir), 
		right(std::make_unique<iHdlExpr>(*rng.right)) {
}
HdlSimpleRange::~HdlSimpleRange() {}
iHdlExprItem* HdlRange::clone() const {
	HdlRange *obj = new HdlRange();
	if (subtype) 
		obj->subtype = std::make_unique<HdlSubtype>(*subtype);
	if (range)
		obj->range = std::make_unique<HdlSimpleRange>(*range);
	if (attribute)
		obj->attribute = std::make_unique<iHdlExpr>(*attribute);
	return obj;
}
HdlRange::~HdlRange() {}

// enumerated type
HdlEnumTypeDec::HdlEnumTypeDec(const std::string& name)
	: HdlTypeDec(name)
{
}
HdlEnumTypeDec::~HdlEnumTypeDec() {
}

// array type
HdlArrayTypeDec::HdlArrayTypeDec(const std::string& name)
	: HdlTypeDec(name)
{
}
HdlArrayTypeDec::~HdlArrayTypeDec() {
}

// struct or record type
HdlStructTypeDec::HdlStructTypeDec(const std::string& name)
	: HdlTypeDec(name), isUnion(false) 
{
}

HdlStructTypeDec::~HdlStructTypeDec() {
}


}
}
