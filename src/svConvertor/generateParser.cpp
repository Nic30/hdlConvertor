#include <hdlConvertor/svConvertor/generateParser.h>
#include <hdlConvertor/svConvertor/statementParser.h>
#include <hdlConvertor/svConvertor/declrParser.h>
#include <hdlConvertor/svConvertor/programParser.h>
#include <hdlConvertor/svConvertor/moduleParser.h>
#include <hdlConvertor/svConvertor/moduleInstanceParser.h>
#include <hdlConvertor/svConvertor/paramDefParser.h>
#include <hdlConvertor/svConvertor/attributeParser.h>
#include <hdlConvertor/svConvertor/literalParser.h>
#include <hdlConvertor/notImplementedLogger.h>
#include <hdlConvertor/hdlAst/hdlStm_others.h>
#include <hdlConvertor/hdlAst/hdlStmIf.h>
#include <hdlConvertor/hdlAst/hdlStmBlock.h>
#include <hdlConvertor/hdlAst/hdlValue.h>
#include <hdlConvertor/hdlAst/hdlDirection.h>
#include <hdlConvertor/createObject.h>

#include <assert.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlAst;

VerGenerateParser::VerGenerateParser(SVCommentParser &_commentParser,
		bool _hierarchyOnly) :
		commentParser(_commentParser), hierarchyOnly(_hierarchyOnly) {
}

void VerGenerateParser::visitGenerate_region(
		sv2017Parser::Generate_regionContext *ctx,
		vector<unique_ptr<iHdlObj>> &res) {
	// generate_region: KW_GENERATE ( generate_item )* KW_ENDGENERATE;
	vector<unique_ptr<iHdlObj>> tmp_res;
	for (auto gi : ctx->generate_item()) {
		visitGenerate_item(gi, tmp_res);
		for (auto & o: tmp_res) {
			auto stm = dynamic_cast<iHdlStatement*>(o.get());
			if (stm)
				stm->in_preproc = true;
			res.push_back(move(o));
		}
		tmp_res.clear();
	}
}

void VerGenerateParser::visitModule_or_generate_item(
		sv2017Parser::Module_or_generate_itemContext *ctx,
		vector<unique_ptr<iHdlObj>> &res,
		std::vector<std::unique_ptr<HdlIdDef>> &params) {
	// module_or_generate_item:
	//     parameter_override
	//     | gate_instantiation
	//     | udp_instantiation
	//     | module_or_interface_or_program_or_udp_instantiation
	//     | ( default_clocking_or_dissable_construct
	//         | local_parameter_declaration
	//         | parameter_declaration )? SEMI
	//     | net_declaration
	//     | data_declaration
	//     | task_declaration
	//     | function_declaration
	//     | checker_declaration
	//     | dpi_import_export
	//     | extern_constraint_declaration
	//     | class_declaration
	//     | interface_class_declaration
	//     | class_constructor_declaration
	//     | covergroup_declaration
	//     | property_declaration
	//     | sequence_declaration
	//     | let_declaration
	//     | genvar_declaration
	//     | clocking_declaration
	//     | assertion_item
	//     | bind_directive
	//     | continuous_assign
	//     | net_alias
	//     | initial_construct
	//     | final_construct
	//     | always_construct
	//     | loop_generate_construct
	//     | conditional_generate_construct
	//     | elaboration_system_task
	// ;
	auto &res_stm = reinterpret_cast<vector<unique_ptr<iHdlStatement>>&>(res);
	auto &res_vars = reinterpret_cast<vector<unique_ptr<HdlIdDef>>&>(res);
	{
		auto o = ctx->parameter_override();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.parameter_override",
					o);
			return;
		}
	}
	{
		auto o = ctx->gate_instantiation();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.gate_instantiation",
					o);
			return;
		}
	}
	{
		auto o = ctx->udp_instantiation();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.udp_instantiation",
					o);
			return;
		}
	}
	{
		auto o = ctx->module_or_interface_or_program_or_udp_instantiation();
		if (o) {

			auto &res_comp =
					reinterpret_cast<vector<unique_ptr<HdlCompInst>>&>(res);
			VerModuleInstanceParser mp(commentParser);
			mp.visitModule_or_interface_or_program_or_udp_instantiation(o,
					res_comp);
			return;
		}
	}
	{
		auto o = ctx->default_clocking_or_dissable_construct();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.default_clocking_or_dissable_construct",
					o);
			return;
		}
	}
	{
		auto o = ctx->local_parameter_declaration();
		if (o) {
			VerParamDefParser pdp(commentParser);
			pdp.visitLocal_parameter_declaration(o, res_vars);
			return;
		}
	}
	{
		auto o = ctx->parameter_declaration();
		if (o) {
			VerParamDefParser pdp(commentParser);
			pdp.visitParameter_declaration(o, params);
			return;
		}
	}
	{
		if (ctx->SEMI()) {
			res_stm.push_back(create_object<HdlStmNop>(ctx));
			return;
		}
	}
	{
		auto o = ctx->net_declaration();
		if (o) {
			VerModuleParser(commentParser, hierarchyOnly).visitNet_declaration(
					o, res_vars);
			return;
		}
	}
	{
		auto o = ctx->data_declaration();
		if (o) {
			VerDeclrParser dp(commentParser);
			return dp.visitData_declaration(o, res);
		}
	}
	{
		auto o = ctx->task_declaration();
		if (o) {
			VerProgramParser pp(commentParser);
			auto f = pp.visitTask_declaration(o);
			res.push_back(move(f));
			return;
		}
	}
	{
		auto o = ctx->function_declaration();
		if (o) {
			VerProgramParser pp(commentParser);
			auto f = pp.visitFunction_declaration(o);
			res.push_back(move(f));
			return;
		}
	}
	{
		auto o = ctx->checker_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.checker_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->dpi_import_export();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.dpi_import_export",
					o);
			return;
		}
	}
	{
		auto o = ctx->extern_constraint_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.extern_constraint_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->class_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.class_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->interface_class_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.interface_class_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->class_constructor_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.class_constructor_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->covergroup_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.covergroup_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->property_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.property_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->sequence_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.sequence_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->let_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.let_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->genvar_declaration();
		if (o) {
			visitGenvar_declaration(o, res_vars);
			return;
		}
	}
	{
		auto o = ctx->clocking_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.clocking_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->assertion_item();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.assertion_item",
					o);
			return;
		}
	}
	{
		auto o = ctx->bind_directive();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.bind_directive",
					o);
			return;
		}
	}
	{
		auto o = ctx->continuous_assign();
		if (o) {
			VerStatementParser sp(commentParser);
			sp.visitContinuous_assign(o, res_stm);
			return;
		}
	}
	{
		auto o = ctx->net_alias();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.net_alias",
					o);
			return;
		}
	}
	{
		auto o = ctx->initial_construct();
		if (o) {
			VerStatementParser sp(commentParser);
			auto ic = sp.visitInitial_construct(o);
			res.push_back(move(ic));
			return;
		}
	}
	{
		auto o = ctx->final_construct();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitModule_or_generate_item.final_construct",
					o);
			return;
		}
	}
	{
		auto o = ctx->always_construct();
		if (o) {
			VerStatementParser sp(commentParser);
			auto ac = sp.visitAlways_construct(o);
			res.push_back(move(ac));
			return;
		}
	}
	{
		auto o = ctx->loop_generate_construct();
		if (o) {
			auto _stm = visitLoop_generate_construct(o);
			res.push_back(move(_stm));
			return;
		}
	}
	{
		auto o = ctx->conditional_generate_construct();
		if (o) {
			visitConditional_generate_construct(o, res_stm);
			return;
		}
	}
	{
		auto o = ctx->elaboration_system_task();
		if (o) {
			VerStatementParser sp(commentParser);
			auto est = sp.visitElaboration_system_task(o);
			res.push_back(move(est));
			return;
		}
	}
}
void VerGenerateParser::visitGenvar_declaration(
		sv2017Parser::Genvar_declarationContext *ctx, vector<unique_ptr<HdlIdDef>> & res) {
	// genvar_declaration:
	//  KW_GENVAR identifier_list SEMI;
	// identifier_list: identifier ( COMMA identifier )*;
	auto il = ctx->identifier_list();
	for (auto id: il->identifier()) {
		VerExprParser ep(commentParser);
		auto name = ep.getIdentifierStr(id);
		auto t = create_object<HdlValueId>(id, "genvar");
		auto v = create_object<HdlIdDef>(id, name, move(t), nullptr);
		res.push_back(move(v));
	}
}
unique_ptr<HdlIdDef> VerGenerateParser::visitGenvar_initialization(
		sv2017Parser::Genvar_initializationContext *ctx) {
	// genvar_initialization:
	//     ( KW_GENVAR )? identifier ASSIGN constant_expression;
	VerExprParser ep(commentParser);
	auto name = ep.getIdentifierStr(ctx->identifier());
	auto _def_val = ctx->constant_expression();
	auto def_val = ep.visitConstant_expression(_def_val);
	auto dt = HdlValueSymbol::type_auto();
	return create_object<HdlIdDef>(ctx, name, move(dt), move(def_val),
			HdlDirection::DIR_INTERNAL, true);
}

unique_ptr<HdlStmExpr> VerGenerateParser::visitGenvar_iteration(
		sv2017Parser::Genvar_iterationContext *ctx) {
	// genvar_iteration:
	//     identifier ( assignment_operator genvar_expression
	//                  | inc_or_dec_operator
	//                  )
	//     | inc_or_dec_operator identifier
	// ;
	auto _id = ctx->identifier();
	VerExprParser ep(commentParser);
	auto id = ep.visitIdentifier(_id);
	auto iod = ctx->inc_or_dec_operator();
	unique_ptr<iHdlExprItem> e;
	if (iod) {
		bool is_prefix = ctx->children[0] == iod;
		auto op = VerLiteralParser::visitInc_or_dec_operator(iod, is_prefix);
		e = create_object<HdlOp>(ctx, op, move(id));
	} else {
		auto ao = ctx->assignment_operator();
		auto op = VerLiteralParser::visitAssignment_operator(ao);
		auto _val = ctx->genvar_expression();
		auto val = visitGenvar_expression(_val);
		e = create_object<HdlOp>(ctx, move(id), op, move(val));
	}
	return create_object<HdlStmExpr>(ctx, move(e));
}

unique_ptr<iHdlExprItem> VerGenerateParser::visitGenvar_expression(
		sv2017Parser::Genvar_expressionContext *ctx) {
	// genvar_expression: constant_expression;
	auto ce = ctx->constant_expression();
	return VerExprParser(commentParser).visitConstant_expression(ce);
}

unique_ptr<HdlStmFor> VerGenerateParser::visitLoop_generate_construct(
		sv2017Parser::Loop_generate_constructContext *ctx) {
	// loop_generate_construct:
	//     KW_FOR LPAREN genvar_initialization SEMI genvar_expression SEMI genvar_iteration RPAREN
	//       generate_item;

	auto _init = ctx->genvar_initialization();
	auto _cond = ctx->genvar_expression();
	auto _step = ctx->genvar_iteration();

	auto init_stm = visitGenvar_initialization(_init);
	auto init = create_object<HdlStmBlock>(_init);
	init->statements.push_back(move(init_stm));
	auto cond = visitGenvar_expression(_cond);
	auto step = visitGenvar_iteration(_step);

	auto gi = ctx->generate_item();
	auto bl = create_object<HdlStmBlock>(gi);
	visitGenerate_item(gi, bl->statements);
	std::unique_ptr<iHdlObj> stm;
	if (bl->statements.size() == 1)
		stm = move(bl->statements[0]);
	else {
		stm = move(bl);
	}

	auto res = create_object<HdlStmFor>(ctx, move(init), move(cond), move(step),
			move(stm));
	return res;
}

void VerGenerateParser::visitGenerate_begin_end_block(
		sv2017Parser::Generate_begin_end_blockContext *ctx,
		vector<unique_ptr<iHdlObj>> &res) {
	// generate_begin_end_block:
	//     ( identifier COLON )? KW_BEGIN ( COLON identifier | {_input->LA(1) != COLON}? )
	//         ( generate_item )*
	//     KW_END ( COLON identifier | {_input->LA(1) != COLON}? )
	// ;
	//     X ( COLON identifier | {_input->LA(1) != COLON}? )
	//         ( block_item_declaration )* ( statement_or_null )*
	//     X (COLON identifier |  {_input->LA(1) != COLON}?);
	std::vector<std::unique_ptr<hdlAst::iHdlObj>> items;
	for (auto gi : ctx->generate_item()) {
		visitGenerate_item(gi, items);
	}
	auto b = create_object<HdlStmBlock>(ctx, items);

	for (auto _label : ctx->identifier()) {
		VerExprParser ep(commentParser);
		b->labels.push_back(ep.getIdentifierStr(_label));
	}
	res.push_back(move(b));
}

void VerGenerateParser::visitConditional_generate_construct(
		sv2017Parser::Conditional_generate_constructContext *ctx,
		vector<unique_ptr<iHdlStatement>> &res) {
	// conditional_generate_construct:
	//     if_generate_construct
	//     | case_generate_construct
	// ;
	auto igc = ctx->if_generate_construct();
	if (igc) {
		visitIf_generate_construct(igc, res);
	} else {
		auto cgc = ctx->case_generate_construct();
		assert(cgc);
		visitCase_generate_construct(cgc, res);
	}
}
void VerGenerateParser::visitCase_generate_construct(
		sv2017Parser::Case_generate_constructContext *ctx,
		vector<unique_ptr<iHdlStatement>> &res) {
	// case_generate_construct:
	//     KW_CASE LPAREN constant_expression RPAREN ( case_generate_item )+ KW_ENDCASE;
	// case_generate_item:
	//     ( KW_DEFAULT ( COLON )?
	//       | constant_expression ( COMMA constant_expression )* COLON
	//     ) generate_item;
	NotImplementedLogger::print(
			"VerGenerateParser.visitCase_generate_construct", ctx);
}


unique_ptr<iHdlObj> pop_block_if_possible(unique_ptr<HdlStmBlock> stm) {
	if (stm->statements.size() == 1) {
		return move(stm->statements[0]);
	} else {
		return stm;
	}
}
void VerGenerateParser::visitIf_generate_construct(
		sv2017Parser::If_generate_constructContext *ctx,
		vector<unique_ptr<iHdlStatement>> &res) {
	// if_generate_construct:
	//     KW_IF LPAREN constant_expression RPAREN generate_item
	//     ( KW_ELSE generate_item | {_input->LA(1) != KW_ELSE}? );
	//
	//conditional_statement:
	//    ( unique_priority )? KW_IF LPAREN cond_predicate RPAREN statement_or_null
	//    ( KW_ELSE statement_or_null | {_input->LA(1) != KW_ELSE}? );
	auto c = ctx->constant_expression();
	auto s = ctx->generate_item();
	VerExprParser ep(commentParser);
	auto cond = ep.visitConstant_expression(c);

	auto ifTrue_bl = create_object<HdlStmBlock>(s[0]);
	visitGenerate_item(s[0], ifTrue_bl->statements);
	auto ifTrue = pop_block_if_possible(move(ifTrue_bl));

	unique_ptr<iHdlObj> ifFalse = nullptr;
	if (s.size() == 2) {
		auto ifFalse_bl = create_object<HdlStmBlock>(s[1]);
		visitGenerate_item(s[1], ifFalse_bl->statements);
		ifFalse = pop_block_if_possible(move(ifFalse_bl));
	}
	auto ifStm = create_object_with_doc<HdlStmIf>(ctx, commentParser, move(cond), move(ifTrue),
			move(ifFalse));
	HdlStmIf_collapse_elifs(*ifStm);

	res.push_back(move(ifStm));
}

void VerGenerateParser::visitGenerate_item(
		sv2017Parser::Generate_itemContext *ctx,
		vector<unique_ptr<iHdlObj>> &res) {
	// generate_item:
	//     ( attribute_instance )*
	//         ( module_or_generate_item
	//           | extern_tf_declaration
	//         )
	//         | KW_RAND data_declaration
	//         | generate_region
	//         | generate_begin_end_block
	// ;
	if (ctx->KW_RAND()) {
		NotImplementedLogger::print(
				"VerGenerateParser.visitGenerate_item.data_declaration",
				ctx->data_declaration());
		return;
	}
	VerAttributeParser::visitAttribute_instance(ctx->attribute_instance());

	{
		auto o = ctx->module_or_generate_item();
		if (o) {
			vector < unique_ptr < HdlIdDef >> params;
			visitModule_or_generate_item(o, res, params);
			if (params.size()) {
				NotImplementedLogger::print(
						"VerGenerateParser.visitGenerate_item.params", ctx);
			}
			return;
		}
	}
	{
		auto o = ctx->extern_tf_declaration();
		if (o) {
			NotImplementedLogger::print(
					"VerGenerateParser.visitGenerate_item.extern_tf_declaration",
					o);
			return;
		}
	}
	{
		auto o = ctx->generate_region();
		if (o) {
			visitGenerate_region(o, res);
			return;
		}
	}
	auto gb = ctx->generate_begin_end_block();
	assert(gb);
	visitGenerate_begin_end_block(gb, res);
}

}
}
