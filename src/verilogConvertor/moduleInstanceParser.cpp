#include "moduleInstanceParser.h"
#include "../notImplementedLogger.h"
#include "../hdlObjects/expr.h"
#include "exprParser.h"

using namespace std;
using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace verilog {

vector<CompInstance *> ModuleInstanceParser::visitModule_instantiation(
		Verilog2001Parser::Module_instantiationContext* ctx) {
	// module_instantiation
	//    : module_identifier (parameter_value_assignment)? module_instance (',' module_instance)* ';'
	//    ;
	auto module_name =
			ctx->module_identifier()->identifier()->getText().c_str();

	auto pva = ctx->parameter_value_assignment();
	vector<Expr*> genericMap;
	if (pva) {
		// parameter_value_assignment
		//    : '#' '(' list_of_parameter_assignments ')'
		//    ;
		genericMap = visitList_of_parameter_assignments(
				pva->list_of_parameter_assignments());
	}
	auto mis = ctx->module_instance();
	bool first = true;
	vector<CompInstance *> res;
	for (auto mi : mis) {
		CompInstance * c;
		if (first) {
			c = visitModule_instance(mi, Expr::ID(module_name), genericMap);
			first = false;
		} else {
			vector<Expr*> gm;
			for (auto e : genericMap)
				gm.push_back(new Expr(*e));
			c = visitModule_instance(mi, Expr::ID(module_name), gm);
		}
		res.push_back(c);
	}
	return res;
}
Expr * ModuleInstanceParser::visitParameter_identifier(
		Verilog2001Parser::Parameter_identifierContext * ctx) {
	// parameter_identifier
	//    : identifier
	//    ;
	return VerExprParser::visitIdentifier(ctx->identifier());
}
vector<Expr*> ModuleInstanceParser::visitList_of_parameter_assignments(
		Verilog2001Parser::List_of_parameter_assignmentsContext * ctx) {

	// list_of_parameter_assignments
	//    : ordered_parameter_assignment (',' ordered_parameter_assignment)*
	//    | named_parameter_assignment (',' named_parameter_assignment)*
	//    ;

	//   ctx->parameter_identifier()->identifier()->getText()

	vector<Expr*> pcs;
	auto opa = ctx->ordered_parameter_assignment();
	if (opa.size()) {
		for (auto pa : opa) {
			// ordered_parameter_assignment
			//    : expression
			//    ;
			auto e = VerExprParser::visitExpression(pa->expression());
			pcs.push_back(e);
		}
	} else {
		auto npa = ctx->named_parameter_assignment();
		for (auto pa : npa) {
			// named_parameter_assignment
			//    : '.' parameter_identifier '(' (expression)? ')'
			//    ;
			auto k = visitParameter_identifier(pa->parameter_identifier());
			Expr * v;
			auto e = pa->expression();
			if (e) {
				v = VerExprParser::visitExpression(e);
			} else {
				v = Expr::null();
			}
			pcs.push_back(new Expr(k, OperatorType::MAP_ASSOCIATION, v ));
		}
	}
	return pcs;
}

CompInstance * ModuleInstanceParser::visitModule_instance(
		Verilog2001Parser::Module_instanceContext * ctx, Expr * module_id,
		vector<Expr*> genericMap) {
	// @note genericMap became the owner of all Expr instances in the vector
	//       that means that the instances can not be shared

	// module_instance
	//    : name_of_instance '(' list_of_port_connections ')'
	//    ;
	auto noi = ctx->name_of_instance();
	// name_of_instance
	//    : module_instance_identifier (range_)?
	//    ;
	// module_instance_identifier
	//    : arrayed_identifier
	//    ;
	auto name = VerExprParser::visitArrayed_identifier(
			noi->module_instance_identifier()->arrayed_identifier());
	auto _r = noi->range_();
	if (_r) {
		auto r = VerExprParser::visitRange_(_r);
		name = new Expr(name, OperatorType::INDEX, r);
	}
	vector<Expr*> portMap = visitList_of_port_connections(
			ctx->list_of_port_connections());
	auto c = new CompInstance(name, module_id);
	c->genericMap = genericMap;
	c->portMap = portMap;
	return c;
}

vector<Expr*> ModuleInstanceParser::visitList_of_port_connections(
		Verilog2001Parser::List_of_port_connectionsContext * ctx) {
	// list_of_port_connections
	//    : ordered_port_connection (',' ordered_port_connection)*
	//    | named_port_connection (',' named_port_connection)*
	//    ;
	//
	vector<Expr*> pcs;
	auto opc = ctx->ordered_port_connection();
	if (opc.size()) {
		for (auto pc : opc) {
			// ordered_port_connection
			//    : attribute_instance* (expression)?
			//    ;
			//
			if (pc->attribute_instance().size())
				NotImplementedLogger::print(
						"ModuleInstanceParser.visitList_of_port_connections.ordered_port_connection attribute_instance");
			auto _e = pc->expression();
			Expr * e;
			if (_e) {
				e = VerExprParser::visitExpression(_e);
			} else {
				e = Expr::null();
			}
			pcs.push_back(e);
		}
	} else {
		auto npc = ctx->named_port_connection();
		for (auto pc : npc) {
			// named_port_connection
			//    : attribute_instance* '.' port_identifier '(' (expression)? ')'
			//    ;
			// port_identifier : identifier;
			if (pc->attribute_instance().size())
				NotImplementedLogger::print(
						"ModuleInstanceParser.visitList_of_port_connections.named_port_connection attribute_instance");

			Expr * k = VerExprParser::visitIdentifier(
					pc->port_identifier()->identifier());
			Expr * v;
			auto e = pc->expression();
			if (e) {
				v = VerExprParser::visitExpression(e);
			} else {
				v = Expr::null();
			}
			pcs.push_back(new Expr(k, OperatorType::MAP_ASSOCIATION, v ));
		}
	}
	return pcs;
}

}
}
