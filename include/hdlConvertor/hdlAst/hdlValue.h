#pragma once

#include <vector>

#include <hdlConvertor/hdlAst/bigInteger.h>
#include <hdlConvertor/hdlAst/iHdlExprItem.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for value of arrays
 * */
class HdlValueArr: public virtual iHdlExprItem {
public:
	std::unique_ptr<std::vector<std::unique_ptr<iHdlExprItem>>> _arr;

	HdlValueArr(const HdlValueArr &other);
	HdlValueArr(std::vector<std::unique_ptr<iHdlExprItem>> &arr);
	HdlValueArr(
			std::unique_ptr<std::vector<std::unique_ptr<iHdlExprItem>>> arr);
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlValueArr() override;
};

/*
 * HDL AST node for HDL id
 * */
class HdlValueId: public virtual iHdlExprItem {
public:
	std::string _str;

	//HdlValueId(const HdlValueId & rhs) = default;
	HdlValueId(std::string __str);
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlValueId() override;
};

/*
 * HDL AST node for integer/bitstring value
 * */
class HdlValueInt: public virtual iHdlExprItem {
public:
	int bits;
	BigInteger _int;
	//HdlValueInt(const HdlValueInt & rhs) = default;
	HdlValueInt(BigInteger __int);
	HdlValueInt(const BigInteger &value, int bits);
	HdlValueInt(const std::string &value, int radix);
	HdlValueInt(const std::string &value, int bits, int radix);

	virtual iHdlExprItem* clone() const override;
	virtual ~HdlValueInt() override;
};

/*
 * HDL AST node for float/real value
 * */
class HdlValueFloat: public virtual iHdlExprItem {
public:
	double _float;

	//HdlValueFloat(const HdlValueFloat & rhs) = default;
	HdlValueFloat(double __float);
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlValueFloat() override;
};

/*
 * HDL AST node for string value
 * */
class HdlValueStr: public virtual iHdlExprItem {
public:
	std::string _str;

	//HdlValueStr(const HdlValueStr & rhs) = default;
	HdlValueStr(const std::string &__str);
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlValueStr() override;
};

enum HdlValueSymbol_t {
	symb_NULL, symb_OPEN, // the unconnected
	symb_ALL, // all items in destination
	symb_OTHERS, // not explicitly specified items in destination
	symb_T, // type of type
	symb_T_AUTO, // automatically derived type (implicit data type from Verilog)
	symb_T_SUBTYPE, // used in subtype declaration as data type of symbol
};
/*
 * HDL AST node for special hdl symbols
 * */
class HdlValueSymbol: public virtual iHdlExprItem {
public:
	HdlValueSymbol_t symb;

	//HdlValueSymbol(const HdlValueSymbol & rhs) = default;
	HdlValueSymbol(HdlValueSymbol_t symb);

	const char* toString();
	static const char* toString(HdlValueSymbol_t symb);

	// syntax sugar, named constructors
	static std::unique_ptr<HdlValueSymbol> null();
	static std::unique_ptr<HdlValueSymbol> open();
	static std::unique_ptr<HdlValueSymbol> all();
	static std::unique_ptr<HdlValueSymbol> others();
	static std::unique_ptr<HdlValueSymbol> type();
	static std::unique_ptr<HdlValueSymbol> type_auto();
	static std::unique_ptr<HdlValueSymbol> type_subtype();

	virtual iHdlExprItem* clone() const override;
	virtual ~HdlValueSymbol() override;
};

/*
 * HDL AST node which purpose is used if conversion of original expression is not implemented
 * */
class HdlExprNotImplemented: public virtual iHdlExprItem {
public:
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlExprNotImplemented() override;
};

template<typename T>
void clone_unique_ptr_vector(const std::vector<std::unique_ptr<T>> &from,
		std::vector<std::unique_ptr<T>> &to) {
	to.reserve(from.size());

	for (const auto &e : from)
		to.push_back(e->clone_uniq());
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
