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

vector<HdlVariableDef*>* VerParamDefParser::visitParameter_port_list(
		sv2017Parser::Parameter_port_listContext *ctx) {
	// parameter_port_list:
	//     HASH LPAREN (
	//        ( list_of_param_assignments
	//          | parameter_port_declaration
	//         ) ( COMMA parameter_port_declaration )* )? RPAREN;

	auto vars = new vector<HdlVariableDef*>();
	auto lpa = ctx->list_of_param_assignments();
	if (lpa) {
		NotImplementedLogger::print(
				"VerVerParamDefParser.visitParameter_port_list - list_of_param_assignments",
				lpa);
	}
	for (auto pd : ctx->parameter_port_declaration()) {
		auto pds = visitParameter_port_declaration(pd);
		for (auto pd : *pds)
			vars->push_back(pd);
		delete pds;
	}

	return vars;
}

vector<HdlVariableDef*>* VerParamDefParser::visitParameter_port_declaration(
		sv2017Parser::Parameter_port_declarationContext *ctx) {
	// parameter_port_declaration:
	//     KW_TYPE list_of_type_assignments
	//     | parameter_declaration
	//     | local_parameter_declaration
	//     | data_type list_of_param_assignments
	// ;
	auto pd = ctx->parameter_declaration();
	if (pd)
		return visitParameter_declaration(pd);

	auto dt = ctx->data_type();
	assert(dt);
	auto lpa = ctx->list_of_param_assignments();
	assert(lpa);
	auto t = VerTypeParser::visitData_type(dt);
	auto doc = commentParser.parse(ctx);
	return visitTyped_list_of_param_assignments(t, lpa, doc);
}

vector<HdlVariableDef*>* VerParamDefParser::visitTyped_list_of_param_assignments(
		iHdlExpr *data_type,
		sv2017Parser::List_of_param_assignmentsContext *lpa,
		const string &doc) {
	auto params = visitList_of_param_assignments(lpa);
	bool first = true;
	for (auto v : *params) {
		if (first) {
			v->type = data_type;
			v->__doc__ = doc + v->__doc__;
			first = false;
		} else
			v->type = new iHdlExpr(*data_type);
	}

	return params;

}
vector<HdlVariableDef*>* VerParamDefParser::visitList_of_param_assignments(
		sv2017Parser::List_of_param_assignmentsContext *ctx) {
	// list_of_param_assignments: param_assignment ( COMMA param_assignment )*;
	vector<HdlVariableDef*> *params = new vector<HdlVariableDef*>();
	for (auto pa : ctx->param_assignment())
		params->push_back(visitParam_assignment(pa));
	return params;
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
		return VerExprParser::visitMintypmax_expression(me);
	} else {
		auto dt = ctx->data_type();
		assert(dt);
		return VerTypeParser::visitData_type(dt);
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
vector<HdlVariableDef*>* VerParamDefParser::visitParameter_declaration(
		sv2017Parser::Parameter_declarationContext *ctx) {
	// parameter_declaration:
	//     KW_PARAMETER
	//     ( KW_TYPE list_of_type_assignments
	//       | ( data_type_or_implicit )? list_of_param_assignments
	//     );

	auto lta = ctx->list_of_type_assignments();
	if (lta) {
		NotImplementedLogger::print(
				"VerParamDefParser.visitParameter_declaration - list_of_type_assignments",
				lta);
		auto vars = new vector<HdlVariableDef*>();
		return vars;
	} else {
		auto _t = ctx->data_type_or_implicit();
		auto t = VerTypeParser::visitData_type_or_implicit(_t);
		auto pds = ctx->list_of_param_assignments();
		auto doc = commentParser.parse(ctx);
		return visitTyped_list_of_param_assignments(t, pds, doc);
	}

}

}
}
