#include <hdlConvertor/svConvertor/paramDefParser.h>

#include <hdlConvertor/svConvertor/utils.h>

#include <hdlConvertor/createObject.h>
#include <hdlConvertor/notImplementedLogger.h>

#include <hdlConvertor/svConvertor/typeParser.h>
#include <hdlConvertor/svConvertor/exprParser.h>

using namespace std;
using sv2017Parser = sv2017_antlr::sv2017Parser;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace sv {

VerParamDefParser::VerParamDefParser(SVCommentParser &commentParser) :
		commentParser(commentParser) {
}

void VerParamDefParser::visitParameter_port_list(
		sv2017Parser::Parameter_port_listContext *ctx,
		vector<unique_ptr<HdlVariableDef>> &res) {
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
		vector<unique_ptr<HdlVariableDef>> &res) {
	// parameter_port_declaration:
	//     KW_TYPE list_of_type_assignments
	//     | parameter_declaration
	//     | local_parameter_declaration
	//     | data_type list_of_param_assignments
	// ;
	auto lta = ctx->list_of_type_assignments();
	if (lta) {
		visitList_of_type_assignments(lta, res);
		return;
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
	//TODO::auto t = VerTypeParser(commentParser).visitData_type(dt);
	//
	// rhinton: need to fix Verilog type parser
	//
	//TODO::auto doc = commentParser.parse(ctx);
	//TODO::visitTyped_list_of_param_assignments(move(t), lpa, doc, res);
}

void VerParamDefParser::visitTyped_list_of_param_assignments(
		unique_ptr<HdlSubtype> data_type,
		sv2017Parser::List_of_param_assignmentsContext *lpa, const string &doc,
		vector<unique_ptr<HdlVariableDef>> &res) {
	vector<unique_ptr<HdlVariableDef>> res_tmp;
	visitList_of_param_assignments(lpa, res_tmp);
	bool first = true;
	auto data_type_tmp = data_type.get();
	for (auto & v : res_tmp) {
		if (first) {
			v->type = move(data_type);
			v->__doc__ = doc + v->__doc__;
			first = false;
		} else {
			//TODO::v->type = make_unique<iHdlExpr>(*data_type_tmp);
			//
			// rhinton: need to fix Verilog type system
		}
		res.push_back(move(v));
	}
}

void VerParamDefParser::visitList_of_param_assignments(
		sv2017Parser::List_of_param_assignmentsContext *ctx,
		vector<unique_ptr<HdlVariableDef>> &res) {
	// list_of_param_assignments: param_assignment ( COMMA param_assignment )*;
	for (auto pa : ctx->param_assignment())
		res.push_back(visitParam_assignment(pa));
}
unique_ptr<iHdlExpr> VerParamDefParser::visitConstant_param_expression(
		sv2017Parser::Constant_param_expressionContext *ctx) {
	// constant_param_expression: param_expression;
	return visitParam_expression(ctx->param_expression());
}
unique_ptr<iHdlExpr> VerParamDefParser::visitParam_expression(
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
		vector<unique_ptr<HdlVariableDef>> &res) {
	// list_of_type_assignments: type_assignment ( COMMA type_assignment )*;
	// type_assignment: identifier ( ASSIGN data_type )?;
	VerTypeParser tp(commentParser);
	for (auto _ta : ctx->type_assignment()) {
		auto name = VerExprParser::getIdentifierStr(_ta->identifier());
		unique_ptr<iHdlExpr> v = nullptr;
		auto _v = _ta->data_type();
		if (_v)
			v = tp.visitData_type(_v);
		//TODO::auto ta = create_object<HdlVariableDef>(_ta, name, iHdlExpr::TYPE_T(),
		//TODO::		move(v));
		//TODO::res.push_back(move(ta));
	}
}

unique_ptr<HdlVariableDef> VerParamDefParser::visitParam_assignment(
		sv2017Parser::Param_assignmentContext *ctx) {
	// param_assignment:
	//     identifier ( unpacked_dimension )* ( ASSIGN constant_param_expression )?;
	auto cpa = ctx->constant_param_expression();
	unique_ptr<iHdlExpr> value = nullptr;
	if (cpa) {
		value = visitConstant_param_expression(cpa);
	}
	auto name = VerExprParser::getIdentifierStr(ctx->identifier());
	//TODO::auto p = create_object<HdlVariableDef>(ctx, name, iHdlExpr::AUTO_T(), move(value));
	//TODO::p->__doc__ += commentParser.parse(ctx);
	//TODO::return p;
	return nullptr;
}
void VerParamDefParser::visitParameter_declaration(
		sv2017Parser::Parameter_declarationContext *ctx,
		vector<unique_ptr<HdlVariableDef>> &res) {
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
		VerTypeParser tp(commentParser);
		unique_ptr<iHdlExpr> t;
		if (_t)
			t = tp.visitData_type_or_implicit(_t, nullptr);
		else
			t = iHdlExpr::AUTO_T();

		auto pds = ctx->list_of_param_assignments();
		auto doc = commentParser.parse(ctx);
		//TODO::visitTyped_list_of_param_assignments(move(t), pds, doc, res);
	}
}
void VerParamDefParser::visitLocal_parameter_declaration(
		sv2017Parser::Local_parameter_declarationContext *ctx,
		vector<unique_ptr<HdlVariableDef>> &_res) {
	// local_parameter_declaration:
	//  KW_LOCALPARAM ( KW_TYPE list_of_type_assignments
	//                   | ( data_type_or_implicit )? list_of_param_assignments
	//                   );
	auto &res = *reinterpret_cast<vector<unique_ptr<HdlVariableDef>>*>(&_res);
	if (ctx->KW_TYPE()) {
		auto lta = ctx->list_of_type_assignments();
		visitList_of_type_assignments(lta, res);
	} else {
		unique_ptr<iHdlExpr> t;
		auto dti = ctx->data_type_or_implicit();
		if (dti) {
			VerTypeParser tp(commentParser);
			t = tp.visitData_type_or_implicit(dti, nullptr);
		} else
			t = iHdlExpr::AUTO_T();
		auto lpa = ctx->list_of_param_assignments();
		auto doc = commentParser.parse(ctx);
		//TODO::visitTyped_list_of_param_assignments(move(t), lpa, doc, res);
	}
}

}
}
