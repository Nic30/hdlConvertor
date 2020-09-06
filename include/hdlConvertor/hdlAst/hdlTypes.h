#pragma once
#include <vector>
#include <utility>
#include <memory>

#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/hdlOpType.h>
#include <hdlConvertor/hdlAst/hdlOp.h>
#include <hdlConvertor/hdlAst/iHdlExprItem.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * Base class for HDL AST node for type definition
 * */
class iHdlTypeDec: public virtual WithDoc, public virtual iHdlExprItem {
public:
	// enum HdlType_t {
	// 	  hdltc_error,
	// 	  hdltc_incomplete,
	// 	  hdltc_physical,
	// 	  hdltc_integral,
	// 	  hdltc_access,
	// 	  hdltc_file,
	// 	  hdltc_protected
	// };
};

enum HdlClassType {
	CLASS, STRUCT, // also vhdl record type
	UNION,
	INTERFACE,
};

const char* HdlClassType_toString(HdlClassType ct);

class HdlClassDef: public virtual iHdlTypeDec {
public:
	// vector of HdlValueId or parametrizations which represents a parent classes for inheritance
	std::vector<std::unique_ptr<iHdlExprItem>> base_types;
	HdlClassType type;
	std::vector<std::unique_ptr<iHdlObj>> members;
	bool is_packed;
	bool is_virtual;

	HdlClassDef();
	HdlClassDef(const HdlClassDef &other);
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlClassDef() override {
	}
};

class HdlPhysicalDef: public virtual iHdlTypeDec {
public:
	std::unique_ptr<iHdlExprItem> range;
	std::vector<std::pair<std::string, std::unique_ptr<iHdlExprItem>>> members;
	HdlPhysicalDef();
	HdlPhysicalDef(const HdlPhysicalDef &other);
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlPhysicalDef() override {
	}
};

class HdlEnumDef: public virtual iHdlTypeDec {
public:
	std::unique_ptr<iHdlExprItem> base_type;

	// pairs<name, value>, value is optional and name==nullptr for
	// VHDL enums with character literals (type t is ('0', '1');)
	std::vector<
			std::pair<std::unique_ptr<std::string>,
					std::unique_ptr<iHdlExprItem>>> values;

	HdlEnumDef();
	HdlEnumDef(const HdlEnumDef &other);
	virtual iHdlExprItem* clone() const override;
	virtual ~HdlEnumDef() override {
	}
};

}
}
