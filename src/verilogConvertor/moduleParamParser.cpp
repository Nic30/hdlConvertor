#include "moduleParamParser.h"
#include "utils.h"
#include "exprParser.h"

using namespace std;
using Verilog2001Parser = Verilog2001_antlr::Verilog2001Parser;
using namespace hdlConvertor::hdlObjects;

namespace hdlConvertor {
namespace verilog {

ModuleParamParser::ModuleParamParser(CommentParser & commentParser) :
		commentParser(commentParser) {
}

vector<Variable*>* ModuleParamParser::visitModule_parameter_port_list(
		Verilog2001Parser::Module_parameter_port_listContext* ctx) {
	// module_parameter_port_list : '#' '(' parameter_declaration_ ( ','
	// parameter_declaration_ )* ')' ;
	auto vars = new vector<Variable*>();
	for (auto pd : ctx->parameter_declaration_()) {
		auto pds = visitParameter_declaration_(pd);
		for (auto pd : *pds)
			vars->push_back(pd);
		delete pds;
	}

	return vars;
}

vector<Variable*>* ModuleParamParser::visitParameter_declaration_(
		Verilog2001Parser::Parameter_declaration_Context* ctx) {
	//// split out semi on end. spec grammar is wrong. It won't allow
	//// #(parameter B=8) since it wants a ';' in (...). Rule
	//// module_parameter_port_list calls this one.

	// parameter_declaration_ :
	// 'parameter' ( 'signed' )? ( range_ )? list_of_param_assignments
	// |'parameter' 'integer' list_of_param_assignments
	// |'parameter' 'real' list_of_param_assignments
	// |'parameter' 'realtime' list_of_param_assignments
	// |'parameter' 'time' list_of_param_assignments
	// ;
	Expr * t = nullptr;
	auto typeStr = ctx->children[1];
	auto term = dynamic_cast<antlr4::tree::TerminalNodeImpl*>(typeStr);
	if (term) {
		t = Expr::ID(term->getText());
	}

	auto r = ctx->range_();
	if (r) {
		t = Utils::mkWireT(r, Utils::is_signed(ctx));
	}

	vector<Variable*> * params = visitList_of_param_assignments(
			ctx->list_of_param_assignments());

	if (t == nullptr)
		t = Utils::mkStringT();
	bool first = true;
	for (auto v : *params) {
		if (first) {
			v->type = t;
			v->__doc__ = commentParser.parse(ctx) + v->__doc__;
			first = false;
		} else
			v->type = new Expr(*t);
	}

	return params;
}
vector<Variable*> *ModuleParamParser::visitList_of_param_assignments(
		Verilog2001Parser::List_of_param_assignmentsContext * ctx) {
	// list_of_param_assignments :
	// param_assignment ( ',' param_assignment )*
	// ;
	vector<Variable*>* params = new vector<Variable*>();
	for (auto pa : ctx->param_assignment())
		params->push_back(visitParam_assignment(pa));
	return params;

}
Variable * ModuleParamParser::visitParam_assignment(
		Verilog2001Parser::Param_assignmentContext* ctx) {
	// param_assignment : parameter_identifier '=' constant_expression ;
	auto value = VerExprParser::visitConstant_expression(
			ctx->constant_expression());
	Variable* p = new Variable(
			ctx->parameter_identifier()->identifier()->getText(), NULL, value);
	p->__doc__ += commentParser.parse(ctx);
	return p;
}
vector<Variable*>* ModuleParamParser::visitParameter_declaration(
		Verilog2001Parser::Parameter_declarationContext * ctx) {
	auto vars = new vector<Variable*>();
	auto pds = visitParameter_declaration_(ctx->parameter_declaration_());
	for (auto pd : *pds)
		vars->push_back(pd);
	delete pds;
	return vars;

}

}
}
