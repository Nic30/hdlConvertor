#pragma once
#include <vector>
#include <hdlConvertor/hdlAst/named.h>
#include <hdlConvertor/hdlAst/iHdlExpr.h>
#include <hdlConvertor/hdlAst/iHdlStatement.h>
#include <hdlConvertor/hdlAst/iHdlObj.h>
#include <hdlConvertor/hdlAst/hdlIdDef.h>

namespace hdlConvertor {
namespace hdlAst {

/*
 * HDL AST node for definition or declaration of HDL function/task etc.
 * */
class HdlFunctionDef: public HdlIdDef {
public:
	std::unique_ptr<iHdlExprItem> returnT;
	std::unique_ptr<std::vector<std::unique_ptr<HdlIdDef>> > params;
	std::vector<std::unique_ptr<iHdlObj>> body;
	const bool is_operator;
	bool is_static;
	bool is_virtual;
	bool is_task;
	bool is_declaration_only;

	HdlFunctionDef(const std::string &name, bool is_operator,
			std::unique_ptr<iHdlExprItem> returnT,
			std::unique_ptr<std::vector<std::unique_ptr<HdlIdDef>>> params);
	virtual ~HdlFunctionDef() override;
};

}
}
