#include <hdlConvertor/svConvertor/paramDefParser.h>

#include <hdlConvertor/svConvertor/utils.h>

#include <hdlConvertor/notImplementedLogger.h>

#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>

namespace hdlConvertor {
namespace sv {

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;

VerParamDefParser::VerParamDefParser(SVCommentParser &commentParser) :
		commentParser(commentParser) {
}

void VerParamDefParser::visitParameter_port_list(
		sv2017Parser::Parameter_port_listContext *ctx,
		vector<HdlVariableDef*> & res) {
	// parameter_port_list:
	//     HASH LPAREN (
	//        ( list_of_param_assignments
	//          | parameter_port_declaration
	//         ) ( COMMA parameter_port_declaration )* )? RPAREN;

	auto lpa = ctx->list_of_param_assignments();
	if (lpa) {
		visitList_of_param_assignments(lpa, res);
		return;
	}
	for (auto pd : ctx->parameter_port_declaration()) {
		visitParameter_port_declaration(pd, res);
	}
}

void VerParamDefParser::visitParameter_port_declaration(
		sv2017Parser::Parameter_port_declarationContext *ctx,
		vector<HdlVariableDef*> & res) {
	// parameter_port_declaration:
	//     KW_TYPE list_of_type_assignments
	//     | parameter_declaration
	//     | local_parameter_declaration
	//     | data_type list_of_param_assignments
	// ;
	auto lta = ctx->list_of_type_assignments();
	if (lta) {
		visitList_of_type_assignments(lta, res);
	}
	auto pd = ctx->parameter_declaration();
	if (pd) {
		visitParameter_declaration(pd, res);
		return;
	}
	auto lpd = ctx->local_parameter_declaration();
	if (lpd) {
		visitLocal_parameter_declaration(lpd, res);
		return;
	}

	auto dt = ctx->data_type();
	assert(dt);
	auto lpa = ctx->list_of_param_assignments();
	assert(lpa);
	auto t = VerTypeParser(commentParser).visitData_type(dt);
	auto doc = commentParser.parse(ctx);
	visitTyped_list_of_param_assignments(t, lpa, doc, res);
}

void VerParamDefParser::visitTyped_list_of_param_assignments(
		iHdlExpr *data_type,
		sv2017Parser::List_of_param_assignmentsContext *lpa,
		const string &doc,
		vector<HdlVariableDef*> & res) {
	vector<HdlVariableDef*> res_tmp;
	visitList_of_param_assignments(lpa, res_tmp);
	bool first = true;
	for (auto v : res_tmp) {
		if (first) {
			v->type = data_type;
			v->__doc__ = doc + v->__doc__;
			first = false;
		} else
			v->type = new iHdlExpr(*data_type);
		res.push_back(v);
	}
}

void VerParamDefParser::visitList_of_param_assignments(
		sv2017Parser::List_of_param_assignmentsContext *ctx,
		vector<HdlVariableDef*> & res) {
	// list_of_param_assignments: param_assignment ( COMMA param_assignment )*;
	for (auto pa : ctx->param_assignment())
		res.push_back(visitParam_assignment(pa));
}
iHdlExpr* VerParamDefParser::visitConstant_param_expression(
		sv2017Parser::Constant_param_expressionContext *ctx) {
	// constant_param_expression: param_expression;
	return visitParam_expression(ctx->param_expression());
}
iHdlExpr* VerParamDefParser::visitParam_expression(
		sv2017Parser::Param_expressionContext *ctx) {
	// param_expression:
	//     mintypmax_expression
	//     | data_type
	// ;
	auto me = ctx->mintypmax_expression();
	if (me) {
		VerExprParser ep(commentParser);
		return ep.visitMintypmax_expression(me);
	} else {
		auto dt = ctx->data_type();
		assert(dt);
		VerTypeParser dp(commentParser);
		return dp.visitData_type(dt);
	}
}

void VerParamDefParser::visitList_of_type_assignments(
		sv2017Parser::List_of_type_assignmentsContext *ctx,
		std::vector<hdlObjects::HdlVariableDef*> &res) {
	// list_of_type_assignments: type_assignment ( COMMA type_assignment )*;
	// type_assignment: identifier ( ASSIGN data_type )?;
	VerTypeParser tp(commentParser);
	for (auto _ta : ctx->type_assignment()) {
		auto name = VerExprParser::getIdentifierStr(_ta->identifier());
		iHdlExpr *v = nullptr;
		auto _v = _ta->data_type();
		if (_v)
			v = tp.visitData_type(_v);
		auto ta = new HdlVariableDef(name, iHdlExpr::TYPE_T(), v);
		res.push_back(ta);
	}
}

HdlVariableDef* VerParamDefParser::visitParam_assignment(
		sv2017Parser::Param_assignmentContext *ctx) {
	// param_assignment:
	//     identifier ( unpacked_dimension )* ( ASSIGN constant_param_expression )?;
	auto cpa = ctx->constant_param_expression();
	iHdlExpr *value = nullptr;
	if (cpa) {
		value = visitConstant_param_expression(cpa);
	}
	HdlVariableDef *p = new HdlVariableDef(ctx->identifier()->getText(),
			nullptr, value);
	p->__doc__ += commentParser.parse(ctx);
	return p;
}
void VerParamDefParser::visitParameter_declaration(
		sv2017Parser::Parameter_declarationContext *ctx,
		vector<HdlVariableDef*> &res) {
	// parameter_declaration:
	//     KW_PARAMETER
	//     ( KW_TYPE list_of_type_assignments
	//       | ( data_type_or_implicit )? list_of_param_assignments
	//     );

	auto lta = ctx->list_of_type_assignments();
	if (lta) {
		visitList_of_type_assignments(lta, res);
	} else {
		auto _t = ctx->data_type_or_implicit();
		auto t = VerTypeParser(commentParser).visitData_type_or_implicit(_t,
				nullptr);
		auto pds = ctx->list_of_param_assignments();
		auto doc = commentParser.parse(ctx);
		visitTyped_list_of_param_assignments(t, pds, doc, res);
	}
}
void VerParamDefParser::visitLocal_parameter_declaration(
		sv2017Parser::Local_parameter_declarationContext *ctx,
		std::vector<hdlObjects::HdlVariableDef*> &_res) {
	// local_parameter_declaration:
	//  KW_LOCALPARAM ( KW_TYPE list_of_type_assignments
	//                   | ( data_type_or_implicit )? list_of_param_assignments
	//                   );
	auto &res = *reinterpret_cast<std::vector<HdlVariableDef*>*>(&_res);
	if (ctx->KW_TYPE()) {
		auto lta = ctx->list_of_type_assignments();
		visitList_of_type_assignments(lta, res);
	} else {
		iHdlExpr *t;
		auto dti = ctx->data_type_or_implicit();
		if (dti) {
			VerTypeParser tp(commentParser);
			t = tp.visitData_type_or_implicit(dti, nullptr);
		} else
			t = iHdlExpr::AUTO_T();
		auto lpa = ctx->list_of_param_assignments();
		auto doc = commentParser.parse(ctx);
		visitTyped_list_of_param_assignments(t, lpa, doc, res);
	}
}

}
}
