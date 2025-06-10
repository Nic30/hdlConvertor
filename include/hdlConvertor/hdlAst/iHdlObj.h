#pragma once

#include <vector>
#include <memory>
#include <string>

namespace hdlConvertor {
namespace hdlAst {

class iHdlExprItem;
/*
 * Interface for object which can appear in HDL AST
 * */
class iHdlObj {
public:
	class HdlAttribute {
	public:
		std::string id;
		std::unique_ptr<iHdlExprItem> value;
		HdlAttribute(const std::string &id,
				std::unique_ptr<iHdlExprItem> &&value);
	};
	std::vector<HdlAttribute> *hdlAttributes;

	// https://stackoverflow.com/questions/64758775/result-type-must-be-constructible-from-value-type-of-input-range-when-trying-t
	iHdlObj();
	iHdlObj(iHdlObj &&rhs) = default;
	iHdlObj(const iHdlObj &other);

	virtual ~iHdlObj();
};

}
}
