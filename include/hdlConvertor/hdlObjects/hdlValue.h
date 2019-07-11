#pragma once

#include <hdlConvertor/hdlObjects/bigInteger.h>
#include <hdlConvertor/hdlObjects/iHdlExprItem.h>
#include <string.h>
#include <assert.h>
#include <vector>

namespace hdlConvertor {
namespace hdlObjects {


enum LiteralValType {
	symb_ID, symb_INT, symb_FLOAT, symb_STRING, symb_OPEN,
	symb_ARRAY, symb_ALL, symb_NULL, symb_OTHERS, symb_T
};


class iHdlExpr;

/*
 * Container of HDL value of any type
 * */
class HdlValue: public virtual iHdlExprItem {
public:
	LiteralValType type;
	int bits;
	BigInteger _int;
	double _float;
	std::string _str;
	const std::vector<iHdlExpr*> * _arr;


	HdlValue();
	HdlValue(LiteralValType type);
	HdlValue(const HdlValue & other);
	HdlValue(BigInteger __int);
	HdlValue(const BigInteger & value, int bits);
	HdlValue(double __float);
	HdlValue(std::string __str);
	HdlValue(const std::vector<iHdlExpr*> * arr);


	iHdlExprItem * clone() const;

	virtual ~HdlValue();
};


const char * HdlValueType_toString(LiteralValType t);

}
}
