#pragma once
#include <vector>
#include <hdlConvertor/hdlObjects/named.h>
#include <hdlConvertor/hdlObjects/iHdlExpr.h>
#include <hdlConvertor/hdlObjects/iHdlStatement.h>
#include <hdlConvertor/hdlObjects/iHdlObj.h>
#include <hdlConvertor/hdlObjects/hdlVariableDef.h>

namespace hdlConvertor {
namespace hdlObjects {

/*
 * HDL AST node for definition or declaration of HDL function/task etc.
 * */
class HdlFunctionDef: public WithNameAndDoc, public iHdlObj {
public:
	std::unique_ptr<iHdlExpr> returnT;
	std::unique_ptr<std::vector<std::unique_ptr<HdlVariableDef>> > params;
	std::vector<std::unique_ptr<iHdlObj>> body;
	const bool is_operator;
	bool is_static;
	bool is_virtual;
	bool is_task;
	bool is_declaration_only;

	HdlFunctionDef(const std::string &name, bool is_operator,
			std::unique_ptr<iHdlExpr> returnT,
			std::unique_ptr<std::vector<std::unique_ptr<HdlVariableDef>>> params);
	virtual ~HdlFunctionDef() override;
};

}
}
