#pragma once

#include <hdlConvertor/hdlObjects/bigInteger.h>
#include <hdlConvertor/hdlObjects/exprItem.h>
#include <string.h>
#include <assert.h>
#include <vector>

namespace hdlConvertor {
namespace hdlObjects {


enum LiteralValType {
	symb_ID, symb_INT, symb_FLOAT, symb_STRING, symb_OPEN,
	symb_ARRAY, symb_ALL, symb_NULL, symb_OTHERS, symb_T
};


class Expr;

/*
 * Container of HDL value of any type
 * */
class LiteralVal: public virtual ExprItem {
public:
	LiteralValType type;
	int bits;
	BigInteger _int;
	double _float;
	std::string _str;
	const std::vector<Expr*> * _arr;


	LiteralVal();
	LiteralVal(LiteralValType type);
	LiteralVal(const LiteralVal & other);
	LiteralVal(BigInteger __int);
	LiteralVal(const BigInteger & value, int bits);
	LiteralVal(double __float);
	LiteralVal(std::string __str);
	LiteralVal(const std::vector<Expr*> * arr);


	ExprItem * clone() const;

	virtual ~LiteralVal();
};


const char * LiteralValType_toString(LiteralValType t);

}
}
