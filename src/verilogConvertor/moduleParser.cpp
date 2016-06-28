#include "moduleParser.h"

ModuleParser::ModuleParser(Context * _context, bool _hierarchyOnly) {
	context = _context;
	hierarchyOnly = _hierarchyOnly;
	ent = new Entity();
}

void ModuleParser::visitModule_declaration(
		Ref<Verilog2001Parser::Module_declarationContext> ctx) {
	// module_declaration
	// : attribute_instance* module_keyword module_identifier
	// ( module_parameter_port_list )? ( list_of_ports )? ';' module_item*
	// 'endmodule'
	// | attribute_instance* module_keyword module_identifier
	// ( module_parameter_port_list )? ( list_of_port_declarations )? ';'
	// non_port_module_item*
	// 'endmodule'
	// ;
	ent->name = strdup(
			ctx->module_identifier()->identifier()->getText().c_str());
	for (auto a : ctx->attribute_instance()) {
		auto ais = AttributeParser::visitAttribute_instance(a);
		for (auto v : *ais)
			ent->generics.push_back(v);
		delete ais;
	}
	auto mppl = ctx->module_parameter_port_list();
	if (mppl) {
		auto ppls = visitModule_parameter_port_list(mppl);
		for (auto v : *ppls)
			ent->generics.push_back(v);
	}
	auto lop = ctx->list_of_ports();
	if (lop) {
		auto ps = PortParser::visitList_of_ports(lop);
		for (auto p : *ps) {
			ent->ports.push_back(p);
		}
		delete ps;
	}

	for (auto mi : ctx->module_item())
		visitModule_item(mi);

	auto lpd = ctx->list_of_port_declarations();
	if (lpd) {
		auto ps = PortParser::visitList_of_port_declarations(lpd);
		for (auto p : *ps) {
			ent->ports.push_back(p);
		}
		delete ps;
	}
	for (auto npmi : ctx->non_port_module_item())
		visitNon_port_module_item(npmi);

	context->entities.push_back(ent);
}

std::vector<Variable*>* ModuleParser::visitModule_parameter_port_list(
		Ref<Verilog2001Parser::Module_parameter_port_listContext> ctx) {
	// module_parameter_port_list : '#' '(' parameter_declaration_ ( ','
	// parameter_declaration_ )* ')' ;
	std::vector<Variable*>* vars = new std::vector<Variable*>();
	for (auto pd : ctx->parameter_declaration_()) {
		auto pds = visitParameter_declaration_(pd);
		for (auto pd : *pds)
			vars->push_back(pd);
		delete pds;
	}

	return vars;
}

std::vector<Variable*>* ModuleParser::visitParameter_declaration_(
		Ref<Verilog2001Parser::Parameter_declaration_Context> ctx) {
	//// split out semi on end. spec grammar is wrong. It won't allow
	//// #(parameter B=8) since it wants a ';' in (...). Rule
	//// module_parameter_port_list calls this one.

	// parameter_declaration_ :
	// 'parameter' ( 'signed' )? ( range )? list_of_param_assignments
	// |'parameter' 'integer' list_of_param_assignments
	// |'parameter' 'real' list_of_param_assignments
	// |'parameter' 'realtime' list_of_param_assignments
	// |'parameter' 'time' list_of_param_assignments
	// ;

	// [TODO] signed

	Expr * t = Utils::mkStringT();
	auto typeStr = ctx->getChild(1);
	auto term = dynamic_cast<antlr4::tree::TerminalNodeImpl*>(typeStr.get());
	if (term) {
		t = Expr::ID(term->getText());
	}

	auto r = ctx->range();
	if (r) {
		std::vector<Expr*> * operands = new std::vector<Expr*>();
		operands->push_back(VerExprParser::visitRange(r));
		t = Expr::call(Utils::mkWireT(), operands);
	}

	std::vector<Variable*> * params = visitList_of_param_assignments(
			ctx->list_of_param_assignments());
	for (auto v : *params)
		v->type = t;
	return params;
}
std::vector<Variable*> *ModuleParser::visitList_of_param_assignments(
		Ref<Verilog2001Parser::List_of_param_assignmentsContext> ctx) {
	// list_of_param_assignments :
	// param_assignment ( ',' param_assignment )*
	// ;
	std::vector<Variable*>* params = new std::vector<Variable*>();
	for (auto pa : ctx->param_assignment())
		params->push_back(visitParam_assignment(pa));
	return params;

}
Variable * ModuleParser::visitParam_assignment(
		Ref<Verilog2001Parser::Param_assignmentContext> ctx) {
	// param_assignment : parameter_identifier '=' constant_expression ;
	auto value = VerExprParser::visitConstant_expression(
			ctx->constant_expression());
	Variable* p = new Variable(
			ctx->parameter_identifier()->identifier()->getText(), NULL, value);
	return p;
}

void ModuleParser::visitModule_item(
		Ref<Verilog2001Parser::Module_itemContext> ctx) {
	// module_item :
	// module_or_generate_item
	// | port_declaration ';'
	// | attribute_instance* generated_instantiation
	// | attribute_instance* local_parameter_declaration
	// | attribute_instance* parameter_declaration
	// | attribute_instance* specify_block
	// | attribute_instance* specparam_declaration
	// ;
	NotImplementedLogger::print("ModuleParser.visitModule_item");
}
void ModuleParser::visitNon_port_module_item(
		Ref<Verilog2001Parser::Non_port_module_itemContext> ctx) {
	NotImplementedLogger::print("ModuleParser.visitNon_port_module_item");
	// non_port_module_item :
	// attribute_instance* generated_instantiation
	// | attribute_instance* local_parameter_declaration
	// | attribute_instance* module_or_generate_item
	// | attribute_instance* parameter_declaration
	// | attribute_instance* specify_block
	// | attribute_instance* specparam_declaration
	// ;
}
