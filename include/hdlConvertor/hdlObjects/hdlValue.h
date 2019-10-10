#pragma once

#include <memory>
#include <vector>

#include <hdlConvertor/hdlObjects/bigInteger.h>
#include <hdlConvertor/hdlObjects/iHdlExprItem.h>

namespace hdlConvertor {
namespace hdlObjects {

enum HdlValueType {
	symb_ID,
	symb_INT,
	symb_FLOAT,
	symb_STRING,
	symb_ARRAY,
	symb_NULL,
	symb_OPEN, // the unconnected
	symb_ALL, // all items in destination
	symb_OTHERS, // not explicitly specified items in destination
	symb_T, // type of type
	symb_AUTO // automatically derived type
};

class iHdlExpr;

/*
 * HDL AST node for value of any type
 * */
class HdlValue: public virtual iHdlExprItem {
public:
	HdlValueType type;
	int bits;
	BigInteger _int;
	double _float;
	std::string _str;
	std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> _arr;

	HdlValue();
	HdlValue(HdlValueType type);
	HdlValue(const HdlValue &other);
	HdlValue(BigInteger __int);
	HdlValue(const BigInteger &value, int bits);
	HdlValue(double __float);
	HdlValue(std::string __str);
	HdlValue(const std::unique_ptr<std::vector<std::unique_ptr<iHdlExpr>>> arr);

	virtual iHdlExprItem* clone() const override;

	virtual ~HdlValue() override;
};

const char* HdlValueType_toString(HdlValueType t);

template<typename T>
void clone_unique_ptr_vector(const std::vector<std::unique_ptr<T>> &from,
		std::vector<std::unique_ptr<T>> &to) {
	to.reserve(from.size());

	for (const auto &e : from)
		to.push_back(std::make_unique<T>(*e));
}

template<typename T>
std::vector<std::unique_ptr<T>> clone_unique_ptr_vector(
		const std::vector<std::unique_ptr<T>> &from) {
	std::vector<std::unique_ptr<T>> to;
	clone_unique_ptr_vector(from, to);
	return to;
}

}
}
