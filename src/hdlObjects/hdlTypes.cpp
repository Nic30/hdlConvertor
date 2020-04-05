#include <hdlConvertor/hdlObjects/hdlTypes.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace hdlObjects {


// constraints
HdlConstraint::HdlConstraint(const HdlConstraint& other) {
	if (other.range)
		range = std::make_unique<HdlRange>(*other.range);
	if (other.element)
		element = std::make_unique<HdlConstraint>(*other.element);
	field_cons.reserve(other.field_cons.size());
	for ( auto& fc : other.field_cons ) {
		field_cons.push_back(std::make_pair(fc.first, 
				std::make_unique<HdlConstraint>(*fc.second)));
	}
	indexes.reserve(other.indexes.size());
	for ( auto& idx : other.indexes ) {
		indexes.push_back(std::make_unique<HdlRange>(*idx));
	}
}
HdlConstraint::HdlConstraint() {}
HdlConstraint::~HdlConstraint() {}

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
	return new HdlRange(*this);
}
HdlRange::HdlRange() {}
HdlRange::HdlRange(const HdlRange& other) {
	if (other.subtype) 
		subtype = std::make_unique<HdlSubtype>(*other.subtype);
	if (other.range)
		range = std::make_unique<HdlSimpleRange>(*other.range);
	if (other.attribute)
		attribute = std::make_unique<iHdlExpr>(*other.attribute);
}
HdlRange::~HdlRange() {}

// type declaration base class
HdlTypeDec::HdlTypeDec(const std::string& name) 
	: WithNameAndDoc(name), iHdlObj(), type(hdltc_error), isUnion(false) 
{
}
// subtype declaration
HdlTypeDec::HdlTypeDec(const std::string& name, const std::unique_ptr<HdlSubtype>& sti) 
	: WithNameAndDoc(name), iHdlObj(), type(hdltc_error), 
	subtype(std::make_unique<HdlSubtype>(*sti)), isUnion(false) 
{
}
HdlTypeDec::~HdlTypeDec() {
}



}
}
