#pragma once

#include <hdlConvertor/hdlObjects/bigInteger.h>
#include <hdlConvertor/hdlObjects/iHdlExprItem.h>
#include <string.h>
#include <assert.h>
#include <vector>

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
	const std::vector<iHdlExpr*> *_arr;

	HdlValue();
	HdlValue(HdlValueType type);
	HdlValue(const HdlValue &other);
	HdlValue(BigInteger __int);
	HdlValue(const BigInteger &value, int bits);
	HdlValue(double __float);
	HdlValue(std::string __str);
	HdlValue(const std::vector<iHdlExpr*> *arr);

	iHdlExprItem* clone() const;

	virtual ~HdlValue();
};

const char* HdlValueType_toString(HdlValueType t);

}
}
