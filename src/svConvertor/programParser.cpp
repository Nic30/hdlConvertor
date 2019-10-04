#include <hdlConvertor/svConvertor/programParser.h>

#include <hdlConvertor/notImplementedLogger.h>

#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/statementParser.h>
#include <hdlConvertor/svConvertor/portParser.h>
#include <hdlConvertor/svConvertor/declrParser.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;

VerProgramParser::VerProgramParser(SVCommentParser &_commentParser) :
		commentParser(_commentParser) {
}

HdlFunctionDef* VerProgramParser::visitTask_and_function_declaration_common(
		sv2017Parser::Task_and_function_declaration_commonContext *ctx,
		iHdlExpr *return_t, bool is_static, bool is_task) {
	// task_and_function_declaration_common:
	//     ( identifier DOT | class_scope )? identifier
	//     ( SEMI ( tf_item_declaration )*
	//       | LPAREN tf_port_list RPAREN SEMI ( block_item_declaration )*
	//     )
	//     ( statement_or_null )*
	// ;
	auto ids = ctx->identifier();
	string name;
	if (ids.size() == 2) {
		NotImplementedLogger::print(
				"VerProgramParser.visitTask_and_function_declaration_common hierarchical name",
				ids[0]);
		name = VerExprParser::getIdentifierStr(ids[1]);
	} else {
		auto cs = ctx->class_scope();
		if (cs)
			NotImplementedLogger::print(
					"VerProgramParser.visitTask_and_function_declaration_common class scoped name",
					cs);
		name = VerExprParser::getIdentifierStr(ids[0]);
	}
	auto params = new std::vector<HdlVariableDef*>();
	auto f = new HdlFunctionDef(name, false, return_t, params);
	f->is_static = is_static;
	f->is_task = is_task;
	f->is_declaration_only = false;
	std::vector<VerPortParser::Non_ANSI_port_info_t> non_ansi_port_groups;
	if (ctx->tf_item_declaration().size()) {
		NotImplementedLogger::print(
				"VerProgramParser.visitTask_and_function_declaration_common class tf_item_declaration",
				ctx->tf_item_declaration()[0]);
	} else {
		auto pl = ctx->tf_port_list();
		if (pl) {
			VerPortParser pp(commentParser, non_ansi_port_groups);
			pp.visitTf_port_list(pl, *params);
		}
	}
	VerStatementParser sp(commentParser);
	for (auto _bid : ctx->block_item_declaration()) {
		sp.visitBlock_item_declaration(_bid, f->body);
	}
	for (auto _stm : ctx->statement_or_null()) {
		auto stm = sp.visitStatement_or_null(_stm);
		f->body.push_back(stm);
	}
	if (non_ansi_port_groups.size()) {
		NotImplementedLogger::print(
				"VerProgramParser.visitTask_and_function_declaration_common non-ansi ports",
				ctx);
	}
	return f;
}

HdlFunctionDef* VerProgramParser::visitTask_declaration(
		sv2017Parser::Task_declarationContext *ctx) {
	// task_declaration:
	//     KW_TASK ( lifetime )?
	// 	   task_and_function_declaration_common
	//     KW_ENDTASK ( COLON identifier | {_input->LA(1) != COLON}? )
	// ;

	VerTypeParser tp(commentParser);
	bool is_static = tp.visitLifetime(ctx->lifetime());
	auto return_t = iHdlExpr::ID("void");
	auto tfcom = ctx->task_and_function_declaration_common();
	return visitTask_and_function_declaration_common(tfcom, return_t, is_static,
			true);
}

HdlFunctionDef* VerProgramParser::visitFunction_declaration(
		sv2017Parser::Function_declarationContext *ctx) {
	//function_declaration:
	//    KW_FUNCTION ( lifetime )?
	//    ( function_data_type_or_implicit )?
	//    task_and_function_declaration_common
	//    KW_ENDFUNCTION ( COLON identifier | {_input->LA(1) != COLON}? )
	//;
	VerTypeParser tp(commentParser);
	bool is_static = tp.visitLifetime(ctx->lifetime());
	auto fdti = ctx->function_data_type_or_implicit();
	auto return_t = tp.visitFunction_data_type_or_implicit(fdti);
	auto tfcom = ctx->task_and_function_declaration_common();
	return visitTask_and_function_declaration_common(tfcom, return_t, is_static,
			false);
}

}
}
