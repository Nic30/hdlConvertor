#pragma once

#include <hdlConvertor/svConvertor/sv2017Parser/sv2017Parser.h>
#include <hdlConvertor/svConvertor/commentParser.h>
#include <hdlConvertor/hdlObjects/hdlFunctionDef.h>

namespace hdlConvertor {
namespace sv {

class VerProgramParser {
	SVCommentParser &commentParser;
public:
	using sv2017Parser = sv2017_antlr::sv2017Parser;
	VerProgramParser(SVCommentParser &commentParser);

	hdlObjects::HdlFunctionDef* visitTask_and_function_declaration_common(
			sv2017Parser::Task_and_function_declaration_commonContext *ctx,
			hdlObjects::iHdlExpr *return_t, bool is_static, bool is_task);
	hdlObjects::HdlFunctionDef* visitTask_declaration(
			sv2017Parser::Task_declarationContext *ctx);
	hdlObjects::HdlFunctionDef* visitFunction_declaration(
			sv2017Parser::Function_declarationContext *ctx);
};

}

}
