#include <hdlConvertor/svConvertor/programParser.h>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>

#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/portParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>
#include <hdlConvertor/svConvertor/statementParser.h>
#include <hdlConvertor/svConvertor/portParser.h>
#include <hdlConvertor/svConvertor/declrParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/createObject.h>


namespace hdlConvertor {
namespace sv {

using namespace std;
using namespace hdlConvertor::hdlAst;


void VerProgramParser::visitTf_item_declaration(
		sv2017Parser::Tf_item_declarationContext *ctx,
		vector<unique_ptr<iHdlObj>> &objs,
		vector<unique_ptr<HdlIdDef>> &ports) {
	// tf_item_declaration:
	//     block_item_declaration
	//     | tf_port_declaration
	// ;
	auto bid = ctx->block_item_declaration();
	if (bid) {
		// the item may specify the type for port, we need to check it
		// and merge it with te port definitions
		auto prev_objs_size = objs.size();
		VerStatementParser(this).visitBlock_item_declaration(bid, objs);
		for (auto it = objs.begin() + prev_objs_size; it != objs.end(); ) {
			auto o = it->get();
			auto o_id = dynamic_cast<HdlIdDef*>(o);
			bool merged = false;
			if (o_id) {
				for (auto & port: ports) {
					if (port->name == o_id->name) {
						port->type = move(o_id->type);
						port->value = move(o_id->value);
						objs.erase(it);
						merged = true;
						break;
					}
				}
			}
			if (!merged) {
				++it;
			}
		}
	} else {
		auto tpd = ctx->tf_port_declaration();
		visitTf_port_declaration(tpd, ports);
	}
}

void VerProgramParser::visitTf_port_declaration(
		sv2017Parser::Tf_port_declarationContext *ctx,
		vector<unique_ptr<HdlIdDef>> &res) {
	// tf_port_declaration:
	//     ( attribute_instance )* tf_port_direction ( KW_VAR )? ( data_type_or_implicit )?
	//     list_of_tf_variable_identifiers SEMI
	// ;
	VerAttributeParser::visitAttribute_instance(ctx->attribute_instance());
	auto _tpd = ctx->tf_port_direction();
	std::vector<VerPortParser::Non_ANSI_port_info_t> non_ansi_port_groups;
	VerPortParser pp(this, non_ansi_port_groups);
	auto pd = pp.visitTf_port_direction(_tpd);
	if (ctx->KW_VAR())
		pd = HdlDirection::DIR_LINKAGE;
	VerTypeParser tp(this);
	auto dti = ctx->data_type_or_implicit();
	auto t = tp.visitData_type_or_implicit(dti, nullptr);
	auto lvi = ctx->list_of_tf_variable_identifiers();
	auto doc = commentParser.parse(ctx);
	pp.visitList_of_tf_variable_identifiers(lvi, move(t), false, pd, doc, res);
	assert(non_ansi_port_groups.size() == 0);
}

std::unique_ptr<HdlFunctionDef> VerProgramParser::visitTask_and_function_declaration_common(
		sv2017Parser::Task_and_function_declaration_commonContext *ctx,
		std::unique_ptr<iHdlExprItem> return_t, bool is_static, bool is_task) {
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
	auto params = make_unique<std::vector<unique_ptr<HdlIdDef>>>();
	auto f = create_object<HdlFunctionDef>(ctx, name, false, move(return_t),
			move(params));
	f->is_static = is_static;
	f->is_task = is_task;
	f->is_declaration_only = false;
	std::vector<VerPortParser::Non_ANSI_port_info_t> non_ansi_port_groups;
	auto pl = ctx->tf_port_list();
	if (pl) {
		VerPortParser pp(this, non_ansi_port_groups);
		pp.visitTf_port_list(pl, *f->params);
	} else {
		for (auto tfp : ctx->tf_item_declaration()) {
			visitTf_item_declaration(tfp, f->body, *f->params);
		}
	}
	VerStatementParser sp(this);
	for (auto _bid : ctx->block_item_declaration()) {
		sp.visitBlock_item_declaration(_bid, f->body);
	}
	for (auto _stm : ctx->statement_or_null()) {
		auto stm = sp.visitStatement_or_null(_stm);
		f->body.push_back(move(stm));
	}
	if (non_ansi_port_groups.size()) {
		NotImplementedLogger::print(
				"VerProgramParser.visitTask_and_function_declaration_common non-ansi ports",
				ctx);
	}
	return f;
}

std::unique_ptr<HdlFunctionDef> VerProgramParser::visitTask_declaration(
		sv2017Parser::Task_declarationContext *ctx) {
	// task_declaration:
	//     KW_TASK ( lifetime )?
	// 	   task_and_function_declaration_common
	//     KW_ENDTASK ( COLON identifier | {_input->LA(1) != COLON}? )
	// ;

	VerTypeParser tp(this);
	bool is_static = tp.visitLifetime(ctx->lifetime());
	auto return_t = create_object<HdlValueId>(ctx, "void");
	auto tfcom = ctx->task_and_function_declaration_common();
	return visitTask_and_function_declaration_common(tfcom, move(return_t),
			is_static, true);
}

std::unique_ptr<HdlFunctionDef> VerProgramParser::visitFunction_declaration(
		sv2017Parser::Function_declarationContext *ctx) {
	//function_declaration:
	//    KW_FUNCTION ( lifetime )?
	//    ( function_data_type_or_implicit )?
	//    task_and_function_declaration_common
	//    KW_ENDFUNCTION ( COLON identifier | {_input->LA(1) != COLON}? )
	//;
	VerTypeParser tp(this);
	bool is_static = tp.visitLifetime(ctx->lifetime());
	auto fdti = ctx->function_data_type_or_implicit();
	auto return_t = tp.visitFunction_data_type_or_implicit(fdti);
	auto tfcom = ctx->task_and_function_declaration_common();
	return visitTask_and_function_declaration_common(tfcom, std::move(return_t),
			is_static, false);
}

}
}
